#pragma once

#include <filesystem>

#include <rex/image_info.h>

namespace harmony {
// Explicit asset-free startup diagnostic. Never launches the guest title.
int RunLinuxStartupProbe(const rex::PPCImageInfo& image,
                         const std::filesystem::path& log_path);
}  // namespace harmony
