/**
 * @file        ui/windowed_app_context_sdl.cpp
 * @brief       SDL3 implementation of the windowed app UI loop context
 *
 * @copyright   Copyright (c) 2026 Tom Clay <tomc@tctechstuff.com>
 *              All rights reserved.
 *
 * @license     BSD 3-Clause License
 *              See LICENSE file in the project root for full license text.
 */

#include <rex/ui/windowed_app_context_sdl.h>

#include <cstdlib>
#include <csignal>
#include <string>
#include <vector>

#include <SDL3/SDL.h>

#include <rex/cvar.h>
#include <rex/logging.h>
#include <rex/platform.h>
#include <rex/system/flags.h>
#include <rex/ui/flags.h>
#include <rex/ui/window_sdl.h>

namespace rex::ui {

#if REX_PLATFORM_GNU_LINUX
namespace {
volatile std::sig_atomic_t headless_termination_requested = 0;

void HandleHeadlessTerminationSignal(int) {
  headless_termination_requested = 1;
}
}  // namespace
#endif

SDLWindowedAppContext::~SDLWindowedAppContext() {
  if (event_watch_registered_) {
    SDL_RemoveEventWatch(WatchEvent, this);
  }
  // Execute leftover pending functions before the loop machinery goes away,
  // mirroring the shutdown contract documented in WindowedAppContext.
  ExecutePendingFunctionsFromUIThread();
  if (initialized_subsystems_) {
    SDL_QuitSubSystem(initialized_subsystems_);
  }
#if REX_PLATFORM_GNU_LINUX
  if (signal_handlers_installed_) {
    std::signal(SIGINT, previous_sigint_handler_);
    std::signal(SIGTERM, previous_sigterm_handler_);
  }
#endif
}

bool SDLWindowedAppContext::Initialize() {
#if REX_PLATFORM_GNU_LINUX
  headless_ = REXCVAR_GET(headless);
  if (headless_) {
    headless_termination_requested = 0;
    previous_sigint_handler_ = std::signal(SIGINT, HandleHeadlessTerminationSignal);
    if (previous_sigint_handler_ == SIG_ERR) {
      REXLOG_ERROR("Failed to install headless SIGINT handler");
      return false;
    }
    previous_sigterm_handler_ = std::signal(SIGTERM, HandleHeadlessTerminationSignal);
    if (previous_sigterm_handler_ == SIG_ERR) {
      std::signal(SIGINT, previous_sigint_handler_);
      REXLOG_ERROR("Failed to install headless SIGTERM handler");
      return false;
    }
    signal_handlers_installed_ = true;
    SDL_SetHint(SDL_HINT_AUDIO_DRIVER, "dummy");
    initialized_subsystems_ = SDL_INIT_EVENTS;
    REXLOG_INFO("Headless SDL mode: events only; audio output uses SDL dummy driver");
  }
#endif

  if (!headless_) {
    // Picked before SDL_InitSubSystem, long before a graphics instance can say
    // which surface extensions it has, so the cvar is the escape hatch.
    std::string requested_driver = REXCVAR_GET(video_driver);
#if REX_PLATFORM_MAC
    // macOS presents via a CAMetalLayer surface obtained from the Cocoa driver.
    if (requested_driver.empty()) {
      requested_driver = "cocoa";
    }
#endif
    if (!requested_driver.empty()) {
      SDL_SetHint(SDL_HINT_VIDEO_DRIVER, requested_driver.c_str());
    }
    initialized_subsystems_ = SDL_INIT_VIDEO;
  }
  if (!SDL_InitSubSystem(initialized_subsystems_)) {
    REXLOG_ERROR("SDL_InitSubSystem({:#x}) failed: {}", initialized_subsystems_, SDL_GetError());
    return false;
  }
  if (!headless_) {
    const char* video_driver_in_use = SDL_GetCurrentVideoDriver();
    REXLOG_INFO("SDL video driver: {}", video_driver_in_use ? video_driver_in_use : "unknown");
  }
  uint32_t first = SDL_RegisterEvents(2);
  if (first == 0) {
    REXLOG_ERROR("SDL_RegisterEvents failed: {}", SDL_GetError());
    return false;
  }
  wakeup_event_type_ = first;
  paint_event_type_ = first + 1;
  if (!SDL_AddEventWatch(WatchEvent, this)) {
    REXLOG_ERROR("SDL_AddEventWatch failed: {}", SDL_GetError());
    return false;
  }
  event_watch_registered_ = true;
  return true;
}

void SDLWindowedAppContext::NotifyUILoopOfPendingFunctions() {
  // SDL_PushEvent is thread-safe by SDL contract.
  SDL_Event event{};
  event.type = wakeup_event_type_;
  SDL_PushEvent(&event);
}

void SDLWindowedAppContext::PlatformQuitFromUIThread() {
  // RunMainMessageLoop re-checks HasQuitFromUIThread after every event; a
  // wakeup guarantees SDL_WaitEvent returns promptly if the queue is empty.
  NotifyUILoopOfPendingFunctions();
}

int SDLWindowedAppContext::RunMainMessageLoop() {
  while (!HasQuitFromUIThread()) {
#if REX_PLATFORM_GNU_LINUX
    if (headless_ && headless_termination_requested) {
      REXLOG_INFO("Headless process received a termination signal; shutting down cleanly");
      QuitFromUIThread();
      continue;
    }
#endif
    SDL_Event event;
#if REX_PLATFORM_GNU_LINUX
    if (headless_) {
      if (SDL_WaitEventTimeout(&event, 250)) {
        ProcessEvent(event);
      }
      continue;
    }
#endif
    if (!SDL_WaitEvent(&event)) {
      REXLOG_ERROR("SDL_WaitEvent failed: {}", SDL_GetError());
      return EXIT_FAILURE;
    }
    ProcessEvent(event);
  }
  return EXIT_SUCCESS;
}

void SDLWindowedAppContext::ProcessEvent(SDL_Event& event) {
  if (event.type == wakeup_event_type_) {
    ExecutePendingFunctionsFromUIThread();
    return;
  }
  if (event.type == paint_event_type_) {
    // Cocoa may enqueue its quit request behind an already queued paint. Once
    // termination has been requested, CAMetalLayer may stop supplying
    // drawables, so entering the paint first can block forever in
    // -[CAMetalLayer nextDrawable] and prevent the quit event from being
    // processed. Give an already queued quit request priority over rendering.
    // Pump explicitly because a continuous stream of custom paint events can
    // otherwise keep SDL_WaitEvent from returning to Cocoa to collect the
    // application-menu quit request.
    SDL_PumpEvents();
    SDL_Event quit_event{};
    if (SDL_PeepEvents(&quit_event, 1, SDL_GETEVENT, SDL_EVENT_QUIT, SDL_EVENT_QUIT) > 0) {
      ProcessEvent(quit_event);
      if (HasQuitFromUIThread()) {
        return;
      }
    }
    if (WindowSDL* window = GetWindow(event.user.windowID)) {
      window->HandlePaintEvent();
    }
    return;
  }
  if (event.type >= SDL_EVENT_WINDOW_FIRST && event.type <= SDL_EVENT_WINDOW_LAST) {
    if (WindowSDL* window = GetWindow(event.window.windowID)) {
      window->HandleWindowEvent(event);
    }
    return;
  }
  switch (event.type) {
    case SDL_EVENT_QUIT:
      if (synchronously_handled_quit_events_ != 0) {
        --synchronously_handled_quit_events_;
      } else if (headless_) {
        QuitFromUIThread();
      } else {
        ProcessQuitRequest();
      }
      break;
    case SDL_EVENT_KEY_DOWN:
    case SDL_EVENT_KEY_UP: {
      if (WindowSDL* window = GetWindow(event.key.windowID)) {
        window->HandleKeyEvent(event);
      }
      break;
    }
    case SDL_EVENT_TEXT_INPUT: {
      if (WindowSDL* window = GetWindow(event.text.windowID)) {
        window->HandleTextInputEvent(event);
      }
      break;
    }
    case SDL_EVENT_MOUSE_MOTION: {
      if (WindowSDL* window = GetWindow(event.motion.windowID)) {
        window->HandleMouseEvent(event);
      }
      break;
    }
    case SDL_EVENT_MOUSE_BUTTON_DOWN:
    case SDL_EVENT_MOUSE_BUTTON_UP: {
      if (WindowSDL* window = GetWindow(event.button.windowID)) {
        window->HandleMouseEvent(event);
      }
      break;
    }
    case SDL_EVENT_MOUSE_WHEEL: {
      if (WindowSDL* window = GetWindow(event.wheel.windowID)) {
        window->HandleMouseEvent(event);
      }
      break;
    }
    case SDL_EVENT_DROP_FILE: {
      if (WindowSDL* window = GetWindow(event.drop.windowID)) {
        window->HandleDropEvent(event);
      }
      break;
    }
    default:
      break;
  }
}

bool SDLCALL SDLWindowedAppContext::WatchEvent(void* userdata, SDL_Event* event) {
  auto* context = static_cast<SDLWindowedAppContext*>(userdata);
  if (event->type == SDL_EVENT_QUIT && SDL_IsMainThread() && context->IsInUIThread()) {
    // Cocoa stops making Metal drawables available as part of its termination
    // request. Handle the request synchronously while SDL is queueing it,
    // before rendering can enter another blocking nextDrawable call.
    ++context->synchronously_handled_quit_events_;
#if REX_PLATFORM_GNU_LINUX
    if (context->headless_) {
      context->QuitFromUIThread();
    } else
#endif
    {
      context->ProcessQuitRequest();
    }
  }
  return true;
}

void SDLWindowedAppContext::ProcessQuitRequest() {
  // Use the normal close-request path rather than terminating the message loop
  // directly. Window listeners use OnClosing to stop guest, audio and GPU
  // threads; bypassing it leaves the process hanging during teardown.
  std::vector<SDL_WindowID> window_ids;
  window_ids.reserve(windows_.size());
  for (const auto& [id, window] : windows_) {
    (void)window;
    window_ids.push_back(id);
  }
  for (SDL_WindowID id : window_ids) {
    if (WindowSDL* window = GetWindow(id)) {
      SDL_Event close_event{};
      close_event.type = SDL_EVENT_WINDOW_CLOSE_REQUESTED;
      close_event.window.windowID = id;
      window->HandleWindowEvent(close_event);
    }
  }
}

}  // namespace rex::ui
