#include <catch2/catch_test_macros.hpp>
#include <rex/platform.h>
#if REX_PLATFORM_GNU_LINUX
#include <rex/memory/mapping_lease.h>
#include <rex/memory/utils.h>
#include <rex/platform/guest_access.h>
#include <rex/platform/guest_memory.h>
#include <rex/system/thread_state.h>
#include <rex/system/xmemory.h>
#include "../test_memory.h"
#include <atomic>
#include <barrier>
#include <chrono>
#include <thread>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string>

TEST_CASE("Linux mapping leases exclude real host VM mutators and release after leaf faults", "[linux][mapping-lease]") {
  using namespace rex::memory;
  for(unsigned operation=0;operation<6;++operation) {
    INFO("mutator "<<operation);
    auto* pages=static_cast<unsigned char*>(AllocFixed(nullptr,8192,AllocationType::kReserveCommit,PageAccess::kReadWrite));
    REQUIRE(pages!=nullptr);std::memset(pages,0xA5,8192);
    auto fd=CreateFileMappingHandle("lease-unit-"+std::to_string(getpid()),8192,PageAccess::kReadWrite,true);
    REQUIRE(fd!=kFileMappingHandleInvalid);
    std::atomic<bool> completed=false,okay=false;std::barrier rendezvous(2);
    MappingAccessLease lease;auto identity=lease.identity();auto generation=lease.generation();
    std::thread mutator([&]{rendezvous.arrive_and_wait();switch(operation){
      case 0:okay=Protect(pages+4096,4096,PageAccess::kReadOnly);break;
      case 1:okay=DeallocFixed(pages,8192,DeallocationType::kDecommit);break;
      case 2:okay=DeallocFixed(pages,8192,DeallocationType::kRelease);break;
      case 3:okay=MapFileView(fd,pages,8192,PageAccess::kReadWrite,0)==pages;break;
      case 4:okay=UnmapFileView(fd,pages,8192);break;
      case 5:CloseFileMappingHandle(fd,"lease-unit-"+std::to_string(getpid()));okay=true;break;
    }completed=true;});
    rendezvous.arrive_and_wait();auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(3);
    while(!MappingMutationWaiters()&&std::chrono::steady_clock::now()<deadline)std::this_thread::yield();
    CHECK(MappingMutationWaiters()>0);CHECK_FALSE(completed.load());
    CHECK(lease.identity()==identity);CHECK(lease.generation()==generation);
    for(size_t width : {size_t(2),size_t(4),size_t(8)}) {
      auto* cell=pages+4096-width/2;
      std::memset(cell,0xA5,width);
      uint64_t value=0,expected=0;std::memset(&expected,0xA5,width);
      auto read=rex::guest::CaptureRead(cell,&value,width);CHECK(read.success);CHECK(value==expected);
      const uint64_t input=0x00001A3E0080503FULL;
      auto write=rex::guest::CaptureWrite(cell,&input,width);CHECK(write.success);
      CHECK(std::memcmp(cell,&input,width)==0);
    }
    lease.Release();mutator.join();CHECK(completed.load());CHECK(okay.load());CHECK_FALSE(HasMappingAccessLease());
    if(operation!=2&&operation!=4)CHECK(DeallocFixed(pages,8192,DeallocationType::kRelease));
    if(operation!=5)CloseFileMappingHandle(fd,"lease-unit-"+std::to_string(getpid()));
  }
  auto* pages=static_cast<unsigned char*>(AllocFixed(nullptr,8192,AllocationType::kReserveCommit,PageAccess::kReadWrite));REQUIRE(pages!=nullptr);
  for(unsigned mask=1;mask<4;++mask){std::memset(pages,0xA5,8192);REQUIRE(Protect(pages,4096,mask&1?PageAccess::kNoAccess:PageAccess::kReadWrite));REQUIRE(Protect(pages+4096,4096,mask&2?PageAccess::kNoAccess:PageAccess::kReadWrite));
    unsigned cleanup=0;struct Cleanup{unsigned& n;~Cleanup(){++n;}};
    {Cleanup cleanup_guard{cleanup};MappingAccessLease lease;uint64_t value=0xDEADBEEF12345678ULL;
      auto read=rex::guest::CaptureRead(pages+4095,&value,8);CHECK_FALSE(read.success);CHECK(value==0xDEADBEEF12345678ULL);CHECK(read.fault.access_intent==0);
      uint64_t input=0x1234567887654321ULL;auto write=rex::guest::CaptureWrite(pages+4092,&input,8);CHECK_FALSE(write.success);CHECK(write.fault.access_intent==1);
    }CHECK(cleanup==1);CHECK_FALSE(HasMappingAccessLease());REQUIRE(Protect(pages,8192,PageAccess::kReadWrite));CHECK(std::memcmp(pages+4092,"\xA5\xA5\xA5\xA5\xA5\xA5\xA5\xA5",8)==0);
  }CHECK(DeallocFixed(pages,8192,DeallocationType::kRelease));
}

