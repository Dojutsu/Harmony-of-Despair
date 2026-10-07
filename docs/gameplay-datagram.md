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
