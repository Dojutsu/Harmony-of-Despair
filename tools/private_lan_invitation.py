#!/usr/bin/env python3
"""Generate private, distinct client invitation grants without printing secrets."""
from __future__ import annotations
import argparse
import os
from pathlib import Path
import secrets
import stat
import struct
import time

MAX_CLIENTS = 5
MAX_LIFETIME = 7 * 24 * 60 * 60

def xuid(value: str) -> int:
    try:
        result = int(value, 16)
    except ValueError as error:
        raise argparse.ArgumentTypeError("XUID must be hexadecimal") from error
    if not 0 < result < 2**64:
        raise argparse.ArgumentTypeError("XUID must be a nonzero 64-bit value")
    return result

def encode(host: int, expiry: int, grants: list[tuple[int, bytes, bytes]], role: int) -> bytes:
    return (b"HPLI" + bytes((1, role, len(grants), 0)) + struct.pack(">QQ", host, expiry)
            + b"".join(struct.pack(">Q", client) + selector + secret
                       for client, selector, secret in grants))

def generate(directory: Path | str, host: int, clients: list[int], expires_in: int) -> list[Path]:
    if not clients or len(clients) > MAX_CLIENTS or len(set(clients)) != len(clients):
        raise ValueError("Provide one to five distinct client XUIDs")
    if host in clients or not all(0 < value < 2**64 for value in [host, *clients]):
        raise ValueError("Host and client XUIDs must be distinct nonzero 64-bit values")
    if not 0 < expires_in <= MAX_LIFETIME:
        raise ValueError("Invitation lifetime must be between 1 and 604800 seconds")
    directory = canonical_path(directory)
    parent = open_directory(directory.parent)
    leaf = None
    created = False
    names: list[str] = []
    try:
        os.mkdir(directory.name, 0o700, dir_fd=parent)
        created = True
        leaf = os.open(directory.name, os.O_RDONLY | os.O_DIRECTORY | os.O_NOFOLLOW | os.O_CLOEXEC,
                       dir_fd=parent)
        require_private_directory(leaf)
        expiry = int(time.time()) + expires_in
        grants = [(client, secrets.token_bytes(16), secrets.token_bytes(32)) for client in clients]
        outputs = [("host.hpli", encode(host, expiry, grants, 0))]
        outputs.extend((f"client-{client:016x}.hpli", encode(host, expiry, [grant], 1))
                       for client, grant in zip(clients, grants))
        for filename, data in outputs:
            write_private_file(leaf, filename, data, names)
        os.fsync(leaf)
        return [directory / name for name in names]
    except BaseException:
        rollback(parent, directory.name, leaf, names, created)
        raise
    finally:
        if leaf is not None:
            os.close(leaf)
        os.close(parent)


def canonical_path(value: Path | str) -> Path:
    text = os.fspath(value)
    if not text.startswith("/") or any(part in ("", ".", "..") for part in text.split("/")[1:]):
        raise ValueError("Invitation paths must be absolute with canonical components")
    return Path(text)


def open_directory(path: Path) -> int:
    descriptor = os.open("/", os.O_RDONLY | os.O_DIRECTORY | os.O_CLOEXEC)
    try:
        for component in path.parts[1:]:
            replacement = os.open(component, os.O_RDONLY | os.O_DIRECTORY | os.O_NOFOLLOW
                                  | os.O_CLOEXEC, dir_fd=descriptor)
            os.close(descriptor)
            descriptor = replacement
        return descriptor
    except BaseException:
        os.close(descriptor)
        raise


def require_private_directory(descriptor: int) -> None:
    info = os.fstat(descriptor)
    if info.st_uid != os.geteuid() or stat.S_IMODE(info.st_mode) != 0o700:
        raise ValueError("Invitation directory must be same-owner mode 0700")


def write_private_file(directory: int, name: str, data: bytes | bytearray, names: list[str]) -> None:
    descriptor = os.open(name, os.O_WRONLY | os.O_CREAT | os.O_EXCL | os.O_NOFOLLOW
                         | os.O_CLOEXEC, 0o600, dir_fd=directory)
    names.append(name)
    try:
        offset = 0
        while offset < len(data):
            written = os.write(descriptor, data[offset:])
            if written <= 0:
                raise OSError("Invitation write failed")
            offset += written
        os.fsync(descriptor)
    finally:
        os.close(descriptor)


def rollback(parent: int, name: str, leaf: int | None, names: list[str], created: bool) -> None:
    # Cleanup stays attached to the opened leaf even if a pathname is renamed.
    if leaf is not None:
        for filename in names:
            try:
                os.unlink(filename, dir_fd=leaf)
            except FileNotFoundError:
                pass
    if created:
        try:
            current = os.stat(name, dir_fd=parent, follow_symlinks=False)
            owned = os.fstat(leaf) if leaf is not None else None
            if owned is not None and (current.st_dev, current.st_ino) == (owned.st_dev, owned.st_ino):
                os.rmdir(name, dir_fd=parent)
        except OSError:
            pass


