
#include <catch2/catch_test_macros.hpp>
#include <rex/platform.h>
#if REX_PLATFORM_WIN32
#include <winsock2.h>
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#endif
#include <rex/system/xam/gameplay_traversal.h>
#include <rex/cvar.h>
#include <rex/system/xsocket.h>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <filesystem>
#include <thread>
#include <cstdlib>
#include <set>
#include <rex/system/xam/session_directory.h>

namespace rex::kernel::xam {
struct XNADDR;
u32 NetDll_XNetXnAddrToInAddr_entry(u32, ppc_ptr_t<XNADDR>, mapped_void, mapped_void);
u32 NetDll_XNetInAddrToXnAddr_entry(u32, u32, ppc_ptr_t<XNADDR>, mapped_void);
}
namespace rex::system::xam {
TEST_CASE("gameplay directory worker survives manual admission and joins at shutdown",
          "[.gameplay-worker]") {
  const auto* url = std::getenv("HARMONY_GAMEPLAY_WORKER_URL");
  const auto* marker = std::getenv("HARMONY_GAMEPLAY_WORKER_PENDING");
  if (!url || !marker) SKIP("Run tools/gameplay_traversal_audit/worker.py");
  const auto previous_url = REXCVAR_GET(session_directory_url);
  REXCVAR_SET(session_directory_url, std::string(url));
  for (bool automatic : {false, true}) {
    CAPTURE(automatic);
    std::filesystem::remove(marker);
    std::mutex observed_mutex;
    std::set<std::thread::id> workers;
    std::set<uint32_t> users;
    auto directory = std::make_unique<SessionDirectoryClient>(
        [&](uint32_t user) -> std::optional<uint64_t> {
          std::lock_guard lock(observed_mutex);
          workers.insert(std::this_thread::get_id());
          users.insert(user);
          return 100 + user;
        }, SessionDirectoryClient::ClientAdmissionTransport{}, automatic);
    SessionRegistry registry;
    std::vector<std::shared_ptr<SessionRecord>> sessions;
    DirectoryTraversalAttempt attempt;
    attempt.session_id = "worker-test";
    attempt.attempt_id = std::string(32, 'a');
    attempt.capability = std::string(32, 'b');
    const std::string generation(32, 'c');
    for (uint32_t user = 0; user < 6; ++user) {
      auto session = registry.Create(100 + user, "Local", {}, 1, 3, 3);
      session->members.front().gameplay_admission =
          std::make_shared<const GameplayAdmissionBinding>(GameplayAdmissionBinding{
              attempt.session_id, attempt.attempt_id, generation});
      sessions.push_back(session);
      directory->QueueGameplayAdmission(session, user, 100 + user, attempt, generation);
    }
    // No configured-invite worker exists, and no manual poll follows enqueue.
    const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(5);
    while (std::chrono::steady_clock::now() < deadline) {
      bool all;
      { std::lock_guard lock(observed_mutex); all = users.size() == 6; }
      if (all && std::filesystem::exists(marker)) break;
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    { std::lock_guard lock(observed_mutex);
      CHECK(users.size() == 6);
      CHECK(workers.size() == 1);
      CHECK_FALSE(workers.contains(std::this_thread::get_id())); }
    REQUIRE(std::filesystem::exists(marker));
    // The fixture holds the sixth HTTP response while destruction cancels and
    // joins. The identity callback's captured state remains alive until joined.
    const auto shutdown = std::chrono::steady_clock::now();
    directory.reset();
    CHECK(std::chrono::steady_clock::now() - shutdown < std::chrono::seconds(3));
    CHECK_FALSE(std::filesystem::exists(marker));
  }
  REXCVAR_SET(session_directory_url, previous_url);
}
namespace {
using Clock = std::chrono::steady_clock;
#if REX_PLATFORM_WIN32
using SockLen = int;
#else
using SockLen = socklen_t;
#endif
constexpr auto timeout = std::chrono::seconds(20);
struct Udp {
#if REX_PLATFORM_WIN32
  SOCKET socket = INVALID_SOCKET;
#else
  int socket = -1;
#endif
  LanAddress address{};
  Udp() {
#if REX_PLATFORM_WIN32
    WSADATA data; REQUIRE(WSAStartup(MAKEWORD(2,2), &data) == 0);
#endif
    socket = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    sockaddr_in addr{}; addr.sin_family=AF_INET; addr.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
    REQUIRE(::bind(socket, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == 0);
    SockLen size=sizeof(addr); REQUIRE(getsockname(socket, reinterpret_cast<sockaddr*>(&addr), &size) == 0);
    address={addr.sin_addr.s_addr,ntohs(addr.sin_port)};
#if REX_PLATFORM_WIN32
    u_long nonblock=1; REQUIRE(ioctlsocket(socket,FIONBIO,&nonblock)==0);
#else
    REQUIRE(fcntl(socket,F_SETFL,fcntl(socket,F_GETFL,0)|O_NONBLOCK)==0);
#endif
  }
  ~Udp() {
    CloseGameplaySocket(uint64_t(socket)); NatProbeDetach(uint64_t(socket));
#if REX_PLATFORM_WIN32
    closesocket(socket); WSACleanup();
#else
    close(socket);
#endif
  }
  void Attach(NatProbeRole role=NatProbeRole::kGameplay) { NatProbeAttach(uint64_t(socket),role,address); }
};
GameplayAuthorization Ticket(const std::shared_ptr<SessionRecord>& session) {
  GameplayAuthorization result;
  result.directory_session="gameplay-test"; result.xbox_session=session->info.id;
  result.host_xuid=session->host_xuid; result.xuid=session->host_xuid;
  result.member_nonce=std::string(32,'1'); result.member_capability=std::string(32,'2');
  result.logical={htonl(0xf0000001),1000}; result.expires_at=Clock::now()+std::chrono::seconds(40);
  for (uint64_t id : {2,3}) {
    auto binding=std::make_shared<const GameplayAdmissionBinding>(GameplayAdmissionBinding{
      result.directory_session,std::string(32,char('a'+id)),std::string(32,char('c'+id))});
    session->members.push_back({id,"Peer",0,false,true,false,binding});
    GameplayPeerAuthorization peer;
    peer.xuid=id; peer.member_nonce=std::string(32,char('4'+id));
    peer.admission_attempt=binding->attempt_id; peer.admission_generation=binding->admission_generation;
    peer.logical={htonl(0xf0000000+uint32_t(id)),1000};
    peer.traversal={std::string(32,char('1'+id)),std::string(32,char('5'+id)),"127.0.0.1",39188,0};
    result.peers.push_back(peer);
  }
  return result;
}
std::array<uint8_t,56> Registered(const GameplayPeerAuthorization& peer, LanAddress endpoint, uint8_t type=2) {
  std::array<uint8_t,56> bytes{}; std::memcpy(bytes.data(),"HNAT",4);
  bytes[4]=1;bytes[5]=type;bytes[6]=type==2?0:1;bytes[7]=1;
  for(size_t i=0;i<16;++i) {
    bytes[8+i]=uint8_t(std::stoul(peer.traversal.attempt_id.substr(2*i,2),nullptr,16));
    bytes[24+i]=uint8_t(std::stoul(peer.traversal.capability.substr(2*i,2),nullptr,16));
  }
  std::memcpy(bytes.data()+46,&endpoint.ipv4,4);
  auto port=htons(endpoint.port);std::memcpy(bytes.data()+50,&port,2);
  return bytes;
}
}
TEST_CASE("gameplay exact member routes separate peers behind one IPv4", "[gameplay][session][network]") {
  SessionRegistry registry; auto session=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);
  auto auth=Ticket(session); Udp socket;socket.Attach();
  REQUIRE(InstallGameplayAuthorization(session,auth));
  REQUIRE(BindGameplaySocket(session,1,uint64_t(socket.socket),1000));
  for(size_t i=0;i<2;++i) {
    LanAddress native{htonl(INADDR_LOOPBACK),uint16_t(42000+i)};
    auto registration=Registered(auth.peers[i],native);
    CHECK_FALSE(NatProbeConsume(socket.socket,registration.data(),56,htonl(INADDR_LOOPBACK),39189));
    REQUIRE(NatProbeConsume(socket.socket,registration.data(),56,htonl(INADDR_LOOPBACK),39188));
    CHECK_FALSE(NatProbeGameplayDestination(socket.socket,auth.peers[i].logical));
    CHECK(NatProbeIsPendingGameplaySource(socket.socket,native));
    auto ack=Registered(auth.peers[i],native,4);
    REQUIRE(NatProbeConsume(socket.socket,ack.data(),56,native.ipv4,native.port));
    CHECK(NatProbeGameplayDestination(socket.socket,auth.peers[i].logical)==native);
    CHECK_FALSE(NatProbeIsPendingGameplaySource(socket.socket,native));
    CHECK(NatProbeNormalizeGameplaySource(socket.socket,native)==auth.peers[i].logical);
    auto xn=GameplayXnAddrToLogical(session->info.id,ReconstructXnAddrIdentity(i+2));
    REQUIRE(xn); CHECK(xn->logical==auth.peers[i].logical);
    auto inverse=GameplayLogicalToXnAddr(auth.peers[i].logical.ipv4);
    REQUIRE(inverse);CHECK(inverse->xuid==i+2);CHECK(inverse->session_id==session->info.id);
  }
  auto wrong=session->info.id;wrong[0]^=1;
  CHECK_FALSE(GameplayXnAddrToLogical(wrong,ReconstructXnAddrIdentity(2)));
  CHECK_FALSE(GameplayLogicalDestination(socket.socket,{htonl(0xf0000063),1000}));
  REQUIRE(registry.Leave(session->info.id,2));
  CHECK_FALSE(GameplayXnAddrToLogical(session->info.id,ReconstructXnAddrIdentity(2)));
  CHECK_FALSE(NatProbeGameplayDestination(socket.socket,auth.peers[0].logical));
  CHECK(NatProbeGameplayDestination(socket.socket,auth.peers[1].logical));
  CHECK(session->FilledPrivateSlots()==1);
}
TEST_CASE("gameplay socket ownership cannot transfer or survive close", "[gameplay][session][security]") {
  SessionRegistry registry; auto session=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);
  auto auth=Ticket(session);Udp first,second;first.Attach();second.Attach();
  REQUIRE(InstallGameplayAuthorization(session,auth));
  REQUIRE(BindGameplaySocket(session,1,first.socket,1000));
  CHECK_FALSE(BindGameplaySocket(session,1,second.socket,1000));
  CHECK(NatProbePeerAttempts(second.socket,false).empty());
  CloseGameplaySocket(first.socket);
  CHECK_FALSE(InstallGameplayAuthorization(session,auth));
  CHECK_FALSE(BindGameplaySocket(session,1,second.socket,1000));
  CHECK_FALSE(GameplayAuthorizationCurrent(session,1,auth.member_nonce));
}
TEST_CASE("gameplay tickets reject unadmitted and replaced local membership", "[gameplay][session][security]") {
  SessionRegistry registry; auto host=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);
  auto auth=Ticket(host); auto client=std::make_shared<SessionRecord>(*host);
  for(auto& member:client->members) member.local=member.xuid==2;
  auth.xuid=2;auth.admission_attempt=auth.peers[0].admission_attempt;
  auth.admission_generation=auth.peers[0].admission_generation;
  auth.logical=auth.peers[0].logical;auth.peers.clear();
  auto wrong=auth;wrong.admission_generation=std::string(32,'f');
  CHECK_FALSE(InstallGameplayAuthorization(client,wrong));
  REQUIRE(InstallGameplayAuthorization(client,auth));
  client->members.erase(std::remove_if(client->members.begin(),client->members.end(),[](const auto& m){return m.xuid==2;}),client->members.end());
  client->members.push_back({2,"Replacement",0,true});
  CHECK_FALSE(GameplayAuthorizationCurrent(client,2,auth.member_nonce));
  CHECK_FALSE(InstallGameplayAuthorization(client,auth));
}
TEST_CASE("gameplay discovery completion and grant expiry do not retire admitted links", "[gameplay][session][network]") {
  SessionRegistry registry;auto session=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);
  auto auth=Ticket(session);Udp discovery,gameplay;discovery.Attach(NatProbeRole::kDiscovery);gameplay.Attach();
  REQUIRE(discovery.address.port!=gameplay.address.port);
  REQUIRE(NatProbeInstallIdentityForSocket({auth.peers[0].admission_attempt,std::string(32,'a'),"127.0.0.1",39188,0,true},discovery.socket));
  REQUIRE(InstallGameplayAuthorization(session,auth));REQUIRE(BindGameplaySocket(session,1,gameplay.socket,1000));
  NatProbeRetireIdentity(auth.peers[0].admission_attempt);
  NatProbeTickAt(gameplay.socket,Clock::now()+std::chrono::seconds(21));
  CHECK(NatProbeRendezvousAttemptActive(gameplay.socket,auth.peers[0].traversal.attempt_id));
  CHECK(NatProbePeerAttempts(discovery.socket,false).empty());
  auto expired=auth;expired.expires_at=Clock::now()-std::chrono::seconds(1);
  CHECK_FALSE(InstallGameplayAuthorization(session,expired));
}
} // namespace rex::system::xam

