#include <rex/system/xam/session.h>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstring>
#include <random>
#include <thread>
#include <unordered_set>

#include <rex/logging.h>
#include <rex/cvar.h>
#include <rex/system/kernel_state.h>
#include <rex/system/xam/nat_probe.h>

#if REX_PLATFORM_WIN32
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <ws2tcpip.h>
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
constexpr uint16_t kDiscoveryVersion = 1;
constexpr uint8_t kQuery = 1;
constexpr uint8_t kAdvertisement = 2;
constexpr uint8_t kJoin = 3;
constexpr uint8_t kLeave = 4;
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
  if (session.state == SessionState::kDeleted || members.empty() ||
      !ValidMemberAccounting(session.members, session.max_public_slots, session.max_private_slots))
    return false;
  if (source == MemberUpdateSource::kInviteGrant && members.size() != 1)
    return false;
  auto candidate = session.members;
  std::unordered_set<uint64_t> batch_ids;
  for (auto member : members) {
    if (!member.xuid || !batch_ids.insert(member.xuid).second)
      return false;
    auto it = std::find_if(candidate.begin(), candidate.end(),
                           [&](const auto& current) { return current.xuid == member.xuid; });
    if (source != MemberUpdateSource::kTitleAllocatedPool) {
      if (member.xuid == session.host_xuid)
        return false;
      if (it != candidate.end())
        continue;
      member.local = false;
      if (source == MemberUpdateSource::kDiscoveryPublic)
        member.private_slot = false;
    } else if (it != candidate.end() && member.name.empty()) {
      // Preserve a name learned from the companion status channel when the
      // title retries membership with no display-name field.
      member.name = it->name;
    }
    if (it == candidate.end())
      candidate.push_back(std::move(member));
    else
      *it = std::move(member);
  }
  if (!ValidMemberAccounting(candidate, session.max_public_slots, session.max_private_slots))
    return false;
  session.members.swap(candidate);
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
};
#pragma pack(pop)

