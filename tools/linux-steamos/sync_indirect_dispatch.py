#!/usr/bin/env python3
"""Synchronize generated dispatch blocks from the authoritative SDK template.

Only the standalone pure-C++ _indirect_call.inja block is replaced. Module
identity, code, registrations, overrides and other generated content are kept.
Default mode verifies; --write applies the same deterministic synchronization.
"""
import argparse
from pathlib import Path
import sys

START = "//=============================================================================\n// Indirect Call Dispatch\n"
END = "//=============================================================================\n// Flush Mode\n"


def synchronize(source, sdk, write=False):
    template = (sdk / "resources/templates/codegen/_indirect_call.inja").read_text()
    if not template.startswith(START) or any(token in template for token in ("{%", "{{", "{#")):
        raise ValueError("dispatch template must remain a standalone pure-C++ block")
    headers = sorted((source / "generated").rglob("*_pch.h"))
    if not headers:
        raise ValueError("no generated module PCH headers found")
    pending = []
    # Validate every input before any output changes.
    for path in headers:
        text = path.read_text()
        if text.count(START) != 1 or text.count(END) != 1:
            raise ValueError("expected one dispatch block in " + str(path))
        if "#define REX_FUNCTION_TABLE_BASE " not in text:
            raise ValueError("missing explicit module table identity: " + str(path))
        start, end = text.index(START), text.index(END)
        if start >= end:
            raise ValueError("invalid generated section ordering: " + str(path))
        updated = text[:start] + template.rstrip() + "\n\n\n" + text[end:]
        if updated != text:
            pending.append((path, updated))
    if write:
        for path, updated in pending:
            path.write_text(updated)
    return len(headers), len(pending)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, default=Path(__file__).resolve().parents[2])
    parser.add_argument("--sdk", required=True, type=Path)
    parser.add_argument("--write", action="store_true")
    args = parser.parse_args()
    count, changed = synchronize(args.source.resolve(strict=True), args.sdk.resolve(strict=True), args.write)
    print(f"generated indirect dispatch: {count} module headers, {changed} differences, write={args.write}")
    return 0 if args.write or not changed else 1


if __name__ == "__main__":
    raise SystemExit(main())
