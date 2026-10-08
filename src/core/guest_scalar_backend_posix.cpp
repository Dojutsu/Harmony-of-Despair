// Private Linux x86-64 backend compilation boundary. Keep the ownership and
// signal implementations unchanged; expose their ordinary scalar path to the
// optimizer without caching admission or bypassing the registered fault leaves.
#include "guest_access_posix.cpp"
#include "guest_memory_posix.cpp"
