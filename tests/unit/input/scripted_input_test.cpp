#include <catch2/catch_test_macros.hpp>
#include <rex/input/scripted/timeline.h>

TEST_CASE("offline input timeline preserves press release and analog bounds", "[input][scripted]") {
  rex::input::scripted::Timeline timeline;
  std::string error;
  REQUIRE(timeline.Parse("# test\n100 16 0 255 -32768 32767 0 0\n300 0 0 0 0 0 0 0\n", error));
  uint32_t packet = 99;
  CHECK(timeline.Sample(99, &packet).buttons == 0);
  CHECK(packet == 0);
  auto press = timeline.Sample(100, &packet);
  CHECK(packet == 1);
  CHECK(press.buttons == 16);
  CHECK(press.right_trigger == 255);
  CHECK(press.left_x == -32768);
  CHECK(press.left_y == 32767);
  CHECK(timeline.Sample(299).buttons == 16);
  CHECK(timeline.Sample(300, &packet).buttons == 0);
  CHECK(packet == 2);
  CHECK(timeline.Sample(UINT64_MAX).buttons == 0);
}

TEST_CASE("offline input parser rejects malformed and unbounded schedules transactionally", "[input][scripted]") {
  rex::input::scripted::Timeline timeline;
  std::string error;
  REQUIRE(timeline.Parse("0 4096 0 0 0 0 0 0", error));
  for (const auto* invalid : {"", "# empty", "0 1 0 0 0 0 0", "0 1 0 0 0 0 0 0 extra",
       "-1 0 0 0 0 0 0 0", "3600001 0 0 0 0 0 0 0", "0 65536 0 0 0 0 0 0",
       "0 0 256 0 0 0 0 0", "0 0 0 -1 0 0 0 0", "0 0 0 0 32768 0 0 0",
       "0 0 0 0 0 -32769 0 0", "1 0 0 0 0 0 0 0\n1 0 0 0 0 0 0 0",
       "2 0 0 0 0 0 0 0\n1 0 0 0 0 0 0 0", "0x10 0 0 0 0 0 0 0",
       "99999999999999999999999999 0 0 0 0 0 0 0"}) {
    CHECK_FALSE(timeline.Parse(invalid, error));
    CHECK_FALSE(error.empty());
    CHECK(timeline.Sample(1000).buttons == 4096);
  }
  CHECK_FALSE(timeline.Parse(std::string(timeline.kMaximumBytes + 1, ' '), error));
  std::string too_many;
  for (size_t i = 0; i <= timeline.kMaximumFrames; ++i)
    too_many += std::to_string(i) + " 0 0 0 0 0 0 0\n";
  CHECK_FALSE(timeline.Parse(too_many, error));
}