namespace rex::system::xam {
TEST_CASE("production admission to independent gameplay sockets fixture", "[.gameplay-integration]") {
  const char* root_env=std::getenv("HARMONY_GAMEPLAY_FIXTURE");
  const char* role_env=std::getenv("HARMONY_GAMEPLAY_ROLE");
  const char* url_env=std::getenv("HARMONY_GAMEPLAY_URL");
  if(!root_env || !role_env || !url_env) SKIP("Run tools/gameplay_traversal_audit/integration.py");
  const std::filesystem::path root(root_env);
  const uint64_t local=std::stoull(role_env);
  const uint16_t discovery_port=uint16_t(std::stoul(std::getenv("HARMONY_GAMEPLAY_DISCOVERY_PORT")));
  REXCVAR_SET(session_directory_url,std::string(url_env));
  REXCVAR_SET(session_directory_build_id,std::string("gameplay-fixture"));
  REXCVAR_SET(session_directory_candidate_type,std::string("public"));
  REXCVAR_SET(session_directory_publish_address,std::string{});
  REXCVAR_SET(lan_bind_address,std::string("127.0.0.1"));
  REXCVAR_SET(lan_gameplay_port,0u);
  SessionRegistry registry;
  // Match production: configured-invite code owns admission polling. After
  // readiness below, no caller polls again; gameplay must have its own lifetime.
  LanDiscoveryService discovery(0x58410A7A,discovery_port,{},[local](uint32_t){return std::optional<uint64_t>(local);},{},false);
  discovery.SetTitleId(0x58410A7A);
  discovery.SetLocalUserIdentity(0,local);
  std::shared_ptr<SessionRecord> session;
  std::unique_ptr<Udp> gameplay;
  uint16_t discovery_source_port=0;
  if(local==1) {
    gameplay=std::make_unique<Udp>();gameplay->Attach();
    session=registry.Create(1,"FixtureHost",gameplay->address,1,3,3);
    REQUIRE(BindGameplaySocket(session,1,gameplay->socket,1000));
    REQUIRE(discovery.Advertise(session));
    std::string code;
    const auto deadline=Clock::now()+timeout;
    while(Clock::now()<deadline) {
      {std::lock_guard lock(*session->mutex);code=session->status_invite_code;}
      if(!code.empty())break;
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    REQUIRE(!code.empty());
    {std::ofstream out(root/"code");out<<code;}
  } else {
    std::string code;{std::ifstream in(root/"code");in>>code;}
    auto issued=discovery.IssueConfiguredInviteAttempt(code,0x58410A7A);REQUIRE(issued);
    // Suppress the signed-LAN fast path so discovery must punch/ACK through
    // the production rendezvous before the original discovery join exchange.
    auto found=discovery.DiscoverConfiguredInvite(*issued,2000,[]{return true;},{},
        {htonl(INADDR_LOOPBACK),uint16_t(discovery_port+1)});
    REQUIRE(found);
    sockaddr_in addr{};SockLen size=sizeof(addr);
    REQUIRE(getsockname(found->socket,reinterpret_cast<sockaddr*>(&addr),&size)==0);
    discovery_source_port=ntohs(addr.sin_port);
    auto correlated=std::make_shared<SessionRecord>(std::move(found->session));
    REQUIRE(discovery.PrepareClientAdmission(0,issued->attempt,*correlated,found->socket)==ClientAdmissionPrepareResult::kPrepared);
    REQUIRE(discovery.ConfirmClientAdmissionSession(0,correlated));
    std::optional<ReadyAcceptedSessionCandidate> ready;
    const auto deadline=Clock::now()+timeout;
    while(Clock::now()<deadline) {
      discovery.PollClientAdmissions();
      ready=discovery.ReadyAcceptedSession();if(ready)break;
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    REQUIRE(ready);
    auto joined=discovery.Join(*correlated,{local,"FixtureClient",0,true,true,false},1000);
    REQUIRE(joined);
    session=std::make_shared<SessionRecord>(std::move(*joined));
    for(auto& member:session->members) {
      member.local=member.xuid==local;
      if(member.local)member.gameplay_admission=std::make_shared<const GameplayAdmissionBinding>(
          GameplayAdmissionBinding{ready->directory_session_id,ready->attempt_id,ready->admission_generation});
    }
    discovery.QueueGameplayAdmission(session,0,local,issued->attempt,ready->admission_generation);
    // Create A2 only after the host has had time to complete/retire A1.
    std::this_thread::sleep_for(std::chrono::seconds(2));
    gameplay=std::make_unique<Udp>();REQUIRE(gameplay->address.port!=discovery_source_port);
    gameplay->Attach();REQUIRE(BindGameplaySocket(session,local,gameplay->socket,1000));
  }
  std::vector<uint64_t> received;
  auto deadline=Clock::now()+std::chrono::seconds(35);
  auto next_send=Clock::now();
  bool reported=false;
  while(Clock::now()<deadline && !std::filesystem::exists(root/"stop")) {
    std::array<uint8_t,2048> buffer{};sockaddr_in source{};SockLen length=sizeof(source);
    int count=recvfrom(gameplay->socket,reinterpret_cast<char*>(buffer.data()),int(buffer.size()),0,
        reinterpret_cast<sockaddr*>(&source),&length);
    if(count>0) {
      if(!NatProbeConsume(gameplay->socket,buffer.data(),count,source.sin_addr.s_addr,ntohs(source.sin_port))) {
        if(NatProbeIsPendingGameplaySource(gameplay->socket,
            {source.sin_addr.s_addr,ntohs(source.sin_port)})) continue;
        REQUIRE(count==39);
        auto normalized=NatProbeNormalizeGameplaySource(gameplay->socket,{source.sin_addr.s_addr,ntohs(source.sin_port)});
        REQUIRE(normalized);
        auto identity=GameplayLogicalToXnAddr(normalized->ipv4);REQUIRE(identity);
        REQUIRE(buffer[0]==identity->xuid);
        for(size_t i=1;i<39;++i) REQUIRE(buffer[i]==uint8_t(identity->xuid+i));
        if(std::find(received.begin(),received.end(),identity->xuid)==received.end())received.push_back(identity->xuid);
      }
    }
    if(Clock::now()>=next_send) {
      for(uint64_t peer:{1,2,3}) {
        if(peer==local)continue;
        auto logical=GameplayXnAddrToLogical(session->info.id,ReconstructXnAddrIdentity(peer));
        if(!logical)continue;
        auto native=NatProbeGameplayDestination(gameplay->socket,logical->logical);
        if(!native)continue;
        std::array<uint8_t,39> payload{};for(size_t i=0;i<payload.size();++i)payload[i]=uint8_t(local+i);
        sockaddr_in target{};target.sin_family=AF_INET;target.sin_addr.s_addr=native->ipv4;target.sin_port=htons(native->port);
        REQUIRE(sendto(gameplay->socket,reinterpret_cast<char*>(payload.data()),int(payload.size()),0,
            reinterpret_cast<sockaddr*>(&target),sizeof(target))==39);
      }
      next_send=Clock::now()+std::chrono::milliseconds(80);
    }
    if(received.size()==2 && !reported) {
      std::ofstream out(root/(std::to_string(local)+".ready"));
      out<<"discovery="<<discovery_source_port<<" gameplay="<<gameplay->address.port<<" peers=2 bytes=39";
      reported=true;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
  }
  CHECK(received.size()==2);
  if(local==1) {
    std::lock_guard lock(*session->mutex);
    CHECK(session->members.size()==3);CHECK(session->FilledPublicSlots()==1);CHECK(session->FilledPrivateSlots()==2);
  }
}
} // namespace rex::system::xam

namespace rex::system::xam {
TEST_CASE("XNet entries round trip admission aliases with exact session and XUID", "[gameplay][network][xnet]") {
  using namespace rex::kernel::xam;
  SessionRegistry registry;auto session=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);
  auto auth=Ticket(session);REQUIRE(InstallGameplayAuthorization(session,auth));
  std::array<uint8_t,36> input{};
  for(const auto& peer:auth.peers) {
    auto identity=ReconstructXnAddrIdentity(peer.xuid);
    const uint32_t public_ip=htonl(0xcb007101);
    std::memcpy(input.data(),&public_ip,4);std::memcpy(input.data()+4,&public_ip,4);
    std::memcpy(input.data()+10,identity.ethernet_address.data(),6);
    std::memcpy(input.data()+16,identity.online_address.data(),20);
    uint32_t address=0;
    REQUIRE(NetDll_XNetXnAddrToInAddr_entry(1,ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(input.data())),
        mapped_void::from_host(session->info.id.data()),mapped_void::from_host(&address))==0);
    CHECK(address==peer.logical.ipv4);
    std::array<uint8_t,36> inverse{};std::array<uint8_t,8> session_id{};
    REQUIRE(NetDll_XNetInAddrToXnAddr_entry(1,ntohl(address),
        ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(inverse.data())),mapped_void::from_host(session_id.data()))==0);
    CHECK(session_id==session->info.id);
    CHECK(std::equal(input.begin()+10,input.end(),inverse.begin()+10));
    CHECK(inverse[8]==3);CHECK(inverse[9]==232); // guest port 1000, big endian
    auto wrong=session->info.id;wrong[0]^=1;
    CHECK(NetDll_XNetXnAddrToInAddr_entry(1,ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(inverse.data())),
        mapped_void::from_host(wrong.data()),mapped_void::from_host(&address))!=0);
  }
}
TEST_CASE("XSocket sends original bytes to the requested admitted peer and preserves LAN", "[gameplay][network][socket]") {
  Udp a,b,lan;
  XSocket sender(nullptr);
  REQUIRE(sender.Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS);
  N_XSOCKADDR_IN bind_address{};bind_address.sin_family=AF_INET;bind_address.sin_addr=INADDR_ANY;bind_address.sin_port=0;
  REQUIRE(sender.Bind(&bind_address,sizeof(bind_address))==X_STATUS_SUCCESS);
  REQUIRE(sender.SetNonBlocking(true)==X_STATUS_SUCCESS);
  SessionRegistry registry;auto session=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);
  auto auth=Ticket(session);
  NatProbeAttach(sender.native_handle(),NatProbeRole::kGameplay,{htonl(INADDR_LOOPBACK),0});
  REQUIRE(InstallGameplayAuthorization(session,auth));REQUIRE(BindGameplaySocket(session,1,sender.native_handle(),1000));
  for(size_t i=0;i<2;++i) {
    const auto native=i?b.address:a.address;
    auto packet=Registered(auth.peers[i],native);
    REQUIRE(NatProbeConsume(sender.native_handle(),packet.data(),56,htonl(INADDR_LOOPBACK),39188));
    packet=Registered(auth.peers[i],native,4);
    REQUIRE(NatProbeConsume(sender.native_handle(),packet.data(),56,native.ipv4,native.port));
  }
  for(size_t i=0;i<3;++i) {
    N_XSOCKADDR_IN destination{};destination.sin_family=AF_INET;
    destination.sin_addr=i<2?ntohl(auth.peers[i].logical.ipv4):INADDR_LOOPBACK;
    destination.sin_port=i<2?1000:lan.address.port;
    std::array<uint8_t,3> bytes{uint8_t(i),7,9};
    REQUIRE(sender.SendTo(bytes.data(),int(bytes.size()),0,&destination,sizeof(destination))==3);
    auto& receiver=i==0?a:(i==1?b:lan);
    std::array<char,8> result{};int received=-1;
    auto deadline=Clock::now()+std::chrono::seconds(1);
    while(Clock::now()<deadline && received<0) {
      received=recvfrom(receiver.socket,result.data(),int(result.size()),0,nullptr,nullptr);
      if(received<0)std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    REQUIRE(received==3);CHECK(std::memcmp(bytes.data(),result.data(),3)==0);
  }
  N_XSOCKADDR_IN unknown{};unknown.sin_family=AF_INET;unknown.sin_addr=0xf0000042;unknown.sin_port=1000;
  std::array<uint8_t,3> bytes{};
  CHECK(sender.SendTo(bytes.data(),3,0,&unknown,sizeof(unknown))==-1);
}
TEST_CASE("pending gameplay admission is permanently revoked before a delayed claim returns", "[gameplay][security][race]") {
  SessionRegistry registry;auto host=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);
  auto auth=Ticket(host);auto session=std::make_shared<SessionRecord>(*host);
  for(auto& member:session->members)member.local=member.xuid==2;
  auth.xuid=2;auth.admission_attempt=auth.peers[0].admission_attempt;
  auth.admission_generation=auth.peers[0].admission_generation;auth.logical=auth.peers[0].logical;auth.peers.clear();
  REQUIRE(TrackGameplayAdmission(session,2));
  RevokeGameplayAuthorization(session,2);
  CHECK_FALSE(InstallGameplayAuthorization(session,auth));
  CHECK_FALSE(TrackGameplayAdmission(session,2));
}
} // namespace rex::system::xam