TEST_CASE("Linux mapping lease also freezes real virtual heap commitment and protection", "[linux][mapping-lease]") {
  using namespace rex::memory;auto& memory=rex::testing::GetTestMemory();auto* heap=memory.LookupHeapByType(false,65536);REQUIRE(heap!=nullptr);
  for(unsigned operation=0;operation<3;++operation){uint32_t address=0;REQUIRE(heap->Alloc(65536,65536,kMemoryAllocationReserve|kMemoryAllocationCommit,kMemoryProtectRead|kMemoryProtectWrite,false,&address));
    auto global=rex::thread::global_critical_region::AcquireDirect();MappingAccessLease lease;HeapAllocationInfo before{};REQUIRE(heap->QueryRegionInfo(address,&before));global.unlock();
    std::barrier rendezvous(2);std::atomic<bool> completed=false,okay=false;
    std::thread mutator([&]{rendezvous.arrive_and_wait();if(operation==0)okay=heap->Protect(address,65536,kMemoryProtectRead);if(operation==1)okay=heap->Decommit(address,65536);if(operation==2)okay=heap->Release(address);completed=true;});
    rendezvous.arrive_and_wait();auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(3);while(!MappingMutationWaiters()&&std::chrono::steady_clock::now()<deadline)std::this_thread::yield();
    CHECK(MappingMutationWaiters()>0);CHECK_FALSE(completed.load());HeapAllocationInfo held{};REQUIRE(heap->QueryRegionInfo(address,&held));CHECK(held.state==before.state);CHECK(held.protect==before.protect);CHECK(held.allocation_base==before.allocation_base);
    lease.Release();mutator.join();CHECK(okay.load());CHECK(completed.load());if(operation!=2)CHECK(heap->Release(address));
  }
}

TEST_CASE("Linux mapping lease blocks physical rewatch and large-page allocation", "[linux][mapping-lease]") {
  using namespace rex::memory;
  auto& memory=rex::testing::GetTestMemory();
  auto* heap=memory.LookupHeapByType(true,65536);REQUIRE(heap!=nullptr);
  uint32_t address=0;REQUIRE(heap->Alloc(65536,65536,kMemoryAllocationReserve|kMemoryAllocationCommit,kMemoryProtectRead|kMemoryProtectWrite,false,&address));
  for(unsigned operation=0;operation<2;++operation) {
    auto global=rex::thread::global_critical_region::AcquireDirect();MappingAccessLease lease;global.unlock();
    std::barrier rendezvous(2);std::atomic<bool> completed=false,okay=false,blocked=false;uint32_t second=0;
    std::thread mutator([&]{
      rendezvous.arrive_and_wait();
      std::unique_lock<std::recursive_mutex> critical(rex::thread::global_critical_region::mutex(),std::defer_lock);
      if(!critical.try_lock()){blocked=true;critical.lock();}
      if(operation==0){memory.EnablePhysicalMemoryAccessCallbacks(memory.GetPhysicalAddress(address),4096,true,false);okay=true;}
      else okay=heap->Alloc(65536,65536,kMemoryAllocationReserve|kMemoryAllocationCommit,kMemoryProtectRead|kMemoryProtectWrite,false,&second);
      completed=true;
    });
    rendezvous.arrive_and_wait();auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(3);
    while(!blocked.load()&&std::chrono::steady_clock::now()<deadline)std::this_thread::yield();
    CHECK(blocked.load());CHECK_FALSE(completed.load());lease.Release();mutator.join();CHECK(completed.load());CHECK(okay.load());if(second)CHECK(heap->Release(second));
  }
  CHECK(heap->Release(address));
}

