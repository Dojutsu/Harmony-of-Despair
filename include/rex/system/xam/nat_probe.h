#pragma once

#include <cstddef>
#include <chrono>
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
  bool invite_lan_eligible = false;
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
// Installs one operation-owned identity on exactly one socket. Other discovery
// and gameplay sockets cannot observe or consume it.
bool NatProbeInstallIdentityForSocket(const NatProbeIdentity& identity,
                                      uint64_t owner_socket);
// Gameplay tickets are installed on one already-attached gameplay socket only.
// They never enter the automatic discovery identity collection.
bool NatProbeInstallGameplayIdentity(const NatProbeIdentity& identity, uint64_t socket,
                                      LanAddress logical,
                                      std::chrono::steady_clock::time_point expires_at);
// Local platform authority installs one exact private endpoint from a verified
// per-member ticket. Direct routes do not contact rendezvous or consume raw
// HNAT controls, and retain the ordinary encrypted gameplay scope lifetime.
bool NatProbeInstallAuthenticatedLanPeer(const NatProbeIdentity& identity, uint64_t socket,
    LanAddress logical, LanAddress native, std::chrono::steady_clock::time_point expires_at);
void NatProbeRemoveGameplayIdentity(uint64_t socket, std::string_view attempt_id);
std::optional<LanAddress> NatProbeGameplayDestination(uint64_t socket, LanAddress logical);
bool NatProbeIsPendingGameplaySource(uint64_t socket, LanAddress native);
void NatProbeRecordGameplayTraffic(uint64_t socket, LanAddress native, size_t bytes, bool sent);
void NatProbeSetLogicalGameplayPeer(std::string_view attempt_id, LanAddress logical);
void NatProbeRetireIdentity(std::string_view attempt_id);
void NatProbeRetireParticipant(uint8_t participant);
bool NatProbeIsClient();
bool NatProbeIsGameplayPort(uint16_t port);
void NatProbeAttach(uint64_t socket, NatProbeRole role, LanAddress local,
                    XSocket* socket_object = nullptr);
void NatProbeDetach(uint64_t socket);
void NatProbeTick(uint64_t socket);
void NatProbeTickAt(uint64_t socket, std::chrono::steady_clock::time_point now);
bool NatProbeIsControlPacket(uint64_t socket, const uint8_t* data, size_t size,
                             uint32_t source_ipv4, uint16_t source_port);
bool NatProbeConsume(uint64_t socket, const uint8_t* data, size_t size, uint32_t source_ipv4,
                     uint16_t source_port);
std::optional<LanAddress> NatProbePeer(uint64_t socket, bool require_ack = true);
std::vector<LanAddress> NatProbePeers(uint64_t socket, bool require_ack = true);
std::vector<NatProbePeerAttempt> NatProbePeerAttempts(uint64_t socket,
                                                       bool require_ack = true);
std::vector<std::string> NatProbeMatchAcknowledgedDiscoveryAttempts(
    uint64_t socket, LanAddress source);
// Host poll preparation: public punch ACK, or a signed invite-scoped LAN
// request that the host answered successfully for this server-issued attempt.
std::vector<NatProbePeerAttempt> NatProbeAcknowledgedDiscoveryAttempts();
bool NatProbeRendezvousAttemptActive(uint64_t socket,
                                     std::string_view attempt_id);
// LAN invite correlation is separate from the server-observed public endpoint.
// It never creates private admission authority; the host grant still does that.
std::vector<std::string> NatProbeHostedInviteAttempts(uint64_t socket);
bool NatProbeRegisterInviteLanPeer(uint64_t socket, std::string_view attempt_id,
                                   LanAddress peer);
bool NatProbeSelectInviteDiscoveryPeer(uint64_t socket, std::string_view attempt_id,
                                       LanAddress peer);
std::optional<LanAddress> NatProbeNormalizeGameplaySource(uint64_t socket,
                                                          LanAddress source);

}  // namespace rex::system::xam
