# rexcore - Core utilities library
# Foundation types, data structures, and threading primitives

add_library(rexcore OBJECT
    arena.cpp
    bit_map.cpp
    bit_stream.cpp
    byte_stream.cpp
    clock.cpp
    cvar.cpp
    exception_handler.cpp
    filesystem.cpp
    filesystem_wildcard.cpp
    hash.cpp
    logging.cpp
    memory.cpp
    mutex.cpp
    ring_buffer.cpp
    string_buffer.cpp
    threading.cpp
    timer_queue.cpp
    utf8.cpp
    vec128.cpp
)
add_library(rex::core ALIAS rexcore)

if(APPLE)
    # Apple's libc++ still gates std::jthread/std::stop_token behind the
    # experimental-library feature flag. Only timer_queue.cpp uses them, and
    # neither type crosses a header boundary.
    set_source_files_properties(timer_queue.cpp PROPERTIES
        COMPILE_OPTIONS "-fexperimental-library")
    # The online session API (rex/system/xam/session.h, the invitation overlay
    # task and game audio capture) now carries std::stop_token/std::jthread
    # across public headers. When this libc++ still gates them, every
    # consumer needs the flag, so propagate it from the base library.
    include(CheckCXXSourceCompiles)
    check_cxx_source_compiles([=[
        #include <stop_token>
        #include <thread>
        int main() {
          std::stop_source source;
          std::jthread worker([](std::stop_token token) { (void)token.stop_requested(); });
          source.request_stop();
          return 0;
        }
    ]=] REX_LIBCXX_HAS_JTHREAD)
    if(NOT REX_LIBCXX_HAS_JTHREAD)
        target_compile_options(rexcore PUBLIC $<$<COMPILE_LANGUAGE:CXX>:-fexperimental-library>)
        target_link_options(rexcore PUBLIC -fexperimental-library)
    endif()
endif()

# Platform-specific sources
if(WIN32)
    target_sources(rexcore PRIVATE
        atomic_win.cpp
        clock_win.cpp
        dbg_win.cpp
        dynlib_win.cpp
        exception_handler_win.cpp
        filesystem_win.cpp
        fiber_win32.cpp
        mapped_memory_win.cpp
        math_msvc.cpp
        memory_win.cpp
        platform/console_win.cpp
        platform/env_win.cpp
        seh_win.cpp
        socket_win.cpp
        system_win.cpp
        threading_win.cpp
    )
    target_compile_definitions(rexcore PUBLIC NOMINMAX WIN32_LEAN_AND_MEAN)
elseif(UNIX)
    # Linux and macOS/Darwin share the POSIX sources; Darwin-specific behavior
    # is selected inside them with #if defined(__APPLE__).
    target_sources(rexcore PRIVATE
        atomic_posix.cpp
        clock_posix.cpp
        dbg_posix.cpp
        dynlib_posix.cpp
        exception_handler_posix.cpp
        filesystem_posix.cpp
        fiber_posix.cpp
        mapped_memory_posix.cpp
        math_gcc.cpp
        memory_posix.cpp
        platform/console_posix.cpp
        platform/env_posix.cpp
        seh_posix.cpp
        socket_posix.cpp
        system_posix.cpp
        threading_posix.cpp
    )
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_sources(rexcore PRIVATE mapping_lease_posix.cpp)
endif()

# The admitted Linux data-fault backend is x86-64 only. Other OS/architecture
# backends keep their existing independent source selection.
if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
    enable_language(ASM)
    # Compile the mutually dependent private scalar backend together so the
    # compiler can inline its ordinary capture path. All exported APIs, exact
    # fault leaves, per-operation admission, retries and MMIO checks remain.
    target_sources(rexcore PRIVATE guest_scalar_backend_posix.cpp guest_access_amd64.S guest_fault_state.cpp)

    if(CMAKE_CXX_COMPILER_ID MATCHES "^(GNU|Clang)$")
        # These checked-access paths live in the runtime's bounded PIC image.
        # Keep the large code model for generated host and guest DLL targets;
        # their independent link policy remains in rexglue_helpers.cmake.
        # Small PIC uses shorter image-relative references. Direct GOT calls
        # preserve the runtime's eager binding without PLT trampolines on each
        # guest access. The linker verifies the signed relocation range.
        set_property(SOURCE
            guest_scalar_backend_posix.cpp guest_fault_state.cpp
            memory_posix.cpp seh_posix.cpp
            APPEND PROPERTY COMPILE_OPTIONS -mcmodel=small -fno-plt)
    endif()
endif()

# Xenos data-format layer (stateless; headers under include/rex/graphics/).
# The GPU emulation consuming it lives in the rexgpu-xenos plugin.
target_sources(rexcore PRIVATE
    ${PROJECT_SOURCE_DIR}/src/graphics/xenos.cpp
    ${PROJECT_SOURCE_DIR}/src/graphics/pipeline/texture/info.cpp
    ${PROJECT_SOURCE_DIR}/src/graphics/pipeline/texture/info_formats.cpp
    ${PROJECT_SOURCE_DIR}/src/graphics/pipeline/texture/extent.cpp
    ${PROJECT_SOURCE_DIR}/src/graphics/pipeline/texture/util.cpp
    ${PROJECT_SOURCE_DIR}/src/graphics/pipeline/texture/conversion.cpp
)

target_include_directories(rexcore PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_include_directories(rexcore PRIVATE
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/thirdparty/cli11/include
)

if(APPLE)
    target_link_libraries(rexcore PRIVATE pthread)
elseif(UNIX)
    target_link_libraries(rexcore PRIVATE pthread rt dl)
endif()

target_link_libraries(rexcore
    PUBLIC
        fmt::fmt
        simde
        tomlplusplus
        spdlog::spdlog
    PRIVATE
        disruptorplus
        utf8cpp
        xxHash::xxhash
)

if(REXGLUE_USE_D3D12)
    target_compile_definitions(rexcore PUBLIC REX_HAS_D3D12=1)
endif()
if(REXGLUE_USE_VULKAN)
    target_compile_definitions(rexcore PUBLIC REX_HAS_VULKAN=1)
endif()

if(REXGLUE_ENABLE_TRACY)
    target_link_libraries(rexcore PUBLIC
        $<$<NOT:$<CONFIG:Release>>:$<TARGET_NAME:TracyClient>>)
    target_compile_definitions(rexcore PUBLIC
        $<$<NOT:$<CONFIG:Release>>:REXGLUE_ENABLE_PROFILING>)
endif()

if(REXGLUE_LINUX_DIRECT_GUEST_MEMORY AND CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(rexcore PUBLIC REXGLUE_DIRECT_GUEST_MEMORY=1)
endif()

if(REXGLUE_ENABLE_PERF_COUNTERS)
    target_sources(rexcore PRIVATE perf/counter.cpp)
    target_compile_definitions(rexcore PUBLIC
        $<$<NOT:$<CONFIG:Release>>:REXGLUE_ENABLE_PERF_COUNTERS>)
endif()
