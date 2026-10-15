#include "legacy_lan_diagnostics_scope.h"

#include <catch2/catch_test_macros.hpp>
#include <rex/platform.h>
#if REX_PLATFORM_WIN32
#include <winsock2.h>
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <dlfcn.h>
#include <future>
#include <openssl/evp.h>
#endif
#include <rex/system/xam/gameplay_traversal.h>
#include <rex/cvar.h>
#include <rex/system/xsocket.h>
#include <rex/system/xthread.h>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <filesystem>
#include <thread>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <sstream>
#include <rex/system/xam/session_directory.h>

namespace rex::kernel::xam {
struct XNADDR;
u32 NetDll_XNetXnAddrToInAddr_entry(u32, ppc_ptr_t<XNADDR>, mapped_void, mapped_void);
u32 NetDll_XNetInAddrToXnAddr_entry(u32, u32, ppc_ptr_t<XNADDR>, mapped_void);
u32 NetDll_XNetRegisterKey_entry(u32, mapped_void, mapped_void);
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
// Real runtime socket wrapper for the independent admission/server fixture.
struct RuntimeUdp {
  XSocket endpoint{nullptr};
  uint64_t socket=uint64_t(-1);
  LanAddress address{};
  RuntimeUdp() {
    REQUIRE(endpoint.Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,
                                XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS);
    N_XSOCKADDR_IN bind{};bind.sin_family=AF_INET;bind.sin_addr=INADDR_LOOPBACK;
    REQUIRE(endpoint.Bind(&bind,sizeof(bind))==X_STATUS_SUCCESS);
    REQUIRE(endpoint.SetNonBlocking(true)==X_STATUS_SUCCESS);
    socket=endpoint.native_handle();
    sockaddr_in native{};SockLen length=sizeof(native);
    REQUIRE(getsockname(socket,reinterpret_cast<sockaddr*>(&native),&length)==0);
    address={native.sin_addr.s_addr,ntohs(native.sin_port)};
  }
  void Attach() { NatProbeAttach(socket,NatProbeRole::kGameplay,address); }
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
    peer.traffic_key.fill(uint8_t(id)); // Public deterministic test material only.
    peer.xuid=id; peer.member_nonce=std::string(32,char('4'+id));
    peer.admission_attempt=binding->attempt_id; peer.admission_generation=binding->admission_generation;
    peer.logical={htonl(0xf0000000+uint32_t(id)),1000};
    peer.traversal={std::string(32,char('1'+id)),std::string(32,char('5'+id)),"127.0.0.1",39188,0};
    result.peers.push_back(peer);
  }
  return result;
}
std::unique_ptr<GameplayDatagramCipher> PeerCipher(const GameplayPeerAuthorization& peer) {
  GameplayLinkId link{};
  for(size_t i=0;i<link.size();++i) link[i]=uint8_t(std::stoul(peer.traversal.attempt_id.substr(i*2,2),nullptr,16));
  auto cipher=GameplayDatagramCipher::Create(peer.traffic_key,link,peer.traversal.participant^1);
  REQUIRE(cipher);return cipher;
}
void SendProtected(Udp& sender, GameplayDatagramCipher& cipher, const sockaddr_in& target, std::string_view payload) {
  auto wire=cipher.Seal(std::span(reinterpret_cast<const uint8_t*>(payload.data()),payload.size()));REQUIRE(wire);
  REQUIRE(sendto(sender.socket,reinterpret_cast<const char*>(wire->data()),int(wire->size()),0,
                 reinterpret_cast<const sockaddr*>(&target),sizeof(target))==int(wire->size()));
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
  const char* fallback_env = std::getenv("HARMONY_GAMEPLAY_PRIVATE_FALLBACK");
  const bool private_fallback = fallback_env && std::string_view(fallback_env) == "1";
#if REX_PLATFORM_LINUX
  Dl_info loaded{};
  REQUIRE(dladdr(reinterpret_cast<const void*>(&ApplyDiscoveryMemberBatch), &loaded));
  REQUIRE(loaded.dli_fname);
  const auto loaded_path = std::filesystem::canonical(loaded.dli_fname).string();
  REQUIRE(loaded_path.find("librexruntime") != std::string::npos);
  std::printf("{\"kind\":\"loaded_runtime\",\"path\":\"%s\",\"role\":%llu}\n",
              loaded_path.c_str(), static_cast<unsigned long long>(local));
#endif
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
  LegacyLanDiagnosticsScope legacy_lan_diagnostics_0;
  LanDiscoveryService discovery(0x58410A7A,discovery_port,{},[local](uint32_t){return std::optional<uint64_t>(local);},{},false);
  discovery.SetTitleId(0x58410A7A);
  discovery.SetLocalUserIdentity(0,local);
  std::shared_ptr<SessionRecord> session;
  std::unique_ptr<RuntimeUdp> gameplay;
  uint16_t discovery_source_port=0;
  if(local==1) {
    gameplay=std::make_unique<RuntimeUdp>();gameplay->Attach();
    session=registry.Create(1,"FixtureHost",gameplay->address,private_fallback ? 0x42f : 1,
                            private_fallback ? 6 : 3, private_fallback ? 0 : 3);
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
    auto correlated=registry.UpsertDiscovered(std::move(found->session));
    REQUIRE(correlated);
    if (private_fallback) {
      REQUIRE(correlated->max_public_slots == 6);
      REQUIRE(correlated->max_private_slots == 0);
    }
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
    REQUIRE(ready->private_allocation_eligible);
    auto joined=discovery.Join(*correlated,{local,"FixtureClient",0,true,true,false},1000);
    REQUIRE(joined);
    bool local_member_found = false;
    for(auto& member:joined->members) {
      member.local=member.xuid==local;
      if(member.local) {
        local_member_found = true;
        member.user_index = 0;
        member.name = "FixtureClient";
        if (private_fallback) REQUIRE_FALSE(member.private_slot);
        member.gameplay_admission=std::make_shared<const GameplayAdmissionBinding>(
            GameplayAdmissionBinding{ready->directory_session_id,ready->attempt_id,ready->admission_generation});
      }
    }
    REQUIRE(local_member_found);
    // Use the same retained-record publication as XGI JoinLocal. Local
    // projection changes identity metadata but preserves the host's pool.
    const auto retained = correlated;
    REQUIRE(registry.CommitJoinedRecord(correlated, std::move(*joined), [&] {
      return correlated == retained;
    }));
    session = correlated;
    if (private_fallback) {
      CHECK(session->FilledPrivateSlots() == 0);
      const auto member = std::find_if(session->members.begin(), session->members.end(),
          [&](const auto& value) { return value.xuid == local; });
      REQUIRE(member != session->members.end());
      REQUIRE(member->local);
      REQUIRE_FALSE(member->private_slot);
      REQUIRE(member->gameplay_admission);
    }
    discovery.QueueGameplayAdmission(session,0,local,issued->attempt,ready->admission_generation);
    // Create A2 only after the host has had time to complete/retire A1.
    std::this_thread::sleep_for(std::chrono::seconds(2));
    gameplay=std::make_unique<RuntimeUdp>();REQUIRE(gameplay->address.port!=discovery_source_port);
    gameplay->Attach();REQUIRE(BindGameplaySocket(session,local,gameplay->socket,1000));
  }
  std::vector<uint64_t> received;
  auto deadline=Clock::now()+std::chrono::seconds(35);
  auto next_send=Clock::now();
  bool reported=false;
  bool encrypted_wire_observed = false;
  while(Clock::now()<deadline && !std::filesystem::exists(root/"stop")) {
    // Observe the native transport without consuming it. The actual XSocket
    // below must then authenticate/decrypt and preserve every plaintext byte.
    std::array<uint8_t,128> wire{};
    const int wire_count = ::recvfrom(gameplay->socket, reinterpret_cast<char*>(wire.data()),
                                     int(wire.size()), MSG_PEEK, nullptr, nullptr);
    if (wire_count >= 4 && std::memcmp(wire.data(), "HGDP", 4) == 0) {
      REQUIRE(wire_count == 39 + kGameplayDatagramHeaderBytes + kGameplayDatagramTagBytes);
      REQUIRE(wire[4] == 1);
      REQUIRE(wire[7] == kGameplayDatagramHeaderBytes);
      encrypted_wire_observed = true;
    }
    std::array<uint8_t,2048> buffer{};N_XSOCKADDR_IN source{};uint32_t length=sizeof(source);
    int count=gameplay->endpoint.RecvFrom(buffer.data(),buffer.size(),0,&source,&length);
    if(count>=0) {
      REQUIRE(count==39);
      auto identity=GameplayLogicalToXnAddr(htonl(uint32_t(source.sin_addr)));REQUIRE(identity);
      REQUIRE(uint16_t(source.sin_port)==1000);
      REQUIRE(buffer[0]==identity->xuid);
      for(size_t i=1;i<39;++i) REQUIRE(buffer[i]==uint8_t(identity->xuid+i));
      if(std::find(received.begin(),received.end(),identity->xuid)==received.end())received.push_back(identity->xuid);
    }
    if(Clock::now()>=next_send) {
      for(uint64_t peer:{1,2,3}) {
        if(peer==local)continue;
        auto logical=GameplayXnAddrToLogical(session->info.id,ReconstructXnAddrIdentity(peer));
        if(!logical)continue;
        auto native=NatProbeGameplayDestination(gameplay->socket,logical->logical);
        if(!native)continue;
        std::array<uint8_t,39> payload{};for(size_t i=0;i<payload.size();++i)payload[i]=uint8_t(local+i);
        N_XSOCKADDR_IN target{};target.sin_family=AF_INET;
        target.sin_addr=ntohl(logical->logical.ipv4);target.sin_port=logical->logical.port;
        const int sent=gameplay->endpoint.SendTo(payload.data(),payload.size(),0,&target,sizeof(target));
        if(sent<0) {
          REQUIRE((errno==EWOULDBLOCK||errno==EAGAIN));
        } else REQUIRE(sent==39);
      }
      next_send=Clock::now()+std::chrono::milliseconds(80);
    }
    if(received.size()==2 && encrypted_wire_observed && !reported) {
      std::ofstream out(root/(std::to_string(local)+".ready"));
      out<<"discovery="<<discovery_source_port<<" gameplay="<<gameplay->address.port<<" peers=2 bytes=39"
         <<" private_eligible=1 public_fallback="<<int(private_fallback)
         <<" private_cap="<<session->max_private_slots<<" encrypted_wire=1";
      reported=true;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
  }
  CHECK(received.size()==2);
  CHECK(encrypted_wire_observed);
  if(local==1) {
    std::lock_guard lock(*session->mutex);
    CHECK(session->members.size()==3);
    CHECK(session->FilledPublicSlots()==(private_fallback ? 3 : 1));
    CHECK(session->FilledPrivateSlots()==(private_fallback ? 0 : 2));
  }
}
} // namespace rex::system::xam

