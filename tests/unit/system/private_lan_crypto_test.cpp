// Published known-answer vectors for the private LAN crypto layer. The same
// expectations hold for OpenSSL (Linux) and CNG (Windows) providers.
#include <catch2/catch_test_macros.hpp>
#include <rex/platform.h>
#include <system/xam/private_lan_crypto.h>
#include <array>
#include <string>
#include <string_view>
#include <vector>
#if REX_PLATFORM_GNU_LINUX || REX_PLATFORM_WIN32
namespace {
namespace crypto = rex::system::xam::lan_crypto;
std::vector<uint8_t> Hex(std::string_view text) {
  std::vector<uint8_t> bytes;
  for (size_t i = 0; i + 1 < text.size(); i += 2) bytes.push_back(uint8_t(std::stoi(std::string(text.substr(i, 2)), nullptr, 16)));
  return bytes;
}
std::vector<uint8_t> Text(std::string_view text) { return {text.begin(), text.end()}; }
template <class T> std::vector<uint8_t> Vector(const T& bytes) { return {bytes.begin(), bytes.end()}; }
}  // namespace

TEST_CASE("Private LAN SHA-256 and HMAC-SHA256 match published vectors", "[private-lan][crypto]") {
  REQUIRE(crypto::Available());
  std::array<uint8_t, 32> digest{};
  const auto abc = Text("abc");
  REQUIRE(crypto::Sha256({abc}, digest));
  CHECK(Vector(digest) == Hex("ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad"));
  // Split input must hash identically to contiguous input.
  const auto a = Text("a"), bc = Text("bc");
  REQUIRE(crypto::Sha256({a, {}, bc}, digest));
  CHECK(Vector(digest) == Hex("ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad"));
  // RFC 4231 test case 2.
  const auto key = Text("Jefe"), data = Text("what do ya want for nothing?");
  REQUIRE(crypto::HmacSha256(key, {data}, digest));
  CHECK(Vector(digest) == Hex("5bdcc146bf60754e6a042426089575c75a003f089d2739839dec58b964ec3843"));
  CHECK_FALSE(crypto::HmacSha256({}, {data}, digest));
}

TEST_CASE("Private LAN HKDF-SHA256 matches RFC 5869 test case 1", "[private-lan][crypto]") {
  const auto ikm = Hex("0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b");
  const auto salt = Hex("000102030405060708090a0b0c");
  const auto info = Hex("f0f1f2f3f4f5f6f7f8f9");
  const auto expected = Hex(
      "3cb25f25faacd57a90434f64d0362f2a2d2d0a90cf1a5a4c5db02d56ecc4c5bf34007208d5b887185865");
  std::vector<uint8_t> okm(42);
  REQUIRE(crypto::HkdfSha256(salt, ikm, {info}, okm));
  CHECK(okm == expected);
  // Info supplied in parts is concatenated.
  const auto first = Hex("f0f1f2"), rest = Hex("f3f4f5f6f7f8f9");
  std::vector<uint8_t> split(42);
  REQUIRE(crypto::HkdfSha256(salt, ikm, {first, rest}, split));
  CHECK(split == expected);
}

TEST_CASE("Private LAN AES-256-GCM matches GCM specification vectors", "[private-lan][crypto]") {
  const std::array<uint8_t, 32> key{};
  const std::array<uint8_t, 12> iv{};
  std::array<uint8_t, 16> tag{};
  // Test case 13: empty plaintext and AAD.
  REQUIRE(crypto::AesGcmSeal(key, iv, {}, {}, nullptr, tag));
  CHECK(Vector(tag) == Hex("530f8afbc74536b9a963b4f1c4cb738b"));
  // Test case 14: one zero block.
  const std::array<uint8_t, 16> zero{};
  std::array<uint8_t, 16> ciphertext{};
  REQUIRE(crypto::AesGcmSeal(key, iv, {}, zero, ciphertext.data(), tag));
  CHECK(Vector(ciphertext) == Hex("cea7403d4d606b6e074ec5d3baf39d18"));
  CHECK(Vector(tag) == Hex("d0d1c8a799996bf0265b98b5d48ab919"));
  std::array<uint8_t, 16> opened{};
  opened.fill(0xaa);
  REQUIRE(crypto::AesGcmOpen(key, iv, {}, ciphertext, tag, opened.data()));
  CHECK(opened == zero);
  // AAD and tag are authenticated.
  const auto aad = Text("header");
  REQUIRE(crypto::AesGcmSeal(key, iv, aad, zero, ciphertext.data(), tag));
  CHECK(crypto::AesGcmOpen(key, iv, aad, ciphertext, tag, opened.data()));
  CHECK_FALSE(crypto::AesGcmOpen(key, iv, {}, ciphertext, tag, opened.data()));
  auto bad = tag;
  bad[0] ^= 1;
  CHECK_FALSE(crypto::AesGcmOpen(key, iv, aad, ciphertext, bad, opened.data()));
}

TEST_CASE("Private LAN X25519 keys agree and reject invalid peers", "[private-lan][crypto]") {
  auto first = crypto::X25519Key::Generate();
  auto second = crypto::X25519Key::Generate();
  REQUIRE(first);
  REQUIRE(second);
  CHECK(first->public_key() != second->public_key());
  std::array<uint8_t, 32> left{}, right{};
  REQUIRE(first->Agree(second->public_key(), left));
  REQUIRE(second->Agree(first->public_key(), right));
  CHECK(left == right);
  CHECK(left != std::array<uint8_t, 32>{});
  CHECK_FALSE(first->Agree(std::array<uint8_t, 32>{}, left));
  crypto::X25519Key empty;
  CHECK_FALSE(empty.valid());
  CHECK_FALSE(empty.Agree(second->public_key(), left));
}

TEST_CASE("Private LAN constant-time equality and random output", "[private-lan][crypto]") {
  const std::array<uint8_t, 4> a{1, 2, 3, 4}, b{1, 2, 3, 4}, c{1, 2, 3, 5};
  CHECK(crypto::Equal(a.data(), b.data(), a.size()));
  CHECK_FALSE(crypto::Equal(a.data(), c.data(), a.size()));
  std::array<uint8_t, 32> first{}, second{};
  REQUIRE(crypto::Random(first));
  REQUIRE(crypto::Random(second));
  CHECK(first != second);
}
#endif
