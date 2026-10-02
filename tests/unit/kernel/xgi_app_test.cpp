#include <algorithm>
#include <array>

#include <catch2/catch_test_macros.hpp>

#include <rex/kernel/xam/apps/xgi_app.h>

namespace rex::kernel::xam::apps {

TEST_CASE("XUserReadStats initializes a valid empty result", "[xam][xgi][stats]") {
  std::array<uint8_t, 76> results;
  results.fill(0xA5);

  REQUIRE(InitializeEmptyStatsReadResults(results));
  CHECK(results[0] == 0);
  CHECK(results[4] == 0);
  CHECK(std::all_of(results.begin(), results.end(), [](uint8_t value) { return value == 0; }));
}

TEST_CASE("XUserReadStats rejects an undersized result header", "[xam][xgi][stats]") {
  std::array<uint8_t, 7> results;
  results.fill(0xA5);

  CHECK_FALSE(InitializeEmptyStatsReadResults(results));
  CHECK(std::all_of(results.begin(), results.end(), [](uint8_t value) { return value == 0xA5; }));
}

}  // namespace rex::kernel::xam::apps
