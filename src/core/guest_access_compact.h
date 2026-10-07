#pragma once
#include <rex/platform/guest_access.h>
#include <optional>
namespace rex::guest::detail {
// Success leaves a fresh optional disengaged. Failure constructs the full
// captured snapshot in normal context; callers observe it only after false.
using ScalarCaptureFailure = std::optional<CapturedFault>;
__attribute__((visibility("hidden")))
bool CaptureReadCompact(const void* address, void* output, size_t width,
                        ScalarCaptureFailure& failure) noexcept;
__attribute__((visibility("hidden")))
bool CaptureWriteCompact(void* address, const void* value, size_t width,
                         ScalarCaptureFailure& failure) noexcept;
} // namespace rex::guest::detail