TEST_CASE("Linux mapping lease delays actual Memory destruction until leaf completion", "[linux][mapping-lease]") {
  auto& memory=rex::testing::GetTestMemory();auto child=fork();REQUIRE(child>=0);
  if(!child){alarm(10);auto global=rex::thread::global_critical_region::AcquireDirect();rex::memory::MappingAccessLease lease;global.unlock();
    std::barrier barrier(2);std::atomic<bool> complete=false;
    std::thread destroyer([&]{barrier.arrive_and_wait();memory.~Memory();complete=true;});barrier.arrive_and_wait();
    auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(3);while(!rex::memory::MappingMutationWaiters()&&std::chrono::steady_clock::now()<deadline)std::this_thread::yield();
    if(!rex::memory::MappingMutationWaiters()||complete.load())_exit(95);
    lease.Release();destroyer.join();_exit(complete.load()?0:96);
  }int status=0;REQUIRE(waitpid(child,&status,0)==child);CHECK(WIFEXITED(status));CHECK(WEXITSTATUS(status)==0);
}

TEST_CASE("Linux mapping lease detects duplicate release and forbidden recursive ownership", "[linux][mapping-lease][negative-control]") {
 for(unsigned mode=0;mode<4;++mode){auto child=fork();REQUIRE(child>=0);if(!child){alarm(3);rex::memory::MappingAccessLease lease;if(mode==0){lease.Release();lease.Release();}if(mode==1){rex::memory::MappingMutationScope mutation;}if(mode==2){rex::memory::MappingAccessLease nested;}if(mode==3){std::thread other([&]{lease.Release();});other.join();}_exit(97);}int status=0;REQUIRE(waitpid(child,&status,0)==child);CHECK(WIFEXITED(status));CHECK(WEXITSTATUS(status)==86);}
}
#endif

#if REX_PLATFORM_GNU_LINUX
TEST_CASE("Linux ordinary scalar virtual RAM crosses every host-page split without partial publication", "[linux][mapping-lease][guest-fault][scalar16][scalar32][scalar64]") {
  using namespace rex::memory;
  auto& memory=rex::testing::GetTestMemory();
  auto* heap=memory.LookupHeapByType(false,65536);REQUIRE(heap!=nullptr);
  uint32_t address=0;
  REQUIRE(heap->Alloc(131072,65536,kMemoryAllocationReserve|kMemoryAllocationCommit,
      kMemoryProtectRead|kMemoryProtectWrite,false,&address));
  auto* pages=memory.TranslateVirtual<unsigned char*>(address);
  struct Binding {
    rex::runtime::ThreadState* previous=rex::runtime::ThreadState::Get();
    rex::runtime::ThreadState thread;
    explicit Binding(Memory& memory):thread(99,0,0,&memory){rex::runtime::ThreadState::Bind(&thread);}
    ~Binding(){rex::runtime::ThreadState::Bind(previous);}
  } binding(memory);
  // The second boundary also crosses a guest 64 KiB page, keeping one allocation.
  for(size_t boundary : {page_size(),size_t(65536)}) {
    for(size_t width : {size_t(2),size_t(4),size_t(8)}) {
      for(size_t first_bytes=1;first_bytes<width;++first_bytes) {
        INFO("boundary "<<boundary<<", width "<<width<<", split "<<first_bytes);
        auto* cell=pages+boundary-first_bytes;
        for(unsigned denied=0;denied<4;++denied) {
          INFO("read protection mask "<<denied);
          std::memset(cell,0xA5,width);
          REQUIRE(Protect(pages+boundary-page_size(),page_size(),denied&1?PageAccess::kNoAccess:PageAccess::kReadWrite));
          REQUIRE(Protect(pages+boundary,page_size(),denied&2?PageAccess::kNoAccess:PageAccess::kReadWrite));
          rex::guest::ExecutionActivation activation;uint64_t output=0xDEADBEEFCAFEBABEULL;
          uint64_t expected=output;
          std::memset(&expected,0xA5,width);
          auto result=rex::guest::detail::TryReadBytes(cell,&output,width);
          REQUIRE(result.IsSuccess()==(denied==0));
          if(result.Failed()) {
            CHECK(output==0xDEADBEEFCAFEBABEULL);
            CHECK(activation.published_faults()==1);
            const auto fault=activation.Consume(result.Fault());
            CHECK(fault.access_intent==0);
            CHECK(fault.address==reinterpret_cast<uintptr_t>(denied&1?cell:pages+boundary));
            CHECK(activation.consumed_faults()==1);
          } else CHECK(output==expected);
          CHECK_FALSE(HasMappingAccessLease());
          REQUIRE(Protect(pages+boundary-page_size(),page_size()*2,PageAccess::kReadWrite));
        }
        for(unsigned denied=0;denied<4;++denied) {
          INFO("write protection mask "<<denied);
          std::memset(cell-1,0xA5,width+2);
          REQUIRE(Protect(pages+boundary-page_size(),page_size(),denied&1?PageAccess::kReadOnly:PageAccess::kReadWrite));
          REQUIRE(Protect(pages+boundary,page_size(),denied&2?PageAccess::kReadOnly:PageAccess::kReadWrite));
          rex::guest::ExecutionActivation activation;
          const uint64_t payload=0x00001A3E0080503FULL;
          auto result=rex::guest::detail::TryWriteBytes(cell,&payload,width);
          REQUIRE(result.IsSuccess()==(denied==0));
          if(result.Failed()) {
            CHECK(activation.published_faults()==1);
            const auto fault=activation.Consume(result.Fault());
            CHECK(fault.access_intent==1);
            CHECK(fault.address==reinterpret_cast<uintptr_t>(denied&1?cell:pages+boundary));
            CHECK(activation.consumed_faults()==1);
          }
          CHECK_FALSE(HasMappingAccessLease());
          REQUIRE(Protect(pages+boundary-page_size(),page_size()*2,PageAccess::kReadWrite));
          CHECK(cell[-1]==0xA5);CHECK(cell[width]==0xA5);
          if(denied) {
            for(size_t byte=0;byte<width;++byte)CHECK(cell[byte]==0xA5);
          } else CHECK(std::memcmp(cell,&payload,width)==0);
        }
      }
    }
  }
  CHECK(heap->Release(address));
}

