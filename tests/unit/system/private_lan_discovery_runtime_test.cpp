#include <catch2/catch_test_macros.hpp>
#include <rex/system/xam/private_lan_discovery.h>
#include <rex/system/xam/private_lan_discovery_wire.h>
#include <rex/system/xsocket.h>
#include <rex/platform.h>
#include <filesystem>
#include <thread>
#include <fstream>
#include <set>
#include <cstring>
#if REX_PLATFORM_GNU_LINUX
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <openssl/evp.h>
#include <openssl/crypto.h>
#include <openssl/rand.h>
#endif
namespace rex::system::xam {
#if REX_PLATFORM_GNU_LINUX
namespace {
using PrivateDiscoveryClock=std::chrono::steady_clock;
void PrivateMark(const std::filesystem::path& root,std::string name){const auto fd=::open((root/name).c_str(),O_WRONLY|O_CREAT|O_EXCL|O_CLOEXEC|O_NOFOLLOW,0600);if(fd>=0){const char byte='1';REQUIRE(write(fd,&byte,1)==1);close(fd);}}
struct DiscoveryRuntimeSocket {
  XSocket endpoint{nullptr};uint64_t handle;LanAddress address;
  DiscoveryRuntimeSocket(uint64_t local,uint32_t ipv4){REQUIRE(endpoint.Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS);
    N_XSOCKADDR_IN target{};target.sin_family=AF_INET;target.sin_addr=ntohl(ipv4);REQUIRE(endpoint.Bind(&target,sizeof(target))==X_STATUS_SUCCESS);
    REQUIRE(endpoint.SetNonBlocking(true)==X_STATUS_SUCCESS);handle=endpoint.native_handle();sockaddr_in native{};socklen_t length=sizeof(native);
    REQUIRE(getsockname(handle,reinterpret_cast<sockaddr*>(&native),&length)==0);address={native.sin_addr.s_addr,ntohs(native.sin_port)};
    NatProbeAttach(handle,NatProbeRole::kGameplay,address);RegisterGameplaySocketCandidate(local,handle,3074);}
};
void PutDiscovery(PrivateLanDiscoveryPublic& p,size_t at,uint64_t value,size_t count){for(size_t i=0;i<count;++i)p[at+i]=uint8_t(value>>((count-i-1)*8));}
// A grant-3 holder maliciously claims XUID 2. Independently authenticate the
// malformed ciphertext to verify the production host, rather than only the
// trusted client serializer, enforces the selector-to-identity boundary.
void SendIdentitySpoof(const PrivateLanInvitation& invitation,const SessionRecord& s,uint32_t title,LanAddress target,LanAddress gameplay) {
  PrivateLanDiscoveryFrame frame;auto& p=frame.public_packet;PutDiscovery(p,0,0x5245584c,4);PutDiscovery(p,4,3,2);p[6]=3;PutDiscovery(p,8,title,4);
  std::copy(s.info.id.begin(),s.info.id.end(),p.begin()+12);std::copy(s.info.key.begin(),s.info.key.end(),p.begin()+20);PutDiscovery(p,36,s.host_xuid,8);
  PutDiscovery(p,64,1,4);PutDiscovery(p,84,3,8);PutDiscovery(p,112,33,8);std::memcpy(p.data()+120,&gameplay.ipv4,4);PutDiscovery(p,124,gameplay.port,2);
  PutDiscovery(p,436,s.nonce,8);PutDiscovery(p,444,s.host_machine_id,8);std::copy(s.arbitration_incarnation.begin(),s.arbitration_incarnation.end(),p.begin()+452);
  auto key=NewArbitrationKey();auto challenge=NewArbitrationToken(),rpc=NewArbitrationToken();REQUIRE(key);REQUIRE(challenge);REQUIRE(rpc);
  std::copy(challenge->begin(),challenge->end(),p.begin()+468);std::copy(key->public_key().begin(),key->public_key().end(),p.begin()+532);
  std::copy(rpc->begin(),rpc->end(),p.begin()+624);p[639]=1;frame.join_claim_proof[0]=1;
  auto wire=SealPrivateLanDiscoveryFrame(invitation,3,title,PrivateLanDiscoveryDirection::kRequest,frame);REQUIRE(wire);
  auto secret=invitation.DiscoveryKey(3,false);REQUIRE(secret);std::array<uint8_t,1400> body{};int count=0,written=0;
  auto cipher=std::unique_ptr<EVP_CIPHER_CTX,decltype(&EVP_CIPHER_CTX_free)>(EVP_CIPHER_CTX_new(),EVP_CIPHER_CTX_free);
  REQUIRE(cipher);REQUIRE(EVP_DecryptInit_ex(cipher.get(),EVP_aes_256_gcm(),nullptr,secret->data(),wire->data()+24)==1);
  REQUIRE(EVP_DecryptUpdate(cipher.get(),nullptr,&count,wire->data(),40)==1);
  REQUIRE(EVP_DecryptUpdate(cipher.get(),body.data(),&written,wire->data()+40,1384)==1);
  REQUIRE(EVP_CIPHER_CTX_ctrl(cipher.get(),EVP_CTRL_GCM_SET_TAG,16,wire->data()+1424)==1);
  REQUIRE(EVP_DecryptFinal_ex(cipher.get(),body.data()+written,&count)==1);
  body[91]=2;REQUIRE(RAND_bytes(wire->data()+24,12)==1);
  REQUIRE(EVP_EncryptInit_ex(cipher.get(),EVP_aes_256_gcm(),nullptr,secret->data(),wire->data()+24)==1);
  REQUIRE(EVP_EncryptUpdate(cipher.get(),nullptr,&count,wire->data(),40)==1);
  REQUIRE(EVP_EncryptUpdate(cipher.get(),wire->data()+40,&written,body.data(),1384)==1);
  REQUIRE(EVP_EncryptFinal_ex(cipher.get(),wire->data()+40+written,&count)==1);
  REQUIRE(EVP_CIPHER_CTX_ctrl(cipher.get(),EVP_CTRL_GCM_GET_TAG,16,wire->data()+1424)==1);
  OPENSSL_cleanse(secret->data(),secret->size());OPENSSL_cleanse(body.data(),body.size());
  const auto socket=::socket(AF_INET,SOCK_DGRAM|SOCK_CLOEXEC,IPPROTO_UDP);REQUIRE(socket>=0);sockaddr_in local{};local.sin_family=AF_INET;local.sin_addr.s_addr=gameplay.ipv4;
  REQUIRE(bind(socket,reinterpret_cast<sockaddr*>(&local),sizeof(local))==0);sockaddr_in remote{};remote.sin_family=AF_INET;remote.sin_addr.s_addr=target.ipv4;remote.sin_port=htons(target.port);
  REQUIRE(sendto(socket,wire->data(),wire->size(),0,reinterpret_cast<sockaddr*>(&remote),sizeof(remote))==ssize_t(wire->size()));close(socket);
}
}
#endif
TEST_CASE("private LAN real production discovery protects three independent native game sockets", "[.private-lan-discovery-integration]") {
#if REX_PLATFORM_GNU_LINUX
  const auto* environment=std::getenv("HARMONY_PRIVATE_LAN_FIXTURE");const auto* role=std::getenv("HARMONY_PRIVATE_LAN_ROLE");const auto* port_text=std::getenv("HARMONY_PRIVATE_LAN_DISCOVERY_PORT");
  if(!environment||!role||!port_text)SKIP("Run tools/private_lan_discovery_audit.py");
  const std::filesystem::path root(environment);const auto local=uint64_t(std::stoull(role));REQUIRE((local>=1&&local<=3));constexpr uint32_t title=0x58410a7a;
  const auto port=uint16_t(std::stoul(port_text));const auto ip=htonl(0x7f000000+uint32_t(local));
  REXCVAR_SET(lan_bind_address,std::string("127.0.0.")+std::to_string(local));REXCVAR_SET(direct_connect_address,std::string("127.0.0.1"));
  REXCVAR_SET(private_lan_allow_legacy_diagnostics,false);
  const auto filename=local==1?"host.hpli":("client-"+std::string(15,'0')+std::to_string(local)+".hpli");
  REXCVAR_SET(private_lan_invitation_file,(root/"invitations"/filename).string());
  auto gameplay=std::make_unique<DiscoveryRuntimeSocket>(local,ip);REXCVAR_SET(lan_gameplay_port,uint32_t(gameplay->address.port));
  SessionRegistry registry;LanDiscoveryService discovery(title,port);discovery.SetArbitrationMachineId(local*11);std::shared_ptr<SessionRecord> session;
  if(local==1){session=registry.Create(1,"OpaquePrivateHost",gameplay->address,1,3,3);REQUIRE(session);REQUIRE(discovery.Advertise(session));PrivateMark(root,"host.ready");}
  else {
    if(local==2){REXCVAR_SET(private_lan_invitation_file,(root/"wrong-invitations/client-0000000000000002.hpli").string());
      LanDiscoveryService wrong(title,port);CHECK(wrong.Search(250,1).empty());REXCVAR_SET(private_lan_invitation_file,(root/"invitations"/filename).string());}
    auto found=discovery.Search(1000,1);REQUIRE(found.size()==1);session=registry.UpsertDiscovered(std::move(found[0]));REQUIRE(session);
    if(local==3){auto invitation=PrivateLanInvitation::Load((root/"invitations"/filename).string());REQUIRE(invitation);
      SendIdentitySpoof(*invitation,*session,title,session->discovery_address,gameplay->address);}
    PrivateMark(root,"rejected-"+std::to_string(local));
    const auto wait=PrivateDiscoveryClock::now()+std::chrono::seconds(10);while(!std::filesystem::exists(root/"gojoin")&&PrivateDiscoveryClock::now()<wait)std::this_thread::sleep_for(std::chrono::milliseconds(10));
    REQUIRE(std::filesystem::exists(root/"gojoin"));SessionMember member{local,"PrivateClient",0,true,true,false};
    auto joined=discovery.Join(*session,member,1000);REQUIRE(joined);
    REQUIRE(registry.CommitJoinedRecord(session,std::move(*joined),[]{return true;}));REQUIRE(discovery.ActivatePrivateLanGameplay(session,local));
  }
  const auto started=PrivateDiscoveryClock::now();auto deadline=started+std::chrono::seconds(55),next_send=PrivateDiscoveryClock::time_point{},last=started;
  std::set<uint64_t> received;bool ready=false,registered=false,departed=false,rejoined=false,removed=false,bootstrap=false,replay=false;
  while(PrivateDiscoveryClock::now()<deadline&&!std::filesystem::exists(root/"stop")) {
    if(local==1&&!bootstrap&&std::filesystem::exists(root/"rejected-2")&&std::filesystem::exists(root/"rejected-3")&&std::filesystem::exists(root/"attacksdone")){
      std::lock_guard lock(*session->mutex);REQUIRE(session->members.size()==1);PrivateMark(root,"1.rejected");bootstrap=true;}
    if(local==2&&!departed&&std::filesystem::exists(root/"depart2")){
      auto left=discovery.Leave(*session,local,5000);REQUIRE(left);REQUIRE(left->members.size()==2);
      REQUIRE(registry.Leave(session->info.id,local));RevokeGameplayAuthorization(session,local);gameplay.reset();departed=true;PrivateMark(root,"2.departed");}
    if(local==2&&departed&&!rejoined){if(!std::filesystem::exists(root/"rejoin2")){std::this_thread::sleep_for(std::chrono::milliseconds(5));continue;}
      session.reset();gameplay=std::make_unique<DiscoveryRuntimeSocket>(local,ip);REXCVAR_SET(lan_gameplay_port,uint32_t(gameplay->address.port));
      auto found=discovery.Search(1000,1);REQUIRE(found.size()==1);session=registry.UpsertDiscovered(std::move(found[0]));REQUIRE(session);
      SessionMember member{local,"RejoinedClient",0,true,true,false};auto joined=discovery.Join(*session,member,1000);REQUIRE(joined);
      REQUIRE(registry.CommitJoinedRecord(session,std::move(*joined),[]{return true;}));REQUIRE(discovery.ActivatePrivateLanGameplay(session,local));
      received.clear();ready=false;registered=false;rejoined=true;}
    if(local!=2&&!rejoined&&std::filesystem::exists(root/"rejoin2")){received.clear();ready=false;registered=false;rejoined=true;}
    std::shared_ptr<const GameplayAuthorization> authorization;
    {std::lock_guard lock(*session->mutex);authorization=session->private_lan_gameplay;}
    if(!authorization){std::this_thread::sleep_for(std::chrono::milliseconds(5));continue;}
    if(local!=2&&!removed&&std::filesystem::exists(root/"depart2")&&authorization->peers.size()==1){PrivateMark(root,std::to_string(local)+".removed");removed=true;}
    if(local!=2&&!replay&&std::filesystem::exists(root/"replaydone")&&!std::filesystem::exists(root/"rejoin2")){
      std::lock_guard lock(*session->mutex);REQUIRE(std::none_of(session->members.begin(),session->members.end(),[](const auto& m){return m.xuid==2;}));PrivateMark(root,std::to_string(local)+".retired-replay");replay=true;}
    if(gameplay){std::array<uint8_t,2048> bytes{};N_XSOCKADDR_IN source{};uint32_t length=sizeof(source);
      const auto count=gameplay->endpoint.RecvFrom(bytes.data(),bytes.size(),0,&source,&length);
      if(count>=0){REQUIRE(count==39);REQUIRE(uint16_t(source.sin_port)==3074);auto peer=GameplayLogicalToXnAddr(htonl(uint32_t(source.sin_addr)));REQUIRE(peer);
        REQUIRE(peer->xuid!=local);for(size_t i=0;i<39;++i)REQUIRE(bytes[i]==uint8_t(peer->xuid+i));received.insert(peer->xuid);last=PrivateDiscoveryClock::now();}
      if(PrivateDiscoveryClock::now()>=next_send){for(const auto& peer:authorization->peers){N_XSOCKADDR_IN target{};target.sin_family=AF_INET;target.sin_addr=ntohl(peer.logical.ipv4);target.sin_port=3074;
          std::array<uint8_t,39> payload{};for(size_t i=0;i<39;++i)payload[i]=uint8_t(local+i);const int count=gameplay->endpoint.SendTo(payload.data(),payload.size(),0,&target,sizeof(target));
          CHECK((count==39||count==-1));}
        next_send=PrivateDiscoveryClock::now()+std::chrono::milliseconds(50);}}
    if(received.size()==2&&!ready){PrivateMark(root,std::to_string(local)+(rejoined?".rejoined":".ready"));ready=true;}
    if(ready&&!registered){auto snapshot=discovery.RegisterArbitration(session,local,session->nonce);if(snapshot&&snapshot->registrants.size()==3){PrivateMark(root,std::to_string(local)+(rejoined?".reregistered":".registered"));registered=true;}}
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
  }
  CHECK(received.size()==2);CHECK(PrivateDiscoveryClock::now()-last<std::chrono::milliseconds(500));CHECK(PrivateDiscoveryClock::now()-started>std::chrono::seconds(30));
  discovery.StopAllClientAdmissions();discovery.StopAdvertising();RevokeGameplayAuthorization(session,local);
#endif
}
} // namespace rex::system::xam
