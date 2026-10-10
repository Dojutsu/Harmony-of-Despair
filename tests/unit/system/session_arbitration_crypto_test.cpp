// Actual provider primitives; no sockets, exported private keys, or transcript logs.
#include <catch2/catch_test_macros.hpp>
#include <rex/platform.h>
#include <rex/system/xam/session_arbitration_crypto.h>
#include <algorithm>
#include <array>
#include <type_traits>
#include <utility>
#include <vector>
namespace {
using namespace rex::system::xam;
ArbitrationToken Credential() { ArbitrationToken token{}; token.fill(0x37); return token; }
std::array<uint8_t, 24> Aad() {
  std::array<uint8_t, 24> aad{};
  for(size_t i=0;i<aad.size();++i)aad[i]=static_cast<uint8_t>(i+1);
  return aad;
}
template<class T> bool HasNonzero(const T& bytes) {
  return std::any_of(bytes.begin(),bytes.end(),[](uint8_t value){return value!=0;});
}
bool EqualCredential(const std::optional<ArbitrationToken>& decoded,const ArbitrationToken& expected) {
  return decoded && std::equal(decoded->begin(),decoded->end(),expected.begin());
}
static_assert(!std::is_copy_constructible_v<EphemeralArbitrationKey>);
static_assert(!std::is_copy_assignable_v<EphemeralArbitrationKey>);
static_assert(std::is_nothrow_move_constructible_v<EphemeralArbitrationKey>);
static_assert(std::is_nothrow_move_assignable_v<EphemeralArbitrationKey>);
} // namespace
#if REX_PLATFORM_GNU_LINUX || REX_PLATFORM_WIN32
TEST_CASE("Arbitration credential envelope roundtrips through actual X25519 and AES256GCM",
          "[session][arbitration][crypto]") {
  const auto token=Credential();const auto aad=Aad();auto client=NewArbitrationKey();
  REQUIRE(client);REQUIRE(client->valid());CHECK(HasNonzero(client->public_key()));
  const auto first=SealArbitrationCredential(client->public_key(),token,aad);
  REQUIRE(first);CHECK(HasNonzero(first->server_public_key));CHECK(HasNonzero(first->iv));
  CHECK(HasNonzero(first->ciphertext));CHECK(HasNonzero(first->tag));
  CHECK(EqualCredential(OpenArbitrationCredential(*client,*first,aad),token));
  const auto second=SealArbitrationCredential(client->public_key(),token,aad);
  REQUIRE(second);CHECK(EqualCredential(OpenArbitrationCredential(*client,*second,aad),token));
  CHECK_FALSE(std::equal(first->server_public_key.begin(),first->server_public_key.end(),second->server_public_key.begin()));
  CHECK_FALSE(std::equal(first->iv.begin(),first->iv.end(),second->iv.begin()));
  CHECK_FALSE(std::equal(first->ciphertext.begin(),first->ciphertext.end(),second->ciphertext.begin()));
  // Opening a second fresh reply does not consume or change the first reply/key.
  CHECK(EqualCredential(OpenArbitrationCredential(*client,*first,aad),token));
}
TEST_CASE("Arbitration envelope rejects changed payload metadata and wrong client key",
          "[session][arbitration][crypto]") {
  const auto token=Credential();const auto aad=Aad();auto client=NewArbitrationKey();
  REQUIRE(client);const auto original=SealArbitrationCredential(client->public_key(),token,aad);
  REQUIRE(original);auto other=NewArbitrationKey();REQUIRE(other);
  CHECK_FALSE(OpenArbitrationCredential(*other,*original,aad));
  auto changed_aad=aad;changed_aad[0]^=1;
  CHECK_FALSE(OpenArbitrationCredential(*client,*original,changed_aad));
  CHECK_FALSE(OpenArbitrationCredential(*client,*original,std::span<const uint8_t>(aad).first(aad.size()-1)));
  for(size_t i=0;i<original->ciphertext.size();++i){
    auto modified=*original;modified.ciphertext[i]^=1;
    CHECK_FALSE(OpenArbitrationCredential(*client,modified,aad));
  }
  for(size_t i=0;i<original->tag.size();++i){
    auto modified=*original;modified.tag[i]^=1;
    CHECK_FALSE(OpenArbitrationCredential(*client,modified,aad));
  }
  for(size_t i=0;i<original->iv.size();++i){
    auto modified=*original;modified.iv[i]^=1;
    CHECK_FALSE(OpenArbitrationCredential(*client,modified,aad));
  }
  for(size_t i=0;i<original->server_public_key.size();++i){
    auto modified=*original;modified.server_public_key[i]^=1;
    CHECK_FALSE(OpenArbitrationCredential(*client,modified,aad));
  }
  CHECK(EqualCredential(OpenArbitrationCredential(*client,*original,aad),token));
}
TEST_CASE("Arbitration KDF binds raw public key encodings including X25519 top bit aliases",
          "[session][arbitration][crypto]") {
  auto client=NewArbitrationKey();REQUIRE(client);
  const auto aad=Aad();const auto token=Credential();
  const auto envelope=SealArbitrationCredential(client->public_key(),token,aad);REQUIRE(envelope);
  auto server_alias=*envelope;server_alias.server_public_key[31]^=0x80;
  CHECK_FALSE(OpenArbitrationCredential(*client,server_alias,aad));
  auto client_alias=client->public_key();client_alias[31]^=0x80;
  const auto aliased_response=SealArbitrationCredential(client_alias,token,aad);REQUIRE(aliased_response);
  // X25519 derives the same curve-point secret for the alias, but the response
  // is bound to its exact requested raw client public key encoding.
  CHECK_FALSE(OpenArbitrationCredential(*client,*aliased_response,aad));
  CHECK(EqualCredential(OpenArbitrationCredential(*client,*envelope,aad),token));
}
TEST_CASE("Arbitration envelope validates transcript bounds and nonzero fields",
          "[session][arbitration][crypto]") {
  auto client=NewArbitrationKey();REQUIRE(client);const auto token=Credential();const auto aad=Aad();
  const auto envelope=SealArbitrationCredential(client->public_key(),token,aad);REQUIRE(envelope);
  CHECK_FALSE(SealArbitrationCredential({},token,aad));
  CHECK_FALSE(SealArbitrationCredential(client->public_key(),{},aad));
  CHECK_FALSE(SealArbitrationCredential(client->public_key(),token,{}));
  CHECK_FALSE(OpenArbitrationCredential(*client,*envelope,{}));
  std::vector<uint8_t> zero(24,0);
  CHECK_FALSE(SealArbitrationCredential(client->public_key(),token,zero));
  CHECK_FALSE(OpenArbitrationCredential(*client,*envelope,zero));
  std::vector<uint8_t> maximum(kMaximumArbitrationAAD,0x5a);
  const auto full=SealArbitrationCredential(client->public_key(),token,maximum);REQUIRE(full);
  CHECK(EqualCredential(OpenArbitrationCredential(*client,*full,maximum),token));
  maximum.push_back(0x5a);
  CHECK_FALSE(SealArbitrationCredential(client->public_key(),token,maximum));
  CHECK_FALSE(OpenArbitrationCredential(*client,*full,maximum));
  auto modified=*envelope;modified.server_public_key={};CHECK_FALSE(OpenArbitrationCredential(*client,modified,aad));
  modified=*envelope;modified.iv={};CHECK_FALSE(OpenArbitrationCredential(*client,modified,aad));
  modified=*envelope;modified.ciphertext={};CHECK_FALSE(OpenArbitrationCredential(*client,modified,aad));
  modified=*envelope;modified.tag={};CHECK_FALSE(OpenArbitrationCredential(*client,modified,aad));
}
TEST_CASE("Arbitration provider rejects low order peers and invalid or moved key ownership",
          "[session][arbitration][crypto]") {
  const auto token=Credential();const auto aad=Aad();ArbitrationPublicKey low_order{};low_order[0]=1;
  CHECK_FALSE(SealArbitrationCredential(low_order,token,aad));
  auto client=NewArbitrationKey();REQUIRE(client);
  const auto public_key=client->public_key();
  const auto envelope=SealArbitrationCredential(public_key,token,aad);REQUIRE(envelope);
  auto modified=*envelope;modified.server_public_key=low_order;
  CHECK_FALSE(OpenArbitrationCredential(*client,modified,aad));
  EphemeralArbitrationKey invalid;CHECK_FALSE(invalid.valid());CHECK_FALSE(HasNonzero(invalid.public_key()));
  CHECK_FALSE(OpenArbitrationCredential(invalid,*envelope,aad));
  EphemeralArbitrationKey moved(std::move(*client));
  CHECK(moved.valid());CHECK_FALSE(client->valid());CHECK_FALSE(HasNonzero(client->public_key()));
  CHECK(std::equal(moved.public_key().begin(),moved.public_key().end(),public_key.begin()));
  CHECK(EqualCredential(OpenArbitrationCredential(moved,*envelope,aad),token));
  CHECK_FALSE(OpenArbitrationCredential(*client,*envelope,aad));
  auto replacement=NewArbitrationKey();REQUIRE(replacement);
  EphemeralArbitrationKey assigned(std::move(*replacement));REQUIRE(assigned.valid());
  assigned=std::move(moved);
  CHECK(assigned.valid());CHECK_FALSE(moved.valid());
  CHECK(EqualCredential(OpenArbitrationCredential(assigned,*envelope,aad),token));
}
#else
TEST_CASE("Arbitration credential envelopes explicitly report unsupported provider",
          "[session][arbitration][crypto]") {
  CHECK_FALSE(NewArbitrationKey());EphemeralArbitrationKey key;
  CHECK_FALSE(key.valid());CHECK_FALSE(HasNonzero(key.public_key()));
  CHECK_FALSE(SealArbitrationCredential({},Credential(),Aad()));
  CHECK_FALSE(OpenArbitrationCredential(key,{},Aad()));
}
#endif
