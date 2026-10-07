
"""Local production directory plus three isolated native runtime processes.
No title launch, private inputs, live deployment, or player profile writes.
"""
import argparse
import json
import os
from pathlib import Path
import socket
import subprocess
import threading
import time
import sys
from tools.master_server.server import DirectoryServer, SessionRegistry, RendezvousRegistry, RendezvousServer

ROOT = Path(__file__).resolve().parents[2]
def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--unit-tests', type=Path,
                        default=ROOT / 'out/reconcile-sdk/out/win-amd64/unit_tests.exe',
                        help='native unit_tests executable; defaults to the Windows build')
    parser.add_argument('--output-directory', type=Path,
                        help='new isolated fixture output directory')
    parser.add_argument('--invite-public-fallback', action='store_true',
                        help='verify private-eligible joins against the witnessed six-public/zero-private host')
    args = parser.parse_args()
    binary = args.unit_tests.resolve(strict=True)
    output = (args.output_directory.resolve() if args.output_directory else
              ROOT / 'out' / ('gameplay-integration-' + time.strftime('%Y%m%d-%H%M%S')))
    output.mkdir(mode=0o700)
    traversal = RendezvousRegistry(rendezvous_host='127.0.0.1', rendezvous_port=0)
    udp = RendezvousServer(('127.0.0.1', 0), traversal)
    traversal.rendezvous_port = udp.address[1]
    # Emulate the edge proxy's advertised public address; the native client
    # correctly rejects a literal loopback directory candidate. UDP mappings
    # are still independently observed from real sockets by production code.
    class FixtureRegistry(SessionRegistry):
        def create(self, payload, source=''):
            return super().create(payload, '198.51.100.1')
        def heartbeat(self, session_id, token, payload, source=''):
            return super().heartbeat(session_id, token, payload, '198.51.100.1')
    registry = FixtureRegistry(on_remove=traversal.remove_session)
    http = DirectoryServer(('127.0.0.1', 0), registry, traversal)
    threads = [threading.Thread(target=http.serve_forever, daemon=True),
               threading.Thread(target=udp.serve_forever, daemon=True)]
    for thread in threads: thread.start()
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as reserve:
        reserve.bind(('127.0.0.1', 0))
        discovery_port = reserve.getsockname()[1]
    lan_sink = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    lan_sink.bind(("127.0.0.1", discovery_port + 1))
    processes, logs = [], []
    def launch(role):
        env = os.environ.copy()
        env.update(HARMONY_GAMEPLAY_FIXTURE=str(output), HARMONY_GAMEPLAY_ROLE=str(role),
                   HARMONY_GAMEPLAY_URL=f'http://127.0.0.1:{http.server_address[1]}',
                   HARMONY_GAMEPLAY_DISCOVERY_PORT=str(discovery_port), LOCALAPPDATA=str(output / f'profile-{role}'))
        if args.invite_public_fallback:
            env['HARMONY_GAMEPLAY_PRIVATE_FALLBACK'] = '1'
        else:
            env.pop('HARMONY_GAMEPLAY_PRIVATE_FALLBACK', None)
        log=(output/f'{role}.log').open('w');logs.append(log)
        processes.append(subprocess.Popen([str(binary),
            '[.gameplay-integration]', '--reporter', 'compact'],env=env,stdout=log,stderr=subprocess.STDOUT,
            cwd=output))
    def wait_for(predicate, seconds):
        deadline=time.monotonic()+seconds
        while time.monotonic()<deadline:
            if any(p.poll() is not None for p in processes):
                raise RuntimeError('native fixture process exited early')
            if predicate(): return
            time.sleep(.05)
        raise RuntimeError('fixture deadline expired')
    try:
        launch(1);wait_for(lambda:(output/'code').exists(),25)
        launch(2)
        wait_for(lambda:any(len(g.members)>=2 for g in traversal.gameplay.groups.values()),25)
        launch(3)
        wait_for(lambda:all((output/f'{i}.ready').exists() for i in (1,2,3)),30)
        # Old discovery attempts must have completed while all three gameplay
        # mappings and their independent pair links remain available.
        with traversal._lock:
            assert len(traversal._attempts)==0
            groups=list(traversal.gameplay.groups.values());assert len(groups)==1
            assert len(groups[0].members)==3 and len(groups[0].links)==3
            endpoints=[m.endpoint for m in groups[0].members.values()]
            assert None not in endpoints and len(set(endpoints))==3
            assert len({endpoint[0] for endpoint in endpoints})==1
        (output/'stop').touch()
        for p in processes: assert p.wait(timeout=12)==0
        receipt = {'scope': 'synthetic payloads through production session/admission/gameplay transport',
                   'actual_title_gameplay_tested': False, 'native_binary': str(binary),
                   'process_returncodes': [p.returncode for p in processes],
                   'participants': 3, 'independent_endpoints': 3, 'pair_links': 3,
                   'discovery_attempts_retired': True, 'payload_bytes': 39, 'gameplay_datagram_protocol': 1,
                   'runtime_socket_send_and_receive': True,
                   'private_eligible_requests': True,
                   'host_public_slots': 6 if args.invite_public_fallback else 3,
                   'host_private_slots': 0 if args.invite_public_fallback else 3,
                   'public_fallback_verified': args.invite_public_fallback,
                   'encrypted_wire_observed': True}
        loaded_runtime_paths = []
        for role in (1, 2, 3):
            marker = (output / f'{role}.ready').read_text()
            assert 'encrypted_wire=1' in marker
            rows = []
            for line in (output / f'{role}.log').read_text().splitlines():
                if line.startswith('{'):
                    row = json.loads(line)
                    if row.get('kind') == 'loaded_runtime':
                        rows.append(row)
            if sys.platform == 'linux':
                assert len(rows) == 1 and rows[0]['role'] == role
                path = Path(rows[0]['path']).resolve(strict=True)
                assert path.name.startswith('librexruntime')
                loaded_runtime_paths.append(str(path))
        if loaded_runtime_paths:
            assert len(set(loaded_runtime_paths)) == 1
            receipt['loaded_runtime_paths'] = loaded_runtime_paths
        if args.invite_public_fallback:
            for role in (1, 2, 3):
                marker = (output / f'{role}.ready').read_text()
                assert 'public_fallback=1 private_cap=0' in marker
        (output/'validation.json').write_text(json.dumps(receipt, indent=2) + '\n')
        print('PASS: production discovery/admission/completion -> three distinct gameplay sockets, all peer pairs, authenticated unchanged 39-byte bidirectional payloads through actual XSocket')
        for i in (1,2,3): print(i,(output/f'{i}.ready').read_text())
        print(output)
    finally:
        (output/'stop').touch()
        for p in processes:
            try:p.wait(timeout=12)
            except subprocess.TimeoutExpired:p.terminate();p.wait(timeout=5)
        for log in logs:log.close()
        http.shutdown();http.server_close();udp.shutdown();lan_sink.close()
        for thread in threads:thread.join(timeout=2)
if __name__=='__main__':main()
