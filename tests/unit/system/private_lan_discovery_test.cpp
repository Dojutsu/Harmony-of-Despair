#include <catch2/catch_test_macros.hpp>
#include <rex/system/xam/private_lan_discovery.h>
#include <rex/system/xsocket.h>
#include <rex/platform.h>
#include <filesystem>
#include <cstring>
#include <thread>
#if REX_PLATFORM_GNU_LINUX
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <openssl/crypto.h>
#endif
namespace rex::system::xam {
#if REX_PLATFORM_GNU_LINUX
namespace {
struct PrivateConfiguration {
  std::string file=REXCVAR_GET(private_lan_invitation_file),bind=REXCVAR_GET(lan_bind_address),direct=REXCVAR_GET(direct_connect_address);
  uint32_t gameplay=REXCVAR_GET(lan_gameplay_port);bool legacy=REXCVAR_GET(private_lan_allow_legacy_diagnostics);
  PrivateConfiguration(){REXCVAR_SET(private_lan_allow_legacy_diagnostics,false);REXCVAR_SET(lan_bind_address,std::string("127.0.0.1"));REXCVAR_SET(direct_connect_address,std::string("127.0.0.1"));}
  ~PrivateConfiguration(){REXCVAR_SET(private_lan_invitation_file,file);REXCVAR_SET(lan_bind_address,bind);REXCVAR_SET(direct_connect_address,direct);REXCVAR_SET(lan_gameplay_port,gameplay);REXCVAR_SET(private_lan_allow_legacy_diagnostics,legacy);}
};
struct Grants {
  std::filesystem::path directory;
  Grants(){char name[]="/tmp/fsc-private-discovery-XXXXXX";const auto created=mkdtemp(name);REQUIRE(created);directory=created;
    const auto expiry=uint64_t(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count())+3600;
    for(bool host:{true,false}){std::array<uint8_t,80> bytes{};std::memcpy(bytes.data(),"HPLI",4);bytes[4]=1;bytes[5]=host?0:1;bytes[6]=1;bytes[15]=1;
      for(unsigned i=0;i<8;++i)bytes[16+i]=uint8_t(expiry>>((7-i)*8));bytes[31]=2;
      for(unsigned i=0;i<16;++i)bytes[32+i]=uint8_t(17+i);for(unsigned i=0;i<32;++i)bytes[48+i]=uint8_t(37+3*i);
      const auto file=directory/(host?"host.hpli":"client.hpli");const auto fd=::open(file.c_str(),O_WRONLY|O_CREAT|O_EXCL|O_CLOEXEC,0600);
      REQUIRE(fd>=0);REQUIRE(::write(fd,bytes.data(),bytes.size())==ssize_t(bytes.size()));::close(fd);OPENSSL_cleanse(bytes.data(),bytes.size());}}
  ~Grants(){std::error_code error;std::filesystem::remove_all(directory,error);}
};
struct RuntimeSocket {
  XSocket endpoint{nullptr};uint64_t socket;LanAddress address;
  explicit RuntimeSocket(uint64_t xuid){REQUIRE(endpoint.Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS);
    N_XSOCKADDR_IN target{};target.sin_family=AF_INET;target.sin_addr=INADDR_LOOPBACK;REQUIRE(endpoint.Bind(&target,sizeof(target))==X_STATUS_SUCCESS);
    REQUIRE(endpoint.SetNonBlocking(true)==X_STATUS_SUCCESS);socket=endpoint.native_handle();sockaddr_in local{};socklen_t length=sizeof(local);
    REQUIRE(getsockname(socket,reinterpret_cast<sockaddr*>(&local),&length)==0);address={local.sin_addr.s_addr,ntohs(local.sin_port)};
    NatProbeAttach(socket,NatProbeRole::kGameplay,address);RegisterGameplaySocketCandidate(xuid,socket,3074);}
};
uint16_t FreePort(){const auto socket=::socket(AF_INET,SOCK_DGRAM|SOCK_CLOEXEC,IPPROTO_UDP);REQUIRE(socket>=0);
  sockaddr_in local{};local.sin_family=AF_INET;local.sin_addr.s_addr=htonl(INADDR_LOOPBACK);REQUIRE(bind(socket,reinterpret_cast<sockaddr*>(&local),sizeof(local))==0);
  socklen_t length=sizeof(local);REQUIRE(getsockname(socket,reinterpret_cast<sockaddr*>(&local),&length)==0);const auto port=ntohs(local.sin_port);::close(socket);return port;}
void ExchangeGameplay(RuntimeSocket& source,RuntimeSocket& destination,uint64_t peer,uint8_t value){
  auto logical=GameplayLogicalToXnAddr(source.address.ipv4);(void)logical;
  const auto session=GameplayLogicalToXnAddr(htonl(0xf0000000+uint32_t(peer)));REQUIRE(session);
  N_XSOCKADDR_IN target{};target.sin_family=AF_INET;target.sin_addr=ntohl(session->logical.ipv4);target.sin_port=3074;
  std::array<uint8_t,39> payload{};payload.fill(value);REQUIRE(source.endpoint.SendTo(payload.data(),payload.size(),0,&target,sizeof(target))==39);
  std::array<uint8_t,96> received{};N_XSOCKADDR_IN from{};uint32_t length=sizeof(from);int count=-1;
  const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(2);
  while(std::chrono::steady_clock::now()<deadline){count=destination.endpoint.RecvFrom(received.data(),received.size(),0,&from,&length);if(count>=0)break;std::this_thread::sleep_for(std::chrono::milliseconds(2));}
  REQUIRE(count==39);CHECK(uint16_t(from.sin_port)==3074);CHECK(std::equal(payload.begin(),payload.end(),received.begin()));
}
}
#endif
TEST_CASE("private LAN production adapter drives real session join registration and encrypted gameplay", "[network][security]") {
#if REX_PLATFORM_GNU_LINUX
  PrivateConfiguration configuration;Grants grants;constexpr uint32_t title=0x58410a7a;const auto port=FreePort();
  REXCVAR_SET(private_lan_invitation_file,(grants.directory/"host.hpli").string());
  RuntimeSocket host_socket(1);SessionRegistry host_registry;auto hosted=host_registry.Create(1,"PrivateHost",host_socket.address,1,3,3);REQUIRE(hosted);
  LanDiscoveryService host(title,port);REQUIRE(host.Advertise(hosted));CHECK(host.IsAdvertising());
  REXCVAR_SET(private_lan_invitation_file,(grants.directory/"client.hpli").string());
  RuntimeSocket client_socket(2);REXCVAR_SET(lan_gameplay_port,uint32_t(client_socket.address.port));
  LanDiscoveryService client(title,port);client.SetArbitrationMachineId(22);
  auto discovered=client.Search(500,1);REQUIRE(discovered.size()==1);CHECK(discovered[0].host_xuid==1);
  SessionRegistry client_registry;auto actual=client_registry.UpsertDiscovered(std::move(discovered[0]));REQUIRE(actual);
  N_XSOCKADDR_IN target{};target.sin_family=AF_INET;target.sin_addr=INADDR_LOOPBACK;target.sin_port=host_socket.address.port;
  std::array<uint8_t,3> raw{1,2,3};CHECK(client_socket.endpoint.SendTo(raw.data(),raw.size(),0,&target,sizeof(target))==-1);
  SessionMember member{2,"PrivateClient",0,true,true,false};auto spoof=member;spoof.xuid=3;
  CHECK_FALSE(client.Join(*actual,spoof,100));
  auto joined=client.Join(*actual,member,500);REQUIRE(joined);REQUIRE(joined->private_lan_gameplay);
  CHECK_FALSE(client_registry.CommitJoinedRecord(actual,*joined,[]{return false;}));CHECK(actual->members.size()==1);
  CHECK_FALSE(NatProbeGameplayDestination(client_socket.socket,{htonl(0xf0000001),3074}));
  REQUIRE(client_registry.CommitJoinedRecord(actual,std::move(*joined),[]{return true;}));
  REQUIRE(client.ActivatePrivateLanGameplay(actual,2));
  auto late_search=client.Search(500,1);REQUIRE(late_search.size()==1);
  REQUIRE(client_registry.UpsertDiscovered(late_search[0])==actual);
  late_search[0].arbitration_incarnation[0]^=1;CHECK_FALSE(client_registry.UpsertDiscovered(late_search[0]));
  CHECK_FALSE(client_registry.UpsertDiscovered(*actual));
  REQUIRE(client_registry.Find(actual->info.id)==actual);
  ExchangeGameplay(client_socket,host_socket,1,42);ExchangeGameplay(host_socket,client_socket,2,17);
  auto registered=client.RegisterArbitration(actual,2,actual->nonce);REQUIRE(registered);CHECK(registered->registrants.size()==1);
  auto host_registered=host.RegisterArbitration(hosted,1,hosted->nonce);REQUIRE(host_registered);CHECK(host_registered->registrants.size()==2);
  std::this_thread::sleep_for(std::chrono::milliseconds(1200));
  ExchangeGameplay(client_socket,host_socket,1,91);ExchangeGameplay(host_socket,client_socket,2,83);
  auto left=client.Leave(*actual,2,500);REQUIRE(left);CHECK(left->members.size()==1);
  REQUIRE(client_registry.Leave(actual->info.id,2));
  {std::lock_guard lock(*hosted->mutex);CHECK(hosted->members.size()==1);}
  CHECK_FALSE(NatProbeGameplayDestination(host_socket.socket,{htonl(0xf0000002),3074}));
  CHECK(client_socket.endpoint.SendTo(raw.data(),raw.size(),0,&target,sizeof(target))==-1);
  host.StopAdvertising();CHECK_FALSE(host.IsAdvertising());
#endif
}
TEST_CASE("native gameplay sockets require protection before admission with explicit legacy diagnostics", "[network][security]") {
#if REX_PLATFORM_GNU_LINUX
  PrivateConfiguration configuration;REXCVAR_SET(private_lan_invitation_file,std::string{});
  RuntimeSocket source(41),destination(42);N_XSOCKADDR_IN target{};target.sin_family=AF_INET;target.sin_addr=INADDR_LOOPBACK;target.sin_port=destination.address.port;
  std::array<uint8_t,3> payload{4,5,6};CHECK(source.endpoint.SendTo(payload.data(),payload.size(),0,&target,sizeof(target))==-1);
  sockaddr_in native{};native.sin_family=AF_INET;native.sin_addr.s_addr=destination.address.ipv4;native.sin_port=htons(destination.address.port);
  REQUIRE(::sendto(source.socket,payload.data(),payload.size(),0,reinterpret_cast<sockaddr*>(&native),sizeof(native))==3);
  std::array<uint8_t,8> output;output.fill(0x9a);const auto before=output;
  CHECK(destination.endpoint.RecvFrom(output.data(),output.size(),0,nullptr,nullptr)==-1);CHECK(output==before);
  REXCVAR_SET(private_lan_allow_legacy_diagnostics,true);
  REQUIRE(source.endpoint.SendTo(payload.data(),payload.size(),0,&target,sizeof(target))==3);
  REQUIRE(destination.endpoint.RecvFrom(output.data(),output.size(),0,nullptr,nullptr)==3);CHECK(std::equal(payload.begin(),payload.end(),output.begin()));
#endif
}
TEST_CASE("private LAN missing invalid grants fail closed without preventing local session creation", "[network][security]") {
#if REX_PLATFORM_GNU_LINUX
  PrivateConfiguration configuration;REXCVAR_SET(private_lan_invitation_file,std::string{});
  SessionRegistry registry;auto local=registry.Create(1,"Offline",{htonl(INADDR_LOOPBACK),3074},1,3,3);REQUIRE(local);
  LanDiscoveryService offline(0x58410a7a,FreePort());CHECK_FALSE(offline.Advertise(local));CHECK(offline.Search(20,1).empty());
  REXCVAR_SET(private_lan_invitation_file,std::string("/tmp/nonexistent-private-lan-grant"));
  LanDiscoveryService invalid(0x58410a7a,FreePort());CHECK_FALSE(invalid.Advertise(local));CHECK(invalid.Search(20,1).empty());
#endif
}
} // namespace rex::system::xam
