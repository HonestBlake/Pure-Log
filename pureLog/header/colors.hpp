// #FILE: colors.hpp, Module Header File

#pragma once

#include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File



        // // #STRUCT: TextColor, Struct
        // struct TextColor{
        // // Factory Methods
        //     TextColor() = default; // #DEFAULT: TextColor(), Default Constructor
        //     TextColor(const TextColor&) = default; // #DEFAULT: TextColor(const TextColor&), Default Copy Constructor
        //     TextColor(TextColor&&) = default; // #DEFAULT: TextColor(TextColor&&), Default Move Constructor
        //     ~TextColor() = default; // #DEFAULT: ~TextColor(), Default Destructor
        // // Operators
        //     TextColor& operator=(const TextColor&) = default; // #DEFAULT: operator=(const TextColor&), Default Copy Assignment Operator
        //     TextColor& operator=(TextColor&&) = default; // #DEFAULT: operator=(TextColor&&), Default Move Assignment Operator
        // // Members
        //     std::optional<Color> log;
        //     std::optional<Color> name;
        //     std::optional<Color> level;
        //     std::optional<Color> message;
        //     std::optional<Color> time;
        //     std::optional<Color> location;
        // }; // #END: TextColor


namespace pureLog::colors{ // #scope: pureLog::colors

    // #STRUCT: Coloring, Struct
    struct Coloring{

    }; // #END: Coloring

    // #ENUM: Color, std::uint8_t Enum Class
    enum class Color: std::uint8_t{
    // Colors
        BLACK,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        PURPLE,
        CYAN,
        WHITE,
    // Bold Colors
        BOLD_BLACK,
        BOLD_RED,
        BOLD_GREEN,
        BOLD_YELLOW,
        BOLD_BLUE,
        BOLD_PURPLE,
        BOLD_CYAN,
        BOLD_WHITE,
    // Underline Colors
        UNDERLINE_BLACK,
        UNDERLINE_RED,
        UNDERLINE_GREEN,
        UNDERLINE_YELLOW,
        UNDERLINE_BLUE,
        UNDERLINE_PURPLE,
        UNDERLINE_CYAN,
        UNDERLINE_WHITE,
    // Background Colors
        BACKGROUND_BLACK,
        BACKGROUND_RED,
        BACKGROUND_GREEN,
        BACKGROUND_YELLOW,
        BACKGROUND_BLUE,
        BACKGROUND_PURPLE,
        BACKGROUND_CYAN,
        BACKGROUND_WHITE,
    // Bright Colors
        BRIGHT_BLACK,
        BRIGHT_RED,
        BRIGHT_GREEN,
        BRIGHT_YELLOW,
        BRIGHT_BLUE,
        BRIGHT_PURPLE,
        BRIGHT_CYAN,
        BRIGHT_WHITE,
    // Bright Bold Colors
        BRIGHT_BOLD_BLACK,
        BRIGHT_BOLD_RED,
        BRIGHT_BOLD_GREEN,
        BRIGHT_BOLD_YELLOW,
        BRIGHT_BOLD_BLUE,
        BRIGHT_BOLD_PURPLE,
        BRIGHT_BOLD_CYAN,
        BRIGHT_BOLD_WHITE,
    // Bright Background Colors
        BRIGHT_BACKGROUND_BLACK,
        BRIGHT_BACKGROUND_RED,
        BRIGHT_BACKGROUND_GREEN,
        BRIGHT_BACKGROUND_YELLOW,
        BRIGHT_BACKGROUND_BLUE,
        BRIGHT_BACKGROUND_PURPLE,
        BRIGHT_BACKGROUND_CYAN,
        BRIGHT_BACKGROUND_WHITE
    }; // #END: Color

