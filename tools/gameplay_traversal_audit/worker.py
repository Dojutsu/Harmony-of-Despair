"""Bounded loopback regression for the real directory worker and HTTP path."""
import argparse
import json
import os
from pathlib import Path
import subprocess
import threading
import time
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer

ROOT = Path(__file__).resolve().parents[2]

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--unit-tests', type=Path,
                        default=ROOT / 'out/reconcile-sdk/out/win-amd64/unit_tests.exe',
                        help='native unit_tests executable; defaults to the Windows build')
    parser.add_argument('--output-directory', type=Path,
                        help='new fixture output directory; defaults to out/gameplay-worker-TIMESTAMP')
    args = parser.parse_args()
    binary = args.unit_tests.resolve()
    output = (args.output_directory.resolve() if args.output_directory else
              ROOT / 'out' / ('gameplay-worker-' + time.strftime('%Y%m%d-%H%M%S')))
    output.mkdir()
    marker = output / 'pending'
    counts = {}
    active = 0
    maximum = 0
    lock = threading.Lock()

    class Handler(BaseHTTPRequestHandler):
        def do_POST(self):
            nonlocal active, maximum
            body = json.loads(self.rfile.read(int(self.headers['Content-Length'])))
            assert self.path == '/sessions/worker-test/gameplay/claim'
            user = body['xuid']
            with lock:
                counts[user] = counts.get(user, 0) + 1
                active += 1
                maximum = max(maximum, active)
            if int(user, 16) == 105:
                marker.touch()
                time.sleep(.25)
                marker.unlink()
            with lock:
                active -= 1
            self.send_response(403)
            self.send_header('Content-Length', '2')
            self.end_headers()
            self.wfile.write(b'{}')

        def log_message(self, *args):
            pass

    server = ThreadingHTTPServer(('127.0.0.1', 0), Handler)
    thread = threading.Thread(target=server.serve_forever)
    thread.start()
    try:
        env = dict(os.environ, HARMONY_GAMEPLAY_WORKER_URL=f'http://127.0.0.1:{server.server_port}',
                   HARMONY_GAMEPLAY_WORKER_PENDING=str(marker), LOCALAPPDATA=str(output/'profile'))
        result = subprocess.run([str(binary),
                                 '[.gameplay-worker]', '--reporter', 'compact'],
                                env=env, cwd=output, capture_output=True, text=True, timeout=20)
        (output/'native.log').write_text(result.stdout + result.stderr)
        print(result.stdout, result.stderr)
        assert result.returncode == 0, result.returncode
        assert len(counts) == 6 and all(n >= 2 for n in counts.values()), counts
        assert maximum == 1 and active == 0, (maximum, active)
        print(json.dumps({'requests_per_user': counts, 'maximum_in_flight': maximum,
                          'active_at_completion': active, 'native_returncode': result.returncode}))
        print('PASS: both driver modes; six queued users each; one worker; in-flight shutdown joined')
        print(output)
    finally:
        server.shutdown()
        server.server_close()
        thread.join()

if __name__ == '__main__':
    main()
