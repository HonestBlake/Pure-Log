// #file: defaultLoggers.hpp, header file

#pragma once

#include "betterLogger.hpp" // Project header
#include "loggers.hpp" // Include for Logger class

namespace worTech::betterCpp::defaultLoggers{

    // #namespace: loggerValues(logger), variable namespace
    namespace loggerValues{
        inline constexpr std::string MAIN_NAME = "main";
        inline constexpr std::string DEBUG_NAME = "debug";
    } // #end loggerValues

    // #class: Main, singleton class
    class Main final: public Logger{
    public:
        Main();
    }; // #end Main

    // #class: Debug, singleton class
    class Debug final: public Logger{
    public:
        Debug();
    }; // #end Debug

} // namespace worTech::betterLogger::defaultLoggers