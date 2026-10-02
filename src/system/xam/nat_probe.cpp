#include <rex/system/xam/nat_probe.h>

#include <algorithm>
#include <array>
#include <cerrno>
#include <chrono>
#include <condition_variable>
#include <cstring>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <rex/cvar.h>
#include <rex/logging.h>
#include <rex/platform.h>
#include <rex/system/xsocket.h>

#if REX_PLATFORM_WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#elif REX_PLATFORM_GNU_LINUX
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#endif

namespace rex::system::xam {

REXCVAR_DEFINE_STRING(nat_probe_server, "", "Network",
                      "IPv4 UDP NAT traversal rendezvous server")
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_UINT32(nat_probe_port, 30740, "Network", "NAT traversal rendezvous UDP port")
    .range(1, 65535)
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_STRING(nat_probe_attempt, "", "Network", "32-hex-character NAT traversal attempt ID")
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_STRING(nat_probe_credential, "", "Network",
                      "32-hex-character NAT traversal credential")
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_UINT32(nat_probe_participant, 0, "Network",
                      "NAT traversal participant: 0 host, 1 client")
    .range(0, 1)
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);

namespace {
constexpr uint8_t kVersion = 1;
constexpr uint8_t kRegister = 1;
constexpr uint8_t kRegistered = 2;
constexpr uint8_t kPunch = 3;
constexpr uint8_t kAck = 4;

#pragma pack(push, 1)
struct Packet {
  char magic[4];
  uint8_t version;
  uint8_t type;
  uint8_t participant;
  uint8_t role;
  uint8_t attempt[16];
  uint8_t credential[16];
  uint32_t observed_ipv4;
  uint16_t observed_port;
  uint32_t peer_ipv4;
  uint16_t peer_port;
  uint32_t reserved;
};
#pragma pack(pop)
static_assert(sizeof(Packet) == 56);

struct Identity {
  std::array<uint8_t, 16> attempt{};
  std::array<uint8_t, 16> capability{};
  LanAddress server{};
  uint8_t participant = 0;
  bool invite_lan_eligible = false;
  bool automatic = false;
  uint64_t owner_socket = 0;
  bool gameplay_authorized = false;
  std::chrono::steady_clock::time_point expires_at{};
  std::string key;
};

struct AttemptState {
  Identity identity;
  LanAddress observed;
  NatProbeEndpointState endpoint;
  std::optional<LanAddress> invite_lan_peer;
  std::optional<LanAddress> selected_discovery_peer;
  LanAddress logical_gameplay_peer{};
  std::chrono::steady_clock::time_point attached_at{};
  uint8_t stability_checkpoints = 0;
  std::chrono::steady_clock::time_point last_registration{};
  std::chrono::steady_clock::time_point last_punch{};
  // Stops the short rendezvous transmission phase without discarding an
  // already authenticated and acknowledged discovery correlation. Private
  // authority still requires a separately live host admission grant.
  bool rendezvous_expired = false;
  uint32_t registrations_sent = 0;
  bool gameplay_sent_logged = false;
  bool gameplay_received_logged = false;
};

struct State {
  NatProbeRole role;
  LanAddress local;
  std::unordered_map<std::string, AttemptState> attempts;
  bool scheduled_tick_logged = false;
  XSocket* socket_object = nullptr;
  uint32_t active_receive_pumps = 0;
};

std::mutex state_mutex;
std::condition_variable state_cv;
std::unordered_map<uint64_t, State> states;
std::unordered_map<std::string, Identity> automatic_identities;
std::unordered_map<std::string, LanAddress> automatic_logical_gameplay_peers;
std::unordered_set<std::string> expired_discovery_attempts;
std::unordered_set<std::string> expired_gameplay_attempts;
std::mutex gameplay_pump_mutex;
std::condition_variable gameplay_pump_cv;
bool gameplay_pump_running = false;
std::jthread gameplay_pump_thread;

std::unordered_set<std::string>& ExpiredAttempts(NatProbeRole role) {
  return role == NatProbeRole::kDiscovery ? expired_discovery_attempts
                                          : expired_gameplay_attempts;
}

bool ParseHex(std::string_view text, uint8_t* output) {
  if (text.size() != 32)
    return false;
  auto digit = [](char value) -> int {
    if (value >= '0' && value <= '9') return value - '0';
    if (value >= 'a' && value <= 'f') return value - 'a' + 10;
    if (value >= 'A' && value <= 'F') return value - 'A' + 10;
    return -1;
  };
  for (size_t i = 0; i < 16; ++i) {
    int high = digit(text[i * 2]);
    int low = digit(text[i * 2 + 1]);
    if (high < 0 || low < 0)
      return false;
    output[i] = uint8_t((high << 4) | low);
  }
  return true;
}

bool FillIdentity(Packet& packet, const Identity& identity) {
  std::memcpy(packet.magic, "HNAT", 4);
  packet.version = kVersion;
  packet.participant = identity.participant;
  std::memcpy(packet.attempt, identity.attempt.data(), identity.attempt.size());
  std::memcpy(packet.credential, identity.capability.data(), identity.capability.size());
  return true;
}

bool PacketPrefixValid(const Packet& packet) {
  return std::memcmp(packet.magic, "HNAT", 4) == 0 && packet.version == kVersion;
}

void Send(uint64_t socket, Packet packet, LanAddress target) {
  sockaddr_in address{};
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = target.ipv4;
  address.sin_port = htons(target.port);
#if REX_PLATFORM_WIN32
  auto native_socket = static_cast<SOCKET>(socket);
#else
  auto native_socket = static_cast<int>(socket);
#endif
  const auto sent = sendto(native_socket, reinterpret_cast<const char*>(&packet), sizeof(packet), 0,
                           reinterpret_cast<sockaddr*>(&address), sizeof(address));
#if REX_PLATFORM_WIN32
  if (sent == SOCKET_ERROR) {
    const int error = WSAGetLastError();
    REXSYS_WARN("NAT traversal: send failed role={} type={} target={:08X}:{} error={}",
                packet.role, packet.type, target.ipv4, target.port, error);
    return;
  }
#else
  if (sent < 0) {
    const int error = errno;
    REXSYS_WARN("NAT traversal: send failed role={} type={} target={:08X}:{} error={}",
                packet.role, packet.type, target.ipv4, target.port, error);
    return;
  }
#endif
  if (size_t(sent) != sizeof(packet)) {
    REXSYS_WARN(
        "NAT traversal: short send role={} type={} target={:08X}:{} sent={} expected={}",
        packet.role, packet.type, target.ipv4, target.port, sent, sizeof(packet));
  }
}

std::optional<LanAddress> ServerAddress() {
  in_addr address{};
  const auto server = REXCVAR_GET(nat_probe_server);
  if (server.empty() || inet_pton(AF_INET, server.c_str(), &address) != 1)
    return std::nullopt;
  return LanAddress{address.s_addr, uint16_t(REXCVAR_GET(nat_probe_port))};
}

std::optional<Identity> ManualIdentity() {
  auto server = ServerAddress();
  if (!server) return std::nullopt;
  Identity identity{};
  identity.server = *server;
  identity.participant = uint8_t(REXCVAR_GET(nat_probe_participant));
  identity.key = REXCVAR_GET(nat_probe_attempt);
  if (!ParseHex(identity.key, identity.attempt.data()) ||
      !ParseHex(REXCVAR_GET(nat_probe_credential), identity.capability.data()))
    return std::nullopt;
  return identity;
}

std::optional<Identity> ParseIdentity(const NatProbeIdentity& value) {
  in_addr address{};
  Identity identity{};
  identity.key = value.attempt_id;
  identity.participant = value.participant;
  identity.invite_lan_eligible = value.invite_lan_eligible;
  identity.automatic = true;
  identity.server.port = value.port;
  if (value.participant > 1 || !value.port || value.server.empty() ||
      !ParseHex(value.attempt_id, identity.attempt.data()) ||
      !ParseHex(value.capability, identity.capability.data()))
    return std::nullopt;
  if (inet_pton(AF_INET, value.server.c_str(), &address) != 1) {
    addrinfo hints{};
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    addrinfo* resolved = nullptr;
    if (getaddrinfo(value.server.c_str(), nullptr, &hints, &resolved) != 0 || !resolved)
      return std::nullopt;
    address = reinterpret_cast<sockaddr_in*>(resolved->ai_addr)->sin_addr;
    freeaddrinfo(resolved);
  }
  identity.server.ipv4 = address.s_addr;
  return identity;
}

bool GameplayAttemptPendingLocked(const State& state,
                                  std::chrono::steady_clock::time_point now) {
  if (state.role != NatProbeRole::kGameplay) return false;
  for (const auto& [key, attempt] : state.attempts) {
    if (attempt.identity.gameplay_authorized) {
      if (now < attempt.identity.expires_at) return true;  // Membership-scoped mapping keepalive.
      continue;
    }
    const auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
                             now - attempt.attached_at)
                             .count();
    if (attempt.identity.automatic && !attempt.rendezvous_expired &&
        NatProbeAutomaticAttemptActive(uint32_t(std::max<int64_t>(0, elapsed)),
                                       attempt.endpoint.acknowledged()))
      return true;
  }
  return false;
}

