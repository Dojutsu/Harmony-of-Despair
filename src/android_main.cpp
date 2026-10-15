// harmonyrecomp - Android entry point.
//
// SDLActivity (Java) loads libmain.so and calls SDL_main through SDL's JNI
// bridge; SDL_main.h renames main() to SDL_main for this translation unit.
// Android apps receive no command line, so the arguments the PC launchers pass
// are assembled here: fixed defaults for the Thor, plus optional extra lines
// from <game root>/android-args.txt so flags can change without a rebuild.

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <dlfcn.h>
#include <jni.h>

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <mutex>
#include <string>
#include <system_error>
#include <vector>

#include <rex/main_android.h>
#include <rex/system/xam/title_presence.h>
#include <rex/ui/windowed_app.h>

namespace {

// Game data lives where the Winlator tests left it; the app reads it through
// "All files access" (MANAGE_EXTERNAL_STORAGE).
constexpr const char* kDefaultGameRoot = "/sdcard/HoD";

std::vector<std::string> BuildArguments(const std::vector<std::string>& java_args) {
  std::vector<std::string> args;
  args.emplace_back("harmonyrecomp");

  std::filesystem::path game_root = kDefaultGameRoot;
  if (const char* env_root = std::getenv("HARMONY_GAME_ROOT"); env_root && *env_root) {
    game_root = env_root;
  }

  // Flags from the Java launcher (player name, online mode, invite code) and
  // from the optional text file next to the game data.
  const std::filesystem::path extra_args_file = game_root / "android-args.txt";
  std::vector<std::string> extra(java_args);
  if (std::ifstream in(extra_args_file); in) {
    std::string line;
    while (std::getline(in, line)) {
      while (!line.empty() && (line.back() == '\r' || line.back() == ' ')) line.pop_back();
      if (line.empty() || line[0] == '#') continue;
      extra.push_back(line);
    }
  }

  auto has_flag = [&](const char* name) {
    const std::string prefix = std::string("--") + name;
    for (const auto& e : extra) {
      if (e.rfind(prefix, 0) == 0) return true;
    }
    return false;
  };

  const std::string data_root = (game_root / "game-data").string();
  if (!has_flag("game_data_root")) args.push_back("--game_data_root=" + data_root);
  if (!has_flag("update_data_root")) args.push_back("--update_data_root=" + data_root);
  if (!has_flag("user_name")) args.emplace_back("--user_name=Thor");
  if (!has_flag("log_flush_interval")) args.emplace_back("--log_flush_interval=1");
  // Arm Mali GPUs (Pixel, many Samsung phones) have no geometry shaders or
  // wireframe fill; the runtime has fallback paths for both (as on macOS), so
  // allow those GPUs instead of refusing to start. GPUs that have the features
  // (the Thor's Adreno) still use them.
  if (!has_flag("vulkan_require_geometry_shader")) {
    args.emplace_back("--vulkan_require_geometry_shader=false");
  }
  if (!has_flag("vulkan_require_fill_mode_non_solid")) {
    args.emplace_back("--vulkan_require_fill_mode_non_solid=false");
  }
  // Mali also lacks shader stores from the vertex stage; only rare draws that
  // write memory from a vertex shader need them, and those are skipped.
  if (!has_flag("vulkan_require_vertex_pipeline_stores_and_atomics")) {
    args.emplace_back("--vulkan_require_vertex_pipeline_stores_and_atomics=false");
  }
  if (!has_flag("log_file")) {
    // Next to the game data, so the log can be pulled over adb without root.
    std::error_code ec;
    const std::filesystem::path log_dir = game_root / "android-logs";
    std::filesystem::create_directories(log_dir, ec);
    args.push_back("--log_file=" + (log_dir / "harmonyrecomp.log").string());
  }
  for (auto& e : extra) args.push_back(std::move(e));
  return args;
}

}  // namespace

// Called by the Java VM when SDLActivity loads libmain.so. Records the VM and
// the app's HTTP bridge class so the runtime's session-directory client can
// call into Java from any native thread.
extern "C" JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void*) {
  JNIEnv* env = nullptr;
  if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) return JNI_ERR;
  rex::SetAndroidJavaVM(vm);
  jclass bridge = env->FindClass("net/dojutsu/harmony/HarmonyHttp");
  if (bridge) {
    rex::SetAndroidHttpBridgeClass(env->NewGlobalRef(bridge));
    env->DeleteLocalRef(bridge);
  } else {
    env->ExceptionClear();
  }
  return JNI_VERSION_1_6;
}

