#include <catch2/catch_test_macros.hpp>

#include <rex/filesystem.h>
#include <rex/platform/dynlib.h>

using rex::platform::ResolveModuleLibraryPath;

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
