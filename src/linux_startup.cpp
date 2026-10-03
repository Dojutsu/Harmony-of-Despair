// Opt-in native Linux runtime diagnostic. No XEX/assets, guest execution,
// presentation, controller, audio or network service is started here.
#include "linux_startup.h"

#include <array>
#include <atomic>
#include <cstdio>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>
#include <thread>
#include <utility>

#include <signal.h>
#include <unistd.h>

#include <fmt/format.h>
#include <rex/filesystem.h>
#include <rex/kernel/init.h>
#include <rex/logging.h>
#include <rex/memory.h>
#include <rex/platform/dynlib.h>
#include <rex/runtime.h>
#include <rex/system/function_dispatcher.h>
#include <rex/system/gpu_plugin.h>
#include <rex/system/kernel_state.h>
#include <rex/system/thread_state.h>

namespace harmony {
// SDK status macros retain their historical unqualified X_STATUS cast.
using rex::X_STATUS;
namespace {

std::string JsonString(std::string_view value) {
  std::string result = "\"";
  for (unsigned char ch : value) {
    if (ch == '"' || ch == '\\') {
      result += '\\';
      result += static_cast<char>(ch);
    } else if (ch < 0x20) {
      result += fmt::format("\\u{:04x}", ch);
    } else {
      result += static_cast<char>(ch);
    }
  }
  return result + '"';
}

class StartupTrace {
 public:
  explicit StartupTrace(const std::filesystem::path& path) : stream_(path) {
    if (!stream_) throw std::runtime_error("cannot open startup JSONL trace");
  }
  void Event(std::string_view stage, std::string_view status, std::string_view detail = {}) {
    const auto line = fmt::format(
        "{{\"schema\":1,\"sequence\":{},\"pid\":{},\"stage\":{},\"status\":{},\"detail\":{}}}",
        ++sequence_, getpid(), JsonString(stage), JsonString(status), JsonString(detail));
    stream_ << line << '\n';
    stream_.flush();
    if (!stream_) throw std::runtime_error("cannot write startup JSONL trace");
    std::puts(line.c_str());
    std::fflush(stdout);
  }
 private:
  std::ofstream stream_;
  unsigned sequence_ = 0;
};

void Require(bool condition, std::string_view reason) {
  if (!condition) throw std::runtime_error(std::string(reason));
}

void ProbeVm(rex::Runtime& runtime) {
  using namespace rex::memory;
  const auto page = page_size();
  void* mapping = AllocFixed(nullptr, page * 3, AllocationType::kReserve, PageAccess::kNoAccess);
  Require(mapping != nullptr, "host VM reservation failed");
  struct Release {
    void* address;
    size_t length;
    ~Release() { DeallocFixed(address, length, DeallocationType::kRelease); }
  } release{mapping, page * 3};
  Require(reinterpret_cast<uintptr_t>(mapping) % page == 0, "host page alignment failed");
  auto* middle = static_cast<uint8_t*>(mapping) + page;
  Require(AllocFixed(middle, page, AllocationType::kCommit, PageAccess::kReadWrite) == middle,
          "commit inside reservation failed");
  middle[0] = 0x42;
  Require(middle[0] == 0x42, "committed-page read/write failed");
  Require(Protect(middle, page, PageAccess::kExecuteReadOnly), "RW to RX transition failed");
  size_t length = 0;
  PageAccess access;
  Require(QueryProtect(middle, length, access) && access == PageAccess::kExecuteReadOnly,
          "RX protection query failed");
  Require(QueryProtect(mapping, length, access) && access == PageAccess::kNoAccess,
          "leading guard page lost its protection");
  Require(QueryProtect(middle + page, length, access) && access == PageAccess::kNoAccess,
          "trailing guard page lost its protection");
  Require(Protect(middle, page, PageAccess::kReadOnly), "RX to R transition failed");

  auto* memory = runtime.memory();
  const auto guest = memory->SystemHeapAlloc(4096, 4096);
  Require(guest != 0, "guest system heap allocation failed");
  struct GuestRelease {
    Memory* memory;
    uint32_t guest;
    ~GuestRelease() { memory->SystemHeapFree(guest); }
  } guest_release{memory, guest};
  auto* translated = memory->TranslateVirtual(guest);
  translated[0] = 0x5A;
  Require(translated[0] == 0x5A, "guest virtual memory round trip failed");
}

void ProbeTls(rex::Runtime& runtime) {
  using rex::runtime::ThreadState;
  Require(ThreadState::Get() == nullptr, "main thread already has a guest binding");
  {
    ThreadState main_state(1, 0, 0, runtime.memory());
    ThreadState::Bind(&main_state);
    std::atomic<bool> worker_ok{false};
    std::thread worker([&] {
      bool ok = ThreadState::Get() == nullptr;
      {
        ThreadState state(2, 0, 0, runtime.memory());
        ThreadState::Bind(&state);
        ok = ok && ThreadState::Get() == &state && ThreadState::GetThreadID() == 2;
      }
      worker_ok = ok && ThreadState::Get() == nullptr;
    });
    worker.join();
    Require(worker_ok && ThreadState::Get() == &main_state,
            "per-thread guest state isolation or cleanup failed");
  }
  Require(ThreadState::Get() == nullptr, "main guest state cleanup failed");
}

void ProbeNativeModule(rex::Runtime& runtime) {
  const auto metadata = runtime.kernel_state()->FindRecompiledModule("data/player_dll/dllAlucard.dll");
  Require(metadata.has_value(), "actual Alucard guest module registry entry missing");
  rex::platform::DynamicLibrary library;
  const auto path = rex::platform::ResolveModuleLibraryPath(metadata->shared_lib_name);
  Require(library.Load(path, rex::platform::SymbolResolution::kImmediate),
          "actual Alucard native ELF failed to load");
  auto get_info = library.GetSymbol<const rex::PPCImageInfo* (*)()>("ReXModule_GetImageInfo");
  auto register_functions = library.GetSymbol<rex::runtime::FunctionDispatcher::RegisterFn>(
      "ReXModule_Register");
  Require(get_info && register_functions, "native module registration exports missing");
  const auto* info = get_info();
  Require(info != nullptr, "native module returned no image information");
  auto* dispatcher = runtime.function_dispatcher();
  Require(dispatcher->InitializeFunctionTable(info->code_base, info->code_size,
      info->image_base, info->image_size, info->function_table_base),
      "native module dispatch table initialization failed");
  const std::string module_id = metadata->guest_path;
  // Remove every recorded host function pointer before dlclose, including on a
  // later check failure. No entry point or other guest function is executed.
  struct RegistrationCleanup {
    rex::runtime::FunctionDispatcher* dispatcher;
    std::string id;
    ~RegistrationCleanup() { dispatcher->UnregisterModule(id); }
  } cleanup{dispatcher, module_id};
  dispatcher->RegisterModule(module_id, info->code_base, register_functions);
  Require(dispatcher->GetFunction(info->code_base) != nullptr,
          "actual Alucard registration did not populate its first guest function");
}

}  // namespace

int RunLinuxStartupProbe(const rex::PPCImageInfo& image, const std::filesystem::path& log_path) {
  if (!log_path.is_absolute()) {
    std::fputs("startup probe requires an absolute runtime log path\n", stderr);
    return 2;
  }
  std::unique_ptr<StartupTrace> trace;
  std::string stage = "logging";
  bool logging_initialized = false;
  int result = 1;
  try {
    std::filesystem::create_directories(log_path.parent_path());
    trace = std::make_unique<StartupTrace>(log_path.string() + ".jsonl");
    trace->Event("process", "start", "native Harmony ELF; explicit asset-free startup probe");
    rex::InitLoggingEarly();
    const auto log_string = log_path.string();
    rex::LogConfig logging;
    logging.log_to_console = true;
    logging.log_file = log_string.c_str();
    logging.default_level = spdlog::level::debug;
    rex::InitLogging(logging);
    logging_initialized = true;
    {
      rex::Runtime runtime(std::filesystem::path{});
      stage = "runtime";
      trace->Event(stage, "begin");
      rex::RuntimeConfig config;
      config.tool_mode = true;
      config.kernel_init = rex::kernel::InitializeKernel;
      Require(runtime.Setup(image, std::move(config)) == X_STATUS_SUCCESS,
              "real runtime and actual Harmony dispatch initialization failed");
      Require(runtime.memory() && runtime.function_dispatcher() && runtime.kernel_state(),
              "runtime subsystem missing after setup");
      if (image.register_modules) image.register_modules(runtime.kernel_state());
      trace->Event(stage, "pass", "actual Harmony image table and kernel modules initialized; no XEX loaded");

      stage = "vm";
      trace->Event(stage, "begin");
      ProbeVm(runtime);
      trace->Event(stage, "pass", "guest allocation; host reservation/commit; aligned RW to RX to R; guarded pages");
      stage = "tls";
      trace->Event(stage, "begin");
      ProbeTls(runtime);
      trace->Event(stage, "pass", "real ThreadState initialization, isolation and destructor cleanup on two threads");

      stage = "fault-routing";
      trace->Event(stage, "begin");
      for (const auto [number, name] : std::array<std::pair<int, const char*>, 4>{{
          {SIGSEGV, "SIGSEGV"}, {SIGBUS, "SIGBUS"}, {SIGILL, "SIGILL"}, {SIGFPE, "SIGFPE"}}}) {
        struct sigaction action {};
        Require(sigaction(number, nullptr, &action) == 0, "cannot inspect startup signal disposition");
        const bool handled = action.sa_handler != SIG_DFL && action.sa_handler != SIG_IGN;
        trace->Event(name, handled ? "handler-installed" : "default-disposition",
                     "installation only; synthetic fault/guest unwind acceptance is separate");
      }
      trace->Event(stage, "initialized", "no signal is injected or swallowed by the startup probe");

      stage = "native-module";
      trace->Event(stage, "begin");
      ProbeNativeModule(runtime);
      trace->Event(stage, "pass", "actual Alucard ELF exports/metadata/dispatch registration/unregistration; no guest execution");

      stage = "platform-boundary";
      trace->Event(stage, "begin");
      auto graphics = rex::system::LoadGpuPlugin("xenos", "vulkan");
      Require(graphics != nullptr, "Xenos platform plugin failed to load/create");
      trace->Event(stage, "reached", "real Xenos plugin loaded/created; renderer Setup/window/display/input/audio deliberately not entered");
      graphics.reset();

      stage = "shutdown";
      trace->Event(stage, "begin");
      runtime.Shutdown();
      Require(rex::Runtime::instance() == nullptr, "runtime global remains after shutdown");
      trace->Event(stage, "pass", "controlled runtime teardown");
    }
    result = 0;
    trace->Event("process", "exit", "exit_code=0; bounded native startup complete; no game/playability claim");
  } catch (const std::exception& error) {
    std::fprintf(stderr, "Harmony startup failure at %s: %s\n", stage.c_str(), error.what());
    if (trace) {
      try {
        trace->Event(stage, "failure", error.what());
        trace->Event("process", "exit", "exit_code=1; controlled startup failure");
      } catch (...) {
        std::fputs("startup trace output failed\n", stderr);
      }
    }
  }
  if (logging_initialized) {
    rex::FlushLogging();
    rex::ShutdownLogging();
  }
  return result;
}
}  // namespace harmony
