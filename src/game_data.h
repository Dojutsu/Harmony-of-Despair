#pragma once

#include <cstdint>
#include <filesystem>
#include <string>
#include <vector>

namespace harmony::game_data {

inline constexpr uint32_t kTitleId = 0x58410A7A;

struct XexIdentity {
  uint32_t title_id = 0;
  uint32_t media_id = 0;
  uint32_t version = 0;
  uint32_t base_version = 0;
};

struct ValidationResult {
  bool valid = false;
  XexIdentity identity;
  std::vector<std::string> errors;
};

std::filesystem::path DefaultRoot();
std::string FormatVersion(uint32_t version);
ValidationResult ValidateRoot(const std::filesystem::path& root);

struct ImportOptions {
  std::filesystem::path source;
  std::filesystem::path destination;
  bool replace_existing = false;
};

ValidationResult Import(const ImportOptions& options);

}  // namespace harmony::game_data
