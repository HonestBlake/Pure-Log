// #file: defaultLogStacks.hpp, source file

#include "defaultLogStacks.hpp" // Module header

namespace worTech::betterCpp::defaultLogStacks{

// #div: AutoFlush, singleton class

    // #func: AutoFlush, private constructor
    AutoFlush::AutoFlush(): LogStack(logger::AUTO_FLUSH_TERMINATE_FLUSH, logger::AUTO_FLUSH_AUTO_FLUSH){}

// #div: TerminateFlush, singleton class

    // #func: TerminateFlush, private constructor
    TerminateFlush::TerminateFlush(): LogStack(logger::TERMINATE_FLUSH_TERMINATE_FLUSH, logger::TERMINATE_FLUSH_AUTO_FLUSH){}

} // namespace worTech::betterLogger::defaultLogStacks