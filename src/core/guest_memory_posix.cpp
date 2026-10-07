#include "guest_access_state.h"
#include <rex/platform/guest_memory.h>
#include "guest_access_compact.h"
#include "guest_mmio_classifier.h"
#include "../system/guest_deferred_transaction.h"
#include <rex/exception_handler.h>
#include <rex/logging.h>
#include <rex/memory/utils.h>
#include <rex/system/mmio_handler.h>
#include <rex/system/thread_state.h>
#include <rex/system/xmemory.h>
#include <rex/types.h>

#include <cstring>
#include <cstdio>
#include <execinfo.h>
#include <unistd.h>
#include <limits>

namespace rex::guest {
namespace {
using MMIO = runtime::MMIOHandler;
constexpr unsigned kRetryLimit = 8;
// Only operation-local address arithmetic is shared: no owner, backing,
// mapping, permission, callback or retry decision is retained here.
struct HostPageBoundary { size_t page; size_t offset; };
size_t HostPageOffset(uintptr_t address, size_t page) noexcept {
  return address % page;
}
HostPageBoundary HostBoundaryFor(const void* pointer, size_t width) noexcept {
  const auto address = reinterpret_cast<uintptr_t>(pointer);
  if (width > std::numeric_limits<uintptr_t>::max() - address)
    FaultContractFailure("access-range-overflow");
  const auto page = memory::page_size();
  return {page, HostPageOffset(address, page)};
}

// Ordinary virtual RAM has no physical write-watch/device callbacks. Retain
// owner and mapping admission through one x86 scalar MOV, including its epilogue.
// A failing MOV publishes no bytes/output and is never split or replayed.
// This is an unaligned scalar operation, not an atomic snapshot guarantee.
std::optional<AccessAttempt> CaptureCrossPageRamScalar(const void* pointer,void* value,size_t width,bool write,const HostPageBoundary& boundary) noexcept {
  const auto address=reinterpret_cast<uintptr_t>(pointer);
  const auto page=boundary.page;
  if(address>std::numeric_limits<uintptr_t>::max()-width || boundary.offset<=page-width)return std::nullopt;
  auto* thread=runtime::ThreadState::Get();
  if(!thread)return std::nullopt;
  memory::GuestMemoryAccessPin owner(thread->memory_access_control());
  if(!owner.memory()) {
    AccessAttempt denied{};denied.fault.address=address;denied.fault.access_intent=write;
    return denied;
  }
  memory::MappingAccessLease lease;
  auto* memory=owner.memory();
  const auto guest=memory->HostToGuestVirtual(pointer);
  if(guest>UINT32_MAX-(width-1) || memory->TranslateVirtual(guest)!=pointer ||
     memory->TranslateVirtual(guest+width-1)!=static_cast<const uint8_t*>(pointer)+width-1 ||
     !memory->MatchesGuestBacking(pointer,guest,width))return std::nullopt;
  auto* first=memory->LookupHeap(guest);auto* last=memory->LookupHeap(guest+width-1);
  if(!first || first!=last || first->heap_type()!=memory::HeapType::kGuestVirtual)return std::nullopt;
  if(auto* handler=MMIO::global_handler();handler && handler->IsMappedRange(pointer,width))return std::nullopt;
  memory::HeapAllocationInfo a{},b{};
  if(!first->QueryRegionInfo(guest,&a) || !last->QueryRegionInfo(guest+width-1,&b) ||
     a.allocation_base!=b.allocation_base || a.allocation_size!=b.allocation_size)return std::nullopt;
  const unsigned permissions=memory::kMemoryProtectRead|(write?memory::kMemoryProtectWrite:0);
  const bool first_admitted=(a.state&memory::kMemoryAllocationCommit) && (a.protect&permissions)==permissions;
  const bool last_admitted=(b.state&memory::kMemoryAllocationCommit) && (b.protect&permissions)==permissions;
  if(!first_admitted || !last_admitted) {
    AccessAttempt denied{};
    denied.fault.address=first_admitted?address+page-boundary.offset:address;
    denied.fault.access_intent=write;
    return denied;
  }
  if(write)return CaptureWrite(const_cast<void*>(pointer),value,width);
  uint64_t staged=0;
  auto captured=CaptureRead(pointer,&staged,width);
  if(captured.success)std::memcpy(value,&staged,width);
  return captured;
}
void DiagnoseCrossPage(const void* pointer,size_t width,bool atomic,bool vector,bool write) noexcept {
  const auto address=reinterpret_cast<uintptr_t>(pointer);
  const auto page=memory::page_size();
  auto* thread=runtime::ThreadState::Get();
  std::fprintf(stderr,"{\"event\":\"rejected-cross-page-access\",\"tid\":%ld,\"guest_thread\":%u,\"address\":\"0x%llx\",\"width\":%zu,\"first_bytes\":%zu,\"alignment\":%zu,\"atomic\":%s,\"vector\":%s,\"write\":%s,\"native_access_started\":false}\n",
    static_cast<long>(gettid()),thread?thread->thread_id():0,
    static_cast<unsigned long long>(address),width,page-address%page,address%width,
    atomic?"true":"false",vector?"true":"false",write?"true":"false");
  for(auto target : {address,address+width-1}) {
    memory::PageAccess access{};size_t length=page;
    bool known=memory::QueryProtect(reinterpret_cast<void*>(target),length,access);
    std::fprintf(stderr,"{\"event\":\"rejected-access-host-page\",\"page\":\"0x%llx\",\"known\":%s,\"protection\":%u}\n",
      static_cast<unsigned long long>(target-target%page),known?"true":"false",static_cast<unsigned>(access));
    if(thread) {
      auto* memory=thread->memory();auto guest=memory->HostToGuestVirtual(reinterpret_cast<void*>(target));
      if(auto* heap=memory->LookupHeap(guest)) {
        memory::HeapAllocationInfo info{};bool allocated=heap->QueryRegionInfo(guest,&info);
        std::fprintf(stderr,"{\"event\":\"rejected-access-guest-page\",\"guest\":\"0x%x\",\"physical\":\"0x%x\",\"heap\":\"0x%x\",\"heap_type\":%u,\"heap_page_size\":%u,\"allocated\":%s,\"allocation\":\"0x%x\",\"allocation_size\":%u,\"state\":%u,\"protection\":%u}\n",
          guest,memory->GetPhysicalAddress(guest),heap->heap_base(),static_cast<unsigned>(heap->heap_type()),heap->page_size(),allocated?"true":"false",info.allocation_base,info.allocation_size,info.state,info.protect);
      }
    }
    if(auto* maps=std::fopen("/proc/self/maps","r")) {
      char line[512];unsigned long long low=0,high=0;
      while(std::fgets(line,sizeof(line),maps))if(std::sscanf(line,"%llx-%llx",&low,&high)==2&&target>=low&&target<high)std::fprintf(stderr,"cross-page-host-map: %s",line);
      std::fclose(maps);
    }
  }
  if(thread) {
    auto* context=thread->context();
    const PPCRegister* registers[]={&context->r0,&context->r1,&context->r2,&context->r3,
      &context->r4,&context->r5,&context->r6,&context->r7,&context->r8,&context->r9,
      &context->r10,&context->r11,&context->r12,&context->r13,&context->r14,&context->r15,
      &context->r16,&context->r17,&context->r18,&context->r19,&context->r20,&context->r21,
      &context->r22,&context->r23,&context->r24,&context->r25,&context->r26,&context->r27,
      &context->r28,&context->r29,&context->r30,&context->r31};
    for(unsigned i=0;i<32;++i)std::fprintf(stderr,"cross-page-gpr[%u]=0x%llx\n",i,static_cast<unsigned long long>(registers[i]->u64));
  }
  void* frames[32];int count=backtrace(frames,32);backtrace_symbols_fd(frames,count,2);
}
void ValidateRange(const void* pointer,size_t width,bool atomic=false,bool vector=false,bool write=false,
                   const HostPageBoundary* boundary=nullptr) noexcept {
  auto address=reinterpret_cast<uintptr_t>(pointer);
  if(width>std::numeric_limits<uintptr_t>::max()-address) FaultContractFailure("access-range-overflow");
  const auto page=boundary ? boundary->page : memory::page_size();
  const auto offset=boundary ? boundary->offset : HostPageOffset(address,page);
  if(width>page || offset>page-width) {
    DiagnoseCrossPage(pointer,width,atomic,vector,write);
    FaultContractFailure("unadmitted-cross-page-access");
  }
  if((atomic&&address%width)||(vector&&address%16)) FaultContractFailure("unadmitted-access-alignment");
}
void RejectMappedAtomic(const void* address,size_t width) noexcept {
  if(auto* handler=MMIO::global_handler();handler && handler->IsMappedRange(address,width))
    FaultContractFailure("unadmitted-mapped-atomic-access");
}
bool CompleteMappedRead(const void* address, void* output, size_t width, bool unsupported,
                        MMIO::DeferredTransaction& transaction) noexcept {
  auto* handler=MMIO::global_handler();uint32_t guest_address=0;
  if(!handler)return false;
  bool mapped=false;
  const bool overlaps=detail::MappedAccessClassifier::Classify(*handler,address,width,guest_address,mapped);
  if(overlaps && (unsupported || width!=4))FaultContractFailure("unadmitted-mapped-data-access");
  if(!mapped){
    if(overlaps)FaultContractFailure("unadmitted-partial-mapped-scalar-access");
    return false;
  }
  if(unsupported || width!=4)FaultContractFailure("unadmitted-mapped-data-access");
  CapturedFault operation{};operation.address=reinterpret_cast<uintptr_t>(address);
  AdjudicationScope guard(operation);uint32_t guest_value=0;
  try {
    if(!handler->CheckLoad(guest_address,&guest_value))FaultContractFailure("mapped-read-unclaimed");
    if(!transaction.CompleteExplicit())FaultContractFailure("duplicate-mapped-read-completion");
  } catch(...) {FaultContractFailure("exception-after-mapped-read-start");}
  const auto native_value=rex::byte_swap(guest_value);std::memcpy(output,&native_value,4);
  return true;
}
bool CompleteMappedWrite(void* address, const void* input, size_t width, bool unsupported,
                         MMIO::DeferredTransaction& transaction) noexcept {
  auto* handler=MMIO::global_handler();uint32_t guest_address=0;
  if(!handler)return false;
  bool mapped=false;
  const bool overlaps=detail::MappedAccessClassifier::Classify(*handler,address,width,guest_address,mapped);
  if(overlaps && (unsupported || width!=4))FaultContractFailure("unadmitted-mapped-data-access");
  if(!mapped){
    if(overlaps)FaultContractFailure("unadmitted-partial-mapped-scalar-access");
    return false;
  }
  if(unsupported || width!=4)FaultContractFailure("unadmitted-mapped-data-access");
  uint32_t native_value=0;std::memcpy(&native_value,input,4);
  CapturedFault operation{};operation.address=reinterpret_cast<uintptr_t>(address);operation.access_intent=1;
  AdjudicationScope guard(operation);
  try {
    if(!handler->CheckStore(guest_address,rex::byte_swap(native_value)))FaultContractFailure("mapped-write-unclaimed");
    if(!transaction.CompleteExplicit())FaultContractFailure("duplicate-mapped-write-completion");
  } catch(...) {FaultContractFailure("exception-after-mapped-write-start");}
  return true;
}
struct DeferredResult { MMIO::DeferredRecovery outcome; uint32_t value=0; };
thread_local memory::PageAccess repair_before = memory::PageAccess::kNoAccess;
thread_local bool repair_before_known = false;
DeferredResult Resolve(const CapturedFault& fault,MMIO::DeferredAccessKind kind,
                       MMIO::DeferredTransaction& transaction) noexcept {
  auto* handler=MMIO::global_handler();
  size_t before_length=memory::page_size();
  repair_before_known=memory::QueryProtect(reinterpret_cast<void*>(fault.address),before_length,repair_before);
  if(!handler)return {MMIO::DeferredRecovery::kGuestFault};
  AdjudicationScope adjudication(fault);
  arch::HostThreadContext context{};
  for(unsigned i=0;i<16;++i)context.int_registers[i]=fault.integer_registers[i];
  context.rip=fault.instruction_pointer;context.eflags=fault.flags;
  std::memcpy(context.xmm_registers,fault.xmm_registers,sizeof(fault.xmm_registers));
  arch::Exception exception;
  exception.InitializeAccessViolation(&context,fault.address,fault.access_intent?
      arch::Exception::AccessViolationOperation::kWrite:arch::Exception::AccessViolationOperation::kRead);
  try {
    auto outcome=handler->ResolveAccessFault(exception,kind,transaction);
    if(outcome==MMIO::DeferredRecovery::kUnsupported)
      FaultContractFailure("unsupported-or-indeterminate-deferred-operation");
    return {outcome,static_cast<uint32_t>(context.rdx)};
  } catch(...) { FaultContractFailure("exception-during-deferred-operation"); }
}
void PrepareRetry(const CapturedFault& fault,MMIO::DeferredTransaction& transaction) noexcept {
  memory::PageAccess access;size_t length=memory::page_size();
  const bool after_known=memory::QueryProtect(reinterpret_cast<void*>(fault.address),length,access);
  if(!after_known || access==memory::PageAccess::kNoAccess ||
     (fault.access_intent && access!=memory::PageAccess::kReadWrite && access!=memory::PageAccess::kExecuteReadWrite)) {
    // Bounded terminal diagnostics run after signal return, never in a handler.
    std::fprintf(stderr,"{\"event\":\"deferred-repair-failure-context\",\"tid\":%ld,\"address\":\"0x%llx\",\"page\":\"0x%llx\",\"host_pc\":\"0x%llx\",\"reg_err\":%llu,\"intent\":%u,\"before_known\":%s,\"before\":%u,\"after_known\":%s,\"after\":%u}\n",
      static_cast<long>(gettid()),static_cast<unsigned long long>(fault.address),
      static_cast<unsigned long long>(fault.address&~(memory::page_size()-1)),
      static_cast<unsigned long long>(fault.instruction_pointer),
      static_cast<unsigned long long>(fault.page_fault_error),fault.access_intent,
      repair_before_known?"true":"false",static_cast<unsigned>(repair_before),
      after_known?"true":"false",static_cast<unsigned>(access));
    if(auto* maps=std::fopen("/proc/self/maps","r")) {
      char line[512];unsigned long long low=0,high=0;
      while(std::fgets(line,sizeof(line),maps)) {
        if(std::sscanf(line,"%llx-%llx",&low,&high)==2 && fault.address>=low && fault.address<high)
          std::fprintf(stderr,"fault-host-map: %s",line);
      }
      std::fclose(maps);
    }
    void* frames[24];int count=backtrace(frames,24);backtrace_symbols_fd(frames,count,2);
    FaultContractFailure("deferred-repair-made-no-protection-progress");
  }
  if(!transaction.BeginRetry())FaultContractFailure("invalid-deferred-retry-state");
}
template<class T> AccessResult<T> Terminal(const CapturedFault& fault) noexcept {
  return AccessResult<T>::Failure(ExecutionActivation::Current()->Publish(fault));
}
}  // namespace
namespace detail {
void RequireFillRange(void* destination,size_t length) noexcept {
  RequireAccess();
  if(length>std::numeric_limits<uintptr_t>::max()-reinterpret_cast<uintptr_t>(destination))
    FaultContractFailure("bulk-range-overflow");
  if(auto* handler=MMIO::global_handler();handler && handler->IsMappedRange(destination,length))
    FaultContractFailure("unadmitted-mapped-bulk-access");
}
AccessResult<bool> TryReadBytes(const void* address,void* output,size_t width,bool vector,bool reservation) noexcept {
  RequireAccessState();
  const auto boundary = HostBoundaryFor(address,width);
  if((width==2 || width==4 || width==8) && !vector && !reservation &&
     width<=boundary.page && boundary.offset>boundary.page-width) {
    if(auto captured=CaptureCrossPageRamScalar(address,output,width,false,boundary)) {
      if(captured->success)return AccessResult<bool>::Success(true);
      return Terminal<bool>(captured->fault);
    }
  }
  ValidateRange(address,width,reservation,vector,false,&boundary);
  if(reservation)RejectMappedAtomic(address,width);
  auto transaction=detail::DeferredTransactionBridge::Create();
  if(CompleteMappedRead(address,output,width,vector||reservation,transaction))return AccessResult<bool>::Success(true);
  for(unsigned attempt=0;attempt<kRetryLimit;++attempt){
    ScalarCaptureFailure failure;
    bool success;
    if (vector || reservation) {
      const auto captured = vector ? CaptureVectorRead(address, output)
                                   : CaptureRead(address, output, width);
      success = captured.success;
      if (!success) failure = captured.fault;
    } else {
      success = CaptureReadCompact(address, output, width, failure);
    }
    if(success){if(!detail::DeferredTransactionBridge::CompleteNative(transaction))FaultContractFailure("duplicate-native-completion");return AccessResult<bool>::Success(true);}
    if (!failure) FaultContractFailure("missing-compact-capture-fault");
    const auto& fault = *failure;
    auto kind=reservation?MMIO::DeferredAccessKind::kAtomic:vector?MMIO::DeferredAccessKind::kVector128:
        width==4?MMIO::DeferredAccessKind::kScalar32:MMIO::DeferredAccessKind::kScalarRam;
    auto resolved=Resolve(fault,kind,transaction);
    if(resolved.outcome==MMIO::DeferredRecovery::kCompleted){
      if(width!=4||vector)FaultContractFailure("unsupported-synthetic-result-width");
      std::memcpy(output,&resolved.value,4);return AccessResult<bool>::Success(true);
    }
    if(resolved.outcome==MMIO::DeferredRecovery::kGuestFault)return Terminal<bool>(fault);
    PrepareRetry(fault,transaction);
  }
  FaultContractFailure("read-retry-budget-exhausted");
}
AccessResult<bool> TryWriteBytes(void* address,const void* value,size_t width,bool vector) noexcept {
  RequireAccessState();
  const auto boundary = HostBoundaryFor(address,width);
  if((width==2 || width==4 || width==8) && !vector &&
     width<=boundary.page && boundary.offset>boundary.page-width) {
    if(auto captured=CaptureCrossPageRamScalar(address,const_cast<void*>(value),width,true,boundary)) {
      if(captured->success)return AccessResult<bool>::Success(true);
      return Terminal<bool>(captured->fault);
    }
  }
  ValidateRange(address,width,false,vector,true,&boundary);auto transaction=detail::DeferredTransactionBridge::Create();
  if(CompleteMappedWrite(address,value,width,vector,transaction))return AccessResult<bool>::Success(true);
  for(unsigned attempt=0;attempt<kRetryLimit;++attempt){
    ScalarCaptureFailure failure;
    bool success;
    if (vector) {
      const auto captured = CaptureVectorWrite(address, value);
      success = captured.success;
      if (!success) failure = captured.fault;
    } else {
      success = CaptureWriteCompact(address, value, width, failure);
    }
    if(success){if(!detail::DeferredTransactionBridge::CompleteNative(transaction))FaultContractFailure("duplicate-native-completion");return AccessResult<bool>::Success(true);}
    if (!failure) FaultContractFailure("missing-compact-capture-fault");
    const auto& fault = *failure;
    auto kind=vector?MMIO::DeferredAccessKind::kVector128:
        width==4?MMIO::DeferredAccessKind::kScalar32:MMIO::DeferredAccessKind::kScalarRam;
    auto resolved=Resolve(fault,kind,transaction);
    if(resolved.outcome==MMIO::DeferredRecovery::kCompleted)return AccessResult<bool>::Success(true);
    if(resolved.outcome==MMIO::DeferredRecovery::kGuestFault)return Terminal<bool>(fault);
    PrepareRetry(fault,transaction);
  }
  FaultContractFailure("write-retry-budget-exhausted");
}
template<class T> AccessResult<T> CompareExchange(void* address,T expected,T desired) noexcept {
  RequireAccess();ValidateRange(address,sizeof(T),true,false,true);RejectMappedAtomic(address,sizeof(T));MMIO::DeferredTransaction transaction;
  for(unsigned attempt=0;attempt<kRetryLimit;++attempt){
    T previous{};
    AccessAttempt capture;
    if constexpr(sizeof(T)==4)capture=CaptureCompareExchange32(address,expected,desired,&previous);
    else capture=CaptureCompareExchange64(address,expected,desired,&previous);
    if(capture.success){if(!transaction.CompleteNative())FaultContractFailure("duplicate-atomic-completion");return AccessResult<T>::Success(previous);}
    auto resolved=Resolve(capture.fault,MMIO::DeferredAccessKind::kAtomic,transaction);
    if(resolved.outcome==MMIO::DeferredRecovery::kGuestFault)return Terminal<T>(capture.fault);
    if(resolved.outcome!=MMIO::DeferredRecovery::kRetry)FaultContractFailure("invalid-atomic-completion");
    PrepareRetry(capture.fault,transaction);
  }
  FaultContractFailure("atomic-retry-budget-exhausted");
}
AccessResult<uint32_t> TryCompareExchange32(void* address,uint32_t expected,uint32_t desired) noexcept {
  return CompareExchange(address,expected,desired);
}
AccessResult<uint64_t> TryCompareExchange64(void* address,uint64_t expected,uint64_t desired) noexcept {
  return CompareExchange(address,expected,desired);
}
AccessResult<bool> TryCopyBytes(void* destination,const void* source,size_t length,CopyEndpoints endpoints) noexcept {
  RequireAccess();if(!length)return AccessResult<bool>::Success(true);
  auto dst=reinterpret_cast<uintptr_t>(destination),src=reinterpret_cast<uintptr_t>(source);
  if(length>std::numeric_limits<uintptr_t>::max()-src || length>std::numeric_limits<uintptr_t>::max()-dst)
    FaultContractFailure("bulk-range-overflow");
  if(dst<src+length&&src<dst+length)FaultContractFailure("unadmitted-overlap-copy");
  if(auto* handler=MMIO::global_handler()){
    auto mask=static_cast<unsigned>(endpoints);
    if(((mask&1)&&handler->IsMappedRange(source,length)) ||
       ((mask&2)&&handler->IsMappedRange(destination,length)))
      FaultContractFailure("unadmitted-mapped-bulk-access");
  }
  size_t completed=0;unsigned consecutive_stalls=0;MMIO::DeferredTransaction transaction;
  while(consecutive_stalls<kRetryLimit){
    auto capture=CaptureCopy(static_cast<unsigned char*>(destination)+completed,
        static_cast<const unsigned char*>(source)+completed,length-completed,endpoints);
    if(capture.completed>length-completed)FaultContractFailure("invalid-bulk-progress");
    consecutive_stalls=capture.completed?0:consecutive_stalls+1;
    completed+=capture.completed;
    if(capture.success){if(!transaction.CompleteNative())FaultContractFailure("duplicate-bulk-completion");return AccessResult<bool>::Success(true);}
    auto resolved=Resolve(capture.fault,MMIO::DeferredAccessKind::kForwardBulk,transaction);
    if(resolved.outcome==MMIO::DeferredRecovery::kGuestFault)return Terminal<bool>(capture.fault);
    if(resolved.outcome!=MMIO::DeferredRecovery::kRetry)FaultContractFailure("invalid-bulk-completion");
    PrepareRetry(capture.fault,transaction);
  }
  FaultContractFailure("bulk-retry-budget-exhausted");
}
}  // namespace detail
uint32_t MmioRead32(uint8_t* base,uint32_t address) {
  detail::MemoryConsumer consumer;
  auto* handler=MMIO::global_handler();
  if(handler && handler->LookupRange(address)){
    CapturedFault operation{};operation.address=reinterpret_cast<uintptr_t>(base+address);
    MMIO::DeferredTransaction transaction;AdjudicationScope guard(operation);uint32_t value=0;
    try { if(handler->CheckLoad(address,&value)){if(!transaction.CompleteExplicit())FaultContractFailure("duplicate-mmio-read-completion");return value;} }
    catch(...) {FaultContractFailure("exception-after-mmio-read-start");}
    FaultContractFailure("mapped-mmio-read-unclaimed");
  }
  return rex::byte_swap(ValueOrThrow(TryRead<uint32_t>(base+address)));
}
void MmioWrite32(uint8_t* base,uint32_t address,uint32_t guest_value) {
  detail::MemoryConsumer consumer;
  auto* handler=MMIO::global_handler();
  if(handler && handler->LookupRange(address)){
    CapturedFault operation{};operation.address=reinterpret_cast<uintptr_t>(base+address);operation.access_intent=1;
    MMIO::DeferredTransaction transaction;AdjudicationScope guard(operation);
    try { if(handler->CheckStore(address,guest_value)){if(!transaction.CompleteExplicit())FaultContractFailure("duplicate-mmio-write-completion");return;} }
    catch(...) {FaultContractFailure("exception-after-mmio-write-start");}
    FaultContractFailure("mapped-mmio-write-unclaimed");
  }
  ValueOrThrow(TryWrite<uint32_t>(base+address,rex::byte_swap(guest_value)));
}
}  // namespace rex::guest
