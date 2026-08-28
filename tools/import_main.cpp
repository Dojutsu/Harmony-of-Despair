#include "game_data.h"

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
               "[--destination <directory>] [--force]\n"
            << "  harmonyrecomp-import --verify [directory]\n";
}

}  // namespace

int main(int argc, char** argv) {
  if (argc >= 2 && std::string(argv[1]) == "--verify") {
    fs::path root = argc >= 3 ? fs::path(argv[2]) : harmony::game_data::DefaultRoot();
    auto result = harmony::game_data::ValidateRoot(root);
    PrintResult(result);
    std::cout << "Game-data directory: " << root.string() << '\n';
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
