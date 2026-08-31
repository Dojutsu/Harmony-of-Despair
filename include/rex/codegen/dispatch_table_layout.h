/**
 * @file        rex/codegen/dispatch_table_layout.h
 * @brief       Deterministic project-wide guest dispatch-table layout
 */
#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace rex::codegen {

struct DispatchTableLayoutInput {
  std::string name;
  uint32_t image_base;
  uint32_t image_size;
  uint32_t code_base;
  uint32_t code_size;
};

struct DispatchTableLayoutEntry {
  std::string name;
  uint32_t table_base;
  uint32_t table_size;
  uint32_t allocation_size;
};

struct DispatchTableLayoutResult {
  bool success = false;
  std::string error;
  uint64_t highest_image_end = 0;
  uint32_t region_end = 0;
  std::vector<DispatchTableLayoutEntry> entries;
};

DispatchTableLayoutResult BuildDispatchTableLayout(
    uint32_t region_base, const std::vector<DispatchTableLayoutInput>& inputs,
    uint32_t supported_base = 0x80000000u, uint64_t supported_end = 0x90000000ull);

}  // namespace rex::codegen
