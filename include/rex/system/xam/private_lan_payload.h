#pragma once
#include <rex/system/xam/private_lan_invitation.h>
#include <rex/system/xam/session_arbitration_crypto.h>
namespace rex::system::xam {
inline constexpr size_t kMaximumPrivateLanPayloadAAD = 2048;
struct PrivateLanPayloadEnvelope {
  ArbitrationPayloadEnvelope payload;
  PrivateLanInvitation::Tag invitation_proof{};
};
// Uses the existing ephemeral X25519/AES256GCM envelope, with the complete
// encrypted reply and ordered keys authenticated by the distinct invite grant.
// AAD contains the exact session identity, fresh request ID and complete public
// roster/endpoint fields. The discovery caller still owns fresh RPC correlation.
std::optional<PrivateLanPayloadEnvelope> SealPrivateLanPayload(
    const PrivateLanInvitation& host_invitation, uint64_t client,
    const ArbitrationPublicKey& recipient, std::span<const uint8_t> plaintext,
    std::span<const uint8_t> aad);
// Invitation proof validation precedes payload decryption/publication. An
// on-path replacement server key/envelope cannot create local peer authority.
std::optional<SensitiveArbitrationPayload> OpenPrivateLanPayload(
    const PrivateLanInvitation& client_invitation, uint64_t client,
    const EphemeralArbitrationKey& recipient, const PrivateLanPayloadEnvelope& envelope,
    std::span<const uint8_t> aad);
}  // namespace rex::system::xam
