// #FILE: consoleOut.hpp, Module Header File

#pragma once

#include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
#include "outputStream.hpp" // #INCLUDE: outputStream.hpp, Module Header File

namespace pureLog::consoleOut{ // #scope: pureLog::consoleOut

    // #ENUM: ConsoleOutType, std::uint8_t Enum Class
    enum class ConsoleInterface: std::uint8_t{
        STD_COUT, // std::cout
        STD_CERR, // std::cerr
        STD_PRINT // std::print
    }; // #END: ConsoleOutType

    // #CLASS: ConsoleOut
    template<OutputBuffering t_buffering, ConsoleInterface t_interface> class ConsoleOut final: public ConditionallyBuffered<isBuffered(t_buffering), ConsoleOut<t_buffering, t_interface>>{
    public:
        friend ConditionallyBuffered<isBuffered(t_buffering), ConsoleOut<t_buffering, t_interface>>;
    // Public Factory Methods
        ~ConsoleOut() = default; // #DEFAULT: ~ConsoleOut(), Default Public Destructor
    private:
    // Protected Factory Methods
        ConsoleOut() = default; // #DEFAULT: ConsoleOut(), Default Protected Constructor
    // Protected Methods
        void write(const std::string& p_log)override;
        void flushOutput()override;
    }; // #END: ConsoleOut

    // Explicit template instantiations for all configurations
    template class ConsoleOut<OutputBuffering::UNBUFFERED, ConsoleInterface::STD_COUT>;
    template class ConsoleOut<OutputBuffering::UNBUFFERED, ConsoleInterface::STD_CERR>;
    template class ConsoleOut<OutputBuffering::UNBUFFERED, ConsoleInterface::STD_PRINT>;
    template class ConsoleOut<OutputBuffering::MANUAL_FLUSH, ConsoleInterface::STD_COUT>;
    template class ConsoleOut<OutputBuffering::MANUAL_FLUSH, ConsoleInterface::STD_CERR>;
    template class ConsoleOut<OutputBuffering::MANUAL_FLUSH, ConsoleInterface::STD_PRINT>;
    template class ConsoleOut<OutputBuffering::TERMINATE_FLUSH, ConsoleInterface::STD_COUT>;
    template class ConsoleOut<OutputBuffering::TERMINATE_FLUSH, ConsoleInterface::STD_CERR>;
    template class ConsoleOut<OutputBuffering::TERMINATE_FLUSH, ConsoleInterface::STD_PRINT>;

} // #END: pureLog::consoleOut