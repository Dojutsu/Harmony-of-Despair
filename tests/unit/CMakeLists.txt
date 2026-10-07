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
    system/session_test.cpp
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

add_executable(accepted_invite_kernel_test kernel/accepted_invite_kernel_test.cpp)
target_link_libraries(accepted_invite_kernel_test PRIVATE rexruntime)
set_target_properties(accepted_invite_kernel_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY $<TARGET_FILE_DIR:rexruntime>)
add_test(NAME accepted_invite_kernel COMMAND accepted_invite_kernel_test)

# Fatal native faults are isolated in bounded child processes. This fixture
# targets the current Linux x86-64 startup ABI, not guest SEH unwind parity.
if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
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
