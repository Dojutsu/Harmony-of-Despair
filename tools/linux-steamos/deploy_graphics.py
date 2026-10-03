#!/usr/bin/env python3
"""Launch a verified Harmony build in the current graphical session; return logs."""
import argparse
from datetime import datetime, timezone
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re
import shlex
import shutil
import signal
import stat
import subprocess
import sys
import time
import uuid

sys.dont_write_bytecode = True
SAFE_ID = r"[A-Za-z0-9][A-Za-z0-9._-]{0,79}"
OWNER = "Harmony graphical-session harness"
ENV_KEYS = {"XDG_RUNTIME_DIR", "WAYLAND_DISPLAY", "DISPLAY", "XAUTHORITY",
            "DBUS_SESSION_BUS_ADDRESS", "XDG_SESSION_ID", "XDG_SESSION_TYPE",
            "XDG_CURRENT_DESKTOP", "XDG_SESSION_DESKTOP"}
GAMESCOPE_EXPORT_KEYS = ENV_KEYS | {"GAMESCOPE_WAYLAND_DISPLAY"}
PROCESS_NAMES = {"steam", "gamescope", "kwin_wayland", "kwin_x11", "plasmashell"}
GAMESCOPE_UNIT = "gamescope-session.service"
GAMESCOPE_UNIT_PROPERTIES = ("MainPID", "ControlGroup", "ActiveState", "SubState", "FragmentPath", "ExecStartPath")


def sha256(path):
    result = hashlib.sha256()
    with Path(path).open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            result.update(block)
    return result.hexdigest()


def owned_path(path, uid, kind, private=False):
    path = Path(path)
    if not path.is_absolute() or path.is_symlink() or path.resolve(strict=True) != path:
        raise ValueError("session path must be absolute and free of links")
    info = path.stat()
    predicate = {"directory": stat.S_ISDIR, "socket": stat.S_ISSOCK, "file": stat.S_ISREG}[kind]
    if info.st_uid != uid or not predicate(info.st_mode) or (private and info.st_mode & 0o022):
        raise ValueError("session path has wrong owner, type or write permissions")
    return path


def validate_environment(environment, uid):
    """Validate existing session endpoints without reading authentication contents."""
    environment = {k: v for k, v in environment.items() if k in ENV_KEYS}
    runtime = owned_path(environment.get("XDG_RUNTIME_DIR", ""), uid, "directory", True)
    session_type = environment.get("XDG_SESSION_TYPE")
    if session_type not in {"wayland", "x11"}:
        raise ValueError("unsupported graphical session type")
    # Steam is an Xwayland client in Gaming Mode, but may also supply the
    # independently verified native Wayland endpoint from Gamescope's export.
    if session_type == "wayland" or "WAYLAND_DISPLAY" in environment:
        display = environment.get("WAYLAND_DISPLAY", "")
        if not re.fullmatch(r"[A-Za-z0-9_.-]+", display):
            raise ValueError("Wayland display must name a local runtime socket")
        owned_path(runtime / display, uid, "socket")
    if "DISPLAY" in environment:
        match = re.fullmatch(r":([0-9]+)(?:\.[0-9]+)?", environment["DISPLAY"])
        if not match:
            raise ValueError("X11 display must be local")
        owned_path(Path("/tmp/.X11-unix") / ("X" + match[1]), uid, "socket")
        if "XAUTHORITY" in environment:
            owned_path(environment["XAUTHORITY"], uid, "file", True)
    elif session_type == "x11":
        raise ValueError("X11 session has no display")
    address = environment.get("DBUS_SESSION_BUS_ADDRESS", "")
    match = re.fullmatch(r"unix:path=([^,;]+)(?:,guid=[0-9a-fA-F]+)?", address)
    if not match or Path(match[1]).parent != runtime:
        raise ValueError("session bus must be a local socket inside the runtime directory")
    owned_path(match[1], uid, "socket")
    return environment


def active_session(sessions, uid):
    active = [s for s in sessions if s.get("User") == str(uid) and s.get("Remote") == "no"
              and s.get("Active") == "yes" and s.get("State") == "active"
              and s.get("Type") in {"wayland", "x11"} and s.get("Seat")]
    if len(active) != 1:
        raise ValueError("exactly one active local graphical session is required")
    return active[0]


