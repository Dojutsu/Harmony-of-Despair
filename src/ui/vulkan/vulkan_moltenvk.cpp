/**
 * @file        ui/vulkan_moltenvk.cpp
 * @brief       MoltenVK Vulkan runtime detection and configuration for macOS
 *
 * @copyright   Copyright (c) 2026 Rien Gupta <rgupta9@scu.edu>
 *              All rights reserved.
 *
 * @license     BSD 3-Clause License
 *              See LICENSE file in the project root for full license text.
 */

#include <rex/platform.h>

#if REX_PLATFORM_MAC

#include "vulkan_moltenvk.h"

#include <algorithm>
#include <cstdlib>
#include <string>
#include <system_error>

#include <rex/filesystem.h>
#include <rex/ui/vulkan/macos_vulkan_paths.h>

namespace rex::ui::vulkan {
namespace {

namespace fs = std::filesystem;
namespace path_data = macos_vulkan_paths;

bool PathExists(const fs::path& path) {
  std::error_code ec;
  return fs::exists(path, ec);
}

bool IsDirectory(const fs::path& path) {
  std::error_code ec;
  return fs::is_directory(path, ec);
}

void AppendUnique(std::vector<fs::path>& paths, const fs::path& path) {
  if (path.empty()) {
    return;
  }
  if (std::find(paths.begin(), paths.end(), path) == paths.end()) {
    paths.push_back(path);
  }
}

void AppendExisting(std::vector<fs::path>& paths, const fs::path& path) {
  if (PathExists(path)) {
    AppendUnique(paths, path);
  }
}

fs::path NormalizeSdkRoot(const fs::path& candidate) {
  if (candidate.empty()) {
    return {};
  }

  for (std::string_view suffix : path_data::kRootSuffixes) {
    fs::path root = suffix == "." ? candidate : candidate / suffix;
    for (std::string_view marker : path_data::kRootMarkers) {
      if (PathExists(root / marker)) {
        return root;
      }
    }
  }

  return {};
}

void AppendNormalizedRoot(std::vector<fs::path>& roots, const fs::path& candidate) {
  AppendUnique(roots, NormalizeSdkRoot(candidate));
}

void CollectExecutableRoots(std::vector<fs::path>& roots) {
  const fs::path executable_dir = rex::filesystem::GetExecutableFolder();
  if (executable_dir.empty()) {
    return;
  }

  AppendNormalizedRoot(roots, executable_dir);
  AppendNormalizedRoot(roots, executable_dir / "vulkan");

  const fs::path install_prefix = executable_dir.parent_path();
  if (!install_prefix.empty()) {
    AppendNormalizedRoot(roots, install_prefix);
    AppendNormalizedRoot(roots, install_prefix / "vulkan");
  }

  if (executable_dir.filename() == "MacOS") {
    const fs::path bundle_contents = executable_dir.parent_path();
    AppendNormalizedRoot(roots, bundle_contents);
    AppendNormalizedRoot(roots, bundle_contents / "Resources" / "vulkan");
  }
}

template <typename Candidates>
void AssignIfExists(fs::path& destination, const fs::path& root, const Candidates& candidates) {
  if (!destination.empty()) {
    return;
  }

  for (std::string_view relative_path : candidates) {
    fs::path candidate = root / relative_path;
    if (PathExists(candidate)) {
      destination = candidate;
      return;
    }
  }
}

std::vector<fs::path> CollectSdkRoots() {
  std::vector<fs::path> roots;

  CollectExecutableRoots(roots);

  for (std::string_view environment_variable : path_data::kSdkEnvironmentVariables) {
    const char* sdk_root = std::getenv(environment_variable.data());
    if (sdk_root && sdk_root[0]) {
      AppendNormalizedRoot(roots, sdk_root);
    }
  }

  const char* home = std::getenv("HOME");
  if (home && home[0]) {
    fs::path user_sdk_dir = fs::path(home) / "VulkanSDK";
    if (IsDirectory(user_sdk_dir)) {
      std::vector<fs::path> version_dirs;
      std::error_code ec;
      for (const fs::directory_entry& entry : fs::directory_iterator(user_sdk_dir, ec)) {
        if (entry.is_directory(ec)) {
          version_dirs.push_back(entry.path());
        }
      }
      std::sort(version_dirs.begin(), version_dirs.end(),
                [](const fs::path& a, const fs::path& b) { return a > b; });
      for (const fs::path& version_dir : version_dirs) {
        AppendNormalizedRoot(roots, version_dir);
      }
    }
  }

  for (std::string_view fallback_root : path_data::kFallbackRoots) {
    AppendNormalizedRoot(roots, fallback_root);
  }

  return roots;
}

}  // namespace

MacOSVulkanRuntimePaths DetectMacOSVulkanRuntimePaths() {
  MacOSVulkanRuntimePaths paths;

  for (const std::filesystem::path& root : CollectSdkRoots()) {
    if (paths.sdk_root.empty()) {
      paths.sdk_root = root;
    }

    for (std::string_view loader_file : path_data::kLoaderFiles) {
      AppendExisting(paths.loader_candidates, root / loader_file);
    }

    AssignIfExists(paths.spirv_tools_library, root, path_data::kSpirvToolsFiles);
    AssignIfExists(paths.moltenvk_icd, root, path_data::kIcdFiles);
  }

  return paths;
}

void ConfigureMacOSVulkanEnvironment(const MacOSVulkanRuntimePaths& paths) {
  if (!paths.sdk_root.empty()) {
    const char* vulkan_sdk = std::getenv("VULKAN_SDK");
    if (!vulkan_sdk || !vulkan_sdk[0]) {
      std::string sdk_root = paths.sdk_root.string();
      setenv("VULKAN_SDK", sdk_root.c_str(), 1);
    }
  }

  if (!paths.moltenvk_icd.empty()) {
    std::string moltenvk_icd = paths.moltenvk_icd.string();
    const char* vk_driver_files = std::getenv("VK_DRIVER_FILES");
    if (!vk_driver_files || !vk_driver_files[0]) {
      setenv("VK_DRIVER_FILES", moltenvk_icd.c_str(), 1);
    }

    const char* vk_icd_filenames = std::getenv("VK_ICD_FILENAMES");
    if (!vk_icd_filenames || !vk_icd_filenames[0]) {
      setenv("VK_ICD_FILENAMES", moltenvk_icd.c_str(), 1);
    }
  }
}

}  // namespace rex::ui::vulkan

#endif  // REX_PLATFORM_MAC
