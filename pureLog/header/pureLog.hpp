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
        template<class T_OutputStream> class OutputStream;
        // #CONCEPT: OutputStreamDerived, Type Concept
        template<class Type> concept OutputStreamDerived = std::is_base_of_v<OutputStream<Type>, Type>;
        // #END: OutputStreamDerived
        
    } // #END: outputStream

    // #NAMESPACE: logger, Inline Module Namespace
    inline namespace logger{
        template<class T_Logger, OutputStreamDerived T_OutputStream> class Logger;
    } // #END: logger

    // #NAMESPACE: consoleOut, Inline Module Namespace
    inline namespace consoleOut{
        enum class ConsoleInterface: std::uint8_t;
        template<OutputBuffering t_buffering, ConsoleInterface t_interface> class ConsoleOut;
    } // #END: consoleOut

    // #NAMESPACE: fileOut, Inline Module Namespace
    inline namespace fileOut{
        class FileOut;
    } // #END: fileOut

} // #END: pureLog
