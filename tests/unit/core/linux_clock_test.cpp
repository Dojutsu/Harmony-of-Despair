/**
 * Linux clock units and guest scaling, with bounded syscall interposition.
 * The default mode delegates to the kernel; only this process's explicitly
 * selected CLOCK_MONOTONIC_RAW observations are replaced during deterministic
 * cases. No Runtime or network service is initialized.
 */
#include <rex/chrono/clock.h>

#include <atomic>
#include <cerrno>
#include <cstdint>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string_view>
#include <sys/syscall.h>
#include <time.h>
#include <unistd.h>

namespace {
using rex::chrono::Clock;
constexpr uint64_t kNanosecondsPerSecond = 1000000000ull;
std::atomic<bool> fake_raw{false};
std::atomic<uint64_t> fake_ticks{0};
std::atomic<long> fake_resolution{1};
unsigned checks = 0;

void Check(bool condition, const char* message) {
  ++checks;
  if (!condition) throw std::runtime_error(message);
}
uint64_t KernelRawTicks() {
  timespec value{};
  Check(::syscall(SYS_clock_gettime, CLOCK_MONOTONIC_RAW, &value) == 0,
        "kernel raw clock available");
  return static_cast<uint64_t>(value.tv_sec) * kNanosecondsPerSecond +
         static_cast<uint64_t>(value.tv_nsec);
}
void Fake(uint64_t ticks, long resolution = 1) {
  fake_ticks.store(ticks, std::memory_order_relaxed);
  fake_resolution.store(resolution, std::memory_order_relaxed);
  fake_raw.store(true, std::memory_order_release);
}
void Units() {
  for (const long resolution : {1l, 10l, 1000l}) {
    Fake(123456789123ull, resolution);
    timespec delivered{};
    Check(::clock_getres(CLOCK_MONOTONIC_RAW, &delivered) == 0 &&
              delivered.tv_sec == 0 && delivered.tv_nsec == resolution,
          "interposed resolution reaches the actual source call boundary");
    Check(Clock::host_tick_frequency_platform() == kNanosecondsPerSecond,
          "nanosecond counter frequency is independent of resolution");
    Check(Clock::QueryHostTickFrequency() == kNanosecondsPerSecond,
          "public host frequency uses the same nanosecond units");
    Check(Clock::host_tick_count_platform() == 123456789123ull,
          "platform counter preserves seconds and nanoseconds");
    Check(Clock::QueryHostTickCount() == 123456789123ull,
          "public counter preserves nanosecond units");
    Check(Clock::QueryHostUptimeMillis() == 123456ull,
          "uptime conversion is independent of resolution");
    fake_ticks.fetch_add(kNanosecondsPerSecond, std::memory_order_relaxed);
    Check(Clock::QueryHostTickCount() - 123456789123ull == Clock::QueryHostTickFrequency(),
          "one-second counter delta equals reported frequency");
  }
  fake_raw.store(false, std::memory_order_release);
}
void Uptime() {
  // Actual overflow boundary of the old nanoseconds * 1000 expression, then
  // real long-uptime examples and the maximum representable nanosecond count.
  constexpr struct { uint64_t ticks; uint64_t millis; } samples[] = {
      {0, 0}, {999999, 0}, {1000000, 1}, {123456789123ull, 123456},
      {18446744073709551ull, 18446744073ull},
      {18446744073709552ull, 18446744073ull},
      {18489600123456789ull, 18489600123ull},  // 214 days + fractional second.
      {43200000123456789ull, 43200000123ull},  // 500 days + fractional second.
      {std::numeric_limits<uint64_t>::max(), 18446744073709ull}};
  uint64_t previous = 0;
  for (const auto& sample : samples) {
    if (sample.ticks / kNanosecondsPerSecond >
        static_cast<uint64_t>(std::numeric_limits<time_t>::max())) continue;
    Fake(sample.ticks);
    Check(Clock::host_tick_count_platform() == sample.ticks,
          "actual platform counter retains the long uptime");
    const auto millis = Clock::QueryHostUptimeMillis();
    Check(millis == sample.millis, "long uptime converts to exact milliseconds without overflow");
    Check(millis >= previous, "uptime remains monotonic across the former overflow boundary");
    previous = millis;
  }
  fake_raw.store(false, std::memory_order_release);
}
void Scaling() {
  Fake(1000000000000ull);
  Clock::QueryGuestTickCount();  // Synchronize after changing only the fake clock.
  Clock::set_guest_tick_frequency(50000000);
  for (const long resolution : {1l, 10l, 1000l}) {
    fake_resolution.store(resolution, std::memory_order_relaxed);
    for (const double scalar : {0.5, 1.0, 2.0}) {
      Clock::set_guest_time_scalar(scalar);
      const auto start = Clock::QueryGuestTickCount();
      fake_ticks.fetch_add(kNanosecondsPerSecond, std::memory_order_relaxed);
      const auto finish = Clock::QueryGuestTickCount();
      Check(finish - start == static_cast<uint64_t>(50000000 * scalar),
            "actual guest counter applies 50 MHz and the requested scalar at every resolution");
      Check(Clock::ScaleGuestDurationMillis(1000) == static_cast<uint32_t>(1000 * scalar),
            "actual duration scaling retains the requested scalar");
    }
  }
  Clock::set_guest_time_scalar(1.0);
  fake_raw.store(false, std::memory_order_release);
}
void Real() {
  fake_raw.store(false, std::memory_order_release);
  timespec resolution{};
  Check(::clock_getres(CLOCK_MONOTONIC_RAW, &resolution) == 0,
        "real raw clock resolution is available");
  Check(Clock::QueryHostTickFrequency() == kNanosecondsPerSecond,
        "real raw clock uses one billion nanosecond ticks per second");
  const auto before = KernelRawTicks();
  const auto ticks = Clock::QueryHostTickCount();
  const auto after = KernelRawTicks();
  Check(before <= ticks && ticks <= after,
        "actual public counter lies between direct kernel nanosecond samples");
  auto previous = ticks;
  for (unsigned i = 0; i < 128; ++i) {
    const auto current = Clock::QueryHostTickCount();
    Check(current >= previous, "real raw counter is monotonic");
    previous = current;
  }
  const auto uptime_before = KernelRawTicks() / 1000000ull;
  const auto uptime = Clock::QueryHostUptimeMillis();
  const auto uptime_after = KernelRawTicks() / 1000000ull;
  Check(uptime_before <= uptime && uptime <= uptime_after,
        "real uptime matches direct kernel nanosecond conversion");

  Clock::set_guest_tick_frequency(50000000);
  for (const double scalar : {0.5, 1.0, 2.0}) {
    Clock::set_guest_time_scalar(scalar);
    const auto ratio = Clock::guest_tick_ratio();
    Check(ratio.first == 1 && ratio.second == static_cast<uint64_t>(20 / scalar),
          "real 50 MHz guest ratio matches the independently expected scalar");
    const auto host_before_start = Clock::QueryHostTickCount();
    const auto guest_start = Clock::QueryGuestTickCount();
    const auto host_after_start = Clock::QueryHostTickCount();
    timespec pause{0, 2000000};
    while (::nanosleep(&pause, &pause) != 0) {
      Check(errno == EINTR, "bounded real sleep only retries interruption");
    }
    const auto host_before_end = Clock::QueryHostTickCount();
    const auto guest_end = Clock::QueryGuestTickCount();
    const auto host_after_end = Clock::QueryHostTickCount();
    const auto lower = (host_before_end - host_after_start) * ratio.first / ratio.second;
    const auto upper = (host_after_end - host_before_start) * ratio.first / ratio.second;
    Check(guest_end >= guest_start, "real guest counter remains monotonic");
    const auto delta = guest_end - guest_start;
    Check(delta + 1 >= lower && delta <= upper + 1,
          "actual real guest delta fits kernel counter brackets and the configured scalar");
  }
  Clock::set_guest_time_scalar(1.0);
  std::cout << "Real CLOCK_MONOTONIC_RAW resolution=" << resolution.tv_sec << "s+"
            << resolution.tv_nsec << "ns (host fixture only)\n";
}
}  // namespace

