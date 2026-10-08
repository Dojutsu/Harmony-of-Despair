#pragma once
#include <rex/system/mmio_handler.h>
#include <rex/platform/guest_fault_state.h>
#include <algorithm>
#include <bit>
#include <limits>
namespace rex::guest::detail {
// Runtime-private friend bridge; it exposes no dynamic entry or cached pointer.
struct MappedAccessClassifier {
  __attribute__((always_inline)) static inline bool Classify(const runtime::MMIOHandler& handler, const void* host_address,
                       size_t length, uint32_t& point_guest, bool& mapped) noexcept {
    uint32_t* point_guest_address=&point_guest; bool* point_mapped=&mapped;
  *point_mapped = false;
  if (!length) {
    *point_mapped = handler.IsMappedAddress(host_address, point_guest_address);
    return false;
  }
  const auto first = reinterpret_cast<uintptr_t>(host_address);
  if (length - 1 > std::numeric_limits<uintptr_t>::max() - first)
    rex::guest::FaultContractFailure("mapped-admission-range-overflow");
  const auto last = first + length - 1;
  const auto virtual_begin = reinterpret_cast<uintptr_t>(handler.virtual_membase_);
  const auto virtual_end = std::min(reinterpret_cast<uintptr_t>(handler.physical_membase_),
                                  reinterpret_cast<uintptr_t>(handler.memory_end_));
  if (virtual_end <= virtual_begin || last < virtual_begin || first >= virtual_end) return false;
  const auto clipped_first = std::max(first, virtual_begin);
  const auto clipped_last = std::min(last, virtual_end - 1);
  const bool point_inside = first >= virtual_begin && first < virtual_end;
  uint32_t guest_first, guest_last;
  try {
    guest_first = handler.host_to_guest_virtual_(handler.host_to_guest_virtual_context_,
                                         reinterpret_cast<const void*>(clipped_first));
  } catch (...) {
    rex::guest::FaultContractFailure(point_inside ? "exception-classifying-mmio-address"
                                                 : "exception-classifying-mmio-range");
  }
  try {
    guest_last = handler.host_to_guest_virtual_(handler.host_to_guest_virtual_context_,
                                        reinterpret_cast<const void*>(clipped_last));
  } catch (...) {
    rex::guest::FaultContractFailure("exception-classifying-mmio-range");
  }
  // This is the admitted runtime metadata translator, not an arbitrary foreign
  // callback. The current 4KiB Linux Memory mapping is affine; other views must
  // meet this explicit contiguous translation contract before bulk admission.
  if (guest_last < guest_first || uint64_t(guest_last) - guest_first != clipped_last - clipped_first)
    rex::guest::FaultContractFailure("nonlinear-mapped-admission-range");

  bool overlap = false;
  for (const auto& range : handler.mapped_ranges_) {
    // Preserve exact (address & mask) == range.address semantics. size is not a
    // matching bound in the existing MMIO API. A pattern with bits outside mask
    // cannot match, even if its declared size overlaps the guest interval.
    if (range.address & ~range.mask) continue;
    if ((guest_first & range.mask) == range.address) {
      if (point_inside) {
        *point_mapped = true;
        *point_guest_address = guest_first;
        return true;
      }
      overlap = true;
    }
    // A previous partial span match cannot stop point classification: a later
    // range may also map the first byte. Device callback ordering stays in the
    // unchanged CheckLoad/CheckStore methods.
    if (overlap) continue;
    // Above the highest differing endpoint bit, every address in the
    // contiguous interval has the same prefix. A conflicting fixed pattern
    // bit there proves no address can match; keep the general fallback below.
    if ((uint64_t((guest_first ^ range.address) & range.mask) >>
         std::bit_width(guest_first ^ guest_last)) != 0) continue;
    // Every next matching word differs first from guest_first at one zero bit
    // becoming one. Keep that higher prefix, choose the required lower fixed
    // bits and set all free lower bits to zero. At most 32 candidates suffice.
    for (unsigned bit = 0; bit != 32; ++bit) {
      const uint64_t pivot = uint64_t(1) << bit;
      if (uint64_t(guest_first) & pivot) continue;
      const uint64_t lower_mask = pivot - 1;
      const uint64_t upper_mask = UINT32_MAX & ~((pivot << 1) - 1);
      const uint32_t candidate = uint32_t((uint64_t(guest_first) & upper_mask) | pivot |
                                         (uint64_t(range.address) & lower_mask));
      if (candidate <= guest_last && (candidate & range.mask) == range.address) { overlap = true; break; }
    }
  }
  return overlap;

  }
};
} // namespace rex::guest::detail