bool AnyGameplayAttemptPendingLocked(std::chrono::steady_clock::time_point now) {
  for (const auto& [socket, state] : states)
    if (GameplayAttemptPendingLocked(state, now)) return true;
  return false;
}

void NatProbeTickLocked(uint64_t socket, State& state,
                        std::chrono::steady_clock::time_point now);

void GameplayPumpMain(std::stop_token stop_token) {
  REXSYS_INFO("NAT traversal: gameplay probe pump started");
  while (!stop_token.stop_requested()) {
    {
      std::unique_lock lock(gameplay_pump_mutex);
      gameplay_pump_cv.wait_for(lock, std::chrono::milliseconds(100),
                                [&] { return stop_token.stop_requested(); });
    }
    if (stop_token.stop_requested()) break;

    const auto now = std::chrono::steady_clock::now();
    std::vector<std::pair<uint64_t, XSocket*>> receive_sockets;
    {
      std::lock_guard lock(state_mutex);
      for (auto& [socket, state] : states) {
        if (!GameplayAttemptPendingLocked(state, now)) continue;
        if (!state.scheduled_tick_logged) {
          state.scheduled_tick_logged = true;
          REXSYS_INFO("NAT traversal: first scheduled gameplay probe tick socket={}", socket);
        }
        NatProbeTickLocked(socket, state, now);
        if (state.socket_object) {
          ++state.active_receive_pumps;
          receive_sockets.emplace_back(socket, state.socket_object);
        }
      }
    }

    for (const auto& [socket, socket_object] : receive_sockets) {
      // Drain only a small bounded run of validated NAT-control datagrams. If
      // gameplay is at the queue head PumpNatControl leaves it untouched.
      for (uint32_t count = 0; count < 8 && socket_object->PumpNatControl(); ++count) {}
      {
        std::lock_guard lock(state_mutex);
        auto found = states.find(socket);
        if (found != states.end() && found->second.active_receive_pumps)
          --found->second.active_receive_pumps;
      }
      state_cv.notify_all();
    }

    std::lock_guard pump_lock(gameplay_pump_mutex);
    std::lock_guard state_lock(state_mutex);
    if (!AnyGameplayAttemptPendingLocked(std::chrono::steady_clock::now())) {
      gameplay_pump_running = false;
      REXSYS_INFO("NAT traversal: gameplay probe pump stopped");
      return;
    }
  }
  std::lock_guard lock(gameplay_pump_mutex);
  gameplay_pump_running = false;
}

