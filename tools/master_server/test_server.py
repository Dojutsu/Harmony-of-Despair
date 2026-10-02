from __future__ import annotations

import http.client
import json
import os
import socket
import threading
import unittest

from tools.master_server.server import (
    AttemptPhase, AttemptPurpose, AuthenticationError, DirectoryServer, INVITE_CODE_ALPHABET,
    INVITE_CODE_LENGTH,
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


def attempt_payload(request_id="00112233445566778899aabbccddeeff", **updates):
    value = {
        "request_id": request_id,
        "title_id": "58410A7A",
        "protocol_version": 1,
        "build_id": "harmony-0.0.1.4-p1",
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


class PhaseOneRegistryTests(unittest.TestCase):
    def make_registries(self):
        now = [1000.0]
        traversal = RendezvousRegistry(
            20, lambda: now[0], rendezvous_host="rendezvous.example")
        registry = SessionRegistry(45, lambda: now[0], traversal.remove_session)
        session = registry.create(payload())
        return now, registry, traversal, session

    def issue(self, registry, traversal, session, request=None, source="client"):
        return registry.issue_by_code_attempt(
            session.invite_code,
            attempt_payload(**(request or {})),
            traversal,
            source,
        )

    def test_live_replay_is_idempotent_and_does_not_extend_expiry(self):
        now, registry, traversal, session = self.make_registries()
        first_status, _, first = self.issue(registry, traversal, session)
        attempt_id = bytes.fromhex(first["attempt_id"])
        self.assertEqual(1000.0, traversal._attempts[attempt_id].issued_at)
        original_expiry = traversal._attempts[attempt_id].expires_at
        now[0] += 7.25
        replay_status, _, replay = self.issue(registry, traversal, session)

        self.assertEqual("created", first_status)
        self.assertEqual("replayed", replay_status)
        self.assertEqual(first["attempt_id"], replay["attempt_id"])
        self.assertEqual(first["capability"], replay["capability"])
        self.assertEqual(original_expiry, traversal._attempts[attempt_id].expires_at)
        self.assertLess(replay["rendezvous_expires_in_ms"],
                        first["rendezvous_expires_in_ms"])
        self.assertEqual(1, len(traversal._attempts))

    def test_expired_attempt_retains_terminal_tombstone_until_session_cleanup(self):
        now, registry, traversal, session = self.make_registries()
        _, _, first = self.issue(registry, traversal, session)
        now[0] += 21
        status, _, replay = self.issue(registry, traversal, session)
        self.assertEqual("terminal", status)
        self.assertIsNone(replay)
        request = traversal._request_ids[attempt_payload()["request_id"]]
        self.assertEqual("expired", request.terminal_reason)
        self.assertTrue(registry.delete(session.session_id, session.registration_token))
        self.assertEqual({}, traversal._request_ids)

    def test_terminal_tombstone_blocks_replay_but_new_request_id_can_issue(self):
        now, registry, traversal, session = self.make_registries()
        _, _, first = self.issue(registry, traversal, session)
        self.assertTrue(traversal.complete(
            session.session_id, first["attempt_id"], first["capability"]))

        terminal_status, _, terminal = self.issue(registry, traversal, session)
        self.assertEqual("terminal", terminal_status)
        self.assertIsNone(terminal)
        now[0] += 0.3
        new_status, _, new_attempt = self.issue(
            registry, traversal, session,
            {"request_id": "ffeeddccbbaa99887766554433221100"})
        self.assertEqual("created", new_status)
        self.assertNotEqual(first["attempt_id"], new_attempt["attempt_id"])

    def test_conflicting_fingerprint_cannot_redirect_request_id(self):
        _, registry, traversal, first_session = self.make_registries()
        second_session = registry.create(payload())
        first_status, _, first = self.issue(registry, traversal, first_session)
        self.assertEqual("created", first_status)

        cases = [
            (first_session, {"title_id": "12345678"}),
            (first_session, {"protocol_version": 2}),
            (first_session, {"build_id": "different-build"}),
            (second_session, {}),
        ]
        for target, changes in cases:
            with self.subTest(changes=changes, code=target.invite_code):
                status, _, attempt = self.issue(
                    registry, traversal, target, changes, source="other-client")
                self.assertEqual("conflict", status)
                self.assertIsNone(attempt)
        self.assertEqual({first["attempt_id"]},
                         {key.hex() for key in traversal._attempts})

    def test_session_cleanup_removes_attempts_capabilities_and_request_state(self):
        _, registry, traversal, session = self.make_registries()
        _, _, attempt = self.issue(registry, traversal, session)
        self.assertTrue(traversal._request_ids)
        self.assertTrue(registry.delete(session.session_id, session.registration_token))
        self.assertEqual({}, traversal._attempts)
        self.assertEqual({}, traversal._by_session)
        self.assertEqual({}, traversal._request_ids)
        self.assertEqual({}, traversal._request_ids_by_session)
        self.assertFalse(traversal.complete(
            session.session_id, attempt["attempt_id"], attempt["capability"]))

    def test_session_expiry_removes_active_and_terminal_by_code_state(self):
        now, registry, traversal, session = self.make_registries()
        _, _, completed = self.issue(registry, traversal, session, source="completed")
        _, _, active = self.issue(
            registry, traversal, session,
            {"request_id": "ffeeddccbbaa99887766554433221100"},
            source="active",
        )
        self.assertTrue(traversal.complete(
            session.session_id, completed["attempt_id"], completed["capability"]))
        self.assertEqual(
            "completed",
            traversal._request_ids[completed["request_id"]].terminal_reason,
        )
        self.assertIn(bytes.fromhex(active["attempt_id"]), traversal._attempts)

        now[0] += 46
        self.assertIsNone(registry.lookup_code(session.invite_code))
        self.assertEqual({}, traversal._attempts)
        self.assertEqual({}, traversal._by_session)
        self.assertEqual({}, traversal._request_ids)
        self.assertEqual({}, traversal._request_ids_by_session)
        self.assertFalse(any(key[0] == session.session_id for key in traversal._last_create))
        self.assertIsNone(traversal.register(
            bytes.fromhex(active["attempt_id"]), bytes.fromhex(active["capability"]),
            1, 0, ("198.51.100.10", 41000),
        ))
        status, _, replay = self.issue(registry, traversal, session)
        self.assertEqual("not_found", status)
        self.assertIsNone(replay)

    def test_unknown_internal_purpose_fails_closed(self):
        _, registry, traversal, session = self.make_registries()
        _, _, client = self.issue(registry, traversal, session)
        attempt_id = bytes.fromhex(client["attempt_id"])
        traversal._attempts[attempt_id].purpose = "future_private"  # type: ignore[assignment]
        self.assertIsNone(traversal.register(
            attempt_id, bytes.fromhex(client["capability"]), 1, 0,
            ("198.51.100.10", 41000),
        ))
        self.assertEqual([], traversal.pending(session.session_id))
        status, _, replay = self.issue(registry, traversal, session)
        self.assertEqual("terminal", status)
        self.assertIsNone(replay)

    def test_service_restart_state_is_process_local(self):
        _, registry, traversal, session = self.make_registries()
        self.issue(registry, traversal, session)
        restarted_traversal = RendezvousRegistry(rendezvous_host="rendezvous.example")
        restarted_registry = SessionRegistry(on_remove=restarted_traversal.remove_session)
        self.assertEqual({}, restarted_traversal._request_ids)
        self.assertEqual([], restarted_registry.list({}))

    def test_concurrent_identical_request_id_creates_exactly_one_attempt(self):
        _, registry, traversal, session = self.make_registries()
        barrier = threading.Barrier(8)
        results = []
        result_lock = threading.Lock()

        def worker():
            barrier.wait()
            result = self.issue(registry, traversal, session)
            with result_lock:
                results.append(result)

        threads = [threading.Thread(target=worker) for _ in range(8)]
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join()

        self.assertEqual(1, sum(status == "created" for status, _, _ in results))
        self.assertEqual(7, sum(status == "replayed" for status, _, _ in results))
        self.assertEqual(1, len({attempt["attempt_id"] for _, _, attempt in results}))
        self.assertEqual(1, len({attempt["capability"] for _, _, attempt in results}))
        self.assertEqual(1, len(traversal._attempts))

    def test_concurrent_conflicting_fingerprints_have_one_winner(self):
        _, registry, traversal, first_session = self.make_registries()
        second_session = registry.create(payload())
        barrier = threading.Barrier(2)
        results = []
        result_lock = threading.Lock()

        def worker(session, source):
            barrier.wait()
            result = self.issue(registry, traversal, session, source=source)
            with result_lock:
                results.append(result)

        threads = [
            threading.Thread(target=worker, args=(first_session, "first")),
            threading.Thread(target=worker, args=(second_session, "second")),
        ]
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join()

        self.assertEqual({"created", "conflict"}, {result[0] for result in results})
        self.assertEqual(1, len(traversal._attempts))
        self.assertEqual(1, len(traversal._request_ids))

    def test_concurrent_distinct_request_ids_can_create_distinct_attempts(self):
        _, registry, traversal, session = self.make_registries()
        barrier = threading.Barrier(2)
        results = []
        result_lock = threading.Lock()

        def worker(request_id, source):
            barrier.wait()
            result = self.issue(
                registry, traversal, session, {"request_id": request_id}, source)
            with result_lock:
                results.append(result)

        threads = [
            threading.Thread(
                target=worker,
                args=("00000000000000000000000000000001", "first")),
            threading.Thread(
                target=worker,
                args=("00000000000000000000000000000002", "second")),
        ]
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join()

        self.assertEqual(["created", "created"], sorted(result[0] for result in results))
        self.assertEqual(2, len({result[2]["attempt_id"] for result in results}))

    def test_concurrent_session_delete_cannot_leave_orphan_attempt(self):
        _, registry, traversal, session = self.make_registries()
        barrier = threading.Barrier(2)
        outcomes = {}
        errors = []
        outcome_lock = threading.Lock()

        def issue():
            try:
                barrier.wait()
                result = self.issue(registry, traversal, session)
                with outcome_lock:
                    outcomes["issue"] = result
            except BaseException as exc:  # Surface worker failures in the test thread.
                with outcome_lock:
                    errors.append(exc)

        def delete():
            try:
                barrier.wait()
                result = registry.delete(session.session_id, session.registration_token)
                with outcome_lock:
                    outcomes["delete"] = result
            except BaseException as exc:  # Surface worker failures in the test thread.
                with outcome_lock:
                    errors.append(exc)

        threads = [threading.Thread(target=issue), threading.Thread(target=delete)]
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join()

        self.assertEqual([], errors)
        self.assertTrue(outcomes["delete"])
        self.assertIn(outcomes["issue"][0], {"created", "not_found"})
        self.assertFalse(registry.exists(session.session_id))
        self.assertTrue(all(
            registry.exists(attempt.session_id)
            for attempt in traversal._attempts.values()
        ))
        self.assertEqual({}, traversal._attempts)
        self.assertEqual({}, traversal._request_ids)


class PhaseTwoRegistryTests(unittest.TestCase):
    def make_private_attempt(self, *, discovery_ready=True):
        now = [1000.0]
        traversal = RendezvousRegistry(
            20, lambda: now[0], rendezvous_host="rendezvous.example",
            admission_ttl_seconds=20)
        registry = SessionRegistry(45, lambda: now[0], traversal.remove_session)
        session = registry.create(payload())
        status, _, client = registry.issue_by_code_attempt(
            session.invite_code, attempt_payload(), traversal, "client")
        self.assertEqual("created", status)
        poll_status, attempts = registry.host_poll_attempts(
            session.session_id, session.registration_token, [], traversal)
        self.assertEqual("ok", poll_status)
        host = attempts[0]
        if discovery_ready:
            attempt_id = bytes.fromhex(client["attempt_id"])
            self.assertIsNotNone(traversal.register(
                attempt_id, bytes.fromhex(host["capability"]), 0, 0,
                ("198.51.100.10", 41000)))
            self.assertIsNotNone(traversal.register(
                attempt_id, bytes.fromhex(client["capability"]), 1, 0,
                ("203.0.113.20", 42000)))
        return now, registry, traversal, session, client, host

    def arm(self, registry, traversal, session, client):
        return registry.arm_admission(
            session.session_id, client["attempt_id"], client["capability"], traversal)

    def acknowledge(self, registry, traversal, session, admission):
        return registry.host_poll_attempts(
            session.session_id,
            session.registration_token,
            [{
                "attempt_id": admission["attempt_id"],
                "admission_generation": admission["admission_generation"],
                "lease_revision": admission["lease_revision"],
            }],
            traversal,
        )

    def test_public_completion_and_expiry_do_not_retain_terminal_state(self):
        now = [1000.0]
        traversal = RendezvousRegistry(
            20, lambda: now[0], rendezvous_host="rendezvous.example")
        registry = SessionRegistry(45, lambda: now[0], traversal.remove_session)
        session = registry.create(payload())

        completed = []
        for index in range(3):
            status, attempt = registry.issue_public_attempt(
                session.session_id, traversal, f"completed-{index}")
            self.assertEqual("created", status)
            attempt_id = bytes.fromhex(attempt["attempt_id"])
            self.assertIsNone(traversal._attempts[attempt_id].admission)
            self.assertTrue(traversal.complete(
                session.session_id, attempt["attempt_id"], attempt["capability"]))
            self.assertNotIn(attempt_id, traversal._attempts)
            self.assertFalse(traversal.complete(
                session.session_id, attempt["attempt_id"], attempt["capability"]))
            completed.append(attempt)

        expiring = []
        for index in range(3):
            status, attempt = registry.issue_public_attempt(
                session.session_id, traversal, f"expiring-{index}")
            self.assertEqual("created", status)
            expiring.append(attempt)
        now[0] += 21
        self.assertEqual([], traversal.pending(session.session_id))

        self.assertEqual({}, traversal._attempts)
        self.assertEqual({}, traversal._terminal_attempts)
        self.assertEqual({}, traversal._terminal_by_session)
        self.assertTrue(registry.exists(session.session_id))
        for attempt in completed + expiring:
            self.assertFalse(traversal.complete(
                session.session_id, attempt["attempt_id"], attempt["capability"]))

    def test_by_code_pre_arm_terminal_state_and_tombstone_are_retained(self):
        _, registry, traversal, session, client, _ = self.make_private_attempt(
            discovery_ready=False)
        attempt_id = bytes.fromhex(client["attempt_id"])
        self.assertTrue(traversal.complete(
            session.session_id, client["attempt_id"], client["capability"]))

        self.assertNotIn(attempt_id, traversal._attempts)
        self.assertIn(attempt_id, traversal._terminal_attempts)
        self.assertIsNone(traversal._terminal_attempts[attempt_id].admission)
        request = traversal._request_ids[client["request_id"]]
        self.assertEqual("completed", request.terminal_reason)
        status, _, replay = registry.issue_by_code_attempt(
            session.invite_code, attempt_payload(), traversal, "replay")
        self.assertEqual("terminal", status)
        self.assertIsNone(replay)

        status, terminal = registry.admission_status(
            session.session_id, client["attempt_id"], client["capability"], traversal)
        self.assertEqual("ok", status)
        self.assertEqual(AttemptPhase.TERMINAL.value, terminal["phase"])
        self.assertEqual("completed", terminal["terminal_reason"])
        self.assertFalse(terminal["host_ready"])

        self.assertTrue(registry.delete(session.session_id, session.registration_token))
        self.assertEqual({}, traversal._terminal_attempts)
        self.assertEqual({}, traversal._terminal_by_session)
        self.assertEqual({}, traversal._request_ids)

    def test_arm_requires_completed_discovery_and_is_idempotent(self):
        now, registry, traversal, session, client, host = self.make_private_attempt(
            discovery_ready=False)
        status, admission = self.arm(registry, traversal, session, client)
        self.assertEqual("not_ready", status)
        self.assertIsNone(admission)

        attempt_id = bytes.fromhex(client["attempt_id"])
        traversal.register(
            attempt_id, bytes.fromhex(host["capability"]), 0, 0,
            ("198.51.100.10", 41000))
        traversal.register(
            attempt_id, bytes.fromhex(client["capability"]), 1, 0,
            ("203.0.113.20", 42000))
        status, admission = self.arm(registry, traversal, session, client)
        self.assertEqual("created", status)
        self.assertEqual(AttemptPhase.ADMISSION_AWAITING_HOST.value, admission["phase"])
        self.assertEqual(1, admission["lease_revision"])
        self.assertFalse(admission["host_ready"])
        self.assertEqual(32, len(admission["admission_generation"]))
        original_expiry = traversal._attempts[attempt_id].admission.expires_at

        now[0] += 5
        replay_status, replay = self.arm(registry, traversal, session, client)
        self.assertEqual("replayed", replay_status)
        self.assertEqual(admission["admission_generation"], replay["admission_generation"])
        self.assertEqual(1, replay["lease_revision"])
        self.assertEqual(original_expiry, traversal._attempts[attempt_id].admission.expires_at)
        self.assertLess(replay["admission_expires_in_ms"], admission["admission_expires_in_ms"])

    def test_armed_admission_does_not_extend_rendezvous_credentials(self):
        now, registry, traversal, session, client, host = self.make_private_attempt()
        attempt_id = bytes.fromhex(client["attempt_id"])
        rendezvous_expiry = traversal._attempts[attempt_id].expires_at

        now[0] += 5
        status, admission = self.arm(registry, traversal, session, client)
        self.assertEqual("created", status)
        self.assertEqual(rendezvous_expiry, traversal._attempts[attempt_id].expires_at)
        self.assertGreater(traversal._attempts[attempt_id].admission.expires_at,
                           rendezvous_expiry)

        now[0] = rendezvous_expiry + 1
        self.assertIsNone(traversal.register(
            attempt_id, bytes.fromhex(host["capability"]), 0, 0,
            ("198.51.100.11", 41001)))
        status, state = registry.admission_status(
            session.session_id, client["attempt_id"], client["capability"], traversal)
        self.assertEqual("ok", status)
        self.assertEqual(admission["admission_generation"], state["admission_generation"])
        self.assertEqual(AttemptPhase.ADMISSION_AWAITING_HOST.value, state["phase"])
        self.assertGreater(state["admission_expires_in_ms"], 0)

    def test_public_host_wrong_session_and_expired_rendezvous_cannot_arm(self):
        now, registry, traversal, session, client, host = self.make_private_attempt()
        other = registry.create(payload())
        self.assertEqual(
            "not_found",
            registry.arm_admission(
                other.session_id, client["attempt_id"], client["capability"], traversal)[0],
        )
        self.assertEqual(
            "not_found",
            registry.arm_admission(
                session.session_id, client["attempt_id"], host["capability"], traversal)[0],
        )

        public = registry.issue_public_attempt(session.session_id, traversal, "public-client")[1]
        self.assertEqual(
            "not_eligible",
            registry.arm_admission(
                session.session_id, public["attempt_id"], public["capability"], traversal)[0],
        )

        now2, registry2, traversal2, session2, client2, _ = self.make_private_attempt()
        now2[0] += 21
        self.assertEqual("terminal", self.arm(registry2, traversal2, session2, client2)[0])

    def test_ack_ready_renew_and_status_are_revision_exact(self):
        now, registry, traversal, session, client, _ = self.make_private_attempt()
        _, admission = self.arm(registry, traversal, session, client)
        attempt_id = bytes.fromhex(client["attempt_id"])
        original_expiry = traversal._attempts[attempt_id].admission.expires_at

        status, value = registry.renew_admission(
            session.session_id, client["attempt_id"], client["capability"],
            {"admission_generation": admission["admission_generation"],
             "previous_lease_revision": 1}, traversal)
        self.assertEqual("not_ready", status)
        self.assertIsNone(value)
        self.assertEqual(original_expiry, traversal._attempts[attempt_id].admission.expires_at)

        self.acknowledge(registry, traversal, session, admission)
        status, ready = registry.admission_status(
            session.session_id, client["attempt_id"], client["capability"], traversal)
        self.assertEqual("ok", status)
        self.assertTrue(ready["host_ready"])
        self.assertEqual(AttemptPhase.ADMISSION_READY.value, ready["phase"])
        self.assertNotIn("capability", ready)

        now[0] += 6
        status, renewed = registry.renew_admission(
            session.session_id, client["attempt_id"], client["capability"],
            {"admission_generation": admission["admission_generation"],
             "previous_lease_revision": 1}, traversal)
        self.assertEqual("renewed", status)
        self.assertEqual(2, renewed["lease_revision"])
        self.assertFalse(renewed["host_ready"])
        renewed_expiry = traversal._attempts[attempt_id].admission.expires_at
        self.assertEqual(now[0] + 20, renewed_expiry)

        for generation, revision in (
            (admission["admission_generation"], 1),
            (admission["admission_generation"], 3),
            ("ff" * 16, 2),
        ):
            with self.subTest(generation=generation, revision=revision):
                self.assertEqual(
                    "conflict",
                    registry.renew_admission(
                        session.session_id, client["attempt_id"], client["capability"],
                        {"admission_generation": generation,
                         "previous_lease_revision": revision}, traversal)[0],
                )
                self.assertEqual(renewed_expiry, traversal._attempts[attempt_id].admission.expires_at)

        # An acknowledgement for the old revision cannot ready the new revision.
        self.acknowledge(registry, traversal, session, admission)
        _, waiting = registry.admission_status(
            session.session_id, client["attempt_id"], client["capability"], traversal)
        self.assertFalse(waiting["host_ready"])
        self.acknowledge(registry, traversal, session, renewed)
        _, ready_again = registry.admission_status(
            session.session_id, client["attempt_id"], client["capability"], traversal)
        self.assertTrue(ready_again["host_ready"])

        status_expiry = traversal._attempts[attempt_id].admission.expires_at
        now[0] += 2
        registry.admission_status(
            session.session_id, client["attempt_id"], client["capability"], traversal)
        self.assertEqual(status_expiry, traversal._attempts[attempt_id].admission.expires_at)

    def test_expiry_completion_revocation_and_session_cleanup_are_terminal(self):
        now, registry, traversal, session, client, host = self.make_private_attempt()
        _, admission = self.arm(registry, traversal, session, client)
        self.acknowledge(registry, traversal, session, admission)
        now[0] += 21
        status, terminal = registry.admission_status(
            session.session_id, client["attempt_id"], client["capability"], traversal)
        self.assertEqual("ok", status)
        self.assertEqual(AttemptPhase.TERMINAL.value, terminal["phase"])
        self.assertEqual("admission_expired", terminal["terminal_reason"])
        self.assertFalse(terminal["host_ready"])
        attempt_id = bytes.fromhex(client["attempt_id"])
        self.assertIn(attempt_id, traversal._terminal_attempts)
        self.acknowledge(registry, traversal, session, admission)
        _, still_terminal = registry.admission_status(
            session.session_id, client["attempt_id"], client["capability"], traversal)
        self.assertEqual(AttemptPhase.TERMINAL.value, still_terminal["phase"])
        self.assertFalse(still_terminal["host_ready"])
        self.assertEqual(
            "terminal",
            registry.renew_admission(
                session.session_id, client["attempt_id"], client["capability"],
                {"admission_generation": admission["admission_generation"],
                 "previous_lease_revision": 1}, traversal)[0],
        )

        _, registry2, traversal2, session2, client2, host2 = self.make_private_attempt()
        _, admission2 = self.arm(registry2, traversal2, session2, client2)
        self.assertEqual(
            "revoked",
            registry2.revoke_admission(
                session2.session_id, client2["attempt_id"], host2["capability"], traversal2),
        )
        _, revoked = registry2.admission_status(
            session2.session_id, client2["attempt_id"], client2["capability"], traversal2)
        self.assertEqual("revoked", revoked["terminal_reason"])
        self.assertFalse(revoked["host_ready"])
        self.assertIn(bytes.fromhex(client2["attempt_id"]), traversal2._terminal_attempts)
        self.assertEqual(
            "terminal",
            registry2.renew_admission(
                session2.session_id, client2["attempt_id"], client2["capability"],
                {"admission_generation": admission2["admission_generation"],
                 "previous_lease_revision": 1}, traversal2)[0],
        )
        self.assertTrue(registry2.delete(session2.session_id, session2.registration_token))
        self.assertEqual({}, traversal2._terminal_attempts)
        self.assertEqual({}, traversal2._terminal_by_session)
        self.assertEqual({}, traversal2._request_ids)

        _, registry3, traversal3, session3, client3, _ = self.make_private_attempt()
        self.arm(registry3, traversal3, session3, client3)
        self.assertTrue(registry3.delete(session3.session_id, session3.registration_token))
        self.assertEqual({}, traversal3._attempts)
        self.assertEqual({}, traversal3._terminal_attempts)
        self.assertEqual({}, traversal3._request_ids)

        _, registry4, traversal4, session4, client4, _ = self.make_private_attempt()
        self.arm(registry4, traversal4, session4, client4)
        self.assertTrue(traversal4.complete(
            session4.session_id, client4["attempt_id"], client4["capability"]))
        self.assertIn(bytes.fromhex(client4["attempt_id"]), traversal4._terminal_attempts)
        _, completed = registry4.admission_status(
            session4.session_id, client4["attempt_id"], client4["capability"], traversal4)
        self.assertEqual("completed", completed["terminal_reason"])
        self.assertFalse(completed["host_ready"])

        restarted = RendezvousRegistry(rendezvous_host="rendezvous.example")
        self.assertEqual({}, restarted._attempts)
        self.assertEqual({}, restarted._terminal_attempts)

    def test_concurrent_arm_and_renew_have_single_generation_and_revision_winner(self):
        _, registry, traversal, session, client, _ = self.make_private_attempt()
        barrier = threading.Barrier(8)
        results = []
        errors = []
        lock = threading.Lock()

        def arm_worker():
            try:
                barrier.wait()
                value = self.arm(registry, traversal, session, client)
                with lock:
                    results.append(value)
            except BaseException as exc:
                with lock:
                    errors.append(exc)

        threads = [threading.Thread(target=arm_worker) for _ in range(8)]
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join()
        self.assertEqual([], errors)
        self.assertEqual(1, sum(status == "created" for status, _ in results))
        self.assertEqual(7, sum(status == "replayed" for status, _ in results))
        self.assertEqual(1, len({value["admission_generation"] for _, value in results}))
        self.assertEqual({1}, {value["lease_revision"] for _, value in results})

        admission = results[0][1]
        self.acknowledge(registry, traversal, session, admission)
        barrier = threading.Barrier(6)
        renewals = []

        def renew_worker():
            try:
                barrier.wait()
                value = registry.renew_admission(
                    session.session_id, client["attempt_id"], client["capability"],
                    {"admission_generation": admission["admission_generation"],
                     "previous_lease_revision": 1}, traversal)
                with lock:
                    renewals.append(value)
            except BaseException as exc:
                with lock:
                    errors.append(exc)

        threads = [threading.Thread(target=renew_worker) for _ in range(6)]
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join()
        self.assertEqual([], errors)
        self.assertEqual(1, sum(status == "renewed" for status, _ in renewals))
        self.assertEqual(5, sum(status == "conflict" for status, _ in renewals))
        self.assertEqual(2, traversal._attempts[
            bytes.fromhex(client["attempt_id"])].admission.lease_revision)

    def test_ack_renew_expiry_terminal_and_delete_races_fail_closed(self):
        now, registry, traversal, session, client, _ = self.make_private_attempt()
        _, admission = self.arm(registry, traversal, session, client)
        self.acknowledge(registry, traversal, session, admission)

        barrier = threading.Barrier(2)
        errors = []
        error_lock = threading.Lock()

        def renew():
            try:
                barrier.wait()
                registry.renew_admission(
                    session.session_id, client["attempt_id"], client["capability"],
                    {"admission_generation": admission["admission_generation"],
                     "previous_lease_revision": 1}, traversal)
            except BaseException as exc:
                with error_lock:
                    errors.append(exc)

        def stale_ack():
            try:
                barrier.wait()
                self.acknowledge(registry, traversal, session, admission)
            except BaseException as exc:
                with error_lock:
                    errors.append(exc)

        threads = [threading.Thread(target=renew), threading.Thread(target=stale_ack)]
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join()
        self.assertEqual([], errors)
        _, state = registry.admission_status(
            session.session_id, client["attempt_id"], client["capability"], traversal)
        self.assertEqual(2, state["lease_revision"])
        self.assertFalse(state["host_ready"])

        now[0] += 21
        barrier = threading.Barrier(2)
        expiry_results = []

        def expiry_ack():
            try:
                barrier.wait()
                self.acknowledge(registry, traversal, session, {
                    **admission, "lease_revision": 2,
                })
            except BaseException as exc:
                with error_lock:
                    errors.append(exc)

        def expiry_status():
            try:
                barrier.wait()
                expiry_results.append(registry.admission_status(
                    session.session_id, client["attempt_id"],
                    client["capability"], traversal))
            except BaseException as exc:
                with error_lock:
                    errors.append(exc)

        threads = [threading.Thread(target=expiry_ack), threading.Thread(target=expiry_status)]
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join()
        self.assertEqual([], errors)
        self.assertEqual(AttemptPhase.TERMINAL.value, expiry_results[0][1]["phase"])
        _, expired = registry.admission_status(
            session.session_id, client["attempt_id"], client["capability"], traversal)
        self.assertEqual(AttemptPhase.TERMINAL.value, expired["phase"])
        self.assertFalse(expired["host_ready"])

        _, registry2, traversal2, session2, client2, _ = self.make_private_attempt()
        _, armed2 = self.arm(registry2, traversal2, session2, client2)
        self.acknowledge(registry2, traversal2, session2, armed2)
        barrier = threading.Barrier(2)
        outcomes = []

        def renew2():
            try:
                barrier.wait()
                outcomes.append(registry2.renew_admission(
                    session2.session_id, client2["attempt_id"], client2["capability"],
                    {"admission_generation": armed2["admission_generation"],
                     "previous_lease_revision": 1}, traversal2)[0])
            except BaseException as exc:
                with error_lock:
                    errors.append(exc)

        def terminate2():
            try:
                barrier.wait()
                outcomes.append("completed" if traversal2.complete(
                    session2.session_id, client2["attempt_id"], client2["capability"])
                    else "not_found")
            except BaseException as exc:
                with error_lock:
                    errors.append(exc)

        threads = [threading.Thread(target=renew2), threading.Thread(target=terminate2)]
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join()
        self.assertEqual([], errors)
        _, terminal = registry2.admission_status(
            session2.session_id, client2["attempt_id"], client2["capability"], traversal2)
        self.assertEqual(AttemptPhase.TERMINAL.value, terminal["phase"])
        self.assertIn("completed", outcomes)

        _, registry3, traversal3, session3, client3, _ = self.make_private_attempt()
        barrier = threading.Barrier(2)
        results = []

        def arm3():
            try:
                barrier.wait()
                results.append(registry3.arm_admission(
                    session3.session_id, client3["attempt_id"],
                    client3["capability"], traversal3)[0])
            except BaseException as exc:
                with error_lock:
                    errors.append(exc)

        def delete3():
            try:
                barrier.wait()
                registry3.delete(session3.session_id, session3.registration_token)
            except BaseException as exc:
                with error_lock:
                    errors.append(exc)

        threads = [threading.Thread(target=arm3), threading.Thread(target=delete3)]
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join()
        self.assertEqual([], errors)
        self.assertIn(results[0], {"created", "not_found"})
        self.assertEqual({}, traversal3._attempts)
        self.assertEqual({}, traversal3._terminal_attempts)

        _, registry4, traversal4, session4, client4, _ = self.make_private_attempt()
        _, armed4 = self.arm(registry4, traversal4, session4, client4)
        self.acknowledge(registry4, traversal4, session4, armed4)
        barrier = threading.Barrier(2)
        renew_delete_results = []

        def renew4():
            try:
                barrier.wait()
                renew_delete_results.append(registry4.renew_admission(
                    session4.session_id, client4["attempt_id"], client4["capability"],
                    {"admission_generation": armed4["admission_generation"],
                     "previous_lease_revision": 1}, traversal4)[0])
            except BaseException as exc:
                with error_lock:
                    errors.append(exc)

        def delete4():
            try:
                barrier.wait()
                registry4.delete(session4.session_id, session4.registration_token)
            except BaseException as exc:
                with error_lock:
                    errors.append(exc)

        threads = [threading.Thread(target=renew4), threading.Thread(target=delete4)]
        for thread in threads:
            thread.start()
        for thread in threads:
            thread.join()
        self.assertEqual([], errors)
        self.assertIn(renew_delete_results[0], {"renewed", "not_found"})
        self.assertEqual({}, traversal4._attempts)
        self.assertEqual({}, traversal4._terminal_attempts)


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

    def create_by_code(self, request=None):
        status, created = self.request("POST", "/sessions", payload())
        self.assertEqual(201, status)
        path = f"/sessions/by-code/{created['invite_code']}/join-attempts"
        status, response = self.request("POST", path, request or attempt_payload())
        return created, path, status, response

    def make_discovery_ready(self, created, client):
        host_path = f"/sessions/{created['session_id']}/join-attempts"
        status, pending = self.request(
            "GET", host_path, token=created["registration_token"])
        self.assertEqual(200, status)
        host = next(
            value for value in pending["attempts"]
            if value["attempt_id"] == client["attempt_id"])
        attempt_id = bytes.fromhex(client["attempt_id"])
        self.assertIsNotNone(self.traversal.register(
            attempt_id, bytes.fromhex(host["capability"]), 0, 0,
            ("198.51.100.10", 41000)))
        self.assertIsNotNone(self.traversal.register(
            attempt_id, bytes.fromhex(client["capability"]), 1, 0,
            ("203.0.113.20", 42000)))
        return host

    @staticmethod
    def admission_path(created, client, operation=""):
        base = (f"/sessions/{created['session_id']}/join-attempts/"
                f"{client['attempt_id']}/admission")
        return f"{base}/{operation}" if operation else base

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
        self.assertEqual(AttemptPurpose.PUBLIC.value, client["purpose"])
        self.assertNotIn("host_capability", client)
        self.assertNotIn("rendezvous_expires_in_ms", client)
        for field in ("phase", "admission_generation", "lease_revision",
                      "admission_expires_in_ms", "host_ready"):
            self.assertNotIn(field, client)
        self.assertEqual("rendezvous.example", client["rendezvous_host"])
        status, _ = self.request("GET", path, token="wrong")
        self.assertEqual(404, status)
        status, pending = self.request("GET", path, token=created["registration_token"])
        self.assertEqual(200, status)
        self.assertEqual(1, len(pending["attempts"]))
        host = pending["attempts"][0]
        self.assertEqual("host", host["participant"])
        self.assertEqual(AttemptPurpose.PUBLIC.value, host["purpose"])
        self.assertNotIn("rendezvous_expires_in_ms", host)
        for field in ("phase", "admission_generation", "lease_revision",
                      "admission_expires_in_ms", "host_ready"):
            self.assertNotIn(field, host)
        self.assertEqual(client["attempt_id"], host["attempt_id"])
        self.assertNotEqual(client["capability"], host["capability"])
        status, _ = self.request(
            "DELETE", f"{path}/{client['attempt_id']}", token=client["capability"])
        self.assertEqual(204, status)
        status, _ = self.request(
            "DELETE", f"{path}/{client['attempt_id']}", token=client["capability"])
        self.assertEqual(404, status)

    def test_atomic_by_code_attempt_exposes_matching_immutable_purpose(self):
        created, path, status, response = self.create_by_code()
        self.assertEqual(201, status)
        self.assertEqual(created["session_id"], response["session"]["session_id"])
        client = response["attempt"]
        self.assertEqual("client", client["participant"])
        self.assertEqual(
            AttemptPurpose.INVITE_CODE_PRIVATE_ELIGIBLE.value, client["purpose"])
        self.assertEqual("00112233445566778899aabbccddeeff", client["request_id"])
        self.assertIn("rendezvous_expires_in_ms", client)
        self.assertNotIn("registration_token", response["session"])

        host_path = f"/sessions/{created['session_id']}/join-attempts"
        poll_status, pending = self.request(
            "GET", host_path, token=created["registration_token"])
        self.assertEqual(200, poll_status)
        self.assertEqual(1, len(pending["attempts"]))
        host = pending["attempts"][0]
        self.assertEqual(client["attempt_id"], host["attempt_id"])
        self.assertEqual(client["purpose"], host["purpose"])
        self.assertNotEqual(client["capability"], host["capability"])
        self.assertNotIn("request_id", host)
        self.assertNotIn("rendezvous_expires_in_ms", host)
        self.assertNotIn(client["capability"], host.values())
        self.assertNotIn(host["capability"], client.values())

    def test_admission_http_arm_poll_ack_status_and_renew(self):
        created, _, status, response = self.create_by_code()
        self.assertEqual(201, status)
        client = response["attempt"]
        host = self.make_discovery_ready(created, client)
        arm_path = self.admission_path(created, client, "arm")

        status, armed = self.request("POST", arm_path, {}, client["capability"])
        self.assertEqual(201, status)
        self.assertEqual(AttemptPhase.ADMISSION_AWAITING_HOST.value, armed["phase"])
        self.assertEqual(1, armed["lease_revision"])
        self.assertFalse(armed["host_ready"])
        attempt_id = bytes.fromhex(client["attempt_id"])
        original_expiry = self.traversal._attempts[attempt_id].admission.expires_at

        status, replay = self.request("POST", arm_path, {}, client["capability"])
        self.assertEqual(200, status)
        self.assertEqual(armed["admission_generation"], replay["admission_generation"])
        self.assertEqual(original_expiry, self.traversal._attempts[attempt_id].admission.expires_at)

        status_path = self.admission_path(created, client)
        status, waiting = self.request("GET", status_path, token=client["capability"])
        self.assertEqual(200, status)
        self.assertFalse(waiting["host_ready"])
        self.assertNotIn("capability", waiting)

        poll_path = f"/sessions/{created['session_id']}/join-attempts/poll"
        acknowledgement = {
            "attempt_id": client["attempt_id"],
            "admission_generation": armed["admission_generation"],
            "lease_revision": 1,
        }
        # Physical same-LAN discovery alone is not a server-side grant. The
        # authenticated host must still acknowledge this exact generation/revision.
        status, unprepared = self.request(
            "POST", poll_path, {"acknowledged": []},
            created["registration_token"])
        self.assertEqual(200, status)
        self.assertFalse(next(
            value for value in unprepared["attempts"]
            if value["attempt_id"] == client["attempt_id"])["host_ready"])
        status, polled = self.request(
            "POST", poll_path, {"acknowledged": [acknowledgement]},
            created["registration_token"])
        self.assertEqual(200, status)
        host_view = next(
            value for value in polled["attempts"]
            if value["attempt_id"] == client["attempt_id"])
        self.assertEqual(host["capability"], host_view["capability"])
        self.assertEqual(armed["admission_generation"],
                         host_view["admission_generation"])
        self.assertEqual(1, host_view["lease_revision"])
        self.assertTrue(host_view["host_ready"])
        self.assertNotIn(client["capability"], host_view.values())
        self.assertNotIn("request_id", host_view)
        self.assertNotIn("rendezvous_expires_in_ms", host_view)

        status, ready = self.request("GET", status_path, token=client["capability"])
        self.assertEqual(200, status)
        self.assertTrue(ready["host_ready"])
        self.assertEqual(armed["admission_generation"],
                         ready["host_seen_admission_generation"])
        self.assertEqual(1, ready["host_seen_lease_revision"])

        renew_path = self.admission_path(created, client, "renew")
        status, renewed = self.request(
            "POST", renew_path,
            {"admission_generation": armed["admission_generation"],
             "previous_lease_revision": 1},
            client["capability"])
        self.assertEqual(200, status)
        self.assertEqual(2, renewed["lease_revision"])
        self.assertFalse(renewed["host_ready"])
        renewed_expiry = self.traversal._attempts[attempt_id].admission.expires_at

        # Old acknowledgement is harmless; current acknowledgement readies revision 2.
        self.request(
            "POST", poll_path, {"acknowledged": [acknowledgement]},
            created["registration_token"])
        _, not_ready = self.request("GET", status_path, token=client["capability"])
        self.assertFalse(not_ready["host_ready"])
        acknowledgement["lease_revision"] = 2
        self.request(
            "POST", poll_path, {"acknowledged": [acknowledgement]},
            created["registration_token"])
        _, ready_again = self.request("GET", status_path, token=client["capability"])
        self.assertTrue(ready_again["host_ready"])
        self.assertEqual(renewed_expiry,
                         self.traversal._attempts[attempt_id].admission.expires_at)

    def test_admission_http_authorization_scope_and_server_owned_fields(self):
        created, _, status, response = self.create_by_code()
        self.assertEqual(201, status)
        client = response["attempt"]
        arm_path = self.admission_path(created, client, "arm")
        status, _ = self.request("POST", arm_path, {}, client["capability"])
        self.assertEqual(409, status)
        self.assertEqual(404, self.request(
            "POST", arm_path, {}, "00" * 16)[0])
        for body in (
            {"admission_generation": "00" * 16},
            {"lease_revision": 99},
            {"purpose": AttemptPurpose.INVITE_CODE_PRIVATE_ELIGIBLE.value},
        ):
            with self.subTest(body=body):
                status, _ = self.request("POST", arm_path, body, client["capability"])
                self.assertEqual(400, status)

        host = self.make_discovery_ready(created, client)
        status, armed = self.request("POST", arm_path, {}, client["capability"])
        self.assertEqual(201, status)
        self.assertEqual(404, self.request("POST", arm_path, {}, host["capability"])[0])
        self.assertEqual(404, self.request(
            "GET", self.admission_path(created, client), token=host["capability"])[0])

        _, other = self.request("POST", "/sessions", payload())
        wrong_session_path = (f"/sessions/{other['session_id']}/join-attempts/"
                              f"{client['attempt_id']}/admission/arm")
        self.assertEqual(404, self.request(
            "POST", wrong_session_path, {}, client["capability"])[0])

        public = self.registry.issue_public_attempt(
            created["session_id"], self.traversal, "public-client")[1]
        self.assertIsNotNone(public)
        self.assertEqual(409, self.request(
            "POST", self.admission_path(created, public, "arm"), {},
            public["capability"])[0])
        self.assertEqual(409, self.request(
            "POST", self.admission_path(created, public, "revoke"), {},
            public["capability"])[0])
        _, host_poll = self.request(
            "GET", f"/sessions/{created['session_id']}/join-attempts",
            token=created["registration_token"])
        public_host = next(
            value for value in host_poll["attempts"]
            if value["attempt_id"] == public["attempt_id"])
        for field in ("phase", "admission_generation", "lease_revision",
                      "admission_expires_in_ms", "host_ready"):
            self.assertNotIn(field, public_host)

        renew_path = self.admission_path(created, client, "renew")
        renewal = {
            "admission_generation": armed["admission_generation"],
            "previous_lease_revision": 1,
        }
        self.assertEqual(404, self.request(
            "POST", renew_path, renewal, host["capability"])[0])
        self.assertEqual(409, self.request(
            "POST", renew_path, {**renewal, "admission_generation": "ff" * 16},
            client["capability"])[0])
        self.assertEqual(409, self.request(
            "POST", renew_path, {**renewal, "previous_lease_revision": 2},
            client["capability"])[0])

        poll_path = f"/sessions/{created['session_id']}/join-attempts/poll"
        acknowledgement = {
            "attempt_id": client["attempt_id"],
            "admission_generation": armed["admission_generation"],
            "lease_revision": 1,
        }
        for change in (
            {"admission_generation": "ee" * 16},
            {"lease_revision": 2},
        ):
            status, _ = self.request(
                "POST", poll_path,
                {"acknowledged": [{**acknowledgement, **change}]},
                created["registration_token"])
            self.assertEqual(200, status)
            _, unchanged = self.request(
                "GET", self.admission_path(created, client), token=client["capability"])
            self.assertFalse(unchanged["host_ready"])
        self.assertEqual(404, self.request(
            "POST", poll_path, {"acknowledged": [acknowledgement]},
            client["capability"])[0])
        self.assertEqual(404, self.request(
            "POST", poll_path, {"acknowledged": [acknowledgement]}, "wrong-token")[0])
        other_poll = f"/sessions/{other['session_id']}/join-attempts/poll"
        self.assertEqual(200, self.request(
            "POST", other_poll, {"acknowledged": [acknowledgement]},
            other["registration_token"])[0])
        _, state = self.request(
            "GET", self.admission_path(created, client), token=client["capability"])
        self.assertFalse(state["host_ready"])

    def test_admission_http_expiry_revocation_and_terminal_status(self):
        now = [1000.0]
        self.registry.clock = lambda: now[0]
        self.traversal.clock = lambda: now[0]
        created, _, status, response = self.create_by_code()
        self.assertEqual(201, status)
        client = response["attempt"]
        self.make_discovery_ready(created, client)
        status, armed = self.request(
            "POST", self.admission_path(created, client, "arm"), {},
            client["capability"])
        self.assertEqual(201, status)
        now[0] += 21
        status, terminal = self.request(
            "GET", self.admission_path(created, client), token=client["capability"])
        self.assertEqual(200, status)
        self.assertEqual(AttemptPhase.TERMINAL.value, terminal["phase"])
        self.assertEqual("admission_expired", terminal["terminal_reason"])
        self.assertFalse(terminal["host_ready"])
        renewal = {
            "admission_generation": armed["admission_generation"],
            "previous_lease_revision": 1,
        }
        self.assertEqual(410, self.request(
            "POST", self.admission_path(created, client, "renew"), renewal,
            client["capability"])[0])
        self.assertEqual(410, self.request(
            "POST", self.admission_path(created, client, "arm"), {},
            client["capability"])[0])

        now[0] += 0.3
        created2, _, status, response2 = self.create_by_code(
            attempt_payload(request_id="ffeeddccbbaa99887766554433221100"))
        self.assertEqual(201, status)
        client2 = response2["attempt"]
        host2 = self.make_discovery_ready(created2, client2)
        self.assertEqual(201, self.request(
            "POST", self.admission_path(created2, client2, "arm"), {},
            client2["capability"])[0])
        self.assertEqual(204, self.request(
            "POST", self.admission_path(created2, client2, "revoke"), {},
            host2["capability"])[0])
        status, revoked = self.request(
            "GET", self.admission_path(created2, client2), token=client2["capability"])
        self.assertEqual(200, status)
        self.assertEqual("revoked", revoked["terminal_reason"])
        self.assertFalse(revoked["host_ready"])

    def test_client_cannot_supply_attempt_purpose(self):
        status, created = self.request("POST", "/sessions", payload())
        self.assertEqual(201, status)
        public_path = f"/sessions/{created['session_id']}/join-attempts"
        status, response = self.request(
            "POST", public_path,
            {"purpose": AttemptPurpose.INVITE_CODE_PRIVATE_ELIGIBLE.value})
        self.assertEqual(400, status)
        self.assertEqual("attempt purpose is server-owned", response["error"])

        private_path = f"/sessions/by-code/{created['invite_code']}/join-attempts"
        status, response = self.request(
            "POST", private_path,
            attempt_payload(purpose=AttemptPurpose.PUBLIC.value))
        self.assertEqual(400, status)
        self.assertEqual("attempt purpose is server-owned", response["error"])
        self.assertEqual([], self.traversal.pending(created["session_id"]))

    def test_by_code_request_id_validation_and_normalization(self):
        status, created = self.request("POST", "/sessions", payload())
        self.assertEqual(201, status)
        path = f"/sessions/by-code/{created['invite_code']}/join-attempts"
        malformed = [
            "", "0" * 31, "0" * 33, "g" * 32, 1234, None,
        ]
        for request_id in malformed:
            with self.subTest(request_id=request_id):
                status, _ = self.request(
                    "POST", path, attempt_payload(request_id=request_id))
                self.assertEqual(400, status)

        status, response = self.request(
            "POST", path,
            attempt_payload(request_id="AABBCCDDEEFF00112233445566778899"))
        self.assertEqual(201, status)
        self.assertEqual(
            "aabbccddeeff00112233445566778899",
            response["attempt"]["request_id"],
        )
        status, replay = self.request(
            "POST", path,
            attempt_payload(request_id="aabbccddeeff00112233445566778899"))
        self.assertEqual(200, status)
        self.assertEqual(response["attempt"]["attempt_id"], replay["attempt"]["attempt_id"])

    def test_by_code_case_normalization_replays_the_same_attempt(self):
        self.registry.invite_code_factory = lambda: "AB7K2Q"
        status, created = self.request("POST", "/sessions", payload())
        self.assertEqual(201, status)
        request = attempt_payload()
        upper_path = f"/sessions/by-code/{created['invite_code']}/join-attempts"
        lower_path = f"/sessions/by-code/{created['invite_code'].lower()}/join-attempts"

        status, first = self.request("POST", upper_path, request)
        self.assertEqual(201, status)
        attempt_id = bytes.fromhex(first["attempt"]["attempt_id"])
        original_expiry = self.traversal._attempts[attempt_id].expires_at
        status, replay = self.request("POST", lower_path, request)
        self.assertEqual(200, status)
        self.assertEqual(first["attempt"]["attempt_id"], replay["attempt"]["attempt_id"])
        self.assertEqual(first["attempt"]["capability"], replay["attempt"]["capability"])
        self.assertEqual(original_expiry, self.traversal._attempts[attempt_id].expires_at)
        self.assertEqual(1, len(self.traversal._attempts))

    def test_by_code_missing_code_and_traversal_unavailable_fail_without_attempt(self):
        status, _ = self.request(
            "POST", "/sessions/by-code/BAD/join-attempts", attempt_payload())
        self.assertEqual(404, status)
        status, created = self.request("POST", "/sessions", payload())
        self.assertEqual(201, status)
        self.traversal.rendezvous_host = ""
        status, _ = self.request(
            "POST", f"/sessions/by-code/{created['invite_code']}/join-attempts",
            attempt_payload(),
        )
        self.assertEqual(503, status)
        self.assertEqual({}, self.traversal._attempts)

    def test_by_code_live_replay_and_fingerprint_conflicts(self):
        created, path, status, first = self.create_by_code()
        self.assertEqual(201, status)
        attempt_id = bytes.fromhex(first["attempt"]["attempt_id"])
        expiry = self.traversal._attempts[attempt_id].expires_at

        status, replay = self.request("POST", path, attempt_payload())
        self.assertEqual(200, status)
        self.assertEqual(first["attempt"]["attempt_id"], replay["attempt"]["attempt_id"])
        self.assertEqual(first["attempt"]["capability"], replay["attempt"]["capability"])
        self.assertEqual(expiry, self.traversal._attempts[attempt_id].expires_at)

        conflicts = [
            attempt_payload(title_id="12345678"),
            attempt_payload(protocol_version=2),
            attempt_payload(build_id="different-build"),
        ]
        for request in conflicts:
            with self.subTest(request=request):
                status, _ = self.request("POST", path, request)
                self.assertEqual(409, status)

        _, second = self.request("POST", "/sessions", payload())
        second_path = f"/sessions/by-code/{second['invite_code']}/join-attempts"
        status, _ = self.request("POST", second_path, attempt_payload())
        self.assertEqual(409, status)
        self.assertEqual(1, len(self.traversal._attempts))
        self.assertEqual(created["session_id"],
                         self.traversal._attempts[attempt_id].session_id)

    def test_by_code_terminal_replay_and_new_user_action(self):
        created, path, status, first = self.create_by_code()
        self.assertEqual(201, status)
        client = first["attempt"]
        attempt_path = (
            f"/sessions/{created['session_id']}/join-attempts/{client['attempt_id']}")
        status, _ = self.request("DELETE", attempt_path, token=client["capability"])
        self.assertEqual(204, status)

        status, _ = self.request("POST", path, attempt_payload())
        self.assertEqual(410, status)
        threading.Event().wait(0.26)
        status, second = self.request(
            "POST", path,
            attempt_payload(request_id="ffeeddccbbaa99887766554433221100"))
        self.assertEqual(201, status)
        self.assertNotEqual(client["attempt_id"], second["attempt"]["attempt_id"])

    def test_incompatible_or_expired_code_creates_no_attempt(self):
        status, created = self.request("POST", "/sessions", payload())
        self.assertEqual(201, status)
        path = f"/sessions/by-code/{created['invite_code']}/join-attempts"
        for request in (
            attempt_payload(title_id="12345678"),
            attempt_payload(protocol_version=2),
            attempt_payload(build_id="different-build"),
        ):
            status, _ = self.request("POST", path, request)
            self.assertEqual(404, status)
        self.assertEqual({}, self.traversal._attempts)

        last_heartbeat = self.registry._sessions[created["session_id"]].last_heartbeat
        self.registry.clock = lambda: last_heartbeat + 46
        status, _ = self.request("POST", path, attempt_payload())
        self.assertEqual(404, status)
        self.assertEqual({}, self.traversal._attempts)

    def test_by_code_route_uses_existing_invite_rate_limit(self):
        status, created = self.request("POST", "/sessions", payload())
        self.assertEqual(201, status)
        path = f"/sessions/by-code/{created['invite_code']}/join-attempts"
        request = attempt_payload()
        for index in range(MAX_INVITE_LOOKUPS_PER_WINDOW):
            status, _ = self.request("POST", path, request)
            self.assertEqual(201 if index == 0 else 200, status)
        status, _ = self.request("POST", path, request)
        self.assertEqual(429, status)

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
