# AI Handoff: Add Header Mode, Module Mode, CMake Presets, VS Code Tasks, And README Docs

Use this as the implementation brief for adding the same dual header/module build support that was added to Pure Log.

Baseline reference repo before these changes:
[HonestBlake/Pure-Log](https://github.com/HonestBlake/Pure-Log)

The target result is a C++23 library that can be consumed in either traditional header mode:

```cpp
#include <pureLog/pureLog.hpp>
```

or module mode:

```cpp
import pureLog;
```

Header mode should be the default. Module mode should be enabled with a CMake option.

## Core Technique

The implementation uses one public CMake target, `PureLog`, that changes its internals based on:

```cmake
PURE_LOG_USE_MODULES
```

When `PURE_LOG_USE_MODULES=OFF`, the library builds normally from `.cpp` files and public headers.

When `PURE_LOG_USE_MODULES=ON`, the library:

- Compiles the same implementation files as module implementation units.
- Adds `.mpp` files as CMake C++ module file sets.
- Defines `PURE_LOG_USE_MODULES=1`.
- Enables `CXX_SCAN_FOR_MODULES`.

This lets consumers link the same target name in both modes:

```cmake
target_link_libraries(MyApp PRIVATE PureLog)
```

## File Layout

Use this shape:

```txt
CMakeLists.txt
CMakePresets.json
README.md

.vscode/
  tasks.json
  configure-cmake.ps1
  select-cmake-compiler.ps1
  settings.json

include/
  pureLog/
    pureLog.hpp

pureLog/
  CMakeLists.txt
  stdIncludes.hpp
  pureLog.hpp
  pureLog.mpp

  log.hpp
  log.cpp
  log.mpp

  colors.hpp
  colors.cpp
  colors.mpp

  formatting.hpp
  formatting.mpp

  outputStream.hpp
  outputStream.cpp
  outputStream.tpp
  outputStream.mpp

  consoleOut.hpp
  consoleOut.cpp
  consoleOut.mpp

  fileOut.hpp
  fileOut.cpp
  fileOut.mpp

  logger.hpp
  logger.tpp
  logger.mpp
```

The `include/pureLog/pureLog.hpp` file is the public umbrella header. It forwards to the internal headers:

```cpp
#include "../../pureLog/pureLog.hpp"
#include "../../pureLog/log.hpp"
#include "../../pureLog/colors.hpp"
#include "../../pureLog/formatting.hpp"
#include "../../pureLog/outputStream.hpp"
#include "../../pureLog/consoleOut.hpp"
#include "../../pureLog/fileOut.hpp"
#include "../../pureLog/logger.hpp"
```

For another library, replace `pureLog` and `PureLog` with that library's namespace, module name, and target name.

## Header Pattern

Each public/internal header must work in both header mode and module mode.

Use a `MODULE_EXPORT` macro. In module mode, the `.mpp` file defines `INCLUDED_BY_MODULE` before including the header. That makes declarations exported. In normal header mode, the macro expands to nothing.

Example:

```cpp
#pragma once

#if defined(PURE_LOG_USE_MODULES) && defined(INCLUDED_BY_MODULE)
    #define MODULE_EXPORT export
#else
    #include "pureLog.hpp"
    #define MODULE_EXPORT
#endif

namespace pureLog {

    MODULE_EXPORT enum class Color: std::uint8_t {
        RED,
        GREEN,
        BLUE
    };

    MODULE_EXPORT struct Coloring {
        std::optional<Color> log;
        std::optional<Color> message;
    };

    MODULE_EXPORT class OutputStream {
    public:
        virtual ~OutputStream() = default;
        virtual void write(const std::string& text) = 0;
    };

}

#undef MODULE_EXPORT
```

For template-heavy headers, keep declarations in `.hpp` and definitions in `.tpp`, then include the `.tpp` at the bottom of the header:

```cpp
#undef MODULE_EXPORT

#include "logger.tpp"
```

The `.tpp` should only include the header in header mode:

```cpp
#pragma once

#ifndef PURE_LOG_USE_MODULES
    #include "logger.hpp"
#endif

namespace pureLog {

    template<class T_Derived>
    T_Derived& Logger<T_Derived>::get() {
        static T_Derived instance;
        return instance;
    }

}
```

## Module Interface Pattern

Each component gets a module partition file, usually `.mpp`.

Example `colors.mpp`:

```cpp
module;

#include "pureLog.hpp"

export module pureLog:colors;

#define INCLUDED_BY_MODULE
#include "colors.hpp"
#undef INCLUDED_BY_MODULE
```

Example `logger.mpp` with imports:

```cpp
module;

#include "pureLog.hpp"

export module pureLog:logger;

import :log;
import :colors;
import :formatting;
import :outputStream;
import :consoleOut;

#define INCLUDED_BY_MODULE
#include "logger.hpp"
#undef INCLUDED_BY_MODULE
```

The root module interface re-exports all partitions:

```cpp
module;

#include "pureLog.hpp"

export module pureLog;

export import :colors;
export import :consoleOut;
export import :fileOut;
export import :formatting;
export import :log;
export import :logger;
export import :outputStream;

export namespace pureLog {
    using ::pureLog::TimePoint;
}
```

## Implementation File Pattern

Each `.cpp` file must compile in both modes.

Example:

```cpp
#ifdef PURE_LOG_USE_MODULES
    module;

    #include "pureLog.hpp"

    module pureLog;

    import :colors;
#else
    #include "colors.hpp"
#endif

namespace pureLog {

    std::string ansi::getColorCode(const Color color) {
        if(auto node = COLOR_CODES.find(color); node != COLOR_CODES.end()) {
            return node->second;
        }

        return WHITE;
    }

}
```

Important detail:
Clang is stricter than GCC about the global module fragment. `module;` must be the first token in the generated module implementation file. The CMake setup below solves that by creating build-directory copies of `.cpp` files with `module;` moved to the top.

## Top-Level CMakeLists.txt

Use the top-level CMake file to define the project, options, module scanning, and subdirectories.

```cmake
cmake_minimum_required(VERSION 4.0.2)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(
    "Pure Log"
    VERSION 1.0.0
    DESCRIPTION "A simple and efficient C++ logging library."
    LANGUAGES CXX
)

option(PURE_LOG_USE_MODULES "Build Pure Log with C++ module interfaces instead of legacy headers." OFF)
option(BUILD_EXAMPLE "Build the Pure Log example executable." OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ${PURE_LOG_USE_MODULES})

message(STATUS "Selected C++ Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Pure Log Uses Modules: ${PURE_LOG_USE_MODULES}")
message(STATUS "Building Examples: ${BUILD_EXAMPLE}")

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

add_subdirectory(${PURE_LOG})

if(BUILD_EXAMPLE)
    add_subdirectory(${EXAMPLE})
endif()
```

## Library CMakeLists.txt

The library CMake file is the most important part.

It:

- Lists implementation files.
- Lists module interface files.
- Builds normal sources in header mode.
- Builds generated module-mode source copies in module mode.
- Registers `.mpp` files with `FILE_SET cxx_modules`.
- Keeps the target name stable as `PureLog`.

```cmake
function(move_global_module_fragment_to_top input output)
    file(READ "${input}" source)

    # Module builds need the global module fragment to be the first token.
    # Move any existing plain `module;` control line to the top of the generated file.
    string(REGEX REPLACE "(^|\n)[ \t]*module[ \t]*;[^\n]*(\n|$)" "\\1" source "${source}")

    get_filename_component(output_dir "${output}" DIRECTORY)
    file(MAKE_DIRECTORY "${output_dir}")
    file(WRITE "${output}" "module;\n\n${source}")

    set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${input}")
endfunction()

set(PURE_LOG_SOURCE_DIR "${PURE_LOG}")
set(PURE_LOG_HEADER_DIR "${PURE_LOG}")

set(PURE_LOG_IMPLEMENTATION_FILES
    "${PURE_LOG}/log.cpp"
    "${PURE_LOG}/colors.cpp"
    "${PURE_LOG}/outputStream.cpp"
    "${PURE_LOG}/consoleOut.cpp"
    "${PURE_LOG}/fileOut.cpp"
)

set(PURE_LOG_MODULE_FILES
    "${PURE_LOG}/pureLog.mpp"
    "${PURE_LOG}/log.mpp"
    "${PURE_LOG}/colors.mpp"
    "${PURE_LOG}/formatting.mpp"
    "${PURE_LOG}/outputStream.mpp"
    "${PURE_LOG}/consoleOut.mpp"
    "${PURE_LOG}/fileOut.mpp"
    "${PURE_LOG}/logger.mpp"
)

if(PURE_LOG_USE_MODULES)
    set(PURE_LOG_MODULE_SOURCE_FILES)

    foreach(SOURCE_FILE IN LISTS PURE_LOG_IMPLEMENTATION_FILES)
        get_filename_component(SOURCE_NAME "${SOURCE_FILE}" NAME)
        set(MODULE_SOURCE_FILE "${CMAKE_CURRENT_BINARY_DIR}/module-mode/${SOURCE_NAME}")

        move_global_module_fragment_to_top("${SOURCE_FILE}" "${MODULE_SOURCE_FILE}")
        list(APPEND PURE_LOG_MODULE_SOURCE_FILES "${MODULE_SOURCE_FILE}")
    endforeach()

    add_library(PureLog STATIC ${PURE_LOG_MODULE_SOURCE_FILES})
    target_compile_definitions(PureLog PRIVATE PURE_LOG_USE_MODULES=1)
    target_include_directories(PureLog PRIVATE "${PURE_LOG_HEADER_DIR}")

    set_source_files_properties(${PURE_LOG_MODULE_FILES} PROPERTIES LANGUAGE CXX)

    target_sources(PureLog
        PUBLIC
            FILE_SET cxx_modules
            TYPE CXX_MODULES
            BASE_DIRS "${PURE_LOG_SOURCE_DIR}"
            FILES ${PURE_LOG_MODULE_FILES}
    )

    set_target_properties(PureLog PROPERTIES CXX_SCAN_FOR_MODULES ON)
else()
    add_library(PureLog STATIC ${PURE_LOG_IMPLEMENTATION_FILES})
    set_target_properties(PureLog PROPERTIES CXX_SCAN_FOR_MODULES OFF)
endif()

target_include_directories(PureLog PUBLIC
    "${INCLUDE}"
    "${PURE_LOG_HEADER_DIR}"
)

target_compile_features(PureLog PUBLIC cxx_std_23)

if(PURE_LOG_USE_MODULES)
    set(PURE_LOG_OUTPUT_NAME "modules-pureLog")
else()
    set(PURE_LOG_OUTPUT_NAME "pureLog")
endif()

set_target_properties(PureLog PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${ROOT_DIR}/lib/$<LOWER_CASE:$<CONFIG>>"
    CXX_EXTENSIONS OFF
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    OUTPUT_NAME "${PURE_LOG_OUTPUT_NAME}"
    PREFIX ""
    SUFFIX ".lib"
)
```

## Example CMakeLists.txt

The example target also switches based on `PURE_LOG_USE_MODULES`.

```cmake
add_executable(Example
    "${EXAMPLE}/example.cpp"
)

target_link_libraries(Example PRIVATE PureLog)

if(PURE_LOG_USE_MODULES)
    target_compile_definitions(Example PRIVATE PURE_LOG_USE_MODULES=1)
    set_target_properties(Example PROPERTIES CXX_SCAN_FOR_MODULES ON)
else()
    set_target_properties(Example PROPERTIES CXX_SCAN_FOR_MODULES OFF)
endif()

if(PURE_LOG_USE_MODULES)
    set(PURE_LOG_EXAMPLE_OUTPUT_NAME "modules-example")
else()
    set(PURE_LOG_EXAMPLE_OUTPUT_NAME "example")
endif()

set_target_properties(Example PROPERTIES
    CXX_EXTENSIONS OFF
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    RUNTIME_OUTPUT_DIRECTORY "${EXAMPLE}/bin/$<LOWER_CASE:$<CONFIG>>"
    OUTPUT_NAME "${PURE_LOG_EXAMPLE_OUTPUT_NAME}"
)
```

The example source should choose include/import like this:

```cpp
#ifdef PURE_LOG_USE_MODULES
    import pureLog;
#else
    #include <pureLog/pureLog.hpp>
#endif

int main() {
    return 0;
}
```

## CMakePresets.json

Add presets for normal header builds, module builds, and a Clangd-friendly module configure.

```json
{
  "version": 6,
  "cmakeMinimumRequired": {
    "major": 4,
    "minor": 0,
    "patch": 2
  },
  "configurePresets": [
    {
      "name": "base",
      "hidden": true,
      "generator": "Ninja",
      "binaryDir": "${sourceDir}/build/${presetName}",
      "cacheVariables": {
        "BUILD_EXAMPLE": "ON",
        "CMAKE_EXPORT_COMPILE_COMMANDS": "ON"
      }
    },
    {
      "name": "Debug",
      "displayName": "Debug",
      "inherits": "base",
      "cacheVariables": {
        "CMAKE_BUILD_TYPE": "Debug",
        "PURE_LOG_USE_MODULES": "OFF",
        "BUILD_EXAMPLE": "ON"
      }
    },
    {
      "name": "Release",
      "displayName": "Release",
      "inherits": "base",
      "cacheVariables": {
        "CMAKE_BUILD_TYPE": "Release",
        "PURE_LOG_USE_MODULES": "OFF",
        "BUILD_EXAMPLE": "ON"
      }
    },
    {
      "name": "Debug-Modules",
      "displayName": "Debug Modules",
      "inherits": "base",
      "cacheVariables": {
        "CMAKE_BUILD_TYPE": "Debug",
        "PURE_LOG_USE_MODULES": "ON",
        "BUILD_EXAMPLE": "ON"
      }
    },
    {
      "name": "Release-Modules",
      "displayName": "Release Modules",
      "inherits": "base",
      "cacheVariables": {
        "CMAKE_BUILD_TYPE": "Release",
        "PURE_LOG_USE_MODULES": "ON",
        "BUILD_EXAMPLE": "ON"
      }
    },
    {
      "name": "Clangd-Modules",
      "displayName": "Clangd Modules",
      "inherits": "base",
      "cacheVariables": {
        "CMAKE_BUILD_TYPE": "Debug",
        "CMAKE_C_COMPILER": "C:/Program Files/MSYS2/mingw64/bin/clang.exe",
        "CMAKE_CXX_COMPILER": "C:/Program Files/MSYS2/mingw64/bin/clang++.exe",
        "PURE_LOG_USE_MODULES": "ON",
        "BUILD_EXAMPLE": "OFF"
      }
    }
  ],
  "buildPresets": [
    {
      "name": "Debug",
      "configurePreset": "Debug"
    },
    {
      "name": "Release",
      "configurePreset": "Release"
    },
    {
      "name": "Debug-Modules",
      "configurePreset": "Debug-Modules"
    },
    {
      "name": "Release-Modules",
      "configurePreset": "Release-Modules"
    },
    {
      "name": "Clangd-Modules",
      "configurePreset": "Clangd-Modules"
    }
  ]
}
```

## VS Code Tasks

Add `.vscode/tasks.json`:

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "CMake: Select GCC",
            "type": "process",
            "command": "powershell",
            "args": [
                "-NoProfile",
                "-ExecutionPolicy",
                "Bypass",
                "-File",
                "${workspaceFolder}/.vscode/select-cmake-compiler.ps1",
                "GCC"
            ],
            "problemMatcher": []
        },
        {
            "label": "CMake: Select Clang",
            "type": "process",
            "command": "powershell",
            "args": [
                "-NoProfile",
                "-ExecutionPolicy",
                "Bypass",
                "-File",
                "${workspaceFolder}/.vscode/select-cmake-compiler.ps1",
                "Clang"
            ],
            "problemMatcher": []
        },
        {
            "label": "CMake: Configure",
            "type": "process",
            "command": "powershell",
            "args": [
                "-NoProfile",
                "-ExecutionPolicy",
                "Bypass",
                "-File",
                "${workspaceFolder}/.vscode/configure-cmake.ps1",
                "${input:cmakeConfigurePreset}"
            ],
            "problemMatcher": []
        }
    ],
    "inputs": [
        {
            "id": "cmakeConfigurePreset",
            "type": "pickString",
            "description": "CMake configure preset",
            "default": "Debug",
            "options": [
                "Debug",
                "Release",
                "Debug-Modules",
                "Release-Modules",
                "Clangd-Modules"
            ]
        }
    ]
}
```

Add `.vscode/configure-cmake.ps1`:

```powershell
param(
    [Parameter(Mandatory = $true)]
    [string]$Preset
)