def validate_gamescope_proof(session, steam, unit, compositor, exported, uid, validator=validate_environment):
    """Admit only the observed SteamOS protected-compositor unit/export contract."""
    active_session([session], uid)
    expected_group = f"/user.slice/user-{uid}.slice/user@{uid}.service/session.slice/{GAMESCOPE_UNIT}"
    if (session.get("Desktop") != "gamescope" or session.get("Type") != "wayland"
            or session.get("User") != str(uid) or steam.get("uid") != uid
            or steam.get("comm") != "steam" or steam.get("session") != session["Id"]
            or Path(steam.get("executable", "")).name != "steam"):
        raise ValueError("Gamescope proof requires the current Wayland gamescope session and verified Steam client")
    if (unit.get("ActiveState") != "active" or unit.get("SubState") != "running"
            or unit.get("FragmentPath") != "/usr/lib/systemd/user/gamescope-session.service"
            or unit.get("ExecStartPath") != "/usr/lib/steamos/gamescope-session"
            or unit.get("ControlGroup") != expected_group or not unit.get("MainPID", "").isdigit()
            or int(unit["MainPID"]) <= 1):
        raise ValueError("known Gamescope user unit is not active with its expected identity")
    if (compositor.get("pid") != int(unit["MainPID"]) or compositor.get("uid") != uid
            or compositor.get("comm") != "gamescope-wl" or compositor.get("cgroup") != expected_group):
        raise ValueError("Gamescope user-unit MainPID/UID/comm/cgroup proof disagrees")
    source = {k: v for k, v in steam["environment"].items() if k in ENV_KEYS}
    for key in ("XDG_RUNTIME_DIR", "DBUS_SESSION_BUS_ADDRESS", "DISPLAY", "XDG_SESSION_ID",
                "XDG_SESSION_TYPE", "XDG_SESSION_DESKTOP", "XDG_CURRENT_DESKTOP"):
        if not source.get(key) or exported.get(key) != source[key]:
            raise ValueError("Gamescope export and current Steam environment disagree: " + key)
    if (source["XDG_SESSION_ID"] != session["Id"] or source["XDG_SESSION_TYPE"] != "x11"
            or source["XDG_SESSION_DESKTOP"] != "gamescope" or source["XDG_CURRENT_DESKTOP"] != "gamescope"):
        raise ValueError("Gamescope export/client does not describe the observed active session")
    display = exported.get("GAMESCOPE_WAYLAND_DISPLAY", "")
    if not re.fullmatch(r"[A-Za-z0-9_.-]+", display):
        raise ValueError("Gamescope export lacks a local native Wayland endpoint")
    for environment in (source, exported):
        if "WAYLAND_DISPLAY" in environment and environment["WAYLAND_DISPLAY"] != display:
            raise ValueError("Gamescope native Wayland endpoint conflicts with the client/export")
    source["WAYLAND_DISPLAY"] = display
    return {"session_id": session["Id"], "uid": uid, "source_pid": steam["pid"],
            "unit": {k: unit[k] for k in GAMESCOPE_UNIT_PROPERTIES}, "compositor": compositor,
            "client_session_type": "x11", "session_type": "wayland",
            "native_wayland_export": {"key": "GAMESCOPE_WAYLAND_DISPLAY", "value": display},
            "environment": validator(source, uid)}


def read_gamescope_export(path, uid):
    path = owned_path(path, uid, "file", True)
    values = {}
    descriptor = os.open(path, os.O_RDONLY | os.O_NOFOLLOW)
    with os.fdopen(descriptor) as stream:
        before = os.fstat(stream.fileno())
        if (before.st_uid != uid or before.st_size > 65536 or not stat.S_ISREG(before.st_mode)
                or before.st_mode & 0o022):
            raise ValueError("invalid Gamescope environment export")
        for line in stream:
            match = re.fullmatch(r"(?:export\s+)?([A-Z_][A-Z0-9_]*)=(.*)", line.strip())
            if not match or match[1] not in GAMESCOPE_EXPORT_KEYS:
                continue
            if match[1] in values:
                raise ValueError("duplicate selected key in Gamescope environment export")
            value = shlex.split(match[2], comments=True, posix=True)
            if len(value) != 1:
                raise ValueError("invalid selected value in Gamescope environment export")
            values[match[1]] = value[0]
        after = os.fstat(stream.fileno())
        if (before.st_dev, before.st_ino, before.st_size, before.st_mtime_ns) != (
                after.st_dev, after.st_ino, after.st_size, after.st_mtime_ns):
            raise ValueError("Gamescope environment export changed during discovery")
    return values


