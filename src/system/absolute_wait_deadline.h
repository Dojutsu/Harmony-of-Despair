#pragma once
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <limits>
#include <rex/chrono/clock.h>

namespace rex::system::detail {
// An absolute guest deadline must be reconsidered after every bounded host
// slice. No host clock changes, retained mapping decisions or guest-state edits.
inline uint32_t AbsoluteDeadlineMillis(uint64_t deadline) {
  const auto now = chrono::Clock::QueryGuestSystemTime();
  if (deadline <= now) return 0;
  const auto ticks = deadline - now;
  const auto ms = ticks / 10000 + (ticks % 10000 != 0);
  return static_cast<uint32_t>(std::min<uint64_t>(ms, std::numeric_limits<uint32_t>::max()));
}
inline std::chrono::milliseconds AbsoluteWaitSlice(uint64_t deadline) {
  const auto ms = AbsoluteDeadlineMillis(deadline);
  if (!ms) return std::chrono::milliseconds(0);
  return std::chrono::milliseconds(std::clamp(chrono::Clock::ScaleGuestDurationMillis(ms), 1u, 100u));
}
inline bool AbsoluteWaitPending(uint64_t deadline) {
  return deadline > chrono::Clock::QueryGuestSystemTime();
}
} // namespace rex::system::detail
