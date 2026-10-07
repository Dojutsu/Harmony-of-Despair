#include <catch2/catch_test_macros.hpp>
#include <rex/system/xam/session.h>
#include <rex/system/xam/session_arbitration_crypto.h>
#include <array>
#include <barrier>
#include <thread>
#include <vector>

namespace rex::system::xam {
TEST_CASE("member reclassification cannot overfill a destination pool", "[session][admission]") {
  SessionRegistry registry;
  auto record = registry.Create(1, "Host", {}, 1, 1, 1);
  REQUIRE(registry.Join(record->info.id, {2, "Private", 0, false, true, false}));
  CHECK_FALSE(registry.Join(record->info.id, {2, "Changed", 0, false, false, true}));
  CHECK(record->members.size() == 2);
  CHECK(record->members[1].private_slot);
  CHECK(record->members[1].name == "Private");
  CHECK_FALSE(record->members[1].ready);
  CHECK(record->FilledPublicSlots() == 1);
  CHECK(record->FilledPrivateSlots() == 1);
  CHECK(record->OpenPublicSlots() == 0);
  CHECK(record->OpenPrivateSlots() == 0);
}
}  // namespace rex::system::xam

namespace rex::system::xam {
namespace {
SessionMember Member(uint64_t id, bool private_slot = false) {
  return {id, "Player" + std::to_string(id), 0, false, private_slot, false};
}
void Accounting(const SessionRecord& r, uint32_t pub, uint32_t priv) {
  CHECK(r.FilledPublicSlots() == pub);
  CHECK(r.FilledPrivateSlots() == priv);
  CHECK(r.members.size() == pub + priv);
  REQUIRE(pub <= r.max_public_slots);
  REQUIRE(priv <= r.max_private_slots);
  CHECK(r.OpenPublicSlots() == r.max_public_slots - pub);
  CHECK(r.OpenPrivateSlots() == r.max_private_slots - priv);
  std::unordered_set<uint64_t> ids;
  for (const auto& member : r.members) CHECK(ids.insert(member.xuid).second);
}
std::string Members(const SessionRecord& r) {
  std::string result;
  for (const auto& m : r.members)
    result += std::to_string(m.xuid) + ":" + m.name + ":" + std::to_string(m.user_index) +
              ":" + std::to_string(m.local) + std::to_string(m.private_slot) +
              std::to_string(m.ready) + ";";
  return result;
}
}
TEST_CASE("host public capacity includes host and retries consume no slot", "[session][admission]") {
  SessionRegistry registry;
  auto r = registry.Create(1, "Host", {}, 1, 4, 2);
  Accounting(*r, 1, 0);
  for (uint64_t id = 2; id <= 4; ++id) {
    REQUIRE(registry.Join(r->info.id, Member(id)));
    Accounting(*r, uint32_t(id), 0);
  }
  const auto before = Members(*r);
  CHECK_FALSE(registry.Join(r->info.id, Member(5)));
  CHECK(Members(*r) == before);
  REQUIRE(registry.Join(r->info.id, Member(4)));
  CHECK(Members(*r) == before);
  Accounting(*r, 4, 0);
  REQUIRE(registry.Leave(r->info.id, 3));
  Accounting(*r, 3, 0);
}
TEST_CASE("title reclassification validates both pools transactionally", "[session][admission]") {
  SessionRegistry registry;
  auto r = registry.Create(1, "Host", {}, 1, 2, 1);
  REQUIRE(registry.Join(r->info.id, Member(2)));
  REQUIRE(registry.Join(r->info.id, Member(3, true)));
  Accounting(*r, 2, 1);
  const auto before = Members(*r);
  CHECK_FALSE(registry.Join(r->info.id, Member(2, true)));
  CHECK(Members(*r) == before);
  CHECK_FALSE(registry.Join(r->info.id, Member(3)));
  CHECK(Members(*r) == before);
  Accounting(*r, 2, 1);
  REQUIRE(registry.Leave(r->info.id, 3));
  REQUIRE(registry.Join(r->info.id, Member(2, true)));
  Accounting(*r, 1, 1);
  REQUIRE(registry.Join(r->info.id, Member(2)));
  Accounting(*r, 2, 0);
}
TEST_CASE("batch joins commit all members or leave all metadata unchanged", "[session][admission]") {
  SessionRegistry registry;
  auto r = registry.Create(1, "Host", {}, 1, 3, 2);
  std::array batch{Member(2), Member(3)};
  REQUIRE(registry.JoinBatch(r, batch));
  Accounting(*r, 3, 0);
  auto before = Members(*r);
  batch = {Member(2, true), Member(4)}; // Would fit after trusted reclassification.
  REQUIRE(registry.JoinBatch(r, batch));
  Accounting(*r, 3, 1);
  before = Members(*r);
  batch = {Member(5, true), Member(6)}; // First fits; second does not.
  CHECK_FALSE(registry.JoinBatch(r, batch));
  CHECK(Members(*r) == before);
  batch = {Member(2), Member(2, true)};
  CHECK_FALSE(registry.JoinBatch(r, batch));
  CHECK(Members(*r) == before);
  batch = {Member(5, true), Member(0)};
  CHECK_FALSE(registry.JoinBatch(r, batch));
  CHECK(Members(*r) == before);
  Accounting(*r, 3, 1);
}
TEST_CASE("last public slot has one concurrent winner", "[session][admission][network]") {
  for (unsigned attempt = 0; attempt < 32; ++attempt) {
    SessionRegistry registry;
    auto r = registry.Create(1, "Host", {}, 1, 2, 2);
    std::barrier start(3);
    std::array<bool, 2> success{};
    std::thread a([&] { start.arrive_and_wait(); success[0] = registry.Join(r->info.id, Member(2)); });
    std::thread b([&] { start.arrive_and_wait(); success[1] = registry.Join(r->info.id, Member(3)); });
    start.arrive_and_wait(); a.join(); b.join();
    CHECK(unsigned(success[0]) + unsigned(success[1]) == 1);
    Accounting(*r, 2, 0);
  }
}
TEST_CASE("stale observations and deleted records cannot receive batch updates", "[session][admission]") {
  SessionRegistry registry;
  SessionRecord observed;
  observed.info.id[0] = 7;
  observed.host_xuid = 1;
  observed.max_public_slots = 4;
  observed.members = {Member(1)};
  registry.UpsertDiscovered(observed);
  auto stale = registry.Find(observed.info.id);
  registry.UpsertDiscovered(observed);
  std::array batch{Member(2)};
  CHECK_FALSE(registry.JoinBatch(stale, batch));
  CHECK(stale->members.size() == 1);
  auto current = registry.Find(observed.info.id);
  CHECK(current->members.size() == 1);
  REQUIRE(registry.Delete(current->info.id));
  CHECK_FALSE(registry.JoinBatch(current, batch));
  CHECK(current->members.size() == 1);
}
TEST_CASE("preexisting invalid host accounting is not made worse", "[session][admission]") {
  SessionRegistry registry;
  auto r = registry.Create(1, "Host", {}, 1, 0, 2);
  const auto before = Members(*r);
  CHECK_FALSE(registry.Join(r->info.id, Member(2, true)));
  CHECK(Members(*r) == before);
}
} // namespace rex::system::xam