namespace rex::system::xam {
TEST_CASE("XNet failure diagnostics tolerate an unbound native caller", "[gameplay][network][xnet]") {
  using namespace rex::kernel::xam;
  REQUIRE_FALSE(rex::system::XThread::IsInThread());
  std::array<uint8_t, 36> input{};
  uint32_t output = 0x7b7c7d7e;
  const auto address = mapped_void::from_host(&output);
  // Neither direct-return failure may consult absent guest LastError/TLS.
  for (int i = 0; i < 3; ++i) {
    CHECK(NetDll_XNetXnAddrToInAddr_entry(1, nullptr, nullptr, address) == 10022);
    CHECK(NetDll_XNetXnAddrToInAddr_entry(1,
        ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(input.data())),
        nullptr, address) == 10049);
    CHECK(output == 0x7b7c7d7e);
  }
}
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
    // Joiners in 3+ player lobbies hand back other members' runtime-built
    // addresses with an XID that differs from the peer session id; the unique
    // logical address must still resolve.
    auto wrong=session->info.id;wrong[0]^=1;
    address=0;
    CHECK(NetDll_XNetXnAddrToInAddr_entry(1,ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(inverse.data())),
        mapped_void::from_host(wrong.data()),mapped_void::from_host(&address))==0);
    CHECK(address==peer.logical.ipv4);
    // The host relays a third player's address with its own identity bytes;
    // the unique logical address still resolves, with or without an XID.
    auto relayed=inverse;std::fill(relayed.begin()+10,relayed.end(),uint8_t(0x5A));
    address=0;
    CHECK(NetDll_XNetXnAddrToInAddr_entry(1,ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(relayed.data())),
        mapped_void::from_host(wrong.data()),mapped_void::from_host(&address))==0);
    CHECK(address==peer.logical.ipv4);
    address=0;
    CHECK(NetDll_XNetXnAddrToInAddr_entry(1,ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(relayed.data())),
        mapped_void{},mapped_void::from_host(&address))==0);
    CHECK(address==peer.logical.ipv4);
    // The reverse lookup echoes the XID the title used for this member, so the
    // title doesn't take its own peer for a member of another session.
    std::array<uint8_t,36> echoed{};std::array<uint8_t,8> echoed_id{};
    REQUIRE(NetDll_XNetInAddrToXnAddr_entry(1,ntohl(address),
        ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(echoed.data())),mapped_void::from_host(echoed_id.data()))==0);
    CHECK(echoed_id==wrong);
    CHECK(std::equal(input.begin()+10,input.end(),echoed.begin()+10));
  }
}
TEST_CASE("XNet reverse lookups report the title's own XID for session members", "[gameplay][network][xnet]") {
  using namespace rex::kernel::xam;
  // A later session reusing earlier logical addresses with other members does
  // not inherit a remembered XID.
  SessionRegistry next_registry;auto next=next_registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);
  auto next_auth=Ticket(next);
  REQUIRE(InstallGameplayAuthorization(next,next_auth));
  auto reverse=[&](const GameplayPeerAuthorization& peer) {
    std::array<uint8_t,36> out{};std::array<uint8_t,8> id{};
    REQUIRE(NetDll_XNetInAddrToXnAddr_entry(1,ntohl(peer.logical.ipv4),
        ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(out.data())),mapped_void::from_host(id.data()))==0);
    return id;
  };
  // Before the title names any member, a member that reaches it first is
  // reported with the title's registered session key, as the host relays it.
  std::array<uint8_t,8> key_id{0x82,0x7B,0x3F,0xF4,0,0,0,0x14};std::array<uint8_t,16> key{};
  REQUIRE(NetDll_XNetRegisterKey_entry(1,mapped_void::from_host(key_id.data()),mapped_void::from_host(key.data()))==0);
  CHECK(reverse(next_auth.peers[0])==key_id);
  CHECK(reverse(next_auth.peers[1])==key_id);
  // Once the title has named one member of this session with its own XID, a
  // member it has not looked up yet (a newcomer) is reported with that XID too.
  auto title_xid=next->info.id;title_xid[7]^=0x55;
  auto identity=ReconstructXnAddrIdentity(next_auth.peers[0].xuid);
  std::array<uint8_t,36> member{};
  std::memcpy(member.data(),&next_auth.peers[0].logical.ipv4,4);std::memcpy(member.data()+4,&next_auth.peers[0].logical.ipv4,4);
  std::memcpy(member.data()+10,identity.ethernet_address.data(),6);std::memcpy(member.data()+16,identity.online_address.data(),20);
  uint32_t resolved=0;
  REQUIRE(NetDll_XNetXnAddrToInAddr_entry(1,ppc_ptr_t<XNADDR>::from_host(reinterpret_cast<XNADDR*>(member.data())),
      mapped_void::from_host(title_xid.data()),mapped_void::from_host(&resolved))==0);
  CHECK(resolved==next_auth.peers[0].logical.ipv4);
  CHECK(reverse(next_auth.peers[0])==title_xid);
  CHECK(reverse(next_auth.peers[1])==title_xid);
}
TEST_CASE("XSocket protects admitted peer payloads and refuses scoped raw fallback", "[gameplay][network][socket]") {
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
  std::array<std::unique_ptr<GameplayDatagramCipher>,2> decoders{PeerCipher(auth.peers[0]),PeerCipher(auth.peers[1])};
  for(size_t i=0;i<2;++i) {
    N_XSOCKADDR_IN destination{};destination.sin_family=AF_INET;
    destination.sin_addr=i<2?ntohl(auth.peers[i].logical.ipv4):INADDR_LOOPBACK;
    destination.sin_port=i<2?1000:lan.address.port;
    std::array<uint8_t,3> bytes{uint8_t(i),7,9};
    REQUIRE(sender.SendTo(bytes.data(),int(bytes.size()),0,&destination,sizeof(destination))==3);
    auto& receiver=i==0?a:(i==1?b:lan);
    std::array<uint8_t,128> result{};int received=-1;
    auto deadline=Clock::now()+std::chrono::seconds(1);
    while(Clock::now()<deadline && received<0) {
      received=recvfrom(receiver.socket,reinterpret_cast<char*>(result.data()),int(result.size()),0,nullptr,nullptr);
      if(received<0)std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    REQUIRE(received==51);CHECK(std::memcmp(bytes.data(),result.data(),3)!=0);
    std::vector<uint8_t> plain;REQUIRE(decoders[i]->Open(std::span(result).first(received),plain));
    CHECK(std::equal(bytes.begin(),bytes.end(),plain.begin(),plain.end()));
  }
  N_XSOCKADDR_IN raw{};raw.sin_family=AF_INET;raw.sin_addr=INADDR_LOOPBACK;raw.sin_port=lan.address.port;
  std::array<uint8_t,3> body{4,7,9};CHECK(sender.SendTo(body.data(),3,0,&raw,sizeof(raw))==-1);
  std::array<uint8_t,128> raw_wire{};CHECK(recvfrom(lan.socket,reinterpret_cast<char*>(raw_wire.data()),int(raw_wire.size()),0,nullptr,nullptr)==-1);
  N_XSOCKADDR_IN admitted{};admitted.sin_family=AF_INET;admitted.sin_addr=ntohl(auth.peers[0].logical.ipv4);admitted.sin_port=1000;
  CHECK(sender.SendTo(body.data(),3,0,&admitted,1)==-1);CHECK(errno==EINVAL);
  CHECK(sender.SendTo(body.data(),3,0,&admitted,sizeof(admitted)+1)==-1);CHECK(errno==EINVAL);
  CHECK(sender.SendTo(body.data(),3,0,nullptr,1)==-1);CHECK(errno==EINVAL);
  CHECK(sender.SendTo(body.data(),3,0,reinterpret_cast<N_XSOCKADDR_IN*>(1),sizeof(admitted))==-1);CHECK(errno==EFAULT);
  auto invalid_family=admitted;invalid_family.sin_family=AF_INET6;
  CHECK(sender.SendTo(body.data(),3,0,&invalid_family,sizeof(invalid_family))==-1);CHECK(errno==EAFNOSUPPORT);
  CHECK(recvfrom(a.socket,reinterpret_cast<char*>(raw_wire.data()),int(raw_wire.size()),0,nullptr,nullptr)==-1);

  CHECK(sender.SendTo(reinterpret_cast<uint8_t*>(1),3,0,&admitted,sizeof(admitted))==-1);CHECK(errno==EFAULT);
  CHECK(sender.SendTo(reinterpret_cast<uint8_t*>(1),uint32_t(kGameplayMaximumPlaintextBytes+1),0,&admitted,sizeof(admitted))==-1);CHECK(errno==EMSGSIZE);
  sockaddr_in connected{};connected.sin_family=AF_INET;connected.sin_addr.s_addr=a.address.ipv4;connected.sin_port=htons(a.address.port);
  REQUIRE(::connect(sender.native_handle(),reinterpret_cast<sockaddr*>(&connected),sizeof(connected))==0);
  REQUIRE(sender.Send(body.data(),3,0)==3);
  int wire_count=recvfrom(a.socket,reinterpret_cast<char*>(raw_wire.data()),int(raw_wire.size()),0,nullptr,nullptr);REQUIRE(wire_count==51);
  std::vector<uint8_t> plain;REQUIRE(decoders[0]->Open(std::span(raw_wire).first(wire_count),plain));CHECK(plain==std::vector<uint8_t>{4,7,9});
  REQUIRE(sender.SendTo(nullptr,0,0,nullptr,0)==0);
  wire_count=recvfrom(a.socket,reinterpret_cast<char*>(raw_wire.data()),int(raw_wire.size()),0,nullptr,nullptr);REQUIRE(wire_count==48);
  REQUIRE(decoders[0]->Open(std::span(raw_wire).first(wire_count),plain));CHECK(plain.empty());
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
  auto peer_cipher=PeerCipher(auth.peers[0]);
  auto send=[&] {
    SendProtected(peer,*peer_cipher,target,"abc");
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

namespace rex::system::xam {
TEST_CASE("admitted XSocket refuses unknown and revoked native sources including empty and peek", "[gameplay-source][gameplay][socket][security]") {
  Udp peer, stranger, rendezvous;
  XSocket receiver(nullptr);
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS);
  N_XSOCKADDR_IN bind_address{};bind_address.sin_family=AF_INET;bind_address.sin_addr=INADDR_ANY;bind_address.sin_port=0;
  REQUIRE(receiver.Bind(&bind_address,sizeof(bind_address))==X_STATUS_SUCCESS);
  REQUIRE(receiver.SetNonBlocking(true)==X_STATUS_SUCCESS);
  sockaddr_in target{};SockLen native_size=sizeof(target);
  REQUIRE(getsockname(receiver.native_handle(),reinterpret_cast<sockaddr*>(&target),&native_size)==0);
  target.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
  SessionRegistry registry;auto session=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);
  auto auth=Ticket(session);
  for(auto& entry:auth.peers) entry.traversal.port=rendezvous.address.port;
  NatProbeAttach(receiver.native_handle(),NatProbeRole::kGameplay,{target.sin_addr.s_addr,ntohs(target.sin_port)});
  REQUIRE(InstallGameplayAuthorization(session,auth));REQUIRE(BindGameplaySocket(session,1,receiver.native_handle(),1000));
  auto packet=Registered(auth.peers[0],peer.address);
  REQUIRE(NatProbeConsume(receiver.native_handle(),packet.data(),56,htonl(INADDR_LOOPBACK),rendezvous.address.port));
  packet=Registered(auth.peers[0],peer.address,4);
  REQUIRE(NatProbeConsume(receiver.native_handle(),packet.data(),56,peer.address.ipv4,peer.address.port));
  auto send=[&](Udp& sender,const char* bytes,int count) {
    REQUIRE(sendto(sender.socket,bytes,count,0,reinterpret_cast<sockaddr*>(&target),sizeof(target))==count);
    REQUIRE(receiver.WaitReadable(500));
  };
  std::array<uint8_t,8> data{};N_XSOCKADDR_IN source{};uint32_t size=sizeof(source);
  auto rejected=[&](Udp& sender,int count,uint32_t flags,bool with_source) {
    CAPTURE(count,flags,with_source);
    std::memset(&source,0xa5,sizeof(source));size=0x55667788;
    const auto before=source;data.fill(0x69);const auto before_data=data;
    send(sender,"bad",count);
    CHECK(receiver.RecvFrom(data.data(),uint32_t(data.size()),flags,with_source?&source:nullptr,&size)==-1);
    CHECK(std::memcmp(&source,&before,sizeof(source))==0);CHECK(size==0x55667788);CHECK(data==before_data);
    CHECK_FALSE(receiver.WaitReadable(0));
  };
  for(int count:{0,3})for(uint32_t flags:{0u,uint32_t(MSG_PEEK)})for(bool with_source:{false,true})
    rejected(stranger,count,flags,with_source);
  // The recv API must use the same admission and receive ownership path.
  for(int count:{0,3})for(uint32_t flags:{0u,uint32_t(MSG_PEEK)}) {
    data.fill(0x69);const auto before_data=data;send(stranger,"bad",count);
    CHECK(receiver.Recv(data.data(),uint32_t(data.size()),flags)==-1);
    CHECK(data==before_data);CHECK_FALSE(receiver.WaitReadable(0));
  }
  // Endpoint membership alone may not authorize any raw bytes, even an empty packet.
  rejected(peer,3,0,true);rejected(peer,0,MSG_PEEK,false);
  auto peer_cipher=PeerCipher(auth.peers[0]);
  // An authenticated empty datagram is valid, and MSG_PEEK leaves it queued.
  for(int count:{0,3}) {
    SendProtected(peer,*peer_cipher,target,std::string_view("abc",count));REQUIRE(receiver.WaitReadable(500));size=sizeof(source);
    REQUIRE(receiver.RecvFrom(data.data(),uint32_t(data.size()),MSG_PEEK,&source,&size)==count);
    CHECK(uint32_t(source.sin_addr)==ntohl(auth.peers[0].logical.ipv4));CHECK(uint16_t(source.sin_port)==1000);
    REQUIRE(receiver.WaitReadable(0));
    REQUIRE(receiver.RecvFrom(data.data(),uint32_t(data.size()),0,&source,&size)==count);
    CHECK_FALSE(receiver.WaitReadable(0));
  }
  REQUIRE(registry.Leave(session->info.id,2));
  rejected(peer,3,0,true);rejected(peer,0,MSG_PEEK,false);
  // Rejected queues yield after32 packets, then continue without admitting bytes.
  for(int i=0;i<40;++i)send(stranger,"bad",3);
  const auto begin=Clock::now();
  CHECK(receiver.RecvFrom(data.data(),uint32_t(data.size()),MSG_PEEK,nullptr,nullptr)==-1);
  CHECK(Clock::now()-begin<std::chrono::milliseconds(100));CHECK(receiver.WaitReadable(0));
  CHECK(receiver.RecvFrom(data.data(),uint32_t(data.size()),0,nullptr,nullptr)==-1);
  CHECK_FALSE(receiver.WaitReadable(0));
}
TEST_CASE("unscoped XSocket retains ordinary native source and peek semantics", "[gameplay-source][socket][network]") {
  Udp peer;XSocket receiver(nullptr);
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS);
  N_XSOCKADDR_IN address{};address.sin_family=AF_INET;address.sin_addr=INADDR_ANY;address.sin_port=0;
  REQUIRE(receiver.Bind(&address,sizeof(address))==X_STATUS_SUCCESS);REQUIRE(receiver.SetNonBlocking(true)==X_STATUS_SUCCESS);
  sockaddr_in target{};SockLen length=sizeof(target);
  REQUIRE(getsockname(receiver.native_handle(),reinterpret_cast<sockaddr*>(&target),&length)==0);target.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
  std::array<uint8_t,8> data{};N_XSOCKADDR_IN from{};uint32_t from_length=sizeof(from);
  for(int count:{0,3}) {
    REQUIRE(sendto(peer.socket,"abc",count,0,reinterpret_cast<sockaddr*>(&target),sizeof(target))==count);REQUIRE(receiver.WaitReadable(500));
    REQUIRE(receiver.RecvFrom(data.data(),uint32_t(data.size()),MSG_PEEK,&from,&from_length)==count);
    CHECK(uint32_t(from.sin_addr)==INADDR_LOOPBACK);CHECK(uint16_t(from.sin_port)==peer.address.port);
    REQUIRE(receiver.WaitReadable(0));REQUIRE(receiver.RecvFrom(data.data(),uint32_t(data.size()),0,&from,&from_length)==count);
    CHECK_FALSE(receiver.WaitReadable(0));
  }
}
}
namespace rex::system::xam {
TEST_CASE("XSocket filtered NAT control and pending payload cannot spin under peek", "[gameplay-control-peek][gameplay][socket][security]") {
  Udp peer, rendezvous;XSocket receiver(nullptr);
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS);
  N_XSOCKADDR_IN address{};address.sin_family=AF_INET;address.sin_addr=INADDR_ANY;address.sin_port=0;
  REQUIRE(receiver.Bind(&address,sizeof(address))==X_STATUS_SUCCESS);REQUIRE(receiver.SetNonBlocking(true)==X_STATUS_SUCCESS);
  sockaddr_in target{};SockLen length=sizeof(target);REQUIRE(getsockname(receiver.native_handle(),reinterpret_cast<sockaddr*>(&target),&length)==0);target.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
  SessionRegistry registry;auto session=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);auto auth=Ticket(session);
  for(auto& entry:auth.peers)entry.traversal.port=rendezvous.address.port;
  NatProbeAttach(receiver.native_handle(),NatProbeRole::kGameplay,{target.sin_addr.s_addr,ntohs(target.sin_port)});
  REQUIRE(InstallGameplayAuthorization(session,auth));REQUIRE(BindGameplaySocket(session,1,receiver.native_handle(),1000));
  auto packet=Registered(auth.peers[0],peer.address);
  REQUIRE(sendto(rendezvous.socket,reinterpret_cast<char*>(packet.data()),int(packet.size()),0,reinterpret_cast<sockaddr*>(&target),sizeof(target))==56);
  REQUIRE(receiver.WaitReadable(500));
  std::array<uint8_t,128> data{};N_XSOCKADDR_IN source{};uint32_t size=sizeof(source);
  const auto begin=Clock::now();CHECK(receiver.RecvFrom(data.data(),uint32_t(data.size()),MSG_PEEK,&source,&size)==-1);
  CHECK(Clock::now()-begin<std::chrono::milliseconds(100));CHECK_FALSE(receiver.WaitReadable(0));
  REQUIRE(NatProbeIsPendingGameplaySource(receiver.native_handle(),peer.address));
  REQUIRE(sendto(peer.socket,"abc",3,0,reinterpret_cast<sockaddr*>(&target),sizeof(target))==3);REQUIRE(receiver.WaitReadable(500));
  CHECK(receiver.RecvFrom(data.data(),uint32_t(data.size()),MSG_PEEK,&source,&size)==-1);CHECK_FALSE(receiver.WaitReadable(0));
  packet=Registered(auth.peers[0],peer.address,4);
  REQUIRE(sendto(peer.socket,reinterpret_cast<char*>(packet.data()),int(packet.size()),0,reinterpret_cast<sockaddr*>(&target),sizeof(target))==56);
  REQUIRE(receiver.WaitReadable(500));CHECK(receiver.RecvFrom(data.data(),uint32_t(data.size()),MSG_PEEK,&source,&size)==-1);CHECK_FALSE(receiver.WaitReadable(0));
  CHECK_FALSE(NatProbeIsPendingGameplaySource(receiver.native_handle(),peer.address));
  auto peer_cipher=PeerCipher(auth.peers[0]);SendProtected(peer,*peer_cipher,target,"abc");REQUIRE(receiver.WaitReadable(500));
  REQUIRE(receiver.RecvFrom(data.data(),uint32_t(data.size()),MSG_PEEK,&source,&size)==3);CHECK(receiver.WaitReadable(0));
  REQUIRE(receiver.RecvFrom(data.data(),uint32_t(data.size()),0,&source,&size)==3);CHECK(std::memcmp(data.data(),"abc",3)==0);
}
}
namespace rex::system::xam {
TEST_CASE("open gameplay socket stays scoped after its last session owner dies", "[gameplay-source][gameplay][socket][security]") {
  Udp stranger;XSocket receiver(nullptr);
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS);
  N_XSOCKADDR_IN address{};address.sin_family=AF_INET;address.sin_addr=INADDR_ANY;address.sin_port=0;
  REQUIRE(receiver.Bind(&address,sizeof(address))==X_STATUS_SUCCESS);REQUIRE(receiver.SetNonBlocking(true)==X_STATUS_SUCCESS);
  sockaddr_in target{};SockLen length=sizeof(target);REQUIRE(getsockname(receiver.native_handle(),reinterpret_cast<sockaddr*>(&target),&length)==0);target.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
  SessionRegistry registry;auto session=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);auto auth=Ticket(session);
  NatProbeAttach(receiver.native_handle(),NatProbeRole::kGameplay,{target.sin_addr.s_addr,ntohs(target.sin_port)});
  REQUIRE(InstallGameplayAuthorization(session,auth));REQUIRE(BindGameplaySocket(session,1,receiver.native_handle(),1000));
  std::weak_ptr<SessionRecord> weak=session;REQUIRE(registry.Delete(session->info.id));session.reset();REQUIRE(weak.expired());
  REQUIRE(IsAuthorizedGameplaySocket(receiver.native_handle()));
  std::array<uint8_t,8> data{};data.fill(0x69);const auto before=data;
  REQUIRE(sendto(stranger.socket,"bad",3,0,reinterpret_cast<sockaddr*>(&target),sizeof(target))==3);REQUIRE(receiver.WaitReadable(500));
  CHECK(receiver.Recv(data.data(),uint32_t(data.size()),MSG_PEEK)==-1);CHECK(data==before);CHECK_FALSE(receiver.WaitReadable(0));
  // Native close ends the tombstone, including if the descriptor is reused.
  const auto old=receiver.native_handle();REQUIRE(receiver.Close()==X_STATUS_SUCCESS);CHECK_FALSE(IsAuthorizedGameplaySocket(old));
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS);
  REQUIRE(receiver.Bind(&address,sizeof(address))==X_STATUS_SUCCESS);REQUIRE(receiver.SetNonBlocking(true)==X_STATUS_SUCCESS);
  CHECK_FALSE(IsAuthorizedGameplaySocket(receiver.native_handle()));length=sizeof(target);
  REQUIRE(getsockname(receiver.native_handle(),reinterpret_cast<sockaddr*>(&target),&length)==0);target.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
  REQUIRE(sendto(stranger.socket,"abc",3,0,reinterpret_cast<sockaddr*>(&target),sizeof(target))==3);REQUIRE(receiver.WaitReadable(500));
  REQUIRE(receiver.Recv(data.data(),uint32_t(data.size()),0)==3);CHECK(std::memcmp(data.data(),"abc",3)==0);
}
#if REX_PLATFORM_GNU_LINUX
TEST_CASE("staged UDP retains kernel EFAULT for an invalid output buffer", "[gameplay-source][socket][linux]") {
  Udp peer;XSocket receiver(nullptr);
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS);
  N_XSOCKADDR_IN address{};address.sin_family=AF_INET;address.sin_addr=INADDR_ANY;address.sin_port=0;
  REQUIRE(receiver.Bind(&address,sizeof(address))==X_STATUS_SUCCESS);REQUIRE(receiver.SetNonBlocking(true)==X_STATUS_SUCCESS);
  sockaddr_in target{};SockLen length=sizeof(target);REQUIRE(getsockname(receiver.native_handle(),reinterpret_cast<sockaddr*>(&target),&length)==0);target.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
  for(uint32_t flags:{0u,uint32_t(MSG_PEEK)}) {
    REQUIRE(sendto(peer.socket,"abc",3,0,reinterpret_cast<sockaddr*>(&target),sizeof(target))==3);REQUIRE(receiver.WaitReadable(500));
    N_XSOCKADDR_IN source{};std::memset(&source,0xa5,sizeof(source));const auto before=source;uint32_t size=0x77889911;
    CHECK(receiver.RecvFrom(reinterpret_cast<uint8_t*>(8),8,flags,&source,&size)==-1);CHECK(errno==EFAULT);
    CHECK(std::memcmp(&source,&before,sizeof(source))==0);CHECK(size==0x77889911);
    if(flags&MSG_PEEK){std::array<uint8_t,8> valid{};REQUIRE(receiver.Recv(valid.data(),uint32_t(valid.size()),0)==3);}
  }
}
#endif
}
namespace rex::system::xam {
TEST_CASE("XSocket processes complete NAT control independently of guest receive capacity", "[gameplay-small-control][gameplay][socket][security]") {
  for(uint32_t capacity:{0u,1u,8u,128u}) {
  CAPTURE(capacity);
  Udp peer, rendezvous;XSocket receiver(nullptr);
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS);
  N_XSOCKADDR_IN address{};address.sin_family=AF_INET;address.sin_addr=INADDR_ANY;address.sin_port=0;
  REQUIRE(receiver.Bind(&address,sizeof(address))==X_STATUS_SUCCESS);REQUIRE(receiver.SetNonBlocking(true)==X_STATUS_SUCCESS);
  sockaddr_in target{};SockLen length=sizeof(target);REQUIRE(getsockname(receiver.native_handle(),reinterpret_cast<sockaddr*>(&target),&length)==0);target.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
  SessionRegistry registry;auto session=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);auto auth=Ticket(session);
  for(auto& entry:auth.peers)entry.traversal.port=rendezvous.address.port;
  NatProbeAttach(receiver.native_handle(),NatProbeRole::kGameplay,{target.sin_addr.s_addr,ntohs(target.sin_port)});
  REQUIRE(InstallGameplayAuthorization(session,auth));REQUIRE(BindGameplaySocket(session,1,receiver.native_handle(),1000));
  auto packet=Registered(auth.peers[0],peer.address);
  REQUIRE(sendto(rendezvous.socket,reinterpret_cast<char*>(packet.data()),int(packet.size()),0,reinterpret_cast<sockaddr*>(&target),sizeof(target))==56);
  REQUIRE(receiver.WaitReadable(500));
  std::array<uint8_t,128> data{};N_XSOCKADDR_IN source{};uint32_t size=sizeof(source);
  const auto begin=Clock::now();CHECK(receiver.RecvFrom(data.data(),capacity,MSG_PEEK,&source,&size)==-1);
  CHECK(Clock::now()-begin<std::chrono::milliseconds(100));CHECK_FALSE(receiver.WaitReadable(0));
  REQUIRE(NatProbeIsPendingGameplaySource(receiver.native_handle(),peer.address));
  REQUIRE(sendto(peer.socket,"abc",3,0,reinterpret_cast<sockaddr*>(&target),sizeof(target))==3);REQUIRE(receiver.WaitReadable(500));
  CHECK(receiver.RecvFrom(data.data(),capacity,MSG_PEEK,&source,&size)==-1);CHECK_FALSE(receiver.WaitReadable(0));
  packet=Registered(auth.peers[0],peer.address,4);
  REQUIRE(sendto(peer.socket,reinterpret_cast<char*>(packet.data()),int(packet.size()),0,reinterpret_cast<sockaddr*>(&target),sizeof(target))==56);
  REQUIRE(receiver.WaitReadable(500));CHECK(receiver.RecvFrom(data.data(),capacity,MSG_PEEK,&source,&size)==-1);CHECK_FALSE(receiver.WaitReadable(0));
  CHECK_FALSE(NatProbeIsPendingGameplaySource(receiver.native_handle(),peer.address));
  auto peer_cipher=PeerCipher(auth.peers[0]);SendProtected(peer,*peer_cipher,target,"abc");REQUIRE(receiver.WaitReadable(500));
  REQUIRE(receiver.RecvFrom(data.data(),uint32_t(data.size()),MSG_PEEK,&source,&size)==3);CHECK(receiver.WaitReadable(0));
  REQUIRE(receiver.RecvFrom(data.data(),uint32_t(data.size()),0,&source,&size)==3);CHECK(std::memcmp(data.data(),"abc",3)==0);
  }
}
}
#if REX_PLATFORM_GNU_LINUX
#include <sys/mman.h>
#include <limits>
namespace rex::system::xam {
TEST_CASE("staged UDP preserves ordinary truncation and bounded output writes", "[gameplay-source][socket][linux]") {
  Udp peer;XSocket receiver(nullptr);
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS);
  N_XSOCKADDR_IN address{};address.sin_family=AF_INET;address.sin_addr=INADDR_ANY;address.sin_port=0;
  REQUIRE(receiver.Bind(&address,sizeof(address))==X_STATUS_SUCCESS);REQUIRE(receiver.SetNonBlocking(true)==X_STATUS_SUCCESS);
  sockaddr_in target{};SockLen length=sizeof(target);REQUIRE(getsockname(receiver.native_handle(),reinterpret_cast<sockaddr*>(&target),&length)==0);target.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
  auto send=[&] {REQUIRE(sendto(peer.socket,"abc",3,0,reinterpret_cast<sockaddr*>(&target),sizeof(target))==3);REQUIRE(receiver.WaitReadable(500));};
  std::array<uint8_t,8> data{};N_XSOCKADDR_IN source{};uint32_t source_size=0x11223344;
  for(uint32_t flags:{0u,uint32_t(MSG_PEEK)}) {
    data.fill(0x69);std::memset(&source,0xa5,sizeof(source));const auto before=source;source_size=0x11223344;send();
    CHECK(receiver.RecvFrom(data.data(),2,flags,&source,&source_size)==-1);CHECK(errno==EMSGSIZE);
    CHECK(data[0]=='a');CHECK(data[1]=='b');for(size_t i=2;i<data.size();++i)CHECK(data[i]==0x69);
    CHECK(std::memcmp(&source,&before,sizeof(source))==0);CHECK(source_size==0x11223344);
    CHECK(receiver.WaitReadable(0)==bool(flags&MSG_PEEK));
    if(flags&MSG_PEEK)REQUIRE(receiver.Recv(data.data(),uint32_t(data.size()),0)==3);
  }
  // A huge caller declaration does not allocate huge host staging or copy beyond the datagram.
  data.fill(0x69);send();REQUIRE(receiver.Recv(data.data(),std::numeric_limits<uint32_t>::max(),0)==3);
  CHECK(std::memcmp(data.data(),"abc",3)==0);for(size_t i=3;i<data.size();++i)CHECK(data[i]==0x69);
  const auto page=sysconf(_SC_PAGESIZE);REQUIRE(page>0);REQUIRE(page<=1024*1024);
  auto* protected_output=static_cast<uint8_t*>(mmap(nullptr,size_t(page)*2,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0));
  REQUIRE(protected_output!=MAP_FAILED);protected_output[0]=0x69;
  REQUIRE(mprotect(protected_output,size_t(page),PROT_READ)==0);send();
  CHECK(receiver.Recv(protected_output,8,0)==-1);CHECK(errno==EFAULT);CHECK(protected_output[0]==0x69);
  REQUIRE(mprotect(protected_output,size_t(page),PROT_READ|PROT_WRITE)==0);
  REQUIRE(mprotect(protected_output+page,size_t(page),PROT_NONE)==0);send();
  CHECK(receiver.Recv(protected_output+page-1,3,0)==-1);CHECK(errno==EFAULT);
  REQUIRE(munmap(protected_output,size_t(page)*2)==0);
}
}
#endif

