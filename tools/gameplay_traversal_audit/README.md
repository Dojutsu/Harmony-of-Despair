# Gameplay traversal evidence tools

`native_audit.cpp`, `server_audit.py`, and `run.py` preserve the original pre-fix
characterization. Passing them never meant gameplay or identity security was
accepted. The separate XUID repeat/leave/rejoin diagnostic remains unresolved.
Some server characterization expectations intentionally describe the old behavior.

The current acceptance fixture is `integration.py`. After building SDK `unit_tests`
with the canonical SDK patch, run from the Reconcile root:

```text
python -B -m tools.gameplay_traversal_audit.integration
python -B -m unittest tools.master_server.test_gameplay tools.master_server.test_server -q
out/reconcile-sdk/out/win-amd64/unit_tests.exe "[gameplay]" --reporter compact
```

The fixture uses a local production HTTP/UDP directory and three isolated native
processes. Only the edge-advertised address is emulated; real independent UDP
sockets perform discovery, authoritative admission and later gameplay traversal.
Signed LAN discovery is directed to a bound sink to exercise public-role traversal.
It verifies three peer pairs, unchanged 39-byte synthetic payloads, distinct
mapping ports, completed discovery retirement, and preserved slot counts.
It does not launch Harmony, prove physical NAT behavior, or accept WAN gameplay.
Temporary player state is redirected into its own timestamped output directory.

The new server requires `server.py` and sibling `gameplay.py` together. Live
service deployment was not performed by this task. Read the canonical
`HARMONY_RECOMP_CONTEXT.md` before deployment or a physical retest.

The test and production builds share runtime output. After any test rebuild,
restore the tests-off, pregenerated Clang 22.1.8 production configuration before
packaging. The September 28 candidate manifest records the final output hashes.
