#pragma once

#include <filesystem>

#include <rex/image_info.h>

namespace harmony {
// Explicit asset-free startup diagnostic. Never launches the guest title.
int RunLinuxStartupProbe(const rex::PPCImageInfo& image,
                         const std::filesystem::path& log_path);
// Bounded actual generated title-function execution; no title boot/presentation.
int RunLinuxGuestProbe(const rex::PPCImageInfo& image,
                       const std::filesystem::path& log_path);
}  // namespace harmony
