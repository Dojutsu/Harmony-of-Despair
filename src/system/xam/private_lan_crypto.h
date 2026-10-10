#pragma once
// Platform crypto for the protected private LAN, arbitration and gameplay
// datagram paths. Linux uses OpenSSL libcrypto; Windows uses CNG (bcrypt).
// Every function fails closed and never logs key, secret or plaintext bytes.
#include <array>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <memory>
#include <optional>
#include <span>

namespace rex::system::xam::lan_crypto {

using Bytes = std::span<const uint8_t>;

// Whether this platform provides the protected private LAN primitives.
bool Available() noexcept;

void Cleanse(void* data, size_t size) noexcept;
// Constant-time equality of two equal-length buffers.
bool Equal(const void* left, const void* right, size_t size) noexcept;
bool Random(std::span<uint8_t> output) noexcept;

bool Sha256(std::initializer_list<Bytes> parts, std::span<uint8_t, 32> output) noexcept;
bool HmacSha256(Bytes key, std::initializer_list<Bytes> parts,
                std::span<uint8_t, 32> output) noexcept;
// RFC 5869 extract-and-expand; info is the concatenation of the parts.
bool HkdfSha256(Bytes salt, Bytes key, std::initializer_list<Bytes> info,
                std::span<uint8_t> output) noexcept;

// AES-256-GCM with a 96-bit IV and a 128-bit tag.
bool AesGcmSeal(std::span<const uint8_t, 32> key, std::span<const uint8_t, 12> iv, Bytes aad,
                Bytes plaintext, uint8_t* ciphertext, std::span<uint8_t, 16> tag) noexcept;
// Writes plaintext only into caller storage; callers commit it after success.
bool AesGcmOpen(std::span<const uint8_t, 32> key, std::span<const uint8_t, 12> iv, Bytes aad,
                Bytes ciphertext, std::span<const uint8_t, 16> tag, uint8_t* plaintext) noexcept;

// RFC 7748 X25519 key with raw 32-byte public encoding.
class X25519Key {
 public:
  X25519Key() noexcept;
  ~X25519Key();
  X25519Key(X25519Key&&) noexcept;
  X25519Key& operator=(X25519Key&&) noexcept;
  X25519Key(const X25519Key&) = delete;
  X25519Key& operator=(const X25519Key&) = delete;

  static std::optional<X25519Key> Generate() noexcept;
  bool valid() const noexcept;
  const std::array<uint8_t, 32>& public_key() const noexcept;
  // Rejects all-zero peers and all-zero (low-order) shared secrets.
  bool Agree(std::span<const uint8_t, 32> peer, std::span<uint8_t, 32> shared) const noexcept;

 private:
  struct State;
  std::unique_ptr<State> state_;
};

template <size_t N> struct SensitiveArray {
  std::array<uint8_t, N> bytes{};
  SensitiveArray() = default;
  SensitiveArray(const SensitiveArray&) = delete;
  SensitiveArray& operator=(const SensitiveArray&) = delete;
  ~SensitiveArray() { Cleanse(bytes.data(), bytes.size()); }
};

}  // namespace rex::system::xam::lan_crypto
