#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>

#include <rex/system/xam/session.h>

namespace rex::system::xam {

enum class NatProbeRole : uint8_t { kDiscovery = 0, kGameplay = 1 };

class NatProbeEndpointState {
 public:
  bool UpdatePeer(LanAddress peer);
  bool Acknowledge(LanAddress source);
  bool acknowledged() const;
  LanAddress peer() const { return peer_; }
  std::optional<LanAddress> acknowledged_peer() const { return acknowledged_peer_; }

 private:
  LanAddress peer_{};
  std::optional<LanAddress> acknowledged_peer_;
};

bool NatProbeEnabled();
bool NatProbeIsClient();
bool NatProbeIsGameplayPort(uint16_t port);
void NatProbeAttach(uint64_t socket, NatProbeRole role, LanAddress local);
void NatProbeDetach(uint64_t socket);
void NatProbeTick(uint64_t socket);
bool NatProbeConsume(uint64_t socket, const uint8_t* data, size_t size, uint32_t source_ipv4,
                     uint16_t source_port);
std::optional<LanAddress> NatProbePeer(uint64_t socket, bool require_ack = true);

}  // namespace rex::system::xam