def validate_contents(data: bytes | bytearray, local_xuid: int) -> dict:
    if not 0 < local_xuid < 2**64 or len(data) < 24 or len(data) > 304:
        raise ValueError("Invalid invitation identity or bounded size")
    if data[:4] != b"HPLI" or data[4] != 1 or data[5] not in (0, 1) or data[7] != 0:
        raise ValueError("Invalid invitation header")
    role, count = data[5], data[6]
    if not 1 <= count <= MAX_CLIENTS or (role == 1 and count != 1) or len(data) != 24 + 56 * count:
        raise ValueError("Invalid invitation entry count or exact size")
    host, expiry = struct.unpack_from(">QQ", data, 8)
    now = int(time.time())
    if not host or not now < expiry <= now + MAX_LIFETIME:
        raise ValueError("Invitation is expired or outside the seven-day limit")
    identities, selectors, keys = set(), set(), set()
    client = 0
    for offset in range(24, len(data), 56):
        client = struct.unpack_from(">Q", data, offset)[0]
        selector, key = bytes(data[offset+8:offset+24]), bytes(data[offset+24:offset+56])
        if (not client or client == host or client in identities or not any(selector)
                or not any(key) or selector in selectors or key in keys):
            raise ValueError("Invalid or duplicate invitation grant")
        identities.add(client)
        selectors.add(selector)
        keys.add(key)
    if local_xuid != (host if role == 0 else client):
        raise ValueError("Invitation does not authorize the configured local XUID")
    return {"role": "host" if role == 0 else "client", "local_xuid": local_xuid,
            "host_xuid": host, "expires_at": expiry, "clients": count}


def read_invitation(source: Path | str, local_xuid: int) -> tuple[bytearray, dict]:
    source = canonical_path(source)
    directory = open_directory(source.parent)
    descriptor = None
    data = bytearray()
    try:
        require_private_directory(directory)
        descriptor = os.open(source.name, os.O_RDONLY | os.O_NONBLOCK | os.O_NOFOLLOW | os.O_CLOEXEC,
                             dir_fd=directory)
        before = os.fstat(descriptor)
        if (not stat.S_ISREG(before.st_mode) or before.st_uid != os.geteuid()
                or before.st_nlink != 1 or stat.S_IMODE(before.st_mode) != 0o600
                or not 80 <= before.st_size <= 304):
            raise ValueError("Invitation must be a same-owner single-link 0600 bounded regular file")
        while len(data) < 305:
            part = os.read(descriptor, 305-len(data))
            if not part:
                break
            data.extend(part)
        after = os.fstat(descriptor)
        signature = lambda info: (info.st_dev, info.st_ino, info.st_size, info.st_mtime_ns,
                                  info.st_ctime_ns, info.st_uid, info.st_mode, info.st_nlink)
        if signature(before) != signature(after) or len(data) != before.st_size:
            raise ValueError("Invitation changed while reading")
        return data, validate_contents(data, local_xuid)
    except BaseException:
        data[:] = bytes(len(data))
        raise
    finally:
        if descriptor is not None:
            os.close(descriptor)
        os.close(directory)


def inspect_invitation(source: Path | str, local_xuid: int) -> dict:
    data, metadata = read_invitation(source, local_xuid)
    try:
        return metadata
    finally:
        data[:] = bytes(len(data))


def import_invitation(source: Path | str, directory: Path | str, local_xuid: int) -> Path:
    data, metadata = read_invitation(source, local_xuid)
    parent = leaf = None
    names: list[str] = []
    created = False
    try:
        directory = canonical_path(directory)
        parent = open_directory(directory.parent)
        os.mkdir(directory.name, 0o700, dir_fd=parent)
        created = True
        leaf = os.open(directory.name, os.O_RDONLY | os.O_DIRECTORY | os.O_NOFOLLOW | os.O_CLOEXEC,
                       dir_fd=parent)
        require_private_directory(leaf)
        filename = "host.hpli" if metadata["role"] == "host" else f"client-{local_xuid:016x}.hpli"
        write_private_file(leaf, filename, data, names)
        os.fsync(leaf)
        return directory / filename
    except BaseException:
        if parent is not None:
            rollback(parent, directory.name, leaf, names, created)
        raise
    finally:
        data[:] = bytes(len(data))
        if leaf is not None:
            os.close(leaf)
        if parent is not None:
            os.close(parent)

def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--directory", required=True)
    parser.add_argument("--host-xuid", type=xuid)
    parser.add_argument("--client-xuid", type=xuid, action="append")
    parser.add_argument("--import-file", help="Import a privately transferred invitation")
    parser.add_argument("--local-xuid", type=xuid, help="Expected local profile XUID for import")
    parser.add_argument("--expires-in", type=int, default=24 * 60 * 60)
    arguments = parser.parse_args()
    try:
        if arguments.import_file:
            if not arguments.local_xuid or arguments.host_xuid or arguments.client_xuid:
                raise ValueError("Import requires --local-xuid and no generation XUID options")
            paths = [import_invitation(arguments.import_file, arguments.directory, arguments.local_xuid)]
        else:
            if not arguments.host_xuid or not arguments.client_xuid or arguments.local_xuid:
                raise ValueError("Generation requires --host-xuid and --client-xuid")
            paths = generate(arguments.directory, arguments.host_xuid, arguments.client_xuid,
                             arguments.expires_in)
    except (ValueError, OSError) as error:
        parser.error(str(error))
    for path in paths:
        print(path)
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
