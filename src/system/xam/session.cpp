#include <rex/system/xam/session.h>
#include <rex/system/xam/private_lan_discovery.h>
#include <rex/system/xam/session_arbitration_crypto.h>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstring>
#include <random>
#include <system_error>
#include <thread>
#include <unordered_set>

#include <rex/logging.h>
#include <rex/cvar.h>
#include <rex/system/kernel_state.h>
#include <rex/thread.h>
#include <rex/system/xam/nat_probe.h>

#if REX_PLATFORM_POSIX_ONLINE
#include <openssl/evp.h>
#include <openssl/hmac.h>
#endif
#if REX_PLATFORM_MAC
#include <ifaddrs.h>
#include <net/if.h>
#include "../net_posix_compat.h"
#endif

#if REX_PLATFORM_WIN32
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <ws2tcpip.h>
#include <bcrypt.h>
using socket_len_t = int;
static constexpr SOCKET kInvalidSocket = INVALID_SOCKET;
#else
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
using SOCKET = int;
using socket_len_t = socklen_t;
static constexpr SOCKET kInvalidSocket = -1;
#endif

namespace rex::system::xam {

// A joined record owns its continuity token and separate registration socket.
// Discovery's retained descriptor can be retired without aliasing this socket.
class ArbitrationClientBinding final {
 public:
  ~ArbitrationClientBinding() {
    if (socket == kInvalidSocket) return;
#if REX_PLATFORM_WIN32
    closesocket(socket);
#else
    close(socket);
#endif
  }
  std::mutex mutex;
  SOCKET socket = kInvalidSocket;
  ArbitrationIdentity identity{};
  uint64_t xuid = 0;
  uint64_t machine_id = 0;
  ArbitrationToken credential{};
  ArbitrationToken challenge{};
  ArbitrationToken attempt{};
  std::optional<EphemeralArbitrationKey> key;
  std::chrono::steady_clock::time_point created = std::chrono::steady_clock::now();
  std::atomic<bool> confirmed = false;
  std::atomic<bool> credential_received = false;
  LanAddress target{};
};

std::optional<LanAddress> LateTraversalQueryState::TakeAcknowledgedPeer(
    bool search_active, std::optional<LanAddress> acknowledged_peer) {
  if (!traversal_enabled_ || !search_active || late_query_sent_ || !acknowledged_peer ||
      queried_peer_ == acknowledged_peer) {
    return std::nullopt;
  }
  late_query_sent_ = true;
  queried_peer_ = acknowledged_peer;
  return acknowledged_peer;
}

REXCVAR_DEFINE_STRING(private_lan_invitation_file,"","Network",
    "Absolute private per-client LAN invitation file; secret bytes are never configuration values")
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_BOOL(private_lan_allow_legacy_diagnostics,false,"Network",
    "Explicit diagnostic opt-in for unauthenticated legacy LAN control and raw LAN gameplay")
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);

REXCVAR_DEFINE_STRING(lan_bind_address, "", "Network",
                      "Physical IPv4 address used for LAN discovery and gameplay traffic")
    .validator([](std::string_view value) {
      if (value.empty())
        return true;
      in_addr address{};
      std::string text(value);
      return inet_pton(AF_INET, text.c_str(), &address) == 1 &&
             address.s_addr != htonl(INADDR_ANY) && address.s_addr != htonl(INADDR_BROADCAST);
    })
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);

REXCVAR_DEFINE_STRING(lan_discovery_listen_address, "", "Network",
                      "Explicit IPv4 discovery listener address (empty preserves LAN broadcast)")
    .validator([](std::string_view value) {
      if (value.empty())
        return true;
      in_addr address{};
      std::string text(value);
      return inet_pton(AF_INET, text.c_str(), &address) == 1 &&
             address.s_addr != htonl(INADDR_ANY) && address.s_addr != htonl(INADDR_BROADCAST);
    })
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);

REXCVAR_DEFINE_UINT32(
    lan_gameplay_port, 0, "Network",
    "Optional native UDP port for LAN gameplay (0 preserves the guest-requested port)")
    .range(0, 65535)
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);

REXCVAR_DEFINE_STRING(
    direct_connect_address, "", "Network",
    "Optional IPv4 host address for direct session discovery (empty uses LAN broadcast)")
    .validator([](std::string_view value) {
      if (value.empty())
        return true;
      in_addr address{};
      std::string text(value);
      return inet_pton(AF_INET, text.c_str(), &address) == 1 &&
             address.s_addr != htonl(INADDR_ANY) && address.s_addr != htonl(INADDR_BROADCAST);
    })
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);

namespace {
constexpr uint32_t kDiscoveryMagic = 0x5245584Cu;
constexpr uint16_t kDiscoveryVersion = 2;
// A by-code joiner waits this long (plus the NAT grace) for the host to answer
// its discovery; the host answers only after a directory poll grants the attempt.
constexpr uint32_t kConfiguredInviteDiscoveryMs = 5000;
constexpr uint8_t kQuery = 1;
constexpr uint8_t kAdvertisement = 2;
constexpr uint8_t kJoin = 3;
constexpr uint8_t kLeave = 4;
constexpr uint8_t kRegister = 5;
constexpr uint8_t kRegisterReply = 6;
constexpr uint8_t kJoinExpired = 7;
constexpr size_t kMaxWireMembers = 8;

enum class MemberUpdateSource {
  kTitleAllocatedPool,
  kDiscoveryPublic,
  kInviteGrant,
};

bool ValidMemberAccounting(std::span<const SessionMember> members, uint32_t public_slots,
                           uint32_t private_slots) {
  uint64_t public_count = 0;
  uint64_t private_count = 0;
  std::unordered_set<uint64_t> identities;
  for (const auto& member : members) {
    if (!member.xuid || !identities.insert(member.xuid).second)
      return false;
    member.private_slot ? ++private_count : ++public_count;
  }
  return public_count <= public_slots && private_count <= private_slots;
}

// Complete candidate planning and commit use one record lock. NAT and grant
// locks are never held here.
bool ApplyMemberBatch(SessionRecord& session, std::span<const SessionMember> members,
                      MemberUpdateSource source) {
  std::lock_guard lock(*session.mutex);
  auto reject = [&](const char* reason) {
    if (source != MemberUpdateSource::kTitleAllocatedPool)
      REXSYS_WARN("INVITE_DIAG HOST_ADMISSION_REJECTED_{} source={} batch={}", reason,
                  source == MemberUpdateSource::kInviteGrant ? "invite_grant" : "public",
                  members.size());
    return false;
  };
  if (session.state == SessionState::kDeleted || members.empty() ||
      !ValidMemberAccounting(session.members, session.max_public_slots, session.max_private_slots))
    return reject("DELETED_EMPTY_OR_INVALID_ROSTER");
  if (source == MemberUpdateSource::kInviteGrant && members.size() != 1)
    return reject("INVALID_GRANT_BATCH");
  if(session.private_lan_invitation&&source==MemberUpdateSource::kTitleAllocatedPool&&
     std::any_of(members.begin(),members.end(),[&](const auto& incoming){return
       std::none_of(session.members.begin(),session.members.end(),[&](const auto& current){return current.xuid==incoming.xuid;});}))return false;
  auto candidate = session.members;
  std::unordered_set<uint64_t> batch_ids;
  for (auto member : members) {
    if (!member.xuid || !batch_ids.insert(member.xuid).second)
      return reject("ZERO_OR_DUPLICATE_XUID");
    auto it = std::find_if(candidate.begin(), candidate.end(),
                           [&](const auto& current) { return current.xuid == member.xuid; });
    if (source != MemberUpdateSource::kTitleAllocatedPool) {
      if (member.xuid == session.host_xuid)
        return reject("HOST_XUID");
      if (it != candidate.end())
        continue;
      member.local = false;
      if (source == MemberUpdateSource::kDiscoveryPublic) {
        member.private_slot = false;
      } else if (member.private_slot) {
        // A verified invite makes the joining player eligible for a private
        // slot. It does not require a private slot: the title may host only
        // public capacity while still joining through its invite path. Plan
        // the final pool under this same record lock, preferring private
        // capacity and falling back to public capacity when it is exhausted.
        const auto private_count = std::count_if(
            candidate.begin(), candidate.end(),
            [](const auto& current) { return current.private_slot; });
        if (uint64_t(private_count) >= session.max_private_slots)
          member.private_slot = false;
      }
    } else if (it != candidate.end() && member.name.empty()) {
      // Preserve a name learned from the companion status channel when the
      // title retries membership with no display-name field.
      member.name = it->name;
    }
    // Ordinary title metadata updates preserve the existing admission instance.
    // Removing and subsequently recreating a member does not inherit it.
    if (it != candidate.end()) {
      member.gameplay_admission = it->gameplay_admission;
      member.machine_id = it->machine_id;
      member.gameplay_address = it->gameplay_address;
    }
    if (it == candidate.end())
      candidate.push_back(std::move(member));
    else
      *it = std::move(member);
  }
  if (!ValidMemberAccounting(candidate, session.max_public_slots,
                             session.max_private_slots))
    return reject("CAPACITY_OR_DUPLICATE_ROSTER");
  if (session.arbitration_client) {
    const auto same_members = candidate.size() == session.members.size() &&
        std::all_of(candidate.begin(),candidate.end(),[&](const auto& member) {
          return std::any_of(session.members.begin(),session.members.end(),
              [&](const auto& previous) { return previous.xuid == member.xuid; });
        });
    if (!same_members) session.arbitration_revision = 0;
  }
  session.members.swap(candidate);
  if (source != MemberUpdateSource::kTitleAllocatedPool) {
    const auto private_count = std::count_if(session.members.begin(), session.members.end(),
                                             [](const auto& member) { return member.private_slot; });
    REXSYS_INFO("INVITE_DIAG HOST_ADMISSION_ACCEPTED source={} public={} private={} total={} public_cap={} private_cap={}",
                source == MemberUpdateSource::kInviteGrant ? "invite_grant" : "public",
                session.members.size() - private_count, private_count,
                session.members.size(), session.max_public_slots,
                session.max_private_slots);
  }
  session.NotifyStatus();
  return true;
}

bool EnsureSocketRuntime() {
#if REX_PLATFORM_WIN32
  static std::once_flag once;
  static bool initialized = false;
  std::call_once(once, [] {
    WSADATA data{};
    initialized = WSAStartup(MAKEWORD(2, 2), &data) == 0;
  });
  return initialized;
#else
  return true;
#endif
}

#pragma pack(push, 1)
struct WireMember {
  uint64_t xuid;
  uint32_t flags;
  char name[16];
  uint64_t machine_id;
  uint32_t gameplay_ipv4;
  uint16_t gameplay_port;
  uint16_t reserved;
};
struct DiscoveryPacket {
  uint32_t magic;
  uint16_t version;
  uint8_t type;
  uint8_t reserved;
  uint32_t title_id;
  uint8_t session_id[8];
  uint8_t session_key[16];
  uint64_t host_xuid;
  uint32_t host_ipv4;
  uint16_t host_port;
  uint16_t reserved2;
  uint32_t flags;
  uint32_t public_slots;
  uint32_t private_slots;
  uint32_t member_count;
  char host_name[16];
  WireMember members[kMaxWireMembers];
  uint64_t nonce;
  uint64_t host_machine_id;
  uint8_t incarnation[16];
  uint8_t attempt[16];
  uint8_t credential[16]; // Only admitted unicast join replies carry encrypted token bytes.
  uint8_t authentication[16];
  uint64_t revision;
  uint32_t registered_mask;
  uint32_t reserved3;
  uint8_t client_public_key[32];
  uint8_t server_public_key[32];
  uint8_t credential_iv[12];
  uint8_t credential_tag[16];
  uint8_t request_id[16]; // Fresh RPC correlation, separate from durable registration attempt.
};
struct InviteLanPacket {
  char magic[4];
  uint8_t version;
  uint8_t type;
  uint16_t reserved;
  uint8_t selector[16];
  uint8_t proof[16];
};
#pragma pack(pop)
static_assert(sizeof(InviteLanPacket) == 40);
static_assert(sizeof(DiscoveryPacket) == 640);
static_assert(sizeof(DiscoveryPacket) < 1200);

constexpr uint8_t kInviteLanRequest = 1;
constexpr uint8_t kInviteLanResponse = 2;

std::optional<std::array<uint8_t, 16>> InviteLanMac(
    std::string_view attempt_id, std::string_view domain,
    std::span<const uint8_t> payload = {}) {
#if REX_PLATFORM_WIN32
  if (attempt_id.size() != 32 ||
      !std::all_of(attempt_id.begin(), attempt_id.end(), [](char value) {
        return (value >= '0' && value <= '9') ||
               (value >= 'a' && value <= 'f');
      }))
    return std::nullopt;
  BCRYPT_ALG_HANDLE algorithm = nullptr;
  if (BCryptOpenAlgorithmProvider(&algorithm, BCRYPT_SHA256_ALGORITHM, nullptr,
                                 BCRYPT_ALG_HANDLE_HMAC_FLAG) < 0)
    return std::nullopt;
  std::vector<uint8_t> input(domain.begin(), domain.end());
  input.insert(input.end(), payload.begin(), payload.end());
  std::array<uint8_t, 32> digest{};
  const auto status = BCryptHash(
      algorithm, reinterpret_cast<PUCHAR>(const_cast<char*>(attempt_id.data())),
      ULONG(attempt_id.size()), input.data(), ULONG(input.size()), digest.data(),
      ULONG(digest.size()));
  BCryptCloseAlgorithmProvider(algorithm, 0);
  if (status < 0)
    return std::nullopt;
  std::array<uint8_t, 16> result{};
  std::copy_n(digest.begin(), result.size(), result.begin());
  return result;
#elif REX_PLATFORM_POSIX_ONLINE
  if (attempt_id.size() != 32 ||
      !std::all_of(attempt_id.begin(), attempt_id.end(), [](char value) {
        return (value >= '0' && value <= '9') ||
               (value >= 'a' && value <= 'f');
      }))
    return std::nullopt;
  std::vector<uint8_t> input(domain.begin(), domain.end());
  input.insert(input.end(), payload.begin(), payload.end());
  std::array<uint8_t, EVP_MAX_MD_SIZE> digest{};
  unsigned int digest_size = 0;
  if (!HMAC(EVP_sha256(), attempt_id.data(), static_cast<int>(attempt_id.size()), input.data(),
            input.size(), digest.data(), &digest_size) ||
      digest_size < 16)
    return std::nullopt;
  std::array<uint8_t, 16> result{};
  std::copy_n(digest.begin(), result.size(), result.begin());
  return result;
#else
  (void)attempt_id;
  (void)domain;
  (void)payload;
  return std::nullopt;
#endif
}

std::array<uint8_t, 6> InviteLanSourceBytes(LanAddress source) {
  std::array<uint8_t, 6> bytes{};
  std::memcpy(bytes.data(), &source.ipv4, 4);
  const auto port = htons(source.port);
  std::memcpy(bytes.data() + 4, &port, 2);
  return bytes;
}

std::array<uint8_t, 74> InviteLanTupleBytes(const DiscoveryPacket& packet) {
  std::array<uint8_t, 74> bytes{};
  size_t offset = 0;
  auto append = [&](const void* data, size_t size) {
    std::memcpy(bytes.data() + offset, data, size);
    offset += size;
  };
  append(&packet.title_id, 4);
  append(packet.session_id, 8);
  append(packet.session_key, 16);
  append(&packet.host_xuid, 8);
  append(&packet.host_ipv4, 4);
  append(&packet.host_port, 2);
  append(&packet.nonce, 8);
  append(&packet.host_machine_id, 8);
  append(packet.incarnation, 16);
  return bytes;
}

bool InviteLanEqual(const uint8_t* left, const uint8_t* right, size_t size) {
  uint8_t difference = 0;
  for (size_t i = 0; i < size; ++i)
    difference |= left[i] ^ right[i];
  return difference == 0;
}

bool InviteLanPacketValid(const InviteLanPacket& packet, uint8_t type) {
  return std::memcmp(packet.magic, "HILN", 4) == 0 && packet.version == 1 &&
         packet.type == type && packet.reserved == 0;
}

InviteLanPacket MakeInviteLanPacket(uint8_t type,
                                   const std::array<uint8_t, 16>& selector,
                                   const std::array<uint8_t, 16>& proof) {
  InviteLanPacket packet{};
  std::memcpy(packet.magic, "HILN", 4);
  packet.version = 1;
  packet.type = type;
  std::copy(selector.begin(), selector.end(), packet.selector);
  std::copy(proof.begin(), proof.end(), packet.proof);
  return packet;
}

uint64_t Swap64(uint64_t value) {
  const uint32_t high = htonl(static_cast<uint32_t>(value >> 32));
  const uint32_t low = htonl(static_cast<uint32_t>(value));
  return (uint64_t(low) << 32) | high;
}
ArbitrationIdentity WireIdentity(const DiscoveryPacket& packet) {
  ArbitrationIdentity result;
  std::copy_n(packet.session_id, 8, result.session_id.begin());
  std::copy_n(packet.session_key, 16, result.exchange_key.begin());
  std::copy_n(packet.incarnation, 16, result.incarnation.begin());
  result.nonce = Swap64(packet.nonce);
  result.host_xuid = Swap64(packet.host_xuid);
  result.host_machine_id = Swap64(packet.host_machine_id);
  return result;
}
ArbitrationIdentity RecordIdentity(const SessionRecord& record) {
  return {record.info.id, record.info.key, record.arbitration_incarnation,
          record.nonce, record.host_xuid, record.host_machine_id};
}
ArbitrationToken WireToken(const uint8_t* data) {
  ArbitrationToken result{}; std::copy_n(data, result.size(), result.begin()); return result;
}
bool NonzeroToken(const ArbitrationToken& value) { return value != ArbitrationToken{}; }
std::array<uint8_t, 148> JoinCredentialAAD(const DiscoveryPacket& packet) {
  std::array<uint8_t, 148> bytes{}; size_t offset = 0;
  const auto append = [&](const void* data, size_t length) {
    std::memcpy(bytes.data()+offset, data, length); offset += length;
  };
  append(&packet.title_id,4); append(packet.session_id,8); append(packet.session_key,16);
  append(&packet.host_xuid,8); append(&packet.nonce,8); append(&packet.host_machine_id,8);
  append(packet.incarnation,16); append(&packet.members[0].xuid,8);
  append(&packet.members[0].machine_id,8); append(packet.attempt,16);
  append(packet.client_public_key,32); append(packet.request_id,16); return bytes;
}
ArbitrationPublicKey WirePublicKey(const uint8_t* bytes) {
  ArbitrationPublicKey key{}; std::copy_n(bytes,key.size(),key.begin()); return key;
}

std::string TokenHex(const ArbitrationToken& token) {
  constexpr char digits[] = "0123456789abcdef";
  std::string key; key.reserve(32);
  for (uint8_t byte : token) { key += digits[byte >> 4]; key += digits[byte & 15]; }
  return key;
}
// Initial retries must retain both the challenge and the client's ephemeral
// public key. A new key cannot obtain an already admitted peer's token through
// the bounded unauthenticated lost-reply retry seam.
std::optional<ArbitrationToken> BoundJoinChallenge(const DiscoveryPacket& packet) {
  const auto challenge = WireToken(packet.attempt);
  if (!NonzeroToken(challenge)) return std::nullopt;
  return InviteLanMac(TokenHex(challenge), "session-admission-challenge-v2", packet.client_public_key);
}
bool SignPacket(DiscoveryPacket& packet, const ArbitrationToken& credential,
                std::string_view domain) {
  if (!NonzeroToken(credential)) return false;
  const auto key = TokenHex(credential);
  std::memset(packet.authentication, 0, sizeof(packet.authentication));
  const auto tag = InviteLanMac(key, domain,
      {reinterpret_cast<const uint8_t*>(&packet), sizeof(packet)});
  if (!tag) return false;
  std::copy(tag->begin(), tag->end(), packet.authentication); return true;
}
bool VerifyPacket(const DiscoveryPacket& packet, const ArbitrationToken& credential,
                  std::string_view domain) {
  auto expected = packet;
  return SignPacket(expected, credential, domain) &&
      InviteLanEqual(packet.authentication, expected.authentication, 16);
}
// A receipt contains correlation fields only: no advertised roster, envelope,
// credential bytes, or success state. Compare the entire canonical packet on
// receipt so future public packet fields cannot accidentally enter this path.
DiscoveryPacket ExpiredJoinReply(const DiscoveryPacket& request) {
  DiscoveryPacket reply{};
  reply.magic = request.magic;
  reply.version = request.version;
  reply.type = kJoinExpired;
  reply.title_id = request.title_id;
  std::copy_n(request.session_id, 8, reply.session_id);
  std::copy_n(request.session_key, 16, reply.session_key);
  reply.host_xuid = request.host_xuid;
  reply.nonce = request.nonce;
  reply.host_machine_id = request.host_machine_id;
  std::copy_n(request.incarnation, 16, reply.incarnation);
  // With member_count zero these fields identify the requester, not a roster.
  reply.members[0].xuid = request.members[0].xuid;
  reply.members[0].machine_id = request.members[0].machine_id;
  std::copy_n(request.attempt, 16, reply.attempt);
  std::copy_n(request.client_public_key, 32, reply.client_public_key);
  std::copy_n(request.request_id, 16, reply.request_id);
  return reply;
}
bool VerifyExpiredJoinReply(const DiscoveryPacket& response,
                            const DiscoveryPacket& request,
                            const ArbitrationToken& credential) {
  auto expected = ExpiredJoinReply(request);
  if (!SignPacket(expected, credential, "session-join-expired-v2")) return false;
  return InviteLanEqual(reinterpret_cast<const uint8_t*>(&response),
                        reinterpret_cast<const uint8_t*>(&expected), sizeof(expected));
}
void CloseSocket(SOCKET value) {
  if (value == kInvalidSocket)
    return;
#if REX_PLATFORM_WIN32
  closesocket(value);
#else
  close(value);
#endif
}
int ReceiveDatagram(SOCKET socket, char* buffer, size_t size, int flags,
                    sockaddr* source, socket_len_t* source_length) {
#if REX_PLATFORM_GNU_LINUX
  // Linux otherwise reports the copied prefix length for oversized UDP. That
  // prefix can look exactly like a valid discovery packet. Preserve Winsock's
  // rejection of an oversized datagram instead of parsing a truncated frame.
  const auto received = recvfrom(socket, buffer, size, flags | MSG_TRUNC, source, source_length);
  if (received > static_cast<decltype(received)>(size)) {
    errno = EMSGSIZE;
    return -1;
  }
  return static_cast<int>(received);
#elif REX_PLATFORM_MAC
  // Same Winsock-style rejection; Darwin reports truncation only via recvmsg.
  const auto received = rex::net::mac::ReceiveReportingTruncation(socket, buffer, size, flags,
                                                                 source, source_length);
  if (received > static_cast<decltype(received)>(size)) {
    errno = EMSGSIZE;
    return -1;
  }
  return static_cast<int>(received);
#else
  return recvfrom(socket, buffer, static_cast<int>(size), flags, source, source_length);
#endif
}
bool SetNonBlocking(SOCKET value) {
#if REX_PLATFORM_WIN32
  u_long enabled = 1;
  return ioctlsocket(value, FIONBIO, &enabled) == 0;
#else
  int flags = fcntl(value, F_GETFL, 0);
  const int descriptor_flags = fcntl(value,F_GETFD,0);
  return flags >= 0 && descriptor_flags >= 0 &&
      fcntl(value,F_SETFD,descriptor_flags | FD_CLOEXEC) == 0 &&
      fcntl(value, F_SETFL, flags | O_NONBLOCK) == 0;
#endif
}
bool IsPrivateLanIpv4(uint32_t network_address) {
  uint32_t address = ntohl(network_address);
  return (address & 0xFF000000u) == 0x0A000000u || (address & 0xFFF00000u) == 0xAC100000u ||
         (address & 0xFFFF0000u) == 0xC0A80000u;
}
bool BindLanSocket(SOCKET socket, uint16_t port) {
  sockaddr_in address{};
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = LanDiscoveryService::DetermineLanIpv4();
  address.sin_port = htons(port);
  return bind(socket, reinterpret_cast<sockaddr*>(&address), sizeof(address)) == 0;
}
bool IsLocallyBindableIpv4(uint32_t network_address) {
  SOCKET socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (socket == kInvalidSocket)
    return false;
  sockaddr_in address{};
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = network_address;
  address.sin_port = 0;
  bool bindable = bind(socket, reinterpret_cast<sockaddr*>(&address), sizeof(address)) == 0;
  CloseSocket(socket);
  return bindable;
}
DiscoveryPacket Encode(const SessionRecord& session, uint32_t title_id) {
  std::lock_guard lock(*session.mutex);
  DiscoveryPacket packet{};
  packet.magic = htonl(kDiscoveryMagic);
  packet.version = htons(kDiscoveryVersion);
  packet.type = kAdvertisement;
  packet.title_id = htonl(title_id);
  std::memcpy(packet.session_id, session.info.id.data(), 8);
  std::memcpy(packet.session_key, session.info.key.data(), 16);
  packet.host_xuid = Swap64(session.host_xuid);
  packet.nonce = Swap64(session.nonce);
  packet.host_machine_id = Swap64(session.host_machine_id);
  std::copy(session.arbitration_incarnation.begin(), session.arbitration_incarnation.end(), packet.incarnation);
  packet.host_ipv4 = session.info.host_address.ipv4;
  packet.host_port = htons(session.info.host_address.port);
  packet.flags = htonl(session.flags);
  packet.public_slots = htonl(session.max_public_slots);
  packet.private_slots = htonl(session.max_private_slots);
  packet.member_count = htonl(uint32_t(std::min(session.members.size(), kMaxWireMembers)));
  std::strncpy(packet.host_name, session.host_name.c_str(), sizeof(packet.host_name) - 1);
  for (size_t i = 0; i < std::min(session.members.size(), kMaxWireMembers); ++i) {
    const auto& source = session.members[i];
    packet.members[i].xuid = Swap64(source.xuid);
    packet.members[i].machine_id = Swap64(source.machine_id);
    const auto address = source.xuid == session.host_xuid ? session.info.host_address : source.gameplay_address;
    packet.members[i].gameplay_ipv4 = address.ipv4;
    packet.members[i].gameplay_port = htons(address.port);
    packet.members[i].flags = htonl((source.local ? 1u : 0u) | (source.private_slot ? 2u : 0u) |
                                    (source.ready ? 4u : 0u));
    std::strncpy(packet.members[i].name, source.name.c_str(), sizeof(packet.members[i].name) - 1);
  }
  return packet;
}
std::optional<SessionRecord> Decode(const DiscoveryPacket& packet, uint32_t title_id,
                                    uint32_t source_ipv4) {
  if (ntohl(packet.magic) != kDiscoveryMagic || ntohs(packet.version) != kDiscoveryVersion ||
      packet.type != kAdvertisement || ntohl(packet.title_id) != title_id ||
      packet.reserved || packet.reserved2 || packet.reserved3)
    return std::nullopt;
  SessionRecord session;
  std::memcpy(session.info.id.data(), packet.session_id, 8);
  std::memcpy(session.info.key.data(), packet.session_key, 16);
  session.host_xuid = Swap64(packet.host_xuid);
  session.nonce = Swap64(packet.nonce);
  session.host_machine_id = Swap64(packet.host_machine_id);
  std::copy_n(packet.incarnation, 16, session.arbitration_incarnation.begin());
  const auto xnaddr = ReconstructXnAddrIdentity(session.host_xuid);
  session.info.ethernet_address = xnaddr.ethernet_address;
  session.info.online_address = xnaddr.online_address;
  session.host_name.assign(packet.host_name, strnlen(packet.host_name, sizeof(packet.host_name)));
  session.info.host_address = {packet.host_ipv4 ? packet.host_ipv4 : source_ipv4,
                               ntohs(packet.host_port)};
  session.flags = ntohl(packet.flags);
  session.max_public_slots = ntohl(packet.public_slots);
  session.max_private_slots = ntohl(packet.private_slots);
  const uint32_t count = ntohl(packet.member_count);
  if (count > kMaxWireMembers || !session.host_xuid)
    return std::nullopt;
  for (uint32_t i = 0; i < count; ++i) {
    uint32_t flags = ntohl(packet.members[i].flags);
    if ((flags & ~7u) || packet.members[i].reserved)
      return std::nullopt;
    session.members.push_back(
        {Swap64(packet.members[i].xuid),
         std::string(packet.members[i].name,
                     strnlen(packet.members[i].name, sizeof(packet.members[i].name))),
         0, false, (flags & 2) != 0, (flags & 4) != 0});
    session.members.back().machine_id = Swap64(packet.members[i].machine_id);
    session.members.back().gameplay_address = {packet.members[i].gameplay_ipv4,
                                              ntohs(packet.members[i].gameplay_port)};
  }
  if (session.members.empty())
    session.members.push_back({session.host_xuid, session.host_name, 0, false, false, false});
  if (!ValidMemberAccounting(session.members, session.max_public_slots, session.max_private_slots))
    return std::nullopt;
  return session;
}

std::optional<SessionRecord> Exchange(const SessionRecord& session, const SessionMember* member,
                                      uint8_t type, uint32_t title_id, uint16_t discovery_port,
                                      uint32_t timeout_ms,
                                      SOCKET retained_socket = kInvalidSocket,
                                      std::shared_ptr<ArbitrationClientBinding> binding = {},
                                      const ClientAdmissionSocketLease* admission_lease = nullptr,
                                      bool* expired_join = nullptr) {
  if ((admission_lease && !admission_lease->active()) || !EnsureSocketRuntime())
    return std::nullopt;
  const bool owns_socket = retained_socket == kInvalidSocket;
  SOCKET socket = owns_socket ? ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP) : retained_socket;
  if (socket == kInvalidSocket)
    return std::nullopt;
  if (owns_socket && !BindLanSocket(socket, 0)) {
    REXSYS_ERROR("LAN discovery: failed to bind join socket to configured interface");
    CloseSocket(socket);
    return std::nullopt;
  }
  SetNonBlocking(socket);
  auto packet = Encode(session, title_id);
  const auto request_id = NewArbitrationToken();
  if (!request_id) { if (owns_socket) CloseSocket(socket); return std::nullopt; }
  std::copy(request_id->begin(),request_id->end(),packet.request_id);
  packet.type = type;
  if (member) {
    packet.member_count = htonl(1);
    std::memset(packet.members, 0, sizeof(packet.members));
    packet.members[0].xuid = Swap64(member->xuid);
    packet.members[0].machine_id = Swap64(binding ? binding->machine_id : member->machine_id);
    packet.members[0].gameplay_port = htons(uint16_t(REXCVAR_GET(lan_gameplay_port) ? REXCVAR_GET(lan_gameplay_port) : 3074));
    packet.members[0].flags = htonl((member->private_slot ? 2u : 0u) | (member->ready ? 4u : 0u));
    std::strncpy(packet.members[0].name, member->name.c_str(), sizeof(packet.members[0].name) - 1);
  }
  if (binding) {
    std::copy(binding->challenge.begin(), binding->challenge.end(), packet.attempt);
    if (type == kJoin) {
      if (!binding->key || !binding->key->valid()) {
        if (owns_socket) CloseSocket(socket);
        return std::nullopt;
      }
      std::copy(binding->key->public_key().begin(), binding->key->public_key().end(), packet.client_public_key);
    }
    if ((type == kLeave || NonzeroToken(binding->credential)) &&
        !SignPacket(packet, binding->credential, type == kJoin ? "session-join-v2" : "session-leave-v2")) {
      if (owns_socket) CloseSocket(socket);
      return std::nullopt;
    }
  }
  sockaddr_in target{};
  target.sin_family = AF_INET;
  uint32_t target_ipv4 = session.discovery_address.ipv4 ? session.discovery_address.ipv4
                                                        : session.info.host_address.ipv4;
  uint16_t target_port =
      session.discovery_address.port ? session.discovery_address.port : discovery_port;
  if (auto peer = NatProbePeer(socket)) {
    target_ipv4 = peer->ipv4;
    target_port = peer->port;
    REXSYS_INFO("NAT traversal: Join using acknowledged discovery endpoint {:08X}:{}", target_ipv4,
                target_port);
  }
  target.sin_addr.s_addr = target_ipv4;
  target.sin_port = htons(target_port);
  int sent = sendto(socket, reinterpret_cast<const char*>(&packet), sizeof(packet), 0,
                    reinterpret_cast<sockaddr*>(&target), sizeof(target));
  REXSYS_INFO("LAN discovery: {} request bytes={} to {:08X}:{} xuid={:016X}",
              type == kJoin ? "join" : "leave", sent, target.sin_addr.s_addr, target_port,
              member ? member->xuid : 0);
  auto deadline = std::chrono::steady_clock::now() + std::chrono::milliseconds(timeout_ms);
  std::optional<SessionRecord> result;
  auto next_send = std::chrono::steady_clock::now() + std::chrono::milliseconds(125);
  while (std::chrono::steady_clock::now() < deadline) {
    if (admission_lease && !admission_lease->active()) break;
    if (std::chrono::steady_clock::now() >= next_send) {
      sendto(socket, reinterpret_cast<const char*>(&packet), sizeof(packet), 0,
             reinterpret_cast<sockaddr*>(&target), sizeof(target));
      next_send = std::chrono::steady_clock::now() + std::chrono::milliseconds(125);
    }
    sockaddr_in source{};
    socket_len_t length = sizeof(source);
    DiscoveryPacket response{};
    int count = ReceiveDatagram(socket, reinterpret_cast<char*>(&response), sizeof(response), 0,
                         reinterpret_cast<sockaddr*>(&source), &length);
    if (count > 0 && NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&response), count,
                                     source.sin_addr.s_addr, ntohs(source.sin_port))) {
      NatProbeTick(socket);
      continue;
    }
    if (count == sizeof(response) && source.sin_addr.s_addr == target.sin_addr.s_addr &&
        source.sin_port == target.sin_port) {
      if ((admission_lease && !admission_lease->active()) ||
          WireIdentity(response) != RecordIdentity(session) || WireToken(response.request_id) != *request_id) continue;
      if (binding && type == kJoin && response.type == kJoinExpired) {
        if (!binding->confirmed && NonzeroToken(binding->credential) &&
            VerifyExpiredJoinReply(response, packet, binding->credential)) {
          if (expired_join) *expired_join = true;
          break;
        }
        continue;
      }
      if (binding) {
        auto credential = binding->credential;
        if (type == kJoin) {
          if (!binding->key || WirePublicKey(response.client_public_key) != binding->key->public_key()) continue;
          ArbitrationCredentialEnvelope envelope;
          envelope.server_public_key = WirePublicKey(response.server_public_key);
          envelope.ciphertext = WireToken(response.credential);
          std::copy_n(response.credential_iv,12,envelope.iv.begin());
          envelope.tag = WireToken(response.credential_tag);
          const auto opened = OpenArbitrationCredential(*binding->key,envelope,JoinCredentialAAD(packet));
          if (!opened) continue;
          credential = *opened;
        }
        if (WireToken(response.attempt) != binding->challenge ||
            !VerifyPacket(response, credential, type == kJoin ? "session-join-reply-v2" : "session-leave-reply-v2")) continue;
        if (type == kJoin) { binding->credential = credential; binding->credential_received = true; }
      }
      result = Decode(response, title_id, source.sin_addr.s_addr);
      if (result) {
        // Preserve the endpoint that successfully reached this session. A
        // direct-connect search may have intentionally replaced the address
        // embedded by a multi-homed host.
        result->info.host_address.ipv4 = session.info.host_address.ipv4;
        result->discovery_address = session.discovery_address;
        result->traversal_session_id = session.traversal_session_id;
        result->traversal_attempt_id = session.traversal_attempt_id;
        result->traversal_capability = session.traversal_capability;
        if (binding && type == kJoin) {
          binding->target = {source.sin_addr.s_addr, ntohs(source.sin_port)};
          result->arbitration_client = binding;
        }
      }
      if (result && (result->info.id != session.info.id || result->info.key != session.info.key ||
                     result->host_xuid != session.host_xuid))
        result.reset();
      if (result && member && type == kJoin &&
          std::none_of(result->members.begin(), result->members.end(),
                       [&](const auto& value) { return value.xuid == member->xuid; }))
        result.reset();
      if (result) {
        REXSYS_INFO("LAN discovery: {} response from {:08X}:{} members={}",
                    type == kJoin ? "join" : "leave", source.sin_addr.s_addr,
                    ntohs(source.sin_port), result->members.size());
        break;
      }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
  if (owns_socket)
    CloseSocket(socket);
  if (!result)
    REXSYS_WARN("LAN discovery: {} request timed out for {:08X}:{}",
                type == kJoin ? "join" : "leave", target_ipv4, target_port);
  return result;
}
}  // namespace

