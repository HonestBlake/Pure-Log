// #FILE: log.hpp, Module Header File

#pragma once

#include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File

namespace pureLog::log{ // #scope: pureLog::log

    // #STRUCT: Log
    struct Log{
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
        std::optional<std_TimePoint> time;
    }; // #END: Log

} // #END: pureLog::log