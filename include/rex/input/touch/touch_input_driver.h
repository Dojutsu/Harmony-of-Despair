/**
 * @file        rex/input/touch/touch_input_driver.h
 * @brief       On-screen touch controls mapped to an Xbox 360 controller.
 *
 * @license     BSD 3-Clause License
 *              See LICENSE file in the project root for full license text.
 */
#pragma once

#include <rex/input/input_driver.h>

#include <cstdint>
#include <vector>

namespace rex::input::touch {

// What the overlay draws. Positions are fractions of the window width/height;
// radii are fractions of the window height, so circles stay round.
struct OverlayControl {
  float x = 0.0f;
  float y = 0.0f;
  float radius = 0.0f;
  const char* label = "";
  bool pressed = false;
};

struct OverlaySnapshot {
  bool visible = false;
  // The stick floats: its base sits wherever the thumb landed.
  OverlayControl stick_base;
  float knob_x = 0.0f;
  float knob_y = 0.0f;
  std::vector<OverlayControl> buttons;
};

// Hidden while a gamepad is connected; the touch device then reports a
// neutral state so it never fights the controller.
OverlaySnapshot GetOverlaySnapshot(float aspect);

class TouchInputDriver final : public InputDriver {
 public:
  explicit TouchInputDriver(rex::ui::Window* window, size_t window_z_order);
  ~TouchInputDriver() override;

  X_STATUS Setup() override;

  void EnumerateDevices(std::vector<DeviceInfo>& out) override;
  X_RESULT GetDeviceState(DeviceId id, X_INPUT_STATE* out_state) override;
  X_RESULT GetDeviceCapabilities(DeviceId id, uint32_t flags,
                                 X_INPUT_CAPABILITIES* out_caps) override;
  X_RESULT SetDeviceVibration(DeviceId id, X_INPUT_VIBRATION* vibration) override;
  X_RESULT GetDeviceKeystroke(DeviceId id, uint32_t flags,
                              X_INPUT_KEYSTROKE* out_keystroke) override;

 private:
  bool event_watch_added_ = false;
  bool events_initialized_ = false;
  uint32_t packet_number_ = 0;
  X_INPUT_GAMEPAD last_gamepad_{};
};

}  // namespace rex::input::touch
