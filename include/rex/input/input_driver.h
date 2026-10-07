#pragma once
/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 *
 * @modified    Tom Clay, 2026 - Adapted for ReXGlue runtime
 */

#include <cstddef>
#include <functional>
#include <vector>

#include <rex/input/device.h>
#include <rex/input/input.h>
#include <rex/kernel.h>
#include <rex/ui/window.h>

namespace rex::ui {
class Window;
}

namespace rex::input {

class InputSystem;

class InputDriver {
 public:
  virtual ~InputDriver() = default;

  virtual X_STATUS Setup() = 0;

  /// Devices this driver has open, in its own arrival order. InputSystem
  /// assigns the cross-driver ordinal, so leave DeviceInfo::ordinal at zero.
  virtual void EnumerateDevices(std::vector<DeviceInfo>& out) = 0;

  virtual X_RESULT GetDeviceState(DeviceId id, X_INPUT_STATE* out_state) = 0;
  // UI sampling must not consume guest keystrokes or start a test timeline.
  virtual X_RESULT GetDeviceStateForUI(DeviceId, X_INPUT_STATE*) {
    return X_ERROR_DEVICE_NOT_CONNECTED;
  }
  // Observe the effective guest state after modal capture has been applied.
  virtual void OnGuestStateDelivered(DeviceId, const X_INPUT_STATE&, bool /*ui_consumed*/) {}
  virtual X_RESULT GetDeviceCapabilities(DeviceId id, uint32_t flags,
                                         X_INPUT_CAPABILITIES* out_caps) = 0;
  virtual X_RESULT SetDeviceVibration(DeviceId id, X_INPUT_VIBRATION* vibration) = 0;
  virtual X_RESULT GetDeviceKeystroke(DeviceId id, uint32_t flags,
                                      X_INPUT_KEYSTROKE* out_keystroke) = 0;

  virtual void OnWindowAvailable(rex::ui::Window* /*window*/) {}

  void set_is_active_callback(std::function<bool()> is_active_callback) {
    is_active_callback_ = is_active_callback;
  }

 protected:
  explicit InputDriver(rex::ui::Window* window, size_t window_z_order)
      : window_(window), window_z_order_(window_z_order) {}

  rex::ui::Window* window() const { return window_; }
  size_t window_z_order() const { return window_z_order_; }

  bool is_active() const { return !is_active_callback_ || is_active_callback_(); }

 private:
  rex::ui::Window* window_;
  size_t window_z_order_;
  std::function<bool()> is_active_callback_ = nullptr;
};

}  // namespace rex::input