void EnsureGameplayPump() {
  std::unique_lock lock(gameplay_pump_mutex);
  if (gameplay_pump_running) {
    gameplay_pump_cv.notify_all();
    return;
  }
  if (gameplay_pump_thread.joinable()) {
    lock.unlock();
    gameplay_pump_thread.join();
    lock.lock();
  }
  gameplay_pump_running = true;
  gameplay_pump_thread = std::jthread(GameplayPumpMain);
}
}  // namespace

bool NatProbeEndpointState::UpdatePeer(LanAddress peer) {
  if (!peer.ipv4 || !peer.port || peer_ == peer) return false;
  peer_ = peer;
  acknowledged_peer_.reset();
  return true;
}

bool NatProbeEndpointState::Acknowledge(LanAddress source) {
  if (source != peer_) return false;
  acknowledged_peer_ = source;
  return true;
}

bool NatProbeEndpointState::acknowledged() const {
  return acknowledged_peer_.has_value() && *acknowledged_peer_ == peer_;
}

std::optional<LanAddress> NatProbeEndpointState::NormalizeAcknowledgedPeer(
    LanAddress source, LanAddress logical) const {
  if (!logical.ipv4 || !logical.port || !acknowledged() || source != *acknowledged_peer_)
    return std::nullopt;
  return logical;
}

bool NatProbeEnabled() {
  std::lock_guard lock(state_mutex);
  return ManualIdentity().has_value() || !automatic_identities.empty();
}

bool InstallAutomaticIdentity(const NatProbeIdentity& value,
                              uint64_t owner_socket) {
  auto identity = ParseIdentity(value);
  if (!identity) return false;
  identity->owner_socket = owner_socket;
  bool start_gameplay_pump = false;
  {
    std::lock_guard lock(state_mutex);
    if (auto found = automatic_identities.find(identity->key);
        found != automatic_identities.end())
      return found->second.owner_socket == owner_socket;
    automatic_identities.insert_or_assign(identity->key, *identity);
    for (auto& [socket, state] : states) {
      if (identity->invite_lan_eligible && state.role == NatProbeRole::kGameplay) continue;
      if (owner_socket && socket != owner_socket)
        continue;
      if (ExpiredAttempts(state.role).contains(identity->key))
        continue;
      AttemptState attempt{};
      attempt.identity = *identity;
      if (auto logical = automatic_logical_gameplay_peers.find(identity->key);
          logical != automatic_logical_gameplay_peers.end())
        attempt.logical_gameplay_peer = logical->second;
      attempt.attached_at = std::chrono::steady_clock::now();
      state.attempts.insert_or_assign(identity->key, std::move(attempt));
    }
    REXSYS_INFO(
        "NAT traversal: installed server-issued attempt={} participant={} owner_socket={}",
        identity->key, identity->participant, owner_socket);
    start_gameplay_pump = AnyGameplayAttemptPendingLocked(std::chrono::steady_clock::now());
  }
  if (start_gameplay_pump) EnsureGameplayPump();
  return true;
}

bool NatProbeInstallIdentity(const NatProbeIdentity& value) {
  return InstallAutomaticIdentity(value, 0);
}

bool NatProbeInstallIdentityForSocket(const NatProbeIdentity& value,
                                      uint64_t owner_socket) {
  return owner_socket && InstallAutomaticIdentity(value, owner_socket);
}

