#include <rex/system/xam/private_lan_discovery.h>
#include <rex/system/xam/private_lan_discovery_wire.h>
#include <rex/platform.h>
#include <algorithm>
#include <cstring>
#include <atomic>
#include <mutex>
#include <thread>
#include <set>
#include "private_lan_crypto.h"
#if REX_PLATFORM_POSIX_ONLINE
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#if REX_PLATFORM_MAC
#include "../net_posix_compat.h"
#endif
#elif REX_PLATFORM_WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#endif
namespace rex::system::xam {
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
namespace {
namespace crypto=lan_crypto;
using Clock=std::chrono::steady_clock;
constexpr uint8_t kQuery=1,kAdvertisement=2,kJoin=3,kLeave=4,kRegister=5,kRegisterReply=6;
using Packet=PrivateLanDiscoveryPublic;
uint64_t Get(const Packet& bytes,size_t at,size_t count) {uint64_t v=0;while(count--)v=(v<<8)|bytes[at++];return v;}
void Put(Packet& bytes,size_t at,uint64_t value,size_t count) {for(size_t i=0;i<count;++i)bytes[at+i]=uint8_t(value>>((count-i-1)*8));}
template<size_t N> std::array<uint8_t,N> Read(const Packet& bytes,size_t at) {std::array<uint8_t,N> v{};std::copy_n(bytes.begin()+at,N,v.begin());return v;}
template<size_t N> void Write(Packet& bytes,size_t at,const std::array<uint8_t,N>& value) {std::copy(value.begin(),value.end(),bytes.begin()+at);}
bool Nonzero(std::span<const uint8_t> bytes){uint8_t v=0;for(auto b:bytes)v|=b;return v!=0;}
ArbitrationIdentity IdentityOf(const SessionRecord& s) {return {s.info.id,s.info.key,s.arbitration_incarnation,s.nonce,s.host_xuid,s.host_machine_id};}
ArbitrationIdentity PacketIdentity(const Packet& p) {return {Read<8>(p,12),Read<16>(p,20),Read<16>(p,452),Get(p,436,8),Get(p,36,8),Get(p,444,8)};}

bool Private(LanAddress a){const auto ip=ntohl(a.ipv4);return a.port&&((ip>>24)==127||(ip>>24)==10||(ip>>20)==0xac1||(ip>>16)==0xc0a8);}
Packet Encode(const SessionRecord& s,uint32_t title) {
  std::lock_guard lock(*s.mutex);Packet p{};Put(p,0,0x5245584c,4);Put(p,4,3,2);p[6]=kAdvertisement;Put(p,8,title,4);
  Write(p,12,s.info.id);Write(p,20,s.info.key);Put(p,36,s.host_xuid,8);
  std::memcpy(p.data()+44,&s.info.host_address.ipv4,4);Put(p,48,s.info.host_address.port,2);
  Put(p,52,s.flags,4);Put(p,56,s.max_public_slots,4);Put(p,60,s.max_private_slots,4);Put(p,64,s.members.size(),4);
  std::memcpy(p.data()+68,s.host_name.data(),std::min(size_t(16),s.host_name.size()));
  for(size_t i=0;i<s.members.size()&&i<8;++i){const auto& m=s.members[i];const auto at=84+i*44;Put(p,at,m.xuid,8);
    Put(p,at+8,(m.local?1:0)|(m.private_slot?2:0)|(m.ready?4:0),4);
    std::memcpy(p.data()+at+12,m.name.data(),std::min(size_t(16),m.name.size()));Put(p,at+28,m.machine_id,8);
    const auto endpoint=m.xuid==s.host_xuid?s.info.host_address:m.gameplay_address;
    std::memcpy(p.data()+at+36,&endpoint.ipv4,4);Put(p,at+40,endpoint.port,2);}
  Put(p,436,s.nonce,8);Put(p,444,s.host_machine_id,8);Write(p,452,s.arbitration_incarnation);return p;
}
std::optional<SessionRecord> Decode(const Packet& p,uint32_t title) {
  if(Get(p,0,4)!=0x5245584c||Get(p,4,2)!=3||Get(p,8,4)!=title||p[6]!=kAdvertisement||
     p[7]||Get(p,50,2)||Get(p,528,4)||Get(p,64,4)>6||!Get(p,36,8)||
     Get(p,56,4)>6||Get(p,60,4)>6||Get(p,56,4)+Get(p,60,4)>6)return std::nullopt;
  SessionRecord s;s.info.id=Read<8>(p,12);s.info.key=Read<16>(p,20);s.host_xuid=Get(p,36,8);
  s.nonce=Get(p,436,8);s.host_machine_id=Get(p,444,8);s.arbitration_incarnation=Read<16>(p,452);
  std::memcpy(&s.info.host_address.ipv4,p.data()+44,4);s.info.host_address.port=uint16_t(Get(p,48,2));
  if(!Private(s.info.host_address)||!s.nonce||!s.host_machine_id||!Nonzero(s.info.id)||!Nonzero(s.info.key)||!Nonzero(s.arbitration_incarnation))return std::nullopt;
  const auto xn=ReconstructXnAddrIdentity(s.host_xuid);s.info.ethernet_address=xn.ethernet_address;s.info.online_address=xn.online_address;
  s.host_name.assign(reinterpret_cast<const char*>(p.data()+68),strnlen(reinterpret_cast<const char*>(p.data()+68),16));
  s.flags=uint32_t(Get(p,52,4));s.max_public_slots=uint32_t(Get(p,56,4));s.max_private_slots=uint32_t(Get(p,60,4));
  std::set<uint64_t> identities,machines;size_t public_slots=0,private_slots=0;
  for(size_t i=0;i<Get(p,64,4);++i){const auto at=84+i*44;const auto flags=Get(p,at+8,4);SessionMember m;
    m.xuid=Get(p,at,8);m.machine_id=Get(p,at+28,8);std::memcpy(&m.gameplay_address.ipv4,p.data()+at+36,4);m.gameplay_address.port=uint16_t(Get(p,at+40,2));
    if(!m.xuid||!m.machine_id||!identities.insert(m.xuid).second||!machines.insert(m.machine_id).second||
       flags&~7u||Get(p,at+42,2)||!Private(m.gameplay_address))return std::nullopt;
    m.name.assign(reinterpret_cast<const char*>(p.data()+at+12),strnlen(reinterpret_cast<const char*>(p.data()+at+12),16));
    m.private_slot=flags&2;m.ready=flags&4;m.private_slot?++private_slots:++public_slots;s.members.push_back(std::move(m));}
  if(!identities.contains(s.host_xuid)||public_slots>s.max_public_slots||private_slots>s.max_private_slots)return std::nullopt;
  return s;
}
PrivateLanJoinClaim Claim(const Packet& p) {
  PrivateLanJoinClaim c;c.xuid=Get(p,84,8);c.machine_id=Get(p,112,8);
  std::memcpy(&c.endpoint.ipv4,p.data()+120,4);c.endpoint.port=uint16_t(Get(p,124,2));
  c.challenge=Read<16>(p,468);c.request_id=Read<16>(p,624);c.client_public_key=Read<32>(p,532);return c;
}
bool Sign(Packet& p,const ArbitrationToken& credential,std::string_view domain) {
  if(domain.empty()||domain.size()>128||!Nonzero(credential))return false;
  std::fill_n(p.begin()+500,16,0);
  constexpr std::string_view prefix="ReXGlue private LAN continuity proof v1";
  std::vector<uint8_t> transcript(prefix.begin(),prefix.end());transcript.push_back(uint8_t(domain.size()));
  transcript.insert(transcript.end(),domain.begin(),domain.end());transcript.insert(transcript.end(),p.begin(),p.end());
  crypto::SensitiveArray<32> proof;if(!crypto::HmacSha256(credential,{transcript},proof.bytes))return false;
  std::copy_n(proof.bytes.begin(),16,p.begin()+500);return true;
}
bool Verify(const Packet& p,const ArbitrationToken& credential,std::string_view domain) {
  auto copy=p;return Sign(copy,credential,domain)&&crypto::Equal(copy.data()+500,p.data()+500,16);
}
void EnvelopeMetadata(Packet& p,const PrivateLanPayloadEnvelope& envelope) {
  Write(p,564,envelope.payload.server_public_key);Write(p,596,envelope.payload.iv);Write(p,608,envelope.payload.tag);
}
bool SameRoster(const SessionRecord& a,const SessionRecord& b) noexcept {
  if(IdentityOf(a)!=IdentityOf(b)||a.state!=b.state||a.flags!=b.flags||a.max_public_slots!=b.max_public_slots||
     a.max_private_slots!=b.max_private_slots||a.info.host_address!=b.info.host_address||a.members.size()!=b.members.size())return false;
  for(size_t i=0;i<a.members.size();++i){const auto& x=a.members[i];const auto& y=b.members[i];
    if(x.xuid!=y.xuid||x.machine_id!=y.machine_id||x.gameplay_address!=y.gameplay_address||x.local!=y.local||
       x.private_slot!=y.private_slot||x.ready!=y.ready||x.name!=y.name||x.gameplay_admission!=y.gameplay_admission)return false;}
  return true;
}
bool Bindings(SessionRecord& s,const GameplayAuthorization& auth,uint64_t local) {
  if(s.members.size()!=auth.peers.size()+1||auth.xuid!=local||s.host_xuid!=auth.host_xuid||s.info.id!=auth.xbox_session)return false;
  for(auto& m:s.members){m.local=m.xuid==local;
    if(m.local)m.gameplay_admission=std::make_shared<const GameplayAdmissionBinding>(GameplayAdmissionBinding{
      auth.directory_session,auth.admission_attempt,auth.admission_generation});
    else {const auto peer=std::find_if(auth.peers.begin(),auth.peers.end(),[&](const auto& p){return p.xuid==m.xuid;});
      if(peer==auth.peers.end()||!peer->authenticated_lan_endpoint||m.gameplay_address!=*peer->authenticated_lan_endpoint)return false;
      m.gameplay_admission=std::make_shared<const GameplayAdmissionBinding>(GameplayAdmissionBinding{
        auth.directory_session,peer->admission_attempt,peer->admission_generation});}}
  return std::any_of(s.members.begin(),s.members.end(),[&](const auto& m){return m.xuid==local&&m.local;});
}
#if REX_PLATFORM_WIN32
using SocketHandle=SOCKET;constexpr SocketHandle kNoSocket=INVALID_SOCKET;
#else
using SocketHandle=int;constexpr SocketHandle kNoSocket=-1;
#endif
struct Socket {
  SocketHandle fd=kNoSocket;
#if REX_PLATFORM_WIN32
  // Balanced per socket; Winsock reference-counts startup and cleanup.
  bool started=false;
  ~Socket(){if(fd!=kNoSocket)::closesocket(fd);if(started)WSACleanup();}
#else
  ~Socket(){if(fd!=kNoSocket)::close(fd);}
#endif
  bool Open(uint16_t port=0) {
#if REX_PLATFORM_WIN32
    WSADATA data{};if(WSAStartup(MAKEWORD(2,2),&data)!=0)return false;started=true;
    fd=::WSASocketW(AF_INET,SOCK_DGRAM,IPPROTO_UDP,nullptr,0,WSA_FLAG_NO_HANDLE_INHERIT);
#elif REX_PLATFORM_MAC
    // No SOCK_CLOEXEC on Darwin: set close-on-exec right after creation.
    fd=::socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
    if(fd!=kNoSocket&&!rex::net::mac::ConfigureSocketDescriptor(fd)){::close(fd);fd=kNoSocket;}
#else
    fd=::socket(AF_INET,SOCK_DGRAM|SOCK_CLOEXEC,IPPROTO_UDP);
#endif
    if(fd==kNoSocket)return false;
    sockaddr_in a{};a.sin_family=AF_INET;a.sin_addr.s_addr=LanDiscoveryService::DetermineLanIpv4();a.sin_port=htons(port);
    const auto ip=ntohl(a.sin_addr.s_addr);if(!((ip>>24)==127||(ip>>24)==10||(ip>>20)==0xac1||(ip>>16)==0xc0a8))return false;
    if(::bind(fd,reinterpret_cast<sockaddr*>(&a),sizeof(a))!=0)return false;
#if REX_PLATFORM_WIN32
    u_long enabled=1;return ::ioctlsocket(fd,FIONBIO,&enabled)==0;
#else
    return fcntl(fd,F_SETFL,fcntl(fd,F_GETFL,0)|O_NONBLOCK)==0;
#endif
  }
};
struct SecretBytes {std::vector<uint8_t>& bytes;~SecretBytes(){crypto::Cleanse(bytes.data(),bytes.size());}};
bool Send(SocketHandle fd,const PrivateLanDiscoveryWire& wire,LanAddress target) {
  if(!Private(target))return false;sockaddr_in a{};a.sin_family=AF_INET;a.sin_addr.s_addr=target.ipv4;a.sin_port=htons(target.port);
#if REX_PLATFORM_WIN32
  return ::sendto(fd,reinterpret_cast<const char*>(wire.data()),int(wire.size()),0,reinterpret_cast<sockaddr*>(&a),sizeof(a))==int(wire.size());
#else
  return ::sendto(fd,wire.data(),wire.size(),0,reinterpret_cast<sockaddr*>(&a),sizeof(a))==ssize_t(wire.size());
#endif
}
std::optional<PrivateLanDiscoveryFrame> Receive(SocketHandle fd,const PrivateLanInvitation& invitation,uint64_t client,uint32_t title,
    PrivateLanDiscoveryDirection direction,LanAddress& source,std::optional<ArbitrationToken> request=std::nullopt) {
  PrivateLanDiscoveryWire wire{};sockaddr_in a{};
#if REX_PLATFORM_WIN32
  // Winsock fails an oversized datagram with WSAEMSGSIZE instead of
  // returning a truncated prefix, so only an exact-size frame is accepted.
  int length=sizeof(a);
  const auto count=::recvfrom(fd,reinterpret_cast<char*>(wire.data()),int(wire.size()),0,reinterpret_cast<sockaddr*>(&a),&length);
  if(count!=int(wire.size())||length!=int(sizeof(a))||a.sin_family!=AF_INET)return std::nullopt;
#elif REX_PLATFORM_MAC
  // Darwin's recvfrom ignores MSG_TRUNC as an input flag and silently returns
  // a truncated prefix; recvmsg reports truncation so only an exact frame passes.
  socklen_t length=sizeof(a);
  const auto count=rex::net::mac::ReceiveReportingTruncation(fd,wire.data(),wire.size(),0,reinterpret_cast<sockaddr*>(&a),&length);
  if(count!=ssize_t(wire.size())||length!=sizeof(a)||a.sin_family!=AF_INET)return std::nullopt;
#else
  socklen_t length=sizeof(a);
  const auto count=::recvfrom(fd,wire.data(),wire.size(),MSG_TRUNC,reinterpret_cast<sockaddr*>(&a),&length);
  if(count!=ssize_t(wire.size())||length!=sizeof(a)||a.sin_family!=AF_INET)return std::nullopt;
#endif
  source={a.sin_addr.s_addr,ntohs(a.sin_port)};if(!Private(source))return std::nullopt;
  return OpenPrivateLanDiscoveryFrame(invitation,client,title,direction,wire,request);
}
} // namespace
struct PrivateLanClientBinding::Impl {
  std::mutex mutex;ArbitrationIdentity identity;uint64_t xuid=0,machine=0,counter=0;
  ArbitrationToken challenge{},registration{},prefix{},credential{};std::optional<EphemeralArbitrationKey> key;
  std::atomic<bool> confirmed=false;LanAddress target;std::shared_ptr<const PrivateLanInvitation> invitation;
  Socket socket;
  ~Impl(){crypto::Cleanse(credential.data(),credential.size());}
  std::optional<ArbitrationToken> Request(){if(counter==UINT64_MAX)return std::nullopt;auto request=prefix;++counter;
    for(unsigned i=0;i<8;++i)request[8+i]=uint8_t(counter>>((7-i)*8));return request;}
};
PrivateLanClientBinding::PrivateLanClientBinding(std::unique_ptr<Impl> impl):impl_(std::move(impl)){}
PrivateLanClientBinding::~PrivateLanClientBinding()=default;
bool PrivateLanClientBinding::Confirmed() const noexcept{return impl_->confirmed;}
uint64_t PrivateLanClientBinding::xuid() const noexcept{return impl_->xuid;}
const ArbitrationIdentity& PrivateLanClientBinding::identity() const noexcept{return impl_->identity;}
struct PrivateLanDiscoveryAdapter::Impl {
  uint32_t title;uint16_t port;uint64_t machine;std::shared_ptr<const PrivateLanInvitation> invitation;
  std::shared_ptr<SessionRecord> host;std::atomic<bool> running=false,client_running=false;std::thread thread,client_thread;
  std::weak_ptr<SessionRecord> client;uint64_t client_xuid=0;
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
  std::unique_ptr<Socket> listener;
  struct DepartureReceipt {
    Packet request{};ArbitrationToken proof{};LanAddress source{};
    PrivateLanDiscoveryWire reply{};Clock::time_point deadline{};bool valid=false;
  };
  std::array<DepartureReceipt,5> departure_receipts{};
  void ClearDepartureReceipts() noexcept {
    crypto::Cleanse(departure_receipts.data(),sizeof(departure_receipts));
  }
  std::optional<SessionRecord> Exchange(const SessionRecord& s,const SessionMember& member,uint8_t operation,
      const std::shared_ptr<PrivateLanClientBinding>& binding,uint32_t timeout) {
    if(!invitation||!invitation->Current()||invitation->host()||member.xuid!=invitation->clients().front()||
       !binding||binding->identity()!=IdentityOf(s)||binding->xuid()!=member.xuid)return std::nullopt;
    auto& b=*binding->impl_;auto request=b.Request();if(!request||!b.key)return std::nullopt;
    auto p=Encode(s,title);p[6]=operation;Put(p,64,1,4);std::fill_n(p.begin()+84,44*8,0);Put(p,84,member.xuid,8);
    Put(p,92,(member.private_slot?2:0)|(member.ready?4:0),4);std::memcpy(p.data()+96,member.name.data(),std::min(size_t(16),member.name.size()));
    Put(p,112,b.machine,8);const auto physical=LanDiscoveryService::DetermineLanIpv4();std::memcpy(p.data()+120,&physical,4);
    Put(p,124,REXCVAR_GET(lan_gameplay_port)?REXCVAR_GET(lan_gameplay_port):3074,2);
    Write(p,468,b.challenge);Write(p,532,b.key->public_key());Write(p,624,*request);
    if(Nonzero(b.credential)&&!Sign(p,b.credential,operation==kJoin?"private-lan-join-v1":"private-lan-leave-v1"))return std::nullopt;
    PrivateLanDiscoveryFrame frame;frame.public_packet=p;
    if(operation==kJoin||operation==kLeave){const auto proof=invitation->Proof(member.xuid,operation==kJoin?"lan-private-join-claim-v1":"lan-private-departure-claim-v1",PrivateLanJoinTranscript(title,b.identity,Claim(p)));
      if(!proof)return std::nullopt;frame.join_claim_proof=*proof;}
    const auto deadline=Clock::now()+std::chrono::milliseconds(timeout);auto next=Clock::time_point{};
    while(Clock::now()<deadline) {
      if(Clock::now()>=next){auto wire=SealPrivateLanDiscoveryFrame(*invitation,member.xuid,title,PrivateLanDiscoveryDirection::kRequest,frame);
        if(!wire||!Send(b.socket.fd,*wire,b.target))return std::nullopt;next=Clock::now()+std::chrono::milliseconds(125);}
      LanAddress source;auto reply=Receive(b.socket.fd,*invitation,member.xuid,title,PrivateLanDiscoveryDirection::kReply,source,*request);
      if(reply&&source==b.target&&PacketIdentity(reply->public_packet)==b.identity&&Read<16>(reply->public_packet,468)==b.challenge) {
        auto decoded=Decode(reply->public_packet,title);if(!decoded)return std::nullopt;
        if(operation==kJoin) {
          if(!reply->payload||Read<32>(reply->public_packet,532)!=b.key->public_key())continue;
          auto secret=OpenPrivateLanPayload(*invitation,member.xuid,*b.key,*reply->payload,PrivateLanJoinTranscript(title,b.identity,Claim(p)));
          if(!secret||secret->bytes().size()<16+112)continue;ArbitrationToken credential{};std::copy_n(secret->bytes().begin(),16,credential.begin());
          if(!Nonzero(credential)||!Verify(reply->public_packet,credential,"private-lan-join-reply-v1"))continue;
          auto ticket=ParsePrivateLanGameplayTicket(title,b.identity,member.xuid,secret->bytes().subspan(16));
          if(!ticket||!Bindings(*decoded,ticket->authorization,member.xuid))continue;
          b.credential=credential;decoded->private_lan_gameplay=std::make_shared<const GameplayAuthorization>(std::move(ticket->authorization));
        } else if(!Verify(reply->public_packet,b.credential,"private-lan-leave-reply-v1"))continue;
        decoded->discovery_address=b.target;decoded->private_lan_invitation=invitation;decoded->private_lan_client=binding;
        return decoded;
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    return std::nullopt;
  }
  void Handle(const PrivateLanDiscoveryFrame& frame,LanAddress source) {
    const auto& p=frame.public_packet;const auto xuid=Get(p,84,8);if(!host||!invitation->Selector(xuid))return;
    if(p[6]==kQuery){auto reply=Encode(*host,title);Write(reply,624,Read<16>(p,624));PrivateLanDiscoveryFrame response;response.public_packet=reply;
      if(auto wire=SealPrivateLanDiscoveryFrame(*invitation,xuid,title,PrivateLanDiscoveryDirection::kReply,response))Send(listener->fd,*wire,source);return;}
    if(PacketIdentity(p)!=IdentityOf(*host))return;
    if(p[6]==kLeave)for(const auto& receipt:departure_receipts)
      if(receipt.valid&&Clock::now()<receipt.deadline&&source==receipt.source&&
         crypto::Equal(p.data(),receipt.request.data(),p.size())&&
         crypto::Equal(frame.join_claim_proof.data(),receipt.proof.data(),receipt.proof.size())) {
        Send(listener->fd,receipt.reply,source);return;
      }
    if(p[6]==kRegister){Register(p,source);return;}
    if(p[6]!=kJoin&&p[6]!=kLeave)return;
    auto claim=Claim(p);if(claim.endpoint.ipv4!=source.ipv4||!Private(claim.endpoint)||!claim.machine_id||Get(p,92,4)&~6u)return;
    SessionRecord before;std::shared_ptr<PrivateLanAuthority> authority;ArbitrationToken credential{};ArbitrationJoinClaim arb;
    {
      std::lock_guard lock(*host->mutex);if(host->state==SessionState::kDeleted||!host->arbitration||!host->private_lan_authority)return;
      before=*host;authority=host->private_lan_authority;
      const auto previous=host->arbitration->CredentialForVerification(IdentityOf(*host),xuid,claim.machine_id);
      if(previous){if(!Verify(p,*previous,p[6]==kJoin?"private-lan-join-v1":"private-lan-leave-v1"))return;credential=*previous;}
      else if(p[6]==kLeave||Nonzero(Read<16>(p,500)))return;
      arb={xuid,claim.machine_id,{source.ipv4,source.port},claim.challenge,credential};
    }
    if(p[6]==kLeave){Depart(source,claim,credential,before,authority,frame.join_claim_proof,p);return;}
    auto admission=authority->Prepare(claim,frame.join_claim_proof);if(!admission)return;
    auto host_bytes=admission->Ticket(host->host_xuid),client_bytes=admission->Ticket(xuid);
    if(!host_bytes||!client_bytes)return;SecretBytes clean_host{*host_bytes},clean_client{*client_bytes};
    auto host_ticket=ParsePrivateLanGameplayTicket(title,IdentityOf(before),host->host_xuid,*host_bytes);if(!host_ticket)return;
    SessionRecord candidate=before;const auto existing=std::find_if(candidate.members.begin(),candidate.members.end(),[&](const auto& m){return m.xuid==xuid;});
    if(existing==candidate.members.end()){SessionMember member;member.xuid=xuid;member.machine_id=claim.machine_id;member.gameplay_address=claim.endpoint;
      member.name.assign(reinterpret_cast<const char*>(p.data()+96),strnlen(reinterpret_cast<const char*>(p.data()+96),16));member.private_slot=Get(p,92,4)&2;member.ready=Get(p,92,4)&4;
      candidate.members.push_back(std::move(member));}
    if(candidate.FilledPublicSlots()>candidate.max_public_slots||candidate.FilledPrivateSlots()>candidate.max_private_slots||
       !Bindings(candidate,host_ticket->authorization,host->host_xuid))return;
    const auto token=NewArbitrationToken();if(!token)return;
    ArbitrationJoinResult decision;{
      std::lock_guard lock(*host->mutex);if(!SameRoster(*host,before))return;
      decision=host->arbitration->CheckAdmission(arb,Clock::now());}
    if(!decision.accepted())return;credential=decision.status==ArbitrationStatus::kReplay?decision.credential:*token;
    std::vector<uint8_t> plaintext(credential.begin(),credential.end());SecretBytes clean_plaintext{plaintext};
    plaintext.insert(plaintext.end(),client_bytes->begin(),client_bytes->end());
    auto envelope=SealPrivateLanPayload(*invitation,xuid,claim.client_public_key,plaintext,PrivateLanJoinTranscript(title,IdentityOf(before),claim));if(!envelope)return;
    auto reply=Encode(candidate,title);Write(reply,468,claim.challenge);Write(reply,532,claim.client_public_key);Write(reply,624,claim.request_id);
    EnvelopeMetadata(reply,*envelope);if(!Sign(reply,credential,"private-lan-join-reply-v1"))return;
    PrivateLanDiscoveryFrame response;response.public_packet=reply;response.payload=std::move(envelope);
    auto wire=SealPrivateLanDiscoveryFrame(*invitation,xuid,title,PrivateLanDiscoveryDirection::kReply,response);if(!wire)return;
    auto authorization=std::make_shared<const GameplayAuthorization>(host_ticket->authorization);
    struct Commit {SessionRecord* host;const SessionRecord* before;PrivateLanAuthority::Admission* admission;
      ArbitrationJoinClaim arb;ArbitrationToken credential;std::shared_ptr<const GameplayAuthorization> auth;};
    Commit commit{host.get(),&before,admission.get(),arb,*token,authorization};
    const bool okay=CommitPrivateLanGameplayAuthorization(host,*authorization,std::move(candidate.members),[](void* context) noexcept {
      auto& c=*static_cast<Commit*>(context);return c.admission->CommitIf([&]() noexcept {
        const auto result=c.host->arbitration->Admit(c.arb,c.credential,Clock::now());
        if(!result.accepted())return false;c.host->private_lan_gameplay=std::move(c.auth);return true;});
    },&commit,[](void* context) noexcept {auto& c=*static_cast<Commit*>(context);return SameRoster(*c.host,*c.before);});
    if(okay){
      for(auto& receipt:departure_receipts)if(receipt.valid&&Get(receipt.request,84,8)==xuid)receipt.valid=false;
      host->NotifyStatus();Send(listener->fd,*wire,source);
    }
  }
  void Register(const Packet& p,LanAddress source);
  void Depart(LanAddress source,const PrivateLanJoinClaim& claim,const ArbitrationToken& credential,
      const SessionRecord& before,const std::shared_ptr<PrivateLanAuthority>& authority,std::span<const uint8_t> proof,const Packet& request);
  void RenewHost();
  void Run(){auto refresh=Clock::now();while(running){try {
    LanAddress source;if(auto frame=Receive(listener->fd,*invitation,0,title,PrivateLanDiscoveryDirection::kRequest,source))Handle(*frame,source);
    if(Clock::now()>=refresh){RenewHost();refresh=Clock::now()+std::chrono::seconds(1);}
    }catch(...){/* Fail closed without logging invitation or peer metadata. */}
    std::this_thread::sleep_for(std::chrono::milliseconds(5));}}
#endif
};
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
void PrivateLanDiscoveryAdapter::Impl::Register(const Packet& p,LanAddress source) {
  std::optional<PrivateLanDiscoveryWire> wire;
  {
    std::lock_guard lock(*host->mutex);const auto xuid=Get(p,84,8),machine=Get(p,112,8);
    if(host->state==SessionState::kDeleted||!host->arbitration||IdentityOf(*host)!=PacketIdentity(p)||Get(p,92,4))return;
    const auto credential=host->arbitration->CredentialForVerification(IdentityOf(*host),xuid,machine);
    if(!credential||!Verify(p,*credential,"private-lan-register-v1"))return;
    const auto base_reply=Encode(*host,title);
    const auto snapshot=host->arbitration->RegisterFromVerifiedEndpointIf(
        {IdentityOf(*host),xuid,machine,{source.ipv4,source.port},*credential,Read<16>(p,468)},
        [&](const ArbitrationSnapshot& registered) {
          auto reply=base_reply;reply[6]=kRegisterReply;Write(reply,468,Read<16>(p,468));Write(reply,624,Read<16>(p,624));
          Put(reply,516,registered.revision,8);uint32_t mask=0;
          for(size_t i=0;i<host->members.size();++i)for(const auto& member:registered.registrants)
            if(member.machine_id==host->members[i].machine_id&&member.xuids.size()==1&&member.xuids[0]==host->members[i].xuid)mask|=1u<<i;
          Put(reply,524,mask,4);if(!Sign(reply,*credential,"private-lan-register-reply-v1"))return false;
          PrivateLanDiscoveryFrame frame;frame.public_packet=reply;
          wire=SealPrivateLanDiscoveryFrame(*invitation,xuid,title,PrivateLanDiscoveryDirection::kReply,frame);return bool(wire);
        });
    if(!snapshot)return;
  }
  if(wire)Send(listener->fd,*wire,source);
}
void PrivateLanDiscoveryAdapter::Impl::Depart(LanAddress source,
    const PrivateLanJoinClaim& claim,const ArbitrationToken& credential,const SessionRecord& before,
    const std::shared_ptr<PrivateLanAuthority>& authority,std::span<const uint8_t> proof,const Packet& request) {
  auto admission=authority->PrepareDeparture(claim,proof);if(!admission)return;
  auto bytes=admission->Ticket(before.host_xuid);if(!bytes)return;SecretBytes clean{*bytes};
  auto ticket=ParsePrivateLanGameplayTicket(title,IdentityOf(before),before.host_xuid,*bytes);if(!ticket)return;
  auto candidate=before;std::erase_if(candidate.members,[&](const auto& m){return m.xuid==claim.xuid;});
  if(!Bindings(candidate,ticket->authorization,before.host_xuid))return;
  auto reply=Encode(candidate,title);Write(reply,468,claim.challenge);Write(reply,624,claim.request_id);
  if(!Sign(reply,credential,"private-lan-leave-reply-v1"))return;
  PrivateLanDiscoveryFrame frame;frame.public_packet=reply;
  auto wire=SealPrivateLanDiscoveryFrame(*invitation,claim.xuid,title,PrivateLanDiscoveryDirection::kReply,frame);if(!wire)return;
  DepartureReceipt receipt;receipt.request=request;std::copy_n(proof.begin(),receipt.proof.size(),receipt.proof.begin());
  receipt.source=source;receipt.reply=*wire;receipt.deadline=Clock::now()+std::chrono::seconds(5);receipt.valid=true;
  const auto clients=invitation->clients();const auto client=std::find(clients.begin(),clients.end(),claim.xuid);
  if(client==clients.end())return;const auto receipt_index=size_t(client-clients.begin());
  auto authorization=std::make_shared<const GameplayAuthorization>(std::move(ticket->authorization));
  struct Commit {SessionRecord* host;const SessionRecord* before;PrivateLanAuthority::Admission* admission;
    uint64_t xuid;std::shared_ptr<const GameplayAuthorization> auth;};
  Commit commit{host.get(),&before,admission.get(),claim.xuid,authorization};
  if(CommitPrivateLanGameplayAuthorization(host,*authorization,std::move(candidate.members),[](void* context) noexcept {
    auto& c=*static_cast<Commit*>(context);return c.admission->CommitIf([&]() noexcept {
      if(!c.host->arbitration->RemoveBatch(std::span<const uint64_t>(&c.xuid,1)))return false;c.host->private_lan_gameplay=std::move(c.auth);return true;});
  },&commit,[](void* context) noexcept {auto& c=*static_cast<Commit*>(context);return SameRoster(*c.host,*c.before);})) {
    departure_receipts[receipt_index]=receipt;host->NotifyStatus();Send(listener->fd,*wire,source);
  }
}
void PrivateLanDiscoveryAdapter::Impl::RenewHost() {
  SessionRecord before;std::shared_ptr<PrivateLanAuthority> authority;
  {std::lock_guard lock(*host->mutex);if(host->state==SessionState::kDeleted||!host->private_lan_authority)return;before=*host;authority=host->private_lan_authority;}
  auto expiration=authority->PrepareExpiration();if(!expiration)return;
  auto bytes=expiration->Ticket(before.host_xuid);if(!bytes)return;SecretBytes clean{*bytes};
  auto ticket=ParsePrivateLanGameplayTicket(title,IdentityOf(before),before.host_xuid,*bytes);if(!ticket)return;
  auto candidate=before;const auto& expired=expiration->RemovedMembers();
  std::erase_if(candidate.members,[&](const auto& m){return std::find(expired.begin(),expired.end(),m.xuid)!=expired.end();});
  if(!Bindings(candidate,ticket->authorization,before.host_xuid))return;
  auto authorization=std::make_shared<const GameplayAuthorization>(std::move(ticket->authorization));
  struct Commit {SessionRecord* host;const SessionRecord* before;PrivateLanAuthority::Admission* expiration;
    std::shared_ptr<const GameplayAuthorization> auth;};Commit commit{host.get(),&before,expiration.get(),authorization};
  if(CommitPrivateLanGameplayAuthorization(host,*authorization,std::move(candidate.members),[](void* context) noexcept {
    auto& c=*static_cast<Commit*>(context);return c.expiration->CommitIf([&]() noexcept {
      if(!c.host->arbitration->RemoveBatch(c.expiration->RemovedMembers()))return false;
      c.host->private_lan_gameplay=std::move(c.auth);return true;});
  },&commit,[](void* context) noexcept {auto& c=*static_cast<Commit*>(context);return SameRoster(*c.host,*c.before);})&&!expired.empty())host->NotifyStatus();
}
#endif
PrivateLanDiscoveryAdapter::PrivateLanDiscoveryAdapter(uint32_t title,uint16_t port,uint64_t machine,
    std::shared_ptr<const PrivateLanInvitation> invitation):impl_(std::make_unique<Impl>()) {
  impl_->title=title;impl_->port=port;impl_->machine=machine;impl_->invitation=std::move(invitation);
}
PrivateLanDiscoveryAdapter::~PrivateLanDiscoveryAdapter(){Stop();}
bool PrivateLanDiscoveryAdapter::IsAdvertising() const noexcept{return impl_->running;}
void PrivateLanDiscoveryAdapter::SetTitle(uint32_t title){if(impl_->title==title)return;if(impl_->running||impl_->client_running)Stop();impl_->title=title;}
void PrivateLanDiscoveryAdapter::SetMachine(uint64_t machine){if(impl_->machine==machine)return;if(impl_->running||impl_->client_running)Stop();impl_->machine=machine;}
bool PrivateLanDiscoveryAdapter::Start(const std::shared_ptr<SessionRecord>& session) {
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
  try {
    if(impl_->running&&impl_->host==session)return true;Stop();
    if(!session||!impl_->invitation||!impl_->invitation->host()||!impl_->invitation->Current())return false;
    SessionRecord before;{std::lock_guard lock(*session->mutex);before=*session;}
    if(before.host_xuid!=impl_->invitation->host_xuid()||before.members.size()!=1||!before.members[0].local||before.members[0].xuid!=before.host_xuid||!before.arbitration)return false;
    auto authority=PrivateLanAuthority::Create(impl_->title,IdentityOf(before),before.info.host_address,impl_->invitation);if(!authority)return false;
    auto bytes=authority->Ticket(before.host_xuid);if(!bytes)return false;SecretBytes clean{*bytes};
    auto ticket=ParsePrivateLanGameplayTicket(impl_->title,IdentityOf(before),before.host_xuid,*bytes);if(!ticket)return false;
    auto candidate=before;if(!Bindings(candidate,ticket->authorization,before.host_xuid))return false;
    auto listener=std::make_unique<Socket>();if(!listener->Open(impl_->port))return false;
    auto shared_authority=std::shared_ptr<PrivateLanAuthority>(std::move(authority));
    auto authorization=std::make_shared<const GameplayAuthorization>(std::move(ticket->authorization));
    struct Commit {SessionRecord* session;const SessionRecord* before;std::shared_ptr<PrivateLanAuthority> authority;
      std::shared_ptr<const PrivateLanInvitation> invitation;std::shared_ptr<const GameplayAuthorization> authorization;};
    Commit commit{session.get(),&before,shared_authority,impl_->invitation,authorization};
    if(!CommitPrivateLanGameplayAuthorization(session,*authorization,std::move(candidate.members),[](void* context) noexcept {
      auto& c=*static_cast<Commit*>(context);c.session->private_lan_authority=std::move(c.authority);
      c.session->private_lan_invitation=std::move(c.invitation);c.session->private_lan_gameplay=std::move(c.authorization);return true;
    },&commit,[](void* context) noexcept {auto& c=*static_cast<Commit*>(context);return SameRoster(*c.session,*c.before);}))return false;
    impl_->listener=std::move(listener);impl_->host=session;impl_->running=true;impl_->thread=std::thread([this]{impl_->Run();});return true;
  }catch(...){Stop();return false;}
#else
  (void)session;return false;
#endif
}
void PrivateLanDiscoveryAdapter::StopClient(){impl_->client_running=false;if(impl_->client_thread.joinable())impl_->client_thread.join();impl_->client.reset();}
void PrivateLanDiscoveryAdapter::Stop() {
  impl_->running=false;if(impl_->thread.joinable())impl_->thread.join();StopClient();
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
  impl_->listener.reset();impl_->ClearDepartureReceipts();
#endif
  if(impl_->host){RevokeGameplayAuthorization(impl_->host,impl_->host->host_xuid);std::lock_guard lock(*impl_->host->mutex);
    impl_->host->private_lan_authority.reset();impl_->host->private_lan_gameplay.reset();}
  impl_->host.reset();
}
std::vector<SessionRecord> PrivateLanDiscoveryAdapter::Search(uint32_t timeout,uint32_t max_results) {
  std::vector<SessionRecord> results;
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
  try {
    if(!max_results||!impl_->invitation||impl_->invitation->host()||!impl_->invitation->Current())return results;
    Socket socket;if(!socket.Open())return results;LanAddress target;in_addr host{};
    if(inet_pton(AF_INET,REXCVAR_GET(direct_connect_address).c_str(),&host)!=1)return results;
    target={host.s_addr,impl_->port};if(!Private(target))return results;
    SessionRecord query;query.host_xuid=impl_->invitation->host_xuid();auto packet=Encode(query,impl_->title);packet[6]=kQuery;Put(packet,64,1,4);
    const auto xuid=impl_->invitation->clients().front();Put(packet,84,xuid,8);const auto request=NewArbitrationToken();if(!request)return results;Write(packet,624,*request);
    PrivateLanDiscoveryFrame frame;frame.public_packet=packet;const auto deadline=Clock::now()+std::chrono::milliseconds(timeout);auto next=Clock::time_point{};
    while(Clock::now()<deadline){if(Clock::now()>=next){auto wire=SealPrivateLanDiscoveryFrame(*impl_->invitation,xuid,impl_->title,PrivateLanDiscoveryDirection::kRequest,frame);
        if(!wire||!Send(socket.fd,*wire,target))return results;next=Clock::now()+std::chrono::milliseconds(125);}
      LanAddress source;auto reply=Receive(socket.fd,*impl_->invitation,xuid,impl_->title,PrivateLanDiscoveryDirection::kReply,source,*request);
      if(reply&&source==target){auto decoded=Decode(reply->public_packet,impl_->title);if(decoded&&decoded->host_xuid==impl_->invitation->host_xuid()) {
        decoded->discovery_address=target;decoded->private_lan_invitation=impl_->invitation;results.push_back(std::move(*decoded));break;}}
      std::this_thread::sleep_for(std::chrono::milliseconds(5));}
  }catch(...){results.clear();}
#else
  (void)timeout;(void)max_results;
#endif
  return results;
}
std::optional<SessionRecord> PrivateLanDiscoveryAdapter::Join(const SessionRecord& session,const SessionMember& member,uint32_t timeout) {
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
  try {
    if(!impl_->invitation||impl_->invitation->host()||!impl_->invitation->Current()||member.xuid!=impl_->invitation->clients().front()||
       session.private_lan_invitation!=impl_->invitation||session.host_xuid!=impl_->invitation->host_xuid())return std::nullopt;
    std::shared_ptr<PrivateLanClientBinding> binding;
    {std::lock_guard lock(*session.mutex);if(session.state==SessionState::kDeleted)return std::nullopt;binding=session.private_lan_client;}
    if(!binding){auto state=std::make_unique<PrivateLanClientBinding::Impl>();auto challenge=NewArbitrationToken(),prefix=NewArbitrationToken(),registration=NewArbitrationToken();auto key=NewArbitrationKey();
      if(!challenge||!prefix||!registration||!key||!impl_->machine||!state->socket.Open())return std::nullopt;
      state->identity=IdentityOf(session);state->xuid=member.xuid;state->machine=impl_->machine;state->challenge=*challenge;state->prefix=*prefix;
      state->registration=*registration;state->key=std::move(key);state->target=session.discovery_address;state->invitation=impl_->invitation;
      binding=std::shared_ptr<PrivateLanClientBinding>(new PrivateLanClientBinding(std::move(state)));
      std::lock_guard lock(*session.mutex);if(session.state==SessionState::kDeleted)return std::nullopt;
      if(session.private_lan_client)binding=session.private_lan_client;else session.private_lan_client=binding;}
    std::lock_guard lock(binding->impl_->mutex);const bool pending=!Nonzero(binding->impl_->credential);
    auto result=impl_->Exchange(session,member,kJoin,binding,timeout);
    if(result&&pending)result=impl_->Exchange(*result,member,kJoin,binding,std::min(timeout,250u));
    if(result)binding->impl_->confirmed=true;return result;
  }catch(...){return std::nullopt;}
#else
  (void)session;(void)member;(void)timeout;return std::nullopt;
#endif
}
std::optional<SessionRecord> PrivateLanDiscoveryAdapter::Leave(const SessionRecord& session,uint64_t xuid,uint32_t timeout) {
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
  StopClient();auto binding=session.private_lan_client;if(!binding||binding->xuid()!=xuid||!binding->Confirmed())return std::nullopt;
  std::lock_guard lock(binding->impl_->mutex);SessionMember member;
  {std::lock_guard record_lock(*session.mutex);const auto found=std::find_if(session.members.begin(),session.members.end(),[&](const auto& m){return m.xuid==xuid;});if(found==session.members.end())return std::nullopt;member=*found;}
  auto result=impl_->Exchange(session,member,kLeave,binding,timeout);return result;
#else
  (void)session;(void)xuid;(void)timeout;return std::nullopt;
#endif
}
std::optional<ArbitrationSnapshot> PrivateLanDiscoveryAdapter::RegisterArbitration(
    const std::shared_ptr<SessionRecord>& session,uint64_t xuid,uint64_t nonce) {
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
  try {
    if(!session||!impl_->invitation||impl_->invitation->host()||!impl_->invitation->Current())return std::nullopt;
    std::shared_ptr<PrivateLanClientBinding> binding;Packet packet;
    {std::lock_guard lock(*session->mutex);if(session->state==SessionState::kDeleted||session->nonce!=nonce)return std::nullopt;
      binding=session->private_lan_client;packet=Encode(*session,impl_->title);}
    if(!binding||!binding->Confirmed()||binding->xuid()!=xuid)return std::nullopt;
    auto& b=*binding->impl_;std::lock_guard lock(b.mutex);auto request=b.Request();if(!request)return std::nullopt;
    packet[6]=kRegister;Put(packet,64,1,4);std::fill_n(packet.begin()+84,44*8,0);Put(packet,84,xuid,8);Put(packet,112,b.machine,8);
    Write(packet,468,b.registration);Write(packet,624,*request);if(!Sign(packet,b.credential,"private-lan-register-v1"))return std::nullopt;
    PrivateLanDiscoveryFrame frame;frame.public_packet=packet;const auto deadline=Clock::now()+std::chrono::milliseconds(1500);auto next=Clock::time_point{};
    while(Clock::now()<deadline){if(Clock::now()>=next){auto wire=SealPrivateLanDiscoveryFrame(*impl_->invitation,xuid,impl_->title,PrivateLanDiscoveryDirection::kRequest,frame);
        if(!wire||!Send(b.socket.fd,*wire,b.target))return std::nullopt;next=Clock::now()+std::chrono::milliseconds(125);}
      LanAddress source;auto reply=Receive(b.socket.fd,*impl_->invitation,xuid,impl_->title,PrivateLanDiscoveryDirection::kReply,source,*request);
      if(reply&&source==b.target&&reply->public_packet[6]==kRegisterReply&&PacketIdentity(reply->public_packet)==b.identity&&
         Read<16>(reply->public_packet,468)==b.registration&&Verify(reply->public_packet,b.credential,"private-lan-register-reply-v1")) {
        auto advertisement=reply->public_packet;advertisement[6]=kAdvertisement;auto decoded=Decode(advertisement,impl_->title);
        const auto revision=Get(advertisement,516,8),mask=Get(advertisement,524,4),count=Get(advertisement,64,4);
        if(!decoded||!revision||(mask>>count))continue;ArbitrationSnapshot snapshot{b.identity,revision,{}};bool present=false;
        for(size_t i=0;i<decoded->members.size();++i)if(mask&(1u<<i)){
          const auto& member=decoded->members[i];snapshot.registrants.push_back({member.machine_id,0,{member.xuid}});
          if(member.xuid==xuid&&member.machine_id==b.machine)present=true;}
        if(!present)continue;std::lock_guard record_lock(*session->mutex);
        if(session->state==SessionState::kDeleted||session->private_lan_client!=binding||IdentityOf(*session)!=b.identity||revision<session->arbitration_revision)return std::nullopt;
        session->arbitration_revision=revision;return snapshot;
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(5));}
  }catch(...){return std::nullopt;}
#else
  (void)session;(void)xuid;(void)nonce;
#endif
  return std::nullopt;
}
bool PrivateLanDiscoveryAdapter::Activate(const std::shared_ptr<SessionRecord>& session,uint64_t xuid) {
#if REX_PLATFORM_POSIX_ONLINE || REX_PLATFORM_WIN32
  if(!session||!impl_->invitation||impl_->invitation->host()||!impl_->invitation->Current())return false;
  {std::lock_guard lock(*session->mutex);if(session->state==SessionState::kDeleted||!session->private_lan_gameplay||
    session->private_lan_gameplay->xuid!=xuid||!session->private_lan_client||!session->private_lan_client->Confirmed())return false;}
  StopClient();impl_->client=session;impl_->client_xuid=xuid;impl_->client_running=true;
  impl_->client_thread=std::thread([this]{auto next=Clock::now();while(impl_->client_running){try {
    if(Clock::now()>=next){auto session=impl_->client.lock();if(!session)break;
      std::shared_ptr<PrivateLanClientBinding> binding;SessionMember member;SessionRecord before;bool valid=false;
      {std::lock_guard lock(*session->mutex);if(session->state==SessionState::kDeleted)break;before=*session;binding=session->private_lan_client;
        const auto found=std::find_if(session->members.begin(),session->members.end(),[&](const auto& m){return m.xuid==impl_->client_xuid&&m.local;});
        if(found!=session->members.end()){member=*found;valid=true;}}
      std::optional<SessionRecord> updated;if(valid&&binding){std::lock_guard lock(binding->impl_->mutex);updated=impl_->Exchange(before,member,kJoin,binding,250);}
      if(updated&&updated->private_lan_gameplay){struct Commit {SessionRecord* session;const SessionRecord* before;
          std::shared_ptr<const GameplayAuthorization> auth;};Commit commit{session.get(),&before,updated->private_lan_gameplay};
        const auto auth=updated->private_lan_gameplay;
        if(CommitPrivateLanGameplayAuthorization(session,*auth,std::move(updated->members),[](void* context) noexcept {
          auto& c=*static_cast<Commit*>(context);c.session->private_lan_gameplay=std::move(c.auth);return true;
        },&commit,[](void* context) noexcept {auto& c=*static_cast<Commit*>(context);return SameRoster(*c.session,*c.before);}))session->NotifyStatus();}
      next=Clock::now()+std::chrono::seconds(1);
    }
    }catch(...){/* Existing ticket expires; no raw fallback. */}
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }});return true;
#else
  (void)session;(void)xuid;return false;
#endif
}
#else
struct PrivateLanClientBinding::Impl {};
PrivateLanClientBinding::PrivateLanClientBinding(std::unique_ptr<Impl> impl):impl_(std::move(impl)){}
PrivateLanClientBinding::~PrivateLanClientBinding()=default;
bool PrivateLanClientBinding::Confirmed() const noexcept{return false;}
uint64_t PrivateLanClientBinding::xuid() const noexcept{return 0;}
const ArbitrationIdentity& PrivateLanClientBinding::identity() const noexcept{static const ArbitrationIdentity value{};return value;}
struct PrivateLanDiscoveryAdapter::Impl {};
PrivateLanDiscoveryAdapter::PrivateLanDiscoveryAdapter(uint32_t,uint16_t,uint64_t,std::shared_ptr<const PrivateLanInvitation>):impl_(std::make_unique<Impl>()){}
PrivateLanDiscoveryAdapter::~PrivateLanDiscoveryAdapter()=default;
bool PrivateLanDiscoveryAdapter::Start(const std::shared_ptr<SessionRecord>&){return false;}
void PrivateLanDiscoveryAdapter::Stop(){}
void PrivateLanDiscoveryAdapter::StopClient(){}
bool PrivateLanDiscoveryAdapter::IsAdvertising() const noexcept{return false;}
std::vector<SessionRecord> PrivateLanDiscoveryAdapter::Search(uint32_t,uint32_t){return {};}
std::optional<SessionRecord> PrivateLanDiscoveryAdapter::Join(const SessionRecord&,const SessionMember&,uint32_t){return std::nullopt;}
std::optional<ArbitrationSnapshot> PrivateLanDiscoveryAdapter::RegisterArbitration(const std::shared_ptr<SessionRecord>&,uint64_t,uint64_t){return std::nullopt;}
std::optional<SessionRecord> PrivateLanDiscoveryAdapter::Leave(const SessionRecord&,uint64_t,uint32_t){return std::nullopt;}
bool PrivateLanDiscoveryAdapter::Activate(const std::shared_ptr<SessionRecord>&,uint64_t){return false;}
void PrivateLanDiscoveryAdapter::SetTitle(uint32_t){}
void PrivateLanDiscoveryAdapter::SetMachine(uint64_t){}
#endif
} // namespace rex::system::xam
