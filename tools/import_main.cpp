#include "game_data.h"
#include "dlc_manifest.h"

#include <rex/filesystem.h>

#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

namespace {

void PrintResult(const harmony::game_data::ValidationResult& result) {
  if (!result.valid) {
    for (const auto& error : result.errors) std::cerr << "Error: " << error << '\n';
    return;
  }
  std::cout << "Castlevania: Harmony of Despair data verified.\n"
            << "Title ID: 58410A7A\n"
            << "Media ID: " << std::hex << std::uppercase << result.identity.media_id << std::dec
            << "\nVersion: " << harmony::game_data::FormatVersion(result.identity.version) << '\n';
}

void Usage() {
  std::cerr << "Usage:\n"
            << "  harmonyrecomp-import <owned-package-or-extracted-directory> "
               "[--destination <directory>] [--force] [--require-tu2]\n"
            << "  harmonyrecomp-import --verify [directory]\n"
            << "  harmonyrecomp-import --verify-tu2 [directory]\n"
            << "  harmonyrecomp-import --validate-tu2 <directory>\n"
            << "  harmonyrecomp-import --inspect-containers <directory>\n"
            << "  harmonyrecomp-import --aggregate <directory> [--destination <directory>] "
               "[--force] [--install-dlc]\n";
}

void PrintInventory(const harmony::game_data::AggregateInventory& inventory) {
  std::cout << "Container inventory: base=" << inventory.base_packages.size()
            << ", TU2=" << inventory.update_packages.size()
            << ", DLC=" << inventory.dlc_packages.size()
            << ", wrong-title=" << inventory.wrong_title_packages.size()
            << ", unrelated=" << inventory.unrelated_files.size() << '\n';
  for (const auto& error : inventory.errors) std::cerr << "Error: " << error << '\n';
}

fs::path DefaultContentRoot() {
  const fs::path user_folder = rex::filesystem::GetUserFolder();
  if (!user_folder.empty()) return user_folder / "harmonyrecomp";
  return harmony::game_data::DefaultRoot().parent_path() / "content";
}

}  // namespace

int main(int argc, char** argv) {
  if (argc == 3 && std::string(argv[1]) == "--inspect-containers") {
    auto inventory = harmony::game_data::DiscoverPackages(fs::path(argv[2]));
    PrintInventory(inventory);
    const bool valid = inventory.errors.empty() && inventory.base_packages.size() == 1 &&
                       inventory.update_packages.size() == 1;
    if (!valid) {
      if (inventory.base_packages.empty()) std::cerr << "Error: base game package not found\n";
      if (inventory.base_packages.size() > 1)
        std::cerr << "Error: multiple compatible base game packages found; selection is ambiguous\n";
      if (inventory.update_packages.empty()) std::cerr << "Error: required TU2 update package not found\n";
      if (inventory.update_packages.size() > 1)
        std::cerr << "Error: multiple compatible TU2 update packages found; selection is ambiguous\n";
    }
    return valid ? 0 : 1;
  }

  if (argc >= 3 && std::string(argv[1]) == "--aggregate") {
    harmony::game_data::ImportOptions options;
    options.source = fs::path(argv[2]);
    options.destination = harmony::game_data::DefaultRoot();
    bool install_dlc = false;
    for (int i = 3; i < argc; ++i) {
      const std::string argument = argv[i];
      if (argument == "--force") options.replace_existing = true;
      else if (argument == "--install-dlc") install_dlc = true;
      else if (argument == "--destination" && i + 1 < argc)
        options.destination = fs::path(argv[++i]);
      else {
        Usage();
        return 2;
      }
    }
    harmony::game_data::AggregateInventory inventory;
    auto result = harmony::game_data::ImportAggregate(options, &inventory);
    PrintInventory(inventory);
    PrintResult(result);
    if (!result.valid) return 1;
    if (install_dlc && !inventory.dlc_packages.empty()) {
      harmony::dlc::DlcManager manager(DefaultContentRoot(), harmony::game_data::kTitleId);
      const fs::path staging = options.destination.parent_path() / "dlc.importing";
      size_t installed = 0;
      for (const auto& package : inventory.dlc_packages) {
        if (manager.is_installed(package.filename().string())) {
          ++installed;
          continue;
        }
        auto dlc_result = manager.install(package, staging, true);
        if (dlc_result.success) ++installed;
        else {
          std::cerr << "Warning: optional DLC import failed for " << package.filename().string()
                    << '\n';
          for (const auto& error : dlc_result.errors) std::cerr << "  " << error << '\n';
        }
      }
      std::cout << "Optional DLC installed: " << installed << "/"
                << inventory.dlc_packages.size() << '\n';
    }
    std::cout << "Aggregate import complete. Launch HarmonyRecomp normally.\n";
    return 0;
  }
  if (argc >= 2 &&
      (std::string(argv[1]) == "--verify" || std::string(argv[1]) == "--verify-tu2")) {
    fs::path root = argc >= 3 ? fs::path(argv[2]) : harmony::game_data::DefaultRoot();
    auto result = std::string(argv[1]) == "--verify-tu2"
                      ? harmony::game_data::ValidateTu2Root(root)
                      : harmony::game_data::ValidateRoot(root);
    PrintResult(result);
    std::cout << "Game-data directory: " << root.string() << '\n';
    return result.valid ? 0 : 1;
  }
  if (argc == 3 && std::string(argv[1]) == "--validate-tu2") {
    auto result = harmony::game_data::ValidateTu2Source(fs::path(argv[2]));
    PrintResult(result);
    return result.valid ? 0 : 1;
  }
  if (argc < 2) {
    Usage();
    return 2;
  }

  harmony::game_data::ImportOptions options;
  options.source = fs::path(argv[1]);
  options.destination = harmony::game_data::DefaultRoot();
  for (int i = 2; i < argc; ++i) {
    std::string argument = argv[i];
    if (argument == "--force") {
      options.replace_existing = true;
    } else if (argument == "--require-tu2") {
      options.require_tu2 = true;
    } else if (argument == "--destination" && i + 1 < argc) {
      options.destination = fs::path(argv[++i]);
    } else {
      Usage();
      return 2;
    }
  }

  std::cout << "Importing locally to " << options.destination.string() << "\n"
            << "No game files or hashes will be uploaded.\n";
  auto result = harmony::game_data::Import(options);
  PrintResult(result);
  if (!result.valid) return 1;
  std::cout << "Import complete. Launch HarmonyRecomp normally.\n";
  return 0;
}
