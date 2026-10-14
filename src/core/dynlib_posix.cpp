#include <rex/filesystem.h>
#include <rex/platform.h>
#include <rex/platform/dynlib.h>

static_assert(REX_PLATFORM_LINUX || REX_PLATFORM_MAC, "This file is POSIX-only");

#include <dlfcn.h>

namespace rex::platform {

std::filesystem::path ResolveModuleLibraryPath(const std::filesystem::path& path) {
#if REX_PLATFORM_LINUX
  // Generated registries hold CMake target stems. Unlike LoadLibrary, dlopen
  // neither appends the shared-library suffix nor the CMake "lib" prefix.
  // Keep an explicit native path/name authoritative, including versioned .so
  // filenames, rather than guessing how a caller intended it to be loaded.
  if (!path.empty() && !path.has_parent_path() && !path.has_extension() && path != "." &&
      path != "..") {
    // Module CMake targets colocate with the host. Use that explicit location:
    // a dlopen call in rexruntime does not inherit the host's ELF RUNPATH.
    return rex::filesystem::GetExecutableFolder() / ("lib" + path.string() + ".so");
  }
#elif REX_PLATFORM_MAC
  // Same CMake target stems on macOS, built as lib<name>.dylib next to the host.
  if (!path.empty() && !path.has_parent_path() && !path.has_extension() && path != "." &&
      path != "..") {
    return rex::filesystem::GetExecutableFolder() / ("lib" + path.string() + ".dylib");
  }
#endif
  return path;
}

DynamicLibrary::~DynamicLibrary() {
  Close();
}

DynamicLibrary::DynamicLibrary(DynamicLibrary&& other) noexcept : handle_(other.handle_) {
  other.handle_ = nullptr;
}

DynamicLibrary& DynamicLibrary::operator=(DynamicLibrary&& other) noexcept {
  if (this != &other) {
    Close();
    handle_ = other.handle_;
    other.handle_ = nullptr;
  }
  return *this;
}

bool DynamicLibrary::Load(const std::filesystem::path& path, SymbolResolution mode) {
  Close();
  int flags = (mode == SymbolResolution::kImmediate) ? RTLD_NOW : RTLD_LAZY;
  handle_ = dlopen(path.c_str(), flags);
  return handle_ != nullptr;
}

bool DynamicLibrary::LoadExisting(const std::filesystem::path& path) {
  Close();
  if (path.empty()) return false;
  handle_ = dlopen(path.c_str(), RTLD_LAZY | RTLD_NOLOAD);
  return handle_ != nullptr;
}

void DynamicLibrary::Close() {
  if (handle_) {
    dlclose(handle_);
    handle_ = nullptr;
  }
}

void* DynamicLibrary::GetRawSymbol(const char* name) const {
  if (!handle_)
    return nullptr;
  return dlsym(handle_, name);
}

}  // namespace rex::platform
