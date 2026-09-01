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
    SessionRegistry, ValidationError, validate_registration,
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


class HttpTests(unittest.TestCase):
    def setUp(self):
        self.server = DirectoryServer(("127.0.0.1", 0), SessionRegistry())
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


class RendezvousTests(unittest.TestCase):
    def setUp(self):
        self.server = RendezvousServer(("127.0.0.1", 0), RendezvousRegistry())
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
        attempt_id = os.urandom(16)
        credential = os.urandom(16)
        host = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        host.bind(("127.0.0.1", 0))
        client.bind(("127.0.0.1", 0))
        host.settimeout(1)
        client.settimeout(1)
        first = self.register(host, attempt_id, credential, 0, 0)
        self.assertEqual(RENDEZVOUS_REGISTERED, first[2])
        self.assertEqual(0, first[10])
        second = self.register(client, attempt_id, credential, 1, 0)
        self.assertEqual(host.getsockname()[1], second[10])
        # Re-registering returns the peer without sending anything to that peer.
        threading.Event().wait(0.11)
        paired = self.register(host, attempt_id, credential, 0, 0)
        self.assertEqual(client.getsockname()[1], paired[10])
        host.close()
        client.close()

    def test_rejects_wrong_credential_and_malformed_packets_without_reply(self):
        attempt_id = os.urandom(16)
        credential = os.urandom(16)
        good = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        bad = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        good.settimeout(1)
        bad.settimeout(0.2)
        self.register(good, attempt_id, credential, 0, 1)
        bad.sendto(self.packet(attempt_id, os.urandom(16), 1, 1), self.server.address)
        with self.assertRaises(TimeoutError):
            bad.recvfrom(RENDEZVOUS_PACKET.size)
        bad.sendto(b"short", self.server.address)
        with self.assertRaises(TimeoutError):
            bad.recvfrom(RENDEZVOUS_PACKET.size)
        good.close()
        bad.close()


if __name__ == "__main__":
    unittest.main()
