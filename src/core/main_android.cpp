/**
 * @file        core/main_android.cpp
 * @brief       Android process-level helpers
 *
 * @license     BSD 3-Clause License
 *              See LICENSE file in the project root for full license text.
 */

#include <rex/platform.h>

#if REX_PLATFORM_ANDROID

#include <rex/main_android.h>

#include <android/api-level.h>

namespace rex {

namespace {
std::filesystem::path& FilesDirStorage() {
  static std::filesystem::path path;
  return path;
}
std::filesystem::path& NativeLibraryDirStorage() {
  static std::filesystem::path path;
  return path;
}
}  // namespace

int GetAndroidApiLevel() {
  static const int api_level = android_get_device_api_level();
  return api_level;
}

const std::filesystem::path& GetAndroidFilesDir() { return FilesDirStorage(); }

const std::filesystem::path& GetAndroidNativeLibraryDir() {
  return NativeLibraryDirStorage();
}

void SetAndroidApplicationPaths(std::filesystem::path files_dir,
                                std::filesystem::path native_library_dir) {
  FilesDirStorage() = std::move(files_dir);
  NativeLibraryDirStorage() = std::move(native_library_dir);
}

namespace {
void*& JavaVMStorage() {
  static void* vm = nullptr;
  return vm;
}
void*& HttpBridgeClassStorage() {
  static void* cls = nullptr;
  return cls;
}
}  // namespace

void SetAndroidJavaVM(void* vm) { JavaVMStorage() = vm; }
void* GetAndroidJavaVM() { return JavaVMStorage(); }
void SetAndroidHttpBridgeClass(void* global_class_reference) {
  HttpBridgeClassStorage() = global_class_reference;
}
void* GetAndroidHttpBridgeClass() { return HttpBridgeClassStorage(); }

}  // namespace rex

#endif  // REX_PLATFORM_ANDROID
