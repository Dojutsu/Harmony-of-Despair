#!/usr/bin/env python3
"""Verify and extract the pinned Steamrt4 SDK outside the source tree."""

import argparse
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
import subprocess
import sys
import tarfile
import tempfile
import urllib.request

MARKER = ".harmony-steamrt4-sysroot.json"


def sha256(stream):
    digest = hashlib.sha256()
    for chunk in iter(lambda: stream.read(1024 * 1024), b""):
        digest.update(chunk)
    return digest.hexdigest()


def load_lock(path):
    lock = json.loads(path.read_text())
    if lock["schema"] != 1 or lock["architecture"] != "amd64":
        raise ValueError("unsupported Steamrt4 lock schema or architecture")
    return lock


def inspect_archive(archive, existing=None):
    counts = {"regular": 0, "directory": 0, "symlink": 0, "hardlink": 0}
    total = 0
    with tarfile.open(archive, "r|gz") as stream:
        for member in stream:
            name = PurePosixPath(member.name)
            if name.is_absolute() or ".." in name.parts:
                raise ValueError("unsafe archive member path")
            if member.isfile():
                kind = "regular"
                total += member.size
            elif member.isdir():
                kind = "directory"
            elif member.issym():
                # Absolute targets belong to the SDK root, not the host root.
                kind = "symlink"
            elif member.islnk():
                kind = "hardlink"
                target = PurePosixPath(member.linkname)
                if target.is_absolute() or ".." in target.parts:
                    raise ValueError("unsafe archive hardlink")
            else:
                raise ValueError("unexpected archive entry type")
            counts[kind] += 1
            if existing is None:
                continue
            path = existing / member.name
            if kind == "symlink":
                if not path.is_symlink() or os.readlink(path) != member.linkname:
                    raise ValueError("existing SDK symlink differs: " + member.name)
            elif kind == "directory":
                if not path.is_dir():
                    raise ValueError("existing SDK directory missing: " + member.name)
            elif kind == "hardlink":
                if not path.is_file() or not os.path.samefile(path, existing / member.linkname):
                    raise ValueError("existing SDK hardlink differs: " + member.name)
            else:
                if path.is_symlink() or not path.is_file() or path.stat().st_size != member.size:
                    raise ValueError("existing SDK file differs: " + member.name)
                with path.open("rb") as actual, stream.extractfile(member) as expected:
                    if sha256(actual) != sha256(expected):
                        raise ValueError("existing SDK file hash differs: " + member.name)
                if path.stat().st_mode & 0o777 != member.mode & 0o777:
                    raise ValueError("existing SDK file mode differs: " + member.name)
    return {"counts": counts, "regular_bytes": total, "member_count": sum(counts.values())}


def check_layout(sysroot, version):
    for name in ("bin", "sbin", "lib", "lib64"):
        path = sysroot / name
        if not path.is_symlink() or os.readlink(path) != "usr/" + name:
            raise ValueError("unexpected merged-usr link: " + name)
    for name in ("usr/bin", "usr/sbin", "usr/lib", "usr/lib64", "etc", "var/lib/dpkg"):
        if not (sysroot / name).is_dir():
            raise ValueError("required SDK directory missing: " + name)
    release = (sysroot / "etc/os-release").read_text()
    if 'BUILD_ID="' + version + '"' not in release:
        raise ValueError("SDK os-release does not match the pinned build")


def download(url, destination):
    with tempfile.NamedTemporaryFile(dir=destination.parent, prefix="steamrt4-download-", delete=False) as part:
        temporary = Path(part.name)
        try:
            with urllib.request.urlopen(url, timeout=60) as response:
                for chunk in iter(lambda: response.read(1024 * 1024), b""):
                    part.write(chunk)
            part.flush()
            temporary.replace(destination)
        except Exception:
            temporary.unlink(missing_ok=True)
            raise


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", required=True, type=Path, help="external environment directory; contains sysroot/")
    parser.add_argument("--archive", type=Path, help="reuse a local archive instead of downloading")
    parser.add_argument("--lock", type=Path, default=Path(__file__).with_name("steamrt4.lock.json"))
    actions = parser.add_mutually_exclusive_group()
    actions.add_argument("--verify-only", action="store_true", help="verify archive and report layout without writing")
    actions.add_argument("--verify-existing", action="store_true", help="hash-compare an existing sysroot before recording provenance")
    args = parser.parse_args()
    lock = load_lock(args.lock)
    root = args.root.expanduser().resolve()
    repository = Path(__file__).resolve().parents[2]
    if root == repository or repository in root.parents:
        raise ValueError("environment root must be outside the source repository")
    sysroot = root / "sysroot"
    if sysroot.exists() and not (args.verify_existing or args.verify_only):
        raise ValueError("sysroot already exists; use --verify-existing to validate it without overwriting")
    archive = args.archive.expanduser().resolve() if args.archive else root / lock["archive"]["name"]
    if not archive.is_file():
        if args.archive or args.verify_only or args.verify_existing:
            raise ValueError("archive is missing")
        root.mkdir(parents=True, exist_ok=True)
        download(lock["archive"]["url"], archive)
    if archive.stat().st_size != lock["archive"]["bytes"]:
        raise ValueError("archive size does not match the lock")
    with archive.open("rb") as stream:
        digest = sha256(stream)
    if digest != lock["archive"]["sha256"]:
        raise ValueError("archive SHA-256 does not match the lock")
    if args.verify_existing and not sysroot.is_dir():
        raise ValueError("existing sysroot is missing")
    layout = inspect_archive(archive, sysroot if args.verify_existing else None)
    result = {"schema": 1, "version": lock["version"], "archive_sha256": digest, "layout": layout}
    if args.verify_only:
        if sysroot.is_dir():
            check_layout(sysroot, lock["version"])
        print(json.dumps(result, indent=2))
        return
    marker = root / MARKER
    if not args.verify_existing:
        root.mkdir(parents=True, exist_ok=True)
        sysroot.mkdir()
        # Failed extraction remains available for diagnosis; never clean an existing tree.
        subprocess.run(["tar", "--extract", "--gzip", "--file", str(archive), "--directory", str(sysroot),
                        "--no-same-owner", "--delay-directory-restore"], check=True)
    check_layout(sysroot, lock["version"])
    result["validation"] = "archive-file-hashes-and-modes" if args.verify_existing else "verified-archive-extraction"
    with tempfile.NamedTemporaryFile(mode="w", dir=root, prefix="steamrt4-marker-", delete=False) as temporary:
        json.dump(result, temporary, indent=2)
        temporary.write("\n")
        marker_temp = Path(temporary.name)
    marker_temp.replace(marker)
    print(json.dumps({**result, "sysroot": str(sysroot)}, indent=2))


if __name__ == "__main__":
    try:
        main()
    except (OSError, ValueError, KeyError, subprocess.CalledProcessError, tarfile.TarError) as error:
        sys.exit("Steamrt4 bootstrap failed: " + str(error))
