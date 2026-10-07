#pragma once

#include <chrono>
#include <filesystem>
#include <mutex>
#include <rex/input/input_driver.h>
#include <rex/input/scripted/timeline.h>

namespace rex::input::scripted {

class ScriptedInputDriver final : public InputDriver {
 public:
  using Clock = std::function<std::chrono::steady_clock::time_point()>;
  explicit ScriptedInputDriver(std::filesystem::path script, Clock clock = {});
  ScriptedInputDriver(std::filesystem::path script, Clock clock, bool append_only);
  X_STATUS Setup() override;
  void EnumerateDevices(std::vector<DeviceInfo>& out) override;
  X_RESULT GetDeviceState(DeviceId id, X_INPUT_STATE* out) override;
  X_RESULT GetDeviceStateForUI(DeviceId id, X_INPUT_STATE* out) override;
  void OnGuestStateDelivered(DeviceId id, const X_INPUT_STATE& state, bool ui_consumed) override;
  X_RESULT GetDeviceCapabilities(DeviceId id, uint32_t flags, X_INPUT_CAPABILITIES* out) override;
  X_RESULT SetDeviceVibration(DeviceId id, X_INPUT_VIBRATION* vibration) override;
  X_RESULT GetDeviceKeystroke(DeviceId id, uint32_t flags, X_INPUT_KEYSTROKE* out) override;

 private:
  X_RESULT Sample(DeviceId id, X_INPUT_STATE* out, bool start_clock);
  void Reload(std::chrono::steady_clock::time_point now, uint64_t elapsed_ms);
  void ReportReloadError(const std::string& error);
  bool external_clock_ = false;
  Clock clock_;
  std::filesystem::path script_;
  Timeline timeline_;
  bool append_only_ = false;
  bool reload_clock_set_ = false;
  std::chrono::steady_clock::time_point reloaded_at_{};
  std::string accepted_text_, last_reload_error_;
  uint64_t script_device_ = 0, script_inode_ = 0;
  std::mutex mutex_;
  bool started_ = false;
  uint32_t logged_ui_packet_ = UINT32_MAX;
  uint32_t logged_guest_packet_ = UINT32_MAX;
  bool logged_guest_consumed_ = false;
  uint32_t guest_source_packet_ = 0;
  int64_t guest_elapsed_ms_ = 0;
  std::chrono::steady_clock::time_point started_at_;
};

}  // namespace rex::input::scripted
