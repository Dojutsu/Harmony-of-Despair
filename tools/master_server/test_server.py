from __future__ import annotations

import http.client
import json
import os
import socket
import threading
import unittest

from tools.master_server.server import (
    AuthenticationError, DirectoryServer, INVITE_CODE_ALPHABET, INVITE_CODE_LENGTH,
    InviteLookupLimiter,
    MAX_INVITE_LOOKUPS_PER_WINDOW, RENDEZVOUS_MAGIC, RENDEZVOUS_PACKET, RENDEZVOUS_REGISTER,
    RENDEZVOUS_REGISTERED, RENDEZVOUS_VERSION, RendezvousRegistry, RendezvousServer,
    SessionRegistry, ValidationError, observed_client_ip, validate_registration,
)


def payload(**updates):
    value = {
        "server_name": "DesktopHost",
        "player_count": 1,
        "max_players": 6,
        "title_id": "58410A7A",
        "protocol_version": 1,
        "build_id": "harmony-0.0.1.4-p1",
        "connectivity_candidates": [
            {
                "type": "tailscale",
                "address": "100.64.0.10",
                "discovery_port": 30741,
                "gameplay_port": 30742,
            }
        ],
    }
    value.update(updates)
    return value


class RegistryTests(unittest.TestCase):
    def test_invite_lookup_limiter_expires_and_bounds_source_state(self):
        now = [1000.0]
        limiter = InviteLookupLimiter(clock=lambda: now[0])
        for index in range(5000):
            self.assertTrue(limiter.allow(f"198.51.100.{index}"))
        self.assertLessEqual(len(limiter._sources), 4096)

        now[0] += 11.0
        self.assertTrue(limiter.allow("203.0.113.1"))
        self.assertEqual(1, len(limiter._sources))

    def test_invite_code_lifecycle_collision_and_case_insensitive_lookup(self):
        now = [1000.0]
        candidates = iter(["AB7K2Q", "AB7K2Q", "CD8M3R"])
        registry = SessionRegistry(45, lambda: now[0], invite_code_factory=lambda: next(candidates))
        first = registry.create(payload(
            host_instance_id="logical-host-1", host_instance_token="host-proof-1"))
        self.assertEqual(INVITE_CODE_LENGTH, len(first.invite_code))
        self.assertTrue(all(ch in INVITE_CODE_ALPHABET for ch in first.invite_code))
        self.assertEqual(first.session_id, registry.lookup_code("ab7k2q")["session_id"])

        replayed = registry.create(payload(
            host_instance_id="logical-host-1", host_instance_token="host-proof-1",
            player_count=2))
        self.assertEqual(first.invite_code, replayed.invite_code)
        self.assertEqual(first.invite_code, registry.heartbeat(
            first.session_id, first.registration_token, payload(player_count=3)).invite_code)

        second = registry.create(payload())
        self.assertEqual("CD8M3R", second.invite_code)
        self.assertNotEqual(first.invite_code, second.invite_code)
        self.assertTrue(registry.delete(first.session_id, first.registration_token))
        self.assertIsNone(registry.lookup_code(first.invite_code))
        self.assertEqual(second.session_id, registry.lookup_code(second.invite_code)["session_id"])

        now[0] += 46
        self.assertIsNone(registry.lookup_code(second.invite_code))
        self.assertEqual({}, registry._invite_codes)

    def test_proxy_observed_ipv4_requires_loopback_peer(self):
        self.assertEqual(
            "203.0.113.9", observed_client_ip("127.0.0.1", "198.51.100.2, 203.0.113.9"))
        self.assertEqual(
            "198.51.100.7", observed_client_ip("198.51.100.7", "203.0.113.9"))
        self.assertEqual("127.0.0.1", observed_client_ip("127.0.0.1", "not-an-address"))

    def test_create_filter_heartbeat_and_expire(self):
        now = [1000.0]
        registry = SessionRegistry(45, lambda: now[0])
        created = registry.create(payload())
        self.assertEqual(1, len(registry.list({"title_id": "58410a7a", "protocol_version": "1"})))
        now[0] += 20
        updated = payload(player_count=2)
        self.assertIsNotNone(registry.heartbeat(created.session_id, created.registration_token, updated))
        self.assertEqual(2, registry.list({})[0]["player_count"])
        now[0] += 46
        self.assertEqual([], registry.list({}))

    def test_token_protects_update_and_delete(self):
        registry = SessionRegistry()
        created = registry.create(payload())
        with self.assertRaises(AuthenticationError):
            registry.heartbeat(created.session_id, "wrong", payload())
        self.assertFalse(registry.delete(created.session_id, "wrong"))
        self.assertTrue(registry.delete(created.session_id, created.registration_token))

    def test_rejects_unsafe_or_oversized_metadata(self):
        with self.assertRaises(ValidationError):
            validate_registration(payload(server_name="x" * 49))
        with self.assertRaises(ValidationError):
            validate_registration(payload(player_count=7, max_players=6))
        with self.assertRaises(ValidationError):
            validate_registration(payload(title_id="not-hex"))
        with self.assertRaises(ValidationError):
            validate_registration(payload(build_id="unsafe query/value"))
        with self.assertRaises(ValidationError):
            validate_registration(payload(connectivity_candidates=[{
                "type": "direct", "address": "127.0.0.1", "discovery_port": 30741,
                "gameplay_port": 30742,
            }]))

    def test_public_candidate_uses_server_observed_address(self):
        registry = SessionRegistry()
        public = payload(connectivity_candidates=[{
            "type": "public", "address": "", "discovery_port": 30741,
            "gameplay_port": 30742,
        }])
        created = registry.create(public, "203.0.113.7")
        self.assertEqual("203.0.113.7", created.public()["connectivity_candidates"][0]["address"])

    def test_host_instance_registration_is_idempotent(self):
        registry = SessionRegistry()
        registration = payload(
            host_instance_id="logical-host-1",
            host_instance_token="host-proof-1",
        )
        created = registry.create(registration)
        replayed = registry.create({**registration, "player_count": 2})
        self.assertEqual(created.session_id, replayed.session_id)
        self.assertEqual(created.registration_token, replayed.registration_token)
        self.assertEqual(2, replayed.metadata["player_count"])
        self.assertEqual(1, len(registry.list({})))

    def test_host_instance_authentication_cannot_replace_another_host(self):
        registry = SessionRegistry()
        registry.create(payload(
            host_instance_id="logical-host-1",
            host_instance_token="host-proof-1",
        ))
        with self.assertRaises(AuthenticationError):
            registry.create(payload(
                host_instance_id="logical-host-1",
                host_instance_token="different-proof",
            ))
        self.assertEqual(1, len(registry.list({})))

    def test_expired_host_instance_recovers_as_one_new_authoritative_session(self):
        now = [1000.0]
        removed = []
        registry = SessionRegistry(45, lambda: now[0], removed.append)
        registration = payload(
            host_instance_id="logical-host-1",
            host_instance_token="host-proof-1",
        )
        old = registry.create(registration)
        now[0] += 46
        recovered = registry.create(registration)
        self.assertNotEqual(old.session_id, recovered.session_id)
        self.assertFalse(registry.exists(old.session_id))
        self.assertEqual([old.session_id], removed)
        self.assertEqual([recovered.session_id],
                         [value["session_id"] for value in registry.list({})])

    def test_different_host_instances_remain_independent(self):
        registry = SessionRegistry()
        first = registry.create(payload(
            host_instance_id="logical-host-1", host_instance_token="host-proof-1"))
        second = registry.create(payload(
            host_instance_id="logical-host-2", host_instance_token="host-proof-2"))
        self.assertNotEqual(first.session_id, second.session_id)
        self.assertEqual(2, len(registry.list({})))

    def test_host_leave_removes_identity_and_new_host_game_gets_new_lobby(self):
        registry = SessionRegistry()
        first = registry.create(payload(
            host_instance_id="logical-host-1", host_instance_token="host-proof-1"))
        self.assertTrue(registry.delete(first.session_id, first.registration_token))
        second = registry.create(payload(
            host_instance_id="logical-host-2", host_instance_token="host-proof-2"))
        self.assertNotEqual(first.session_id, second.session_id)
        self.assertEqual([second.session_id],
                         [value["session_id"] for value in registry.list({})])


