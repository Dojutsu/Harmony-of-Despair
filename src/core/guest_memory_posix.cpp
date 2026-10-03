#include <rex/platform/guest_memory.h>
#include <rex/exception_handler.h>
#include <rex/memory/utils.h>
#include <rex/system/mmio_handler.h>
#include <rex/types.h>

#include <cstring>
#include <limits>

namespace rex::guest {
namespace {
using MMIO = runtime::MMIOHandler;
constexpr unsigned kRetryLimit = 8;
void ValidateRange(const void* pointer,size_t width,bool atomic=false,bool vector=false) noexcept {
  auto address=reinterpret_cast<uintptr_t>(pointer);
  if(width>std::numeric_limits<uintptr_t>::max()-address) FaultContractFailure("access-range-overflow");
  auto page=memory::page_size();
  if(width>page || address%page>page-width) FaultContractFailure("unadmitted-cross-page-access");
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
  const bool mapped=handler->IsMappedAddress(address,&guest_address);
  const bool overlaps=handler->IsMappedRange(address,width);
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
  const bool mapped=handler->IsMappedAddress(address,&guest_address);
  const bool overlaps=handler->IsMappedRange(address,width);
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
DeferredResult Resolve(const CapturedFault& fault,MMIO::DeferredAccessKind kind,
                       MMIO::DeferredTransaction& transaction) noexcept {
  auto* handler=MMIO::global_handler();
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
  if(!memory::QueryProtect(reinterpret_cast<void*>(fault.address),length,access) ||
     access==memory::PageAccess::kNoAccess ||
     (fault.access_intent && access!=memory::PageAccess::kReadWrite && access!=memory::PageAccess::kExecuteReadWrite))
    FaultContractFailure("deferred-repair-made-no-protection-progress");
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
  RequireAccess();ValidateRange(address,width,reservation,vector);
  if(reservation)RejectMappedAtomic(address,width);
  MMIO::DeferredTransaction transaction;
  if(CompleteMappedRead(address,output,width,vector||reservation,transaction))return AccessResult<bool>::Success(true);
  for(unsigned attempt=0;attempt<kRetryLimit;++attempt){
    auto captured=vector?CaptureVectorRead(address,output):CaptureRead(address,output,width);
    if(captured.success){if(!transaction.CompleteNative())FaultContractFailure("duplicate-native-completion");return AccessResult<bool>::Success(true);}
    auto kind=reservation?MMIO::DeferredAccessKind::kAtomic:vector?MMIO::DeferredAccessKind::kVector128:
        width==4?MMIO::DeferredAccessKind::kScalar32:MMIO::DeferredAccessKind::kScalarRam;
    auto resolved=Resolve(captured.fault,kind,transaction);
    if(resolved.outcome==MMIO::DeferredRecovery::kCompleted){
      if(width!=4||vector)FaultContractFailure("unsupported-synthetic-result-width");
      std::memcpy(output,&resolved.value,4);return AccessResult<bool>::Success(true);
    }
    if(resolved.outcome==MMIO::DeferredRecovery::kGuestFault)return Terminal<bool>(captured.fault);
    PrepareRetry(captured.fault,transaction);
  }
  FaultContractFailure("read-retry-budget-exhausted");
}
AccessResult<bool> TryWriteBytes(void* address,const void* value,size_t width,bool vector) noexcept {
  RequireAccess();ValidateRange(address,width,false,vector);MMIO::DeferredTransaction transaction;
  if(CompleteMappedWrite(address,value,width,vector,transaction))return AccessResult<bool>::Success(true);
  for(unsigned attempt=0;attempt<kRetryLimit;++attempt){
    auto captured=vector?CaptureVectorWrite(address,value):CaptureWrite(address,value,width);
    if(captured.success){if(!transaction.CompleteNative())FaultContractFailure("duplicate-native-completion");return AccessResult<bool>::Success(true);}
    auto kind=vector?MMIO::DeferredAccessKind::kVector128:
        width==4?MMIO::DeferredAccessKind::kScalar32:MMIO::DeferredAccessKind::kScalarRam;
    auto resolved=Resolve(captured.fault,kind,transaction);
    if(resolved.outcome==MMIO::DeferredRecovery::kCompleted)return AccessResult<bool>::Success(true);
    if(resolved.outcome==MMIO::DeferredRecovery::kGuestFault)return Terminal<bool>(captured.fault);
    PrepareRetry(captured.fault,transaction);
  }
  FaultContractFailure("write-retry-budget-exhausted");
}
template<class T> AccessResult<T> CompareExchange(void* address,T expected,T desired) noexcept {
  RequireAccess();ValidateRange(address,sizeof(T),true);RejectMappedAtomic(address,sizeof(T));MMIO::DeferredTransaction transaction;
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
