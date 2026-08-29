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
)

if(WIN32)
    add_executable(harmonyrecomp WIN32 ${HARMONYRECOMP_SOURCES})
else()
    add_executable(harmonyrecomp ${HARMONYRECOMP_SOURCES})
endif()

rexglue_setup_target(harmonyrecomp GPU_PLUGINS xenos)

add_executable(harmonyrecomp-import
    tools/import_main.cpp
    src/game_data.cpp
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
add_executable(game_data_tests
    tests/game_data_tests.cpp
    src/game_data.cpp
)
target_include_directories(game_data_tests PRIVATE src)
target_link_libraries(game_data_tests PRIVATE rex::runtime)
add_test(NAME game-data COMMAND game_data_tests)

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
else()
    message(WARNING "SHA-256 test source not found")
endif()
