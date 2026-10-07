#include <rex/system/xam/private_lan_invitation.h>
#include <rex/platform.h>
#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <vector>
#if REX_PLATFORM_GNU_LINUX
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#endif
#ifndef FSC_PRIVATE_LAN_STANDALONE
#include <catch2/catch_test_macros.hpp>
#endif
using namespace rex::system::xam;
namespace {
size_t checks = 0;
void Check(bool value, const char* message) {
  ++checks;
  if (!value) throw std::runtime_error(message);
}
#if REX_PLATFORM_GNU_LINUX
struct PrivateDirectory {
  std::filesystem::path path;
  PrivateDirectory() {
    std::array<char, 128> name{};
    std::strcpy(name.data(), "/tmp/fsc-private-lan-invitation-XXXXXX");
    auto* created = mkdtemp(name.data());
    Check(created != nullptr, "create private test directory"); path = created;
  }
  ~PrivateDirectory() { std::error_code error; std::filesystem::remove_all(path, error); }
};
void Set64(std::vector<uint8_t>& bytes, size_t offset, uint64_t value) {
  for (int shift = 56; shift >= 0; shift -= 8) bytes[offset++] = uint8_t(value >> shift);
}
std::vector<uint8_t> File(bool host, uint64_t expiry, uint64_t host_xuid = 1, size_t maximum = 2) {
  const size_t count = host ? maximum : 1;
  std::vector<uint8_t> bytes(24 + 56 * count);
  std::memcpy(bytes.data(), "HPLI", 4); bytes[4] = 1; bytes[5] = host ? 0 : 1; bytes[6] = count;
  Set64(bytes, 8, host_xuid); Set64(bytes, 16, expiry);
  for (size_t i = 0; i < count; ++i) {
    Set64(bytes, 24 + i * 56, i + 2);
    for (size_t j = 0; j < 16; ++j) bytes[32 + i * 56 + j] = uint8_t(j + 1 + i * 79);
    for (size_t j = 0; j < 32; ++j) bytes[48 + i * 56 + j] = uint8_t(j * 3 + 1 + i * 89);
  }
  return bytes;
}
void Write(const std::filesystem::path& path, const std::vector<uint8_t>& bytes) {
  const int fd = ::open(path.c_str(), O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0600);
  Check(fd >= 0, "write private test fixture");
  Check(::write(fd, bytes.data(), bytes.size()) == ssize_t(bytes.size()), "exact test write");
  ::close(fd);
}
void Run() {
  checks = 0;
  PrivateDirectory directory;
  const auto host_file = directory.path / "host.hpli", client_file = directory.path / "client.hpli";
  const auto now = std::chrono::system_clock::now();
  const auto seconds = uint64_t(std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count());
  const auto host_bytes = File(true, seconds + 3600), client_bytes = File(false, seconds + 3600);
  Write(host_file, host_bytes); Write(client_file, client_bytes);
  auto host = PrivateLanInvitation::Load(host_file.string());
  auto client = PrivateLanInvitation::Load(client_file.string());
  Check(bool(host) && bool(client), "load legitimate host/client invitations");
  Check(host->host() && !client->host() && host->host_xuid() == 1 && client->host_xuid() == 1,
        "host role and identity");
  Check(host->clients() == std::vector<uint64_t>({2, 3}) && client->clients() == std::vector<uint64_t>({2}),
        "distinct private grant inventories");
  std::vector<uint8_t> transcript(1428);
  for (size_t i = 0; i < transcript.size(); ++i) transcript[i] = uint8_t(i * 79 + 31);
  auto tag = client->Proof(2, "lan-join-request-v3", transcript);
  Check(bool(tag) && host->Verify(2, "lan-join-request-v3", transcript, *tag), "matching grant proof");
  Check(!host->Verify(3, "lan-join-request-v3", transcript, *tag), "client identity spoof rejected");
  Check(!client->Proof(3, "lan-join-request-v3", transcript), "client cannot access another private grant");
  Check(!host->Verify(2, "lan-join-reply-v3", transcript, *tag), "direction reflection rejected");
  Check(!host->Verify(2, "lan-search-request-v3", transcript, *tag), "RPC type substitution rejected");
  for (size_t i = 0; i < transcript.size(); ++i) {
    transcript[i] ^= 1;
    Check(!host->Verify(2, "lan-join-request-v3", transcript, *tag), "transcript modification rejected");
    transcript[i] ^= 1;
  }
  for (size_t i = 0; i < tag->size(); ++i) {
    (*tag)[i] ^= 1;
    Check(!host->Verify(2, "lan-join-request-v3", transcript, *tag), "MAC modification rejected");
    (*tag)[i] ^= 1;
  }
  std::vector<uint8_t> oversized(4097, 1);
  Check(!host->Proof(2, "join", oversized) && !host->Proof(2, "", transcript) &&
        !host->Proof(2, std::string(129, 'j'), transcript) &&
        !host->Proof(2, std::string_view("join\0request", 12), transcript) &&
        !host->Proof(2, "join", {}), "proof bounds enforced");
  Check(!host->Verify(2, "lan-join-request-v3", transcript, std::span(*tag).first(15)),
        "short MAC rejected");
  auto wrong = client_bytes; wrong[48] ^= 1; Write(client_file, wrong);
  auto wrong_secret = PrivateLanInvitation::Load(client_file.string());
  Check(bool(wrong_secret), "different private secret loads without exposing it");
  const auto wrong_tag = wrong_secret->Proof(2, "lan-join-request-v3", transcript);
  Check(bool(wrong_tag) && !host->Verify(2, "lan-join-request-v3", transcript, *wrong_tag),
        "wrong invitation rejected");
  Write(client_file, File(false, seconds + 3600, 4));
  const auto wrong_host = PrivateLanInvitation::Load(client_file.string());
  const auto wrong_host_tag = wrong_host->Proof(2, "lan-join-request-v3", transcript);
  Check(bool(wrong_host_tag) && !host->Verify(2, "lan-join-request-v3", transcript, *wrong_host_tag),
        "host identity substitution rejected");
  Check(!host->Current(now + std::chrono::hours(2)), "invitation expires");
  Check(!PrivateLanInvitation::Load(host_file.string(), now + std::chrono::hours(2)), "expired load rejected");
  auto reject = [&](std::vector<uint8_t> bytes) {
    Write(client_file, bytes);
    Check(!PrivateLanInvitation::Load(client_file.string()), "malformed private invitation rejected");
  };
  for (size_t position : {size_t(0), size_t(4), size_t(5), size_t(6), size_t(7)}) {
    auto changed = client_bytes; changed[position] = 0xFF; reject(changed);
  }
  auto changed = client_bytes; Set64(changed, 8, 0); reject(changed);
  changed = client_bytes; Set64(changed, 24, 0); reject(changed);
  changed = client_bytes; Set64(changed, 24, 1); reject(changed);
  changed = client_bytes; Set64(changed, 16, seconds); reject(changed);
  changed = client_bytes; Set64(changed, 16, seconds + 604860); reject(changed);
  changed = client_bytes; std::fill_n(changed.begin() + 32, 16, 0); reject(changed);
  changed = client_bytes; std::fill_n(changed.begin() + 48, 32, 0); reject(changed);
  changed = client_bytes; changed.push_back(0); reject(changed);
  for (size_t length = 0; length < client_bytes.size(); ++length)
    reject(std::vector<uint8_t>(client_bytes.begin(), client_bytes.begin() + length));
  reject(std::vector<uint8_t>(PrivateLanInvitation::kMaximumFileBytes + 1, 1));
  changed = host_bytes; Set64(changed, 80, 2); reject(changed);
  changed = host_bytes; std::copy_n(changed.begin() + 32, 16, changed.begin() + 88); reject(changed);
  changed = host_bytes; std::copy_n(changed.begin() + 48, 32, changed.begin() + 104); reject(changed);
  Write(client_file, File(true, seconds + 3600, 1, 5));
  const auto maximum = PrivateLanInvitation::Load(client_file.string());
  Check(bool(maximum) && maximum->clients() == std::vector<uint64_t>({2,3,4,5,6}),
        "maximum five private grants load");
  Write(client_file, client_bytes);
  Check(::chmod(client_file.c_str(), 0400) == 0 && bool(PrivateLanInvitation::Load(client_file.string())),
        "read-only private secret accepted");
  Check(::chmod(client_file.c_str(), 0700) == 0 && !PrivateLanInvitation::Load(client_file.string()),
        "executable secret refused");
  Check(::chmod(client_file.c_str(), 0600) == 0, "restore private file");
  // The pinned runner drops capabilities even for UID 0. Exercise owner
  // refusal where this isolated process can prepare that fixture; never add
  // CAP_CHOWN or weaken the runner to manufacture the test.
  if (geteuid() == 0 && ::chown(client_file.c_str(), 1, -1) == 0) {
    Check(!PrivateLanInvitation::Load(client_file.string()), "wrong file owner refused");
    Check(::chown(client_file.c_str(), 0, -1) == 0, "restore private owner");
  }
  Check(::chmod(client_file.c_str(), 0640) == 0 && !PrivateLanInvitation::Load(client_file.string()),
        "group-readable secret refused");
  Check(::chmod(client_file.c_str(), 0600) == 0, "restore private mode");
  const auto hardlink = directory.path / "hardlink.hpli";
  Check(::link(client_file.c_str(), hardlink.c_str()) == 0 &&
        !PrivateLanInvitation::Load(client_file.string()) && !PrivateLanInvitation::Load(hardlink.string()),
        "hardlinked secret refused");
  std::filesystem::remove(hardlink);
  const auto symlink = directory.path / "symlink.hpli";
  std::filesystem::create_symlink(client_file, symlink);
  Check(!PrivateLanInvitation::Load(symlink.string()), "final symlink refused");
  const auto alias = directory.path / "alias";
  std::filesystem::create_directory_symlink(directory.path, alias);
  Check(!PrivateLanInvitation::Load((alias / "client.hpli").string()), "ancestor symlink refused");
  Check(!PrivateLanInvitation::Load(client_file.filename().string()), "relative secret path refused");
  Check(!PrivateLanInvitation::Load((directory.path / ".." / directory.path.filename() / "client.hpli").string()),
        "noncanonical secret path refused");
  Check(::chmod(directory.path.c_str(), 0755) == 0 && !PrivateLanInvitation::Load(client_file.string()),
        "public secret parent refused");
  Check(::chmod(directory.path.c_str(), 0700) == 0, "restore private parent");
  const auto fifo = directory.path / "fifo";
  Check(::mkfifo(fifo.c_str(), 0600) == 0 && !PrivateLanInvitation::Load(fifo.string()),
        "nonregular file refused without blocking");
  std::atomic<bool> concurrent{true};
  std::vector<std::thread> threads;
  for (unsigned i = 0; i < 8; ++i) threads.emplace_back([&] {
    for (unsigned j = 0; j < 256; ++j)
      if (!host->Verify(2, "lan-join-request-v3", transcript, *tag)) concurrent = false;
  });
  for (auto& thread : threads) thread.join();
  Check(concurrent, "immutable invitation proofs support concurrent callers");
  std::cout << checks << " private invitation file and possession-proof checks passed\n";
}
#endif
}  // namespace
#ifdef FSC_PRIVATE_LAN_STANDALONE
int main() {
  try { Run(); return 0; }
  catch (const std::exception& error) { std::cerr << error.what() << '\n'; return 1; }
}
#else
TEST_CASE("Private LAN invitation loader and identity-bound possession proofs fail closed", "[network][security]") {
#if REX_PLATFORM_GNU_LINUX
  REQUIRE_NOTHROW(Run());
#endif
}
#endif
