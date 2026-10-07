# Unit Tests for ReXGlue core components

add_executable(unit_tests
    test_memory.cpp
    audio/game_audio_capture_test.cpp
    memory/heap_allocation_test.cpp
    kernel/object_table_test.cpp
    kernel/xgi_app_test.cpp
    core/cvar_test.cpp
    core/fiber_test.cpp
    core/filesystem_test.cpp
    core/dynlib_test.cpp
    core/hash_test.cpp
    core/stream_test.cpp
    core/chrono_test.cpp
    ppc/import_function_test.cpp
    ppc/stack_test.cpp
    system/guest_path_test.cpp
    system/format_test.cpp
    system/achievement_manager_test.cpp
    system/function_dispatcher_test.cpp
    system/gameplay_traversal_test.cpp
    system/gameplay_datagram_test.cpp
    system/session_test.cpp
    system/session_arbitration_test.cpp
    system/session_arbitration_crypto_test.cpp
    system/session_arbitration_transport_test.cpp
    system/accepted_invite_test.cpp
    system/session_admission_test.cpp
    system/session_client_admission_test.cpp
    system/session_invite_grant_test.cpp
    system/online_status_test.cpp
    system/socket_test.cpp
    input/input_assignment_test.cpp
    codegen/codegen_writer_test.cpp
    codegen/output_partition_test.cpp
    codegen/output_stamp_test.cpp
    codegen/dispatch_table_layout_test.cpp
)

target_sources(unit_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/src/rexglue/ui/ui.cpp
    ${PROJECT_SOURCE_DIR}/src/rexglue/ui/progress.cpp
)

