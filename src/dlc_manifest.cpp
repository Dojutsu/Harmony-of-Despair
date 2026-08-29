#include "dlc_manifest.h"
#include <rex/system/xcontent.h>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <ctime>
#include <queue>
#include <vector>
#include <span>

#include <rex/filesystem/devices/stfs_container_device.h>
#include <rex/filesystem/file.h>

#include "thirdparty/crypto/sha256.h"

namespace fs = std::filesystem;
using rex::filesystem::Entry;
using rex::filesystem::File;
using rex::filesystem::FileAccess;
using rex::filesystem::StfsContainerDevice;

namespace harmony::dlc {

// ---------------------------------------------------------------------------
// Simple JSON helpers (enough for the manifest format we write/read)
// ---------------------------------------------------------------------------

static std::string json_escape(std::string s) {
  std::string out;
  out.reserve(s.size() * 2);
  for (char c : s) {
    switch (c) {
      case '"': out += "\\\""; break;
      case '\\': out += "\\\\"; break;
      case '\n': out += "\\n"; break;
      case '\r': out += "\\r"; break;
      case '\t': out += "\\t"; break;
      default: out += c;
    }
  }
  return out;
}

static std::optional<std::string> json_parse_string(const std::string& json, size_t& pos) {
  if (pos >= json.size() || json[pos] != '"') return std::nullopt;
  ++pos;
  std::string value;
  while (pos < json.size() && json[pos] != '"') {
    if (json[pos] == '\\' && pos + 1 < json.size()) {
      ++pos;
      switch (json[pos]) {
        case '"': value += '"'; break;
        case '\\': value += '\\'; break;
        case 'n': value += '\n'; break;
        case 'r': value += '\r'; break;
        case 't': value += '\t'; break;
        default: value += json[pos]; break;
      }
    } else {
      value += json[pos];
    }
    ++pos;
  }
  if (pos < json.size() && json[pos] == '"') ++pos;
  return value;
}

static std::optional<uint64_t> json_parse_number(const std::string& json, size_t& pos) {
  size_t start = pos;
  if (pos < json.size() && json[pos] == '-') ++pos;
  while (pos < json.size() && std::isdigit(json[pos])) ++pos;
  if (pos == start) return std::nullopt;
  try {
    return std::stoull(json.substr(start, pos - start));
  } catch (...) {
    return std::nullopt;
  }
}

// ---------------------------------------------------------------------------
// DlcManifest serialization
// ---------------------------------------------------------------------------

std::string DlcManifest::to_json() const {
  std::ostringstream out;
  out << "{\n";
  out << "  \"schema_version\": " << schema_version << ",\n";
  out << "  \"source_container\": \"" << json_escape(source_container) << "\",\n";
  out << "  \"content_id\": \"" << json_escape(content_id) << "\",\n";
  out << "  \"title_id\": \"" << std::hex << std::uppercase << title_id << "\",\n";
  out << "  \"media_id\": \"" << std::hex << std::uppercase << media_id << "\",\n";
  out << "  \"version\": \"" << std::hex << std::uppercase << version << "\",\n";
  out << "  \"base_version\": \"" << std::hex << std::uppercase << base_version << "\",\n";
  out << "  \"content_type_name\": \"" << json_escape(content_type_name) << "\",\n";
  out << "  \"install_timestamp\": " << install_timestamp << ",\n";
  out << "  \"installed_path\": \"" << json_escape(installed_path.string()) << "\",\n";
  out << "  \"display_name\": \"" << json_escape(display_name) << "\",\n";
  out << "  \"file_count\": " << file_count << ",\n";
  out << "  \"directory_count\": " << directory_count << ",\n";
  out << "  \"total_logical_bytes\": " << total_logical_bytes << ",\n";
  out << "  \"package_type\": \"" << json_escape(package_type) << "\",\n";
  out << "  \"inferred_name\": \"" << json_escape(inferred_name) << "\",\n";
  out << "  \"executable_modules\": [";
  for (size_t i = 0; i < executable_modules.size(); ++i) {
    if (i > 0) out << ", ";
    out << "\"" << json_escape(executable_modules[i]) << "\"";
  }
  out << "],\n";
  out << "  \"files\": [\n";
  for (size_t i = 0; i < files.size(); ++i) {
    const auto& f = files[i];
    out << "    {\n";
    out << "      \"relative_path\": \"" << json_escape(f.relative_path.string()) << "\",\n";
    out << "      \"logical_bytes\": " << f.logical_bytes << ",\n";
    out << "      \"is_executable\": " << (f.is_executable ? "true" : "false") << ",\n";
    out << "      \"sha256_hash\": \"" << (f.sha256_hash.empty() ? "" : json_escape(f.sha256_hash)) << "\"\n";
    out << "    }";
    if (i + 1 < files.size()) out << ",";
    out << "\n";
  }
  out << "  ]\n";
  out << "}\n";
  return out.str();
}

std::optional<DlcManifest> DlcManifest::from_json(const std::string& json) {
  DlcManifest manifest;
  size_t pos = 0;

  auto skip_ws = [&]() {
    while (pos < json.size() && std::isspace(json[pos])) ++pos;
  };
  auto expect = [&](char c) {
    skip_ws();
    if (pos >= json.size() || json[pos] != c) return false;
    ++pos;
    return true;
  };
  auto parse_key = [&](std::string& key) {
    skip_ws();
    if (pos >= json.size() || json[pos] != '"') return false;
    ++pos;
    key.clear();
    while (pos < json.size() && json[pos] != '"') key += json[pos++];
    if (pos < json.size() && json[pos] == '"') ++pos;
    return true;
  };

  if (!expect('{')) return std::nullopt;

  while (pos < json.size()) {
    skip_ws();
    if (json[pos] == '}') { ++pos; break; }
    if (json[pos] == ',') { ++pos; continue; }

    std::string key;
    if (!parse_key(key)) return std::nullopt;
    if (!expect(':')) return std::nullopt;

    if (key == "schema_version") {
      if (auto v = json_parse_number(json, pos)) manifest.schema_version = static_cast<int>(*v);
    } else if (key == "source_container") {
      if (auto v = json_parse_string(json, pos)) manifest.source_container = *v;
    } else if (key == "content_id") {
      if (auto v = json_parse_string(json, pos)) manifest.content_id = *v;
    } else if (key == "title_id") {
      if (auto v = json_parse_number(json, pos)) manifest.title_id = static_cast<uint32_t>(*v);
    } else if (key == "media_id") {
      if (auto v = json_parse_number(json, pos)) manifest.media_id = static_cast<uint32_t>(*v);
    } else if (key == "version") {
      if (auto v = json_parse_number(json, pos)) manifest.version = static_cast<uint32_t>(*v);
    } else if (key == "base_version") {
      if (auto v = json_parse_number(json, pos)) manifest.base_version = static_cast<uint32_t>(*v);
    } else if (key == "content_type_name") {
      if (auto v = json_parse_string(json, pos)) manifest.content_type_name = *v;
    } else if (key == "install_timestamp") {
      if (auto v = json_parse_number(json, pos)) manifest.install_timestamp = *v;
    } else if (key == "installed_path") {
      if (auto v = json_parse_string(json, pos)) manifest.installed_path = *v;
    } else if (key == "display_name") {
      if (auto v = json_parse_string(json, pos)) manifest.display_name = *v;
    } else if (key == "file_count") {
      if (auto v = json_parse_number(json, pos)) manifest.file_count = static_cast<uint32_t>(*v);
    } else if (key == "directory_count") {
      if (auto v = json_parse_number(json, pos)) manifest.directory_count = static_cast<uint32_t>(*v);
    } else if (key == "total_logical_bytes") {
      if (auto v = json_parse_number(json, pos)) manifest.total_logical_bytes = *v;
    } else if (key == "package_type") {
      if (auto v = json_parse_string(json, pos)) manifest.package_type = *v;
    } else if (key == "inferred_name") {
      if (auto v = json_parse_string(json, pos)) manifest.inferred_name = *v;
    } else if (key == "executable_modules") {
      skip_ws();
      if (pos < json.size() && json[pos] == '[') {
        ++pos;
        while (pos < json.size()) {
          skip_ws();
          if (json[pos] == ']') { ++pos; break; }
          if (json[pos] == ',') { ++pos; continue; }
          if (auto v = json_parse_string(json, pos)) manifest.executable_modules.push_back(*v);
        }
      }
    } else if (key == "files") {
      skip_ws();
      if (pos < json.size() && json[pos] == '[') {
        ++pos;
        while (pos < json.size()) {
          skip_ws();
          if (json[pos] == ']') { ++pos; break; }
          if (json[pos] == ',') { ++pos; continue; }
          if (json[pos] != '{') { ++pos; continue; }
          ++pos;
          DlcFileEntry entry;
          while (pos < json.size()) {
            skip_ws();
            if (json[pos] == '}') { ++pos; break; }
            if (json[pos] == ',') { ++pos; continue; }
            std::string fkey;
            if (!parse_key(fkey)) { ++pos; continue; }
            if (!expect(':')) { ++pos; continue; }
            if (fkey == "relative_path") {
              if (auto v = json_parse_string(json, pos)) entry.relative_path = *v;
            } else if (fkey == "logical_bytes") {
              if (auto v = json_parse_number(json, pos)) entry.logical_bytes = *v;
            } else if (fkey == "is_executable") {
              if (auto v = json_parse_string(json, pos)) entry.is_executable = (*v == "true");
            } else if (fkey == "sha256_hash") {
              if (auto v = json_parse_string(json, pos)) entry.sha256_hash = *v;
            }
          }
          manifest.files.push_back(entry);
        }
      }
    }
    ++pos;
  }
  return manifest;
}

bool DlcManifest::write_to_file(const fs::path& path) const {
  std::ofstream out(path, std::ios::binary | std::ios::trunc);
  if (!out) return false;
  out << to_json();
  return out.good();
}

std::optional<DlcManifest> DlcManifest::read_from_file(const fs::path& path) {
  std::ifstream in(path, std::ios::binary);
  if (!in) return std::nullopt;
  std::string json((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
  return from_json(json);
}

// ---------------------------------------------------------------------------
// DlcImportResult serialization
// ---------------------------------------------------------------------------

std::string DlcImportResult::to_json() const {
  std::ostringstream out;
  out << "{\n";
  out << "  \"success\": " << (success ? "true" : "false") << ",\n";
  out << "  \"content_id\": \"" << json_escape(content_id) << "\",\n";
  out << "  \"installed_path\": \"" << json_escape(installed_path.string()) << "\",\n";
  out << "  \"manifest_path\": \"" << json_escape(manifest_path.string()) << "\",\n";
  out << "  \"errors\": [";
  for (size_t i = 0; i < errors.size(); ++i) {
    if (i > 0) out << ", ";
    out << "\"" << json_escape(errors[i]) << "\"";
  }
  out << "],\n";
  out << "  \"warnings\": [";
  for (size_t i = 0; i < warnings.size(); ++i) {
    if (i > 0) out << ", ";
    out << "\"" << json_escape(warnings[i]) << "\"";
  }
  out << "]\n";
  out << "}\n";
  return out.str();
}

std::optional<DlcImportResult> DlcImportResult::from_json(const std::string& json) {
  DlcImportResult result;
  size_t pos = 0;

  auto skip_ws = [&]() {
    while (pos < json.size() && std::isspace(json[pos])) ++pos;
  };
  auto expect = [&](char c) {
    skip_ws();
    if (pos >= json.size() || json[pos] != c) return false;
    ++pos;
    return true;
  };
  auto parse_key = [&](std::string& key) {
    skip_ws();
    if (pos >= json.size() || json[pos] != '"') return false;
    ++pos;
    key.clear();
    while (pos < json.size() && json[pos] != '"') key += json[pos++];
    if (pos < json.size() && json[pos] == '"') ++pos;
    return true;
  };
  auto parse_bool = [&]() -> std::optional<bool> {
    skip_ws();
    if (pos + 4 <= json.size() && json.substr(pos, 4) == "true") { pos += 4; return true; }
    if (pos + 5 <= json.size() && json.substr(pos, 5) == "false") { pos += 5; return false; }
    return std::nullopt;
  };

  if (!expect('{')) return std::nullopt;

  while (pos < json.size()) {
    skip_ws();
    if (json[pos] == '}') { ++pos; break; }
    if (json[pos] == ',') { ++pos; continue; }

    std::string key;
    if (!parse_key(key)) return std::nullopt;
    if (!expect(':')) return std::nullopt;

    if (key == "success") {
      if (auto v = parse_bool()) result.success = *v;
    } else if (key == "content_id") {
      if (auto v = json_parse_string(json, pos)) result.content_id = *v;
    } else if (key == "installed_path") {
      if (auto v = json_parse_string(json, pos)) result.installed_path = *v;
    } else if (key == "manifest_path") {
      if (auto v = json_parse_string(json, pos)) result.manifest_path = *v;
    } else if (key == "errors") {
      skip_ws();
      if (pos < json.size() && json[pos] == '[') {
        ++pos;
        while (pos < json.size()) {
          skip_ws();
          if (json[pos] == ']') { ++pos; break; }
          if (json[pos] == ',') { ++pos; continue; }
          if (auto v = json_parse_string(json, pos)) result.errors.push_back(*v);
        }
      }
    } else if (key == "warnings") {
      skip_ws();
      if (pos < json.size() && json[pos] == '[') {
        ++pos;
        while (pos < json.size()) {
          skip_ws();
          if (json[pos] == ']') { ++pos; break; }
          if (json[pos] == ',') { ++pos; continue; }
          if (auto v = json_parse_string(json, pos)) result.warnings.push_back(*v);
        }
      }
    }
    ++pos;
  }
  return result;
}

// ---------------------------------------------------------------------------
// DlcManager
// ---------------------------------------------------------------------------

DlcManager::DlcManager(const fs::path& content_root, uint32_t title_id)
    : content_root_(content_root), title_id_(title_id) {}

fs::path DlcManager::marketplace_dir() const {
  std::ostringstream xuid_ss;
  xuid_ss << std::hex << std::uppercase << std::setfill('0') << std::setw(16) << uint64_t(0);
  std::ostringstream title_ss;
  title_ss << std::hex << std::uppercase << std::setfill('0') << std::setw(8) << title_id_;
  std::ostringstream type_ss;
  type_ss << std::hex << std::uppercase << std::setfill('0') << std::setw(8) << uint32_t(0x00000002);
  return content_root_ / xuid_ss.str() / title_ss.str() / type_ss.str();
}

fs::path DlcManager::staging_dir(const fs::path& staging_root, const std::string& content_id) const {
  return staging_root / content_id;
}

std::string DlcManager::compute_sha256(const fs::path& file_path) {
  std::ifstream in(file_path, std::ios::binary | std::ios::ate);
  if (!in) return "";
  auto size = in.tellg();
  in.seekg(0);
  if (size <= 0) return "";

  sha256::SHA256 sha;
  // Stream-friendly: feed the file in chunks.
  std::vector<uint8_t> buffer(1024 * 1024);
  while (in) {
    in.read(reinterpret_cast<char*>(buffer.data()), buffer.size());
    auto read = in.gcount();
    if (read > 0) {
      sha.add(buffer.data(), static_cast<size_t>(read));
    }
  }
  return sha.getHash();
}

bool DlcManager::extract_to_staging(const fs::path& container_path,
                                    const fs::path& staging_dir,
                                    DlcManifest& manifest,
                                    std::vector<std::string>& errors) {
  auto header = StfsContainerDevice::ReadPackageHeader(container_path);
  if (!header) {
    errors.push_back("source is neither a directory nor a valid Xbox 360 STFS package");
    return false;
  }

  manifest.title_id = header->metadata.execution_info.title_id;
  manifest.media_id = header->metadata.execution_info.media_id;
  manifest.version = header->metadata.execution_info.version_value;
  manifest.base_version = header->metadata.execution_info.base_version_value;
  manifest.content_id = container_path.filename().string();
  manifest.source_container = container_path.string();

  auto display_name_uc = header->metadata.display_name(rex::system::XLanguage::kEnglish);
  if (!display_name_uc.empty()) {
    manifest.display_name = rex::string::to_utf8(display_name_uc);
  } else {
    manifest.display_name = container_path.filename().string();
  }
  manifest.content_type_name = "MarketplaceContent";

  StfsContainerDevice device("", container_path);
  if (!device.Initialize()) {
    errors.push_back("the STFS package is corrupt or incomplete");
    return false;
  }

  Entry* root = device.ResolvePath("/");
  if (!root) {
    errors.push_back("the STFS package has no readable root directory");
    return false;
  }

  std::error_code ec;
  fs::create_directories(staging_dir, ec);
  if (ec) {
    errors.push_back("cannot create staging directory: " + ec.message());
    return false;
  }

  std::queue<Entry*> pending;
  for (const auto& child : root->children()) pending.push(child.get());

  std::vector<uint8_t> buffer(1024 * 1024);
  uint32_t file_count = 0;
  uint32_t dir_count = 0;
  uint64_t total_bytes = 0;

  while (!pending.empty()) {
    Entry* entry = pending.front();
    pending.pop();
    for (const auto& child : entry->children()) pending.push(child.get());

    fs::path relative = fs::u8path(entry->path());
    if (relative.is_absolute()) relative = relative.relative_path();

    // Basic path safety checks before writing anything host-side.
    if (relative.empty() || relative.is_absolute()) {
      errors.push_back("the STFS package contains an unsafe path");
      return false;
    }
    for (const auto& component : relative) {
      if (component == "..") {
        errors.push_back("the STFS package contains an unsafe path (..)");
        return false;
      }
    }

    fs::path output = staging_dir / relative;
    bool is_directory =
        (entry->attributes() & rex::filesystem::kFileAttributeDirectory) != 0;

    if (is_directory) {
      ++dir_count;
      fs::create_directories(output, ec);
      if (ec) {
        errors.push_back("cannot create extracted directory: " + ec.message());
        return false;
      }
      continue;
    }

    ++file_count;
    total_bytes += entry->size();

    fs::create_directories(output.parent_path(), ec);
    if (ec) {
      errors.push_back("cannot create extracted directory: " + ec.message());
      return false;
    }

    File* input = nullptr;
    if (entry->Open(FileAccess::kFileReadData, &input) != 0 || !input) {
      errors.push_back("cannot read " + entry->path() + " from the STFS package");
      return false;
    }

    std::ofstream out(output, std::ios::binary | std::ios::trunc);
    if (!out) {
      input->Destroy();
      errors.push_back("cannot create " + output.string());
      return false;
    }

    uint64_t offset = 0;
    while (offset < entry->size()) {
      const uint64_t requested =
          std::min(static_cast<uint64_t>(buffer.size()), entry->size() - offset);
      uint64_t actual = 0;
      if (input->ReadSync(std::span<uint8_t>(buffer.data(), static_cast<size_t>(requested)),
                          offset, &actual) != 0 || actual == 0) {
        input->Destroy();
        errors.push_back("the STFS package ended while extracting " + entry->path());
        return false;
      }
      out.write(reinterpret_cast<const char*>(buffer.data()),
                static_cast<std::streamsize>(actual));
      if (!out) {
        input->Destroy();
        errors.push_back("disk write failed while extracting " + entry->path());
        return false;
      }
      offset += actual;
    }
    input->Destroy();

    DlcFileEntry file_entry;
    file_entry.relative_path = relative;
    file_entry.logical_bytes = entry->size();

    std::string generic = relative.generic_string();
    if (generic.size() >= 4 && (generic.ends_with(".dll") || generic.ends_with(".xex") ||
                                 generic.ends_with(".dllp"))) {
      file_entry.is_executable = true;
      if (compute_sha256_enabled_) {
        file_entry.sha256_hash = compute_sha256(output);
      }
      manifest.executable_modules.push_back(generic);
    }

    manifest.files.push_back(file_entry);
  }

  manifest.file_count = file_count;
  manifest.directory_count = dir_count;
  manifest.total_logical_bytes = total_bytes;
  return true;
}

void DlcManager::classify_package(DlcManifest& manifest) {
  bool has_player_dll = false;
  bool has_enemy_dll = false;
  bool has_music = false;
  bool has_stage_assets = false;
  std::string player_name;

  for (const auto& file : manifest.files) {
    const std::string& path = file.relative_path.generic_string();

    if (path.find("data/data/player/dll") != std::string::npos && path.ends_with(".dll")) {
      has_player_dll = true;
      size_t pos = path.rfind('/');
      if (pos != std::string::npos) {
        std::string fname = path.substr(pos + 1);
        if (fname.starts_with("dll") && fname.ends_with(".dll")) {
          player_name = fname.substr(3, fname.size() - 7);
        }
      }
    }

    if (path.find("dll/dll/enemy/DLL_") != std::string::npos && path.ends_with(".dll")) {
      has_enemy_dll = true;
    }

    if (path.find("data/data/sound/BGM_") != std::string::npos &&
        (path.ends_with(".xsb") || path.ends_with(".xwb"))) {
      has_music = true;
    }

    if (path.find("data/data/arc/stage") != std::string::npos ||
        path.find("data/data/stage/stage") != std::string::npos) {
      has_stage_assets = true;
    }
  }

  if (has_player_dll) {
    manifest.package_type = "character";
    manifest.inferred_name = player_name.empty() ? "Unknown Character" : player_name;
  } else if (has_enemy_dll || has_stage_assets) {
    manifest.package_type = "stage";
    manifest.inferred_name = "Stage Pack";
  } else if (has_music) {
    manifest.package_type = "music";
    manifest.inferred_name = "Music Pack";
  } else {
    manifest.package_type = "unknown";
    manifest.inferred_name = "Unknown Package";
  }
}

std::string DlcManager::generate_display_name(const DlcManifest& manifest) {
  if (!manifest.display_name.empty()) return manifest.display_name;
  if (!manifest.inferred_name.empty()) return manifest.inferred_name;
  return manifest.content_id;
}

DlcImportResult DlcManager::install(const fs::path& container_path,
                                    const fs::path& staging_root,
                                    bool compute_hashes) {
  DlcImportResult result;
  result.content_id = container_path.filename().string();

  if (!fs::exists(container_path)) {
    result.errors.push_back("source does not exist: " + container_path.string());
    return result;
  }
  if (fs::is_symlink(container_path)) {
    result.errors.push_back("source cannot be a symbolic link");
    return result;
  }

  fs::path staging = staging_dir(staging_root, result.content_id);
  std::error_code ec;
  fs::remove_all(staging, ec);

  DlcManifest manifest;
  manifest.schema_version = 1;
  manifest.install_timestamp = std::time(nullptr);

  if (!extract_to_staging(container_path, staging, manifest, result.errors)) {
    result.success = false;
    return result;
  }

  compute_sha256_enabled_ = compute_hashes;
  classify_package(manifest);
  manifest.display_name = generate_display_name(manifest);

  result.installed_path = marketplace_dir() / result.content_id;
  manifest.installed_path = result.installed_path.string();

  fs::path manifest_path = staging / "dlc_manifest.json";
  if (!manifest.write_to_file(manifest_path)) {
    result.errors.push_back("cannot write manifest file");
    return result;
  }
  result.manifest_path = manifest_path;

  std::error_code ec2;
  fs::create_directories(result.installed_path, ec2);
  if (ec2) {
    result.errors.push_back("cannot create install directory: " + ec2.message());
    return result;
  }

  for (const auto& file_entry : manifest.files) {
    fs::path src = staging / file_entry.relative_path;
    fs::path dst = result.installed_path / file_entry.relative_path;

    if (fs::is_directory(src)) {
      fs::create_directories(dst, ec2);
    } else if (fs::is_regular_file(src)) {
      fs::create_directories(dst.parent_path(), ec2);
      if (ec2) {
        result.errors.push_back("cannot create directory: " + ec2.message());
        return result;
      }
      fs::copy_file(src, dst, fs::copy_options::none, ec2);
      if (ec2) {
        result.errors.push_back("copy failed: " + ec2.message());
        return result;
      }
    }
  }

  // Replicate the ReXGlue marketplace-content header layout so XAM
  // enumeration sees this package the same way it would a normal install.
  std::error_code ec3;
  fs::path headers_dir = result.installed_path;
  for (int i = 0; i < 2; ++i) headers_dir /= "..";
  headers_dir /= "Headers";
  headers_dir /= "00000002";

  fs::create_directories(headers_dir, ec3);
  if (ec3) {
    result.errors.push_back("cannot create Headers directory: " + ec3.message());
    return result;
  }

  fs::path header_path = headers_dir / (result.content_id + ".header");
  std::ofstream header_file(header_path, std::ios::binary | std::ios::trunc);
  if (!header_file) {
    result.errors.push_back("cannot create header file");
    return result;
  }

  // 0x148-byte XCONTENT_AGGREGATE_DATA + 4-byte license mask placeholder.
  std::vector<uint8_t> header_data(0x14C, 0);
  header_file.write(reinterpret_cast<const char*>(header_data.data()), header_data.size());
  header_file.close();

  result.success = true;
  return result;
}

std::vector<DlcEntry> DlcManager::list_installed() const {
  std::vector<DlcEntry> entries;
  fs::path mkt_dir = marketplace_dir();
  if (!fs::exists(mkt_dir)) return entries;

  for (const auto& entry : fs::directory_iterator(mkt_dir)) {
    if (!entry.is_directory()) continue;

    DlcEntry dlc_entry;
    dlc_entry.content_id = entry.path().filename().string();
    dlc_entry.installed_path = entry.path();
    dlc_entry.is_installed = true;

    fs::path manifest_path = entry.path() / "dlc_manifest.json";
    if (fs::exists(manifest_path)) {
      auto manifest = DlcManifest::read_from_file(manifest_path);
      if (manifest) {
        dlc_entry.display_name = manifest->display_name;
        dlc_entry.package_type = manifest->package_type;
        dlc_entry.install_timestamp = manifest->install_timestamp;
        dlc_entry.manifest_path = manifest_path;
      }
    }

    entries.push_back(dlc_entry);
  }
  return entries;
}

std::optional<DlcManifest> DlcManager::get_manifest(const std::string& content_id) const {
  fs::path pkg_dir = marketplace_dir() / content_id;
  if (!fs::exists(pkg_dir)) return std::nullopt;
  fs::path manifest_path = pkg_dir / "dlc_manifest.json";
  return DlcManifest::read_from_file(manifest_path);
}

bool DlcManager::remove(const std::string& content_id) {
  fs::path pkg_dir = marketplace_dir() / content_id;
  if (!fs::exists(pkg_dir)) return false;

  std::error_code ec;
  fs::remove_all(pkg_dir, ec);
  if (ec) return false;

  fs::path headers_dir = pkg_dir;
  for (int i = 0; i < 2; ++i) headers_dir /= "..";
  headers_dir /= "Headers";
  headers_dir /= "00000002";
  fs::path header_path = headers_dir / (content_id + ".header");
  if (fs::exists(header_path)) {
    fs::remove(header_path, ec);
  }
  return true;
}

bool DlcManager::is_installed(const std::string& content_id) const {
  return fs::exists(marketplace_dir() / content_id);
}

}  // namespace harmony::dlc