def read_gamescope_metadata(pid):
    directory = Path("/proc") / str(pid)
    uid_line = next(line for line in (directory / "status").read_text().splitlines() if line.startswith("Uid:"))
    uids = [int(value) for value in uid_line.split()[1:]]
    if len(set(uids)) != 1 or directory.stat().st_uid != uids[0]:
        raise ValueError("Gamescope compositor has inconsistent process ownership")
    groups = [line.split("::", 1)[1] for line in (directory / "cgroup").read_text().splitlines()
              if line.startswith("0::")]
    if len(groups) != 1:
        raise ValueError("Gamescope compositor requires the observed unified user-unit cgroup")
    tail = (directory / "stat").read_text().rsplit(")", 1)[1].split()
    return {"pid": pid, "uid": uids[0], "comm": (directory / "comm").read_text().strip(),
            "cgroup": groups[0], "start_ticks": int(tail[19])}


def read_gamescope_unit(environment):
    query = ["systemctl", "--user", "show", GAMESCOPE_UNIT, "--no-pager",
             "--property=" + ",".join(k for k in GAMESCOPE_UNIT_PROPERTIES if k != "ExecStartPath") + ",ExecStart"]
    output = subprocess.check_output(query, text=True, timeout=10,
                                    env={"PATH": "/usr/bin:/bin", "LANG": "C.UTF-8",
                                         "XDG_RUNTIME_DIR": environment["XDG_RUNTIME_DIR"],
                                         "DBUS_SESSION_BUS_ADDRESS": environment["DBUS_SESSION_BUS_ADDRESS"]})
    values = dict(line.split("=", 1) for line in output.splitlines() if "=" in line)
    command = re.search(r"(?:^|\s)path=([^ ;]+)", values.pop("ExecStart", ""))
    values["ExecStartPath"] = command[1] if command else ""
    return values


def discover_gamescope_proof(session, processes, uid):
    clients = [p for p in processes if p.get("uid") == uid and p.get("session") == session["Id"]
               and p.get("comm") == "steam"]
    if len(clients) != 1:
        raise ValueError("protected Gamescope discovery requires exactly one verified current-session Steam client")
    steam = clients[0]
    environment = validate_environment(steam["environment"], uid)
    unit = read_gamescope_unit(environment)
    if not unit.get("MainPID", "").isdigit() or int(unit["MainPID"]) <= 1:
        raise ValueError("known Gamescope unit has no live MainPID")
    compositor = read_gamescope_metadata(int(unit["MainPID"]))
    export_path = Path(environment["XDG_RUNTIME_DIR"]) / "gamescope-environment"
    exported = read_gamescope_export(export_path, uid)
    proof = validate_gamescope_proof(session, steam, unit, compositor, exported, uid)
    if read_gamescope_unit(environment) != unit or read_gamescope_metadata(compositor["pid"]) != compositor:
        raise ValueError("Gamescope unit/compositor identity changed during discovery")
    proof["environment_source"] = str(export_path)
    return proof


def select_session(sessions, processes, uid, mode, validator=validate_environment, gaming_proof=None):
    session = active_session(sessions, uid)
    candidates = [p for p in processes if p.get("uid") == uid and p.get("session") == session["Id"]
                  and p.get("comm") in PROCESS_NAMES]
    if gaming_proof and (gaming_proof["session_id"] != session["Id"] or gaming_proof["uid"] != uid
                         or session.get("Desktop") != "gamescope"):
        raise ValueError("Gamescope proof belongs to a different session or user")
    gaming = session.get("Desktop") == "gamescope" and (
        gaming_proof is not None or any(p["comm"] == "gamescope" for p in candidates))
    if mode == "gaming" and not gaming:
        raise ValueError("current graphical session has no live Gamescope; Gaming Mode is not active")
    if mode == "desktop" and gaming:
        raise ValueError("current graphical session is Gaming Mode; use --mode gaming")
    priority = {"steam": 0 if gaming else 2, "plasmashell": 0, "kwin_wayland": 1,
                "kwin_x11": 1, "gamescope": 3}
    rejected = []
    for process in sorted(candidates, key=lambda p: (priority[p["comm"]], p["pid"])):
        try:
            if gaming_proof:
                if process["pid"] != gaming_proof["source_pid"]:
                    continue
                environment = validator(gaming_proof["environment"], uid)
            else:
                environment = validator(process["environment"], uid)
            if environment.get("XDG_SESSION_ID", session["Id"]) != session["Id"]:
                raise ValueError("process environment names a different logind session")
            if environment["XDG_SESSION_TYPE"] != session["Type"] and not gaming_proof:
                raise ValueError("process environment and logind session type disagree")
        except (OSError, ValueError) as error:
            rejected.append({"pid": process["pid"], "reason": str(error)})
            continue
        return {"session": session, "source_pid": process["pid"], "source_process": process["comm"],
                "source_executable": process.get("executable"),
                "mode": "gaming" if gaming else "desktop", "environment": environment,
                "client_session_type": environment["XDG_SESSION_TYPE"], "gaming_proof": gaming_proof,
                "rejected_candidates": rejected}
    raise ValueError("no verified current-session process provides usable graphical endpoints")


