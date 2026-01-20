# Pure Log

A heavily customizable and lightweight C++ logging library.

## Features
- **Customizable Formatting:** Fully control log message formats using formatting strings
- **Colorized Output:** Supports colored logs for improved readability (configurable, works in terminals that support ANSI colors)
- **Flexible Logging Levels:** Built-in levels (DEBUG, INFO, WARN, ERROR, etc.), plus ability to define custom levels
- **Configurable Output Streams:** Output logs to console, files, or user-defined streams
- **Custom Logger Types:** Easily extend or create specialized loggers for different parts of your codebase
- **Runtime Configuration:** Adjust formatting, output streams, and logging levels at runtime and compile-time
- **Lightweight and Dependency-Free:** Designed for minimal overhead and no external dependencies (uses standard C++ only)
- **Thread Safety:** Safe for concurrent logging in multi-threaded applications

## Getting Started

### Prerequisites
- C++20 or newer compiler GCC, Clang (Both Tested)
- Compatible with Windows(Tested), Linux, macOS
- No external dependencies required

### Build & Installation

### Quick Start Example
```cpp
#include <pureLog/pureLog.hpp>


class Debugger: public pureLog::Logger<Debugger>{
    friend class pureLog::Logger<Debugger>;
private:
    Debugger(): pureLog::Logger<Debugger>("Debugger", pureLog::OutputStream::get<pureLog::StdCout<pureLog::OutputStream::BUFFERED>>()){
    }
public:
    Debugger& special(){
        initiateLog("Special", "This is a special log message!");
        return *this;
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

int main(){
    Debugger& debugger = Debugger::get();
    debugger.colorFormatWarnName();
    debugger.formatNameColor(pureLog::Color::WHITE);
    debugger.formatLogColor(pureLog::Color::BRIGHT_RED);
    debugger.formatLocationColor(pureLog::Color::UNDERLINE_RED);
    debugger.formatTimeColor(pureLog::Color::WHITE);
    debugger.formatLevelColor(pureLog::Color::BOLD_RED);
    debugger.nameColor(pureLog::Color::BRIGHT_CYAN);
    debugger.levelSpecificLevelColor("Special", pureLog::Color::BRIGHT_PURPLE);
    debugger.levelSpecificMessageFormat("Special", "[SPECIAL LOG]: {}");
    debugger.levelSpecificLevelFormat("Special", "\"{}\"");
    debugger.levelSpecificLogColor("Special", pureLog::Color::BRIGHT_RED);
    debugger.levelSpecificLogColor(pureLog::Log::Level::WARN, pureLog::Color::YELLOW);
    debugger.levelSpecificLevelFormat(pureLog::Log::Level::TRACE, "");
    debugger.levelSpecificLogColor(pureLog::Log::Level::TRACE, pureLog::Color::BRIGHT_GREEN);
    debugger.log("Invalid value passed to parser: {}", 3).time();
    debugger.warn("This is a warning message.").location();
    debugger.info("Informational message without additional data.");
    debugger.debug("Debugging value: {}");
    debugger.critical("Critical error encountered! System will shut down.").time().location();
    debugger.special();
    debugger.trace("hi").location();
    debugger.flush().timeFormat("<{}:{}:{}:{}>");
    return 0;
}
```

Output:
```
[Debugger] (21:53:47) : Invalid value passed to parser: 3
[Debugger] Warn: This is a warning message. -- int main(), Line: 62 C:/Users/blake/Programing/C++ Projects/Pure Log/example/example.cpp
[Debugger] Info: Informational message without additional data.
[Debugger] Debug: Debugging value: {}
[Debugger] (21:53:47) Critical: Critical error encountered! System will shut down. -- int main(), Line: 65 C:/Users/blake/Programing/C++ Projects/Pure Log/example/example.cpp
[Debugger] "Special" [SPECIAL LOG]: This is a special log message!
[Debugger] hi -- int main(), Line: 67 C:/Users/blake/Programing/C++ Projects/Pure Log/example/example.cpp
[Debugger] <21:53:47:696> : Invalid value passed to parser: 3
[Debugger] Warn: This is a warning message. -- int main(), Line: 62 C:/Users/blake/Programing/C++ Projects/Pure Log/example/example.cpp
[Debugger] Info: Informational message without additional data.
[Debugger] Debug: Debugging value: {}
[Debugger] <21:53:47:696> Critical: Critical error encountered! System will shut down. -- int main(), Line: 65 C:/Users/blake/Programing/C++ Projects/Pure Log/example/example.cpp
[Debugger] "Special" [SPECIAL LOG]: This is a special log message!
[Debugger] hi -- int main(), Line: 67 C:/Users/blake/Programing/C++ Projects/Pure Log/example/example.cpp
```

## License

MIT License (see [LICENCE.md](LICENCE.md))

## Acknowledgments

- [spdlog](https://github.com/gabime/spdlog) — inspiration for design
- [fmtlib](https://github.com/fmtlib/fmt) — formatting concepts
- Contributors: @yourgithubhandle, @othercontributors