$ErrorActionPreference = "Stop"

$workspaceRoot = Resolve-Path (Join-Path $PSScriptRoot "..")
$settingsPath = Join-Path $PSScriptRoot "settings.json"

if(Test-Path $settingsPath){
    $settings = Get-Content -Raw $settingsPath | ConvertFrom-Json
    $configureEnvironment = $settings.PSObject.Properties["cmake.configureEnvironment"].Value

    if($configureEnvironment){
        foreach($entry in $configureEnvironment.PSObject.Properties){
            Set-Item -Path "env:$($entry.Name)" -Value $entry.Value
        }
    }
}

Push-Location $workspaceRoot
try{
    & cmake --fresh --preset $Preset
    exit $LASTEXITCODE
}finally{
    Pop-Location
}
```

Add `.vscode/select-cmake-compiler.ps1`:

```powershell
param(
    [Parameter(Mandatory = $true)]
    [ValidateSet("GCC", "Clang")]
    [string]$Compiler
)

$ErrorActionPreference = "Stop"

$settingsPath = Join-Path $PSScriptRoot "settings.json"

if(Test-Path $settingsPath){
    $rawSettings = Get-Content -Raw $settingsPath
    if([string]::IsNullOrWhiteSpace($rawSettings)){
        $settings = [pscustomobject]@{}
    }else{
        $settings = $rawSettings | ConvertFrom-Json
    }
}else{
    $settings = [pscustomobject]@{}
}

