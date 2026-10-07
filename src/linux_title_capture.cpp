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
REXCVAR_DEFINE_UINT32(harmony_capture_interval_ms, 10000, "Debug",
                     "Interval for bounded offline guest-frame capture, in milliseconds")
    .range(1000, 60000)
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);

REXCVAR_DEFINE_UINT32(harmony_capture_delay_ms, 0, "Debug",
                     "Initial delay for bounded offline guest-frame capture, in milliseconds")
    .range(0, 600000)
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);

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
  const auto interval = std::chrono::milliseconds(REXCVAR_GET(harmony_capture_interval_ms));
  const auto delay = std::chrono::milliseconds(REXCVAR_GET(harmony_capture_delay_ms));
  return std::jthread([presenter, path, interval, delay](std::stop_token stop) {
    try {
    using namespace std::chrono_literals;
    constexpr size_t kMaximumFrameBytes = 16 * 1024 * 1024;
    constexpr size_t kMaximumTotalBytes = 256 * 1024 * 1024;
    size_t total_bytes = 0;
    std::mutex wait_mutex;
    std::condition_variable_any changed;
    std::unique_lock wait_lock(wait_mutex);
    // Keep elapsed timestamps anchored to capture startup, including the delay,
    // so controller/frame correlation retains its original clock.
    const auto started = std::chrono::steady_clock::now();
    if (delay > 0ms) {
      changed.wait_for(wait_lock, stop, delay, [] { return false; });
      if (stop.stop_requested()) return;
    }
    for (unsigned index = 0; index < 32 && !stop.stop_requested(); ++index) {
      changed.wait_for(wait_lock, stop, interval, [] { return false; });
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
