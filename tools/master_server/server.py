#!/usr/bin/env python3
"""Small in-memory session directory for HarmonyRecomp.

TLS is intentionally terminated by a reverse proxy such as Caddy. This service
binds to loopback by default and never carries discovery or gameplay UDP.
"""

from __future__ import annotations

import argparse
import ipaddress
import json
import secrets
import socket
import struct
import threading
import time
import urllib.parse
from dataclasses import dataclass
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from typing import Any


MAX_BODY_BYTES = 8 * 1024
MAX_SERVER_NAME = 48
MAX_BUILD_ID = 64
MAX_CANDIDATES = 4
DEFAULT_TTL_SECONDS = 45
RENDEZVOUS_MAGIC = b"HNAT"
RENDEZVOUS_VERSION = 1
RENDEZVOUS_REGISTER = 1
RENDEZVOUS_REGISTERED = 2
RENDEZVOUS_PACKET = struct.Struct("!4sBBBB16s16s4sH4sH4x")
RENDEZVOUS_MIN_INTERVAL_SECONDS = 0.1
MAX_RENDEZVOUS_ATTEMPTS = 1024


class ValidationError(ValueError):
    pass


def _required_int(value: Any, name: str, minimum: int, maximum: int) -> int:
    if isinstance(value, bool) or not isinstance(value, int):
        raise ValidationError(f"{name} must be an integer")
    if not minimum <= value <= maximum:
        raise ValidationError(f"{name} is out of range")
    return value


def _required_text(value: Any, name: str, maximum: int) -> str:
    if not isinstance(value, str):
        raise ValidationError(f"{name} must be a string")
    value = value.strip()
    if not value or len(value) > maximum or any(ord(ch) < 0x20 for ch in value):
        raise ValidationError(f"{name} is invalid")
    return value


def _build_id(value: Any) -> str:
    value = _required_text(value, "build_id", MAX_BUILD_ID)
    if any(not (ch.isascii() and (ch.isalnum() or ch in "._-")) for ch in value):
        raise ValidationError("build_id contains unsupported characters")
    return value


def _validate_candidates(value: Any) -> list[dict[str, Any]]:
    if not isinstance(value, list) or not 1 <= len(value) <= MAX_CANDIDATES:
        raise ValidationError("connectivity_candidates must contain 1 to 4 entries")
    result: list[dict[str, Any]] = []
    for candidate in value:
        if not isinstance(candidate, dict):
            raise ValidationError("connectivity candidate must be an object")
        candidate_type = _required_text(candidate.get("type"), "candidate type", 24)
        if candidate_type not in {"direct", "tailscale"}:
            raise ValidationError("unsupported connectivity candidate type")
        address = _required_text(candidate.get("address"), "candidate address", 45)
        try:
            parsed = ipaddress.ip_address(address)
        except ValueError as exc:
            raise ValidationError("candidate address must be an IPv4 literal") from exc
        if parsed.version != 4 or parsed.is_unspecified or parsed.is_multicast or parsed.is_loopback:
            raise ValidationError("candidate address is not publishable")
        discovery_port = _required_int(candidate.get("discovery_port"), "discovery_port", 1, 65535)
        gameplay_port = _required_int(candidate.get("gameplay_port"), "gameplay_port", 1, 65535)
        result.append(
            {
                "type": candidate_type,
                "address": str(parsed),
                "discovery_port": discovery_port,
                "gameplay_port": gameplay_port,
            }
        )
    return result


def validate_registration(payload: Any) -> dict[str, Any]:
    if not isinstance(payload, dict):
        raise ValidationError("request body must be an object")
    player_count = _required_int(payload.get("player_count"), "player_count", 1, 64)
    max_players = _required_int(payload.get("max_players"), "max_players", 1, 64)
    if player_count > max_players:
        raise ValidationError("player_count exceeds max_players")
    title_id = _required_text(payload.get("title_id"), "title_id", 8).upper()
    if len(title_id) != 8 or any(ch not in "0123456789ABCDEF" for ch in title_id):
        raise ValidationError("title_id must contain exactly eight hexadecimal digits")
    return {
        "server_name": _required_text(payload.get("server_name"), "server_name", MAX_SERVER_NAME),
        "player_count": player_count,
        "max_players": max_players,
        "title_id": title_id,
        "protocol_version": _required_int(payload.get("protocol_version"), "protocol_version", 1, 65535),
        "build_id": _build_id(payload.get("build_id")),
        "connectivity_candidates": _validate_candidates(payload.get("connectivity_candidates")),
    }


@dataclass
class StoredSession:
    session_id: str
    registration_token: str
    metadata: dict[str, Any]
    last_heartbeat: float

    def public(self) -> dict[str, Any]:
        return {
            "session_id": self.session_id,
            **self.metadata,
            "last_heartbeat": int(self.last_heartbeat),
        }


