#include <rex/system/xam/session.h>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstring>
#include <random>
#include <thread>

#include <rex/logging.h>
#include <rex/cvar.h>
#include <rex/system/kernel_state.h>

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

REXCVAR_DEFINE_STRING(lan_bind_address, "", "Network",
                      "Physical IPv4 address used for LAN discovery and gameplay traffic")
    .validator([](std::string_view value) {
      if (value.empty())
        return true;
      in_addr address{};
      std::string text(value);
      return inet_pton(AF_INET, text.c_str(), &address) == 1 &&
             address.s_addr != htonl(INADDR_ANY) &&
             address.s_addr != htonl(INADDR_BROADCAST);
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
             address.s_addr != htonl(INADDR_ANY) &&
             address.s_addr != htonl(INADDR_BROADCAST);
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
  return (address & 0xFF000000u) == 0x0A000000u ||
         (address & 0xFFF00000u) == 0xAC100000u ||
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
  uint32_t count = std::min<uint32_t>(ntohl(packet.member_count), kMaxWireMembers);
  for (uint32_t i = 0; i < count; ++i) {
    uint32_t flags = ntohl(packet.members[i].flags);
    session.members.push_back(
        {Swap64(packet.members[i].xuid),
         std::string(packet.members[i].name,
                     strnlen(packet.members[i].name, sizeof(packet.members[i].name))),
         0, false, (flags & 2) != 0, (flags & 4) != 0});
  }
  if (session.members.empty())
    session.members.push_back({session.host_xuid, session.host_name, 0, false, false, false});
  return session;
}

std::optional<SessionRecord> Exchange(const SessionRecord& session, const SessionMember* member,
                                      uint8_t type, uint32_t title_id, uint16_t discovery_port,
                                      uint32_t timeout_ms) {
  if (!EnsureSocketRuntime())
    return std::nullopt;
  SOCKET socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (socket == kInvalidSocket)
    return std::nullopt;
  if (!BindLanSocket(socket, 0)) {
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
  target.sin_addr.s_addr = session.info.host_address.ipv4;
  target.sin_port = htons(discovery_port);
  int sent = sendto(socket, reinterpret_cast<const char*>(&packet), sizeof(packet), 0,
                    reinterpret_cast<sockaddr*>(&target), sizeof(target));
  REXSYS_INFO("LAN discovery: {} request bytes={} to {:08X}:{} xuid={:016X}",
              type == kJoin ? "join" : "leave", sent, target.sin_addr.s_addr, discovery_port,
              member ? member->xuid : 0);
  auto deadline = std::chrono::steady_clock::now() + std::chrono::milliseconds(timeout_ms);
  std::optional<SessionRecord> result;
  while (std::chrono::steady_clock::now() < deadline) {
    sockaddr_in source{};
    socket_len_t length = sizeof(source);
    DiscoveryPacket response{};
    int count = recvfrom(socket, reinterpret_cast<char*>(&response), sizeof(response), 0,
                         reinterpret_cast<sockaddr*>(&source), &length);
    if (count == sizeof(response)) {
      result = Decode(response, title_id, source.sin_addr.s_addr);
      if (result) {
        // Preserve the endpoint that successfully reached this session. A
        // direct-connect search may have intentionally replaced the address
        // embedded by a multi-homed host.
        result->info.host_address.ipv4 = session.info.host_address.ipv4;
      }
      if (result && result->info.id == session.info.id) {
        REXSYS_INFO("LAN discovery: {} response from {:08X}:{} members={}",
                    type == kJoin ? "join" : "leave", source.sin_addr.s_addr,
                    ntohs(source.sin_port), result->members.size());
        break;
      }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
  CloseSocket(socket);
  if (!result)
    REXSYS_WARN("LAN discovery: {} request timed out for {:08X}:{}",
                type == kJoin ? "join" : "leave", session.info.host_address.ipv4,
                discovery_port);
  return result;
}
}  // namespace

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
  auto session = Find(id);
  if (!session)
    return false;
  std::lock_guard lock(*session->mutex);
  if (session->state == SessionState::kDeleted)
    return false;
  auto it = std::find_if(session->members.begin(), session->members.end(),
                         [&](const auto& m) { return m.xuid == member.xuid; });
  if (it != session->members.end()) {
    *it = std::move(member);
    return true;
  }
  if (member.private_slot ? !session->OpenPrivateSlots() : !session->OpenPublicSlots())
    return false;
  session->members.push_back(std::move(member));
  return true;
}
bool SessionRegistry::Leave(const std::array<uint8_t, 8>& id, uint64_t xuid) {
  auto session = Find(id);
  if (!session)
    return false;
  std::lock_guard lock(*session->mutex);
  size_t before = session->members.size();
  std::erase_if(session->members, [&](const auto& m) { return m.xuid == xuid; });
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
  return true;
}
bool SessionRegistry::Start(const std::array<uint8_t, 8>& id) {
  auto session = Find(id);
  if (!session)
    return false;
  std::lock_guard lock(*session->mutex);
  session->state = SessionState::kInGame;
  return true;
}
bool SessionRegistry::End(const std::array<uint8_t, 8>& id) {
  auto session = Find(id);
  if (!session)
    return false;
  std::lock_guard lock(*session->mutex);
  session->state = SessionState::kReporting;
  return true;
}
void SessionRegistry::UpsertDiscovered(SessionRecord record) {
  auto session = std::make_shared<SessionRecord>(std::move(record));
  std::lock_guard lock(mutex_);
  auto id_key = IdKey(session->info.id);
  if (local_session_ids_.contains(id_key))
    return;
  sessions_[id_key] = std::move(session);
}

class LanDiscoveryService::Impl {
 public:
  Impl(uint32_t title_id, uint16_t port) : title_id(title_id), port(port) {}
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
    socket = kInvalidSocket;
    advertised.reset();
  }
  void Run() {
    while (running) {
      sockaddr_in source{};
      socket_len_t length = sizeof(source);
      DiscoveryPacket query{};
      int count = recvfrom(socket, reinterpret_cast<char*>(&query), sizeof(query), 0,
                           reinterpret_cast<sockaddr*>(&source), &length);
      bool valid = count == sizeof(query) && ntohl(query.magic) == kDiscoveryMagic &&
                   ntohs(query.version) == kDiscoveryVersion && ntohl(query.title_id) == title_id &&
                   advertised;
      if (valid && query.type == kQuery) {
        REXSYS_INFO("LAN discovery: received search query from {:08X}:{}", source.sin_addr.s_addr,
                    ntohs(source.sin_port));
      }
      if (valid && query.type == kJoin && ntohl(query.member_count)) {
        std::lock_guard lock(*advertised->mutex);
        const auto& wire = query.members[0];
        uint32_t flags = ntohl(wire.flags);
        SessionMember member{Swap64(wire.xuid),
                             std::string(wire.name, strnlen(wire.name, sizeof(wire.name))),
                             0,
                             false,
                             (flags & 2) != 0,
                             (flags & 4) != 0};
        auto it = std::find_if(advertised->members.begin(), advertised->members.end(),
                               [&](const auto& value) { return value.xuid == member.xuid; });
        if (it == advertised->members.end()) {
          REXSYS_INFO("LAN discovery: host accepted join xuid={:016X} name='{}' from {:08X}:{}",
                      member.xuid, member.name, source.sin_addr.s_addr, ntohs(source.sin_port));
          advertised->members.push_back(std::move(member));
        } else {
          REXSYS_INFO("LAN discovery: host reused member xuid={:016X} from {:08X}:{}", member.xuid,
                      source.sin_addr.s_addr, ntohs(source.sin_port));
        }
      } else if (valid && query.type == kLeave && ntohl(query.member_count)) {
        std::lock_guard lock(*advertised->mutex);
        uint64_t xuid = Swap64(query.members[0].xuid);
        std::erase_if(advertised->members, [&](const auto& value) { return value.xuid == xuid; });
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
                      source.sin_addr.s_addr, ntohs(source.sin_port),
                      ntohl(response.member_count));
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
};

LanDiscoveryService::LanDiscoveryService(uint32_t title_id, uint16_t port)
    : impl_(std::make_unique<Impl>(title_id, port)) {}
LanDiscoveryService::~LanDiscoveryService() = default;
void LanDiscoveryService::SetTitleId(uint32_t title_id) {
  impl_->title_id = title_id;
}
bool LanDiscoveryService::Advertise(const std::shared_ptr<SessionRecord>& session) {
  if (!impl_->Start(session))
    return false;
  directory_.StartHosting(session, impl_->title_id, impl_->port);
  return true;
}
void LanDiscoveryService::StopAdvertising() {
  directory_.StopHosting();
  impl_->Stop();
}
bool LanDiscoveryService::IsAdvertising() const {
  return impl_->running;
}
std::vector<SessionRecord> LanDiscoveryService::Search(uint32_t timeout_ms, uint32_t max_results) {
  std::vector<SessionRecord> results;
  if (!EnsureSocketRuntime())
    return results;
  SOCKET socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (socket == kInvalidSocket)
    return results;
  std::string selected_address = REXCVAR_GET(direct_connect_address);
  uint16_t selected_discovery_port = impl_->port;
  uint16_t selected_gameplay_port = 0;
  bool directory_selected = false;
  if (selected_address.empty() && !REXCVAR_GET(session_directory_url).empty()) {
    auto sessions = directory_.List(impl_->title_id);
    for (size_t i = 0; i < sessions.size(); ++i) {
      const auto& candidate = sessions[i].connectivity_candidates.front();
      REXSYS_INFO("Session directory: [{}] '{}' players={}/{} candidate={} {}:{}", i,
                  sessions[i].server_name, sessions[i].player_count, sessions[i].max_players,
                  candidate.type, candidate.address, candidate.discovery_port);
    }
    uint32_t index = REXCVAR_GET(session_directory_session_index);
    if (index != 0xFFFFFFFFu) {
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
    }
  }
  const bool direct = !selected_address.empty();
  if (direct) {
    if (!BindLanSocket(socket, 0)) {
      REXSYS_ERROR("Direct connect: failed to bind search socket to configured interface");
      CloseSocket(socket);
      return results;
    }
  } else {
    int yes = 1;
    setsockopt(socket, SOL_SOCKET, SO_BROADCAST, reinterpret_cast<const char*>(&yes), sizeof(yes));
  }
  // Keep limited-broadcast search wildcard-bound. Windows doesn't loop back a
  // 255.255.255.255 datagram from a socket bound to a unicast address, and the
  // listener has the same requirement. Advertisements, XNADDR, join exchange,
  // and gameplay transport still use the explicit selected address.
  SetNonBlocking(socket);
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
  DiscoveryPacket query{};
  query.magic = htonl(kDiscoveryMagic);
  query.version = htons(kDiscoveryVersion);
  query.type = kQuery;
  query.title_id = htonl(impl_->title_id);
  int query_sent = sendto(socket, reinterpret_cast<const char*>(&query), sizeof(query), 0,
                          reinterpret_cast<sockaddr*>(&target), sizeof(target));
  if (direct) {
    REXSYS_INFO("Direct connect: search query bytes={} to {:08X}:{} title={:08X}", query_sent,
                target.sin_addr.s_addr, selected_discovery_port, impl_->title_id);
  } else {
    REXSYS_INFO("LAN discovery: search broadcast bytes={} UDP {} title={:08X}", query_sent,
                impl_->port, impl_->title_id);
  }
  // Also probe the local listener for deterministic same-host tests/tools.
  // Stable XUID/session-ID filtering prevents this from surfacing as a remote
  // result in the title.
  if (!direct) {
    target.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    sendto(socket, reinterpret_cast<const char*>(&query), sizeof(query), 0,
           reinterpret_cast<sockaddr*>(&target), sizeof(target));
  }
  auto deadline = std::chrono::steady_clock::now() + std::chrono::milliseconds(timeout_ms);
  while (std::chrono::steady_clock::now() < deadline && results.size() < max_results) {
    sockaddr_in source{};
    socket_len_t length = sizeof(source);
    DiscoveryPacket response{};
    int count = recvfrom(socket, reinterpret_cast<char*>(&response), sizeof(response), 0,
                         reinterpret_cast<sockaddr*>(&source), &length);
    if (count == sizeof(response)) {
      auto decoded = Decode(response, impl_->title_id, source.sin_addr.s_addr);
      if (decoded && direct) {
        // The manually supplied endpoint is authoritative. This preserves the
        // complete host-provided session identity while avoiding a private or
        // otherwise unreachable address embedded by a multi-homed host.
        decoded->info.host_address.ipv4 = target.sin_addr.s_addr;
        if (directory_selected && selected_gameplay_port)
          decoded->info.host_address.port = selected_gameplay_port;
      }
      if (decoded && std::none_of(results.begin(), results.end(), [&](const auto& existing) {
            return existing.info.id == decoded->info.id;
          })) {
        REXSYS_INFO("LAN discovery: found host '{}' xuid={:016X} address={:08X}:{}",
                    decoded->host_name, decoded->host_xuid, decoded->info.host_address.ipv4,
                    decoded->info.host_address.port);
        results.push_back(std::move(*decoded));
      }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
  CloseSocket(socket);
  return results;
}
std::optional<SessionRecord> LanDiscoveryService::Join(const SessionRecord& session,
                                                       const SessionMember& member,
                                                       uint32_t timeout_ms) {
  return Exchange(session, &member, kJoin, impl_->title_id, impl_->port, timeout_ms);
}
std::optional<SessionRecord> LanDiscoveryService::Leave(const SessionRecord& session, uint64_t xuid,
                                                        uint32_t timeout_ms) {
  SessionMember member;
  member.xuid = xuid;
  return Exchange(session, &member, kLeave, impl_->title_id, impl_->port, timeout_ms);
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
}
SessionManager::SessionManager(KernelState* state, uint16_t discovery_port)
    // KernelState constructs the session service before the executable module
    // is loaded, so the title ID is not available yet. XGI binds the actual
    // title ID immediately before advertising or searching.
    : kernel_state_(state), discovery_(0, discovery_port) {}
SessionManager::~SessionManager() = default;
void SessionManager::RegisterObject(XSession* session) {
  std::lock_guard lock(object_mutex_);
  objects_[session->guest_object()] = session;
}
void SessionManager::UnregisterObject(XSession* session) {
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
