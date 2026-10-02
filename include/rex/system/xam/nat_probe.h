#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

#include <rex/system/xam/session.h>

namespace rex::system {
class XSocket;
}

namespace rex::system::xam {

enum class NatProbeRole : uint8_t { kDiscovery = 0, kGameplay = 1 };

struct NatProbeIdentity {
  std::string attempt_id;
  std::string capability;
  std::string server;
  uint16_t port = 30740;
  uint8_t participant = 0;
};

struct NatProbePeerAttempt {
  std::string attempt_id;
  LanAddress peer;
};

constexpr uint32_t NatProbeRegistrationIntervalMs(bool has_peer) {
  return has_peer ? 1000u : 100u;
}

constexpr bool NatProbeAutomaticAttemptActive(uint32_t elapsed_ms, bool acknowledged) {
  return !acknowledged && elapsed_ms < 20000u;
}

class NatProbeEndpointState {
 public:
  bool UpdatePeer(LanAddress peer);
  bool Acknowledge(LanAddress source);
  bool acknowledged() const;
  LanAddress peer() const { return peer_; }
  std::optional<LanAddress> acknowledged_peer() const { return acknowledged_peer_; }
  std::optional<LanAddress> NormalizeAcknowledgedPeer(LanAddress source,
                                                       LanAddress logical) const;

 private:
  LanAddress peer_{};
  std::optional<LanAddress> acknowledged_peer_;
};

bool NatProbeEnabled();
bool NatProbeInstallIdentity(const NatProbeIdentity& identity);
void NatProbeSetLogicalGameplayPeer(std::string_view attempt_id, LanAddress logical);
void NatProbeRetireIdentity(std::string_view attempt_id);
void NatProbeRetireParticipant(uint8_t participant);
bool NatProbeIsClient();
bool NatProbeIsGameplayPort(uint16_t port);
void NatProbeAttach(uint64_t socket, NatProbeRole role, LanAddress local,
                    XSocket* socket_object = nullptr);
void NatProbeDetach(uint64_t socket);
void NatProbeTick(uint64_t socket);
bool NatProbeIsControlPacket(uint64_t socket, const uint8_t* data, size_t size,
                             uint32_t source_ipv4, uint16_t source_port);
bool NatProbeConsume(uint64_t socket, const uint8_t* data, size_t size, uint32_t source_ipv4,
                     uint16_t source_port);
std::optional<LanAddress> NatProbePeer(uint64_t socket, bool require_ack = true);
std::vector<LanAddress> NatProbePeers(uint64_t socket, bool require_ack = true);
std::vector<NatProbePeerAttempt> NatProbePeerAttempts(uint64_t socket,
                                                       bool require_ack = true);
std::optional<LanAddress> NatProbeNormalizeGameplaySource(uint64_t socket,
                                                          LanAddress source);

}  // namespace rex::system::xam
