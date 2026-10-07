#!/usr/bin/env python3
"""Append one future controller press/release pair to an opted-in local process."""
import argparse
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re
import stat
import sys
import time

MAX_BYTES = 256 * 1024
MAX_ROWS = 4096
MAX_MS = 3600000
ANCHOR = re.compile(r"Offline controller append clock: monotonic_ms=(\d+) pid=(\d+) device=(\d+) inode=(\d+) external_clock=(true|false)")
ACCEPTED = re.compile(r"Offline controller append accepted: elapsed_ms=(\d+) previous_rows=(\d+) rows=(\d+)")
DELIVERY = re.compile(r"Offline controller (transition|UI-consumed): elapsed_ms=(\d+) packet=(\d+) buttons=([0-9A-Fa-f]{4})")


def fail(message):
    raise ValueError(message)


def read_log(path):
    # One local operation, bounded even if a diagnostic log grows unexpectedly.
    with open(path, "rb") as stream:
        data = stream.read(64 * 1024 * 1024 + 1)
    if len(data) > 64 * 1024 * 1024:
        fail("log exceeds 64 MiB; use a bounded copy containing the clock and delivery records")
    return data.decode("utf-8", errors="replace")


def parse_anchor(text):
    matches = list(ANCHOR.finditer(text))
    if len(matches) != 1:
        fail("log must contain exactly one append clock anchor")
    match = matches[0]
    if match[5] != "false":
        fail("external test clocks cannot schedule a physical process")
    return {key: int(match[i + 1]) for i, key in enumerate(("monotonic_ms", "pid", "device", "inode"))}


def check_process(anchor, now_ms):
    pid = anchor["pid"]
    if pid <= 0 or anchor["monotonic_ms"] > now_ms:
        fail("clock anchor is not a current local process")
    directory = Path("/proc") / str(pid)
    if directory.stat().st_uid != os.geteuid():
        fail("clock process is not owned by the caller")
    # /proc starttime prevents accepting an old clock record after PID reuse.
    text = (directory / "stat").read_text()
    end = text.rfind(")")
    fields = text[end + 2:].split()
    if end < 0 or len(fields) < 20 or fields[0] in ("Z", "X", "x"):
        fail("clock process is unavailable")
    ticks = int(fields[19])
    started_ms = ticks * 1000 // os.sysconf("SC_CLK_TCK")
    if anchor["monotonic_ms"] < started_ms:
        fail("clock record predates this process")


def parse_rows(data):
    if len(data) > MAX_BYTES or not data.endswith(b"\n"):
        fail("script must be bounded and end with a committed newline")
    try:
        text = data.decode("ascii")
    except UnicodeDecodeError:
        fail("script must use ASCII decimal rows")
    rows = []
    bounds = ((0, MAX_MS), (0, 65535), (0, 255), (0, 255)) + ((-32768, 32767),) * 4
    for line in text.splitlines():
        tokens = line.split("#", 1)[0].split()
        if not tokens:
            continue
        if len(tokens) != 8 or any(re.fullmatch(r"-?\d+", token, re.ASCII) is None for token in tokens):
            fail("script contains an invalid fixed-width decimal row")
        values = tuple(map(int, tokens))
        if any(not lo <= value <= hi for value, (lo, hi) in zip(values, bounds)):
            fail("script contains an out-of-range row")
        if rows and values[0] <= rows[-1][0]:
            fail("script timestamps are not strictly increasing")
        rows.append(values)
        if len(rows) > MAX_ROWS:
            fail("script exceeds 4096 total rows")
    if not rows:
        fail("script contains no rows")
    return rows


def private_stat(fd):
    info = os.fstat(fd)
    if not stat.S_ISREG(info.st_mode) or info.st_uid != os.geteuid() or info.st_mode & 0o077:
        fail("script must be a private regular file owned by the caller")
    if info.st_size > MAX_BYTES:
        fail("script exceeds 256 KiB")
    return info


