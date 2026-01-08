// #FILE: log.cpp, Module Source File

#include "log.hpp" // #INCLUDE: log.hpp, Module Header File 

namespace pureLog::log{ // #scope: pureLog::log

// #DIV: Factory Methods

    // #FUNCTION: Log(), Constructor
    Log::Log(): level(Level::NONE){

    } // #END: Log()

    // #FUNCTION: Log(const std::variant<Log::Level, std::string>), Constructor
    Log::Log(const std::variant<Log::Level, std::string> p_level): level(p_level){

    } // #END: Log(const std::variant<Log::Level, std::string>)

    // #FUNCTION: Log(std::variant<Log::Level, std::string>&&), Constructor
    Log::Log(std::variant<Log::Level, std::string>&& p_level): level(std::move(p_level)){

    } // #END: Log(std::variant<Log::Level, std::string>&&)
        
} // #END: pureLog::log