std::optional<std::array<uint8_t, 16>> InviteLanAuthenticationTag(
    std::string_view attempt_id, std::string_view domain,
    std::span<const uint8_t> payload) {
  return InviteLanMac(attempt_id, domain, payload);
}

XnAddrIdentity ReconstructXnAddrIdentity(uint64_t xuid) {
  XnAddrIdentity result;
  for (size_t i = 0; i < result.ethernet_address.size(); ++i)
    result.ethernet_address[i] = uint8_t(xuid >> (i * 8));
  std::memcpy(result.online_address.data(), &xuid, sizeof(xuid));
  return result;
}

std::array<uint8_t, 60> SerializeGuestSessionInfo(const SessionInfo& info) {
  std::array<uint8_t, 60> output{};
  std::memcpy(output.data(), info.id.data(), info.id.size());
  std::memcpy(output.data() + 8, &info.host_address.ipv4, 4);
  std::memcpy(output.data() + 12, &info.host_address.ipv4, 4);
  output[16] = uint8_t(info.host_address.port >> 8);
  output[17] = uint8_t(info.host_address.port);
  std::memcpy(output.data() + 18, info.ethernet_address.data(), 6);
  std::memcpy(output.data() + 24, info.online_address.data(), 20);
  std::memcpy(output.data() + 44, info.key.data(), 16);
  return output;
}

std::optional<AcceptedInviteRecord> SerializeAcceptedInviteRecord(
    const ReadyConfiguredInvite& ready) {
  if (!ready.host_ready || !ready.private_allocation_eligible ||
      !ready.operation.local_xuid || !ready.host_xuid || !ready.operation.title_id ||
      !ready.client_admission_lifecycle_token ||
      ready.xnaddr != ReconstructXnAddrIdentity(ready.host_xuid))
    return std::nullopt;
  SessionInfo info;
  info.id = ready.xbox_session_id;
  info.host_address = ready.host_endpoint;
  info.ethernet_address = ready.xnaddr.ethernet_address;
  info.online_address = ready.xnaddr.online_address;
  info.key = ready.exchange_key;
  AcceptedInviteRecord record{};
  auto store64 = [&](size_t offset, uint64_t value) {
    for (size_t i = 0; i < 8; ++i)
      record[offset + i] = uint8_t(value >> ((7 - i) * 8));
  };
  store64(0, ready.operation.local_xuid);
  store64(8, ready.host_xuid);
  for (size_t i = 0; i < 4; ++i)
    record[16 + i] = uint8_t(ready.operation.title_id >> ((3 - i) * 8));
  const auto guest_info = SerializeGuestSessionInfo(info);
  std::memcpy(record.data() + 20, guest_info.data(), guest_info.size());
  record[83] = 1;
  return record;
}

bool ApplyDiscoveryMemberBatch(SessionRecord& session, std::span<const SessionMember> members,
                               DiscoveryAdmissionContext context) {
  return ApplyMemberBatch(session, members,
                          context.source == DiscoveryAdmissionSource::kInviteGrant
                              ? MemberUpdateSource::kInviteGrant
                              : MemberUpdateSource::kDiscoveryPublic);
}

uint32_t SessionRecord::FilledPublicSlots() const {
  std::lock_guard lock(*mutex);
  return uint32_t(
      std::count_if(members.begin(), members.end(), [](const auto& m) { return !m.private_slot; }));
}
uint32_t SessionRecord::FilledPrivateSlots() const {
  std::lock_guard lock(*mutex);
  return uint32_t(
      std::count_if(members.begin(), members.end(), [](const auto& m) { return m.private_slot; }));
}
uint32_t SessionRecord::OpenPublicSlots() const {
  std::lock_guard lock(*mutex);
  return max_public_slots > FilledPublicSlots() ? max_public_slots - FilledPublicSlots() : 0;
}
uint32_t SessionRecord::OpenPrivateSlots() const {
  std::lock_guard lock(*mutex);
  return max_private_slots > FilledPrivateSlots() ? max_private_slots - FilledPrivateSlots() : 0;
}
SessionRegistry::SessionRegistry(ChangeObserver observer)
    : machine_id_(NewArbitrationMachineId().value_or(0)), change_observer_(std::move(observer)) {}

uint64_t SessionRegistry::IdKey(const std::array<uint8_t, 8>& id) {
  uint64_t key;
  std::memcpy(&key, id.data(), 8);
  return key;
}
std::shared_ptr<SessionRecord> SessionRegistry::Create(uint64_t host_xuid, std::string host_name,
                                                       LanAddress host_address, uint32_t flags,
                                                       uint32_t public_slots,
                                                       uint32_t private_slots) {
  auto session = std::make_shared<SessionRecord>();
  const auto random_id = NewArbitrationToken();
  const auto random_key = NewArbitrationToken();
  const auto incarnation = NewArbitrationToken();
  const auto local_credential = NewArbitrationToken();
  const auto nonce = NewArbitrationMachineId();
  if (!machine_id_ || !random_id || !random_key || !incarnation || !local_credential || !nonce)
    return nullptr;
  std::copy_n(random_id->begin(), session->info.id.size(), session->info.id.begin());
  if (!IdKey(session->info.id)) return nullptr;
  session->info.key = *random_key;
  session->nonce = *nonce;
  session->host_machine_id = machine_id_;
  session->arbitration_incarnation = *incarnation;
  session->host_xuid = host_xuid;
  session->host_name = std::move(host_name);
  session->info.host_address = host_address;
  const auto xnaddr = ReconstructXnAddrIdentity(host_xuid);
  session->info.ethernet_address = xnaddr.ethernet_address;
  session->info.online_address = xnaddr.online_address;
  session->flags = flags;
  session->max_public_slots = public_slots;
  session->max_private_slots = private_slots;
  session->members.push_back({host_xuid, session->host_name, 0, true, false, false});
  session->members.back().machine_id = machine_id_;
  session->members.back().gameplay_address = host_address;
  session->arbitration = std::make_shared<SessionArbitrationAuthority>(
      ArbitrationIdentity{session->info.id, session->info.key, *incarnation, session->nonce,
                          host_xuid, machine_id_}, *local_credential);
  std::lock_guard lock(mutex_);
  auto id_key = IdKey(session->info.id);
  if (sessions_.contains(id_key) || local_session_ids_.contains(id_key)) return nullptr;
  local_session_ids_.insert(id_key);
  sessions_[id_key] = session;
  return session;
}
bool SessionRegistry::Delete(const std::array<uint8_t, 8>& id) {
  {
    std::lock_guard lock(mutex_);
    auto it = sessions_.find(IdKey(id));
    if (it == sessions_.end())
      return false;
    std::lock_guard session_lock(*it->second->mutex);
    it->second->state = SessionState::kDeleted;
    if (it->second->arbitration) it->second->arbitration->Invalidate();
    it->second->NotifyStatus();
    sessions_.erase(it);
  }
  if (change_observer_)
    change_observer_(id);
  return true;
}
size_t SessionRegistry::DeleteHostedBy(uint64_t host_xuid) {
  std::vector<std::array<uint8_t, 8>> deleted;
  size_t removed = 0;
  {
    std::lock_guard lock(mutex_);
    for (auto it = sessions_.begin(); it != sessions_.end();) {
      std::lock_guard session_lock(*it->second->mutex);
      if (it->second->host_xuid == host_xuid) {
        deleted.push_back(it->second->info.id);
        it->second->state = SessionState::kDeleted;
        if (it->second->arbitration) it->second->arbitration->Invalidate();
        it->second->NotifyStatus();
        it = sessions_.erase(it);
        ++removed;
      } else {
        ++it;
      }
    }
  }
  if (change_observer_)
    for (const auto& id : deleted)
      change_observer_(id);
  return removed;
}
size_t SessionRegistry::UpdateHostedPort(uint64_t host_xuid, uint16_t port) {
  std::lock_guard lock(mutex_);
  size_t updated = 0;
  for (auto& [_, session] : sessions_) {
    std::lock_guard session_lock(*session->mutex);
    if (session->host_xuid == host_xuid && session->state != SessionState::kDeleted) {
      if (!port) continue;
      const LanAddress endpoint{session->info.host_address.ipv4, port};
      if (session->private_lan_authority && session->info.host_address != endpoint) {
        // The real title advertises before binding. Publish the physical port
        // and the authority's future encrypted tickets together. An active
        // peer route cannot be redirected by rebinding a local socket.
        auto prepared=session->private_lan_authority->PrepareHostEndpoint(endpoint);
        if(!prepared||!prepared->CommitIf([&]() noexcept {
          session->info.host_address=endpoint;
          for(auto& member:session->members)
            if(member.xuid==host_xuid)member.gameplay_address=endpoint;
          return true;
        }))continue;
      } else {
        session->info.host_address=endpoint;
        for(auto& member:session->members)
          if(member.xuid==host_xuid)member.gameplay_address=endpoint;
      }
      ++updated;
    }
  }
  return updated;
}
size_t SessionRegistry::UpdateRemoteGameplayEndpoint(uint64_t local_xuid, LanAddress address) {
  std::lock_guard lock(mutex_);
  size_t updated = 0;
  for (auto& [id, session] : sessions_) {
    std::lock_guard session_lock(*session->mutex);
    if (session->host_xuid != local_xuid && !local_session_ids_.contains(id) &&
        session->state != SessionState::kDeleted && session->info.host_address != address) {
      session->info.host_address = address;
      ++updated;
    }
  }
  return updated;
}
std::shared_ptr<SessionRecord> SessionRegistry::Find(const std::array<uint8_t, 8>& id) const {
  std::lock_guard lock(mutex_);
  auto it = sessions_.find(IdKey(id));
  return it == sessions_.end() ? nullptr : it->second;
}
std::vector<std::shared_ptr<SessionRecord>> SessionRegistry::List() const {
  std::lock_guard lock(mutex_);
  std::vector<std::shared_ptr<SessionRecord>> result;
  for (const auto& [_, session] : sessions_)
    result.push_back(session);
  return result;
}
std::vector<std::shared_ptr<SessionRecord>> SessionRegistry::ListRemote(uint64_t local_xuid) const {
  std::lock_guard registry_lock(mutex_);
  std::vector<std::shared_ptr<SessionRecord>> result;
  for (const auto& [id, session] : sessions_) {
    std::lock_guard lock(*session->mutex);
    if (session->host_xuid != local_xuid && !local_session_ids_.contains(id) &&
        session->state != SessionState::kDeleted)
      result.push_back(session);
  }
  return result;
}
bool SessionRegistry::Join(const std::array<uint8_t, 8>& id, SessionMember member) {
  return JoinBatch(Find(id), std::span<const SessionMember>(&member, 1));
}
bool SessionRegistry::JoinBatch(const std::shared_ptr<SessionRecord>& expected,
                                std::span<const SessionMember> members) {
  if (!expected)
    return false;
  // Registry -> record is the existing deletion lock order. No NAT, grant, or
  // network operation occurs while either lock is held.
  std::lock_guard registry_lock(mutex_);
  auto it = sessions_.find(IdKey(expected->info.id));
  if (it == sessions_.end() || it->second != expected)
    return false;
  return ApplyMemberBatch(*expected, members, MemberUpdateSource::kTitleAllocatedPool);
}
bool SessionRegistry::Leave(const std::array<uint8_t, 8>& id, uint64_t xuid) {
  auto session = Find(id);
  if (!session)
    return false;
  std::lock_guard lock(*session->mutex);
  if(session->private_lan_authority&&xuid!=session->host_xuid)return false;
  if(session->private_lan_client&&session->private_lan_client->xuid()==xuid) {
    session->private_lan_client.reset();session->private_lan_gameplay.reset();
  }
  size_t before = session->members.size();
  std::erase_if(session->members, [&](const auto& m) { return m.xuid == xuid; });
  if (session->arbitration) session->arbitration->Remove(xuid);
  if (session->arbitration_client && session->arbitration_client->xuid == xuid)
    session->arbitration_client.reset();
  session->arbitration_revision = 0;
  if (before != session->members.size()) session->NotifyStatus();
  return before != session->members.size();
}
bool SessionRegistry::Modify(const std::array<uint8_t, 8>& id, uint32_t flags,
                             uint32_t public_slots, uint32_t private_slots) {
  auto session = Find(id);
  if (!session)
    return false;
  std::lock_guard lock(*session->mutex);
  if (public_slots < session->FilledPublicSlots() || private_slots < session->FilledPrivateSlots())
    return false;
  session->flags = flags;
  session->max_public_slots = public_slots;
  session->max_private_slots = private_slots;
  session->NotifyStatus();
  return true;
}
bool SessionRegistry::Start(const std::array<uint8_t, 8>& id) {
  auto session = Find(id);
  if (!session)
    return false;
  std::lock_guard lock(*session->mutex);
  session->state = SessionState::kInGame;
  session->NotifyStatus();
  return true;
}
bool SessionRegistry::End(const std::array<uint8_t, 8>& id) {
  auto session = Find(id);
  if (!session)
    return false;
  std::lock_guard lock(*session->mutex);
  session->state = SessionState::kReporting;
  session->NotifyStatus();
  return true;
}
std::shared_ptr<SessionRecord> SessionRegistry::UpsertDiscovered(SessionRecord record) {
  // Public discovery can create a fresh observation after a user leaves.
  // A joined/pending binding must instead publish through the exact retained
  // record commit, so late joined output can never create or revive a record.
  if (record.arbitration_client || record.private_lan_client || record.private_lan_gameplay || record.private_lan_authority) return nullptr;
  auto session = std::make_shared<SessionRecord>(std::move(record));
  {
    std::lock_guard lock(mutex_);
    auto id_key = IdKey(session->info.id);
    if (local_session_ids_.contains(id_key))
      return nullptr;
    auto existing = sessions_.find(id_key);
    if (existing != sessions_.end()) {
      std::lock_guard existing_lock(*existing->second->mutex);
      // A public Search observation cannot replace an exact invite correlation
      // with the same Xbox session ID or redirect its endpoint.
      if (!existing->second->traversal_attempt_id.empty() &&
          session->traversal_attempt_id.empty())
        return existing->second;
      if (existing->second->arbitration_client || existing->second->private_lan_client) {
        if (RecordIdentity(*existing->second) != RecordIdentity(*session)) return nullptr;
        return existing->second;
      }
    }
    sessions_[id_key] = session;
  }
  if (change_observer_)
    change_observer_(session->info.id);
  return session;
}

