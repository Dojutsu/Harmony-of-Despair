#pragma once

#include <chrono>
#include <filesystem>
#include <mutex>
#include <rex/input/input_driver.h>
#include <rex/input/scripted/timeline.h>

namespace rex::input::scripted {

class ScriptedInputDriver final : public InputDriver {
 public:
  explicit ScriptedInputDriver(std::filesystem::path script);
  X_STATUS Setup() override;
  void EnumerateDevices(std::vector<DeviceInfo>& out) override;
  X_RESULT GetDeviceState(DeviceId id, X_INPUT_STATE* out) override;
  X_RESULT GetDeviceCapabilities(DeviceId id, uint32_t flags, X_INPUT_CAPABILITIES* out) override;
  X_RESULT SetDeviceVibration(DeviceId id, X_INPUT_VIBRATION* vibration) override;
  X_RESULT GetDeviceKeystroke(DeviceId id, uint32_t flags, X_INPUT_KEYSTROKE* out) override;

 private:
  std::filesystem::path script_;
  Timeline timeline_;
  std::mutex mutex_;
  bool started_ = false;
  std::chrono::steady_clock::time_point started_at_;
};

}  // namespace rex::input::scripted
