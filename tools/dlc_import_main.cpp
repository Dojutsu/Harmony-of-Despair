#include "dlc_manifest.h"
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;
using namespace harmony::dlc;

void PrintUsage() {
    std::cerr << "Usage:\n"
              << "  harmonyrecomp-dlc-import <dlc-container> [--staging <dir>] [--destination <content-root>] [--no-hashes]\n"
              << "  harmonyrecomp-dlc-import --list [--destination <content-root>]\n"
              << "  harmonyrecomp-dlc-import --remove <content-id> [--destination <content-root>]\n"
              << "  harmonyrecomp-dlc-import --verify [--destination <content-root>]\n"
              << "  harmonyrecomp-dlc-import --help\n";
}

std::string FormatHex(uint32_t value) {
    std::ostringstream ss;
    ss << std::hex << std::uppercase << std::setfill('0') << std::setw(8) << value;
    return ss.str();
}

void PrintResult(const DlcImportResult& result) {
    if (!result.success) {
        std::cerr << "Import failed:\n";
        for (const auto& error : result.errors) {
            std::cerr << "  Error: " << error << '\n';
        }
        for (const auto& warning : result.warnings) {
            std::cerr << "  Warning: " << warning << '\n';
        }
        return;
    }
    
    std::cout << "DLC package installed successfully.\n";
    std::cout << "Content ID: " << result.content_id << '\n';
    std::cout << "Installed to: " << result.installed_path.string() << '\n';
    std::cout << "Manifest: " << result.manifest_path.string() << '\n';
    
    if (!result.warnings.empty()) {
        std::cout << "Warnings:\n";
        for (const auto& warning : result.warnings) {
            std::cout << "  - " << warning << '\n';
        }
    }
}

void PrintDlcEntry(const DlcEntry& entry) {
    std::cout << "  Content ID: " << entry.content_id << '\n';
    std::cout << "  Display Name: " << entry.display_name << '\n';
    std::cout << "  Package Type: " << entry.package_type << '\n';
    std::cout << "  Installed: " << (entry.is_installed ? "Yes" : "No") << '\n';
    if (entry.is_installed) {
        std::cout << "  Path: " << entry.installed_path.string() << '\n';
        std::time_t ts = static_cast<std::time_t>(entry.install_timestamp);
        std::cout << "  Installed: " << std::ctime(&ts);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        PrintUsage();
        return 2;
    }
    
    std::string command = argv[1];
    
    DlcManager manager(
        "dlc_content",  // Default content root (relative to the working directory)
        0x58410A7A  // Harmony of Despair title ID
    );
    
    fs::path staging_root = "/tmp/dlc_staging";
    fs::path content_root = manager.content_root();
    bool compute_hashes = true;
    
    // Parse arguments
    for (int i = 2; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--staging" && i + 1 < argc) {
            staging_root = fs::path(argv[++i]);
        } else if (arg == "--destination" && i + 1 < argc) {
            content_root = fs::path(argv[++i]);
            manager = DlcManager(content_root, 0x58410A7A);
        } else if (arg == "--no-hashes") {
            compute_hashes = false;
        } else if (arg == "--help") {
            PrintUsage();
            return 0;
        }
    }
    
    if (command == "--list") {
        std::cout << "Installed DLC packages:\n";
        auto entries = manager.list_installed();
        if (entries.empty()) {
            std::cout << "  No DLC packages installed.\n";
        } else {
            for (const auto& entry : entries) {
                PrintDlcEntry(entry);
                std::cout << '\n';
            }
        }
        std::cout << "Total: " << entries.size() << " package(s)\n";
        return 0;
    }
    
    if (command == "--remove" && argc >= 3) {
        std::string content_id = argv[2];
        std::cout << "Removing DLC package: " << content_id << '\n';
        if (manager.remove(content_id)) {
            std::cout << "Package removed successfully.\n";
            return 0;
        } else {
            std::cerr << "Failed to remove package or package not found.\n";
            return 1;
        }
    }
    
    if (command == "--verify") {
        std::cout << "Verifying DLC installation in: " << content_root.string() << '\n';
        auto entries = manager.list_installed();
        std::cout << "Found " << entries.size() << " installed package(s):\n";
        for (const auto& entry : entries) {
            PrintDlcEntry(entry);
            std::cout << '\n';
        }
        return entries.empty() ? 1 : 0;
    }
    
    if (command == "--help") {
        PrintUsage();
        return 0;
    }
    
    if (argc < 2) {
        PrintUsage();
        return 2;
    }
    
    // Install command
    fs::path container_path = argv[1];
    
    std::cout << "Installing DLC package from: " << container_path.string() << '\n';
    std::cout << "Staging directory: " << staging_root.string() << '\n';
    std::cout << "Content root: " << content_root.string() << '\n';
    std::cout << "Compute SHA256 hashes: " << (compute_hashes ? "Yes" : "No") << '\n';
    std::cout << "Title ID: 58410A7A\n";
    std::cout << "No proprietary game files will be uploaded or shared.\n\n";
    
    auto result = manager.install(container_path, staging_root, compute_hashes);
    PrintResult(result);
    
    return result.success ? 0 : 1;
}
