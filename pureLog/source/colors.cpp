// #FILE: colors.cpp, Module Source File

#include "colors.hpp" // #INCLUDE: colors.hpp, Module Header File

namespace pureLog::colors{ // #scope: pureLog::colors

// #SCOPE: ansi

    // #FUNCTION: getColorCode(const Color), Function
    std::string ansi::getColorCode(const Color p_color){
        if(auto node = COLOR_CODES.find(p_color); node != COLOR_CODES.end()){
            return node->second;
        }
        return WHITE; // Default to white if color not found
    } // #END: getColorCode(const Color)

} // #END: pureLog::colors