function Set-JsonProperty{
    param(
        [Parameter(Mandatory = $true)] [psobject]$Object,
        [Parameter(Mandatory = $true)] [string]$Name,
        [Parameter(Mandatory = $true)] $Value
    )

    $property = $Object.PSObject.Properties[$Name]
    if($property){
        $property.Value = $Value
    }else{
        $Object | Add-Member -NotePropertyName $Name -NotePropertyValue $Value
    }
}

$compilerEnvironment = switch($Compiler){
    "GCC" {
        [pscustomobject]@{
            CC = "C:/Program Files/MSYS2/mingw64/bin/gcc.exe"
            CXX = "C:/Program Files/MSYS2/mingw64/bin/g++.exe"
        }
    }
    "Clang" {
        [pscustomobject]@{
            CC = "C:/Program Files/MSYS2/mingw64/bin/clang.exe"
            CXX = "C:/Program Files/MSYS2/mingw64/bin/clang++.exe"
        }
    }
}

Set-JsonProperty $settings "cmake.configureArgs" @("--fresh")
Set-JsonProperty $settings "cmake.configureEnvironment" $compilerEnvironment

$settings | ConvertTo-Json -Depth 10 | Set-Content -Encoding utf8 $settingsPath

Write-Host "Selected CMake compiler: $Compiler"
Write-Host "CC=$($compilerEnvironment.CC)"
Write-Host "CXX=$($compilerEnvironment.CXX)"
```


## README Update Instructions

Update the README to document both build modes and how consumers use them.

Add a short intro:

```md
# Pure Log

