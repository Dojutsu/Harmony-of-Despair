#include <catch2/catch_test_macros.hpp>

#include <rex/codegen/dispatch_table_layout.h>

using rex::codegen::BuildDispatchTableLayout;
using rex::codegen::DispatchTableLayoutInput;

TEST_CASE("Dispatch tables are deterministic aligned and disjoint", "[codegen][layout]") {
  std::vector<DispatchTableLayoutInput> inputs = {
      {"default", 0x82000000, 0x00980000, 0x82220000, 0x006AC8C8},
      {"module", 0x83C80000, 0x00080000, 0x83C90000, 0x00014BF8},
  };
  auto layout = BuildDispatchTableLayout(0x89400000, inputs);
  REQUIRE(layout.success);
  REQUIRE(layout.entries.size() == 2);
  CHECK(layout.entries[0].table_base == 0x89400000);
  CHECK((layout.entries[1].table_base & 0xFFFF) == 0);
  CHECK(layout.entries[0].table_base + layout.entries[0].allocation_size <=
        layout.entries[1].table_base);
  CHECK(layout.highest_image_end == 0x83D00000);
}

TEST_CASE("Dispatch layout rejects image overlap alignment and overflow", "[codegen][layout]") {
  std::vector<DispatchTableLayoutInput> inputs = {
      {"module", 0x83C80000, 0x00080000, 0x83C90000, 0x00014BF8},
  };
  CHECK_FALSE(BuildDispatchTableLayout(0x83C90000, inputs).success);
  CHECK_FALSE(BuildDispatchTableLayout(0x89400001, inputs).success);
  CHECK_FALSE(BuildDispatchTableLayout(0x8FFF0000, inputs).success);
}
