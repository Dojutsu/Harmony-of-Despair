/**
 * @file        system/xam/portable_crypto.h
 * @brief       Self-contained SHA-256, HMAC/HKDF, AES-256-GCM and X25519 for
 *              platforms without a system crypto library (Android/bionic).
 *
 * @license     BSD 3-Clause License
 *              See LICENSE file in the project root for full license text.
 */
#pragma once

#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <span>

namespace rex::system::xam::portable_crypto {

using Bytes = std::span<const uint8_t>;

class Sha256 final {
 public:
  Sha256() noexcept;
  void Update(Bytes data) noexcept;
  void Final(std::span<uint8_t, 32> output) noexcept;

 private:
  void Block(const uint8_t* block) noexcept;
  uint32_t state_[8];
  uint8_t buffer_[64];
  size_t buffered_ = 0;
  uint64_t total_ = 0;
};

void Sha256Digest(std::initializer_list<Bytes> parts, std::span<uint8_t, 32> output) noexcept;
void HmacSha256(Bytes key, std::initializer_list<Bytes> parts,
                std::span<uint8_t, 32> output) noexcept;
// RFC 5869 extract-and-expand; output must be at most 255 * 32 bytes.
bool HkdfSha256(Bytes salt, Bytes key, std::initializer_list<Bytes> info,
                std::span<uint8_t> output) noexcept;

class Aes256 final {
 public:
  explicit Aes256(std::span<const uint8_t, 32> key) noexcept;
  ~Aes256();
  void Encrypt(const uint8_t input[16], uint8_t output[16]) const noexcept;

 private:
  uint32_t round_keys_[60];
};

// AES-256-GCM with a 96-bit IV and a 128-bit tag. ciphertext/plaintext may
// alias nothing; both may be null when the respective input is empty.
void AesGcmSeal(std::span<const uint8_t, 32> key, std::span<const uint8_t, 12> iv, Bytes aad,
                Bytes plaintext, uint8_t* ciphertext, std::span<uint8_t, 16> tag) noexcept;
bool AesGcmOpen(std::span<const uint8_t, 32> key, std::span<const uint8_t, 12> iv, Bytes aad,
                Bytes ciphertext, std::span<const uint8_t, 16> tag, uint8_t* plaintext) noexcept;

// RFC 7748 X25519: output = scalar * point (point as a little-endian u-coordinate).
void X25519(std::span<uint8_t, 32> output, std::span<const uint8_t, 32> scalar,
            std::span<const uint8_t, 32> point) noexcept;
void X25519BasePoint(std::span<uint8_t, 32> output, std::span<const uint8_t, 32> scalar) noexcept;

bool ConstantTimeEqual(const uint8_t* left, const uint8_t* right, size_t size) noexcept;
void Cleanse(void* data, size_t size) noexcept;

}  // namespace rex::system::xam::portable_crypto
