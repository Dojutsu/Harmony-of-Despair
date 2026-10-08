// Exercise the real shared guest timeout conversion, including hostile extremes.
#include <catch2/catch_test_macros.hpp>
#include <rex/system/xobject.h>
#include <cstdint>
#include <limits>
struct TimeoutProbe : rex::system::XObject {
  using XObject::TimeoutTicksToMs;
};
TEST_CASE("Guest relative timeout conversion cannot wrap or negate INT64_MIN", "[kernel][timeout-range]") {
  CHECK(TimeoutProbe::TimeoutTicksToMs(0) == 0);
  CHECK(TimeoutProbe::TimeoutTicksToMs(-1) == 0);
  CHECK(TimeoutProbe::TimeoutTicksToMs(-9999) == 0);
  CHECK(TimeoutProbe::TimeoutTicksToMs(-10000) == 1);
  CHECK(TimeoutProbe::TimeoutTicksToMs(-19999) == 1);
  CHECK(TimeoutProbe::TimeoutTicksToMs(-20000) == 2);
  constexpr uint64_t maximum = std::numeric_limits<uint32_t>::max();
  CHECK(TimeoutProbe::TimeoutTicksToMs(-int64_t((maximum-1)*10000)) == maximum-1);
  CHECK(TimeoutProbe::TimeoutTicksToMs(-int64_t(maximum*10000)) == maximum);
  CHECK(TimeoutProbe::TimeoutTicksToMs(-int64_t(maximum*10000+9999)) == maximum);
  CHECK(TimeoutProbe::TimeoutTicksToMs(-int64_t((maximum+1)*10000)) == maximum);
  CHECK(TimeoutProbe::TimeoutTicksToMs(-int64_t((maximum+12345)*10000)) == maximum);
  CHECK(TimeoutProbe::TimeoutTicksToMs(std::numeric_limits<int64_t>::min()+1) == maximum);
  CHECK(TimeoutProbe::TimeoutTicksToMs(std::numeric_limits<int64_t>::min()) == maximum);
}
