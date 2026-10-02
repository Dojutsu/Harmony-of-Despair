#!/usr/bin/env python3
"""Small in-memory session directory for HarmonyRecomp.

TLS is intentionally terminated by a reverse proxy such as Caddy. This service
binds to loopback by default and never carries discovery or gameplay UDP.
"""

from __future__ import annotations

import argparse
import collections
import enum
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

try:
    from .gameplay import GameplayRegistry, GameplayError
except ImportError:
    from gameplay import GameplayRegistry, GameplayError


MAX_BODY_BYTES = 8 * 1024
MAX_SERVER_NAME = 48
MAX_BUILD_ID = 64
MAX_CANDIDATES = 4
MAX_HOST_INSTANCE_ID = 64
MAX_HOST_INSTANCE_TOKEN = 128
DEFAULT_TTL_SECONDS = 45
RENDEZVOUS_MAGIC = b"HNAT"
RENDEZVOUS_VERSION = 1
RENDEZVOUS_REGISTER = 1
RENDEZVOUS_REGISTERED = 2
RENDEZVOUS_PACKET = struct.Struct("!4sBBBB16s16s4sH4sH4x")
RENDEZVOUS_MIN_INTERVAL_SECONDS = 0.1
MAX_RENDEZVOUS_ATTEMPTS = 1024
DEFAULT_ATTEMPT_TTL_SECONDS = 20
DEFAULT_ADMISSION_TTL_SECONDS = 20
MAX_ATTEMPTS_PER_SESSION = 8
ATTEMPT_CREATE_MIN_INTERVAL_SECONDS = 0.25
INVITE_CODE_ALPHABET = "ABCDEFGHJKMNPQRSTUVWXYZ23456789"
INVITE_CODE_LENGTH = 6
INVITE_CODE_GENERATION_ATTEMPTS = 128
INVITE_LOOKUP_WINDOW_SECONDS = 10.0
MAX_INVITE_LOOKUPS_PER_WINDOW = 30
MAX_INVITE_LOOKUP_SOURCES = 4096
ATTEMPT_REQUEST_ID_LENGTH = 32


class AttemptPurpose(str, enum.Enum):
    PUBLIC = "public"
    INVITE_CODE_PRIVATE_ELIGIBLE = "invite_code_private_eligible"


class AttemptPhase(str, enum.Enum):
    RENDEZVOUS_ACTIVE = "rendezvous_active"
    ADMISSION_AWAITING_HOST = "admission_awaiting_host"
    ADMISSION_READY = "admission_ready"
    TERMINAL = "terminal"


class ValidationError(ValueError):
    pass


class AuthenticationError(ValueError):
    pass


def observed_client_ip(peer: str, forwarded_for: str = "") -> str:
    """Use a reverse proxy's observed IPv4 only when the HTTP peer is loopback."""
    if peer not in ("127.0.0.1", "::1") or not forwarded_for:
        return peer
    for value in reversed(forwarded_for.split(",")):
        try:
            address = ipaddress.ip_address(value.strip())
        except ValueError:
            continue
        if address.version == 4:
            return str(address)
    return peer


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


def _title_id(value: Any) -> str:
    value = _required_text(value, "title_id", 8).upper()
    if len(value) != 8 or any(ch not in "0123456789ABCDEF" for ch in value):
        raise ValidationError("title_id must contain exactly eight hexadecimal digits")
    return value


def _attempt_request_id(value: Any) -> str:
    if not isinstance(value, str) or len(value) != ATTEMPT_REQUEST_ID_LENGTH:
        raise ValidationError("request_id must contain exactly 32 hexadecimal digits")
    normalized = value.lower()
    if any(ch not in "0123456789abcdef" for ch in normalized):
        raise ValidationError("request_id must contain exactly 32 hexadecimal digits")
    return normalized


def _reject_client_purpose(payload: Any) -> dict[str, Any]:
    if not isinstance(payload, dict):
        raise ValidationError("request body must be an object")
    if "purpose" in payload:
        raise ValidationError("attempt purpose is server-owned")
    return payload


def validate_by_code_attempt(payload: Any) -> dict[str, Any]:
    payload = _reject_client_purpose(payload)
    return {
        "request_id": _attempt_request_id(payload.get("request_id")),
        "title_id": _title_id(payload.get("title_id")),
        "protocol_version": _required_int(
            payload.get("protocol_version"), "protocol_version", 1, 65535),
        "build_id": _build_id(payload.get("build_id")),
    }


def _hex_128(value: Any, name: str) -> str:
    if not isinstance(value, str) or len(value) != 32:
        raise ValidationError(f"{name} must contain exactly 32 hexadecimal digits")
    normalized = value.lower()
    if any(ch not in "0123456789abcdef" for ch in normalized):
        raise ValidationError(f"{name} must contain exactly 32 hexadecimal digits")
    return normalized


def validate_admission_arm(payload: Any) -> None:
    if not isinstance(payload, dict):
        raise ValidationError("request body must be an object")
    if payload:
        raise ValidationError("admission arm request must be empty")


def validate_admission_renew(payload: Any) -> dict[str, Any]:
    if not isinstance(payload, dict):
        raise ValidationError("request body must be an object")
    expected = {"admission_generation", "previous_lease_revision"}
    if set(payload) != expected:
        raise ValidationError("admission renewal fields are invalid")
    return {
        "admission_generation": _hex_128(
            payload.get("admission_generation"), "admission_generation"),
        "previous_lease_revision": _required_int(
            payload.get("previous_lease_revision"),
            "previous_lease_revision", 1, (1 << 63) - 1),
    }


def validate_host_poll(payload: Any) -> list[dict[str, Any]]:
    if not isinstance(payload, dict) or set(payload) != {"acknowledged"}:
        raise ValidationError("host poll request must contain acknowledged")
    acknowledged = payload.get("acknowledged")
    if not isinstance(acknowledged, list) or len(acknowledged) > MAX_ATTEMPTS_PER_SESSION:
        raise ValidationError("acknowledged must be a bounded array")
    result = []
    for value in acknowledged:
        if (not isinstance(value, dict) or
                set(value) != {"attempt_id", "admission_generation", "lease_revision"}):
            raise ValidationError("acknowledgement fields are invalid")
        result.append({
            "attempt_id": _hex_128(value.get("attempt_id"), "attempt_id"),
            "admission_generation": _hex_128(
                value.get("admission_generation"), "admission_generation"),
            "lease_revision": _required_int(
                value.get("lease_revision"), "lease_revision", 1, (1 << 63) - 1),
        })
    return result


def _url_token(value: Any, name: str, maximum: int) -> str:
    value = _required_text(value, name, maximum)
    if any(not (ch.isascii() and (ch.isalnum() or ch in "-_")) for ch in value):
        raise ValidationError(f"{name} contains unsupported characters")
    return value


