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
#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string_view>
#include <sys/syscall.h>
#include <time.h>
#include <unistd.h>

namespace rex::chrono {
extern uint64_t last_host_tick_count_, last_guest_tick_count_, guest_tick_remainder_;
extern uint64_t guest_tick_frequency_;
extern double guest_time_scalar_;
extern std::pair<uint64_t, uint64_t> guest_tick_ratio_;
extern std::mutex tick_mutex_;
}

namespace {
using rex::chrono::Clock;
constexpr uint64_t kNanosecondsPerSecond = 1000000000ull;
std::atomic<bool> fake_raw{false};
std::atomic<uint64_t> fake_ticks{0};
std::atomic<long> fake_resolution{1};
unsigned checks = 0;
std::mutex sample_mutex;
std::condition_variable sample_cv;
bool old_sample_ready = false, release_old_sample = false;
thread_local bool delay_old_sample = false;

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
// Reset exact private clock state between synthetic epochs. The real monotonic
// counter never moves backwards; deterministic cases deliberately use distinct
// synthetic epochs and must not rely on the production stale-sample behavior.
void ResetGuestClock(uint64_t host, uint64_t guest = 0, uint64_t numerator = 1,
                     uint64_t denominator = 20) {
  fake_raw.store(false, std::memory_order_release);
  {
    std::lock_guard lock(rex::chrono::tick_mutex_);
    rex::chrono::last_host_tick_count_ = host;
    rex::chrono::last_guest_tick_count_ = guest;
    rex::chrono::guest_tick_remainder_ = 0;
    rex::chrono::guest_tick_frequency_ = 50000000;
    rex::chrono::guest_time_scalar_ = 1.0;
    rex::chrono::guest_tick_ratio_ = {numerator, denominator};
  }
  Fake(host);
}
void RestoreRealGuestClock() {
  fake_raw.store(false, std::memory_order_release);
  const auto host = Clock::QueryHostTickCount();
  std::lock_guard lock(rex::chrono::tick_mutex_);
  rex::chrono::last_host_tick_count_ = host;
  rex::chrono::last_guest_tick_count_ = 0;
  rex::chrono::guest_tick_remainder_ = 0;
  rex::chrono::guest_tick_frequency_ = 50000000;
  rex::chrono::guest_time_scalar_ = 1.0;
  rex::chrono::guest_tick_ratio_ = {1, 20};
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
  ResetGuestClock(1000000000000ull);
  Check(Clock::QueryGuestTickCount() == 0, "synthetic scaling epoch starts at the exact reset anchor");
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
void Granularity() {
  for (const uint64_t step : {1ull, 3ull, 7ull, 19ull, 20ull, 21ull, 39ull, 1000ull}) {
    ResetGuestClock(10000, 9);
    Check(Clock::QueryGuestTickCount() == 9, "zero-delta warmup preserves guest ticks");
    uint64_t end = 9;
    for (uint64_t i = 1; i <= 1000; ++i) {
      fake_ticks.store(10000 + i * step, std::memory_order_relaxed);
      end = Clock::QueryGuestTickCount();
    }
    Check(end == 9 + 1000 * step / 20,
          "50MHz elapsed conversion is independent of update partition granularity");
  }
  ResetGuestClock(0);
  fake_ticks.store(19, std::memory_order_relaxed);
  Check(Clock::QueryGuestTickCount() == 0 && rex::chrono::guest_tick_remainder_ == 19,
        "nineteen nanoseconds retain an incomplete guest tick");
  Check(Clock::QueryGuestTickCount() == 0 && rex::chrono::guest_tick_remainder_ == 19 &&
            rex::chrono::last_host_tick_count_ == 19,
        "equal host sample preserves both anchor and retained fraction");
  fake_ticks.store(18, std::memory_order_relaxed);
  Check(Clock::QueryGuestTickCount() == 0 && rex::chrono::guest_tick_remainder_ == 19 &&
            rex::chrono::last_host_tick_count_ == 19,
        "older host sample preserves both anchor and retained fraction");
  fake_ticks.store(20, std::memory_order_relaxed);
  Check(Clock::QueryGuestTickCount() == 1 && rex::chrono::guest_tick_remainder_ == 0,
        "the twentieth nanosecond completes the retained fraction");
  fake_ticks.store(30, std::memory_order_relaxed);
  Clock::QueryGuestTickCount();
  Clock::set_guest_tick_frequency(50000000);
  Clock::set_guest_time_scalar(1.0);
  Check(rex::chrono::guest_tick_remainder_ == 10,
        "recomputing an unchanged ratio preserves the fraction");
  Clock::set_guest_time_scalar(2.0);
  Check(rex::chrono::guest_tick_remainder_ == 0,
        "changing ratio starts a fraction in the new denominator");
  fake_ticks.store(40, std::memory_order_relaxed);
  Check(Clock::QueryGuestTickCount() == 2, "new ratio applies to subsequent host elapsed time");
  RestoreRealGuestClock();
}
void StaleSample() {
  ResetGuestClock(40);
  old_sample_ready = false;
  release_old_sample = false;
  fake_ticks.store(80, std::memory_order_relaxed);
  uint64_t old_result = 0;
  std::thread old([&] {
    delay_old_sample = true;
    old_result = Clock::QueryGuestTickCount();
  });
  bool ready;
  {
    std::unique_lock lock(sample_mutex);
    ready = sample_cv.wait_for(lock, std::chrono::seconds(3), [] { return old_sample_ready; });
  }
  uint64_t newer_result = 0;
  if (ready) {
    fake_ticks.store(100, std::memory_order_relaxed);
    newer_result = Clock::QueryGuestTickCount();
  }
  {
    std::lock_guard lock(sample_mutex);
    release_old_sample = true;
  }
  sample_cv.notify_all();
  old.join();
  Check(ready, "bounded old-sample interposition reached the actual clock syscall");
  Check(newer_result == 3 && old_result == 3, "stale caller observes the latest guest tick count");
  Check(rex::chrono::last_host_tick_count_ == 100,
        "stale pre-lock sample cannot rewind the host elapsed-time anchor");
  fake_ticks.store(120, std::memory_order_relaxed);
  Check(Clock::QueryGuestTickCount() == 4, "elapsed time after a stale sample is counted once");
  RestoreRealGuestClock();
}
void FullWidth() {
  constexpr auto max = std::numeric_limits<uint64_t>::max();
  ResetGuestClock(0, 0, max, max);
  fake_ticks.store(2, std::memory_order_relaxed);
  Check(Clock::QueryGuestTickCount() == 2, "full-width multiplication does not truncate before division");
  ResetGuestClock(0, max - 1);
  fake_ticks.store(40, std::memory_order_relaxed);
  Check(Clock::QueryGuestTickCount() == 0, "guest tick counter retains uint64 wrap semantics");
  uint64_t random = 0xA17BC39D;
  auto next = [&] { random ^= random << 13; random ^= random >> 7; random ^= random << 17; return random; };
  for (unsigned i = 0; i < 10000; ++i) {
    const auto delta = next(), numerator = next(), denominator = next() | 1;
    const auto remainder = next() % denominator;
    ResetGuestClock(0, 0, numerator, denominator);
    rex::chrono::guest_tick_remainder_ = remainder;
    fake_ticks.store(delta, std::memory_order_relaxed);
    // The implementation is portable64bit arithmetic. This Linux-only fixture
    // uses an independently wider mathematical oracle, including overflowing products.
    const auto exact = static_cast<unsigned __int128>(delta) * numerator + remainder;
    Check(Clock::QueryGuestTickCount() == static_cast<uint64_t>(exact / denominator),
          "full-width guest quotient matches independent128bit arithmetic");
    Check(rex::chrono::guest_tick_remainder_ == static_cast<uint64_t>(exact % denominator),
          "full-width guest remainder matches independent128bit arithmetic");
  }
  for (const auto numerator : {0ull, 1ull, 2ull, 50000000ull}) {
    ResetGuestClock(0, 0, numerator, 1000000000);
    fake_ticks.store(max, std::memory_order_relaxed);
    const auto exact = static_cast<unsigned __int128>(max) * numerator;
    Check(Clock::QueryGuestTickCount() == static_cast<uint64_t>(exact / 1000000000),
          "extreme host count with small numerator matches the wide oracle");
  }
  Check(rex::cvar::SetFlagByName("clock_no_scaling", "true"), "enable direct guest conversion");
  ResetGuestClock(0, 77, max, max);
  fake_ticks.store(2, std::memory_order_relaxed);
  Check(Clock::QueryGuestTickCount() == 2, "direct conversion also avoids intermediate overflow");
  Check(rex::chrono::last_host_tick_count_ == 0 && rex::chrono::last_guest_tick_count_ == 77,
        "direct conversion leaves incremental clock state unchanged");
  Check(rex::cvar::SetFlagByName("clock_no_scaling", "false"), "restore incremental guest conversion");
  RestoreRealGuestClock();
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
    if (delay_old_sample) {
      std::unique_lock lock(sample_mutex);
      old_sample_ready = true;
      sample_cv.notify_all();
      sample_cv.wait(lock, [] { return release_old_sample; });
    }
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
                       selection == "scaling" || selection == "real" || selection == "granularity" ||
                       selection == "stale" || selection == "full-width"), "known bounded clock case");
    if (selection == "all" || selection == "units") Units();
    if (selection == "all" || selection == "uptime") Uptime();
    if (selection == "all" || selection == "scaling") Scaling();
    if (selection == "all" || selection == "granularity") Granularity();
    if (selection == "all" || selection == "stale") StaleSample();
    if (selection == "all" || selection == "full-width") FullWidth();
    if (selection == "all" || selection == "real") { RestoreRealGuestClock(); Real(); }
    std::cout << "PASS Linux clock " << selection << " " << checks << " checks\n";
    return 0;
  } catch (const std::exception& error) {
    fake_raw.store(false, std::memory_order_release);
    std::cerr << "FAIL after " << checks << ": " << error.what() << '\n';
    return 1;
  }
}
