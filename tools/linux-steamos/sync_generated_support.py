#!/usr/bin/env python3
"""Refresh generated C++ support and CMake settings from canonical SDK templates.

Keeps every module's configuration prefix and all guest instruction bodies intact.
The accepted template subset is constant C++ plus one indirect-dispatch include,
and the CMake settings section permits only literal cmake_var substitutions.
Default mode verifies; --write applies validated changes.
"""
import argparse
from pathlib import Path
import re

PCH_START = "//=============================================================================\n// SDK Headers\n"
CMAKE_START = "# The options go on the target as well:"
CMAKE_END = "# Configure a rexglue target with SDK libraries and platform settings."
INCLUDE = '{% include "codegen/_indirect_call.inja" %}'
TOKENS = ("{%", "{{", "{#")


def once(text, marker, label):
    if text.count(marker) != 1:
        raise ValueError("expected one " + label)
    return text.index(marker)


def templates(sdk):
    directory = sdk / "resources/templates"
    pch = (directory / "codegen/pch_h.inja").read_text()
    pch = pch[once(pch, PCH_START, "canonical C++ support section"):]
    once(pch, INCLUDE, "canonical indirect dispatch include")
    dispatch = (directory / "codegen/_indirect_call.inja").read_text()
    if any(token in dispatch for token in TOKENS):
        raise ValueError("indirect dispatch must be constant C++")
    pch = pch.replace(INCLUDE, dispatch.rstrip() + "\n")
    if any(token in pch for token in TOKENS):
        raise ValueError("generated C++ support must be constant after dispatch include")
    cmake = (directory / "init/rexglue_cmake.inja").read_text()
    begin = once(cmake, CMAKE_START, "canonical CMake settings start")
    end = once(cmake, CMAKE_END, "canonical CMake settings end")
    if begin >= end:
        raise ValueError("invalid canonical CMake section order")
    cmake = cmake[begin:end]
    cmake = re.sub(r'\{\{ cmake_var\("([A-Za-z_][A-Za-z_0-9]*)"\) \}\}',
                   lambda m: "${" + m.group(1) + "}", cmake)
    if any(token in cmake for token in TOKENS):
        raise ValueError("CMake settings contain an unsupported template expression")
    return pch, cmake


def synchronize(source, sdk, write=False):
    pch, cmake = templates(sdk)
    headers = sorted((source / "generated").rglob("*_pch.h"))
    if not headers:
        raise ValueError("no generated module PCH headers")
    pending = []
    # Validate every file before writing any output.
    for path in headers:
        text = path.read_text()
        start = once(text, PCH_START, "C++ support in " + str(path))
        prefix = text[:start]
        for identity in ("REX_IMAGE_BASE", "REX_IMAGE_SIZE", "REX_FUNCTION_TABLE_BASE"):
            if prefix.count("#define " + identity + " ") != 1:
                raise ValueError("missing or duplicate module identity in " + str(path))
        updated = prefix + pch
        if text != updated:
            pending.append((path, updated))
    path = source / "generated/rexglue.cmake"
    text = path.read_text()
    start = once(text, CMAKE_START, "generated CMake settings start")
    end = once(text, CMAKE_END, "generated CMake settings end")
    if start >= end:
        raise ValueError("invalid generated CMake section order")
    updated = text[:start] + cmake + text[end:]
    if text != updated:
        pending.append((path, updated))
    if write:
        for path, updated in pending:
            path.write_text(updated)
    return len(headers), len(pending)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, default=Path(__file__).resolve().parents[2])
    parser.add_argument("--sdk", type=Path, required=True)
    parser.add_argument("--write", action="store_true")
    args = parser.parse_args()
    count, changed = synchronize(args.source.resolve(strict=True), args.sdk.resolve(strict=True), args.write)
    print(f"generated support: {count} module headers, {changed} differences, write={args.write}")
    return 0 if args.write or not changed else 1


if __name__ == "__main__":
    raise SystemExit(main())
