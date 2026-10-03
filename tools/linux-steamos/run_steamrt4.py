#!/usr/bin/env python3
"""Run an explicit command with pinned Steamrt4 userspace and read-only source."""

import argparse
import json
import math
import os
from pathlib import Path
import platform
import subprocess
import sys

sys.dont_write_bytecode = True

from bootstrap_steamrt4 import MARKER, check_layout, load_lock


def overlaps(left, right):
    return left == right or left in right.parents or right in left.parents


def bind_path(value):
    path = value.expanduser().resolve()
    if "," in str(path) or any(ord(character) < 32 for character in str(path)):
        raise ValueError("Docker mount paths cannot contain commas or control characters")
    return path


def git_metadata(source):
    directories = []
    for flag in ("--git-dir", "--git-common-dir"):
        path = subprocess.check_output(["git", "-c", "safe.directory=" + str(source), "-C", str(source), "rev-parse", flag], text=True,
                                       env={**os.environ, "GIT_OPTIONAL_LOCKS": "0"}).strip()
        candidate = Path(path)
        if not candidate.is_absolute():
            candidate = source / candidate
        directories.append(bind_path(candidate))
    return directories


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--sysroot", required=True, type=Path)
    parser.add_argument("--source", required=True, type=Path, help="Harmony checkout/worktree")
    parser.add_argument("--sdk", required=True, type=Path, help="separate pinned SDK checkout/worktree")
    parser.add_argument("--build-root", required=True, type=Path, help="external writable build directory")
    parser.add_argument("--lock", type=Path, default=Path(__file__).with_name("steamrt4.lock.json"))
    parser.add_argument("--cpus", type=float, default=4)
    parser.add_argument("--memory", default="16g", help="Docker build memory limit")
    parser.add_argument("--interactive", action="store_true", help="attach stdin and a terminal")
    parser.add_argument("--dry-run", action="store_true", help="validate paths/provenance and print argv; create no container")
    parser.add_argument("command", nargs=argparse.REMAINDER)
    args = parser.parse_args()
    command = args.command[1:] if args.command[:1] == ["--"] else args.command
    if not command:
        parser.error("an explicit command after -- is required")
    if not math.isfinite(args.cpus) or args.cpus <= 0:
        raise ValueError("--cpus must be a positive finite value")
    if platform.system() != "Linux" or platform.machine().lower() not in ("x86_64", "amd64"):
        raise ValueError("this locked SDK runner supports Linux x86-64 only")
    lock = load_lock(args.lock)
    sysroot, source, sdk, build = [bind_path(value) for value in
                                  (args.sysroot, args.source, args.sdk, args.build_root)]
    for path in (sysroot, source, sdk):
        if not path.is_dir():
            raise ValueError("required directory is missing: " + str(path))
    check_layout(sysroot, lock["version"])
    marker = json.loads((sysroot.parent / MARKER).read_text())
    if marker.get("version") != lock["version"] or marker.get("archive_sha256") != lock["archive"]["sha256"]:
        raise ValueError("sysroot provenance does not match the lock; run bootstrap first")
    readonly = [source, sdk, *git_metadata(source), *git_metadata(sdk)]
    if any(overlaps(build, path) for path in [sysroot, *readonly]):
        raise ValueError("build root must be disjoint from SDK userspace, source, and Git metadata")
    if build == Path("/"):
        raise ValueError("build root cannot be the filesystem root")
    mounts = [(sysroot / "usr/bin", "/bin"), (sysroot / "usr/sbin", "/sbin"),
              (sysroot / "usr/lib", "/lib"), (sysroot / "usr/lib64", "/lib64"),
              (sysroot / "usr", "/usr"), (sysroot / "etc", "/etc"),
              (sysroot / "var/lib/dpkg", "/var/lib/dpkg")]
    # Common Git directories retain worktree/submodule lookup at their original paths.
    # Elide duplicate/nested mounts already covered by a source or metadata parent.
    unique = sorted(set(readonly), key=lambda path: len(path.parts))
    covered = []
    for path in unique:
        if any(parent == path or parent in path.parents for parent in covered):
            continue
        mounts.append((path, str(path)))
        covered.append(path)
    args_docker = ["docker", "run", "--rm", "--pull", "never", "--network", "none", "--read-only",
                   "--cap-drop", "ALL", "--security-opt", "no-new-privileges", "--pids-limit", "1024",
                   "--shm-size", "1g", "--memory", args.memory, "--cpus", str(args.cpus), "--user", str(os.getuid()) + ":" + str(os.getgid()),
                   "--tmpfs", "/tmp:rw,exec,nosuid,nodev,size=1g", "--workdir", str(build)]
    environment = {"PATH": "/usr/bin:/bin:/usr/sbin:/sbin", "HOME": "/tmp", "TMPDIR": "/tmp",
                   "LANG": "C.UTF-8", "LC_ALL": "C.UTF-8", "PYTHONDONTWRITEBYTECODE": "1",
                   "HARMONY_SOURCE": str(source), "HARMONY_SDK": str(sdk), "HARMONY_BUILD_ROOT": str(build),
                   "HARMONY_LINUX_SDK_SOURCE": str(sdk), "REXGLUE_LINUX_BUILD_ROOT": str(build),
                   "GIT_OPTIONAL_LOCKS": "0", "GIT_CONFIG_COUNT": "2",
                   "GIT_CONFIG_KEY_0": "safe.directory", "GIT_CONFIG_VALUE_0": str(source),
                   "GIT_CONFIG_KEY_1": "safe.directory", "GIT_CONFIG_VALUE_1": str(sdk)}
    for name, value in environment.items():
        args_docker += ["--env", name + "=" + value]
    for path, destination in mounts:
        if not path.is_dir():
            raise ValueError("read-only mount source is missing: " + str(path))
        args_docker += ["--mount", "type=bind,src=" + str(path) + ",dst=" + destination + ",readonly"]
    args_docker += ["--mount", "type=bind,src=" + str(build) + ",dst=" + str(build)]
    if args.interactive:
        args_docker += ["--interactive", "--tty"]
    args_docker += [lock["carrier"]["image_id"], *command]
    if args.dry_run:
        print(json.dumps({"sdk_version": lock["version"], "carrier_image_id": lock["carrier"]["image_id"],
                          "argv": args_docker}, indent=2))
        return
    image = json.loads(subprocess.check_output(["docker", "image", "inspect", lock["carrier"]["image_id"]], text=True))[0]
    if image["Id"] != lock["carrier"]["image_id"] or image["Os"] + "/" + image["Architecture"] != lock["carrier"]["platform"]:
        raise ValueError("local carrier image does not match the locked ID/platform")
    build.mkdir(parents=True, exist_ok=True)
    raise SystemExit(subprocess.call(args_docker))


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, KeyError, subprocess.CalledProcessError) as error:
        sys.exit("Steamrt4 runner failed: " + str(error))
