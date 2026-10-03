"""Graphical session, artifact ownership and bounded process tests; no SSH needed."""
from contextlib import redirect_stdout
import io
import json
import os
from pathlib import Path
import signal
import socket
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

import deploy_graphics as graphics


class GraphicalSessionTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name)
        self.uid = os.getuid()
        self.sockets = []
        for name in ("wayland-dynamic", "bus"):
            sock = socket.socket(socket.AF_UNIX)
            sock.bind(str(self.root / name))
            self.sockets.append(sock)
            self.addCleanup(sock.close)
        self.environment = {"XDG_RUNTIME_DIR": str(self.root), "WAYLAND_DISPLAY": "wayland-dynamic",
                            "DBUS_SESSION_BUS_ADDRESS": "unix:path=" + str(self.root / "bus"),
                            "XDG_SESSION_TYPE": "wayland", "XDG_SESSION_ID": "dynamic82",
                            "LD_PRELOAD": "/untrusted/injection.so", "STEAM_COMPAT_DATA_PATH": "/not-imported"}
        self.session = {"Id": "dynamic82", "User": str(self.uid), "Remote": "no", "Active": "yes",
                        "State": "active", "Type": "wayland", "Seat": "seat0"}
        self.process = {"pid": 123, "uid": self.uid, "comm": "plasmashell", "session": "dynamic82",
                        "environment": self.environment}

    def test_existing_wayland_endpoints_and_allowlist(self):
        result = graphics.select_session([self.session], [self.process], self.uid, "desktop")
        self.assertEqual(result["mode"], "desktop")
        self.assertEqual(result["environment"]["WAYLAND_DISPLAY"], "wayland-dynamic")
        self.assertNotIn("LD_PRELOAD", result["environment"])
        self.assertNotIn("STEAM_COMPAT_DATA_PATH", result["environment"])

    def test_default_gaming_refuses_desktop_without_modifying_it(self):
        with self.assertRaisesRegex(ValueError, "Gaming Mode is not active"):
            graphics.select_session([self.session], [self.process], self.uid, "gaming")
        self.assertTrue((self.root / "wayland-dynamic").exists())

    def test_live_same_session_gamescope_and_steam_are_required(self):
        session = {**self.session, "Desktop": "gamescope"}
        gamescope = {**self.process, "pid": 10, "comm": "gamescope", "environment": {}}
        steam = {**self.process, "pid": 20, "comm": "steam"}
        result = graphics.select_session([session], [gamescope, steam], self.uid, "gaming")
        self.assertEqual(result["source_process"], "steam")
        self.assertEqual(result["mode"], "gaming")
        with self.assertRaisesRegex(ValueError, "use --mode gaming"):
            graphics.select_session([session], [gamescope, steam], self.uid, "desktop")
        with self.assertRaisesRegex(ValueError, "Gaming Mode is not active"):
            graphics.select_session([session], [{**gamescope, "session": "old"}, steam], self.uid, "gaming")

    def test_ambiguous_inactive_remote_and_foreign_sessions_are_refused(self):
        variants = [[], [self.session, {**self.session, "Id": "other"}],
                    [{**self.session, "Active": "no"}], [{**self.session, "Remote": "yes"}],
                    [{**self.session, "User": str(self.uid + 1)}]]
        for sessions in variants:
            with self.subTest(sessions=sessions), self.assertRaisesRegex(ValueError, "exactly one"):
                graphics.select_session(sessions, [self.process], self.uid, "desktop")

    def test_foreign_webhelper_and_wrong_session_processes_are_excluded(self):
        variants = [{**self.process, "uid": self.uid + 1}, {**self.process, "comm": "steamwebhelper"},
                    {**self.process, "session": "old"}]
        for process in variants:
            with self.subTest(process=process), self.assertRaisesRegex(ValueError, "no verified"):
                graphics.select_session([self.session], [process], self.uid, "desktop")

    def test_missing_linked_or_world_writable_runtime_is_rejected(self):
        linked = self.root / "linked-runtime"
        linked.symlink_to(self.root, target_is_directory=True)
        for runtime in (str(self.root / "missing"), str(linked)):
            with self.subTest(runtime=runtime), self.assertRaises((ValueError, OSError)):
                graphics.validate_environment({**self.environment, "XDG_RUNTIME_DIR": runtime}, self.uid)
        self.root.chmod(0o777)
        with self.assertRaisesRegex(ValueError, "permissions"):
            graphics.validate_environment(self.environment, self.uid)
        self.root.chmod(0o700)

    def test_wayland_traversal_bus_outside_runtime_and_remote_x11_rejected(self):
        changes = [{"WAYLAND_DISPLAY": "../foreign"}, {"WAYLAND_DISPLAY": "/tmp/foreign"},
                   {"DBUS_SESSION_BUS_ADDRESS": "tcp:host=127.0.0.1,port=1234"},
                   {"DBUS_SESSION_BUS_ADDRESS": "unix:path=/other/bus"}, {"DISPLAY": "remote:0"}]
        for change in changes:
            with self.subTest(change=change), self.assertRaises(ValueError):
                graphics.validate_environment({**self.environment, **change}, self.uid)

    def test_reconnect_selects_current_display_and_session_values(self):
        replacement = socket.socket(socket.AF_UNIX)
        self.addCleanup(replacement.close)
        replacement.bind(str(self.root / "wayland-new"))
        session = {**self.session, "Id": "after-normal-session-change"}
        process = {**self.process, "session": session["Id"],
                   "environment": {**self.environment, "XDG_SESSION_ID": session["Id"], "WAYLAND_DISPLAY": "wayland-new"}}
        result = graphics.select_session([session], [process], self.uid, "desktop")
        self.assertEqual(result["session"]["Id"], session["Id"])
        self.assertEqual(result["environment"]["WAYLAND_DISPLAY"], "wayland-new")

    def test_authentication_file_contents_are_never_read(self):
        authority = self.root / "authority"
        authority.write_text("this secret must not be read")
        authority.chmod(0o600)
        # Its metadata is sufficient; the socket check is independently tested above.
        with patch.object(graphics, "owned_path", wraps=graphics.owned_path) as own:
            with patch.object(Path, "read_bytes", side_effect=AssertionError("unexpected credential read")):
                self.assertEqual(graphics.owned_path(authority, self.uid, "file", True), authority)
        self.assertEqual(own.call_count, 1)

    def test_discovery_checks_process_executable_and_selects_dynamic_session(self):
        process = self.root / "12345"
        process.mkdir()
        (process / "comm").write_text("gamescope\n")
        (process / "exe").symlink_to("/usr/bin/gamescope")
        (process / "environ").write_bytes(b"\0".join((k + "=" + v).encode() for k, v in self.environment.items()))
        properties = "\n".join(k + "=" + v for k, v in {**self.session, "Desktop": "gamescope"}.items())
        def loginctl(command, **unused):
            return "dynamic82 fake session\n" if command[1] == "list-sessions" else properties
        original = Path.iterdir
        def directories(path):
            return iter([process]) if path == Path("/proc") else original(path)
        # The protected-unit proof has its own tests below; retain this fixture's
        # original purpose of checking accessible process executable selection.
        with patch.object(subprocess, "check_output", side_effect=loginctl), patch.object(Path, "iterdir", directories), \
                patch.object(graphics, "discover_gamescope_proof", return_value=None):
            result = graphics.discover_session("gaming")
            self.assertEqual(result["source_executable"], "/usr/bin/gamescope")
            self.assertEqual(result["session"]["Id"], "dynamic82")
            (process / "exe").unlink()
            (process / "exe").symlink_to("/untrusted/not-gamescope")
            with self.assertRaisesRegex(ValueError, "Gaming Mode is not active"):
                graphics.discover_session("gaming")

    def test_nested_gamescope_in_kde_is_not_gaming_mode(self):
        session = {**self.session, "Desktop": "KDE"}
        nested = {**self.process, "pid": 10, "comm": "gamescope"}
        with self.assertRaisesRegex(ValueError, "Gaming Mode is not active"):
            graphics.select_session([session], [nested, self.process], self.uid, "gaming")
        result = graphics.select_session([session], [nested, self.process], self.uid, "desktop")
        self.assertEqual(result["mode"], "desktop")
        self.assertEqual(result["source_process"], "plasmashell")