// On-screen touch controls (TouchControls.java) drive a virtual SDL gamepad,
// which the runtime's input driver picks up like any connected controller.
namespace {
std::mutex touch_mutex;
SDL_JoystickID touch_id = 0;
SDL_Joystick* touch_pad = nullptr;
}  // namespace

extern "C" JNIEXPORT jboolean JNICALL
Java_net_dojutsu_harmony_TouchControls_nativeAttach(JNIEnv*, jclass) {
  std::lock_guard lock(touch_mutex);
  if (touch_pad) return JNI_TRUE;
  // Too early: the game has not started SDL's gamepad support yet.
  if (!SDL_WasInit(SDL_INIT_GAMEPAD)) return JNI_FALSE;
  SDL_VirtualJoystickDesc desc;
  SDL_INIT_INTERFACE(&desc);
  desc.type = SDL_JOYSTICK_TYPE_GAMEPAD;
  desc.naxes = SDL_GAMEPAD_AXIS_COUNT;
  desc.nbuttons = SDL_GAMEPAD_BUTTON_COUNT;
  desc.name = "Harmony touch controls";
  touch_id = SDL_AttachVirtualJoystick(&desc);
  if (!touch_id) return JNI_FALSE;
  touch_pad = SDL_OpenJoystick(touch_id);
  if (!touch_pad) {
    SDL_DetachVirtualJoystick(touch_id);
    touch_id = 0;
    return JNI_FALSE;
  }
  return JNI_TRUE;
}

extern "C" JNIEXPORT void JNICALL
Java_net_dojutsu_harmony_TouchControls_nativeDetach(JNIEnv*, jclass) {
  std::lock_guard lock(touch_mutex);
  if (!touch_pad) return;
  SDL_CloseJoystick(touch_pad);
  SDL_DetachVirtualJoystick(touch_id);
  touch_pad = nullptr;
  touch_id = 0;
}

extern "C" JNIEXPORT void JNICALL
Java_net_dojutsu_harmony_TouchControls_nativeSetButton(JNIEnv*, jclass, jint button, jboolean down) {
  std::lock_guard lock(touch_mutex);
  if (touch_pad) SDL_SetJoystickVirtualButton(touch_pad, button, down == JNI_TRUE);
}

extern "C" JNIEXPORT void JNICALL
Java_net_dojutsu_harmony_TouchControls_nativeSetAxis(JNIEnv*, jclass, jint axis, jint value) {
  std::lock_guard lock(touch_mutex);
  if (touch_pad) SDL_SetJoystickVirtualAxis(touch_pad, axis, static_cast<Sint16>(value));
}

// The title's rich-presence context: 4 and 5 mean the player is in a stage,
// which switches the touch D-pad to an analog stick.
extern "C" JNIEXPORT jint JNICALL
Java_net_dojutsu_harmony_TouchControls_nativePresence(JNIEnv*, jclass) {
  return static_cast<jint>(rex::system::xam::TitlePresenceContext());
}

int main(int argc, char** argv) {
  // SDL's Java side knows the app's private directories; the game stores its
  // config, saves and cache there unless flags say otherwise.
  const char* internal = SDL_GetAndroidInternalStoragePath();
  const char* external = SDL_GetAndroidExternalStoragePath();
  std::filesystem::path files_dir = external && *external ? external : (internal ? internal : "");

  // The native library directory holds librexgpu-xenos.so and the per-module
  // libraries; derive it from this library's own location.
  std::filesystem::path native_dir;
  if (const char* lib_dir = std::getenv("HARMONY_NATIVE_LIB_DIR"); lib_dir && *lib_dir) {
    native_dir = lib_dir;
  } else {
    Dl_info info{};
    if (dladdr(reinterpret_cast<const void*>(&BuildArguments), &info) && info.dli_fname) {
      native_dir = std::filesystem::path(info.dli_fname).parent_path();
    }
  }
  rex::SetAndroidApplicationPaths(files_dir, native_dir);

  // SDL passes the Java activity's getArguments() after its own argv[0].
  std::vector<std::string> java_args;
  for (int i = 1; i < argc; ++i) {
    if (argv[i] && *argv[i]) java_args.emplace_back(argv[i]);
  }
  std::vector<std::string> args = BuildArguments(java_args);
  std::vector<char*> native_argv;
  native_argv.reserve(args.size() + 1);
  for (auto& a : args) native_argv.push_back(a.data());
  native_argv.push_back(nullptr);
  return rex::ui::RunWindowedApp(int(args.size()), native_argv.data());
}
