#include <rex/system/xam/nat_probe.h>

#include <array>
#include <chrono>
#include <cstring>
#include <mutex>
#include <string>
#include <unordered_map>

#include <rex/cvar.h>
#include <rex/logging.h>
#include <rex/platform.h>

#if REX_PLATFORM_WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
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

struct State {
  NatProbeRole role;
  LanAddress local;
  LanAddress observed;
  NatProbeEndpointState endpoint;
  std::chrono::steady_clock::time_point attached_at{};
  uint8_t stability_checkpoints = 0;
  std::chrono::steady_clock::time_point last_registration{};
  std::chrono::steady_clock::time_point last_punch{};
};

std::mutex state_mutex;
std::unordered_map<uint64_t, State> states;

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

bool FillIdentity(Packet& packet) {
  std::memcpy(packet.magic, "HNAT", 4);
  packet.version = kVersion;
  packet.participant = uint8_t(REXCVAR_GET(nat_probe_participant));
  return ParseHex(REXCVAR_GET(nat_probe_attempt), packet.attempt) &&
         ParseHex(REXCVAR_GET(nat_probe_credential), packet.credential);
}

bool ValidIdentity(const Packet& packet) {
  Packet expected{};
  if (!FillIdentity(expected))
    return false;
  return std::memcmp(packet.magic, expected.magic, 4) == 0 && packet.version == kVersion &&
         std::memcmp(packet.attempt, expected.attempt, 16) == 0 &&
         std::memcmp(packet.credential, expected.credential, 16) == 0;
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
  sendto(native_socket, reinterpret_cast<const char*>(&packet), sizeof(packet), 0,
         reinterpret_cast<sockaddr*>(&address), sizeof(address));
}