bool NatProbeInstallGameplayIdentity(const NatProbeIdentity& value, uint64_t socket,
                                      LanAddress logical,
                                      std::chrono::steady_clock::time_point expires_at) {
  auto identity = ParseIdentity(value);
  if (!identity || !logical.ipv4 || !logical.port || expires_at <= std::chrono::steady_clock::now())
    return false;
  identity->owner_socket = socket;
  identity->gameplay_authorized = true;
  identity->expires_at = expires_at;
  {
    std::lock_guard lock(state_mutex);
    auto found = states.find(socket);
    if (found == states.end() || found->second.role != NatProbeRole::kGameplay) return false;
    auto& attempts = found->second.attempts;
    auto old = attempts.find(identity->key);
    if (old != attempts.end()) {
      if (!old->second.identity.gameplay_authorized ||
          old->second.identity.capability != identity->capability ||
          old->second.identity.participant != identity->participant ||
          old->second.logical_gameplay_peer != logical) return false;
      old->second.identity.expires_at = expires_at;
    } else {
      AttemptState attempt;
      attempt.identity = *identity;
      attempt.logical_gameplay_peer = logical;
      attempt.attached_at = std::chrono::steady_clock::now();
      attempts.emplace(identity->key, std::move(attempt));
      REXSYS_INFO("GAMEPLAY_TRAVERSAL_ATTACHED socket={} link={} participant={} logical={:08X}:{}",
                  socket, identity->key, identity->participant, logical.ipv4, logical.port);
    }
  }
  EnsureGameplayPump();
  return true;
}

bool NatProbeIsPendingGameplaySource(uint64_t socket, LanAddress native) {
  std::lock_guard lock(state_mutex);
  auto found = states.find(socket);
  if (found == states.end() || found->second.role != NatProbeRole::kGameplay) return false;
  return std::any_of(found->second.attempts.begin(), found->second.attempts.end(), [&](const auto& value) {
    const auto& attempt = value.second;
    return attempt.identity.gameplay_authorized && attempt.endpoint.peer() == native &&
        !attempt.endpoint.acknowledged() && std::chrono::steady_clock::now() < attempt.identity.expires_at;
  });
}

void NatProbeRecordGameplayTraffic(uint64_t socket, LanAddress native, size_t bytes, bool sent) {
  if (!bytes) return;
  std::lock_guard lock(state_mutex);
  auto found = states.find(socket);
  if (found == states.end()) return;
  for (auto& [key, attempt] : found->second.attempts) {
    if (!attempt.identity.gameplay_authorized || attempt.endpoint.acknowledged_peer() != native ||
        std::chrono::steady_clock::now() >= attempt.identity.expires_at) continue;
    auto& logged = sent ? attempt.gameplay_sent_logged : attempt.gameplay_received_logged;
    if (!logged) {
      logged = true;
      REXSYS_INFO("GAMEPLAY_FIRST_{} socket={} link={} native={:08X}:{} logical={:08X}:{} bytes={}",
          sent ? "SEND" : "RECEIVE", socket, key, ntohl(native.ipv4), native.port,
          ntohl(attempt.logical_gameplay_peer.ipv4), attempt.logical_gameplay_peer.port, bytes);
    }
  }
}

void NatProbeRemoveGameplayIdentity(uint64_t socket, std::string_view attempt_id) {
  std::lock_guard lock(state_mutex);
  auto found = states.find(socket);
  if (found != states.end()) {
    auto attempt = found->second.attempts.find(std::string(attempt_id));
    if (attempt != found->second.attempts.end() && attempt->second.identity.gameplay_authorized)
      found->second.attempts.erase(attempt);
  }
  gameplay_pump_cv.notify_all();
}

std::optional<LanAddress> NatProbeGameplayDestination(uint64_t socket, LanAddress logical) {
  std::lock_guard lock(state_mutex);
  auto found = states.find(socket);
  if (found == states.end() || found->second.role != NatProbeRole::kGameplay) return std::nullopt;
  std::optional<LanAddress> result;
  for (const auto& [key, attempt] : found->second.attempts) {
    if (!attempt.identity.gameplay_authorized || attempt.identity.expires_at <= std::chrono::steady_clock::now() ||
        attempt.logical_gameplay_peer != logical || !attempt.endpoint.acknowledged()) continue;
    if (result && *result != attempt.endpoint.peer()) return std::nullopt;
    result = attempt.endpoint.peer();
  }
  return result;
}

void NatProbeSetLogicalGameplayPeer(std::string_view attempt_id, LanAddress logical) {
  if (!logical.ipv4 || !logical.port) return;
  std::lock_guard lock(state_mutex);
  const std::string key(attempt_id);
  automatic_logical_gameplay_peers.insert_or_assign(key, logical);
  for (auto& [socket, state] : states) {
    auto attempt = state.attempts.find(key);
    if (attempt != state.attempts.end()) attempt->second.logical_gameplay_peer = logical;
  }
}

void NatProbeRetireIdentity(std::string_view attempt_id) {
  std::lock_guard lock(state_mutex);
  const std::string key(attempt_id);
  automatic_identities.erase(key);
  automatic_logical_gameplay_peers.erase(key);
  expired_discovery_attempts.erase(key);
  expired_gameplay_attempts.erase(key);
  for (auto& [socket, state] : states) state.attempts.erase(key);
  gameplay_pump_cv.notify_all();
}

void NatProbeRetireParticipant(uint8_t participant) {
  std::lock_guard lock(state_mutex);
  std::vector<std::string> retired;
  for (const auto& [key, identity] : automatic_identities)
    if (identity.participant == participant) retired.push_back(key);
  for (const auto& key : retired) automatic_identities.erase(key);
  for (const auto& key : retired) automatic_logical_gameplay_peers.erase(key);
  for (const auto& key : retired) expired_discovery_attempts.erase(key);
  for (const auto& key : retired) expired_gameplay_attempts.erase(key);
  for (auto& [socket, state] : states)
      for (const auto& key : retired) state.attempts.erase(key);
  gameplay_pump_cv.notify_all();
}

