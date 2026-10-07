#define SDL_MAIN_HANDLED
#include <SDL3/SDL_main.h>
#include <rex/chrono/clock.h>
#include <rex/input/input_system.h>
#include <rex/input/sdl/sdl_input_driver.h>
#include <rex/ui/windowed_app_context_sdl.h>
#include <rex/input/scripted/scripted_input_driver.h>
#include <rex/logging.h>
#include <rex/system/dispatch_wait.h>
#include <rex/ui/dialog_completion.h>
#include <condition_variable>
#include <deque>
#include <future>
#include <thread>
#include <rex/ui/imgui_controller.h>
#include <chrono>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <spdlog/sinks/ostream_sink.h>
#include <string>
#include <string_view>
#include <unistd.h>

using namespace rex;
using namespace rex::input;
namespace {
unsigned checks = 0;
void Check(bool condition, const char* message) {
  ++checks;
  if (!condition) throw std::runtime_error(message);
}
class FakePad : public InputDriver {
 public:
  FakePad() : InputDriver(nullptr, 0) {}
  X_STATUS Setup() override { return X_STATUS_SUCCESS; }
  void EnumerateDevices(std::vector<DeviceInfo>& out) override {
    DeviceInfo info; info.id = static_cast<DeviceId>(1); out.push_back(info);
  }
  X_RESULT GetDeviceState(DeviceId, X_INPUT_STATE* out) override { *out = state; return X_ERROR_SUCCESS; }
  X_RESULT GetDeviceStateForUI(DeviceId id, X_INPUT_STATE* out) override { return GetDeviceState(id, out); }
  X_RESULT GetDeviceCapabilities(DeviceId, uint32_t, X_INPUT_CAPABILITIES*) override { return X_ERROR_SUCCESS; }
  X_RESULT SetDeviceVibration(DeviceId, X_INPUT_VIBRATION*) override { return X_ERROR_SUCCESS; }
  X_RESULT GetDeviceKeystroke(DeviceId, uint32_t, X_INPUT_KEYSTROKE* out) override {
    ++keystroke_polls;
    if (!state.gamepad.buttons) return X_ERROR_EMPTY;
    *out = {}; out->virtual_key = 0x5800; return X_ERROR_SUCCESS;
  }
  unsigned keystroke_polls = 0;
  X_INPUT_STATE state{};
};
void DriverRouting() {
  InputSystem input(nullptr);
  auto driver = std::make_unique<FakePad>();
  auto* pad = driver.get();
  input.AddDriver(std::move(driver));
  input.SetDeviceAssignment(std::make_unique<SlotAssignment>());
  X_INPUT_STATE guest{}, host{};
  pad->state.gamepad.buttons = X_INPUT_GAMEPAD_A;
  Check(input.GetState(0, &guest) == X_ERROR_SUCCESS && guest.gamepad.buttons == X_INPUT_GAMEPAD_A,
        "guest controller works before UI capture");
  const auto packet = uint32_t(guest.packet_number);
  input.SetUIControllerCapture(true);
  Check(input.GetStateForUI(0, &host) == X_ERROR_SUCCESS && host.gamepad.buttons == X_INPUT_GAMEPAD_A,
        "host UI receives native driver state");
  Check(input.GetState(0, &guest) == X_ERROR_SUCCESS && !guest.gamepad.buttons && uint32_t(guest.packet_number) != packet,
        "modal UI masks guest and announces neutral state");
  input.SetUIControllerCapture(false);
  Check(input.GetState(0, &guest) == X_ERROR_SUCCESS && !guest.gamepad.buttons,
        "closing A cannot also activate the guest title");
  pad->state.gamepad.buttons = 0;
  Check(input.GetState(0, &guest) == X_ERROR_SUCCESS && !guest.gamepad.buttons,
        "guest remains neutral when closing control releases");
  pad->state.gamepad.buttons = X_INPUT_GAMEPAD_A;
  Check(input.GetState(0, &guest) == X_ERROR_SUCCESS && guest.gamepad.buttons == X_INPUT_GAMEPAD_A,
        "fresh press reaches guest after host dialog closes");
}
void SDLVirtualController() {
  SDL_SetMainReady();
  ui::SDLWindowedAppContext context;
  InputSystem input(nullptr);
  auto driver = std::make_unique<sdl::SDLInputDriver>(nullptr, 0);
  Check(driver->Setup() == X_STATUS_SUCCESS, "actual SDL input driver setup");
  driver->AttachUIContext(context);
  input.AddDriver(std::move(driver));
  class PrivateAssignment final : public DeviceAssignment {
   public:
    void OnDevicesChanged(const std::vector<DeviceInfo>& devices) override {
      private_devices.clear();
      for (const auto& device : devices) {
        if (device.name == "Private controller UI regression") private_devices.push_back(device.id);
      }
    }
    void DevicesForUser(uint32_t user, std::vector<DeviceId>& out) const override {
      if (!user) out.insert(out.end(), private_devices.begin(), private_devices.end());
    }
   private:
    std::vector<DeviceId> private_devices;
  };
  input.SetDeviceAssignment(std::make_unique<PrivateAssignment>());
  SDL_VirtualJoystickDesc description{};
  SDL_INIT_INTERFACE(&description);
  description.type = SDL_JOYSTICK_TYPE_GAMEPAD;
  description.name = "Private controller UI regression";
  description.naxes = SDL_GAMEPAD_AXIS_COUNT;
  description.nbuttons = SDL_GAMEPAD_BUTTON_COUNT;
  description.axis_mask = (1u << SDL_GAMEPAD_AXIS_COUNT) - 1;
  description.button_mask = (1u << SDL_GAMEPAD_BUTTON_COUNT) - 1;
  description.name = "Private unassigned controller UI regression";
  const auto unassigned = SDL_AttachVirtualJoystick(&description);
  Check(unassigned != 0, "additional private controller cannot steal fixture user assignment");
  description.name = "Private controller UI regression";
  const auto id = SDL_AttachVirtualJoystick(&description);
  Check(id != 0, "in-process virtual gamepad attached without host device changes");
  auto* joystick = SDL_OpenJoystick(id);
  Check(joystick != nullptr, "private virtual joystick opened");
  X_INPUT_STATE opened{};
  Check(input.GetStateForUI(0, &opened) == X_ERROR_SUCCESS, "actual SDL watch opens newly attached gamepad");
  input.SetActiveCallback([] { return false; });
  Check(SDL_SetJoystickVirtualButton(joystick, SDL_GAMEPAD_BUTTON_SOUTH, true) &&
        SDL_SetJoystickVirtualAxis(joystick, SDL_GAMEPAD_AXIS_LEFTX, 20000) &&
        SDL_SetJoystickVirtualAxis(joystick, SDL_GAMEPAD_AXIS_LEFTY, -12000),
        "virtual A and directional input published");
  SDL_UpdateJoysticks(); SDL_PumpEvents();
  X_INPUT_STATE host{}, guest{};
  const auto host_status = input.GetStateForUI(0, &host);
  Check(host_status == X_ERROR_SUCCESS &&
        host.gamepad.buttons == X_INPUT_GAMEPAD_A && host.gamepad.thumb_lx == 20000 && host.gamepad.thumb_ly == 11999,
        "actual SDL event/watch/driver route supplies raw host UI fields");
  Check(input.GetState(0, &guest) == X_ERROR_SUCCESS && !guest.gamepad.buttons,
        "SDL guest activity gate leaves raw host UI sampling available");
  input.SetActiveCallback([] { return true; });
  input.SetUIControllerCapture(true);
  Check(input.GetState(0, &guest) == X_ERROR_SUCCESS && !guest.gamepad.buttons && !guest.gamepad.thumb_lx,
        "actual SDL controller is neutral to guest while modal UI captures");
  Check(SDL_SetJoystickVirtualButton(joystick, SDL_GAMEPAD_BUTTON_SOUTH, false) &&
        SDL_SetJoystickVirtualButton(joystick, SDL_GAMEPAD_BUTTON_EAST, true), "private virtual B input set");
  SDL_UpdateJoysticks(); SDL_PumpEvents();
  Check(input.GetStateForUI(0, &host) == X_ERROR_SUCCESS && host.gamepad.buttons == X_INPUT_GAMEPAD_B,
        "UI controller route progresses while guest is not polling");
  input.SetUIControllerCapture(false);
  Check(input.GetState(0, &guest) == X_ERROR_SUCCESS && !guest.gamepad.buttons,
        "actual SDL closing B cannot leak into guest after modal closes");
  Check(SDL_SetJoystickVirtualButton(joystick, SDL_GAMEPAD_BUTTON_EAST, false) &&
        SDL_SetJoystickVirtualAxis(joystick, SDL_GAMEPAD_AXIS_LEFTX, 0) &&
        SDL_SetJoystickVirtualAxis(joystick, SDL_GAMEPAD_AXIS_LEFTY, 0),
        "private SDL controller released before keystroke-only cycle");
  SDL_UpdateJoysticks(); SDL_PumpEvents();
  X_INPUT_KEYSTROKE key{};
  Check(input.GetKeystroke(0, 0, &key) == X_ERROR_EMPTY,
        "actual SDL neutral release clears previous modal gate without guest state poll");
  SDL_SetJoystickVirtualButton(joystick, SDL_GAMEPAD_BUTTON_SOUTH, true);
  SDL_UpdateJoysticks(); SDL_PumpEvents();
  Check(input.GetKeystroke(0, 0, &key) == X_ERROR_SUCCESS && key.virtual_key == 0x5800 &&
        key.flags == X_INPUT_KEYSTROKE_KEYDOWN,
        "actual SDL guest A keydown establishes repeat state before modal");
  const auto pressed_at = chrono::Clock::QueryGuestUptimeMillis();
  input.SetUIControllerCapture(true);
  Check(input.GetKeystroke(0, 0, &key) == X_ERROR_EMPTY,
        "modal suppresses actual SDL keystroke polling");
  std::this_thread::sleep_for(std::chrono::milliseconds(HID_SDL_REPEAT_DELAY + 50));
  Check(chrono::Clock::QueryGuestUptimeMillis() - pressed_at > HID_SDL_REPEAT_DELAY,
        "modal lasts beyond actual SDL guest repeat delay");
  input.SetUIControllerCapture(false);
  input.SetActiveCallback([] { return false; });
  Check(input.GetState(0, &guest) == X_ERROR_SUCCESS && !guest.gamepad.buttons,
        "closing modal while guest activity is masked remains neutral");
  input.SetActiveCallback([] { return true; });
  Check(input.GetState(0, &guest) == X_ERROR_SUCCESS && !guest.gamepad.buttons,
        "activity-filtered zero cannot release physically held closing A");
  Check(input.GetKeystroke(0, 0, &key) == X_ERROR_EMPTY,
        "held closing A stays suppressed in actual SDL keystrokes after activity resumes");
  SDL_SetJoystickVirtualButton(joystick, SDL_GAMEPAD_BUTTON_SOUTH, false);
  SDL_UpdateJoysticks(); SDL_PumpEvents();
  Check(input.GetKeystroke(0, 0, &key) == X_ERROR_SUCCESS && key.virtual_key == 0x5800 &&
        key.flags == X_INPUT_KEYSTROKE_KEYUP,
        "actual SDL release emits keyup instead of stale keydown repeat after modal");
  Check(input.GetKeystroke(0, 0, &key) == X_ERROR_EMPTY,
        "actual SDL neutral controller has no repeat after release");
  SDL_SetJoystickVirtualButton(joystick, SDL_GAMEPAD_BUTTON_SOUTH, true);
  SDL_UpdateJoysticks(); SDL_PumpEvents();
  Check(input.GetKeystroke(0, 0, &key) == X_ERROR_SUCCESS && key.flags == X_INPUT_KEYSTROKE_KEYDOWN,
        "actual SDL fresh press resumes keystrokes after modal release");
  SDL_CloseJoystick(joystick);
  Check(SDL_DetachVirtualJoystick(id), "private virtual gamepad detaches cleanly");
  Check(input.GetStateForUI(0, &host) == X_ERROR_DEVICE_NOT_CONNECTED,
        "actual SDL removal reaches native UI route");
  Check(SDL_DetachVirtualJoystick(unassigned), "additional private gamepad detaches cleanly");
  input.Shutdown();
}

void KeystrokeOnlyRelease() {
  InputSystem input(nullptr); auto driver = std::make_unique<FakePad>(); auto* pad = driver.get();
  input.AddDriver(std::move(driver)); input.SetDeviceAssignment(std::make_unique<SlotAssignment>());
  X_INPUT_KEYSTROKE key{};
  pad->state.gamepad.buttons = X_INPUT_GAMEPAD_A;
  input.SetUIControllerCapture(true); input.SetUIControllerCapture(false);
  Check(input.GetKeystroke(0, 0, &key) == X_ERROR_EMPTY && !pad->keystroke_polls,
        "keystroke-only guest ignores held closing input");
  pad->state.gamepad.buttons = 0;
  Check(input.GetKeystroke(0, 0, &key) == X_ERROR_EMPTY && pad->keystroke_polls == 1,
        "keystroke-only release clears UI latch without GetState");
  pad->state.gamepad.buttons = X_INPUT_GAMEPAD_A;
  Check(input.GetKeystroke(0, 0, &key) == X_ERROR_SUCCESS && key.virtual_key == 0x5800,
        "keystroke-only guest resumes on fresh press after UI release");
  class GuestOnlyPad final : public FakePad {
   public:
    X_RESULT GetDeviceStateForUI(DeviceId, X_INPUT_STATE*) override {
      return X_ERROR_DEVICE_NOT_CONNECTED;
    }
  };
  InputSystem guest_only(nullptr); auto unsupported = std::make_unique<GuestOnlyPad>();
  unsupported->state.gamepad.buttons = X_INPUT_GAMEPAD_A;
  guest_only.AddDriver(std::move(unsupported));
  guest_only.SetDeviceAssignment(std::make_unique<SlotAssignment>());
  guest_only.SetUIControllerCapture(true); guest_only.SetUIControllerCapture(false);
  Check(guest_only.GetKeystroke(0, 0, &key) == X_ERROR_SUCCESS,
        "drivers without a host UI route do not retain an uncheckable release latch");
}

void ScriptClock() {
  char path[] = "/tmp/rex-controller-ui-XXXXXX";
  const int descriptor = mkstemp(path);
  Check(descriptor >= 0, "private script fixture created");
  close(descriptor);
  struct Cleanup { const char* path; ~Cleanup() { std::remove(path); } } cleanup{path};
  { std::ofstream stream(path); stream << "0 4096 0 0 0 0 0 0\n100 0 0 0 0 0 0 0\n200 8192 0 0 0 0 0 0\n"; }
  auto now = std::chrono::steady_clock::time_point{};
  auto driver = std::make_unique<scripted::ScriptedInputDriver>(path, [&] { return now; });
  Check(driver->Setup() == X_STATUS_SUCCESS, "bounded file-only script setup");
  std::vector<DeviceInfo> devices;
  driver->EnumerateDevices(devices);
  Check(devices.size() == 1, "one scripted controller");
  InputSystem input(nullptr); input.AddDriver(std::move(driver));
  input.SetDeviceAssignment(std::make_unique<SlotAssignment>());
  std::ostringstream captured;
  auto sink = std::make_shared<spdlog::sinks::ostream_sink_mt>(captured);
  rex::AddSink(sink); rex::SetAllLevels(spdlog::level::debug);
  struct SinkCleanup { spdlog::sink_ptr sink; ~SinkCleanup() {
    rex::RemoveSink(sink); rex::SetAllLevels(spdlog::level::info);
  } } sink_cleanup{sink};
  X_INPUT_STATE guest{}, host{};
  now += std::chrono::seconds(5);
  Check(input.GetStateForUI(0, &host) == X_ERROR_SUCCESS && !host.gamepad.buttons,
        "UI sampling cannot start the first-guest-poll script clock");
  now += std::chrono::seconds(5);
  Check(input.GetState(0, &guest) == X_ERROR_SUCCESS && guest.gamepad.buttons == X_INPUT_GAMEPAD_A,
        "first guest poll anchors original script clock");
  now += std::chrono::milliseconds(150);
  Check(input.GetStateForUI(0, &host) == X_ERROR_SUCCESS && !host.gamepad.buttons && host.packet_number == 2,
        "script continues in UI while guest waits on dialog fence");
  Check(input.GetState(0, &guest) == X_ERROR_SUCCESS && guest.packet_number == host.packet_number,
        "UI and guest sample same row without consuming transitions twice");
  input.SetUIControllerCapture(true);
  now += std::chrono::milliseconds(100);
  Check(input.GetStateForUI(0, &host) == X_ERROR_SUCCESS && host.gamepad.buttons == X_INPUT_GAMEPAD_B,
        "same scripted controller delivers explicit host cancel press");
  rex::FlushLogging();
  Check(captured.str().find("Offline UI controller transition: elapsed_ms=250 packet=3 buttons=2000") != std::string::npos &&
        captured.str().find("Offline controller transition: elapsed_ms=250") == std::string::npos,
        "UI poll is identified separately and cannot claim guest delivery");
  Check(input.GetState(0, &guest) == X_ERROR_SUCCESS && !guest.gamepad.buttons,
        "scripted host button is suppressed in effective guest state during modal");
  rex::FlushLogging();
  Check(captured.str().find("Offline controller UI-consumed: elapsed_ms=250 packet=3 buttons=0000") != std::string::npos &&
        captured.str().find("Offline controller transition: elapsed_ms=250") == std::string::npos,
        "consumed script row logs effective neutral guest state with explicit UI identity");
  const auto size = captured.str().size();
  input.GetStateForUI(0, &host); input.GetState(0, &guest); rex::FlushLogging();
  Check(captured.str().size() == size, "repeated UI and guest polls do not duplicate selected-row evidence");
}
class CompletionDialog {
 public:
  explicit CompletionDialog(unsigned& deleted) : deleted_(deleted) {}
  void set_close_callback(std::function<void()> value) { close = std::move(value); }
  void Then(thread::Fence* value) { fence = value; }
  ~CompletionDialog() { ++deleted_; if (fence) fence->Signal(); }
  std::function<void()> close;
 private:
  unsigned& deleted_;
  thread::Fence* fence = nullptr;
};
void CompletionFailure() {
  std::atomic<int> shown{0}; unsigned deleted = 0, callbacks = 0;
  auto close = [&](CompletionDialog*, uint32_t& error, uint32_t& length) -> X_RESULT {
    ++callbacks; error = 17; length = 23; return X_ERROR_SUCCESS;
  };
  for (unsigned failure = 0; failure < 2; ++failure) {
    auto* dialog = new CompletionDialog(deleted);
    auto result = ui::RunDialogAndWait(dialog, close, [](auto) { return false; }, shown);
    Check(result.result == X_ERROR_CANCELLED && !result.extended_error && !result.length,
          "absent or rejecting UI delivery cancels with initialized output fields");
    Check(deleted == failure + 1 && !callbacks && shown == 0,
          "failed UI delivery deletes dialog without success callback or fence wait");
  }
  auto* dialog = new CompletionDialog(deleted);
  auto result = ui::RunDialogAndWait(dialog, close, [&](auto attach) {
    attach(); dialog->close(); delete dialog; return true;
  }, shown);
  Check(result.result == X_ERROR_SUCCESS && result.extended_error == 17 && result.length == 23,
        "actual close callback publishes extended result through real fence");
  Check(deleted == 3 && callbacks == 1 && shown == 0,
        "early completion before wait preserves dialog accounting and fence signal");
}
void DispatchWakeups() {
  std::mutex mutex; std::condition_variable_any condition;
  std::atomic<bool> running{true}; std::deque<int> queue;
  std::promise<void> entered; std::promise<bool> completed;
  auto ready = entered.get_future(); auto result = completed.get_future();
  std::thread worker([&] {
    std::unique_lock lock(mutex); entered.set_value();
    completed.set_value(system::WaitForDispatchWork(condition, lock, running, queue));
  });
  ready.wait();
  { std::lock_guard lock(mutex); }
  condition.notify_all(); condition.notify_all();
  const bool waited = result.wait_for(std::chrono::milliseconds(30)) == std::future_status::timeout;
  { std::lock_guard lock(mutex); queue.push_back(1); }
  condition.notify_all();
  const bool accepted = result.get(); worker.join();
  Check(waited && accepted && queue.size() == 1,
        "spurious empty-queue wakes stay parked until actual work exists");
  queue.clear(); running = true;
  std::promise<void> entered_shutdown; auto shutdown_ready = entered_shutdown.get_future();
  std::promise<bool> stopped; auto stopped_result = stopped.get_future();
  std::thread shutdown([&] {
    std::unique_lock lock(mutex); entered_shutdown.set_value();
    stopped.set_value(system::WaitForDispatchWork(condition, lock, running, queue));
  });
  shutdown_ready.wait();
  { std::lock_guard lock(mutex); running = false; }
  condition.notify_all();
  const bool accepted_shutdown = stopped_result.get(); shutdown.join();
  Check(!accepted_shutdown && queue.empty(), "shutdown wake returns without empty front/pop");
}

class DialogFrames {
 public:
  explicit DialogFrames(unsigned default_button, bool generic = false)
      : default_button_(default_button), generic_(generic) {
    context_ = ImGui::CreateContext();
    auto& io = ImGui::GetIO();
    ui::ConfigureControllerNavigation(io);
    io.IniFilename = nullptr;
    io.DisplaySize = ImVec2(800, 600);
    io.DeltaTime = 1.0f / 60;
    unsigned char* pixels; int width, height;
    io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
    navigation_.SetCaptured(true);
  }
  ~DialogFrames() { ImGui::DestroyContext(context_); }
  void Frame(uint16_t buttons = 0, bool connected = true, int16_t x = 0) {
    ImGui::SetCurrentContext(context_);
    X_INPUT_GAMEPAD state{}; state.buttons = buttons; state.thumb_lx = x;
    navigation_.Update(ImGui::GetIO(), state, connected);
    ImGui::NewFrame();
    if (first_) ImGui::OpenPopup("controller regression");
    if (ImGui::BeginPopupModal("controller regression", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
      char body[] = "Read-only host message";
      if (generic_) ImGui::InputTextMultiline("##body", body, sizeof(body), ImVec2(600, 0),
          ImGuiInputTextFlags_AutoSelectAll | ImGuiInputTextFlags_ReadOnly);
      const char* labels[] = {"Keep existing", "Create new"};
      for (unsigned i = 0; i < (generic_ ? 1u : 2u); ++i) {
        if (ui::DrawDialogButton(labels[i], ImVec2(140, 32), first_ && i == default_button_)) chosen = int(i);
        if (ImGui::IsItemFocused()) focused = int(i);
        if (!generic_ && i == 0) ImGui::SameLine();
      }
      if (ui::DialogCancelPressed()) cancelled = true;
      ImGui::EndPopup();
    }
    first_ = false;
    ImGui::Render();
  }
  void Capture(bool value) { navigation_.SetCaptured(value); }
  int chosen = -1, focused = -1;
  bool cancelled = false;
 private:
  unsigned default_button_;
  bool generic_;
  ImGuiContext* context_;
  ui::ControllerNavigation navigation_;
  bool first_ = true;
};
void ImGuiBehavior() {
  {
    DialogFrames dialog(0); dialog.Capture(false); dialog.Frame(); dialog.Frame();
    dialog.Frame(X_INPUT_GAMEPAD_A); dialog.Frame(X_INPUT_GAMEPAD_B);
    Check(dialog.chosen == -1 && !dialog.cancelled,
        "noncapturing overlays cannot also consume guest A or B");
  }
  {
    DialogFrames dialog(0, true); dialog.Frame(); dialog.Frame();
    Check(dialog.focused == 0, "host message default focus overrides read-only text area");
    dialog.Frame(X_INPUT_GAMEPAD_A);
    Check(dialog.chosen == 0, "host message OK activates from fresh controller A");
  }
  {
    DialogFrames dialog(0, true); dialog.Frame(); dialog.Frame(); dialog.Frame(X_INPUT_GAMEPAD_B);
    Check(dialog.cancelled && dialog.chosen == -1, "host message B dismisses without activating OK");
  }
  {
    DialogFrames dialog(1);
    dialog.Frame(X_INPUT_GAMEPAD_A); dialog.Frame(X_INPUT_GAMEPAD_A);
    Check(dialog.chosen == -1, "A held when prompt opens cannot auto-accept it");
    dialog.Frame(); dialog.Frame();
    Check(dialog.focused == 1, "requested active_button gets real ImGui focus");
    dialog.Frame(X_INPUT_GAMEPAD_A);
    Check(dialog.chosen == 1, "fresh gamepad A activates requested default button");
  }
  {
    DialogFrames dialog(0);
    dialog.Frame(); dialog.Frame(); dialog.Frame();
    Check(dialog.focused == 0, "first button default is honored");
    dialog.Frame(X_INPUT_GAMEPAD_DPAD_RIGHT); dialog.Frame(); dialog.Frame();
    Check(dialog.focused == 1, "D-pad right moves real ImGui focus to other choice");
    dialog.Frame(X_INPUT_GAMEPAD_A);
    Check(dialog.chosen == 1, "A confirms navigated choice");
  }
  {
    DialogFrames dialog(0); dialog.Frame(); dialog.Frame();
    dialog.Frame(X_INPUT_GAMEPAD_B);
    Check(dialog.cancelled && dialog.chosen == -1, "explicit B cancels without selecting a title default");
    dialog.Frame(0, false);
    Check(!(ImGui::GetIO().BackendFlags & ImGuiBackendFlags_HasGamepad), "disconnect/focus loss clears controller backend");
    Check(!ImGui::IsKeyDown(ImGuiKey_GamepadFaceRight), "disconnect/focus loss releases host cancel key");
  }
  {
    DialogFrames dialog(0); dialog.Frame(); dialog.Frame();
    dialog.Frame(0, false); dialog.Frame(X_INPUT_GAMEPAD_A); dialog.Frame(X_INPUT_GAMEPAD_A);
    Check(dialog.chosen == -1, "held A after host focus returns waits for release");
    dialog.Frame(); dialog.Frame(X_INPUT_GAMEPAD_A);
    Check(dialog.chosen == 0, "fresh A after focus release can activate host prompt");
  }
  {
    DialogFrames dialog(0); dialog.Frame(); dialog.Frame(); dialog.Frame();
    dialog.Frame(0, true, 32767); dialog.Frame(); dialog.Frame();
    Check(dialog.focused == 1, "left stick can navigate real ImGui buttons");
  }
}
}
int main(int argc, char** argv) {
  try {
    rex::InitLogging();
    DriverRouting(); KeystrokeOnlyRelease(); SDLVirtualController(); ScriptClock(); ImGuiBehavior(); CompletionFailure(); DispatchWakeups();
    if (argc == 2 && std::string_view(argv[1]) == "--json-summary") {
      std::cout << "{\"fixture\":\"controller_ui\",\"status\":\"pass\",\"checks\":" << checks << "}\n";
    } else {
      std::cout << "Controller UI actual driver/script clock and ImGui focus/navigation PASS (" << checks << " checks)\n";
    }
    return 0;
  } catch (const std::exception& error) {
    std::cerr << "Controller UI regression: " << error.what() << '\n'; return 1;
  }
}
