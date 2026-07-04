# Project cmake list file

cmake_minimum_required(VERSION 4.0.2)

option(PURE_LOG_USE_MODULES "Build Pure Log with C++ module interfaces instead of legacy headers." ON)
option(PURE_LOG_IMPORT_STD "Use import std in Pure Log module builds instead of standard library header includes." ON)
option(BUILD_EXAMPLE "Build the Pure Log example executable." OFF)

if(PURE_LOG_IMPORT_STD AND NOT PURE_LOG_USE_MODULES)
    message(FATAL_ERROR "PURE_LOG_IMPORT_STD requires PURE_LOG_USE_MODULES to be enabled.")
endif()

if(PURE_LOG_IMPORT_STD AND NOT DEFINED CMAKE_EXPERIMENTAL_CXX_IMPORT_STD)
    # CMake intentionally changes this token between experimental import-std revisions.
    set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(
    "Pure Log"
    VERSION 1.0.0
    DESCRIPTION "A simple and efficient C++ logging library."
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ${PURE_LOG_USE_MODULES})

message(STATUS "Selected C++ Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Pure Log Uses Modules: ${PURE_LOG_USE_MODULES}")
message(STATUS "Pure Log Imports std Module: ${PURE_LOG_IMPORT_STD}")
message(STATUS "Building Examples: ${BUILD_EXAMPLE}")

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(
        -Wno-inline-namespace-reopened-noninline
        -Wno-backslash-newline-escape
    )
endif()

# if(PURE_LOG_USE_MODULES AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#     # GCC 16.1.0 can ICE while emitting Debug DWARF for imported module types.
#     add_compile_options("$<$<CONFIG:Debug>:-g0>")
# endif()

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(INCLUDE "${ROOT_DIR}/include")
set(PURE_LOG "${ROOT_DIR}/pureLog")
set(EXAMPLE "${ROOT_DIR}/example")

add_subdirectory(${PURE_LOG})

if(BUILD_EXAMPLE)
    add_subdirectory(${EXAMPLE})
endif()
