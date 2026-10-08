#!/usr/bin/env python3
"""Exercise private invitation tickets and three real XSocket transports.

The fixture carries public claims and encrypted replies over private local test
files. It tests production grant, ticket, cipher and direct-route components;
it does not claim that production LAN discovery or actual title gameplay ran.
"""
from __future__ import annotations
import argparse
import json
import os
from pathlib import Path
import subprocess
import tempfile
import time
from private_lan_invitation import generate


def wait_for(paths: list[Path], processes: list[subprocess.Popen], seconds: float) -> None:
    deadline = time.monotonic() + seconds
    while time.monotonic() < deadline:
        failed = [(p.pid, p.poll()) for p in processes if p.poll() is not None]
        if failed:
            raise RuntimeError(f"Fixture process exited before validation: {failed}")
        if all(path.exists() for path in paths):
            return
        time.sleep(0.025)
    raise TimeoutError("Private LAN runtime fixture timed out")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--unit-tests", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    executable = args.unit_tests.resolve(strict=True)
    output = args.output.absolute()
    output.mkdir(parents=True, exist_ok=True)
    processes = []
    logs = []
    receipt = {"schema": 1, "passed": False, "actual_title_gameplay": False,
               "production_lan_discovery": False,
               "control_transport": "private fixture files containing public claims and encrypted replies",
               "gameplay_transport": "three independent production XSocket instances on loopback UDP",
               "components": ["private per-client grant possession", "authenticated ephemeral ticket envelope",
                              "full-session ticket parser", "per-pair datagram cipher", "trusted direct LAN routing"]}
    with tempfile.TemporaryDirectory(prefix="private-lan-runtime-", dir=output) as directory:
        fixture = Path(directory)
        os.chmod(fixture, 0o700)
        generate(fixture / "invitations", 1, [2, 3], 3600)
        generate(fixture / "wrong-invitations", 1, [2], 3600)
        started = time.monotonic()
        try:
            for role in [1, 2, 3]:
                profile = fixture / f"profile-{role}"
                profile.mkdir(mode=0o700)
                environment = os.environ.copy()
                environment.update(HARMONY_PRIVATE_LAN_FIXTURE=str(fixture),
                                   HARMONY_PRIVATE_LAN_ROLE=str(role), LOCALAPPDATA=str(profile))
                log = open(output / f"private-lan-{role}.log", "wb")
                logs.append(log)
                processes.append(subprocess.Popen([str(executable), "[.private-lan-integration]"],
                                                   env=environment, stdout=log, stderr=subprocess.STDOUT))
                if role == 1:
                    wait_for([fixture / "identity"], processes, 10)
            wait_for([fixture / f"{role}.ready" for role in [1, 2, 3]], processes, 15)
            receipt["all_six_directed_pairs"] = True
            wait_for([fixture / "rejected-2", fixture / "rejected-3"], processes, 5)
            receipt["wrong_grant_and_identity_spoof_rejected"] = True
            (fixture / "depart2").write_bytes(b"1")
            wait_for([fixture / "1.removed", fixture / "2.departed", fixture / "3.removed",
                      fixture / "retired-replay-rejected"], processes, 8)
            (fixture / "rejoin2").write_bytes(b"1")
            wait_for([fixture / f"{role}.rejoined" for role in [1, 2, 3]], processes, 10)
            receipt["runtime_departure_and_fresh_rejoin"] = True
            receipt["retired_join_replay_rejected"] = True
            # Continue through the original 30-second ticket lease. Subsequent
            # correlated replies must renew authority without resetting cipher
            # counters or replay windows.
            remaining = max(0, started + 35 - time.monotonic())
            while remaining > 0:
                if any(p.poll() is not None for p in processes):
                    raise RuntimeError("Fixture stopped before lease renewal validation")
                time.sleep(min(remaining, 0.1))
                remaining = max(0, started + 35 - time.monotonic())
            (fixture / "stop").write_bytes(b"1")
            codes = [p.wait(timeout=8) for p in processes]
            if codes != [0, 0, 0]:
                raise RuntimeError(f"Private LAN fixtures failed: {codes}")
            receipt.update(passed=True, return_codes=codes, elapsed_seconds=round(time.monotonic()-started, 3))
        except Exception as error:
            receipt["error"] = str(error)
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
            for log in logs:
                log.close()
            (output / "private-lan-runtime-validation.json").write_text(json.dumps(receipt, indent=2)+"\n")
    print(json.dumps(receipt, indent=2))
    return 0 if receipt["passed"] else 1

if __name__ == "__main__":
    raise SystemExit(main())
