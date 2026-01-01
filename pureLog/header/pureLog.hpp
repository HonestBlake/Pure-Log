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

#define PURE_LOG_PURE_VIRTUAL 0

#pragma once

#include "standardLibs.hpp" // #INCLUDE: standardLibs.hpp, Standard Library Includes

// #NAMESPACE: pureLog, Project Namespace
namespace pureLog{ 

    using std_TimePoint = std::chrono::time_point<std::chrono::system_clock>;

    // #NAMESPACE: log, Inline Module Namespace
    inline namespace log{
        class Log;
    } // #END: log

    // #NAMESPACE: outputStream, Inline Module Namespace
    inline namespace outputStream{
        enum class OutputBuffering: std::uint8_t;
        class OutputStream;
        class BufferedOutputStream;
    } // #END: outputStream

    // #NAMESPACE: logger, Inline Module Namespace
    inline namespace logger{
        template<class T_Derived> class Logger;
    } // #END: logger

    // #NAMESPACE: consoleOut, Inline Module Namespace
    inline namespace consoleOut{
        template<bool t_isBuffered> class StdCout;
        template<bool t_isBuffered> class StdCerr;
    } // #END: consoleOut

    // #NAMESPACE: fileOut, Inline Module Namespace
    inline namespace fileOut{
        class FileOut;
    } // #END: fileOut

} // #END: pureLog