bool NatProbeIsClient() {
  std::lock_guard lock(state_mutex);
  if (!automatic_identities.empty()) return automatic_identities.begin()->second.participant == 1;
  return REXCVAR_GET(nat_probe_participant) == 1;
}

bool NatProbeIsGameplayPort(uint16_t port) {
  const uint32_t configured = REXCVAR_GET(lan_gameplay_port);
  return port == (configured ? configured : 30742);
}

void NatProbeAttach(uint64_t socket, NatProbeRole role, LanAddress local,
                    XSocket* socket_object) {
  bool start_gameplay_pump = false;
  {
    std::lock_guard lock(state_mutex);
    State state{};
    state.role = role;
    state.local = local;
    state.socket_object = socket_object;
    auto add = [&](const Identity& identity) {
      AttemptState attempt{};
      attempt.identity = identity;
      if (auto logical = automatic_logical_gameplay_peers.find(identity.key);
          logical != automatic_logical_gameplay_peers.end())
        attempt.logical_gameplay_peer = logical->second;
      attempt.attached_at = std::chrono::steady_clock::now();
      state.attempts.emplace(identity.key, std::move(attempt));
    };
    if (auto manual = ManualIdentity()) add(*manual);
    for (const auto& [key, identity] : automatic_identities)
      if (!(identity.invite_lan_eligible && role == NatProbeRole::kGameplay) &&
          (!identity.owner_socket || identity.owner_socket == socket) &&
          !ExpiredAttempts(role).contains(key))
        add(identity);
    start_gameplay_pump = role == NatProbeRole::kGameplay &&
                          GameplayAttemptPendingLocked(state, std::chrono::steady_clock::now());
    states.insert_or_assign(socket, state);
    REXSYS_INFO("NAT traversal: attached {} socket={} local={:08X}:{} attempts={}",
                role == NatProbeRole::kDiscovery ? "discovery" : "gameplay", socket, local.ipv4,
                local.port, state.attempts.size());
    for (const auto& [key, attempt] : state.attempts) {
      REXSYS_INFO("NAT traversal: socket={} role={} associated attempt={} participant={}", socket,
                  uint8_t(role), key, attempt.identity.participant);
    }
  }
  if (start_gameplay_pump) EnsureGameplayPump();
}

void NatProbeDetach(uint64_t socket) {
  std::unique_lock lock(state_mutex);
  state_cv.wait(lock, [&] {
    auto found = states.find(socket);
    return found == states.end() || found->second.active_receive_pumps == 0;
  });
  states.erase(socket);
  gameplay_pump_cv.notify_all();
}

namespace {
void NatProbeTickLocked(uint64_t socket, State& state,
                        std::chrono::steady_clock::time_point now) {
  constexpr std::array checkpoints{std::chrono::seconds(5), std::chrono::seconds(15),
                                   std::chrono::seconds(30)};
  for (auto iterator = state.attempts.begin(); iterator != state.attempts.end();) {
    auto& attempt = iterator->second;
    if (attempt.rendezvous_expired) {
      ++iterator;
      continue;
    }
    if (attempt.identity.gameplay_authorized && now >= attempt.identity.expires_at) {
      iterator = state.attempts.erase(iterator);
      continue;
    }
    if (attempt.identity.automatic && !attempt.identity.gameplay_authorized &&
        now - attempt.attached_at >= std::chrono::seconds(20)) {
      if (!attempt.endpoint.acknowledged() && !attempt.invite_lan_peer) {
        REXSYS_INFO(
            "NAT traversal: unacknowledged automatic rendezvous attempt retired role={}",
            uint8_t(state.role));
        const auto expired_key = attempt.identity.key;
        ExpiredAttempts(state.role).insert(expired_key);
        for (auto& [other_socket, other_state] : states)
          if (other_socket != socket && other_state.role == state.role)
            other_state.attempts.erase(expired_key);
        iterator = state.attempts.erase(iterator);
        continue;
      }
      attempt.rendezvous_expired = true;
      REXSYS_INFO("NAT traversal: automatic rendezvous transmissions ended role={}",
                  uint8_t(state.role));
      ++iterator;
      continue;
    }
    for (size_t i = 0; i < checkpoints.size(); ++i) {
      const uint8_t bit = uint8_t(1u << i);
      if (attempt.observed.port && !(attempt.stability_checkpoints & bit) &&
          now - attempt.attached_at >= checkpoints[i]) {
        attempt.stability_checkpoints |= bit;
        REXSYS_INFO("NAT traversal: role={} mapping stable at {}s public={:08X}:{}",
                    uint8_t(state.role), checkpoints[i].count(), attempt.observed.ipv4,
                    attempt.observed.port);
      }
    }
    // A host may already have its gameplay socket registered when the joining
    // client's gameplay socket appears. Poll quickly until the rendezvous server
    // supplies that peer so the title's bounded membership exchange is not spent
    // waiting for the normal mapping keepalive interval.
    const auto registration_interval = std::chrono::milliseconds(
        NatProbeRegistrationIntervalMs(attempt.endpoint.peer().port != 0));
    if (now - attempt.last_registration >= registration_interval) {
      Packet packet{};
      FillIdentity(packet, attempt.identity);
      packet.type = kRegister;
      packet.role = uint8_t(state.role);
      Send(socket, packet, attempt.identity.server);
      attempt.last_registration = now;
      ++attempt.registrations_sent;
      REXSYS_INFO(
          "NAT traversal: registration sent socket={} role={} attempt={} participant={} count={}",
          socket, uint8_t(state.role), attempt.identity.key, attempt.identity.participant,
          attempt.registrations_sent);
    }
    const auto peer = attempt.endpoint.peer();
    if (peer.port && !attempt.endpoint.acknowledged() &&
        now - attempt.last_punch >= std::chrono::milliseconds(100)) {
      Packet packet{};
      FillIdentity(packet, attempt.identity);
      packet.type = kPunch;
      packet.role = uint8_t(state.role);
      std::memset(packet.credential, 0, sizeof(packet.credential));
      Send(socket, packet, peer);
      attempt.last_punch = now;
      REXSYS_INFO("NAT traversal: {} punch sent socket={} peer={:08X}:{}",
                  state.role == NatProbeRole::kDiscovery ? "discovery" : "gameplay", socket,
                  peer.ipv4, peer.port);
    }
    ++iterator;
  }
}
}  // namespace