def append(args):
    if sys.platform != "linux":
        fail("append helper requires Linux")
    if not 1000 <= args.lead_ms <= 60000 or not 50 <= args.hold_ms <= 10000:
        fail("lead must be 1000..60000 ms and hold 50..10000 ms")
    values = (args.buttons, args.lt, args.rt, args.lx, args.ly, args.rx, args.ry)
    bounds = ((0, 65535), (0, 255), (0, 255)) + ((-32768, 32767),) * 4
    if any(not lo <= value <= hi for value, (lo, hi) in zip(values, bounds)):
        fail("controller values exceed their fixed integer bounds")
    anchor = parse_anchor(read_log(args.anchor_log))
    fd = os.open(args.script, os.O_RDWR | os.O_APPEND | os.O_CLOEXEC | os.O_NOFOLLOW | os.O_NONBLOCK)
    try:
        fcntl.flock(fd, fcntl.LOCK_EX)
        before = private_stat(fd)
        if (before.st_dev, before.st_ino) != (anchor["device"], anchor["inode"]):
            fail("script identity differs from the running driver")
        data = os.read(fd, MAX_BYTES + 1)
        rows = parse_rows(data)
        after = private_stat(fd)
        if (before.st_size, before.st_mtime_ns, before.st_ctime_ns) != (after.st_size, after.st_mtime_ns, after.st_ctime_ns):
            fail("script changed during helper preflight")
        now_ms = time.monotonic_ns() // 1000000
        check_process(anchor, now_ms)
        elapsed = now_ms - anchor["monotonic_ms"]
        pressed = max(elapsed + args.lead_ms, rows[-1][0] + 1)
        released = pressed + args.hold_ms
        added = ((pressed,) + values, (released, 0, 0, 0, 0, 0, 0, 0))
        encoded = "".join(" ".join(map(str, row)) + "\n" for row in added).encode("ascii")
        if len(rows) + 2 > MAX_ROWS or len(data) + len(encoded) > MAX_BYTES or released > MAX_MS:
            fail("new pair exceeds the total schedule limits")
        current = os.stat(args.script, follow_symlinks=False)
        if (current.st_dev, current.st_ino) != (before.st_dev, before.st_ino):
            fail("script path changed before append")
        # A single bounded append, never truncate/replace or reset the clock.
        # Runtime publishes only completed validated extensions. A short write
        # is reported; the helper never rewrites previously accepted bytes.
        if os.write(fd, encoded) != len(encoded):
            fail("append was incomplete; inspect the pending tail before another append")
        os.fsync(fd)
        scheduled = data + encoded
        if os.pread(fd, len(scheduled), 0) != scheduled:
            fail("scheduled byte prefix changed during append")
        return {"anchor": anchor, "prior_file_prefix_sha256": hashlib.sha256(data).hexdigest(),
                "scheduled_tail_sha256": hashlib.sha256(encoded).hexdigest(),
                "scheduled_file_sha256": hashlib.sha256(scheduled).hexdigest(),
                "scheduled_prefix_bytes": len(scheduled),
                "prior_rows": len(rows), "elapsed_ms_at_append": elapsed,
                "rows": [{"milliseconds": row[0], "source_packet": len(rows) + index + 1,
                          "buttons": row[1], "controller_values": list(row[1:])} for index, row in enumerate(added)]}
    finally:
        os.close(fd)


def verify(args):
    with open(args.manifest, "rb") as stream:
        data = stream.read(65537)
    if len(data) > 65536:
        fail("receipt exceeds 64 KiB")
    manifest = json.loads(data)
    rows = manifest["rows"]
    prior = manifest["prior_rows"]
    if type(prior) is not int or not 1 <= prior <= MAX_ROWS - 2 or len(rows) != 2:
        fail("receipt row count is invalid")
    for index, row in enumerate(rows):
        if type(row["milliseconds"]) is not int or not 0 <= row["milliseconds"] <= MAX_MS or \
                type(row["source_packet"]) is not int or row["source_packet"] != prior + index + 1 or \
                type(row["buttons"]) is not int or not 0 <= row["buttons"] <= 65535:
            fail("receipt row bounds are invalid")
    if rows[0]["milliseconds"] >= rows[1]["milliseconds"] or rows[1]["buttons"] != 0:
        fail("receipt must describe an increasing pair with a release")
    text = read_log(args.runtime_log)
    anchor = parse_anchor(text)
    if anchor != manifest["anchor"]:
        fail("delivery log does not match the scheduled process clock")
    results = []
    for row in manifest["rows"]:
        matching = [match for match in DELIVERY.finditer(text)
                    if int(match[3]) == row["source_packet"] and int(match[2]) >= row["milliseconds"]]
        delivered = any(match[1] == "transition" and int(match[4], 16) == row["buttons"] for match in matching)
        consumed = any(match[1] == "UI-consumed" for match in matching)
        results.append({"source_packet": row["source_packet"], "guest_delivered": delivered,
                        "ui_consumed_observed": consumed})
    accepted = any(int(match[3]) >= prior + 2 and int(match[1]) < rows[0]["milliseconds"]
                   for match in ACCEPTED.finditer(text))
    return {"anchor": anchor, "delivery": results, "schedule_rows_accepted": accepted,
            "all_button_edges_guest_delivered": all(row["guest_delivered"] for row in results)}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    sub = commands.add_parser("append")
    sub.add_argument("--script", required=True)
    sub.add_argument("--anchor-log", required=True)
    for name in ("buttons", "lt", "rt", "lx", "ly", "rx", "ry"):
        sub.add_argument("--" + name, type=int, default=0)
    sub.add_argument("--lead-ms", type=int, default=1000)
    sub.add_argument("--hold-ms", type=int, default=150)
    sub = commands.add_parser("verify")
    sub.add_argument("--manifest", required=True)
    sub.add_argument("--runtime-log", required=True)
    args = parser.parse_args()
    try:
        result = append(args) if args.command == "append" else verify(args)
        print(json.dumps(result, sort_keys=True))
        return 0 if args.command == "append" or (result["schedule_rows_accepted"] and result["all_button_edges_guest_delivered"]) else 2
    except (OSError, ValueError, KeyError, TypeError, IndexError):
        # Diagnostics never echo script/log contents or malformed values.
        print("controller append operation rejected; accepted schedule retained", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
