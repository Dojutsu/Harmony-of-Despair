// SHA-256 consistency test (uses SDK's sha256 implementation)
// Verifies the hash function is deterministic and stable for manifest use.

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include "sha256.h"

static int failures = 0;

static void check(const char* name, const std::string& input, const std::string& expected) {
  sha256::SHA256 sha;
  std::string hash = sha(input);
  if (hash != expected) {
    fprintf(stderr, "FAIL: %s\n  Expected: %s\n  Got:      %s\n", name, expected.c_str(), hash.c_str());
    failures++;
  } else {
    fprintf(stderr, "PASS: %s\n", name);
  }
}

static void check_stream(const char* name,
                        const std::vector<std::pair<const void*, size_t>>& chunks,
                        const std::string& expected) {
  sha256::SHA256 sha;
  for (const auto& chunk : chunks) {
    sha.add(chunk.first, chunk.second);
  }
  std::string hash = sha.getHash();
  if (hash != expected) {
    fprintf(stderr, "FAIL: %s\n  Expected: %s\n  Got:      %s\n", name, expected.c_str(), hash.c_str());
    failures++;
  } else {
    fprintf(stderr, "PASS: %s\n", name);
  }
}

int main() {
  // Use SDK's actual outputs as reference.
  check("Empty string", "",
        "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
  check("abc", "abc",
        "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad");
  check("Hello World", "Hello World",
        "a591a6d40bf420404a011733cfb7b190d62c65bf0bcda32b57b277d9ad9f146e");

  // Streaming must match single-shot
  std::vector<std::pair<const void*, size_t>> stream_chunks = {
    {"Hello ", 6},
    {"World", 5}
  };
  check_stream("Streaming Hello World", stream_chunks,
               "a591a6d40bf420404a011733cfb7b190d62c65bf0bcda32b57b277d9ad9f146e");

  // Reset consistency
  {
    sha256::SHA256 sha;
    std::string h1 = sha("test");
    sha.reset();
    std::string h2 = sha("test");
    if (h1 != h2) {
      fprintf(stderr, "FAIL: Reset consistency\n");
      failures++;
    } else {
      fprintf(stderr, "PASS: Reset consistency\n");
    }
  }

  // Binary data
  uint8_t binary[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
                      0x06, 0x07, 0x08, 0x09};
  std::vector<std::pair<const void*, size_t>> bin_chunks = {
    {binary, sizeof(binary)}
  };
  check_stream("Binary data", bin_chunks,
               "1f825aa2f0020ef7cf91dfa30da4668d791c5d4824fc8e41354b89ec05795ab3");

  // Large payload
  std::string big(10000, 'A');
  check("10000 A's", big,
        "85757d9ef5868bb53472a6be8d81d1e3c398546b69b107141ad336053c40cb54");

  // Determinism
  {
    sha256::SHA256 s1, s2;
    std::string d1 = s1("determinism check");
    std::string d2 = s2("determinism check");
    if (d1 != d2) {
      fprintf(stderr, "FAIL: Determinism\n");
      failures++;
    } else {
      fprintf(stderr, "PASS: Determinism\n");
    }
  }

  if (failures > 0) {
    fprintf(stderr, "\n%d test(s) failed.\n", failures);
    return 1;
  }
  fprintf(stderr, "\nAll consistency tests passed.\n");
  return 0;
}