bool SessionRegistry::WithNoLiveLocalMember(const std::function<void()>& mutation) {
  std::lock_guard registry_lock(mutex_);
  std::vector<std::unique_lock<std::recursive_mutex>> record_locks;
  record_locks.reserve(sessions_.size());
  for (const auto& [id, session] : sessions_) {
    if (!session) continue;
    record_locks.emplace_back(*session->mutex);
    if (session->state != SessionState::kDeleted &&
        std::any_of(session->members.begin(), session->members.end(),
                    [](const auto& member) { return member.local; }))
      return false;
  }
  mutation();
  return true;
}

bool SessionRegistry::CommitJoinedRecord(const std::shared_ptr<SessionRecord>& expected,
    SessionRecord updated, const std::function<bool()>& object_current) {
  if(updated.private_lan_invitation) {
    if(!expected||!object_current||!updated.private_lan_client||!updated.private_lan_client->Confirmed()||!updated.private_lan_gameplay)return false;
    auto global_lock=rex::thread::global_critical_region::AcquireDirect();std::lock_guard registry_lock(mutex_);
    const auto found=sessions_.find(IdKey(expected->info.id));if(found==sessions_.end()||found->second!=expected)return false;
    struct Commit {SessionRecord* expected;SessionRecord* updated;const std::function<bool()>* object_current;bool accounting;};
    Commit commit{expected.get(),&updated,&object_current,ValidMemberAccounting(updated.members,updated.max_public_slots,updated.max_private_slots)};const auto authorization=updated.private_lan_gameplay;
    const bool okay=CommitPrivateLanGameplayAuthorization(expected,*authorization,std::move(updated.members),[](void* context) noexcept {
      auto& c=*static_cast<Commit*>(context);auto& e=*c.expected;auto& u=*c.updated;
      e.info=u.info;e.discovery_address=u.discovery_address;e.host_name=std::move(u.host_name);e.flags=u.flags;
      e.max_public_slots=u.max_public_slots;e.max_private_slots=u.max_private_slots;e.private_lan_invitation=std::move(u.private_lan_invitation);
      e.private_lan_gameplay=std::move(u.private_lan_gameplay);e.arbitration_revision=0;return true;
    },&commit,[](void* context) noexcept {try {
      auto& c=*static_cast<Commit*>(context);return c.expected->state!=SessionState::kDeleted&&!c.expected->arbitration&&
        RecordIdentity(*c.expected)==RecordIdentity(*c.updated)&&c.expected->private_lan_client==c.updated->private_lan_client&&
        (*c.object_current)()&&c.accounting;
      }catch(...){return false;}});
    if(okay)expected->NotifyStatus();return okay;
  }
  if (!expected || !object_current || !updated.arbitration_client || !updated.arbitration_client->confirmed) return false;
  auto global_lock = rex::thread::global_critical_region::AcquireDirect();
  std::lock_guard registry_lock(mutex_);
  const auto found = sessions_.find(IdKey(expected->info.id));
  if (found == sessions_.end() || found->second != expected) return false;
  std::lock_guard record_lock(*expected->mutex);
  if (expected->state == SessionState::kDeleted || expected->arbitration ||
      RecordIdentity(*expected) != RecordIdentity(updated) ||
      expected->arbitration_client != updated.arbitration_client ||
      !object_current() || !ValidMemberAccounting(updated.members,updated.max_public_slots,updated.max_private_slots)) return false;
  expected->info = updated.info;
  expected->discovery_address = updated.discovery_address;
  expected->host_name = std::move(updated.host_name);
  expected->flags = updated.flags;
  expected->max_public_slots = updated.max_public_slots;
  expected->max_private_slots = updated.max_private_slots;
  expected->members = std::move(updated.members);
  expected->arbitration_revision = 0;
  expected->NotifyStatus();
  return true;
}

bool SessionRegistry::CommitArbitration(const std::shared_ptr<SessionRecord>& expected,
    const ArbitrationIdentity& identity, uint64_t revision, const std::function<bool()>& publish) {
  if (!expected || !publish) return false;
  auto global = rex::thread::global_critical_region::AcquireDirect();
  std::lock_guard registry_lock(mutex_);
  const auto found = sessions_.find(IdKey(identity.session_id));
  if (found == sessions_.end() || found->second != expected) return false;
  std::lock_guard record_lock(*expected->mutex);
  if (expected->state == SessionState::kDeleted ||
      expected->info.id != identity.session_id || expected->info.key != identity.exchange_key ||
      expected->nonce != identity.nonce || expected->host_xuid != identity.host_xuid ||
      expected->host_machine_id != identity.host_machine_id ||
      expected->arbitration_incarnation != identity.incarnation) return false;
  if (!revision) return false;
  if (expected->arbitration) {
    const auto current = expected->arbitration->Snapshot();
    if (!current || current->identity != identity || current->revision != revision) return false;
  } else if (expected->arbitration_revision != revision) return false;
  if (!publish()) return false;
  if (expected->state == SessionState::kLobby) {
    expected->state = SessionState::kRegistration;
    expected->NotifyStatus();
  }
  return true;
}

std::optional<uint64_t> SessionRegistry::FindArbitrationMachineId(
    const XnAddrIdentity& identity, uint32_t ipv4, uint16_t port, uint64_t local_xuid) const {
  if (!ipv4 || !port || !local_xuid) return std::nullopt;
  std::optional<uint64_t> result;
  if (machine_id_ && port == 3074 && identity == ReconstructXnAddrIdentity(local_xuid) &&
      ipv4 == LanDiscoveryService::DetermineLanIpv4()) result = machine_id_;
  std::lock_guard registry_lock(mutex_);
  for (const auto& [key, session] : sessions_) {
    std::lock_guard record_lock(*session->mutex);
    if (session->state == SessionState::kDeleted) continue;
    for (const auto& member : session->members) {
      if (!member.machine_id || identity != ReconstructXnAddrIdentity(member.xuid)) continue;
      const auto address = member.xuid == session->host_xuid ? session->info.host_address : member.gameplay_address;
      // XNetGetTitleXnAddr exposes3074 to the title even when native UDP
      // port mapping uses a different bound port. Both are explicit aliases
      // of this exact known machine/IP; no arbitrary-port match is allowed.
      if (ipv4 != address.ipv4 || (port != address.port && port != 3074)) continue;
      if (result && *result != member.machine_id) return std::nullopt;
      result = member.machine_id;
    }
  }
  return result;
}

class LanDiscoveryService::Impl {
 public:
  Impl(uint32_t title_id, uint16_t port,
       std::shared_ptr<HostAdmissionGrantStore> admission_grants)
      : title_id(title_id), port(port), admission_grants(std::move(admission_grants)) {
    private_configured=!REXCVAR_GET(private_lan_invitation_file).empty();
    legacy_diagnostics=REXCVAR_GET(private_lan_allow_legacy_diagnostics);
    if(private_configured){auto invitation=PrivateLanInvitation::Load(REXCVAR_GET(private_lan_invitation_file));
      if(invitation)private_adapter=std::make_unique<PrivateLanDiscoveryAdapter>(title_id,port,machine_id,std::move(invitation));}
  }
  ~Impl() { Stop(); }
  bool Start(std::shared_ptr<SessionRecord> value) {
    if(private_configured)return private_adapter&&private_adapter->Start(value);
    if(!legacy_diagnostics&&REXCVAR_GET(session_directory_url).empty())return false;
    Stop();
    if (!EnsureSocketRuntime())
      return false;
    advertised = std::move(value);
    socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socket == kInvalidSocket)
      return false;
    int yes = 1;
    setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<const char*>(&yes), sizeof(yes));
#if REX_PLATFORM_MAC
    // BSD only shares a wildcard UDP port between listeners with SO_REUSEPORT;
    // Linux grants that with SO_REUSEADDR alone (several local instances).
    setsockopt(socket, SOL_SOCKET, SO_REUSEPORT, &yes, sizeof(yes));
