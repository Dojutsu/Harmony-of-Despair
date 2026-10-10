#include <rex/system/xam/session_arbitration_crypto.h>
#include <rex/platform.h>
#include "private_lan_crypto.h"
#include <algorithm>
#include <utility>
#include <string_view>

namespace rex::system::xam {
namespace {
namespace crypto = lan_crypto;
template<class T> bool Nonzero(const T& bytes) {
  uint8_t accumulated = 0;
  for (uint8_t byte : bytes) accumulated |= byte;
  return accumulated != 0;
}
bool ValidAAD(std::span<const uint8_t> aad) {
  return !aad.empty() && aad.size() <= kMaximumArbitrationAAD && Nonzero(aad);
}
const ArbitrationPublicKey kInvalidPublicKey{};
template<size_t N> using SensitiveBytes = crypto::SensitiveArray<N>;
bool DeriveKey(const crypto::X25519Key& own, const ArbitrationPublicKey& peer,
               const ArbitrationPublicKey& client, const ArbitrationPublicKey& server,
               std::span<const uint8_t> aad, SensitiveBytes<32>& output,
               std::string_view domain = "ReXGlue LAN arbitration credential envelope v2") {
  if (!own.valid() || !Nonzero(peer) || !ValidAAD(aad)) return false;
  SensitiveBytes<32> shared;
  if (!own.Agree(peer, shared.bytes)) return false;
  // Full32 SHA256 output, with fixed domain, ordered raw public keys and an
  // explicit AAD length. Binding raw keys also covers X25519 encoding aliases.
  const auto aad_size = static_cast<uint32_t>(aad.size());
  const std::array<uint8_t, 4> encoded_size{
      static_cast<uint8_t>(aad_size >> 24), static_cast<uint8_t>(aad_size >> 16),
      static_cast<uint8_t>(aad_size >> 8), static_cast<uint8_t>(aad_size)};
  const auto* domain_bytes = reinterpret_cast<const uint8_t*>(domain.data());
  return crypto::Sha256({shared.bytes, {domain_bytes, domain.size()}, client, server,
                         encoded_size, aad}, output.bytes) &&
         Nonzero(output.bytes);
}
} // namespace
struct EphemeralArbitrationKey::State {
  crypto::X25519Key key;
};
EphemeralArbitrationKey::EphemeralArbitrationKey() noexcept = default;
EphemeralArbitrationKey::~EphemeralArbitrationKey() = default;
EphemeralArbitrationKey::EphemeralArbitrationKey(EphemeralArbitrationKey&&) noexcept = default;
EphemeralArbitrationKey& EphemeralArbitrationKey::operator=(EphemeralArbitrationKey&&) noexcept = default;
bool EphemeralArbitrationKey::valid() const noexcept {
  return state_ && state_->key.valid();
}
const ArbitrationPublicKey& EphemeralArbitrationKey::public_key() const noexcept {
  return valid() ? state_->key.public_key() : kInvalidPublicKey;
}
std::optional<EphemeralArbitrationKey> NewArbitrationKey() {
  auto generated = crypto::X25519Key::Generate();
  if (!generated) return std::nullopt;
  EphemeralArbitrationKey result;
  result.state_ = std::make_unique<EphemeralArbitrationKey::State>();
  result.state_->key = std::move(*generated);
  if (!result.valid()) return std::nullopt;
  return result;
}
std::optional<ArbitrationCredentialEnvelope> SealArbitrationCredential(
    const ArbitrationPublicKey& peer, const ArbitrationToken& credential, std::span<const uint8_t> aad) {
  if (!Nonzero(peer) || !Nonzero(credential) || !ValidAAD(aad)) return std::nullopt;
  auto server = NewArbitrationKey(); if (!server) return std::nullopt;
  ArbitrationCredentialEnvelope envelope; envelope.server_public_key = server->public_key();
  SensitiveBytes<32> key;
  if (!DeriveKey(server->state_->key, peer, peer, envelope.server_public_key, aad, key)) return std::nullopt;
  unsigned tries = 0;
  do { if (!crypto::Random(envelope.iv)) return std::nullopt; }
  while (!Nonzero(envelope.iv) && ++tries < 8);
  if (!Nonzero(envelope.iv)) return std::nullopt;
  if (!crypto::AesGcmSeal(key.bytes, envelope.iv, aad, credential, envelope.ciphertext.data(),
                          envelope.tag) ||
      !Nonzero(envelope.ciphertext) || !Nonzero(envelope.tag)) return std::nullopt;
  return envelope;
}
std::optional<ArbitrationToken> OpenArbitrationCredential(
    const EphemeralArbitrationKey& client, const ArbitrationCredentialEnvelope& envelope,
    std::span<const uint8_t> aad) {
  if (!client.valid() || !ValidAAD(aad) || !Nonzero(envelope.server_public_key) ||
      !Nonzero(envelope.iv) || !Nonzero(envelope.ciphertext) || !Nonzero(envelope.tag)) return std::nullopt;
  SensitiveBytes<32> key; SensitiveBytes<16> token;
  if (!DeriveKey(client.state_->key, envelope.server_public_key, client.public_key(),
      envelope.server_public_key, aad, key)) return std::nullopt;
  if (!crypto::AesGcmOpen(key.bytes, envelope.iv, aad, envelope.ciphertext, envelope.tag,
                          token.bytes.data()) ||
      !Nonzero(token.bytes)) return std::nullopt;
  return token.bytes;
}
struct SensitiveArbitrationPayload::State {
  std::vector<uint8_t> bytes;
  ~State() { crypto::Cleanse(bytes.data(), bytes.size()); }
};
SensitiveArbitrationPayload::SensitiveArbitrationPayload() noexcept = default;
SensitiveArbitrationPayload::~SensitiveArbitrationPayload() = default;
SensitiveArbitrationPayload::SensitiveArbitrationPayload(SensitiveArbitrationPayload&&) noexcept = default;
SensitiveArbitrationPayload& SensitiveArbitrationPayload::operator=(SensitiveArbitrationPayload&&) noexcept = default;
std::span<const uint8_t> SensitiveArbitrationPayload::bytes() const noexcept {
  return state_ ? std::span<const uint8_t>(state_->bytes) : std::span<const uint8_t>{};
}

std::optional<ArbitrationPayloadEnvelope> SealArbitrationPayload(
    const ArbitrationPublicKey& peer, std::span<const uint8_t> plaintext,
    std::span<const uint8_t> aad) {
  if (!Nonzero(peer) || !ValidAAD(aad) || plaintext.empty() ||
      plaintext.size() > kMaximumArbitrationPayload) return std::nullopt;
  try {
    auto server = NewArbitrationKey(); if (!server) return std::nullopt;
    ArbitrationPayloadEnvelope result;
    result.server_public_key = server->public_key(); result.ciphertext.resize(plaintext.size());
    SensitiveBytes<32> key;
    if (!DeriveKey(server->state_->key, peer, peer, result.server_public_key, aad, key,
                   "ReXGlue private LAN payload envelope v1")) return std::nullopt;
    if (!crypto::Random(result.iv) || !Nonzero(result.iv)) return std::nullopt;
    if (!crypto::AesGcmSeal(key.bytes, result.iv, aad, plaintext, result.ciphertext.data(),
                            result.tag)) return std::nullopt;
    return result;
  } catch (...) { return std::nullopt; }
}

std::optional<SensitiveArbitrationPayload> OpenArbitrationPayload(
    const EphemeralArbitrationKey& client, const ArbitrationPayloadEnvelope& envelope,
    std::span<const uint8_t> aad) {
  if (!client.valid() || !ValidAAD(aad) || !Nonzero(envelope.server_public_key) ||
      !Nonzero(envelope.iv) || envelope.ciphertext.empty() ||
      envelope.ciphertext.size() > kMaximumArbitrationPayload || !Nonzero(envelope.tag)) return std::nullopt;
  try {
    SensitiveBytes<32> key;
    if (!DeriveKey(client.state_->key, envelope.server_public_key, client.public_key(),
                   envelope.server_public_key, aad, key,
                   "ReXGlue private LAN payload envelope v1")) return std::nullopt;
    SensitiveArbitrationPayload result;
    result.state_ = std::make_unique<SensitiveArbitrationPayload::State>();
    result.state_->bytes.resize(envelope.ciphertext.size());
    // A failed tag check returns nullopt; State cleanses any staged bytes.
    if (!crypto::AesGcmOpen(key.bytes, envelope.iv, aad, envelope.ciphertext, envelope.tag,
                            result.state_->bytes.data())) return std::nullopt;
    return result;
  } catch (...) { return std::nullopt; }
}
} // namespace rex::system::xam
