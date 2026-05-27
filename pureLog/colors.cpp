// #FILE: colors.cpp, Module Source File

#ifdef PURE_LOG_USE_MODULES // Using Modules
    module;

    #include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
    
    module pureLog; // #FROM: pureLog, Project Module Implementation Unit
    import :colors;
#else // Using Headers
    #include "colors.hpp" // #INCLUDE: colors.hpp, Module Header File
#endif

namespace pureLog{ // #SCOPE: pureLog

// #SCOPE: ansi

    // #FUNCTION: getColorCode(const Color), Function
    std::string ansi::getColorCode(const Color p_color){
        if(auto node = COLOR_CODES.find(p_color); node != COLOR_CODES.end()){
            return node->second;
        }
        return WHITE; // Default to white if color not found
    } // #END: getColorCode(const Color)

// #END: ansi

} // #END: pureLog
