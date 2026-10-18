# harmonyrecomp - ReXGlue Recompiled Project
#
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(harmonyrecomp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# This title's generated modules contain no native nonlocal-jump sites. Reuse
# the checked normal consumer only on the qualified Linux x86-64 target; SDK
# consumers elsewhere retain the default-OFF policy and authored C++ APIs.
if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_SYSTEM_PROCESSOR MATCHES "^(x86_64|AMD64|amd64)$")
    option(REXGLUE_FUNCTION_MEMORY_CONSUMER
        "Reuse checked consumers in the qualified Harmony generated functions" ON)
    # Generated guest code uses native loads/stores as on Windows; MMIO and
    # write-watch faults are serviced by the runtime exception handler chain.
    # This supersedes the checked consumer above for generated code.
    option(REXGLUE_LINUX_DIRECT_GUEST_MEMORY
        "Use native generated guest memory access on Linux x86-64" ON)
endif()

if(ANDROID)
    # Every shared library the APK ships (the game as libmain.so and the
    # per-module libraries) lands in one folder for packaging.
    set(HARMONY_ANDROID_LIB_DIR "${CMAKE_BINARY_DIR}/android-libs/arm64-v8a")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${HARMONY_ANDROID_LIB_DIR}")
endif()

include(generated/rexglue.cmake)

# rexruntime exposes public UI headers that include imgui.h, but its build-tree
# target does not forward the private rexui/imgui object-library usage requirements.
# Apply the workaround only when rexruntime is a real non-imported target from an
# in-tree ReXGlue build; installed SDKs provide a different target layout.
if(TARGET rexruntime AND TARGET imgui)
    get_target_property(_harmonyrecomp_rexruntime_imported rexruntime IMPORTED)
    if(NOT _harmonyrecomp_rexruntime_imported)
        target_include_directories(rexruntime INTERFACE
            "$<TARGET_PROPERTY:imgui,INTERFACE_INCLUDE_DIRECTORIES>")
    endif()
endif()

# Sources
set(HARMONYRECOMP_SOURCES
    src/main.cpp
    src/game_data.cpp
    src/scene_cache_hook.cpp
    src/team_search_diag_hooks.cpp
    src/chapter_unlock_hooks.cpp
)

if(WIN32)
    add_executable(harmonyrecomp WIN32 ${HARMONYRECOMP_SOURCES})
elseif(ANDROID)
    # SDLActivity loads the game as libmain.so and enters through SDL_main.
    add_library(harmonyrecomp SHARED ${HARMONYRECOMP_SOURCES})
    set_target_properties(harmonyrecomp PROPERTIES OUTPUT_NAME main)
else()
    add_executable(harmonyrecomp ${HARMONYRECOMP_SOURCES})
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    rexglue_setup_target(harmonyrecomp GPU_PLUGINS xenos
        ENTRYPOINT "${CMAKE_CURRENT_SOURCE_DIR}/src/linux_main.cpp")
    target_sources(harmonyrecomp PRIVATE src/linux_startup.cpp src/linux_graphics.cpp src/linux_title_capture.cpp
        src/linux_first_run.cpp src/dlc_manifest.cpp)
    # The opt-in Vulkan diagnostic includes the SDK's RenderDoc API header.
    target_link_libraries(harmonyrecomp PRIVATE renderdoc)
elseif(ANDROID)
    rexglue_setup_target(harmonyrecomp GPU_PLUGINS xenos
        ENTRYPOINT "${CMAKE_CURRENT_SOURCE_DIR}/src/android_main.cpp")
    target_link_libraries(harmonyrecomp PRIVATE SDL3::SDL3 android log)
    # The SDK's shared pieces (runtime, SDL, GPU plugin) join the game and its
    # module libraries in the packaging folder.
    add_custom_target(harmonyrecomp_android_libs ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory "${HARMONY_ANDROID_LIB_DIR}"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:rex::runtime>
            $<TARGET_FILE:SDL3::SDL3>
            $<TARGET_FILE:rex::gpu-xenos>
            "${HARMONY_ANDROID_LIB_DIR}"
        VERBATIM)
    add_dependencies(harmonyrecomp_android_libs harmonyrecomp)
    # First-run import for the start screen: the same steps as the PC's
    # harmonyrecomp-import --aggregate --install-dlc, called from Java.
    add_library(harmonyimport SHARED
        src/android_import.cpp
        src/game_data.cpp
        src/dlc_manifest.cpp
        thirdparty/crypto/sha256.cpp)
    target_include_directories(harmonyimport PRIVATE src thirdparty/crypto)
    target_link_libraries(harmonyimport PRIVATE rex::runtime log)
    add_dependencies(harmonyrecomp_android_libs harmonyimport)
