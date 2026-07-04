// #FILE: log.cpp, Module Source File

#ifdef PURE_LOG_USE_MODULES // Using Modules
    module;

    #ifndef PURE_LOG_IMPORT_STD
        #include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
    #endif

    module pureLog; // #FROM: pureLog, Project Module Implementation Unit

    #ifdef PURE_LOG_IMPORT_STD
        import std;
    #endif

    import :log;

    #ifdef PURE_LOG_IMPORT_STD
        #include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
    #endif
#else // Using Headers
    #include "log.hpp" // #INCLUDE: log.hpp, Module Header File
#endif

namespace pureLog{ // #scope: pureLog

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

// #DIV: Static Methods

    std::string Log::getLevelString(const std::variant<Log::Level, std::string>& p_level){
        if(std::holds_alternative<Log::Level>(p_level)) [[likely]] {
            if(auto node = LEVEL_STRINGS.find(std::get<Log::Level>(p_level)); node != LEVEL_STRINGS.end()) [[likely]] {
                return node->second;
            }
            return ""; // Level not found
        }else{
            return std::get<std::string>(p_level);
        }
    }
        
} // #END: pureLog
