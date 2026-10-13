// harmonyrecomp - Android first-run game file import.
//
// The start screen (LauncherActivity) cannot run the PC's harmonyrecomp-import
// tool, so this small library exposes the same import steps to Java:
// container inspection, the aggregate base + TU2 import with optional DLC,
// and the fallback for an already extracted TU2 folder (Setup-Harmony.ps1).

#include "dlc_manifest.h"
#include "game_data.h"

#include <jni.h>

#include <filesystem>
#include <string>
#include <system_error>

namespace fs = std::filesystem;
namespace gd = harmony::game_data;

namespace {

std::string FromJava(JNIEnv* env, jstring value) {
  if (!value) return {};
  const char* chars = env->GetStringUTFChars(value, nullptr);
  std::string result = chars ? chars : "";
  if (chars) env->ReleaseStringUTFChars(value, chars);
  return result;
}

jstring ToJava(JNIEnv* env, const std::string& value) { return env->NewStringUTF(value.c_str()); }

std::string FirstError(const gd::ValidationResult& result, const char* fallback) {
  return result.errors.empty() ? fallback : result.errors.front();
}

}  // namespace

// 2 = base game and TU2 ready, 1 = base game only, 0 = no usable game data.
extern "C" JNIEXPORT jint JNICALL
Java_net_dojutsu_harmony_GameFiles_nativeStatus(JNIEnv* env, jclass, jstring root) {
  try {
    const fs::path path = FromJava(env, root);
    if (gd::ValidateTu2Root(path).valid) return 2;
    if (gd::ValidateRoot(path).valid) return 1;
  } catch (...) {
  }
  return 0;
}

// Returns "OK:<summary>" or "ERR:<reason>".
extern "C" JNIEXPORT jstring JNICALL
Java_net_dojutsu_harmony_GameFiles_nativeImport(JNIEnv* env, jclass, jstring source,
                                                jstring destination, jstring content_root) {
  try {
    gd::ImportOptions options;
    options.source = FromJava(env, source);
    options.destination = FromJava(env, destination);
    options.replace_existing = true;
    const fs::path dlc_root = FromJava(env, content_root);
    std::error_code ec;
    fs::create_directories(options.destination.parent_path(), ec);

    gd::AggregateInventory inventory = gd::DiscoverPackages(options.source);
    const bool containers = inventory.errors.empty() && inventory.base_packages.size() == 1 &&
                            inventory.update_packages.size() == 1;
    if (!containers) {
      // Advanced fallback: an already extracted, complete TU2 folder.
      if (!gd::ValidateTu2Source(options.source).valid) {
        std::string reason;
        if (inventory.base_packages.empty())
          reason = "The base game package was not found in that folder.";
        else if (inventory.base_packages.size() > 1)
          reason = "That folder has more than one copy of the base game. Keep only one.";
        else if (inventory.update_packages.empty())
          reason = "Title update 2 was not found in that folder. It is required.";
        else if (inventory.update_packages.size() > 1)
          reason = "That folder has more than one copy of title update 2. Keep only one.";
        else
          reason = inventory.errors.empty() ? "No Harmony of Despair files were found."
                                            : inventory.errors.front();
        return ToJava(env, "ERR:" + reason);
      }
      options.require_tu2 = true;
      const auto result = gd::Import(options);
      if (!result.valid || !gd::ValidateTu2Root(options.destination).valid)
        return ToJava(env, "ERR:" + FirstError(result, "The copied game files did not verify."));
      return ToJava(env, "OK:Game files copied (version " +
                             gd::FormatVersion(result.identity.version) + ").");
    }

    const auto result = gd::ImportAggregate(options, &inventory);
    if (!result.valid || !gd::ValidateTu2Root(options.destination).valid)
      return ToJava(env, "ERR:" + FirstError(result, "The copied game files did not verify."));

    size_t installed = 0;
    size_t failed = 0;
    if (!inventory.dlc_packages.empty() && !dlc_root.empty()) {
      fs::create_directories(dlc_root, ec);
      harmony::dlc::DlcManager manager(dlc_root, gd::kTitleId);
      const fs::path staging = options.destination.parent_path() / "dlc.importing";
      for (const auto& package : inventory.dlc_packages) {
        if (manager.is_installed(package.filename().string())) {
          ++installed;
          continue;
        }
        if (manager.install(package, staging, true).success) ++installed;
        else ++failed;
      }
      fs::remove_all(staging, ec);
    }
    std::string summary = "Game files copied (version " +
                          gd::FormatVersion(result.identity.version) + ").";
    if (!inventory.dlc_packages.empty()) {
      summary += " Extra content: " + std::to_string(installed) + " of " +
                 std::to_string(inventory.dlc_packages.size()) + " added.";
      if (failed) summary += " Some extra content could not be read and was skipped.";
    }
    return ToJava(env, "OK:" + summary);
  } catch (const std::exception& e) {
    return ToJava(env, std::string("ERR:") + e.what());
  } catch (...) {
    return ToJava(env, "ERR:The import stopped unexpectedly.");
  }
}