A customizable, lightweight C++ logging library with traditional header builds and C++ module builds.
```

Add a base info section:

```md
## Base Info

- Language standard: C++23
- Minimum CMake version used by the project: 4.0.2
- Tested CMake version: 4.3.3
- Tested working compilers:
  - GCC 16.1.0, MSYS2 MinGW64
  - Clang 22.1.4, MSYS2 MinGW64
- Build output: static library target named `PureLog`
- Default build mode: header mode, unless `PURE_LOG_USE_MODULES` is enabled
```

Add mode examples:

````md
Header mode:

```cpp
#include <pureLog/pureLog.hpp>
```

Module mode:

```cpp
import pureLog;
```

The public logging API is the same after the include or import.
````

Add a quick start section that uses header mode first, then says:

````md
For module mode, replace the include with:

```cpp
import pureLog;
```
````

Add a CMake integration section with both `FetchContent` and `add_subdirectory`.

Header mode FetchContent:

```cmake
cmake_minimum_required(VERSION 4.0.2)
project(MyApp LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    PureLog
    GIT_REPOSITORY https://github.com/your-name/PureLog.git
    GIT_TAG main
)

set(PURE_LOG_USE_MODULES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(PureLog)

add_executable(MyApp main.cpp)
target_link_libraries(MyApp PRIVATE PureLog)
target_compile_features(MyApp PRIVATE cxx_std_23)
```

Module mode FetchContent:

```cmake
cmake_minimum_required(VERSION 4.0.2)
project(MyApp LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    PureLog
    GIT_REPOSITORY https://github.com/your-name/PureLog.git
    GIT_TAG main
)

set(PURE_LOG_USE_MODULES ON CACHE BOOL "" FORCE)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

FetchContent_MakeAvailable(PureLog)

add_executable(MyApp main.cpp)
target_link_libraries(MyApp PRIVATE PureLog)
target_compile_features(MyApp PRIVATE cxx_std_23)
set_target_properties(MyApp PROPERTIES CXX_SCAN_FOR_MODULES ON)
```

Header mode `add_subdirectory`:

```cmake
cmake_minimum_required(VERSION 4.0.2)
project(MyApp LANGUAGES CXX)

set(PURE_LOG_USE_MODULES OFF CACHE BOOL "" FORCE)

add_subdirectory(external/PureLog)

add_executable(MyApp main.cpp)
target_link_libraries(MyApp PRIVATE PureLog)
target_compile_features(MyApp PRIVATE cxx_std_23)
```

Module mode `add_subdirectory`:

```cmake
cmake_minimum_required(VERSION 4.0.2)
project(MyApp LANGUAGES CXX)

set(PURE_LOG_USE_MODULES ON CACHE BOOL "" FORCE)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

add_subdirectory(external/PureLog)

add_executable(MyApp main.cpp)
target_link_libraries(MyApp PRIVATE PureLog)
target_compile_features(MyApp PRIVATE cxx_std_23)
set_target_properties(MyApp PROPERTIES CXX_SCAN_FOR_MODULES ON)
```

Add a manual build section:

````md
## Manual Builds And Manual CMake Wiring

### Header Mode

```powershell
cmake -S path/to/PureLog -B path/to/PureLog/build/header -G Ninja -DPURE_LOG_USE_MODULES=OFF -DCMAKE_BUILD_TYPE=Release
cmake --build path/to/PureLog/build/header
```

### Module Mode

Use the implementation `.cpp` files as sources and register `.mpp` files as a C++ module file set:

```cmake
target_sources(PureLog
    PUBLIC
        FILE_SET cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS "${PURE_LOG_ROOT}/pureLog"
        FILES ${PURE_LOG_MODULE_FILES}
)
```

C++ module artifacts are compiler and build-directory specific. For module mode, building Pure Log as part of the consuming CMake build is more reliable than trying to reuse only a prebuilt static library.
````

Also document the Clang caveat:

```md
Clang is strict about the global module fragment: `module;` must be the first token in a module implementation source. Pure Log's CMake handles this by generating build-directory copies of `.cpp` files with `module;` moved to the top.
```

## Verification Checklist

After implementing, verify these commands or presets:

```powershell
cmake --fresh --preset Debug
cmake --build --preset Debug

cmake --fresh --preset Release
cmake --build --preset Release

cmake --fresh --preset Debug-Modules
cmake --build --preset Debug-Modules

cmake --fresh --preset Release-Modules
cmake --build --preset Release-Modules
```

Also verify that a consumer can use:

```cpp
#include <pureLog/pureLog.hpp>
```

in header mode and:

```cpp
import pureLog;
```

in module mode.
