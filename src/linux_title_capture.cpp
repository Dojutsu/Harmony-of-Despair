#include "linux_title_capture.h"

#include <chrono>
#include <condition_variable>
#include <filesystem>
#include <exception>
#include <fstream>
#include <mutex>
#include <string>
#include <vector>
#include <rex/cvar.h>
#include <rex/logging.h>
#include <rex/ui/presenter.h>

REXCVAR_DEFINE_STRING(harmony_capture_dir, "", "Debug",
                     "Opt-in offline guest-frame capture into a new local directory");

namespace harmony {
std::jthread StartLinuxTitleCapture(rex::ui::Presenter* presenter) {
  const auto path = std::filesystem::path(REXCVAR_GET(harmony_capture_dir));
  if (path.empty() || !presenter) return {};
  std::error_code error;
  if (!path.is_absolute() || !std::filesystem::create_directory(path, error)) {
    REXLOG_ERROR("Guest capture needs a new absolute directory with an existing parent");
    return {};
  }
  std::filesystem::permissions(path, std::filesystem::perms::owner_all, error);
  if (error) return {};
  return std::jthread([presenter, path](std::stop_token stop) {
    try {
    using namespace std::chrono_literals;
    constexpr size_t kMaximumFrameBytes = 16 * 1024 * 1024;
    constexpr size_t kMaximumTotalBytes = 256 * 1024 * 1024;
    size_t total_bytes = 0;
    std::mutex wait_mutex;
    std::condition_variable_any changed;
    std::unique_lock wait_lock(wait_mutex);
    const auto started = std::chrono::steady_clock::now();
    for (unsigned index = 0; index < 32 && !stop.stop_requested(); ++index) {
      changed.wait_for(wait_lock, stop, 10s, [] { return false; });
      if (stop.stop_requested()) break;
      rex::ui::RawImage image;
      if (!presenter->CaptureGuestOutput(image)) continue;
      if (!image.width || !image.height || image.width > 4096 || image.height > 4096) continue;
      const size_t row_bytes = size_t(image.width) * 4;
      const size_t rgb_bytes = size_t(image.width) * image.height * 3;
      if (image.stride < row_bytes || image.stride > kMaximumFrameBytes ||
          rgb_bytes > kMaximumFrameBytes || total_bytes > kMaximumTotalBytes - rgb_bytes ||
          size_t(image.height - 1) * image.stride + row_bytes > image.data.size()) continue;
      std::vector<uint8_t> rgb(rgb_bytes);
      for (size_t y = 0; y < image.height; ++y) {
        const auto* source = image.data.data() + y * image.stride;
        auto* destination = rgb.data() + y * size_t(image.width) * 3;
        for (size_t x = 0; x < image.width; ++x) {
          destination[x * 3] = source[x * 4];
          destination[x * 3 + 1] = source[x * 4 + 1];
          destination[x * 3 + 2] = source[x * 4 + 2];
        }
      }
      const auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
          std::chrono::steady_clock::now() - started).count();
      const auto destination = path / ("guest-" + std::to_string(index) + "-" + std::to_string(milliseconds) + "ms.ppm");
      std::ofstream output(destination, std::ios::binary);
      output << "P6\n" << image.width << ' ' << image.height << "\n255\n";
      output.write(reinterpret_cast<const char*>(rgb.data()), static_cast<std::streamsize>(rgb.size()));
      if (!output) {
        REXLOG_WARN("Local guest-frame capture write failed");
        break;
      }
      total_bytes += rgb_bytes;
      REXLOG_INFO("Guest frame captured: index={} elapsed_ms={} width={} height={}",
                  index, milliseconds, image.width, image.height);
    }
    } catch (const std::exception&) {
      REXLOG_WARN("Local guest-frame capture stopped after a diagnostic error");
    } catch (...) {
      REXLOG_WARN("Local guest-frame capture stopped after an unexpected diagnostic error");
    }
  });
}
}  // namespace harmony