class GamescopeQualificationTests(unittest.TestCase):
    def setUp(self):
        GraphicalSessionTests.setUp(self)
        self.session["Desktop"] = "gamescope"
        self.steam = {**self.process, "comm": "steam", "executable": "/verified/steam",
                      "environment": {**self.environment, "XDG_SESSION_TYPE": "x11", "DISPLAY": ":987654",
                                      "XDG_CURRENT_DESKTOP": "gamescope", "XDG_SESSION_DESKTOP": "gamescope"}}
        self.steam["environment"].pop("WAYLAND_DISPLAY")
        self.unit = {"MainPID": "45678", "ControlGroup":
                     f"/user.slice/user-{self.uid}.slice/user@{self.uid}.service/session.slice/gamescope-session.service",
                     "ActiveState": "active", "SubState": "running",
                     "FragmentPath": "/usr/lib/systemd/user/gamescope-session.service",
                     "ExecStartPath": "/usr/lib/steamos/gamescope-session"}
        self.compositor = {"pid": 45678, "uid": self.uid, "comm": "gamescope-wl",
                           "cgroup": self.unit["ControlGroup"], "start_ticks": 1234}
        self.exported = {k: v for k, v in self.steam["environment"].items() if k in graphics.ENV_KEYS}
        self.exported["GAMESCOPE_WAYLAND_DISPLAY"] = "wayland-dynamic"
        original = graphics.owned_path
        def endpoints(path, uid, kind, private=False):
            # Only the fixture's Xwayland socket is synthetic. All Wayland,
            # runtime/bus and export ownership checks use real temporary nodes.
            if Path(path) == Path("/tmp/.X11-unix/X987654"):
                self.assertEqual(uid, self.uid)
                self.assertEqual(kind, "socket")
                return Path(path)
            return original(path, uid, kind, private)
        self.endpoint_patch = patch.object(graphics, "owned_path", side_effect=endpoints)
        self.endpoint_patch.start()
        self.addCleanup(self.endpoint_patch.stop)

    def proof(self, **changes):
        values = {"session": self.session, "steam": self.steam, "unit": self.unit,
                  "compositor": self.compositor, "exported": self.exported, "uid": self.uid}
        values.update(changes)
        return graphics.validate_gamescope_proof(**values)

    def test_protected_unit_and_export_admit_real_wayland_session_x11_client(self):
        proof = self.proof()
        result = graphics.select_session([self.session], [self.steam], self.uid, "gaming", gaming_proof=proof)
        self.assertEqual(result["mode"], "gaming")
        self.assertEqual(result["session"]["Type"], "wayland")
        self.assertEqual(result["client_session_type"], "x11")
        self.assertEqual(result["environment"]["XDG_SESSION_TYPE"], "x11")
        self.assertEqual(result["environment"]["WAYLAND_DISPLAY"], "wayland-dynamic")
        self.assertEqual(result["gaming_proof"]["native_wayland_export"]["key"], "GAMESCOPE_WAYLAND_DISPLAY")
        self.assertNotIn("LD_PRELOAD", result["environment"])
        self.assertNotIn("GAMESCOPE_WAYLAND_DISPLAY", result["environment"])

    def test_unknown_inactive_wrong_unit_path_pid_or_cgroup_is_refused(self):
        changes = [{"ActiveState": "inactive"}, {"SubState": "exited"}, {"MainPID": "0"},
                   {"MainPID": "not-a-pid"}, {"MainPID": "45679"}, {"ControlGroup": "/unknown/unit"},
                   {"FragmentPath": "/home/user/custom.service"}, {"ExecStartPath": "/unknown/compositor"}]
        for change in changes:
            with self.subTest(change=change), self.assertRaises(ValueError):
                self.proof(unit={**self.unit, **change})

    def test_wrong_compositor_uid_comm_or_unit_membership_is_refused(self):
        for change in ({"uid": self.uid + 1}, {"comm": "unknown"}, {"cgroup": "/other/unit"}, {"pid": 1}):
            with self.subTest(change=change), self.assertRaises(ValueError):
                self.proof(compositor={**self.compositor, **change})

    def test_stale_export_or_client_session_and_display_are_refused(self):
        for key in ("XDG_RUNTIME_DIR", "DBUS_SESSION_BUS_ADDRESS", "DISPLAY", "XDG_SESSION_ID",
                    "XDG_SESSION_TYPE", "XDG_SESSION_DESKTOP", "XDG_CURRENT_DESKTOP"):
            with self.subTest(key=key), self.assertRaisesRegex(ValueError, "disagree"):
                self.proof(exported={**self.exported, key: "stale"})
        with self.assertRaises(ValueError):
            self.proof(steam={**self.steam, "session": "old"})

    def test_kde_foreign_or_unobserved_session_type_is_not_admitted(self):
        for change in ({"Desktop": "KDE"}, {"Type": "x11"}, {"User": str(self.uid + 1)}):
            with self.subTest(change=change), self.assertRaises(ValueError):
                self.proof(session={**self.session, **change})

    def test_missing_foreign_or_linked_wayland_socket_is_refused_for_x11_client(self):
        for display in ("missing", "../outside", "/absolute/socket"):
            with self.subTest(display=display), self.assertRaises((ValueError, OSError)):
                self.proof(exported={**self.exported, "GAMESCOPE_WAYLAND_DISPLAY": display})
        (self.root / "linked-wayland").symlink_to(self.root / "wayland-dynamic")
        with self.assertRaises(ValueError):
            self.proof(exported={**self.exported, "GAMESCOPE_WAYLAND_DISPLAY": "linked-wayland"})
        original = graphics.owned_path
        def foreign_socket(path, uid, kind, private=False):
            if Path(path) == self.root / "wayland-dynamic":
                raise ValueError("session path has wrong owner")
            return original(path, uid, kind, private)
        with patch.object(graphics, "owned_path", side_effect=foreign_socket), self.assertRaisesRegex(ValueError, "owner"):
            self.proof()

    def test_conflicting_native_display_is_not_overridden(self):
        for values in ({"exported": {**self.exported, "WAYLAND_DISPLAY": "other"}},
                       {"steam": {**self.steam, "environment": {**self.steam["environment"], "WAYLAND_DISPLAY": "other"}}}):
            with self.subTest(values=values), self.assertRaisesRegex(ValueError, "conflicts"):
                self.proof(**values)

    def test_proof_cannot_be_reused_for_another_user_or_session(self):
        proof = self.proof()
        for changed in ({"uid": self.uid + 1}, {"session_id": "old"}):
            with self.subTest(changed=changed), self.assertRaisesRegex(ValueError, "different session or user"):
                graphics.select_session([self.session], [self.steam], self.uid, "gaming", gaming_proof={**proof, **changed})

    def test_export_parser_keeps_only_selected_values_without_shell_execution(self):
        export = self.root / "gamescope-environment"
        export.write_text("\n".join("export " + k + "=" + repr(v) for k, v in self.exported.items()) +
                          "\nAUTH_TOKEN=fixture-private-value\nLD_PRELOAD=/not-imported.so\n" +
                          "IGNORED_COMMAND=$(touch " + str(self.root / "must-not-exist") + ")\n")
        values = graphics.read_gamescope_export(export, self.uid)
        self.assertEqual(values, self.exported)
        self.assertNotIn("AUTH_TOKEN", values)
        self.assertFalse((self.root / "must-not-exist").exists())

    def test_export_link_duplicate_oversized_and_write_permissions_are_refused(self):
        export = self.root / "gamescope-environment"
        export.symlink_to(self.root / "unknown")
        with self.assertRaises((ValueError, OSError)):
            graphics.read_gamescope_export(export, self.uid)
        export.unlink()
        for text in ("DISPLAY=:0\nDISPLAY=:1\n", "x" * 65537):
            export.write_text(text)
            with self.subTest(text_length=len(text)), self.assertRaises(ValueError):
                graphics.read_gamescope_export(export, self.uid)
        export.write_text("DISPLAY=:0\n")
        export.chmod(0o666)
        with self.assertRaisesRegex(ValueError, "permissions"):
            graphics.read_gamescope_export(export, self.uid)

    def test_protected_compositor_discovery_uses_unit_metadata_not_private_proc_env(self):
        export = self.root / "gamescope-environment"
        export.write_text("\n".join(k + "=" + v for k, v in self.exported.items()))
        with patch.object(graphics, "read_gamescope_unit", return_value=self.unit), \
                patch.object(graphics, "read_gamescope_metadata", return_value=self.compositor), \
                patch.object(Path, "read_bytes", side_effect=AssertionError("do not read private compositor environment")):
            proof = graphics.discover_gamescope_proof(self.session, [self.steam], self.uid)
        self.assertEqual(proof["environment_source"], str(export))
        self.assertEqual(proof["compositor"]["comm"], "gamescope-wl")

    def test_unit_restart_during_discovery_is_refused(self):
        export = self.root / "gamescope-environment"
        export.write_text("\n".join(k + "=" + v for k, v in self.exported.items()))
        with patch.object(graphics, "read_gamescope_unit", side_effect=[self.unit, {**self.unit, "MainPID": "45679"}]), \
                patch.object(graphics, "read_gamescope_metadata", return_value=self.compositor):
            with self.assertRaisesRegex(ValueError, "identity changed"):
                graphics.discover_gamescope_proof(self.session, [self.steam], self.uid)


class ArtifactAndProcessTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.home = Path(self.temporary.name)
        self.root = self.home / "harmony-dev"
        self.build = self.root / "builds" / "test-build"
        (self.build / "bin").mkdir(parents=True)
        (self.root / "logs").mkdir()
        (self.root / ".harmony-dev-layout.json").write_text(json.dumps(
            {"schema": 1, "owner": "Harmony Linux startup harness"}))
        self.files = {}
        for name in ("harmonyrecomp", "ld-linux-x86-64.so.2"):
            path = self.build / "bin" / name
            path.write_bytes(b"\x7fELFtest")
            path.chmod(0o755)
            self.files["bin/" + name] = {"mode": 0o755, "sha256": graphics.sha256(path)}
        (self.build / "manifest.json").write_text(json.dumps(
            {"schema": 1, "build_id": "test-build", "files": self.files}))

    def verify(self):
        with patch.object(Path, "home", return_value=self.home):
            return graphics.verify_build(self.root, "test-build")

    def test_verified_immutable_artifacts_accepted_and_tampering_rejected(self):
        build, manifest = self.verify()
        self.assertEqual(build, self.build)
        self.assertEqual(manifest["files"], self.files)
        (self.build / "bin/harmonyrecomp").write_bytes(b"modified")
        with self.assertRaisesRegex(ValueError, "hash mismatch"):
            self.verify()

    def test_links_undeclared_files_and_nested_manifest_are_rejected(self):
        unknown = self.build / "bin/unknown"
        unknown.symlink_to("harmonyrecomp")
        with self.assertRaisesRegex(ValueError, "link"):
            self.verify()
        unknown.unlink()
        unknown.write_text("preserve")
        with self.assertRaisesRegex(ValueError, "differs from manifest"):
            self.verify()
        unknown.unlink()
        (self.build / "bin/manifest.json").write_text("nested undeclared")
        with self.assertRaisesRegex(ValueError, "differs from manifest"):
            self.verify()

    def test_unknown_root_and_changed_marker_are_preserved(self):
        marker = self.root / ".harmony-dev-layout.json"
        marker.write_text('{"owner":"another project"}')
        with self.assertRaisesRegex(ValueError, "ownership marker"):
            self.verify()
        self.assertEqual(marker.read_text(), '{"owner":"another project"}')

    def test_stale_pid_reuse_or_foreign_owner_is_never_killed(self):
        record = {"owner": graphics.OWNER, "pid": 12345, "uid": os.getuid(), "start_ticks": 10,
                  "pgid": 12345, "command_sha256": "original"}
        for changed in ({"start_ticks": 11}, {"uid": os.getuid() + 1}, {"command_sha256": "unrelated"}, {"pgid": 9}):
            identity = {k: record[k] for k in ("uid", "start_ticks", "pgid", "command_sha256")}
            identity.update(changed)
            with self.subTest(changed=changed), patch.object(graphics, "process_identity", return_value=identity), \
                    patch.object(os, "killpg") as kill:
                with self.assertRaisesRegex(ValueError, "refusing stale cleanup"):
                    graphics.terminate_owned_group(record)
                kill.assert_not_called()

    def test_unverifiable_orphan_group_is_detected_without_killing_it(self):
        with patch.object(graphics, "process_identity", return_value=None), \
                patch.object(graphics, "group_members", return_value=[{"pid": 67890}]), patch.object(os, "killpg") as kill:
            with self.assertRaisesRegex(ValueError, "unverifiable remaining group"):
                graphics.terminate_owned_group({"pid": 12345})
            kill.assert_not_called()

    def test_process_exit_stdout_stderr_and_cleanup_are_captured(self):
        run = self.root / "logs" / "normal"
        run.mkdir()
        result = graphics.execute_bounded([sys.executable, "-c", "import sys;print('out');print('err',file=sys.stderr)"],
                                          run, {"PATH": "/usr/bin:/bin"}, run, 5)
        self.assertEqual(result, {"exit_code": 0, "signal": None, "timed_out": False, "status": "pass"})
        self.assertEqual((run / "stdout.log").read_text().strip(), "out")
        self.assertEqual((run / "stderr.log").read_text().strip(), "err")
        metadata = json.loads((run / "graphics-process.json").read_text())
        self.assertFalse(metadata["active"])
        self.assertEqual(metadata["remaining_processes"], [])

    def test_timeout_cleans_own_process_group_and_preserves_unrelated_process(self):
        run = self.root / "logs" / "timeout"
        run.mkdir()
        unrelated = subprocess.Popen([sys.executable, "-c", "import time;time.sleep(20)"], start_new_session=True)
        self.addCleanup(lambda: unrelated.poll() is None and unrelated.terminate())
        self.addCleanup(lambda: unrelated.poll() is None and unrelated.wait(timeout=5))
        try:
            result = graphics.execute_bounded([sys.executable, "-c", "import time;time.sleep(20)"],
                                              run, {"PATH": "/usr/bin:/bin"}, run, 1)
            self.assertTrue(result["timed_out"])
            self.assertEqual(result["signal"], signal.SIGTERM)
            self.assertIsNone(unrelated.poll())
            metadata = json.loads((run / "graphics-process.json").read_text())
            self.assertEqual(graphics.group_members(metadata["pid"]), [])
        finally:
            unrelated.terminate()
            unrelated.wait(timeout=5)

    def test_failed_session_receipt_has_no_payload_or_process(self):
        arguments = argparse_namespace(self.root)
        output = io.StringIO()
        with patch.object(Path, "home", return_value=self.home), \
                patch.object(graphics, "discover_session", side_effect=ValueError("Gaming Mode is not active")), \
                redirect_stdout(output):
            graphics.remote_run(arguments)
        returned = json.loads(output.getvalue())
        self.assertEqual(returned["receipt"]["status"], "failure")
        self.assertEqual(returned["receipt"]["stage"], "session-discovery")
        self.assertTrue(returned["receipt"]["payload_removed"])
        self.assertFalse((self.root / "logs/test-run/payload").exists())
        self.assertFalse((self.root / "logs/test-run/graphics-process.json").exists())


def argparse_namespace(root):
    from argparse import Namespace
    return Namespace(root=str(root), build_id="test-build", run_id="test-run", mode="gaming",
                     executable="harmonyrecomp", arg=[], video_driver=None, timeout=5)


if __name__ == "__main__":
    unittest.main()
