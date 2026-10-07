#include <rex/system/xam/private_lan_authority.h>
#include <rex/platform.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <mutex>
#include <set>
#if REX_PLATFORM_GNU_LINUX
#include <arpa/inet.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#endif
namespace rex::system::xam {
namespace {
constexpr size_t kTicketHeader = 112, kTicketPeer = 116;
using Bytes16 = std::array<uint8_t,16>;
using Bytes32 = std::array<uint8_t,32>;
bool Nonzero(std::span<const uint8_t> data) {uint8_t sum=0;for(auto byte:data)sum|=byte;return sum!=0;}
std::string Hex(std::span<const uint8_t> bytes) {
  constexpr char digits[]="0123456789abcdef";std::string result;result.reserve(bytes.size()*2);
  for(auto byte:bytes){result+=digits[byte>>4];result+=digits[byte&15];}return result;
}
void Append(std::vector<uint8_t>& output,std::span<const uint8_t> bytes) {output.insert(output.end(),bytes.begin(),bytes.end());}
void Put(std::vector<uint8_t>& output,uint64_t value,unsigned size) {
  for(int shift=int(size*8)-8;shift>=0;shift-=8)output.push_back(uint8_t(value>>shift));
}
uint64_t Get(const uint8_t* input,unsigned size) {
  uint64_t value=0;for(unsigned i=0;i<size;++i)value=(value<<8)|input[i];return value;
}
bool PrivateEndpoint(LanAddress endpoint) {
#if REX_PLATFORM_GNU_LINUX
  const auto ip=ntohl(endpoint.ipv4);
  return endpoint.port&&((ip>>24)==127||(ip>>24)==10||(ip>>20)==0xac1||(ip>>16)==0xc0a8);
#else
  (void)endpoint;return false;
#endif
}
bool Logical(uint32_t ip) {
#if REX_PLATFORM_GNU_LINUX
  const auto value=ntohl(ip);return (value>>24)==0xf0&&(value&0xffffff)!=0;
#else
  (void)ip;return false;
#endif
}
bool Random(std::span<uint8_t> output) {
#if REX_PLATFORM_GNU_LINUX
  return RAND_bytes(output.data(),int(output.size()))==1&&Nonzero(output);
#else
  (void)output;return false;
#endif
}
std::optional<Bytes32> Fingerprint(uint32_t title,const ArbitrationIdentity& identity) {
#if REX_PLATFORM_GNU_LINUX
  std::vector<uint8_t> input;Put(input,title,4);Append(input,identity.session_id);Append(input,identity.exchange_key);
  Append(input,identity.incarnation);Put(input,identity.nonce,8);Put(input,identity.host_xuid,8);Put(input,identity.host_machine_id,8);
  Bytes32 result{};unsigned length=0;
  if(EVP_Digest(input.data(),input.size(),result.data(),&length,EVP_sha256(),nullptr)!=1||length!=result.size())return std::nullopt;
  return result;
#else
  (void)title;(void)identity;return std::nullopt;
#endif
}
struct Pair {
  Bytes16 link{},capability{};Bytes32 traffic{};
  ~Pair(){
#if REX_PLATFORM_GNU_LINUX
    OPENSSL_cleanse(traffic.data(),traffic.size());OPENSSL_cleanse(capability.data(),capability.size());
#endif
  }
};
struct Member {
  PrivateLanJoinClaim join;
  PrivateLanAuthority::Clock::time_point last_fresh_rpc{};
  Bytes16 nonce{},generation{},capability{};uint32_t logical=0;
  ~Member(){
#if REX_PLATFORM_GNU_LINUX
    OPENSSL_cleanse(capability.data(),capability.size());
#endif
  }
};
bool SameAdmission(const Member& member,const PrivateLanJoinClaim& claim) {
  return member.join.xuid==claim.xuid&&member.join.machine_id==claim.machine_id&&
      member.join.endpoint==claim.endpoint&&member.join.challenge==claim.challenge&&
      member.join.client_public_key==claim.client_public_key;
}
}  // namespace
std::vector<uint8_t> PrivateLanJoinTranscript(uint32_t title,
    const ArbitrationIdentity& identity,const PrivateLanJoinClaim& claim) {
  std::vector<uint8_t> bytes;constexpr std::string_view domain="ReXGlue private LAN join claim v1";
  bytes.insert(bytes.end(),domain.begin(),domain.end());Put(bytes,title,4);Append(bytes,identity.session_id);
  Append(bytes,identity.exchange_key);Append(bytes,identity.incarnation);Put(bytes,identity.nonce,8);
  Put(bytes,identity.host_xuid,8);Put(bytes,identity.host_machine_id,8);Put(bytes,claim.xuid,8);Put(bytes,claim.machine_id,8);
  const auto* ip=reinterpret_cast<const uint8_t*>(&claim.endpoint.ipv4);bytes.insert(bytes.end(),ip,ip+4);
  Put(bytes,claim.endpoint.port,2);Append(bytes,claim.challenge);Append(bytes,claim.request_id);Append(bytes,claim.client_public_key);
  return bytes;
}
struct PrivateLanAuthority::State {
  uint32_t title;ArbitrationIdentity identity;std::shared_ptr<const PrivateLanInvitation> invitation;
  Bytes32 fingerprint{};mutable std::mutex mutex;std::map<uint64_t,Member> members;
  std::map<std::pair<uint64_t,uint64_t>,Pair> pairs;
  std::set<std::pair<uint64_t,std::string>> retired;
  uint64_t revision=1;bool active=true;
};
PrivateLanAuthority::PrivateLanAuthority(std::shared_ptr<State> state):state_(std::move(state)){}
PrivateLanAuthority::~PrivateLanAuthority() {std::lock_guard lock(state_->mutex);state_->active=false;}
struct PrivateLanAuthority::Admission::Draft {
  std::shared_ptr<State> owner;uint64_t base_revision=0;bool committed=false;
  std::map<uint64_t,Member> members;std::map<std::pair<uint64_t,uint64_t>,Pair> pairs;
};
PrivateLanAuthority::Admission::Admission(std::unique_ptr<Draft> draft):draft_(std::move(draft)){}
PrivateLanAuthority::Admission::~Admission()=default;
bool PrivateLanAuthority::Admission::Commit() noexcept {
  return CommitIf([]() noexcept {return true;});
}
bool PrivateLanAuthority::Admission::CommitIfRaw(bool (*publish)(void*) noexcept,void* context) noexcept {
  try {
    if(draft_->committed)return false;
    auto& owner=*draft_->owner;std::lock_guard lock(owner.mutex);
    if(!owner.active||!owner.invitation->Current()||owner.revision!=draft_->base_revision||owner.revision==UINT64_MAX)return false;
    if(!publish(context))return false;
    owner.members.swap(draft_->members);owner.pairs.swap(draft_->pairs);++owner.revision;
    draft_->committed=true;return true;
  }catch(...){return false;}
}
std::unique_ptr<PrivateLanAuthority> PrivateLanAuthority::Create(uint32_t title,
    ArbitrationIdentity identity,LanAddress endpoint,std::shared_ptr<const PrivateLanInvitation> invitation) {
#if REX_PLATFORM_GNU_LINUX
  if(!title||!identity.host_xuid||!identity.host_machine_id||!identity.nonce||!Nonzero(identity.session_id)||
      !Nonzero(identity.exchange_key)||!Nonzero(identity.incarnation)||!PrivateEndpoint(endpoint)||
      !invitation||!invitation->host()||!invitation->Current()||invitation->host_xuid()!=identity.host_xuid)return {};
  try {
    auto state=std::make_shared<State>();state->title=title;state->identity=identity;state->invitation=std::move(invitation);
    auto hash=Fingerprint(title,identity);if(!hash)return {};state->fingerprint=*hash;
    Member host;host.join.xuid=identity.host_xuid;host.join.machine_id=identity.host_machine_id;
    host.join.endpoint=endpoint;host.logical=htonl(0xf0000001);
    if(!Random(host.nonce)||!Random(host.generation)||!Random(host.capability))return {};
    state->members.emplace(host.join.xuid,host);
    return std::unique_ptr<PrivateLanAuthority>(new PrivateLanAuthority(std::move(state)));
  }catch(...){return {};}
#else
  (void)title;(void)identity;(void)endpoint;(void)invitation;return {};
#endif
}
std::unique_ptr<PrivateLanAuthority::Admission> PrivateLanAuthority::Prepare(
    const PrivateLanJoinClaim& claim,std::span<const uint8_t> proof,Clock::time_point now) {
#if REX_PLATFORM_GNU_LINUX
  if(!claim.xuid||claim.xuid==state_->identity.host_xuid||!claim.machine_id||!PrivateEndpoint(claim.endpoint)||
      !Nonzero(claim.challenge)||!Nonzero(std::span(claim.request_id).first(8))||
      !Get(claim.request_id.data()+8,8)||!Nonzero(claim.client_public_key))return {};
  try {
    auto transcript=PrivateLanJoinTranscript(state_->title,state_->identity,claim);
    if(!state_->invitation->Verify(claim.xuid,"lan-private-join-claim-v1",transcript,proof))return {};
    auto draft=std::make_unique<Admission::Draft>();draft->owner=state_;
    {
      std::lock_guard lock(state_->mutex);
      if(!state_->active||state_->revision==UINT64_MAX)return {};
      draft->base_revision=state_->revision;draft->members=state_->members;draft->pairs=state_->pairs;
      if(auto old=draft->members.find(claim.xuid);old!=draft->members.end()) {
        auto& member=old->second;
        if(!SameAdmission(member,claim)||!std::equal(claim.request_id.begin(),claim.request_id.begin()+8,member.join.request_id.begin())||
            now-member.last_fresh_rpc>=std::chrono::seconds(60))return {};
        const auto previous=Get(member.join.request_id.data()+8,8),sequence=Get(claim.request_id.data()+8,8);
        if(sequence<previous)return {};
        if(sequence>previous) {member.join.request_id=claim.request_id;member.last_fresh_rpc=now;}
        return std::unique_ptr<Admission>(new Admission(std::move(draft)));
      }
      if(state_->members.size()>=6||state_->retired.size()+state_->members.size()-1>=256||
          state_->retired.contains({claim.xuid,Hex(claim.challenge)}))return {};
    }
    // Fresh provider work and all allocations precede publication. The exact
    // revision will be checked again at Commit after roster/scope preflight.
    for(const auto& [xuid,member]:draft->members)
      if(member.join.machine_id==claim.machine_id||member.join.endpoint==claim.endpoint)return {};
    const std::array<uint8_t,1> probe{1};if(!SealArbitrationPayload(claim.client_public_key,probe,transcript))return {};
    Member member;member.join=claim;member.last_fresh_rpc=now;
    if(!Random(member.nonce)||!Random(member.generation)||!Random(member.capability))return {};
    const auto clients=state_->invitation->clients();const auto ordinal=std::find(clients.begin(),clients.end(),claim.xuid);
    if(ordinal==clients.end()) { return {}; }
    member.logical=htonl(0xf0000002+uint32_t(ordinal-clients.begin()));
    for(const auto& [xuid,previous]:draft->members) {
      (void)previous;Pair pair;if(!Random(pair.link)||!Random(pair.capability)||!Random(pair.traffic))return {};
      const auto ordered=std::minmax(xuid,claim.xuid);draft->pairs.emplace(std::make_pair(ordered.first,ordered.second),pair);
    }
    draft->members.emplace(claim.xuid,member);return std::unique_ptr<Admission>(new Admission(std::move(draft)));
  }catch(...){return {};}
#else
  (void)claim;(void)proof;(void)now;return {};
#endif
}
bool PrivateLanAuthority::Admit(const PrivateLanJoinClaim& claim,std::span<const uint8_t> proof,Clock::time_point now) {
  auto admission=Prepare(claim,proof,now);return admission&&admission->Commit();
}
bool PrivateLanAuthority::Remove(uint64_t client) {
  if(client==state_->identity.host_xuid)return false;
  std::lock_guard lock(state_->mutex);
  auto member=state_->members.find(client);if(!state_->active||state_->revision==UINT64_MAX||member==state_->members.end()||state_->retired.size()>=256)return false;
  try {
    state_->retired.emplace(client,Hex(member->second.join.challenge));
    state_->members.erase(member);++state_->revision;
    std::erase_if(state_->pairs,[&](const auto& pair){return pair.first.first==client||pair.first.second==client;});
    return true;
  }catch(...){return false;}
}
std::vector<uint64_t> PrivateLanAuthority::Expire(Clock::time_point now) {
  try {
    std::lock_guard lock(state_->mutex);
    if(!state_->active||state_->revision==UINT64_MAX)return {};
    std::vector<uint64_t> expired;
    for(const auto& [xuid,member]:state_->members)
      if(xuid!=state_->identity.host_xuid&&now-member.last_fresh_rpc>=std::chrono::seconds(60))expired.push_back(xuid);
    if(expired.empty())return expired;
    // Allocate every replacement before modifying any member, key or replay
    // tombstone. Capacity is bounded by Admit's maximum of 256 generations.
    auto members=state_->members;auto pairs=state_->pairs;auto retired=state_->retired;
    for(auto xuid:expired) {
      retired.emplace(xuid,Hex(members.at(xuid).join.challenge));members.erase(xuid);
      std::erase_if(pairs,[&](const auto& pair){return pair.first.first==xuid||pair.first.second==xuid;});
    }
    if(retired.size()>256)return {};
    state_->members.swap(members);state_->pairs.swap(pairs);state_->retired.swap(retired);++state_->revision;return expired;
  }catch(...){return {};}
}
namespace {
std::optional<std::vector<uint8_t>> EncodeAuthorityTicket(const auto& context,const auto& members,const auto& pairs,
    uint64_t local,uint32_t lease) {
  if(lease<1000||lease>60000||!context.invitation->Current())return std::nullopt;
  try {
    const auto member=members.find(local);if(member==members.end())return std::nullopt;
    const auto now=PrivateLanAuthority::Clock::now();
    for(const auto& [xuid,current]:members)
      if(xuid!=context.identity.host_xuid&&now-current.last_fresh_rpc>=std::chrono::seconds(60))return std::nullopt;
    std::vector<uint8_t> bytes;
    struct CleanTemporary {
      std::vector<uint8_t>& bytes;
      ~CleanTemporary() {
#if REX_PLATFORM_GNU_LINUX
        if(!bytes.empty())OPENSSL_cleanse(bytes.data(),bytes.size());
#endif
      }
    } cleanse{bytes};
    bytes.reserve(kTicketHeader+(members.size()-1)*kTicketPeer);
    const std::array<uint8_t,8> header{'H','P','L','T',1,uint8_t(members.size()-1),0,0};Append(bytes,header);
    Append(bytes,context.fingerprint);Put(bytes,context.identity.host_xuid,8);Put(bytes,local,8);
    Append(bytes,member->second.nonce);Append(bytes,member->second.generation);Append(bytes,member->second.capability);
    const auto append_ip=[&](uint32_t ip){const auto* data=reinterpret_cast<const uint8_t*>(&ip);bytes.insert(bytes.end(),data,data+4);};
    append_ip(member->second.logical);Put(bytes,lease,4);
    for(const auto& [peer_xuid,peer]:members) {
      if(peer_xuid==local)continue;
      const auto ordered=std::minmax(local,peer_xuid);
      const auto& pair=pairs.at({ordered.first,ordered.second});
      Put(bytes,peer_xuid,8);Append(bytes,peer.nonce);Append(bytes,peer.generation);Append(bytes,pair.link);
      Append(bytes,pair.capability);Append(bytes,pair.traffic);append_ip(peer.logical);append_ip(peer.join.endpoint.ipv4);
      Put(bytes,peer.join.endpoint.port,2);Put(bytes,0,2);
    }
    return std::optional<std::vector<uint8_t>>(std::move(bytes));
  }catch(...){return std::nullopt;}
}
} // namespace
std::optional<std::vector<uint8_t>> PrivateLanAuthority::Ticket(uint64_t local,uint32_t lease) const {
  std::lock_guard lock(state_->mutex);if(!state_->active)return std::nullopt;
  return EncodeAuthorityTicket(*state_,state_->members,state_->pairs,local,lease);
}
std::optional<std::vector<uint8_t>> PrivateLanAuthority::Admission::Ticket(uint64_t local,uint32_t lease) const {
  if(draft_->committed)return std::nullopt;
  {std::lock_guard lock(draft_->owner->mutex);
    if(!draft_->owner->active||draft_->owner->revision!=draft_->base_revision)return std::nullopt;}
  return EncodeAuthorityTicket(*draft_->owner,draft_->members,draft_->pairs,local,lease);
}
std::optional<PrivateLanGameplayTicket> ParsePrivateLanGameplayTicket(uint32_t title,
    const ArbitrationIdentity& identity,uint64_t local,std::span<const uint8_t> bytes,uint16_t guest_port) {
#if REX_PLATFORM_GNU_LINUX
  if(!title||!local||!guest_port||!identity.host_xuid||!identity.host_machine_id||!identity.nonce||
      !Nonzero(identity.session_id)||!Nonzero(identity.exchange_key)||!Nonzero(identity.incarnation)||bytes.size()<kTicketHeader||std::memcmp(bytes.data(),"HPLT",4)||
      bytes[4]!=1||bytes[5]>5||bytes[6]||bytes[7]||bytes.size()!=kTicketHeader+size_t(bytes[5])*kTicketPeer)return std::nullopt;
  try {
    const auto hash=Fingerprint(title,identity);
    if(!hash||CRYPTO_memcmp(hash->data(),bytes.data()+8,hash->size())||Get(bytes.data()+40,8)!=identity.host_xuid||
        Get(bytes.data()+48,8)!=local)return std::nullopt;
    const auto lease=Get(bytes.data()+108,4);
    uint32_t logical=0;std::memcpy(&logical,bytes.data()+104,4);
    if(!Logical(logical)||lease<1000||lease>60000||!Nonzero(bytes.subspan(56,16))||
        !Nonzero(bytes.subspan(72,16))||!Nonzero(bytes.subspan(88,16)))return std::nullopt;
    PrivateLanGameplayTicket result;auto& auth=result.authorization;
    auth.directory_session="lan-"+Hex(*hash);auth.xbox_session=identity.session_id;auth.host_xuid=identity.host_xuid;
    auth.xuid=local;auth.member_nonce=Hex(bytes.subspan(56,16));auth.admission_attempt=auth.member_nonce;
    auth.admission_generation=Hex(bytes.subspan(72,16));auth.member_capability=Hex(bytes.subspan(88,16));
    auth.logical={logical,guest_port};auth.expires_at=std::chrono::steady_clock::now()+std::chrono::milliseconds(lease);
    std::set<uint64_t> xuids{local};std::set<uint32_t> addresses{logical};std::set<std::string> links;
    std::set<std::pair<uint32_t,uint16_t>> endpoints;
    for(size_t i=0;i<bytes[5];++i) {
      const auto peer=bytes.subspan(kTicketHeader+i*kTicketPeer,kTicketPeer);
      const auto xuid=Get(peer.data(),8);uint32_t alias=0,native=0;
      std::memcpy(&alias,peer.data()+104,4);std::memcpy(&native,peer.data()+108,4);
      const LanAddress endpoint{native,uint16_t(Get(peer.data()+112,2))};
      if(!xuid||!xuids.insert(xuid).second||!Logical(alias)||!addresses.insert(alias).second||
          !PrivateEndpoint(endpoint)||!endpoints.emplace(endpoint.ipv4,endpoint.port).second||Get(peer.data()+114,2)||!Nonzero(peer.subspan(8,16))||
          !Nonzero(peer.subspan(24,16))||!Nonzero(peer.subspan(40,16))||!Nonzero(peer.subspan(56,16))||
          !Nonzero(peer.subspan(72,32)))return std::nullopt;
      GameplayPeerAuthorization authorized;authorized.xuid=xuid;authorized.member_nonce=Hex(peer.subspan(8,16));
      authorized.admission_attempt=authorized.member_nonce;authorized.admission_generation=Hex(peer.subspan(24,16));
      authorized.logical={alias,guest_port};authorized.authenticated_lan_endpoint=endpoint;
      authorized.traversal.attempt_id=Hex(peer.subspan(40,16));
      authorized.traversal.capability=Hex(peer.subspan(56,16));authorized.traversal.participant=local<xuid?0:1;
      if(!links.insert(authorized.traversal.attempt_id).second)return std::nullopt;
      std::copy_n(peer.data()+72,32,authorized.traffic_key.begin());
      auth.peers.push_back(std::move(authorized));result.peer_endpoints.push_back(endpoint);
    }
    if(local!=identity.host_xuid&&!xuids.contains(identity.host_xuid))return std::nullopt;
    return result;
  }catch(...){return std::nullopt;}
#else
  (void)title;(void)identity;(void)local;(void)bytes;(void)guest_port;return std::nullopt;
#endif
}
}  // namespace rex::system::xam