void NatProbeTick(uint64_t socket) {
  NatProbeTickAt(socket, std::chrono::steady_clock::now());
}

void NatProbeTickAt(uint64_t socket, std::chrono::steady_clock::time_point now) {
  std::lock_guard lock(state_mutex);
  auto found = states.find(socket);
  if (found == states.end()) return;
  NatProbeTickLocked(socket, found->second, now);
}

bool NatProbeIsControlPacket(uint64_t socket, const uint8_t* data, size_t size,
                             uint32_t source_ipv4, uint16_t source_port) {
  if (size != sizeof(Packet)) return false;
  Packet packet{};
  std::memcpy(&packet, data, sizeof(packet));
  if (!PacketPrefixValid(packet)) return false;

  std::lock_guard lock(state_mutex);
  auto found = states.find(socket);
  if (found == states.end() || packet.role != uint8_t(found->second.role)) return false;
  auto attempt = std::find_if(found->second.attempts.begin(), found->second.attempts.end(),
                              [&](const auto& value) {
                                return std::memcmp(packet.attempt,
                                                   value.second.identity.attempt.data(), 16) == 0;
                              });
  if (attempt == found->second.attempts.end()) return false;
  const auto& attempt_state = attempt->second;
  if (attempt_state.identity.gameplay_authorized &&
      (std::chrono::steady_clock::now() >= attempt_state.identity.expires_at ||
       (packet.type == kRegistered && LanAddress{source_ipv4, source_port} != attempt_state.identity.server)))
    return false;
  if (packet.type == kRegistered)
    return packet.participant == attempt_state.identity.participant &&
           std::memcmp(packet.credential, attempt_state.identity.capability.data(), 16) == 0;
  if (packet.participant == attempt_state.identity.participant) return false;
  const LanAddress source{source_ipv4, source_port};
  if (packet.type == kPunch)
    return !attempt_state.endpoint.peer().port || attempt_state.endpoint.peer() == source;
  if (packet.type == kAck) return attempt_state.endpoint.peer() == source;
  return false;
}

