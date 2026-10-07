#include <rex/system/mmio_handler.h>
#include <rex/platform/function_memory_consumer.h>
#include "../../../src/system/guest_deferred_transaction.h"
#include <rex/system/xmemory.h>
#include <rex/platform/exceptions.h>
#include <rex/logging.h>
#include <cstdio>
#include <array>
#include <cstring>
#include <dlfcn.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <cerrno>
#include <string>
int RunMappedClassifierEquivalence(const char* mode);
namespace {
rex::guest::detail::FunctionMemoryConsumer* signal_scope=nullptr;
const void* signal_address=nullptr;
rex::runtime::MMIOHandler::DeferredTransaction* signal_transaction=nullptr;
bool signal_private=false;
void CompletionSignal(int signal) {
  static constexpr char marker[]="transaction-bridge-signal-enter\n";
  if(signal!=SIGUSR1||!signal_transaction)std::_Exit(96);
  (void)::write(STDERR_FILENO,marker,sizeof(marker)-1);
  rex::guest::EnterSignalContext();
  if(signal_private)rex::guest::detail::DeferredTransactionBridge::CompleteNative(*signal_transaction);
  else signal_transaction->CompleteNative();
  std::_Exit(97);
}

void CachedSignalRead(int signal) {
  static constexpr char marker[]="function-memory-consumer-cached-signal-enter\n";
  if(signal!=SIGUSR1||!signal_scope||!signal_address)std::_Exit(96);
  (void)::write(STDERR_FILENO,marker,sizeof(marker)-1);
  // Same internal context marker used by the production SEH signal entry.
  // The fixture links the exact runtime objects into one executable; no
  // production export or competing private TLS/backend copy is introduced.
  rex::guest::EnterSignalContext();
  signal_scope->Read<uint32_t>(signal_address);
  std::_Exit(97);
}
bool Child(const char* executable,const char* mode,int expected,const char* marker) {
  int descriptors[2];if(pipe(descriptors))return false;
  std::fflush(nullptr);const auto child=fork();
  if(child<0){close(descriptors[0]);close(descriptors[1]);return false;}
  if(!child){
    close(descriptors[0]);if(dup2(descriptors[1],STDERR_FILENO)<0)std::_Exit(96);close(descriptors[1]);alarm(10);
    const auto* loader=std::getenv("HARMONY_TEST_ELF_LOADER");
    const auto* library=std::getenv("HARMONY_TEST_LIBRARY_PATH");
    if(bool(loader)!=bool(library))std::_Exit(96);
    if(loader)execl(loader,loader,"--library-path",library,executable,mode,nullptr);
    else execl(executable,executable,mode,nullptr);
    std::_Exit(96);
  }
  close(descriptors[1]);std::string error;char bytes[512];ssize_t count;
  while((count=read(descriptors[0],bytes,sizeof(bytes)))>0){
    if(error.size()+size_t(count)>4096){kill(child,SIGKILL);close(descriptors[0]);waitpid(child,nullptr,0);return false;}
    error.append(bytes,size_t(count));
  }
  close(descriptors[0]);int status=0;pid_t waited;
  do{waited=waitpid(child,&status,0);}while(waited<0&&errno==EINTR);
  const bool okay=waited==child&&WIFEXITED(status)&&WEXITSTATUS(status)==expected&&error.find(marker)!=std::string::npos;
  const char* kind=std::strncmp(mode,"classifier-",11)?"function_consumer_child":"classifier_refusal_child";
  std::printf("{\"kind\":\"%s\",\"mode\":\"%s\",\"exit\":%d,\"signal\":%d,\"marker_present\":%s}\n",kind,mode,WIFEXITED(status)?WEXITSTATUS(status):-1,WIFSIGNALED(status)?WTERMSIG(status):0,error.find(marker)!=std::string::npos?"true":"false");
  return okay;
}
}
int main(int argc,char** argv) {
 const rlimit no_core{0,0};if(setrlimit(RLIMIT_CORE,&no_core))return 94;
 rex::InitLogging();
 if(argc>1 && !std::strncmp(argv[1],"classifier-",11))
  return RunMappedClassifierEquivalence(argv[1]+11);
 if(argc==1 && RunMappedClassifierEquivalence(nullptr))return 100;
 Dl_info info{};if(!dladdr(reinterpret_cast<void*>(&rex::guest::detail::TryReadBytes),&info)||!info.dli_fname)return 95;
 std::printf("{\"kind\":\"loaded_runtime\",\"path\":\"%s\"}\n",info.dli_fname);
 rex::memory::Memory memory;if(!memory.Initialize())return 1;
 auto* heap=memory.LookupHeapByType(false,65536);uint32_t allocated=0;
 if(!heap||!heap->Alloc(65536,65536,rex::memory::kMemoryAllocationReserve|rex::memory::kMemoryAllocationCommit,rex::memory::kMemoryProtectRead|rex::memory::kMemoryProtectWrite,false,&allocated))return 2;
 auto* p=memory.virtual_membase()+allocated;uint32_t seed=0x7158293A;std::memcpy(p,&seed,4);
 if(argc>1) {
  rex::guest::ExecutionActivation activation;
  rex::guest::detail::FunctionMemoryConsumer scope;
  if(scope.Read<uint32_t>(p)!=seed)return 3;
  rex::guest::CapturedFault fault{};
  if(std::strcmp(argv[1],"bridge-completion-signal")==0||std::strcmp(argv[1],"public-completion-signal")==0) {
    signal_private=std::strcmp(argv[1],"bridge-completion-signal")==0;
    auto transaction=signal_private?rex::guest::detail::DeferredTransactionBridge::Create():rex::runtime::MMIOHandler::DeferredTransaction{};
    signal_transaction=&transaction;
    struct sigaction action{};action.sa_handler=CompletionSignal;sigemptyset(&action.sa_mask);
    if(sigaction(SIGUSR1,&action,nullptr))return 95;
    std::fflush(stdout);if(raise(SIGUSR1))return 96;return 97;
  }
  if(std::strcmp(argv[1],"cached-signal")==0){
   signal_scope=&scope;signal_address=p;
   struct sigaction action{};action.sa_handler=CachedSignalRead;sigemptyset(&action.sa_mask);
   if(sigaction(SIGUSR1,&action,nullptr))return 95;
   std::fputs("function-memory-consumer-cached-scope-armed\n",stderr);std::fflush(stdout);
   if(raise(SIGUSR1))return 96;return 97;
  }

  if(std::strcmp(argv[1],"cached-pending")==0){activation.Publish(fault);scope.Read<uint32_t>(p);std::_Exit(90);}
  if(std::strcmp(argv[1],"cached-adjudicating")==0){rex::guest::AdjudicationScope adjudication(fault);scope.Write<uint32_t>(p,0);std::_Exit(90);}
  return 91;
 }
 unsigned assertions=0;
 for(unsigned repeat=0;repeat<64;++repeat) {
  if(rex::guest::ExecutionActivation::Current())return 4;++assertions;
  {
   rex::guest::detail::FunctionMemoryConsumer direct;
   if(rex::guest::ExecutionActivation::Current())return 5;++assertions;
   if(direct.Read<uint32_t>(p)!=seed)return 6;++assertions;
   auto* owner=rex::guest::ExecutionActivation::Current();if(!owner)return 7;++assertions;
   auto id=owner->id();
   {
    rex::guest::ExecutionActivation child;
    if(child.id()==id||rex::guest::ExecutionActivation::Current()!=&child)return 8;++assertions;
    if(direct.Read<uint32_t>(p)!=seed||child.published_faults()||child.consumed_faults())return 9;++assertions;
    rex::guest::detail::FunctionMemoryConsumer nested;
    if(nested.Read<uint32_t>(p)!=seed||rex::guest::ExecutionActivation::Current()!=&child)return 10;++assertions;
   }
   if(rex::guest::ExecutionActivation::Current()!=owner||owner->id()!=id)return 11;++assertions;
   try{direct.Read<uint32_t>(memory.virtual_membase());return 12;}catch(const rex::SehException& fault){if(fault.code()!=rex::SehException::ACCESS_VIOLATION)return 13;}
   if(owner->HasPendingFault()||owner->published_faults()!=1||owner->consumed_faults()!=1)return 14;++assertions;
   if(direct.Read<uint32_t>(p)!=seed)return 15;++assertions;
  }
  if(rex::guest::ExecutionActivation::Current())return 16;++assertions;
 }
 {
  rex::guest::detail::FunctionMemoryConsumer scope;
  scope.Write<uint8_t>(p+32,0x91);if(scope.Read<uint8_t>(p+32)!=rex::guest::Read<uint8_t>(p+32))return 22;++assertions;
  scope.Write<uint16_t>(p+34,0x9571);if(scope.Read<uint16_t>(p+34)!=rex::guest::Read<uint16_t>(p+34))return 23;++assertions;
  scope.Write<uint32_t>(p+36,0x95613714);if(scope.Read<uint32_t>(p+36)!=rex::guest::Read<uint32_t>(p+36))return 24;++assertions;
  scope.Write<uint64_t>(p+40,0x9561371493517021ULL);if(scope.Read<uint64_t>(p+40)!=rex::guest::Read<uint64_t>(p+40))return 25;++assertions;
  std::array<uint32_t,4> vector{0x9157,0xFFFFFF,0x13525,0xFFFFEEEE};scope.WriteVector(p+48,vector);
  if(scope.ReadVector<decltype(vector)>(p+48)!=rex::guest::ReadVector<decltype(vector)>(p+48))return 26;++assertions;
  if(scope.ReadReserved32(p+36)!=rex::guest::ReadReserved32(p+36))return 27;++assertions;
  if(scope.ReadReserved64(p+40)!=rex::guest::ReadReserved64(p+40))return 28;++assertions;
  scope.Write<uint32_t>(p+64,0x75319246);const auto before32=scope.CompareExchange32(p+64,0x75319246,0x96317821);
  if(before32!=0x75319246||scope.Read<uint32_t>(p+64)!=0x96317821)return 29;++assertions;
  scope.Write<uint64_t>(p+72,0x7531924653107521ULL);const auto before64=scope.CompareExchange64(p+72,0x7531924653107521ULL,0x9631782168259061ULL);
  if(before64!=0x7531924653107521ULL||scope.Read<uint64_t>(p+72)!=0x9631782168259061ULL)return 30;++assertions;
  scope.FillBytes(p+80,0x71,36);rex::guest::FillBytes(p+160,0x71,36);
  if(std::memcmp(p+80,p+160,36))return 31;++assertions;
  if(scope.ReadString(p+80,36)!=rex::guest::ReadString(p+160,36))return 32;++assertions;
 }
 if(rex::guest::ExecutionActivation::Current())return 33;++assertions;
 struct Mapped { unsigned reads=0,writes=0;uint32_t stored=0;bool invalid_phase=false; } mapped;
 auto read=+[](void*,void* opaque,uint32_t)->uint32_t {
   auto& state=*static_cast<Mapped*>(opaque);++state.reads;
   auto* owner=rex::guest::ExecutionActivation::Current();
   state.invalid_phase|=!owner||owner->phase()!=rex::guest::ActivationPhase::Adjudicating||owner->HasPendingFault();
   return 0xABCDE013u;
 };
 auto write=+[](void*,void* opaque,uint32_t,uint32_t value) {
   auto& state=*static_cast<Mapped*>(opaque);++state.writes;state.stored=value;
   auto* owner=rex::guest::ExecutionActivation::Current();
   state.invalid_phase|=!owner||owner->phase()!=rex::guest::ActivationPhase::Adjudicating||owner->HasPendingFault();
 };
 auto* handler=rex::runtime::MMIOHandler::global_handler();
 if(!handler||!handler->RegisterRange(allocated+128,UINT32_MAX,4,&mapped,read,write))return 17;
 for(unsigned owned=0;owned<2;++owned) {
   std::optional<rex::guest::ExecutionActivation> activation;if(owned)activation.emplace();
   auto* before=rex::guest::ExecutionActivation::Current();
   const auto normal=rex::guest::MmioRead32(memory.virtual_membase(),allocated+128);
   rex::guest::MmioWrite32(memory.virtual_membase(),allocated+128,0x91537A62);
   const auto stored=mapped.stored;
   {rex::guest::detail::FunctionMemoryConsumer scope;
    if(scope.MmioRead32(memory.virtual_membase(),allocated+128)!=normal)return 18;++assertions;
    scope.MmioWrite32(memory.virtual_membase(),allocated+128,0x91537A62);
    if(mapped.stored!=stored||mapped.invalid_phase)return 19;++assertions;
   }
   if(rex::guest::ExecutionActivation::Current()!=before)return 20;++assertions;
 }
 if(mapped.reads!=4||mapped.writes!=4)return 21;++assertions;
 std::printf("{\"kind\":\"lazy_lifecycle\",\"assertions\":%u,\"nested_and_direct_owners_restored\":true,\"fault_unwind_and_reuse\":true}\n",assertions);
 char executable[4096];
 const auto* loader=std::getenv("HARMONY_TEST_ELF_LOADER");
 if(loader){if(argv[0][0]!='/'||std::strlen(argv[0])>=sizeof(executable))return 98;std::strcpy(executable,argv[0]);}
 else{auto length=readlink("/proc/self/exe",executable,sizeof(executable)-1);if(length<=0)return 98;executable[length]=0;}
 if(!Child(executable,"cached-pending",86,"guest-continuation-with-pending-fault")||
    !Child(executable,"cached-adjudicating",86,"guest-access-during-adjudication")||
    !Child(executable,"cached-signal",139,"function-memory-consumer-cached-signal-enter")||
    !Child(executable,"bridge-completion-signal",139,"transaction-bridge-signal-enter")||
    !Child(executable,"public-completion-signal",139,"transaction-bridge-signal-enter")||
    !Child(executable,"classifier-throw-point",86,"exception-classifying-mmio-address")||
    !Child(executable,"classifier-throw-range",86,"exception-classifying-mmio-range")||
    !Child(executable,"classifier-nonlinear",86,"nonlinear-mapped-admission-range")||
    !Child(executable,"classifier-overflow",86,"mapped-admission-range-overflow"))return 99;
 return 0;
}
