#include <catch2/catch_test_macros.hpp>
#include <rex/cvar.h>
#include <string>
#include <string_view>

namespace {
struct RestoreUrl {
  std::string previous = rex::cvar::GetFlagByName("session_directory_url");
  ~RestoreUrl() { rex::cvar::SetFlagByName("session_directory_url", previous); }
};
void Accept(std::string_view url) {
  INFO(url);
  REQUIRE(rex::cvar::SetFlagByName("session_directory_url", url));
  CHECK(rex::cvar::GetFlagByName("session_directory_url") == url);
}
void Reject(std::string_view url) {
  INFO(url);
  const auto before = rex::cvar::GetFlagByName("session_directory_url");
  CHECK_FALSE(rex::cvar::SetFlagByName("session_directory_url", url));
  CHECK(rex::cvar::GetFlagByName("session_directory_url") == before);
}
}
TEST_CASE("Directory URLs retain HTTPS and exact loopback HTTP authorities", "[directory][url][security]") {
  RestoreUrl restore;
  for (std::string_view url : {"", "https://example.com", "https://example.com:443", "https://EXAMPLE.com/api/v1/",
      "https://127.0.0.1:8443", "https://[2001:db8::1]:443/api", "https://example.com./base",
      "http://127.0.0.1", "http://127.0.0.1:1", "http://127.0.0.1:65535/path@place",
      "http://localhost:8080/api", "http://LOCALHOST", "http://[::1]", "http://[0:0:0:0:0:0:0:1]:80/api",
      "http://localhost:00080", "https://example.com/path/%2f%2fremote.example"}) Accept(url);
}
TEST_CASE("Directory loopback exemption rejects remote userinfo and authority confusables", "[directory][url][security]") {
  RestoreUrl restore; Accept("https://example.com/base");
  for (std::string_view url : {"http://localhost:80@remote.example", "http://127.0.0.1:80@remote.example",
      "http://localhost@remote.example", "http://localhost:80%40remote.example", "http://localhost%3a80%40remote.example",
      "http://localhost:80\\@remote.example", "http://localhost/\\remote.example", "https://user:pass@example.com",
      "http://localhost.remote.example", "http://127.0.0.10", "http://127.1", "http://2130706433",
      "http://localhost.", "http://[::ffff:127.0.0.1]", "http://[::2]", "http://[2001:db8::1]",
      "http://[::1]:80@remote.example", "https://%65xample.com", "https://remote.example\\@localhost"}) Reject(url);
}
TEST_CASE("Directory URLs reject invalid ports IPv6 and endpoint ambiguity", "[directory][url][security]") {
  RestoreUrl restore; Accept("http://localhost:8080/api");
  for (std::string_view url : {"https://", "http://", "https:///example.com", "ftp://localhost", "HTTPS://example.com",
      "http://localhost:", "http://localhost:0", "http://localhost:65536", "http://localhost:99999999999999999999",
      "http://localhost:-1", "http://localhost:+80", "http://localhost:80:90", "http://localhost:80x",
      "http://localhost?redirect=remote.example", "http://localhost#@remote.example", "https://example.com/api#fragment",
      "https://example.com/api?query=1", "https://[::1", "https://::1", "https://[]", "https://[invalid]",
      "https://[::1]extra", "https://[::1]:", "https://[::1]:65536", "https://[::1%25lo]", "https://example..com",
      "https://-example.com", "https://example-.com", "https://.example.com", "https://example.com/ path"}) Reject(url);
}
TEST_CASE("Directory URL bounds and controls fail before changing configured authority", "[directory][url][security]") {
  RestoreUrl restore; Accept("https://example.com");
  const std::string prefix = "https://example.com/";
  Accept(prefix + std::string(512 - prefix.size(), 'a'));
  Reject(prefix + std::string(513 - prefix.size(), 'a'));
  Reject("https://" + std::string(64, 'a') + ".example.com");
  for (unsigned ch : {0u, 9u, 10u, 13u, 31u, 32u, 127u, 128u, 255u}) {
    for (size_t at : {size_t(7), size_t(12), prefix.size()}) {
      std::string url = prefix + "path"; url.insert(at, 1, char(ch)); Reject(url);
    }
  }
}
