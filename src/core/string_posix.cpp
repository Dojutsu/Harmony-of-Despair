/**
 * @file        core/string_posix.cpp
 * @brief       POSIX platform string function implementations
 *
 * @copyright   Copyright (c) 2026 Tom Clay <tomc@tctechstuff.com>
 * @license     BSD 3-Clause License
 */

#include <rex/platform.h>
#include <rex/string.h>

static_assert(REX_PLATFORM_LINUX || REX_PLATFORM_MAC, "This file is POSIX-only");

#include <string.h>

#include <algorithm>

#include <strings.h>

namespace rex::string {

int compare_case(const char* string1, const char* string2) {
  return strcasecmp(string1, string2);
}

int compare_case_n(const char* string1, const char* string2, size_t count) {
  return strncasecmp(string1, string2, count);
}

char* duplicate(const char* source) {
  return strdup(source);
}

int safe_strcpy(char* dst, size_t dst_size, const char* src) {
  if (!dst || !src || dst_size == 0)
    return 22;  // EINVAL
  const size_t src_len = std::strlen(src);
  if (src_len + 1 > dst_size) {
    dst[0] = '\0';
    return 34;  // ERANGE
  }
  std::memcpy(dst, src, src_len + 1);
  return 0;
}

int safe_strncpy(char* dst, size_t dst_size, const char* src, size_t count) {
  if (!dst || !src || dst_size == 0)
    return 22;  // EINVAL
  const size_t src_len = strnlen(src, count);
  const size_t to_copy = std::min(src_len, dst_size - 1);
  std::memcpy(dst, src, to_copy);
  dst[to_copy] = '\0';
  return (src_len > to_copy) ? 34 : 0;  // ERANGE on truncation
}

int safe_strcat(char* dst, size_t dst_size, const char* src) {
  if (!dst || !src || dst_size == 0)
    return 22;  // EINVAL
  const size_t dst_len = std::strlen(dst);
  if (dst_len >= dst_size) {
    return 22;  // EINVAL
  }
  const size_t src_len = std::strlen(src);
  if (dst_len + src_len + 1 > dst_size) {
    dst[dst_len] = '\0';
    return 34;  // ERANGE
  }
  std::memcpy(dst + dst_len, src, src_len + 1);
  return 0;
}

char* safe_strtok(char* str, const char* delim, char** context) {
  return strtok_r(str, delim, context);
}

}  // namespace rex::string