#if REX_PLATFORM_GNU_LINUX
namespace rex::system::xam {
TEST_CASE("retiring gameplay descriptor stays fail closed while a native operation owns it",
          "[gameplay-source][gameplay][socket][security][retirement]") {
  XSocket receiver(nullptr);
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM, XSocket::X_IPPROTO_UDP) == X_STATUS_SUCCESS);
  N_XSOCKADDR_IN address{};
  address.sin_family = AF_INET; address.sin_addr = INADDR_LOOPBACK;
  REQUIRE(receiver.Bind(&address, sizeof(address)) == X_STATUS_SUCCESS);
  auto operation = receiver.AcquireNativeLease();
  REQUIRE(operation);
  const auto original = operation.handle();
  SessionRegistry registry;
  auto session = registry.Create(1, "Host", {htonl(INADDR_LOOPBACK), 30742}, 1, 3, 3);
  auto authorization = Ticket(session);
  NatProbeAttach(original, NatProbeRole::kGameplay,
                 {htonl(INADDR_LOOPBACK), ntohs(receiver.bound_port())}, &receiver);
  REQUIRE(InstallGameplayAuthorization(session, authorization));
  REQUIRE(BindGameplaySocket(session, 1, original, 1000));
  REQUIRE(IsAuthorizedGameplaySocket(original));
  REQUIRE(receiver.Close() == X_STATUS_SUCCESS);
  CHECK(operation.retired());
  CHECK(receiver.native_handle() == uint64_t(-1));
  CHECK(IsAuthorizedGameplaySocket(original));
  CHECK_FALSE(NatProbeNormalizeGameplaySource(original, {htonl(INADDR_LOOPBACK), 49188}));
  CHECK(fcntl(static_cast<int>(original), F_GETFD) >= 0);
  operation = {};
  CHECK_FALSE(IsAuthorizedGameplaySocket(original));
  CHECK(fcntl(static_cast<int>(original), F_GETFD) == -1);
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET, XSocket::X_SOCK_DGRAM, XSocket::X_IPPROTO_UDP) == X_STATUS_SUCCESS);
  CHECK_FALSE(IsAuthorizedGameplaySocket(receiver.native_handle()));
}
}
#endif

