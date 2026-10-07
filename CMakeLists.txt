# harmonyrecomp - ReXGlue Recompiled Project
#
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(harmonyrecomp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
)

if(WIN32)
    add_executable(harmonyrecomp WIN32 ${HARMONYRECOMP_SOURCES})
else()
    add_executable(harmonyrecomp ${HARMONYRECOMP_SOURCES})
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    rexglue_setup_target(harmonyrecomp GPU_PLUGINS xenos
        ENTRYPOINT "${CMAKE_CURRENT_SOURCE_DIR}/src/linux_main.cpp")
    target_sources(harmonyrecomp PRIVATE src/linux_startup.cpp src/linux_graphics.cpp src/linux_title_capture.cpp)
    # The opt-in Vulkan diagnostic includes the SDK's RenderDoc API header.
    target_link_libraries(harmonyrecomp PRIVATE renderdoc)
else()
    rexglue_setup_target(harmonyrecomp GPU_PLUGINS xenos)
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
