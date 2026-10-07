#include <catch2/catch_test_macros.hpp>
#include <rex/platform.h>
#include <rex/system/xam/gameplay_datagram.h>
#include <algorithm>
#include <array>
#include <mutex>
#include <thread>
#include <type_traits>
#include <vector>
#if REX_PLATFORM_LINUX
namespace {
using namespace rex::system::xam;
GameplayTrafficKey TestKey() { GameplayTrafficKey key{};for(size_t i=0;i<key.size();++i)key[i]=uint8_t(i+1);return key; }
GameplayLinkId TestLink() { GameplayLinkId link{};for(size_t i=0;i<link.size();++i)link[i]=uint8_t(0xa0+i);return link; }
struct Pair {
 std::unique_ptr<GameplayDatagramCipher> a=GameplayDatagramCipher::Create(TestKey(),TestLink(),0);
 std::unique_ptr<GameplayDatagramCipher> b=GameplayDatagramCipher::Create(TestKey(),TestLink(),1);
};
std::vector<uint8_t> Body(size_t size) {std::vector<uint8_t> data(size);for(size_t i=0;i<size;++i)data[i]=uint8_t(i*79+37);return data;}
uint64_t Sequence(const std::vector<uint8_t>& wire) {uint64_t value=0;for(size_t i=24;i<32;++i)value=(value<<8)|wire[i];return value;}
static_assert(!std::is_copy_constructible_v<GameplayDatagramCipher>);
static_assert(!std::is_move_constructible_v<GameplayDatagramCipher>);
}
TEST_CASE("Gameplay datagrams roundtrip both directions and enforce IPv4 wire limits", "[gameplay][crypto]") {
 Pair pair;REQUIRE(pair.a);REQUIRE(pair.b);
 for(size_t length:{size_t(0),size_t(1),size_t(15),size_t(16),size_t(17),size_t(1500),kGameplayMaximumPlaintextBytes}){
  const auto body=Body(length);auto ab=pair.a->Seal(body);auto ba=pair.b->Seal(body);REQUIRE(ab);REQUIRE(ba);
  CHECK(ab->size()==length+48);CHECK(ba->size()==length+48);CHECK(*ab!=*ba);
  std::vector<uint8_t> out{0xff};REQUIRE(pair.b->Open(*ab,out));CHECK(out==body);REQUIRE(pair.a->Open(*ba,out));CHECK(out==body);
 }
 CHECK_FALSE(pair.a->Seal(Body(kGameplayMaximumPlaintextBytes+1)));
}
TEST_CASE("Gameplay parser authenticates every header payload and tag byte before publication", "[gameplay][crypto]") {
 Pair pair;const auto body=Body(37);const auto packet=pair.a->Seal(body);REQUIRE(packet);
 for(size_t i=0;i<packet->size();++i){auto forged=*packet;forged[i]^=1;std::vector<uint8_t> out{0xde,0xad};CHECK_FALSE(pair.b->Open(forged,out));CHECK(out==std::vector<uint8_t>{0xde,0xad});}
 for(size_t length=0;length<packet->size();++length){std::vector<uint8_t> out{0x91};CHECK_FALSE(pair.b->Open(std::span(*packet).first(length),out));CHECK(out==std::vector<uint8_t>{0x91});}
 auto extended=*packet;extended.push_back(0);std::vector<uint8_t> out{0x93};CHECK_FALSE(pair.b->Open(extended,out));CHECK(out==std::vector<uint8_t>{0x93});
 REQUIRE(pair.b->Open(*packet,out));CHECK(out==body); // Failures may not burn the real sequence.
}
TEST_CASE("Gameplay keys links directions and reflection remain distinct", "[gameplay][crypto]") {
 Pair pair;auto packet=pair.a->Seal(Body(64));REQUIRE(packet);std::vector<uint8_t> out{0x9a};
 auto other_key=TestKey();other_key[9]^=0xff;auto wrong_key=GameplayDatagramCipher::Create(other_key,TestLink(),1);REQUIRE(wrong_key);
 auto other_link=TestLink();other_link[9]^=0xff;auto wrong_link=GameplayDatagramCipher::Create(TestKey(),other_link,1);REQUIRE(wrong_link);
 CHECK_FALSE(wrong_key->Open(*packet,out));CHECK_FALSE(wrong_link->Open(*packet,out));CHECK_FALSE(pair.a->Open(*packet,out));CHECK(out==std::vector<uint8_t>{0x9a});
 CHECK_FALSE(GameplayDatagramCipher::Create({},TestLink(),0));CHECK_FALSE(GameplayDatagramCipher::Create(TestKey(),{},0));CHECK_FALSE(GameplayDatagramCipher::Create(TestKey(),TestLink(),2));
}
TEST_CASE("Gameplay replay window preserves out of order traffic across word boundaries", "[gameplay][crypto]") {
 Pair pair;std::vector<std::vector<uint8_t>> packets;
 for(unsigned i=0;i<600;++i){auto packet=pair.a->Seal(Body(8));REQUIRE(packet);CHECK(Sequence(*packet)==i+1);packets.push_back(std::move(*packet));}
 std::vector<uint8_t> out;
 REQUIRE(pair.b->Open(packets[299],out)); // seq300
 REQUIRE(pair.b->Open(packets[44],out)); // age255
 CHECK_FALSE(pair.b->Open(packets[43],out)); // age256
 CHECK_FALSE(pair.b->Open(packets[44],out));
 REQUIRE(pair.b->Open(packets[236],out)); // age63
 REQUIRE(pair.b->Open(packets[235],out)); // age64
 REQUIRE(pair.b->Open(packets[234],out)); // age65
 REQUIRE(pair.b->Open(packets[363],out)); // shift64
 CHECK_FALSE(pair.b->Open(packets[299],out));CHECK_FALSE(pair.b->Open(packets[236],out));
 REQUIRE(pair.b->Open(packets[428],out)); // shift65
 CHECK_FALSE(pair.b->Open(packets[363],out));
 REQUIRE(pair.b->Open(packets[429],out)); // shift1
 REQUIRE(pair.b->Open(packets[599],out)); // shift170
 CHECK_FALSE(pair.b->Open(packets[363],out)); // previously marked, age236
 REQUIRE(pair.b->Open(packets[344],out)); // age255, not previously marked
 CHECK_FALSE(pair.b->Open(packets[343],out)); // age256
}
TEST_CASE("Gameplay forged high sequence cannot advance replay state", "[gameplay][crypto]") {
 Pair pair;auto packet=pair.a->Seal(Body(16));REQUIRE(packet);auto forged=*packet;std::fill(forged.begin()+24,forged.begin()+32,0xff);
 std::vector<uint8_t> out{0xe1};CHECK_FALSE(pair.b->Open(forged,out));CHECK(out==std::vector<uint8_t>{0xe1});REQUIRE(pair.b->Open(*packet,out));
 auto next=pair.a->Seal(Body(4));REQUIRE(next);REQUIRE(pair.b->Open(*next,out));CHECK(Sequence(*next)==2);
}
TEST_CASE("Gameplay authenticated peeks repeat until actual consumption", "[gameplay][crypto]") {
 Pair pair;const auto body=Body(128);auto packet=pair.a->Seal(body);REQUIRE(packet);std::vector<uint8_t> out;
 REQUIRE(pair.b->Open(*packet,out,false));REQUIRE(pair.b->Open(*packet,out,false));CHECK(out==body);
 REQUIRE(pair.b->Open(*packet,out));CHECK_FALSE(pair.b->Open(*packet,out,false));CHECK_FALSE(pair.b->Open(*packet,out));
}
TEST_CASE("Gameplay parallel sends allocate unique ordered nonces", "[gameplay][crypto]") {
 Pair pair;std::mutex lock;std::vector<std::vector<uint8_t>> packets;std::vector<std::thread> threads;
 for(unsigned t=0;t<8;++t)threads.emplace_back([&]{for(unsigned i=0;i<32;++i){auto packet=pair.a->Seal(Body(32));std::lock_guard guard(lock);if(packet)packets.push_back(std::move(*packet));}});
 for(auto& thread:threads) { thread.join(); }
 REQUIRE(packets.size()==256);
 std::sort(packets.begin(),packets.end(),[](const auto& a,const auto& b){return Sequence(a)<Sequence(b);});
 std::vector<uint8_t> out;for(size_t i=0;i<packets.size();++i){CHECK(Sequence(packets[i])==i+1);REQUIRE(pair.b->Open(packets[i],out));CHECK(out==Body(32));}
}
TEST_CASE("Gameplay hostile oversized and raw packets preserve caller output", "[gameplay][crypto]") {
 Pair pair;std::vector<uint8_t> out{0xfe,0x2d};
 for(size_t length:{size_t(0),size_t(4),size_t(47),kGameplayMaximumWireBytes+1,size_t(65536)}){CHECK_FALSE(pair.b->Open(Body(length),out));CHECK(out==std::vector<uint8_t>{0xfe,0x2d});}
 uint32_t value=0x438cfac3;for(unsigned i=0;i<512;++i){size_t length=i%128;std::vector<uint8_t> data(length);for(auto& byte:data){value^=value<<13;value^=value>>17;value^=value<<5;byte=uint8_t(value);}CHECK_FALSE(pair.b->Open(data,out));CHECK(out==std::vector<uint8_t>{0xfe,0x2d});}
}
#ifdef FSC_GAMEPLAY_PROVIDER_FAILURE
extern bool fsc_fail_encrypt_final,fsc_fail_decrypt_final;
TEST_CASE("Gameplay encryption provider failure burns nonce and leaks no packet", "[gameplay][crypto][provider]") {
 Pair pair;fsc_fail_encrypt_final=true;CHECK_FALSE(pair.a->Seal(Body(32)));fsc_fail_encrypt_final=false;
 auto wire=pair.a->Seal(Body(32));REQUIRE(wire);CHECK(Sequence(*wire)==2);std::vector<uint8_t> out;REQUIRE(pair.b->Open(*wire,out));
}
TEST_CASE("Gameplay failed provider authentication preserves replay and output", "[gameplay][crypto][provider]") {
 Pair pair;auto wire=pair.a->Seal(Body(32));REQUIRE(wire);std::vector<uint8_t> out{0x9f};fsc_fail_decrypt_final=true;
 CHECK_FALSE(pair.b->Open(*wire,out));fsc_fail_decrypt_final=false;CHECK(out==std::vector<uint8_t>{0x9f});REQUIRE(pair.b->Open(*wire,out));CHECK(out==Body(32));
}
#endif
#endif
