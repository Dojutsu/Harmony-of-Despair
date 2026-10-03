// Opt-in native Linux presentation acceptance. Uses the real Xenos provider,
// native Window and presenter; never boots the guest title or changes its data.
#include "linux_graphics.h"

#include <atomic>
#include <chrono>
#include <cstdio>
#include <exception>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>
#include <thread>

#include <unistd.h>

#include <SDL3/SDL.h>
#include <fmt/format.h>
#include <rex/cvar.h>
#include <rex/logging.h>
#include <rex/system/gpu_plugin.h>
#include <rex/ui/vulkan/presenter.h>
#include <rex/ui/vulkan/provider.h>
#include <rex/ui/window.h>
#include <rex/ui/windowed_app_context_sdl.h>

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

class GraphicsTrace {
 public:
  explicit GraphicsTrace(const std::filesystem::path& path) : stream_(path) {
    if (!stream_) throw std::runtime_error("cannot open graphics JSONL trace");
  }
  void Event(std::string_view stage, std::string_view status, std::string_view detail = {}) {
    const auto line = fmt::format(
        "{{\"schema\":1,\"sequence\":{},\"pid\":{},\"stage\":{},\"status\":{},\"detail\":{}}}",
        ++sequence_, getpid(), JsonString(stage), JsonString(status), JsonString(detail));
    stream_ << line << '\n';
    stream_.flush();
    if (!stream_) throw std::runtime_error("cannot write graphics JSONL trace");
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

// Listener callbacks do no throwing/logging work and have no ReXApp hard-exit
// policy. The normal SDL loop and explicit ownership scope perform teardown.
class ProbeWindowListener final : public rex::ui::WindowListener {
 public:
  ProbeWindowListener(rex::ui::SDLWindowedAppContext& context, std::atomic<bool>& stopping)
      : context_(context), stopping_(stopping) {}
  void OnOpened(rex::ui::UISetupEvent&) noexcept override { ++opened; }
  void OnResize(rex::ui::UISetupEvent&) noexcept override { ++resized; }
  void OnGotFocus(rex::ui::UISetupEvent&) noexcept override { ++focused; }
  void OnLostFocus(rex::ui::UISetupEvent&) noexcept override { ++unfocused; }
  void OnClosing(rex::ui::UIEvent&) noexcept override {
    ++closing;
    stopping_.store(true, std::memory_order_release);
    context_.QuitFromUIThread();
  }
  unsigned opened = 0, resized = 0, focused = 0, unfocused = 0, closing = 0;
 private:
  rex::ui::SDLWindowedAppContext& context_;
  std::atomic<bool>& stopping_;
};

// The scheduler is joined before this scope is destroyed. Flush queued UI
// callbacks while every captured owner still exists, then detach before native
// window destruction and release presenter/device/provider before SDL teardown.
struct PresentationScope {
  rex::ui::SDLWindowedAppContext& context;
  std::unique_ptr<rex::system::IGraphicsSystem>& graphics;
  std::unique_ptr<rex::ui::Window>& window;
  bool context_initialized = false;
  bool finished = false;
  void Finish() {
    if (context_initialized) context.QuitFromUIThread();
    if (window) {
      window->SetPresenter(nullptr);
      window->RequestClose();
      Require(window->phase() == rex::ui::Window::Phase::kClosedOpenable,
              "native probe window did not close synchronously");
      window.reset();
    }
    if (graphics) {
      graphics->Shutdown();
      graphics.reset();
    }
    finished = true;
  }
  ~PresentationScope() {
    if (!finished) {
      try { Finish(); }
      catch (...) { std::fputs("graphics probe cleanup failed\n", stderr); }
    }
  }
};

void ObserveControllers(GraphicsTrace& trace) {
  if (!SDL_InitSubSystem(SDL_INIT_GAMEPAD)) {
    trace.Event("controller", "unavailable", SDL_GetError());
    return;
  }
  struct QuitGamepad {
    ~QuitGamepad() { SDL_QuitSubSystem(SDL_INIT_GAMEPAD); }
  } quit_gamepad;
  int count = 0;
  SDL_JoystickID* ids = SDL_GetGamepads(&count);
  struct FreeIds {
    SDL_JoystickID* ids;
    ~FreeIds() { SDL_free(ids); }
  } free_ids{ids};
  if (!ids) {
    trace.Event("controller", "unavailable", SDL_GetError());
    return;
  }
  trace.Event("controller", "enumerated", fmt::format("gamepads={}; read-only; no mapping or input synthesis", count));
  for (int i = 0; i < count; ++i) {
    const char* name = SDL_GetGamepadNameForID(ids[i]);
    trace.Event("controller-device", "observed",
                fmt::format("id={}; type={}; name={}", ids[i],
                            static_cast<int>(SDL_GetGamepadTypeForID(ids[i])), name ? name : "unknown"));
  }
}

}  // namespace

int RunLinuxGraphicsProbe(const std::filesystem::path& log_path) {
  if (!log_path.is_absolute()) {
    std::fputs("graphics probe requires an absolute runtime log path\n", stderr);
    return 2;
  }
  std::unique_ptr<GraphicsTrace> trace;
  std::string stage = "logging";
  bool logging_initialized = false;
  int result = 1;
  try {
    std::filesystem::create_directories(log_path.parent_path());
    trace = std::make_unique<GraphicsTrace>(log_path.string() + ".jsonl");
    trace->Event("process", "start", "native Harmony ELF; bounded real Xenos/Vulkan presentation; no title assets");
    char app_name[] = "harmonyrecomp";
    char* arguments[] = {app_name};
    rex::cvar::Init(1, arguments);
    rex::cvar::ApplyEnvironment();
    rex::cvar::SetFlagByName("headless", "false");
    rex::cvar::SetFlagByName("fullscreen", "false");
    rex::cvar::SetFlagByName("window_width", "960");
    rex::cvar::SetFlagByName("window_height", "540");
    rex::InitLoggingEarly();
    const auto log_string = log_path.string();
    rex::LogConfig logging;
    logging.log_to_console = true;
    logging.log_file = log_string.c_str();
    logging.default_level = spdlog::level::debug;
    rex::InitLogging(logging);
    logging_initialized = true;
    {
      rex::ui::SDLWindowedAppContext context;
      std::unique_ptr<rex::system::IGraphicsSystem> graphics;
      std::unique_ptr<rex::ui::Window> window;
      std::atomic<bool> stopping{false};
      // Queued callbacks may be drained by owners during exceptional teardown.
      // Their referenced state must therefore outlive that ownership scope.
      std::exception_ptr callback_failure;
      bool controllers_observed = false;
      std::chrono::steady_clock::time_point deadline;
      ProbeWindowListener listener(context, stopping);
      PresentationScope owners{context, graphics, window};
      stage = "sdl-video";
      trace->Event(stage, "begin");
      Require(context.Initialize(), "real SDL video context initialization failed");
      owners.context_initialized = true;
      const char* video_driver = SDL_GetCurrentVideoDriver();
      trace->Event(stage, "pass", video_driver ? video_driver : "unknown");

      stage = "gpu-plugin";
      trace->Event(stage, "begin", "existing Xenos Vulkan factory");
      graphics = rex::system::LoadGpuPlugin("xenos", "vulkan");
      Require(graphics != nullptr, "real Xenos Vulkan plugin failed to load");
      trace->Event(stage, "pass");
      stage = "renderer";
      trace->Event(stage, "begin", "standalone existing SetupPresentation API; no guest GPU/title boot");
      Require(graphics->SetupPresentation(&context) == X_STATUS_SUCCESS,
              "real Xenos Vulkan provider/presenter initialization failed");
      auto* provider = dynamic_cast<rex::ui::vulkan::VulkanProvider*>(graphics->provider());
      auto* presenter = dynamic_cast<rex::ui::vulkan::VulkanPresenter*>(graphics->presenter());
      Require(provider && provider->vulkan_instance() && provider->vulkan_device() && presenter,
              "Xenos did not expose the expected Vulkan provider/presenter");
      const auto& extensions = provider->vulkan_instance()->extensions();
      const auto& properties = provider->vulkan_device()->properties();
      trace->Event("vulkan-instance", "pass", fmt::format("surface={}; wayland={}; xcb={}",
          extensions.ext_KHR_surface, extensions.ext_KHR_wayland_surface, extensions.ext_KHR_xcb_surface));
      trace->Event("vulkan-device", "pass", fmt::format("name={}; vendor={:04x}; device={:04x}; api={}.{}.{}; graphics_queue={}",
          properties.deviceName, properties.vendorID, properties.deviceID,
          VK_VERSION_MAJOR(properties.apiVersion), VK_VERSION_MINOR(properties.apiVersion),
          VK_VERSION_PATCH(properties.apiVersion), provider->vulkan_device()->queue_family_graphics_compute()));
      trace->Event(stage, "pass", "existing provider/device/queues/presenter/shaders initialized");
      presenter->EnableStartupDiagnostics();

      stage = "window";
      trace->Event(stage, "begin", "windowed 960x540; existing native WindowSDL");
      window = rex::ui::Window::Create(context, "Harmony Linux L3 presentation probe", 960, 540);
      Require(window != nullptr, "native Harmony window allocation failed");
      window->SetFullscreen(false);
      window->SetTextInputActive(false);
      window->AddListener(&listener);
      Require(window->Open() && window->phase() == rex::ui::Window::Phase::kOpen,
              "native Harmony window creation/open failed");
      trace->Event(stage, "pass", fmt::format("pixels={}x{}; phase=open", window->GetActualPhysicalWidth(),
                                             window->GetActualPhysicalHeight()));

      stage = "surface";
      trace->Event(stage, "begin", "existing Window::SetPresenter native surface/Vulkan swapchain path");
      window->SetPresenter(presenter);
      const auto connected = presenter->GetStartupDiagnostics();
      Require(connected.surface_creations && connected.swapchain_creations,
              "real Vulkan surface/swapchain connection did not succeed");
      trace->Event(stage, "pass", fmt::format("surface_creations={}; swapchain_creations={}; last_vk_result={}",
          connected.surface_creations, connected.swapchain_creations, connected.last_vk_result));

      stage = "presentation";
      trace->Event(stage, "begin", "existing black clear/command submission/presentation; bounded three-second SDL event loop");
      std::atomic<bool> scheduler_failed{false};
      deadline = std::chrono::steady_clock::now() + std::chrono::seconds(3);
      {
        std::jthread scheduler([&](std::stop_token stop) noexcept {
          try {
            while (!stop.stop_requested() && !stopping.load(std::memory_order_acquire)) {
              if (!context.CallInUIThreadDeferred([&, presenter]() noexcept {
                if (stopping.load(std::memory_order_acquire)) return;
                try {
                  presenter->PaintFromUIThread(true);
                  const auto snapshot = presenter->GetStartupDiagnostics();
                  if (snapshot.presentations && !controllers_observed) {
                    trace->Event("first-frame", "presented", fmt::format("queue_submissions={}; presentations={}; last_vk_result={}",
                        snapshot.queue_submissions, snapshot.presentations, snapshot.last_vk_result));
                    ObserveControllers(*trace);
                    controllers_observed = true;
                  }
                  if (std::chrono::steady_clock::now() >= deadline) {
                    stopping.store(true, std::memory_order_release);
                    context.QuitFromUIThread();
                  }
                } catch (...) {
                  // Retain the exception without allocating inside a callback.
                  // The ordinary main C++ boundary reports it after the loop.
                  callback_failure = std::current_exception();
                  stopping.store(true, std::memory_order_release);
                  context.QuitFromUIThread();
                }
              })) break;
              std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
          } catch (...) {
            scheduler_failed.store(true, std::memory_order_release);
            stopping.store(true, std::memory_order_release);
            try { context.RequestDeferredQuit(); } catch (...) {}
          }
        });
        const int loop_result = context.RunMainMessageLoop();
        stopping.store(true, std::memory_order_release);
        scheduler.request_stop();
        scheduler.join();
        // Drain all callbacks before checking/throwing at the outer boundary.
        // Their captures are still alive and stopping prevents further paints.
        context.ExecutePendingFunctionsFromUIThread();
        Require(loop_result == 0, "SDL event loop failed");
      }
      Require(!scheduler_failed.load(std::memory_order_acquire), "bounded graphics scheduler failed");
      if (callback_failure) std::rethrow_exception(callback_failure);
      const auto presented = presenter->GetStartupDiagnostics();
      Require(presented.surface_creations && presented.swapchain_creations && presented.queue_submissions &&
                  presented.presentations && presented.last_vk_result >= 0,
              "real renderer did not successfully submit and present a frame");
      trace->Event(stage, "pass", fmt::format("surface_creations={}; swapchain_creations={}; queue_submissions={}; presentations={}; last_vk_result={}",
          presented.surface_creations, presented.swapchain_creations, presented.queue_submissions,
          presented.presentations, presented.last_vk_result));
      trace->Event("window-events", "observed", fmt::format("opened={}; resized={}; focused={}; unfocused={}",
          listener.opened, listener.resized, listener.focused, listener.unfocused));
      trace->Event("audio", "not-started", "presentation does not require the guest audio backend; no playback probe");

      stage = "shutdown";
      trace->Event(stage, "begin");
      owners.Finish();
      Require(!window && !graphics, "presentation owners remain after shutdown");
      trace->Event(stage, "pass", "presenter detached; native window closed/destroyed; graphics provider/device released normally");
    }
    trace->Event("sdl-teardown", "pass", "actual SDL context destroyed after native window/provider");
    result = 0;
    trace->Event("process", "exit", "exit_code=0; bounded actual presentation complete; no title/gameplay claim");
  } catch (const std::exception& error) {
    std::fprintf(stderr, "Harmony graphics failure at %s: %s\n", stage.c_str(), error.what());
    if (trace) {
      try {
        trace->Event(stage, "failure", error.what());
        trace->Event("process", "exit", "exit_code=1; controlled graphics failure");
      } catch (...) { std::fputs("graphics trace output failed\n", stderr); }
    }
  }
  if (logging_initialized) {
    rex::FlushLogging();
    rex::ShutdownLogging();
  }
  return result;
}

}  // namespace harmony
