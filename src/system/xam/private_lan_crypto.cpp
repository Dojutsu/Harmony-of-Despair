#include "private_lan_crypto.h"

#include <rex/platform.h>

#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>

#if REX_PLATFORM_POSIX_ONLINE
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <openssl/kdf.h>
#include <openssl/rand.h>
#elif REX_PLATFORM_WIN32
#include <windows.h>
#include <bcrypt.h>
#endif

namespace rex::system::xam::lan_crypto {
namespace {
bool Nonzero(Bytes bytes) noexcept {
  uint8_t value = 0;
  for (uint8_t byte : bytes) value |= byte;
  return value != 0;
}
[[maybe_unused]] bool FitsInt(size_t size) noexcept { return size <= size_t(INT_MAX); }
#if REX_PLATFORM_POSIX_ONLINE
template <class T, void (*Free)(T*)> using Owner = std::unique_ptr<T, decltype(Free)>;
using CipherContext = Owner<EVP_CIPHER_CTX, EVP_CIPHER_CTX_free>;
using DigestContext = Owner<EVP_MD_CTX, EVP_MD_CTX_free>;
using KeyContext = Owner<EVP_PKEY_CTX, EVP_PKEY_CTX_free>;
using KeyOwner = Owner<EVP_PKEY, EVP_PKEY_free>;
#elif REX_PLATFORM_WIN32
bool Ok(NTSTATUS status) noexcept { return status >= 0; }
struct Algorithm {
  BCRYPT_ALG_HANDLE handle = nullptr;
  ~Algorithm() { if (handle) BCryptCloseAlgorithmProvider(handle, 0); }
};
struct Key {
  BCRYPT_KEY_HANDLE handle = nullptr;
  ~Key() { if (handle) BCryptDestroyKey(handle); }
};
struct Hash {
  BCRYPT_HASH_HANDLE handle = nullptr;
  ~Hash() { if (handle) BCryptDestroyHash(handle); }
};
struct Secret {
  BCRYPT_SECRET_HANDLE handle = nullptr;
  ~Secret() { if (handle) BCryptDestroySecret(handle); }
};
bool FitsUlong(size_t size) noexcept { return size <= size_t(ULONG_MAX); }
bool Digest(Bytes key, bool hmac, std::initializer_list<Bytes> parts,
            std::span<uint8_t, 32> output) noexcept {
  Algorithm algorithm;
  Hash hash;
  if (!FitsUlong(key.size()) ||
      !Ok(BCryptOpenAlgorithmProvider(&algorithm.handle, BCRYPT_SHA256_ALGORITHM, nullptr,
                                      hmac ? BCRYPT_ALG_HANDLE_HMAC_FLAG : 0)) ||
      !Ok(BCryptCreateHash(algorithm.handle, &hash.handle, nullptr, 0,
                           hmac ? const_cast<PUCHAR>(key.data()) : nullptr,
                           hmac ? ULONG(key.size()) : 0, 0)))
    return false;
  for (const auto& part : parts) {
    if (!FitsUlong(part.size())) return false;
    if (!part.empty() &&
        !Ok(BCryptHashData(hash.handle, const_cast<PUCHAR>(part.data()), ULONG(part.size()), 0)))
      return false;
  }
  return Ok(BCryptFinishHash(hash.handle, output.data(), ULONG(output.size()), 0));
}
bool Gcm(std::span<const uint8_t, 32> key, std::span<const uint8_t, 12> iv, Bytes aad,
         Bytes input, uint8_t* output, uint8_t* tag, bool seal) noexcept {
  if (!FitsUlong(aad.size()) || !FitsUlong(input.size())) return false;
  Algorithm algorithm;
  Key handle;
  if (!Ok(BCryptOpenAlgorithmProvider(&algorithm.handle, BCRYPT_AES_ALGORITHM, nullptr, 0)) ||
      !Ok(BCryptSetProperty(algorithm.handle, BCRYPT_CHAINING_MODE,
                            reinterpret_cast<PUCHAR>(const_cast<wchar_t*>(BCRYPT_CHAIN_MODE_GCM)),
                            ULONG(sizeof(BCRYPT_CHAIN_MODE_GCM)), 0)) ||
      !Ok(BCryptGenerateSymmetricKey(algorithm.handle, &handle.handle, nullptr, 0,
                                     const_cast<PUCHAR>(key.data()), ULONG(key.size()), 0)))
    return false;
  BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO info;
  BCRYPT_INIT_AUTH_MODE_INFO(info);
  info.pbNonce = const_cast<PUCHAR>(iv.data());
  info.cbNonce = ULONG(iv.size());
  info.pbAuthData = aad.empty() ? nullptr : const_cast<PUCHAR>(aad.data());
  info.cbAuthData = ULONG(aad.size());
  info.pbTag = tag;
  info.cbTag = 16;
  // CNG rejects null buffers even for empty input; GCM needs no padding.
  uint8_t empty = 0;
  auto* in = input.empty() ? &empty : const_cast<PUCHAR>(input.data());
  auto* out = input.empty() ? &empty : output;
  ULONG written = 0;
  const auto status =
      seal ? BCryptEncrypt(handle.handle, in, ULONG(input.size()), &info, nullptr, 0, out,
                           ULONG(input.size()), &written, 0)
           : BCryptDecrypt(handle.handle, in, ULONG(input.size()), &info, nullptr, 0, out,
                           ULONG(input.size()), &written, 0);
  return Ok(status) && written == input.size();
}
#endif
}  // namespace

bool Available() noexcept {
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
  return true;
#else
  return false;
#endif
}

void Cleanse(void* data, size_t size) noexcept {
  if (!data || !size) return;
#if REX_PLATFORM_POSIX_ONLINE
  OPENSSL_cleanse(data, size);
#elif REX_PLATFORM_WIN32
  SecureZeroMemory(data, size);
#else
  volatile auto* bytes = static_cast<volatile uint8_t*>(data);
  while (size--) *bytes++ = 0;
#endif
}

bool Equal(const void* left, const void* right, size_t size) noexcept {
#if REX_PLATFORM_POSIX_ONLINE
  return CRYPTO_memcmp(left, right, size) == 0;
#else
  // Fixed-length XOR reduction; CNG exposes no generic constant-time compare.
  const volatile auto* a = static_cast<const volatile uint8_t*>(left);
  const volatile auto* b = static_cast<const volatile uint8_t*>(right);
  uint8_t difference = 0;
  for (size_t i = 0; i < size; ++i) difference |= uint8_t(a[i] ^ b[i]);
  return difference == 0;
#endif
}

bool Random(std::span<uint8_t> output) noexcept {
  if (output.empty()) return true;
#if REX_PLATFORM_POSIX_ONLINE
  return FitsInt(output.size()) && RAND_bytes(output.data(), int(output.size())) == 1;
#elif REX_PLATFORM_WIN32
  return FitsUlong(output.size()) &&
         Ok(BCryptGenRandom(nullptr, output.data(), ULONG(output.size()),
                            BCRYPT_USE_SYSTEM_PREFERRED_RNG));
#else
  return false;
#endif
}

bool Sha256(std::initializer_list<Bytes> parts, std::span<uint8_t, 32> output) noexcept {
#if REX_PLATFORM_POSIX_ONLINE
  DigestContext digest(EVP_MD_CTX_new(), EVP_MD_CTX_free);
  if (!digest || EVP_DigestInit_ex(digest.get(), EVP_sha256(), nullptr) != 1) return false;
  for (const auto& part : parts)
    if (EVP_DigestUpdate(digest.get(), part.data(), part.size()) != 1) return false;
  unsigned written = 0;
  return EVP_DigestFinal_ex(digest.get(), output.data(), &written) == 1 && written == output.size();
#elif REX_PLATFORM_WIN32
  return Digest({}, false, parts, output);
#else
  (void)parts; (void)output; return false;
#endif
}

bool HmacSha256(Bytes key, std::initializer_list<Bytes> parts,
                std::span<uint8_t, 32> output) noexcept {
  if (key.empty()) return false;
#if REX_PLATFORM_POSIX_ONLINE
  try {
    std::vector<uint8_t> message;
    struct Clean { std::vector<uint8_t>& bytes; ~Clean() { Cleanse(bytes.data(), bytes.size()); } } clean{message};
    for (const auto& part : parts) message.insert(message.end(), part.begin(), part.end());
    unsigned written = 0;
    return FitsInt(key.size()) &&
           HMAC(EVP_sha256(), key.data(), int(key.size()), message.data(), message.size(),
                output.data(), &written) && written == output.size();
  } catch (...) { return false; }
#elif REX_PLATFORM_WIN32
  return Digest(key, true, parts, output);
#else
  (void)parts; (void)output; return false;
#endif
}

bool HkdfSha256(Bytes salt, Bytes key, std::initializer_list<Bytes> info,
                std::span<uint8_t> output) noexcept {
  if (key.empty() || output.empty() || output.size() > 255 * 32) return false;
#if REX_PLATFORM_POSIX_ONLINE
  KeyContext context(EVP_PKEY_CTX_new_id(EVP_PKEY_HKDF, nullptr), EVP_PKEY_CTX_free);
  if (!context || EVP_PKEY_derive_init(context.get()) != 1 ||
      EVP_PKEY_CTX_set_hkdf_mode(context.get(), EVP_PKEY_HKDEF_MODE_EXTRACT_AND_EXPAND) != 1 ||
      EVP_PKEY_CTX_set_hkdf_md(context.get(), EVP_sha256()) != 1 || !FitsInt(salt.size()) ||
      !FitsInt(key.size()) ||
      EVP_PKEY_CTX_set1_hkdf_salt(context.get(), salt.data(), int(salt.size())) != 1 ||
      EVP_PKEY_CTX_set1_hkdf_key(context.get(), key.data(), int(key.size())) != 1)
    return false;
  for (const auto& part : info)
    if (!FitsInt(part.size()) ||
        EVP_PKEY_CTX_add1_hkdf_info(context.get(), part.data(), int(part.size())) != 1)
      return false;
  size_t length = output.size();
  return EVP_PKEY_derive(context.get(), output.data(), &length) == 1 && length == output.size();
#elif REX_PLATFORM_WIN32
  // RFC 5869 over CNG HMAC-SHA256. An empty salt is HashLen zero bytes.
  SensitiveArray<32> prk, block;
  const std::array<uint8_t, 32> zero_salt{};
  if (!HmacSha256(salt.empty() ? Bytes(zero_salt) : salt, {key}, prk.bytes)) return false;
  std::vector<uint8_t> joined;
  try {
    for (const auto& part : info) joined.insert(joined.end(), part.begin(), part.end());
  } catch (...) { return false; }
  size_t produced = 0;
  for (uint8_t counter = 1; produced < output.size(); ++counter) {
    const Bytes previous = counter == 1 ? Bytes{} : Bytes(block.bytes);
    // HMAC consumes its parts into CNG before the result overwrites block.
    std::array<uint8_t, 32> next{};
    const bool ok = HmacSha256(prk.bytes, {previous, Bytes(joined), Bytes(&counter, 1)}, next);
    std::copy(next.begin(), next.end(), block.bytes.begin());
    Cleanse(next.data(), next.size());
    if (!ok) return false;
    const auto count = std::min(output.size() - produced, block.bytes.size());
    std::copy_n(block.bytes.begin(), count, output.begin() + produced);
    produced += count;
  }
  return true;
#else
  (void)salt; (void)info; return false;
#endif
}

bool AesGcmSeal(std::span<const uint8_t, 32> key, std::span<const uint8_t, 12> iv, Bytes aad,
                Bytes plaintext, uint8_t* ciphertext, std::span<uint8_t, 16> tag) noexcept {
  if (!plaintext.empty() && !ciphertext) return false;
#if REX_PLATFORM_POSIX_ONLINE
  CipherContext cipher(EVP_CIPHER_CTX_new(), EVP_CIPHER_CTX_free);
  int written = 0, final_size = 0;
  std::array<uint8_t, 16> final{};
  return cipher && FitsInt(aad.size()) && FitsInt(plaintext.size()) &&
      EVP_EncryptInit_ex(cipher.get(), EVP_aes_256_gcm(), nullptr, nullptr, nullptr) == 1 &&
      EVP_CIPHER_CTX_ctrl(cipher.get(), EVP_CTRL_GCM_SET_IVLEN, int(iv.size()), nullptr) == 1 &&
      EVP_EncryptInit_ex(cipher.get(), nullptr, nullptr, key.data(), iv.data()) == 1 &&
      (aad.empty() || EVP_EncryptUpdate(cipher.get(), nullptr, &written, aad.data(), int(aad.size())) == 1) &&
      (plaintext.empty() || (EVP_EncryptUpdate(cipher.get(), ciphertext, &written, plaintext.data(),
                                               int(plaintext.size())) == 1 &&
                             written == int(plaintext.size()))) &&
      EVP_EncryptFinal_ex(cipher.get(), final.data(), &final_size) == 1 && final_size == 0 &&
      EVP_CIPHER_CTX_ctrl(cipher.get(), EVP_CTRL_GCM_GET_TAG, int(tag.size()), tag.data()) == 1;
#elif REX_PLATFORM_WIN32
  return Gcm(key, iv, aad, plaintext, ciphertext, tag.data(), true);
#else
  (void)key; (void)iv; (void)aad; (void)tag; return false;
#endif
}

bool AesGcmOpen(std::span<const uint8_t, 32> key, std::span<const uint8_t, 12> iv, Bytes aad,
                Bytes ciphertext, std::span<const uint8_t, 16> tag, uint8_t* plaintext) noexcept {
  if (!ciphertext.empty() && !plaintext) return false;
#if REX_PLATFORM_POSIX_ONLINE
  CipherContext cipher(EVP_CIPHER_CTX_new(), EVP_CIPHER_CTX_free);
  int written = 0, final_size = 0;
  std::array<uint8_t, 16> expected{};
  std::copy(tag.begin(), tag.end(), expected.begin());
  SensitiveArray<16> final;
  return cipher && FitsInt(aad.size()) && FitsInt(ciphertext.size()) &&
      EVP_DecryptInit_ex(cipher.get(), EVP_aes_256_gcm(), nullptr, nullptr, nullptr) == 1 &&
      EVP_CIPHER_CTX_ctrl(cipher.get(), EVP_CTRL_GCM_SET_IVLEN, int(iv.size()), nullptr) == 1 &&
      EVP_DecryptInit_ex(cipher.get(), nullptr, nullptr, key.data(), iv.data()) == 1 &&
      (aad.empty() || EVP_DecryptUpdate(cipher.get(), nullptr, &written, aad.data(), int(aad.size())) == 1) &&
      (ciphertext.empty() || (EVP_DecryptUpdate(cipher.get(), plaintext, &written, ciphertext.data(),
                                                int(ciphertext.size())) == 1 &&
                              written == int(ciphertext.size()))) &&
      EVP_CIPHER_CTX_ctrl(cipher.get(), EVP_CTRL_GCM_SET_TAG, int(expected.size()), expected.data()) == 1 &&
      EVP_DecryptFinal_ex(cipher.get(), final.bytes.data(), &final_size) == 1 && final_size == 0;
#elif REX_PLATFORM_WIN32
  std::array<uint8_t, 16> expected{};
  std::copy(tag.begin(), tag.end(), expected.begin());
  return Gcm(key, iv, aad, ciphertext, plaintext, expected.data(), false);
#else
  (void)key; (void)iv; (void)aad; (void)tag; return false;
#endif
}

struct X25519Key::State {
  std::array<uint8_t, 32> public_key{};
#if REX_PLATFORM_POSIX_ONLINE
  KeyOwner key{nullptr, EVP_PKEY_free};
#elif REX_PLATFORM_WIN32
  Algorithm algorithm;
  Key key;
#endif
};
X25519Key::X25519Key() noexcept = default;
X25519Key::~X25519Key() = default;
X25519Key::X25519Key(X25519Key&&) noexcept = default;
X25519Key& X25519Key::operator=(X25519Key&&) noexcept = default;
bool X25519Key::valid() const noexcept { return state_ && Nonzero(state_->public_key); }
const std::array<uint8_t, 32>& X25519Key::public_key() const noexcept {
  static const std::array<uint8_t, 32> invalid{};
  return valid() ? state_->public_key : invalid;
}

std::optional<X25519Key> X25519Key::Generate() noexcept {
  try {
    X25519Key result;
    result.state_ = std::make_unique<State>();
    auto& state = *result.state_;
#if REX_PLATFORM_POSIX_ONLINE
    KeyContext context(EVP_PKEY_CTX_new_id(EVP_PKEY_X25519, nullptr), EVP_PKEY_CTX_free);
    EVP_PKEY* raw = nullptr;
    if (!context || EVP_PKEY_keygen_init(context.get()) != 1 ||
        EVP_PKEY_keygen(context.get(), &raw) != 1) {
      EVP_PKEY_free(raw);
      return std::nullopt;
    }
    state.key.reset(raw);
    size_t size = state.public_key.size();
    if (EVP_PKEY_get_raw_public_key(raw, state.public_key.data(), &size) != 1 ||
        size != state.public_key.size())
      return std::nullopt;
#elif REX_PLATFORM_WIN32
    if (!Ok(BCryptOpenAlgorithmProvider(&state.algorithm.handle, BCRYPT_ECDH_ALGORITHM, nullptr, 0)) ||
        !Ok(BCryptSetProperty(state.algorithm.handle, BCRYPT_ECC_CURVE_NAME,
                              reinterpret_cast<PUCHAR>(const_cast<wchar_t*>(BCRYPT_ECC_CURVE_25519)),
                              ULONG(sizeof(BCRYPT_ECC_CURVE_25519)), 0)) ||
        !Ok(BCryptGenerateKeyPair(state.algorithm.handle, &state.key.handle, 255, 0)) ||
        !Ok(BCryptFinalizeKeyPair(state.key.handle, 0)))
      return std::nullopt;
    // BCRYPT_ECCPUBLIC_BLOB: header, X (the RFC 7748 u-coordinate bytes), zero Y.
    std::array<uint8_t, sizeof(BCRYPT_ECCKEY_BLOB) + 64> blob{};
    ULONG size = 0;
    if (!Ok(BCryptExportKey(state.key.handle, nullptr, BCRYPT_ECCPUBLIC_BLOB, blob.data(),
                            ULONG(blob.size()), &size, 0)) ||
        size != blob.size())
      return std::nullopt;
    BCRYPT_ECCKEY_BLOB header{};
    std::memcpy(&header, blob.data(), sizeof(header));
    if (header.dwMagic != BCRYPT_ECDH_PUBLIC_GENERIC_MAGIC || header.cbKey != 32) return std::nullopt;
    std::copy_n(blob.begin() + sizeof(header), 32, state.public_key.begin());
#else
    return std::nullopt;
#endif
    if (!result.valid()) return std::nullopt;
    return result;
  } catch (...) { return std::nullopt; }
}

bool X25519Key::Agree(std::span<const uint8_t, 32> peer, std::span<uint8_t, 32> shared) const noexcept {
  if (!valid() || !Nonzero(peer)) return false;
#if REX_PLATFORM_POSIX_ONLINE
  KeyOwner peer_key(EVP_PKEY_new_raw_public_key(EVP_PKEY_X25519, nullptr, peer.data(), peer.size()),
                    EVP_PKEY_free);
  KeyContext context(EVP_PKEY_CTX_new(state_->key.get(), nullptr), EVP_PKEY_CTX_free);
  size_t size = shared.size();
  if (!peer_key || !context || EVP_PKEY_derive_init(context.get()) != 1 ||
      EVP_PKEY_derive_set_peer(context.get(), peer_key.get()) != 1 ||
      EVP_PKEY_derive(context.get(), shared.data(), &size) != 1 || size != shared.size())
    return false;
#elif REX_PLATFORM_WIN32
  std::array<uint8_t, sizeof(BCRYPT_ECCKEY_BLOB) + 64> blob{};
  const BCRYPT_ECCKEY_BLOB header{BCRYPT_ECDH_PUBLIC_GENERIC_MAGIC, 32};
  std::memcpy(blob.data(), &header, sizeof(header));
  std::copy(peer.begin(), peer.end(), blob.begin() + sizeof(header));
  // RFC 7748 masks the top bit of the u-coordinate; OpenSSL does so
  // implicitly while CNG rejects the encoding. Callers still bind the raw
  // peer bytes in their derivation, so aliases cannot swap credentials.
  blob[sizeof(header) + 31] &= 0x7f;
  Key peer_key;
  Secret secret;
  SensitiveArray<32> raw;
  ULONG size = 0;
  if (!Ok(BCryptImportKeyPair(state_->algorithm.handle, nullptr, BCRYPT_ECCPUBLIC_BLOB,
                              &peer_key.handle, blob.data(), ULONG(blob.size()), 0)) ||
      !Ok(BCryptSecretAgreement(state_->key.handle, peer_key.handle, &secret.handle, 0)) ||
      !Ok(BCryptDeriveKey(secret.handle, BCRYPT_KDF_RAW_SECRET, nullptr, raw.bytes.data(),
                          ULONG(raw.bytes.size()), &size, 0)) ||
      size != raw.bytes.size())
    return false;
  // CNG returns the raw Curve25519 secret byte-reversed relative to RFC 7748.
  std::reverse_copy(raw.bytes.begin(), raw.bytes.end(), shared.begin());
#else
  (void)peer; (void)shared; return false;
#endif
  if (!Nonzero(shared)) {
    Cleanse(shared.data(), shared.size());
    return false;
  }
  return true;
}

}  // namespace rex::system::xam::lan_crypto
