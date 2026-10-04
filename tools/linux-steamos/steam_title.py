#!/usr/bin/python3
"""Launch the existing immutable Harmony package only as its registered Steam entry."""
import argparse
from datetime import datetime, timezone
import json
import os
from pathlib import Path
import sys
import uuid
import deploy_graphics as h


def steam_identity(registration, proc_root=Path('/proc'), pid=None):
    pid = os.getpid() if pid is None else pid
    for _ in range(32):
        p = proc_root / str(pid)
        fields = (p / 'stat').read_text().rsplit(')', 1)[1].split()
        if (p / 'comm').read_text().strip() == 'reaper':
            args = (p / 'cmdline').read_bytes().split(b'\0')
            expected = ('AppId=' + str(registration['appid'])).encode()
            if b'SteamLaunch' in args and expected in args:
                if (p / 'exe').resolve() != Path(registration['reaper']).resolve():
                    raise ValueError('unexpected Steam reaper executable')
                return {'reaper_pid': pid, 'appid': registration['appid']}
        pid = int(fields[1])
        if pid <= 1:
            break
    raise ValueError('launch must originate from the registered Steam-managed entry')


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--root', type=Path, required=True)
    parser.add_argument('--build-id', required=True)
    parser.add_argument('--data-root', type=Path, required=True)
    parser.add_argument('--profile-root', type=Path, required=True)
    parser.add_argument('--timeout', type=int, default=300)
    parser.add_argument('--video-driver', choices=('wayland', 'x11'), default='wayland')
    parser.add_argument('--graphics-probe', action='store_true')
    args = parser.parse_args()
    if not 1 <= args.timeout <= 300:
        parser.error('timeout must be within 1..300 seconds')
    root = args.root.resolve(strict=True)
    registration_path = h.owned_path(root / 'bin/steam-entry.json', os.getuid(), 'file', True)
    registration = json.loads(registration_path.read_text())
    identity = steam_identity(registration)
    print(json.dumps({'stage': 'steam-launch', 'identity': identity}), flush=True)
    # Preserve actual Steam/reaper ancestry, while retaining verified Gaming Mode
    # sockets and the pinned package loader/library closure used in earlier runs.
    run_id = datetime.now(timezone.utc).strftime('steam-%Y%m%dT%H%M%SZ-') + uuid.uuid4().hex[:8]
    data = args.data_root.resolve(strict=True)
    profile = args.profile_root.resolve(strict=True)
    argv = ['--game_data_root=' + str(data), '--update_data_root=' + str(data),
            '--user_data_root=' + str(profile / 'saves'), '--cache_root=' + str(profile / 'cache'),
            '--harmony_config_root=' + str(profile / 'config'),
            '--log_file={run}/runtime.log', '--log_level=debug', '--no-fullscreen']
    ns = argparse.Namespace(root=str(root), build_id=args.build_id, run_id=run_id,
                            mode='gaming', executable='harmonyrecomp', arg=argv,
                            video_driver='wayland', allow_steam_virtual_gamepad=True,
                            timeout=args.timeout)
    if args.graphics_probe:
        ns.arg = ['--graphics-probe', '{run}/runtime.log']
    ns.video_driver = args.video_driver
    original_discovery = h.discover_session
    def steam_discovery(mode):
        session = original_discovery(mode)
        inherited = os.environ
        if inherited.get('XDG_RUNTIME_DIR') != session['environment']['XDG_RUNTIME_DIR']:
            raise ValueError('Steam runtime directory differs from verified Gaming Mode')
        environment = dict(session['environment'])
        for key in ('DISPLAY', 'XAUTHORITY'):
            if key in inherited:
                environment[key] = inherited[key]
        session['environment'] = h.validate_environment(environment, os.getuid())
        session['steam_identity'] = identity
        return session
    h.discover_session = steam_discovery
    try:
        h.remote_run(ns)
    finally:
        h.discover_session = original_discovery
    run = root / 'logs' / run_id
    if run.is_dir():
        (run / 'steam-launch.json').write_text(json.dumps({
            'owner': 'Harmony Steam title launcher', 'identity': identity,
            'inherited_environment': {k: os.environ[k] for k in
                ['SteamAppId', 'SteamGameId', 'SteamOverlayGameId', 'DISPLAY',
                 'WAYLAND_DISPLAY', 'XDG_RUNTIME_DIR', 'XDG_SESSION_ID'] if k in os.environ}
        }, indent=2) + '\n')
    receipt = json.loads((run / 'receipt.json').read_text())
    return receipt.get('exit_code', 1) if receipt.get('stage') == 'complete' else 1


if __name__ == '__main__':
    sys.exit(main())
