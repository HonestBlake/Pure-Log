// #FILE: consoleOut.cpp, Module Source File  

#include "consoleOut.hpp" // #INCLUDE: consoleOut.hpp, Module Header File

namespace pureLog::consoleOut{ // #scope: pureLog::consoleOut


    // #FUNCTION: write(const std::string&), Template Override Method
    template<OutputBuffering t_buffering, ConsoleInterface t_interface>
    void ConsoleOut<t_buffering, t_interface>::write(const std::string& p_log){
        if constexpr(t_interface == ConsoleInterface::STD_COUT){
            std::cout << p_log;
        }else if constexpr(t_interface == ConsoleInterface::STD_CERR){
            std::cerr << p_log;
        }else if constexpr(t_interface == ConsoleInterface::STD_PRINT){
            // std::print("{}", p_log); //! Not yet supported in GCC 15.1.0
        }
    } // #END: write(const std::string&)

    // #FUNCTION: flushOutput(), Template Override Method
    template<OutputBuffering t_buffering, ConsoleInterface t_interface>
    void ConsoleOut<t_buffering, t_interface>::flushOutput(){
        if constexpr(t_interface == ConsoleInterface::STD_COUT){
            std::cout.flush();
        }else if constexpr(t_interface == ConsoleInterface::STD_CERR){
            std::cerr.flush();
        }
    } // #END: flushOutput()

} // #END: pureLog::consoleOut