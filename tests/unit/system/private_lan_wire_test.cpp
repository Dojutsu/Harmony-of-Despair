#include <rex/system/xam/private_lan_discovery_wire.h>
#include <rex/platform.h>
#include <algorithm>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#if REX_PLATFORM_GNU_LINUX
#include <fcntl.h>
#include <unistd.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>
#endif
#ifndef FSC_PRIVATE_LAN_STANDALONE
#include <catch2/catch_test_macros.hpp>
#endif
using namespace rex::system::xam;
namespace {
size_t checks=0;
void Check(bool result,const char* reason){++checks;if(!result)throw std::runtime_error(reason);}
#if REX_PLATFORM_GNU_LINUX
struct GrantFiles {
  uint64_t expiry=0;std::filesystem::path directory;std::shared_ptr<const PrivateLanInvitation> host,second,third;
  GrantFiles(){
    char name[]="/tmp/fsc-private-lan-wire-XXXXXX";const auto made=mkdtemp(name);Check(made,"wire fixture directory");directory=made;
    expiry=uint64_t(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count())+3600;
    auto write=[&](const char* file,bool hosted,uint8_t xuid){
      const size_t count=hosted?2:1;std::vector<uint8_t> bytes(24+count*56);std::memcpy(bytes.data(),"HPLI",4);
      bytes[4]=1;bytes[5]=hosted?0:1;bytes[6]=uint8_t(count);bytes[15]=1;
      for(unsigned i=0;i<8;++i)bytes[16+i]=uint8_t(expiry>>((7-i)*8));
      for(size_t i=0;i<count;++i){const auto client=hosted?uint8_t(i+2):xuid;bytes[31+i*56]=client;
        for(unsigned j=0;j<16;++j)bytes[32+i*56+j]=uint8_t(client*17+j);
        for(unsigned j=0;j<32;++j)bytes[48+i*56+j]=uint8_t(client*29+j*7);}
      const auto path=directory/file;const auto fd=::open(path.c_str(),O_WRONLY|O_CREAT|O_EXCL|O_CLOEXEC,0600);
      Check(fd>=0&&::write(fd,bytes.data(),bytes.size())==ssize_t(bytes.size()),"wire fixture private grants");::close(fd);
      auto grant=PrivateLanInvitation::Load(path.string());Check(bool(grant),"wire fixture loads");return grant;
    };
    host=write("host",true,0);second=write("second",false,2);third=write("third",false,3);
  }
  ~GrantFiles(){std::error_code error;std::filesystem::remove_all(directory,error);}
};
// Independent RFC 5869 extract and first expand block. Production uses the
// EVP HKDF provider; this reference uses only the underlying HMAC primitive.
std::array<uint8_t,32> ReferenceHkdf(std::span<const uint8_t> ikm,
    std::span<const uint8_t> salt,std::span<const uint8_t> info){
  std::array<uint8_t,32> prk{},output{};unsigned count=0;
  Check(HMAC(EVP_sha256(),salt.data(),int(salt.size()),ikm.data(),ikm.size(),prk.data(),&count)&&count==32,"reference HKDF extract");
  std::vector<uint8_t> block(info.begin(),info.end());block.push_back(1);
  Check(HMAC(EVP_sha256(),prk.data(),int(prk.size()),block.data(),block.size(),output.data(),&count)&&count==32,"reference HKDF expand");
  OPENSSL_cleanse(prk.data(),prk.size());return output;
}
void Run(){
  checks=0;GrantFiles files;
  // No production credential is used by this fixture.
  PrivateLanDiscoveryFrame request;auto& prefix=request.public_packet;
  prefix[0]='R';prefix[1]='E';prefix[2]='X';prefix[3]='L';prefix[5]=3;prefix[6]=3;
  constexpr uint32_t title=0x58410a7a;for(unsigned i=0;i<4;++i)prefix[8+i]=uint8_t(title>>((3-i)*8));
  std::memcpy(prefix.data()+68,"PrivateLobbyName",16);
  prefix[43]=1;prefix[67]=1;prefix[91]=2;prefix[624]=19;prefix[639]=1;
  auto key=NewArbitrationKey();Check(bool(key),"wire actual recipient key");
  std::copy(key->public_key().begin(),key->public_key().end(),prefix.begin()+532);
  request.join_claim_proof[0]=23;ArbitrationToken rpc{};std::copy_n(prefix.begin()+624,16,rpc.begin());
  auto encoded=SealPrivateLanDiscoveryFrame(*files.second,2,title,PrivateLanDiscoveryDirection::kRequest,request);
  Check(bool(encoded)&&encoded->size()==1440,"private frame stays below IPv4 MTU");
  auto opened=OpenPrivateLanDiscoveryFrame(*files.host,2,title,PrivateLanDiscoveryDirection::kRequest,*encoded);
  Check(std::search(encoded->begin(),encoded->end(),prefix.begin()+68,prefix.begin()+84)==encoded->end(),"private lobby name is opaque on LAN wire");
  auto automatic=OpenPrivateLanDiscoveryFrame(*files.host,0,title,PrivateLanDiscoveryDirection::kRequest,*encoded);
  Check(automatic&&automatic->public_packet==prefix,"host selects expected client using opaque grant selector");
  auto another_wire=SealPrivateLanDiscoveryFrame(*files.second,2,title,PrivateLanDiscoveryDirection::kRequest,request);
  Check(another_wire&&*another_wire!=*encoded,"each private frame uses a fresh random GCM nonce");
  auto request_key=files.host->DiscoveryKey(2,false),client_key=files.second->DiscoveryKey(2,false),reply_key=files.host->DiscoveryKey(2,true),third_key=files.host->DiscoveryKey(3,false);
  Check(request_key&&client_key&&reply_key&&third_key&&*request_key==*client_key&&*request_key!=*reply_key&&*request_key!=*third_key,"HKDF binds grant participant and distinct request/reply domains");
  const std::array<uint8_t,22> rfc_ikm{0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b};
  const std::array<uint8_t,13> rfc_salt{0,1,2,3,4,5,6,7,8,9,10,11,12};
  const std::array<uint8_t,10> rfc_info{0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9};
  const std::array<uint8_t,32> rfc_output{0x3c,0xb2,0x5f,0x25,0xfa,0xac,0xd5,0x7a,0x90,0x43,0x4f,0x64,0xd0,0x36,0x2f,0x2a,0x2d,0x2d,0x0a,0x90,0xcf,0x1a,0x5a,0x4c,0x5d,0xb0,0x2d,0x56,0xec,0xc4,0xc5,0xbf};
  Check(ReferenceHkdf(rfc_ikm,rfc_salt,rfc_info)==rfc_output,"independent RFC 5869 published known answer");
  std::array<uint8_t,32> fixture_ikm{};std::array<uint8_t,16> fixture_salt{};
  for(unsigned i=0;i<32;++i)fixture_ikm[i]=uint8_t(2*29+i*7);
  for(unsigned i=0;i<16;++i)fixture_salt[i]=uint8_t(2*17+i);
  constexpr std::string_view hkdf_domain="ReXGlue private LAN discovery encryption v1";
  std::vector<uint8_t> fixture_info(hkdf_domain.begin(),hkdf_domain.end());fixture_info.push_back(0);
  for(uint64_t value:{uint64_t(1),uint64_t(2),files.expiry})
    for(int shift=56;shift>=0;shift-=8)fixture_info.push_back(uint8_t(value>>shift));
  fixture_info.insert(fixture_info.end(),fixture_salt.begin(),fixture_salt.end());
  auto reference_key=ReferenceHkdf(fixture_ikm,fixture_salt,fixture_info);
  Check(request_key&&*request_key==reference_key,"EVP HKDF grant derivation matches independent extract-expand");
  OPENSSL_cleanse(reference_key.data(),reference_key.size());OPENSSL_cleanse(fixture_ikm.data(),fixture_ikm.size());
  Check(!files.host->DiscoveryKey(99,false)&&!files.host->Selector(99)&&
        !files.host->ClientForSelector(std::span(fixture_salt).first(15)),"unknown grant and malformed selector fail closed");
  for(auto* key:{&request_key,&client_key,&reply_key,&third_key})if(*key)OPENSSL_cleanse((*key)->data(),(*key)->size());
  Check(opened&&opened->public_packet==prefix&&opened->join_claim_proof==request.join_claim_proof,"exact authenticated join request bytes");
  for(size_t i=0;i<encoded->size();++i){auto corrupt=*encoded;corrupt[i]^=1;
    Check(!OpenPrivateLanDiscoveryFrame(*files.host,2,title,PrivateLanDiscoveryDirection::kRequest,corrupt),"every request byte mutation rejected");}
  for(size_t length=0;length<encoded->size();++length)
    Check(!OpenPrivateLanDiscoveryFrame(*files.host,2,title,PrivateLanDiscoveryDirection::kRequest,std::span(*encoded).first(length)),"every truncation and legacy packet rejected");
  std::vector<uint8_t> trailing(encoded->begin(),encoded->end());trailing.push_back(0);
  Check(!OpenPrivateLanDiscoveryFrame(*files.host,2,title,PrivateLanDiscoveryDirection::kRequest,trailing),"oversize private frame rejected");
  Check(!OpenPrivateLanDiscoveryFrame(*files.host,3,title,PrivateLanDiscoveryDirection::kRequest,*encoded)&&
        !OpenPrivateLanDiscoveryFrame(*files.host,2,title^1,PrivateLanDiscoveryDirection::kRequest,*encoded),"recipient and title exact");
  Check(!SealPrivateLanDiscoveryFrame(*files.host,2,title,PrivateLanDiscoveryDirection::kRequest,request)&&
        !OpenPrivateLanDiscoveryFrame(*files.second,2,title,PrivateLanDiscoveryDirection::kRequest,*encoded),"wrong host/client direction refused");
  PrivateLanDiscoveryFrame reply=request;reply.public_packet[6]=2;reply.join_claim_proof={};
  std::vector<uint8_t> plaintext(708);for(size_t i=0;i<plaintext.size();++i)plaintext[i]=uint8_t(i*11+7);
  const std::array<uint8_t,4> aad{1,2,3,4};reply.payload=SealPrivateLanPayload(*files.host,2,key->public_key(),plaintext,aad);
  Check(bool(reply.payload),"actual authenticated encrypted private ticket payload");
  auto response=SealPrivateLanDiscoveryFrame(*files.host,2,title,PrivateLanDiscoveryDirection::kReply,reply);Check(bool(response),"host signs complete private reply");
  auto received=OpenPrivateLanDiscoveryFrame(*files.second,2,title,PrivateLanDiscoveryDirection::kReply,*response,rpc);Check(bool(received)&&bool(received->payload),"reply authenticates exact pending RPC before payload parse");
  auto decrypted=OpenPrivateLanPayload(*files.second,2,*key,*received->payload,aad);
  Check(decrypted&&std::equal(decrypted->bytes().begin(),decrypted->bytes().end(),plaintext.begin()),"framing preserves private ticket authentication and encryption");
  for(size_t i=0;i<response->size();++i){auto corrupt=*response;corrupt[i]^=1;
    Check(!OpenPrivateLanDiscoveryFrame(*files.second,2,title,PrivateLanDiscoveryDirection::kReply,corrupt,rpc),"every reply byte mutation rejected");}
  auto another=rpc;another[15]^=1;
  Check(!OpenPrivateLanDiscoveryFrame(*files.second,2,title,PrivateLanDiscoveryDirection::kReply,*response,another)&&
        !OpenPrivateLanDiscoveryFrame(*files.second,2,title,PrivateLanDiscoveryDirection::kReply,*response),"replayed or uncorrelated reply rejected");
  Check(!OpenPrivateLanDiscoveryFrame(*files.third,3,title,PrivateLanDiscoveryDirection::kReply,*response,rpc),"another invited client cannot authenticate this reply");
  auto malformed=reply;malformed.payload->payload.ciphertext.resize(769);
  Check(!SealPrivateLanDiscoveryFrame(*files.host,2,title,PrivateLanDiscoveryDirection::kReply,malformed),"private cipher bound enforced before frame copy");
  malformed=reply;malformed.public_packet[7]=1;
  Check(!SealPrivateLanDiscoveryFrame(*files.host,2,title,PrivateLanDiscoveryDirection::kReply,malformed),"reserved public bytes refused even by trusted signer");
  // The parser must reject malformed padding even when the sender has the
  // correct grant. Construct a valid fresh GCM envelope around that bad body.
  auto signing_key=files.host->DiscoveryKey(2,true);Check(bool(signing_key),"authenticated malformed fixture key");
  std::array<uint8_t,1400> bad_body{};int count=0,written=0;
  auto context=std::unique_ptr<EVP_CIPHER_CTX,decltype(&EVP_CIPHER_CTX_free)>(EVP_CIPHER_CTX_new(),EVP_CIPHER_CTX_free);
  Check(context&&EVP_DecryptInit_ex(context.get(),EVP_aes_256_gcm(),nullptr,nullptr,nullptr)==1&&
    EVP_DecryptInit_ex(context.get(),nullptr,nullptr,signing_key->data(),response->data()+24)==1&&
    EVP_DecryptUpdate(context.get(),nullptr,&count,response->data(),40)==1&&
    EVP_DecryptUpdate(context.get(),bad_body.data(),&written,response->data()+40,1384)==1&&written==1384&&
    EVP_CIPHER_CTX_ctrl(context.get(),EVP_CTRL_GCM_SET_TAG,16,response->data()+1424)==1&&
    EVP_DecryptFinal_ex(context.get(),bad_body.data()+written,&count)==1&&count==0,"independent raw authenticated fixture decode");
  bad_body[672]=uint8_t(707>>8);bad_body[673]=uint8_t(707);bad_body[1383]=1;
  auto signed_bad=*response;Check(RAND_bytes(signed_bad.data()+24,12)==1,"malformed fixture uses fresh nonce");
  Check(EVP_EncryptInit_ex(context.get(),EVP_aes_256_gcm(),nullptr,signing_key->data(),signed_bad.data()+24)==1&&
    EVP_EncryptUpdate(context.get(),nullptr,&count,signed_bad.data(),40)==1&&
    EVP_EncryptUpdate(context.get(),signed_bad.data()+40,&written,bad_body.data(),1384)==1&&written==1384&&
    EVP_EncryptFinal_ex(context.get(),signed_bad.data()+40+written,&count)==1&&count==0&&
    EVP_CIPHER_CTX_ctrl(context.get(),EVP_CTRL_GCM_GET_TAG,16,signed_bad.data()+1424)==1,"independent raw malformed fixture authentication");
  OPENSSL_cleanse(signing_key->data(),signing_key->size());OPENSSL_cleanse(bad_body.data(),bad_body.size());
  Check(!OpenPrivateLanDiscoveryFrame(*files.second,2,title,PrivateLanDiscoveryDirection::kReply,signed_bad,rpc),"correct grant cannot legitimize nonzero encrypted padding");
  for(uint8_t type:{uint8_t(1),uint8_t(4),uint8_t(5)}){
    auto control=request;control.public_packet[6]=type;control.join_claim_proof={};
    auto bytes=SealPrivateLanDiscoveryFrame(*files.second,2,title,PrivateLanDiscoveryDirection::kRequest,control);
    Check(bytes&&OpenPrivateLanDiscoveryFrame(*files.host,2,title,PrivateLanDiscoveryDirection::kRequest,*bytes),"existing search/leave/register operations retain authenticated framing");}
  std::cout<<checks<<" private LAN full-frame authentication, MTU, downgrade, recipient and replay-correlation checks passed\n";
}
#endif
}
#ifdef FSC_PRIVATE_LAN_STANDALONE
int main(){try{Run();return 0;}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
#else
TEST_CASE("Private LAN discovery framing authenticates complete bounded RPC bytes before parsing", "[network][security]") {
#if REX_PLATFORM_GNU_LINUX
  REQUIRE_NOTHROW(Run());
#endif
}
#endif