bool NatProbeConsume(uint64_t socket, const uint8_t* data, size_t size, uint32_t source_ipv4,
                     uint16_t source_port) {
  if (size != sizeof(Packet))
    return false;
  Packet packet{};
  std::memcpy(&packet, data, sizeof(packet));
  if (!PacketPrefixValid(packet))
    return false;
  if (packet.type == kPunch || packet.type == kAck)
    REXSYS_INFO("NAT_DIAG peer control received socket={} source={:08X}:{} type={} role={} participant={}",
                socket, source_ipv4, source_port, packet.type, packet.role,
                packet.participant);
  std::lock_guard lock(state_mutex);
  auto found = states.find(socket);
  if (found == states.end()) {
    REXSYS_WARN("NAT traversal: packet rejected socket={} reason=detached", socket);
    return false;
  }
  if (packet.role != uint8_t(found->second.role)) {
    REXSYS_WARN("NAT traversal: packet rejected socket={} reason=socket_role packet_role={} "
                "socket_role={}", socket, packet.role, uint8_t(found->second.role));
    return false;
  }
  auto& state = found->second;
  auto attempt = std::find_if(state.attempts.begin(), state.attempts.end(), [&](const auto& value) {
    return std::memcmp(packet.attempt, value.second.identity.attempt.data(), 16) == 0;
  });
  if (attempt == state.attempts.end()) {
    REXSYS_WARN("NAT traversal: packet rejected socket={} role={} reason=unknown_attempt",
                socket, uint8_t(state.role));
    return false;
  }
  auto& attempt_state = attempt->second;
  if (attempt_state.identity.gameplay_authorized &&
      (std::chrono::steady_clock::now() >= attempt_state.identity.expires_at ||
       (packet.type == kRegistered && LanAddress{source_ipv4, source_port} != attempt_state.identity.server)))
    return false;
  if (packet.type == kRegistered) {
    if (packet.participant != attempt_state.identity.participant ||
        std::memcmp(packet.credential, attempt_state.identity.capability.data(), 16) != 0)
      {
        REXSYS_WARN(
            "NAT traversal: registration response rejected socket={} role={} attempt={} "
            "reason=identity",
            socket, uint8_t(state.role), attempt_state.identity.key);
        return false;
      }
    LanAddress observed{packet.observed_ipv4, ntohs(packet.observed_port)};
    LanAddress peer{packet.peer_ipv4, ntohs(packet.peer_port)};
    REXSYS_INFO(
        "NAT traversal: registration response socket={} role={} attempt={} participant={} "
        "observed={:08X}:{} peer={:08X}:{}",
        socket, uint8_t(state.role), attempt_state.identity.key,
        attempt_state.identity.participant, observed.ipv4, observed.port, peer.ipv4, peer.port);
    if (attempt_state.observed.port && attempt_state.observed != observed)
      REXSYS_WARN("NAT traversal: mapping changed role={} old={:08X}:{} new={:08X}:{}",
                  uint8_t(state.role), attempt_state.observed.ipv4, attempt_state.observed.port, observed.ipv4,
                  observed.port);
    if (attempt_state.observed != observed) {
      attempt_state.observed = observed;
      REXSYS_INFO("NAT traversal: role={} observed public={:08X}:{}", uint8_t(state.role),
                  observed.ipv4, observed.port);
    }
    const auto old_peer = attempt_state.endpoint.peer();
    if (attempt_state.endpoint.UpdatePeer(peer)) {
      if (old_peer.port) {
        REXSYS_INFO(
            "NAT traversal: role={} peer endpoint changed old={:08X}:{} new={:08X}:{}; "
            "old acknowledgement invalidated",
            uint8_t(state.role), old_peer.ipv4, old_peer.port, peer.ipv4, peer.port);
      } else {
        REXSYS_INFO("NAT traversal: role={} peer endpoint={:08X}:{}", uint8_t(state.role), peer.ipv4,
                    peer.port);
      }
      attempt_state.last_punch = {};
    }
    return true;
  }
  if (packet.participant == attempt_state.identity.participant) {
    REXSYS_WARN("NAT_DIAG peer control rejected socket={} reason=same_participant", socket);
    return false;
  }
  // Peer punch packets prove possession of the unguessable attempt ID and are
  // accepted only from the server-observed endpoint for the opposite participant.
  if (packet.type == kPunch) {
    const LanAddress source{source_ipv4, source_port};
    if (!attempt_state.endpoint.peer().port) {
      if (attempt_state.identity.gameplay_authorized) return true;
      attempt_state.endpoint.UpdatePeer(source);
    }
    if (attempt_state.endpoint.peer() != source) {
      REXSYS_WARN("NAT_DIAG punch rejected socket={} reason=source_mismatch expected={:08X}:{} actual={:08X}:{}",
                  socket, attempt_state.endpoint.peer().ipv4,
                  attempt_state.endpoint.peer().port, source.ipv4, source.port);
      return true;
    }
    Packet response{};
    FillIdentity(response, attempt_state.identity);
    std::memset(response.credential, 0, sizeof(response.credential));
    response.type = kAck;
    response.role = uint8_t(state.role);
    Send(socket, response, source);
    REXSYS_INFO("NAT traversal: role={} punch received and acknowledged from {:08X}:{}",
                uint8_t(state.role), source_ipv4, source_port);
    return true;
  }
  if (packet.type == kAck &&
      attempt_state.endpoint.Acknowledge(LanAddress{source_ipv4, source_port})) {
    REXSYS_INFO("NAT traversal: role={} acknowledgement received from {:08X}:{}",
                uint8_t(state.role), source_ipv4, source_port);
    gameplay_pump_cv.notify_all();
    return true;
  }
  if (packet.type == kAck)
    REXSYS_WARN("NAT_DIAG acknowledgement rejected socket={} reason=source_mismatch expected={:08X}:{} actual={:08X}:{}",
                socket, attempt_state.endpoint.peer().ipv4,
                attempt_state.endpoint.peer().port, source_ipv4, source_port);
  return false;
}

std::optional<LanAddress> NatProbePeer(uint64_t socket, bool require_ack) {
  {
    std::lock_guard lock(state_mutex);
    auto found = states.find(socket);
    if (found != states.end() && found->second.role == NatProbeRole::kDiscovery)
      for (const auto& [_, attempt] : found->second.attempts)
        if (attempt.selected_discovery_peer)
          return attempt.selected_discovery_peer;
  }
  auto peers = NatProbePeers(socket, require_ack);
  return peers.empty() ? std::nullopt : std::optional<LanAddress>(peers.front());
}

std::vector<LanAddress> NatProbePeers(uint64_t socket, bool require_ack) {
  auto attempts = NatProbePeerAttempts(socket, require_ack);
  std::vector<LanAddress> result;
  for (const auto& attempt : attempts)
    if (std::find(result.begin(), result.end(), attempt.peer) == result.end())
      result.push_back(attempt.peer);
  return result;
}

