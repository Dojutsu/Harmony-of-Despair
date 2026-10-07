# Opt-in generated Linux function memory consumers

`REXGLUE_FUNCTION_MEMORY_CONSUMER` defaults OFF. Enabling it through generated
`rexglue.cmake` defines the numeric flag only on generated Linux x86-64 targets
and their PCHs. An explicit preprocessor value0 retains the ordinary policy.
Regenerate all image PCHs and the generated CMake file from their canonical SDK
templates before enabling a build; preserve image metadata and instruction bodies.

The function prologue declares an unengaged, noncopyable normal consumer. Only
its first memory operation constructs the existing MemoryConsumer. It borrows
an existing activation, or retains one direct-call fallback root until normal
return or exception unwind. No captured-fault payload is initialized for a
no-memory function. Every operation retains the existing Try/ValueOrThrow path,
including strict signal/current-owner/phase/pending checks, registered leaves,
leases, MMIO, retries and partial effects. Authored Read/Write/Try APIs and foreign
nonthrowing boundaries remain unchanged. The authored trap helper establishes
its own lazy scope only inside its memory-consuming branch.

The scope belongs to one function/thread and must never cross a native nonlocal
jump. Generated PPC setjmp/longjmp forms are compilation errors when enabled.
Projects whose foreign callbacks can jump across generated frames must keep the
feature OFF. Do not suppress this guard or enable the definition globally on
arbitrary authored C++ code.

The permanent `function_memory_consumer` native test checks723 lifecycle/operation
assertions and bounded cached pending/adjudicating/signal children. It links the
exact runtime object/dependency set into one executable so the hidden production
signal-context marker is accessible without a production test export or competing
private TLS/backend copy. SIGUSR1 arrives after scope initialization; its handler
uses an async-safe marker, enters the existing signal context, and attempts a
cached-scope read. A normal exit139, signal0 and the entry marker prove the exact
strict backend refusal, separately from a native crash.

Private actual-title-source qualification compared17 complete generated functions,
288 collision and960 grid/containment/caller full-context/full64-KiB outcomes,
including direct no-owner calls and partial faults. The real no-memory function
retains identical16-byte machine code. An eager-prologue mutant fails its pending
owner case. Five interleaved exact5f4-runtime leaf medians measured5.26% lower local
CPU cost; this establishes no physical title/display/countdown improvement.
Full integrated builds, all existing memory regressions and a physical profile
remain required before claiming title performance improvement.
