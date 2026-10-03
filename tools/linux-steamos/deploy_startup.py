#!/usr/bin/env python3
"""Deploy an immutable verified startup/recovery bundle and collect bounded traces."""
import argparse
from datetime import datetime, timezone
import hashlib
import inspect
import json
import os
from pathlib import Path, PurePosixPath
import re
import shlex
import subprocess
import sys
import tarfile
import uuid

sys.dont_write_bytecode = True
SAFE_ID = r"[A-Za-z0-9][A-Za-z0-9._-]{0,79}"
REQUIRED = {"bin/harmonyrecomp", "bin/linux_startup_test", "bin/ld-linux-x86-64.so.2"}
STAGES = {("process", "start"), ("runtime", "begin"), ("runtime", "pass"),
          ("vm", "begin"), ("vm", "pass"), ("tls", "begin"), ("tls", "pass"),
          ("fault-routing", "begin"), ("fault-routing", "initialized"),
          ("native-module", "begin"), ("native-module", "pass"),
          ("platform-boundary", "begin"), ("platform-boundary", "reached"),
          ("shutdown", "begin"), ("shutdown", "pass"), ("process", "exit")}


def digest(stream):
    result = hashlib.sha256()
    for block in iter(lambda: stream.read(1024 * 1024), b""):
        result.update(block)
    return result.hexdigest()


def validate_bundle(bundle):
    """Reject links, special files, traversal, undeclared payloads and bad hashes."""
    with tarfile.open(bundle, "r:gz") as archive:
        members = archive.getmembers()
        names = set()
        for member in members:
            path = PurePosixPath(member.name)
            if (path.is_absolute() or ".." in path.parts or "\\" in member.name or
                    not path.parts or path.as_posix() != member.name.rstrip("/") or path.as_posix() in names or
                    not (member.isfile() or member.isdir()) or member.mode & ~0o777):
                raise ValueError("unsafe or duplicate archive member: " + member.name)
            names.add(path.as_posix())
            if member.name != "manifest.json" and (path.parts[0] not in {"bin", "lib"} or
                                                     member.isfile() and len(path.parts) < 2):
                raise ValueError("payload must stay inside bin/ or lib/")
        metadata = archive.getmember("manifest.json")
        if not metadata.isfile() or metadata.size > 1024 * 1024:
            raise ValueError("invalid manifest file")
        manifest = json.load(archive.extractfile(metadata))
        if (not isinstance(manifest, dict) or type(manifest.get("schema")) is not int or
                manifest["schema"] != 1 or not isinstance(manifest.get("build_id"), str) or
                not re.fullmatch(SAFE_ID, manifest["build_id"]) or
                not isinstance(manifest.get("files"), dict)):
            raise ValueError("invalid manifest schema/build_id/files")
        files = {m.name: m for m in members if m.isfile() and m.name != "manifest.json"}
        if set(files) != set(manifest["files"]) or not REQUIRED <= set(files):
            raise ValueError("manifest must list exactly the payload and required ELFs")
        if sum(m.size for m in files.values()) > 8 * 1024**3:
            raise ValueError("bundle exceeds the 8 GiB development-artifact bound")
        for name, member in files.items():
            entry = manifest["files"][name]
            if (not isinstance(entry, dict) or type(entry.get("mode")) is not int or
                    entry["mode"] != member.mode or not isinstance(entry.get("sha256"), str) or
                    not re.fullmatch(r"[0-9a-f]{64}", entry["sha256"])):
                raise ValueError("invalid manifest mode/hash: " + name)
            with archive.extractfile(member) as stream:
                if digest(stream) != entry["sha256"]:
                    raise ValueError("payload hash mismatch: " + name)
            if name in REQUIRED:
                with archive.extractfile(member) as stream:
                    if stream.read(4) != b"\x7fELF" or not member.mode & 0o111:
                        raise ValueError("required executable is not an executable ELF: " + name)
        return manifest


