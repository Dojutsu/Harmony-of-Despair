#include <rex/input/input_system.h>
#include <rex/input/scripted/scripted_input_driver.h>
#include <rex/logging.h>
#include <spdlog/sinks/ostream_sink.h>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <sys/stat.h>
#include <thread>
#include <unistd.h>

using namespace rex;
using namespace rex::input;
using scripted::ScriptedInputDriver;
namespace {
unsigned checks = 0;
void Check(bool condition, const char* message) {
  ++checks;
  if (!condition) throw std::runtime_error(message);
}
std::string Row(unsigned ms, unsigned buttons = 0) {
  return std::to_string(ms) + " " + std::to_string(buttons) + " 0 0 0 0 0 0\n";
}
struct PrivateFile {
  std::filesystem::path path;
  PrivateFile() {
    char name[] = "/tmp/rex-script-append-XXXXXX";
    const int fd = ::mkstemp(name);
    Check(fd >= 0, "create private regular script");
    ::close(fd); path = name;
  }
  ~PrivateFile() { std::error_code error; std::filesystem::remove(path, error); }
  void Write(const std::string& text) {
    std::ofstream out(path, std::ios::binary | std::ios::trunc); out << text;
    Check(bool(out), "write private fixture script");
  }
  void Append(const std::string& text) {
    std::ofstream out(path, std::ios::binary | std::ios::app); out << text;
    Check(bool(out), "append private fixture script");
  }
};
struct LogCapture {
  std::ostringstream stream;
  std::shared_ptr<spdlog::sinks::ostream_sink_mt> sink =
      std::make_shared<spdlog::sinks::ostream_sink_mt>(stream);
  LogCapture() { AddSink(sink); SetAllLevels(spdlog::level::debug); }
  ~LogCapture() { RemoveSink(sink); SetAllLevels(spdlog::level::info); }
  std::string Text() { FlushLogging(); return stream.str(); }
};
struct Driver {
  PrivateFile file;
  std::chrono::steady_clock::time_point now{};
  ScriptedInputDriver driver;
  DeviceId id{};
  explicit Driver(const std::string& text, bool live = true)
      : driver(file.path, [this] { return now; }, live) {
    file.Write(text);
    Check(driver.Setup() == X_STATUS_SUCCESS, "actual scripted driver setup");
    std::vector<DeviceInfo> devices; driver.EnumerateDevices(devices);
    Check(devices.size() == 1, "single synthetic controller enumeration"); id = devices[0].id;
  }
  X_INPUT_STATE State(unsigned ms, bool ui = false) {
    now = std::chrono::steady_clock::time_point{} + std::chrono::milliseconds(ms);
    X_INPUT_STATE state{};
    const auto result = ui ? driver.GetDeviceStateForUI(id, &state) : driver.GetDeviceState(id, &state);
    Check(result == X_ERROR_SUCCESS, "actual state poll succeeds"); return state;
  }
  void Expect(unsigned ms, unsigned buttons, unsigned packet, const char* message) {
    auto state = State(ms);
    Check(state.gamepad.buttons == buttons && state.packet_number == packet, message);
  }
};
void AppendAndPending() {
  Driver d(Row(0));
  d.Expect(0, 0, 1, "first guest poll selects initial row");
  d.file.Append(Row(500, 4096) + Row(750));
  d.Expect(249, 0, 1, "reload cadence does not select a future row early");
  d.Expect(250, 0, 1, "completed future press and release accepted transactionally");
  d.Expect(500, 4096, 2, "appended press keeps original first-guest clock");
  d.Expect(750, 0, 3, "appended release delivered with stable source packet");
  d.file.Append("1500 8192 0 0 0 0 0 0");
  d.Expect(1000, 0, 3, "complete-looking pending row needs newline commit");
  d.file.Append("\n" + Row(1750));
  d.Expect(1250, 0, 3, "pending tail becomes an atomic completed extension");
  d.Expect(1500, 8192, 4, "completed pending press delivered");
  d.Expect(1750, 0, 5, "completed pending release delivered");
  Driver cadence(Row(0)); cadence.State(0);
  cadence.file.Append(Row(500, 4096) + Row(750)); cadence.State(249);
  cadence.file.Write(Row(0));
  cadence.Expect(250, 0, 1, "before-cadence append was not accepted");
  cadence.Expect(500, 0, 1, "truncated unaccepted append cannot leave a latent press");
  Driver before(Row(0));
  before.file.Append(Row(500, 4096) + Row(750));
  Check(before.State(10000, true).packet_number == 0, "UI-only reload does not start script clock");
  before.Expect(20000, 0, 1, "later first guest poll still starts at zero");
  before.Expect(20500, 4096, 2, "UI-accepted future rows retain first-guest anchor");
  before.Expect(20750, 0, 3, "UI-accepted release reaches guest");
  Driver pair(Row(0)); pair.State(0);
  pair.file.Append(Row(1000, 4096));
  pair.Expect(250, 0, 1, "completed press without a release remains unpublished");
  pair.Expect(500, 0, 1, "missing release cannot publish a held button");
  pair.file.Append(Row(1500));
  pair.Expect(750, 0, 1, "completed neutral tail commits future pair");
  pair.Expect(1000, 4096, 2, "paired press is published only with its release");
  pair.Expect(1500, 0, 3, "paired release is retained");
  Driver late_pair(Row(0)); late_pair.State(0); late_pair.file.Append(Row(500, 4096));
  late_pair.Expect(250, 0, 1, "pending press-only extension remains unaccepted");
  late_pair.Expect(500, 0, 1, "missing release prevents press even at its due time");
  late_pair.file.Append(Row(1000));
  late_pair.Expect(750, 0, 1, "late release cannot revive an expired pending press");
  late_pair.Expect(1000, 0, 1, "expired unaccepted pair cannot replace last good state");
  Driver analog(Row(0)); analog.State(0);
  analog.file.Append("1000 0 255 0 20000 0 0 0\n1500 0 0 0 0 0 0 1\n");
  analog.Expect(250, 0, 1, "release must clear every control including right axis");
  Check(analog.State(1000).gamepad.left_trigger == 0, "invalid analog release cannot publish trigger");
}
void RejectedSnapshot(const std::string& replacement, const char* message) {
  Driver d(Row(0) + Row(500, 4096) + Row(1000));
  d.State(0); d.file.Write(replacement);
  d.Expect(250, 0, 1, message);
  d.Expect(500, 4096, 2, "rejected reload retains accepted future press");
  d.Expect(1000, 0, 3, "rejected reload cannot lose accepted release");
}
void Rejections() {
  const auto accepted = Row(0) + Row(500, 4096) + Row(1000);
  RejectedSnapshot(Row(0) + Row(500, 8192) + Row(1000), "accepted future prefix cannot change");
  RejectedSnapshot(Row(0), "truncation cannot replace accepted schedule");
  RejectedSnapshot(accepted + Row(1000, 8192), "nonmonotonic extension rejected");
  RejectedSnapshot(accepted + "1500 65536 0 0 0 0 0 0\n", "button bound enforced");
  RejectedSnapshot(accepted + "1500 0 256 0 0 0 0 0\n", "trigger bound enforced");
  RejectedSnapshot(accepted + "1500 0 0 0 -32769 0 0 0\n", "axis bound enforced");
  RejectedSnapshot(accepted + "3600001 0 0 0 0 0 0 0\n", "one-hour bound enforced");
  RejectedSnapshot(accepted + "1500 0 0 0 0 0 0 0 1\n", "exact eight integers enforced");
  RejectedSnapshot(accepted + "1500 0x1000 0 0 0 0 0 0\n", "decimal-only syntax enforced");
  RejectedSnapshot(accepted + std::string(scripted::Timeline::kMaximumBytes, '#'), "bounded file read enforced");
  Driver past(Row(0)); past.State(0); past.file.Append(Row(250, 4096) + Row(500));
  past.Expect(250, 0, 1, "appended row equal to current elapsed is not future");
  past.Expect(500, 0, 1, "late rejected row cannot activate later");
  Driver owned(accepted); owned.State(0);
  Check(::chmod(owned.file.path.c_str(), 0644) == 0, "create nonprivate fixture permissions");
  owned.Expect(250, 0, 1, "nonprivate reload retains accepted schedule");
  owned.Expect(500, 4096, 2, "nonprivate reload does not remove press");
  owned.Expect(1000, 0, 3, "nonprivate reload does not remove release");
  Driver linked(accepted); linked.State(0); PrivateFile target; target.Write(Row(0, 8192));
  Check(::unlink(linked.file.path.c_str()) == 0 &&
        ::symlink(target.path.c_str(), linked.file.path.c_str()) == 0, "replace path with symlink fixture");
  linked.Expect(250, 0, 1, "O_NOFOLLOW rejects symlink reload");
  linked.Expect(500, 4096, 2, "symlink cannot override accepted press");
  linked.Expect(1000, 0, 3, "symlink cannot override accepted release");
  Driver inode(accepted); inode.State(0); PrivateFile replacement; replacement.Write(accepted + Row(1500, 8192));
  std::filesystem::rename(replacement.path, inode.file.path);
  inode.Expect(250, 0, 1, "replacement inode rejected even with identical prefix");
  inode.Expect(1000, 0, 3, "replacement inode cannot replace release");
  inode.Expect(1500, 0, 3, "replacement inode cannot append actions");
  LogCapture logs;
  Driver errors(accepted); errors.State(0); errors.file.Append("1500 PRIVATE-CONTENT-SHOULD-NOT-LOG 0 0 0 0 0 0\n");
  errors.State(250); const auto first = logs.Text();
  errors.State(500); errors.State(750); errors.State(1000);
  Check(logs.Text() == first, "same bad reload reason logged once despite repeated cadence");
  Check(first.find("PRIVATE-CONTENT-SHOULD-NOT-LOG") == std::string::npos,
        "reload diagnostics contain no rejected file contents");
}
void MaximumRows() {
  Driver d(Row(0)); d.State(0); std::string extension;
  for (unsigned i = 1; i < scripted::Timeline::kMaximumFrames; ++i) extension += Row(i * 500);
  d.file.Append(extension); d.Expect(250, 0, 1, "4096 total rows accepted");
  d.file.Append(Row(4096 * 500, 8192));
  d.Expect(500, 0, 2, "4097th total row cannot replace accepted prefix");
  d.Expect(4095 * 500, 0, 4096, "maximum accepted source packet preserved");
  d.Expect(4096 * 500, 0, 4096, "over-limit extension remains rejected");
}
void SetupPolicy(const char* wrong_owner) {
  PrivateFile file; file.Write(Row(0));
  Check(::chmod(file.path.c_str(), 0644) == 0, "set nonprivate setup fixture");
  ScriptedInputDriver public_file(file.path, {}, true);
  Check(public_file.Setup() == X_STATUS_INVALID_PARAMETER, "live setup requires private permissions");
  Check(::chmod(file.path.c_str(), 0600) == 0, "restore private setup fixture");
  PrivateFile link; Check(::unlink(link.path.c_str()) == 0 && ::symlink(file.path.c_str(), link.path.c_str()) == 0,
                          "create setup symlink fixture");
  ScriptedInputDriver symlink(link.path, {}, true);
  Check(symlink.Setup() == X_STATUS_INVALID_PARAMETER, "live setup rejects symlink");
  file.Write("0 0 0 0 0 0 0 0");
  ScriptedInputDriver pending(file.path, {}, true);
  Check(pending.Setup() == X_STATUS_INVALID_PARAMETER, "live setup requires committed initial newline");
  file.Write("0 4096 0 0 0 0 0 0\n1000 0 0 0 0 0 0 0");
  ScriptedInputDriver partial_release(file.path, {}, true);
  Check(partial_release.Setup() == X_STATUS_INVALID_PARAMETER,
        "live setup cannot publish completed press with pending initial release");
  file.Write("0 0 255 0 0 0 0 0\n");
  ScriptedInputDriver held_trigger(file.path, {}, true);
  Check(held_trigger.Setup() == X_STATUS_INVALID_PARAMETER,
        "initial live release must neutralize analog controls too");
  // Static mode deliberately retains its original unterminated-row behavior and never reloads.
  Driver ordinary("0 4096 0 0 0 0 0 0", false); ordinary.Expect(0, 4096, 1, "ordinary static setup unchanged");
  ordinary.file.Write(Row(0, 8192)); ordinary.Expect(1000, 4096, 1, "ordinary static mode does not reload");
  if (wrong_owner) {
    struct stat st{};
    Check(::lstat(wrong_owner, &st) == 0 && S_ISREG(st.st_mode) && st.st_uid != ::geteuid(),
          "foreign-owner fixture is an actual differently owned regular file");
    ScriptedInputDriver foreign(wrong_owner, {}, true);
    Check(foreign.Setup() == X_STATUS_INVALID_PARAMETER, "live setup rejects actual foreign owner");
  } else {
    std::cout << "SKIP actual foreign-owner fixture (supply --wrong-owner path)\n";
  }
}
void DeliveryEvidence() {
  PrivateFile file; file.Write(Row(0)); auto now = std::chrono::steady_clock::time_point{};
  auto driver = std::make_unique<ScriptedInputDriver>(file.path, [&] { return now; }, true);
  Check(driver->Setup() == X_STATUS_SUCCESS, "delivery evidence uses actual append driver");
  InputSystem input(nullptr); input.AddDriver(std::move(driver));
  input.SetDeviceAssignment(std::make_unique<SlotAssignment>());
  LogCapture logs; X_INPUT_STATE state{};
  Check(input.GetState(0, &state) == X_ERROR_SUCCESS, "delivery clock starts on actual guest poll");
  Check(logs.Text().find("external_clock=true") != std::string::npos, "fixture clock is explicitly marked nonphysical");
  file.Append(Row(500, 4096) + Row(750) + Row(1000, 8192) + Row(1250));
  now += std::chrono::milliseconds(250); input.GetStateForUI(0, &state);
  now += std::chrono::milliseconds(250); input.SetUIControllerCapture(true);
  Check(input.GetStateForUI(0, &state) == X_ERROR_SUCCESS && state.gamepad.buttons == 4096,
        "appended raw UI press is observed");
  Check(logs.Text().find("Offline UI controller transition: elapsed_ms=500 packet=2 buttons=1000") != std::string::npos &&
        logs.Text().find("Offline controller transition: elapsed_ms=500") == std::string::npos,
        "UI-only append sampling cannot claim guest delivery");
  Check(input.GetState(0, &state) == X_ERROR_SUCCESS && !state.gamepad.buttons,
        "actual InputSystem masks appended modal press");
  Check(logs.Text().find("Offline controller UI-consumed: elapsed_ms=500 packet=2 buttons=0000") != std::string::npos &&
        logs.Text().find("Offline controller transition: elapsed_ms=500") == std::string::npos,
        "masked appended row reports effective neutral UI consumption");
  input.SetUIControllerCapture(false);
  now += std::chrono::milliseconds(250); input.GetState(0, &state);
  now += std::chrono::milliseconds(250);
  Check(input.GetState(0, &state) == X_ERROR_SUCCESS && state.gamepad.buttons == 8192,
        "fresh appended press reaches guest after explicit release");
  Check(logs.Text().find("Offline controller transition: elapsed_ms=1000 packet=4 buttons=2000") != std::string::npos,
        "effective appended guest press uses exact source packet evidence");
  now += std::chrono::milliseconds(250);
  Check(input.GetState(0, &state) == X_ERROR_SUCCESS && !state.gamepad.buttons,
        "effective appended guest release reaches guest");
  Check(logs.Text().find("Offline controller transition: elapsed_ms=1250 packet=5 buttons=0000") != std::string::npos,
        "effective appended release has distinct guest delivery evidence");
}
void LiveHelperRun(const char* path) {
  auto driver = std::make_unique<ScriptedInputDriver>(path, ScriptedInputDriver::Clock{}, true);
  Check(driver->Setup() == X_STATUS_SUCCESS, "real-clock helper driver setup");
  InputSystem input(nullptr); input.AddDriver(std::move(driver));
  input.SetDeviceAssignment(std::make_unique<SlotAssignment>());
  SetAllLevels(spdlog::level::debug);
  X_INPUT_STATE state{}; input.GetState(0, &state); FlushLogging();
  std::cout << "READY actual append helper clock\n" << std::flush;
  const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(8);
  bool press = false, release = false;
  while (std::chrono::steady_clock::now() < deadline && !release) {
    Check(input.GetState(0, &state) == X_ERROR_SUCCESS, "actual helper guest state poll");
    if (state.gamepad.buttons == 4096 && state.packet_number == 2) press = true;
    if (press && !state.gamepad.buttons && state.packet_number == 3) release = true;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
  FlushLogging();
  Check(press && release, "real helper future press and release both delivered to actual guest route");
}
}  // namespace
int main(int argc, char** argv) {
  try {
    if (argc == 3 && std::string(argv[1]) == "--helper-run") {
      LiveHelperRun(argv[2]); std::cout << "PASS actual helper guest delivery\n"; return 0;
    }
    const char* wrong_owner = nullptr;
    if (argc == 3 && std::string(argv[1]) == "--wrong-owner") wrong_owner = argv[2];
    else if (argc != 1) throw std::runtime_error("usage: scripted_input_reload_test [--wrong-owner path]");
    AppendAndPending(); Rejections(); MaximumRows(); SetupPolicy(wrong_owner); DeliveryEvidence();
    std::cout << "PASS " << checks << " actual scripted append checks\n"; return 0;
  } catch (const std::exception& error) {
    std::cerr << "FAIL after " << checks << ": " << error.what() << '\n'; return 1;
  }
}
