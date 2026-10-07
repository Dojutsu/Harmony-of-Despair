#!/usr/bin/env python3
"""Local helper validation, using the actual helper module and private files."""
import importlib.util
import json
import os
from pathlib import Path
import stat
import subprocess
import sys
import tempfile
import time
import types
import unittest
from unittest import mock

SOURCE = Path(__file__).resolve().parents[2] / "tools" / "append_input_script.py"
spec = importlib.util.spec_from_file_location("append_input_script", SOURCE)
helper = importlib.util.module_from_spec(spec)
spec.loader.exec_module(helper)
ROW = b"0 0 0 0 0 0 0 0\n"


class HelperTest(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix="rex-append-helper-")
        self.directory = Path(self.temp.name)
        self.script = self.directory / "script.txt"
        self.script.write_bytes(ROW)
        self.script.chmod(0o600)
        self.log = self.directory / "clock.log"
        self.anchor = {"monotonic_ms": time.monotonic_ns() // 1000000,
                       "pid": os.getpid(), "device": self.script.stat().st_dev,
                       "inode": self.script.stat().st_ino}
        self.log.write_text(self.line())
        self.args = types.SimpleNamespace(script=str(self.script), anchor_log=str(self.log),
                                         buttons=4096, lt=0, rt=0, lx=0, ly=0, rx=0, ry=0,
                                         lead_ms=1000, hold_ms=150)

    def tearDown(self):
        self.temp.cleanup()

    def line(self, external="false"):
        return ("Offline controller append clock: monotonic_ms={monotonic_ms} "
                "pid={pid} device={device} inode={inode} external_clock=".format(**self.anchor)
                + external + "\n")

    def rejected(self):
        before = self.script.read_bytes()
        with self.assertRaises((ValueError, OSError)):
            helper.append(self.args)
        self.assertEqual(before, self.script.read_bytes())

    def test_actual_owned_file_appends_future_pair(self):
        result = helper.append(self.args)
        data = self.script.read_bytes()
        self.assertTrue(data.startswith(ROW))
        rows = helper.parse_rows(data)
        self.assertEqual(len(rows), 3)
        self.assertGreaterEqual(rows[1][0], result["elapsed_ms_at_append"] + 1000)
        self.assertEqual(rows[1][1:], (4096, 0, 0, 0, 0, 0, 0))
        self.assertEqual(rows[2][1:], (0,) * 7)
        self.assertEqual(rows[2][0] - rows[1][0], 150)
        self.assertEqual([row["source_packet"] for row in result["rows"]], [2, 3])
        self.assertEqual(self.script.stat().st_ino, self.anchor["inode"])

    def test_repeated_append_preserves_complete_prefix(self):
        helper.append(self.args); prefix = self.script.read_bytes()
        result = helper.append(self.args)
        self.assertTrue(self.script.read_bytes().startswith(prefix))
        self.assertEqual([row["source_packet"] for row in result["rows"]], [4, 5])
        self.assertEqual(len(helper.parse_rows(self.script.read_bytes())), 5)

    def test_private_and_identity_guards(self):
        self.script.chmod(0o644); self.rejected(); self.script.chmod(0o600)
        self.anchor["inode"] += 1; self.log.write_text(self.line()); self.rejected()

    def test_symlink_is_rejected(self):
        target = self.directory / "target"; target.write_bytes(ROW); target.chmod(0o600)
        self.script.unlink(); self.script.symlink_to(target); self.rejected()
        self.assertEqual(target.read_bytes(), ROW)

    def test_pending_and_malformed_rows_rejected(self):
        for invalid in (b"0 0 0 0 0 0 0 0", ROW + b"1 0x1000 0 0 0 0 0 0\n",
                        ROW + b"1 0 256 0 0 0 0 0\n", ROW + b"1 0 0 0 0 0 0 -32769\n",
                        ROW + b"1 0 0 0 0 0 0 0 9\n", ROW + b"0 0 0 0 0 0 0 0\n"):
            with self.subTest(size=len(invalid)):
                self.script.write_bytes(invalid); self.rejected()

    def test_total_limits_and_hour_bound(self):
        self.script.write_bytes(b"#" * (helper.MAX_BYTES + 1)); self.rejected()
        self.script.write_bytes(b"".join(f"{i} 0 0 0 0 0 0 0\n".encode() for i in range(4095)))
        self.rejected()
        self.script.write_bytes(b"3600000 0 0 0 0 0 0 0\n"); self.rejected()

    def test_controller_and_delay_bounds(self):
        for key, value in (("buttons", 65536), ("lt", 256), ("lx", -32769),
                           ("lead_ms", 999), ("hold_ms", 49), ("hold_ms", 10001)):
            old = getattr(self.args, key); setattr(self.args, key, value)
            with self.subTest(key=key): self.rejected()
            setattr(self.args, key, old)

    def test_test_clock_missing_and_multiple_anchors_rejected(self):
        for text in (self.line("true"), "no clock record", self.line() * 2):
            self.log.write_text(text); self.rejected()

    def test_pid_reuse_future_and_foreign_process_rejected(self):
        self.anchor["monotonic_ms"] = 0; self.log.write_text(self.line()); self.rejected()
        self.anchor["monotonic_ms"] = time.monotonic_ns() // 1000000 + 100000
        self.log.write_text(self.line()); self.rejected()
        self.anchor["monotonic_ms"] = time.monotonic_ns() // 1000000
        self.anchor["pid"] = 999999999; self.log.write_text(self.line()); self.rejected()

    def test_short_append_is_not_claimed_success(self):
        before = self.script.read_bytes()
        with mock.patch.object(helper.os, "write", return_value=1):
            with self.assertRaises(ValueError): helper.append(self.args)
        self.assertEqual(self.script.read_bytes(), before)

    def test_button_delivery_requires_guest_records(self):
        manifest = helper.append(self.args)
        path = self.directory / "manifest.json"; path.write_text(json.dumps(manifest))
        args = types.SimpleNamespace(manifest=str(path), runtime_log=str(self.log))
        press, release = manifest["rows"]
        base = self.line() + "Offline controller append accepted: elapsed_ms=250 previous_rows=1 rows=3\n"
        self.log.write_text(base + f"Offline UI controller transition: elapsed_ms={press['milliseconds']} packet=2 buttons=1000\n")
        self.assertFalse(helper.verify(args)["all_button_edges_guest_delivered"])
        self.log.write_text(base + f"Offline controller UI-consumed: elapsed_ms={press['milliseconds']} packet=2 buttons=0000\n")
        result = helper.verify(args)
        self.assertFalse(result["all_button_edges_guest_delivered"])
        self.assertTrue(result["delivery"][0]["ui_consumed_observed"])
        self.log.write_text(base + f"Offline controller transition: elapsed_ms={press['milliseconds']} packet=2 buttons=1000\n"
                            + f"Offline controller transition: elapsed_ms={release['milliseconds']} packet=3 buttons=0000\n")
        result = helper.verify(args)
        self.assertTrue(result["all_button_edges_guest_delivered"])
        self.assertTrue(result["schedule_rows_accepted"])

    def test_cli_error_does_not_echo_contents(self):
        self.script.write_text("PRIVATE-CONTENT-SHOULD-NOT-LOG\n")
        result = subprocess.run([sys.executable, "-B", str(SOURCE), "append", "--script", str(self.script),
                                 "--anchor-log", str(self.log), "--buttons", "4096"], capture_output=True, text=True)
        self.assertEqual(result.returncode, 1)
        self.assertNotIn("PRIVATE-CONTENT-SHOULD-NOT-LOG", result.stderr + result.stdout)


if __name__ == "__main__":
    unittest.main()
