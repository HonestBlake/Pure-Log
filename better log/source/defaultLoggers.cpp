// #file: defaultLoggers.hpp, source file

#include "defaultLoggers.hpp" // Module header

namespace worTech::betterCpp::defaultLoggers{

// #div: Main, singleton class

    // #func: Main, public constructor
    Main::Main(): Logger(std::move(logger::MAIN_NAME)){}

// #div: Debug, singleton class
    
    // #func: Debug, public constructor
    Debug::Debug(): Logger(std::move(logger::DEBUG_NAME)){}
    
} // namespace worTech::betterLogger::defaultLoggers