// #FILE: consoleOut.cpp, Module Source File  

#include "consoleOut.hpp" // #INCLUDE: consoleOut.hpp, Module Header File\

namespace pureLog::consoleOut{ // #scope: pureLog::consoleOut

// #SCOPE: StdCout<t_isBuffered>

// #DIV: Private Factory Methods

    // #FUNCTION: ~StdCout(), Destructor
    template<bool t_isBuffered>
    StdCout<t_isBuffered>::~StdCout(){
        if constexpr(t_isBuffered){
            this->flushBuffer();
        }
        flushOutput();
    } // #END: ~StdCout()

// #DIV: Private Methods

    // #FUNCTION: write(const std::string&), Template Override Method
    template<bool t_isBuffered>
    void StdCout<t_isBuffered>::write(const std::string& p_log){
        std::cout << p_log;
    } // #END: write(const std::string&)

    // #FUNCTION: flushOutput(), Template Override Method
    template<bool t_isBuffered>
    void StdCout<t_isBuffered>::flushOutput(){
        std::cout.flush();
    } // #END: flushOutput()

// #END: StdCout<t_isBuffered>

// #SCOPE: StdCerr<t_isBuffered>

// #DIV: Private Factory Methods

    // #FUNCTION: ~StdCerr(), Destructor
    template<bool t_isBuffered>
    StdCerr<t_isBuffered>::~StdCerr(){
        if constexpr(t_isBuffered){
            this->flushBuffer();
        }
        flushOutput();
    } // #END: ~StdCerr()

// #DIV: Private Methods

    // #FUNCTION: write(const std::string&), Template Override Method
    template<bool t_isBuffered>
    void StdCerr<t_isBuffered>::write(const std::string& p_log){
        std::cerr << p_log;
    } // #END: write(const std::string&)

    // #FUNCTION: flushOutput(), Template Override Method
    template<bool t_isBuffered>
    void StdCerr<t_isBuffered>::flushOutput(){
        std::cerr.flush();
    } // #END: flushOutput()

// #END: StdCerr<t_isBuffered>

} // #END: pureLog::consoleOut