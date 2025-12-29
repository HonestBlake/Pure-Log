// #FILE: log.hpp, Module Header File

#pragma once

#include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File

namespace pureLog::log{ // #scope: pureLog::log

    // #STRUCT: Log
    struct Log{
    // Public Types

        // #ENUM: Log::Level, std::uint8_t Enum Class
        enum class Level: std::uint8_t{
            LOG,
            INFO,
            WARN,
            ERROR,
            CRITICAL,
            FATAL,
            TRACE,
            DEBUG
        }; // #END: log::Level

        // #ENUM: Log::Format, std::uint8_t Enum Class
        enum class Format: std::uint8_t{
            NAME,
            TIME,
            LEVEL,
            MESSAGE,
            LOCATION
        }; // #END: Log::Format

    // Public Factory Methods
        Log();
        explicit Log(Level p_level);
        Log(const Log&) = default; // #DEFAULT: Log(const Log&), Default Copy Constructor
        Log(Log&&) = default; // #DEFAULT: Log(Log&&), Default Move Constructor
        ~Log() = default; // #DEFAULT: ~Log(), Default Destructor
    // Public Operators
        Log& operator=(const Log&) = default; // #DEFAULT: operator=(const Log&), Default Copy Assignment Operator
        Log& operator=(Log&&) = default; // #DEFAULT: operator=(Log&&), Default Move Assignment Operator
    // Public Static Members
        static inline constexpr std::uint8_t NUM_FORMATS = 5;
        static inline constexpr std::string FORMAT_SEPARATOR = " ";
        static inline constexpr std::string LEVEL_FORMAT = "{}:";
        static inline constexpr std::string NAME_FORMAT = "[{}]";
        static inline constexpr std::string TIME_FORMAT = "{}:{}:{}";
        static inline const std::string LOCATION_FORMAT = "- {}, Line: {} {}";
        static inline const std::map<Level, std::string> LEVEL_STRINGS = {
            {Level::INFO, "Info"},
            {Level::WARN, "Warn"},
            {Level::ERROR, "Error"},
            {Level::CRITICAL, "Critical"},
            {Level::FATAL, "Fatal"},
            {Level::TRACE, "Trace"},
            {Level::DEBUG, "Debug"}
        };
    // Public Members
        Level level;
        std::string message;
        std::optional<std::source_location> location;
        std::optional<std_TimePoint> time;
    }; // #END: Log

} // #END: pureLog::log