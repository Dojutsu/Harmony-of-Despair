// Private metadata classification equivalence; linked into one coherent runtime image.
#include "../../../src/core/guest_mmio_classifier.h"
#include <rex/logging.h>
#include <array>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
struct Translation { uintptr_t begin; uint32_t guest_base; unsigned calls=0, mode=0; };
uint32_t Translate(const void* opaque,const void* address) {
 auto& t=*const_cast<Translation*>(static_cast<const Translation*>(opaque));++t.calls;
 const auto delta=reinterpret_cast<uintptr_t>(address)-t.begin;
 if(t.mode==1 || (t.mode==2 && delta))throw std::runtime_error("fixture translator");
 return t.guest_base+uint32_t(delta)*(t.mode==3?2:1);
}
int RunMappedClassifierEquivalence(const char* mode) {
 using Handler=rex::runtime::MMIOHandler;
 constexpr uintptr_t begin=uintptr_t(0x10000000000ULL),end=begin+65536;
 Translation t{begin,0};
 auto read=+[](void*,void*,uint32_t)->uint32_t{std::_Exit(97);};
 auto write=+[](void*,void*,uint32_t,uint32_t){std::_Exit(97);};
 auto make=[&]{return Handler::Install(reinterpret_cast<uint8_t*>(begin),reinterpret_cast<uint8_t*>(end),reinterpret_cast<uint8_t*>(end+65536),Translate,&t,nullptr,nullptr);};
 if(mode) {
  auto handler=make();if(!handler)return 96;handler->RegisterRange(0,0xFFFF0000,65535,nullptr,read,write);
  uint32_t point=0;bool mapped=false;
  if(!std::strcmp(mode,"throw-point"))t.mode=1;
  else if(!std::strcmp(mode,"throw-range"))t.mode=2;
  else if(!std::strcmp(mode,"nonlinear"))t.mode=3;
  else if(!std::strcmp(mode,"overflow")) {
   rex::guest::detail::MappedAccessClassifier::Classify(*handler,reinterpret_cast<void*>(UINTPTR_MAX),8,point,mapped);return 98;
  } else return 99;
  rex::guest::detail::MappedAccessClassifier::Classify(*handler,reinterpret_cast<void*>(begin),4,point,mapped);return 98;
 }
 struct Range {uint32_t address,mask,size;};
 uint64_t probes=0,byte_oracles=0;unsigned sets=0;
 uint32_t rng=0x91573102;
 auto random=[&]{rng^=rng<<13;rng^=rng>>17;rng^=rng<<5;return rng;};
 const uint32_t masks[]={0,1,2,3,7,15,255,65535,0xFFFF0000,UINT32_MAX,0xAAAAAAAA,0x55555555,0xF00000F0,0x80000001};
 for(unsigned epoch=0;epoch<80;++epoch) {
  t.guest_base=epoch%3==0?0:epoch%3==1?0x7FC7FFF0:0xA0000000;
  t.mode=0;auto handler=make();if(!handler)return 1;
  std::vector<Range> ranges;
  for(unsigned i=0;i<1+epoch%7;++i) {
   const auto mask=i<3?masks[(epoch+i)%14]:random();
   uint32_t address=(t.guest_base+random()%65536)&mask;
   if(i==2 && epoch%5==0)address|=~mask&0x10101;
   const auto size=random()%16384;ranges.push_back({address,mask,size});
   if(!handler->RegisterRange(address,mask,size,nullptr,read,write))return 2;
  }
  auto probe=[&](uintptr_t first,size_t length) {
   uint32_t old_point=0x12345678,new_point=old_point;bool new_mapped=false;
   const bool old_mapped=handler->IsMappedAddress(reinterpret_cast<void*>(first),&old_point);
   const bool old_overlap=handler->IsMappedRange(reinterpret_cast<void*>(first),length);
   const bool new_overlap=rex::guest::detail::MappedAccessClassifier::Classify(*handler,reinterpret_cast<void*>(first),length,new_point,new_mapped);
   bool point_oracle=false,overlap_oracle=false;
   if(first>=begin&&first<end)for(const auto& range:ranges)point_oracle|=((uint32_t(first-begin)+t.guest_base)&range.mask)==range.address;
   for(size_t byte=0;byte<length;++byte) {
    const auto address=first+byte;
    if(address<begin||address>=end)continue;
    ++byte_oracles;for(const auto& range:ranges)overlap_oracle|=((uint32_t(address-begin)+t.guest_base)&range.mask)==range.address;
   }
   if(old_mapped!=new_mapped||old_overlap!=new_overlap||old_point!=new_point||old_mapped!=point_oracle||old_overlap!=overlap_oracle) {
    std::fprintf(stderr,"epoch=%u first=%zx length=%zu mapped=%u/%u/%u span=%u/%u/%u point=%x/%x\n",epoch,first,length,old_mapped,new_mapped,point_oracle,old_overlap,new_overlap,overlap_oracle,old_point,new_point);std::_Exit(3);
   }
   ++probes;
  };
  for(unsigned i=0;i<256;++i)probe(begin+random()%65536,random()%257);
  for(auto first:{begin-32,begin-1,begin,begin+1,end-32,end-1,end,end+1})for(size_t length:{0,1,2,4,8,16,32,64,128})probe(first,length);
  for(auto offset:{0u,1u,0x7FFFu,0x8000u,0xFFF0u})probe(begin+offset,512);
  ++sets;
 }
 // An earlier overlap must not hide a later first-byte device match.
 t.guest_base=0;t.calls=0;auto handler=make();if(!handler)return 4;
 handler->RegisterRange(8,UINT32_MAX,1,nullptr,read,write);
 handler->RegisterRange(0,UINT32_MAX,1,nullptr,read,write);
 uint32_t point=99;bool mapped=false;
 const bool overlap=rex::guest::detail::MappedAccessClassifier::Classify(*handler,reinterpret_cast<void*>(begin),16,point,mapped);
 if(!overlap||!mapped||point!=0||t.calls!=2)return 5;
 t.calls=0;uint32_t oldpoint=99;
 if(!handler->IsMappedAddress(reinterpret_cast<void*>(begin),&oldpoint)||!handler->IsMappedRange(reinterpret_cast<void*>(begin),16)||oldpoint!=0||t.calls!=3)return 6;
 std::printf("{\"kind\":\"classifier_equivalence\",\"range_sets\":%u,\"probes\":%llu,\"byte_oracles\":%llu,\"callbacks\":0,\"old_translation_calls\":3,\"new_translation_calls\":2,\"clipped_sparse_alias_intervals_equal\":true}\n",sets,(unsigned long long)probes,(unsigned long long)byte_oracles);
 return 0;
}
