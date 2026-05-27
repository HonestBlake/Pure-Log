# Pure Log

A customizable, lightweight C++ logging library with traditional header builds and C++ module builds.

## Base Info

- Language standard: C++23
- Minimum CMake version used by the project: 4.0.2
- Tested CMake version: 4.3.3
- Tested working compilers:
  - GCC 16.1.0, MSYS2 MinGW64
  - Clang 22.1.4, MSYS2 MinGW64
- Build output: static library target named `PureLog`
- Default build mode: header mode, unless `PURE_LOG_USE_MODULES` is enabled

Pure Log can be consumed in one of two modes. Pick one mode for your target.

Header mode:

```cpp
#include <pureLog/pureLog.hpp>
```

Module mode:

```cpp
import pureLog;
```

The public logging API is the same after the include or import.

## Quick Start

```cpp
#include <pureLog/pureLog.hpp>

class Debugger: public pureLog::Logger<Debugger>{
    friend class pureLog::Logger<Debugger>;

private:
    Debugger():
        pureLog::Logger<Debugger>(
            "Debugger",
            pureLog::OutputStream::get<pureLog::StdCout<pureLog::OutputStream::BUFFERED>>()
        ){
    }

public:
    Debugger& special(){
        initiateLog("Special", "This is a special log message!");
        return *this;
    }
};

int main(){
    Debugger& debugger = Debugger::get();

    debugger.nameColor(pureLog::Color::BRIGHT_CYAN);
    debugger.levelSpecificLevelColor("Special", pureLog::Color::BRIGHT_PURPLE);
    debugger.levelSpecificMessageFormat("Special", "[SPECIAL LOG]: {}");
    debugger.levelSpecificLogColor("Special", pureLog::Color::BRIGHT_RED);

    debugger.log("Invalid value passed to parser: {}", 3).time();
    debugger.warn("This is a warning message.").location();
    debugger.info("Informational message without additional data.");
    debugger.special();
    debugger.flush();

    return 0;
}
```

For module mode, replace the include with:

```cpp
import pureLog;
```

## Feature Guide

### Logger Types

Pure Log uses a CRTP logger base:

```cpp
class MyLogger: public pureLog::Logger<MyLogger>{
    friend class pureLog::Logger<MyLogger>;

private:
    MyLogger(): pureLog::Logger<MyLogger>("MyLogger"){
    }
};
```

`Logger<T>::get()` returns a singleton instance of the logger type. Logger instances are intentionally non-copyable and non-movable.

You can choose an output stream in the logger constructor:

```cpp
MyLogger():
    pureLog::Logger<MyLogger>(
        "MyLogger",
        pureLog::OutputStream::get<pureLog::StdCerr<pureLog::OutputStream::UNBUFFERED>>()
    ){
}
```

You can also change the stream later:

```cpp
logger.outputStream(pureLog::OutputStream::get<pureLog::StdCout<pureLog::OutputStream::BUFFERED>>());
```

### Logging Levels

Built-in levels:

- `Log::Level::NONE`
- `Log::Level::INFO`
- `Log::Level::WARN`
- `Log::Level::ERROR`
- `Log::Level::CRITICAL`
- `Log::Level::FATAL`
- `Log::Level::TRACE`
- `Log::Level::DEBUG`

Chainable level methods:

```cpp
logger.log();
logger.info();
logger.warn();
logger.error();
logger.critical();
logger.fatal();
logger.trace();
logger.debug();
```

Each level has a message overload with `std::vformat` support:

```cpp
logger.info("Loaded {} records from {}", count, path);
logger.error(std::string("Failed to open file"));
```

Custom levels are string-based. Create them from a derived logger by calling the protected `initiateLog` helper:

```cpp
class Debugger: public pureLog::Logger<Debugger>{
    friend class pureLog::Logger<Debugger>;

private:
    Debugger(): pureLog::Logger<Debugger>("Debugger"){
    }

public:
    Debugger& special(const std::string& message){
        initiateLog("Special", message);
        return *this;
    }
};
```

### Message Composition

A log call starts or replaces the currently buffered log. `message()` appends to the current log message:

```cpp
logger.info("Parsing");
logger.message(" file {}", fileName);
logger.message(" at offset {}", offset);
logger.send();
```

`send()` emits the current log. `flush()` emits the current log and flushes the output stream.

The logger destructor also flushes any buffered log.

### Time And Source Location

Attach time with the current system clock:

