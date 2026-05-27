// #FILE: consoleOut.cpp, Module Source File

#ifdef PURE_LOG_USE_MODULES // Using Modules
    module;

    #include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File

    module pureLog; // #FROM: pureLog, Project Module Implementation Unit

    import :consoleOut;
    import :outputStream;
#else // Using Headers
    #include "consoleOut.hpp" // #INCLUDE: consoleOut.hpp, Module Header File
#endif

namespace pureLog{ // #scope: pureLog

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

    // Explicit template instantiations for all configurations
    template class StdCout<OutputStream::BUFFERED>;
    template class StdCout<OutputStream::UNBUFFERED>;
    template class StdCerr<OutputStream::BUFFERED>;
    template class StdCerr<OutputStream::UNBUFFERED>;

} // #END: pureLog
