#include "linux_user_paths.h"
#include <array>
#include <cstdio>
#include <cstdlib>

int main() {
  unsigned checks = 0;
  auto check = [&](bool value) { ++checks; if (!value) std::exit(1); };
  using harmony::LinuxConfigPath;
  check(LinuxConfigPath("", "/home/test/config", "/home/test") ==
        "/home/test/config/harmonyrecomp/harmonyrecomp.toml");
  check(LinuxConfigPath("", "", "/home/test") ==
        "/home/test/.config/harmonyrecomp/harmonyrecomp.toml");
  check(LinuxConfigPath("", "relative", "/home/test") ==
        "/home/test/.config/harmonyrecomp/harmonyrecomp.toml");
  check(LinuxConfigPath("/deployment/config", "/ignored", "/ignored") ==
        "/deployment/config/harmonyrecomp/harmonyrecomp.toml");
  check(LinuxConfigPath("", "/xdg", "") == "/xdg/harmonyrecomp/harmonyrecomp.toml");
  for (auto values : {std::array<std::string_view,3>{"relative", "/xdg", "/home/test"},
                     std::array<std::string_view,3>{"", "", ""},
                     std::array<std::string_view,3>{"", "relative", "relative"}}) {
    bool rejected = false;
    try { (void)LinuxConfigPath(values[0], values[1], values[2]); }
    catch (const std::invalid_argument&) { rejected = true; }
    check(rejected);
  }
  std::printf("Linux configuration path checks: %u passed\n", checks);
}
