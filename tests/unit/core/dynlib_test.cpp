#include <catch2/catch_test_macros.hpp>

#include <rex/filesystem.h>
#include <rex/platform/dynlib.h>

using rex::platform::ResolveModuleLibraryPath;

TEST_CASE("Optional debugger lookup retains existing modules only", "[core][dynlib]") {
  rex::platform::DynamicLibrary existing;
  CHECK_FALSE(existing.LoadExisting(""));
  CHECK_FALSE(existing.LoadExisting("full-send-missing-optional-debugger-library"));
  CHECK_FALSE(bool(existing));
#if REX_PLATFORM_LINUX
  // libc is already linked into this process. Retaining it must preserve symbols
  // after a second independently owned reference is released.
  REQUIRE(existing.LoadExisting("libc.so.6"));
  auto strlen_symbol = existing.GetSymbol<size_t (*)(const char*)>("strlen");
  REQUIRE(strlen_symbol);
  rex::platform::DynamicLibrary second;
  REQUIRE(second.LoadExisting("libc.so.6"));
  second.Close();
  CHECK(strlen_symbol("Full-Send") == 9);
  existing.Close();
  CHECK_FALSE(bool(existing));
#endif
}

TEST_CASE("Native module target stems use the platform library filename", "[core][dynlib]") {
#if REX_PLATFORM_LINUX
  const auto module_path = ResolveModuleLibraryPath("harmonyrecomp_dllAlucard");
  CHECK(module_path.filename() == "libharmonyrecomp_dllAlucard.so");
  CHECK(module_path.is_absolute());
  CHECK(module_path.parent_path() == rex::filesystem::GetExecutableFolder());
  // A target itself named libexample gets CMake's normal additional prefix.
  CHECK(ResolveModuleLibraryPath("libexample").filename() == "liblibexample.so");
#else
  CHECK(ResolveModuleLibraryPath("harmonyrecomp_dllAlucard") == "harmonyrecomp_dllAlucard");
  CHECK(ResolveModuleLibraryPath("libexample") == "libexample");
#endif
}

TEST_CASE("Native module explicit paths and filenames stay authoritative", "[core][dynlib]") {
  CHECK(ResolveModuleLibraryPath("").empty());
  CHECK(ResolveModuleLibraryPath("libexample.so") == "libexample.so");
  CHECK(ResolveModuleLibraryPath("libexample.so.1") == "libexample.so.1");
  CHECK(ResolveModuleLibraryPath("example.dll") == "example.dll");
  CHECK(ResolveModuleLibraryPath("example.dylib") == "example.dylib");
  CHECK(ResolveModuleLibraryPath("./example") == "./example");
  CHECK(ResolveModuleLibraryPath("plugins/example") == "plugins/example");
  CHECK(ResolveModuleLibraryPath("plugins/libexample.so") == "plugins/libexample.so");
  CHECK(ResolveModuleLibraryPath("/opt/harmony/libexample.so") == "/opt/harmony/libexample.so");
  CHECK(ResolveModuleLibraryPath(".") == ".");
  CHECK(ResolveModuleLibraryPath("..") == "..");
}
