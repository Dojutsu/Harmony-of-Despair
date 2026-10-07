#!/usr/bin/env python3
"""Extract the real emitted scene notification block and its unguarded control."""
from __future__ import annotations

import argparse
import hashlib
from pathlib import Path
import re
import tomllib

HOOK = (
    "\tif (HarmonySkipAbsentSceneNotification(ctx.r9)) {\n"
    "\t\tgoto loc_8247B9BC;\n"
    "\t}\n"
    "\telse {\n"
    "\t}\n"
)


def extract(source: str, config: dict) -> tuple[str, str]:
    hooks = [hook for hook in config.get("midasm_hook", [])
             if hook.get("address") == 0x8247A4C8]
    expected = {
        "address": 0x8247A4C8,
        "name": "HarmonySkipAbsentSceneNotification",
        "registers": ["r9"],
        "jump_address_on_true": 0x8247B9BC,
        "after_instruction": False,
    }
    if len(hooks) != 1 or any(hooks[0].get(key) != value
                             for key, value in expected.items()):
        raise ValueError("TOML scene notification hook contract does not match")
    start, end = "loc_8247A4C8:\n", "loc_8247A4E8:\n"
    if source.count(start) != 1 or source.count(end) != 1:
        raise ValueError("scene notification extraction labels are not unique")
    first, last = source.index(start), source.index(end)
    if last <= first:
        raise ValueError("scene notification extraction labels are out of order")
    block = source[first:last]
    if block.count(HOOK) != 1 or not block.startswith(start + HOOK):
        raise ValueError("exact emitted if/else hook is missing at the entry label")
    for instruction in (
        "ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 128);",
        "ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 156);",
        "REX_STORE_U8(ctx.r11.u32 + 972, ctx.r20.u8);",
    ):
        if block.count(instruction) != 1:
            raise ValueError("expected emitted notification access is missing or duplicated")
    if set(re.findall(r"loc_[0-9A-F]+", block)) != {
            "loc_8247A4C8", "loc_8247A4DC", "loc_8247B9BC"}:
        raise ValueError("notification block has an unexpected control-flow dependency")
    common = "loc_8247B9BC:\n\t// mr r3,r20\n\tctx.r3.u64 = ctx.r20.u64;\n"
    if source.count(common) != 1:
        raise ValueError("actual shared guest return-value statement is not unique")
    suffix = common + "\treturn; // Harness boundary before the guest stack epilogue.\n"
    return block + suffix, block.replace(HOOK, "", 1) + suffix


def write_if_changed(path: Path, content: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    if not path.exists() or path.read_text() != content:
        path.write_text(content)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", type=Path, required=True)
    parser.add_argument("--config", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--original-output", type=Path, required=True)
    args = parser.parse_args()
    if args.output.resolve() == args.original_output.resolve():
        parser.error("generated and original outputs must be distinct")
    source = args.source.read_text()
    try:
        patched, original = extract(source, tomllib.loads(args.config.read_text()))
    except (ValueError, tomllib.TOMLDecodeError) as error:
        parser.error(str(error))
    provenance = ("// Extracted from actual generated source; SHA256 " +
                  hashlib.sha256(source.encode()).hexdigest() + "\n")
    write_if_changed(args.output, provenance + patched)
    write_if_changed(args.original_output, provenance + original)


if __name__ == "__main__":
    main()