std::optional<LanAddress> ServerAddress() {
  in_addr address{};
  const auto server = REXCVAR_GET(nat_probe_server);
  if (server.empty() || inet_pton(AF_INET, server.c_str(), &address) != 1)
    return std::nullopt;
  return LanAddress{address.s_addr, uint16_t(REXCVAR_GET(nat_probe_port))};
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

bool NatProbeEnabled() {
  Packet packet{};
  return ServerAddress().has_value() && FillIdentity(packet);
}

bool NatProbeIsClient() { return REXCVAR_GET(nat_probe_participant) == 1; }

bool NatProbeIsGameplayPort(uint16_t port) {
  const uint32_t configured = REXCVAR_GET(lan_gameplay_port);
  return port == (configured ? configured : 30742);
}

void NatProbeAttach(uint64_t socket, NatProbeRole role, LanAddress local) {
  if (!NatProbeEnabled())
    return;
  std::lock_guard lock(state_mutex);
  State state{};
  state.role = role;
  state.local = local;
  state.attached_at = std::chrono::steady_clock::now();
  states.insert_or_assign(socket, state);
  REXSYS_INFO("NAT traversal: attached {} socket={} local={:08X}:{}",
              role == NatProbeRole::kDiscovery ? "discovery" : "gameplay", socket, local.ipv4,
              local.port);
}

void NatProbeDetach(uint64_t socket) {
  std::lock_guard lock(state_mutex);
  states.erase(socket);
}

void NatProbeTick(uint64_t socket) {
  auto server = ServerAddress();
  if (!server)
    return;
  std::lock_guard lock(state_mutex);
  auto found = states.find(socket);
  if (found == states.end())
    return;
  auto& state = found->second;
  auto now = std::chrono::steady_clock::now();
  constexpr std::array checkpoints{std::chrono::seconds(5), std::chrono::seconds(15),
                                   std::chrono::seconds(30)};
  for (size_t i = 0; i < checkpoints.size(); ++i) {
    const uint8_t bit = uint8_t(1u << i);
    if (state.observed.port && !(state.stability_checkpoints & bit) &&
        now - state.attached_at >= checkpoints[i]) {
      state.stability_checkpoints |= bit;
      REXSYS_INFO("NAT traversal: role={} mapping stable at {}s public={:08X}:{}",
                  uint8_t(state.role), checkpoints[i].count(), state.observed.ipv4,
                  state.observed.port);
    }
  }
  if (now - state.last_registration >= std::chrono::seconds(1)) {
    Packet packet{};
    FillIdentity(packet);
    packet.type = kRegister;
    packet.role = uint8_t(state.role);
    Send(socket, packet, *server);
    state.last_registration = now;
  }
  const auto peer = state.endpoint.peer();
  if (peer.port && !state.endpoint.acknowledged() &&
      now - state.last_punch >= std::chrono::milliseconds(100)) {
    Packet packet{};
    FillIdentity(packet);
    packet.type = kPunch;
    packet.role = uint8_t(state.role);
    Send(socket, packet, peer);
    state.last_punch = now;
    REXSYS_INFO("NAT traversal: {} punch sent socket={} peer={:08X}:{}",
                state.role == NatProbeRole::kDiscovery ? "discovery" : "gameplay", socket,
                peer.ipv4, peer.port);
  }
}

bool NatProbeConsume(uint64_t socket, const uint8_t* data, size_t size, uint32_t source_ipv4,
                     uint16_t source_port) {
  if (size != sizeof(Packet))
    return false;
  Packet packet{};
  std::memcpy(&packet, data, sizeof(packet));
  if (!ValidIdentity(packet))
    return false;
  std::lock_guard lock(state_mutex);
  auto found = states.find(socket);
  if (found == states.end() || packet.role != uint8_t(found->second.role))
    return false;
  auto& state = found->second;
  if (packet.type == kRegistered && packet.participant == REXCVAR_GET(nat_probe_participant)) {
    LanAddress observed{packet.observed_ipv4, ntohs(packet.observed_port)};
    LanAddress peer{packet.peer_ipv4, ntohs(packet.peer_port)};
    if (state.observed.port && state.observed != observed)
      REXSYS_WARN("NAT traversal: mapping changed role={} old={:08X}:{} new={:08X}:{}",
                  uint8_t(state.role), state.observed.ipv4, state.observed.port, observed.ipv4,
                  observed.port);
    if (state.observed != observed) {
      state.observed = observed;
      REXSYS_INFO("NAT traversal: role={} observed public={:08X}:{}", uint8_t(state.role),
                  observed.ipv4, observed.port);
    }
    const auto old_peer = state.endpoint.peer();
    if (state.endpoint.UpdatePeer(peer)) {
      if (old_peer.port) {
        REXSYS_INFO(
            "NAT traversal: role={} peer endpoint changed old={:08X}:{} new={:08X}:{}; "
            "old acknowledgement invalidated",
            uint8_t(state.role), old_peer.ipv4, old_peer.port, peer.ipv4, peer.port);
      } else {
        REXSYS_INFO("NAT traversal: role={} peer endpoint={:08X}:{}", uint8_t(state.role), peer.ipv4,
                    peer.port);
      }
      state.last_punch = {};
    }
    return true;
  }
  if (packet.participant == REXCVAR_GET(nat_probe_participant))
    return false;
  if (packet.type == kPunch) {
    const LanAddress source{source_ipv4, source_port};
    if (!state.endpoint.peer().port) state.endpoint.UpdatePeer(source);
    if (state.endpoint.peer() != source) return true;
    Packet response{};
    FillIdentity(response);
    response.type = kAck;
    response.role = uint8_t(state.role);
    Send(socket, response, source);
    REXSYS_INFO("NAT traversal: role={} punch received and acknowledged from {:08X}:{}",
                uint8_t(state.role), source_ipv4, source_port);
    return true;
  }
  if (packet.type == kAck &&
      state.endpoint.Acknowledge(LanAddress{source_ipv4, source_port})) {
    REXSYS_INFO("NAT traversal: role={} acknowledgement received from {:08X}:{}",
                uint8_t(state.role), source_ipv4, source_port);
    return true;
  }
  return false;
}

std::optional<LanAddress> NatProbePeer(uint64_t socket, bool require_ack) {
  std::lock_guard lock(state_mutex);
  auto found = states.find(socket);
  if (found == states.end() || !found->second.endpoint.peer().port ||
      (require_ack && !found->second.endpoint.acknowledged()))
    return std::nullopt;
  return found->second.endpoint.peer();
}

}  // namespace rex::system::xam