class HttpTests(unittest.TestCase):
    def setUp(self):
        self.traversal = RendezvousRegistry(rendezvous_host="rendezvous.example", rendezvous_port=30740)
        self.registry = SessionRegistry(on_remove=self.traversal.remove_session)
        self.server = DirectoryServer(("127.0.0.1", 0), self.registry, self.traversal)
        self.thread = threading.Thread(target=self.server.serve_forever, daemon=True)
        self.thread.start()

    def tearDown(self):
        self.server.shutdown()
        self.server.server_close()
        self.thread.join()

    def request(self, method, path, body=None, token=None):
        connection = http.client.HTTPConnection("127.0.0.1", self.server.server_port)
        headers = {"Content-Type": "application/json"}
        if token:
            headers["Authorization"] = f"Bearer {token}"
        encoded = json.dumps(body) if body is not None else None
        connection.request(method, path, encoded, headers)
        response = connection.getresponse()
        data = response.read()
        return response.status, json.loads(data) if data else None

    def test_full_http_lifecycle(self):
        status, created = self.request("POST", "/sessions", payload())
        self.assertEqual(201, status)
        self.assertEqual(INVITE_CODE_LENGTH, len(created["invite_code"]))
        status, listed = self.request(
            "GET", "/sessions?title_id=58410A7A&protocol_version=1&build_id=harmony-0.0.1.4-p1"
        )
        self.assertEqual(200, status)
        self.assertEqual(created["session_id"], listed["sessions"][0]["session_id"])
        status, _ = self.request(
            "POST", f"/sessions/{created['session_id']}/heartbeat", payload(player_count=2),
            created["registration_token"],
        )
        self.assertEqual(200, status)
        status, _ = self.request(
            "DELETE", f"/sessions/{created['session_id']}", token=created["registration_token"]
        )
        self.assertEqual(204, status)

    def test_invite_lookup_returns_only_public_session_data(self):
        status, created = self.request("POST", "/sessions", payload())
        self.assertEqual(201, status)
        status, resolved = self.request(
            "GET", f"/sessions/by-code/{created['invite_code'].lower()}")
        self.assertEqual(200, status)
        self.assertEqual(created["session_id"], resolved["session"]["session_id"])
        for secret in ("registration_token", "host_instance_id", "host_instance_token",
                       "invite_code"):
            self.assertNotIn(secret, resolved["session"])

        status, _ = self.request("GET", "/sessions/by-code/BAD")
        self.assertEqual(404, status)
        status, _ = self.request("GET", "/sessions/by-code/AAAAAA")
        self.assertEqual(404, status)

        status, _ = self.request(
            "DELETE", f"/sessions/{created['session_id']}", token=created["registration_token"])
        self.assertEqual(204, status)
        status, _ = self.request("GET", f"/sessions/by-code/{created['invite_code']}")
        self.assertEqual(404, status)

    def test_invite_lookup_rate_limit_is_per_source_and_bounded(self):
        _, created = self.request("POST", "/sessions", payload())
        path = f"/sessions/by-code/{created['invite_code']}"
        for _ in range(MAX_INVITE_LOOKUPS_PER_WINDOW):
            status, _ = self.request("GET", path)
            self.assertEqual(200, status)
        status, _ = self.request("GET", path)
        self.assertEqual(429, status)

    def test_heartbeat_distinguishes_missing_session_from_bad_token(self):
        status, created = self.request("POST", "/sessions", payload())
        self.assertEqual(201, status)

        status, _ = self.request(
            "POST", f"/sessions/{created['session_id']}/heartbeat", payload(), "wrong-token"
        )
        self.assertEqual(403, status)
        status, _ = self.request(
            "POST", "/sessions/missing/heartbeat", payload(), created["registration_token"]
        )
        self.assertEqual(404, status)

        status, listed = self.request("GET", "/sessions")
        self.assertEqual(200, status)
        self.assertEqual([created["session_id"]],
                         [value["session_id"] for value in listed["sessions"]])

    def test_secure_join_attempt_lifecycle(self):
        status, created = self.request("POST", "/sessions", payload())
        self.assertEqual(201, status)
        path = f"/sessions/{created['session_id']}/join-attempts"
        status, client = self.request("POST", path, {})
        self.assertEqual(201, status)
        self.assertEqual("client", client["participant"])
        self.assertNotIn("host_capability", client)
        self.assertEqual("rendezvous.example", client["rendezvous_host"])
        status, _ = self.request("GET", path, token="wrong")
        self.assertEqual(404, status)
        status, pending = self.request("GET", path, token=created["registration_token"])
        self.assertEqual(200, status)
        self.assertEqual(1, len(pending["attempts"]))
        host = pending["attempts"][0]
        self.assertEqual("host", host["participant"])
        self.assertEqual(client["attempt_id"], host["attempt_id"])
        self.assertNotEqual(client["capability"], host["capability"])
        status, _ = self.request(
            "DELETE", f"{path}/{client['attempt_id']}", token=client["capability"])
        self.assertEqual(204, status)
        status, _ = self.request(
            "DELETE", f"{path}/{client['attempt_id']}", token=client["capability"])
        self.assertEqual(404, status)

    def test_session_delete_removes_join_attempts(self):
        status, created = self.request("POST", "/sessions", payload())
        path = f"/sessions/{created['session_id']}/join-attempts"
        status, client = self.request("POST", path, {})
        self.assertEqual(201, status)
        status, _ = self.request(
            "DELETE", f"/sessions/{created['session_id']}", token=created["registration_token"])
        self.assertEqual(204, status)
        self.assertIsNone(self.traversal.register(
            bytes.fromhex(client["attempt_id"]), bytes.fromhex(client["capability"]),
            1, 0, ("127.0.0.1", 40000)))

    def test_join_attempt_requires_configured_rendezvous(self):
        self.server.traversal.rendezvous_host = ""
        status, created = self.request("POST", "/sessions", payload())
        status, response = self.request(
            "POST", f"/sessions/{created['session_id']}/join-attempts", {})
        self.assertEqual(503, status)
        self.assertEqual("public traversal is unavailable", response["error"])

    def test_replayed_registration_returns_one_authoritative_lobby(self):
        registration = payload(
            host_instance_id="logical-host-1",
            host_instance_token="host-proof-1",
        )
        first_status, first = self.request("POST", "/sessions", registration)
        second_status, second = self.request(
            "POST", "/sessions", {**registration, "player_count": 2})
        self.assertEqual(201, first_status)
        self.assertEqual(201, second_status)
        self.assertEqual(first, second)
        status, listed = self.request("GET", "/sessions")
        self.assertEqual(200, status)
        self.assertEqual(1, len(listed["sessions"]))
        self.assertEqual(2, listed["sessions"][0]["player_count"])
        self.assertNotIn("host_instance_id", listed["sessions"][0])
        self.assertNotIn("host_instance_token", listed["sessions"][0])

    def test_wrong_host_instance_proof_is_rejected_without_duplicate(self):
        registration = payload(
            host_instance_id="logical-host-1",
            host_instance_token="host-proof-1",
        )
        self.request("POST", "/sessions", registration)
        status, _ = self.request(
            "POST", "/sessions", {**registration, "host_instance_token": "wrong-proof"})
        self.assertEqual(403, status)
        _, listed = self.request("GET", "/sessions")
        self.assertEqual(1, len(listed["sessions"]))

    def test_expired_lobby_is_not_searchable_and_cannot_issue_attempt(self):
        now = [1000.0]
        self.registry.ttl_seconds = 45
        self.registry.clock = lambda: now[0]
        registration = payload(
            host_instance_id="logical-host-1",
            host_instance_token="host-proof-1",
        )
        _, old = self.request("POST", "/sessions", registration)
        old_attempt_path = f"/sessions/{old['session_id']}/join-attempts"
        status, issued = self.request("POST", old_attempt_path, {})
        self.assertEqual(201, status)

        now[0] += 46
        _, recovered = self.request("POST", "/sessions", registration)
        self.assertNotEqual(old["session_id"], recovered["session_id"])
        status, listed = self.request("GET", "/sessions")
        self.assertEqual([recovered["session_id"]],
                         [value["session_id"] for value in listed["sessions"]])
        status, _ = self.request("POST", old_attempt_path, {})
        self.assertEqual(404, status)
        self.assertIsNone(self.traversal.register(
            bytes.fromhex(issued["attempt_id"]), bytes.fromhex(issued["capability"]),
            1, 0, ("127.0.0.1", 40000)))


