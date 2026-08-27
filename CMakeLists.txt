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
)

if(WIN32)
    add_executable(harmonyrecomp WIN32 ${HARMONYRECOMP_SOURCES})
else()
    add_executable(harmonyrecomp ${HARMONYRECOMP_SOURCES})
endif()

rexglue_setup_target(harmonyrecomp GPU_PLUGINS xenos)

# Read-only validation/extraction utility used to audit the source STFS package.
add_executable(stfs_inspect tools/stfs_inspect.cpp)
target_link_libraries(stfs_inspect PRIVATE rex::runtime)
