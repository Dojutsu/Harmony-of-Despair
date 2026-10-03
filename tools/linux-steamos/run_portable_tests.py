#!/usr/bin/env python3
"""Run exact, reviewed native SDK cases and retain every failure or skip receipt.

Outputs belong outside this source worktree. Default modes exclude broadcast and
hidden fixtures. A successful run with the four existing stream skips is labelled
PASS_WITH_KNOWN_SOURCE_SKIPS, never full serialization or multiplayer validation.
"""
from __future__ import annotations

import argparse
from collections import Counter
from datetime import datetime, timezone
import hashlib
import json
import math
import os
from pathlib import Path
import signal
import socket
import subprocess
import sys
import time
import xml.etree.ElementTree as ET


# The helper can also be copied into a source-free disposable test bundle.
SOURCE_ROOT = next((parent for parent in Path(__file__).resolve().parents
                    if (parent / "CMakeLists.txt").is_file()
                    and (parent / "include/rex").is_dir()
                    and (parent / "tests/unit").is_dir()), None)
DEFAULT_MODES = ("model", "loopback", "filesystem", "serialization")
MODES = (*DEFAULT_MODES, "isolated-broadcast")
MAX_RECEIPT_BYTES = 16 * 1024 * 1024


def utc_now():
    return datetime.now(timezone.utc).isoformat()


def write_json(path, value):
    temporary = path.with_suffix(path.suffix + ".tmp")
    temporary.write_text(json.dumps(value, indent=2) + "\n", encoding="utf-8")
    temporary.replace(path)


def load_manifest(path):
    data = json.loads(path.read_text(encoding="utf-8"))
    if data.get("schema_version") != 1:
        raise ValueError("unsupported selector manifest schema")
    cases = data["cases"]
    names = [case["name"] for case in cases]
    if not cases or len(names) != len(set(names)):
        raise ValueError("selector names must be nonempty and unique")
    for case in cases:
        source = Path(case["source"])
        if (not case["name"] or "\n" in case["name"] or source.is_absolute()
                or ".." in source.parts or not str(source).startswith("tests/unit/")):
            raise ValueError("invalid case name or source ownership path")
        if case["mode"] not in (*MODES, "deferred"):
            raise ValueError("unknown case mode")
    counts = dict(Counter(case["mode"] for case in cases))
    if counts != data["expected_mode_counts"]:
        raise ValueError("selector manifest counts do not match its cases")
    return data


def exact_selector(name):
    # Escape Catch controls, not shell characters: arguments never use a shell.
    return "".join("\\" + character if character in '\\,[]"~' else character
                   for character in name)


def checked_bytes(path):
    if path.stat().st_size > MAX_RECEIPT_BYTES:
        raise ValueError("receipt exceeds the parser size bound")
    return path.read_bytes()


def parse_discovery(path):
    data = json.loads(checked_bytes(path))
    tests = data["listings"]["tests"]
    names = [test["name"] for test in tests]
    if any(not isinstance(name, str) or not name for name in names):
        raise ValueError("invalid discovered name")
    if len(names) != len(set(names)):
        raise ValueError("duplicate discovered names")
    return names


