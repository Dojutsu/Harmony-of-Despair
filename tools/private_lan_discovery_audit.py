#!/usr/bin/env python3
"""Three production private LAN services and native encrypted synthetic gameplay.

A loopback UDP adversary proxy records only opaque ciphertext in memory. The
actual production LAN parser/authority processes every search/join/register/
renew/leave frame. No local file carries title/session claims or traffic keys.
Coordination files contain only private test phase markers. No actual title
code/assets or SteamOS hardware are exercised by this fixture.
"""
from __future__ import annotations
import argparse
from collections import deque
import json
import os
from pathlib import Path
import select
import socket
import subprocess
import tempfile
import threading
import time
from private_lan_invitation import generate
from private_lan_runtime_audit import wait_for


class OpaqueAdversary:
    def __init__(self, host_port: int):
        self.host = ('127.0.0.1', host_port)
        self.listener = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.listener.bind(('127.0.0.1', 0))
        self.port = self.listener.getsockname()[1]
        self.listener.setblocking(False)
        self.outbound: dict[tuple[str, int], socket.socket] = {}
        self.clients: dict[socket.socket, tuple[str, int]] = {}
        self.frames: deque[tuple[socket.socket, bytes, str]] = deque(maxlen=128)
        self.lock = threading.Lock()
        self.stopped = threading.Event()
        self.error = None
        self.block_client2_replies = False
        self.dropped_client2_replies = 0
        self.thread = threading.Thread(target=self.run, name='opaque-lan-fixture-proxy', daemon=True)
        self.thread.start()

    def run(self):
        try:
            while not self.stopped.is_set():
                with self.lock:
                    readers = [self.listener, *self.clients]
                ready, _, _ = select.select(readers, [], [], .025)
                for descriptor in ready:
                    packet, source = descriptor.recvfrom(1473)
                    if descriptor is self.listener:
                        if source[0] not in ('127.0.0.2', '127.0.0.3') or len(packet) != 1440:
                            continue
                        with self.lock:
                            outgoing = self.outbound.get(source)
                            if outgoing is None:
                                outgoing = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                                outgoing.bind((source[0], 0))
                                outgoing.setblocking(False)
                                self.outbound[source] = outgoing
                                self.clients[outgoing] = source
                            self.frames.append((outgoing, packet, source[0]))
                        outgoing.sendto(packet, self.host)
                    elif source == self.host:
                        with self.lock:
                            client = self.clients.get(descriptor)
                            blocked = bool(client and client[0] == '127.0.0.2' and self.block_client2_replies)
                            if blocked:
                                self.dropped_client2_replies += 1
                        if client and not blocked:
                            self.listener.sendto(packet, client)
        except BaseException as error:
            if not self.stopped.is_set():
                self.error = type(error).__name__

    def mutate_and_downgrade(self):
        """Opaque on-path changes, exact legacy sizes and oversized frames."""
        with self.lock:
            records = list(self.frames)
        if not records:
            raise RuntimeError('No actual private discovery request captured')
        outgoing, packet, _ = records[-1]
        for position in (5, 8, 24, 40+532, 1424):
            damaged = bytearray(packet)
            damaged[position] ^= 1
            outgoing.sendto(damaged, self.host)
        for size in (40, 56, 640, 1439, 1441, 1473):
            outgoing.sendto(b'REXL' + bytes(size-4), self.host)
        return len(records)

    def replay_retired(self):
        with self.lock:
            records = [(descriptor, packet) for descriptor, packet, ip in self.frames if ip == '127.0.0.2']
        if len(records) < 3:
            raise RuntimeError('Insufficient real client-2 join/renewal/registration frames')
        for descriptor, packet in records:
            descriptor.sendto(packet, self.host)
        return len(records)

    def close(self):
        self.stopped.set()
        self.thread.join(timeout=2)
        with self.lock:
            for descriptor in self.clients:
                descriptor.close()
            self.clients.clear()
            self.frames.clear()
        self.listener.close()


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--unit-tests', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    executable = args.unit_tests.resolve(strict=True)
    output = args.output.absolute()
    output.mkdir(parents=True, exist_ok=True)
    processes, logs = [], []
    receipt = {'schema': 1, 'passed': False, 'actual_title_gameplay': False,
               'production_lan_discovery': True,
               'control_transport': 'production private LAN UDP through opaque adversary proxy',
               'gameplay_transport': 'three independent production XSocket UDP instances with synthetic 39-byte flows',
               'private_service_interfaces': ['127.0.0.1', '127.0.0.2', '127.0.0.3']}
    probe = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    probe.bind(('127.0.0.1', 0))
    host_port = probe.getsockname()[1]
    probe.close()
    adversary = OpaqueAdversary(host_port)
    with tempfile.TemporaryDirectory(prefix='private-lan-discovery-', dir=output) as directory:
        fixture = Path(directory)
        os.chmod(fixture, 0o700)
        generate(fixture/'invitations', 1, [2, 3], 3600)
        generate(fixture/'wrong-invitations', 1, [2], 3600)
        started = time.monotonic()
        try:
            for role in (1, 2, 3):
                profile = fixture/f'profile-{role}'
                profile.mkdir(mode=0o700)
                environment = os.environ.copy()
                environment.update(HARMONY_PRIVATE_LAN_FIXTURE=str(fixture), HARMONY_PRIVATE_LAN_ROLE=str(role),
                                   HARMONY_PRIVATE_LAN_DISCOVERY_PORT=str(host_port if role == 1 else adversary.port),
                                   LOCALAPPDATA=str(profile))
                log = open(output/f'private-lan-discovery-{role}.log', 'wb')
                logs.append(log)
                processes.append(subprocess.Popen([str(executable), '[.private-lan-discovery-integration]'],
                                                   env=environment, stdout=log, stderr=subprocess.STDOUT))
                if role == 1:
                    wait_for([fixture/'host.ready'], processes, 10)
            wait_for([fixture/'rejected-2', fixture/'rejected-3'], processes, 10)
            receipt['bootstrap_adversary_captured_requests'] = adversary.mutate_and_downgrade()
            time.sleep(.2)
            (fixture/'attacksdone').write_bytes(b'1')
            wait_for([fixture/'1.rejected'], processes, 5)
            receipt['wrong_secret_and_authenticated_identity_spoof_no_roster_effect'] = True
            receipt['opaque_mitm_and_legacy_oversize_downgrade_no_roster_effect'] = True
            (fixture/'gojoin').write_bytes(b'1')
            wait_for([fixture/f'{role}.ready' for role in (1, 2, 3)], processes, 12)
            wait_for([fixture/f'{role}.registered' for role in (1, 2, 3)], processes, 12)
            receipt['all_six_directed_pairs_and_real_arbitration_registration'] = True
            with adversary.lock:
                adversary.block_client2_replies = True
            (fixture/'depart2').write_bytes(b'1')
            wait_for([fixture/'1.removed', fixture/'3.removed'], processes, 4)
            if (fixture/'2.departed').exists():
                raise RuntimeError('Client completed departure despite blocked real UDP replies')
            time.sleep(.15)
            with adversary.lock:
                dropped = adversary.dropped_client2_replies
                adversary.block_client2_replies = False
            if not dropped:
                raise RuntimeError('No actual UDP leave reply was blocked')
            wait_for([fixture/'2.departed'], processes, 4)
            receipt['lost_leave_reply_idempotent_retry'] = True
            receipt['opaque_client2_replies_dropped_during_leave'] = dropped
            receipt['captured_private_requests_replayed_after_departure'] = adversary.replay_retired()
            time.sleep(.3)
            (fixture/'replaydone').write_bytes(b'1')
            wait_for([fixture/'1.retired-replay', fixture/'3.retired-replay'], processes, 5)
            receipt['actual_udp_retired_join_renew_register_leave_replay_no_readmission'] = True
            (fixture/'rejoin2').write_bytes(b'1')
            wait_for([fixture/f'{role}.rejoined' for role in (1, 2, 3)], processes, 12)
            wait_for([fixture/f'{role}.reregistered' for role in (1, 2, 3)], processes, 12)
            receipt['fresh_socket_key_challenge_rejoin_and_gameplay'] = True
            while time.monotonic() < started+36:
                if adversary.error or any(p.poll() is not None for p in processes):
                    raise RuntimeError('Discovery runtime stopped before lease renewal validation')
                time.sleep(.1)
            (fixture/'stop').write_bytes(b'1')
            codes = [p.wait(timeout=8) for p in processes]
            if codes != [0, 0, 0]:
                raise RuntimeError(f'Private discovery fixtures failed: {codes}')
            receipt.update(passed=True, return_codes=codes, elapsed_seconds=round(time.monotonic()-started, 3))
        except Exception as error:
            receipt['error'] = str(error)
            for process in processes:
                if process.poll() is None:
                    process.terminate()
            for process in processes:
                try:
                    process.wait(timeout=5)
                except subprocess.TimeoutExpired:
                    process.kill()
                    process.wait()
        finally:
            adversary.close()
            for log in logs:
                log.close()
            (output/'private-lan-discovery-validation.json').write_text(json.dumps(receipt, indent=2)+'\n')
    print(json.dumps(receipt, indent=2))
    return 0 if receipt['passed'] else 1

if __name__ == '__main__':
    raise SystemExit(main())
