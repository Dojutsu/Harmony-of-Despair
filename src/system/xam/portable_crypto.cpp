/**
 * @file        system/xam/portable_crypto.cpp
 * @brief       Self-contained crypto primitives for platforms without OpenSSL or CNG.
 *
 * Straightforward reference-style implementations (FIPS 180-4, RFC 2104,
 * RFC 5869, FIPS 197, NIST SP 800-38D, RFC 7748). Verified against OpenSSL
 * with tools/portable_crypto_check.cpp; the data volumes here (lobby
 * handshakes and small gameplay datagrams) do not need table-driven speed.
 *
 * @license     BSD 3-Clause License
 *              See LICENSE file in the project root for full license text.
 */

#include "portable_crypto.h"

#include <algorithm>
#include <array>
#include <cstring>
#include <vector>

namespace rex::system::xam::portable_crypto {
namespace {

inline uint32_t Rotr(uint32_t value, unsigned bits) noexcept {
  return (value >> bits) | (value << (32 - bits));
}
inline uint32_t LoadBe32(const uint8_t* bytes) noexcept {
  return (uint32_t(bytes[0]) << 24) | (uint32_t(bytes[1]) << 16) | (uint32_t(bytes[2]) << 8) |
         uint32_t(bytes[3]);
}
inline void StoreBe32(uint8_t* bytes, uint32_t value) noexcept {
  bytes[0] = uint8_t(value >> 24);
  bytes[1] = uint8_t(value >> 16);
  bytes[2] = uint8_t(value >> 8);
  bytes[3] = uint8_t(value);
}
inline void StoreBe64(uint8_t* bytes, uint64_t value) noexcept {
  StoreBe32(bytes, uint32_t(value >> 32));
  StoreBe32(bytes + 4, uint32_t(value));
}

constexpr uint32_t kSha256K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

}  // namespace

// ---------------------------------------------------------------------------
// SHA-256

Sha256::Sha256() noexcept
    : state_{0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab,
             0x5be0cd19},
      buffer_{} {}

void Sha256::Block(const uint8_t* block) noexcept {
  uint32_t w[64];
  for (unsigned i = 0; i < 16; ++i) w[i] = LoadBe32(block + i * 4);
  for (unsigned i = 16; i < 64; ++i) {
    const uint32_t s0 = Rotr(w[i - 15], 7) ^ Rotr(w[i - 15], 18) ^ (w[i - 15] >> 3);
    const uint32_t s1 = Rotr(w[i - 2], 17) ^ Rotr(w[i - 2], 19) ^ (w[i - 2] >> 10);
    w[i] = w[i - 16] + s0 + w[i - 7] + s1;
  }
  uint32_t a = state_[0], b = state_[1], c = state_[2], d = state_[3];
  uint32_t e = state_[4], f = state_[5], g = state_[6], h = state_[7];
  for (unsigned i = 0; i < 64; ++i) {
    const uint32_t s1 = Rotr(e, 6) ^ Rotr(e, 11) ^ Rotr(e, 25);
    const uint32_t ch = (e & f) ^ (~e & g);
    const uint32_t t1 = h + s1 + ch + kSha256K[i] + w[i];
    const uint32_t s0 = Rotr(a, 2) ^ Rotr(a, 13) ^ Rotr(a, 22);
    const uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
    const uint32_t t2 = s0 + maj;
    h = g;
    g = f;
    f = e;
    e = d + t1;
    d = c;
    c = b;
    b = a;
    a = t1 + t2;
  }
  state_[0] += a;
  state_[1] += b;
  state_[2] += c;
  state_[3] += d;
  state_[4] += e;
  state_[5] += f;
  state_[6] += g;
  state_[7] += h;
  Cleanse(w, sizeof(w));
}

void Sha256::Update(Bytes data) noexcept {
  const uint8_t* input = data.data();
  size_t remaining = data.size();
  if (!input || !remaining) return;
  total_ += remaining;
  if (buffered_) {
    const size_t take = std::min(remaining, sizeof(buffer_) - buffered_);
    std::memcpy(buffer_ + buffered_, input, take);
    buffered_ += take;
    input += take;
    remaining -= take;
    if (buffered_ < sizeof(buffer_)) return;
    Block(buffer_);
    buffered_ = 0;
  }
  while (remaining >= sizeof(buffer_)) {
    Block(input);
    input += sizeof(buffer_);
    remaining -= sizeof(buffer_);
  }
  if (remaining) {
    std::memcpy(buffer_, input, remaining);
    buffered_ = remaining;
  }
}

void Sha256::Final(std::span<uint8_t, 32> output) noexcept {
  const uint64_t bit_length = total_ * 8;
  uint8_t pad = 0x80;
  Update(Bytes(&pad, 1));
  const uint8_t zero = 0;
  while (buffered_ != 56) Update(Bytes(&zero, 1));
  uint8_t length[8];
  StoreBe64(length, bit_length);
  Update(Bytes(length, 8));
  for (unsigned i = 0; i < 8; ++i) StoreBe32(output.data() + i * 4, state_[i]);
  Cleanse(buffer_, sizeof(buffer_));
  Cleanse(state_, sizeof(state_));
}

void Sha256Digest(std::initializer_list<Bytes> parts, std::span<uint8_t, 32> output) noexcept {
  Sha256 hash;
  for (const auto& part : parts) hash.Update(part);
  hash.Final(output);
}

void HmacSha256(Bytes key, std::initializer_list<Bytes> parts,
                std::span<uint8_t, 32> output) noexcept {
  std::array<uint8_t, 64> block_key{};
  if (key.size() > block_key.size()) {
    std::array<uint8_t, 32> digest{};
    Sha256Digest({key}, digest);
    std::copy(digest.begin(), digest.end(), block_key.begin());
    Cleanse(digest.data(), digest.size());
  } else {
    std::copy(key.begin(), key.end(), block_key.begin());
  }
  std::array<uint8_t, 64> ipad{}, opad{};
  for (size_t i = 0; i < block_key.size(); ++i) {
    ipad[i] = uint8_t(block_key[i] ^ 0x36);
    opad[i] = uint8_t(block_key[i] ^ 0x5c);
  }
  std::array<uint8_t, 32> inner{};
  Sha256 hash;
  hash.Update(ipad);
  for (const auto& part : parts) hash.Update(part);
  hash.Final(inner);
  Sha256Digest({Bytes(opad), Bytes(inner)}, output);
  Cleanse(block_key.data(), block_key.size());
  Cleanse(ipad.data(), ipad.size());
  Cleanse(opad.data(), opad.size());
  Cleanse(inner.data(), inner.size());
}

bool HkdfSha256(Bytes salt, Bytes key, std::initializer_list<Bytes> info,
                std::span<uint8_t> output) noexcept {
  if (output.empty() || output.size() > 255 * 32) return false;
  const std::array<uint8_t, 32> zero_salt{};
  std::array<uint8_t, 32> prk{};
  HmacSha256(salt.empty() ? Bytes(zero_salt) : salt, {key}, prk);
  std::vector<uint8_t> joined;
  for (const auto& part : info) joined.insert(joined.end(), part.begin(), part.end());
  std::array<uint8_t, 32> block{};
  size_t produced = 0;
  for (uint8_t counter = 1; produced < output.size(); ++counter) {
    const Bytes previous = counter == 1 ? Bytes{} : Bytes(block);
    std::array<uint8_t, 32> next{};
    HmacSha256(prk, {previous, Bytes(joined), Bytes(&counter, 1)}, next);
    block = next;
    const size_t count = std::min(output.size() - produced, block.size());
    std::copy_n(block.begin(), count, output.begin() + produced);
    produced += count;
    Cleanse(next.data(), next.size());
  }
  Cleanse(prk.data(), prk.size());
  Cleanse(block.data(), block.size());
  return true;
}

// ---------------------------------------------------------------------------
// AES-256 (encryption only; GCM never decrypts with the block cipher)

namespace {

struct AesTables {
  uint8_t sbox[256];
  AesTables() noexcept {
    // Generate the S-box from the GF(2^8) inverse and the affine transform so
    // no 256-entry constant has to be transcribed.
    uint8_t p = 1, q = 1;
    do {
      p = uint8_t(p ^ (p << 1) ^ ((p & 0x80) ? 0x1b : 0));  // p *= 3
      q ^= uint8_t(q << 1);
      q ^= uint8_t(q << 2);
      q ^= uint8_t(q << 4);
      if (q & 0x80) q ^= 0x09;  // q /= 3
      const uint8_t x = q;
      const uint8_t affine =
          uint8_t(x ^ ((x << 1) | (x >> 7)) ^ ((x << 2) | (x >> 6)) ^ ((x << 3) | (x >> 5)) ^
                  ((x << 4) | (x >> 4)) ^ 0x63);
      sbox[p] = affine;
    } while (p != 1);
    sbox[0] = 0x63;
  }
};
const AesTables& Tables() noexcept {
  static const AesTables tables;
  return tables;
}
inline uint8_t Xtime(uint8_t value) noexcept {
  return uint8_t((value << 1) ^ ((value & 0x80) ? 0x1b : 0));
}
inline uint32_t SubWord(uint32_t word) noexcept {
  const auto& s = Tables().sbox;
  return (uint32_t(s[word >> 24]) << 24) | (uint32_t(s[(word >> 16) & 0xff]) << 16) |
         (uint32_t(s[(word >> 8) & 0xff]) << 8) | uint32_t(s[word & 0xff]);
}

}  // namespace

Aes256::Aes256(std::span<const uint8_t, 32> key) noexcept : round_keys_{} {
  for (unsigned i = 0; i < 8; ++i) round_keys_[i] = LoadBe32(key.data() + i * 4);
  uint32_t rcon = 0x01000000;
  for (unsigned i = 8; i < 60; ++i) {
    uint32_t temp = round_keys_[i - 1];
    if (i % 8 == 0) {
      temp = SubWord((temp << 8) | (temp >> 24)) ^ rcon;
      rcon = uint32_t(Xtime(uint8_t(rcon >> 24))) << 24;
    } else if (i % 8 == 4) {
      temp = SubWord(temp);
    }
    round_keys_[i] = round_keys_[i - 8] ^ temp;
  }
}

Aes256::~Aes256() { Cleanse(round_keys_, sizeof(round_keys_)); }

void Aes256::Encrypt(const uint8_t input[16], uint8_t output[16]) const noexcept {
  const auto& s = Tables().sbox;
  uint8_t state[16];
  std::memcpy(state, input, 16);
  const auto add_round_key = [&](unsigned round) {
    for (unsigned c = 0; c < 4; ++c) {
      const uint32_t k = round_keys_[round * 4 + c];
      state[c * 4 + 0] ^= uint8_t(k >> 24);
      state[c * 4 + 1] ^= uint8_t(k >> 16);
      state[c * 4 + 2] ^= uint8_t(k >> 8);
      state[c * 4 + 3] ^= uint8_t(k);
    }
  };
  const auto sub_shift = [&] {
    uint8_t t[16];
    for (unsigned i = 0; i < 16; ++i) t[i] = s[state[i]];
    // state[c*4 + r]: row r is rotated left by r columns.
    for (unsigned c = 0; c < 4; ++c)
      for (unsigned r = 0; r < 4; ++r) state[c * 4 + r] = t[((c + r) % 4) * 4 + r];
  };
  const auto mix_columns = [&] {
    for (unsigned c = 0; c < 4; ++c) {
      uint8_t* col = state + c * 4;
      const uint8_t a0 = col[0], a1 = col[1], a2 = col[2], a3 = col[3];
      col[0] = uint8_t(Xtime(a0) ^ (Xtime(a1) ^ a1) ^ a2 ^ a3);
      col[1] = uint8_t(a0 ^ Xtime(a1) ^ (Xtime(a2) ^ a2) ^ a3);
      col[2] = uint8_t(a0 ^ a1 ^ Xtime(a2) ^ (Xtime(a3) ^ a3));
      col[3] = uint8_t((Xtime(a0) ^ a0) ^ a1 ^ a2 ^ Xtime(a3));
    }
  };
  add_round_key(0);
  for (unsigned round = 1; round < 14; ++round) {
    sub_shift();
    mix_columns();
    add_round_key(round);
  }
  sub_shift();
  add_round_key(14);
  std::memcpy(output, state, 16);
  Cleanse(state, sizeof(state));
}

// ---------------------------------------------------------------------------
// GCM

namespace {

struct Block128 {
  uint8_t bytes[16];
};

inline void XorInto(uint8_t* target, const uint8_t* source, size_t count) noexcept {
  for (size_t i = 0; i < count; ++i) target[i] ^= source[i];
}

// GF(2^128) multiplication with the GCM bit ordering (SP 800-38D 6.3).
void GfMultiply(uint8_t x[16], const uint8_t y[16]) noexcept {
  uint8_t z[16] = {};
  uint8_t v[16];
  std::memcpy(v, y, 16);
  for (unsigned i = 0; i < 128; ++i) {
    const uint8_t mask = uint8_t(-((x[i / 8] >> (7 - (i % 8))) & 1));
    for (unsigned j = 0; j < 16; ++j) z[j] ^= uint8_t(v[j] & mask);
    const uint8_t lsb = uint8_t(v[15] & 1);
    for (unsigned j = 15; j > 0; --j) v[j] = uint8_t((v[j] >> 1) | (v[j - 1] << 7));
    v[0] >>= 1;
    v[0] ^= uint8_t(0xe1 & uint8_t(-lsb));
  }
  std::memcpy(x, z, 16);
}

class Ghash {
 public:
  explicit Ghash(const uint8_t h[16]) noexcept { std::memcpy(h_, h, 16); }
  void Update(Bytes data) noexcept {
    for (size_t offset = 0; offset < data.size(); offset += 16) {
      const size_t count = std::min<size_t>(16, data.size() - offset);
      uint8_t block[16] = {};
      if (count) std::memcpy(block, data.data() + offset, count);
      XorInto(y_, block, 16);
      GfMultiply(y_, h_);
    }
  }
  void Lengths(uint64_t aad_bytes, uint64_t text_bytes) noexcept {
    uint8_t block[16];
    StoreBe64(block, aad_bytes * 8);
    StoreBe64(block + 8, text_bytes * 8);
    XorInto(y_, block, 16);
    GfMultiply(y_, h_);
  }
  const uint8_t* value() const noexcept { return y_; }

