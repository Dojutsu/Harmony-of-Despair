#include <rex/system/xam/session_arbitration_crypto.h>
#include <rex/platform.h>
#if REX_PLATFORM_LINUX
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#endif
#include <algorithm>
#include <utility>

namespace rex::system::xam {
namespace {
template<class T> bool Nonzero(const T& bytes) {
  uint8_t accumulated = 0;
  for (uint8_t byte : bytes) accumulated |= byte;
  return accumulated != 0;
}
[[maybe_unused]] bool ValidAAD(std::span<const uint8_t> aad) {
  return !aad.empty() && aad.size() <= kMaximumArbitrationAAD && Nonzero(aad);
}
const ArbitrationPublicKey kInvalidPublicKey{};
#if REX_PLATFORM_LINUX
template<class T, void (*Free)(T*)> using CryptoOwner = std::unique_ptr<T, decltype(Free)>;
using KeyOwner = CryptoOwner<EVP_PKEY, EVP_PKEY_free>;
using KeyContext = CryptoOwner<EVP_PKEY_CTX, EVP_PKEY_CTX_free>;
using CipherContext = CryptoOwner<EVP_CIPHER_CTX, EVP_CIPHER_CTX_free>;
using DigestContext = CryptoOwner<EVP_MD_CTX, EVP_MD_CTX_free>;
template<size_t N> struct SensitiveBytes {
  std::array<uint8_t, N> bytes{};
  ~SensitiveBytes() { OPENSSL_cleanse(bytes.data(), bytes.size()); }
  SensitiveBytes() = default;
  SensitiveBytes(const SensitiveBytes&) = delete;
  SensitiveBytes& operator=(const SensitiveBytes&) = delete;
};
bool DeriveKey(EVP_PKEY* own, const ArbitrationPublicKey& peer,
               const ArbitrationPublicKey& client, const ArbitrationPublicKey& server,
               std::span<const uint8_t> aad, SensitiveBytes<32>& output) {
  if (!own || !Nonzero(peer) || !ValidAAD(aad)) return false;
  KeyOwner peer_key(EVP_PKEY_new_raw_public_key(EVP_PKEY_X25519, nullptr, peer.data(), peer.size()), EVP_PKEY_free);
  KeyContext context(EVP_PKEY_CTX_new(own, nullptr), EVP_PKEY_CTX_free);
  SensitiveBytes<32> shared;
  size_t size = shared.bytes.size();
  if (!peer_key || !context || EVP_PKEY_derive_init(context.get()) != 1 ||
      EVP_PKEY_derive_set_peer(context.get(), peer_key.get()) != 1 ||
      EVP_PKEY_derive(context.get(), shared.bytes.data(), &size) != 1 ||
      size != shared.bytes.size() || !Nonzero(shared.bytes)) return false;
  // Full32 SHA256 output, with fixed domain, ordered raw public keys and an
  // explicit AAD length. Binding raw keys also covers X25519 encoding aliases.
  static constexpr char domain[] = "ReXGlue LAN arbitration credential envelope v2";
  const auto aad_size = static_cast<uint32_t>(aad.size());
  const std::array<uint8_t, 4> encoded_size{
      static_cast<uint8_t>(aad_size >> 24), static_cast<uint8_t>(aad_size >> 16),
      static_cast<uint8_t>(aad_size >> 8), static_cast<uint8_t>(aad_size)};
  DigestContext digest(EVP_MD_CTX_new(), EVP_MD_CTX_free); unsigned int written = 0;
  return digest && EVP_DigestInit_ex(digest.get(), EVP_sha256(), nullptr) == 1 &&
      EVP_DigestUpdate(digest.get(), shared.bytes.data(), shared.bytes.size()) == 1 &&
      EVP_DigestUpdate(digest.get(), domain, sizeof(domain) - 1) == 1 &&
      EVP_DigestUpdate(digest.get(), client.data(), client.size()) == 1 &&
      EVP_DigestUpdate(digest.get(), server.data(), server.size()) == 1 &&
      EVP_DigestUpdate(digest.get(), encoded_size.data(), encoded_size.size()) == 1 &&
      EVP_DigestUpdate(digest.get(), aad.data(), aad.size()) == 1 &&
      EVP_DigestFinal_ex(digest.get(), output.bytes.data(), &written) == 1 &&
      written == output.bytes.size() && Nonzero(output.bytes);
}
#endif
} // namespace
struct EphemeralArbitrationKey::State {
  ArbitrationPublicKey public_key{};
#if REX_PLATFORM_LINUX
  KeyOwner key{nullptr, EVP_PKEY_free};
#endif
};
EphemeralArbitrationKey::EphemeralArbitrationKey() noexcept = default;
EphemeralArbitrationKey::~EphemeralArbitrationKey() = default;
EphemeralArbitrationKey::EphemeralArbitrationKey(EphemeralArbitrationKey&&) noexcept = default;
EphemeralArbitrationKey& EphemeralArbitrationKey::operator=(EphemeralArbitrationKey&&) noexcept = default;
bool EphemeralArbitrationKey::valid() const noexcept {
#if REX_PLATFORM_LINUX
  return state_ && state_->key && Nonzero(state_->public_key);
#else
  return false;
#endif
}
const ArbitrationPublicKey& EphemeralArbitrationKey::public_key() const noexcept {
  return valid() ? state_->public_key : kInvalidPublicKey;
}
std::optional<EphemeralArbitrationKey> NewArbitrationKey() {
#if REX_PLATFORM_LINUX
  KeyContext context(EVP_PKEY_CTX_new_id(EVP_PKEY_X25519, nullptr), EVP_PKEY_CTX_free);
  EVP_PKEY* raw = nullptr;
  if (!context || EVP_PKEY_keygen_init(context.get()) != 1 || EVP_PKEY_keygen(context.get(), &raw) != 1) {
    EVP_PKEY_free(raw); return std::nullopt;
  }
  KeyOwner generated(raw, EVP_PKEY_free);
  EphemeralArbitrationKey result;
  result.state_ = std::make_unique<EphemeralArbitrationKey::State>();
  result.state_->key = std::move(generated);
  size_t size = result.state_->public_key.size();
  if (EVP_PKEY_get_raw_public_key(raw, result.state_->public_key.data(), &size) != 1 ||
      size != result.state_->public_key.size() || !result.valid()) return std::nullopt;
  return result;
#else
  return std::nullopt;
#endif
}
std::optional<ArbitrationCredentialEnvelope> SealArbitrationCredential(
    const ArbitrationPublicKey& peer, const ArbitrationToken& credential, std::span<const uint8_t> aad) {
#if REX_PLATFORM_LINUX
  if (!Nonzero(peer) || !Nonzero(credential) || !ValidAAD(aad)) return std::nullopt;
  auto server = NewArbitrationKey(); if (!server) return std::nullopt;
  ArbitrationCredentialEnvelope envelope; envelope.server_public_key = server->public_key();
  SensitiveBytes<32> key;
  if (!DeriveKey(server->state_->key.get(), peer, peer, envelope.server_public_key, aad, key)) return std::nullopt;
  unsigned tries = 0;
  do { if (RAND_bytes(envelope.iv.data(), static_cast<int>(envelope.iv.size())) != 1) return std::nullopt; }
  while (!Nonzero(envelope.iv) && ++tries < 8);
  if (!Nonzero(envelope.iv)) return std::nullopt;
  CipherContext cipher(EVP_CIPHER_CTX_new(), EVP_CIPHER_CTX_free); int size = 0, final_size = 0;
  std::array<uint8_t, 16> final{};
  if (!cipher || EVP_EncryptInit_ex(cipher.get(), EVP_aes_256_gcm(), nullptr, nullptr, nullptr) != 1 ||
      EVP_CIPHER_CTX_ctrl(cipher.get(), EVP_CTRL_GCM_SET_IVLEN, static_cast<int>(envelope.iv.size()), nullptr) != 1 ||
      EVP_EncryptInit_ex(cipher.get(), nullptr, nullptr, key.bytes.data(), envelope.iv.data()) != 1 ||
      EVP_EncryptUpdate(cipher.get(), nullptr, &size, aad.data(), static_cast<int>(aad.size())) != 1 ||
      EVP_EncryptUpdate(cipher.get(), envelope.ciphertext.data(), &size, credential.data(), static_cast<int>(credential.size())) != 1 ||
      size != static_cast<int>(credential.size()) || EVP_EncryptFinal_ex(cipher.get(), final.data(), &final_size) != 1 ||
      final_size != 0 || EVP_CIPHER_CTX_ctrl(cipher.get(), EVP_CTRL_GCM_GET_TAG, static_cast<int>(envelope.tag.size()), envelope.tag.data()) != 1 ||
      !Nonzero(envelope.ciphertext) || !Nonzero(envelope.tag)) return std::nullopt;
  return envelope;
#else
  (void)peer; (void)credential; (void)aad; return std::nullopt;
#endif
}
std::optional<ArbitrationToken> OpenArbitrationCredential(
    const EphemeralArbitrationKey& client, const ArbitrationCredentialEnvelope& envelope,
    std::span<const uint8_t> aad) {
#if REX_PLATFORM_LINUX
  if (!client.valid() || !ValidAAD(aad) || !Nonzero(envelope.server_public_key) ||
      !Nonzero(envelope.iv) || !Nonzero(envelope.ciphertext) || !Nonzero(envelope.tag)) return std::nullopt;
  SensitiveBytes<32> key; SensitiveBytes<16> token; SensitiveBytes<16> final;
  if (!DeriveKey(client.state_->key.get(), envelope.server_public_key, client.public_key(),
      envelope.server_public_key, aad, key)) return std::nullopt;
  auto tag = envelope.tag;
  CipherContext cipher(EVP_CIPHER_CTX_new(), EVP_CIPHER_CTX_free); int size = 0, final_size = 0;
  if (!cipher || EVP_DecryptInit_ex(cipher.get(), EVP_aes_256_gcm(), nullptr, nullptr, nullptr) != 1 ||
      EVP_CIPHER_CTX_ctrl(cipher.get(), EVP_CTRL_GCM_SET_IVLEN, static_cast<int>(envelope.iv.size()), nullptr) != 1 ||
      EVP_DecryptInit_ex(cipher.get(), nullptr, nullptr, key.bytes.data(), envelope.iv.data()) != 1 ||
      EVP_DecryptUpdate(cipher.get(), nullptr, &size, aad.data(), static_cast<int>(aad.size())) != 1 ||
      EVP_DecryptUpdate(cipher.get(), token.bytes.data(), &size, envelope.ciphertext.data(), static_cast<int>(envelope.ciphertext.size())) != 1 ||
      size != static_cast<int>(token.bytes.size()) ||
      EVP_CIPHER_CTX_ctrl(cipher.get(), EVP_CTRL_GCM_SET_TAG, static_cast<int>(tag.size()), tag.data()) != 1 ||
      EVP_DecryptFinal_ex(cipher.get(), final.bytes.data(), &final_size) != 1 ||
      final_size != 0 || !Nonzero(token.bytes)) return std::nullopt;
  return token.bytes;
#else
  (void)client; (void)envelope; (void)aad; return std::nullopt;
#endif
}
} // namespace rex::system::xam
