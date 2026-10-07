#include <catch2/catch_test_macros.hpp>
#include <rex/cvar.h>
#include <rex/logging.h>
#include <rex/logging/sink.h>
#include <cstdlib>
#include <fstream>
#include <memory>
#include <vector>
#if REX_PLATFORM_LINUX
#include <unistd.h>
namespace {
struct PrivateDiagnostics {
  rex::cvar::testing::ScopedLifecycleOverride lifecycle;
  std::string url = rex::cvar::GetFlagByName("session_directory_url");
  std::string invite = rex::cvar::GetFlagByName("session_directory_invite_code");
  spdlog::level::level_enum previous = rex::GetLoggerRaw(rex::log::core())->level();
  std::shared_ptr<rex::LogCaptureSink> sink = std::make_shared<rex::LogCaptureSink>();
  PrivateDiagnostics() { rex::AddSink(sink); rex::SetCategoryLevel(rex::log::core(), spdlog::level::debug); }
  ~PrivateDiagnostics() {
    rex::cvar::SetFlagByName("session_directory_url", url);
    rex::cvar::SetFlagByName("session_directory_invite_code", invite);
    rex::RemoveSink(sink); rex::SetCategoryLevel(rex::log::core(), previous);
  }
  std::vector<rex::LogEntry> Entries() { std::vector<rex::LogEntry> entries; sink->CopyEntries(entries); return entries; }
};
struct ConfigFile {
  std::string path;
  ConfigFile() { char name[]="/tmp/fsc-private-cvar-XXXXXX";int fd=mkstemp(name); REQUIRE(fd>=0); REQUIRE(close(fd)==0);path=name; }
  ~ConfigFile() { if(!path.empty())unlink(path.c_str()); }
  void Write(std::string_view text) { std::ofstream stream(path,std::ios::trunc);stream<<text;REQUIRE(stream.good()); }
};
}
TEST_CASE("Directory configuration diagnostics redact accepted and rejected values", "[linux][cvar][privacy]") {
  PrivateDiagnostics capture;
  ConfigFile config;
  const std::string accepted="https://example.invalid/PRIVATE_URL_TEST_SENTINEL";
  const std::string rejected="http://localhost:80@PRIVATE_REJECT_TEST_SENTINEL.invalid";
  REQUIRE(rex::cvar::SetFlagByName("session_directory_url", ""));
  REQUIRE(rex::cvar::SetFlagByName("session_directory_invite_code", ""));
  // Reset source precedence to permit the real TOML application path.
  rex::cvar::ResetToDefault("session_directory_url");
  rex::cvar::ResetToDefault("session_directory_invite_code");
  config.Write("session_directory_url = \""+accepted+"\"\nsession_directory_invite_code = \"ABCDEF\"\n");
  rex::cvar::LoadConfig(config.path);
  CHECK(rex::cvar::GetFlagByName("session_directory_url")==accepted);
  CHECK(rex::cvar::GetFlagByName("session_directory_invite_code")=="ABCDEF");
  config.Write("session_directory_url = \""+rejected+"\"\nsession_directory_invite_code = \"PRIVATE_INVALID_CODE_TEST_SENTINEL\"\n");
  rex::cvar::LoadConfig(config.path);
  CHECK(rex::cvar::GetFlagByName("session_directory_url")==accepted);
  CHECK(rex::cvar::GetFlagByName("session_directory_invite_code")=="ABCDEF");
  bool accepted_logged=false, rejected_logged=false;
  for(const auto& entry:capture.Entries()) {
    CHECK(entry.text.find(accepted)==std::string::npos);
    CHECK(entry.text.find(rejected)==std::string::npos);
    CHECK(entry.text.find("ABCDEF")==std::string::npos);
    CHECK(entry.text.find("PRIVATE_INVALID_CODE_TEST_SENTINEL")==std::string::npos);
    accepted_logged|=entry.text.find("Config: session_directory_url = <redacted>")!=std::string::npos;
    rejected_logged|=entry.text.find("custom validation failed for '<redacted>'")!=std::string::npos;
  }
  CHECK(accepted_logged);CHECK(rejected_logged);
}
TEST_CASE("Malformed TOML reports location without echoing source text", "[linux][cvar][privacy]") {
  PrivateDiagnostics capture;
  ConfigFile config;
  config.Write("session_directory_url = \"PRIVATE_MALFORMED_TEST_SENTINEL\" trailing\n");
  rex::cvar::LoadConfig(config.path);
  bool location=false;
  for(const auto& entry:capture.Entries()) {
    CHECK(entry.text.find("PRIVATE_MALFORMED_TEST_SENTINEL")==std::string::npos);
    location|=entry.text.find("at line 1, column")!=std::string::npos;
  }
  CHECK(location);
}
#endif
