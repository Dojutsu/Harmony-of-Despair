# Linux checked guest data-fault boundary

The Linux x86-64 backend owns only a registered guest access instruction, its
registered address interval, and the admitted read/write intent. It captures
SIGSEGV/SEGV_ACCERR into preallocated TLS, changes RIP to that same assembly
leaf's failure return, then returns normally. No C++ exception, decoder, lock,
allocation, MMIO callback or guest dispatch executes in signal context. All
other signals, native instructions, host payload/output faults and NX faults
chain through the existing prior/default action.

`ExecutionActivation` owns the retained first terminal fault. `AccessResult<T>`
relays its immutable token through `GatewayScope` without throwing. Only the
current activation on its original thread, with every nonthrowing gateway
returned, may consume that token. Normal C++ `DeliverFault` stores the same
access-violation code/address/read-write information used by the guest contract
and throws `SehException`. Pending overwrite, duplicate/stale/cross-thread
consumption, ignored results, continuation while pending and exit with an
unconsumed fault terminate with a contract diagnostic. These are runtime bugs,
not successful guest recovery.

## Admitted routes

| Route | Contract |
| --- | --- |
| Scalar 1/2/4/8-byte RAM | Page-contained checked read/write; no failed output/store commit |
| Generated vector access | Aligned 16-byte/page-contained checked load/store; preserves original SIMD value |
| Reservation load / aligned 32/64-bit CAS | Native RAM operation; mapped devices rejected before access; access failure distinct from compare mismatch |
| Forward nonoverlapping bulk | REP MOVSB remaining cursor; completed prefix retained; source and destination ownership declared separately |
| 32-bit MMIO | Normal-context callback once; synthesized read/ack completes helper without replay |
| 64-bit explicit MMIO | Existing high-word-first pair of 32-bit suboperations; no invented atomic device transaction |
| RAM/write watch | Existing PhysicalHeap repair/notification in normal context; retry unfinished access only |
| Typed HLE arguments/results | Tagged TryGet/TrySet/TryTranslate, original stack slots/endian; check before invoking export or committing result |
| Audited string/format and CRT hooks | Checked reads/writes/bulk; no recoverable guest pointer escapes into libc |
| Known compiled PPC/C++ calls | Ordinary exceptions after leaf return; dispatcher restores binding/LR/stack and trap state |
| Native guest thread entry | Contain guest faults, including initial APC callbacks, before returning through pthread |

Low `Capture*` primitives are runtime-internal/test infrastructure; production
call sites are confined to the checked memory backend. They are not general
guest fault transport APIs.

`Try*` APIs require an explicit activation. Throwing `Read`/`Write` convenience
APIs are for known exception-capable C++ callers only; they may establish a root
for direct tests/authored C++ use. They are not a safe foreign/noexcept callback
API. Such callbacks must use checked status transport and an explicit consumer,
or remain excluded. C linkage alone does not make a compiled C++ PPC function
nonthrowing.

Unconverted HLE raw pointers, runtime-owned cleanup metadata and unknown foreign
callbacks are **not** recovery leaves. Their native faults chain; they are not
silently translated into a guest exception. This is an admission manifest, not
complete HLE or title execution coverage. Renderer/audio/network callback
migration is outside this milestone. Guest CreateFiber/makecontext gateways are
explicitly refused before guest effects until a fiber-owned activation/foreign
containment contract is proven. Generic host fibers and their L0 tests remain
independent.

## Deferred completion and reentry

A transaction is bound to its activation. Completed native/emulated operations
cannot be completed or restarted twice. Unsupported mapped vector/atomic/bulk
operations are refused before device emulation, independently of current page
protection; bulk/fill intervals are checked before any guest prefix write.
Sparse-mask partial scalar/device overlap without a matching scalar base is
excluded rather than given invented MMIO semantics. A successful callback must make
protection progress before RAM retry. One deferred adjudication is allowed per
thread; checked access, child activation and low-level capture reentry are
refused before effects. Native callback faults chain without overwriting the
original record; a callback exception/ambiguous completion is terminal and is
never replayed. Failed explicit MMIO suboperations do not restart prior words.

Overlap memmove, arbitrary cross-page scalar/vector accesses, backward bulk,
split/unaligned/device atomics, physical read watches/providers and arbitrary
libc recovery are excluded. If title execution requires one, stop and establish
its separate progress/lifetime contract before admitting it.

## Platform scope

Windows retains its SEH/backend, HLE selection and native memory operations.
Shared emitted macro names have equivalent Windows definitions; no Windows
network or compiler behavior changes are intended. Actual Windows validation
remains independent.

Tokens, tagged transport and deferred transaction ownership are architecture
neutral. The implemented leaf instructions, initial-exec signal TLS, x86-64
ucontext/register extraction, XMM capture and REG_ERR intent are Linux x86-64
specific. Only registered startup-loaded runtime DSOs are admitted; late TLS/DSO
unload is not a supported fault boundary. Runtime imports are eagerly bound.
Linux ARM64 and Android need separately tested context/leaf mechanisms and
libc/loader/signal rules, without changing the higher-level contract.
