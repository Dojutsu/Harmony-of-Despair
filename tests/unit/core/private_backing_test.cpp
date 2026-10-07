// Process-private Linux backing must not reopen, resize or unlink named objects.
#include <catch2/catch_test_macros.hpp>
#include <rex/memory/utils.h>
#include <cerrno>
#include <cstdint>
#include <cstring>
#include <limits>
#include <string>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

namespace {
using namespace rex::memory;
std::string Name() { return "rex-private-backing-test-" + std::to_string(getpid()); }
struct Backing {
  std::string name;
  FileMappingHandle handle;
  explicit Backing(std::string value, size_t size = 8192)
      : name(std::move(value)), handle(CreateFileMappingHandle(name, size, PageAccess::kReadWrite, false)) {}
  ~Backing() { if (handle != kFileMappingHandleInvalid) CloseFileMappingHandle(handle, name); }
  int fd() const { return static_cast<int>(handle); }
};
struct View {
  Backing& backing;
  void* address;
  explicit View(Backing& value) : backing(value), address(MapFileView(value.handle, nullptr, 8192, PageAccess::kReadWrite, 0)) {}
  ~View() { if (address) UnmapFileView(backing.handle, address, 8192); }
};
struct NamedCanary {
  std::string name = "/" + Name();
  int fd = shm_open(name.c_str(), O_RDWR | O_CREAT | O_EXCL | O_CLOEXEC, 0600);
  ~NamedCanary() { if (fd >= 0) { close(fd); shm_unlink(name.c_str()); } }
};
}

TEST_CASE("Linux backing has private permissions and cannot survive exec", "[private_backing]") {
  Backing backing(Name());
  REQUIRE(backing.handle != kFileMappingHandleInvalid);
  struct stat info{};
  REQUIRE(fstat(backing.fd(), &info) == 0);
  CHECK((info.st_mode & 0777) == 0600);
  CHECK(info.st_size == 8192);
  CHECK((fcntl(backing.fd(), F_GETFD) & FD_CLOEXEC) != 0);
}

TEST_CASE("Identical guest arena names do not share bytes", "[private_backing]") {
  Backing first(Name()), second(Name());
  REQUIRE(first.handle != kFileMappingHandleInvalid);
  REQUIRE(second.handle != kFileMappingHandleInvalid);
  struct stat a{}, b{};
  REQUIRE(fstat(first.fd(), &a) == 0);
  REQUIRE(fstat(second.fd(), &b) == 0);
  CHECK((a.st_dev != b.st_dev || a.st_ino != b.st_ino));
  View one(first), two(second);
  REQUIRE(one.address);
  REQUIRE(two.address);
  auto* x = static_cast<uint8_t*>(one.address);
  auto* y = static_cast<uint8_t*>(two.address);
  CHECK(x[0] == 0);
  CHECK(y[0] == 0);
  x[0] = 0xA5;
  CHECK(y[0] == 0);
  y[8191] = 0x5A;
  CHECK(x[8191] == 0);
}

TEST_CASE("Closing backing preserves another same-name live mapping", "[private_backing]") {
  Backing surviving(Name());
  REQUIRE(surviving.handle != kFileMappingHandleInvalid);
  View view(surviving);
  REQUIRE(view.address);
  auto* bytes = static_cast<uint8_t*>(view.address);
  bytes[4096] = 0x39;
  { Backing other(Name()); REQUIRE(other.handle != kFileMappingHandleInvalid); }
  CHECK(bytes[4096] == 0x39);
  Backing third(Name());
  REQUIRE(third.handle != kFileMappingHandleInvalid);
  View fresh(third);
  REQUIRE(fresh.address);
  CHECK(static_cast<uint8_t*>(fresh.address)[4096] == 0);
}

TEST_CASE("Guest backing cannot change live mapping length", "[private_backing]") {
  Backing backing(Name());
  REQUIRE(backing.handle != kFileMappingHandleInvalid);
  errno = 0;
  CHECK(ftruncate(backing.fd(), 4096) == -1);
  CHECK(errno == EPERM);
  errno = 0;
  CHECK(ftruncate(backing.fd(), 16384) == -1);
  CHECK(errno == EPERM);
  struct stat info{};
  REQUIRE(fstat(backing.fd(), &info) == 0);
  CHECK(info.st_size == 8192);
  View view(backing);
  REQUIRE(view.address);
  static_cast<uint8_t*>(view.address)[8191] = 0x71;
  CHECK(static_cast<uint8_t*>(view.address)[8191] == 0x71);
}

TEST_CASE("Guest backing leaves preexisting named memory untouched", "[private_backing]") {
  NamedCanary canary;
  REQUIRE(canary.fd >= 0);
  const char marker[] = "owned canary";
  REQUIRE(ftruncate(canary.fd, sizeof(marker)) == 0);
  REQUIRE(pwrite(canary.fd, marker, sizeof(marker), 0) == sizeof(marker));
  { Backing backing(Name()); REQUIRE(backing.handle != kFileMappingHandleInvalid); }
  const int reopened = shm_open(canary.name.c_str(), O_RDONLY | O_CLOEXEC, 0);
  REQUIRE(reopened >= 0);
  struct stat info{};
  const int stat_result = fstat(reopened, &info);
  char observed[sizeof(marker)]{};
  const auto length = pread(reopened, observed, sizeof(observed), 0);
  close(reopened);
  REQUIRE(stat_result == 0);
  CHECK(info.st_size == sizeof(marker));
  CHECK(length == sizeof(marker));
  CHECK(std::memcmp(observed, marker, sizeof(marker)) == 0);
}

TEST_CASE("Guest backing rejects unusable sizes without creating a mapping", "[private_backing]") {
  CHECK(CreateFileMappingHandle(Name(), 0, PageAccess::kReadWrite, false) == kFileMappingHandleInvalid);
  CHECK(CreateFileMappingHandle(Name(), std::numeric_limits<size_t>::max(), PageAccess::kReadWrite, false) == kFileMappingHandleInvalid);
  CHECK(CreateFileMappingHandle(Name(), 8192, PageAccess::kNoAccess, false) == kFileMappingHandleInvalid);
}