class SessionRegistry:
    def __init__(self, ttl_seconds: int = DEFAULT_TTL_SECONDS, clock=time.time):
        self.ttl_seconds = ttl_seconds
        self.clock = clock
        self._lock = threading.Lock()
        self._sessions: dict[str, StoredSession] = {}

    def _expire_locked(self, now: float) -> None:
        stale = [key for key, value in self._sessions.items() if now - value.last_heartbeat >= self.ttl_seconds]
        for key in stale:
            del self._sessions[key]

    def create(self, payload: Any) -> StoredSession:
        metadata = validate_registration(payload)
        now = self.clock()
        value = StoredSession(secrets.token_urlsafe(18), secrets.token_urlsafe(32), metadata, now)
        with self._lock:
            self._expire_locked(now)
            self._sessions[value.session_id] = value
        return value

    def heartbeat(self, session_id: str, token: str, payload: Any) -> StoredSession | None:
        metadata = validate_registration(payload)
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            value = self._sessions.get(session_id)
            if value is None or not secrets.compare_digest(value.registration_token, token):
                return None
            value.metadata = metadata
            value.last_heartbeat = now
            return value

    def delete(self, session_id: str, token: str) -> bool:
        with self._lock:
            value = self._sessions.get(session_id)
            if value is None or not secrets.compare_digest(value.registration_token, token):
                return False
            del self._sessions[session_id]
            return True

    def list(self, filters: dict[str, str]) -> list[dict[str, Any]]:
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            values = list(self._sessions.values())
        for key in ("title_id", "build_id"):
            expected = filters.get(key)
            if expected:
                if key == "title_id":
                    expected = expected.upper()
                values = [value for value in values if value.metadata[key] == expected]
        protocol = filters.get("protocol_version")
        if protocol:
            try:
                protocol_value = int(protocol)
            except ValueError:
                return []
            values = [value for value in values if value.metadata["protocol_version"] == protocol_value]
        return [value.public() for value in values]


class DirectoryHandler(BaseHTTPRequestHandler):
    server_version = "HarmonyDirectory/1"

    @property
    def registry(self) -> SessionRegistry:
        return self.server.registry  # type: ignore[attr-defined]

    def log_message(self, fmt: str, *args: Any) -> None:
        print(f"{self.address_string()} - {fmt % args}")

    def _json(self, status: HTTPStatus, value: Any) -> None:
        body = json.dumps(value, separators=(",", ":")).encode("utf-8")
        self.send_response(status)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(body)))
        self.send_header("Cache-Control", "no-store")
        self.end_headers()
        self.wfile.write(body)

    def _read_json(self) -> Any:
        try:
            length = int(self.headers.get("Content-Length", "0"))
        except ValueError as exc:
            raise ValidationError("invalid Content-Length") from exc
        if not 1 <= length <= MAX_BODY_BYTES:
            raise ValidationError("request body size is invalid")
        try:
            return json.loads(self.rfile.read(length))
        except (UnicodeDecodeError, json.JSONDecodeError) as exc:
            raise ValidationError("request body is not valid JSON") from exc

    def _bearer(self) -> str:
        value = self.headers.get("Authorization", "")
        return value[7:] if value.startswith("Bearer ") else ""

    def do_GET(self) -> None:  # noqa: N802
        parsed = urllib.parse.urlsplit(self.path)
        if parsed.path != "/sessions":
            self._json(HTTPStatus.NOT_FOUND, {"error": "not found"})
            return
        query = {key: values[-1] for key, values in urllib.parse.parse_qs(parsed.query).items()}
        self._json(HTTPStatus.OK, {"sessions": self.registry.list(query)})

    def do_POST(self) -> None:  # noqa: N802
        parsed = urllib.parse.urlsplit(self.path)
        try:
            payload = self._read_json()
            if parsed.path == "/sessions":
                value = self.registry.create(payload)
                self._json(
                    HTTPStatus.CREATED,
                    {"session_id": value.session_id, "registration_token": value.registration_token},
                )
                return
            parts = parsed.path.strip("/").split("/")
            if len(parts) == 3 and parts[0] == "sessions" and parts[2] == "heartbeat":
                value = self.registry.heartbeat(parts[1], self._bearer(), payload)
                if value is None:
                    self._json(HTTPStatus.NOT_FOUND, {"error": "unknown session or token"})
                else:
                    self._json(HTTPStatus.OK, {"session_id": value.session_id})
                return
            self._json(HTTPStatus.NOT_FOUND, {"error": "not found"})
        except ValidationError as exc:
            self._json(HTTPStatus.BAD_REQUEST, {"error": str(exc)})

    def do_DELETE(self) -> None:  # noqa: N802
        parsed = urllib.parse.urlsplit(self.path)
        parts = parsed.path.strip("/").split("/")
        if len(parts) != 2 or parts[0] != "sessions":
            self._json(HTTPStatus.NOT_FOUND, {"error": "not found"})
            return
        if self.registry.delete(parts[1], self._bearer()):
            self.send_response(HTTPStatus.NO_CONTENT)
            self.end_headers()
        else:
            self._json(HTTPStatus.NOT_FOUND, {"error": "unknown session or token"})


