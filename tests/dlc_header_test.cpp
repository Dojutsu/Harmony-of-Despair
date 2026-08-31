#include "dlc_manifest.h"

#include <rex/string/utf8.h>
#include <rex/system/xam/content_device.h>
#include <rex/system/xam/content_manager.h>

#include <algorithm>
#include <array>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

namespace {

bool expect(bool condition, const char* message) {
  if (!condition) {
    std::cerr << "FAIL: " << message << '\n';
    return false;
  }
  return true;
}

}  // namespace

int main() {
  const auto unique = std::to_string(
      std::chrono::steady_clock::now().time_since_epoch().count());
  const fs::path test_root =
      fs::temp_directory_path() / ("harmony-dlc-header-" + unique);
  const fs::path header_path = test_root / "owned-package.header";
  std::error_code ec;
  fs::create_directories(test_root, ec);
  if (!expect(!ec, "create temporary directory")) return 1;

  constexpr uint32_t kTitleId = 0x58410A7A;
  const std::string file_name = "2DFBA40073459E0C5C31290000000000";
  const std::string display_name = "Harmony DLC test";
  std::string error;
  if (!expect(harmony::dlc::write_marketplace_content_header(
                  header_path, kTitleId, file_name, display_name, 0, error),
              error.c_str())) {
    fs::remove_all(test_root, ec);
    return 1;
  }

  using rex::system::XContentType;
  using rex::system::xam::DummyDeviceId;
  using rex::system::xam::XCONTENT_AGGREGATE_DATA;

  bool ok = true;
  ok &= expect(fs::file_size(header_path) == sizeof(XCONTENT_AGGREGATE_DATA),
               "header is exactly XCONTENT_AGGREGATE_DATA size");

  XCONTENT_AGGREGATE_DATA content_data{};
  std::ifstream input(header_path, std::ios::binary);
  input.read(reinterpret_cast<char*>(&content_data), sizeof(content_data));
  ok &= expect(input.good() || input.eof(), "read complete header");
  ok &= expect(static_cast<uint32_t>(content_data.device_id) ==
                   static_cast<uint32_t>(DummyDeviceId::HDD),
               "device is HDD");
  ok &= expect(content_data.content_type == XContentType::kMarketplaceContent,
               "content type is marketplace");
  ok &= expect(static_cast<uint64_t>(content_data.xuid) == 0,
               "marketplace XUID is common");
  ok &= expect(static_cast<uint32_t>(content_data.title_id) == kTitleId,
               "title ID matches Harmony of Despair");
  ok &= expect(content_data.file_name() == file_name,
               "file name is the container basename");
  ok &= expect(content_data.display_name() ==
                   rex::string::to_utf16(display_name),
               "display name round-trips through ReXGlue encoding");
  ok &= expect(content_data.padding[0] == 0 && content_data.padding[1] == 0,
               "file-name padding is zero");

  constexpr uint32_t kLicenseMask = 1;
  const fs::path licensed_header_path = test_root / "owned-package-licensed.header";
  error.clear();
  ok &= expect(harmony::dlc::write_marketplace_content_header(
                   licensed_header_path, kTitleId, file_name, display_name,
                   kLicenseMask, error),
               "write licensed marketplace header");
  ok &= expect(fs::file_size(licensed_header_path) ==
                   sizeof(XCONTENT_AGGREGATE_DATA) + sizeof(uint32_t),
               "licensed header appends the package mask");

  uint32_t round_trip_license_mask = 0;
  std::ifstream licensed_input(licensed_header_path, std::ios::binary);
  licensed_input.seekg(sizeof(XCONTENT_AGGREGATE_DATA));
  licensed_input.read(reinterpret_cast<char*>(&round_trip_license_mask),
                      sizeof(round_trip_license_mask));
  ok &= expect(round_trip_license_mask == kLicenseMask,
               "package license mask round-trips in ReXGlue host format");

  fs::remove_all(test_root, ec);
  if (!ok) return 1;
  std::cout << "DLC marketplace header production-path test passed\n";
  return 0;
}
