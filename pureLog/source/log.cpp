// #FILE: log.cpp, Module Source File

#include "log.hpp" // #INCLUDE: log.hpp, Module Header File 

namespace pureLog::log{ // #scope: pureLog::log

// #DIV: Factory Methods

    // #FUNCTION: Log(), Constructor
    Log::Log(): level(Level::LOG){

    } // #END: Log()

    // #FUNCTION: Log(Level), Constructor
    Log::Log(Level p_level): level(p_level){

    } // #END: Log(Level)
        
} // #END: pureLog::log