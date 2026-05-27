// #FILE: log.hpp, Module Header File

#pragma once

#if defined(PURE_LOG_USE_MODULES) && defined(INCLUDED_BY_MODULE) // Using Modules
    #define MODULE_EXPORT export
#else // Using Headers Or Open as stand alone file
    #include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
    #define MODULE_EXPORT
#endif

namespace pureLog{ // #scope: pureLog

    // #STRUCT: Log
    MODULE_EXPORT struct Log{
    // Types

        // #ENUM: Log::Level, std::uint8_t Enum Class
        enum class Level: std::uint8_t{
            NONE,
            INFO,
            WARN,
            ERROR,
            CRITICAL,
            FATAL,
            TRACE,
            DEBUG
        }; // #END: log::Level
        
    // Factory Methods
        Log();
        explicit Log(const std::variant<Log::Level, std::string> p_level);
        explicit Log(std::variant<Log::Level, std::string>&& p_level);
        Log(const Log&) = default; // #DEFAULT: Log(const Log&), Default Copy Constructor
        Log(Log&&) = default; // #DEFAULT: Log(Log&&), Default Move Constructor
        ~Log() = default; // #DEFAULT: ~Log(), Default Destructor
    // Operators
        Log& operator=(const Log&) = default; // #DEFAULT: operator=(const Log&), Default Copy Assignment Operator
        Log& operator=(Log&&) = default; // #DEFAULT: operator=(Log&&), Default Move Assignment Operator
    // Static Methods
        static std::string getLevelString(const std::variant<Log::Level, std::string>& p_level);
    // Static Members
        static inline const std::unordered_map<Level, std::string> LEVEL_STRINGS = {
            {Level::INFO, "Info"},
            {Level::WARN, "Warn"},
            {Level::ERROR, "Error"},
            {Level::CRITICAL, "Critical"},
            {Level::FATAL, "Fatal"},
            {Level::TRACE, "Trace"},
            {Level::DEBUG, "Debug"}
        };
    // Members
        std::variant<Level, std::string> level; // Built-In Level or custom level string
        std::string message;
        std::optional<std::source_location> location;
        std::optional<TimePoint> time;
    }; // #END: Log

} // #END: pureLog

#undef MODULE_EXPORT