extern "C" int clock_gettime(clockid_t clock, timespec* value) noexcept {
  if (clock == CLOCK_MONOTONIC_RAW && fake_raw.load(std::memory_order_acquire)) {
    const auto ticks = fake_ticks.load(std::memory_order_relaxed);
    value->tv_sec = static_cast<time_t>(ticks / kNanosecondsPerSecond);
    value->tv_nsec = static_cast<long>(ticks % kNanosecondsPerSecond);
    return 0;
  }
  return static_cast<int>(::syscall(SYS_clock_gettime, clock, value));
}
extern "C" int clock_getres(clockid_t clock, timespec* value) noexcept {
  if (clock == CLOCK_MONOTONIC_RAW && fake_raw.load(std::memory_order_acquire)) {
    if (value) {
      value->tv_sec = 0;
      value->tv_nsec = fake_resolution.load(std::memory_order_relaxed);
    }
    return 0;
  }
  return static_cast<int>(::syscall(SYS_clock_getres, clock, value));
}
int main(int argc, char** argv) {
  try {
    Check(rex::cvar::SetFlagByName("clock_no_scaling", "false"), "enable actual guest scaling");
    Check(rex::cvar::SetFlagByName("clock_source_raw", "false"), "use actual platform clock API");
    const std::string_view selection = argc == 2 ? argv[1] : "all";
    Check(argc <= 2 && (selection == "all" || selection == "units" || selection == "uptime" ||
                       selection == "scaling" || selection == "real"), "known bounded clock case");
    if (selection == "all" || selection == "units") Units();
    if (selection == "all" || selection == "uptime") Uptime();
    if (selection == "all" || selection == "scaling") Scaling();
    if (selection == "all" || selection == "real") Real();
    std::cout << "PASS Linux clock " << selection << " " << checks << " checks\n";
    return 0;
  } catch (const std::exception& error) {
    fake_raw.store(false, std::memory_order_release);
    std::cerr << "FAIL after " << checks << ": " << error.what() << '\n';
    return 1;
  }
}
