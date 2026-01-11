// #FILE: pureLog.hpp, Project Header File

//   _____                  _                  
//  |  __ \                | |                 
//  | |__) |   _ _ __ ___  | |     ___   __ _  
//  |  ___/ | | | '__/ _ \ | |    / _ \ / _` | 
//  | |   | |_| | | |  __/ | |___| (_) | (_| | 
//  |_|    \__,_|_|  \___| |______\___/ \__, | 
//                                       __/ | 
//                                      |___/  
// Pure Log, A Simple and Efficient C++ Logging Library

#pragma once

#define PURE_LOG_PURE_VIRTUAL 0

#include "stdIncludes.hpp" // #INCLUDE: standardLibs.hpp, Standard Library Includes

// #NAMESPACE: pureLog, Project Namespace
namespace pureLog{ 

    using std_TimePoint = std::chrono::time_point<std::chrono::system_clock>;

    // #NAMESPACE: log, Inline Module Namespace
    inline namespace log{
        class Log;
    } // #END: log

    // #NAMESPACE: formats, Inline Module Namespace
    inline namespace formats{
        struct Formatting;
    } // #END: formats

    // #NAMESPACE: colors, Inline Module Namespace
    inline namespace colors{
        struct Coloring;
        enum class Color: std::uint8_t;
        namespace ansi{}
    } // #END: colors

    // #NAMESPACE: outputStream, Inline Module Namespace
    inline namespace outputStream{
        enum class OutputBuffering: std::uint8_t;
        class OutputStream;
        class BufferedOutputStream;
    } // #END: outputStream

    // #NAMESPACE: logger, Inline Module Namespace
    inline namespace logger{
        constexpr bool USING_LEVEL_FORMATS = true;
        constexpr bool USING_COLORS = true;
        template<class T_Derived, bool t_usingLevelFormatting = USING_LEVEL_FORMATS, bool t_usingColors = USING_COLORS> class Logger;
    } // #END: logger

    // #NAMESPACE: consoleOut, Inline Module Namespace
    inline namespace consoleOut{
        template<bool t_isBuffered> class StdCout;
        template<bool t_isBuffered> class StdCerr;
    } // #END: consoleOut

    // #NAMESPACE: fileOut, Inline Module Namespace
    inline namespace fileOut{
        template<bool t_isBuffered> class FileOut;
    } // #END: fileOut

} // #END: pureLog