class RendezvousTests(unittest.TestCase):
    def setUp(self):
        self.registry = RendezvousRegistry()
        issued = self.registry.issue("session")
        self.attempt_id = bytes.fromhex(issued["attempt_id"])
        self.client_credential = bytes.fromhex(issued["capability"])
        self.host_credential = bytes.fromhex(self.registry.pending("session")[0]["capability"])
        self.server = RendezvousServer(("127.0.0.1", 0), self.registry)
        self.thread = threading.Thread(target=self.server.serve_forever, daemon=True)
        self.thread.start()

    def tearDown(self):
        self.server.shutdown()
        self.thread.join()

    @staticmethod
    def packet(attempt_id, credential, participant, role):
        return RENDEZVOUS_PACKET.pack(
            RENDEZVOUS_MAGIC, RENDEZVOUS_VERSION, RENDEZVOUS_REGISTER,
            participant, role, attempt_id, credential,
            b"\0" * 4, 0, b"\0" * 4, 0,
        )

    def register(self, client, attempt_id, credential, participant, role):
        client.sendto(self.packet(attempt_id, credential, participant, role), self.server.address)
        response, _ = client.recvfrom(RENDEZVOUS_PACKET.size)
        return RENDEZVOUS_PACKET.unpack(response)

    def test_pairs_only_matching_attempt_credentials_and_roles(self):
        host = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        host.bind(("127.0.0.1", 0))
        client.bind(("127.0.0.1", 0))
        host.settimeout(1)
        client.settimeout(1)
        first = self.register(host, self.attempt_id, self.host_credential, 0, 0)
        self.assertEqual(RENDEZVOUS_REGISTERED, first[2])
        self.assertEqual(0, first[10])
        second = self.register(client, self.attempt_id, self.client_credential, 1, 0)
        self.assertEqual(host.getsockname()[1], second[10])
        # Re-registering returns the peer without sending anything to that peer.
        threading.Event().wait(0.11)
        paired = self.register(host, self.attempt_id, self.host_credential, 0, 0)
        self.assertEqual(client.getsockname()[1], paired[10])
        host.close()
        client.close()

    def test_rejects_wrong_credential_and_malformed_packets_without_reply(self):
        good = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        bad = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        good.settimeout(1)
        bad.settimeout(0.2)
        self.register(good, self.attempt_id, self.host_credential, 0, 1)
        bad.sendto(self.packet(self.attempt_id, os.urandom(16), 1, 1), self.server.address)
        with self.assertRaises(TimeoutError):
            bad.recvfrom(RENDEZVOUS_PACKET.size)
        bad.sendto(b"short", self.server.address)
        with self.assertRaises(TimeoutError):
            bad.recvfrom(RENDEZVOUS_PACKET.size)
        good.close()
        bad.close()

    def test_gameplay_server_suppresses_stale_unpaired_reply_but_pairs_immediately(self):
        host = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        host.bind(("127.0.0.1", 0))
        client.bind(("127.0.0.1", 0))
        host.settimeout(1)
        client.settimeout(1)

        first = self.register(host, self.attempt_id, self.host_credential, 0, 1)
        self.assertEqual(0, first[10])
        threading.Event().wait(0.11)
        host.sendto(
            self.packet(self.attempt_id, self.host_credential, 0, 1), self.server.address)
        host.settimeout(0.2)
        with self.assertRaises(TimeoutError):
            host.recvfrom(RENDEZVOUS_PACKET.size)

        paired_client = self.register(
            client, self.attempt_id, self.client_credential, 1, 1)
        self.assertEqual(host.getsockname()[1], paired_client[10])
        threading.Event().wait(0.11)
        host.settimeout(1)
        paired_host = self.register(host, self.attempt_id, self.host_credential, 0, 1)
        self.assertEqual(client.getsockname()[1], paired_host[10])
        host.close()
        client.close()