target_include_directories(unit_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/thirdparty
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(unit_tests PRIVATE
    rexcodegen
    rexruntime
    xxHash::xxhash
    Catch2::Catch2WithMain
)
if(WIN32)
    target_link_libraries(unit_tests PRIVATE ws2_32)
endif()

# ReXApp is shipped as source for recomp projects, rather than compiled into
# rexui. Keep its SDK-consumer compilation path covered by the test build.
add_library(rexapp_compile_test OBJECT
    ${PROJECT_SOURCE_DIR}/src/ui/rex_app.cpp
)
target_link_libraries(rexapp_compile_test PRIVATE
    rexruntime
    rexui
    rexinput
    rexaudio
)
add_dependencies(unit_tests rexapp_compile_test)

# Strip Tracy/profiling instrumentation from test targets
target_compile_options(unit_tests PRIVATE
    -UTRACY_ENABLE -UREXGLUE_ENABLE_PROFILING
    -UREXGLUE_ENABLE_PERF_COUNTERS -UREXGLUE_PROFILE_GUEST_FUNCTIONS
)

set_target_properties(unit_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>
)
if(UNIX AND NOT APPLE)
    set_target_properties(unit_tests PROPERTIES
        INSTALL_RPATH "$ORIGIN"
        BUILD_WITH_INSTALL_RPATH ON
    )
endif()

# Capture-only Vulkan resource lifetime policy uses Linux process fixtures.
if(REXGLUE_USE_VULKAN AND CMAKE_SYSTEM_NAME STREQUAL "Linux")
    find_package(Threads REQUIRED)
    add_executable(vulkan_capture_lifetime_test ui/vulkan_capture_lifetime_test.cpp)
    target_include_directories(vulkan_capture_lifetime_test PRIVATE
        ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
    target_link_libraries(vulkan_capture_lifetime_test PRIVATE Vulkan::Headers Threads::Threads renderdoc)
    set_target_properties(vulkan_capture_lifetime_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>)
    add_test(NAME vulkan_capture_lifetime COMMAND vulkan_capture_lifetime_test)
    set_tests_properties(vulkan_capture_lifetime PROPERTIES LABELS "vulkan;capture;lifetime" TIMEOUT 30)
endif()

# Discover tests
add_executable(online_status_lifecycle system/online_status_lifecycle.cpp)
target_link_libraries(online_status_lifecycle PRIVATE rexruntime)
target_include_directories(online_status_lifecycle PRIVATE ${PROJECT_SOURCE_DIR}/thirdparty)
set_target_properties(online_status_lifecycle PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>)

include(Catch)
if(WIN32 OR CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_executable(recvfrom_lifetime_test kernel/recvfrom_lifetime_test.cpp)
    target_include_directories(recvfrom_lifetime_test PRIVATE ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/thirdparty)
    target_link_libraries(recvfrom_lifetime_test PRIVATE rexruntime)
    if(WIN32)
        target_link_libraries(recvfrom_lifetime_test PRIVATE ws2_32)
    endif()
    set_target_properties(recvfrom_lifetime_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>)
    if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
        set_target_properties(recvfrom_lifetime_test PROPERTIES
            INSTALL_RPATH "$ORIGIN" BUILD_WITH_INSTALL_RPATH ON)
    endif()
    add_test(NAME recvfrom_lifetime COMMAND recvfrom_lifetime_test)
    set_tests_properties(recvfrom_lifetime PROPERTIES LABELS "network;guest_socket" TIMEOUT 60)
endif()
catch_discover_tests(unit_tests
    TEST_PREFIX "unit."
    PROPERTIES
        LABELS "unit"
        TIMEOUT 60
)

add_executable(xgi_slot_array_test kernel/xgi_slot_array_test.cpp)
target_link_libraries(xgi_slot_array_test PRIVATE rexruntime)
set_target_properties(xgi_slot_array_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>)
add_test(NAME xgi_slot_array COMMAND xgi_slot_array_test)

add_executable(xgi_arbitration_abi_test kernel/xgi_arbitration_abi_test.cpp)
target_link_libraries(xgi_arbitration_abi_test PRIVATE rexruntime)
target_compile_options(xgi_arbitration_abi_test PRIVATE -UREXGLUE_ENABLE_PROFILING)
set_target_properties(xgi_arbitration_abi_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>)
if(UNIX AND NOT APPLE)
    set_target_properties(xgi_arbitration_abi_test PROPERTIES
        INSTALL_RPATH "$ORIGIN" BUILD_WITH_INSTALL_RPATH ON)
endif()
add_test(NAME xgi_arbitration_abi COMMAND xgi_arbitration_abi_test)
set_tests_properties(xgi_arbitration_abi PROPERTIES TIMEOUT 30)

add_executable(accepted_invite_kernel_test kernel/accepted_invite_kernel_test.cpp)
target_link_libraries(accepted_invite_kernel_test PRIVATE rexruntime)
set_target_properties(accepted_invite_kernel_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>)
add_test(NAME accepted_invite_kernel COMMAND accepted_invite_kernel_test)

# Fatal native faults are isolated in bounded child processes. This fixture
# targets the current Linux x86-64 startup ABI, not guest SEH unwind parity.
if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
    add_executable(controller_ui_test ui/controller_ui_test.cpp)
    target_link_libraries(controller_ui_test PRIVATE rexruntime imgui::imgui)
    target_compile_options(controller_ui_test PRIVATE -UREXGLUE_ENABLE_PROFILING)
    set_target_properties(controller_ui_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>
        INSTALL_RPATH "$ORIGIN" BUILD_WITH_INSTALL_RPATH ON)
    add_test(NAME controller_ui COMMAND controller_ui_test)
    set_tests_properties(controller_ui PROPERTIES LABELS "linux;ui;input" TIMEOUT 60)

    # Compile the actual pure-C++ dispatch template, so tests cannot silently
    # diverge from the macro emitted into every recompiled module.
    configure_file(${PROJECT_SOURCE_DIR}/resources/templates/codegen/_indirect_call.inja
        ${CMAKE_CURRENT_BINARY_DIR}/indirect_call_test.inc COPYONLY)
    add_executable(indirect_dispatch_test system/indirect_dispatch_test.cpp)
    target_include_directories(indirect_dispatch_test PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
    target_link_libraries(indirect_dispatch_test PRIVATE rexruntime)
    target_compile_options(indirect_dispatch_test PRIVATE -UREXGLUE_ENABLE_PROFILING)
    set_target_properties(indirect_dispatch_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>
        INSTALL_RPATH "$ORIGIN" BUILD_WITH_INSTALL_RPATH ON)
    add_test(NAME indirect_dispatch COMMAND indirect_dispatch_test)
    set_tests_properties(indirect_dispatch PROPERTIES LABELS "linux;security;dispatch" TIMEOUT 60)

    add_executable(video_swap_test kernel/video_swap_test.cpp)
    target_link_libraries(video_swap_test PRIVATE rexruntime)
    set_target_properties(video_swap_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>
        INSTALL_RPATH "$ORIGIN" BUILD_WITH_INSTALL_RPATH ON)
    add_test(NAME video_swap COMMAND video_swap_test)
    set_tests_properties(video_swap PROPERTIES LABELS "linux;video;guest_fault" TIMEOUT 60)

    add_executable(linux_startup_test core/linux_startup_test.cpp)
    target_link_libraries(linux_startup_test PRIVATE rexruntime)
    set_target_properties(linux_startup_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>
        INSTALL_RPATH "$ORIGIN"
        BUILD_WITH_INSTALL_RPATH ON)
    add_test(NAME linux_startup COMMAND linux_startup_test)
    set_tests_properties(linux_startup PROPERTIES LABELS "linux;startup" TIMEOUT 60)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
    add_executable(guest_access_capture_test core/guest_access_capture_test.cpp)
    target_link_libraries(guest_access_capture_test PRIVATE rexruntime)
    set_target_properties(guest_access_capture_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>
        INSTALL_RPATH "$ORIGIN" BUILD_WITH_INSTALL_RPATH ON)
    add_test(NAME guest_access_capture COMMAND guest_access_capture_test)
    set_tests_properties(guest_access_capture PROPERTIES LABELS "linux;guest_fault" TIMEOUT 60)
    target_sources(unit_tests PRIVATE core/guest_fault_state_test.cpp system/mmio_recovery_test.cpp ppc/guest_gateway_fault_test.cpp)
endif()

# Production hardware-fault contract, isolated from test framework handlers.
if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
    add_executable(linux_guest_fault_test core/linux_guest_fault_test.cpp)
    target_link_libraries(linux_guest_fault_test PRIVATE rexruntime)
    target_link_options(linux_guest_fault_test PRIVATE "-Wl,-z,now")
    set_target_properties(linux_guest_fault_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>
        INSTALL_RPATH "$ORIGIN" BUILD_WITH_INSTALL_RPATH ON)
    add_test(NAME linux_guest_fault COMMAND linux_guest_fault_test)
    set_tests_properties(linux_guest_fault PROPERTIES LABELS "linux;guest_fault" TIMEOUT 60)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
    find_package(Python3 REQUIRED COMPONENTS Interpreter)
    add_test(NAME guest_access_template_compile
        COMMAND "${Python3_EXECUTABLE}" -B
            "${PROJECT_SOURCE_DIR}/tests/compile/guest_access_template_compile.py"
            --compiler "${CMAKE_CXX_COMPILER}")
    set_tests_properties(guest_access_template_compile PROPERTIES LABELS "linux;guest_fault;codegen" TIMEOUT 60)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_sources(unit_tests PRIVATE core/mapping_lease_test.cpp)
endif()

# Local opt-in scripted controller regression for unattended title validation.
target_sources(unit_tests PRIVATE input/scripted_input_test.cpp)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_sources(unit_tests PRIVATE core/private_backing_test.cpp)
    add_executable(object_wait_trace_test kernel/object_wait_trace_test.cpp)
    target_link_libraries(object_wait_trace_test PRIVATE rexruntime)
    target_compile_options(object_wait_trace_test PRIVATE -UREXGLUE_ENABLE_PROFILING)
    set_target_properties(object_wait_trace_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>
        INSTALL_RPATH "$ORIGIN" BUILD_WITH_INSTALL_RPATH ON)
    file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/object-wait-trace/artifacts")
    foreach(trace_mode alias-on alias-off last-on last-off release-failure)
        add_test(NAME object_wait_trace_${trace_mode} COMMAND object_wait_trace_test ${trace_mode})
        set_tests_properties(object_wait_trace_${trace_mode} PROPERTIES
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/object-wait-trace"
            LABELS "kernel;threading" TIMEOUT 15)
    endforeach()
endif()

# Optional local append-only controller fixture; no devices or network needed.
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_executable(scripted_input_reload_test input/scripted_input_reload_test.cpp)
    target_link_libraries(scripted_input_reload_test PRIVATE rexruntime)
    set_target_properties(scripted_input_reload_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>
        INSTALL_RPATH "$ORIGIN" BUILD_WITH_INSTALL_RPATH ON)
    add_test(NAME scripted_input_reload COMMAND scripted_input_reload_test)
    set_tests_properties(scripted_input_reload PROPERTIES LABELS "linux;input" TIMEOUT 20)
    find_package(Python3 REQUIRED COMPONENTS Interpreter)
    add_test(NAME scripted_input_append_helper
        COMMAND "${Python3_EXECUTABLE}" -B
            "${PROJECT_SOURCE_DIR}/tests/compile/scripted_input_append_test.py")
    set_tests_properties(scripted_input_append_helper PROPERTIES LABELS "linux;input" TIMEOUT 20)
endif()

# Each CLI case execs a fresh process; no registry reset hides startup behavior.
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_executable(cvar_cli_test core/cvar_cli_test.cpp)
    target_link_libraries(cvar_cli_test PRIVATE rexruntime)
    set_target_properties(cvar_cli_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>
        INSTALL_RPATH "$ORIGIN" BUILD_WITH_INSTALL_RPATH ON)
    add_test(NAME cvar_cli COMMAND cvar_cli_test)
    set_tests_properties(cvar_cli PROPERTIES LABELS "linux;cvar" TIMEOUT 20)
endif()

# Syscall interposition is confined to this native process, not unit_tests.
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_executable(linux_clock_test core/linux_clock_test.cpp)
    target_link_libraries(linux_clock_test PRIVATE rexruntime)
    set_target_properties(linux_clock_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>
        INSTALL_RPATH "$ORIGIN" BUILD_WITH_INSTALL_RPATH ON)
    add_test(NAME linux_clock COMMAND linux_clock_test)
    set_tests_properties(linux_clock PROPERTIES LABELS "linux;clock" TIMEOUT 20)
endif()

# This test needs the hidden signal-context marker without exposing a production
# test seam. Link one exact runtime object/dependency set into the executable;
# linking the shared runtime as well would create competing private TLS copies.
if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
    add_executable(function_memory_consumer_test core/function_memory_consumer_test.cpp
        system/mmio_classifier_equivalence_test.cpp
        $<TARGET_OBJECTS:rexruntime>)
    # The runtime finds curl in src/system; its imported target is scoped there.
    # This direct object consumer needs the same dependency in this directory.
    if(NOT TARGET CURL::libcurl)
        find_package(CURL REQUIRED)
    endif()
    if(NOT TARGET OpenSSL::Crypto)
        find_package(OpenSSL REQUIRED COMPONENTS Crypto)
    endif()
    get_target_property(_function_consumer_runtime_libraries rexruntime LINK_LIBRARIES)
    get_target_property(_function_consumer_runtime_includes rexruntime INCLUDE_DIRECTORIES)
    target_link_libraries(function_memory_consumer_test PRIVATE ${_function_consumer_runtime_libraries})
    target_include_directories(function_memory_consumer_test PRIVATE
        ${_function_consumer_runtime_includes} ${PROJECT_SOURCE_DIR}/thirdparty)
    target_link_options(function_memory_consumer_test PRIVATE "-Wl,-z,now" "-Wl,-z,text")
    set_target_properties(function_memory_consumer_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>
        INSTALL_RPATH "$ORIGIN" BUILD_WITH_INSTALL_RPATH ON)
    add_test(NAME function_memory_consumer COMMAND function_memory_consumer_test)
    set_tests_properties(function_memory_consumer PROPERTIES LABELS "linux;guest_fault;codegen" TIMEOUT 60)
endif()

# Native descriptor retirement uses real bounded blocking syscalls on loopback.
if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
    add_executable(socket_retirement_test system/socket_retirement_test.cpp)
    target_link_libraries(socket_retirement_test PRIVATE rexruntime)
    target_compile_options(socket_retirement_test PRIVATE -UREXGLUE_ENABLE_PROFILING)
    target_link_options(socket_retirement_test PRIVATE "-Wl,-z,now")
    set_target_properties(socket_retirement_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>
        INSTALL_RPATH "$ORIGIN" BUILD_WITH_INSTALL_RPATH ON)
    add_test(NAME socket_retirement COMMAND socket_retirement_test)
    set_tests_properties(socket_retirement PROPERTIES LABELS "linux;network;guest_socket" TIMEOUT 75)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
    add_executable(socket_retirement_race_test system/socket_retirement_race_test.cpp)
    target_link_libraries(socket_retirement_race_test PRIVATE rexruntime)
    target_compile_options(socket_retirement_race_test PRIVATE -UREXGLUE_ENABLE_PROFILING)
    target_link_options(socket_retirement_race_test PRIVATE "-Wl,-z,now")
    set_target_properties(socket_retirement_race_test PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>
        INSTALL_RPATH "$ORIGIN" BUILD_WITH_INSTALL_RPATH ON)
    add_test(NAME socket_retirement_race COMMAND socket_retirement_race_test)
    add_test(NAME socket_connect_retirement COMMAND socket_retirement_race_test --connect-close)
    add_test(NAME socket_accept_retirement COMMAND socket_retirement_race_test --accept-close)
    set_tests_properties(socket_retirement_race socket_connect_retirement socket_accept_retirement PROPERTIES LABELS "linux;network;guest_socket;security" TIMEOUT 15)
endif()
