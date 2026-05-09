/**
 * @file        core/string_win.cpp
 * @brief       Windows platform string function implementations
 *
 * @copyright   Copyright (c) 2026 Tom Clay <tomc@tctechstuff.com>
 * @license     BSD 3-Clause License
 */

#include <rex/platform.h>
#include <rex/string.h>

static_assert(REX_PLATFORM_WIN32, "This file is Windows-only");

#include <string.h>

namespace rex::string {

int compare_case(const char* string1, const char* string2) {
  return _stricmp(string1, string2);
}

int compare_case_n(const char* string1, const char* string2, size_t count) {
  return _strnicmp(string1, string2, count);
}

char* duplicate(const char* source) {
  return _strdup(source);
}

int safe_strcpy(char* dst, size_t dst_size, const char* src) {
  return strcpy_s(dst, dst_size, src);
}

int safe_strncpy(char* dst, size_t dst_size, const char* src, size_t count) {
  return strncpy_s(dst, dst_size, src, count);
}

int safe_strcat(char* dst, size_t dst_size, const char* src) {
  return strcat_s(dst, dst_size, src);
}

char* safe_strtok(char* str, const char* delim, char** context) {
  return strtok_s(str, delim, context);
}

}  // namespace rex::string