class DirectoryServer(ThreadingHTTPServer):
    daemon_threads = True

    def __init__(self, address: tuple[str, int], registry: SessionRegistry):
        super().__init__(address, DirectoryHandler)
        self.registry = registry


@dataclass
class RendezvousAttempt:
    credential: bytes
    last_seen: float
    endpoints: dict[tuple[int, int], tuple[str, int]]
    endpoint_seen: dict[tuple[int, int], float]


class RendezvousRegistry:
    """Short-lived, credential-bound NAT traversal endpoint observations."""

    def __init__(self, ttl_seconds: int = DEFAULT_TTL_SECONDS, clock=time.monotonic):
        self.ttl_seconds = ttl_seconds
        self.clock = clock
        self._lock = threading.Lock()
        self._attempts: dict[bytes, RendezvousAttempt] = {}

    def register(
        self, attempt_id: bytes, credential: bytes, participant: int, role: int,
        source: tuple[str, int],
    ) -> tuple[tuple[str, int], tuple[str, int] | None] | None:
        if participant not in (0, 1) or role not in (0, 1):
            return None
        now = self.clock()
        key = (participant, role)
        with self._lock:
            self._attempts = {
                value_id: value for value_id, value in self._attempts.items()
                if now - value.last_seen < self.ttl_seconds
            }
            attempt = self._attempts.get(attempt_id)
            if attempt is None:
                if len(self._attempts) >= MAX_RENDEZVOUS_ATTEMPTS:
                    return None
                attempt = RendezvousAttempt(credential, now, {}, {})
                self._attempts[attempt_id] = attempt
            elif not secrets.compare_digest(attempt.credential, credential):
                return None
            previous = attempt.endpoint_seen.get(key)
            if previous is not None and now - previous < RENDEZVOUS_MIN_INTERVAL_SECONDS:
                return None
            attempt.last_seen = now
            attempt.endpoints[key] = source
            attempt.endpoint_seen[key] = now
            return source, attempt.endpoints.get((1 - participant, role))


class RendezvousServer:
    def __init__(self, address: tuple[str, int], registry: RendezvousRegistry):
        self.registry = registry
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.socket.bind(address)
        self.address = self.socket.getsockname()
        self._stopping = threading.Event()

    def serve_forever(self) -> None:
        self.socket.settimeout(0.25)
        while not self._stopping.is_set():
            try:
                packet, source = self.socket.recvfrom(RENDEZVOUS_PACKET.size + 1)
            except TimeoutError:
                continue
            except OSError:
                break
            if len(packet) != RENDEZVOUS_PACKET.size:
                continue
            (magic, version, message_type, participant, role, attempt_id, credential,
             _observed_ip, _observed_port, _peer_ip, _peer_port) = RENDEZVOUS_PACKET.unpack(packet)
            if magic != RENDEZVOUS_MAGIC or version != RENDEZVOUS_VERSION:
                continue
            if message_type != RENDEZVOUS_REGISTER:
                continue
            result = self.registry.register(attempt_id, credential, participant, role, source)
            if result is None:
                continue
            observed, peer = result
            peer = peer or ("0.0.0.0", 0)
            response = RENDEZVOUS_PACKET.pack(
                RENDEZVOUS_MAGIC, RENDEZVOUS_VERSION, RENDEZVOUS_REGISTERED,
                participant, role, attempt_id, credential,
                socket.inet_aton(observed[0]), observed[1],
                socket.inet_aton(peer[0]), peer[1],
            )
            self.socket.sendto(response, source)

    def shutdown(self) -> None:
        self._stopping.set()
        self.socket.close()


def main() -> int:
    parser = argparse.ArgumentParser(description="HarmonyRecomp discovery-only session directory")
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=8080)
    parser.add_argument("--ttl", type=int, default=DEFAULT_TTL_SECONDS)
    parser.add_argument("--rendezvous-host", default="")
    parser.add_argument("--rendezvous-port", type=int, default=30740)
    args = parser.parse_args()
    if (not 1 <= args.port <= 65535 or not 1 <= args.rendezvous_port <= 65535 or
            not 5 <= args.ttl <= 3600):
        parser.error("port or ttl is out of range")
    server = DirectoryServer((args.host, args.port), SessionRegistry(args.ttl))
    rendezvous = None
    rendezvous_thread = None
    if args.rendezvous_host:
        rendezvous = RendezvousServer(
            (args.rendezvous_host, args.rendezvous_port), RendezvousRegistry(args.ttl)
        )
        rendezvous_thread = threading.Thread(target=rendezvous.serve_forever, daemon=True)
        rendezvous_thread.start()
        print(f"Harmony rendezvous listening on udp://{rendezvous.address[0]}:"
              f"{rendezvous.address[1]} (ttl={args.ttl}s)")
    print(f"Harmony directory listening on http://{args.host}:{args.port} (ttl={args.ttl}s)")
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass
    finally:
        if rendezvous is not None:
            rendezvous.shutdown()
        if rendezvous_thread is not None:
            rendezvous_thread.join()
        server.server_close()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