```cpp
logger.info("Started").time();
```

Attach a specific time:

```cpp
logger.time(std::chrono::system_clock::now());
logger.time(std::time(nullptr));
```

Attach source location:

```cpp
logger.warn("Unexpected value").location();
```

`location()` defaults to `std::source_location::current()`. You can also pass a specific `std::source_location`.

### Formatting

The default formatting pieces are:

- `name`: `[{}]`
- `time`: `({}:{}:{})`
- `level`: `{}:`
- `message`: `{}`
- `location`: `-- {}, Line: {} {}`
- separator: one space
- log ending: newline

The default order is:

```cpp
{
    Formatting::Type::NAME,
    Formatting::Type::TIME,
    Formatting::Type::LEVEL,
    Formatting::Type::MESSAGE,
    Formatting::Type::LOCATION
}
```

Set the whole format object:

```cpp
pureLog::Formatting formatting;
formatting.time = "<{}:{}:{}:{}>";
formatting.order = {
    pureLog::Formatting::Type::LEVEL,
    pureLog::Formatting::Type::MESSAGE,
    pureLog::Formatting::Type::LOCATION,
    pureLog::Formatting::Type::NAME,
    pureLog::Formatting::Type::TIME
};

logger.formatting(formatting);
```

Or set individual parts:

```cpp
logger.nameFormat("[{}]");
logger.levelFormat("{}:");
logger.messageFormat("{}");
logger.timeFormat("<{}:{}:{}:{}>");
logger.locationFormat("-- {}, Line: {} {}");
logger.orderFormat({
    pureLog::Formatting::Type::NAME,
    pureLog::Formatting::Type::LEVEL,
    pureLog::Formatting::Type::MESSAGE,
    pureLog::Formatting::Type::LOCATION,
    pureLog::Formatting::Type::TIME
});
```

Format argument order:

- `nameFormat`: logger name
- `levelFormat`: level string
- `messageFormat`: message string
- `timeFormat`: hours, minutes, seconds, milliseconds
- `locationFormat`: function name, line, file name

### Level-Specific Formatting

You can override formatting for one level without changing the general logger format:

```cpp
logger.levelSpecificLevelFormat(pureLog::Log::Level::WARN, "Warning({})");
logger.levelSpecificMessageFormat("Special", "[SPECIAL] {}");
logger.levelSpecificTimeFormat(pureLog::Log::Level::ERROR, "<{}:{}:{}:{}>");
logger.levelSpecificLocationFormat(pureLog::Log::Level::TRACE, "{}:{} {}");
logger.levelSpecificOrderFormat("Special", {
    pureLog::Formatting::Type::LEVEL,
    pureLog::Formatting::Type::MESSAGE
});
```

You can also assign a full `Formatting` object for a level:

```cpp
pureLog::Formatting specialFormat;
specialFormat.level = "\"{}\"";
specialFormat.message = "[SPECIAL] {}";
logger.levelSpecificFormatting("Special", specialFormat);
```

### Colors

Coloring can be applied to the whole log or to individual parts:

```cpp
logger.logColor(pureLog::Color::BRIGHT_RED);
logger.nameColor(pureLog::Color::BRIGHT_CYAN);
logger.levelColor(pureLog::Color::BOLD_RED);
logger.messageColor(pureLog::Color::WHITE);
logger.timeColor(pureLog::Color::BRIGHT_BLACK);
logger.locationColor(pureLog::Color::UNDERLINE_RED);
```

Or set a whole `Coloring` object:

```cpp
pureLog::Coloring coloring;
coloring.name = pureLog::Color::BRIGHT_CYAN;
coloring.level = pureLog::Color::BOLD_RED;
coloring.message = pureLog::Color::WHITE;
logger.coloring(coloring);
```

Level-specific coloring is also supported:

```cpp
logger.levelSpecificLogColor(pureLog::Log::Level::WARN, pureLog::Color::YELLOW);
logger.levelSpecificLevelColor("Special", pureLog::Color::BRIGHT_PURPLE);
logger.levelSpecificMessageColor("Special", pureLog::Color::BRIGHT_WHITE);
```

Available ANSI color groups:

- normal foreground: black, red, green, yellow, blue, purple, cyan, white
- bold foreground
- underline foreground
- background
- bright foreground
- bright bold foreground
- bright background