def parse_junit(path, expected_name, known_skip_reason=None):
    root = ET.fromstring(checked_bytes(path))
    suites = list(root.iter("testsuite"))
    rows = list(root.iter("testcase"))
    if not suites or not rows:
        raise ValueError("JUnit has no test suite or case receipts")
    # Catch emits one row per section, not one row per TEST_CASE. Its suite
    # `tests` attribute counts assertions, so discovery owns case counting.
    unexpected = [row.get("name", "") for row in rows
                  if row.get("name") != expected_name
                  and not row.get("name", "").startswith(expected_name + "/")]
    if unexpected:
        raise ValueError("JUnit contains an unexpected test or section name")
    totals = {}
    for attribute in ("tests", "failures", "errors", "skipped"):
        values = [int(suite.get(attribute, "0")) for suite in suites]
        if any(value < 0 for value in values):
            raise ValueError("negative JUnit counter")
        totals[attribute] = sum(values)
    if totals["tests"] < 1:
        raise ValueError("JUnit records no assertions")
    failure_nodes = [node for node in root.iter()
                     if node.tag in ("failure", "error", "internalError")]
    skip_nodes = list(root.iter("skipped"))
    skips = [{"message": node.get("message", ""), "type": node.get("type", ""),
              "detail": "".join(node.itertext())} for node in skip_nodes]
    result = {"assertion_counters": totals, "section_rows": len(rows),
              "failure_nodes": len(failure_nodes), "skips": skips}
    if failure_nodes or totals["failures"] or totals["errors"]:
        result["status"] = "FAIL"
    elif skip_nodes or totals["skipped"]:
        known = (known_skip_reason and skip_nodes and
                 all(skip["type"] == "SKIP" and
                     known_skip_reason in skip["detail"] for skip in skips))
        result["status"] = "SKIPPED_SOURCE_DEFECT" if known else "UNEXPECTED_SKIP"
    else:
        result["status"] = "PASS"
    return result


def apply_exit_status(result, returncode):
    # Catch 3.12 returns 4 when the one selected case explicitly skips.
    # This exception requires the exact known-source SKIP, never an empty run,
    # unexpected skip, !mayfail failure, crash, or invalid/unmatched selector.
    acceptable = (0, 4) if result["status"] == "SKIPPED_SOURCE_DEFECT" else (0,)
    if returncode not in acceptable and result["status"] in ("PASS", "SKIPPED_SOURCE_DEFECT"):
        result["status"] = "FAIL_EXIT"
    return result


def child_environment(case_directory):
    env = dict(os.environ)
    for key in list(env):
        if (key.startswith(("REX_", "HARMONY_GAMEPLAY_"))
                or key.lower() in ("http_proxy", "https_proxy", "all_proxy", "no_proxy")):
            del env[key]
    # These overrides affect only the disposable child, never the user's settings.
    # Keep the caller's verified loader paths (notably chroot LD_LIBRARY_PATH).
    for variable, child in (("TMPDIR", "tmp"), ("XDG_CONFIG_HOME", "config"),
                            ("XDG_DATA_HOME", "data"), ("XDG_CACHE_HOME", "cache")):
        path = case_directory / child
        path.mkdir()
        env[variable] = str(path)
    return env


def stop_process(process):
    if process.poll() is not None:
        return
    try:
        os.killpg(process.pid, signal.SIGTERM)
    except ProcessLookupError:
        process.wait()
        return
    try:
        process.wait(timeout=1)
    except subprocess.TimeoutExpired:
        try:
            os.killpg(process.pid, signal.SIGKILL)
        except ProcessLookupError:
            pass
        process.wait()


def run_process(argv, directory, env, timeout, receipt_prefix):
    started = time.monotonic()
    stdout = directory / (receipt_prefix + ".stdout")
    stderr = directory / (receipt_prefix + ".stderr")
    timed_out = False
    with stdout.open("wb") as out, stderr.open("wb") as err:
        process = subprocess.Popen(argv, cwd=directory, env=env, stdout=out,
                                   stderr=err, start_new_session=True)
        try:
            process.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            timed_out = True
            stop_process(process)
        except BaseException:
            stop_process(process)
            raise
    return {"argv": argv, "returncode": process.returncode, "timed_out": timed_out,
            "duration_seconds": time.monotonic() - started,
            "stdout": str(stdout), "stderr": str(stderr)}


def network_receipt():
    interfaces = sorted(name for _, name in socket.if_nameindex())
    return {"interfaces": interfaces,
            "verified_loopback_only": bool(interfaces) and set(interfaces) == {"lo"}}


def is_source_output(directory):
    if SOURCE_ROOT is None:
        return False
    # BuildServer's development root can appear through more than one mount path.
    return any(parent.exists() and os.path.samefile(parent, SOURCE_ROOT)
               for parent in (directory, *directory.parents))