def validate_trace(path):
    events = [json.loads(line) for line in Path(path).read_text().splitlines() if line.strip()]
    if not events:
        raise ValueError("empty startup trace")
    for index, event in enumerate(events, 1):
        if (not isinstance(event, dict) or type(event.get("schema")) is not int or event["schema"] != 1 or
                type(event.get("sequence")) is not int or event["sequence"] != index or
                type(event.get("pid")) is not int or event["pid"] != events[0]["pid"] or
                event["pid"] <= 0 or any(not isinstance(event.get(k), str)
                                         for k in ("stage", "status", "detail")) or
                event["status"] == "failure"):
            raise ValueError("invalid/failing startup event " + str(index))
    if not STAGES <= {(e["stage"], e["status"]) for e in events}:
        raise ValueError("missing startup stages")
    if ((events[0]["stage"], events[0]["status"]) != ("process", "start") or
            (events[-1]["stage"], events[-1]["status"]) != ("process", "exit") or
            events[-1]["detail"] != "exit_code=0; bounded native startup complete; no game/playability claim"):
        raise ValueError("startup trace did not end with controlled success")
    return len(events)


REMOTE = r'''
import signal
import shutil
import time
root, run_id, archive_hash, action = sys.argv[1:]
root = Path(root)
home = Path.home().resolve()
if home not in root.resolve().parents or root.is_symlink():
    raise ValueError("deployment root must be a real directory under the target user's home")
marker = {"schema": 1, "owner": "Harmony Linux startup harness"}
marker_path = root / ".harmony-dev-layout.json"
if root.exists() and (not marker_path.is_file() or marker_path.is_symlink() or
                      json.loads(marker_path.read_text()) != marker):
    raise ValueError("existing deployment root has no matching ownership marker")
root.mkdir(parents=True, exist_ok=True)
if not marker_path.exists():
    with marker_path.open("x") as stream: json.dump(marker, stream)
for name in ("builds", "logs"):
    path = root / name
    if path.is_symlink() or (path.exists() and not path.is_dir()):
        raise ValueError("unsafe deployment layout")
    path.mkdir(exist_ok=True)
current = root / "current"
if current.exists() or current.is_symlink():
    target = Path(os.readlink(current)) if current.is_symlink() else Path("/")
    if (len(target.parts) != 2 or target.parts[0] != "builds" or
            not re.fullmatch(SAFE_ID, target.parts[1]) or
            not (root / target / "manifest.json").is_file()):
        raise ValueError("refusing to replace an unknown current entry")
upload = root / "builds" / (".upload-" + run_id + ".tar.gz")
if action == "prepare":
    if upload.exists() or (root / "logs" / run_id).exists():
        raise ValueError("run/upload already exists")
    print(json.dumps({"upload": str(upload)}))
    sys.exit(0)
run = root / "logs" / run_id
run.mkdir()
receipt = {"schema": 1, "run_id": run_id, "mode": "headless SSH, explicit SDK ELF loader",
           "deployment_root": str(root), "status": "failure", "stage": "bundle-validation"}
try:
    with upload.open("rb") as stream:
        if digest(stream) != archive_hash: raise ValueError("transport archive hash mismatch")
    manifest = validate_bundle(upload)
    build = root / "builds" / manifest["build_id"]
    receipt.update(build_id=manifest["build_id"], build_path=str(build), archive_sha256=archive_hash)
    if build.is_symlink(): raise ValueError("build path is a symlink")
    if not build.exists():
        staging = root / "builds" / (".install-" + run_id)
        staging.mkdir()
        try:
            with tarfile.open(upload, "r:gz") as archive:
                for member in archive.getmembers():
                    path = staging / member.name
                    if member.isdir(): path.mkdir(parents=True, exist_ok=True); continue
                    path.parent.mkdir(parents=True, exist_ok=True)
                    with path.open("xb") as stream: shutil.copyfileobj(archive.extractfile(member), stream)
                    path.chmod(member.mode)
            staging.rename(build)
        finally:
            if staging.exists(): shutil.rmtree(staging)
    if json.loads((build / "manifest.json").read_text()) != manifest:
        raise ValueError("immutable build ID already has a different manifest")
    actual = {str(p.relative_to(build)) for p in build.rglob("*") if p.is_file()}
    if actual != set(manifest["files"]) | {"manifest.json"}:
        raise ValueError("immutable build has unexpected/missing files")
    for name, entry in manifest["files"].items():
        path = build / name
        if path.is_symlink() or path.stat().st_mode & 0o7777 != entry["mode"]:
            raise ValueError("immutable payload mode/link mismatch: " + name)
        with path.open("rb") as stream:
            if digest(stream) != entry["sha256"]: raise ValueError("immutable payload hash mismatch: " + name)
    for name in ("home", "tmp"): (run / name).mkdir()
    environment = {"PATH": "/usr/bin:/bin", "HOME": str(run / "home"), "TMPDIR": str(run / "tmp"),
                   "LANG": "C.UTF-8", "LC_ALL": "C.UTF-8"}
    loader = [str(build / "bin/ld-linux-x86-64.so.2"), "--library-path",
              str(build / "bin") + ":" + str(build / "lib")]
    results = {}
    l2 = manifest.get("l2") is True
    probes = []
    if l2:
        environment["HARMONY_TEST_ELF_LOADER"] = loader[0]
        environment["HARMONY_TEST_LIBRARY_PATH"] = loader[2]
        if not {"bin/linux_guest_fault_test", "bin/unit_tests"} <= set(manifest["files"]):
            raise ValueError("L2 bundle is missing production fixtures")
        probes += [("guest-fault", ["linux_guest_fault_test"], 30),
                   ("recovery", ["unit_tests", "[guest_fault],[guest-fault]", "--reporter", "junit", "--out", str(run / "recovery.xml")], 60)]
    probes += [("harmony", ["harmonyrecomp", "--startup-probe", str(run / "runtime.log")], 60),
                                ("sdk", ["linux_startup_test"], 20)]
    if l2:
        probes += [("guest", ["harmonyrecomp", "--guest-probe", str(run / "guest-runtime.log")], 60)]
    for name, args, timeout in probes:
        receipt["stage"] = name + "-execution"
        command = loader + [str(build / "bin" / args[0]), *args[1:]]
        with (run / (name + ".stdout.log")).open("wb") as stdout, (run / (name + ".stderr.log")).open("wb") as stderr:
            process = subprocess.Popen(command, cwd=run, env=environment, stdout=stdout, stderr=stderr,
                                       start_new_session=True)
            timed_out = False
            try: code = process.wait(timeout=timeout)
            except subprocess.TimeoutExpired:
                timed_out = True
                try: os.killpg(process.pid, signal.SIGTERM)
                except ProcessLookupError: pass
                try: code = process.wait(timeout=5)
                except subprocess.TimeoutExpired:
                    try: os.killpg(process.pid, signal.SIGKILL)
                    except ProcessLookupError: pass
                    code = process.wait()
        results[name] = {"argv": command, "environment": environment, "exit_code": code,
                         "signal": -code if code < 0 else None, "timed_out": timed_out}
        receipt["executions"] = results
        if l2 and (code or timed_out or (run / (name + ".stderr.log")).stat().st_size):
            raise ValueError("L2 prerequisite failed before further execution: " + name)
    receipt["executions"] = results
    receipt["stage"] = "trace-validation"
    receipt["startup_events"] = validate_trace(run / "runtime.log.jsonl")
    if l2:
        receipt["guest_events"] = validate_trace(run / "guest-runtime.log.jsonl")
        events = [json.loads(x) for x in (run / "guest-runtime.log.jsonl").read_text().splitlines()]
        if not {("guest-fault-recovery", "pass"), ("guest-execution", "pass")} <= {(e["stage"], e["status"]) for e in events}:
            raise ValueError("bounded real guest execution did not pass")
        lines = (run / "guest-fault.stdout.log").read_text().splitlines()
        summary = json.loads(lines[-1])
        if summary.get("stage") != "linux_guest_fault_summary" or summary.get("failures") != 0 or summary.get("checks", 0) < 236:
            raise ValueError("production hardware-fault fixture did not qualify")
        receipt["guest_fault_checks"] = summary["checks"]
        import xml.etree.ElementTree as ET
        xml = ET.parse(run / "recovery.xml")
        if not xml.findall(".//testcase") or xml.findall(".//failure") or xml.findall(".//error"):
            raise ValueError("production recovery unit tests did not qualify")
        receipt["recovery_test_sections"] = len(xml.findall(".//testcase"))
        if any((run / (name + ".stderr.log")).stat().st_size for name in results):
            raise ValueError("unexpected stderr in qualifying L2 execution")
    if any(r["exit_code"] or r["timed_out"] for r in results.values()):
        raise ValueError("startup or SDK test did not exit successfully")
    temporary = root / (".current-" + run_id)
    temporary.symlink_to(Path("builds") / manifest["build_id"])
    temporary.replace(current)
    receipt.update(status="pass", stage="complete")
except Exception as error:
    receipt["error"] = str(error)
finally:
    upload.unlink(missing_ok=True)
    (run / "receipt.json").write_text(json.dumps(receipt, indent=2) + "\n")
    names = ["receipt.json", "harmony.stdout.log", "harmony.stderr.log", "sdk.stdout.log",
             "sdk.stderr.log", "runtime.log", "runtime.log.jsonl", "guest-fault.stdout.log", "guest-fault.stderr.log",
             "recovery.stdout.log", "recovery.stderr.log", "recovery.xml", "guest.stdout.log", "guest.stderr.log",
             "guest-runtime.log", "guest-runtime.log.jsonl"]
    receipt["artifacts"] = [n for n in names if (run / n).is_file() and not (run / n).is_symlink()]
    print(json.dumps(receipt))
'''


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--target", default="harmony-ally")
    parser.add_argument("--bundle", required=True, type=Path)
    parser.add_argument("--output-directory", required=True, type=Path)
    parser.add_argument("--root", default="/home/deck/.local/share/harmony-dev")
    for name in ("ssh-config", "identity", "known-hosts"):
        parser.add_argument("--" + name, type=Path)
    args = parser.parse_args()
    if not re.fullmatch(r"[A-Za-z0-9_.-]+", args.target) or not re.fullmatch(r"/[A-Za-z0-9_./-]+", args.root):
        parser.error("target/root must use plain alias/path characters")
    manifest = validate_bundle(args.bundle)
    source = Path(__file__).resolve().parents[2]
    output = args.output_directory.resolve()
    if any(parent.exists() and os.path.samefile(parent, source) for parent in (output, *output.parents)):
        parser.error("return receipts outside the source repository, including bind aliases")
    output.mkdir(parents=True, exist_ok=True)
    run_id = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ-") + uuid.uuid4().hex[:8]
    options = ["-oBatchMode=yes", "-oStrictHostKeyChecking=yes", "-oConnectTimeout=10"]
    for value, flag in ((args.ssh_config, "-F"), (args.identity, "-i")):
        if value: options += [flag, str(value)]
    if args.known_hosts: options += ["-oUserKnownHostsFile=" + str(args.known_hosts)]
    destination = output / run_id
    destination.mkdir()
    transport = {"schema": 1, "run_id": run_id, "target": args.target, "status": "failure", "stage": "remote-layout"}
    with args.bundle.open("rb") as stream: archive_hash = digest(stream)
    script = "\n".join([inspect.getsource(digest), inspect.getsource(validate_bundle), inspect.getsource(validate_trace)])
    script = ("import hashlib,json,os,re,subprocess,sys,tarfile\nfrom pathlib import Path,PurePosixPath\n" +
              "SAFE_ID=" + repr(SAFE_ID) + "\nREQUIRED=" + repr(REQUIRED) + "\nSTAGES=" + repr(STAGES) + "\n" + script + REMOTE)
    def remote(action):
        command = ["ssh", *options, args.target,
                   "python3 - " + " ".join(shlex.quote(x) for x in (args.root, run_id, archive_hash, action))]
        result = subprocess.run(command, input=script, text=True, capture_output=True, timeout=180)
        transport["last_ssh"] = {"action": action, "exit_code": result.returncode, "stderr": result.stderr}
        result.check_returncode()
        return json.loads(result.stdout)
    try:
        prepared = remote("prepare")
        transport["stage"] = "scp-upload"
        subprocess.run(["scp", *options, str(args.bundle), args.target + ":" + prepared["upload"]], check=True, timeout=300)
        transport["stage"] = "remote-execution"
        receipt = remote("execute")
        transport["stage"] = "log-return"
        for name in receipt["artifacts"]:
            subprocess.run(["scp", *options, args.target + ":" + args.root + "/logs/" + run_id + "/" + name,
                            str(destination / name)], check=True, timeout=120)
        (destination / "deployment-receipt.json").write_text(json.dumps(receipt, indent=2) + "\n")
        transport.update(status="pass", stage="complete")
    except Exception as error:
        transport["error"] = str(error)
        raise
    finally:
        (destination / "transport-receipt.json").write_text(json.dumps(transport, indent=2) + "\n")
    print(json.dumps({"build_id": manifest["build_id"], "status": receipt["status"],
                      "receipt": str(destination / "deployment-receipt.json")}, indent=2))
    return 0 if receipt["status"] == "pass" else 1


if __name__ == "__main__":
    try:
        sys.exit(main())
    except (OSError, ValueError, KeyError, tarfile.TarError, subprocess.SubprocessError) as error:
        sys.exit("L1 deployment failed: " + str(error))
