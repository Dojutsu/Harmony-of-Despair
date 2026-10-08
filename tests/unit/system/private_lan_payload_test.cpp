#include <rex/system/xam/private_lan_payload.h>
#include <rex/platform.h>
#include <algorithm>
#include <array>
#include <chrono>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#if REX_PLATFORM_GNU_LINUX
#include <fcntl.h>
#include <unistd.h>
#endif
#ifndef FSC_PRIVATE_LAN_STANDALONE
#include <catch2/catch_test_macros.hpp>
#endif
using namespace rex::system::xam;
namespace {
size_t checks = 0;
void Check(bool success, const char* message) {
  ++checks; if (!success) throw std::runtime_error(message);
}
#if REX_PLATFORM_GNU_LINUX
struct InvitationFiles {
  std::filesystem::path directory;
  std::shared_ptr<const PrivateLanInvitation> host, client, other;
  InvitationFiles() {
    std::array<char,128> path{}; std::strcpy(path.data(), "/tmp/fsc-private-lan-payload-XXXXXX");
    const auto created = mkdtemp(path.data()); Check(created != nullptr, "private payload fixture directory");
    directory = created;
    const auto expiry = uint64_t(std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()).count()) + 3600;
    auto write = [&](const char* name, bool hosted, uint8_t client) {
      const size_t count = hosted ? 2 : 1;
      std::vector<uint8_t> bytes(24 + count * 56);
      std::memcpy(bytes.data(), "HPLI", 4); bytes[4] = 1; bytes[5] = hosted ? 0 : 1; bytes[6] = count;
      bytes[15] = 1;
      for (unsigned i=0;i<8;++i) bytes[16+i] = uint8_t(expiry >> (56-i*8));
      for (size_t i=0;i<count;++i) {
        const uint8_t member = hosted ? uint8_t(i + 2) : client;
        bytes[31+i*56] = member;
        for (size_t j=0;j<16;++j) bytes[32+i*56+j] = uint8_t(j + member * 37);
        for (size_t j=0;j<32;++j) bytes[48+i*56+j] = uint8_t(j * 3 + member * 41);
      }
      const auto file = directory / name;
      const int descriptor = ::open(file.c_str(), O_WRONLY | O_CREAT | O_EXCL | O_CLOEXEC, 0600);
      Check(descriptor >= 0 && ::write(descriptor, bytes.data(), bytes.size()) == ssize_t(bytes.size()),
            "private payload invitation fixture write");
      ::close(descriptor);
      auto loaded = PrivateLanInvitation::Load(file.string()); Check(bool(loaded), "private payload grant load");
      return loaded;
    };
    host=write("host",true,0); client=write("client",false,2); other=write("other",false,3);
  }
  ~InvitationFiles() { std::error_code error; std::filesystem::remove_all(directory,error); }
};
void Run() {
  checks=0;
  InvitationFiles invitations;
  auto key=NewArbitrationKey(), other_key=NewArbitrationKey();
  Check(bool(key)&&bool(other_key),"actual X25519 key generation");
  std::vector<uint8_t> aad(1024), plaintext(kMaximumArbitrationPayload);
  for(size_t i=0;i<aad.size();++i)aad[i]=uint8_t(i*73+29);
  for(size_t i=0;i<plaintext.size();++i)plaintext[i]=uint8_t(i*37+11);
  for(size_t length : {size_t(1),size_t(15),size_t(16),size_t(17),size_t(255),size_t(256),size_t(744),size_t(768)}) {
    const auto expected=std::span(plaintext).first(length);
    auto sealed=SealPrivateLanPayload(*invitations.host,2,key->public_key(),expected,aad);
    Check(bool(sealed),"bounded authenticated ticket seals");
    auto opened=OpenPrivateLanPayload(*invitations.client,2,*key,*sealed,aad);
    Check(bool(opened)&&std::equal(opened->bytes().begin(),opened->bytes().end(),expected.begin(),expected.end()),
          "authenticated ticket roundtrips exact plaintext");
    auto moved=std::move(*opened);
    Check(opened->bytes().empty()&&moved.bytes().size()==length,"sensitive plaintext has exclusive move ownership");
    Check(!OpenPrivateLanPayload(*invitations.other,3,*key,*sealed,aad),"another invited client cannot decrypt ticket");
    Check(!OpenPrivateLanPayload(*invitations.client,3,*key,*sealed,aad),"wrong client identity fails closed");
    Check(!OpenPrivateLanPayload(*invitations.client,2,*other_key,*sealed,aad),"recipient ephemeral key substitution rejected");
  }
  auto sealed=SealPrivateLanPayload(*invitations.host,2,key->public_key(),plaintext,aad);
  Check(bool(sealed),"maximum ticket fixture");
  for(size_t i=0;i<aad.size();++i) {
    aad[i]^=1;
    Check(!OpenPrivateLanPayload(*invitations.client,2,*key,*sealed,aad),"session/request/roster AAD mutation rejected");
    aad[i]^=1;
  }
  for(size_t i=0;i<sealed->payload.ciphertext.size();++i) {
    sealed->payload.ciphertext[i]^=1;
    Check(!OpenPrivateLanPayload(*invitations.client,2,*key,*sealed,aad),"ticket ciphertext tampering rejected");
    sealed->payload.ciphertext[i]^=1;
  }
  for(auto* field : {&sealed->payload.server_public_key})
    for(auto& byte:*field) { byte^=1; Check(!OpenPrivateLanPayload(*invitations.client,2,*key,*sealed,aad),
                                          "server key mutation rejected"); byte^=1; }
  for(auto& byte:sealed->payload.iv) { byte^=1; Check(!OpenPrivateLanPayload(*invitations.client,2,*key,*sealed,aad),
                                                    "ticket IV tampering rejected"); byte^=1; }
  for(auto& byte:sealed->payload.tag) { byte^=1; Check(!OpenPrivateLanPayload(*invitations.client,2,*key,*sealed,aad),
                                                     "ticket AEAD tag tampering rejected"); byte^=1; }
  for(auto& byte:sealed->invitation_proof) { byte^=1; Check(!OpenPrivateLanPayload(*invitations.client,2,*key,*sealed,aad),
                                                         "invitation proof tampering rejected"); byte^=1; }
  auto changed=*sealed; changed.payload.ciphertext.pop_back();
  Check(!OpenPrivateLanPayload(*invitations.client,2,*key,changed,aad),"ticket truncation rejected");
  changed=*sealed; changed.payload.ciphertext.push_back(1);
  Check(!OpenPrivateLanPayload(*invitations.client,2,*key,changed,aad),"oversized ticket rejected");
  Check(!SealPrivateLanPayload(*invitations.client,2,key->public_key(),plaintext,aad),"client grant cannot act as hosted authority");
  Check(!SealPrivateLanPayload(*invitations.host,4,key->public_key(),plaintext,aad),"uninvited client has no ticket");
  Check(!OpenPrivateLanPayload(*invitations.host,2,*key,*sealed,aad),"host grant is not accepted as client role");
  Check(!SealPrivateLanPayload(*invitations.host,2,key->public_key(),{},aad),"empty ticket refused");
  std::vector<uint8_t> excessive(769,1), excessive_aad(2049,1);
  Check(!SealPrivateLanPayload(*invitations.host,2,key->public_key(),excessive,aad),"ticket allocation bounded before sealing");
  Check(!SealPrivateLanPayload(*invitations.host,2,key->public_key(),plaintext,excessive_aad),"outer AAD length bound");
  // A real on-path attacker can construct a valid unauthenticated X25519/GCM
  // envelope for the public client key. The invitation wrapper must reject it.
  auto fake=SealArbitrationPayload(key->public_key(),plaintext,aad);
  Check(bool(fake),"actual substituted envelope constructed by nonholder");
  auto unauthenticated=OpenArbitrationPayload(*key,*fake,aad);
  Check(bool(unauthenticated),"unauthenticated envelope alone does not prove host identity");
  PrivateLanPayloadEnvelope attack{std::move(*fake),sealed->invitation_proof};
  Check(!OpenPrivateLanPayload(*invitations.client,2,*key,attack,aad),"actual server/envelope MITM substitution blocked");
  // The original credential envelope remains a separate cryptographic domain.
  ArbitrationToken credential{}; credential[0]=17; credential[15]=29;
  auto original=SealArbitrationCredential(key->public_key(),credential,aad);
  Check(bool(original),"existing credential envelope still seals");
  auto continuity=OpenArbitrationCredential(*key,*original,aad);
  Check(continuity&&*continuity==credential,"existing credential envelope roundtrips unchanged");
  ArbitrationPayloadEnvelope cross{original->server_public_key,original->iv,
                                   std::vector<uint8_t>(original->ciphertext.begin(),original->ciphertext.end()),original->tag};
  Check(!OpenArbitrationPayload(*key,cross,aad),"credential envelope cannot cross into private ticket domain");
  std::cout<<checks<<" authenticated private ticket envelope checks passed\n";
}
#endif
}  // namespace
#ifdef FSC_PRIVATE_LAN_STANDALONE
int main() { try { Run();return 0; }catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;} }
#else
TEST_CASE("Private LAN ticket envelopes require possession proofs before accepting ephemeral servers", "[network][security]") {
#if REX_PLATFORM_GNU_LINUX
  REQUIRE_NOTHROW(Run());
#endif
}
#endif