def discover_session(mode):
    uid = os.getuid()
    listing = subprocess.check_output(["loginctl", "list-sessions", "--no-legend", "--no-pager"], text=True)
    sessions = []
    for line in listing.splitlines():
        session_id = line.split()[0]
        data = subprocess.check_output(["loginctl", "show-session", session_id, "--no-pager"], text=True)
        values = dict(line.split("=", 1) for line in data.splitlines() if "=" in line)
        sessions.append({k: values.get(k, "") for k in
                         ("Id", "User", "Name", "Remote", "Active", "State", "Type", "Seat", "Leader", "Service", "Desktop")})
    processes = []
    for directory in Path("/proc").iterdir():
        if not directory.name.isdigit():
            continue
        try:
            if directory.stat().st_uid != uid:
                continue
            comm = (directory / "comm").read_text().strip()
            if comm not in PROCESS_NAMES:
                continue
            executable = os.readlink(directory / "exe")
            if Path(executable).name != comm:
                continue
            raw = (directory / "environ").read_bytes()
            environment = {}
            for entry in raw.split(b"\0"):
                key, separator, value = entry.partition(b"=")
                if separator and key.decode(errors="replace") in ENV_KEYS:
                    environment[key.decode()] = value.decode()
            session_id = environment.get("XDG_SESSION_ID")
            if not session_id:
                match = re.search(r"/session-([A-Za-z0-9]+)\.scope(?:/|$)", (directory / "cgroup").read_text())
                session_id = match[1] if match else None
            processes.append({"pid": int(directory.name), "uid": uid, "comm": comm,
                              "executable": executable, "session": session_id, "environment": environment})
        except (OSError, UnicodeError):
            continue
    session = active_session(sessions, uid)
    proof = discover_gamescope_proof(session, processes, uid) if session.get("Desktop") == "gamescope" else None
    return select_session(sessions, processes, uid, mode, gaming_proof=proof)


def verify_build(root, build_id):
    home = Path.home().resolve()
    root = Path(root)
    if root.is_symlink() or root.resolve(strict=True) != root or home not in root.parents:
        raise ValueError("deployment root must be a real directory under the target user's home")
    owned_path(root, os.getuid(), "directory", True)
    marker = root / ".harmony-dev-layout.json"
    if (marker.is_symlink() or json.loads(marker.read_text()) !=
            {"schema": 1, "owner": "Harmony Linux startup harness"}):
        raise ValueError("deployment root lacks the existing startup harness ownership marker")
    if not re.fullmatch(SAFE_ID, build_id):
        raise ValueError("invalid immutable build identity")
    build = root / "builds" / build_id
    if build.resolve(strict=True) != build or build.is_symlink():
        raise ValueError("immutable build path must not contain links")
    owned_path(build, os.getuid(), "directory", True)
    manifest_path = owned_path(build / "manifest.json", os.getuid(), "file", True)
    manifest = json.loads(manifest_path.read_text())
    if type(manifest.get("schema")) is not int or manifest["schema"] != 1 or manifest.get("build_id") != build_id or not isinstance(manifest.get("files"), dict):
        raise ValueError("invalid immutable build manifest")
    payload = {}
    for path in build.rglob("*"):
        if path.is_symlink() or not (path.is_file() or path.is_dir()):
            raise ValueError("immutable build contains a link or special file")
        if path.is_file() and path != manifest_path:
            payload[path.relative_to(build).as_posix()] = path
    if set(payload) != set(manifest["files"]):
        raise ValueError("immutable build payload differs from manifest")
    for name, path in payload.items():
        if not re.fullmatch(r"(?:bin|lib)/[A-Za-z0-9_.+-]+", name):
            raise ValueError("unsafe immutable payload name")
        entry = manifest["files"][name]
        if (path.stat().st_uid != os.getuid() or path.stat().st_mode & 0o7777 != entry.get("mode")
                or sha256(path) != entry.get("sha256")):
            raise ValueError("immutable build owner/mode/hash mismatch: " + name)
    if not {"bin/harmonyrecomp", "bin/ld-linux-x86-64.so.2"} <= set(payload):
        raise ValueError("immutable build lacks the native application or pinned loader")
    return build, manifest


