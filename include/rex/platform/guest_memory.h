// Admitted Linux guest memory operations. Windows code selects its existing path.
#pragma once
#include <cstring>
#include <optional>
#include <string>
#include <type_traits>
#include <rex/platform/guest_fault_state.h>

namespace rex::guest {
namespace detail {
AccessResult<bool> TryReadBytes(const void*, void*, size_t, bool vector = false, bool reservation = false) noexcept;
AccessResult<bool> TryWriteBytes(void*, const void*, size_t, bool vector = false) noexcept;
AccessResult<uint32_t> TryCompareExchange32(void*, uint32_t, uint32_t) noexcept;
AccessResult<uint64_t> TryCompareExchange64(void*, uint64_t, uint64_t) noexcept;
AccessResult<bool> TryCopyBytes(void*, const void*, size_t, CopyEndpoints = CopyEndpoints::kBoth) noexcept;
void RequireFillRange(void*,size_t) noexcept;

// Normal C++ consumers can establish a root when called directly by tests or
// authored C++ code. Nonthrowing/foreign callers must use explicit activation +
// Try APIs, and return failure to a designated consumer before another effect.
class MemoryConsumer {
 public:
  MemoryConsumer() {
    if (!CurrentForAccessOrNull()) { root_.emplace(); RequireAccess(); }
  }
 private:
  std::optional<ExecutionActivation> root_;
};
}  // namespace detail

template <class T> AccessResult<T> TryRead(const void* address) noexcept {
  static_assert(std::is_trivially_copyable_v<T> && (sizeof(T)==1 || sizeof(T)==2 || sizeof(T)==4 || sizeof(T)==8));
  T value{};
  auto read=detail::TryReadBytes(address,&value,sizeof(T));
  if(read.Failed()) return read.template Forward<T>();
  return AccessResult<T>::Success(value);
}
template <class T> AccessResult<bool> TryWrite(void* address,T value) noexcept {
  static_assert(std::is_trivially_copyable_v<T> && (sizeof(T)==1 || sizeof(T)==2 || sizeof(T)==4 || sizeof(T)==8));
  return detail::TryWriteBytes(address,&value,sizeof(T));
}
template <class T> T Read(const void* address) {
  detail::MemoryConsumer consumer;
  return ValueOrThrow(TryRead<T>(address));
}
template <class T> void Write(void* address,T value) {
  detail::MemoryConsumer consumer;
  ValueOrThrow(TryWrite<T>(address,value));
}
template <class T> T ReadVector(const void* address) {
  static_assert(sizeof(T)==16 && std::is_trivially_copyable_v<T>);
  detail::MemoryConsumer consumer; T value{};
  ValueOrThrow(detail::TryReadBytes(address,&value,16,true)); return value;
}
template <class T> void WriteVector(void* address,T value) {
  static_assert(sizeof(T)==16 && std::is_trivially_copyable_v<T>);
  detail::MemoryConsumer consumer; ValueOrThrow(detail::TryWriteBytes(address,&value,16,true));
}
inline uint32_t ReadReserved32(const void* address) {
  detail::MemoryConsumer consumer; uint32_t value{};
  ValueOrThrow(detail::TryReadBytes(address,&value,4,false,true)); return value;
}
inline uint64_t ReadReserved64(const void* address) {
  detail::MemoryConsumer consumer; uint64_t value{};
  ValueOrThrow(detail::TryReadBytes(address,&value,8,false,true)); return value;
}
inline uint32_t CompareExchange32(void* address,uint32_t expected,uint32_t desired) {
  detail::MemoryConsumer consumer; return ValueOrThrow(detail::TryCompareExchange32(address,expected,desired));
}
inline uint64_t CompareExchange64(void* address,uint64_t expected,uint64_t desired) {
  detail::MemoryConsumer consumer; return ValueOrThrow(detail::TryCompareExchange64(address,expected,desired));
}
inline void CopyBytes(void* destination,const void* source,size_t length) {
  detail::MemoryConsumer consumer; ValueOrThrow(detail::TryCopyBytes(destination,source,length));
}
inline void CopyToGuest(void* destination,const void* host_source,size_t length) {
  detail::MemoryConsumer consumer; ValueOrThrow(detail::TryCopyBytes(destination,host_source,length,CopyEndpoints::kDestination));
}
inline void CopyFromGuest(void* host_destination,const void* source,size_t length) {
  detail::MemoryConsumer consumer; ValueOrThrow(detail::TryCopyBytes(host_destination,source,length,CopyEndpoints::kSource));
}
inline void FillBytes(void* destination,unsigned char value,size_t length) {
  detail::MemoryConsumer consumer;
  detail::RequireFillRange(destination,length);
  unsigned char block[128]; std::memset(block,value,sizeof(block));
  auto* target=static_cast<unsigned char*>(destination);
  for(size_t completed=0;completed<length;) {
    size_t step=length-completed<sizeof(block)?length-completed:sizeof(block);
    ValueOrThrow(detail::TryCopyBytes(target+completed,block,step,CopyEndpoints::kDestination));completed+=step;
  }
}
inline std::string ReadString(const void* source,size_t length) {
  detail::MemoryConsumer consumer;std::string result(length,'\0');
  ValueOrThrow(detail::TryCopyBytes(result.data(),source,length,CopyEndpoints::kSource));return result;
}
uint32_t MmioRead32(uint8_t* base,uint32_t address);
void MmioWrite32(uint8_t* base,uint32_t address,uint32_t guest_value);
}  // namespace rex::guest