#endif
    // Limited-broadcast reception requires a wildcard listener on Windows.
    // Outgoing search/join sockets and all advertised/gameplay addresses are
    // still bound to the explicitly selected physical interface.
    sockaddr_in listen_address{};
    listen_address.sin_family = AF_INET;
    listen_address.sin_addr.s_addr = htonl(INADDR_ANY);
    const auto& explicit_listener = REXCVAR_GET(lan_discovery_listen_address);
    if (!explicit_listener.empty() &&
        inet_pton(AF_INET, explicit_listener.c_str(), &listen_address.sin_addr) != 1) {
      REXSYS_ERROR("LAN discovery: invalid explicit listener address");
      CloseSocket(socket);
      socket = kInvalidSocket;
      return false;
    }
    listen_address.sin_port = htons(port);
    if (bind(socket, reinterpret_cast<sockaddr*>(&listen_address), sizeof(listen_address)) != 0) {
      REXSYS_ERROR("LAN discovery: failed to bind listener on UDP {} (error={})", port,
#if REX_PLATFORM_WIN32
                   WSAGetLastError()
#else
                   errno
#endif
      );
      CloseSocket(socket);
      socket = kInvalidSocket;
      return false;
    }
    SetNonBlocking(socket);
    sockaddr_in local_address{};
    socket_len_t local_length = sizeof(local_address);
    if (getsockname(socket, reinterpret_cast<sockaddr*>(&local_address), &local_length) == 0) {
      NatProbeAttach(socket, NatProbeRole::kDiscovery,
                     {local_address.sin_addr.s_addr, ntohs(local_address.sin_port)});
    }
    running = true;
    REXSYS_INFO("LAN discovery: advertising on UDP {} as {:08X}:{}", port,
                advertised->info.host_address.ipv4, advertised->info.host_address.port);
    thread = std::thread([this] { Run(); });
    return true;
  }
  void Stop() {
    if(private_adapter)private_adapter->Stop();
    running = false;
    if (thread.joinable())
      thread.join();
    CloseSocket(socket);
    NatProbeDetach(socket);
    socket = kInvalidSocket;
    advertised.reset();
    admission_grants->Clear();
    StopClient();
  }
  void StopClient() {
    if(private_adapter)private_adapter->StopClient();
    client_running = false;
    if (client_thread.joinable())
      client_thread.join();
    if (client_socket != kInvalidSocket) {
      const auto generation = retained_search.Retire();
      REXSYS_INFO("NAT traversal: retiring retained discovery search generation={} socket={}",
                  generation.value_or(0), client_socket);
      NatProbeDetach(client_socket);
      CloseSocket(client_socket);
      client_socket = kInvalidSocket;
    }
    for (const auto& attempt_id : client_attempt_ids)
      NatProbeRetireIdentity(attempt_id);
    client_attempt_ids.clear();
  }
  void RunClient() {
    while (client_running) {
      NatProbeTick(client_socket);
      if (!client_exchange) {
        sockaddr_in source{};
        socket_len_t length = sizeof(source);
        std::array<uint8_t, sizeof(DiscoveryPacket)> packet{};
        int count = ReceiveDatagram(client_socket, reinterpret_cast<char*>(packet.data()),
                             int(packet.size()), 0, reinterpret_cast<sockaddr*>(&source), &length);
        if (count > 0)
          NatProbeConsume(client_socket, packet.data(), count, source.sin_addr.s_addr,
                          ntohs(source.sin_port));
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
  }
  void Run() {
    auto next_expiration = std::chrono::steady_clock::time_point{};
    while (running) {
      NatProbeTick(socket);
      const auto now = std::chrono::steady_clock::now();
      if (now >= next_expiration && advertised) {
        std::lock_guard record_lock(*advertised->mutex);
        if (advertised->arbitration) {
          const auto expired = advertised->arbitration->ExpireUnconfirmed(now);
          if (!expired.empty()) {
            std::erase_if(advertised->members,[&](const auto& member) {
              return std::find(expired.begin(),expired.end(),member.xuid) != expired.end();
            });
            advertised->NotifyStatus();
          }
        }
        next_expiration = now + std::chrono::milliseconds(250);
      }
      sockaddr_in source{};
      socket_len_t length = sizeof(source);
      DiscoveryPacket query{};
      int count = ReceiveDatagram(socket, reinterpret_cast<char*>(&query), sizeof(query), 0,
                           reinterpret_cast<sockaddr*>(&source), &length);
      if (count > 0)
        REXSYS_INFO("NAT_DIAG discovery listener datagram socket={} source={:08X}:{} bytes={}",
                    uint64_t(socket), source.sin_addr.s_addr, ntohs(source.sin_port), count);
      if (count > 0 && NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&query), count,
                                       source.sin_addr.s_addr, ntohs(source.sin_port))) {
        continue;
      }
      if (count == sizeof(InviteLanPacket)) {
        InviteLanPacket invite_packet{};
        std::memcpy(&invite_packet, &query, sizeof(invite_packet));
        const LanAddress remote{source.sin_addr.s_addr, ntohs(source.sin_port)};
        if (!InviteLanPacketValid(invite_packet, kInviteLanRequest) ||
            (!IsPrivateLanIpv4(remote.ipv4) &&
             (ntohl(remote.ipv4) & 0xFF000000u) != 0x7F000000u) || !advertised) {
          REXSYS_INFO("INVITE_LAN_RESPONSE_REJECTED_MALFORMED");
          continue;
        }
        bool matched = false;
        for (const auto& attempt_id : NatProbeHostedInviteAttempts(uint64_t(socket))) {
          const auto selector = InviteLanMac(attempt_id, "invite-lan-selector-v1");
          const auto source_bytes = InviteLanSourceBytes(remote);
          const auto request_proof =
              InviteLanMac(attempt_id, "invite-lan-request-v1", source_bytes);
          if (!selector || !request_proof ||
              !InviteLanEqual(invite_packet.selector, selector->data(), selector->size()) ||
              !InviteLanEqual(invite_packet.proof, request_proof->data(),
                              request_proof->size()))
            continue;
          const std::array acknowledged{attempt_id};
          const auto hosted_session=admission_grants->hosted_directory_session();
          // The proof shows the joiner holds this server-issued attempt, the same
          // evidence an acknowledged public punch carries, so answer it before the
          // directory grant exists, as the public path does. Waiting for the grant
          // deadlocked: the server issues it only after the joiner arms admission,
          // which needs this answer first. A joiner behind the host's public
          // address (no hairpin NAT) has only this route.
          if (!legacy_diagnostics&&(!hosted_session||!admission_grants->HasCurrentPrivateDiscoveryGrant(*hosted_session,acknowledged)))
            REXSYS_INFO("INVITE_LAN_REQUEST_BEFORE_GRANT attempt_ref={} peer={:08X}:{}",
                        attempt_id.substr(0, 8), remote.ipv4, remote.port);
          DiscoveryPacket hosted_packet = Encode(*advertised, title_id);
          const auto tuple = InviteLanTupleBytes(hosted_packet);
          const auto response_proof =
              InviteLanMac(attempt_id, "invite-lan-response-v1", tuple);
          if (!response_proof)
            break;
          const auto reply = MakeInviteLanPacket(kInviteLanResponse, *selector,
                                                 *response_proof);
          const int sent = sendto(socket, reinterpret_cast<const char*>(&reply),
                                  sizeof(reply), 0,
                                  reinterpret_cast<sockaddr*>(&source), length);
          if (sent == sizeof(reply) &&
              NatProbeRegisterInviteLanPeer(uint64_t(socket), attempt_id, remote)) {
            REXSYS_INFO("INVITE_LAN_RESPONSE_SENT attempt_ref={} peer={:08X}:{}",
                        attempt_id.substr(0, 8), remote.ipv4, remote.port);
          }
          matched = true;
          break;
        }
        if (!matched)
          REXSYS_INFO("INVITE_LAN_RESPONSE_REJECTED_ATTEMPT_OR_PROOF");
        continue;
      }
      bool valid = count == sizeof(query) && ntohl(query.magic) == kDiscoveryMagic &&
                   ntohs(query.version) == kDiscoveryVersion && ntohl(query.title_id) == title_id &&
                   advertised;
      if (valid && query.type == kRegister) {
        std::optional<ArbitrationSnapshot> snapshot;
        ArbitrationToken credential{};
        std::optional<DiscoveryPacket> reply;
        {
          std::lock_guard record_lock(*advertised->mutex);
          const auto identity = WireIdentity(query);
          const auto xuid = Swap64(query.members[0].xuid);
          const auto machine = Swap64(query.members[0].machine_id);
          if (advertised->state != SessionState::kDeleted && advertised->arbitration &&
              identity == RecordIdentity(*advertised) && ntohl(query.member_count) == 1 &&
              !query.reserved && !query.reserved2 && !query.reserved3 &&
              query.members[0].flags == 0 && query.members[0].reserved == 0 &&
              !NonzeroToken(WireToken(query.credential)) &&
              NonzeroToken(WireToken(query.request_id))) {
            const auto private_token = advertised->arbitration->CredentialForVerification(identity, xuid, machine);
            if (private_token && VerifyPacket(query, *private_token, "session-register-v2")) {
              credential = *private_token;
              const auto status = advertised->arbitration->RegisterFromVerifiedEndpoint(
                  {identity, xuid, machine, {source.sin_addr.s_addr, ntohs(source.sin_port)},
                   credential, WireToken(query.attempt)});
              if (status == ArbitrationStatus::kAccepted || status == ArbitrationStatus::kReplay)
                snapshot = advertised->arbitration->Snapshot();
            }
          }
          if (snapshot) {
            auto response = Encode(*advertised, title_id);
            response.type = kRegisterReply;
            std::copy_n(query.attempt, 16, response.attempt);
            std::copy_n(query.request_id,16,response.request_id);
            response.revision = Swap64(snapshot->revision);
            uint32_t mask = 0;
            for (size_t i = 0; i < advertised->members.size() && i < kMaxWireMembers; ++i)
              for (const auto& registrant : snapshot->registrants)
                if (registrant.machine_id == advertised->members[i].machine_id &&
                    registrant.xuids.size() == 1 && registrant.xuids[0] == advertised->members[i].xuid)
                  mask |= 1u << i;
            response.registered_mask = htonl(mask);
            if (SignPacket(response, credential, "session-register-reply-v2")) reply = response;
          }
        }
        if (reply)
          sendto(socket, reinterpret_cast<const char*>(&*reply), sizeof(*reply), 0,
                 reinterpret_cast<sockaddr*>(&source), length);
        continue;
      }
      if (valid && query.type == kQuery && !legacy_diagnostics) {
        const auto matches=NatProbeMatchAcknowledgedDiscoveryAttempts(socket,{source.sin_addr.s_addr,ntohs(source.sin_port)});
        const auto hosted_session=admission_grants->hosted_directory_session();
        // Answer a source that completed this host's server-issued attempt
        // (acknowledged punch or proven LAN request) while its grant is current,
        // or before any grant exists: the directory issues the grant only after
        // the joiner arms admission, which the joiner does after this answer.
        // A consumed, expired or invalidated grant still ends discovery, and
        // joining still needs the current grant.
        valid=hosted_session&&!matches.empty();
        if(valid&&!admission_grants->HasCurrentPrivateDiscoveryGrant(*hosted_session,matches)) {
          valid=!admission_grants->HasPrivateDiscoveryGrantRecord(*hosted_session,matches);
          if(valid)
            REXSYS_INFO("LAN discovery: answering authenticated attempt before grant from {:08X}:{}",
                        source.sin_addr.s_addr,ntohs(source.sin_port));
        }
      }
      if (valid && query.type == kQuery) {
        REXSYS_INFO("LAN discovery: received search query from {:08X}:{}", source.sin_addr.s_addr,
                    ntohs(source.sin_port));
      }
      ArbitrationToken reply_credential{};
      std::optional<ArbitrationCredentialEnvelope> reply_envelope;
      if (valid && (query.type == kJoin || query.type == kLeave)) {
        const auto& wire = query.members[0];
        const uint32_t flags = ntohl(wire.flags);
        const uint64_t xuid = Swap64(wire.xuid);
        if (query.type == kJoin)
          REXSYS_INFO("INVITE_DIAG HOST_JOIN_REQUEST_RECEIVED xuid={:016X} xbox_session={:02X}{:02X}{:02X}{:02X}{:02X}{:02X}{:02X}{:02X} private_request={} flags={}",
                      xuid, query.session_id[0], query.session_id[1],
                      query.session_id[2], query.session_id[3],
                      query.session_id[4], query.session_id[5],
                      query.session_id[6], query.session_id[7],
                      (flags & 2) != 0, flags);
        bool existing = false;
        // A relaunched client arrives with a fresh machine id and no credential
        // while its silent previous incarnation is still on the roster.
        bool stale_member = false;
        std::optional<DiscoveryPacket> expired_reply;
        {
          std::lock_guard lock(*advertised->mutex);
          // Routing validation is not an admission credential. The only
          // private authority is a separately reserved host grant below.
          valid = advertised->state != SessionState::kDeleted && ntohl(query.member_count) == 1 &&
                  !query.reserved && !query.reserved2 && !query.reserved3 && !wire.reserved && NonzeroToken(WireToken(query.request_id)) && !(flags & ~6u) && xuid &&
                  xuid != advertised->host_xuid &&
                  Swap64(query.host_xuid) == advertised->host_xuid &&
                  std::memcmp(query.session_id, advertised->info.id.data(), 8) == 0 &&
                  std::memcmp(query.session_key, advertised->info.key.data(), 16) == 0 &&
                  WireIdentity(query) == RecordIdentity(*advertised) && advertised->arbitration;
          if (valid && query.type == kLeave) {
            const auto token = advertised->arbitration->CredentialForVerification(
                WireIdentity(query), xuid, Swap64(wire.machine_id));
            valid = token && VerifyPacket(query, *token, "session-leave-v2");
            if (valid) reply_credential = *token;
          }
          if (valid && query.type == kJoin) {
            valid = !NonzeroToken(WireToken(query.credential));
            if (valid && NonzeroToken(WireToken(query.authentication))) {
              const auto token = advertised->arbitration->CredentialForVerification(
                  WireIdentity(query), xuid, Swap64(wire.machine_id));
              valid = token && VerifyPacket(query, *token, "session-join-v2");
              if (valid) reply_credential = *token;
              else if (!token) {
                const auto challenge = BoundJoinChallenge(query);
                const ArbitrationJoinClaim claim{xuid, Swap64(wire.machine_id),
                    {source.sin_addr.s_addr, ntohs(source.sin_port)},
                    challenge.value_or(ArbitrationToken{}), {}};
                const auto expired_token = advertised->arbitration->ExpiredJoinCredentialForVerification(
                    WireIdentity(query), claim);
                if (expired_token && VerifyPacket(query, *expired_token, "session-join-v2")) {
                  auto reply = ExpiredJoinReply(query);
                  if (SignPacket(reply, *expired_token, "session-join-expired-v2"))
                    expired_reply = reply;
                }
              }
            }
          }
          existing = valid && std::any_of(advertised->members.begin(), advertised->members.end(),
                                          [&](const auto& member) { return member.xuid == xuid; });
          if(valid&&existing&&!legacy_diagnostics) {
            const auto member=std::find_if(advertised->members.begin(),advertised->members.end(),[&](const auto& value){return value.xuid==xuid;});
            valid=member!=advertised->members.end()&&bool(member->gameplay_admission);
            stale_member = valid && !NonzeroToken(WireToken(query.authentication)) &&
                           member->machine_id && member->machine_id != Swap64(wire.machine_id);
          }
        }
        if (expired_reply) {
          // The fixed, retired receipt proves only expiry. No member is
          // revived and sending happens outside the hosted record mutex.
          sendto(socket, reinterpret_cast<const char*>(&*expired_reply), sizeof(*expired_reply), 0,
                 reinterpret_cast<sockaddr*>(&source), length);
          continue;
        }
        if (valid && query.type == kJoin) {
          SessionMember member{xuid,
                               std::string(wire.name, strnlen(wire.name, sizeof(wire.name))),
                               0,
                               false,
                               (flags & 2) != 0,
                               (flags & 4) != 0};
          member.machine_id = Swap64(wire.machine_id);
          member.gameplay_address = {source.sin_addr.s_addr, ntohs(wire.gameplay_port)};
          const auto challenge = BoundJoinChallenge(query);
          const ArbitrationJoinClaim claim{xuid, member.machine_id,
              {source.sin_addr.s_addr, ntohs(source.sin_port)}, challenge.value_or(ArbitrationToken{}), reply_credential};
          {
            std::lock_guard record_lock(*advertised->mutex);
            // A stale member is only replaced below, after a fresh directory
            // grant proves the relaunched client; the arbitration check then
            // runs against the cleared roster before anything is admitted.
            valid = member.gameplay_address.port && advertised->arbitration &&
                (stale_member ||
                 advertised->arbitration->CheckAdmission(claim, SessionArbitrationAuthority::Clock::now()).accepted());
          }
          HostAdmissionReservation reservation;
          DiscoveryAdmissionContext context;
          REXSYS_INFO("INVITE_DIAG HOST_ADMISSION_BEGIN xuid={:016X} private_request={} existing={} stale={}",
                      xuid, member.private_slot, existing, stale_member);
          if (valid && (!existing || stale_member)) {
            // NAT snapshot -> atomic grant reservation -> membership commit ->
            // finalization. No pair of these lock domains is nested.
            auto matches = NatProbeMatchAcknowledgedDiscoveryAttempts(
                socket, {source.sin_addr.s_addr, ntohs(source.sin_port)});
            auto directory_session = admission_grants->hosted_directory_session();
            if (directory_session) {
              auto authority = admission_grants->Reserve(*directory_session, uint64_t(socket),
                                                         source.sin_addr.s_addr,
                                                         ntohs(source.sin_port), matches, xuid);
              REXSYS_INFO("INVITE_DIAG HOST_GRANT_MATCH xuid={:016X} status={} attempt={} admission_gen={} revision={}",
                          xuid, static_cast<int>(authority.status),
                          authority.reservation.attempt_id,
                          authority.reservation.admission_generation,
                          authority.reservation.lease_revision);
              if (authority.status == HostAdmissionReservationStatus::kReserved) {
                reservation = std::move(authority.reservation);
                context.source = DiscoveryAdmissionSource::kInviteGrant;
                member.gameplay_admission = std::make_shared<const GameplayAdmissionBinding>(
                    GameplayAdmissionBinding{reservation.directory_session_id,
                                              reservation.attempt_id,
                                              reservation.admission_generation});
                if (stale_member) {
                  // The grant proves the same player relaunched. Drop the
                  // silent incarnation so the join proceeds as a new admission.
                  std::lock_guard record_lock(*advertised->mutex);
                  if (advertised->arbitration) advertised->arbitration->Remove(xuid);
                  std::erase_if(advertised->members,
                                [&](const auto& value) { return value.xuid == xuid; });
                  existing = false;
                  valid = advertised->arbitration &&
                      advertised->arbitration->CheckAdmission(claim, SessionArbitrationAuthority::Clock::now()).accepted();
                  REXSYS_INFO("INVITE_DIAG HOST_STALE_MEMBER_REPLACED xuid={:016X} admitted={}", xuid, valid);
                }
              } else if (authority.status ==
                         HostAdmissionReservationStatus::kDuplicateReservation) {
                // The winning packet owns the one synchronous transaction.
                // This duplicate mutates nothing and may retry after the
                // winner publishes the resulting roster.
                valid = false;
              }
            }
          }
          if(!legacy_diagnostics&&!existing&&!reservation)valid=false;
          if (valid) {
            const auto token = NewArbitrationToken();
            std::lock_guard record_lock(*advertised->mutex);
            const auto before = advertised->members;
            const auto admission = advertised->arbitration ?
                advertised->arbitration->CheckAdmission(claim, SessionArbitrationAuthority::Clock::now()) : ArbitrationJoinResult{};
            if (token && admission.accepted()) {
              const auto credential = admission.status == ArbitrationStatus::kReplay ? admission.credential : *token;
              reply_envelope = SealArbitrationCredential(WirePublicKey(query.client_public_key),
                  credential, JoinCredentialAAD(query));
            }
            valid = token && admission.accepted() && reply_envelope &&
                ApplyDiscoveryMemberBatch(*advertised, std::span<const SessionMember>(&member, 1), context);
            if (valid) {
              const auto admitted = advertised->arbitration->Admit(claim, *token, SessionArbitrationAuthority::Clock::now());
              valid = admitted.accepted();
              if (valid) {
                reply_credential = admitted.credential;
                for (auto& current : advertised->members)
                  if (current.xuid == xuid) {
                    current.machine_id = member.machine_id;
                    current.gameplay_address = member.gameplay_address;
                  }
              } else advertised->members = before;
            }
          }
          if (reservation)
            admission_grants->Finish(reservation, valid);
          if (!valid)
            REXSYS_WARN("INVITE_DIAG HOST_ADMISSION_REJECTED_GRANT_OR_ROSTER xuid={:016X} private_request={}",
                        xuid, member.private_slot);
          if (valid) {
            REXSYS_INFO(
                "LAN discovery: host accepted join xuid={:016X} source={} from {:08X}:{}",
                xuid,
                context.source == DiscoveryAdmissionSource::kInviteGrant
                    ? "invite-grant"
                    : "public",
                source.sin_addr.s_addr, ntohs(source.sin_port));
          }
        } else if (valid) {
          std::lock_guard lock(*advertised->mutex);
          auto before = advertised->members.size();
          advertised->arbitration->Remove(xuid);
          std::erase_if(advertised->members,
                        [&](const auto& value) { return value.xuid == xuid; });
          if (before != advertised->members.size())
            advertised->NotifyStatus();
        }
      }
      if (valid && (query.type == kQuery || query.type == kJoin || query.type == kLeave)) {
        DiscoveryPacket response{};
        {
          std::lock_guard record_lock(*advertised->mutex);
          if (advertised->state == SessionState::kDeleted) continue;
          response = Encode(*advertised,title_id);
        }
        if (query.type == kJoin || query.type == kLeave) {
          std::copy_n(query.attempt, 16, response.attempt);
          std::copy_n(query.request_id,16,response.request_id);
          if (query.type == kJoin) {
            if (!reply_envelope) continue;
            std::copy_n(query.client_public_key,32,response.client_public_key);
            std::copy(reply_envelope->server_public_key.begin(),reply_envelope->server_public_key.end(),response.server_public_key);
            std::copy(reply_envelope->ciphertext.begin(),reply_envelope->ciphertext.end(),response.credential);
            std::copy(reply_envelope->iv.begin(),reply_envelope->iv.end(),response.credential_iv);
            std::copy(reply_envelope->tag.begin(),reply_envelope->tag.end(),response.credential_tag);
          }
          if (!SignPacket(response, reply_credential, query.type == kJoin ? "session-join-reply-v2" : "session-leave-reply-v2")) continue;
        }
        int sent = sendto(socket, reinterpret_cast<const char*>(&response), sizeof(response), 0,
                          reinterpret_cast<sockaddr*>(&source), length);
        if (query.type == kQuery) {
          REXSYS_INFO("LAN discovery: search response bytes={} to {:08X}:{}", sent,
                      source.sin_addr.s_addr, ntohs(source.sin_port));
        } else if (query.type == kJoin) {
          REXSYS_INFO("LAN discovery: host join response bytes={} to {:08X}:{} members={}", sent,
                      source.sin_addr.s_addr, ntohs(source.sin_port), ntohl(response.member_count));
        }
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
  }
  bool private_configured=false,legacy_diagnostics=false;
  std::unique_ptr<PrivateLanDiscoveryAdapter> private_adapter;
  uint64_t machine_id = NewArbitrationMachineId().value_or(0);
  uint32_t title_id;
  uint16_t port;
  SOCKET socket = kInvalidSocket;
  std::atomic<bool> running = false;
  std::thread thread;
  std::shared_ptr<SessionRecord> advertised;
  SOCKET client_socket = kInvalidSocket;
  std::atomic<bool> client_running = false;
  std::atomic<bool> client_exchange = false;
  std::thread client_thread;
  RetainedDiscoverySearchState retained_search;
  std::vector<std::string> client_attempt_ids;
  std::shared_ptr<HostAdmissionGrantStore> admission_grants;
};

LanDiscoveryService::LanDiscoveryService(
    uint32_t title_id, uint16_t port, std::shared_ptr<HostAdmissionGrantStore> admission_grants,
    SessionDirectoryClient::LocalUserIdentityProvider user_identity,
    SessionDirectoryClient::ClientAdmissionTransport client_admission_transport,
    bool automatic_client_admission_driver,
    SessionDirectoryClient::InviteJoinAttemptTransport invite_join_attempt_transport,
    SessionDirectoryClient::JoinAttemptCompletionTransport
        join_attempt_completion_transport)
    : admission_grants_(admission_grants ? std::move(admission_grants)
                                         : std::make_shared<HostAdmissionGrantStore>()),
      impl_(std::make_unique<Impl>(title_id, port, admission_grants_)),
      directory_(std::move(user_identity), std::move(client_admission_transport),
                 automatic_client_admission_driver,
                 std::move(invite_join_attempt_transport),
                 std::move(join_attempt_completion_transport)) {}
LanDiscoveryService::~LanDiscoveryService() = default;
void LanDiscoveryService::SetArbitrationMachineId(uint64_t machine_id) { impl_->machine_id = machine_id;if(impl_->private_adapter)impl_->private_adapter->SetMachine(machine_id); }
void LanDiscoveryService::SetTitleId(uint32_t title_id) {
  directory_.SetClientAdmissionTitle(title_id);
  impl_->title_id = title_id;
  if(impl_->private_adapter)impl_->private_adapter->SetTitle(title_id);
}
void LanDiscoveryService::SetLocalUserIdentity(uint32_t local_user_index,
                                               std::optional<uint64_t> xuid) {
  directory_.SetClientAdmissionUserIdentity(local_user_index, xuid);
}
ClientAdmissionPrepareResult LanDiscoveryService::PrepareClientAdmission(
    uint32_t local_user_index, const DirectoryTraversalAttempt& attempt,
    const SessionRecord& discovered, uint64_t discovery_socket) {
  return directory_.PrepareClientAdmission(local_user_index, impl_->title_id, attempt, discovered,
                                           discovery_socket);
}
bool LanDiscoveryService::ConfirmClientAdmissionSession(
    uint32_t local_user_index, const std::shared_ptr<const SessionRecord>& session) {
  return directory_.ConfirmClientAdmissionSession(local_user_index, session);
}
bool LanDiscoveryService::HasClientAdmission(uint32_t local_user_index) const {
  return directory_.HasClientAdmission(local_user_index);
}
std::optional<uint64_t> LanDiscoveryService::ClientAdmissionLifecycleToken(
    uint32_t local_user_index) const {
  return directory_.ClientAdmissionLifecycleToken(local_user_index);
}
void LanDiscoveryService::PollClientAdmissions(std::chrono::steady_clock::time_point now) {
  directory_.PollClientAdmissions(now);
}
void LanDiscoveryService::StopClientAdmission(uint32_t local_user_index) {
  directory_.StopClientAdmission(local_user_index);
}
void LanDiscoveryService::QueueGameplayAdmission(const std::shared_ptr<SessionRecord>& session,
    uint32_t user_index, uint64_t xuid, const DirectoryTraversalAttempt& attempt,
    const std::string& generation) {
  directory_.QueueGameplayAdmission(session, user_index, xuid, attempt, generation);
}
bool LanDiscoveryService::ActivatePrivateLanGameplay(const std::shared_ptr<SessionRecord>& session,uint64_t xuid) {
  return impl_->private_configured&&impl_->private_adapter&&impl_->private_adapter->Activate(session,xuid);
}
void LanDiscoveryService::StopAllClientAdmissions() {
  if(impl_->private_adapter)impl_->private_adapter->StopClient();
  directory_.StopAllClientAdmissions();
}
bool LanDiscoveryService::Advertise(const std::shared_ptr<SessionRecord>& session) {
  if (!impl_->Start(session))
    return false;
  if(!impl_->private_configured)directory_.StartHosting(session, impl_->title_id, impl_->port, admission_grants_);
  return true;
}
void LanDiscoveryService::StopAdvertising() {
  directory_.StopHosting();
  impl_->Stop();
}
bool LanDiscoveryService::IsAdvertising() const {
  return impl_->private_configured?(impl_->private_adapter&&impl_->private_adapter->IsAdvertising()):bool(impl_->running);
}
std::optional<DirectoryInviteJoinAttempt>
LanDiscoveryService::IssueConfiguredInviteAttempt(std::string_view code,
                                                  uint32_t title_id) {
  if (!title_id || title_id != impl_->title_id)
    return std::nullopt;
  return directory_.CreateInviteCodeJoinAttempt(code, title_id);
}
void LanDiscoveryService::ReleaseConfiguredInviteAttempt(
    const DirectoryTraversalAttempt& attempt) {
  directory_.CompleteJoinAttempt(attempt);
}
std::optional<ConfiguredInviteDiscoveryResult>
LanDiscoveryService::DiscoverConfiguredInvite(
    const DirectoryInviteJoinAttempt& issued, uint32_t timeout_ms,
    const std::function<bool()>& operation_is_current,
    const std::function<void(ConfiguredInviteStage)>& stage_observer,
    LanAddress lan_probe_target) {
  auto current = [&] {
    return !operation_is_current || operation_is_current();
  };
  auto observe = [&](ConfiguredInviteStage stage) {
    if (stage_observer)
      stage_observer(stage);
    return current();
  };

  const auto& attempt = issued.attempt;
  if (!current() || attempt.participant != 1 ||
      attempt.purpose != "invite_code_private_eligible" ||
      attempt.session_id != issued.session.session_id)
    return std::nullopt;
  const DirectoryCandidate* endpoint = nullptr;
  for (const auto& candidate : issued.session.connectivity_candidates) {
    if (candidate.type != "public")
      continue;
    if (endpoint)
      return std::nullopt;
    endpoint = &candidate;
  }
  in_addr authoritative_ipv4{};
  if (!endpoint || !endpoint->discovery_port || !endpoint->gameplay_port ||
      inet_pton(AF_INET, endpoint->address.c_str(), &authoritative_ipv4) != 1)
    return std::nullopt;
  // An explicit Direct Connect endpoint is also authoritative for the signed
  // invite LAN fallback. Private loopback tests must not emit LAN broadcasts.
  // An explicit caller target remains stronger, preserving fixture behavior.
  if (!lan_probe_target.ipv4 && !REXCVAR_GET(direct_connect_address).empty()) {
    in_addr direct{};
    if (inet_pton(AF_INET, REXCVAR_GET(direct_connect_address).c_str(), &direct) != 1)
      return std::nullopt;
    lan_probe_target = {direct.s_addr, endpoint->discovery_port};
  }
  if (!observe(ConfiguredInviteStage::kBeforeSocketSetup) ||
      !EnsureSocketRuntime())
    return std::nullopt;

  SOCKET socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (socket == kInvalidSocket)
    return std::nullopt;
  bool transferred = false;
  auto cleanup = [&] {
    if (transferred)
      return;
    NatProbeDetach(uint64_t(socket));
    CloseSocket(socket);
    NatProbeRetireIdentity(attempt.attempt_id);
  };
  if (!current() || !BindLanSocket(socket, 0)) {
    REXSYS_WARN(
        "Configured invite: operation-owned discovery socket bind failed after attempt issuance");
    cleanup();
    return std::nullopt;
  }
  if (!SetNonBlocking(socket)) {
    cleanup();
    return std::nullopt;
  }
  sockaddr_in local_address{};
  socket_len_t local_length = sizeof(local_address);
  if (getsockname(socket, reinterpret_cast<sockaddr*>(&local_address),
                  &local_length) != 0) {
    cleanup();
    return std::nullopt;
  }
  NatProbeAttach(uint64_t(socket), NatProbeRole::kDiscovery,
                 {local_address.sin_addr.s_addr,
                  ntohs(local_address.sin_port)});
  if (!current() || !NatProbeInstallIdentityForSocket(
                        {attempt.attempt_id, attempt.capability,
                         attempt.rendezvous_host, attempt.rendezvous_port, 1, true},
                        uint64_t(socket))) {
    cleanup();
    return std::nullopt;
  }

  const auto started = std::chrono::steady_clock::now();
  const auto deadline =
      started + std::chrono::milliseconds(timeout_ms + SearchTimingBudget::kNatGraceMs);
  DiscoveryPacket query{};
  query.magic = htonl(kDiscoveryMagic);
  query.version = htons(kDiscoveryVersion);
  query.type = kQuery;
  query.title_id = htonl(impl_->title_id);
  const LanAddress local{local_address.sin_addr.s_addr, ntohs(local_address.sin_port)};
  const auto selector = InviteLanMac(attempt.attempt_id, "invite-lan-selector-v1");
  const auto source_bytes = InviteLanSourceBytes(local);
  const auto request_proof =
      InviteLanMac(attempt.attempt_id, "invite-lan-request-v1", source_bytes);
  int broadcast_enabled = 1;
  const bool lan_enabled = selector && request_proof &&
                           setsockopt(socket, SOL_SOCKET, SO_BROADCAST,
                                      reinterpret_cast<const char*>(&broadcast_enabled),
                                      sizeof(broadcast_enabled)) == 0;
  if (lan_enabled)
    REXSYS_INFO("INVITE_LAN_DISCOVERY_STARTED attempt_ref={}",
                attempt.attempt_id.substr(0, 8));
  struct Candidate {
    LanAddress peer;
    bool lan = false;
    std::array<uint8_t, 16> proof{};
    std::chrono::steady_clock::time_point next_query{};
  };
  std::vector<Candidate> candidates;
  auto next_lan_probe = started;
  bool sent_once = false;
  bool waiting_observed = false;
  bool traversal_observed = false;
  while (current() && std::chrono::steady_clock::now() < deadline) {
    const auto now = std::chrono::steady_clock::now();
    NatProbeTick(uint64_t(socket));
    if (lan_enabled && now >= next_lan_probe) {
      const auto probe = MakeInviteLanPacket(kInviteLanRequest, *selector,
                                             *request_proof);
      sockaddr_in broadcast{};
      broadcast.sin_family = AF_INET;
      broadcast.sin_addr.s_addr = lan_probe_target.ipv4 ? lan_probe_target.ipv4
                                                        : htonl(INADDR_BROADCAST);
      broadcast.sin_port = htons(lan_probe_target.port ? lan_probe_target.port
                                                       : endpoint->discovery_port);
      sendto(socket, reinterpret_cast<const char*>(&probe), sizeof(probe), 0,
             reinterpret_cast<sockaddr*>(&broadcast), sizeof(broadcast));
      next_lan_probe = now + std::chrono::milliseconds(100);
    }
    for (const auto& peer : NatProbePeerAttempts(uint64_t(socket))) {
      if (peer.attempt_id != attempt.attempt_id ||
          std::any_of(candidates.begin(), candidates.end(), [&](const Candidate& value) {
            return !value.lan && value.peer == peer.peer;
          }))
        continue;
      candidates.push_back({peer.peer, false, {}, now});
      REXSYS_INFO("INVITE_PUBLIC_CANDIDATE_VALIDATED attempt_ref={} endpoint={:08X}:{}",
                  attempt.attempt_id.substr(0, 8), peer.peer.ipv4, peer.peer.port);
    }
    if (!candidates.empty() && !traversal_observed) {
      traversal_observed = true;
      if (!observe(ConfiguredInviteStage::kTraversalReady)) {
        cleanup();
        return std::nullopt;
      }
    }
    for (auto& candidate : candidates) {
      if (now < candidate.next_query)
        continue;
      if (!observe(sent_once ? ConfiguredInviteStage::kBeforeDiscoveryRetry
                             : ConfiguredInviteStage::kBeforeFirstDiscoverySend)) {
        cleanup();
        return std::nullopt;
      }
      sockaddr_in target{};
      target.sin_family = AF_INET;
      target.sin_addr.s_addr = candidate.peer.ipv4;
      target.sin_port = htons(candidate.peer.port);
      const int sent = sendto(socket, reinterpret_cast<const char*>(&query),
                              sizeof(query), 0,
                              reinterpret_cast<sockaddr*>(&target), sizeof(target));
      if (sent != sizeof(query)) {
        cleanup();
        return std::nullopt;
      }
      sent_once = true;
      candidate.next_query = now + std::chrono::milliseconds(50);
      if (!waiting_observed) {
        waiting_observed = true;
        if (!observe(ConfiguredInviteStage::kDiscoveryWaiting)) {
          cleanup();
          return std::nullopt;
        }
      }
    }
    sockaddr_in source{};
    socket_len_t length = sizeof(source);
    DiscoveryPacket response{};
    int count = ReceiveDatagram(socket, reinterpret_cast<char*>(&response),
                         sizeof(response), 0,
                         reinterpret_cast<sockaddr*>(&source), &length);
    if (count > 0 && NatProbeConsume(
                         uint64_t(socket),
                         reinterpret_cast<const uint8_t*>(&response), size_t(count),
                         source.sin_addr.s_addr, ntohs(source.sin_port))) {
      continue;
    }
    if (count == sizeof(InviteLanPacket) && lan_enabled) {
      InviteLanPacket lan_response{};
      std::memcpy(&lan_response, &response, sizeof(lan_response));
      const LanAddress responding{source.sin_addr.s_addr, ntohs(source.sin_port)};
      REXSYS_INFO("INVITE_LAN_RESPONSE_RECEIVED attempt_ref={} endpoint={:08X}:{}",
                  attempt.attempt_id.substr(0, 8), responding.ipv4, responding.port);
      if (!InviteLanPacketValid(lan_response, kInviteLanResponse) ||
          !InviteLanEqual(lan_response.selector, selector->data(), selector->size()) ||
          (!IsPrivateLanIpv4(responding.ipv4) &&
           (ntohl(responding.ipv4) & 0xFF000000u) != 0x7F000000u) ||
          candidates.size() >= 8) {
        REXSYS_INFO("INVITE_LAN_RESPONSE_REJECTED_MALFORMED attempt_ref={}",
                    attempt.attempt_id.substr(0, 8));
        continue;
      }
      Candidate candidate{responding, true, {}, now};
      std::copy_n(lan_response.proof, candidate.proof.size(),
                  candidate.proof.begin());
      if (std::none_of(candidates.begin(), candidates.end(), [&](const Candidate& value) {
            return value.lan && value.peer == responding && value.proof == candidate.proof;
          })) {
        candidates.push_back(candidate);
      }
      continue;
    }
    if (count == sizeof(response) && current()) {
      const LanAddress responding{source.sin_addr.s_addr,
                                  ntohs(source.sin_port)};
      auto decoded = Decode(response, impl_->title_id, source.sin_addr.s_addr);
      if (!decoded || !current()) {
        REXSYS_INFO("INVITE_LAN_RESPONSE_REJECTED_TUPLE_OR_TITLE attempt_ref={}",
                    attempt.attempt_id.substr(0, 8));
        continue;
      }
      const auto tuple = InviteLanTupleBytes(response);
      const auto expected = InviteLanMac(attempt.attempt_id,
                                         "invite-lan-response-v1", tuple);
      auto candidate = std::find_if(candidates.begin(), candidates.end(),
                                    [&](const Candidate& value) {
        return value.peer == responding &&
               (!value.lan || (expected && InviteLanEqual(
                   value.proof.data(), expected->data(), expected->size())));
      });
      if (candidate == candidates.end())
        continue;
      if (candidate->lan) {
        if (response.host_ipv4 != responding.ipv4 ||
            ntohs(response.host_port) != endpoint->gameplay_port ||
            !NatProbeRegisterInviteLanPeer(uint64_t(socket), attempt.attempt_id,
                                           responding)) {
          REXSYS_INFO("INVITE_LAN_RESPONSE_REJECTED_TUPLE_OR_PROOF attempt_ref={}",
                      attempt.attempt_id.substr(0, 8));
          continue;
        }
        REXSYS_INFO("INVITE_LAN_CANDIDATE_VALIDATED attempt_ref={} endpoint={:08X}:{}",
                    attempt.attempt_id.substr(0, 8), responding.ipv4, responding.port);
      }
      const auto matches = NatProbeMatchAcknowledgedDiscoveryAttempts(
          uint64_t(socket), responding);
      if (std::find(matches.begin(), matches.end(), attempt.attempt_id) ==
              matches.end() ||
          !NatProbeSelectInviteDiscoveryPeer(uint64_t(socket), attempt.attempt_id,
                                            responding))
        continue;
      decoded->discovery_address = responding;
      if (!candidate->lan)
        decoded->info.host_address = {authoritative_ipv4.s_addr,
                                      endpoint->gameplay_port};
      decoded->traversal_session_id = attempt.session_id;
      decoded->traversal_attempt_id = attempt.attempt_id;
      decoded->traversal_capability = attempt.capability;
      NatProbeSetLogicalGameplayPeer(attempt.attempt_id,
                                     decoded->info.host_address);
      if (candidate->lan)
        NatProbeAddSameNetworkGameplayCandidate(decoded->info.host_address);
      REXSYS_INFO("INVITE_ROUTE_SELECTED_{} attempt_ref={} discovery={:08X}:{} gameplay={:08X}:{}",
                  candidate->lan ? "LAN" : "PUBLIC", attempt.attempt_id.substr(0, 8),
                  responding.ipv4, responding.port, decoded->info.host_address.ipv4,
                  decoded->info.host_address.port);
      transferred = true;
      return ConfiguredInviteDiscoveryResult{std::move(*decoded),
                                             uint64_t(socket)};
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
  REXSYS_INFO("NAT_DIAG configured invite traversal ended attempt={} selected=false current={}",
              attempt.attempt_id, current());
  cleanup();
  return std::nullopt;
}
std::vector<DirectoryListing> LanDiscoveryService::SearchListings(uint64_t exclude_host_xuid) {
  if (impl_->private_configured || impl_->legacy_diagnostics ||
      REXCVAR_GET(session_directory_url).empty())
    return {};
  return directory_.ListSearchable(impl_->title_id, exclude_host_xuid);
}
std::vector<SessionRecord> LanDiscoveryService::Search(uint32_t timeout_ms, uint32_t max_results,
                                                       uint32_t local_user_index) {
  (void)local_user_index;
  if(impl_->private_configured)return impl_->private_adapter?impl_->private_adapter->Search(timeout_ms,max_results):std::vector<SessionRecord>{};
  if(!impl_->legacy_diagnostics)return {};
  static std::atomic<uint64_t> next_search_attempt{0};
  const uint64_t search_attempt = ++next_search_attempt;
  const auto search_started = std::chrono::steady_clock::now();
  std::vector<SessionRecord> results;
  if (!EnsureSocketRuntime())
    return results;
  // A retained discovery socket belongs to the completed Search that created
  // it and remains alive only so Join/Leave can reuse its punched mapping. A
  // replacement Search supersedes that attempt before creating a new socket;
  // otherwise both probes keep registering under the same participant/role.
  impl_->StopClient();
  SOCKET socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (socket == kInvalidSocket)
    return results;
  std::string selected_address = REXCVAR_GET(direct_connect_address);
  uint16_t selected_discovery_port = impl_->port;
  uint16_t selected_gameplay_port = 0;
  bool directory_selected = false;
  bool directory_browse = false;
  std::vector<DirectoryTraversalAttempt> directory_attempts;
  const bool automatic_public_traversal =
      selected_address.empty() && !REXCVAR_GET(session_directory_url).empty() &&
      REXCVAR_GET(session_directory_candidate_type) == "public" &&
      REXCVAR_GET(session_directory_session_index) == 0xFFFFFFFFu;
  if (selected_address.empty() && !REXCVAR_GET(session_directory_url).empty()) {
    uint32_t index = REXCVAR_GET(session_directory_session_index);
    if (index != 0xFFFFFFFFu) {
      auto sessions = directory_.List(impl_->title_id);
      for (size_t i = 0; i < sessions.size(); ++i) {
        const auto& candidate = sessions[i].connectivity_candidates.front();
        REXSYS_INFO("Session directory: [{}] '{}' players={}/{} candidate={} {}:{}", i,
                    sessions[i].server_name, sessions[i].player_count, sessions[i].max_players,
                    candidate.type, candidate.address, candidate.discovery_port);
      }
      if (index < sessions.size()) {
        const auto& candidate = sessions[index].connectivity_candidates.front();
        selected_address = candidate.address;
        selected_discovery_port = candidate.discovery_port;
        selected_gameplay_port = candidate.gameplay_port;
        directory_selected = true;
        REXSYS_INFO("Session directory: selected [{}] '{}' via {}", index,
                    sessions[index].server_name, selected_address);
      } else {
        REXSYS_WARN("Session directory: selected index {} is unavailable", index);
      }
    } else {
      // Normal guest searches never wait on HTTPS. A completed cache entry is
      // converted into ordinary discovery probes below; a slow or unavailable
      // directory leaves LAN broadcast unaffected.
      directory_.RequestList(impl_->title_id);
      directory_browse = true;
    }
  }
  if (automatic_public_traversal) {
    auto sessions = directory_.List(impl_->title_id);
    size_t issued = 0;
    for (const auto& session : sessions) {
      if (issued >= max_results || session.connectivity_candidates.empty() ||
          session.connectivity_candidates.front().type != "public")
        continue;
      auto attempt = directory_.CreateJoinAttempt(session.session_id);
      if (!attempt)
        continue;
      if (NatProbeInstallIdentity({attempt->attempt_id, attempt->capability,
                                   attempt->rendezvous_host, attempt->rendezvous_port, 1}))
        directory_attempts.push_back(*attempt), ++issued;
    }
    directory_browse = false;
    REXSYS_INFO(
        "Session directory: Search generation={} obtained {} public traversal attempt(s)",
        search_attempt, issued);
  }
  const bool direct = !selected_address.empty();
  const bool traversal = NatProbeEnabled();
  const SearchTimingBudget timing(timeout_ms, traversal);
  REXSYS_INFO(
      "Discovery: search attempt={} started response_window_ms={} nat_grace_ms={} "
      "nat_enabled={}",
      search_attempt, timing.original_window_ms(),
      timing.total_window_ms() - timing.original_window_ms(), traversal);
  if (direct) {
    if (!BindLanSocket(socket, 0)) {
      REXSYS_ERROR("Discovery: failed to bind search socket to configured interface");
      CloseSocket(socket);
      return results;
    }
  }
  // Automatic public traversal still falls back to LAN broadcast while the
  // rendezvous peer is pending. Windows rejects that send with WSAEACCES unless
  // SO_BROADCAST is enabled, even though the socket is intentionally bound to
  // the selected physical interface for public NAT traffic.
  if (!direct) {
    int yes = 1;
    setsockopt(socket, SOL_SOCKET, SO_BROADCAST, reinterpret_cast<const char*>(&yes), sizeof(yes));
  }
  // Keep limited-broadcast search wildcard-bound. Windows doesn't loop back a
  // 255.255.255.255 datagram from a socket bound to a unicast address, and the
  // listener has the same requirement. Advertisements, XNADDR, join exchange,
  // and gameplay transport still use the explicit selected address.
  SetNonBlocking(socket);
  sockaddr_in local_address{};
  socket_len_t local_length = sizeof(local_address);
  if (getsockname(socket, reinterpret_cast<sockaddr*>(&local_address), &local_length) == 0) {
    NatProbeAttach(socket, NatProbeRole::kDiscovery,
                   {local_address.sin_addr.s_addr, ntohs(local_address.sin_port)});
  }
  sockaddr_in target{};
  target.sin_family = AF_INET;
  if (direct) {
    if (inet_pton(AF_INET, selected_address.c_str(), &target.sin_addr) != 1) {
      REXSYS_ERROR("Invalid direct-connect IPv4 address '{}'", selected_address);
      CloseSocket(socket);
      return results;
    }
  } else {
    target.sin_addr.s_addr = htonl(INADDR_BROADCAST);
  }
  target.sin_port = htons(selected_discovery_port);
  bool traversal_target = false;
  std::optional<LanAddress> initially_queried_traversal_peer;
  if (traversal) {
    auto rendezvous_deadline =
        std::chrono::steady_clock::now() + std::chrono::milliseconds(std::min(timeout_ms, 2000u));
    while (std::chrono::steady_clock::now() < rendezvous_deadline) {
      NatProbeTick(socket);
      sockaddr_in source{};
      socket_len_t source_length = sizeof(source);
      std::array<uint8_t, sizeof(DiscoveryPacket)> packet{};
      int count = ReceiveDatagram(socket, reinterpret_cast<char*>(packet.data()), int(packet.size()), 0,
                           reinterpret_cast<sockaddr*>(&source), &source_length);
      if (count > 0)
        NatProbeConsume(socket, packet.data(), count, source.sin_addr.s_addr,
                        ntohs(source.sin_port));
      if (auto peer = NatProbePeer(socket)) {
        target.sin_addr.s_addr = peer->ipv4;
        target.sin_port = htons(peer->port);
        traversal_target = true;
        initially_queried_traversal_peer = peer;
        REXSYS_INFO("NAT traversal: search attempt={} ready during initial wait peer={:08X}:{}",
                    search_attempt, peer->ipv4, peer->port);
        break;
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    if (!traversal_target) {
      REXSYS_INFO(
          "NAT traversal: search attempt={} initial rendezvous wait expired without readiness",
          search_attempt);
    }
  }
  LateTraversalQueryState late_traversal_query(traversal, initially_queried_traversal_peer);
  std::vector<LanAddress> queried_automatic_peers;
  if (automatic_public_traversal && initially_queried_traversal_peer)
    queried_automatic_peers.push_back(*initially_queried_traversal_peer);
  DiscoveryPacket query{};
  query.magic = htonl(kDiscoveryMagic);
  query.version = htons(kDiscoveryVersion);
  query.type = kQuery;
  query.title_id = htonl(impl_->title_id);
  int query_sent = sendto(socket, reinterpret_cast<const char*>(&query), sizeof(query), 0,
                          reinterpret_cast<sockaddr*>(&target), sizeof(target));
  if (direct || traversal_target) {
    REXSYS_INFO(
        "Direct connect: search attempt={} initial query bytes={} to {:08X}:{} title={:08X} "
        "traversal_ready={}",
        search_attempt, query_sent, target.sin_addr.s_addr, ntohs(target.sin_port), impl_->title_id,
        traversal_target);
  } else {
    REXSYS_INFO(
        "LAN discovery: search attempt={} initial broadcast bytes={} UDP {} title={:08X} "
        "traversal_ready={}",
        search_attempt, query_sent, impl_->port, impl_->title_id, traversal_target);
  }
  // Also probe the local listener for deterministic same-host tests/tools.
  // Stable XUID/session-ID filtering prevents this from surfacing as a remote
  // result in the title.
  if (!direct && !traversal_target) {
    target.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    sendto(socket, reinterpret_cast<const char*>(&query), sizeof(query), 0,
           reinterpret_cast<sockaddr*>(&target), sizeof(target));
  }
  struct DirectoryProbe {
    uint32_t ipv4;
    uint16_t discovery_port;
    uint16_t gameplay_port;
    std::string server_name;
    std::string candidate_type;
  };
  std::vector<DirectoryProbe> directory_probes;
  bool directory_probes_sent = !directory_browse;
  auto send_directory_probes = [&] {
    if (directory_probes_sent)
      return;
    auto sessions = directory_.CachedList(impl_->title_id);
    if (!sessions)
      return;
    directory_probes_sent = true;
    for (size_t i = 0; i < sessions->size() && directory_probes.size() < max_results; ++i) {
      const auto& session = (*sessions)[i];
      const auto& candidate = session.connectivity_candidates.front();
      sockaddr_in candidate_target{};
      candidate_target.sin_family = AF_INET;
      candidate_target.sin_port = htons(candidate.discovery_port);
      if (inet_pton(AF_INET, candidate.address.c_str(), &candidate_target.sin_addr) != 1)
        continue;
      if (std::any_of(directory_probes.begin(), directory_probes.end(), [&](const auto& probe) {
            return probe.ipv4 == candidate_target.sin_addr.s_addr &&
                   probe.discovery_port == candidate.discovery_port;
          }))
        continue;
      int sent = sendto(socket, reinterpret_cast<const char*>(&query), sizeof(query), 0,
                        reinterpret_cast<sockaddr*>(&candidate_target), sizeof(candidate_target));
      REXSYS_INFO("Session directory: probing [{}] '{}' players={}/{} via {} {}:{} bytes={}", i,
                  session.server_name, session.player_count, session.max_players, candidate.type,
                  candidate.address, candidate.discovery_port, sent);
      if (sent == sizeof(query)) {
        directory_probes.push_back({candidate_target.sin_addr.s_addr, candidate.discovery_port,
                                    candidate.gameplay_port, session.server_name, candidate.type});
      }
    }
  };
  const auto response_window_started = std::chrono::steady_clock::now();
  const auto original_deadline =
      response_window_started + std::chrono::milliseconds(timing.original_window_ms());
  const auto deadline =
      response_window_started + std::chrono::milliseconds(timing.total_window_ms());
  REXSYS_INFO(
      "Discovery: search attempt={} original_deadline_ms={} final_deadline_ms={} "
      "from_response_window_start",
      search_attempt, timing.original_window_ms(), timing.total_window_ms());
  bool extension_logged = false;
  while (std::chrono::steady_clock::now() < deadline && results.size() < max_results) {
    const auto now = std::chrono::steady_clock::now();
    if (traversal && !extension_logged && now >= original_deadline) {
      extension_logged = true;
      REXSYS_INFO(
          "NAT traversal: search attempt={} original deadline reached; entering bounded {} ms "
          "extension",
          search_attempt, SearchTimingBudget::kNatGraceMs);
    }
    NatProbeTick(socket);
    send_directory_probes();
    sockaddr_in source{};
    socket_len_t length = sizeof(source);
    DiscoveryPacket response{};
    int count = ReceiveDatagram(socket, reinterpret_cast<char*>(&response), sizeof(response), 0,
                         reinterpret_cast<sockaddr*>(&source), &length);
    bool consumed_probe =
        count > 0 && NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&response), count,
                                     source.sin_addr.s_addr, ntohs(source.sin_port));
    if (auto peer =
            late_traversal_query.TakeAcknowledgedPeer(now < deadline, NatProbePeer(socket))) {
      target.sin_addr.s_addr = peer->ipv4;
      target.sin_port = htons(peer->port);
      traversal_target = true;
      int sent = sendto(socket, reinterpret_cast<const char*>(&query), sizeof(query), 0,
                        reinterpret_cast<sockaddr*>(&target), sizeof(target));
      REXSYS_INFO(
          "NAT traversal: search attempt={} late acknowledged peer={:08X}:{}; one-time discovery "
          "query bytes={}",
          search_attempt, peer->ipv4, peer->port, sent);
    }
    if (automatic_public_traversal && now < deadline) {
      for (const auto& peer : NatProbePeers(socket)) {
        if (std::find(queried_automatic_peers.begin(), queried_automatic_peers.end(), peer) !=
            queried_automatic_peers.end())
          continue;
        sockaddr_in peer_target{};
        peer_target.sin_family = AF_INET;
        peer_target.sin_addr.s_addr = peer.ipv4;
        peer_target.sin_port = htons(peer.port);
        int sent = sendto(socket, reinterpret_cast<const char*>(&query), sizeof(query), 0,
                          reinterpret_cast<sockaddr*>(&peer_target), sizeof(peer_target));
        queried_automatic_peers.push_back(peer);
        traversal_target = true;
        REXSYS_INFO(
            "NAT traversal: search attempt={} server-issued peer={:08X}:{}; one-time discovery "
            "query bytes={}",
            search_attempt, peer.ipv4, peer.port, sent);
      }
    }
    if (consumed_probe) {
      continue;
    }
    if (count == sizeof(response)) {
      auto decoded = Decode(response, impl_->title_id, source.sin_addr.s_addr);
      if (decoded) {
        decoded->discovery_address = {source.sin_addr.s_addr, ntohs(source.sin_port)};
      }
      if (decoded && (direct || (traversal_target && !automatic_public_traversal))) {
        // The manually supplied endpoint is authoritative. This preserves the
        // complete host-provided session identity while avoiding a private or
        // otherwise unreachable address embedded by a multi-homed host.
        decoded->info.host_address.ipv4 = target.sin_addr.s_addr;
        if (directory_selected && selected_gameplay_port)
          decoded->info.host_address.port = selected_gameplay_port;
      } else if (decoded) {
        auto probe =
            std::find_if(directory_probes.begin(), directory_probes.end(), [&](const auto& value) {
              return value.ipv4 == source.sin_addr.s_addr &&
                     value.discovery_port == ntohs(source.sin_port);
            });
        if (probe != directory_probes.end()) {
          decoded->info.host_address.ipv4 = probe->ipv4;
          decoded->info.host_address.port = probe->gameplay_port;
          REXSYS_INFO(
              "Session directory: normalized '{}' via {} to session {:02X}{:02X} endpoint "
              "{:08X}:{}",
              probe->server_name, probe->candidate_type, decoded->info.id[0], decoded->info.id[1],
              decoded->info.host_address.ipv4, decoded->info.host_address.port);
        }
      }
      if (decoded && automatic_public_traversal) {
        const LanAddress responding{source.sin_addr.s_addr, ntohs(source.sin_port)};
        auto peer_attempts = NatProbePeerAttempts(socket);
        auto peer = std::find_if(peer_attempts.begin(), peer_attempts.end(),
                                 [&](const auto& value) { return value.peer == responding; });
        if (peer != peer_attempts.end()) {
          auto issued =
              std::find_if(directory_attempts.begin(), directory_attempts.end(),
                           [&](const auto& value) { return value.attempt_id == peer->attempt_id; });
          if (issued != directory_attempts.end()) {
            decoded->traversal_session_id = issued->session_id;
            decoded->traversal_attempt_id = issued->attempt_id;
            decoded->traversal_capability = issued->capability;
            NatProbeSetLogicalGameplayPeer(issued->attempt_id, decoded->info.host_address);
          }
        }
      }
      if (decoded && std::none_of(results.begin(), results.end(), [&](const auto& existing) {
            return existing.info.id == decoded->info.id;
          })) {
        REXSYS_INFO("LAN discovery: found host '{}' xuid={:016X} address={:08X}:{}",
                    decoded->host_name, decoded->host_xuid, decoded->info.host_address.ipv4,
                    decoded->info.host_address.port);
        results.push_back(std::move(*decoded));
        if (traversal) {
          REXSYS_INFO(
              "NAT traversal: search attempt={} added remote session count={} retained discovery "
              "endpoint={:08X}:{}",
              search_attempt, results.size(), source.sin_addr.s_addr, ntohs(source.sin_port));
        }
      }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
  const auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                              std::chrono::steady_clock::now() - search_started)
                              .count();
  REXSYS_INFO("Discovery: search attempt={} completed results={} elapsed_ms={} reason={}",
              search_attempt, results.size(), elapsed_ms,
              results.size() >= max_results ? "max_results"
                                            : (traversal ? "nat_deadline" : "original_deadline"));
  if (NatProbeEnabled()) {
    impl_->client_socket = socket;
    impl_->client_attempt_ids.reserve(directory_attempts.size());
    for (const auto& attempt : directory_attempts)
      impl_->client_attempt_ids.push_back(attempt.attempt_id);
    impl_->retained_search.Retain(search_attempt);
    impl_->client_running = true;
    REXSYS_INFO("NAT traversal: retained discovery search generation={} socket={} for Join/Leave",
                search_attempt, socket);
    impl_->client_thread = std::thread([impl = impl_.get()] { impl->RunClient(); });
  } else {
    CloseSocket(socket);
  }
  return results;
}
std::optional<SessionRecord> LanDiscoveryService::Join(const SessionRecord& session,
                                                       const SessionMember& member,
                                                       uint32_t timeout_ms) {
  if(impl_->private_configured)return impl_->private_adapter?impl_->private_adapter->Join(session,member,timeout_ms):std::nullopt;
  auto admission_lease = directory_.AcquireClientAdmissionSocket(member.user_index, session);
  if(!impl_->legacy_diagnostics&&!admission_lease)return std::nullopt;
  if (!admission_lease && directory_.HasClientAdmission(member.user_index)) return std::nullopt;
  if (!admission_lease) impl_->client_exchange = true;
  struct ExchangeScope { std::function<void()> release; ~ExchangeScope() { release(); } };
  const ExchangeScope exchange_scope{[&] {
    if (!admission_lease) impl_->client_exchange = false;
  }};
  std::shared_ptr<ArbitrationClientBinding> binding;
  {
    std::lock_guard record_lock(*session.mutex);
    if (session.state == SessionState::kDeleted) return std::nullopt;
    binding = session.arbitration_client;
    if (binding) {
      // Never acquire binding mutex while holding record mutex; creation and
      // confirmation flags use atomics below.
      if (!binding->confirmed && !binding->credential_received && std::chrono::steady_clock::now() - binding->created >=
          SessionArbitrationAuthority::kInitialJoinRetryWindow) {
        session.arbitration_client.reset(); binding.reset();
      }
    }
  }
  if (!binding) {
    const auto challenge = NewArbitrationToken();
    const auto attempt = NewArbitrationToken();
    auto key = NewArbitrationKey();
    if (challenge && attempt && key && impl_->machine_id) {
      binding = std::make_shared<ArbitrationClientBinding>();
      binding->identity = RecordIdentity(session);
      binding->xuid = member.xuid; binding->machine_id = impl_->machine_id;
      binding->challenge = *challenge; binding->attempt = *attempt; binding->key = std::move(key);
      binding->socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
      if (binding->socket == kInvalidSocket || !BindLanSocket(binding->socket, 0) || !SetNonBlocking(binding->socket)) binding.reset();
    }
  }
  if (binding) {
    std::lock_guard record_lock(*session.mutex);
    if (session.state == SessionState::kDeleted) return std::nullopt;
    if (session.arbitration_client) binding = session.arbitration_client;
    else session.arbitration_client = binding;
  }
  std::optional<SessionRecord> result;
  bool expired_join = false;
  if (binding && binding->xuid == member.xuid && binding->identity == RecordIdentity(session)) {
    std::lock_guard binding_lock(binding->mutex);
    const auto join_socket = admission_lease ? SOCKET(admission_lease->socket()) :
        (impl_->client_socket != kInvalidSocket ? impl_->client_socket : binding->socket);
    const bool already_has_credential = NonzeroToken(binding->credential);
    result = Exchange(session, &member, kJoin, impl_->title_id, impl_->port, timeout_ms,join_socket,binding,
                      admission_lease ? &*admission_lease : nullptr, &expired_join);
    if (result && !already_has_credential)
      result = Exchange(*result,&member,kJoin,impl_->title_id,impl_->port,
                        std::min(timeout_ms,250u),join_socket,binding,
                        admission_lease ? &*admission_lease : nullptr, &expired_join);
    if (result) binding->confirmed = true;
  }
  if (expired_join) {
    // Drop only this exact unconfirmed pending binding after releasing its
    // mutex. Silence or an unauthenticated packet never rotates credentials.
    std::lock_guard record_lock(*session.mutex);
    if (session.state != SessionState::kDeleted && session.arbitration_client == binding &&
        binding->identity == RecordIdentity(session) && !binding->confirmed) {
      session.arbitration_client.reset();
    }
  }
  return result;
}
std::optional<ArbitrationSnapshot> LanDiscoveryService::RegisterArbitration(
    const std::shared_ptr<SessionRecord>& session, uint64_t local_xuid, uint64_t nonce) {
  if(impl_->private_configured&&session&&session->host_xuid!=local_xuid)
    return impl_->private_adapter?impl_->private_adapter->RegisterArbitration(session,local_xuid,nonce):std::nullopt;
  if (!session || !local_xuid || !nonce) return std::nullopt;
  std::shared_ptr<ArbitrationClientBinding> binding;
  DiscoveryPacket packet{};
  {
    std::lock_guard record_lock(*session->mutex);
    if (session->state == SessionState::kDeleted || session->nonce != nonce) return std::nullopt;
    if (session->arbitration && session->host_xuid == local_xuid) {
      if (!NonzeroToken(session->arbitration_local_attempt)) {
        const auto attempt = NewArbitrationToken();
        if (!attempt) return std::nullopt;
        session->arbitration_local_attempt = *attempt;
      }
      const auto status = session->arbitration->RegisterLocal(local_xuid,
          session->host_machine_id, nonce, session->arbitration_local_attempt);
      if (status != ArbitrationStatus::kAccepted && status != ArbitrationStatus::kReplay) return std::nullopt;
      return session->arbitration->Snapshot();
    }
    binding = session->arbitration_client;
    if (!binding || binding->xuid != local_xuid || binding->identity != RecordIdentity(*session)) return std::nullopt;
    packet = Encode(*session, impl_->title_id);
  }
  std::lock_guard binding_lock(binding->mutex);
  if (!binding->confirmed || !NonzeroToken(binding->credential) || binding->socket == kInvalidSocket ||
      !binding->target.ipv4 || !binding->target.port) return std::nullopt;
  const auto request_id = NewArbitrationToken();
  if (!request_id) return std::nullopt;
  std::copy(request_id->begin(),request_id->end(),packet.request_id);
  packet.type = kRegister;
  packet.member_count = htonl(1);
  std::memset(packet.members, 0, sizeof(packet.members));
  packet.members[0].xuid = Swap64(local_xuid);
  packet.members[0].machine_id = Swap64(binding->machine_id);
  std::copy(binding->attempt.begin(), binding->attempt.end(), packet.attempt);
  if (!SignPacket(packet, binding->credential, "session-register-v2")) return std::nullopt;
  sockaddr_in target{}; target.sin_family = AF_INET;
  target.sin_addr.s_addr = binding->target.ipv4; target.sin_port = htons(binding->target.port);
  const auto deadline = std::chrono::steady_clock::now() + std::chrono::milliseconds(1500);
  auto next_send = std::chrono::steady_clock::time_point{};
  while (std::chrono::steady_clock::now() < deadline) {
    if (std::chrono::steady_clock::now() >= next_send) {
      sendto(binding->socket, reinterpret_cast<const char*>(&packet), sizeof(packet), 0,
             reinterpret_cast<sockaddr*>(&target), sizeof(target));
      next_send = std::chrono::steady_clock::now() + std::chrono::milliseconds(250);
    }
    DiscoveryPacket response{}; sockaddr_in source{}; socket_len_t length = sizeof(source);
    const auto count = ReceiveDatagram(binding->socket, reinterpret_cast<char*>(&response), sizeof(response), 0,
                                       reinterpret_cast<sockaddr*>(&source), &length);
    if (count == sizeof(response) && source.sin_addr.s_addr == target.sin_addr.s_addr && source.sin_port == target.sin_port &&
        ntohl(response.magic) == kDiscoveryMagic && ntohs(response.version) == kDiscoveryVersion &&
        response.type == kRegisterReply && ntohl(response.title_id) == impl_->title_id &&
        !response.reserved && !response.reserved2 && !response.reserved3 &&
        WireIdentity(response) == binding->identity && WireToken(response.attempt) == binding->attempt &&
        WireToken(response.request_id) == *request_id &&
        !NonzeroToken(WireToken(response.credential)) && VerifyPacket(response, binding->credential, "session-register-reply-v2")) {
      auto advertisement = response; advertisement.type = kAdvertisement;
      const auto decoded = Decode(advertisement, impl_->title_id, source.sin_addr.s_addr);
      const uint32_t count_members = ntohl(response.member_count);
      const uint32_t mask = ntohl(response.registered_mask);
      if (!decoded || count_members > kMaxWireMembers || (mask >> count_members) || !Swap64(response.revision)) continue;
      ArbitrationSnapshot snapshot{binding->identity, Swap64(response.revision), {}};
      std::unordered_set<uint64_t> machines;
      bool requester_present = false;
      for (size_t i = 0; i < decoded->members.size(); ++i) {
        if (!(mask & (1u << i))) continue;
        const auto& member = decoded->members[i];
        if (!member.machine_id || !machines.insert(member.machine_id).second) { snapshot.registrants.clear(); break; }
        if (member.xuid == local_xuid && member.machine_id == binding->machine_id) requester_present = true;
        snapshot.registrants.push_back({member.machine_id, 0, {member.xuid}});
      }
      if (!requester_present || snapshot.registrants.empty()) continue;
      std::lock_guard record_lock(*session->mutex);
      if (session->state == SessionState::kDeleted || session->arbitration_client != binding ||
          RecordIdentity(*session) != binding->identity || session->nonce != nonce) return std::nullopt;
      if (snapshot.revision < session->arbitration_revision) continue;
      for (auto& member : session->members) {
        const auto found = std::find_if(decoded->members.begin(), decoded->members.end(),
            [&](const auto& current) { return current.xuid == member.xuid; });
        if (found != decoded->members.end()) {
          member.machine_id = found->machine_id;
          member.gameplay_address = found->gameplay_address;
        }
      }
      session->arbitration_revision = snapshot.revision;
      return snapshot;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
  return std::nullopt;
}

std::optional<SessionRecord> LanDiscoveryService::Leave(const SessionRecord& session, uint64_t xuid,
                                                        uint32_t timeout_ms) {
  if(impl_->private_configured)return impl_->private_adapter?impl_->private_adapter->Leave(session,xuid,timeout_ms):std::nullopt;
  if(!impl_->legacy_diagnostics&&(!session.arbitration_client||!session.arbitration_client->confirmed||
     session.arbitration_client->xuid!=xuid||session.arbitration_client->identity!=RecordIdentity(session)))return std::nullopt;
  SessionMember member;
  member.xuid = xuid;
  impl_->client_exchange = true;
  auto binding = session.arbitration_client;
  std::optional<SessionRecord> result;
  if (binding && binding->xuid == xuid) {
    std::lock_guard binding_lock(binding->mutex);
    result = Exchange(session, &member, kLeave, impl_->title_id, impl_->port, timeout_ms,
                      impl_->client_socket, binding);
  }
  impl_->client_exchange = false;
  return result;
}
std::optional<ReadyConfiguredInvite>
LanDiscoveryService::ReadyConfiguredInviteResult(
    const ConfiguredInviteOperationIdentity& operation,
    const DirectoryTraversalAttempt& attempt,
    uint64_t client_admission_lifecycle_token,
    uint32_t local_user_index) {
  auto candidate = directory_.ReadyClientAdmission(local_user_index);
  if (!candidate || !candidate->session ||
      candidate->local_user_index != operation.local_user_index ||
      candidate->local_user_xuid != operation.local_xuid ||
      candidate->title_id != operation.title_id ||
      !client_admission_lifecycle_token ||
      candidate->lifecycle_token != client_admission_lifecycle_token ||
      candidate->directory_session_id != attempt.session_id ||
      candidate->attempt_id != attempt.attempt_id ||
      candidate->directory_session_id != candidate->session->traversal_session_id ||
      candidate->attempt_id != candidate->session->traversal_attempt_id ||
      candidate->session->traversal_capability != attempt.capability ||
      !candidate->private_allocation_eligible)
    return std::nullopt;
  ReadyConfiguredInvite ready;
  ready.operation = operation;
  ready.directory_session_id = candidate->directory_session_id;
  ready.directory_attempt_id = candidate->attempt_id;
  ready.admission_generation = candidate->admission_generation;
  ready.lease_revision = candidate->lease_revision;
  ready.client_admission_lifecycle_token = candidate->lifecycle_token;
  ready.host_ready = true;
  ready.private_allocation_eligible = true;
  {
    std::lock_guard lock(*candidate->session->mutex);
    ready.xbox_session_id = candidate->session->info.id;
    ready.host_xuid = candidate->session->host_xuid;
    ready.exchange_key = candidate->session->info.key;
    ready.host_endpoint = candidate->session->info.host_address;
    ready.discovery_endpoint = candidate->session->discovery_address;
    ready.xnaddr = {candidate->session->info.ethernet_address,
                    candidate->session->info.online_address};
    ready.nonce = candidate->session->nonce;
  }
  if (!ready.host_xuid || !ready.host_endpoint.ipv4 ||
      !ready.host_endpoint.port || !ready.discovery_endpoint.ipv4 ||
      !ready.discovery_endpoint.port ||
      ready.xnaddr != ReconstructXnAddrIdentity(ready.host_xuid))
    return std::nullopt;
  return ready;
}

std::optional<ReadyAcceptedSessionCandidate>
LanDiscoveryService::ReadyAcceptedSession(uint32_t local_user_index) {
  return directory_.ReadyClientAdmission(local_user_index);
}
uint32_t LanDiscoveryService::DetermineLanIpv4() {
  if(!REXCVAR_GET(private_lan_invitation_file).empty()&&REXCVAR_GET(lan_bind_address).empty())return htonl(INADDR_LOOPBACK);

  const auto& configured = REXCVAR_GET(lan_bind_address);
  if (!configured.empty()) {
    in_addr address{};
    if (inet_pton(AF_INET, configured.c_str(), &address) == 1)
      return address.s_addr;
    REXSYS_ERROR("Invalid configured LAN bind address '{}'", configured);
    return htonl(INADDR_LOOPBACK);
  }
#if REX_PLATFORM_MAC
  {
    // macOS host names are usually "<name>.local", whose lookup goes through
    // mDNS and may stall or yield nothing. Enumerate the interfaces instead,
    // with the same preference: the first bindable non-loopback IPv4, replaced
    // by the first directly routable private LAN address.
    ifaddrs* interfaces = nullptr;
    if (getifaddrs(&interfaces) == 0) {
      uint32_t result = htonl(INADDR_LOOPBACK);
      for (auto* item = interfaces; item; item = item->ifa_next) {
        if (!item->ifa_addr || item->ifa_addr->sa_family != AF_INET ||
            !(item->ifa_flags & IFF_UP) || !(item->ifa_flags & IFF_RUNNING) ||
            (item->ifa_flags & IFF_LOOPBACK))
          continue;
        const auto* address = reinterpret_cast<const sockaddr_in*>(item->ifa_addr);
        if (address->sin_addr.s_addr == htonl(INADDR_LOOPBACK) ||
            !IsLocallyBindableIpv4(address->sin_addr.s_addr))
          continue;
        if (result == htonl(INADDR_LOOPBACK))
          result = address->sin_addr.s_addr;
        if (IsPrivateLanIpv4(address->sin_addr.s_addr)) {
          result = address->sin_addr.s_addr;
          break;
        }
      }
      freeifaddrs(interfaces);
      if (result != htonl(INADDR_LOOPBACK))
        return result;
    }
    // Fall through to the host-name lookup below.
  }
#endif
  char hostname[256]{};
  if (gethostname(hostname, sizeof(hostname)) != 0)
    return htonl(INADDR_LOOPBACK);
  addrinfo hints{};
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_DGRAM;
  addrinfo* addresses = nullptr;
  if (getaddrinfo(hostname, nullptr, &hints, &addresses) != 0)
    return htonl(INADDR_LOOPBACK);
  uint32_t result = htonl(INADDR_LOOPBACK);
  for (auto* item = addresses; item; item = item->ai_next) {
    auto* address = reinterpret_cast<sockaddr_in*>(item->ai_addr);
    if (address->sin_addr.s_addr != htonl(INADDR_LOOPBACK) &&
        IsLocallyBindableIpv4(address->sin_addr.s_addr)) {
      if (result == htonl(INADDR_LOOPBACK))
        result = address->sin_addr.s_addr;
      // Prefer a directly routable private LAN over VPN/CGNAT and virtual
      // adapters. Discovery packets remain portable UDP broadcasts, while the
      // advertised address is the one a peer on the local network can reach.
      if (IsPrivateLanIpv4(address->sin_addr.s_addr)) {
        result = address->sin_addr.s_addr;
        break;
      }
    }
  }
  freeaddrinfo(addresses);
  return result;
}

std::optional<uint64_t> ResolveRexGlueLocalUserXuid(
    uint32_t local_user_index, std::optional<uint64_t> current_profile_xuid) {
  if (local_user_index != 0 || !current_profile_xuid || !*current_profile_xuid)
    return std::nullopt;
  return current_profile_xuid;
}

XSession::XSession(KernelState* state) : XObject(state, kObjectType) {}
XSession::~XSession() {
  if (kernel_state()) {
    kernel_state()->session_manager()->ReleaseRecord(record());
    kernel_state()->session_manager()->UnregisterObject(this);
  }
}
bool XSession::Initialize() {
  if (!CreateNative(16))
    return false;
  kernel_state()->session_manager()->RegisterObject(this);
  return true;
}
void XSession::set_record(std::shared_ptr<SessionRecord> value) {
  auto guard = rex::thread::global_critical_region::AcquireDirect();
  auto previous = record_.exchange(value, std::memory_order_acq_rel);
  if (previous && previous != value)
    kernel_state()->session_manager()->ReleaseRecord(previous);
  kernel_state()->session_manager()->online_status().Attach(this, value);
}

struct SessionManager::ConfiguredInviteOperation {
  explicit ConfiguredInviteOperation(ConfiguredInviteOperationIdentity value)
      : identity(std::move(value)) {}

  void PublishWorker(std::jthread value) {
    std::lock_guard lock(worker_mutex);
    worker = std::move(value);
    worker_published = true;
    worker_cv.notify_all();
  }
  void RequestStop() {
    stop_source.request_stop();
    wait_cv.notify_all();
    worker_cv.notify_all();
  }
  void WaitUntilPublishedAndJoin() {
    std::lock_guard join_lock(join_mutex);
    std::unique_lock lock(worker_mutex);
    worker_cv.wait(lock, [this] { return worker_published; });
    auto* published_worker = &worker;
    lock.unlock();
    if (published_worker->joinable() &&
        published_worker->get_id() != std::this_thread::get_id())
      published_worker->join();
  }

  ConfiguredInviteOperationIdentity identity;
  std::stop_source stop_source;
  std::mutex worker_mutex;
  std::condition_variable worker_cv;
  bool worker_published = false;
  std::jthread worker;
  std::mutex join_mutex;
  std::mutex wait_mutex;
  std::condition_variable wait_cv;
  std::optional<DirectoryTraversalAttempt> issued_attempt;
  uint64_t operation_socket = 0;
  bool admission_owns_attempt = false;
  uint64_t admission_lifecycle_token = 0;
  std::shared_ptr<SessionRecord> correlated_session;
  std::string last_handoff_deferral;
  bool handoff_began = false;
  // One successful notification belongs to this operation token/title generation.
  // Lease renewal or client-session teardown must not notify the title again.
  bool handoff_notified = false;
  // Started by in-game team search: the title joins by the session it picked
  // from the search results, so no accepted-invite notification is sent.
  bool search_join = false;
};

SessionManager::SessionManager(KernelState* state, uint16_t discovery_port,
                               SessionManagerDependencies dependencies)
    // KernelState constructs the session service before the executable module
    // is loaded, so the title ID is not available yet. XGI binds the actual
    // title ID immediately before advertising or searching.
    : kernel_state_(state),
      online_status_(state && state->user_profile() ? state->user_profile()->xuid() : 0,
                     state && state->user_profile() ? state->user_profile()->name() : "",
                     REXCVAR_GET(online_status_directory)),
      registry_([this](const auto& id) { OnRegistryChanged(id); }),
      user_identity_(
          dependencies.user_identity
              ? std::move(dependencies.user_identity)
              : SessionDirectoryClient::LocalUserIdentityProvider(
                    [state](uint32_t local_user_index) -> std::optional<uint64_t> {
                      auto* profile = state ? state->user_profile() : nullptr;
                      return ResolveRexGlueLocalUserXuid(
                          local_user_index,
                          profile ? std::optional<uint64_t>(profile->xuid())
                                  : std::nullopt);
                    })),
      configured_invite_discovery_(
          dependencies.configured_invite_discovery
              ? std::move(dependencies.configured_invite_discovery)
              : ConfiguredInviteDiscoveryOperation(
                    [](LanDiscoveryService& discovery,
                       const DirectoryInviteJoinAttempt& issued,
                       uint32_t timeout_ms,
                       const std::function<bool()>& current,
                       const std::function<void(ConfiguredInviteStage)>& observe) {
                      return discovery.DiscoverConfiguredInvite(
                          issued, timeout_ms, current, observe);
                    })),
      configured_invite_stage_observer_(
          std::move(dependencies.configured_invite_stage_observer)),
      accepting_listener_count_(
          dependencies.accepting_listener_count
              ? std::move(dependencies.accepting_listener_count)
              : [state](uint32_t id) -> size_t {
                  return state ? state->CountNotifyListenersAccepting(id) : 0;
                }),
      broadcast_notification_(
          dependencies.broadcast_notification
              ? std::move(dependencies.broadcast_notification)
              : [state](uint32_t id, uint32_t data) -> size_t {
                  return state ? state->BroadcastNotificationIfAtLeast(id, data, 1) : 0;
                }),
      current_title_id_(dependencies.current_title_id
                            ? std::move(dependencies.current_title_id)
                            : [state] { return state ? state->title_id() : 0; }),
      discovery_(0, discovery_port, {}, user_identity_,
                 std::move(dependencies.client_admission_transport), false,
                 std::move(dependencies.invite_join_attempt_transport),
                 std::move(dependencies.join_attempt_completion_transport)) {
  discovery_.SetArbitrationMachineId(registry_.local_machine_id());
}
SessionManager::~SessionManager() {
  ShutdownAsyncActivity();
}
void SessionManager::RegisterObject(XSession* session) {
  std::lock_guard lock(object_mutex_);
  objects_[session->guest_object()] = session;
}
void SessionManager::UnregisterObject(XSession* session) {
  online_status_.Detach(session);
  std::lock_guard lock(object_mutex_);
  objects_.erase(session->guest_object());
}
void SessionManager::ReleaseRecord(const std::shared_ptr<SessionRecord>& record) {
  if (!record)
    return;
  auto* profile = kernel_state_ ? kernel_state_->user_profile() : nullptr;
  if (profile && record->host_xuid == profile->xuid()) {
    discovery_.StopAdvertising();
    registry_.Delete(record->info.id);
  }
}
XSession* SessionManager::LookupObject(uint32_t guest_object) const {
  std::lock_guard lock(object_mutex_);
  auto it = objects_.find(guest_object);
  return it == objects_.end() ? nullptr : it->second;
}

namespace {
bool SessionMatchesReady(const SessionRecord& session,
                         const ReadyConfiguredInvite& ready) {
  std::lock_guard lock(*session.mutex);
  return session.state != SessionState::kDeleted &&
         session.info.id == ready.xbox_session_id &&
         session.info.host_address == ready.host_endpoint &&
         session.info.ethernet_address == ready.xnaddr.ethernet_address &&
         session.info.online_address == ready.xnaddr.online_address &&
         session.info.key == ready.exchange_key &&
         session.host_xuid == ready.host_xuid &&
         session.traversal_session_id == ready.directory_session_id &&
         session.traversal_attempt_id == ready.directory_attempt_id;
}

AcceptedInviteIdentity AcceptedIdentity(const ReadyConfiguredInvite& ready) {
  AcceptedInviteIdentity identity;
  identity.operation_token = ready.operation.operation_token;
  identity.title_generation = ready.operation.title_generation;
  identity.title_id = ready.operation.title_id;
  identity.local_user_index = ready.operation.local_user_index;
  identity.local_xuid = ready.operation.local_xuid;
  identity.directory_session_id = ready.directory_session_id;
  identity.directory_attempt_id = ready.directory_attempt_id;
  identity.admission_generation = ready.admission_generation;
  identity.admission_lifecycle_token = ready.client_admission_lifecycle_token;
  identity.xbox_session_id = ready.xbox_session_id;
  return identity;
}
}  // namespace

bool SessionManager::RuntimeIdentityMatches(
    const ConfiguredInviteOperationIdentity& identity) const {
  const auto user = user_identity_ ? user_identity_(identity.local_user_index)
                                   : std::nullopt;
  const auto title = current_title_id_ ? current_title_id_() : 0;
  return user && *user == identity.local_xuid &&
         (!kernel_state_ || title == identity.title_id) &&
         (!title || title == identity.title_id);
}

void SessionManager::OnRegistryChanged(
    const std::array<uint8_t, 8>& session_id) {
  auto snapshot = accepted_invites_.Snapshot(0);
  if (!snapshot || snapshot->first.xbox_session_id != session_id)
    return;
  auto registered = registry_.Find(session_id);
  if (!registered) {
    REXSYS_INFO("INVITE_DIAG op={} gen={} ACCEPTED_RECORD_INVALIDATED_REGISTRY_DELETED",
                snapshot->first.operation_token,
                snapshot->first.title_generation);
    accepted_invites_.Invalidate(snapshot->first);
    return;
  }
  SessionInfo info;
  uint64_t host_xuid = 0;
  bool current = false;
  {
    std::lock_guard lock(*registered->mutex);
    info = registered->info;
    host_xuid = registered->host_xuid;
    current = registered->state != SessionState::kDeleted &&
              registered->traversal_session_id ==
                  snapshot->first.directory_session_id &&
              registered->traversal_attempt_id ==
                  snapshot->first.directory_attempt_id;
  }
  const auto guest_info = SerializeGuestSessionInfo(info);
  bool xuid_matches = true;
  for (size_t i = 0; i < 8; ++i)
    xuid_matches &= snapshot->second[8 + i] ==
                    uint8_t(host_xuid >> ((7 - i) * 8));
  if (!current ||
      !std::equal(guest_info.begin(), guest_info.end(),
                  snapshot->second.begin() + 20) ||
      !xuid_matches) {
    REXSYS_INFO("INVITE_DIAG op={} gen={} ACCEPTED_RECORD_INVALIDATED_REGISTRY_MISMATCH",
                snapshot->first.operation_token,
                snapshot->first.title_generation);
    accepted_invites_.Invalidate(snapshot->first);
  }
}

void SessionManager::TryPublishAcceptedInvite(
    const std::shared_ptr<ConfiguredInviteOperation>& operation) {
  std::lock_guard lock(configured_invite_mutex_);
  auto defer = [&](std::string_view reason) {
    if (operation->last_handoff_deferral != reason) {
      operation->last_handoff_deferral = reason;
      REXSYS_INFO("INVITE_DIAG op={} gen={} ACCEPTED_INVITE_HANDOFF_DEFERRED_{}",
                  operation->identity.operation_token,
                  operation->identity.title_generation, reason);
    }
  };
  if (operation->handoff_notified ||
      configured_invite_state_ == ConfiguredInviteLifecycleState::kPublished)
    return;
  if (async_shutdown_.load(std::memory_order_acquire) ||
      configured_invite_operation_ != operation ||
      operation->stop_source.stop_requested()) {
    defer("OPERATION_NOT_CURRENT");
    return;
  }
  if (configured_invite_state_ !=
      ConfiguredInviteLifecycleState::kReadyForAcceptedInvite ||
      !ready_configured_invite_ || !operation->issued_attempt) {
    defer("READY_STATE_MISSING");
    return;
  }
  if (!RuntimeIdentityMatches(operation->identity)) {
    defer("IDENTITY_OR_TITLE_CHANGED");
    return;
  }
  const auto listeners =
      operation->search_join ? size_t(1) : accepting_listener_count_(kXnLiveInviteAccepted);
  if (!listeners) {
    defer("NO_ACCEPTING_LISTENER");
    return;
  }
  if (!operation->handoff_began) {
    operation->handoff_began = true;
    REXSYS_INFO("INVITE_DIAG op={} gen={} ACCEPTED_INVITE_HANDOFF_BEGIN listeners={}",
                operation->identity.operation_token,
                operation->identity.title_generation, listeners);
  }
  const auto ready = *ready_configured_invite_;
  auto current = discovery_.ReadyConfiguredInviteResult(
      operation->identity, *operation->issued_attempt,
      operation->admission_lifecycle_token,
      operation->identity.local_user_index);
  if (!current || current->directory_attempt_id != ready.directory_attempt_id ||
      current->directory_session_id != ready.directory_session_id ||
      current->admission_generation != ready.admission_generation ||
      current->lease_revision != ready.lease_revision ||
      current->xbox_session_id != ready.xbox_session_id ||
      current->host_xuid != ready.host_xuid ||
      !ready.host_ready || !ready.private_allocation_eligible ||
      !operation->correlated_session ||
      !SessionMatchesReady(*operation->correlated_session, ready)) {
    REXSYS_WARN("INVITE_DIAG op={} gen={} ACCEPTED_INVITE_HANDOFF_FAILED_GRANT_OR_CORRELATION private={} host_ready={}",
                operation->identity.operation_token,
                operation->identity.title_generation,
                ready.private_allocation_eligible, ready.host_ready);
    return;
  }
  REXSYS_INFO("INVITE_DIAG op={} gen={} ACCEPTED_RECORD_BUILD_BEGIN invitee={:016X} inviter={:016X} title={:08X} xbox_session={:02X}{:02X}{:02X}{:02X}{:02X}{:02X}{:02X}{:02X} private={}",
              operation->identity.operation_token,
              operation->identity.title_generation,
              ready.operation.local_xuid, ready.host_xuid,
              ready.operation.title_id,
              ready.xbox_session_id[0], ready.xbox_session_id[1],
              ready.xbox_session_id[2], ready.xbox_session_id[3],
              ready.xbox_session_id[4], ready.xbox_session_id[5],
              ready.xbox_session_id[6], ready.xbox_session_id[7],
              ready.private_allocation_eligible);
  auto record = SerializeAcceptedInviteRecord(ready);
  if (!record) {
    REXSYS_WARN("INVITE_DIAG op={} gen={} ACCEPTED_RECORD_BUILD_FAIL reason=serialization",
                operation->identity.operation_token,
                operation->identity.title_generation);
    return;
  }

  // XGI joins by the Xbox session ID. Never notify until that exact record is
  // present and can be looked up through the same registry path.
  REXSYS_INFO("INVITE_DIAG op={} gen={} SESSION_REGISTRY_INSTALL_BEGIN",
              operation->identity.operation_token,
              operation->identity.title_generation);
  auto registered = registry_.Find(ready.xbox_session_id);
  bool public_observation = false;
  if (registered) {
    std::lock_guard record_lock(*registered->mutex);
    public_observation = registered->traversal_attempt_id.empty();
  }
  if (!registered || public_observation)
    registered = registry_.UpsertDiscovered(*operation->correlated_session);
  if (!registered || !SessionMatchesReady(*registered, ready) ||
      registry_.Find(ready.xbox_session_id) != registered) {
    REXSYS_WARN("INVITE_DIAG op={} gen={} SESSION_REGISTRY_INSTALL_FAIL",
                operation->identity.operation_token,
                operation->identity.title_generation);
    return;
  }
  REXSYS_INFO("INVITE_DIAG op={} gen={} SESSION_REGISTRY_INSTALL_SUCCESS SESSION_REGISTRY_LOOKUP_SUCCESS",
              operation->identity.operation_token,
              operation->identity.title_generation);
  if (operation->search_join) {
    // The title is already waiting in its own join call for this session.
    REXSYS_INFO("SEARCH_DIAG op={} gen={} SEARCH_JOIN_READY",
                operation->identity.operation_token,
                operation->identity.title_generation);
    operation->handoff_notified = true;
    configured_invite_state_ = ConfiguredInviteLifecycleState::kPublished;
    return;
  }
  const auto identity = AcceptedIdentity(ready);
  if (!accepted_invites_.Publish(identity, *record)) {
    auto existing = accepted_invites_.Snapshot(identity.local_user_index);
    if (existing && existing->first == identity && existing->second == *record) {
      configured_invite_state_ = ConfiguredInviteLifecycleState::kPublished;
    } else {
      REXSYS_WARN("INVITE_DIAG op={} gen={} ACCEPTED_INVITE_HANDOFF_FAILED_STORE_CONFLICT",
                  operation->identity.operation_token,
                  operation->identity.title_generation);
    }
    return;
  }
  REXSYS_INFO("INVITE_DIAG op={} gen={} ACCEPTED_RECORD_PUBLISHED private={}",
              operation->identity.operation_token,
              operation->identity.title_generation,
              ready.private_allocation_eligible);
  if (broadcast_notification_(kXnLiveInviteAccepted, 0) < 1) {
    REXSYS_WARN("INVITE_DIAG op={} gen={} XNOTIFY_02000002_BROADCAST_FAIL no_listeners",
                operation->identity.operation_token,
                operation->identity.title_generation);
    accepted_invites_.Invalidate(identity);
    return;
  }
  REXSYS_INFO("INVITE_DIAG op={} gen={} XNOTIFY_02000002_BROADCAST user=0",
              operation->identity.operation_token,
              operation->identity.title_generation);
  operation->handoff_notified = true;
  configured_invite_state_ = ConfiguredInviteLifecycleState::kPublished;
}

std::optional<AcceptedInviteStore::ReadLease>
SessionManager::GetAcceptedInviteRecord(uint32_t local_user_index,
                                        uint32_t title_id) {
  std::lock_guard lock(configured_invite_mutex_);
  auto operation = configured_invite_operation_;
  if (!operation || configured_invite_state_ !=
                        ConfiguredInviteLifecycleState::kPublished ||
      !ready_configured_invite_ ||
      local_user_index != operation->identity.local_user_index ||
      title_id != operation->identity.title_id ||
      !RuntimeIdentityMatches(operation->identity) ||
      !operation->issued_attempt) {
    REXSYS_WARN("INVITE_DIAG XLIVEBASE_58023_FAIL_NO_PUBLISHED_OPERATION user={} title={:08X} op={} gen={}",
                local_user_index, title_id,
                operation ? operation->identity.operation_token : 0,
                operation ? operation->identity.title_generation : 0);
    return std::nullopt;
  }
  auto current = discovery_.ReadyConfiguredInviteResult(
      operation->identity, *operation->issued_attempt,
      operation->admission_lifecycle_token, local_user_index);
  if (!current || !current->host_ready ||
      !current->private_allocation_eligible ||
      current->admission_generation !=
          ready_configured_invite_->admission_generation ||
      current->xbox_session_id != ready_configured_invite_->xbox_session_id ||
      current->host_xuid != ready_configured_invite_->host_xuid) {
    REXSYS_WARN("INVITE_DIAG op={} gen={} XLIVEBASE_58023_FAIL_GRANT_NOT_CURRENT",
                operation->identity.operation_token,
                operation->identity.title_generation);
    return std::nullopt;
  }
  auto registered = registry_.Find(current->xbox_session_id);
  if (!registered || !SessionMatchesReady(*registered, *current)) {
    REXSYS_WARN("INVITE_DIAG op={} gen={} XLIVEBASE_58023_FAIL_REGISTRY_NOT_FOUND",
                operation->identity.operation_token,
                operation->identity.title_generation);
    return std::nullopt;
  }
  auto lease = accepted_invites_.Acquire(local_user_index, title_id);
  REXSYS_INFO("INVITE_DIAG op={} gen={} XLIVEBASE_58023_{} user={} title={:08X}",
              operation->identity.operation_token,
              operation->identity.title_generation,
              lease ? "STORE_ACQUIRED" : "FAIL_STORE_EMPTY",
              local_user_index, title_id);
  return lease;
}

bool SessionManager::CompleteAcceptedInviteJoin(
    uint32_t local_user_index, uint64_t local_xuid,
    const std::shared_ptr<SessionRecord>& session) {
  if(session&&session->private_lan_invitation)return discovery_.ActivatePrivateLanGameplay(session,local_xuid);
  std::lock_guard lock(configured_invite_mutex_);
  auto operation = configured_invite_operation_;
  size_t member_count = 0;
  uint64_t host_xuid = 0;
  if (session) {
    std::lock_guard session_lock(*session->mutex);
    member_count = session->members.size();
    host_xuid = session->host_xuid;
  }
  REXSYS_INFO(
      "GAMEPLAY_JOIN_COMPLETE_BEGIN local_user={} local_xuid={:016X} "
      "host_xuid={:016X} state={} members={} session_present={} invite_present={} "
      "session={} admission={} attempt={}",
      local_user_index, local_xuid, host_xuid,
      static_cast<uint32_t>(configured_invite_state_), member_count,
      session != nullptr, ready_configured_invite_.has_value(),
      ready_configured_invite_ ? ready_configured_invite_->directory_session_id : "",
      ready_configured_invite_ ? ready_configured_invite_->admission_generation : "",
      ready_configured_invite_ ? ready_configured_invite_->directory_attempt_id : "");
  auto reject = [&](const char* reason) {
    REXSYS_WARN(
        "GAMEPLAY_JOIN_COMPLETE_REJECT reason={} local_user={} local_xuid={:016X} "
        "host_xuid={:016X} session={} admission={} attempt={}",
        reason, local_user_index, local_xuid, host_xuid,
        ready_configured_invite_ ? ready_configured_invite_->directory_session_id : "",
        ready_configured_invite_ ? ready_configured_invite_->admission_generation : "",
        ready_configured_invite_ ? ready_configured_invite_->directory_attempt_id : "");
    REXSYS_INFO("GAMEPLAY_JOIN_COMPLETE_RESULT success=0 reason={} session={} admission={}",
                reason,
                ready_configured_invite_ ? ready_configured_invite_->directory_session_id : "",
                ready_configured_invite_ ? ready_configured_invite_->admission_generation : "");
    return false;
  };
  if (!operation) return reject("missing_operation");
  if (configured_invite_state_ != ConfiguredInviteLifecycleState::kPublished)
    return reject("state_not_published");
  if (!ready_configured_invite_) return reject("missing_accepted_invite");
  if (!session) return reject("missing_session");
  if (local_user_index != operation->identity.local_user_index)
    return reject("local_user_index_mismatch");
  if (local_xuid != operation->identity.local_xuid)
    return reject("local_xuid_mismatch");
  if (registry_.Find(session->info.id) != session)
    return reject("registry_session_mismatch");
  if (!SessionMatchesReady(*session, *ready_configured_invite_))
    return reject("session_identifier_or_ready_mismatch");
  {
    std::lock_guard session_lock(*session->mutex);
    if (std::none_of(session->members.begin(), session->members.end(),
                     [local_xuid](const SessionMember& member) {
                       return member.xuid == local_xuid && member.local;
                     }))
      return reject("missing_local_member");
  }
  if (operation->issued_attempt && !REXCVAR_GET(session_directory_url).empty()) {
    {
      std::lock_guard session_lock(*session->mutex);
      for (auto& member : session->members)
        if (member.local && member.xuid == local_xuid)
          member.gameplay_admission = std::make_shared<const GameplayAdmissionBinding>(
              GameplayAdmissionBinding{ready_configured_invite_->directory_session_id,
                  ready_configured_invite_->directory_attempt_id,
                  ready_configured_invite_->admission_generation});
    }
    discovery_.QueueGameplayAdmission(session, local_user_index, local_xuid,
        *operation->issued_attempt, ready_configured_invite_->admission_generation);
  } else {
    REXSYS_WARN("GAMEPLAY_JOIN_COMPLETE_NO_QUEUE reason={} session={} admission={}",
                operation->issued_attempt ? "directory_disabled" : "missing_issued_attempt",
                ready_configured_invite_->directory_session_id,
                ready_configured_invite_->admission_generation);
  }
  const auto completed_session = ready_configured_invite_->directory_session_id;
  const auto completed_admission = ready_configured_invite_->admission_generation;
  accepted_invites_.Invalidate(AcceptedIdentity(*ready_configured_invite_));
  ready_configured_invite_.reset();
  configured_invite_state_ = ConfiguredInviteLifecycleState::kCompleted;
  operation->RequestStop();
  REXSYS_INFO("GAMEPLAY_JOIN_COMPLETE_RESULT success=1 session={} admission={}",
              completed_session, completed_admission);
  return true;
}

bool SessionManager::IsConfiguredInviteOperationCurrent(
    const ConfiguredInviteOperationIdentity& identity) const {
  if (async_shutdown_.load(std::memory_order_acquire))
    return false;
  std::lock_guard lock(configured_invite_mutex_);
  return configured_invite_operation_ &&
         configured_invite_operation_->identity.operation_token ==
             identity.operation_token &&
         configured_invite_operation_->identity.title_generation ==
             identity.title_generation &&
         configured_invite_operation_->identity.title_id == identity.title_id &&
         configured_invite_operation_->identity.local_user_index ==
             identity.local_user_index &&
         configured_invite_operation_->identity.local_xuid ==
             identity.local_xuid &&
         configured_invite_operation_->identity.invite_code ==
             identity.invite_code &&
         configured_invite_state_ !=
             ConfiguredInviteLifecycleState::kCancelled;
}

void SessionManager::SetConfiguredInviteState(
    const std::shared_ptr<ConfiguredInviteOperation>& operation,
    ConfiguredInviteLifecycleState state) {
  std::lock_guard lock(configured_invite_mutex_);
  if (configured_invite_operation_ != operation ||
      configured_invite_state_ == ConfiguredInviteLifecycleState::kCancelled)
    return;
  configured_invite_state_ = state;
  if (state != ConfiguredInviteLifecycleState::kReadyForAcceptedInvite &&
      state != ConfiguredInviteLifecycleState::kPublished)
    ready_configured_invite_.reset();
  if (state == ConfiguredInviteLifecycleState::kFailed ||
      state == ConfiguredInviteLifecycleState::kExpired)
    if (auto identity = accepted_invites_.Identity(
            operation->identity.local_user_index);
        identity && identity->operation_token ==
                        operation->identity.operation_token)
      accepted_invites_.Invalidate(*identity);
}

void SessionManager::ObserveConfiguredInviteStage(
    const std::shared_ptr<ConfiguredInviteOperation>& operation,
    ConfiguredInviteStage stage) const {
  // The operation token and title generation distinguish retries without
  // disclosing the invite code or the traversal capability.
  const auto token = operation->identity.operation_token;
  const auto generation = operation->identity.title_generation;
  switch (stage) {
    case ConfiguredInviteStage::kAttemptIssued:
      REXSYS_INFO("INVITE_DIAG op={} gen={} BY_CODE_ATTEMPT_ISSUED", token, generation);
      break;
    case ConfiguredInviteStage::kTraversalReady:
      REXSYS_INFO("INVITE_DIAG op={} gen={} TRAVERSAL_READY", token, generation);
      break;
    case ConfiguredInviteStage::kHostCorrelated:
      REXSYS_INFO("INVITE_DIAG op={} gen={} HOST_CORRELATED", token, generation);
      break;
    case ConfiguredInviteStage::kReadyForAcceptedInvite:
      REXSYS_INFO("INVITE_DIAG op={} gen={} READY_FOR_ACCEPTED_INVITE", token, generation);
      break;
    default:
      break;
  }
  if (configured_invite_stage_observer_)
    configured_invite_stage_observer_(stage, operation->identity);
}

bool SessionManager::StartConfiguredInviteOperation(uint32_t title_id) {
  if (!title_id || async_shutdown_.load(std::memory_order_acquire))
    return false;
  auto normalized = NormalizeDirectoryInviteCode(runtime_invite_code());
  auto local_xuid = user_identity_ ? user_identity_(0) : std::nullopt;
  if (!normalized || !local_xuid || !*local_xuid)
    return false;

  std::shared_ptr<ConfiguredInviteOperation> operation;
  {
    std::lock_guard lock(configured_invite_mutex_);
    const bool active =
        configured_invite_operation_ &&
        configured_invite_state_ != ConfiguredInviteLifecycleState::kCompleted &&
        configured_invite_state_ != ConfiguredInviteLifecycleState::kCancelled &&
        configured_invite_state_ != ConfiguredInviteLifecycleState::kExpired &&
        configured_invite_state_ != ConfiguredInviteLifecycleState::kFailed;
    if (active || configured_invite_claim_token_)
      return false;
    ConfiguredInviteOperationIdentity identity;
    identity.operation_token = ++next_configured_invite_operation_token_;
    if (!identity.operation_token)
      identity.operation_token = ++next_configured_invite_operation_token_;
    identity.title_generation = configured_invite_title_generation_;
    identity.title_id = title_id;
    identity.local_user_index = 0;
    identity.local_xuid = *local_xuid;
    identity.invite_code = *normalized;
    operation = std::make_shared<ConfiguredInviteOperation>(std::move(identity));
    operation->search_join = search_join_next_;
    search_join_next_ = false;
    configured_invite_operation_ = operation;
    configured_invite_claim_token_ = operation->identity.operation_token;
    configured_invite_state_ = ConfiguredInviteLifecycleState::kClaimed;
    ready_configured_invite_.reset();
  }
  REXSYS_INFO("INVITE_DIAG op={} gen={} CONFIGURED_INVITE_CLAIMED title={:08X} xuid={:016X}",
              operation->identity.operation_token,
              operation->identity.title_generation, title_id, *local_xuid);

  discovery_.SetLocalUserIdentity(0, operation->identity.local_xuid);
  try {
    std::jthread worker([this, operation] {
      {
        std::unique_lock lock(operation->worker_mutex);
        operation->worker_cv.wait(lock,
                                  [&] { return operation->worker_published; });
      }
      RunConfiguredInviteOperation(operation);
    });
    operation->PublishWorker(std::move(worker));
  } catch (const std::system_error&) {
    // Cancellation must never wait for an unpublished worker after native
    // thread creation fails. Publish the empty worker before retiring claim.
    operation->PublishWorker({});
    std::lock_guard lock(configured_invite_mutex_);
    if (configured_invite_operation_ == operation) {
      configured_invite_operation_.reset();
      configured_invite_claim_token_ = 0;
      configured_invite_state_ = ConfiguredInviteLifecycleState::kFailed;
    }
    REXSYS_WARN("INVITE_DIAG op={} gen={} WORKER_CREATION_FAILED",
                operation->identity.operation_token,
                operation->identity.title_generation);
    return false;
  }
  return true;
}

void SessionManager::RunConfiguredInviteOperation(
    const std::shared_ptr<ConfiguredInviteOperation>& operation) {
  auto current = [this, operation] {
    return !operation->stop_source.stop_requested() &&
           IsConfiguredInviteOperationCurrent(operation->identity) &&
           RuntimeIdentityMatches(operation->identity);
  };
  auto observe = [this, operation](ConfiguredInviteStage stage) {
    ObserveConfiguredInviteStage(operation, stage);
    if (stage == ConfiguredInviteStage::kTraversalReady)
      SetConfiguredInviteState(
          operation, ConfiguredInviteLifecycleState::kTraversalReady);
  };
  auto fail = [&](ConfiguredInviteLifecycleState state) {
    if (current())
      SetConfiguredInviteState(operation, state);
  };
  auto cleanup = [&] {
    ObserveConfiguredInviteStage(operation, ConfiguredInviteStage::kCleanup);
    if (operation->admission_owns_attempt ||
        discovery_.HasClientAdmission(operation->identity.local_user_index)) {
      discovery_.StopClientAdmission(operation->identity.local_user_index);
      discovery_.PollClientAdmissions();
    } else {
      if (operation->operation_socket) {
        NatProbeDetach(operation->operation_socket);
#if REX_PLATFORM_WIN32
        closesocket(SOCKET(operation->operation_socket));
#else
        close(int(operation->operation_socket));
#endif
        operation->operation_socket = 0;
      }
      if (operation->issued_attempt)
        discovery_.ReleaseConfiguredInviteAttempt(*operation->issued_attempt);
    }
    operation->correlated_session.reset();
    if (auto identity = accepted_invites_.Identity(
            operation->identity.local_user_index);
        identity && identity->operation_token ==
                        operation->identity.operation_token &&
        configured_invite_state() != ConfiguredInviteLifecycleState::kPublished)
      accepted_invites_.Invalidate(*identity);
    {
      std::lock_guard lock(configured_invite_mutex_);
      if (configured_invite_claim_token_ ==
          operation->identity.operation_token)
        configured_invite_claim_token_ = 0;
      if (configured_invite_operation_ == operation &&
          configured_invite_state_ !=
              ConfiguredInviteLifecycleState::kReadyForAcceptedInvite)
        ready_configured_invite_.reset();
    }
    ObserveConfiguredInviteStage(operation,
                                 ConfiguredInviteStage::kCleanupComplete);
  };

  ObserveConfiguredInviteStage(operation, ConfiguredInviteStage::kWorkerStarted);
  if (!current()) {
    cleanup();
    return;
  }
  ObserveConfiguredInviteStage(operation,
                               ConfiguredInviteStage::kBeforeAttemptIssue);
  if (!current()) {
    cleanup();
    return;
  }
  auto issued = discovery_.IssueConfiguredInviteAttempt(
      operation->identity.invite_code, operation->identity.title_id);
  if (!issued) {
    REXSYS_WARN("INVITE_DIAG op={} gen={} BY_CODE_ATTEMPT_FAILED (unknown or expired code, or directory unreachable)",
                operation->identity.operation_token, operation->identity.title_generation);
    fail(ConfiguredInviteLifecycleState::kFailed);
    cleanup();
    return;
  }
  operation->issued_attempt = issued->attempt;
  REXSYS_INFO("INVITE_DIAG op={} gen={} BY_CODE_ATTEMPT_DETAILS attempt={} revision={}",
              operation->identity.operation_token,
              operation->identity.title_generation,
              issued->attempt.attempt_id, issued->attempt.lease_revision);
  SetConfiguredInviteState(operation,
                           ConfiguredInviteLifecycleState::kAttemptIssued);
  ObserveConfiguredInviteStage(operation, ConfiguredInviteStage::kAttemptIssued);
  if (!current()) {
    cleanup();
    return;
  }

  // The host only answers once the directory has granted this attempt, which
  // takes a poll round trip after it first hears from us; allow for that.
  auto discovered = configured_invite_discovery_(
      discovery_, *issued, kConfiguredInviteDiscoveryMs, current, observe);
  if (!discovered || !current()) {
    fail(ConfiguredInviteLifecycleState::kFailed);
    cleanup();
    return;
  }
  operation->operation_socket = discovered->socket;
  operation->correlated_session =
      std::make_shared<SessionRecord>(std::move(discovered->session));
  REXSYS_INFO("INVITE_DIAG op={} gen={} HOST_DISCOVERY_RECEIVED host_xuid={:016X} xbox_session={:02X}{:02X}{:02X}{:02X}{:02X}{:02X}{:02X}{:02X}",
              operation->identity.operation_token,
              operation->identity.title_generation,
              operation->correlated_session->host_xuid,
              operation->correlated_session->info.id[0], operation->correlated_session->info.id[1],
              operation->correlated_session->info.id[2], operation->correlated_session->info.id[3],
              operation->correlated_session->info.id[4], operation->correlated_session->info.id[5],
              operation->correlated_session->info.id[6], operation->correlated_session->info.id[7]);
  SetConfiguredInviteState(operation,
                           ConfiguredInviteLifecycleState::kHostCorrelated);
  ObserveConfiguredInviteStage(operation,
                               ConfiguredInviteStage::kHostCorrelated);
  if (!current()) {
    cleanup();
    return;
  }
  auto prepared = discovery_.PrepareClientAdmission(
      operation->identity.local_user_index, *operation->issued_attempt,
      *operation->correlated_session, operation->operation_socket);
  if (prepared != ClientAdmissionPrepareResult::kPrepared) {
    fail(ConfiguredInviteLifecycleState::kFailed);
    cleanup();
    return;
  }
  operation->admission_owns_attempt = true;
  operation->operation_socket = 0;
  auto admission_lifecycle_token = discovery_.ClientAdmissionLifecycleToken(
      operation->identity.local_user_index);
  if (!admission_lifecycle_token || !*admission_lifecycle_token) {
    fail(ConfiguredInviteLifecycleState::kFailed);
    cleanup();
    return;
  }
  operation->admission_lifecycle_token = *admission_lifecycle_token;
  if (!current() || !discovery_.ConfirmClientAdmissionSession(
                        operation->identity.local_user_index,
                        operation->correlated_session)) {
    fail(ConfiguredInviteLifecycleState::kFailed);
    cleanup();
    return;
  }

  bool ready_observed = false;
  while (current()) {
    discovery_.PollClientAdmissions();
    if (!current())
      break;
    if (!discovery_.HasClientAdmission(operation->identity.local_user_index)) {
      fail(ready_observed ? ConfiguredInviteLifecycleState::kExpired
                          : ConfiguredInviteLifecycleState::kFailed);
      break;
    }
    auto ready = discovery_.ReadyConfiguredInviteResult(
        operation->identity, *operation->issued_attempt,
        operation->admission_lifecycle_token,
        operation->identity.local_user_index);
    if (ready) {
      if (!ready_observed)
        REXSYS_INFO("INVITE_DIAG op={} gen={} HOST_GRANT_READY attempt={} admission_gen={} revision={} private={}",
                    operation->identity.operation_token,
                    operation->identity.title_generation,
                    ready->directory_attempt_id, ready->admission_generation,
                    ready->lease_revision, ready->private_allocation_eligible);
      {
        std::lock_guard lock(configured_invite_mutex_);
        if (configured_invite_operation_ == operation &&
            configured_invite_state_ !=
                ConfiguredInviteLifecycleState::kCancelled) {
          ready_configured_invite_ = std::move(*ready);
          if (configured_invite_state_ !=
              ConfiguredInviteLifecycleState::kPublished)
            configured_invite_state_ = operation->handoff_notified
                                           ? ConfiguredInviteLifecycleState::kPublished
                                           : ConfiguredInviteLifecycleState::kReadyForAcceptedInvite;
        }
      }
      if (!ready_observed) {
        ready_observed = true;
        ObserveConfiguredInviteStage(
            operation, ConfiguredInviteStage::kReadyForAcceptedInvite);
      }
      TryPublishAcceptedInvite(operation);
    } else {
      std::lock_guard lock(configured_invite_mutex_);
      // Each lease renewal is briefly "not ready" until the host acknowledges
      // the new revision. Once the invite was published to the title, keep it
      // published while the admission itself is still held (checked above):
      // a join landing in that window was otherwise rejected as
      // "state_not_published" and the joiner silently left the lobby.
      if (configured_invite_operation_ == operation &&
          configured_invite_state_ != ConfiguredInviteLifecycleState::kPublished) {
        ready_configured_invite_.reset();
        configured_invite_state_ =
            ConfiguredInviteLifecycleState::kHostCorrelated;
      }
    }
    std::unique_lock wait_lock(operation->wait_mutex);
    operation->wait_cv.wait_for(
        wait_lock, std::chrono::milliseconds(5),
        [&] { return operation->stop_source.stop_requested(); });
  }
  cleanup();
}

std::shared_ptr<SessionManager::ConfiguredInviteOperation>
SessionManager::RetireConfiguredInviteOperationLocked() {
  auto operation = configured_invite_operation_;
  if (!operation) return {};
  configured_invite_state_ = ConfiguredInviteLifecycleState::kCancelled;
  ready_configured_invite_.reset();
  return operation;
}

void SessionManager::DrainConfiguredInviteOperation(
    const std::shared_ptr<ConfiguredInviteOperation>& operation) {
  if (!operation) return;
  // An existing guest read lease may finish here. Never wait for that lease
  // while holding the registry/record guards used by runtime replacement.
  if (auto identity = accepted_invites_.Identity(operation->identity.local_user_index);
      identity && identity->operation_token == operation->identity.operation_token)
    accepted_invites_.Invalidate(*identity);
  operation->RequestStop();
  ObserveConfiguredInviteStage(operation, ConfiguredInviteStage::kCancellationVisible);
  // Retire the exact admission before joining: a late HTTP completion may not
  // restore accepted authority after cancellation is visible.
  discovery_.StopClientAdmission(operation->identity.local_user_index);
  operation->WaitUntilPublishedAndJoin();
  std::lock_guard lock(configured_invite_mutex_);
  if (configured_invite_operation_ == operation)
    configured_invite_operation_.reset();
  if (configured_invite_claim_token_ == operation->identity.operation_token)
    configured_invite_claim_token_ = 0;
}

void SessionManager::CancelConfiguredInviteOperation() {
  std::shared_ptr<ConfiguredInviteOperation> operation;
  {
    std::lock_guard lock(configured_invite_mutex_);
    operation = RetireConfiguredInviteOperationLocked();
  }
  DrainConfiguredInviteOperation(operation);
}

std::string SessionManager::runtime_invite_code() const {
  std::optional<std::string> override;
  std::optional<uint64_t> owner;
  {
    std::lock_guard lock(configured_invite_mutex_);
    if (!configured_invite_active_title_id_ || async_shutdown_.load(std::memory_order_acquire))
      return {};
    override = runtime_invite_override_;
    owner = runtime_invite_override_xuid_;
  }
  if (override) {
    const auto user = user_identity_ ? user_identity_(0) : std::nullopt;
    if (user != owner || async_shutdown_.load(std::memory_order_acquire)) return {};
    return *override;
  }
  return NormalizeDirectoryInviteCode(REXCVAR_GET(session_directory_invite_code)).value_or("");
}

RuntimeInviteUpdateResult SessionManager::UpdateRuntimeInviteCode(
    std::string_view code, std::stop_token cancellation) {
  const auto normalized = code.empty() ? std::optional<std::string>(std::string{})
                                      : NormalizeDirectoryInviteCode(code);
  if (!normalized) return RuntimeInviteUpdateResult::kInvalidCode;
  std::unique_lock control_lock(configured_invite_control_mutex_, std::defer_lock);
  while (!control_lock.try_lock_for(std::chrono::milliseconds(10))) {
    if (cancellation.stop_requested()) return RuntimeInviteUpdateResult::kCancelled;
    if (async_shutdown_.load(std::memory_order_acquire))
      return RuntimeInviteUpdateResult::kUnavailable;
  }
  if (cancellation.stop_requested()) return RuntimeInviteUpdateResult::kCancelled;
  if (async_shutdown_.load(std::memory_order_acquire))
    return RuntimeInviteUpdateResult::kUnavailable;
  uint32_t title_id;
  {
    std::lock_guard lock(configured_invite_mutex_);
    title_id = configured_invite_active_title_id_;
  }
  const auto user = user_identity_ ? user_identity_(0) : std::nullopt;
  const auto current_title = current_title_id_ ? current_title_id_() : 0;
  if (!title_id || !user || !*user || (kernel_state_ && current_title != title_id) ||
      (current_title && current_title != title_id))
    return RuntimeInviteUpdateResult::kUnavailable;

  std::shared_ptr<ConfiguredInviteOperation> old_operation;
  {
    std::lock_guard lock(configured_invite_mutex_);
    if (!registry_.WithNoLiveLocalMember([&] {
          old_operation = RetireConfiguredInviteOperationLocked();
        }))
      return RuntimeInviteUpdateResult::kLiveSession;
  }
  // No registry, record, invite or guest-global lock is held while cancelling
  // admission, invoking the stage observer or joining the old worker.
  DrainConfiguredInviteOperation(old_operation);
  if (cancellation.stop_requested()) return RuntimeInviteUpdateResult::kCancelled;
  if (async_shutdown_.load(std::memory_order_acquire))
    return RuntimeInviteUpdateResult::kUnavailable;
  const auto current_user = user_identity_ ? user_identity_(0) : std::nullopt;
  const auto rechecked_title = current_title_id_ ? current_title_id_() : 0;
  if (current_user != user || (kernel_state_ && rechecked_title != title_id) ||
      (rechecked_title && rechecked_title != title_id))
    return RuntimeInviteUpdateResult::kUnavailable;
  bool committed = false;
  {
    std::lock_guard lock(configured_invite_mutex_);
    if (configured_invite_active_title_id_ != title_id)
      return RuntimeInviteUpdateResult::kUnavailable;
    if (!registry_.WithNoLiveLocalMember([&] {
          if (cancellation.stop_requested() || async_shutdown_.load(std::memory_order_acquire))
            return;
          runtime_invite_override_ = *normalized;
          runtime_invite_override_xuid_ = *user;
          ++configured_invite_title_generation_;
          configured_invite_state_ = ConfiguredInviteLifecycleState::kUnclaimed;
          ready_configured_invite_.reset();
          committed = true;
        }))
      return RuntimeInviteUpdateResult::kLiveSession;
  }
  if (!committed)
    return cancellation.stop_requested() ? RuntimeInviteUpdateResult::kCancelled
                                         : RuntimeInviteUpdateResult::kUnavailable;
  if (normalized->empty()) return RuntimeInviteUpdateResult::kCleared;
  return StartConfiguredInviteOperation(title_id) ? RuntimeInviteUpdateResult::kStarted
                                               : RuntimeInviteUpdateResult::kUnavailable;
}

void SessionManager::OnTitleTransition(uint32_t title_id) {
  std::lock_guard control_lock(configured_invite_control_mutex_);
  auto configured_code = NormalizeDirectoryInviteCode(runtime_invite_code());
  auto local_xuid = user_identity_ ? user_identity_(0) : std::nullopt;
  {
    std::lock_guard lock(configured_invite_mutex_);
    // Repeated callbacks describe the same title lifetime even after its invite
    // attempt has ended. Retry only through an explicit runtime-code update or
    // a real title/user/code change; a late duplicate must not issue authority.
    if (configured_invite_operation_ && configured_code && local_xuid &&
        configured_invite_operation_->identity.title_id == title_id &&
        configured_invite_operation_->identity.invite_code ==
            *configured_code &&
        configured_invite_operation_->identity.local_xuid == *local_xuid)
      return;
  }
  CancelConfiguredInviteOperation();
  accepted_invites_.Clear();
  discovery_.StopAllClientAdmissions();
  discovery_.SetTitleId(title_id);
  {
    std::lock_guard lock(configured_invite_mutex_);
    ++configured_invite_title_generation_;
    if (configured_invite_active_title_id_ && configured_invite_active_title_id_ != title_id) {
      runtime_invite_override_.reset();
      runtime_invite_override_xuid_.reset();
    }
    configured_invite_active_title_id_ = title_id;
    configured_invite_state_ = ConfiguredInviteLifecycleState::kUnclaimed;
  }
  StartConfiguredInviteOperation(title_id);
}

void SessionManager::OnTitleTermination() {
  ClearDirectoryListingAttributes();
  RememberSearchListings({});
  std::lock_guard control_lock(configured_invite_control_mutex_);
  CancelConfiguredInviteOperation();
  accepted_invites_.Clear();
  discovery_.StopAllClientAdmissions();
  discovery_.PollClientAdmissions();
  discovery_.SetTitleId(0);
  std::lock_guard lock(configured_invite_mutex_);
  ++configured_invite_title_generation_;
  configured_invite_active_title_id_ = 0;
  runtime_invite_override_.reset();
  runtime_invite_override_xuid_.reset();
  configured_invite_state_ = ConfiguredInviteLifecycleState::kUnclaimed;
  ready_configured_invite_.reset();
}

void SessionManager::ShutdownAsyncActivity() {
  std::unique_lock lock(async_shutdown_mutex_);
  if (async_shutdown_complete_)
    return;
  async_shutdown_.store(true, std::memory_order_release);
  std::lock_guard control_lock(configured_invite_control_mutex_);
  CancelConfiguredInviteOperation();
  accepted_invites_.Close();
  discovery_.StopAllClientAdmissions();
  discovery_.PollClientAdmissions();
  {
    std::lock_guard invite_lock(configured_invite_mutex_);
    configured_invite_active_title_id_ = 0;
    runtime_invite_override_.reset();
    runtime_invite_override_xuid_.reset();
  }
  async_shutdown_complete_ = true;
}

ConfiguredInviteLifecycleState SessionManager::configured_invite_state() const {
  std::lock_guard lock(configured_invite_mutex_);
  return configured_invite_state_;
}

std::optional<ReadyConfiguredInvite>
SessionManager::ready_configured_invite() const {
  std::lock_guard lock(configured_invite_mutex_);
  return ready_configured_invite_;
}
void SessionManager::RememberSearchListings(std::vector<DirectoryListing> listings) {
  std::lock_guard lock(search_listings_mutex_);
  search_listings_ = std::move(listings);
}

bool SessionManager::IsSearchListing(const std::array<uint8_t, 8>& xbox_session_id) const {
  std::lock_guard lock(search_listings_mutex_);
  return std::any_of(search_listings_.begin(), search_listings_.end(), [&](const auto& listing) {
    return listing.xbox_session_id == xbox_session_id;
  });
}

bool SessionManager::JoinSearchListing(const std::array<uint8_t, 8>& xbox_session_id,
                                       std::chrono::milliseconds timeout) {
  std::string code;
  {
    std::lock_guard lock(search_listings_mutex_);
    auto found = std::find_if(search_listings_.begin(), search_listings_.end(),
                              [&](const auto& listing) {
                                return listing.xbox_session_id == xbox_session_id;
                              });
    if (found == search_listings_.end())
      return false;
    code = found->invite_code;
  }
  {
    std::lock_guard lock(configured_invite_mutex_);
    search_join_next_ = true;
  }
  const auto started = UpdateRuntimeInviteCode(code);
  {
    std::lock_guard lock(configured_invite_mutex_);
    search_join_next_ = false;
  }
  if (started != RuntimeInviteUpdateResult::kStarted) {
    REXSYS_WARN("SEARCH_DIAG SEARCH_JOIN_NOT_STARTED result={}", static_cast<int>(started));
    return false;
  }
  REXSYS_INFO("SEARCH_DIAG SEARCH_JOIN_STARTED");
  const auto deadline = std::chrono::steady_clock::now() + timeout;
  while (std::chrono::steady_clock::now() < deadline) {
    const auto state = configured_invite_state();
    if (state == ConfiguredInviteLifecycleState::kPublished) {
      if (registry_.Find(xbox_session_id)) {
        REXSYS_INFO("SEARCH_DIAG SEARCH_JOIN_ADMITTED");
        return true;
      }
      // The host has since replaced that lobby; the listing was stale.
      if (auto ready = ready_configured_invite();
          ready && ready->xbox_session_id != xbox_session_id)
        break;
    }
    if (state == ConfiguredInviteLifecycleState::kFailed ||
        state == ConfiguredInviteLifecycleState::kExpired ||
        state == ConfiguredInviteLifecycleState::kCancelled ||
        state == ConfiguredInviteLifecycleState::kCompleted ||
        async_shutdown_.load(std::memory_order_acquire))
      break;
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
  }
  REXSYS_WARN("SEARCH_DIAG SEARCH_JOIN_FAILED state={}",
              static_cast<uint32_t>(configured_invite_state()));
  // Leave nothing behind that a later search, invite code or hosted lobby
  // would trip over.
  UpdateRuntimeInviteCode("");
  return false;
}
}  // namespace rex::system::xam