#include <rex/platform.h>
#if REX_PLATFORM_WIN32
#include <WinSock2.h>
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#endif
#include <cstring>

namespace rex::system::xam {
namespace {
using Packet = std::array<uint8_t, 640>; // Version2:84 +8*44 +96 registration bytes.
#if REX_PLATFORM_WIN32
using TestSocket = SOCKET;
constexpr auto bad_socket = INVALID_SOCKET;
#else
using TestSocket = int;
constexpr auto bad_socket = -1;
#endif
struct Socket {
  TestSocket fd = ::socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  ~Socket() {
#if REX_PLATFORM_WIN32
    if (fd != bad_socket) closesocket(fd);
#else
    if (fd != bad_socket) close(fd);
#endif
  }
};
void Put(Packet& p, size_t offset, uint64_t value, size_t width = 4) {
  for (size_t i = 0; i < width; ++i) p[offset+i] = uint8_t(value >> (8*(width-i-1)));
}
sockaddr_in Address(uint16_t port) {
  sockaddr_in addr{};
  addr.sin_family = AF_INET; addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  addr.sin_port = htons(port);
  return addr;
}
std::optional<Packet> Receive(TestSocket fd, sockaddr_in& source, uint32_t wait_ms) {
  fd_set fds; FD_ZERO(&fds); FD_SET(fd, &fds);
  timeval timeout{long(wait_ms/1000), long(wait_ms%1000)*1000};
  if (select(int(fd)+1, &fds, nullptr, nullptr, &timeout) <= 0) return std::nullopt;
#if REX_PLATFORM_WIN32
  int length = sizeof(source);
#else
  socklen_t length = sizeof(source);
#endif
  Packet p{};
  if (recvfrom(fd, reinterpret_cast<char*>(p.data()), int(p.size()), 0,
               reinterpret_cast<sockaddr*>(&source), &length) != int(p.size()))
    return std::nullopt;
  return p;
}
std::optional<Packet> Transfer(TestSocket fd, uint16_t port, const Packet& p) {
  auto target = Address(port);
  if (sendto(fd, reinterpret_cast<const char*>(p.data()), int(p.size()), 0,
             reinterpret_cast<sockaddr*>(&target), sizeof(target)) != int(p.size()))
    return std::nullopt;
  sockaddr_in from{};
  return Receive(fd, from, 150);
}
struct LocalDiscoveryConfig {
  std::string bind = REXCVAR_GET(lan_bind_address);
  std::string direct = REXCVAR_GET(direct_connect_address);
  std::string directory = REXCVAR_GET(session_directory_url);
  LocalDiscoveryConfig() {
#if REX_PLATFORM_WIN32
    WSADATA data{}; REQUIRE(WSAStartup(MAKEWORD(2,2), &data) == 0);
#endif
    REXCVAR_SET(lan_bind_address, "127.0.0.1");
    REXCVAR_SET(direct_connect_address, "127.0.0.1");
    REXCVAR_SET(session_directory_url, "");
  }
  ~LocalDiscoveryConfig() {
    REXCVAR_SET(lan_bind_address, bind);
    REXCVAR_SET(direct_connect_address, direct);
    REXCVAR_SET(session_directory_url, directory);
#if REX_PLATFORM_WIN32
    WSACleanup();
#endif
  }
};
Packet Query(uint32_t title) {
  Packet p{}; Put(p, 0, 0x5245584c); Put(p, 4, 2, 2); p[6] = 1; Put(p, 8, title);
  return p;
}
Packet JoinPacket(Packet base, uint64_t xuid, bool priv = false) {
  base[6] = 3; Put(base, 64, 1);
  std::fill(base.begin()+84, base.begin()+436, 0);
  std::fill(base.begin()+468, base.end(), 0);
  Put(base, 84, xuid, 8); Put(base, 92, priv ? 2 : 0);
  std::memcpy(base.data()+96, "WirePlayer", 10);
  Put(base,112,0x100000000ull+xuid,8); Put(base,124,3074,2);
  Put(base,468,0x200000000ull+xuid,8); Put(base,624,0x300000000ull+xuid,8);
  const auto key=NewArbitrationKey(); REQUIRE(key);
  std::copy(key->public_key().begin(),key->public_key().end(),base.begin()+532);
  return base;
}
}
TEST_CASE("discovery admission validates identity and ignores private wire claims",
          "[session][admission][network][lan]") {
  LocalDiscoveryConfig config;
  constexpr uint32_t title = 0x58410A7A;
  constexpr uint16_t port = 39057;
  SessionRegistry registry;
  auto r = registry.Create(1, "Host", {htonl(INADDR_LOOPBACK), 3074}, 1, 4, 2);
  LanDiscoveryService host(title, port);
  REQUIRE(host.Advertise(r));
  Socket socket;
  REQUIRE(socket.fd != bad_socket);
  auto base = Transfer(socket.fd, port, Query(title)); REQUIRE(base);
  auto assert_count = [&](uint32_t pub, uint32_t priv) {
    std::lock_guard lock(*r->mutex); Accounting(*r, pub, priv);
  };
  auto wrong = JoinPacket(*base, 2); wrong[12] ^= 1;
  CHECK_FALSE(Transfer(socket.fd, port, wrong)); assert_count(1,0);
  wrong = JoinPacket(*base, 2); wrong[20] ^= 1;
  CHECK_FALSE(Transfer(socket.fd, port, wrong)); assert_count(1,0);
  wrong = JoinPacket(*base, 2); Put(wrong,8,title+1);
  CHECK_FALSE(Transfer(socket.fd, port, wrong)); assert_count(1,0);
  wrong = JoinPacket(*base, 2); Put(wrong,4,1,2);
  CHECK_FALSE(Transfer(socket.fd, port, wrong)); assert_count(1,0);
  wrong = JoinPacket(*base, 2); Put(wrong,36,9,8);
  CHECK_FALSE(Transfer(socket.fd, port, wrong)); assert_count(1,0);
  for (auto id : {uint64_t{0}, uint64_t{1}}) {
    CHECK_FALSE(Transfer(socket.fd, port, JoinPacket(*base, id))); assert_count(1,0);
  }
  wrong = JoinPacket(*base, 2); Put(wrong,64,2);
  CHECK_FALSE(Transfer(socket.fd, port, wrong)); assert_count(1,0);
  wrong = JoinPacket(*base, 2); Put(wrong,92,8);
  CHECK_FALSE(Transfer(socket.fd, port, wrong)); assert_count(1,0);
  const auto admitted_two = JoinPacket(*base, 2, true);
  REQUIRE(Transfer(socket.fd, port, admitted_two)); assert_count(2,0);
  // Same observed socket/challenge with another ephemeral key cannot fetch
  // the admitted member's continuity credential.
  auto different_key = JoinPacket(*base,2,true);
  CHECK_FALSE(Transfer(socket.fd,port,different_key)); assert_count(2,0);
  REQUIRE(Transfer(socket.fd, port, JoinPacket(*base, 3))); assert_count(3,0);
  REQUIRE(Transfer(socket.fd, port, JoinPacket(*base, 4))); assert_count(4,0);
  CHECK_FALSE(Transfer(socket.fd, port, JoinPacket(*base, 5, true))); assert_count(4,0);
  std::string before;
  { std::lock_guard lock(*r->mutex); before = Members(*r); }
  auto retry = admitted_two; Put(retry,92,6); retry[96]='X';
  REQUIRE(Transfer(socket.fd, port, retry)); assert_count(4,0);
  { std::lock_guard lock(*r->mutex); CHECK(Members(*r) == before); }
  auto authenticated_leave = [&](uint64_t xuid) {
    auto request = JoinPacket(*base, xuid); request[6] = 4;
    const auto identity = r->arbitration->identity();
    const auto token = r->arbitration->CredentialForVerification(identity, xuid, 0x100000000ull+xuid);
    REQUIRE(token);
    constexpr char digits[] = "0123456789abcdef"; std::string key;
    for (uint8_t byte : *token) { key += digits[byte >> 4]; key += digits[byte & 15]; }
    const auto tag = InviteLanAuthenticationTag(key, "session-leave-v2", request);
    REQUIRE(tag); std::copy(tag->begin(),tag->end(),request.begin()+500);
    return request;
  };
  auto unauthenticated_leave = JoinPacket(*base,3); unauthenticated_leave[6]=4;
  CHECK_FALSE(Transfer(socket.fd,port,unauthenticated_leave)); assert_count(4,0);
  auto leave = authenticated_leave(3);
  REQUIRE(Transfer(socket.fd, port, leave)); assert_count(3,0);
  REQUIRE(registry.Join(r->info.id, Member(6, true))); assert_count(3,1);
  REQUIRE(Transfer(socket.fd, port, JoinPacket(*base, 6))); assert_count(3,1);
  leave = authenticated_leave(6);
  REQUIRE(Transfer(socket.fd, port, leave)); assert_count(3,0);
  // Registry and discovery compete under the same record lock.
  std::barrier start(2); bool title_joined = false;
  std::thread contender([&] { start.arrive_and_wait(); title_joined=registry.Join(r->info.id,Member(7)); });
  start.arrive_and_wait();
  bool wire_joined=Transfer(socket.fd, port, JoinPacket(*base, 8)).has_value();
  contender.join(); CHECK(unsigned(title_joined)+unsigned(wire_joined)==1); assert_count(4,0);
  REQUIRE(registry.Delete(r->info.id));
  CHECK_FALSE(Transfer(socket.fd, port, JoinPacket(*base, 9)));
}
TEST_CASE("advertisement decode rejects duplicate and impossible rosters",
          "[session][admission][network][lan]") {
  LocalDiscoveryConfig config;
  constexpr uint32_t title = 0x58410A7A;
  SessionRegistry registry;
  auto session = registry.Create(1, "Host", {htonl(INADDR_LOOPBACK), 3074}, 1, 4, 2);
  Packet valid=Query(title); valid[6]=2;
  std::memcpy(valid.data()+12, session->info.id.data(), 8);
  std::memcpy(valid.data()+20, session->info.key.data(), 16);
  Put(valid,36,1,8); Put(valid,48,3074,2); Put(valid,56,4); Put(valid,60,2); Put(valid,64,2);
  Put(valid,84,1,8); Put(valid,128,2,8);
  for (int variant=0; variant<7; ++variant) {
    INFO("variant=" << variant);
    Packet response=valid;
    if(variant==1) Put(response,128,1,8); // Duplicate XUID.
    if(variant==2) Put(response,64,9); // Wire capacity exceeded, not clamped.
    if(variant==3) Put(response,56,1); // Two public members in one public slot.
    if(variant==4) { Put(response,136,2); Put(response,60,0); } // Private overflow.
    if(variant==5) Put(response,128,0,8);
    Socket server; REQUIRE(server.fd!=bad_socket);
    auto addr=Address(0); REQUIRE(bind(server.fd,reinterpret_cast<sockaddr*>(&addr),sizeof(addr))==0);
#if REX_PLATFORM_WIN32
    int length=sizeof(addr);
#else
    socklen_t length=sizeof(addr);
#endif
    REQUIRE(getsockname(server.fd,reinterpret_cast<sockaddr*>(&addr),&length)==0);
    std::atomic<bool> responded=false;
    std::jthread reply([&] {
      sockaddr_in source{};
      if(Receive(server.fd,source,1000)) {
        std::vector<uint8_t> wire(response.begin(), response.end());
        if (variant == 6) wire.push_back(0xA5); // Valid prefix, oversized frame.
        sendto(server.fd,reinterpret_cast<const char*>(wire.data()),int(wire.size()),0,
               reinterpret_cast<sockaddr*>(&source),sizeof(source));
        responded=true;
      }
    });
    LanDiscoveryService client(title, ntohs(addr.sin_port));
    // Discovery observations are display metadata; they cannot create a
    // private joined binding. Authenticated exact-session join/retry is
    // exercised against two real services in session_arbitration_transport.
    const auto result=client.Search(100,4);
    CHECK(responded);
    CHECK((result.size()==1) == (variant==0));
    if(!result.empty()) CHECK_FALSE(result[0].arbitration_client);
  }

}
} // namespace rex::system::xam
