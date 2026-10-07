#include <rex/system/xam/private_lan_authority.h>
#include <rex/platform.h>
#include <algorithm>
#include <array>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#if REX_PLATFORM_GNU_LINUX
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#endif
#ifndef FSC_PRIVATE_LAN_STANDALONE
#include <catch2/catch_test_macros.hpp>
#endif
using namespace rex::system::xam;
namespace {
size_t checks=0;
void Check(bool value,const char* reason){++checks;if(!value)throw std::runtime_error(reason);}
#if REX_PLATFORM_GNU_LINUX
struct Invitations {
  std::filesystem::path directory;
  std::shared_ptr<const PrivateLanInvitation> host,second,third;
  Invitations(){
    std::array<char,128> name{};std::strcpy(name.data(),"/tmp/fsc-private-lan-authority-XXXXXX");
    const auto created=mkdtemp(name.data());Check(created,"authority private fixture directory");directory=created;
    const auto expiry=uint64_t(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count())+3600;
    auto write=[&](const char* filename,bool hosted,uint8_t xuid){
      const size_t count=hosted?2:1;std::vector<uint8_t> bytes(24+count*56);
      std::memcpy(bytes.data(),"HPLI",4);bytes[4]=1;bytes[5]=hosted?0:1;bytes[6]=count;bytes[15]=1;
      for(unsigned i=0;i<8;++i)bytes[16+i]=uint8_t(expiry>>(56-i*8));
      for(size_t i=0;i<count;++i){const auto member=hosted?uint8_t(i+2):xuid;bytes[31+i*56]=member;
        for(unsigned j=0;j<16;++j)bytes[32+i*56+j]=uint8_t(member*31+j);
        for(unsigned j=0;j<32;++j)bytes[48+i*56+j]=uint8_t(member*37+j*5);}
      const auto path=directory/filename;const int fd=::open(path.c_str(),O_WRONLY|O_CREAT|O_EXCL|O_CLOEXEC,0600);
      Check(fd>=0&&::write(fd,bytes.data(),bytes.size())==ssize_t(bytes.size()),"authority grant fixture write");::close(fd);
      auto loaded=PrivateLanInvitation::Load(path.string());Check(bool(loaded),"authority fixture loads");return loaded;
    };
    host=write("host",true,0);second=write("second",false,2);third=write("third",false,3);
  }
  ~Invitations(){std::error_code error;std::filesystem::remove_all(directory,error);}
};
GameplayLinkId Link(std::string_view hex){GameplayLinkId result{};
  auto digit=[](char byte){return byte<='9'?byte-'0':byte-'a'+10;};
  for(size_t i=0;i<result.size();++i) {
    result[i]=uint8_t((digit(hex[i*2])<<4)|digit(hex[i*2+1]));
  }
  return result;
}
const GameplayPeerAuthorization& Peer(const PrivateLanGameplayTicket& ticket,uint64_t peer){
  for(const auto& candidate:ticket.authorization.peers)if(candidate.xuid==peer)return candidate;
  throw std::runtime_error("missing expected private peer");
}
void Run(){
  checks=0;Invitations invitations;
  ArbitrationIdentity identity;identity.session_id[0]=17;identity.exchange_key[0]=29;identity.incarnation[0]=43;
  identity.nonce=101;identity.host_xuid=1;identity.host_machine_id=11;
  constexpr uint32_t title=0x58410A7A;
  auto authority=PrivateLanAuthority::Create(title,identity,{htonl(INADDR_LOOPBACK),30001},invitations.host);
  Check(bool(authority),"legitimate private LAN authority");
  auto key2=NewArbitrationKey(),key3=NewArbitrationKey();Check(bool(key2)&&bool(key3),"authority actual client keys");
  PrivateLanJoinClaim second;second.xuid=2;second.machine_id=22;second.endpoint={htonl(INADDR_LOOPBACK),30002};
  second.challenge[0]=59;second.request_id[0]=71;second.request_id[15]=1;second.client_public_key=key2->public_key();
  PrivateLanJoinClaim third;third.xuid=3;third.machine_id=33;third.endpoint={htonl(INADDR_LOOPBACK),30003};
  third.challenge[0]=83;third.request_id[0]=97;third.request_id[15]=1;third.client_public_key=key3->public_key();
  auto proof=[&](const PrivateLanInvitation& invitation,const PrivateLanJoinClaim& claim){
    auto tag=invitation.Proof(claim.xuid,"lan-private-join-claim-v1",PrivateLanJoinTranscript(title,identity,claim));
    Check(bool(tag),"client creates its expected private claim proof");return *tag;};
  Check(authority->Admit(second,proof(*invitations.second,second)),"second authenticated admission");
  auto ticket=[&](uint64_t xuid){auto encoded=authority->Ticket(xuid);Check(bool(encoded),"private ticket issuance");
    auto parsed=ParsePrivateLanGameplayTicket(title,identity,xuid,*encoded);Check(bool(parsed),"exact private ticket parse");return *parsed;};
  const auto initial=ticket(1);const auto initial_peer=Peer(initial,2);
  Check(authority->Admit(second,proof(*invitations.second,second)),"exact lost-reply retry accepted");
  Check(Peer(ticket(1),2).traffic_key==initial_peer.traffic_key&&
        Peer(ticket(1),2).traversal.attempt_id==initial_peer.traversal.attempt_id,"retry retains pair key and link");
  auto changed=second;changed.machine_id=44;
  Check(!authority->Admit(changed,proof(*invitations.second,changed)),"authenticated identity relocation rejected");
  changed=second;changed.client_public_key=key3->public_key();
  Check(!authority->Admit(changed,proof(*invitations.second,changed)),"existing identity ephemeral-key replacement rejected");
  changed=third;changed.xuid=2;
  Check(!authority->Admit(changed,proof(*invitations.second,second)),"wrong-grant identity spoof rejected");
  changed=third;changed.machine_id=22;
  Check(!authority->Admit(changed,proof(*invitations.third,changed)),"machine identity conflict rejected");
  changed=third;changed.endpoint=second.endpoint;
  Check(!authority->Admit(changed,proof(*invitations.third,changed)),"gameplay endpoint alias rejected");
  changed=third;changed.endpoint={htonl(0x08080808),30003};
  Check(!authority->Admit(changed,proof(*invitations.third,changed)),"public endpoint excluded from direct LAN");
  changed=third;changed.client_public_key={};changed.client_public_key[0]=1;
  Check(!authority->Admit(changed,proof(*invitations.third,changed)),"low-order X25519 input rejected without membership");
  auto altered=proof(*invitations.third,third);altered[0]^=1;
  Check(!authority->Admit(third,altered),"wrong possession proof rejected");
  Check(authority->Admit(third,proof(*invitations.third,third)),"third authenticated admission");
  std::array<PrivateLanGameplayTicket,3> tickets{ticket(1),ticket(2),ticket(3)};
  for(size_t i=0;i<tickets.size();++i)for(size_t j=i+1;j<tickets.size();++j){
    const auto local=tickets[i].authorization.xuid,remote=tickets[j].authorization.xuid;
    const auto& a=Peer(tickets[i],remote);const auto& b=Peer(tickets[j],local);
    Check(a.traffic_key==b.traffic_key&&a.traversal.attempt_id==b.traversal.attempt_id&&
          a.traversal.capability==b.traversal.capability&&a.traversal.participant!=b.traversal.participant,
          "all three pairs share exact fresh directional links");
    auto cipher=GameplayDatagramCipher::Create(a.traffic_key,Link(a.traversal.attempt_id),a.traversal.participant);
    auto peer=GameplayDatagramCipher::Create(b.traffic_key,Link(b.traversal.attempt_id),b.traversal.participant);
    const std::array<uint8_t,7> body{1,2,3,4,5,6,7};auto wire=cipher->Seal(body);std::vector<uint8_t> output;
    Check(wire&&peer->Open(*wire,output)&&std::equal(output.begin(),output.end(),body.begin(),body.end()),
          "all three pairs pass real authenticated datagrams");
    Check(!peer->Open(*wire,output),"all three pairs reject duplicate packets");
  }
  Check(Peer(tickets[0],2).traffic_key!=Peer(tickets[1],3).traffic_key,"pair keys are independent");
  const auto unaffected=Peer(tickets[0],3);
  Check(authority->Remove(2),"real authority departure removes member");
  Check(!authority->Ticket(2)&&ticket(1).authorization.peers.size()==1,"departed member loses private ticket/peer visibility");
  Check(!authority->Admit(second,proof(*invitations.second,second)),"departed initial request replay cannot recreate member");
  second.challenge[0]^=1;second.request_id[0]^=1;auto rekey=NewArbitrationKey();second.client_public_key=rekey->public_key();
  Check(authority->Admit(second,proof(*invitations.second,second)),"fresh authenticated rejoin");
  const auto refreshed=ticket(1);
  Check(Peer(refreshed,2).traffic_key!=initial_peer.traffic_key&&
        Peer(refreshed,2).traversal.attempt_id!=initial_peer.traversal.attempt_id&&
        Peer(refreshed,2).member_nonce!=initial_peer.member_nonce,"rejoin mints fresh pair and member generations");
  Check(Peer(refreshed,3).traffic_key==unaffected.traffic_key&&
        Peer(refreshed,3).traversal.attempt_id==unaffected.traversal.attempt_id,"unaffected pair survives another member's rejoin");
  auto encoded=authority->Ticket(2);Check(bool(encoded),"parser adversarial fixture");
  for(size_t length=0;length<encoded->size();++length)
    Check(!ParsePrivateLanGameplayTicket(title,identity,2,std::span(*encoded).first(length)),"every ticket truncation rejected");
  auto corrupt=*encoded;corrupt.push_back(0);Check(!ParsePrivateLanGameplayTicket(title,identity,2,corrupt),"ticket trailing bytes rejected");
  for(size_t offset : {size_t(0),size_t(4),size_t(5),size_t(6),size_t(7),size_t(8),size_t(40),size_t(48),size_t(104),size_t(108)}){
    corrupt=*encoded;corrupt[offset]=0xff;Check(!ParsePrivateLanGameplayTicket(title,identity,2,corrupt),"ticket header identity/bounds mutation rejected");}
  // Duplicate IDs, logical aliases and link IDs are ambiguous authority.
  for (size_t offset : {size_t(0), size_t(40), size_t(104)}) {
    corrupt=*encoded; const size_t length=offset==0?8:(offset==40?16:4);
    std::copy_n(corrupt.begin()+112+offset,length,corrupt.begin()+112+116+offset);
    Check(!ParsePrivateLanGameplayTicket(title,identity,2,corrupt),"duplicate peer identity/route/link rejected");
  }
  auto wrong_identity=identity;wrong_identity.incarnation[0]^=1;
  Check(!ParsePrivateLanGameplayTicket(title,wrong_identity,2,*encoded)&&
        !ParsePrivateLanGameplayTicket(title^1,identity,2,*encoded)&&
        !ParsePrivateLanGameplayTicket(title,identity,3,*encoded),"complete expected session/title/member binding");
  for(size_t field : {size_t(8),size_t(24),size_t(40),size_t(56),size_t(72)}){
    corrupt=*encoded;const size_t length=field==72?32:16;std::fill_n(corrupt.begin()+112+field,length,0);
    Check(!ParsePrivateLanGameplayTicket(title,identity,2,corrupt),"zero peer nonce/generation/link/capability/traffic rejected");}
  corrupt=*encoded;std::fill_n(corrupt.begin()+112+108,4,0);corrupt[112+108]=8;corrupt[112+109]=8;corrupt[112+110]=8;corrupt[112+111]=8;
  Check(!ParsePrivateLanGameplayTicket(title,identity,2,corrupt),"public ticket endpoint rejected");
  corrupt=*encoded;corrupt[112+114]=1;Check(!ParsePrivateLanGameplayTicket(title,identity,2,corrupt),"peer reserved bytes rejected");
  Check(!authority->Ticket(1,999)&&!authority->Ticket(1,60001)&&!authority->Remove(1),"lease bounds and host identity guarded");
  auto expiry_authority=PrivateLanAuthority::Create(title,identity,{htonl(INADDR_LOOPBACK),30001},invitations.host);
  Check(bool(expiry_authority),"fresh expiry authority");
  const auto started=PrivateLanAuthority::Clock::now();
  Check(expiry_authority->Admit(second,proof(*invitations.second,second),started),"fresh expiry admission");
  Check(expiry_authority->Admit(second,proof(*invitations.second,second),started+std::chrono::seconds(59)),"duplicate lost-reply RPC accepted without lease renewal");
  Check(expiry_authority->Expire(started+std::chrono::seconds(60))==std::vector<uint64_t>{2},"duplicate replay cannot extend host membership");
  Check(!expiry_authority->Ticket(2)&&!expiry_authority->Admit(second,proof(*invitations.second,second),started+std::chrono::seconds(61)),"expired challenge cannot recreate membership");
  second.challenge[1]=1;second.request_id[15]=1;
  Check(expiry_authority->Admit(second,proof(*invitations.second,second),started+std::chrono::seconds(62)),"fresh challenge after liveness expiry");
  const auto before_rpc=second;second.request_id[15]=2;
  Check(expiry_authority->Admit(second,proof(*invitations.second,second),started+std::chrono::seconds(120)),"fresh monotonic authenticated renewal");
  Check(expiry_authority->Expire(started+std::chrono::seconds(121)).empty(),"fresh renewal extends exact host liveness");
  Check(!expiry_authority->Admit(before_rpc,proof(*invitations.second,before_rpc),started+std::chrono::seconds(121)),"earlier signed request rejected after fresh renewal");
  changed=second;changed.request_id[0]^=1;
  Check(!expiry_authority->Admit(changed,proof(*invitations.second,changed),started+std::chrono::seconds(121)),"RPC nonce prefix replacement rejected within admission");
  changed=second;std::fill(changed.request_id.begin()+8,changed.request_id.end(),0);
  Check(!expiry_authority->Admit(changed,proof(*invitations.second,changed)),"zero renewal sequence rejected");
  Check(expiry_authority->Expire(started+std::chrono::seconds(180))==std::vector<uint64_t>{2},"renewed member still expires without another fresh RPC");
  auto transaction=PrivateLanAuthority::Create(title,identity,{htonl(INADDR_LOOPBACK),30001},invitations.host);
  Check(bool(transaction),"staged private authority");
  auto prepared=transaction->Prepare(third,proof(*invitations.third,third));
  Check(bool(prepared)&&bool(prepared->Ticket(3)),"preflight obtains provisional encrypted-ticket inputs");
  Check(!transaction->Ticket(3),"prepared member is invisible to live authority");
  prepared.reset();Check(!transaction->Ticket(3),"failed roster/provider preflight discards complete admission");
  prepared=transaction->Prepare(third,proof(*invitations.third,third));
  Check(bool(prepared),"staged final commit fixture");bool roster_published=false;
  Check(!prepared->CommitIf([]() noexcept {return false;})&&!transaction->Ticket(3),"failed roster/arbitration commit cannot publish keys or membership");
  Check(prepared->CommitIf([&]() noexcept {roster_published=true;return true;})&&roster_published,"nonthrowing roster/arbitration and private authority publish together");
  Check(bool(transaction->Ticket(3))&&!prepared->Commit()&&!prepared->Ticket(3),"staged commit is exactly once and cannot issue obsolete draft tickets");
  prepared=transaction->Prepare(third,proof(*invitations.third,third));
  Check(bool(prepared)&&transaction->Remove(3),"intervening departure fixture");roster_published=false;
  Check(!prepared->CommitIf([&]() noexcept {roster_published=true;return true;})&&!roster_published,"stale authority prevents external roster/arbitration effects");
  Check(!transaction->Ticket(3),"stale prepared admission cannot resurrect retired member");
  auto abandoned=PrivateLanAuthority::Create(title,identity,{htonl(INADDR_LOOPBACK),30001},invitations.host);
  prepared=abandoned->Prepare(third,proof(*invitations.third,third));Check(bool(prepared),"owner lifetime draft");
  abandoned.reset();Check(!prepared->Commit()&&!prepared->Ticket(3),"destroyed authority invalidates outstanding draft without dangling storage");
  auto renewal=PrivateLanAuthority::Create(title,identity,{htonl(INADDR_LOOPBACK),30001},invitations.host);
  third.request_id[15]=1;Check(renewal->Admit(third,proof(*invitations.third,third),started),"staged renewal fixture");
  third.request_id[15]=2;prepared=renewal->Prepare(third,proof(*invitations.third,third),started+std::chrono::seconds(59));
  Check(bool(prepared),"fresh renewal can preflight without publication");prepared.reset();
  Check(renewal->Expire(started+std::chrono::seconds(60))==std::vector<uint64_t>{3},"discarded renewal cannot refresh host membership");
  std::cout<<checks<<" private LAN authority, three-pair datagram, replay/rejoin and ticket parser checks passed\n";
}
#endif
}  // namespace
#ifdef FSC_PRIVATE_LAN_STANDALONE
int main(){try{Run();return 0;}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
#else
TEST_CASE("Private LAN authority issues independent authenticated pair tickets and retires replayed admissions", "[network][security]"){
#if REX_PLATFORM_GNU_LINUX
  REQUIRE_NOTHROW(Run());
#endif
}
#endif
