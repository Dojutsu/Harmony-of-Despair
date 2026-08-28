#include "game_data.h"

#include <rex/filesystem/devices/stfs_container_device.h>
#include <rex/filesystem/file.h>

#include <algorithm>
#include <array>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <queue>
#include <sstream>
#include <span>
#include <string_view>
#include <system_error>

namespace fs = std::filesystem;

namespace harmony::game_data {
namespace {

constexpr uint32_t kXex2Magic = 0x58455832;
constexpr uint32_t kExecutionInfoKey = 0x00040006;
constexpr std::string_view kInstallMarker = ".harmonyrecomp-install.json";

struct SupportedVersion {
  uint32_t media_id;
  uint32_t version;
};

constexpr std::array<SupportedVersion, 1> kSupportedVersions = {{
    {0x6480C08F, 0x00000104},
}};

constexpr std::array<const char*, 7> kRequiredFiles = {{
    "default.xex",
    "data/player_dll/dllAlucard.dll",
    "data/player_dll/dllAxeArmor.dll",
    "data/player_dll/dllCharlotte.dll",
    "data/player_dll/dllJonathan.dll",
    "data/player_dll/dllShanoa.dll",
    "data/player_dll/dllSoma.dll",
}};

uint32_t ReadBe32(const uint8_t* value) {
  return (uint32_t(value[0]) << 24) | (uint32_t(value[1]) << 16) |
         (uint32_t(value[2]) << 8) | uint32_t(value[3]);
}

bool ReadXexIdentity(const fs::path& path, XexIdentity& identity, std::string& error) {
  std::ifstream input(path, std::ios::binary);
  if (!input) {
    error = "cannot open " + path.string();
    return false;
  }

  std::array<uint8_t, 24> fixed{};
  input.read(reinterpret_cast<char*>(fixed.data()), fixed.size());
  if (input.gcount() != static_cast<std::streamsize>(fixed.size()) ||
      ReadBe32(fixed.data()) != kXex2Magic) {
    error = path.string() + " is not an Xbox 360 XEX2 image";
    return false;
  }

  const uint32_t header_size = ReadBe32(fixed.data() + 8);
  const uint32_t header_count = ReadBe32(fixed.data() + 20);
  if (header_size < fixed.size() || header_count > 4096 ||
      uint64_t(fixed.size()) + uint64_t(header_count) * 8 > header_size) {
    error = path.string() + " has a corrupt XEX header";
    return false;
  }

  uint32_t execution_offset = 0;
  std::array<uint8_t, 8> optional{};
  for (uint32_t i = 0; i < header_count; ++i) {
    input.read(reinterpret_cast<char*>(optional.data()), optional.size());
    if (!input) {
      error = path.string() + " has a truncated XEX optional-header table";
      return false;
    }
    if (ReadBe32(optional.data()) == kExecutionInfoKey) {
      execution_offset = ReadBe32(optional.data() + 4);
    }
  }

  if (!execution_offset || uint64_t(execution_offset) + 24 > header_size) {
    error = path.string() + " has no valid XEX execution metadata";
    return false;
  }

  input.seekg(execution_offset);
  std::array<uint8_t, 24> execution{};
  input.read(reinterpret_cast<char*>(execution.data()), execution.size());
  if (!input) {
    error = path.string() + " has truncated XEX execution metadata";
    return false;
  }

  identity.media_id = ReadBe32(execution.data());
  identity.version = ReadBe32(execution.data() + 4);
  identity.base_version = ReadBe32(execution.data() + 8);
  identity.title_id = ReadBe32(execution.data() + 12);
  return true;
}

bool IsSupported(const XexIdentity& identity) {
  return std::ranges::any_of(kSupportedVersions, [&](const SupportedVersion& supported) {
    return identity.media_id == supported.media_id && identity.version == supported.version;
  });
}

ValidationResult ValidatePayload(const fs::path& root) {
  ValidationResult result;
  std::error_code ec;
  if (!fs::is_directory(root, ec)) {
    result.errors.push_back("game-data directory does not exist: " + root.string());
    return result;
  }

  for (const char* relative : kRequiredFiles) {
    const fs::path candidate = root / fs::path(relative);
    if (!fs::is_regular_file(candidate, ec) || fs::file_size(candidate, ec) == 0) {
      result.errors.push_back(std::string("missing required executable-layer file: ") + relative);
    }
  }
  if (!result.errors.empty()) return result;

  size_t non_executable_payload_files = 0;
  for (fs::recursive_directory_iterator it(root, ec), end; it != end && !ec; it.increment(ec)) {
    if (!it->is_regular_file(ec)) continue;
    const fs::path relative = fs::relative(it->path(), root, ec);
    if (ec) break;
    const std::string generic = relative.generic_string();
    const bool executable_anchor =
        std::ranges::any_of(kRequiredFiles, [&](const char* required) { return generic == required; });
    if (!executable_anchor && generic != kInstallMarker) ++non_executable_payload_files;
  }
  if (ec) {
    result.errors.push_back("cannot verify the complete game-data hierarchy: " + ec.message());
    return result;
  }
  if (non_executable_payload_files == 0) {
    result.errors.push_back(
        "source contains only private build-time executable inputs, not gameplay data");
    return result;
  }

  std::string error;
  if (!ReadXexIdentity(root / "default.xex", result.identity, error)) {
    result.errors.push_back(error);
    return result;
  }
  if (result.identity.title_id != kTitleId) {
    result.errors.push_back("wrong Xbox 360 game selected (expected Title ID 58410A7A)");
    return result;
  }
  if (!IsSupported(result.identity)) {
    result.errors.push_back("unsupported Harmony of Despair version " +
                            FormatVersion(result.identity.version));
    return result;
  }

  for (size_t i = 1; i < kRequiredFiles.size(); ++i) {
    XexIdentity module;
    if (!ReadXexIdentity(root / kRequiredFiles[i], module, error)) {
      result.errors.push_back(error);
      continue;
    }
    if (module.title_id != result.identity.title_id || module.media_id != result.identity.media_id ||
        module.version != result.identity.version) {
      result.errors.push_back(std::string("player module does not match the selected game: ") +
                              kRequiredFiles[i]);
    }
  }

  result.valid = result.errors.empty();
  return result;
}

bool WriteInstallMarker(const fs::path& root, const XexIdentity& identity, std::string& error) {
  std::ofstream marker(root / kInstallMarker, std::ios::binary | std::ios::trunc);
  if (!marker) {
    error = "cannot write the verified-install marker";
    return false;
  }
  marker << "{\n"
         << "  \"schema\": 1,\n"
         << "  \"title_id\": \"58410A7A\",\n"
         << "  \"media_id\": \"" << std::hex << std::uppercase << std::setw(8)
         << std::setfill('0') << identity.media_id << "\",\n"
         << "  \"version\": \"" << FormatVersion(identity.version) << "\",\n"
         << "  \"payload_policy\": \"complete-source-hierarchy\"\n"
         << "}\n";
  if (!marker) {
    error = "disk write failed while recording the verified installation";
    return false;
  }
  return true;
}

bool SafeRelativePath(const fs::path& path) {
  if (path.empty() || path.is_absolute()) return false;
  for (const auto& component : path.lexically_normal()) {
    if (component == "..") return false;
  }
  return true;
}

bool CopyDirectory(const fs::path& source, const fs::path& destination, std::string& error) {
  std::error_code ec;
  fs::create_directories(destination, ec);
  if (ec) {
    error = "cannot create import directory: " + ec.message();
    return false;
  }

  for (fs::recursive_directory_iterator it(source, fs::directory_options::none, ec), end;
       it != end; it.increment(ec)) {
    if (ec) {
      error = "cannot enumerate source directory: " + ec.message();
      return false;
    }
    const fs::directory_entry& entry = *it;
    if (entry.is_symlink(ec)) {
      error = "source contains a symbolic link, which is not accepted: " + entry.path().string();
      return false;
    }
    fs::path relative = fs::relative(entry.path(), source, ec);
    if (ec || !SafeRelativePath(relative)) {
      error = "source contains an unsafe path";
      return false;
    }
    fs::path output = destination / relative;
    if (entry.is_directory(ec)) {
      fs::create_directories(output, ec);
    } else if (entry.is_regular_file(ec)) {
      fs::create_directories(output.parent_path(), ec);
      if (!ec) fs::copy_file(entry.path(), output, fs::copy_options::none, ec);
    } else {
      error = "source contains an unsupported filesystem entry: " + entry.path().string();
      return false;
    }
    if (ec) {
      error = "copy failed for " + entry.path().string() + ": " + ec.message();
      return false;
    }
  }
  return true;
}

bool ExtractStfs(const fs::path& source, const fs::path& destination, XexIdentity& package_identity,
                 std::string& error) {
  using rex::filesystem::Entry;
  using rex::filesystem::File;
  using rex::filesystem::FileAccess;
  using rex::filesystem::StfsContainerDevice;

  auto header = StfsContainerDevice::ReadPackageHeader(source);
  if (!header) {
    error = "source is neither a directory nor a valid Xbox 360 STFS package";
    return false;
  }
  package_identity.media_id = header->metadata.execution_info.media_id;
  package_identity.version = header->metadata.execution_info.version_value;
  package_identity.base_version = header->metadata.execution_info.base_version_value;
  package_identity.title_id = header->metadata.execution_info.title_id;
  if (package_identity.title_id != kTitleId) {
    error = "wrong Xbox 360 title selected (Title ID does not match Harmony of Despair)";
    return false;
  }
  if (!IsSupported(package_identity)) {
    error = "this Harmony of Despair package version is not supported yet";
    return false;
  }

  StfsContainerDevice device("", source);
  if (!device.Initialize()) {
    error = "the STFS package is corrupt or incomplete";
    return false;
  }
  Entry* root = device.ResolvePath("/");
  if (!root) {
    error = "the STFS package has no readable root directory";
    return false;
  }

  std::error_code ec;
  fs::create_directories(destination, ec);
  if (ec) {
    error = "cannot create import directory: " + ec.message();
    return false;
  }

  std::queue<Entry*> pending;
  for (const auto& child : root->children()) pending.push(child.get());
  std::vector<uint8_t> buffer(1024 * 1024);
  while (!pending.empty()) {
    Entry* entry = pending.front();
    pending.pop();
    for (const auto& child : entry->children()) pending.push(child.get());

    fs::path relative = fs::path(entry->path());
    if (relative.is_absolute()) relative = relative.relative_path();
    if (!SafeRelativePath(relative)) {
      error = "the STFS package contains an unsafe path";
      return false;
    }
    fs::path output = destination / relative;
    const bool is_directory =
        (entry->attributes() & rex::filesystem::kFileAttributeDirectory) != 0;
    if (is_directory) {
      fs::create_directories(output, ec);
      if (ec) {
        error = "cannot create extracted directory: " + ec.message();
        return false;
      }
      continue;
    }

    fs::create_directories(output.parent_path(), ec);
    if (ec) {
      error = "cannot create extracted directory: " + ec.message();
      return false;
    }
    File* input = nullptr;
    if (entry->Open(FileAccess::kFileReadData, &input) != 0 || !input) {
      error = "cannot read " + entry->path() + " from the STFS package";
      return false;
    }
    std::ofstream out(output, std::ios::binary | std::ios::trunc);
    if (!out) {
      input->Destroy();
      error = "cannot create " + output.string();
      return false;
    }
    size_t offset = 0;
    while (offset < entry->size()) {
      const size_t requested = std::min(buffer.size(), entry->size() - offset);
      size_t actual = 0;
      if (input->ReadSync(std::span<uint8_t>(buffer.data(), requested), offset, &actual) != 0 ||
          actual == 0) {
        input->Destroy();
        error = "the STFS package ended while extracting " + entry->path();
        return false;
      }
      out.write(reinterpret_cast<const char*>(buffer.data()), actual);
      if (!out) {
        input->Destroy();
        error = "disk write failed while extracting " + entry->path();
        return false;
      }
      offset += actual;
    }
    input->Destroy();
  }
  return true;
}

}  // namespace

fs::path DefaultRoot() {
#ifdef _WIN32
  if (const char* local_app_data = std::getenv("LOCALAPPDATA")) {
    return fs::path(local_app_data) / "HarmonyRecomp" / "game-data";
  }
#else
  if (const char* xdg_data_home = std::getenv("XDG_DATA_HOME")) {
    return fs::path(xdg_data_home) / "HarmonyRecomp" / "game-data";
  }
  if (const char* home = std::getenv("HOME")) {
    return fs::path(home) / ".local" / "share" / "HarmonyRecomp" / "game-data";
  }
#endif
  return fs::current_path() / "HarmonyRecomp-game-data";
}

std::string FormatVersion(uint32_t version) {
  return std::to_string((version >> 28) & 0xF) + "." +
         std::to_string((version >> 24) & 0xF) + "." +
         std::to_string((version >> 8) & 0xFFFF) + "." + std::to_string(version & 0xFF);
}

ValidationResult ValidateRoot(const fs::path& root) {
  ValidationResult result = ValidatePayload(root);
  if (!result.valid) return result;

  std::ifstream marker(root / kInstallMarker, std::ios::binary);
  if (!marker.is_open()) {
    result.valid = false;
    result.errors.push_back(
        "installation is not transactionally verified; import it with harmonyrecomp-import");
    return result;
  }
  std::string contents((std::istreambuf_iterator<char>(marker)),
                       std::istreambuf_iterator<char>());
  std::ostringstream media_id;
  media_id << std::hex << std::uppercase << result.identity.media_id;
  if (contents.find("\"schema\": 1") == std::string::npos ||
      contents.find("\"title_id\": \"58410A7A\"") == std::string::npos ||
      contents.find("\"media_id\": \"" + media_id.str() + "\"") == std::string::npos ||
      contents.find("\"version\": \"" + FormatVersion(result.identity.version) + "\"") ==
          std::string::npos ||
      contents.find("\"payload_policy\": \"complete-source-hierarchy\"") ==
          std::string::npos) {
    result.valid = false;
    result.errors.push_back(
        "installation is not transactionally verified; import it with harmonyrecomp-import");
  }
  return result;
}

ValidationResult Import(const ImportOptions& options) {
  ValidationResult failure;
  if (options.source.empty() || options.destination.empty()) {
    failure.errors.push_back("source and destination are required");
    return failure;
  }

  std::error_code ec;
  if (fs::is_symlink(options.source, ec)) {
    failure.errors.push_back("source cannot be a symbolic link");
    return failure;
  }
  ec.clear();
  const fs::path source = fs::weakly_canonical(options.source, ec);
  if (ec || !fs::exists(source)) {
    failure.errors.push_back("source does not exist: " + options.source.string());
    return failure;
  }
  fs::path destination = fs::absolute(options.destination, ec).lexically_normal();
  if (ec) {
    failure.errors.push_back("destination path is invalid");
    return failure;
  }
  if (destination == destination.root_path()) {
    failure.errors.push_back("destination cannot be a filesystem root");
    return failure;
  }
  const fs::path relative_to_source = destination.lexically_relative(source);
  if (fs::is_directory(source) && !relative_to_source.empty() &&
      relative_to_source != fs::path(".") &&
      *relative_to_source.begin() != "..") {
    failure.errors.push_back("destination cannot be inside the source directory");
    return failure;
  }
  if (fs::exists(destination) && !options.replace_existing) {
    failure.errors.push_back("destination already exists; use --force to replace it");
    return failure;
  }

  fs::path staging = destination;
  staging += ".importing";
  fs::remove_all(staging, ec);
  ec.clear();

  std::string error;
  XexIdentity package_identity;
  const bool copied = fs::is_directory(source)
                          ? CopyDirectory(source, staging, error)
                          : ExtractStfs(source, staging, package_identity, error);
  if (!copied) {
    fs::remove_all(staging, ec);
    failure.errors.push_back(error);
    return failure;
  }

  // Validate the extracted/copied payload before writing any usability marker.
  // The entire source hierarchy remains intact; these checks identify the
  // supported executable layer and do not claim that seven files are the full
  // runtime dataset.
  ValidationResult result = ValidatePayload(staging);
  if (!result.valid) {
    fs::remove_all(staging, ec);
    return result;
  }
  if (package_identity.title_id &&
      (package_identity.title_id != result.identity.title_id ||
       package_identity.media_id != result.identity.media_id ||
       package_identity.version != result.identity.version)) {
    fs::remove_all(staging, ec);
    result.valid = false;
    result.errors.push_back("STFS package metadata does not match its default.xex");
    return result;
  }

  if (!WriteInstallMarker(staging, result.identity, error)) {
    fs::remove_all(staging, ec);
    result.valid = false;
    result.errors.push_back(error);
    return result;
  }
  result = ValidateRoot(staging);
  if (!result.valid) {
    fs::remove_all(staging, ec);
    return result;
  }

  fs::path backup = destination;
  backup += ".previous";
  fs::remove_all(backup, ec);
  ec.clear();
  if (fs::exists(destination)) {
    fs::rename(destination, backup, ec);
    if (ec) {
      fs::remove_all(staging, ec);
      result.valid = false;
      result.errors.push_back("cannot replace existing game data: " + ec.message());
      return result;
    }
  }
  fs::rename(staging, destination, ec);
  if (ec) {
    std::error_code restore_error;
    if (fs::exists(backup)) fs::rename(backup, destination, restore_error);
    result.valid = false;
    result.errors.push_back("cannot finalize imported game data: " + ec.message());
    return result;
  }
  fs::remove_all(backup, ec);
  return result;
}

}  // namespace harmony::game_data
