#include <rex/system/xam/session_arbitration_guest.h>
#include <rex/memory.h>
#include <rex/memory/mapping_lease.h>
#include <algorithm>
#include <cstring>
#include <unordered_set>
namespace rex::system::xam {
namespace {
bool OrdinaryRange(memory::Memory* memory, uint32_t address, uint32_t length, bool writable) {
  if (!memory || !address || !length || uint64_t{address} + length > (uint64_t{1} << 32))
    return false;
  const auto last = uint32_t(uint64_t{address} + length - 1);
  auto* heap = memory->LookupHeap(address);
  if (!heap || heap != memory->LookupHeap(last) || heap->heap_type() != memory::HeapType::kGuestVirtual)
    return false;
  const auto access = heap->QueryRangeAccess(address, last);
  if (access == memory::PageAccess::kNoAccess ||
      (writable && access != memory::PageAccess::kReadWrite &&
       access != memory::PageAccess::kExecuteReadWrite)) return false;
  uint64_t cursor = address - (address - heap->heap_base()) % heap->page_size();
  const uint64_t end = uint64_t{address} + length;
  while (cursor < end) {
    memory::HeapAllocationInfo info{};
    if (!heap->QueryRegionInfo(uint32_t(cursor), &info) || !info.region_size ||
        !(info.state & memory::kMemoryAllocationCommit)) return false;
    const uint64_t next = uint64_t{info.base_address} + info.region_size;
    if (next <= cursor) return false;
    cursor = next;
  }
#if REX_PLATFORM_GNU_LINUX
  return memory->MatchesGuestBacking(memory->TranslateVirtual(address), address, length);
#else
  return true;
#endif
}
uint64_t ReadBe(std::span<const uint8_t> bytes, size_t offset, size_t width) {
  uint64_t value = 0;
  for (size_t i = 0; i < width; ++i) value = (value << 8) | bytes[offset + i];
  return value;
}
void WriteBe(std::span<uint8_t> bytes, size_t offset, uint64_t value, size_t width) {
  for (size_t i = 0; i < width; ++i) {
    bytes[offset + width - i - 1] = uint8_t(value); value >>= 8;
  }
}
} // namespace
bool CopyArbitrationGuestInput(memory::Memory* memory, uint32_t address, std::span<uint8_t> output) {
  if (output.empty() || output.size() > UINT32_MAX) return false;
#if REX_PLATFORM_GNU_LINUX
  memory::MappingAccessLease lease;
#endif
  if (!OrdinaryRange(memory, address, uint32_t(output.size()), false)) return false;
  std::memcpy(output.data(), memory->TranslateVirtual(address), output.size());
  return true;
}
bool CopyArbitrationGuestOutput(memory::Memory* memory, uint32_t address, std::span<const uint8_t> input) {
  if (input.empty() || input.size() > UINT32_MAX) return false;
#if REX_PLATFORM_GNU_LINUX
  memory::MappingAccessLease lease;
#endif
  if (!OrdinaryRange(memory, address, uint32_t(input.size()), true)) return false;
  std::memcpy(memory->TranslateVirtual(address), input.data(), input.size());
  return true;
}
std::optional<GuestArbitrationRequest> ReadArbitrationGuestRequest(
    memory::Memory* memory, uint32_t address, uint32_t length) {
  if (length != 28 && length != 32) return std::nullopt;
#if REX_PLATFORM_GNU_LINUX
  memory::MappingAccessLease lease;
#endif
  if (!OrdinaryRange(memory, address, length, false)) return std::nullopt;
  std::array<uint8_t, 28> bytes{};
  // TU2 leaves the final stack word unwritten; validate but never interpret it.
  std::memcpy(bytes.data(), memory->TranslateVirtual(address), bytes.size());
  return GuestArbitrationRequest{uint32_t(ReadBe(bytes,0,4)), uint32_t(ReadBe(bytes,4,4)),
      ReadBe(bytes,8,8), uint32_t(ReadBe(bytes,16,4)), uint32_t(ReadBe(bytes,20,4)),
      uint32_t(ReadBe(bytes,24,4))};
}
bool PreflightArbitrationGuestOutput(memory::Memory* memory, uint32_t address, uint32_t capacity) {
  if (capacity < kArbitrationGuestPreflightSize ||
      uint64_t{address} + capacity > (uint64_t{1} << 32)) return false;
#if REX_PLATFORM_GNU_LINUX
  memory::MappingAccessLease lease;
#endif
  return OrdinaryRange(memory,address,kArbitrationGuestPreflightSize,true);
}
std::optional<std::vector<uint8_t>> SerializeArbitrationGuestResults(
    const ArbitrationSnapshot& snapshot, uint32_t guest_address) {
  if (snapshot.registrants.empty() || snapshot.registrants.size() > SessionArbitrationAuthority::kMaxMembers)
    return std::nullopt;
  uint32_t size = kArbitrationGuestHeaderSize +
      kArbitrationGuestRegistrantSize * uint32_t(snapshot.registrants.size());
  std::unordered_set<uint64_t> users, machines;
  for (const auto& registrant : snapshot.registrants) {
    if (!registrant.machine_id || registrant.trustworthiness != 0 || registrant.xuids.size() != 1 ||
        !machines.insert(registrant.machine_id).second) return std::nullopt;
    for (auto xuid : registrant.xuids)
      if (!xuid || !users.insert(xuid).second) return std::nullopt;
    size += 8;
  }
  if (!guest_address || uint64_t{guest_address} + size > (uint64_t{1} << 32)) return std::nullopt;
  std::vector<uint8_t> result(size,0);
  WriteBe(result,0,snapshot.registrants.size(),4);
  WriteBe(result,4,guest_address + kArbitrationGuestHeaderSize,4);
  uint32_t offset = kArbitrationGuestHeaderSize +
      kArbitrationGuestRegistrantSize * uint32_t(snapshot.registrants.size());
  for (size_t i = 0; i < snapshot.registrants.size(); ++i) {
    const auto& registrant = snapshot.registrants[i];
    const size_t record = kArbitrationGuestHeaderSize + kArbitrationGuestRegistrantSize * i;
    WriteBe(result,record,registrant.machine_id,8);
    WriteBe(result,record+8,registrant.trustworthiness,4);
    WriteBe(result,record+12,registrant.xuids.size(),4);
    WriteBe(result,record+16,guest_address+offset,4);
    WriteBe(result,offset,registrant.xuids[0],8); offset+=8;
  }
  return result;
}
} // namespace rex::system::xam