std::vector<NatProbePeerAttempt> NatProbePeerAttempts(uint64_t socket, bool require_ack) {
  std::lock_guard lock(state_mutex);
  std::vector<NatProbePeerAttempt> result;
  auto found = states.find(socket);
  if (found == states.end()) return result;
  for (const auto& [key, attempt] : found->second.attempts) {
    if (attempt.endpoint.peer().port && (!require_ack || attempt.endpoint.acknowledged()))
      result.push_back({key, attempt.endpoint.peer()});
  }
  return result;
}

std::vector<std::string> NatProbeMatchAcknowledgedDiscoveryAttempts(
    uint64_t socket, LanAddress source) {
  std::lock_guard lock(state_mutex);
  std::vector<std::string> result;
  auto found = states.find(socket);
  if (found == states.end() || found->second.role != NatProbeRole::kDiscovery)
    return result;
  for (const auto& [key, attempt] : found->second.attempts) {
    if (attempt.selected_discovery_peer && *attempt.selected_discovery_peer != source)
      continue;
    if ((attempt.endpoint.acknowledged_peer() == source &&
         attempt.endpoint.peer() == source) ||
        attempt.invite_lan_peer == source)
      result.push_back(key);
  }
  return result;
}

std::vector<NatProbePeerAttempt> NatProbeAcknowledgedDiscoveryAttempts() {
  std::lock_guard lock(state_mutex);
  std::vector<NatProbePeerAttempt> result;
  for (const auto& [_, state] : states) {
    if (state.role != NatProbeRole::kDiscovery)
      continue;
    for (const auto& [key, attempt] : state.attempts) {
      // A host-authenticated invite LAN exchange is also evidence that this
      // discovery attempt reached the host. The server still validates the
      // host's registration token and the exact admission generation/revision.
      if (attempt.endpoint.acknowledged())
        result.push_back({key, attempt.endpoint.peer()});
      else if (attempt.identity.automatic && attempt.identity.participant == 0 &&
               attempt.identity.invite_lan_eligible && attempt.invite_lan_peer)
        result.push_back({key, *attempt.invite_lan_peer});
    }
  }
  return result;
}

bool NatProbeRendezvousAttemptActive(uint64_t socket,
                                     std::string_view attempt_id) {
  std::lock_guard lock(state_mutex);
  auto found = states.find(socket);
  if (found == states.end()) return false;
  auto attempt = found->second.attempts.find(std::string(attempt_id));
  return attempt != found->second.attempts.end() &&
         !attempt->second.rendezvous_expired;
}

std::vector<std::string> NatProbeHostedInviteAttempts(uint64_t socket) {
  std::lock_guard lock(state_mutex);
  std::vector<std::string> result;
  auto found = states.find(socket);
  if (found == states.end() || found->second.role != NatProbeRole::kDiscovery)
    return result;
  for (const auto& [key, attempt] : found->second.attempts)
    if (attempt.identity.automatic && attempt.identity.invite_lan_eligible &&
        attempt.identity.participant == 0 && !attempt.rendezvous_expired)
      result.push_back(key);
  return result;
}

bool NatProbeRegisterInviteLanPeer(uint64_t socket, std::string_view attempt_id,
                                   LanAddress peer) {
  if (!peer.ipv4 || !peer.port)
    return false;
  std::lock_guard lock(state_mutex);
  auto found = states.find(socket);
  if (found == states.end() || found->second.role != NatProbeRole::kDiscovery)
    return false;
  auto attempt = found->second.attempts.find(std::string(attempt_id));
  if (attempt == found->second.attempts.end() ||
      !attempt->second.identity.invite_lan_eligible ||
      attempt->second.rendezvous_expired ||
      (attempt->second.invite_lan_peer && attempt->second.invite_lan_peer != peer))
    return false;
  attempt->second.invite_lan_peer = peer;
  return true;
}

bool NatProbeSelectInviteDiscoveryPeer(uint64_t socket, std::string_view attempt_id,
                                       LanAddress peer) {
  std::lock_guard lock(state_mutex);
  auto found = states.find(socket);
  if (found == states.end() || found->second.role != NatProbeRole::kDiscovery)
    return false;
  auto attempt = found->second.attempts.find(std::string(attempt_id));
  if (attempt == found->second.attempts.end() ||
      !attempt->second.identity.invite_lan_eligible ||
      (attempt->second.selected_discovery_peer &&
       attempt->second.selected_discovery_peer != peer))
    return false;
  if (attempt->second.invite_lan_peer != peer &&
      !(attempt->second.endpoint.acknowledged() && attempt->second.endpoint.peer() == peer))
    return false;
  attempt->second.selected_discovery_peer = peer;
  return true;
}

std::optional<LanAddress> NatProbeNormalizeGameplaySource(uint64_t socket,
                                                          LanAddress source) {
  std::lock_guard lock(state_mutex);
  auto found = states.find(socket);
  if (found == states.end() || found->second.role != NatProbeRole::kGameplay)
    return std::nullopt;
  for (const auto& [key, attempt] : found->second.attempts) {
    if (attempt.identity.gameplay_authorized &&
        std::chrono::steady_clock::now() >= attempt.identity.expires_at) continue;
    if (auto logical =
            attempt.endpoint.NormalizeAcknowledgedPeer(source, attempt.logical_gameplay_peer))
      return logical;
  }
  return std::nullopt;
}

}  // namespace rex::system::xam