#if REX_PLATFORM_GNU_LINUX
namespace rex::system::xam {
TEST_CASE("gameplay renewals preserve nonce replay state and retired link identities",
          "[gameplay][security][crypto-renewal]") {
  SessionRegistry registry;
  auto session=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);
  auto auth=Ticket(session);Udp socket;socket.Attach();
  REQUIRE(InstallGameplayAuthorization(session,auth));
  REQUIRE(BindGameplaySocket(session,1,socket.socket,1000));
  auto peer=PeerCipher(auth.peers[0]);
  const std::array<uint8_t,3> message{11,23,37};
  std::vector<uint8_t> plain;
  auto inbound=peer->Seal(message);REQUIRE(inbound);
  REQUIRE(OpenGameplayDatagram(socket.socket,auth.peers[0].logical,*inbound,plain,true));
  CHECK(plain==std::vector<uint8_t>(message.begin(),message.end()));
  auto first=SealGameplayDatagram(socket.socket,auth.peers[0].logical,message);REQUIRE(first);
  REQUIRE(peer->Open(*first,plain));CHECK((*first)[31]==1);
  auto renewed=auth;renewed.expires_at+=std::chrono::seconds(20);
  REQUIRE(InstallGameplayAuthorization(session,renewed));
  plain={91,92};const auto sentinel=plain;
  CHECK_FALSE(OpenGameplayDatagram(socket.socket,auth.peers[0].logical,*inbound,plain,true));
  CHECK(plain==sentinel);
  auto second=SealGameplayDatagram(socket.socket,auth.peers[0].logical,message);REQUIRE(second);
  REQUIRE(peer->Open(*second,plain));CHECK((*second)[31]==2);
  // A rejected replacement must leave the original authority and cipher intact.
  for (int variant=0;variant<5;++variant) {
    auto changed=renewed;
    if(variant==0)changed.peers[0].traffic_key[0]^=1;
    if(variant==1)changed.peers[0].traversal.participant^=1;
    if(variant==2)changed.peers[0].member_nonce[0]='e';
    if(variant==3)changed.peers[0].admission_generation[0]^=1;
    if(variant==4)changed.peers[0].logical.ipv4=htonl(0xf0000064);
    CAPTURE(variant);CHECK_FALSE(InstallGameplayAuthorization(session,changed));
  }
  auto third=SealGameplayDatagram(socket.socket,auth.peers[0].logical,message);REQUIRE(third);
  REQUIRE(peer->Open(*third,plain));CHECK((*third)[31]==3);
  // Omitted links become tombstones; an old ticket cannot restart their nonce.
  auto removed=renewed;removed.peers.erase(removed.peers.begin());
  REQUIRE(InstallGameplayAuthorization(session,removed));
  CHECK_FALSE(SealGameplayDatagram(socket.socket,auth.peers[0].logical,message));
  CHECK_FALSE(InstallGameplayAuthorization(session,renewed));
  auto fresh=renewed;fresh.peers[0].traversal.attempt_id=std::string(32,'9');
  fresh.peers[0].traffic_key.fill(17);
  REQUIRE(InstallGameplayAuthorization(session,fresh));
  plain=sentinel;
  CHECK_FALSE(OpenGameplayDatagram(socket.socket,fresh.peers[0].logical,*inbound,plain,true));
  CHECK(plain==sentinel);
  auto fresh_peer=PeerCipher(fresh.peers[0]);auto fresh_in=fresh_peer->Seal(message);REQUIRE(fresh_in);
  REQUIRE(OpenGameplayDatagram(socket.socket,fresh.peers[0].logical,*fresh_in,plain,true));
  auto fresh_out=SealGameplayDatagram(socket.socket,fresh.peers[0].logical,message);REQUIRE(fresh_out);
  REQUIRE(fresh_peer->Open(*fresh_out,plain));CHECK((*fresh_out)[31]==1);
  // Expiry removes routes, while subsequent valid renewal retains crypto state.
  auto short_lived=fresh;short_lived.expires_at=Clock::now()+std::chrono::milliseconds(20);
  REQUIRE(InstallGameplayAuthorization(session,short_lived));
  std::this_thread::sleep_for(std::chrono::milliseconds(30));
  CHECK_FALSE(SealGameplayDatagram(socket.socket,fresh.peers[0].logical,message));
  REQUIRE(InstallGameplayAuthorization(session,fresh));
  auto after_expiry=SealGameplayDatagram(socket.socket,fresh.peers[0].logical,message);REQUIRE(after_expiry);
  REQUIRE(fresh_peer->Open(*after_expiry,plain));CHECK((*after_expiry)[31]==2);
}

