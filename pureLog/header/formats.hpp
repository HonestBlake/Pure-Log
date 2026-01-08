// #FILE: format.hpp, Module Header File

#pragma once

#include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
#include "colors.hpp" // #INCLUDE: colors.hpp, Module Header File

namespace pureLog::formats{ // #scope: pureLog::format

    // #STRUCT: Format, Struct
    struct Format{
    // Types

        // #ENUM: Type, std::uint8_t Enum Class
        enum class Type: std::uint8_t{
            NAME,
            TIME,
            LEVEL,
            MESSAGE,
            LOCATION
        }; // #END: Type
        
        // #STRUCT: TextColor, Struct
        struct TextColor{
        // Factory Methods
            TextColor() = default; // #DEFAULT: TextColor(), Default Constructor
            TextColor(const TextColor&) = default; // #DEFAULT: TextColor(const TextColor&), Default Copy Constructor
            TextColor(TextColor&&) = default; // #DEFAULT: TextColor(TextColor&&), Default Move Constructor
            ~TextColor() = default; // #DEFAULT: ~TextColor(), Default Destructor
        // Operators
            TextColor& operator=(const TextColor&) = default; // #DEFAULT: operator=(const TextColor&), Default Copy Assignment Operator
            TextColor& operator=(TextColor&&) = default; // #DEFAULT: operator=(TextColor&&), Default Move Assignment Operator
        // Members
            std::optional<Color> log;
            std::optional<Color> name;
            std::optional<Color> level;
            std::optional<Color> message;
            std::optional<Color> time;
            std::optional<Color> location;
        }; // #END: TextColor

    // Factory Methods
        Format() = default; // #DEFAULT: Format(), Default Constructor
        Format(const Format&) = default; // #DEFAULT: Format(const Format&), Default Copy Constructor
        Format(Format&&) = default; // #DEFAULT: Format(Format&&), Default Move Constructor
        ~Format() = default; // #DEFAULT: ~Format(), Default Destructor
    // Operators
        Format& operator=(const Format&) = default; // #DEFAULT: operator=(const Format&), Default Copy Assignment Operator
        Format& operator=(Format&&) = default; // #DEFAULT: operator=(Format&&), Default Move Assignment Operator
    // Static Members
        static inline constexpr std::uint8_t COUNT = 5;
        static inline constexpr std::string SEPARATOR = " ";
        static inline constexpr std::string LOG_END = "\n";
        static inline constexpr std::string LEVEL = "{}:";
        static inline constexpr std::string NAME = "[{}]";
        static inline constexpr std::string MESSAGE = "{}";
        static inline constexpr std::string TIME = "({}:{}:{})";
        static inline const std::string LOCATION = "-- {}, Line: {} {}";
        static inline constexpr std::array<Type, COUNT> DEFAULT_ORDER = {
            Type::NAME,
            Type::TIME,
            Type::LEVEL,
            Type::MESSAGE,
            Type::LOCATION
        };
    // Members
        std::string name = NAME;
        std::string level = LEVEL;
        std::string message = MESSAGE;
        std::string time = TIME;
        std::string location = LOCATION;
        std::array<Type, COUNT> order = DEFAULT_ORDER;
        TextColor color;
    }; // #END: Format

} // #END: pureLog::format