class TraversalRegistryTests(unittest.TestCase):
    def test_gameplay_unpaired_responses_are_coalesced_until_pairing(self):
        now = [10.0]
        registry = RendezvousRegistry(20, lambda: now[0])
        client = registry.issue("session", "client")
        host = registry.pending("session")[0]
        attempt = bytes.fromhex(client["attempt_id"])
        host_credential = bytes.fromhex(host["capability"])
        client_credential = bytes.fromhex(client["capability"])
        host_source = ("198.51.100.10", 41000)
        client_source = ("203.0.113.20", 42000)

        first = registry.register(attempt, host_credential, 0, 1, host_source)
        self.assertEqual((host_source, None), first)
        for _ in range(8):
            now[0] += 0.11
            self.assertIsNone(
                registry.register(attempt, host_credential, 0, 1, host_source))
        now[0] += 1.13
        self.assertIsNone(
            registry.register(attempt, host_credential, 0, 1, host_source))

        now[0] += 0.11
        client_result = registry.register(
            attempt, client_credential, 1, 1, client_source)
        self.assertEqual((client_source, host_source), client_result)
        now[0] += 0.11
        host_result = registry.register(attempt, host_credential, 0, 1, host_source)
        self.assertEqual((host_source, client_source), host_result)
        now[0] += 0.11
        self.assertEqual(
            (host_source, client_source),
            registry.register(attempt, host_credential, 0, 1, host_source),
        )

    def test_gameplay_endpoint_change_and_attempt_state_are_isolated(self):
        now = [20.0]
        registry = RendezvousRegistry(20, lambda: now[0])
        first = registry.issue("session", "first")
        first_host = registry.pending("session")[0]
        first_attempt = bytes.fromhex(first["attempt_id"])
        first_credential = bytes.fromhex(first_host["capability"])
        source = ("198.51.100.10", 41000)
        changed = ("198.51.100.10", 41001)

        self.assertIsNotNone(
            registry.register(first_attempt, first_credential, 0, 1, source))
        now[0] += 0.11
        self.assertIsNone(
            registry.register(first_attempt, first_credential, 0, 1, source))
        now[0] += 0.11
        self.assertEqual(
            (changed, None),
            registry.register(first_attempt, first_credential, 0, 1, changed),
        )

        now[0] += 0.3
        second = registry.issue("session", "second")
        second_host = next(
            value for value in registry.pending("session")
            if value["attempt_id"] == second["attempt_id"])
        second_attempt = bytes.fromhex(second["attempt_id"])
        self.assertEqual(
            (source, None),
            registry.register(second_attempt, bytes.fromhex(second_host["capability"]),
                              0, 1, source),
        )

    def test_discovery_responses_remain_immediate_and_attempt_cleanup_removes_state(self):
        now = [30.0]
        registry = RendezvousRegistry(2, lambda: now[0])
        client = registry.issue("session", "client")
        host = registry.pending("session")[0]
        attempt = bytes.fromhex(client["attempt_id"])
        credential = bytes.fromhex(host["capability"])
        source = ("198.51.100.10", 41000)

        self.assertEqual((source, None), registry.register(attempt, credential, 0, 0, source))
        now[0] += 0.11
        self.assertEqual((source, None), registry.register(attempt, credential, 0, 0, source))
        registry.remove_session("session")
        now[0] += 0.11
        self.assertIsNone(registry.register(attempt, credential, 0, 1, source))

    def test_expiry_wrong_role_and_session_isolation(self):
        now = [10.0]
        registry = RendezvousRegistry(20, lambda: now[0])
        client = registry.issue("one", "client")
        host = registry.pending("one")[0]
        attempt = bytes.fromhex(client["attempt_id"])
        self.assertIsNone(registry.register(attempt, bytes.fromhex(client["capability"]),
                                            0, 0, ("127.0.0.1", 1)))
        self.assertIsNotNone(registry.register(attempt, bytes.fromhex(host["capability"]),
                                               0, 0, ("127.0.0.1", 1)))
        self.assertFalse(registry.complete("two", client["attempt_id"], client["capability"]))
        now[0] += 21
        self.assertIsNone(registry.register(attempt, bytes.fromhex(client["capability"]),
                                            1, 0, ("127.0.0.1", 2)))

    def test_multiple_clients_are_isolated_and_capped(self):
        now = [10.0]
        registry = RendezvousRegistry(20, lambda: now[0])
        attempts = []
        for index in range(8):
            attempts.append(registry.issue("session", f"client-{index}"))
        self.assertTrue(all(attempts))
        self.assertEqual(8, len({value["attempt_id"] for value in attempts}))
        self.assertIsNone(registry.issue("session", "overflow"))

    def test_rate_limit_and_session_removal(self):
        now = [10.0]
        registry = RendezvousRegistry(20, lambda: now[0])
        first = registry.issue("session", "same-client")
        self.assertIsNotNone(first)
        self.assertIsNone(registry.issue("session", "same-client"))
        now[0] += 0.3
        self.assertIsNotNone(registry.issue("session", "same-client"))
        registry.remove_session("session")
        self.assertEqual([], registry.pending("session"))


if __name__ == "__main__":
    unittest.main()