uint64_t Swap64(uint64_t value) {
  const uint32_t high = htonl(static_cast<uint32_t>(value >> 32));
  const uint32_t low = htonl(static_cast<uint32_t>(value));
  return (uint64_t(low) << 32) | high;
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
bool SetNonBlocking(SOCKET value) {
#if REX_PLATFORM_WIN32
  u_long enabled = 1;
  return ioctlsocket(value, FIONBIO, &enabled) == 0;
#else
  int flags = fcntl(value, F_GETFL, 0);
  return flags >= 0 && fcntl(value, F_SETFL, flags | O_NONBLOCK) == 0;
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
    packet.members[i].flags = htonl((source.local ? 1u : 0u) | (source.private_slot ? 2u : 0u) |
                                    (source.ready ? 4u : 0u));
    std::strncpy(packet.members[i].name, source.name.c_str(), sizeof(packet.members[i].name) - 1);
  }
  return packet;
}
std::optional<SessionRecord> Decode(const DiscoveryPacket& packet, uint32_t title_id,
                                    uint32_t source_ipv4) {
  if (ntohl(packet.magic) != kDiscoveryMagic || ntohs(packet.version) != kDiscoveryVersion ||
      packet.type != kAdvertisement || ntohl(packet.title_id) != title_id)
    return std::nullopt;
  SessionRecord session;
  std::memcpy(session.info.id.data(), packet.session_id, 8);
  std::memcpy(session.info.key.data(), packet.session_key, 16);
  session.host_xuid = Swap64(packet.host_xuid);
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
    if (flags & ~7u)
      return std::nullopt;
    session.members.push_back(
        {Swap64(packet.members[i].xuid),
         std::string(packet.members[i].name,
                     strnlen(packet.members[i].name, sizeof(packet.members[i].name))),
         0, false, (flags & 2) != 0, (flags & 4) != 0});
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
                                      SOCKET retained_socket = kInvalidSocket) {
  if (!EnsureSocketRuntime())
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
  packet.type = type;
  if (member) {
    packet.member_count = htonl(1);
    std::memset(packet.members, 0, sizeof(packet.members));
    packet.members[0].xuid = Swap64(member->xuid);
    packet.members[0].flags = htonl((member->private_slot ? 2u : 0u) | (member->ready ? 4u : 0u));
    std::strncpy(packet.members[0].name, member->name.c_str(), sizeof(packet.members[0].name) - 1);
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
  while (std::chrono::steady_clock::now() < deadline) {
    sockaddr_in source{};
    socket_len_t length = sizeof(source);
    DiscoveryPacket response{};
    int count = recvfrom(socket, reinterpret_cast<char*>(&response), sizeof(response), 0,
                         reinterpret_cast<sockaddr*>(&source), &length);
    if (count > 0 && NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&response), count,
                                     source.sin_addr.s_addr, ntohs(source.sin_port))) {
      NatProbeTick(socket);
      continue;
    }
    if (count == sizeof(response)) {
      result = Decode(response, title_id, source.sin_addr.s_addr);
      if (result) {
        // Preserve the endpoint that successfully reached this session. A
        // direct-connect search may have intentionally replaced the address
        // embedded by a multi-homed host.
        result->info.host_address.ipv4 = session.info.host_address.ipv4;
        result->discovery_address = session.discovery_address;
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
  std::random_device random;
  do {
    for (auto& byte : session->info.id)
      byte = uint8_t(random());
  } while (!IdKey(session->info.id));
  for (auto& byte : session->info.key)
    byte = uint8_t(random());
  session->nonce = (uint64_t(random()) << 32) | random();
  session->host_xuid = host_xuid;
  session->host_name = std::move(host_name);
  session->info.host_address = host_address;
  for (size_t i = 0; i < session->info.ethernet_address.size(); ++i)
    session->info.ethernet_address[i] = uint8_t(host_xuid >> (i * 8));
  std::memcpy(session->info.online_address.data(), &host_xuid, sizeof(host_xuid));
  session->flags = flags;
  session->max_public_slots = public_slots;
  session->max_private_slots = private_slots;
  session->members.push_back({host_xuid, session->host_name, 0, true, false, false});
  std::lock_guard lock(mutex_);
  auto id_key = IdKey(session->info.id);
  local_session_ids_.insert(id_key);
  sessions_[id_key] = session;
  return session;
}
bool SessionRegistry::Delete(const std::array<uint8_t, 8>& id) {
  std::lock_guard lock(mutex_);
  auto it = sessions_.find(IdKey(id));
  if (it == sessions_.end())
    return false;
  std::lock_guard session_lock(*it->second->mutex);
  it->second->state = SessionState::kDeleted;
  it->second->NotifyStatus();
  sessions_.erase(it);
  return true;
}
size_t SessionRegistry::DeleteHostedBy(uint64_t host_xuid) {
  std::lock_guard lock(mutex_);
  size_t removed = 0;
  for (auto it = sessions_.begin(); it != sessions_.end();) {
    std::lock_guard session_lock(*it->second->mutex);
    if (it->second->host_xuid == host_xuid) {
      it->second->state = SessionState::kDeleted;
      it->second->NotifyStatus();
      it = sessions_.erase(it);
      ++removed;
    } else {
      ++it;
    }
  }
  return removed;
}
size_t SessionRegistry::UpdateHostedPort(uint64_t host_xuid, uint16_t port) {
  std::lock_guard lock(mutex_);
  size_t updated = 0;
  for (auto& [_, session] : sessions_) {
    std::lock_guard session_lock(*session->mutex);
    if (session->host_xuid == host_xuid && session->state != SessionState::kDeleted) {
      session->info.host_address.port = port;
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
  size_t before = session->members.size();
  std::erase_if(session->members, [&](const auto& m) { return m.xuid == xuid; });
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
  auto session = std::make_shared<SessionRecord>(std::move(record));
  std::lock_guard lock(mutex_);
  auto id_key = IdKey(session->info.id);
  if (local_session_ids_.contains(id_key))
    return nullptr;
  sessions_[id_key] = std::move(session);
  return sessions_[id_key];
}

class LanDiscoveryService::Impl {
 public:
  Impl(uint32_t title_id, uint16_t port, std::shared_ptr<HostAdmissionGrantStore> admission_grants)
      : title_id(title_id), port(port), admission_grants(std::move(admission_grants)) {}
  ~Impl() { Stop(); }
  bool Start(std::shared_ptr<SessionRecord> value) {
    Stop();
    if (!EnsureSocketRuntime())
      return false;
    advertised = std::move(value);
    socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socket == kInvalidSocket)
      return false;
    int yes = 1;
    setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<const char*>(&yes), sizeof(yes));
    // Limited-broadcast reception requires a wildcard listener on Windows.
    // Outgoing search/join sockets and all advertised/gameplay addresses are
    // still bound to the explicitly selected physical interface.
    sockaddr_in listen_address{};
    listen_address.sin_family = AF_INET;
    listen_address.sin_addr.s_addr = htonl(INADDR_ANY);
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
        int count = recvfrom(client_socket, reinterpret_cast<char*>(packet.data()),
                             int(packet.size()), 0, reinterpret_cast<sockaddr*>(&source), &length);
        if (count > 0)
          NatProbeConsume(client_socket, packet.data(), count, source.sin_addr.s_addr,
                          ntohs(source.sin_port));
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
  }
  void Run() {
    while (running) {
      NatProbeTick(socket);
      sockaddr_in source{};
      socket_len_t length = sizeof(source);
      DiscoveryPacket query{};
      int count = recvfrom(socket, reinterpret_cast<char*>(&query), sizeof(query), 0,
                           reinterpret_cast<sockaddr*>(&source), &length);
      if (count > 0 && NatProbeConsume(socket, reinterpret_cast<const uint8_t*>(&query), count,
                                       source.sin_addr.s_addr, ntohs(source.sin_port))) {
        continue;
      }
      bool valid = count == sizeof(query) && ntohl(query.magic) == kDiscoveryMagic &&
                   ntohs(query.version) == kDiscoveryVersion && ntohl(query.title_id) == title_id &&
                   advertised;
      if (valid && query.type == kQuery) {
        REXSYS_INFO("LAN discovery: received search query from {:08X}:{}", source.sin_addr.s_addr,
                    ntohs(source.sin_port));
      }
      if (valid && (query.type == kJoin || query.type == kLeave)) {
        const auto& wire = query.members[0];
        const uint32_t flags = ntohl(wire.flags);
        const uint64_t xuid = Swap64(wire.xuid);
        bool existing = false;
        {
          std::lock_guard lock(*advertised->mutex);
          // Routing validation is not an admission credential. The only
          // private authority is a separately reserved host grant below.
          valid = advertised->state != SessionState::kDeleted && ntohl(query.member_count) == 1 &&
                  !query.reserved && !query.reserved2 && !(flags & ~6u) && xuid &&
                  xuid != advertised->host_xuid &&
                  Swap64(query.host_xuid) == advertised->host_xuid &&
                  std::memcmp(query.session_id, advertised->info.id.data(), 8) == 0 &&
                  std::memcmp(query.session_key, advertised->info.key.data(), 16) == 0;
          existing = valid && std::any_of(advertised->members.begin(), advertised->members.end(),
                                          [&](const auto& member) { return member.xuid == xuid; });
        }
        if (valid && query.type == kJoin) {
          SessionMember member{xuid,
                               std::string(wire.name, strnlen(wire.name, sizeof(wire.name))),
                               0,
                               false,
                               (flags & 2) != 0,
                               (flags & 4) != 0};
          HostAdmissionReservation reservation;
          DiscoveryAdmissionContext context;
          if (!existing) {
            // NAT snapshot -> atomic grant reservation -> membership commit ->
            // finalization. No pair of these lock domains is nested.
            auto matches = NatProbeMatchAcknowledgedDiscoveryAttempts(
                socket, {source.sin_addr.s_addr, ntohs(source.sin_port)});
            auto directory_session = admission_grants->hosted_directory_session();
            if (directory_session) {
              auto authority = admission_grants->Reserve(*directory_session, uint64_t(socket),
                                                         source.sin_addr.s_addr,
                                                         ntohs(source.sin_port), matches, xuid);
              if (authority.status == HostAdmissionReservationStatus::kReserved) {
                reservation = std::move(authority.reservation);
                context.source = DiscoveryAdmissionSource::kInviteGrant;
              } else if (authority.status ==
                         HostAdmissionReservationStatus::kDuplicateReservation) {
                // The winning packet owns the one synchronous transaction.
                // This duplicate mutates nothing and may retry after the
                // winner publishes the resulting roster.
                valid = false;
              }
            }
          }
          if (valid)
            valid = ApplyDiscoveryMemberBatch(*advertised,
                                              std::span<const SessionMember>(&member, 1), context);
          if (reservation)
            admission_grants->Finish(reservation, valid);
          if (valid) {
            REXSYS_INFO("LAN discovery: host accepted join xuid={:016X} source={} from {:08X}:{}",
                        xuid,
                        context.source == DiscoveryAdmissionSource::kInviteGrant ? "invite-grant"
                                                                                 : "public",
                        source.sin_addr.s_addr, ntohs(source.sin_port));
          }
        } else if (valid) {
          std::lock_guard lock(*advertised->mutex);
          auto before = advertised->members.size();
          std::erase_if(advertised->members,
                        [&](const auto& value) { return value.xuid == xuid; });
          if (before != advertised->members.size())
            advertised->NotifyStatus();
        }
      }
      if (valid && (query.type == kQuery || query.type == kJoin || query.type == kLeave)) {
        auto response = Encode(*advertised, title_id);
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
    bool automatic_client_admission_driver)
    : admission_grants_(admission_grants ? std::move(admission_grants)
                                         : std::make_shared<HostAdmissionGrantStore>()),
      impl_(std::make_unique<Impl>(title_id, port, admission_grants_)),
      directory_(std::move(user_identity), std::move(client_admission_transport),
                 automatic_client_admission_driver) {}
LanDiscoveryService::~LanDiscoveryService() = default;
void LanDiscoveryService::SetTitleId(uint32_t title_id) {
  directory_.SetClientAdmissionTitle(title_id);
  impl_->title_id = title_id;
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
void LanDiscoveryService::PollClientAdmissions(std::chrono::steady_clock::time_point now) {
  directory_.PollClientAdmissions(now);
}
bool LanDiscoveryService::Advertise(const std::shared_ptr<SessionRecord>& session) {
  if (!impl_->Start(session))
    return false;
  directory_.StartHosting(session, impl_->title_id, impl_->port, admission_grants_);
  return true;
}
void LanDiscoveryService::StopAdvertising() {
  directory_.StopHosting();
  impl_->Stop();
}
bool LanDiscoveryService::IsAdvertising() const {
  return impl_->running;
}
std::vector<SessionRecord> LanDiscoveryService::Search(uint32_t timeout_ms, uint32_t max_results,
                                                       uint32_t local_user_index) {
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
  const auto& invite_code = REXCVAR_GET(session_directory_invite_code);
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
    } else if (REXCVAR_GET(session_directory_invite_code).empty()) {
      // Normal guest searches never wait on HTTPS. A completed cache entry is
      // converted into ordinary discovery probes below; a slow or unavailable
      // directory leaves LAN broadcast unaffected.
      directory_.RequestList(impl_->title_id);
      directory_browse = true;
    }
  }
  if (automatic_public_traversal) {
    size_t issued = 0;
    if (invite_code.empty()) {
      auto sessions = directory_.List(impl_->title_id);
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
    } else if (auto invited =
                   directory_.CreateInviteCodeJoinAttempt(invite_code, impl_->title_id)) {
      REXSYS_INFO("Session directory: invite code resolved '{}'", invited->session.server_name);
      if (!invited->session.connectivity_candidates.empty() &&
          invited->session.connectivity_candidates.front().type == "public" &&
          NatProbeInstallIdentity({invited->attempt.attempt_id, invited->attempt.capability,
                                   invited->attempt.rendezvous_host,
                                   invited->attempt.rendezvous_port, 1})) {
        directory_attempts.push_back(std::move(invited->attempt));
        ++issued;
      }
    } else {
      REXSYS_WARN("Session directory: invite code did not resolve to a compatible lobby");
    }
    directory_browse = false;
    REXSYS_INFO("Session directory: Search generation={} obtained {} traversal attempt(s) mode={}",
                search_attempt, issued, invite_code.empty() ? "public-list" : "invite-code");
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
      int count = recvfrom(socket, reinterpret_cast<char*>(packet.data()), int(packet.size()), 0,
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
    int count = recvfrom(socket, reinterpret_cast<char*>(&response), sizeof(response), 0,
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
    bool admission_owns_socket = false;
    bool discard_invite_socket = false;
    if (!invite_code.empty()) {
      for (const auto& result : results) {
        auto attempt = std::find_if(directory_attempts.begin(), directory_attempts.end(),
                                    [&](const auto& value) {
                                      return value.purpose == "invite_code_private_eligible" &&
                                             result.traversal_session_id == value.session_id &&
                                             result.traversal_attempt_id == value.attempt_id &&
                                             result.traversal_capability == value.capability;
                                    });
        if (attempt != directory_attempts.end()) {
          auto prepared = directory_.PrepareClientAdmission(local_user_index, impl_->title_id,
                                                            *attempt, result, uint64_t(socket));
          if (prepared == ClientAdmissionPrepareResult::kPrepared) {
            admission_owns_socket = true;
          } else if (prepared == ClientAdmissionPrepareResult::kBusy) {
            REXSYS_WARN("Session directory: ready invite lifecycle is busy for user={}",
                        local_user_index);
            discard_invite_socket = true;
          } else {
            REXSYS_WARN("Session directory: exact invite discovery could not arm client admission");
            discard_invite_socket = true;
          }
          break;
        }
      }
    }
    if (discard_invite_socket) {
      for (const auto& attempt : directory_attempts)
        directory_.CompleteJoinAttempt(attempt);
      NatProbeDetach(socket);
      CloseSocket(socket);
      results.clear();
    } else if (!admission_owns_socket) {
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
      REXSYS_INFO(
          "Session directory: transferred exact invite socket={} to admission lifecycle user={}",
          socket, local_user_index);
    }
  } else {
    CloseSocket(socket);
  }
  return results;
}
std::optional<SessionRecord> LanDiscoveryService::Join(const SessionRecord& session,
                                                       const SessionMember& member,
                                                       uint32_t timeout_ms) {
  const auto admission_socket =
      directory_.ClientAdmissionSocketForSession(member.user_index, session);
  if (admission_socket)
    directory_.SetClientAdmissionExchange(member.user_index, true);
  else
    impl_->client_exchange = true;
  auto result = Exchange(session, &member, kJoin, impl_->title_id, impl_->port, timeout_ms,
                         admission_socket ? SOCKET(*admission_socket) : impl_->client_socket);
  if (admission_socket)
    directory_.SetClientAdmissionExchange(member.user_index, false);
  else
    impl_->client_exchange = false;
  return result;
}
std::optional<SessionRecord> LanDiscoveryService::Leave(const SessionRecord& session, uint64_t xuid,
                                                        uint32_t timeout_ms) {
  SessionMember member;
  member.xuid = xuid;
  impl_->client_exchange = true;
  auto result = Exchange(session, &member, kLeave, impl_->title_id, impl_->port, timeout_ms,
                         impl_->client_socket);
  impl_->client_exchange = false;
  return result;
}
std::optional<ReadyAcceptedSessionCandidate> LanDiscoveryService::ReadyAcceptedSession(
    uint32_t local_user_index) {
  return directory_.ReadyClientAdmission(local_user_index);
}
uint32_t LanDiscoveryService::DetermineLanIpv4() {
  const auto& configured = REXCVAR_GET(lan_bind_address);
  if (!configured.empty()) {
    in_addr address{};
    if (inet_pton(AF_INET, configured.c_str(), &address) == 1)
      return address.s_addr;
    REXSYS_ERROR("Invalid configured LAN bind address '{}'", configured);
    return htonl(INADDR_LOOPBACK);
  }
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
    kernel_state()->session_manager()->ReleaseRecord(record_);
    kernel_state()->session_manager()->UnregisterObject(this);
  }
}
bool XSession::Initialize() {
  if (!CreateNative(16))
    return false;
  kernel_state()->session_manager()->RegisterObject(this);
  return true;
}
void XSession::set_record(std::shared_ptr<SessionRecord> record) {
  if (record_ && record_ != record)
    kernel_state()->session_manager()->ReleaseRecord(record_);
  record_ = std::move(record);
  kernel_state()->session_manager()->online_status().Attach(this, record_);
}
SessionManager::SessionManager(KernelState* state, uint16_t discovery_port)
    // KernelState constructs the session service before the executable module
    // is loaded, so the title ID is not available yet. XGI binds the actual
    // title ID immediately before advertising or searching.
    : kernel_state_(state),
      online_status_(state->user_profile()->xuid(), state->user_profile()->name(),
                     REXCVAR_GET(online_status_directory)),
      discovery_(0, discovery_port, {},
                 [state](uint32_t local_user_index) -> std::optional<uint64_t> {
                   auto* profile = state->user_profile();
                   return ResolveRexGlueLocalUserXuid(
                       local_user_index,
                       profile ? std::optional<uint64_t>(profile->xuid()) : std::nullopt);
                 }) {}
SessionManager::~SessionManager() = default;
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
  auto* profile = kernel_state_->user_profile();
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
}  // namespace rex::system::xam
