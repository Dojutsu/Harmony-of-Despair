#pragma once

#include <filesystem>
#include <stdexcept>
#include <string_view>

namespace harmony {
// Pure resolution, independent of process environment and filesystem mutation.
// Explicit development overrides are separate from saves/cache/owned data.
inline std::filesystem::path LinuxConfigPath(std::string_view override_root,
                                            std::string_view xdg_config_home,
                                            std::string_view home) {
  std::filesystem::path root;
  if (!override_root.empty()) {
    root = override_root;
    if (!root.is_absolute()) throw std::invalid_argument("harmony_config_root must be absolute");
  } else if (std::filesystem::path(xdg_config_home).is_absolute()) {
    root = xdg_config_home;
  } else {
    root = home;
    if (!root.is_absolute()) throw std::invalid_argument("Linux config requires absolute HOME or XDG_CONFIG_HOME");
    root /= ".config";
  }
  return root / "harmonyrecomp" / "harmonyrecomp.toml";
}
}  // namespace harmony
