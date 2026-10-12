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

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <string>
#include <system_error>
#include <vector>

#include <rex/main_android.h>
#include <rex/ui/windowed_app.h>

namespace {

// Game data lives where the Winlator tests left it; the app reads it through
// "All files access" (MANAGE_EXTERNAL_STORAGE).
constexpr const char* kDefaultGameRoot = "/sdcard/HoD";

std::vector<std::string> BuildArguments() {
  std::vector<std::string> args;
  args.emplace_back("harmonyrecomp");

  std::filesystem::path game_root = kDefaultGameRoot;
  if (const char* env_root = std::getenv("HARMONY_GAME_ROOT"); env_root && *env_root) {
    game_root = env_root;
  }

  const std::filesystem::path extra_args_file = game_root / "android-args.txt";
  std::vector<std::string> extra;
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

int main(int, char**) {
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

  std::vector<std::string> args = BuildArguments();
  std::vector<char*> argv;
  argv.reserve(args.size() + 1);
  for (auto& a : args) argv.push_back(a.data());
  argv.push_back(nullptr);
  return rex::ui::RunWindowedApp(int(args.size()), argv.data());
}
