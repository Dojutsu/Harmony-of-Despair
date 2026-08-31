/**
 * @file        codegen/dispatch_table_layout.cpp
 * @brief       Deterministic project-wide guest dispatch-table layout
 */

#include <rex/codegen/dispatch_table_layout.h>

#include <algorithm>
#include <limits>

#include <fmt/format.h>

namespace rex::codegen {

namespace {

constexpr uint64_t kAlignment = 0x10000;
constexpr uint64_t kThunkReserveSize = 0x10000;

uint64_t AlignUp(uint64_t value) {
  return (value + kAlignment - 1) & ~(kAlignment - 1);
}

bool Overlaps(uint64_t a_begin, uint64_t a_end, uint64_t b_begin, uint64_t b_end) {
  return a_begin < b_end && a_end > b_begin;
}

}  // namespace

DispatchTableLayoutResult BuildDispatchTableLayout(
    uint32_t region_base, const std::vector<DispatchTableLayoutInput>& inputs,
    uint32_t supported_base, uint64_t supported_end) {
  DispatchTableLayoutResult result;
  if (inputs.empty()) {
    result.error = "dispatch-table layout has no executable images";
    return result;
  }
  if ((region_base & (kAlignment - 1)) != 0) {
    result.error = fmt::format("dispatch-table region base 0x{:08X} is not 64-KiB aligned",
                               region_base);
    return result;
  }
  if (region_base < supported_base || uint64_t(region_base) >= supported_end) {
    result.error = fmt::format("dispatch-table region base 0x{:08X} is outside supported "
                               "guest range 0x{:08X}-0x{:08X}",
                               region_base, supported_base, supported_end);
    return result;
  }

  std::vector<std::pair<uint64_t, uint64_t>> images;
  images.reserve(inputs.size());
  uint64_t highest_image_end = 0;
  for (const auto& input : inputs) {
    if (!input.image_size || !input.code_size) {
      result.error = fmt::format("'{}' has an empty image or code range", input.name);
      return result;
    }
    uint64_t image_end = uint64_t(input.image_base) + input.image_size;
    uint64_t code_end = uint64_t(input.code_base) + input.code_size;
    if (image_end > std::numeric_limits<uint32_t>::max() ||
        code_end > std::numeric_limits<uint32_t>::max()) {
      result.error = fmt::format("'{}' image/code range wraps guest address space", input.name);
      return result;
    }
    images.emplace_back(input.image_base, image_end);
    highest_image_end = std::max(highest_image_end, image_end);
  }
  result.highest_image_end = highest_image_end;
  if (uint64_t(region_base) < highest_image_end) {
    result.error = fmt::format("dispatch-table region 0x{:08X} begins below highest image end "
                               "0x{:08X}",
                               region_base, highest_image_end);
    return result;
  }

  uint64_t cursor = region_base;
  for (const auto& input : inputs) {
    uint64_t logical_size = (uint64_t(input.code_size) + kThunkReserveSize) * 2;
    uint64_t allocation_size = AlignUp(logical_size);
    uint64_t table_end = cursor + allocation_size;
    if (table_end < cursor || table_end > supported_end || table_end > UINT32_MAX) {
      result.error = fmt::format("dispatch table for '{}' overflows supported guest range at "
                                 "0x{:08X}",
                                 input.name, cursor);
      return result;
    }
    for (const auto& [image_begin, image_end] : images) {
      if (Overlaps(cursor, table_end, image_begin, image_end)) {
        result.error = fmt::format("dispatch table for '{}' at 0x{:08X}-0x{:08X} overlaps "
                                   "guest image 0x{:08X}-0x{:08X}",
                                   input.name, cursor, table_end, image_begin, image_end);
        return result;
      }
    }
    for (const auto& existing : result.entries) {
      uint64_t existing_end = uint64_t(existing.table_base) + existing.allocation_size;
      if (Overlaps(cursor, table_end, existing.table_base, existing_end)) {
        result.error = fmt::format("dispatch tables '{}' and '{}' overlap", input.name,
                                   existing.name);
        return result;
      }
    }
    result.entries.push_back({input.name, static_cast<uint32_t>(cursor),
                              static_cast<uint32_t>(logical_size),
                              static_cast<uint32_t>(allocation_size)});
    cursor = table_end;
  }
  result.region_end = static_cast<uint32_t>(cursor);
  result.success = true;
  return result;
}

}  // namespace rex::codegen
