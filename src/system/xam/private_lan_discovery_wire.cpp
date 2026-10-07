#include <rex/system/xam/private_lan_discovery_wire.h>
#include <rex/platform.h>
#include <algorithm>
#include <cstring>
#if REX_PLATFORM_GNU_LINUX
#include <openssl/evp.h>
#include <openssl/crypto.h>
#include <openssl/rand.h>
#endif
namespace rex::system::xam {
namespace {
constexpr size_t kHeader=40,kBody=1384,kClaim=640,kPayloadProof=656,kLength=672,kReserved=674,kCiphertext=676;
constexpr size_t kRecipientKey=532,kServerKey=564,kIv=596,kTag=608,kRequest=624;
static_assert(kHeader+kBody+16==kPrivateLanDiscoveryWireBytes);
static_assert(kPrivateLanDiscoveryWireBytes<=1472);
uint64_t Number(std::span<const uint8_t> bytes) {uint64_t value=0;for(auto byte:bytes)value=(value<<8)|byte;return value;}
bool Nonzero(std::span<const uint8_t> bytes) {uint8_t value=0;for(auto byte:bytes)value|=byte;return value!=0;}
bool Zero(std::span<const uint8_t> bytes) {return !Nonzero(bytes);}
bool Shape(std::span<const uint8_t> body,uint64_t host,uint64_t client,uint32_t title,PrivateLanDiscoveryDirection direction) {
  if(body.size()!=kBody||!host||!client||host==client||!title||
     Number(body.first(4))!=0x5245584c||Number(body.subspan(4,2))!=3||body[7]||
     Number(body.subspan(8,4))!=title||Number(body.subspan(36,8))!=host||
     !Zero(body.subspan(50,2))||!Zero(body.subspan(528,4))||!Zero(body.subspan(kReserved,2))||
     !Nonzero(body.subspan(kRequest,16)))return false;
  const bool request=direction==PrivateLanDiscoveryDirection::kRequest;const auto type=body[6];
  if(request) {
    if(type!=1&&type!=3&&type!=4&&type!=5)return false;
    if(Number(body.subspan(64,4))!=1||Number(body.subspan(84,8))!=client||
       !Zero(body.subspan(84+44,44*7))||!Zero(body.subspan(484,16)))return false;
  } else if(type!=2&&type!=6&&type!=7)return false;
  const auto members=Number(body.subspan(64,4));if(members>8)return false;
  for(size_t i=0;i<8;++i)if(!Zero(body.subspan(84+i*44+42,2)))return false;
  if(request&&type==3) {if(!Nonzero(body.subspan(kClaim,16)))return false;}
  else if(!Zero(body.subspan(kClaim,16)))return false;
  const size_t length=size_t(Number(body.subspan(kLength,2)));
  if(length>kPrivateLanDiscoveryMaximumPayload||!Zero(body.subspan(kCiphertext+length)))return false;
  if(length) {
    if(request||type!=2||!Nonzero(body.subspan(kPayloadProof,16))||!Zero(body.subspan(484,16))||
       !Nonzero(body.subspan(kRecipientKey,32))||!Nonzero(body.subspan(kServerKey,32))||
       !Nonzero(body.subspan(kIv,12))||!Nonzero(body.subspan(kTag,16)))return false;
  } else if(!Zero(body.subspan(kPayloadProof,16))||!Zero(body.subspan(kServerKey,32))||
            !Zero(body.subspan(kIv,12))||!Zero(body.subspan(kTag,16)))return false;
  return true;
}
bool Role(const PrivateLanInvitation& invitation,PrivateLanDiscoveryDirection direction,bool sealing) {
  if(direction!=PrivateLanDiscoveryDirection::kRequest&&direction!=PrivateLanDiscoveryDirection::kReply)return false;
  return invitation.host()==((direction==PrivateLanDiscoveryDirection::kReply)==sealing)&&invitation.Current();
}
#if REX_PLATFORM_GNU_LINUX
template<size_t N> struct SensitiveBytes {
  std::array<uint8_t,N> bytes{};
  ~SensitiveBytes(){OPENSSL_cleanse(bytes.data(),bytes.size());}
};
using Cipher=std::unique_ptr<EVP_CIPHER_CTX,decltype(&EVP_CIPHER_CTX_free)>;
#endif
} // namespace
std::optional<PrivateLanDiscoveryWire> SealPrivateLanDiscoveryFrame(
    const PrivateLanInvitation& invitation,uint64_t client,uint32_t title,
    PrivateLanDiscoveryDirection direction,const PrivateLanDiscoveryFrame& frame) {
#if REX_PLATFORM_GNU_LINUX
  try {
    if(!Role(invitation,direction,true))return std::nullopt;
    SensitiveBytes<kBody> plaintext;auto& body=plaintext.bytes;
    std::copy(frame.public_packet.begin(),frame.public_packet.end(),body.begin());
    std::copy(frame.join_claim_proof.begin(),frame.join_claim_proof.end(),body.begin()+kClaim);
    if(frame.payload) {
      const auto& envelope=*frame.payload;const auto count=envelope.payload.ciphertext.size();
      if(!count||count>kPrivateLanDiscoveryMaximumPayload)return std::nullopt;
      std::copy(envelope.payload.server_public_key.begin(),envelope.payload.server_public_key.end(),body.begin()+kServerKey);
      std::copy(envelope.payload.iv.begin(),envelope.payload.iv.end(),body.begin()+kIv);
      std::copy(envelope.payload.tag.begin(),envelope.payload.tag.end(),body.begin()+kTag);
      std::copy(envelope.invitation_proof.begin(),envelope.invitation_proof.end(),body.begin()+kPayloadProof);
      body[kLength]=uint8_t(count>>8);body[kLength+1]=uint8_t(count);
      std::copy(envelope.payload.ciphertext.begin(),envelope.payload.ciphertext.end(),body.begin()+kCiphertext);
    }
    if(!Shape(body,invitation.host_xuid(),client,title,direction))return std::nullopt;
    auto key=invitation.DiscoveryKey(client,direction==PrivateLanDiscoveryDirection::kReply);
    if(!key)return std::nullopt;
    struct CleanKey {std::array<uint8_t,32>& key;~CleanKey(){OPENSSL_cleanse(key.data(),key.size());}} cleanse{*key};
    const auto selector=invitation.Selector(client);if(!selector)return std::nullopt;
    PrivateLanDiscoveryWire wire{};std::memcpy(wire.data(),"HPLN",4);wire[4]=3;wire[5]=direction==PrivateLanDiscoveryDirection::kReply?1:0;
    std::copy(selector->begin(),selector->end(),wire.begin()+8);wire[36]=uint8_t(kBody>>8);wire[37]=uint8_t(kBody);
    if(RAND_bytes(wire.data()+24,12)!=1||!Nonzero(std::span(wire).subspan(24,12)))return std::nullopt;
    Cipher cipher(EVP_CIPHER_CTX_new(),EVP_CIPHER_CTX_free);int count=0,written=0;
    if(!cipher||EVP_EncryptInit_ex(cipher.get(),EVP_aes_256_gcm(),nullptr,nullptr,nullptr)!=1||
       EVP_CIPHER_CTX_ctrl(cipher.get(),EVP_CTRL_GCM_SET_IVLEN,12,nullptr)!=1||
       EVP_EncryptInit_ex(cipher.get(),nullptr,nullptr,key->data(),wire.data()+24)!=1||
       EVP_EncryptUpdate(cipher.get(),nullptr,&count,wire.data(),kHeader)!=1||
       EVP_EncryptUpdate(cipher.get(),wire.data()+kHeader,&written,body.data(),kBody)!=1||written!=int(kBody)||
       EVP_EncryptFinal_ex(cipher.get(),wire.data()+kHeader+written,&count)!=1||count!=0||
       EVP_CIPHER_CTX_ctrl(cipher.get(),EVP_CTRL_GCM_GET_TAG,16,wire.data()+kHeader+kBody)!=1)return std::nullopt;
    return wire;
  }catch(...){return std::nullopt;}
#else
  (void)invitation;(void)client;(void)title;(void)direction;(void)frame;return std::nullopt;
#endif
}
std::optional<PrivateLanDiscoveryFrame> OpenPrivateLanDiscoveryFrame(
    const PrivateLanInvitation& invitation,uint64_t client,uint32_t title,
    PrivateLanDiscoveryDirection direction,std::span<const uint8_t> wire,std::optional<ArbitrationToken> outstanding) {
#if REX_PLATFORM_GNU_LINUX
  try {
    if(!Role(invitation,direction,false)||wire.size()!=kPrivateLanDiscoveryWireBytes||std::memcmp(wire.data(),"HPLN",4)||
       wire[4]!=3||wire[5]!=(direction==PrivateLanDiscoveryDirection::kReply?1:0)||!Zero(wire.subspan(6,2))||
       !Zero(wire.subspan(38,2))||Number(wire.subspan(36,2))!=kBody||!Nonzero(wire.subspan(24,12))||
       (direction==PrivateLanDiscoveryDirection::kReply&&!outstanding))return std::nullopt;
    const auto selected=invitation.ClientForSelector(wire.subspan(8,16));
    if(!selected||(client&&client!=*selected)||(!client&&direction!=PrivateLanDiscoveryDirection::kRequest))return std::nullopt;
    client=*selected;auto key=invitation.DiscoveryKey(client,direction==PrivateLanDiscoveryDirection::kReply);if(!key)return std::nullopt;
    struct CleanKey {std::array<uint8_t,32>& key;~CleanKey(){OPENSSL_cleanse(key.data(),key.size());}} cleanse{*key};
    SensitiveBytes<kBody+16> plaintext;Cipher cipher(EVP_CIPHER_CTX_new(),EVP_CIPHER_CTX_free);int count=0,written=0;
    if(!cipher||EVP_DecryptInit_ex(cipher.get(),EVP_aes_256_gcm(),nullptr,nullptr,nullptr)!=1||
       EVP_CIPHER_CTX_ctrl(cipher.get(),EVP_CTRL_GCM_SET_IVLEN,12,nullptr)!=1||
       EVP_DecryptInit_ex(cipher.get(),nullptr,nullptr,key->data(),wire.data()+24)!=1||
       EVP_DecryptUpdate(cipher.get(),nullptr,&count,wire.data(),kHeader)!=1||
       EVP_DecryptUpdate(cipher.get(),plaintext.bytes.data(),&written,wire.data()+kHeader,kBody)!=1||written!=int(kBody)||
       EVP_CIPHER_CTX_ctrl(cipher.get(),EVP_CTRL_GCM_SET_TAG,16,const_cast<uint8_t*>(wire.data()+kHeader+kBody))!=1||
       EVP_DecryptFinal_ex(cipher.get(),plaintext.bytes.data()+written,&count)!=1||count!=0)return std::nullopt;
    const auto body=std::span(plaintext.bytes).first(kBody);
    if(!Shape(body,invitation.host_xuid(),client,title,direction)||
       (outstanding&&!std::equal(outstanding->begin(),outstanding->end(),body.begin()+kRequest)))return std::nullopt;
    PrivateLanDiscoveryFrame result;std::copy_n(body.begin(),kPrivateLanDiscoveryPublicBytes,result.public_packet.begin());
    std::copy_n(body.begin()+kClaim,16,result.join_claim_proof.begin());const auto length=Number(body.subspan(kLength,2));
    if(length) {
      auto& payload=result.payload.emplace();std::copy_n(body.begin()+kServerKey,32,payload.payload.server_public_key.begin());
      std::copy_n(body.begin()+kIv,12,payload.payload.iv.begin());std::copy_n(body.begin()+kTag,16,payload.payload.tag.begin());
      std::copy_n(body.begin()+kPayloadProof,16,payload.invitation_proof.begin());
      payload.payload.ciphertext.assign(body.begin()+kCiphertext,body.begin()+kCiphertext+length);
    }
    return result;
  }catch(...){return std::nullopt;}
#else
  (void)invitation;(void)client;(void)title;(void)direction;(void)wire;(void)outstanding;return std::nullopt;
#endif
}
} // namespace rex::system::xam
