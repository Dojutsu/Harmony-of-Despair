// Host-side check of portable_crypto against OpenSSL. Build and run:
//   g++ -std=c++20 -O1 -I src/system/xam tools/portable_crypto_check.cpp src/system/xam/portable_crypto.cpp -lcrypto -o /tmp/pcc
#include "portable_crypto.h"

#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <openssl/kdf.h>
#include <openssl/rand.h>

#include <algorithm>
#include <array>
#include <cstdio>
#include <cstring>
#include <vector>

namespace pc = rex::system::xam::portable_crypto;
static int failures = 0;
static void Check(bool ok, const char* what, int iteration) {
  if (!ok) {
    ++failures;
    std::printf("FAIL %s (iteration %d)\n", what, iteration);
  }
}
static std::vector<uint8_t> RandomBytes(size_t size) {
  std::vector<uint8_t> out(size);
  if (size) RAND_bytes(out.data(), int(size));
  return out;
}
static bool Hex(const char* hex, std::vector<uint8_t>& out) {
  out.clear();
  for (size_t i = 0; hex[i] && hex[i + 1]; i += 2) {
    unsigned v;
    if (std::sscanf(hex + i, "%2x", &v) != 1) return false;
    out.push_back(uint8_t(v));
  }
  return true;
}

int main() {
  // Known answers first.
  {
    std::array<uint8_t, 32> d{};
    const char* abc = "abc";
    pc::Sha256Digest({pc::Bytes(reinterpret_cast<const uint8_t*>(abc), 3)}, d);
    std::vector<uint8_t> want;
    Hex("ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad", want);
    Check(std::equal(d.begin(), d.end(), want.begin()), "sha256(abc)", 0);
  }
  {
    std::vector<uint8_t> k, u, want;
    Hex("a546e36bf0527c9d3b16154b82465edd62144c0ac1fc5a18506a2244ba449ac4", k);
    Hex("e6db6867583030db3594c1a424b15f7c726624ec26b3353b10a903a6d0ab1c4c", u);
    Hex("c3da55379de9c6908e94ea4df28d084f32eccf03491c71f754b4075577a28552", want);
    std::array<uint8_t, 32> out{};
    pc::X25519(out, std::span<const uint8_t, 32>(k.data(), 32), std::span<const uint8_t, 32>(u.data(), 32));
    Check(std::equal(out.begin(), out.end(), want.begin()), "x25519 rfc7748 vector 1", 0);
  }
  {
    std::vector<uint8_t> key(32, 0), want_c, want_t;
    std::array<uint8_t, 12> iv{};
    std::array<uint8_t, 16> tag{};
    std::vector<uint8_t> pt(16, 0), ct(16);
    pc::AesGcmSeal(std::span<const uint8_t, 32>(key.data(), 32), iv, {}, pt, ct.data(), tag);
    Hex("cea7403d4d606b6e074ec5d3baf39d18", want_c);
    Hex("d0d1c8a799996bf0265b98b5d48ab919", want_t);
    Check(ct == want_c, "gcm test case 14 ciphertext", 0);
    Check(std::equal(tag.begin(), tag.end(), want_t.begin()), "gcm test case 14 tag", 0);
  }

  for (int it = 0; it < 400; ++it) {
    const size_t n1 = it % 7 == 0 ? 0 : size_t(it * 37 % 300);
    const size_t n2 = size_t(it * 11 % 90);
    auto a = RandomBytes(n1), b = RandomBytes(n2), key = RandomBytes(1 + it % 100);

    // SHA-256
    {
      std::array<uint8_t, 32> mine{}, ref{};
      pc::Sha256Digest({a, b}, mine);
      std::vector<uint8_t> joined(a);
      joined.insert(joined.end(), b.begin(), b.end());
      unsigned len = 0;
      const uint8_t empty = 0;
      EVP_Digest(joined.empty() ? &empty : joined.data(), joined.size(), ref.data(), &len,
                 EVP_sha256(), nullptr);
      Check(mine == ref, "sha256", it);
    }
    // HMAC
    {
      std::array<uint8_t, 32> mine{}, ref{};
      pc::HmacSha256(key, {a, b}, mine);
      std::vector<uint8_t> joined(a);
      joined.insert(joined.end(), b.begin(), b.end());
      unsigned len = 0;
      const uint8_t empty = 0;
      HMAC(EVP_sha256(), key.data(), int(key.size()), joined.empty() ? &empty : joined.data(),
           joined.size(), ref.data(), &len);
      Check(mine == ref, "hmac", it);
    }
    // HKDF
    {
      auto salt = RandomBytes(it % 3 == 0 ? 0 : 16);
      const size_t out_len = 1 + size_t(it * 13 % 100);
      std::vector<uint8_t> mine(out_len), ref(out_len);
      Check(pc::HkdfSha256(salt, key, {a, b}, mine), "hkdf ok", it);
      // RFC 5869 by hand over OpenSSL's HMAC (OpenSSL 3's HKDF context does
      // not accept the info in pieces the way this harness feeds it).
      std::vector<uint8_t> info(a);
      info.insert(info.end(), b.begin(), b.end());
      const uint8_t zero_salt[32] = {};
      std::array<uint8_t, 32> prk{};
      unsigned len = 0;
      HMAC(EVP_sha256(), salt.empty() ? zero_salt : salt.data(), salt.empty() ? 32 : int(salt.size()),
           key.data(), key.size(), prk.data(), &len);
      std::vector<uint8_t> block;
      for (uint8_t counter = 1; ref.size() > size_t(counter - 1) * 32; ++counter) {
        std::vector<uint8_t> msg(block);
        msg.insert(msg.end(), info.begin(), info.end());
        msg.push_back(counter);
        std::array<uint8_t, 32> t{};
        HMAC(EVP_sha256(), prk.data(), 32, msg.data(), msg.size(), t.data(), &len);
        block.assign(t.begin(), t.end());
        const size_t off = size_t(counter - 1) * 32;
        std::copy_n(block.begin(), std::min<size_t>(32, ref.size() - off), ref.begin() + off);
      }
      Check(mine == ref, "hkdf", it);
    }
    // AES-256-GCM
    {
      auto k = RandomBytes(32), iv = RandomBytes(12);
      std::span<const uint8_t, 32> ks(k.data(), 32);
      std::span<const uint8_t, 12> ivs(iv.data(), 12);
      std::vector<uint8_t> ct(a.size()), ref_ct(a.size());
      std::array<uint8_t, 16> tag{}, ref_tag{};
      pc::AesGcmSeal(ks, ivs, b, a, ct.data(), tag);
      EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
      int len = 0;
      EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), nullptr, nullptr, nullptr);
      EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, 12, nullptr);
      EVP_EncryptInit_ex(ctx, nullptr, nullptr, k.data(), iv.data());
      if (!b.empty()) EVP_EncryptUpdate(ctx, nullptr, &len, b.data(), int(b.size()));
      if (!a.empty()) EVP_EncryptUpdate(ctx, ref_ct.data(), &len, a.data(), int(a.size()));
      EVP_EncryptFinal_ex(ctx, ref_ct.data() + a.size(), &len);
      EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, 16, ref_tag.data());
      EVP_CIPHER_CTX_free(ctx);
      Check(ct == ref_ct, "gcm ciphertext", it);
      Check(tag == ref_tag, "gcm tag", it);
      std::vector<uint8_t> pt(a.size());
      Check(pc::AesGcmOpen(ks, ivs, b, ct, tag, pt.data()), "gcm open", it);
      Check(pt == a, "gcm roundtrip", it);
      if (!ct.empty()) {
        ct[0] ^= 1;
        Check(!pc::AesGcmOpen(ks, ivs, b, ct, tag, pt.data()), "gcm reject tamper", it);
      }
      auto bad_tag = tag;
      bad_tag[15] ^= 0x80;
      Check(!pc::AesGcmOpen(ks, ivs, b, ref_ct, bad_tag, pt.data()), "gcm reject tag", it);
    }
    // X25519
    {
      auto sk = RandomBytes(32);
      EVP_PKEY* ref_key = EVP_PKEY_new_raw_private_key(EVP_PKEY_X25519, nullptr, sk.data(), 32);
      std::array<uint8_t, 32> ref_pub{};
      size_t pub_len = 32;
      EVP_PKEY_get_raw_public_key(ref_key, ref_pub.data(), &pub_len);
      std::array<uint8_t, 32> mine_pub{};
      pc::X25519BasePoint(mine_pub, std::span<const uint8_t, 32>(sk.data(), 32));
      Check(mine_pub == ref_pub, "x25519 public", it);

      auto peer_sk = RandomBytes(32);
      EVP_PKEY* peer_key = EVP_PKEY_new_raw_private_key(EVP_PKEY_X25519, nullptr, peer_sk.data(), 32);
      std::array<uint8_t, 32> peer_pub{};
      pub_len = 32;
      EVP_PKEY_get_raw_public_key(peer_key, peer_pub.data(), &pub_len);
      // Occasionally set the top bit of the peer key to check masking.
      if (it % 5 == 0) peer_pub[31] |= 0x80;
      std::array<uint8_t, 32> mine_shared{}, ref_shared{};
      pc::X25519(mine_shared, std::span<const uint8_t, 32>(sk.data(), 32), peer_pub);
      EVP_PKEY* peer_pub_key = EVP_PKEY_new_raw_public_key(EVP_PKEY_X25519, nullptr, peer_pub.data(), 32);
      EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(ref_key, nullptr);
      EVP_PKEY_derive_init(ctx);
      EVP_PKEY_derive_set_peer(ctx, peer_pub_key);
      size_t shared_len = 32;
      EVP_PKEY_derive(ctx, ref_shared.data(), &shared_len);
      EVP_PKEY_CTX_free(ctx);
      EVP_PKEY_free(peer_pub_key);
      EVP_PKEY_free(peer_key);
      EVP_PKEY_free(ref_key);
      Check(mine_shared == ref_shared, "x25519 shared", it);
    }
  }
  std::printf(failures ? "FAILURES: %d\n" : "all checks passed\n", failures);
  return failures ? 1 : 0;
}
