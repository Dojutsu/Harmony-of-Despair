/**
 * @file        core/guest_access_android.cpp
 * @brief       Signal-context bookkeeping for platforms without the x86-64
 *              registered-leaf fault backend
 *
 * @license     BSD 3-Clause License
 *              See LICENSE file in the project root for full license text.
 *
 * Generated code on these platforms accesses guest memory natively; MMIO and
 * write-watch faults are serviced by the exception handler chain from the
 * signal handler. The shared fault-state bookkeeping still asks whether it
 * runs inside a signal and whether capture is suppressed, so keep that state.
 */

#include <rex/platform.h>

#if REX_PLATFORM_ANDROID

#include <rex/platform/guest_access.h>

namespace rex::guest {

namespace {
thread_local int signal_depth = 0;
thread_local int capture_suppressed = 0;
}  // namespace

bool InSignalContext() noexcept { return signal_depth != 0; }
void EnterSignalContext() noexcept { ++signal_depth; }
void LeaveSignalContext() noexcept {
  if (signal_depth > 0) --signal_depth;
}
void SuppressAccessCapture(bool suppressed) noexcept { capture_suppressed = suppressed ? 1 : 0; }
bool HasArmedAccessFrame() noexcept { return false; }

}  // namespace rex::guest

#endif  // REX_PLATFORM_ANDROID
