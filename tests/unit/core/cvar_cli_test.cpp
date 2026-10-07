#include <rex/cvar.h>
#include <algorithm>
#include <charconv>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

REXCVAR_DEFINE_STRING(cvar_cli_alpha, "ALPHA", "Test", "Fresh CLI string");
REXCVAR_DEFINE_STRING(cvar_cli_beta, "BETA", "Test", "Adjacent CLI string");
REXCVAR_DEFINE_STRING(cvar_cli_gamma, "GAMMA", "Test", "Raw CLI string");
REXCVAR_DEFINE_INT32(cvar_cli_number, 42, "Test", "Numeric CLI value");
REXCVAR_DEFINE_BOOL(cvar_cli_boolean, false, "Test", "Boolean CLI value");
REXCVAR_DEFINE_BOOL(cvar_cli_default_boolean, true, "Test", "Negated CLI value");
REXCVAR_DEFINE_STRING(cvar_cli_initial, "INITIAL", "Test", "Initial-only CLI string")
    .lifecycle(rex::cvar::Lifecycle::kInitOnly);
REXCVAR_DEFINE_STRING(cvar_cli_restart, "RESTART", "Test", "Restart CLI string")
    .lifecycle(rex::cvar::Lifecycle::kRequiresRestart);

namespace {
using rex::cvar::Source;
unsigned checks = 0;
void Check(bool ok, const char* message) {
  ++checks; if (!ok) throw std::runtime_error(message);
}
void Value(std::string_view name, std::string_view expected, Source source = Source::kCommandLine) {
  const auto actual = rex::cvar::GetFlagByName(name);
  if (actual != expected) std::cerr << "value mismatch for " << name << " expected-size=" << expected.size()
                                  << " actual-size=" << actual.size() << '\n';
  Check(actual == expected, "actual cvar value matches expected");
  const auto actual_source = rex::cvar::GetFlagSource(name);
  if (actual_source != source) std::cerr << "source mismatch for " << name << " expected=" << static_cast<int>(source)
                                        << " actual=" << static_cast<int>(actual_source) << '\n';
  Check(actual_source == source, "actual cvar source matches expected");
}
std::vector<std::string> Init(std::vector<std::string> args) {
  args.insert(args.begin(), "native-cvar-cli");
  const auto original = args;
  std::vector<char*> pointers; for (auto& arg : args) pointers.push_back(arg.data());
  pointers.push_back(nullptr); const auto pointer_snapshot = pointers;
  auto result = rex::cvar::Init(static_cast<int>(args.size()), pointers.data());
  Check(args == original, "Init preserves all original argument bytes");
  Check(pointers == pointer_snapshot, "Init preserves caller argv pointers and null sentinel");
  return result;
}
struct Config {
  std::filesystem::path path;
  explicit Config(const char* text) {
    char file[] = "/tmp/rex-cvar-cli-XXXXXX";
    const auto fd = ::mkstemp(file); Check(fd >= 0, "create owned config fixture"); ::close(fd); path = file;
    std::ofstream stream(path); stream << text; Check(bool(stream), "write owned config fixture");
  }
  ~Config() { std::error_code error; std::filesystem::remove(path, error); }
};
rex::cvar::FlagEntry LateString(const char* name, std::string& value) {
  rex::cvar::FlagEntry entry{}; entry.name = name; entry.type = rex::cvar::FlagType::String;
  entry.setter = [&value](std::string_view input) { value = input; return true; };
  entry.getter = [&value] { return value; }; entry.default_value = value; return entry;
}
void Scenario(std::string_view name) {
  if (name == "adjacent") {
    const auto rest = Init({"left", "--cvar_cli_alpha=", "--cvar_cli_beta=", "--cvar_cli_gamma=value", "right"});
    Value("cvar_cli_alpha", ""); Value("cvar_cli_beta", ""); Value("cvar_cli_gamma", "value");
    Check(rest == std::vector<std::string>({"left", "right"}), "adjacent empties preserve positional order");
  } else if (name == "separated") {
    Check(Init({"--cvar_cli_alpha", "", "--cvar_cli_beta", "", "--cvar_cli_gamma=value"}).empty(),
          "separated empty arguments are consumed exactly once");
    Value("cvar_cli_alpha", ""); Value("cvar_cli_beta", ""); Value("cvar_cli_gamma", "value");
  } else if (name == "raw-value") {
    const auto rest = Init({"--cvar_cli_alpha", "--cvar_cli_beta=", "--cvar_cli_beta=value",
                            "--cvar_cli_gamma=--cvar_cli_alpha=", "literal", "", "tail"});
    Value("cvar_cli_alpha", "--cvar_cli_beta="); Value("cvar_cli_beta", "value");
    Value("cvar_cli_gamma", "--cvar_cli_alpha=");
    Check(rest == std::vector<std::string>({"literal", "", "tail"}), "raw positional bytes and empty positional preserved");
  } else if (name == "terminator") {
    const auto rest = Init({"--cvar_cli_alpha=", "--", "--cvar_cli_beta=", "literal", "", "--cvar_cli_late=ignored"});
    Value("cvar_cli_alpha", ""); Value("cvar_cli_beta", "BETA", Source::kDefault);
    Check(rest == std::vector<std::string>({"--cvar_cli_beta=", "literal", "", "--cvar_cli_late=ignored"}),
          "terminator preserves literal option-shaped positional tail");
    std::string late = "LATE"; rex::cvar::FlagRegistrar registrar(LateString("cvar_cli_late", late));
    Value("cvar_cli_late", "LATE", Source::kDefault);
  } else if (name == "consumed-separator") {
    Check(Init({"--cvar_cli_alpha", "--", "--cvar_cli_beta=", "--cvar_cli_gamma=value"}).empty(),
          "separator consumed as required string value does not end option parsing");
    Value("cvar_cli_alpha", "--"); Value("cvar_cli_beta", ""); Value("cvar_cli_gamma", "value");
  } else if (name == "numeric") {
    Check(Init({"--cvar_cli_alpha=", "--cvar_cli_number=not-a-number", "--cvar_cli_beta=value"}).empty(),
          "invalid numeric setter cannot consume adjacent options");
    Value("cvar_cli_number", "42", Source::kDefault); Value("cvar_cli_alpha", ""); Value("cvar_cli_beta", "value");
  } else if (name == "numeric-valid") {
    Init({"--cvar_cli_alpha=", "--cvar_cli_number=-12", "--cvar_cli_beta=value"});
    Value("cvar_cli_number", "-12"); Value("cvar_cli_alpha", ""); Value("cvar_cli_beta", "value");
  } else if (name == "boolean-empty") {
    Init({"--cvar_cli_boolean=", "--cvar_cli_alpha=", "--no-cvar_cli_default_boolean=", "--cvar_cli_beta=value"});
    Value("cvar_cli_boolean", "true"); Value("cvar_cli_default_boolean", "false");
    Value("cvar_cli_alpha", ""); Value("cvar_cli_beta", "value");
  } else if (name == "boolean-invalid") {
    Init({"--cvar_cli_default_boolean=not-a-boolean"});
    // Existing CLI11 flag conversion uses false for this token; retain its
    // command-line source rather than introducing new boolean syntax rules.
    Value("cvar_cli_default_boolean", "false");
  } else if (name == "precedence") {
    Config config("cvar_cli_alpha = \"CONFIG\"\ncvar_cli_initial = \"CONFIG\"\ncvar_cli_restart = \"CONFIG\"\n");
    rex::cvar::LoadConfig(config.path);
    Check(::setenv("REX_CVAR_CLI_ALPHA", "ENV", 1) == 0, "set fixture environment");
    Init({"--cvar_cli_alpha=", "--cvar_cli_initial=", "--cvar_cli_restart="});
    rex::cvar::ApplyEnvironment(); rex::cvar::LoadConfig(config.path);
    Value("cvar_cli_alpha", ""); Value("cvar_cli_initial", ""); Value("cvar_cli_restart", "");
    rex::cvar::FinalizeInit();
    Check(!rex::cvar::SetFlagByName("cvar_cli_initial", "runtime"), "empty init-only CLI value remains protected after finalize");
    Value("cvar_cli_initial", "");
    Check(rex::cvar::SetFlagByName("cvar_cli_alpha", "runtime"), "ordinary runtime override still wins");
    Value("cvar_cli_alpha", "runtime", Source::kRuntime);
    Check(rex::cvar::SetFlagByName("cvar_cli_restart", "runtime"), "requires-restart lifecycle still accepts runtime write");
    const auto pending = rex::cvar::GetPendingRestartFlags();
    Check(std::find(pending.begin(), pending.end(), "cvar_cli_restart") != pending.end(), "restart lifecycle records pending change");
    ::unsetenv("REX_CVAR_CLI_ALPHA");
  } else if (name == "late") {
    Config config("cvar_cli_late_string = \"CONFIG\"\ncvar_cli_late_number = 7\ncvar_cli_late_boolean = false\ncvar_cli_late_negative = true\n");
    rex::cvar::LoadConfig(config.path);
    Check(::setenv("REX_CVAR_CLI_LATE_STRING", "ENV", 1) == 0 &&
          ::setenv("REX_CVAR_CLI_LATE_NUMBER", "123", 1) == 0, "set late fixture environment");
    Check(Init({"--cvar_cli_late_string=", "--cvar_cli_late_number=bad", "--cvar_cli_late_boolean",
                "--no-cvar_cli_late_negative", "--cvar_cli_alpha="}).empty(), "unknown late options retain original forms");
    rex::cvar::FinalizeInit();
    std::string value = "LATE";
    auto entry = LateString("cvar_cli_late_string", value); entry.lifecycle = rex::cvar::Lifecycle::kInitOnly;
    rex::cvar::FlagRegistrar string(std::move(entry)); Value("cvar_cli_late_string", "");
    Check(!rex::cvar::SetFlagByName("cvar_cli_late_string", "runtime"), "late init-only empty replay retains lifecycle");
    int32_t number = 42; rex::cvar::FlagEntry number_entry{};
    number_entry.name = "cvar_cli_late_number"; number_entry.type = rex::cvar::FlagType::Int32;
    number_entry.setter = [&number](std::string_view input) {
      int32_t parsed = 0; auto [end, error] = std::from_chars(input.data(), input.data() + input.size(), parsed);
      if (error != std::errc{} || end != input.data() + input.size()) return false;
      number = parsed; return true;
    };
    number_entry.getter = [&number] { return std::to_string(number); }; number_entry.default_value = "42";
    rex::cvar::FlagRegistrar numeric(std::move(number_entry)); Value("cvar_cli_late_number", "123", Source::kEnvironment);
    bool boolean = false, negative = true;
    auto boolean_entry = LateString("cvar_cli_late_boolean", value);
    boolean_entry.type = rex::cvar::FlagType::Boolean;
    boolean_entry.setter = [&boolean](std::string_view input) { boolean = input == "true"; return true; };
    boolean_entry.getter = [&boolean] { return boolean ? "true" : "false"; }; boolean_entry.default_value = "false";
    rex::cvar::FlagRegistrar truth(std::move(boolean_entry)); Value("cvar_cli_late_boolean", "true");
    auto negative_entry = LateString("cvar_cli_late_negative", value);
    negative_entry.type = rex::cvar::FlagType::Boolean;
    negative_entry.setter = [&negative](std::string_view input) { negative = input == "true"; return true; };
    negative_entry.getter = [&negative] { return negative ? "true" : "false"; }; negative_entry.default_value = "true";
    rex::cvar::FlagRegistrar falsity(std::move(negative_entry)); Value("cvar_cli_late_negative", "false");
    ::unsetenv("REX_CVAR_CLI_LATE_STRING"); ::unsetenv("REX_CVAR_CLI_LATE_NUMBER");
  } else if (name == "services") {
    Config config("nat_probe_server = \"127.0.0.1\"\nsession_directory_url = \"http://127.0.0.1:9\"\nsession_directory_publish_address = \"127.0.0.2\"\n");
    rex::cvar::LoadConfig(config.path);
    Value("nat_probe_server", "127.0.0.1", rex::cvar::Source::kConfig);
    Value("session_directory_url", "http://127.0.0.1:9", rex::cvar::Source::kConfig);
    Value("session_directory_publish_address", "127.0.0.2", rex::cvar::Source::kConfig);
    Init({"--nat_probe_server=", "--session_directory_url=", "--session_directory_publish_address=",
          "--online_status_directory=/tmp/owned-status-fixture", "--input_script=/tmp/owned-input-fixture"});
    for (const char* service : {"nat_probe_server", "session_directory_url", "session_directory_publish_address"}) Value(service, "");
    Value("online_status_directory", "/tmp/owned-status-fixture"); Value("input_script", "/tmp/owned-input-fixture");
    rex::cvar::LoadConfig(config.path);
    for (const char* service : {"nat_probe_server", "session_directory_url", "session_directory_publish_address"}) Value(service, "");
  } else throw std::runtime_error("unknown fresh CLI case");
}
const char* cases[] = {"adjacent", "separated", "raw-value", "terminator", "consumed-separator",
                       "numeric", "numeric-valid", "boolean-empty", "boolean-invalid", "precedence", "late", "services"};
}  // namespace
int main(int argc, char** argv) {
  try {
    if (argc == 2) { Scenario(argv[1]); std::cout << "PASS " << argv[1] << " " << checks << " checks\n"; return 0; }
    Check(argc == 1, "usage: cvar_cli_test [case]");
    for (const auto* scenario : cases) {
      const auto child = ::fork(); Check(child >= 0, "fork fresh native CLI child");
      if (!child) { ::execl("/proc/self/exe", "cvar_cli_test", scenario, static_cast<char*>(nullptr)); ::_exit(127); }
      int status = 0; Check(::waitpid(child, &status, 0) == child && WIFEXITED(status) && WEXITSTATUS(status) == 0,
                            "fresh CLI child succeeds without resetting registry globals");
    }
    std::cout << "PASS 12 fresh-process cvar CLI cases\n"; return 0;
  } catch (const std::exception& error) {
    std::cerr << "FAIL after " << checks << ": " << error.what() << '\n'; return 1;
  }
}
