#pragma once

#include <filesystem>

namespace harmony {
// Bounded presentation by the real Xenos/Vulkan provider, without title assets.
int RunLinuxGraphicsProbe(const std::filesystem::path& log_path);
}  // namespace harmony
