// Lazy normal consumers for explicitly qualified generated Linux functions.
// The scope is local to one function/thread. Every operation retains the checked
// Try backend and ValueOrThrow; nonthrowing/foreign callers keep using explicit
// activations and the existing Try APIs. Native nonlocal jumps are unsupported.
#pragma once
#include <rex/platform/guest_memory.h>
namespace rex::guest::detail {
class FunctionMemoryConsumer {
 public:
  FunctionMemoryConsumer() = default;
  FunctionMemoryConsumer(const FunctionMemoryConsumer&) = delete;
  FunctionMemoryConsumer& operator=(const FunctionMemoryConsumer&) = delete;
  void Ensure() { if (!consumer_) consumer_.emplace(); }
  template<class T> T Read(const void* address) {
    Ensure(); return ValueOrThrow(TryRead<T>(address));
  }
  template<class T> void Write(void* address, T value) {
    Ensure(); ValueOrThrow(TryWrite<T>(address,value));
  }
  template<class T> T ReadVector(const void* address) {
    static_assert(sizeof(T)==16 && std::is_trivially_copyable_v<T>);
    Ensure(); T value{};
    ValueOrThrow(detail::TryReadBytes(address,&value,16,true)); return value;
  }
  template<class T> void WriteVector(void* address,T value) {
    static_assert(sizeof(T)==16 && std::is_trivially_copyable_v<T>);
    Ensure(); ValueOrThrow(detail::TryWriteBytes(address,&value,16,true));
  }
  uint32_t ReadReserved32(const void* address) {
    Ensure(); uint32_t value{};
    ValueOrThrow(detail::TryReadBytes(address,&value,4,false,true)); return value;
  }
  uint64_t ReadReserved64(const void* address) {
    Ensure(); uint64_t value{};
    ValueOrThrow(detail::TryReadBytes(address,&value,8,false,true)); return value;
  }
  uint32_t CompareExchange32(void* address,uint32_t expected,uint32_t desired) {
    Ensure(); return ValueOrThrow(detail::TryCompareExchange32(address,expected,desired));
  }
  uint64_t CompareExchange64(void* address,uint64_t expected,uint64_t desired) {
    Ensure(); return ValueOrThrow(detail::TryCompareExchange64(address,expected,desired));
  }
  void FillBytes(void* destination,unsigned char value,size_t length) {
    Ensure(); detail::RequireFillRange(destination,length);
    unsigned char block[128]; std::memset(block,value,sizeof(block));
    auto* target=static_cast<unsigned char*>(destination);
    for(size_t completed=0;completed<length;) {
      size_t step=length-completed<sizeof(block)?length-completed:sizeof(block);
      ValueOrThrow(detail::TryCopyBytes(target+completed,block,step,CopyEndpoints::kDestination)); completed+=step;
    }
  }
  std::string ReadString(const void* source,size_t length) {
    Ensure(); std::string result(length,'\0');
    ValueOrThrow(detail::TryCopyBytes(result.data(),source,length,CopyEndpoints::kSource)); return result;
  }
  uint32_t MmioRead32(uint8_t* base,uint32_t address) {
    Ensure(); return rex::guest::MmioRead32(base,address);
  }
  void MmioWrite32(uint8_t* base,uint32_t address,uint32_t value) {
    Ensure(); rex::guest::MmioWrite32(base,address,value);
  }
 private:
  // An unengaged optional initializes its flag, never the captured-fault payload.
  // A root is created only on the first memory operation and only if needed.
  std::optional<detail::MemoryConsumer> consumer_;
};
} // namespace rex::guest::detail