else()
    rexglue_setup_target(harmonyrecomp GPU_PLUGINS xenos)
endif()

if(ANDROID)
    # Host-side tools and tests are not built for the device.
    return()
endif()

add_executable(harmonyrecomp-import
    tools/import_main.cpp
    src/game_data.cpp
    src/dlc_manifest.cpp
)
target_include_directories(harmonyrecomp-import PRIVATE src)
target_link_libraries(harmonyrecomp-import PRIVATE rex::runtime)
add_dependencies(harmonyrecomp harmonyrecomp-import)

# Bring your own DLC (BYO-DLC) import tool.
# Installs owned Harmony of Despair DLC packages into the ReXGlue
# marketplace-content layout without touching the verified base
# game_data_root.
add_executable(harmonyrecomp-dlc-import
    tools/dlc_import_main.cpp
    src/dlc_manifest.cpp
)
target_include_directories(harmonyrecomp-dlc-import PRIVATE src)
target_link_libraries(harmonyrecomp-dlc-import PRIVATE rex::runtime)
add_dependencies(harmonyrecomp harmonyrecomp-dlc-import)

# Read-only validation/extraction utility used to audit the source STFS package.
add_executable(stfs_inspect tools/stfs_inspect.cpp)
target_link_libraries(stfs_inspect PRIVATE rex::runtime)

include(CTest)
enable_testing()
# Generated call sites must retain the authoritative host-owned dispatch path.
# Installed SDKs do not include codegen source templates; the isolated source
# build checks every module as well as the synchronizer's preservation contract.
if(CMAKE_SYSTEM_NAME STREQUAL "Linux" AND
   EXISTS "${REXSDK_DIR}/resources/templates/codegen/_indirect_call.inja")
    find_package(Python3 REQUIRED COMPONENTS Interpreter)
    add_test(NAME indirect-dispatch-sync-tests
        COMMAND ${Python3_EXECUTABLE} -B
            "${CMAKE_CURRENT_SOURCE_DIR}/tools/linux-steamos/test_sync_indirect_dispatch.py")
    add_test(NAME indirect-dispatch-sync
        COMMAND ${Python3_EXECUTABLE} -B
            "${CMAKE_CURRENT_SOURCE_DIR}/tools/linux-steamos/sync_indirect_dispatch.py"
            --source "${CMAKE_CURRENT_SOURCE_DIR}" --sdk "${REXSDK_DIR}")
    set_tests_properties(indirect-dispatch-sync-tests indirect-dispatch-sync
        PROPERTIES LABELS "security;dispatch" TIMEOUT 30)
    add_test(NAME generated-support-sync-tests
        COMMAND ${Python3_EXECUTABLE} -B
            "${CMAKE_CURRENT_SOURCE_DIR}/tools/linux-steamos/test_sync_generated_support.py")
    add_test(NAME generated-support-sync
        COMMAND ${Python3_EXECUTABLE} -B
            "${CMAKE_CURRENT_SOURCE_DIR}/tools/linux-steamos/sync_generated_support.py"
            --source "${CMAKE_CURRENT_SOURCE_DIR}" --sdk "${REXSDK_DIR}")
    set_tests_properties(generated-support-sync-tests generated-support-sync
        PROPERTIES LABELS "security;codegen" TIMEOUT 30)
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_executable(linux_user_paths_tests tests/linux_user_paths_test.cpp)
    target_include_directories(linux_user_paths_tests PRIVATE src)
    add_test(NAME linux-user-paths COMMAND linux_user_paths_tests)

    # Compile the actual generated notification block with its authored hook.
    # A second copy removes only the hook to retain the original fault oracle.
    find_package(Python3 REQUIRED COMPONENTS Interpreter)
    set(_scene_cache_generated "${CMAKE_CURRENT_BINARY_DIR}/scene_cache_hook_generated.inc")
    set(_scene_cache_original "${CMAKE_CURRENT_BINARY_DIR}/scene_cache_hook_original.inc")
    add_custom_command(OUTPUT "${_scene_cache_generated}" "${_scene_cache_original}"
        COMMAND ${Python3_EXECUTABLE} -B
            "${CMAKE_CURRENT_SOURCE_DIR}/tests/extract_scene_cache_hook.py"
            --source "${CMAKE_CURRENT_SOURCE_DIR}/generated/default/harmonyrecomp_recomp.3.cpp"
            --config "${CMAKE_CURRENT_SOURCE_DIR}/default_tu2_overrides.toml"
            --output "${_scene_cache_generated}" --original-output "${_scene_cache_original}"
        DEPENDS tests/extract_scene_cache_hook.py default_tu2_overrides.toml
            generated/default/harmonyrecomp_recomp.3.cpp
        VERBATIM)
    add_executable(scene_cache_hook_tests tests/scene_cache_hook_test.cpp
        src/scene_cache_hook.cpp "${_scene_cache_generated}" "${_scene_cache_original}")
    target_include_directories(scene_cache_hook_tests PRIVATE src generated/default
        "${CMAKE_CURRENT_BINARY_DIR}")
    target_link_libraries(scene_cache_hook_tests PRIVATE rex::runtime)
    add_test(NAME scene-cache-hook COMMAND scene_cache_hook_tests)
    set_tests_properties(scene-cache-hook PROPERTIES LABELS "title;scene" TIMEOUT 30)
