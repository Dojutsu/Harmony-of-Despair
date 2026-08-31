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

struct AggregateInventory {
  std::vector<std::filesystem::path> base_packages;
  std::vector<std::filesystem::path> update_packages;
  std::vector<std::filesystem::path> dlc_packages;
  std::vector<std::filesystem::path> wrong_title_packages;
  std::vector<std::filesystem::path> unrelated_files;
  std::vector<std::string> errors;
};

std::filesystem::path DefaultRoot();
std::string FormatVersion(uint32_t version);
ValidationResult ValidateRoot(const std::filesystem::path& root);
ValidationResult ValidateTu2Source(const std::filesystem::path& root);
ValidationResult ValidateTu2Root(const std::filesystem::path& root);
AggregateInventory DiscoverPackages(const std::filesystem::path& source);

struct ImportOptions {
  std::filesystem::path source;
  std::filesystem::path destination;
  bool replace_existing = false;
  bool require_tu2 = false;
};

ValidationResult Import(const ImportOptions& options);
ValidationResult ImportAggregate(const ImportOptions& options,
                                 AggregateInventory* inventory = nullptr);

}  // namespace harmony::game_data