    // #NAMESPACE: ansi, Variable Namespace
    namespace ansi{ 
        inline constexpr std::string RESET = "\e[0m";
        // Colors
        inline constexpr std::string BLACK = "\e[0;30m";
        inline constexpr std::string RED = "\e[0;31m";
        inline constexpr std::string GREEN = "\e[0;32m";
        inline constexpr std::string YELLOW = "\e[0;33m";
        inline constexpr std::string BLUE = "\e[0;34m";
        inline constexpr std::string PURPLE = "\e[0;35m";
        inline constexpr std::string CYAN = "\e[0;36m";
        inline constexpr std::string WHITE = "\e[0;37m";
        // Bold Colors
        inline constexpr std::string BOLD_BLACK = "\e[1;30m";
        inline constexpr std::string BOLD_RED = "\e[1;31m";
        inline constexpr std::string BOLD_GREEN = "\e[1;32m";
        inline constexpr std::string BOLD_YELLOW = "\e[1;33m";
        inline constexpr std::string BOLD_BLUE = "\e[1;34m";
        inline constexpr std::string BOLD_PURPLE = "\e[1;35m";
        inline constexpr std::string BOLD_CYAN = "\e[1;36m";
        inline constexpr std::string BOLD_WHITE = "\e[1;37m";
        // Underline Colors
        inline constexpr std::string UNDERLINE_BLACK = "\e[4;30m";
        inline constexpr std::string UNDERLINE_RED = "\e[4;31m";
        inline constexpr std::string UNDERLINE_GREEN = "\e[4;32m";
        inline constexpr std::string UNDERLINE_YELLOW = "\e[4;33m";
        inline constexpr std::string UNDERLINE_BLUE = "\e[4;34m";
        inline constexpr std::string UNDERLINE_PURPLE = "\e[4;35m";
        inline constexpr std::string UNDERLINE_CYAN = "\e[4;36m";
        inline constexpr std::string UNDERLINE_WHITE = "\e[4;37m";
        // Background Colors
        inline constexpr std::string BACKGROUND_BLACK = "\e[40m";
        inline constexpr std::string BACKGROUND_RED = "\e[41m";
        inline constexpr std::string BACKGROUND_GREEN = "\e[42m";
        inline constexpr std::string BACKGROUND_YELLOW = "\e[43m";
        inline constexpr std::string BACKGROUND_BLUE = "\e[44m";
        inline constexpr std::string BACKGROUND_PURPLE = "\e[45m";
        inline constexpr std::string BACKGROUND_CYAN = "\e[46m";
        inline constexpr std::string BACKGROUND_WHITE = "\e[47m";
        // Bright Colors
        inline constexpr std::string BRIGHT_BLACK = "\e[0;90m";
        inline constexpr std::string BRIGHT_RED = "\e[0;91m";
        inline constexpr std::string BRIGHT_GREEN = "\e[0;92m";
        inline constexpr std::string BRIGHT_YELLOW = "\e[0;93m";
        inline constexpr std::string BRIGHT_BLUE = "\e[0;94m";
        inline constexpr std::string BRIGHT_PURPLE = "\e[0;95m";
        inline constexpr std::string BRIGHT_CYAN = "\e[0;96m";
        inline constexpr std::string BRIGHT_WHITE = "\e[0;97m";
        // Bright Bold Colors
        inline constexpr std::string BRIGHT_BOLD_BLACK = "\e[1;90m";
        inline constexpr std::string BRIGHT_BOLD_RED = "\e[1;91m";
        inline constexpr std::string BRIGHT_BOLD_GREEN = "\e[1;92m";
        inline constexpr std::string BRIGHT_BOLD_YELLOW = "\e[1;93m";
        inline constexpr std::string BRIGHT_BOLD_BLUE = "\e[1;94m";
        inline constexpr std::string BRIGHT_BOLD_PURPLE = "\e[1;95m";
        inline constexpr std::string BRIGHT_BOLD_CYAN = "\e[1;96m";
        inline constexpr std::string BRIGHT_BOLD_WHITE = "\e[1;97m";
        // Bright Background Colors
        inline constexpr std::string BRIGHT_BACKGROUND_BLACK = "\e[0;100m";
        inline constexpr std::string BRIGHT_BACKGROUND_RED = "\e[0;101m";
        inline constexpr std::string BRIGHT_BACKGROUND_GREEN = "\e[0;102m";
        inline constexpr std::string BRIGHT_BACKGROUND_YELLOW = "\e[0;103m";
        inline constexpr std::string BRIGHT_BACKGROUND_BLUE = "\e[0;104m";
        inline constexpr std::string BRIGHT_BACKGROUND_PURPLE = "\e[0;105m";
        inline constexpr std::string BRIGHT_BACKGROUND_CYAN = "\e[0;106m";
        inline constexpr std::string BRIGHT_BACKGROUND_WHITE = "\e[0;107m";
        inline const std::unordered_map<Color, std::string> COLOR_CODES = {
        // Colors
            {Color::BLACK, BLACK},
            {Color::RED, RED},
            {Color::GREEN, GREEN},
            {Color::YELLOW, YELLOW},
            {Color::BLUE, BLUE},
            {Color::PURPLE, PURPLE},
            {Color::CYAN, CYAN},
            {Color::WHITE, WHITE},
        // Bold Colors
            {Color::BOLD_BLACK, BOLD_BLACK},
            {Color::BOLD_RED, BOLD_RED},
            {Color::BOLD_GREEN, BOLD_GREEN},
            {Color::BOLD_YELLOW, BOLD_YELLOW},
            {Color::BOLD_BLUE, BOLD_BLUE},
            {Color::BOLD_PURPLE, BOLD_PURPLE},
            {Color::BOLD_CYAN, BOLD_CYAN},
            {Color::BOLD_WHITE, BOLD_WHITE},
        // Underline Colors
            {Color::UNDERLINE_BLACK, UNDERLINE_BLACK},
            {Color::UNDERLINE_RED, UNDERLINE_RED},
            {Color::UNDERLINE_GREEN, UNDERLINE_GREEN},
            {Color::UNDERLINE_YELLOW, UNDERLINE_YELLOW},
            {Color::UNDERLINE_BLUE, UNDERLINE_BLUE},
            {Color::UNDERLINE_PURPLE, UNDERLINE_PURPLE},
            {Color::UNDERLINE_CYAN, UNDERLINE_CYAN},
            {Color::UNDERLINE_WHITE, UNDERLINE_WHITE},
        // Background Colors
            {Color::BACKGROUND_BLACK, BACKGROUND_BLACK},
            {Color::BACKGROUND_RED, BACKGROUND_RED},
            {Color::BACKGROUND_GREEN, BACKGROUND_GREEN},
            {Color::BACKGROUND_YELLOW, BACKGROUND_YELLOW},
            {Color::BACKGROUND_BLUE, BACKGROUND_BLUE},
            {Color::BACKGROUND_PURPLE, BACKGROUND_PURPLE},
            {Color::BACKGROUND_CYAN, BACKGROUND_CYAN},
            {Color::BACKGROUND_WHITE, BACKGROUND_WHITE},
        // Bright Colors
            {Color::BRIGHT_BLACK, BRIGHT_BLACK},
            {Color::BRIGHT_RED, BRIGHT_RED},
            {Color::BRIGHT_GREEN, BRIGHT_GREEN},
            {Color::BRIGHT_YELLOW, BRIGHT_YELLOW},
            {Color::BRIGHT_BLUE, BRIGHT_BLUE},
            {Color::BRIGHT_PURPLE, BRIGHT_PURPLE},
            {Color::BRIGHT_CYAN, BRIGHT_CYAN},
            {Color::BRIGHT_WHITE, BRIGHT_WHITE},
        // Bright Bold Colors
            {Color::BRIGHT_BOLD_BLACK, BRIGHT_BOLD_BLACK},
            {Color::BRIGHT_BOLD_RED, BRIGHT_BOLD_RED},
            {Color::BRIGHT_BOLD_GREEN, BRIGHT_BOLD_GREEN},
            {Color::BRIGHT_BOLD_YELLOW, BRIGHT_BOLD_YELLOW},
            {Color::BRIGHT_BOLD_BLUE, BRIGHT_BOLD_BLUE},
            {Color::BRIGHT_BOLD_PURPLE, BRIGHT_BOLD_PURPLE},
            {Color::BRIGHT_BOLD_CYAN, BRIGHT_BOLD_CYAN},
            {Color::BRIGHT_BOLD_WHITE, BRIGHT_BOLD_WHITE},
        // Bright Background Colors
            {Color::BRIGHT_BACKGROUND_BLACK, BRIGHT_BACKGROUND_BLACK},
            {Color::BRIGHT_BACKGROUND_RED, BRIGHT_BACKGROUND_RED},
            {Color::BRIGHT_BACKGROUND_GREEN, BRIGHT_BACKGROUND_GREEN},
            {Color::BRIGHT_BACKGROUND_YELLOW, BRIGHT_BACKGROUND_YELLOW},
            {Color::BRIGHT_BACKGROUND_BLUE, BRIGHT_BACKGROUND_BLUE},
            {Color::BRIGHT_BACKGROUND_PURPLE, BRIGHT_BACKGROUND_PURPLE},
            {Color::BRIGHT_BACKGROUND_CYAN, BRIGHT_BACKGROUND_CYAN},
            {Color::BRIGHT_BACKGROUND_WHITE, BRIGHT_BACKGROUND_WHITE}
        };
            
    } // #END: ansi

} // #END: pureLog::colors
