from __future__ import annotations

import http.client
import json
import os
import socket
import threading
import unittest

from tools.master_server.server import (
    DirectoryServer, RENDEZVOUS_MAGIC, RENDEZVOUS_PACKET, RENDEZVOUS_REGISTER,
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
        self.assertIsNone(registry.heartbeat(created.session_id, "wrong", payload()))
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
