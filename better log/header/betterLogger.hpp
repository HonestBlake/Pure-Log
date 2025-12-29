// #file: betterLogger.hpp, header file

#pragma once

#include "standardLibraries.hpp" // standard libraries

#define ODR_IGNORE inline 

// #namespace: worTech, inline developer namespace
inline namespace worTech{

    // #namespace: betterCpp, project namespace
    namespace betterCpp{

        // #namespace: logStacks, inline module namespace
        inline namespace logStacks{
            namespace defaultFormats{} 
            namespace deflt = defaultFormats; // #alias defaultFormats to deflt
            class LogStack;
        } // #end logStacks

        // #namespace: formats, inline module namespace
        inline namespace formats{
            namespace ansiiColorCodes{} 
            namespace ansii = ansiiColorCodes; // alias ansiiColorCodes to ansii
            enum struct LogLevel: uint8_t; 
            using Level = LogLevel; // alias LogLevel to Level
            enum struct FormatType: uint8_t; 
            using Format = FormatType; // alias FormatType to Format
            namespace logFormatting{} 
            namespace log = logFormatting; // alias logFormatting to log
        } // #end formats

        // #namespace: loggers, inline module namespace
        inline namespace loggers{
            namespace defaultFormats{} 
            namespace deflt = defaultFormats; // alias defaultFormats to deflt
            class Logger;
        } // #end loggers

        // #namespace: defaultLogStacks, inline module namespace
        inline namespace defaultLogStacks{
            namespace loggerValues{} 
            namespace logger = loggerValues; // alias loggerValues to logger
            class AutoFlush;
            class TerminateFlush;
        } // #end defaultLogStacks

        // #namespace: defaultLoggers, inline module namespace
        inline namespace defaultLoggers{
            namespace loggerValues{} 
            namespace logger = loggerValues; // #alias loggerValues to logger
            class Main;
            class Debug;
        } // #end defaultLoggers

    } // #end betterCpp
    namespace better = betterCpp; // alias betterCpp to better
    namespace btr = betterCpp; // alias betterCpp to btr
    
} // #end worTech
namespace wt = worTech; // alias worTech to wt