def process_identity(pid):
    directory = Path("/proc") / str(pid)
    try:
        tail = (directory / "stat").read_text().rsplit(")", 1)[1].split()
        return {"uid": directory.stat().st_uid, "start_ticks": int(tail[19]),
                "pgid": os.getpgid(pid), "command_sha256": hashlib.sha256((directory / "cmdline").read_bytes()).hexdigest()}
    except (FileNotFoundError, ProcessLookupError):
        return None


def group_members(pgid):
    members = []
    for directory in Path("/proc").iterdir():
        if not directory.name.isdigit():
            continue
        try:
            tail = (directory / "stat").read_text().rsplit(")", 1)[1].split()
            if int(tail[2]) == pgid:
                members.append({"pid": int(directory.name), "uid": directory.stat().st_uid,
                                "start_ticks": int(tail[19]), "state": tail[0]})
        except (FileNotFoundError, ProcessLookupError):
            continue
    return members


def cleanup_group(pid, start_ticks):
    """Clean only members of the newly isolated group with matching ownership."""
    for sig in (signal.SIGTERM, signal.SIGKILL):
        members = group_members(pid)
        if not members:
            return []
        if any(m["uid"] != os.getuid() or m["start_ticks"] < start_ticks for m in members):
            raise ValueError("refusing process-group cleanup: membership ownership changed")
        try:
            os.killpg(pid, sig)
        except ProcessLookupError:
            return []
        time.sleep(0.2)
    # Zombies are exited processes awaiting their parent's reap, not running tests.
    remaining = [m for m in group_members(pid) if m["state"] != "Z"]
    if remaining:
        raise ValueError("graphical process group still has running members after cleanup")
    return remaining


def execute_bounded(command, cwd, environment, run, timeout):
    process = None
    identity = None
    record = {"owner": OWNER, "active": False}
    metadata = run / "graphics-process.json"
    try:
        with (run / "stdout.log").open("wb") as stdout, (run / "stderr.log").open("wb") as stderr:
            process = subprocess.Popen(command, cwd=cwd, env=environment, stdout=stdout, stderr=stderr,
                                       start_new_session=True)
            identity = process_identity(process.pid)
            record["pid"] = process.pid
            if identity is not None:
                record.update(active=True, **identity)
                if identity["uid"] != os.getuid() or identity["pgid"] != process.pid:
                    raise ValueError("new graphical process has unexpected ownership or process group")
            metadata.write_text(json.dumps(record, indent=2) + "\n")
            timed_out = False
            try:
                code = process.wait(timeout=timeout)
            except subprocess.TimeoutExpired:
                timed_out = True
                os.killpg(process.pid, signal.SIGTERM)
                try:
                    code = process.wait(timeout=5)
                except subprocess.TimeoutExpired:
                    os.killpg(process.pid, signal.SIGKILL)
                    code = process.wait(timeout=5)
            record.update(exit_code=code, timed_out=timed_out)
            return {"exit_code": code, "signal": -code if code < 0 else None, "timed_out": timed_out,
                    "status": "pass" if code == 0 and not timed_out else "failure"}
    finally:
        if process is not None:
            if identity is not None:
                record["remaining_processes"] = cleanup_group(process.pid, identity["start_ticks"])
            if process.poll() is None:
                process.wait(timeout=5)
        record["active"] = False
        metadata.write_text(json.dumps(record, indent=2) + "\n")