 private:
  uint8_t h_[16];
  uint8_t y_[16] = {};
};

void Gctr(const Aes256& cipher, uint8_t counter[16], Bytes input, uint8_t* output) noexcept {
  for (size_t offset = 0; offset < input.size(); offset += 16) {
    // Increment the low 32 bits big-endian.
    for (int i = 15; i >= 12; --i)
      if (++counter[i]) break;
    uint8_t keystream[16];
    cipher.Encrypt(counter, keystream);
    const size_t count = std::min<size_t>(16, input.size() - offset);
    for (size_t i = 0; i < count; ++i) output[offset + i] = uint8_t(input[offset + i] ^ keystream[i]);
    Cleanse(keystream, sizeof(keystream));
  }
}

void GcmCore(std::span<const uint8_t, 32> key, std::span<const uint8_t, 12> iv, Bytes aad,
             Bytes input, uint8_t* output, Bytes ghash_text, uint8_t tag[16]) noexcept {
  const Aes256 cipher(key);
  uint8_t h[16];
  const uint8_t zero[16] = {};
  cipher.Encrypt(zero, h);
  uint8_t j0[16] = {};
  std::memcpy(j0, iv.data(), 12);
  j0[15] = 1;
  uint8_t counter[16];
  std::memcpy(counter, j0, 16);
  if (!input.empty()) Gctr(cipher, counter, input, output);
  Ghash ghash(h);
  ghash.Update(aad);
  ghash.Update(ghash_text);
  ghash.Lengths(aad.size(), ghash_text.size());
  cipher.Encrypt(j0, tag);
  XorInto(tag, ghash.value(), 16);
  Cleanse(h, sizeof(h));
}

}  // namespace

void AesGcmSeal(std::span<const uint8_t, 32> key, std::span<const uint8_t, 12> iv, Bytes aad,
                Bytes plaintext, uint8_t* ciphertext, std::span<uint8_t, 16> tag) noexcept {
  GcmCore(key, iv, aad, plaintext, ciphertext, Bytes(ciphertext, plaintext.size()), tag.data());
}

bool AesGcmOpen(std::span<const uint8_t, 32> key, std::span<const uint8_t, 12> iv, Bytes aad,
                Bytes ciphertext, std::span<const uint8_t, 16> tag, uint8_t* plaintext) noexcept {
  // Authenticate before releasing plaintext: decrypt into a scratch buffer.
  std::vector<uint8_t> scratch(ciphertext.size());
  uint8_t computed[16];
  GcmCore(key, iv, aad, ciphertext, scratch.data(), ciphertext, computed);
  const bool ok = ConstantTimeEqual(computed, tag.data(), 16);
  if (ok && !scratch.empty()) std::memcpy(plaintext, scratch.data(), scratch.size());
  Cleanse(scratch.data(), scratch.size());
  Cleanse(computed, sizeof(computed));
  return ok;
}

// ---------------------------------------------------------------------------
// X25519 over GF(2^255 - 19) with five 51-bit limbs.

namespace {

using u128 = unsigned __int128;
constexpr uint64_t kMask51 = (uint64_t(1) << 51) - 1;

struct Fe {
  uint64_t v[5];
};

inline void Carry(Fe& h) noexcept {
  uint64_t c;
  c = h.v[0] >> 51; h.v[0] &= kMask51; h.v[1] += c;
  c = h.v[1] >> 51; h.v[1] &= kMask51; h.v[2] += c;
  c = h.v[2] >> 51; h.v[2] &= kMask51; h.v[3] += c;
  c = h.v[3] >> 51; h.v[3] &= kMask51; h.v[4] += c;
  c = h.v[4] >> 51; h.v[4] &= kMask51; h.v[0] += c * 19;
  c = h.v[0] >> 51; h.v[0] &= kMask51; h.v[1] += c;
}

inline Fe Add(const Fe& a, const Fe& b) noexcept {
  Fe r;
  for (unsigned i = 0; i < 5; ++i) r.v[i] = a.v[i] + b.v[i];
  Carry(r);
  return r;
}

inline Fe Sub(const Fe& a, const Fe& b) noexcept {
  // a - b + 2p keeps every limb non-negative for reduced inputs.
  Fe r;
  r.v[0] = a.v[0] + 0xFFFFFFFFFFFDAull - b.v[0];
  r.v[1] = a.v[1] + 0xFFFFFFFFFFFFEull - b.v[1];
  r.v[2] = a.v[2] + 0xFFFFFFFFFFFFEull - b.v[2];
  r.v[3] = a.v[3] + 0xFFFFFFFFFFFFEull - b.v[3];
  r.v[4] = a.v[4] + 0xFFFFFFFFFFFFEull - b.v[4];
  Carry(r);
  return r;
}

inline Fe Mul(const Fe& a, const Fe& b) noexcept {
  const u128 a0 = a.v[0], a1 = a.v[1], a2 = a.v[2], a3 = a.v[3], a4 = a.v[4];
  const uint64_t b0 = b.v[0], b1 = b.v[1], b2 = b.v[2], b3 = b.v[3], b4 = b.v[4];
  const uint64_t b1_19 = b1 * 19, b2_19 = b2 * 19, b3_19 = b3 * 19, b4_19 = b4 * 19;
  u128 r0 = a0 * b0 + a1 * b4_19 + a2 * b3_19 + a3 * b2_19 + a4 * b1_19;
  u128 r1 = a0 * b1 + a1 * b0 + a2 * b4_19 + a3 * b3_19 + a4 * b2_19;
  u128 r2 = a0 * b2 + a1 * b1 + a2 * b0 + a3 * b4_19 + a4 * b3_19;
  u128 r3 = a0 * b3 + a1 * b2 + a2 * b1 + a3 * b0 + a4 * b4_19;
  u128 r4 = a0 * b4 + a1 * b3 + a2 * b2 + a3 * b1 + a4 * b0;
  Fe r;
  uint64_t c;
  c = uint64_t(r0 >> 51); r.v[0] = uint64_t(r0) & kMask51; r1 += c;
  c = uint64_t(r1 >> 51); r.v[1] = uint64_t(r1) & kMask51; r2 += c;
  c = uint64_t(r2 >> 51); r.v[2] = uint64_t(r2) & kMask51; r3 += c;
  c = uint64_t(r3 >> 51); r.v[3] = uint64_t(r3) & kMask51; r4 += c;
  c = uint64_t(r4 >> 51); r.v[4] = uint64_t(r4) & kMask51; r.v[0] += c * 19;
  Carry(r);
  return r;
}

inline Fe Square(const Fe& a) noexcept { return Mul(a, a); }

inline Fe MulSmall(const Fe& a, uint64_t s) noexcept {
  Fe r;
  u128 t[5];
  for (unsigned i = 0; i < 5; ++i) t[i] = u128(a.v[i]) * s;
  uint64_t c = 0;
  for (unsigned i = 0; i < 5; ++i) {
    t[i] += c;
    r.v[i] = uint64_t(t[i]) & kMask51;
    c = uint64_t(t[i] >> 51);
  }
  r.v[0] += c * 19;
  Carry(r);
  return r;
}

inline void Swap(uint64_t swap, Fe& a, Fe& b) noexcept {
  const uint64_t mask = uint64_t(0) - swap;
  for (unsigned i = 0; i < 5; ++i) {
    const uint64_t t = mask & (a.v[i] ^ b.v[i]);
    a.v[i] ^= t;
    b.v[i] ^= t;
  }
}

Fe Invert(const Fe& z) noexcept {
  // z^(p-2): bits 254..8 set, low byte 0xEB.
  Fe result = {{1, 0, 0, 0, 0}};
  for (int bit = 254; bit >= 0; --bit) {
    result = Square(result);
    const bool set = bit >= 8 ? true : ((0xEB >> bit) & 1) != 0;
    if (set) result = Mul(result, z);
  }
  return result;
}

Fe FromBytes(std::span<const uint8_t, 32> bytes) noexcept {
  uint64_t words[4];
  for (unsigned i = 0; i < 4; ++i) {
    uint64_t w = 0;
    for (unsigned j = 0; j < 8; ++j) w |= uint64_t(bytes[i * 8 + j]) << (8 * j);
    words[i] = w;
  }
  Fe h;
  h.v[0] = words[0] & kMask51;
  h.v[1] = ((words[0] >> 51) | (words[1] << 13)) & kMask51;
  h.v[2] = ((words[1] >> 38) | (words[2] << 26)) & kMask51;
  h.v[3] = ((words[2] >> 25) | (words[3] << 39)) & kMask51;
  h.v[4] = (words[3] >> 12) & kMask51;  // drops the top bit per RFC 7748
  return h;
}

void ToBytes(std::span<uint8_t, 32> out, Fe h) noexcept {
  Carry(h);
  Carry(h);
  // Reduce to canonical [0, p): if h >= p, subtract p (add 19 and drop bit 255).
  uint64_t q = (h.v[0] + 19) >> 51;
  q = (h.v[1] + q) >> 51;
  q = (h.v[2] + q) >> 51;
  q = (h.v[3] + q) >> 51;
  q = (h.v[4] + q) >> 51;
  h.v[0] += 19 * q;
  uint64_t c;
  c = h.v[0] >> 51; h.v[0] &= kMask51; h.v[1] += c;
  c = h.v[1] >> 51; h.v[1] &= kMask51; h.v[2] += c;
  c = h.v[2] >> 51; h.v[2] &= kMask51; h.v[3] += c;
  c = h.v[3] >> 51; h.v[3] &= kMask51; h.v[4] += c;
  h.v[4] &= kMask51;
  const uint64_t words[4] = {
      h.v[0] | (h.v[1] << 51),
      (h.v[1] >> 13) | (h.v[2] << 38),
      (h.v[2] >> 26) | (h.v[3] << 25),
      (h.v[3] >> 39) | (h.v[4] << 12),
  };
  for (unsigned i = 0; i < 4; ++i)
    for (unsigned j = 0; j < 8; ++j) out[i * 8 + j] = uint8_t(words[i] >> (8 * j));
}

}  // namespace

void X25519(std::span<uint8_t, 32> output, std::span<const uint8_t, 32> scalar,
            std::span<const uint8_t, 32> point) noexcept {
  uint8_t k[32];
  std::memcpy(k, scalar.data(), 32);
  k[0] &= 248;
  k[31] &= 127;
  k[31] |= 64;

  const Fe x1 = FromBytes(point);
  Fe x2 = {{1, 0, 0, 0, 0}}, z2 = {{0, 0, 0, 0, 0}};
  Fe x3 = x1, z3 = {{1, 0, 0, 0, 0}};
  uint64_t swap = 0;
  for (int t = 254; t >= 0; --t) {
    const uint64_t kt = (k[t >> 3] >> (t & 7)) & 1;
    swap ^= kt;
    Swap(swap, x2, x3);
    Swap(swap, z2, z3);
    swap = kt;
    const Fe a = Add(x2, z2);
    const Fe aa = Square(a);
    const Fe b = Sub(x2, z2);
    const Fe bb = Square(b);
    const Fe e = Sub(aa, bb);
    const Fe c = Add(x3, z3);
    const Fe d = Sub(x3, z3);
    const Fe da = Mul(d, a);
    const Fe cb = Mul(c, b);
    x3 = Square(Add(da, cb));
    z3 = Mul(x1, Square(Sub(da, cb)));
    x2 = Mul(aa, bb);
    z2 = Mul(e, Add(aa, MulSmall(e, 121665)));
  }
  Swap(swap, x2, x3);
  Swap(swap, z2, z3);
  ToBytes(output, Mul(x2, Invert(z2)));
  Cleanse(k, sizeof(k));
}

void X25519BasePoint(std::span<uint8_t, 32> output, std::span<const uint8_t, 32> scalar) noexcept {
  std::array<uint8_t, 32> base{};
  base[0] = 9;
  X25519(output, scalar, base);
}

bool ConstantTimeEqual(const uint8_t* left, const uint8_t* right, size_t size) noexcept {
  const volatile uint8_t* a = left;
  const volatile uint8_t* b = right;
  uint8_t difference = 0;
  for (size_t i = 0; i < size; ++i) difference |= uint8_t(a[i] ^ b[i]);
  return difference == 0;
}

void Cleanse(void* data, size_t size) noexcept {
  if (!data || !size) return;
  volatile auto* bytes = static_cast<volatile uint8_t*>(data);
  while (size--) *bytes++ = 0;
}

}  // namespace rex::system::xam::portable_crypto
