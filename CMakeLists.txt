# Project cmake list file

cmake_minimum_required(VERSION 4.0.2)
    project(
        "Pure Log" 
        VERSION 1.0.0
        DESCRIPTION "A simple and efficient C++ logging library."
    LANGUAGES CXX 
)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Export compile commands for tools like clangd
set(CMAKE_CXX_SCAN_FOR_MODULES OFF) # No module support yet

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(
        -Wno-inline-namespace-reopened-noninline
        -Wno-backslash-newline-escape
    )
endif()

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(INCLUDE "${ROOT_DIR}/include")
set(PURE_LOG "${ROOT_DIR}/pureLog")
set(EXAMPLE "${ROOT_DIR}/example")

add_subdirectory(${PURE_LOG}) # Add package cmake list file

set(BUILD_EXAMPLE ON)
if(BUILD_EXAMPLE)
    add_subdirectory(${EXAMPLE}) # Add examples cmake list file   
endif()