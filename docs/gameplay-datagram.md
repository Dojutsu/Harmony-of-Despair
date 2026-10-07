# Admitted gameplay datagram candidate

This isolated Linux codec is not integrated into the playable Full-Send package.
It uses the existing OpenSSL provider: HKDF-SHA256 derives separate AES256-GCM
keys for each link and direction. Provider references:
[HKDF](https://docs.openssl.org/3.0/man3/EVP_PKEY_CTX_set_hkdf_md/) and
[authenticated encryption](https://docs.openssl.org/3.0/man3/EVP_EncryptInit/).

A fresh admission link receives a random32-byte key through the existing
host-authorized HTTPS ticket channel, separately from visible NAT credentials.
The key is not written to logs, guest RAM, files or NAT control packets. Codec
objects have no key-export/copy/move API and cleanse derived keys on destruction.

The wire header contains HGDP, version1, direction0/1, big-endian header size32,
16-byte ephemeral link ID and a big-endian64-bit sequence. All32 header bytes are
AAD. Ciphertext is followed by a full16-byte GCM tag. Maximum wire length is65507,
maximum plaintext65459. This exposes packet length/timing and ephemeral route
identity; it does not authenticate external Xbox account ownership.

A direction key uses unique nonces: four zero bytes and the eight sequence
bytes. Sending burns the next sequence before provider calls, never wraps and
never reuses failures. An object must remain alive across ticket renewals.
Recreating an object with the same key/link/direction is forbidden by its owner.

Receiving authenticates into a private cleansed staging buffer. Failed parsing,
wrong key/link/direction, authentication failure and replay preserve caller output
and replay state. A256-packet bitmap admits bounded reordering and rejects copies.
Authenticated peek does not mark replay state; the socket receive lock serializes
peek/consume. No guest bytes are exposed before successful authentication.

Actual source/provider checks pass3464 assertions in10 standalone test cases in
Clang19/O2 and GCC14/ASan+UBSan, including forced provider failures. Eight codec
cases are registered in the SDK suite; the two provider-failure cases use a
standalone linker-interposition fixture with no production seam. Full ticket,
guest adapter, socket, integration and actual title qualification remain required.

The actual guest send adapters accept up to64 scatter descriptors. They sum
lengths in64bits before allocation, limit ordinaryUDP to65507bytes and admitted
UDP to65459bytes, and cap stream staging at16MiB. Guest32-bit ranges must remain
affine in host memory; descriptor, destination and payload reads are staged under
a brief mapping lease using own-process Linux kernel copies. IPv4 destinations
are exactly16bytes/AF_INET or null/length0 for a connected socket. Result and
OVERLAPPED write permissions are checked before I/O and rechecked before
publication, without holding a mapping lease across native I/O. Send errors
survive the existing pending-receive pump.

Qualification: a fresh fullSDK build passes474tests, including real guest memory
and socket adapters, authenticated peek/empty/truncation/source bounds, blocked
receive followed by admission, persistent renewal/replay and retired-link refusal.
A separate release/sanitized provider fixture passes3464assertions in10cases;
an independent stdlibHKDF/OpenSSL3.0.20 reference matches the actualOpenSSL3.5.6
wire bytes. The production admission fixture runs three separate native processes
and all three encrypted peer links through realXSocket APIs with preserved39-byte
synthetic payloads. It does not launch or qualify title gameplay. DefaultLAN
without directory admission remains an explicit separate transport limitation.
