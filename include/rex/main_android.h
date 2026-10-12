/**
 * @file        rex/main_android.h
 * @brief       Android process-level helpers (API level, application paths)
 *
 * @license     BSD 3-Clause License
 *              See LICENSE file in the project root for full license text.
 */
#pragma once

#include <rex/platform.h>

#if REX_PLATFORM_ANDROID

#include <filesystem>
#include <string>

namespace rex {

/// Android API level of the device the process runs on.
int GetAndroidApiLevel();

/// Directory the host application may use for persistent private files
/// (the app's external files directory when set by the Java side, otherwise
/// the internal files directory). Empty until SetAndroidApplicationPaths.
const std::filesystem::path& GetAndroidFilesDir();

/// Directory holding the application's native libraries (where the GPU plugin
/// shared object is staged by the APK packaging).
const std::filesystem::path& GetAndroidNativeLibraryDir();

/// Called once from the platform entry point before any runtime use.
void SetAndroidApplicationPaths(std::filesystem::path files_dir,
                                std::filesystem::path native_library_dir);

/// The process JavaVM* (opaque here so this header needs no <jni.h>), recorded
/// by the host library's JNI_OnLoad. Null until then.
void SetAndroidJavaVM(void* vm);
void* GetAndroidJavaVM();

/// Global reference to the host app's HTTP bridge class (a Java class with
/// `static byte[] request(String url, String method, String bearer, byte[]
/// body, int[] status)`), used by the session-directory client. Null when the
/// host app does not provide one; the directory is then unreachable.
void SetAndroidHttpBridgeClass(void* global_class_reference);
void* GetAndroidHttpBridgeClass();

}  // namespace rex

#endif  // REX_PLATFORM_ANDROID