def normalize_invite_code(value: str) -> str | None:
    if not isinstance(value, str):
        return None
    normalized = value.upper()
    if (len(normalized) != INVITE_CODE_LENGTH or
            any(ch not in INVITE_CODE_ALPHABET for ch in normalized)):
        return None
    return normalized


def generate_invite_code() -> str:
    return "".join(secrets.choice(INVITE_CODE_ALPHABET) for _ in range(INVITE_CODE_LENGTH))


def _validate_candidates(value: Any) -> list[dict[str, Any]]:
    if not isinstance(value, list) or not 1 <= len(value) <= MAX_CANDIDATES:
        raise ValidationError("connectivity_candidates must contain 1 to 4 entries")
    result: list[dict[str, Any]] = []
    for candidate in value:
        if not isinstance(candidate, dict):
            raise ValidationError("connectivity candidate must be an object")
        candidate_type = _required_text(candidate.get("type"), "candidate type", 24)
        if candidate_type not in {"direct", "tailscale", "public"}:
            raise ValidationError("unsupported connectivity candidate type")
        address = candidate.get("address", "")
        if candidate_type == "public" and address == "":
            parsed_address = ""
        else:
            address = _required_text(address, "candidate address", 45)
            try:
                parsed = ipaddress.ip_address(address)
            except ValueError as exc:
                raise ValidationError("candidate address must be an IPv4 literal") from exc
            if parsed.version != 4 or parsed.is_unspecified or parsed.is_multicast or parsed.is_loopback:
                raise ValidationError("candidate address is not publishable")
            parsed_address = str(parsed)
        discovery_port = _required_int(candidate.get("discovery_port"), "discovery_port", 1, 65535)
        gameplay_port = _required_int(candidate.get("gameplay_port"), "gameplay_port", 1, 65535)
        result.append(
            {
                "type": candidate_type,
                "address": parsed_address,
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
    title_id = _title_id(payload.get("title_id"))
    return {
        "server_name": _required_text(payload.get("server_name"), "server_name", MAX_SERVER_NAME),
        "player_count": player_count,
        "max_players": max_players,
        "title_id": title_id,
        "protocol_version": _required_int(payload.get("protocol_version"), "protocol_version", 1, 65535),
        "build_id": _build_id(payload.get("build_id")),
        "connectivity_candidates": _validate_candidates(payload.get("connectivity_candidates")),
    }


def validate_host_instance(payload: Any) -> tuple[str, str]:
    if not isinstance(payload, dict):
        raise ValidationError("request body must be an object")
    instance_id = payload.get("host_instance_id")
    instance_token = payload.get("host_instance_token")
    if instance_id is None and instance_token is None:
        return "", ""
    if instance_id is None or instance_token is None:
        raise ValidationError("host instance ID and token must be supplied together")
    return (
        _url_token(instance_id, "host_instance_id", MAX_HOST_INSTANCE_ID),
        _url_token(instance_token, "host_instance_token", MAX_HOST_INSTANCE_TOKEN),
    )


@dataclass
class StoredSession:
    session_id: str
    registration_token: str
    host_instance_id: str
    host_instance_token: str
    invite_code: str
    metadata: dict[str, Any]
    last_heartbeat: float

    def public(self) -> dict[str, Any]:
        return {
            "session_id": self.session_id,
            **self.metadata,
            "last_heartbeat": int(self.last_heartbeat),
        }


class SessionRegistry:
    def __init__(self, ttl_seconds: int = DEFAULT_TTL_SECONDS, clock=time.time,
                 on_remove=None, invite_code_factory=generate_invite_code):
        self.ttl_seconds = ttl_seconds
        self.clock = clock
        self._lock = threading.Lock()
        self._sessions: dict[str, StoredSession] = {}
        self._host_instances: dict[str, str] = {}
        self._invite_codes: dict[str, str] = {}
        self.invite_code_factory = invite_code_factory
        self.on_remove = on_remove

    def _remove_locked(self, session_id: str) -> None:
        value = self._sessions.pop(session_id, None)
        if value is None:
            return
        if (value.host_instance_id and
                self._host_instances.get(value.host_instance_id) == session_id):
            del self._host_instances[value.host_instance_id]
        if self._invite_codes.get(value.invite_code) == session_id:
            del self._invite_codes[value.invite_code]
        if self.on_remove:
            self.on_remove(session_id)

    def _expire_locked(self, now: float) -> None:
        stale = [key for key, value in self._sessions.items() if now - value.last_heartbeat >= self.ttl_seconds]
        for key in stale:
            self._remove_locked(key)

    def create(self, payload: Any, source: str = "") -> StoredSession:
        metadata = validate_registration(payload)
        host_instance_id, host_instance_token = validate_host_instance(payload)
        for candidate in metadata["connectivity_candidates"]:
            if candidate["type"] == "public" and source:
                candidate["address"] = source
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            if host_instance_id:
                current_id = self._host_instances.get(host_instance_id)
                current = self._sessions.get(current_id, None)
                if current is not None:
                    if not secrets.compare_digest(current.host_instance_token,
                                                  host_instance_token):
                        raise AuthenticationError("host instance authentication failed")
                    current.metadata = metadata
                    current.last_heartbeat = now
                    return current
                self._host_instances.pop(host_instance_id, None)
            invite_code = None
            for _ in range(INVITE_CODE_GENERATION_ATTEMPTS):
                candidate = normalize_invite_code(self.invite_code_factory())
                if candidate is not None and candidate not in self._invite_codes:
                    invite_code = candidate
                    break
            if invite_code is None:
                raise RuntimeError("unable to allocate invite code")
            value = StoredSession(
                secrets.token_urlsafe(18), secrets.token_urlsafe(32),
                host_instance_id, host_instance_token, invite_code, metadata, now)
            self._sessions[value.session_id] = value
            self._invite_codes[value.invite_code] = value.session_id
            if host_instance_id:
                self._host_instances[host_instance_id] = value.session_id
        return value

    def heartbeat(self, session_id: str, token: str, payload: Any,
                  source: str = "") -> StoredSession | None:
        metadata = validate_registration(payload)
        for candidate in metadata["connectivity_candidates"]:
            if candidate["type"] == "public" and source:
                candidate["address"] = source
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            value = self._sessions.get(session_id)
            if value is None:
                return None
            if not secrets.compare_digest(value.registration_token, token):
                raise AuthenticationError("registration authentication failed")
            value.metadata = metadata
            value.last_heartbeat = now
            return value

    def delete(self, session_id: str, token: str) -> bool:
        with self._lock:
            value = self._sessions.get(session_id)
            if value is None or not secrets.compare_digest(value.registration_token, token):
                return False
            self._remove_locked(session_id)
            return True

    def owns(self, session_id: str, token: str) -> bool:
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            value = self._sessions.get(session_id)
            return value is not None and secrets.compare_digest(value.registration_token, token)

    def exists(self, session_id: str) -> bool:
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            return session_id in self._sessions

    def issue_public_attempt(
        self, session_id: str, traversal: RendezvousRegistry, source: str = "",
    ) -> tuple[str, dict[str, Any] | None]:
        """Validate the directory session and issue under registry -> traversal locks."""
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            if session_id not in self._sessions:
                return "not_found", None
            if not traversal.rendezvous_host:
                return "unavailable", None
            value = traversal.issue(
                session_id, source, purpose=AttemptPurpose.PUBLIC)
            return ("created", value) if value is not None else ("limited", None)

    def issue_by_code_attempt(
        self, code: str, request: dict[str, Any], traversal: RendezvousRegistry,
        source: str = "",
    ) -> tuple[str, dict[str, Any] | None, dict[str, Any] | None]:
        """Atomically resolve a compatible code and issue its idempotent attempt."""
        normalized = normalize_invite_code(code)
        if normalized is None:
            return "not_found", None, None
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            session_id = self._invite_codes.get(normalized)
            value = self._sessions.get(session_id) if session_id is not None else None
            if value is None:
                return "not_found", None, None
            metadata = value.metadata
            if not traversal.rendezvous_host:
                return "unavailable", None, None
            fingerprint = (
                normalized,
                value.session_id,
                request["title_id"],
                request["protocol_version"],
                request["build_id"],
            )
            status, attempt = traversal.issue_idempotent(
                value.session_id,
                request["request_id"],
                fingerprint,
                source,
                purpose=AttemptPurpose.INVITE_CODE_PRIVATE_ELIGIBLE,
                allow_create=(
                    metadata["title_id"] == request["title_id"] and
                    metadata["protocol_version"] == request["protocol_version"] and
                    metadata["build_id"] == request["build_id"]),
            )
            return status, value.public(), attempt

    def arm_admission(
        self, session_id: str, attempt_id: str, credential: str,
        traversal: RendezvousRegistry,
    ) -> tuple[str, dict[str, Any] | None]:
        """Arm while preserving the registry -> traversal lock order."""
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            if session_id not in self._sessions:
                return "not_found", None
            return traversal.arm_admission(session_id, attempt_id, credential)

    def renew_admission(
        self, session_id: str, attempt_id: str, credential: str,
        request: dict[str, Any], traversal: RendezvousRegistry,
    ) -> tuple[str, dict[str, Any] | None]:
        """Renew while preserving the registry -> traversal lock order."""
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            if session_id not in self._sessions:
                return "not_found", None
            return traversal.renew_admission(
                session_id, attempt_id, credential,
                request["admission_generation"], request["previous_lease_revision"])

    def admission_status(
        self, session_id: str, attempt_id: str, credential: str,
        traversal: RendezvousRegistry,
    ) -> tuple[str, dict[str, Any] | None]:
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            if session_id not in self._sessions:
                return "not_found", None
            return traversal.admission_status(session_id, attempt_id, credential)

    def host_poll_attempts(
        self, session_id: str, token: str, acknowledged: list[dict[str, Any]],
        traversal: RendezvousRegistry,
    ) -> tuple[str, list[dict[str, Any]] | None]:
        """Authenticate and poll/ack atomically with directory-session lifetime."""
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            value = self._sessions.get(session_id)
            if value is None or not secrets.compare_digest(value.registration_token, token):
                return "not_found", None
            return "ok", traversal.host_poll(session_id, acknowledged)

    def gameplay_request(self, session_id, action, credential, payload, traversal):
        # Existing directory -> traversal lock order; hosting authentication and
        # directory lifetime are checked atomically with every gameplay operation.
        with self._lock:
            self._expire_locked(self.clock())
            session = self._sessions.get(session_id)
            if session is None:
                return None
            if action == "sync" and not secrets.compare_digest(session.registration_token, credential):
                return None
            return traversal.gameplay_request(session_id, action, credential, payload)

    def revoke_admission(
        self, session_id: str, attempt_id: str, credential: str,
        traversal: RendezvousRegistry,
    ) -> str:
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            if session_id not in self._sessions:
                return "not_found"
            return traversal.revoke_admission(session_id, attempt_id, credential)

    def lookup_code(self, code: str) -> dict[str, Any] | None:
        normalized = normalize_invite_code(code)
        if normalized is None:
            return None
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            session_id = self._invite_codes.get(normalized)
            value = self._sessions.get(session_id) if session_id is not None else None
            return value.public() if value is not None else None

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


class InviteLookupLimiter:
    """Small process-local fixed-window limiter with bounded source state."""

    def __init__(self, clock=time.monotonic):
        self.clock = clock
        self._lock = threading.Lock()
        self._sources: collections.OrderedDict[str, tuple[float, int]] = collections.OrderedDict()

    def allow(self, source: str) -> bool:
        now = self.clock()
        with self._lock:
            stale_before = now - INVITE_LOOKUP_WINDOW_SECONDS
            while self._sources:
                oldest_source, (started, _) = next(iter(self._sources.items()))
                if started > stale_before:
                    break
                self._sources.pop(oldest_source)
            started, count = self._sources.pop(source, (now, 0))
            if started <= stale_before:
                started, count = now, 0
            count += 1
            self._sources[source] = (started, count)
            while len(self._sources) > MAX_INVITE_LOOKUP_SOURCES:
                self._sources.popitem(last=False)
            return count <= MAX_INVITE_LOOKUPS_PER_WINDOW


class DirectoryHandler(BaseHTTPRequestHandler):
    server_version = "HarmonyDirectory/1"

    @property
    def registry(self) -> SessionRegistry:
        return self.server.registry  # type: ignore[attr-defined]

    @property
    def traversal(self) -> RendezvousRegistry:
        return self.server.traversal  # type: ignore[attr-defined]

    @property
    def invite_limiter(self) -> InviteLookupLimiter:
        return self.server.invite_limiter  # type: ignore[attr-defined]

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

    def _observed_client_ip(self) -> str:
        return observed_client_ip(
            self.client_address[0], self.headers.get("X-Forwarded-For", ""))

    def _admission_error(self, status: str) -> None:
        if status == "terminal":
            self._json(HTTPStatus.GONE, {"error": "attempt is terminal"})
        elif status in {"not_eligible", "not_ready", "conflict"}:
            self._json(HTTPStatus.CONFLICT, {"error": status.replace("_", " ")})
        elif status == "invalid_purpose":
            self._json(
                HTTPStatus.SERVICE_UNAVAILABLE,
                {"error": "admission state failed closed"},
            )
        else:
            self._json(
                HTTPStatus.NOT_FOUND,
                {"error": "unknown session, attempt, or capability"},
            )

    def do_GET(self) -> None:  # noqa: N802
        parsed = urllib.parse.urlsplit(self.path)
        if parsed.path == "/sessions":
            query = {key: values[-1] for key, values in urllib.parse.parse_qs(parsed.query).items()}
            self._json(HTTPStatus.OK, {"sessions": self.registry.list(query)})
            return
        parts = parsed.path.strip("/").split("/")
        if len(parts) == 3 and parts[0] == "sessions" and parts[1] == "by-code":
            code = normalize_invite_code(parts[2])
            if code is None:
                self._json(HTTPStatus.NOT_FOUND, {"error": "unknown invite code"})
            elif not self.invite_limiter.allow(self._observed_client_ip()):
                self._json(HTTPStatus.TOO_MANY_REQUESTS, {"error": "invite lookup limit reached"})
            else:
                value = self.registry.lookup_code(code)
                if value is None:
                    self._json(HTTPStatus.NOT_FOUND, {"error": "unknown invite code"})
                else:
                    self._json(HTTPStatus.OK, {"session": value})
            return
        if (len(parts) == 5 and parts[0] == "sessions" and
                parts[2] == "join-attempts" and parts[4] == "admission"):
            status, value = self.registry.admission_status(
                parts[1], parts[3], self._bearer(), self.traversal)
            if status == "ok":
                self._json(HTTPStatus.OK, value)
            else:
                self._admission_error(status)
            return
        if len(parts) == 3 and parts[0] == "sessions" and parts[2] == "join-attempts":
            status, attempts = self.registry.host_poll_attempts(
                parts[1], self._bearer(), [], self.traversal)
            if status != "ok":
                self._json(HTTPStatus.NOT_FOUND, {"error": "unknown session or token"})
            else:
                self._json(HTTPStatus.OK, {"attempts": attempts})
            return
        self._json(HTTPStatus.NOT_FOUND, {"error": "not found"})

    def do_POST(self) -> None:  # noqa: N802
        parsed = urllib.parse.urlsplit(self.path)
        try:
            payload = self._read_json()
            if parsed.path == "/sessions":
                value = self.registry.create(payload, self._observed_client_ip())
                self._json(
                    HTTPStatus.CREATED,
                    {"session_id": value.session_id,
                     "registration_token": value.registration_token,
                     "invite_code": value.invite_code},
                )
                return
            parts = parsed.path.strip("/").split("/")
            if (len(parts) == 4 and parts[0] == "sessions" and parts[2] == "gameplay" and
                    parts[3] in ("sync", "claim", "status", "revoke")):
                try:
                    value = self.registry.gameplay_request(
                        parts[1], parts[3], self._bearer(), payload, self.traversal)
                except GameplayError as exc:
                    self._json(HTTPStatus.CONFLICT, {"error": str(exc)})
                    return
                if value is None:
                    self._json(HTTPStatus.NOT_FOUND, {"error": "gameplay membership unavailable"})
                else:
                    self._json(HTTPStatus.OK, value)
                return
            if (len(parts) == 4 and parts[0] == "sessions" and
                    parts[1] == "by-code" and parts[3] == "join-attempts"):
                code = normalize_invite_code(parts[2])
                if code is None:
                    self._json(HTTPStatus.NOT_FOUND, {"error": "unknown invite code"})
                    return
                if not self.invite_limiter.allow(self._observed_client_ip()):
                    self._json(
                        HTTPStatus.TOO_MANY_REQUESTS,
                        {"error": "invite lookup limit reached"},
                    )
                    return
                request = validate_by_code_attempt(payload)
                status, session, attempt = self.registry.issue_by_code_attempt(
                    code, request, self.traversal, self._observed_client_ip())
                if status == "created":
                    self._json(HTTPStatus.CREATED, {"session": session, "attempt": attempt})
                elif status == "replayed":
                    self._json(HTTPStatus.OK, {"session": session, "attempt": attempt})
                elif status == "not_found":
                    self._json(
                        HTTPStatus.NOT_FOUND,
                        {"error": "unknown or incompatible invite code"},
                    )
                elif status == "unavailable":
                    self._json(
                        HTTPStatus.SERVICE_UNAVAILABLE,
                        {"error": "public traversal is unavailable"},
                    )
                elif status == "invalid_purpose":
                    self._json(
                        HTTPStatus.SERVICE_UNAVAILABLE,
                        {"error": "attempt issuance failed closed"},
                    )
                elif status == "limited":
                    self._json(
                        HTTPStatus.TOO_MANY_REQUESTS,
                        {"error": "attempt limit reached"},
                    )
                elif status == "conflict":
                    self._json(
                        HTTPStatus.CONFLICT,
                        {"error": "request_id is already bound to another request"},
                    )
                elif status == "terminal":
                    self._json(
                        HTTPStatus.GONE,
                        {"error": "request_id attempt is terminal"},
                    )
                else:
                    self._json(
                        HTTPStatus.SERVICE_UNAVAILABLE,
                        {"error": "attempt issuance failed closed"},
                    )
                return
            if (len(parts) == 4 and parts[0] == "sessions" and
                    parts[2] == "join-attempts" and parts[3] == "poll"):
                acknowledged = validate_host_poll(payload)
                status, attempts = self.registry.host_poll_attempts(
                    parts[1], self._bearer(), acknowledged, self.traversal)
                if status != "ok":
                    self._json(HTTPStatus.NOT_FOUND, {"error": "unknown session or token"})
                else:
                    self._json(HTTPStatus.OK, {"attempts": attempts})
                return
            if (len(parts) == 6 and parts[0] == "sessions" and
                    parts[2] == "join-attempts" and parts[4] == "admission"):
                if parts[5] == "arm":
                    validate_admission_arm(payload)
                    status, value = self.registry.arm_admission(
                        parts[1], parts[3], self._bearer(), self.traversal)
                    if status == "created":
                        self._json(HTTPStatus.CREATED, value)
                    elif status == "replayed":
                        self._json(HTTPStatus.OK, value)
                    else:
                        self._admission_error(status)
                    return
                if parts[5] == "renew":
                    request = validate_admission_renew(payload)
                    status, value = self.registry.renew_admission(
                        parts[1], parts[3], self._bearer(), request, self.traversal)
                    if status == "renewed":
                        self._json(HTTPStatus.OK, value)
                    else:
                        self._admission_error(status)
                    return
                if parts[5] == "revoke":
                    validate_admission_arm(payload)
                    status = self.registry.revoke_admission(
                        parts[1], parts[3], self._bearer(), self.traversal)
                    if status == "revoked":
                        self.send_response(HTTPStatus.NO_CONTENT)
                        self.end_headers()
                    else:
                        self._admission_error(status)
                    return
            if len(parts) == 3 and parts[0] == "sessions" and parts[2] == "join-attempts":
                _reject_client_purpose(payload)
                status, value = self.registry.issue_public_attempt(
                    parts[1], self.traversal, self._observed_client_ip())
                if status == "not_found":
                    self._json(HTTPStatus.NOT_FOUND, {"error": "unknown session"})
                    return
                if status == "unavailable":
                    self._json(HTTPStatus.SERVICE_UNAVAILABLE,
                               {"error": "public traversal is unavailable"})
                    return
                if status == "limited" or value is None:
                    self._json(HTTPStatus.TOO_MANY_REQUESTS, {"error": "attempt limit reached"})
                else:
                    self._json(HTTPStatus.CREATED, value)
                return
            if len(parts) == 3 and parts[0] == "sessions" and parts[2] == "heartbeat":
                value = self.registry.heartbeat(parts[1], self._bearer(), payload,
                                                self._observed_client_ip())
                if value is None:
                    self._json(HTTPStatus.NOT_FOUND, {"error": "unknown session or token"})
                else:
                    self._json(HTTPStatus.OK, {"session_id": value.session_id})
                return
            self._json(HTTPStatus.NOT_FOUND, {"error": "not found"})
        except AuthenticationError as exc:
            self._json(HTTPStatus.FORBIDDEN, {"error": str(exc)})
        except ValidationError as exc:
            self._json(HTTPStatus.BAD_REQUEST, {"error": str(exc)})

    def do_DELETE(self) -> None:  # noqa: N802
        parsed = urllib.parse.urlsplit(self.path)
        parts = parsed.path.strip("/").split("/")
        if len(parts) == 4 and parts[0] == "sessions" and parts[2] == "join-attempts":
            if self.traversal.complete(parts[1], parts[3], self._bearer()):
                self.send_response(HTTPStatus.NO_CONTENT)
                self.end_headers()
            else:
                self._json(HTTPStatus.NOT_FOUND, {"error": "unknown attempt or capability"})
            return
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

    def __init__(self, address: tuple[str, int], registry: SessionRegistry,
                 traversal: RendezvousRegistry | None = None):
        super().__init__(address, DirectoryHandler)
        self.registry = registry
        self.traversal = traversal or RendezvousRegistry()
        self.invite_limiter = InviteLookupLimiter()


@dataclass
class AdmissionState:
    generation: bytes
    lease_revision: int
    expires_at: float
    host_seen_generation: bytes | None = None
    host_seen_revision: int | None = None
    host_seen_at: float | None = None


@dataclass
class RendezvousAttempt:
    session_id: str
    credentials: tuple[bytes, bytes]
    purpose: AttemptPurpose
    issued_at: float
    expires_at: float
    completed: bool
    request_id: str | None
    endpoints: dict[tuple[int, int], tuple[str, int]]
    endpoint_seen: dict[tuple[int, int], float]
    responses: dict[
        tuple[int, int],
        tuple[float, tuple[str, int], tuple[str, int] | None],
    ]
    admission: AdmissionState | None = None


@dataclass
class TerminalAttempt:
    session_id: str
    credentials: tuple[bytes, bytes]
    purpose: AttemptPurpose | str
    request_id: str | None
    admission: AdmissionState | None
    terminal_reason: str


@dataclass
class AttemptRequestState:
    session_id: str
    fingerprint: tuple[str, str, str, int, str]
    attempt_id: bytes
    terminal_reason: str | None = None


class RendezvousRegistry:
    """Short-lived, credential-bound NAT traversal endpoint observations."""

    def __init__(self, ttl_seconds: int = DEFAULT_ATTEMPT_TTL_SECONDS, clock=time.monotonic,
                 rendezvous_host: str = "", rendezvous_port: int = 30740,
                 admission_ttl_seconds: int = DEFAULT_ADMISSION_TTL_SECONDS):
        self.ttl_seconds = ttl_seconds
        self.admission_ttl_seconds = admission_ttl_seconds
        self.clock = clock
        self._lock = threading.Lock()
        self._attempts: dict[bytes, RendezvousAttempt] = {}
        self._by_session: dict[str, set[bytes]] = {}
        self._terminal_attempts: dict[bytes, TerminalAttempt] = {}
        self._terminal_by_session: dict[str, set[bytes]] = {}
        self._last_create: dict[tuple[str, str], float] = {}
        self._request_ids: dict[str, AttemptRequestState] = {}
        self._request_ids_by_session: dict[str, set[str]] = {}
        self.rendezvous_host = rendezvous_host
        self.rendezvous_port = rendezvous_port
        self.gameplay = GameplayRegistry()

    @staticmethod
    def _purpose(value: Any) -> AttemptPurpose | None:
        try:
            return value if isinstance(value, AttemptPurpose) else AttemptPurpose(value)
        except (TypeError, ValueError):
            return None

    def _remove_attempt_locked(self, attempt_id: bytes, reason: str) -> None:
        value = self._attempts.pop(attempt_id, None)
        if value is None:
            return
        attempts = self._by_session.get(value.session_id)
        if attempts is not None:
            attempts.discard(attempt_id)
            if not attempts:
                self._by_session.pop(value.session_id, None)
        if value.request_id is not None or value.admission is not None:
            self._terminal_attempts[attempt_id] = TerminalAttempt(
                session_id=value.session_id,
                credentials=value.credentials,
                purpose=value.purpose,
                request_id=value.request_id,
                admission=value.admission,
                terminal_reason=reason,
            )
            self._terminal_by_session.setdefault(value.session_id, set()).add(attempt_id)
        if value.request_id is not None:
            request = self._request_ids.get(value.request_id)
            if request is not None and request.attempt_id == attempt_id:
                request.terminal_reason = reason

    def _expire_locked(self, now: float) -> None:
        stale: list[tuple[bytes, str]] = []
        for key, value in self._attempts.items():
            if value.completed:
                stale.append((key, "completed"))
            elif value.admission is not None:
                if now >= value.admission.expires_at:
                    stale.append((key, "admission_expired"))
            elif now >= value.expires_at:
                stale.append((key, "expired"))
        for key, reason in stale:
            self._remove_attempt_locked(key, reason)

    def _issue_locked(
        self, session_id: str, source: str, purpose: AttemptPurpose,
        request_id: str | None = None,
    ) -> tuple[bytes, RendezvousAttempt] | None:
        now = self.clock()
        attempts = self._by_session.setdefault(session_id, set())
        rate_key = (session_id, source)
        previous = self._last_create.get(rate_key)
        if (len(attempts) >= MAX_ATTEMPTS_PER_SESSION or
                previous is not None and now - previous < ATTEMPT_CREATE_MIN_INTERVAL_SECONDS or
                len(self._attempts) >= MAX_RENDEZVOUS_ATTEMPTS):
            if not attempts:
                self._by_session.pop(session_id, None)
            return None
        attempt_id = secrets.token_bytes(16)
        while attempt_id in self._attempts:
            attempt_id = secrets.token_bytes(16)
        value = RendezvousAttempt(
            session_id=session_id,
            credentials=(secrets.token_bytes(16), secrets.token_bytes(16)),
            purpose=purpose,
            issued_at=now,
            expires_at=now + self.ttl_seconds,
            completed=False,
            request_id=request_id,
            endpoints={},
            endpoint_seen={},
            responses={},
        )
        self._attempts[attempt_id] = value
        attempts.add(attempt_id)
        self._last_create[rate_key] = now
        print(f"NAT timing: issued session={session_id} attempt={attempt_id.hex()} "
              f"expires_at={value.expires_at:.6f}", flush=True)
        return attempt_id, value

    def issue(
        self, session_id: str, source: str = "",
        purpose: AttemptPurpose | str = AttemptPurpose.PUBLIC,
    ) -> dict[str, Any] | None:
        normalized_purpose = self._purpose(purpose)
        if normalized_purpose is None:
            return None
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            created = self._issue_locked(session_id, source, normalized_purpose)
            if created is None:
                return None
            attempt_id, attempt = created
            return self._public(attempt_id, attempt, 1)

    def issue_idempotent(
        self, session_id: str, request_id: str,
        fingerprint: tuple[str, str, str, int, str], source: str = "",
        purpose: AttemptPurpose | str = AttemptPurpose.INVITE_CODE_PRIVATE_ELIGIBLE,
        allow_create: bool = True,
    ) -> tuple[str, dict[str, Any] | None]:
        normalized_purpose = self._purpose(purpose)
        if normalized_purpose is None:
            return "invalid_purpose", None
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            previous = self._request_ids.get(request_id)
            if previous is not None:
                if previous.fingerprint != fingerprint:
                    return "conflict", None
                if previous.terminal_reason is not None:
                    return "terminal", None
                attempt = self._attempts.get(previous.attempt_id)
                if attempt is None:
                    previous.terminal_reason = "missing"
                    return "terminal", None
                value = self._public(previous.attempt_id, attempt, 1)
                if value is None:
                    self._remove_attempt_locked(previous.attempt_id, "invalid_purpose")
                    return "terminal", None
                return "replayed", value
            if not allow_create:
                return "not_found", None
            created = self._issue_locked(
                session_id, source, normalized_purpose, request_id=request_id)
            if created is None:
                return "limited", None
            attempt_id, attempt = created
            self._request_ids[request_id] = AttemptRequestState(
                session_id=session_id,
                fingerprint=fingerprint,
                attempt_id=attempt_id,
            )
            self._request_ids_by_session.setdefault(session_id, set()).add(request_id)
            value = self._public(attempt_id, attempt, 1)
            if value is None:
                self._remove_attempt_locked(attempt_id, "invalid_purpose")
                return "invalid_purpose", None
            return "created", value

    @staticmethod
    def _decode_128(value: str) -> bytes | None:
        try:
            decoded = bytes.fromhex(value)
        except (TypeError, ValueError):
            return None
        return decoded if len(decoded) == 16 else None

    @staticmethod
    def _host_ready(admission: AdmissionState, now: float) -> bool:
        return (
            now < admission.expires_at and
            admission.host_seen_generation == admission.generation and
            admission.host_seen_revision == admission.lease_revision
        )

    def _admission_view(
        self, attempt_id: bytes, purpose: AttemptPurpose,
        admission: AdmissionState | None, now: float,
        *, include_host_seen: bool, terminal_reason: str | None = None,
    ) -> dict[str, Any]:
        host_ready = admission is not None and self._host_ready(admission, now)
        if terminal_reason is not None:
            phase = AttemptPhase.TERMINAL
            host_ready = False
        elif admission is None:
            phase = AttemptPhase.RENDEZVOUS_ACTIVE
        elif host_ready:
            phase = AttemptPhase.ADMISSION_READY
        else:
            phase = AttemptPhase.ADMISSION_AWAITING_HOST
        value: dict[str, Any] = {
            "attempt_id": attempt_id.hex(),
            "purpose": purpose.value,
            "phase": phase.value,
            "admission_generation": (
                admission.generation.hex() if admission is not None else None),
            "lease_revision": admission.lease_revision if admission is not None else None,
            "admission_lease_duration_ms": int(self.admission_ttl_seconds * 1000),
            "admission_expires_in_ms": (
                max(0, int((admission.expires_at - now) * 1000))
                if admission is not None and terminal_reason is None else 0),
            "host_ready": host_ready,
        }
        if include_host_seen:
            value["host_seen_admission_generation"] = (
                admission.host_seen_generation.hex()
                if admission is not None and admission.host_seen_generation is not None
                else None)
            value["host_seen_lease_revision"] = (
                admission.host_seen_revision if admission is not None else None)
        if terminal_reason is not None:
            value["terminal_reason"] = terminal_reason
        return value

    def _terminal_client_locked(
        self, session_id: str, attempt_id: bytes, credential: bytes,
    ) -> TerminalAttempt | None:
        terminal = self._terminal_attempts.get(attempt_id)
        if (terminal is None or terminal.session_id != session_id or
                not secrets.compare_digest(terminal.credentials[1], credential)):
            return None
        return terminal

    def arm_admission(
        self, session_id: str, attempt_text: str, credential_text: str,
    ) -> tuple[str, dict[str, Any] | None]:
        attempt_id = self._decode_128(attempt_text)
        credential = self._decode_128(credential_text)
        if attempt_id is None or credential is None:
            return "not_found", None
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            attempt = self._attempts.get(attempt_id)
            if attempt is None:
                terminal = self._terminal_client_locked(session_id, attempt_id, credential)
                return ("terminal", None) if terminal is not None else ("not_found", None)
            if (attempt.session_id != session_id or
                    not secrets.compare_digest(attempt.credentials[1], credential)):
                return "not_found", None
            purpose = self._purpose(attempt.purpose)
            if purpose is None:
                self._remove_attempt_locked(attempt_id, "invalid_purpose")
                return "invalid_purpose", None
            if purpose is not AttemptPurpose.INVITE_CODE_PRIVATE_ELIGIBLE:
                return "not_eligible", None
            if attempt.admission is not None:
                return "replayed", self._admission_view(
                    attempt_id, purpose, attempt.admission, now, include_host_seen=False)
            # The directory owns no Xbox session tuple. Both discovery-role endpoint
            # observations are the strongest completed-rendezvous evidence it has.
            if (0, 0) not in attempt.endpoints or (1, 0) not in attempt.endpoints:
                return "not_ready", None
            attempt.admission = AdmissionState(
                generation=secrets.token_bytes(16),
                lease_revision=1,
                expires_at=now + self.admission_ttl_seconds,
            )
            return "created", self._admission_view(
                attempt_id, purpose, attempt.admission, now, include_host_seen=False)

    def renew_admission(
        self, session_id: str, attempt_text: str, credential_text: str,
        generation_text: str, previous_revision: int,
    ) -> tuple[str, dict[str, Any] | None]:
        attempt_id = self._decode_128(attempt_text)
        credential = self._decode_128(credential_text)
        generation = self._decode_128(generation_text)
        if attempt_id is None or credential is None or generation is None:
            return "not_found", None
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            attempt = self._attempts.get(attempt_id)
            if attempt is None:
                terminal = self._terminal_client_locked(session_id, attempt_id, credential)
                return ("terminal", None) if terminal is not None else ("not_found", None)
            if (attempt.session_id != session_id or
                    not secrets.compare_digest(attempt.credentials[1], credential)):
                return "not_found", None
            purpose = self._purpose(attempt.purpose)
            if purpose is None:
                self._remove_attempt_locked(attempt_id, "invalid_purpose")
                return "invalid_purpose", None
            if purpose is not AttemptPurpose.INVITE_CODE_PRIVATE_ELIGIBLE:
                return "not_eligible", None
            admission = attempt.admission
            if admission is None:
                return "not_ready", None
            if (admission.generation != generation or
                    admission.lease_revision != previous_revision):
                return "conflict", None
            if not self._host_ready(admission, now):
                return "not_ready", None
            if admission.lease_revision >= (1 << 63) - 1:
                return "conflict", None
            admission.lease_revision += 1
            admission.expires_at = now + self.admission_ttl_seconds
            return "renewed", self._admission_view(
                attempt_id, purpose, admission, now, include_host_seen=False)

    def admission_status(
        self, session_id: str, attempt_text: str, credential_text: str,
    ) -> tuple[str, dict[str, Any] | None]:
        attempt_id = self._decode_128(attempt_text)
        credential = self._decode_128(credential_text)
        if attempt_id is None or credential is None:
            return "not_found", None
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            attempt = self._attempts.get(attempt_id)
            if attempt is not None:
                if (attempt.session_id != session_id or
                        not secrets.compare_digest(attempt.credentials[1], credential)):
                    return "not_found", None
                purpose = self._purpose(attempt.purpose)
                if purpose is None:
                    self._remove_attempt_locked(attempt_id, "invalid_purpose")
                    return "invalid_purpose", None
                if purpose is not AttemptPurpose.INVITE_CODE_PRIVATE_ELIGIBLE:
                    return "not_eligible", None
                return "ok", self._admission_view(
                    attempt_id, purpose, attempt.admission, now, include_host_seen=True)
            terminal = self._terminal_client_locked(session_id, attempt_id, credential)
            if terminal is None:
                return "not_found", None
            purpose = self._purpose(terminal.purpose)
            if purpose is None:
                return "invalid_purpose", None
            return "ok", self._admission_view(
                attempt_id, purpose, terminal.admission, now, include_host_seen=True,
                terminal_reason=terminal.terminal_reason)

    def host_poll(
        self, session_id: str, acknowledged: list[dict[str, Any]],
    ) -> list[dict[str, Any]]:
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            for value in acknowledged:
                attempt_id = self._decode_128(value["attempt_id"])
                generation = self._decode_128(value["admission_generation"])
                if attempt_id is None or generation is None:
                    continue
                attempt = self._attempts.get(attempt_id)
                if attempt is None or attempt.session_id != session_id:
                    continue
                purpose = self._purpose(attempt.purpose)
                if purpose is None:
                    self._remove_attempt_locked(attempt_id, "invalid_purpose")
                    continue
                if purpose is not AttemptPurpose.INVITE_CODE_PRIVATE_ELIGIBLE:
                    continue
                admission = attempt.admission
                if (admission is None or now >= admission.expires_at or
                        admission.generation != generation or
                        admission.lease_revision != value["lease_revision"]):
                    continue
                admission.host_seen_generation = admission.generation
                admission.host_seen_revision = admission.lease_revision
                admission.host_seen_at = now
            return self._pending_locked(session_id, now)

    def _pending_locked(self, session_id: str, now: float) -> list[dict[str, Any]]:
        pending = []
        for key in list(self._by_session.get(session_id, set())):
            attempt = self._attempts.get(key)
            if attempt is None:
                continue
            value = self._public(key, attempt, 0, now=now)
            if value is None:
                self._remove_attempt_locked(key, "invalid_purpose")
                continue
            pending.append(value)
        if pending:
            print(f"NAT timing: host poll session={session_id} attempts="
                  f"{','.join(item['attempt_id'] for item in pending)}", flush=True)
        return pending

    def pending(self, session_id: str) -> list[dict[str, Any]]:
        return self.host_poll(session_id, [])

    def _terminate(
        self, session_id: str, attempt_text: str, credential_text: str, reason: str,
        *, require_admission: bool = False,
    ) -> str:
        attempt_id = self._decode_128(attempt_text)
        credential = self._decode_128(credential_text)
        if attempt_id is None or credential is None:
            return "not_found"
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            attempt = self._attempts.get(attempt_id)
            if attempt is None or attempt.session_id != session_id:
                return "not_found"
            purpose = self._purpose(attempt.purpose)
            if purpose is None:
                self._remove_attempt_locked(attempt_id, "invalid_purpose")
                return "invalid_purpose"
            if require_admission:
                if purpose is not AttemptPurpose.INVITE_CODE_PRIVATE_ELIGIBLE:
                    return "not_eligible"
                if attempt.admission is None:
                    return "not_ready"
            if not any(secrets.compare_digest(value, credential)
                       for value in attempt.credentials):
                return "not_found"
            self._remove_attempt_locked(attempt_id, reason)
            return reason

    def complete(self, session_id: str, attempt_text: str, credential_text: str) -> bool:
        return self._terminate(
            session_id, attempt_text, credential_text, "completed") == "completed"

    def revoke_admission(
        self, session_id: str, attempt_text: str, credential_text: str,
    ) -> str:
        status = self._terminate(
            session_id, attempt_text, credential_text, "revoked", require_admission=True)
        return "revoked" if status == "revoked" else status

    def remove_session(self, session_id: str) -> None:
        with self._lock:
            self.gameplay.remove_session(session_id)
            for key in list(self._by_session.get(session_id, set())):
                self._remove_attempt_locked(key, "session_removed")
            for key in self._terminal_by_session.pop(session_id, set()):
                self._terminal_attempts.pop(key, None)
            for request_id in self._request_ids_by_session.pop(session_id, set()):
                self._request_ids.pop(request_id, None)
            for key in [key for key in self._last_create if key[0] == session_id]:
                del self._last_create[key]

    def _public(self, attempt_id: bytes, attempt: RendezvousAttempt,
                participant: int, now: float | None = None) -> dict[str, Any] | None:
        purpose = self._purpose(attempt.purpose)
        if purpose is None:
            return None
        if now is None:
            now = self.clock()
        value = {
            "attempt_id": attempt_id.hex(),
            "capability": attempt.credentials[participant].hex(),
            "participant": "host" if participant == 0 else "client",
            "purpose": purpose.value,
            "expires_in": max(0, int(attempt.expires_at - now)),
            "rendezvous_host": self.rendezvous_host,
            "rendezvous_port": self.rendezvous_port,
        }
        if participant == 1 and attempt.request_id is not None:
            value["request_id"] = attempt.request_id
            value["rendezvous_expires_in_ms"] = max(
                0, int((attempt.expires_at - now) * 1000))
        if participant == 0 and attempt.admission is not None:
            value.update(self._admission_view(
                attempt_id, purpose, attempt.admission, now, include_host_seen=False))
        return value

    def gameplay_request(self, session, action, credential, payload):
        now = self.clock()
        with self._lock:
            self._expire_locked(now)
            if action == "sync":
                def attest(attempt_text, generation):
                    key = self._decode_128(attempt_text)
                    attempt = self._attempts.get(key) or self._terminal_attempts.get(key)
                    if (attempt is None or attempt.session_id != session or
                            self._purpose(attempt.purpose) is not AttemptPurpose.INVITE_CODE_PRIVATE_ELIGIBLE or
                            attempt.admission is None or attempt.admission.generation.hex() != generation or
                            attempt.admission.host_seen_generation != attempt.admission.generation or
                            attempt.admission.host_seen_revision != attempt.admission.lease_revision):
                        return None
                    # Only a live grant or its successful completion is a usable
                    # prerequisite. Host authentication (above) attests the actual
                    # roster commit; the client cannot manufacture that assertion.
                    if isinstance(attempt, TerminalAttempt) and attempt.terminal_reason != "completed":
                        return None
                    return attempt.credentials[1]
                result = self.gameplay.sync(session, payload, now, attest)
            else:
                result = self.gameplay.client(session, action, payload, credential, now)
            if result is not None:
                result["rendezvous_host"] = self.rendezvous_host
                result["rendezvous_port"] = self.rendezvous_port
            return result

    def register(
        self, attempt_id: bytes, credential: bytes, participant: int, role: int,
        source: tuple[str, int],
    ) -> tuple[tuple[str, int], tuple[str, int] | None] | None:
        if participant not in (0, 1) or role not in (0, 1):
            return None
        now = self.clock()
        key = (participant, role)
        with self._lock:
            self._expire_locked(now)
            if attempt_id in self.gameplay.links:
                return self.gameplay.register(attempt_id, credential, participant, role, source, now)
            attempt = self._attempts.get(attempt_id)
            if attempt is not None and self._purpose(attempt.purpose) is None:
                self._remove_attempt_locked(attempt_id, "invalid_purpose")
                return None
            if (attempt is None or attempt.completed or now >= attempt.expires_at or
                    not secrets.compare_digest(attempt.credentials[participant], credential)):
                return None
            if role == 1 and self._purpose(attempt.purpose) is AttemptPurpose.INVITE_CODE_PRIVATE_ELIGIBLE:
                return None  # Invite discovery capabilities never authorize gameplay sockets.
            previous = attempt.endpoint_seen.get(key)
            if previous is not None and now - previous < RENDEZVOUS_MIN_INTERVAL_SECONDS:
                return None
            previous_endpoint = attempt.endpoints.get(key)
            attempt.endpoints[key] = source
            attempt.endpoint_seen[key] = now
            peer = attempt.endpoints.get((1 - participant, role))
            print(f"NAT timing: register attempt={attempt_id.hex()} participant={participant} "
                  f"role={role} source={source[0]}:{source[1]} peer="
                  f"{peer[0] + ':' + str(peer[1]) if peer else 'pending'}", flush=True)
            if role == 1:
                response = attempt.responses.get(key)
                endpoint_changed = previous_endpoint != source
                peer_changed = response is None or response[2] != peer
                repeated_unpaired = (response is not None and not endpoint_changed and
                                      not peer_changed and peer is None)
                if repeated_unpaired:
                    print(f"NAT timing: response coalesced attempt={attempt_id.hex()} "
                          f"participant={participant} role={role} "
                          f"destination={source[0]}:{source[1]} peer=pending", flush=True)
                    return None
                attempt.responses[key] = (now, source, peer)
            return source, peer


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
            print(f"NAT timing: response attempt={attempt_id.hex()} participant={participant} "
                  f"role={role} destination={source[0]}:{source[1]} peer="
                  f"{peer[0]}:{peer[1]}", flush=True)

    def shutdown(self) -> None:
        self._stopping.set()
        self.socket.close()


def main() -> int:
    parser = argparse.ArgumentParser(description="HarmonyRecomp discovery-only session directory")
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=8080)
    parser.add_argument("--ttl", type=int, default=DEFAULT_TTL_SECONDS)
    parser.add_argument("--rendezvous-host", default="")
    parser.add_argument(
        "--rendezvous-public-host",
        default="",
        help="Public DNS name or address returned to traversal clients",
    )
    parser.add_argument("--rendezvous-port", type=int, default=30740)
    args = parser.parse_args()
    if (not 1 <= args.port <= 65535 or not 1 <= args.rendezvous_port <= 65535 or
            not 5 <= args.ttl <= 3600):
        parser.error("port or ttl is out of range")
    rendezvous_public_host = args.rendezvous_public_host or args.rendezvous_host
    if args.rendezvous_host in ("0.0.0.0", "::") and not args.rendezvous_public_host:
        parser.error("--rendezvous-public-host is required when binding a wildcard address")
    traversal = RendezvousRegistry(DEFAULT_ATTEMPT_TTL_SECONDS, rendezvous_host=rendezvous_public_host,
                                   rendezvous_port=args.rendezvous_port)
    sessions = SessionRegistry(args.ttl, on_remove=traversal.remove_session)
    server = DirectoryServer((args.host, args.port), sessions, traversal)
    rendezvous = None
    rendezvous_thread = None
    if args.rendezvous_host:
        rendezvous = RendezvousServer((args.rendezvous_host, args.rendezvous_port), traversal)
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
