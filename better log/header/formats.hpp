// #file: formats.hpp, header file

#pragma once

#include "betterLogger.hpp" // Project header

namespace worTech::betterCpp::formats{

    // #namespace: ansiiColorCodes, variable namespace
    namespace ansiiColorCodes{
        inline constexpr std::string RESET = "\033[0m";
        inline constexpr std::string BLACK = "\033[30m";
        inline constexpr std::string RED = "\033[31m";
        inline constexpr std::string GREEN = "\033[32m";
        inline constexpr std::string YELLOW = "\033[33m";
        inline constexpr std::string BLUE = "\033[34m";
        inline constexpr std::string MAGENTA = "\033[35m";
        inline constexpr std::string CYAN = "\033[36m";
        inline constexpr std::string WHITE = "\033[37m";
        inline constexpr std::string BOLD_BLACK = "\033[1;30m";
        inline constexpr std::string BOLD_RED = "\033[1;31m";
        inline constexpr std::string BOLD_GREEN = "\033[1;32m";
        inline constexpr std::string BOLD_YELLOW = "\033[1;33m";
        inline constexpr std::string BOLD_BLUE = "\033[1;34m";
        inline constexpr std::string BOLD_MAGENTA = "\033[1;35m";
        inline constexpr std::string BOLD_CYAN = "\033[1;36m";
        inline constexpr std::string BOLD_WHITE = "\033[1;37m";
    } // #end: ansiiColorCodes

    // #enum: LogLevel, uint8_t enum struct
    enum struct LogLevel: uint8_t{
        NONE,
        INFO,
        TRACE,
        WARNING,
        ERROR,
        CRITICAL
    }; // #end: LogLevel

    // #enum: FormatType, uint8_t enum struct
    enum class FormatType: uint8_t{
        LOGGER,
        LEVEL,
        TIME,
        MESSAGE,
        LOCATION
    }; // #end: FormatType

    // #namespace: logFormatting, variable namespace
    namespace logFormatting{
        inline constexpr std::string LOGGER_BEGIN = "[";
        inline constexpr std::string LOGGER_END = "]";
        inline constexpr std::string TIME_BEGIN = "(";
        inline constexpr std::string TIME_END = ")";
        inline constexpr std::string TIME_SPACE = ":";
        inline constexpr std::string LEVEL_END = ":";
        inline constexpr std::string LINE_BEGIN = "line";
        inline constexpr std::string SPACE = " ";
        inline constexpr size_t FORMAT_SIZE = 5;
        inline const std::unordered_map<Level, std::string> LEVEL_NAME = {
            {Level::NONE, ""},
            {Level::INFO, "Info"},
            {Level::TRACE, "Trace"},
            {Level::WARNING, "Warning"},
            {Level::ERROR, "Error"},
            {Level::CRITICAL, "Critical"}
        };
        inline const std::unordered_map<Level, std::string> LEVEL_COLOR = {
            {Level::NONE, ansii::WHITE},
            {Level::INFO, ansii::CYAN},
            {Level::TRACE, ansii::GREEN},
            {Level::WARNING, ansii::YELLOW},
            {Level::ERROR, ansii::RED},
            {Level::CRITICAL, ansii::MAGENTA}
        };
        inline const std::unordered_map<Level, std::string> LEVEL_COLOR_BOLD = {
            {Level::NONE, ansii::BOLD_WHITE},
            {Level::INFO, ansii::BOLD_CYAN},
            {Level::TRACE, ansii::BOLD_GREEN},
            {Level::WARNING, ansii::BOLD_YELLOW},
            {Level::ERROR, ansii::BOLD_RED},
            {Level::CRITICAL, ansii::BOLD_MAGENTA}
        };
    } // #end: logFormatting
    
} // namespace worTech::betterLogger::formats