#include <rex/system/xam/private_lan_payload.h>
namespace rex::system::xam {
namespace {
constexpr std::string_view kPayloadProofDomain = "lan-private-ticket-reply-v1";
std::optional<std::vector<uint8_t>> ProofTranscript(const ArbitrationPublicKey& recipient,
    const ArbitrationPayloadEnvelope& envelope, std::span<const uint8_t> aad) {
  if (aad.empty() || aad.size() > kMaximumPrivateLanPayloadAAD || envelope.ciphertext.empty() ||
      envelope.ciphertext.size() > kMaximumArbitrationPayload) return std::nullopt;
  try {
    std::vector<uint8_t> transcript;
    transcript.reserve(4 + aad.size() + 32 + 32 + 12 + 2 + envelope.ciphertext.size() + 16);
    const auto length = uint32_t(aad.size());
    for (int shift = 24; shift >= 0; shift -= 8) transcript.push_back(uint8_t(length >> shift));
    transcript.insert(transcript.end(), aad.begin(), aad.end());
    transcript.insert(transcript.end(), recipient.begin(), recipient.end());
    transcript.insert(transcript.end(), envelope.server_public_key.begin(), envelope.server_public_key.end());
    transcript.insert(transcript.end(), envelope.iv.begin(), envelope.iv.end());
    transcript.push_back(uint8_t(envelope.ciphertext.size() >> 8));
    transcript.push_back(uint8_t(envelope.ciphertext.size()));
    transcript.insert(transcript.end(), envelope.ciphertext.begin(), envelope.ciphertext.end());
    transcript.insert(transcript.end(), envelope.tag.begin(), envelope.tag.end());
    return transcript;
  } catch (...) { return std::nullopt; }
}
}  // namespace
std::optional<PrivateLanPayloadEnvelope> SealPrivateLanPayload(
    const PrivateLanInvitation& invitation, uint64_t client, const ArbitrationPublicKey& recipient,
    std::span<const uint8_t> plaintext, std::span<const uint8_t> aad) {
  if (!invitation.host() || !invitation.Current() || aad.size() > kMaximumPrivateLanPayloadAAD)
    return std::nullopt;
  auto payload = SealArbitrationPayload(recipient, plaintext, aad);
  if (!payload) return std::nullopt;
  const auto transcript = ProofTranscript(recipient, *payload, aad);
  if (!transcript) return std::nullopt;
  const auto proof = invitation.Proof(client, kPayloadProofDomain, *transcript);
  if (!proof) return std::nullopt;
  return PrivateLanPayloadEnvelope{std::move(*payload), *proof};
}
std::optional<SensitiveArbitrationPayload> OpenPrivateLanPayload(
    const PrivateLanInvitation& invitation, uint64_t client, const EphemeralArbitrationKey& recipient,
    const PrivateLanPayloadEnvelope& envelope, std::span<const uint8_t> aad) {
  if (invitation.host() || !recipient.valid() || !invitation.Current()) return std::nullopt;
  const auto transcript = ProofTranscript(recipient.public_key(), envelope.payload, aad);
  if (!transcript || !invitation.Verify(client, kPayloadProofDomain, *transcript,
                                        envelope.invitation_proof)) return std::nullopt;
  return OpenArbitrationPayload(recipient, envelope.payload, aad);
}
}  // namespace rex::system::xam
