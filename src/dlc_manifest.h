#pragma once
#include <cstdint>
#include <filesystem>
#include <string>
#include <vector>
#include <map>
#include <optional>

namespace harmony::dlc {

struct DlcFileEntry {
    std::filesystem::path relative_path;
    uint64_t logical_bytes = 0;
    bool is_executable = false;
    std::string sha256_hash;  // Empty if not computed
};

struct DlcManifest {
    int schema_version = 1;
    std::string source_container;
    std::string content_id;           // Filename of the STFS container
    uint32_t title_id = 0;
    uint32_t media_id = 0;
    uint32_t version = 0;
    uint32_t base_version = 0;
    std::string content_type_name;
    uint64_t install_timestamp = 0;
    std::filesystem::path installed_path;
    std::string display_name;
    
    uint32_t file_count = 0;
    uint32_t directory_count = 0;
    uint64_t total_logical_bytes = 0;
    
    std::vector<DlcFileEntry> files;
    
    // Executable modules found in this package
    std::vector<std::string> executable_modules;
    
    // Package classification
    std::string package_type;         // "character", "stage", "music", "unknown"
    std::string inferred_name;        // Human-readable name
    
    // Serialize to JSON string
    std::string to_json() const;
    
    // Deserialize from JSON string
    static std::optional<DlcManifest> from_json(const std::string& json);
    
    // Write manifest to file
    bool write_to_file(const std::filesystem::path& path) const;
    
    // Read manifest from file
    static std::optional<DlcManifest> read_from_file(const std::filesystem::path& path);
};

// DLC import result
struct DlcImportResult {
    bool success = false;
    std::string content_id;
    std::filesystem::path installed_path;
    std::filesystem::path manifest_path;
    std::vector<std::string> errors;
    std::vector<std::string> warnings;
    
    std::string to_json() const;
    static std::optional<DlcImportResult> from_json(const std::string& json);
};

// DLC entry in the content system
struct DlcEntry {
    std::string content_id;
    std::string display_name;
    std::string package_type;
    std::filesystem::path installed_path;
    std::filesystem::path manifest_path;
    uint64_t install_timestamp = 0;
    bool is_installed = false;
};

// DLC manager - handles installation, enumeration, removal
class DlcManager {
public:
    DlcManager(const std::filesystem::path& content_root, uint32_t title_id);
    
    // Install a DLC package from an STFS container
    DlcImportResult install(const std::filesystem::path& container_path,
                           const std::filesystem::path& staging_root,
                           bool compute_hashes = true);
    
    // List all installed DLC packages
    std::vector<DlcEntry> list_installed() const;
    
    // Get manifest for an installed package
    std::optional<DlcManifest> get_manifest(const std::string& content_id) const;
    
    // Remove an installed DLC package
    bool remove(const std::string& content_id);
    
    // Check if a DLC package is installed
    bool is_installed(const std::string& content_id) const;
    
    // Get the content root path
    const std::filesystem::path& content_root() const { return content_root_; }
    
    // Get the title ID
    uint32_t title_id() const { return title_id_; }
    
private:
    std::filesystem::path content_root_;
    uint32_t title_id_;
    
    // Flag to control SHA256 hash computation
    bool compute_sha256_enabled_ = true;
    
    // Get the marketplace content directory for this title
    std::filesystem::path marketplace_dir() const;
    
    // Get the staging directory
    std::filesystem::path staging_dir(const std::filesystem::path& staging_root,
                                     const std::string& content_id) const;
    
    // Extract STFS container to staging directory
    bool extract_to_staging(const std::filesystem::path& container_path,
                           const std::filesystem::path& staging_dir,
                           DlcManifest& manifest,
                           std::vector<std::string>& errors);
    
    // Compute SHA256 hash of a file
    std::string compute_sha256(const std::filesystem::path& file_path);
    
    // Classify the package type based on contents
    void classify_package(DlcManifest& manifest);
    
    // Generate display name from STFS metadata or content ID
    std::string generate_display_name(const DlcManifest& manifest);
};

}  // namespace harmony::dlc
