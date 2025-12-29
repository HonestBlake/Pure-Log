// #file: defaultLogStacks.hpp, header file

#pragma once

#include "betterLogger.hpp" // Project header
#include "logStacks.hpp" // Holds LogStack class

namespace worTech::betterCpp::defaultLogStacks{

    // #namespace: loggerValues(logger), variable namespace
    // #scope: defaultLogStacks, component namespace
    // #info: holds values for log stack classes
    namespace loggerValues{
        inline constexpr bool AUTO_FLUSH_TERMINATE_FLUSH = false;
        inline constexpr bool AUTO_FLUSH_AUTO_FLUSH = true;
        inline constexpr bool TERMINATE_FLUSH_TERMINATE_FLUSH = true;
        inline constexpr bool TERMINATE_FLUSH_AUTO_FLUSH = false;
    } // #end loggerValues

    // #class: AutoFlush, final singleton class
    class AutoFlush final: public LogStack{
    public:
        friend class LogStack;
    private:
        AutoFlush();
    }; // #end AutoFlush

    // #class: TerminateFlush, final singleton class
    class TerminateFlush final: public LogStack{
    public:
        friend class LogStack;
    private:
        TerminateFlush();
    }; // #end TerminateFlush

} // namespace worTech::betterLogger::defaultLogStacks