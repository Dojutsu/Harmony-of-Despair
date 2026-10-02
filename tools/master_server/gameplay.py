"""Admission-derived gameplay rendezvous. All calls hold the traversal lock.

The authenticated host attests committed membership; this does not authenticate
external XUID ownership. Discovery capabilities can claim only the corresponding
admission's fresh member credential, never another member or a new membership.
"""
from __future__ import annotations

from dataclasses import dataclass, field
import ipaddress
import secrets


class GameplayError(ValueError):
    pass


def hex_id(value, size):
    if (not isinstance(value, str) or len(value) != size or
            any(c not in "0123456789abcdef" for c in value) or int(value, 16) == 0):
        raise GameplayError("invalid gameplay identity")
    return value


def validate_sync(payload):
    if not isinstance(payload, dict) or set(payload) != {"xbox_session", "host_xuid", "members"}:
        raise GameplayError("invalid gameplay membership snapshot")
    xbox = hex_id(payload["xbox_session"], 16)
    host = hex_id(payload["host_xuid"], 16)
    members = payload["members"]
    if not isinstance(members, list) or len(members) > 5:
        raise GameplayError("invalid gameplay member count")
    seen_xuids, seen_attempts = {host}, set()
    normalized = []
    for member in members:
        if not isinstance(member, dict) or set(member) != {"xuid", "attempt_id", "admission_generation"}:
            raise GameplayError("invalid gameplay member")
        xuid = hex_id(member["xuid"], 16)
        attempt = hex_id(member["attempt_id"], 32)
        generation = hex_id(member["admission_generation"], 32)
        if xuid in seen_xuids or attempt in seen_attempts:
            raise GameplayError("duplicate gameplay membership")
        seen_xuids.add(xuid)
        seen_attempts.add(attempt)
        normalized.append((xuid, attempt, generation))
    return xbox, host, normalized


@dataclass
class Member:
    xuid: str
    attempt: str
    generation: str
    claim_capability: bytes
    logical_ipv4: str
    nonce: str = field(default_factory=lambda: secrets.token_hex(16))
    capability: str = field(default_factory=lambda: secrets.token_hex(16))
    endpoint: tuple[str, int] | None = None
    expires_at: float = 0


@dataclass
class Link:
    members: tuple[Member, Member]
    credentials: tuple[bytes, bytes] = field(default_factory=lambda: (secrets.token_bytes(16), secrets.token_bytes(16)))
    last_seen: dict[int, float] = field(default_factory=dict)


@dataclass
class Group:
    xbox_session: str
    host_xuid: str
    expires_at: float
    members: dict[str, Member] = field(default_factory=dict)
    retired: set[tuple[str, str]] = field(default_factory=set)
    links: dict[bytes, Link] = field(default_factory=dict)