def result_status(results, interrupted=False):
    if interrupted:
        return "INTERRUPTED"
    if any(result["status"] not in ("PASS", "SKIPPED_SOURCE_DEFECT") for result in results):
        return "FAIL"
    if any(result["status"] == "SKIPPED_SOURCE_DEFECT" for result in results):
        return "PASS_WITH_KNOWN_SOURCE_SKIPS"
    return "PASS"


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--test-binary", required=True, type=Path)
    parser.add_argument("--report-dir", required=True, type=Path,
                        help="new or empty output directory outside this source worktree")
    parser.add_argument("--manifest", type=Path,
                        default=Path(__file__).with_name("portable-test-selectors.json"))
    parser.add_argument("--mode", action="append", choices=MODES,
                        help="repeat to combine modes; defaults to model/loopback/filesystem/serialization")
    parser.add_argument("--timeout", type=float, default=60,
                        help="per-case wall bound in seconds, greater than zero and at most 60")
    parser.add_argument("--nohostnet", action="store_true",
                        help="caller asserts an isolated network namespace; runner verifies only lo exists")
    parser.add_argument("--list-only", action="store_true",
                        help="verify all exact selectors without running test assertions")
    args = parser.parse_args(argv)
    if not sys.platform.startswith("linux"):
        parser.error("this runner is for native Linux tests")
    if not math.isfinite(args.timeout) or not 0 < args.timeout <= 60:
        parser.error("--timeout must be finite, greater than zero, and at most 60")
    modes = list(dict.fromkeys(args.mode or DEFAULT_MODES))
    binary = args.test_binary.resolve()
    directory = args.report_dir.resolve()
    if not binary.is_file() or not os.access(binary, os.X_OK):
        parser.error("--test-binary must be an existing executable")
    if is_source_output(directory):
        parser.error("--report-dir must be outside this source worktree")
    if directory.exists() and any(directory.iterdir()):
        parser.error("--report-dir must be empty; existing receipts will not be overwritten")
    try:
        manifest = load_manifest(args.manifest)
        network = network_receipt()
    except (OSError, KeyError, TypeError, ValueError) as error:
        parser.error(str(error))
    if "isolated-broadcast" in modes and not args.nohostnet:
        parser.error("broadcast mode requires explicit --nohostnet and a loopback-only namespace")
    if args.nohostnet and not network["verified_loopback_only"]:
        parser.error("--nohostnet could not be verified: native interfaces are not only lo")

    directory.mkdir(parents=True, exist_ok=True)
    selected = [case for case in manifest["cases"] if case["mode"] in modes]
    deferred = [case for case in manifest["cases"] if case["mode"] == "deferred"]
    not_selected = [{"name": case["name"], "mode": case["mode"], "reason": "NOT_SELECTED_MODE"}
                    for case in manifest["cases"]
                    if case["mode"] not in modes and case["mode"] != "deferred"]
    summary = {"schema_version": 1, "started_utc": utc_now(), "status": "RUNNING",
               "test_binary": str(binary), "binary_sha256": hashlib.sha256(binary.read_bytes()).hexdigest(),
               "manifest_sha256": hashlib.sha256(args.manifest.read_bytes()).hexdigest(),
               "modes": modes, "requested_case_count": len(selected), "list_only": args.list_only,
               "network": network, "results": [], "deferred": deferred,
               "not_selected": not_selected,
               "scope": "Selected native Linux cases; not Windows, game, WAN, or multiplayer acceptance"}
    summary_path = directory / "SUMMARY.json"
    write_json(summary_path, summary)
    interrupted = False
    try:
        discovery_dir = directory / "inventory"
        discovery_dir.mkdir()
        inventory = run_process([str(binary), "*", "--list-tests", "--reporter", "json"],
                                discovery_dir, child_environment(discovery_dir), 10, "all")
        if inventory["timed_out"] or inventory["returncode"]:
            raise ValueError("complete binary discovery failed or timed out")
        discovered = parse_discovery(Path(inventory["stdout"]))
        missing = [case["name"] for case in manifest["cases"]
                   if case.get("linux_compiled_expected", True) and case["name"] not in discovered]
        wrongly_compiled = [case["name"] for case in deferred
                            if not case["linux_compiled_expected"] and case["name"] in discovered]
        summary["discovery"] = {"process": inventory, "total_binary_cases": len(discovered),
                                "reviewed_linux_expected": sum(case.get("linux_compiled_expected", True)
                                                               for case in manifest["cases"]),
                                "missing_reviewed_cases": missing,
                                "unexpected_platform_cases": wrongly_compiled}
        if missing or wrongly_compiled:
            raise ValueError("compiled inventory differs from the reviewed Linux selectors")
        for index, case in enumerate(selected, 1):
            slug = "".join(character if character.isalnum() else "-" for character in case["name"])
            case_dir = directory / f"{index:03d}-{slug[:48]}-{hashlib.sha256(case['name'].encode()).hexdigest()[:8]}"
            case_dir.mkdir()
            env = child_environment(case_dir)
            result = {"name": case["name"], "mode": case["mode"], "source": case["source"]}
            selector = exact_selector(case["name"])
            discovery = run_process([str(binary), selector, "--list-tests", "--reporter", "json"],
                                    case_dir, env, 10, "discovery")
            result["discovery"] = discovery
            try:
                found = parse_discovery(Path(discovery["stdout"]))
                if discovery["timed_out"] or discovery["returncode"] or found != [case["name"]]:
                    raise ValueError("exact selector did not discover its one intended case")
            except (OSError, KeyError, TypeError, ValueError) as error:
                result.update(status="DISCOVERY_FAIL", detail=str(error))
            else:
                if args.list_only:
                    result["status"] = "PASS"
                    result["assertions_executed"] = False
                else:
                    xml_path = case_dir / "result.junit.xml"
                    process = run_process([str(binary), selector, "--reporter", "junit",
                                           "--durations", "yes", "--order", "lex", "--rng-seed", "1",
                                           "--warn", "UnmatchedTestSpec", "--out", str(xml_path)],
                                          case_dir, env, args.timeout, "native")
                    result.update(process=process, junit=str(xml_path), assertions_executed=True)
                    if process["timed_out"]:
                        result["status"] = "TIMEOUT"
                    else:
                        try:
                            result.update(parse_junit(xml_path, case["name"], case.get("known_skip_reason")))
                        except (OSError, TypeError, ValueError, ET.ParseError) as error:
                            result.update(status="INVALID_JUNIT", detail=str(error))
                        apply_exit_status(result, process["returncode"])
            summary["results"].append(result)
            write_json(summary_path, summary)
    except KeyboardInterrupt:
        interrupted = True
    except (OSError, KeyError, TypeError, ValueError) as error:
        summary["fatal_error"] = str(error)
    summary["completed_utc"] = utc_now()
    summary["counts"] = dict(Counter(result["status"] for result in summary["results"]))
    summary["completed_case_count"] = len(summary["results"])
    summary["not_run_selected_names"] = [case["name"] for case in selected[len(summary["results"]):]]
    summary["status"] = result_status(summary["results"], interrupted)
    if summary.get("fatal_error") or summary["not_run_selected_names"]:
        summary["status"] = "INTERRUPTED" if interrupted else "FAIL"
    if args.list_only and summary["status"] == "PASS":
        summary["status"] = "DISCOVERY_ONLY"
    write_json(summary_path, summary)
    print(json.dumps({key: summary[key] for key in
                      ("status", "requested_case_count", "completed_case_count", "counts")}
                     | {"summary": str(summary_path)}))
    return 130 if interrupted else 0 if summary["status"] in (
        "PASS", "PASS_WITH_KNOWN_SOURCE_SKIPS", "DISCOVERY_ONLY") else 1


if __name__ == "__main__":
    raise SystemExit(main())