TEST_CASE("blocked ordinary UDP receives a complete encrypted packet after admission",
          "[gameplay][socket][security][admission-race]") {
  Udp peer,rendezvous;
  XSocket receiver(nullptr);
  REQUIRE(receiver.Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,
                             XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS);
  N_XSOCKADDR_IN bind{};bind.sin_family=AF_INET;bind.sin_addr=INADDR_LOOPBACK;
  REQUIRE(receiver.Bind(&bind,sizeof(bind))==X_STATUS_SUCCESS);
  sockaddr_in target{};socklen_t target_length=sizeof(target);
  REQUIRE(getsockname(receiver.native_handle(),reinterpret_cast<sockaddr*>(&target),&target_length)==0);
  NatProbeAttach(receiver.native_handle(),NatProbeRole::kGameplay,
                 {target.sin_addr.s_addr,ntohs(target.sin_port)});
  SessionRegistry registry;auto session=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);
  auto auth=Ticket(session);
  for(auto& entry:auth.peers)entry.traversal.port=rendezvous.address.port;
  std::array<uint8_t,3> bytes{91,92,93};N_XSOCKADDR_IN source{};uint32_t source_length=sizeof(source);
  auto cipher=PeerCipher(auth.peers[0]);const std::array<uint8_t,3> expected{1,2,3};
  auto packet=cipher->Seal(expected);REQUIRE(packet);
  timeval timeout{3,0};
  REQUIRE(setsockopt(receiver.native_handle(),SOL_SOCKET,SO_RCVTIMEO,&timeout,sizeof(timeout))==0);
  std::promise<pid_t> started;int received=-999;
  std::thread waiter([&]{started.set_value(pid_t(syscall(SYS_gettid)));
    received=receiver.RecvFrom(bytes.data(),bytes.size(),0,&source,&source_length);});
  const auto path="/proc/self/task/"+std::to_string(started.get_future().get())+"/syscall";
  bool blocked=false;const auto deadline=Clock::now()+std::chrono::seconds(2);
  while(Clock::now()<deadline) {
    if(auto* input=std::fopen(path.c_str(),"r")) {
      long number=-1;blocked=std::fscanf(input,"%ld",&number)==1&&number==SYS_recvfrom;
      std::fclose(input);if(blocked)break;
    }
    std::this_thread::yield();
  }
  // Always wake and join the owned waiter before assertions can unwind.
  bool installed=false,bound=false,registered=false,acknowledged=false;
  if(blocked) {
    installed=InstallGameplayAuthorization(session,auth);
    bound=installed&&BindGameplaySocket(session,1,receiver.native_handle(),1000);
    auto control=Registered(auth.peers[0],peer.address);
    registered=bound&&NatProbeConsume(receiver.native_handle(),control.data(),control.size(),
                                    htonl(INADDR_LOOPBACK),rendezvous.address.port);
    control=Registered(auth.peers[0],peer.address,4);
    acknowledged=registered&&NatProbeConsume(receiver.native_handle(),control.data(),control.size(),
                                              peer.address.ipv4,peer.address.port);
  }
  bool sent=packet&&sendto(peer.socket,packet->data(),packet->size(),0,
                         reinterpret_cast<sockaddr*>(&target),sizeof(target))==ssize_t(packet->size());
  // A finite timeout and original-descriptor shutdown prevent a failed fixture
  // from stranding a blocked receive, without weakening runtime policy.
  if(!acknowledged||!sent)receiver.Close();
  waiter.join();
  REQUIRE(blocked);REQUIRE(installed);REQUIRE(bound);REQUIRE(registered);REQUIRE(acknowledged);REQUIRE(sent);
  CHECK(received==3);CHECK(bytes==expected);
  CHECK(uint32_t(source.sin_addr)==ntohl(auth.peers[0].logical.ipv4));
  CHECK(uint16_t(source.sin_port)==1000);CHECK(source_length==sizeof(source));
}
TEST_CASE("private LAN roster cipher routes and authority publish as one transaction", "[gameplay][network][security]") {
  SessionRegistry registry;auto session=registry.Create(1,"AtomicHost",{htonl(INADDR_LOOPBACK),3074},1,3,3);
  auto auth=Ticket(session);Udp local,second,third;
  for(size_t i=0;i<auth.peers.size();++i)auth.peers[i].authenticated_lan_endpoint=i?third.address:second.address;
  auto proposed=session->members;session->members.resize(1);
  REQUIRE(TrackGameplayAdmission(session,1));
  RegisterGameplaySocketCandidate(1,local.socket,3074);
  struct State {bool accept=false;size_t calls=0;};State state;
  auto commit=[](void* context) noexcept {auto& value=*static_cast<State*>(context);++value.calls;return value.accept;};
  local.Attach(NatProbeRole::kDiscovery);
  state.accept=true;
  CHECK_FALSE(CommitPrivateLanGameplayAuthorization(session,auth,proposed,commit,&state));
  CHECK(state.calls==0);CHECK(session->members.size()==1);
  CHECK_FALSE(GameplayAuthorizationCurrent(session,1,auth.member_nonce));
  local.Attach();state.accept=false;
  CHECK_FALSE(CommitPrivateLanGameplayAuthorization(session,auth,proposed,commit,&state));
  CHECK(state.calls==1);CHECK(session->members.size()==1);
  CHECK_FALSE(NatProbeGameplayDestination(local.socket,{auth.peers[0].logical.ipv4,3074}));
  CHECK_FALSE(GameplayAuthorizationCurrent(session,1,auth.member_nonce));
  {
    struct RestoreProvider {~RestoreProvider(){EVP_set_default_properties(nullptr,nullptr);}} restore;
    REQUIRE(EVP_set_default_properties(nullptr,"provider=fsc_nonexistent")==1);
    state.accept=true;
    CHECK_FALSE(CommitPrivateLanGameplayAuthorization(session,auth,proposed,commit,&state));
    CHECK(state.calls==1);CHECK(session->members.size()==1);
  }
  auto duplicate=proposed;duplicate[2].xuid=duplicate[1].xuid;
  CHECK_FALSE(CommitPrivateLanGameplayAuthorization(session,auth,duplicate,commit,&state));CHECK(state.calls==1);
  CHECK_FALSE(CommitPrivateLanGameplayAuthorization(session,auth,proposed,commit,&state,
      [](void*) noexcept {return false;}));
  CHECK(state.calls==1);CHECK(session->members.size()==1);
  REQUIRE(CommitPrivateLanGameplayAuthorization(session,auth,proposed,commit,&state));
  CHECK(state.calls==2);CHECK(session->members.size()==3);
  CHECK(GameplayAuthorizationCurrent(session,1,auth.member_nonce));
  for(size_t i=0;i<auth.peers.size();++i)
    CHECK(NatProbeGameplayDestination(local.socket,{auth.peers[i].logical.ipv4,3074})==auth.peers[i].authenticated_lan_endpoint);
  auto peer_cipher=PeerCipher(auth.peers[0]);const std::array<uint8_t,3> payload{1,2,3};
  auto packet=peer_cipher->Seal(payload);REQUIRE(packet);std::vector<uint8_t> plaintext;
  const auto logical=LanAddress{auth.peers[0].logical.ipv4,3074};
  REQUIRE(OpenGameplayDatagram(local.socket,logical,*packet,plaintext,true));CHECK(plaintext==std::vector<uint8_t>(payload.begin(),payload.end()));
  auto before=SealGameplayDatagram(local.socket,logical,payload);REQUIRE(before);
  auth.expires_at=Clock::now()+std::chrono::seconds(40);
  proposed[0].name="RenewedHost";
  state.accept=false;
  CHECK_FALSE(CommitPrivateLanGameplayAuthorization(session,auth,proposed,commit,&state));
  CHECK(session->members.front().name=="AtomicHost");
  CHECK_FALSE(OpenGameplayDatagram(local.socket,logical,*packet,plaintext,true));
  state.accept=true;
  REQUIRE(CommitPrivateLanGameplayAuthorization(session,auth,proposed,commit,&state));
  CHECK(session->members.front().name=="RenewedHost");
  CHECK_FALSE(OpenGameplayDatagram(local.socket,logical,*packet,plaintext,true));
  auto after=SealGameplayDatagram(local.socket,logical,payload);REQUIRE(after);CHECK(*after!=*before);
  auto reduced=auth;reduced.peers.pop_back();auto roster=proposed;roster.pop_back();
  state.accept=false;
  CHECK_FALSE(CommitPrivateLanGameplayAuthorization(session,reduced,roster,commit,&state));
  CHECK(session->members.size()==3);
  CHECK(NatProbeGameplayDestination(local.socket,{auth.peers[1].logical.ipv4,3074})==third.address);
  state.accept=true;
  REQUIRE(CommitPrivateLanGameplayAuthorization(session,reduced,roster,commit,&state));
  CHECK(session->members.size()==2);
  CHECK_FALSE(NatProbeGameplayDestination(local.socket,{auth.peers[1].logical.ipv4,3074}));
  CHECK_FALSE(SealGameplayDatagram(local.socket,{auth.peers[1].logical.ipv4,3074},payload));
  NatProbeDetach(local.socket);const auto calls=state.calls;
  CHECK_FALSE(CommitPrivateLanGameplayAuthorization(session,reduced,roster,commit,&state));CHECK(state.calls==calls);
  CHECK(session->members.size()==2);
}
} // namespace rex::system::xam
#endif
namespace rex::system::xam {
namespace {
std::array<uint8_t,56> RegisteredWithRelay(const GameplayPeerAuthorization& peer, LanAddress endpoint,
                                           uint16_t relay_port) {
  auto bytes=Registered(peer,endpoint);
  auto port=htons(relay_port);std::memcpy(bytes.data()+52,&port,2);
  return bytes;
}
// Pins the gameplay relay delay for one test, so the real-time probe pump
// cannot switch to the relay before the test's own simulated ticks expect it.
struct GameplayRelayDelay {
  uint32_t previous=REXCVAR_GET(nat_gameplay_relay_after_ms);
  explicit GameplayRelayDelay(uint32_t value) { REXCVAR_SET(nat_gameplay_relay_after_ms,value); }
  ~GameplayRelayDelay() { REXCVAR_SET(nat_gameplay_relay_after_ms,previous); }
};
struct RelayFixture {
  SessionRegistry registry;
  std::shared_ptr<SessionRecord> session=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);
  GameplayAuthorization auth=Ticket(session);
  Udp socket;
  LanAddress direct{htonl(0xC6336401),43000};  // Unreachable public endpoint (TEST-NET-2).
  LanAddress relay{htonl(INADDR_LOOPBACK),30801};
  RelayFixture() {
    socket.Attach();
    REQUIRE(InstallGameplayAuthorization(session,auth));
    REQUIRE(BindGameplaySocket(session,1,uint64_t(socket.socket),1000));
  }
  bool Offer(uint16_t relay_port) {
    auto registration=RegisteredWithRelay(auth.peers[0],direct,relay_port);
    return NatProbeConsume(socket.socket,registration.data(),56,htonl(INADDR_LOOPBACK),39188);
  }
  std::optional<LanAddress> Peer() {
    for(const auto& attempt:NatProbePeerAttempts(socket.socket,false))
      if(attempt.attempt_id==auth.peers[0].traversal.attempt_id) return attempt.peer;
    return std::nullopt;
  }
};
}
TEST_CASE("unacknowledged direct gameplay path falls back to the server relay", "[gameplay][network][relay]") {
  GameplayRelayDelay delay(1000);
  RelayFixture fixture;
  REQUIRE(fixture.Offer(fixture.relay.port));
  NatProbeTickAt(fixture.socket.socket,Clock::now());
  CHECK(fixture.Peer()==fixture.direct);
  NatProbeTickAt(fixture.socket.socket,Clock::now()+std::chrono::milliseconds(1100));
  REQUIRE(fixture.Peer()==fixture.relay);
  CHECK(NatProbeIsPendingGameplaySource(fixture.socket.socket,fixture.relay));
  CHECK_FALSE(NatProbeGameplayDestination(fixture.socket.socket,fixture.auth.peers[0].logical));
  // Later server responses keep reporting the direct endpoint; the relay stays.
  REQUIRE(fixture.Offer(fixture.relay.port));
  CHECK(fixture.Peer()==fixture.relay);
  auto ack=Registered(fixture.auth.peers[0],fixture.relay,4);
  REQUIRE(NatProbeConsume(fixture.socket.socket,ack.data(),56,fixture.relay.ipv4,fixture.relay.port));
  CHECK(NatProbeGameplayDestination(fixture.socket.socket,fixture.auth.peers[0].logical)==fixture.relay);
  CHECK(NatProbeNormalizeGameplaySource(fixture.socket.socket,fixture.relay)==fixture.auth.peers[0].logical);
}
TEST_CASE("relay registration and punches reach the assigned relay port", "[gameplay][network][relay]") {
  GameplayRelayDelay delay(1000);
  Udp relay_socket;
  RelayFixture fixture;
  fixture.relay=relay_socket.address;
  REQUIRE(fixture.Offer(fixture.relay.port));
  auto receive=[&](uint8_t type) {
    for(int i=0;i<50;++i) {
      std::array<uint8_t,64> bytes{};
      const auto count=recv(relay_socket.socket,reinterpret_cast<char*>(bytes.data()),int(bytes.size()),0);
      if(count==56&&std::memcmp(bytes.data(),"HNAT",4)==0&&bytes[5]==type) return true;
      if(count<0) std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
    return false;
  };
  NatProbeTickAt(fixture.socket.socket,Clock::now());
  CHECK(receive(1));  // Credential-bearing registration teaches the relay this socket's mapping.
  CHECK_FALSE(receive(3));  // No punch to the relay while the direct path still has time.
  NatProbeTickAt(fixture.socket.socket,Clock::now()+std::chrono::milliseconds(1100));
  CHECK(receive(3));
}
TEST_CASE("peer punch from the relay address switches this side to the relay", "[gameplay][network][relay]") {
  RelayFixture fixture;
  REQUIRE(fixture.Offer(fixture.relay.port));
  auto punch=Registered(fixture.auth.peers[0],fixture.relay,3);
  CHECK(NatProbeIsControlPacket(fixture.socket.socket,punch.data(),56,fixture.relay.ipv4,fixture.relay.port));
  REQUIRE(NatProbeConsume(fixture.socket.socket,punch.data(),56,fixture.relay.ipv4,fixture.relay.port));
  CHECK(fixture.Peer()==fixture.relay);
  // A different port on the server is not this side's relay.
  RelayFixture other;
  REQUIRE(other.Offer(other.relay.port));
  auto stray=Registered(other.auth.peers[0],{other.relay.ipv4,30999},3);
  CHECK_FALSE(NatProbeIsControlPacket(other.socket.socket,stray.data(),56,other.relay.ipv4,30999));
  CHECK(other.Peer()==other.direct);
}
TEST_CASE("gameplay links fall back to the relay quickly", "[gameplay][network][relay]") {
  // Same-house candidates answer well inside the default delay.
  CHECK(REXCVAR_GET(nat_gameplay_relay_after_ms)==400);
  CHECK(REXCVAR_GET(nat_relay_after_ms)==1000);
  RelayFixture fixture;
  REQUIRE(fixture.Offer(fixture.relay.port));
  const auto start=Clock::now();
  NatProbeTickAt(fixture.socket.socket,start);
  NatProbeTickAt(fixture.socket.socket,start+std::chrono::milliseconds(450));
  CHECK(fixture.Peer()==fixture.relay);
}
TEST_CASE("a same-house gameplay peer keeps the longer relay delay", "[gameplay][network][relay]") {
  // The server saw this side at the peer's public address: both are behind the
  // same home router, whose home-network candidates need the full budget.
  RelayFixture fixture;
  auto registration=RegisteredWithRelay(fixture.auth.peers[0],fixture.direct,fixture.relay.port);
  std::memcpy(registration.data()+40,&fixture.direct.ipv4,4);
  const auto observed_port=htons(41000);std::memcpy(registration.data()+44,&observed_port,2);
  REQUIRE(NatProbeConsume(fixture.socket.socket,registration.data(),56,htonl(INADDR_LOOPBACK),39188));
  const auto start=Clock::now();
  NatProbeTickAt(fixture.socket.socket,start);
  NatProbeTickAt(fixture.socket.socket,start+std::chrono::milliseconds(450));
  CHECK(fixture.Peer()==fixture.direct);
  NatProbeTickAt(fixture.socket.socket,start+std::chrono::milliseconds(1100));
  CHECK(fixture.Peer()==fixture.relay);
}
TEST_CASE("a late direct packet after the relay switch is answered through the relay", "[gameplay][network][relay]") {
  Udp relay_socket;
  RelayFixture fixture;
  fixture.relay=relay_socket.address;
  REQUIRE(fixture.Offer(fixture.relay.port));
  const auto start=Clock::now();
  NatProbeTickAt(fixture.socket.socket,start);
  NatProbeTickAt(fixture.socket.socket,start+std::chrono::milliseconds(450));
  REQUIRE(fixture.Peer()==fixture.relay);
  auto drain=[&] {
    std::array<uint8_t,64> bytes{};
    while(recv(relay_socket.socket,reinterpret_cast<char*>(bytes.data()),int(bytes.size()),0)>0) {}
  };
  auto receive=[&](uint8_t type) {
    for(int i=0;i<50;++i) {
      std::array<uint8_t,64> bytes{};
      const auto count=recv(relay_socket.socket,reinterpret_cast<char*>(bytes.data()),int(bytes.size()),0);
      if(count==56&&std::memcmp(bytes.data(),"HNAT",4)==0&&bytes[5]==type) return true;
      if(count<0) std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
    return false;
  };
  drain();
  // The peer has not switched yet: its direct punch is answered with an ack
  // through the relay, which makes it switch as well.
  auto punch=Registered(fixture.auth.peers[0],fixture.direct,3);
  CHECK(NatProbeIsControlPacket(fixture.socket.socket,punch.data(),56,fixture.direct.ipv4,fixture.direct.port));
  REQUIRE(NatProbeConsume(fixture.socket.socket,punch.data(),56,fixture.direct.ipv4,fixture.direct.port));
  CHECK(receive(4));
  CHECK(fixture.Peer()==fixture.relay);
  drain();
  auto ack=Registered(fixture.auth.peers[0],fixture.direct,4);
  CHECK(NatProbeIsControlPacket(fixture.socket.socket,ack.data(),56,fixture.direct.ipv4,fixture.direct.port));
  REQUIRE(NatProbeConsume(fixture.socket.socket,ack.data(),56,fixture.direct.ipv4,fixture.direct.port));
  CHECK(receive(3));
  CHECK(fixture.Peer()==fixture.relay);
  CHECK_FALSE(NatProbeGameplayDestination(fixture.socket.socket,fixture.auth.peers[0].logical));
  // Any other source is still refused.
  auto stray=Registered(fixture.auth.peers[0],{fixture.direct.ipv4,43001},3);
  CHECK_FALSE(NatProbeIsControlPacket(fixture.socket.socket,stray.data(),56,fixture.direct.ipv4,43001));
}
TEST_CASE("an unacknowledged relay link refreshes its relay registration quickly", "[gameplay][network][relay]") {
  Udp relay_socket;
  RelayFixture fixture;
  fixture.relay=relay_socket.address;
  REQUIRE(fixture.Offer(fixture.relay.port));
  auto count_registrations=[&] {
    int found=0;
    for(int i=0;i<20;++i) {
      std::array<uint8_t,64> bytes{};
      const auto count=recv(relay_socket.socket,reinterpret_cast<char*>(bytes.data()),int(bytes.size()),0);
      if(count==56&&std::memcmp(bytes.data(),"HNAT",4)==0&&bytes[5]==1) ++found;
      if(count<0) std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
    return found;
  };
  const auto start=Clock::now();
  NatProbeTickAt(fixture.socket.socket,start);
  NatProbeTickAt(fixture.socket.socket,start+std::chrono::milliseconds(450));
  REQUIRE(fixture.Peer()==fixture.relay);
  count_registrations();
  NatProbeTickAt(fixture.socket.socket,start+std::chrono::milliseconds(750));
  CHECK(count_registrations()>=1);  // A 1 s refresh would send none here.
}
TEST_CASE("no relay offer or disabled relay keeps the direct path", "[gameplay][network][relay]") {
  {
    RelayFixture fixture;
    REQUIRE(fixture.Offer(0));
    NatProbeTickAt(fixture.socket.socket,Clock::now()+std::chrono::seconds(5));
    CHECK(fixture.Peer()==fixture.direct);
  }
  {
    REXCVAR_SET(nat_relay_enabled,false);
    RelayFixture fixture;
    REQUIRE(fixture.Offer(fixture.relay.port));
    NatProbeTickAt(fixture.socket.socket,Clock::now()+std::chrono::seconds(5));
    CHECK(fixture.Peer()==fixture.direct);
    REXCVAR_SET(nat_relay_enabled,true);
  }
}
}
namespace rex::system::xam {
#if !REX_PLATFORM_WIN32
// Manual end-to-end check against a real directory/relay server. The harness
// supplies two issued gameplay link credentials and, to model carrier NAT,
// blocks direct UDP between the two fixed client ports.
// RELAY_E2E="server_port link host_cap client_cap port0 port1 expect(relay|direct)"
TEST_CASE("gameplay link reaches its peer through a real relay server", "[.relay-e2e]") {
  const char* config=std::getenv("RELAY_E2E");
  REQUIRE(config);
  std::istringstream input(config);
  uint32_t server_port=0,ports[2]{};std::string link,caps[2],expect;
  input>>server_port>>link>>caps[0]>>caps[1]>>ports[0]>>ports[1]>>expect;
  REQUIRE(input);
  int sockets[2];
  LanAddress logical[2]={{htonl(0xf0000001),1000},{htonl(0xf0000002),1000}};
  for(int i=0;i<2;++i) {
    sockets[i]=::socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
    sockaddr_in addr{};addr.sin_family=AF_INET;addr.sin_addr.s_addr=htonl(INADDR_LOOPBACK);
    addr.sin_port=htons(uint16_t(ports[i]));
    REQUIRE(::bind(sockets[i],reinterpret_cast<sockaddr*>(&addr),sizeof(addr))==0);
    REQUIRE(fcntl(sockets[i],F_SETFL,fcntl(sockets[i],F_GETFL,0)|O_NONBLOCK)==0);
    NatProbeAttach(uint64_t(sockets[i]),NatProbeRole::kGameplay,{addr.sin_addr.s_addr,uint16_t(ports[i])});
    REQUIRE(NatProbeInstallGameplayIdentity({link,caps[i],"127.0.0.1",uint16_t(server_port),uint8_t(i)},
        uint64_t(sockets[i]),logical[1-i],Clock::now()+std::chrono::seconds(60)));
  }
  auto pump=[&] {
    for(int i=0;i<2;++i) {
      NatProbeTick(uint64_t(sockets[i]));
      for(;;) {
        std::array<uint8_t,1600> bytes{};sockaddr_in from{};SockLen length=sizeof(from);
        const auto count=recvfrom(sockets[i],bytes.data(),bytes.size(),0,reinterpret_cast<sockaddr*>(&from),&length);
        if(count<=0) break;
        NatProbeConsume(uint64_t(sockets[i]),bytes.data(),size_t(count),from.sin_addr.s_addr,ntohs(from.sin_port));
      }
    }
  };
  std::optional<LanAddress> routes[2];
  const auto started=Clock::now();
  while(Clock::now()-started<std::chrono::seconds(10)&&!(routes[0]&&routes[1])) {
    pump();
    for(int i=0;i<2;++i) routes[i]=NatProbeGameplayDestination(uint64_t(sockets[i]),logical[1-i]);
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
  const auto elapsed=std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now()-started).count();
  INFO("connected after " << elapsed << " ms");
  REQUIRE(routes[0]);REQUIRE(routes[1]);
  for(int i=0;i<2;++i) {
    if(expect=="relay") CHECK(routes[i]->port!=ports[1-i]);
    else CHECK(routes[i]->port==ports[1-i]);
  }
  // A datagram from side 1 arrives at side 0 from side 0's route and maps to side 1.
  sockaddr_in target{};target.sin_family=AF_INET;target.sin_addr.s_addr=routes[1]->ipv4;
  target.sin_port=htons(routes[1]->port);
  REQUIRE(sendto(sockets[1],"payload",7,0,reinterpret_cast<sockaddr*>(&target),sizeof(target))==7);
  bool delivered=false;
  for(int attempt=0;attempt<200&&!delivered;++attempt) {
    std::array<uint8_t,64> bytes{};sockaddr_in from{};SockLen length=sizeof(from);
    const auto count=recvfrom(sockets[0],bytes.data(),bytes.size(),0,reinterpret_cast<sockaddr*>(&from),&length);
    if(count==7&&std::memcmp(bytes.data(),"payload",7)==0) {
      const LanAddress source{from.sin_addr.s_addr,ntohs(from.sin_port)};
      CHECK(source==*routes[0]);
      CHECK(NatProbeNormalizeGameplaySource(uint64_t(sockets[0]),source)==logical[1]);
      delivered=true;
    } else std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
  CHECK(delivered);
  WARN("relay-e2e mode=" << expect << " connected_ms=" << elapsed);
  for(int i=0;i<2;++i) { NatProbeDetach(uint64_t(sockets[i])); close(sockets[i]); }
}
#endif
}
namespace rex::system::xam {
TEST_CASE("public-route joiner reaches its host through the advertised LAN address", "[gameplay][session][network]") {
  // On a cellular/relay (public) route the joiner's SessionInfo::host_address is
  // the host's public endpoint, while the title keeps sending to the LAN
  // endpoint it was advertised in the listing.
  const LanAddress advertised{htonl(0x0A000030),30742};
  const LanAddress public_host{htonl(0xC6336402),30742};  // TEST-NET-2
  SessionRegistry registry;
  auto session=registry.Create(1,"Host",public_host,1,3,3);
  auto binding=std::make_shared<const GameplayAdmissionBinding>(GameplayAdmissionBinding{
      "gameplay-test",std::string(32,'a'),std::string(32,'b')});
  {
    std::lock_guard lock(*session->mutex);
    for(auto& member:session->members) member.local=false;
    session->members.push_back({2,"Joiner",0,true,false,false,binding});
  }
  GameplayAuthorization auth;
  auth.directory_session="gameplay-test"; auth.xbox_session=session->info.id;
  auth.host_xuid=1; auth.xuid=2;
  auth.admission_attempt=binding->attempt_id; auth.admission_generation=binding->admission_generation;
  auth.member_nonce=std::string(32,'1'); auth.member_capability=std::string(32,'2');
  auth.logical={htonl(0xf0000002),1000}; auth.expires_at=Clock::now()+std::chrono::seconds(40);
  GameplayPeerAuthorization host;
  host.traffic_key.fill(1); // Public deterministic test material only.
  host.xuid=1; host.member_nonce=std::string(32,'3');
  host.admission_attempt=std::string(32,'c'); host.admission_generation=std::string(32,'d');
  host.logical={htonl(0xf0000001),1000};
  host.traversal={std::string(32,'4'),std::string(32,'5'),"127.0.0.1",39188,0};
  auth.peers.push_back(host);
  Udp socket;socket.Attach();
  REQUIRE(InstallGameplayAuthorization(session,auth));
  REQUIRE(BindGameplaySocket(session,2,uint64_t(socket.socket),1000));
  const LanAddress native{htonl(INADDR_LOOPBACK),42010};
  auto registration=Registered(host,native);
  REQUIRE(NatProbeConsume(socket.socket,registration.data(),56,htonl(INADDR_LOOPBACK),39188));
  auto ack=Registered(host,native,4);
  REQUIRE(NatProbeConsume(socket.socket,ack.data(),56,native.ipv4,native.port));
  REQUIRE(NatProbeGameplayDestination(socket.socket,host.logical)==native);

  // Without the recorded advertised endpoint the LAN address has no route.
  CHECK_FALSE(GameplayLogicalDestination(socket.socket,{advertised.ipv4,1000}));
  // A joiner on a home-network route keeps reporting its own LAN address.
  CHECK_FALSE(GameplaySelfLogicalAddress(2));
  // Another host or session never lends its advertised address.
  RecordAdvertisedHostAddress(session->info.id,9,advertised);
  auto other_session=session->info.id;other_session[0]^=1;
  RecordAdvertisedHostAddress(other_session,1,advertised);
  CHECK_FALSE(GameplayLogicalDestination(socket.socket,{advertised.ipv4,1000}));

  CHECK_FALSE(GameplaySelfLogicalAddress(2));
  RecordAdvertisedHostAddress(session->info.id,1,advertised);
  // On the public route the joiner reports the logical address the others know it by.
  CHECK(GameplaySelfLogicalAddress(2)==auth.logical);
  CHECK_FALSE(GameplaySelfLogicalAddress(1));
  CHECK(GameplayLogicalDestination(socket.socket,{advertised.ipv4,1000})==host.logical);
  CHECK(GameplayLogicalDestination(socket.socket,{advertised.ipv4,advertised.port})==host.logical);
  CHECK(GameplayGuestSourceAlias(socket.socket,host.logical)==advertised.ipv4);
  // Only the exact advertised address and port (or the guest port) resolve.
  CHECK_FALSE(GameplayLogicalDestination(socket.socket,{htonl(0x0A000031),1000}));
  CHECK_FALSE(GameplayLogicalDestination(socket.socket,{advertised.ipv4,4444}));
  // The public endpoint keeps working as before.
  CHECK(GameplayLogicalDestination(socket.socket,{public_host.ipv4,1000})==host.logical);
}
}
