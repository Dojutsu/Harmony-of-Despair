// Linux cooperative host-mapping stability. Never acquire these guards in a
// signal handler. In-page guest access does not acquire this gate.
#pragma once
#include <rex/platform.h>
#if REX_PLATFORM_GNU_LINUX
#include <cstdint>
#include <condition_variable>
#include <memory>
#include <shared_mutex>
#include <thread>
#include <rex/thread/mutex.h>
namespace rex::memory {
class MappingAccessLease;
class MappingMutationScope {
 public:
  MappingMutationScope();
  ~MappingMutationScope();
  MappingMutationScope(const MappingMutationScope&)=delete;
  MappingMutationScope& operator=(const MappingMutationScope&)=delete;
 private:
  std::unique_lock<std::recursive_mutex> global_lock_;
  std::unique_lock<std::shared_mutex> lock_;
  unsigned level_;
  std::thread::id owner_;
};
class MappingAccessLease {
 public:
  MappingAccessLease();
  ~MappingAccessLease();
  MappingAccessLease(const MappingAccessLease&)=delete;
  MappingAccessLease& operator=(const MappingAccessLease&)=delete;
  void Release();
  uint64_t identity() const { return identity_; }
  uint64_t generation() const { return generation_; }
 private:
  std::unique_lock<std::recursive_mutex> global_lock_;
  std::shared_lock<std::shared_mutex> lock_;
  std::thread::id owner_;
  uint64_t identity_=0,generation_=0;
  bool active_=false;
};
// Separate ownership survives Memory and ThreadState teardown. A binding is
// copied while Memory is live; an operation pins it before dereferencing Memory.
// Retirement closes admission and drains pins without any global/mapping lock.
class Memory;
class GuestMemoryAccessControl {
 public:
  explicit GuestMemoryAccessControl(Memory* memory) : memory_(memory) {}
  void CloseAndDrain();
 private:
  friend class GuestMemoryAccessPin;
  std::mutex mutex_;
  std::condition_variable changed_;
  Memory* memory_;
  unsigned pins_ = 0;
  bool retiring_ = false;
};
class GuestMemoryAccessPin {
 public:
  explicit GuestMemoryAccessPin(const std::shared_ptr<GuestMemoryAccessControl>& control);
  ~GuestMemoryAccessPin();
  GuestMemoryAccessPin(const GuestMemoryAccessPin&) = delete;
  GuestMemoryAccessPin& operator=(const GuestMemoryAccessPin&) = delete;
  Memory* memory() const { return memory_; }
 private:
  std::shared_ptr<GuestMemoryAccessControl> control_;
  Memory* memory_ = nullptr;
};
// Cooperative backing identities survive file descriptor reuse. Mutators call
// these under their mapping guard; readers query only while holding a lease.
uint64_t MappingHandleIdentity(int handle);
void ForgetMappingHandle(int handle);
void RecordMappingView(void* base,size_t length,uint64_t identity,size_t file_offset);
void ForgetMappingViews(void* base,size_t length);
bool MappingViewMatches(const void* base,size_t length,uint64_t identity,size_t file_offset);
unsigned MappingMutationWaiters();
bool HasMappingAccessLease();
} // namespace rex::memory
// All mutators acquire global before mapping gate before heap mutex.
// The global guard prevents guest suspension while a mapping guard is held.
#define REX_MAPPING_OWNER_MUTATION() \
  rex::memory::MappingMutationScope rex_mapping_mutation_guard
// Platform VM leaves use the same order; nested mutation retains the original
// global guard and does not reacquire the nonrecursive mapping gate.
#define REX_MAPPING_MUTATION() rex::memory::MappingMutationScope rex_mapping_mutation_guard
#else
#define REX_MAPPING_OWNER_MUTATION()
#define REX_MAPPING_MUTATION()
#endif
