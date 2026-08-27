#include <rex/filesystem/devices/stfs_container_device.h>
#include <rex/filesystem/file.h>

#include <algorithm>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <queue>
#include <span>
#include <string>
#include <vector>

namespace fs = std::filesystem;
using rex::filesystem::Entry;
using rex::filesystem::File;
using rex::filesystem::FileAccess;
using rex::filesystem::StfsContainerDevice;

int main(int argc, char** argv) {
  if (argc != 2 && argc != 3) {
    std::cerr << "usage: stfs_inspect <container> [extract-directory]\n";
    return 2;
  }

  const fs::path source = fs::u8path(argv[1]);
  const bool extract = argc == 3;
  const fs::path destination = extract ? fs::u8path(argv[2]) : fs::path{};

  StfsContainerDevice device("", source);
  if (!device.Initialize()) {
    std::cerr << "failed to initialize STFS container\n";
    return 1;
  }

  Entry* root = device.ResolvePath("/");
  if (!root) {
    std::cerr << "failed to resolve STFS root\n";
    return 1;
  }

  uint64_t files = 0;
  uint64_t directories = 0;
  uint64_t logical_size = 0;
  std::queue<Entry*> pending;
  for (const auto& child : root->children()) pending.push(child.get());

  std::vector<uint8_t> buffer(1024 * 1024);
  while (!pending.empty()) {
    Entry* entry = pending.front();
    pending.pop();
    for (const auto& child : entry->children()) pending.push(child.get());

    const bool is_directory =
        (entry->attributes() & rex::filesystem::kFileAttributeDirectory) != 0;
    std::cout << (is_directory ? "D" : "F") << '\t' << entry->size() << '\t'
              << entry->path() << '\n';

    fs::path relative = fs::u8path(entry->path());
    if (relative.is_absolute()) relative = relative.relative_path();
    const fs::path output = destination / relative;

    if (is_directory) {
      ++directories;
      if (extract) fs::create_directories(output);
      continue;
    }

    ++files;
    logical_size += entry->size();
    if (!extract) continue;

    fs::create_directories(output.parent_path());
    File* input = nullptr;
    if (entry->Open(FileAccess::kFileReadData, &input) != 0 || !input) {
      std::cerr << "open failed: " << entry->path() << '\n';
      return 1;
    }

    std::ofstream out(output, std::ios::binary | std::ios::trunc);
    if (!out) {
      input->Destroy();
      std::cerr << "create failed: " << output.string() << '\n';
      return 1;
    }

    size_t offset = 0;
    while (offset < entry->size()) {
      const size_t requested = std::min(buffer.size(), entry->size() - offset);
      size_t actual = 0;
      const rex::X_STATUS status = input->ReadSync(
          std::span<uint8_t>(buffer.data(), requested), offset, &actual);
      if (status != 0 || actual == 0) {
        input->Destroy();
        std::cerr << "read failed at " << offset << ": " << entry->path() << '\n';
        return 1;
      }
      out.write(reinterpret_cast<const char*>(buffer.data()), actual);
      offset += actual;
    }
    input->Destroy();
  }

  std::cerr << "SUMMARY entries=" << (files + directories) << " files=" << files
            << " directories=" << directories << " logical_bytes=" << logical_size << '\n';
  return 0;
}
