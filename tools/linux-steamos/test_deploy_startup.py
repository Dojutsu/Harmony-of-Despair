"""Safety and acceptance checks for the L1 deployment harness; no SSH required."""
from contextlib import redirect_stdout
import hashlib
import io
import json
from pathlib import Path
import sys
import tarfile
import tempfile
import unittest
from unittest.mock import patch

import deploy_startup

from deploy_startup import REQUIRED, STAGES, validate_bundle, validate_trace


class DeploymentValidationTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name)

    def bundle(self, change=None, extra=()):
        payload = {name: b"\x7fELFfixture" for name in REQUIRED}
        manifest = {"schema": 1, "build_id": "l1-test-123", "files": {
            name: {"sha256": hashlib.sha256(data).hexdigest(), "mode": 0o755}
            for name, data in payload.items()}}
        if change: change(manifest, payload)
        path = self.root / "bundle.tar.gz"
        with tarfile.open(path, "w:gz") as archive:
            for name, data, mode in [("manifest.json", json.dumps(manifest).encode(), 0o644),
                                     *((name, data, 0o755) for name, data in payload.items())]:
                entry = tarfile.TarInfo(name); entry.size = len(data); entry.mode = mode
                archive.addfile(entry, io.BytesIO(data))
            for name, kind in extra:
                entry = tarfile.TarInfo(name); entry.mode = 0o755; entry.type = kind
                if kind == tarfile.SYMTYPE: entry.linkname = "/etc/passwd"
                archive.addfile(entry, io.BytesIO(b""))
        return path

    def events(self):
        pairs = [("process", "start"), *sorted(STAGES - {("process", "start"), ("process", "exit")}),
                 ("process", "exit")]
        events = [{"schema": 1, "sequence": i, "pid": 42, "stage": stage, "status": status,
                   "detail": "validated"} for i, (stage, status) in enumerate(pairs, 1)]
        events[-1]["detail"] = "exit_code=0; bounded native startup complete; no game/playability claim"
        return events

    def trace(self, events):
        path = self.root / "runtime.jsonl"
        path.write_text("".join(json.dumps(e) + "\n" for e in events))
        return path

    def test_complete_bundle_is_accepted(self):
        self.assertEqual(validate_bundle(self.bundle())["build_id"], "l1-test-123")

    def test_payload_hash_mismatch_is_rejected(self):
        def tamper(manifest, payload): payload["bin/harmonyrecomp"] += b"corrupt"
        with self.assertRaisesRegex(ValueError, "hash mismatch"):
            validate_bundle(self.bundle(tamper))

    def test_links_special_files_and_traversal_are_rejected(self):
        for name, kind in [("lib/link", tarfile.SYMTYPE), ("lib/device", tarfile.CHRTYPE),
                           ("../escaped", tarfile.REGTYPE), ("/absolute", tarfile.REGTYPE),
                           ("bin/../escaped", tarfile.REGTYPE), ("bin\\escaped", tarfile.REGTYPE)]:
            with self.subTest(name=name), self.assertRaises(ValueError):
                validate_bundle(self.bundle(extra=[(name, kind)]))

    def test_undeclared_payload_and_duplicate_entries_are_rejected(self):
        for extra in [[("lib/unknown.so", tarfile.REGTYPE)],
                      [("bin/harmonyrecomp", tarfile.REGTYPE)],
                      [("lib", tarfile.DIRTYPE), ("lib/", tarfile.DIRTYPE)]]:
            with self.subTest(extra=extra), self.assertRaises(ValueError):
                validate_bundle(self.bundle(extra=extra))

    def test_unknown_layout_unsafe_id_and_modes_are_rejected(self):
        for change in [lambda m, p: m.update(build_id="../overwrite"),
                       lambda m, p: m["files"]["bin/harmonyrecomp"].update(mode=0o4755),
                       lambda m, p: m["files"].pop("bin/linux_startup_test")]:
            with self.subTest(change=change), self.assertRaises(ValueError):
                validate_bundle(self.bundle(change))

    def test_non_elf_required_executable_is_rejected(self):
        def tamper(manifest, payload):
            payload["bin/harmonyrecomp"] = b"text"
            manifest["files"]["bin/harmonyrecomp"]["sha256"] = hashlib.sha256(b"text").hexdigest()
        with self.assertRaisesRegex(ValueError, "executable ELF"):
            validate_bundle(self.bundle(tamper))

    def test_complete_controlled_trace_is_accepted(self):
        events = self.events()
        self.assertEqual(validate_trace(self.trace(events)), len(events))

    def test_empty_incomplete_failing_or_malformed_trace_is_rejected(self):
        traces = [[], self.events()[:-1]]
        for key, value in [("sequence", 1), ("pid", 43), ("status", "failure"), ("schema", True)]:
            events = self.events(); events[1][key] = value; traces.append(events)
        events = self.events(); events[-1]["detail"] = "crashed"; traces.append(events)
        for events in traces:
            with self.subTest(events=events), self.assertRaises(ValueError):
                validate_trace(self.trace(events))


    def prepare_layout(self, root):
        # Exercise only remote preparation under an isolated temporary HOME.
        # It returns before bundle extraction or subprocess/ELF execution.
        output = io.StringIO()
        arguments = ["remote-prepare", str(root), "test-run-123", "0" * 64, "prepare"]
        with patch.object(Path, "home", return_value=self.root), patch.object(sys, "argv", arguments), redirect_stdout(output):
            try:
                exec(deploy_startup.REMOTE, vars(deploy_startup).copy())
            except SystemExit as exit_result:
                self.assertEqual(exit_result.code, 0)
            else:
                self.fail("preparation did not stop before runtime execution")
        return json.loads(output.getvalue())

    def test_remote_prepare_creates_only_owned_layout(self):
        root = self.root / "harmony-dev"
        result = self.prepare_layout(root)
        marker = json.loads((root / ".harmony-dev-layout.json").read_text())
        self.assertEqual(marker, {"schema": 1, "owner": "Harmony Linux startup harness"})
        self.assertEqual({p.name for p in root.iterdir()}, {".harmony-dev-layout.json", "builds", "logs"})
        self.assertTrue((root / "builds").is_dir())
        self.assertTrue((root / "logs").is_dir())
        self.assertEqual(result["upload"], str(root / "builds/.upload-test-run-123.tar.gz"))
        self.assertFalse(Path(result["upload"]).exists())
        self.assertFalse((root / "current").exists())

    def test_remote_prepare_preserves_unknown_root_and_current(self):
        unknown = self.root / "existing-project"
        unknown.mkdir()
        evidence = unknown / "user-configuration"
        evidence.write_text("preserve this existing content")
        with self.assertRaisesRegex(ValueError, "matching ownership marker"):
            self.prepare_layout(unknown)
        self.assertEqual(evidence.read_text(), "preserve this existing content")
        self.assertEqual([p.name for p in unknown.iterdir()], ["user-configuration"])

        owned = self.root / "owned-project"
        self.prepare_layout(owned)
        current = owned / "current"
        current.write_text("unknown current entry must survive")
        before = {p.name for p in owned.iterdir()}
        with self.assertRaisesRegex(ValueError, "unknown current entry"):
            self.prepare_layout(owned)
        self.assertEqual(current.read_text(), "unknown current entry must survive")
        self.assertEqual({p.name for p in owned.iterdir()}, before)
        self.assertEqual(list((owned / "builds").iterdir()), [])
        self.assertEqual(list((owned / "logs").iterdir()), [])


if __name__ == "__main__":
    unittest.main()
