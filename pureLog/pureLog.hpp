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

#include "stdIncludes.hpp" // #INCLUDE: standardLibs.hpp, Standard Library Includes

#define PURE_LOG_PURE_VIRTUAL 0 // For pure virtual declarations

// #NAMESPACE: pureLog, Exported Project Namespace
namespace pureLog{ 

    using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

    // class Log;

    // struct Formatting;

    // struct Coloring;
    // enum class Color: std::uint8_t;
    // namespace ansi{}

    // enum class OutputBuffering: std::uint8_t;
    // class OutputStream;
    // class BufferedOutputStream;

    // constexpr bool USING_LEVEL_FORMATS = true;
    // constexpr bool USING_COLORS = true;
    // template<class T_Derived, bool t_usingLevelFormatting = USING_LEVEL_FORMATS, bool t_usingColors = USING_COLORS> class Logger;

    // template<bool t_isBuffered> class StdCout;
    // template<bool t_isBuffered> class StdCerr;

    // template<bool t_isBuffered> class FileOut;

} // #END: pureLog