TEST_CASE("Linux scalar32 stage-loading address is admitted within its original allocation", "[linux][mapping-lease][guest-fault][scalar32]") {
  using namespace rex::memory;
  constexpr uint32_t allocation=0x43E00000,allocation_size=0x400000,guest=0x43FD6FFE;
  auto& memory=rex::testing::GetTestMemory();
  auto* heap=memory.LookupHeap(guest);REQUIRE(heap!=nullptr);
  REQUIRE(heap->heap_type()==HeapType::kGuestVirtual);
  REQUIRE(heap->AllocFixed(allocation,allocation_size,65536,kMemoryAllocationReserve|kMemoryAllocationCommit,kMemoryProtectRead|kMemoryProtectWrite));
  auto* cell=memory.TranslateVirtual<unsigned char*>(guest);
  REQUIRE(reinterpret_cast<uintptr_t>(cell)%page_size()==page_size()-2);
  HeapAllocationInfo info{};REQUIRE(heap->QueryRegionInfo(guest,&info));
  CHECK(info.allocation_base==allocation);CHECK(info.allocation_size==allocation_size);
  struct Binding {
    rex::runtime::ThreadState* previous=rex::runtime::ThreadState::Get();
    rex::runtime::ThreadState thread;
    explicit Binding(Memory& memory):thread(99,0,0,&memory){rex::runtime::ThreadState::Bind(&thread);}
    ~Binding(){rex::runtime::ThreadState::Bind(previous);}
  } binding(memory);
  std::memcpy(cell,"\x12\x34\x56\x78",4);
  rex::guest::ExecutionActivation activation;
  auto read=rex::guest::TryRead<uint32_t>(cell);
  REQUIRE(read.IsSuccess());CHECK(read.Value()==0x78563412);
  auto write=rex::guest::TryWrite<uint32_t>(cell,0xA1B2C3D4);
  REQUIRE(write.IsSuccess());CHECK(std::memcmp(cell,"\xD4\xC3\xB2\xA1",4)==0);
  CHECK(activation.published_faults()==0);CHECK_FALSE(HasMappingAccessLease());
  CHECK(heap->Release(allocation));
}

