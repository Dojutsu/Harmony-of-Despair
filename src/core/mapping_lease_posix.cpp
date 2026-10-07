#include <rex/memory/mapping_lease.h>
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <map>
#include <vector>
namespace rex::memory {
namespace {
std::shared_mutex gate;
std::atomic<unsigned> waiters{0};
uint64_t mapping_generation=0;
std::atomic<uint64_t> identities{0};
struct View { uintptr_t low,high;uint64_t identity;size_t file_offset; };
std::vector<View> views;
std::map<int,uint64_t> handles;
uint64_t backing_identities=0;
thread_local unsigned writer_depth=0;
thread_local const MappingAccessLease* reader=nullptr;
[[noreturn]] void Failure(const char* reason) {
  std::fprintf(stderr,"{\"event\":\"memory-lease-contract-failure\",\"reason\":\"%s\"}\n",reason);
  std::_Exit(86);
}
}
MappingMutationScope::MappingMutationScope():global_lock_(rex::thread::global_critical_region::mutex(),std::defer_lock),lock_(gate,std::defer_lock),
 level_(writer_depth),owner_(std::this_thread::get_id()) {
  if(reader)Failure("mutation-during-access-lease");
  if(writer_depth==std::numeric_limits<unsigned>::max())Failure("mutation-depth-overflow");
  if(!writer_depth){waiters.fetch_add(1);global_lock_.lock();lock_.lock();waiters.fetch_sub(1);} else {global_lock_.lock();}
  ++writer_depth;
}
MappingMutationScope::~MappingMutationScope() {
  if(owner_!=std::this_thread::get_id() || writer_depth!=level_+1)Failure("mutation-owner-or-order");
  --writer_depth;
  if(!writer_depth){if(mapping_generation==UINT64_MAX)Failure("mapping-generation-overflow");++mapping_generation;}
}
MappingAccessLease::MappingAccessLease():global_lock_(rex::thread::global_critical_region::AcquireDirect()),lock_(gate,std::defer_lock),owner_(std::this_thread::get_id()) {
  if(reader || writer_depth)Failure("nested-or-mutating-access-lease");
  lock_.lock();generation_=mapping_generation;identity_=identities.fetch_add(1)+1;
  if(!identity_)Failure("lease-identity-overflow");
  active_=true;reader=this;
}
void MappingAccessLease::Release() {
  if(!active_ || owner_!=std::this_thread::get_id() || reader!=this)Failure("duplicate-or-foreign-lease-release");
  reader=nullptr;active_=false;lock_.unlock();global_lock_.unlock();
}
MappingAccessLease::~MappingAccessLease(){if(active_)Release();}
void GuestMemoryAccessControl::CloseAndDrain() {
  std::unique_lock lock(mutex_);
  retiring_=true;
  changed_.wait(lock,[this]{return pins_==0;});
  memory_=nullptr;
}
GuestMemoryAccessPin::GuestMemoryAccessPin(const std::shared_ptr<GuestMemoryAccessControl>& control):control_(control) {
  if(!control_)return;
  std::lock_guard lock(control_->mutex_);
  if(control_->retiring_ || !control_->memory_)return;
  if(control_->pins_==std::numeric_limits<unsigned>::max())Failure("memory-owner-pin-overflow");
  ++control_->pins_;memory_=control_->memory_;
}
GuestMemoryAccessPin::~GuestMemoryAccessPin() {
  if(!memory_)return;
  std::lock_guard lock(control_->mutex_);
  if(!control_->pins_)Failure("memory-owner-pin-underflow");
  --control_->pins_;
  if(!control_->pins_)control_->changed_.notify_all();
}
uint64_t MappingHandleIdentity(int handle) {
  if(!writer_depth)Failure("backing-identity-without-mutation");
  auto found=handles.find(handle);if(found!=handles.end())return found->second;
  if(backing_identities==UINT64_MAX)Failure("backing-identity-overflow");
  return handles.emplace(handle,++backing_identities).first->second;
}
void ForgetMappingHandle(int handle) {
  if(!writer_depth)Failure("backing-close-without-mutation");
  handles.erase(handle);
}
void ForgetMappingViews(void* base,size_t length) {
  if(!writer_depth)Failure("view-change-without-mutation");
  const auto low=reinterpret_cast<uintptr_t>(base);
  if(length>UINTPTR_MAX-low)Failure("view-range-overflow");
  const auto high=low+length;
  for(size_t i=0;i<views.size();) {
    auto view=views[i];
    if(view.high<=low || view.low>=high){++i;continue;}
    views.erase(views.begin()+i);
    if(view.low<low)views.push_back({view.low,low,view.identity,view.file_offset});
    if(view.high>high)views.push_back({high,view.high,view.identity,view.file_offset+high-view.low});
  }
}
void RecordMappingView(void* base,size_t length,uint64_t identity,size_t file_offset) {
  ForgetMappingViews(base,length);
  auto low=reinterpret_cast<uintptr_t>(base);
  views.push_back({low,low+length,identity,file_offset});
}
bool MappingViewMatches(const void* base,size_t length,uint64_t identity,size_t file_offset) {
  if(!reader)Failure("view-query-without-access-lease");
  const auto low=reinterpret_cast<uintptr_t>(base);
  if(!identity || length>UINTPTR_MAX-low)return false;
  for(const auto& view:views)if(low>=view.low && low+length<=view.high)
    return view.identity==identity && view.file_offset+low-view.low==file_offset;
  return false;
}
unsigned MappingMutationWaiters(){return waiters.load();}
bool HasMappingAccessLease(){return reader!=nullptr;}
}
