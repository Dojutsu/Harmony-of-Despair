
"""Local production directory plus three isolated native runtime processes.
No title launch, private inputs, live deployment, or player profile writes.
"""
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
    output = ROOT / 'out' / ('gameplay-integration-' + time.strftime('%Y%m%d-%H%M%S'))
    output.mkdir()
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
        log=(output/f'{role}.log').open('w');logs.append(log)
        processes.append(subprocess.Popen([str(ROOT/'out/reconcile-sdk/out/win-amd64/unit_tests.exe'),
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
        print('PASS: production discovery/admission/completion -> three distinct gameplay sockets, all peer pairs, unchanged 39-byte bidirectional payloads')
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