TEST_CASE("Linux cross-page scalar admission rejects mutated virtual heap state", "[linux][mapping-lease][guest-fault][negative-control]") {
  using namespace rex::memory;
  auto& memory=rex::testing::GetTestMemory();
  auto* heap=memory.LookupHeapByType(false,65536);REQUIRE(heap!=nullptr);
  struct Binding {
    rex::runtime::ThreadState* previous=rex::runtime::ThreadState::Get();
    rex::runtime::ThreadState thread;
    explicit Binding(Memory& memory):thread(99,0,0,&memory){rex::runtime::ThreadState::Bind(&thread);}
    ~Binding(){rex::runtime::ThreadState::Bind(previous);}
  } binding(memory);
  for(size_t width : {size_t(2),size_t(4),size_t(8)}) {
    for(unsigned operation=0;operation<3;++operation) {
      for(unsigned denied=1;denied<4;++denied) {
        if(operation==2 && denied!=3)continue;
        INFO("width "<<width<<", mutator "<<operation<<", denial mask "<<denied);
        uint32_t address=0;
        REQUIRE(heap->Alloc(131072,65536,kMemoryAllocationReserve|kMemoryAllocationCommit,kMemoryProtectRead|kMemoryProtectWrite,false,&address));
        auto* pages=memory.TranslateVirtual<unsigned char*>(address);
        auto* cell=pages+65536-width/2;
        std::memset(cell-1,0xA5,width+2);
        for(unsigned half=0;half<2;++half) {
          if(!(denied&(1u<<half)))continue;
          if(operation==0)REQUIRE(heap->Protect(address+half*65536,65536,kMemoryProtectNoAccess));
          if(operation==1)REQUIRE(heap->Decommit(address+half*65536,65536));
        }
        if(operation==2)REQUIRE(heap->Release(address));
        const auto fault_address=reinterpret_cast<uintptr_t>(denied&1?cell:pages+65536);
        rex::guest::ExecutionActivation activation;
        uint64_t output=0xDEADBEEFCAFEBABEULL,payload=0x1234567887654321ULL;
        auto read=rex::guest::detail::TryReadBytes(cell,&output,width);
        REQUIRE(read.Failed());CHECK(output==0xDEADBEEFCAFEBABEULL);
        const auto read_fault=activation.Consume(read.Fault());
        CHECK(read_fault.address==fault_address);CHECK(read_fault.access_intent==0);
        auto write=rex::guest::detail::TryWriteBytes(cell,&payload,width);
        REQUIRE(write.Failed());
        const auto write_fault=activation.Consume(write.Fault());
        CHECK(write_fault.address==fault_address);CHECK(write_fault.access_intent==1);
        CHECK(activation.published_faults()==2);CHECK(activation.consumed_faults()==2);
        CHECK_FALSE(HasMappingAccessLease());
        if(operation!=2) {
          REQUIRE(Protect(pages+65536-page_size(),page_size()*2,PageAccess::kReadWrite));
          for(size_t byte=0;byte<width;++byte)CHECK(cell[byte]==0xA5);
          CHECK(cell[-1]==0xA5);CHECK(cell[width]==0xA5);
          CHECK(heap->Release(address));
        }
      }
    }
  }
}

