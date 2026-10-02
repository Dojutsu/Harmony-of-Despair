// Characterization of existing defects, not acceptance tests for a fix.

#include "system/session_admission_test.cpp"
#include <rex/system/xam/nat_probe.h>
#include <cstdio>
namespace rex::system::xam {
TEST_CASE("audit: another discovery socket can repeat and remove an admitted XUID", "[gameplay-audit]") {
  LocalDiscoveryConfig config;
  SessionRegistry registry;
  auto r=registry.Create(1,"Host",{htonl(INADDR_LOOPBACK),30742},1,3,3);
  LanDiscoveryService host(0x58410A7A,39167);
  REQUIRE(host.Advertise(r));
  Socket a,b;
  REQUIRE(a.fd!=bad_socket); REQUIRE(b.fd!=bad_socket);
  auto advertised=Transfer(b.fd,39167,Query(0x58410A7A)); REQUIRE(advertised);
  REQUIRE(Transfer(b.fd,39167,JoinPacket(*advertised,0xB)));
  {std::lock_guard lock(*r->mutex); REQUIRE(r->members.size()==2);}
  // A has never been admitted, has neither B's credential nor B's source port.
  REQUIRE(Transfer(a.fd,39167,JoinPacket(*advertised,0xB)));
  {std::lock_guard lock(*r->mutex); REQUIRE(r->members.size()==2);}
  auto leave=JoinPacket(*advertised,0xB); leave[6]=4;
  REQUIRE(Transfer(a.fd,39167,leave));
  {std::lock_guard lock(*r->mutex); REQUIRE(r->members.size()==1);}
  REQUIRE(Transfer(a.fd,39167,JoinPacket(*advertised,0xB)));
  {std::lock_guard lock(*r->mutex); REQUIRE(r->members.size()==2); REQUIRE(r->members[1].xuid==0xB);}
  std::puts("AUDIT_PROVEN: unadmitted socket A repeated B join, removed B, then joined as B; tuple was public advertisement");
}
TEST_CASE("audit: scoped discovery identity cannot attach to a later gameplay socket", "[gameplay-audit]") {
  LocalDiscoveryConfig config;
  Socket a1,a2;
  REQUIRE(a1.fd!=bad_socket); REQUIRE(a2.fd!=bad_socket);
  auto addr=Address(0);
  REQUIRE(bind(a1.fd,reinterpret_cast<sockaddr*>(&addr),sizeof(addr))==0);
  REQUIRE(bind(a2.fd,reinterpret_cast<sockaddr*>(&addr),sizeof(addr))==0);
  sockaddr_in one{},two{}; int len=sizeof(one);
  REQUIRE(getsockname(a1.fd,reinterpret_cast<sockaddr*>(&one),&len)==0);
  len=sizeof(two); REQUIRE(getsockname(a2.fd,reinterpret_cast<sockaddr*>(&two),&len)==0);
  REQUIRE(one.sin_port!=two.sin_port);
  const std::string id="aabbccdd00112233445566778899aabb";
  const std::string cap="1234567890abcdef1234567890abcdef";
  NatProbeAttach(uint64_t(a1.fd),NatProbeRole::kDiscovery,{one.sin_addr.s_addr,ntohs(one.sin_port)});
  REQUIRE(NatProbeInstallIdentityForSocket({id,cap,"127.0.0.1",39168,1},uint64_t(a1.fd)));
  NatProbeAttach(uint64_t(a2.fd),NatProbeRole::kGameplay,{two.sin_addr.s_addr,ntohs(two.sin_port)});
  std::array<uint8_t,56> packet{};
  std::memcpy(packet.data(),"HNAT",4);packet[4]=1;packet[5]=2;packet[6]=1;packet[7]=0;
  auto decode=[](const std::string& s,uint8_t* out){for(size_t i=0;i<16;++i)out[i]=uint8_t(std::stoul(s.substr(i*2,2),nullptr,16));};
  decode(id,packet.data()+8);decode(cap,packet.data()+24);
  packet[40]=127;packet[43]=1;packet[44]=0x98;packet[45]=0x60;
  packet[46]=127;packet[49]=1;packet[50]=0x98;packet[51]=0x61;
  REQUIRE(NatProbeConsume(uint64_t(a1.fd),packet.data(),packet.size(),htonl(INADDR_LOOPBACK),39168));
  packet[7]=1;
  CHECK_FALSE(NatProbeConsume(uint64_t(a2.fd),packet.data(),packet.size(),htonl(INADDR_LOOPBACK),39168));
  CHECK(NatProbePeerAttempts(uint64_t(a2.fd),false).empty());
  std::printf("AUDIT_PROVEN: discovery port=%u gameplay port=%u, later gameplay rejects identity\n",ntohs(one.sin_port),ntohs(two.sin_port));
  NatProbeDetach(uint64_t(a2.fd)); NatProbeDetach(uint64_t(a1.fd)); NatProbeRetireIdentity(id);
}
}
