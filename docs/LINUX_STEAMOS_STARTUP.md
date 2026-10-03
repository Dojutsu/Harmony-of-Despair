# Bounded native Linux startup on SteamOS

Build the L1 native Harmony ELF and its modules with the locked Steamrt4 runner described in [LINUX_STEAMOS_ENVIRONMENT.md](LINUX_STEAMOS_ENVIRONMENT.md). The startup probe reaches runtime, VM, TLS, fault-routing, native-module loading and the platform/renderer boundary, then shuts down. It does not launch guest gameplay or require private guest images.

The Linux-only invocation is:

```sh
harmonyrecomp --startup-probe /absolute/path/to/runtime.log
```

It writes SDK text logging to `runtime.log` and a separate structured trace to `runtime.log.jsonl`. A successful run ends with `process/exit` and `exit_code=0; bounded native startup complete; no game/playability claim`. A failed stage remains a failure; a lack of compositor access in headless SSH is not evidence against eventual graphical operation.

## Deployment bundle

Prepare a gzip tar containing only regular files under `bin/` and `lib/`, plus `manifest.json`. Dereference pinned SDK library symlinks while preparing the bundle; the deployment harness rejects archive links, devices, traversal, duplicate or undeclared files. The bundle requires:

- `bin/harmonyrecomp`, native title modules and its matching ReXGlue runtime/plugin libraries.
- `bin/linux_startup_test` and `bin/ld-linux-x86-64.so.2` from the locked build/runtime.
- The pinned SDK dependency closure under `lib/`, with no arbitrary BuildServer or Ally libraries substituted.

Manifest shape:

```json
{"schema":1,"build_id":"l1-example","files":{"bin/harmonyrecomp":{"sha256":"<64 lowercase hex digits>","mode":493}}}
```

List every payload file and its exact SHA-256/mode (493 is octal 0755); the manifest itself is excluded from `files`. Include provenance such as source SHAs, SDK/runtime/compiler versions and dependency pins as additional fields. Build IDs are immutable: reusing an ID requires an identical manifest and payload, rather than replacing an earlier build.

## BuildServer deployment and receipts

```sh
python3 -B tools/linux-steamos/deploy_startup.py \
  --target harmony-ally \
  --bundle /absolute/path/to/verified-startup.tar.gz \
  --output-directory /absolute/path/outside/source/ally-startup-receipts
```

The existing SSH configuration is used by default. Optional `--ssh-config`, `--identity` and `--known-hosts` select already configured BuildServer files; credential material is never bundled. Host-key checking remains strict. No packages, sudo, system partition, Steam, controller or boot changes are performed.

The authorized deployment root is `/home/deck/.local/share/harmony-dev`. The harness creates its ownership marker, immutable `builds/<build-id>/{bin,lib}`, and `logs/<run-id>`. It rejects an unmarked existing root and unknown `current` entries. The `current` symlink advances only after successful startup and SDK smoke tests. Builds and run logs remain available for review; upload staging files are removed.

Execution uses the bundled SDK ELF loader with an explicit `bin:lib` library path. Keeping the loader and native modules beside the title in `bin/` preserves executable-relative module resolution. Child HOME and TMPDIR are isolated within the run, the working directory is the run, and DISPLAY/Wayland/audio/session variables are omitted. Harmony is bounded to 60 seconds and the SDK startup test to 20 seconds; timed-out process groups receive termination followed by bounded kill if necessary. The harness records exit codes, signals, exact argv/environment and startup stage results.

Only the known stdout/stderr, SDK log, JSONL trace and receipts are copied back to BuildServer. The harness validates the JSONL schema, stage coverage and controlled final exit, not merely process launch. An unexpected failure produces a failure receipt and preserves diagnostic logs. Remote log directories may contain only this harness's isolated per-run HOME/TMPDIR; they do not alter the deck user's normal application state.

Run harness validation without SSH:

```sh
python3 -B -m unittest discover -s tools/linux-steamos -p test_deploy_startup.py
```