class GameplayRegistry:
    def __init__(self, lease_seconds=45):
        self.lease_seconds = lease_seconds
        self.groups: dict[str, Group] = {}
        self.links: dict[bytes, tuple[str, Link]] = {}
        self.next_address = 1

    def _member(self, xuid, attempt="", generation="", capability=b""):
        # Process-wide non-recycled guest addresses. These never leave as native
        # destinations: the runtime must translate them through an exact link.
        if self.next_address >= 0x00ffffff:
            raise GameplayError("gameplay address space exhausted")
        address = str(ipaddress.IPv4Address(0xf0000000 + self.next_address))
        self.next_address += 1
        return Member(xuid, attempt, generation, capability, address)

    def remove_session(self, session):
        group = self.groups.pop(session, None)
        if group:
            for key in group.links:
                self.links.pop(key, None)

    def _retire(self, session, group, xuid):
        member = group.members.pop(xuid)
        if member.attempt:
            group.retired.add((member.attempt, member.generation))
        for key, link in list(group.links.items()):
            if member in link.members:
                del group.links[key]
                self.links.pop(key, None)
        print(f"GAMEPLAY_REVOKED session={session} xuid={xuid} admission={member.generation}", flush=True)

    def expire(self, now):
        # Preserve retired-admission tombstones until the directory session ends.
        # Expiry may not reauthorize the same membership on a delayed host sync.
        for session, group in self.groups.items():
            for xuid, member in list(group.members.items()):
                if xuid != group.host_xuid and (now >= group.expires_at or now >= member.expires_at):
                    self._retire(session, group, xuid)

    def sync(self, session, payload, now, attest):
        xbox, host, requested = validate_sync(payload)
        self.expire(now)
        group = self.groups.get(session)
        if group and (group.xbox_session != xbox or group.host_xuid != host):
            raise GameplayError("hosted Xbox session changed")
        # Validate the entire update before mutating any other member's state.
        proofs = {}
        for xuid, attempt, generation in requested:
            old = group.members.get(xuid) if group else None
            if old and (old.attempt, old.generation) == (attempt, generation):
                continue
            if group and (attempt, generation) in group.retired:
                continue
            proof = attest(attempt, generation)
            if proof is None:
                raise GameplayError("member has no committed-admission prerequisite")
            proofs[(attempt, generation)] = proof
        if group is None:
            group = Group(xbox, host, now + self.lease_seconds)
            group.members[host] = self._member(host)
            self.groups[session] = group
        wanted = {xuid: (attempt, generation) for xuid, attempt, generation in requested}
        for xuid, member in list(group.members.items()):
            if xuid != host and wanted.get(xuid) != (member.attempt, member.generation):
                self._retire(session, group, xuid)
        for xuid, attempt, generation in requested:
            if xuid in group.members or (attempt, generation) in group.retired:
                continue
            if any(m.attempt == attempt for m in group.members.values()):
                raise GameplayError("admission already assigned")
            member = self._member(xuid, attempt, generation, proofs[(attempt, generation)])
            member.expires_at = now + self.lease_seconds
            for peer in group.members.values():
                key = secrets.token_bytes(16)
                while key in self.links:
                    key = secrets.token_bytes(16)
                link = Link((peer, member))
                group.links[key] = link
                self.links[key] = (session, link)
            group.members[xuid] = member
            print(f"GAMEPLAY_AUTHORIZED session={session} xbox_session={xbox} xuid={xuid} admission={generation}", flush=True)
        group.expires_at = now + self.lease_seconds
        return self.view(session, group, group.members[host], now)

    def view(self, session, group, member, now):
        links = []
        for key, link in group.links.items():
            if member not in link.members:
                continue
            index = 0 if link.members[0] is member else 1
            peer = link.members[1-index]
            links.append(dict(attempt_id=key.hex(), capability=link.credentials[index].hex(),
                participant=index, peer_xuid=peer.xuid, peer_nonce=peer.nonce,
                peer_logical_ipv4=peer.logical_ipv4, peer_attempt_id=peer.attempt,
                peer_admission_generation=peer.generation))
        return dict(session_id=session, xbox_session=group.xbox_session,
            host_xuid=group.host_xuid, xuid=member.xuid, attempt_id=member.attempt,
            admission_generation=member.generation, member_nonce=member.nonce,
            member_capability=member.capability, logical_ipv4=member.logical_ipv4,
            expires_in_ms=max(0, int(((min(group.expires_at, member.expires_at)
                if member.attempt else group.expires_at)-now)*1000)), links=links,
            role="gameplay", protocol_version=1)

    def client(self, session, action, payload, credential, now):
        if not isinstance(payload, dict):
            raise GameplayError("invalid gameplay request")
        expected = {"xbox_session", "xuid", "attempt_id", "admission_generation"}
        if action != "claim":
            expected.add("member_nonce")
        if set(payload) != expected:
            raise GameplayError("invalid gameplay request fields")
        for key in expected:
            hex_id(payload[key], 16 if key in ("xbox_session", "xuid") else 32)
        if not isinstance(credential, str):
            return None
        self.expire(now)
        group = self.groups.get(session)
        member = group.members.get(payload["xuid"]) if group else None
        if (not group or now >= group.expires_at or not member or not member.attempt or
                group.xbox_session != payload["xbox_session"] or
                member.attempt != payload["attempt_id"] or
                member.generation != payload["admission_generation"]):
            return None
        if action == "claim":
            try:
                supplied = bytes.fromhex(credential)
            except (ValueError, TypeError):
                return None
            if not secrets.compare_digest(member.claim_capability, supplied):
                return None
        elif (member.nonce != payload["member_nonce"] or
              not secrets.compare_digest(member.capability, credential)):
            return None
        if action == "revoke":
            self._retire(session, group, member.xuid)
            return {"revoked": True}
        member.expires_at = now + self.lease_seconds
        return self.view(session, group, member, now)

    def register(self, key, credential, participant, role, source, now):
        self.expire(now)
        entry = self.links.get(key)
        if not entry or participant not in (0, 1) or role != 1:
            return None
        session, link = entry
        group = self.groups[session]
        if now >= group.expires_at or not secrets.compare_digest(link.credentials[participant], credential):
            return None
        member, peer = link.members[participant], link.members[1-participant]
        # Pin one independently observed gameplay mapping per admitted socket.
        # A copied capability cannot silently move it to a second source socket.
        if member.endpoint is not None and member.endpoint != source:
            return None
        if participant in link.last_seen and now-link.last_seen[participant] < .05:
            return None
        link.last_seen[participant] = now
        first = member.endpoint is None
        member.endpoint = source
        if member.attempt:
            member.expires_at = now + self.lease_seconds
        if first:
            print(f"GAMEPLAY_MAPPING session={session} xuid={member.xuid} admission={member.generation} role=gameplay endpoint={source[0]}:{source[1]}", flush=True)
        return source, peer.endpoint