def terminate_owned_group(record):
    """Only a still matching recorded session leader may authorize stale cleanup."""
    pid = record["pid"]
    current = process_identity(pid)
    if current is None:
        if group_members(pid):
            raise ValueError("refusing stale cleanup: exited leader has unverifiable remaining group members")
        return "already-exited"
    expected = {k: record[k] for k in ("uid", "start_ticks", "pgid", "command_sha256")}
    if current != expected or current["uid"] != os.getuid() or current["pgid"] != pid:
        raise ValueError("refusing stale cleanup: PID ownership/start time/command changed")
    cleanup_group(pid, current["start_ticks"])
    return "terminated"


def cleanup_stale_runs(root):
    cleaned = []
    for path in (root / "logs").glob("*/graphics-process.json"):
        if path.is_symlink() or path.parent.is_symlink():
            raise ValueError("graphical run metadata must not contain links")
        record = json.loads(path.read_text())
        if record.get("owner") != OWNER or not record.get("active"):
            continue
        status = terminate_owned_group(record)
        record.update(active=False, cleanup=status)
        path.write_text(json.dumps(record, indent=2) + "\n")
        cleaned.append({"run": path.parent.name, "cleanup": status})
    return cleaned


def remote_run(args):
    build, manifest = verify_build(Path(args.root), args.build_id)
    root = Path(args.root)
    if (root / "logs").is_symlink() or not (root / "logs").is_dir():
        raise ValueError("existing logs directory is not a real owned directory")
    owned_path(root / "logs", os.getuid(), "directory", True)
    lock_path = root / ".graphics-launch.lock"
    descriptor = os.open(lock_path, os.O_WRONLY | os.O_CREAT | os.O_NOFOLLOW, 0o600)
    with os.fdopen(descriptor, "w") as lock:
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        stale = cleanup_stale_runs(root)
        run = root / "logs" / args.run_id
        run.mkdir()
        receipt = {"schema": 1, "owner": OWNER, "build_id": args.build_id, "source": manifest.get("source"),
                   "run_id": args.run_id, "mode": args.mode, "status": "failure", "stage": "session-discovery",
                   "stale_cleanup": stale, "run_path": str(run)}
        payload = run / "payload"
        try:
            session = discover_session(args.mode)
            receipt["session"] = session
            receipt["stage"] = "payload-copy"
            shutil.copytree(build, payload)
            for name in ("home", "tmp", "cache", "config", "data"):
                (run / name).mkdir()
            environment = {"PATH": "/usr/bin:/bin", "HOME": str(run / "home"), "TMPDIR": str(run / "tmp"),
                           "XDG_CACHE_HOME": str(run / "cache"), "XDG_CONFIG_HOME": str(run / "config"),
                           "XDG_DATA_HOME": str(run / "data"), "LANG": "C.UTF-8", "LC_ALL": "C.UTF-8",
                           **session["environment"]}
            if args.video_driver:
                environment["SDL_VIDEODRIVER"] = args.video_driver
            relative = "bin/" + args.executable
            if relative not in manifest["files"] or not manifest["files"][relative]["mode"] & 0o111:
                raise ValueError("executable must be a declared executable in the immutable build")
            command = [str(payload / "bin/ld-linux-x86-64.so.2"), "--library-path",
                       str(payload / "bin") + ":" + str(payload / "lib"), str(payload / relative),
                       *(argument.replace("{run}", str(run)) for argument in args.arg)]
            receipt.update(stage="graphical-execution", argv=command, environment=environment)
            receipt.update(execute_bounded(command, payload / "bin", environment, run, args.timeout), stage="complete")
        except Exception as error:
            receipt["error"] = str(error)
        finally:
            if payload.exists():
                shutil.rmtree(payload)
            receipt["payload_removed"] = not payload.exists()
            (run / "receipt.json").write_text(json.dumps(receipt, indent=2) + "\n")
            artifacts = sorted(path.relative_to(run).as_posix() for path in run.rglob("*")
                               if path.is_file() and not path.is_symlink()
                               and path.parts[len(run.parts)] not in {"home", "tmp", "cache", "config", "data"})
            print(json.dumps({"receipt": receipt, "artifacts": artifacts}))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--target", default="harmony-ally")
    parser.add_argument("--root", default="/home/deck/.local/share/harmony-dev")
    parser.add_argument("--build-id", required=True)
    parser.add_argument("--mode", choices=("gaming", "desktop"), default="gaming")
    parser.add_argument("--executable", default="harmonyrecomp")
    parser.add_argument("--arg", action="append", default=[], help="argument; {run} expands to this run's log directory")
    parser.add_argument("--video-driver", choices=("wayland", "x11"))
    parser.add_argument("--timeout", type=int, default=30)
    parser.add_argument("--output-directory", type=Path)
    parser.add_argument("--remote", action="store_true", help=argparse.SUPPRESS)
    parser.add_argument("--run-id", help=argparse.SUPPRESS)
    for name in ("ssh-config", "identity", "known-hosts"):
        parser.add_argument("--" + name, type=Path)
    args = parser.parse_args()
    if (not re.fullmatch(SAFE_ID, args.build_id) or not re.fullmatch(r"[A-Za-z0-9_.+-]+", args.executable)
            or not re.fullmatch(r"[A-Za-z0-9_.-]+", args.target) or not re.fullmatch(r"/[A-Za-z0-9_./-]+", args.root)
            or not 1 <= args.timeout <= 120):
        parser.error("invalid identity/path or timeout outside 1..120 seconds")
    if args.remote:
        if not args.run_id or not re.fullmatch(SAFE_ID, args.run_id):
            parser.error("invalid remote run identity")
        remote_run(args)
        return 0
    if not args.output_directory:
        parser.error("--output-directory is required")
    source = Path(__file__).resolve().parents[2]
    output = args.output_directory.resolve()
    if any(parent.exists() and os.path.samefile(parent, source) for parent in (output, *output.parents)):
        parser.error("return logs outside the source repository, including bind aliases")
    run_id = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ-") + uuid.uuid4().hex[:8]
    destination = output / run_id
    destination.mkdir(parents=True)
    options = ["-oBatchMode=yes", "-oStrictHostKeyChecking=yes", "-oConnectTimeout=10"]
    for value, flag in ((args.ssh_config, "-F"), (args.identity, "-i")):
        if value:
            options += [flag, str(value)]
    if args.known_hosts:
        options += ["-oUserKnownHostsFile=" + str(args.known_hosts)]
    remote_arguments = ["--remote", "--run-id", run_id, "--root", args.root, "--build-id", args.build_id,
                        "--mode", args.mode, "--executable", args.executable, "--timeout", str(args.timeout)]
    if args.video_driver:
        remote_arguments += ["--video-driver", args.video_driver]
    remote_arguments += ["--arg=" + argument for argument in args.arg]
    transport = {"schema": 1, "run_id": run_id, "target": args.target, "status": "failure"}
    try:
        result = subprocess.run(["ssh", *options, args.target, "python3 - " + shlex.join(remote_arguments)],
                                input=Path(__file__).read_text(), text=True, capture_output=True,
                                timeout=args.timeout + 120)
        (destination / "transport.stdout.log").write_text(result.stdout)
        (destination / "transport.stderr.log").write_text(result.stderr)
        transport["ssh_exit"] = result.returncode
        result.check_returncode()
        returned = json.loads(result.stdout)
        for artifact in returned["artifacts"]:
            if not re.fullmatch(r"[A-Za-z0-9_./+-]+", artifact) or ".." in Path(artifact).parts:
                raise ValueError("unsafe returned artifact name")
            local = destination / artifact
            local.parent.mkdir(parents=True, exist_ok=True)
            subprocess.run(["scp", *options, args.target + ":" + args.root + "/logs/" + run_id + "/" + artifact,
                            str(local)], check=True, timeout=120)
        receipt = returned["receipt"]
        (destination / "deployment-receipt.json").write_text(json.dumps(receipt, indent=2) + "\n")
        transport.update(status="pass", receipt=str(destination / "deployment-receipt.json"))
    except Exception as error:
        transport["error"] = str(error)
        raise
    finally:
        (destination / "transport-receipt.json").write_text(json.dumps(transport, indent=2) + "\n")
    print(json.dumps({"status": receipt["status"], "receipt": str(destination / "deployment-receipt.json")}))
    return 0 if receipt["status"] == "pass" else 1


if __name__ == "__main__":
    try:
        sys.exit(main())
    except (OSError, ValueError, KeyError, subprocess.SubprocessError) as error:
        sys.exit("graphical deployment failed: " + str(error))