The enum names are uppercase, for example `Color::RED`, `Color::BOLD_RED`, `Color::UNDERLINE_RED`, `Color::BACKGROUND_RED`, `Color::BRIGHT_RED`, `Color::BRIGHT_BOLD_RED`, and `Color::BRIGHT_BACKGROUND_RED`.

### Output Streams

Built-in streams:

```cpp
pureLog::StdCout<pureLog::OutputStream::UNBUFFERED>
pureLog::StdCout<pureLog::OutputStream::BUFFERED>
pureLog::StdCerr<pureLog::OutputStream::UNBUFFERED>
pureLog::StdCerr<pureLog::OutputStream::BUFFERED>
```

Buffered streams store log strings until `flush()` or destruction. Unbuffered streams write immediately.

File output is supported by deriving from `FileOut` and passing a path to the protected base constructor:

```cpp
class File: public pureLog::FileOut<pureLog::OutputStream::UNBUFFERED>{
    friend File& pureLog::OutputStream::get<File>();

private:
    File(): pureLog::FileOut<pureLog::OutputStream::UNBUFFERED>("log.txt"){
    }
};

class FileLogger: public pureLog::Logger<FileLogger>{
    friend class pureLog::Logger<FileLogger>;

private:
    FileLogger(): pureLog::Logger<FileLogger>("FileLogger", pureLog::OutputStream::get<File>()){
        if(!pureLog::OutputStream::get<File>().isOpen()){
            throw std::runtime_error("Failed to open log file.");
        }
    }
};
```

Custom streams can derive from `OutputStream` or `BufferedOutputStream`:

```cpp
class CustomOutput: public pureLog::BufferedOutputStream{
    friend CustomOutput& pureLog::OutputStream::get<CustomOutput>();

private:
    CustomOutput() = default;

    void write(const std::string& log)override{
        // Write log somewhere.
    }

    void flushOutput()override{
        // Flush destination if needed.
    }
};
```

### Compile-Time Feature Selection

The logger template has compile-time switches for level-specific formatting and colors:

```cpp
class PlainLogger: public pureLog::Logger<PlainLogger, false, false>{
    friend class pureLog::Logger<PlainLogger, false, false>;

private:
    PlainLogger(): pureLog::Logger<PlainLogger, false, false>("Plain"){
    }
};
```

When level-specific formatting is disabled, level-specific formatting APIs produce a compile-time error if used. When colors are disabled, color APIs produce a compile-time error if used.

Runtime getters are available for inspecting current logger state:

```cpp
logger.usingLevelFormatting();
logger.usingColors();
logger.formatting();
logger.levelSpecificFormatting();
logger.coloring();
logger.levelSpecificColoring();
logger.name();
```

## Using Pure Log With CMake

Pure Log provides a CMake target named `PureLog`. The preferred integration is `FetchContent`, followed by `add_subdirectory` when the source is already checked into your tree.

### FetchContent

Header mode:

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

Module mode:

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

### add_subdirectory

Header mode:

```cmake
cmake_minimum_required(VERSION 4.0.2)
project(MyApp LANGUAGES CXX)

set(PURE_LOG_USE_MODULES OFF CACHE BOOL "" FORCE)

add_subdirectory(external/PureLog)

add_executable(MyApp main.cpp)
target_link_libraries(MyApp PRIVATE PureLog)
target_compile_features(MyApp PRIVATE cxx_std_23)
```

Module mode:

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

## Manual Builds And Manual CMake Wiring

### Header Mode

Build Pure Log manually:

```powershell
cmake -S path/to/PureLog -B path/to/PureLog/build/header -G Ninja -DPURE_LOG_USE_MODULES=OFF -DCMAKE_BUILD_TYPE=Release
cmake --build path/to/PureLog/build/header
```

Then import the built static library:

```cmake
add_library(PureLog::PureLog STATIC IMPORTED)

set_target_properties(PureLog::PureLog PROPERTIES
    IMPORTED_LOCATION "path/to/PureLog/lib/release/pureLog.lib"
    INTERFACE_INCLUDE_DIRECTORIES "path/to/PureLog/include;path/to/PureLog/pureLog"
)

add_executable(MyApp main.cpp)
target_link_libraries(MyApp PRIVATE PureLog::PureLog)
target_compile_features(MyApp PRIVATE cxx_std_23)
```

### Module Mode With GCC

With the tested GCC/MSYS2 build, no special source preparation is needed for manual module wiring. Add the implementation `.cpp` files as normal sources and add the `.mpp` files as a C++ module file set:

```cmake
cmake_minimum_required(VERSION 4.0.2)
project(MyApp LANGUAGES CXX)

set(PURE_LOG_ROOT "path/to/PureLog")

set(PURE_LOG_IMPLEMENTATION_FILES
    "${PURE_LOG_ROOT}/pureLog/log.cpp"
    "${PURE_LOG_ROOT}/pureLog/colors.cpp"
    "${PURE_LOG_ROOT}/pureLog/outputStream.cpp"
    "${PURE_LOG_ROOT}/pureLog/consoleOut.cpp"
    "${PURE_LOG_ROOT}/pureLog/fileOut.cpp"
)

set(PURE_LOG_MODULE_FILES
    "${PURE_LOG_ROOT}/pureLog/pureLog.mpp"
    "${PURE_LOG_ROOT}/pureLog/log.mpp"
    "${PURE_LOG_ROOT}/pureLog/colors.mpp"
    "${PURE_LOG_ROOT}/pureLog/formatting.mpp"
    "${PURE_LOG_ROOT}/pureLog/outputStream.mpp"
    "${PURE_LOG_ROOT}/pureLog/consoleOut.mpp"
    "${PURE_LOG_ROOT}/pureLog/fileOut.mpp"
    "${PURE_LOG_ROOT}/pureLog/logger.mpp"
)

add_library(PureLog STATIC ${PURE_LOG_IMPLEMENTATION_FILES})

target_compile_definitions(PureLog PRIVATE PURE_LOG_USE_MODULES=1)
target_include_directories(PureLog PUBLIC
    "${PURE_LOG_ROOT}/include"
    "${PURE_LOG_ROOT}/pureLog"
)
target_compile_features(PureLog PUBLIC cxx_std_23)
set_target_properties(PureLog PROPERTIES CXX_SCAN_FOR_MODULES ON)

target_sources(PureLog
    PUBLIC
        FILE_SET cxx_modules
        TYPE CXX_MODULES
        BASE_DIRS "${PURE_LOG_ROOT}/pureLog"
        FILES ${PURE_LOG_MODULE_FILES}
)

add_executable(MyApp main.cpp)
target_link_libraries(MyApp PRIVATE PureLog)
target_compile_features(MyApp PRIVATE cxx_std_23)
set_target_properties(MyApp PROPERTIES CXX_SCAN_FOR_MODULES ON)
```

### Module Mode With Clang

Clang is stricter about the global module fragment: `module;` must be the first token in the implementation source that participates in module mode. Pure Log's own CMake handles this by generating build-directory copies of the `.cpp` files with `module;` moved to the top.

If you manually wire module mode with Clang, add this helper and use the generated files in `add_library`:

```cmake
set(PURE_LOG_MODULE_COPY_DIR "${CMAKE_CURRENT_BINARY_DIR}/pureLog-module-mode")

function(pure_log_prepare_clang_module_source input output)
    file(READ "${input}" source)

    string(REGEX REPLACE "(^|\n)[ \t]*module[ \t]*;[^\n]*(\n|$)" "\\1" source "${source}")

    get_filename_component(output_dir "${output}" DIRECTORY)
    file(MAKE_DIRECTORY "${output_dir}")
    file(WRITE "${output}" "module;\n\n${source}")

    set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${input}")
endfunction()

set(PURE_LOG_MODULE_SOURCE_FILES)

foreach(source_file IN LISTS PURE_LOG_IMPLEMENTATION_FILES)
    get_filename_component(source_name "${source_file}" NAME)
    set(module_source_file "${PURE_LOG_MODULE_COPY_DIR}/${source_name}")
    pure_log_prepare_clang_module_source("${source_file}" "${module_source_file}")
    list(APPEND PURE_LOG_MODULE_SOURCE_FILES "${module_source_file}")
endforeach()

add_library(PureLog STATIC ${PURE_LOG_MODULE_SOURCE_FILES})
```

Use the same `target_compile_definitions`, `target_include_directories`, `target_sources(FILE_SET cxx_modules ...)`, and executable linking shown in the GCC example.

C++ module artifacts are compiler and build-directory specific. If you want module mode, building Pure Log as part of the consuming CMake build is more reliable than trying to reuse only a prebuilt static library.

## License

MIT License (see [LICENCE.md](LICENCE.md))

## Acknowledgments

- [spdlog](https://github.com/gabime/spdlog) - inspiration for design
- [fmtlib](https://github.com/fmtlib/fmt) - formatting concepts
