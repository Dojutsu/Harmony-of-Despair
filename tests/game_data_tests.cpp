#include "game_data.h"

#include <array>
#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

namespace {

bool Check(bool condition, const char* description) {
  if (!condition) {
    std::cerr << "FAILED: " << description << '\n';
  }
  return condition;
}

void WriteBe32(std::array<uint8_t, 80>& bytes, size_t offset, uint32_t value) {
  bytes[offset] = uint8_t(value >> 24);
  bytes[offset + 1] = uint8_t(value >> 16);
  bytes[offset + 2] = uint8_t(value >> 8);
  bytes[offset + 3] = uint8_t(value);
}

void WriteSyntheticXex(const fs::path& path, uint32_t title_id, uint32_t media_id,
                       uint32_t version) {
  std::array<uint8_t, 80> bytes{};
  WriteBe32(bytes, 0, 0x58455832);
  WriteBe32(bytes, 8, bytes.size());
  WriteBe32(bytes, 20, 1);
  WriteBe32(bytes, 24, 0x00040006);
  WriteBe32(bytes, 28, 40);
  WriteBe32(bytes, 40, media_id);
  WriteBe32(bytes, 44, version);
  WriteBe32(bytes, 48, version);
  WriteBe32(bytes, 52, title_id);
  fs::create_directories(path.parent_path());
  std::ofstream(path, std::ios::binary)
      .write(reinterpret_cast<const char*>(bytes.data()), bytes.size());
}

void Populate(const fs::path& root, uint32_t title_id = 0x58410A7A,
              uint32_t media_id = 0x6480C08F, uint32_t version = 0x00000104) {
  WriteSyntheticXex(root / "default.xex", title_id, media_id, version);
  for (const char* name : {"dllAlucard.dll", "dllAxeArmor.dll", "dllCharlotte.dll",
                           "dllJonathan.dll", "dllShanoa.dll", "dllSoma.dll"}) {
    WriteSyntheticXex(root / "data/player_dll" / name, title_id, media_id, version);
  }
  fs::create_directories(root / "data/assets");
  std::ofstream(root / "data/assets/synthetic.dat") << "synthetic";
}

}  // namespace

int main() {
  const auto unique_suffix =
      std::chrono::steady_clock::now().time_since_epoch().count();
  fs::path base = fs::temp_directory_path() /
                  ("harmonyrecomp-game-data-tests-" +
                   std::to_string(unique_suffix));
  std::error_code ec;
  fs::remove_all(base, ec);

  std::cout << "Checking missing and unsupported inputs\n";
  auto missing = harmony::game_data::ValidateRoot(base / "missing");
  if (!Check(!missing.valid, "missing root must be rejected")) return 1;

  Populate(base / "valid");
  if (!Check(!harmony::game_data::ValidateRoot(base / "valid").valid,
             "uninstalled payload must be rejected"))
    return 1;

  Populate(base / "wrong-title", 0x12345678);
  harmony::game_data::ImportOptions wrong_title;
  wrong_title.source = base / "wrong-title";
  wrong_title.destination = base / "wrong-title-installed";
  if (!Check(!harmony::game_data::Import(wrong_title).valid,
             "wrong title must be rejected"))
    return 1;

  Populate(base / "unsupported", 0x58410A7A, 0x6480C08F, 0x00000204);
  harmony::game_data::ImportOptions unsupported;
  unsupported.source = base / "unsupported";
  unsupported.destination = base / "unsupported-installed";
  if (!Check(!harmony::game_data::Import(unsupported).valid,
             "unsupported version must be rejected"))
    return 1;

  Populate(base / "incomplete");
  fs::remove(base / "incomplete/data/player_dll/dllSoma.dll");
  harmony::game_data::ImportOptions incomplete;
  incomplete.source = base / "incomplete";
  incomplete.destination = base / "incomplete-installed";
  if (!Check(!harmony::game_data::Import(incomplete).valid,
             "incomplete payload must be rejected"))
    return 1;

  std::cout << "Checking transactional import and replacement guard\n";
  harmony::game_data::ImportOptions import;
  import.source = base / "valid";
  import.destination = base / "installed";
  auto imported = harmony::game_data::Import(import);
  if (!Check(imported.valid, "valid payload must import")) return 1;
  if (!Check(harmony::game_data::ValidateRoot(import.destination).valid,
             "imported payload must validate"))
    return 1;

  auto refused_existing = harmony::game_data::Import(import);
  if (!Check(!refused_existing.valid,
             "existing installation must not be replaced without force"))
    return 1;

  std::cout << "Checking symbolic-link rejection\n";
  fs::create_directory_symlink(base / "valid", base / "linked-source", ec);
  if (!ec) {
    import.source = base / "linked-source";
    import.destination = base / "linked-install";
    if (!Check(!harmony::game_data::Import(import).valid,
               "symbolic-link source must be rejected"))
      return 1;
    fs::remove(base / "linked-source", ec);
  }

  std::cout << "Cleaning test fixture\n";
  fs::remove_all(base, ec);
  if (!Check(!ec, "test fixture cleanup must succeed")) return 1;
  return 0;
}