TEST_CASE("Linux owner retirement rejects stale thread bindings and drains admitted operations", "[linux][mapping-lease][retirement]") {
  using namespace rex::memory;
  auto& memory=rex::testing::GetTestMemory();
  auto child=fork();REQUIRE(child>=0);
  if(!child) {
    alarm(10);
    rex::runtime::ThreadState stale(99,0,0,&memory);
    const auto control=stale.memory_access_control();
    auto pin=std::make_unique<GuestMemoryAccessPin>(control);
    if(pin->memory()!=&memory)_exit(91);
    std::atomic<bool> started=false,complete=false;
    std::thread destroyer([&]{started=true;memory.~Memory();complete=true;});
    const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(3);
    bool closed=false;
    while(std::chrono::steady_clock::now()<deadline) {
      GuestMemoryAccessPin probe(control);
      if(!probe.memory()){closed=true;break;}
      std::this_thread::yield();
    }
    if(!started.load() || !closed || complete.load())_exit(92);
    // Retirement waited without holding global: an existing pin can finish.
    { MappingAccessLease lease;if(pin->memory()!=&memory)_exit(93); }
    pin.reset();destroyer.join();
    GuestMemoryAccessPin rejected(stale.memory_access_control());
    if(rejected.memory() || !complete.load())_exit(94);
    // The stale binding rejects a checked access before touching freed Memory.
    rex::runtime::ThreadState::Bind(&stale);
    for(size_t width : {size_t(2),size_t(4),size_t(8)}) {
      rex::guest::ExecutionActivation activation;
      uint64_t output=0xDEADBEEFCAFEBABEULL,payload=0x1234567887654321ULL;
      auto* cell=reinterpret_cast<void*>(0x140000FFFULL);
      auto read=rex::guest::detail::TryReadBytes(cell,&output,width);
      if(!read.Failed() || output!=0xDEADBEEFCAFEBABEULL)_exit(95);
      auto fault=activation.Consume(read.Fault());
      if(fault.address!=0x140000FFFULL || fault.access_intent || activation.consumed_faults()!=1)_exit(96);
      auto write=rex::guest::detail::TryWriteBytes(cell,&payload,width);
      if(!write.Failed())_exit(97);
      fault=activation.Consume(write.Fault());
      if(fault.address!=0x140000FFFULL || fault.access_intent!=1 || activation.consumed_faults()!=2)_exit(98);
    }
    rex::runtime::ThreadState::Bind(nullptr);
    _exit(0);
  }
  int status=0;REQUIRE(waitpid(child,&status,0)==child);
  REQUIRE(WIFEXITED(status));CHECK(WEXITSTATUS(status)==0);
}
#endif

#if REX_PLATFORM_GNU_LINUX
TEST_CASE("Linux cross-page admission rejects replaced backing even when heap metadata is unchanged", "[linux][mapping-lease][guest-fault][negative-control]") {
  using namespace rex::memory;
  auto& memory=rex::testing::GetTestMemory();
  auto* heap=memory.LookupHeapByType(false,65536);REQUIRE(heap!=nullptr);
  uint32_t address=0;REQUIRE(heap->Alloc(65536,65536,kMemoryAllocationReserve|kMemoryAllocationCommit,kMemoryProtectRead|kMemoryProtectWrite,false,&address));
  auto* pages=memory.TranslateVirtual<unsigned char*>(address);
  auto fd=CreateFileMappingHandle("replacement-unit-"+std::to_string(getpid()),8192,PageAccess::kReadWrite,true);
  REQUIRE(fd!=kFileMappingHandleInvalid);
  for(size_t width : {size_t(2),size_t(4),size_t(8)}) {
    for(bool write : {false,true}) {
      INFO("width "<<width<<", write "<<write);
      auto child=fork();REQUIRE(child>=0);
      if(!child) {
        alarm(5);
        if(MapFileView(fd,pages,8192,PageAccess::kReadWrite,0)!=pages)_exit(91);
        rex::runtime::ThreadState binding(99,0,0,&memory);rex::runtime::ThreadState::Bind(&binding);
        rex::guest::ExecutionActivation activation;
        uint64_t value=0x1122334455667788ULL;
        auto* cell=pages+page_size()-width/2;
        auto result=write?rex::guest::detail::TryWriteBytes(cell,&value,width):rex::guest::detail::TryReadBytes(cell,&value,width);
        (void)result;_exit(92);
      }
      int status=0;REQUIRE(waitpid(child,&status,0)==child);
      REQUIRE(WIFEXITED(status));CHECK(WEXITSTATUS(status)==rex::guest::kFaultContractFailureExitCode);
    }
  }
  auto* observed=static_cast<unsigned char*>(MapFileView(fd,nullptr,8192,PageAccess::kReadOnly,0));
  REQUIRE(observed!=nullptr);CHECK(std::memcmp(observed+4092,"\0\0\0\0\0\0\0\0",8)==0);
  CHECK(UnmapFileView(fd,observed,8192));
  CloseFileMappingHandle(fd,"replacement-unit-"+std::to_string(getpid()));
  CHECK(heap->Release(address));
}
#endif