endif()
# DLC chapters chained after Chapter 6: pure rule tests over a fake guest image.
add_executable(chapter_unlock_tests tests/chapter_unlock_test.cpp)
target_include_directories(chapter_unlock_tests PRIVATE src)
add_test(NAME chapter-unlock COMMAND chapter_unlock_tests)
set_tests_properties(chapter-unlock PROPERTIES LABELS "title;chapters" TIMEOUT 30)

add_executable(game_data_tests
    tests/game_data_tests.cpp
    src/game_data.cpp
)
target_include_directories(game_data_tests PRIVATE src)
target_link_libraries(game_data_tests PRIVATE rex::runtime)
add_test(NAME game-data COMMAND game_data_tests)
set_tests_properties(game-data PROPERTIES TIMEOUT 90)

# Portable SHA-256 known-vector tests + reusable library target.
# harmonyrecomp-dlc-import consumes the same library so dlc_manifest.cpp
# can include "thirdparty/crypto/sha256.h" without a broad global include.
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/crypto/sha256.cpp")
    add_library(sha256_lib STATIC
        "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/crypto/sha256.cpp"
    )
    target_include_directories(sha256_lib PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/crypto"
    )

    add_executable(sha256_tests
        tests/sha256_test.cpp
    )
    target_link_libraries(sha256_tests PRIVATE sha256_lib)
    add_test(NAME sha256-known-vectors COMMAND sha256_tests)

    target_link_libraries(harmonyrecomp-dlc-import PRIVATE sha256_lib)
    target_link_libraries(harmonyrecomp-import PRIVATE sha256_lib)
    if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
        # The Linux first-run setup screen installs DLC in-process.
        target_link_libraries(harmonyrecomp PRIVATE sha256_lib)
    endif()

    add_executable(dlc_header_tests
        tests/dlc_header_test.cpp
        src/dlc_manifest.cpp
    )
    target_include_directories(dlc_header_tests PRIVATE src)
    target_link_libraries(dlc_header_tests PRIVATE rex::runtime sha256_lib)
    add_test(NAME dlc-marketplace-header COMMAND dlc_header_tests)
else()
    message(WARNING "SHA-256 test source not found")
endif()

# Explicit, asset-free runtime initialization; normal title startup is unchanged.
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_test(NAME linux-startup COMMAND harmonyrecomp --startup-probe
        "${CMAKE_CURRENT_BINARY_DIR}/startup-smoke.log")
    set_tests_properties(linux-startup PROPERTIES TIMEOUT 60)
endif()
