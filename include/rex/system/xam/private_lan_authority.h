#pragma once
#include <rex/system/xam/private_lan_invitation.h>
#include <rex/system/xam/gameplay_traversal.h>
#include <rex/system/xam/session_arbitration_crypto.h>
namespace rex::system::xam {
struct PrivateLanJoinClaim {
  uint64_t xuid = 0;
  uint64_t machine_id = 0;
  LanAddress endpoint;
  ArbitrationToken challenge{};
  ArbitrationToken request_id{};
  ArbitrationPublicKey client_public_key{};
};
// Exact semantic transcript for invitation bootstrap; the discovery adapter
// also authenticates every outer public packet byte before interpreting it.
std::vector<uint8_t> PrivateLanJoinTranscript(uint32_t title,
    const ArbitrationIdentity& identity, const PrivateLanJoinClaim& claim);
class PrivateLanAuthority final {
 public:
  static std::unique_ptr<PrivateLanAuthority> Create(uint32_t title,
      ArbitrationIdentity identity, LanAddress host_endpoint,
      std::shared_ptr<const PrivateLanInvitation> invitation);
  ~PrivateLanAuthority();
  PrivateLanAuthority(const PrivateLanAuthority&) = delete;
  PrivateLanAuthority& operator=(const PrivateLanAuthority&) = delete;
  // Verifies the per-client possession proof before creating immutable member
  // generations and fresh pair links. Exact initial retries retain their keys.
  bool Admit(const PrivateLanJoinClaim& claim, std::span<const uint8_t> proof);
  bool Remove(uint64_t client);
  // Private encoded ticket, delivered only inside the authenticated ephemeral
  // envelope. Callers must cleanse this temporary buffer after sealing.
  std::optional<std::vector<uint8_t>> Ticket(uint64_t member, uint32_t lease_ms = 30000) const;
 private:
  struct State;
  explicit PrivateLanAuthority(std::unique_ptr<State> state);
  std::unique_ptr<State> state_;
};
struct PrivateLanGameplayTicket {
  GameplayAuthorization authorization;
  std::vector<LanAddress> peer_endpoints;
};
// Strict exact-size parser; output is published only after all bounds, IDs,
// generations, keys, routes and full session fingerprint validate.
std::optional<PrivateLanGameplayTicket> ParsePrivateLanGameplayTicket(
    uint32_t title, const ArbitrationIdentity& expected, uint64_t local_xuid,
    std::span<const uint8_t> bytes, uint16_t guest_port = 3074);
}  // namespace rex::system::xam
