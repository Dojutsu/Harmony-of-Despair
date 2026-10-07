# Private LAN invitation capabilities

This candidate authenticates possession of a private invitation bound to an
expected host XUID and one expected client XUID. It does not authenticate Xbox
Live ownership. The host owns up to five distinct grants; each client receives
only its own grant. Invited clients cannot use their grant to authenticate
another client's bootstrap identity.

Generate fresh grants locally, using the XUIDs already configured by the local
`user_xuid` profile setting:

```
python3 -B tools/private_lan_invitation.py \
  --directory /absolute/private/invitations \
  --host-xuid 0009000000000001 \
  --client-xuid 0009000000000002 \
  --client-xuid 0009000000000003
```

The directory must not exist. The generator creates it with mode 0700 and
writes `host.hpli` and one `client-<xuid>.hpli` per client with mode 0600. It
prints only file paths. Transfer each client's file through an existing trusted
private channel; treat that file as the invitation capability. Keep the host
file private. Files expire after one day by default; `--expires-in` accepts
1–604800 seconds. Generate a fresh set for a new invitation group.

The native loader requires an absolute path with no symlink or dot components,
a same-owner 0700 parent, a same-owner regular single-link non-executable private
file and exact bounded contents. It rejects expired/far-future invitations,
duplicate XUIDs, duplicate selectors/secrets, zero identity/key values and
trailing bytes. Key bytes have no public export API and are cleansed on object
destruction. The file path is suitable for configuration; the secret bytes are
never a cvar value, command-line argument, public discovery/session key or log
message.

Each possession proof is HMAC-SHA-256 truncated to 128 bits. Its domain includes
host and client XUIDs, invitation selector and expiry, explicit operation-domain
and transcript lengths, and every transcript byte. Comparisons use the crypto
provider's constant-time routine. Network callers must include exact session
incarnation, request challenge, ordered ephemeral keys, endpoints and roles,
and must validate fresh correlation before accepting a replayed proof.

Private tickets use the existing X25519/AES-256-GCM exchange with a separate
key-derivation domain and a 768-byte plaintext bound. The production wrapper
authenticates ordered recipient/server public keys, IV, ciphertext length,
ciphertext, tag and the complete caller-bound AAD with the matching private
invitation grant before decrypting or publishing plaintext. Decrypted bytes
have exclusive move ownership and are cleansed on destruction. The old
16-byte continuity envelope retains its original domain and behavior.

This checkpoint provides the tested file loader, possession proofs, authenticated
ticket-envelope component and local generator. The discovery/bootstrap and protected gameplay integration remain
active work; possession-proof unit tests alone do not establish playable LAN
multiplayer or authenticate an unauthenticated X25519 exchange.

## Private pair authority and direct routes

`PrivateLanAuthority` verifies a distinct expected-client invitation proof over the full title/session identity, machine, fresh challenge and request, recipient key and private gameplay endpoint. It issues fresh member generations and independent per-pair traffic keys, link IDs and capabilities. Exact retries retain these keys; departures tombstone the old challenge, and a fresh authenticated rejoin rotates only affected links. Exact-size private tickets bind the complete session fingerprint and reject duplicate identities, aliases, links, physical routes and invalid fields.

A verified ticket supplies `authenticated_lan_endpoint` to the existing gameplay authorization. Direct routes reuse the existing protected socket scope and cipher lifetime, avoid rendezvous/DNS/punching, ignore HNAT controls, reject public routes and refuse endpoint mutation during a retained link. This is a trusted local API, never a network-facing membership grant. Production LAN discovery has not yet been connected to this authority.

Validation at the foundation checkpoint: clean pinned Steam Runtime 4 SDK build and 477/477 CTests passed; standalone authority proof passed 434 checks in Clang release and GCC ASan/UBSan before the final direct-route integration. The independent three-process real XSocket fixture is being added separately; actual title gameplay has not run.
