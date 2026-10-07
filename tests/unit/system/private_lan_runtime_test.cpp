#include <catch2/catch_test_macros.hpp>
#include <rex/platform.h>
#include <rex/system/xam/private_lan_authority.h>
#include <rex/system/xam/private_lan_payload.h>
#include <rex/system/xsocket.h>
#include <rex/cvar.h>
#include <array>
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <set>
#include <thread>
#include <cstdlib>
#include <cstring>
#if REX_PLATFORM_GNU_LINUX
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <openssl/crypto.h>
#endif
namespace rex::system::xam {
#if REX_PLATFORM_GNU_LINUX
namespace {
using LanClock=std::chrono::steady_clock;
constexpr uint32_t kPrivateFixtureTitle=0x58410A7A;
void Put(std::vector<uint8_t>& bytes,uint64_t value,size_t length) {
  for(size_t i=0;i<length;++i) bytes.push_back(uint8_t(value>>((length-i-1)*8)));
}
uint64_t Get(std::span<const uint8_t> bytes,size_t& at,size_t length) {
  REQUIRE(at+length<=bytes.size()); uint64_t value=0;
  for(size_t i=0;i<length;++i)value=(value<<8)|bytes[at++]; return value;
}
void Append(std::vector<uint8_t>& bytes,std::span<const uint8_t> value) {bytes.insert(bytes.end(),value.begin(),value.end());}
void Save(const std::filesystem::path& path,std::span<const uint8_t> bytes) {
  const auto temporary=path.string()+".tmp";
  const int fd=::open(temporary.c_str(),O_WRONLY|O_CREAT|O_TRUNC|O_CLOEXEC|O_NOFOLLOW,0600);
  REQUIRE(fd>=0);const auto count=::write(fd,bytes.data(),bytes.size());::close(fd);
  REQUIRE(count==ssize_t(bytes.size()));REQUIRE(::rename(temporary.c_str(),path.c_str())==0);
}
std::optional<std::vector<uint8_t>> Load(const std::filesystem::path& path,size_t maximum) {
  std::ifstream input(path,std::ios::binary);if(!input)return std::nullopt;
  std::vector<uint8_t> bytes(maximum+1);input.read(reinterpret_cast<char*>(bytes.data()),bytes.size());
  const auto count=input.gcount();if(count<0||size_t(count)>maximum)return std::nullopt;
  bytes.resize(size_t(count));return bytes;
}
void Mark(const std::filesystem::path& root,std::string_view name) {
  const std::array<uint8_t,1> byte{1};Save(root/std::string(name),byte);
}
struct PrivateRuntimeUdp {
  XSocket endpoint{nullptr};uint64_t socket=uint64_t(-1);LanAddress address{};
  PrivateRuntimeUdp() {
    REQUIRE(endpoint.Initialize(XSocket::X_AF_INET,XSocket::X_SOCK_DGRAM,XSocket::X_IPPROTO_UDP)==X_STATUS_SUCCESS);
    N_XSOCKADDR_IN bound{};bound.sin_family=AF_INET;bound.sin_addr=INADDR_LOOPBACK;
    REQUIRE(endpoint.Bind(&bound,sizeof(bound))==X_STATUS_SUCCESS);
    REQUIRE(endpoint.SetNonBlocking(true)==X_STATUS_SUCCESS);socket=endpoint.native_handle();
    sockaddr_in native{};socklen_t length=sizeof(native);
    REQUIRE(getsockname(socket,reinterpret_cast<sockaddr*>(&native),&length)==0);
    address={native.sin_addr.s_addr,ntohs(native.sin_port)};
    NatProbeAttach(socket,NatProbeRole::kGameplay,address);
  }
};
std::vector<uint8_t> PublicIdentity(const ArbitrationIdentity& identity) {
  std::vector<uint8_t> bytes;Append(bytes,identity.session_id);Append(bytes,identity.exchange_key);
  Append(bytes,identity.incarnation);Put(bytes,identity.nonce,8);Put(bytes,identity.host_xuid,8);Put(bytes,identity.host_machine_id,8);
  return bytes;
}
ArbitrationIdentity ReadIdentity(std::span<const uint8_t> bytes) {
  REQUIRE(bytes.size()==64);ArbitrationIdentity identity;size_t at=0;
  std::copy_n(bytes.begin(),8,identity.session_id.begin());at+=8;
  std::copy_n(bytes.begin()+at,16,identity.exchange_key.begin());at+=16;
  std::copy_n(bytes.begin()+at,16,identity.incarnation.begin());at+=16;
  identity.nonce=Get(bytes,at,8);identity.host_xuid=Get(bytes,at,8);identity.host_machine_id=Get(bytes,at,8);return identity;
}
std::vector<uint8_t> ClaimBytes(const PrivateLanJoinClaim& claim,std::span<const uint8_t> proof) {
  std::vector<uint8_t> bytes;Put(bytes,claim.xuid,8);Put(bytes,claim.machine_id,8);
  Put(bytes,ntohl(claim.endpoint.ipv4),4);Put(bytes,claim.endpoint.port,2);
  Append(bytes,claim.challenge);Append(bytes,claim.request_id);Append(bytes,claim.client_public_key);Append(bytes,proof);
  return bytes;
}
std::pair<PrivateLanJoinClaim,PrivateLanInvitation::Tag> ReadClaim(std::span<const uint8_t> bytes) {
  REQUIRE(bytes.size()==102);PrivateLanJoinClaim claim;PrivateLanInvitation::Tag proof{};size_t at=0;
  claim.xuid=Get(bytes,at,8);claim.machine_id=Get(bytes,at,8);claim.endpoint.ipv4=htonl(uint32_t(Get(bytes,at,4)));
  claim.endpoint.port=uint16_t(Get(bytes,at,2));std::copy_n(bytes.begin()+at,16,claim.challenge.begin());at+=16;
  std::copy_n(bytes.begin()+at,16,claim.request_id.begin());at+=16;
  std::copy_n(bytes.begin()+at,32,claim.client_public_key.begin());at+=32;
  std::copy_n(bytes.begin()+at,16,proof.begin());return {claim,proof};
}
std::vector<uint8_t> EnvelopeBytes(const PrivateLanPayloadEnvelope& envelope,const ArbitrationToken& request) {
  std::vector<uint8_t> bytes;Append(bytes,request);Append(bytes,envelope.payload.server_public_key);
  Append(bytes,envelope.payload.iv);Append(bytes,envelope.payload.tag);Append(bytes,envelope.invitation_proof);
  Put(bytes,envelope.payload.ciphertext.size(),2);Append(bytes,envelope.payload.ciphertext);return bytes;
}
std::optional<PrivateLanPayloadEnvelope> ReadEnvelope(std::span<const uint8_t> bytes,const ArbitrationToken& request) {
  if(bytes.size()<94||!std::equal(request.begin(),request.end(),bytes.begin()))return std::nullopt;
  PrivateLanPayloadEnvelope envelope;size_t at=16;
  std::copy_n(bytes.begin()+at,32,envelope.payload.server_public_key.begin());at+=32;
  std::copy_n(bytes.begin()+at,12,envelope.payload.iv.begin());at+=12;
  std::copy_n(bytes.begin()+at,16,envelope.payload.tag.begin());at+=16;
  std::copy_n(bytes.begin()+at,16,envelope.invitation_proof.begin());at+=16;
  const size_t count=Get(bytes,at,2);if(!count||count>kMaximumArbitrationPayload||bytes.size()!=at+count)return std::nullopt;
  envelope.payload.ciphertext.assign(bytes.begin()+at,bytes.end());return envelope;
}
void Adopt(const std::shared_ptr<SessionRecord>& session,const GameplayAuthorization& authorization) {
  {std::lock_guard lock(*session->mutex);
    session->info.id=authorization.xbox_session;session->host_xuid=authorization.host_xuid;
    std::vector<SessionMember> members;
    SessionMember local{authorization.xuid,"PrivateFixture",0,true,false,false};
    local.gameplay_admission=std::make_shared<const GameplayAdmissionBinding>(GameplayAdmissionBinding{
        authorization.directory_session,authorization.admission_attempt,authorization.admission_generation});members.push_back(local);
    for(const auto& peer:authorization.peers) {
      SessionMember member{peer.xuid,"Peer",0,false,false,false};
      member.gameplay_admission=std::make_shared<const GameplayAdmissionBinding>(GameplayAdmissionBinding{
          authorization.directory_session,peer.admission_attempt,peer.admission_generation});members.push_back(member);
    }
    session->members=std::move(members);
  }
  REQUIRE(InstallGameplayAuthorization(session,authorization));
}
} // namespace
#endif
TEST_CASE("private LAN invitation tickets protect three real independent runtime sockets", "[.private-lan-integration]") {
#if REX_PLATFORM_GNU_LINUX
  const char* root_env=std::getenv("HARMONY_PRIVATE_LAN_FIXTURE");const char* role_env=std::getenv("HARMONY_PRIVATE_LAN_ROLE");
  if(!root_env||!role_env)SKIP("Run tools/private_lan_runtime_audit.py");
  const std::filesystem::path root(root_env);const uint64_t local=std::stoull(role_env);
  REQUIRE((local==1||local==2||local==3));
  REXCVAR_SET(lan_bind_address,std::string("127.0.0.1"));REXCVAR_SET(lan_gameplay_port,0u);
  const auto invitation=PrivateLanInvitation::Load((root/"invitations"/(local==1?"host.hpli":("client-"+std::string(15,'0')+std::to_string(local)+".hpli"))).string());
  REQUIRE(invitation);
  auto gameplay=std::make_unique<PrivateRuntimeUdp>();auto session=std::make_shared<SessionRecord>();
  ArbitrationIdentity identity;std::unique_ptr<PrivateLanAuthority> authority;
  std::optional<EphemeralArbitrationKey> key;PrivateLanJoinClaim own_claim;
  std::optional<GameplayAuthorization> authorization;
  uint64_t rpc_sequence=0;
  auto initialize_claim=[&] {
    key=NewArbitrationKey();REQUIRE(key);own_claim.xuid=local;own_claim.machine_id=local*11;
    own_claim.endpoint=gameplay->address;own_claim.challenge=*NewArbitrationToken();
    own_claim.client_public_key=key->public_key();own_claim.request_id=*NewArbitrationToken();rpc_sequence=0;
  };
  if(local==1) {
    SessionRegistry registry;auto hosted=registry.Create(1,"Host",gameplay->address,1,3,3);REQUIRE(hosted);
    identity={hosted->info.id,hosted->info.key,hosted->arbitration_incarnation,hosted->nonce,1,hosted->host_machine_id};
    authority=PrivateLanAuthority::Create(kPrivateFixtureTitle,identity,gameplay->address,invitation);REQUIRE(authority);
    Save(root/"identity",PublicIdentity(identity));
  } else {
    auto bytes=Load(root/"identity",64);REQUIRE(bytes);identity=ReadIdentity(*bytes);initialize_claim();
  }
  bool departed=false,rejoined=false,removed=false;
  if(local!=1) {
    auto bad_claim=own_claim;std::optional<PrivateLanInvitation::Tag> bad_proof;
    if(local==2) {
      auto wrong=PrivateLanInvitation::Load((root/"wrong-invitations/client-0000000000000002.hpli").string());REQUIRE(wrong);
      bad_proof=wrong->Proof(local,"lan-private-join-claim-v1",PrivateLanJoinTranscript(kPrivateFixtureTitle,identity,bad_claim));
    } else {
      bad_claim.xuid=2;
      bad_proof=invitation->Proof(local,"lan-private-join-claim-v1",PrivateLanJoinTranscript(kPrivateFixtureTitle,identity,bad_claim));
    }
    REQUIRE(bad_proof);Save(root/("claim-"+std::to_string(local)),ClaimBytes(bad_claim,*bad_proof));
  }
  const auto started=LanClock::now();auto deadline=started+std::chrono::seconds(50);
  auto last_received=started;auto next_rpc=LanClock::time_point{};
  auto next_send=LanClock::time_point{};std::set<uint64_t> received;bool bound=false,reported=false;
  while(LanClock::now()<deadline&&!std::filesystem::exists(root/"stop")) {
    if(local!=1&&!std::filesystem::exists(root/("rejected-"+std::to_string(local)))) {
      std::this_thread::sleep_for(std::chrono::milliseconds(2));continue;
    }
    if(std::filesystem::exists(root/"depart2")&&!removed&&local==1) {
      REQUIRE(authority->Remove(2));removed=true;Mark(root,"1.removed");
    }
    if(std::filesystem::exists(root/"depart2")&&!departed&&local==2) {
      RevokeGameplayAuthorization(session,local);gameplay.reset();authorization.reset();bound=false;
      departed=true;Mark(root,"2.departed");
    }
    if(departed&&!rejoined&&local==2) {
      if(!std::filesystem::exists(root/"rejoin2")) {std::this_thread::sleep_for(std::chrono::milliseconds(2));continue;}
      gameplay=std::make_unique<PrivateRuntimeUdp>();session=std::make_shared<SessionRecord>();
      initialize_claim();rejoined=true;received.clear();reported=false;next_rpc=LanClock::time_point{};
    }
    if(local!=2&&!rejoined&&std::filesystem::exists(root/"rejoin2")) {
      rejoined=true;received.clear();reported=false;
    }
    if(LanClock::now()>=next_rpc) {
      if(local==1) {
        for(uint64_t client:{2,3}) {
          auto bytes=Load(root/("claim-"+std::to_string(client)),102);if(!bytes||bytes->size()!=102)continue;
          auto [claim,proof]=ReadClaim(*bytes);
          auto admission=authority->Prepare(claim,proof);
          if(!admission) {
            Mark(root,"rejected-"+std::to_string(client));
            if(removed&&client==2&&!std::filesystem::exists(root/"rejoin2"))Mark(root,"retired-replay-rejected");
            continue;
          }
          REQUIRE(claim.xuid==client);
          auto ticket=admission->Ticket(client);REQUIRE(ticket);
          const auto aad=PrivateLanJoinTranscript(kPrivateFixtureTitle,identity,claim);
          auto envelope=SealPrivateLanPayload(*invitation,client,claim.client_public_key,*ticket,aad);
          OPENSSL_cleanse(ticket->data(),ticket->size());REQUIRE(envelope);REQUIRE(admission->Commit());
          Save(root/("reply-"+std::to_string(client)),EnvelopeBytes(*envelope,claim.request_id));
        }
        auto bytes=authority->Ticket(1);REQUIRE(bytes);
        auto ticket=ParsePrivateLanGameplayTicket(kPrivateFixtureTitle,identity,1,*bytes);OPENSSL_cleanse(bytes->data(),bytes->size());
        REQUIRE(ticket);authorization=ticket->authorization;Adopt(session,*authorization);
      } else {
        // The next claim replaces the previous request only after its response
        // is processed below. Each envelope is correlated with this exact ID.
        REQUIRE(rpc_sequence!=UINT64_MAX);++rpc_sequence;
        for(size_t i=0;i<8;++i)own_claim.request_id[8+i]=uint8_t(rpc_sequence>>((7-i)*8));
        const auto aad=PrivateLanJoinTranscript(kPrivateFixtureTitle,identity,own_claim);
        auto proof=invitation->Proof(local,"lan-private-join-claim-v1",aad);REQUIRE(proof);
        Save(root/("claim-"+std::to_string(local)),ClaimBytes(own_claim,*proof));
      }
      next_rpc=LanClock::now()+std::chrono::milliseconds(300);
    }
    if(local!=1) {
      auto bytes=Load(root/("reply-"+std::to_string(local)),94+kMaximumArbitrationPayload);
      if(bytes)if(auto envelope=ReadEnvelope(*bytes,own_claim.request_id)) {
        const auto aad=PrivateLanJoinTranscript(kPrivateFixtureTitle,identity,own_claim);
        auto opened=OpenPrivateLanPayload(*invitation,local,*key,*envelope,aad);REQUIRE(opened);
        auto ticket=ParsePrivateLanGameplayTicket(kPrivateFixtureTitle,identity,local,opened->bytes());REQUIRE(ticket);
        authorization=ticket->authorization;Adopt(session,*authorization);
        if(local==3&&std::filesystem::exists(root/"depart2")&&authorization->peers.size()==1)Mark(root,"3.removed");
        std::filesystem::remove(root/("reply-"+std::to_string(local)));
      }
    }
    if(authorization&&!bound) {REQUIRE(BindGameplaySocket(session,local,gameplay->socket,3074));bound=true;}
    if(bound) {
      std::array<uint8_t,2048> buffer{};N_XSOCKADDR_IN source{};uint32_t length=sizeof(source);
      const int count=gameplay->endpoint.RecvFrom(buffer.data(),buffer.size(),0,&source,&length);
      if(count>=0) {
        REQUIRE(count==39);REQUIRE(uint16_t(source.sin_port)==3074);
        auto peer=GameplayLogicalToXnAddr(htonl(uint32_t(source.sin_addr)));REQUIRE(peer);
        REQUIRE(peer->xuid!=local);for(size_t i=0;i<39;++i)REQUIRE(buffer[i]==uint8_t(peer->xuid+i));received.insert(peer->xuid);last_received=LanClock::now();
      }
      if(LanClock::now()>=next_send) {
        for(const auto& peer:authorization->peers) {
          REQUIRE(peer.authenticated_lan_endpoint);REQUIRE(NatProbeGameplayDestination(gameplay->socket,peer.logical)==peer.authenticated_lan_endpoint);
          N_XSOCKADDR_IN target{};target.sin_family=AF_INET;target.sin_addr=ntohl(peer.logical.ipv4);target.sin_port=3074;
          std::array<uint8_t,39> payload{};for(size_t i=0;i<39;++i)payload[i]=uint8_t(local+i);
          const int sent=gameplay->endpoint.SendTo(payload.data(),payload.size(),0,&target,sizeof(target));REQUIRE(sent==39);
        }
        next_send=LanClock::now()+std::chrono::milliseconds(50);
      }
    }
    if(received.size()==2&&!reported) {Mark(root,std::to_string(local)+(rejoined?".rejoined":".ready"));reported=true;}
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
  }
  CHECK(received.size()==2);CHECK(LanClock::now()-last_received<std::chrono::milliseconds(500));
  CHECK(LanClock::now()-started>std::chrono::seconds(30));RevokeGameplayAuthorization(session,local);
#endif
}
} // namespace rex::system::xam