namespace rex::system::xam {
TEST_CASE("one preexisting gameplay socket can bind after session creation without guessing", "[gameplay][race]") {
  Udp first,second;first.Attach();second.Attach();
  RegisterGameplaySocketCandidate(1,first.socket,1000);
  RegisterGameplaySocketCandidate(1,second.socket,1000);
  SessionRegistry registry;auto session=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);
  auto auth=Ticket(session);REQUIRE(InstallGameplayAuthorization(session,auth));
  CHECK_FALSE(NatProbeRendezvousAttemptActive(first.socket,auth.peers[0].traversal.attempt_id));
  CHECK_FALSE(NatProbeRendezvousAttemptActive(second.socket,auth.peers[0].traversal.attempt_id));
  CloseGameplaySocket(second.socket);
  REQUIRE(InstallGameplayAuthorization(session,auth));
  CHECK(NatProbeRendezvousAttemptActive(first.socket,auth.peers[0].traversal.attempt_id));
  CHECK_FALSE(BindGameplaySocket(session,1,second.socket,1000));
}
} // namespace rex::system::xam

namespace rex::system::xam {
TEST_CASE("XSocket drops an early gameplay packet until its own ACK then normalizes it", "[gameplay][socket][race]") {
  Udp peer, rendezvous;
  XSocket receiver(nullptr);
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS);
  N_XSOCKADDR_IN bind_address{};bind_address.sin_family=AF_INET;bind_address.sin_addr=INADDR_ANY;bind_address.sin_port=0;
  REQUIRE(receiver.Bind(&bind_address,sizeof(bind_address))==X_STATUS_SUCCESS);
  REQUIRE(receiver.SetNonBlocking(true)==X_STATUS_SUCCESS);
  sockaddr_in target{};SockLen length=sizeof(target);
  REQUIRE(getsockname(receiver.native_handle(),reinterpret_cast<sockaddr*>(&target),&length)==0);
  target.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
  SessionRegistry registry;auto session=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);
  auto auth=Ticket(session);
  for(auto& entry:auth.peers) entry.traversal.port=rendezvous.address.port;
  NatProbeAttach(receiver.native_handle(),NatProbeRole::kGameplay,{target.sin_addr.s_addr,ntohs(target.sin_port)});
  REQUIRE(InstallGameplayAuthorization(session,auth));REQUIRE(BindGameplaySocket(session,1,receiver.native_handle(),1000));
  auto packet=Registered(auth.peers[0],peer.address);
  REQUIRE(NatProbeConsume(receiver.native_handle(),packet.data(),56,htonl(INADDR_LOOPBACK),rendezvous.address.port));
  auto send=[&] {
    REQUIRE(sendto(peer.socket,"abc",3,0,reinterpret_cast<sockaddr*>(&target),sizeof(target))==3);
    REQUIRE(receiver.WaitReadable(500));
  };
  std::array<uint8_t,8> data{};N_XSOCKADDR_IN source{};uint32_t size=sizeof(source);
  send();CHECK(receiver.RecvFrom(data.data(),uint32_t(data.size()),0,&source,&size)==-1);
  packet=Registered(auth.peers[0],peer.address,4);
  REQUIRE(NatProbeConsume(receiver.native_handle(),packet.data(),56,peer.address.ipv4,peer.address.port));
  send();REQUIRE(receiver.RecvFrom(data.data(),uint32_t(data.size()),0,&source,&size)==3);
  CHECK(std::memcmp(data.data(),"abc",3)==0);
  CHECK(uint32_t(source.sin_addr)==ntohl(auth.peers[0].logical.ipv4));
  CHECK(uint16_t(source.sin_port)==1000);
}
} // namespace rex::system::xam
