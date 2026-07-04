// #FILE: outputStream.cpp, Module Source File

#ifdef PURE_LOG_USE_MODULES // Using Modules
    module;

    #ifndef PURE_LOG_IMPORT_STD
        #include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
    #endif

    module pureLog; // #FROM: pureLog, Project Module Implementation Unit

    #ifdef PURE_LOG_IMPORT_STD
        import std;
    #endif

    import :outputStream;

    #ifdef PURE_LOG_IMPORT_STD
        #include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
    #endif
#else // Using Headers
    #include "outputStream.hpp" // #INCLUDE: outputStream.hpp, Module Header File
#endif

namespace pureLog{ // #scope: pureLog

// #SCOPE: OutputStream

// #DIV: Public Operators

    // #FUNCTION: operator<<(std::string&&), Operator
    OutputStream& OutputStream::operator<<(std::string&& p_log){
        handleLog(std::move(p_log));
        return *this;
    } // #END: operator<<(std::string&&)

// #DIV: Public Methods

    // #FUNCTION: flush(), Method
    OutputStream& OutputStream::flush(){
        flushOutput();
        return *this;
    } // #END: flush()

// #DIV: Protected Methods

    // #FUNCTION: handleLog(std::string&&), Method
    void OutputStream::handleLog(std::string&& p_log){
        write(p_log);
    } // #END: handleLog(std::string&&)

    // #FUNCTION: flushOutput(), Method
    void OutputStream::flushOutput(){
        // Implemented by derived classes
    } // #END: flushOutput()

// #END: OutputStream

// #SCOPE: BufferedOutputStream

// #DIV: Public Methods

    // #FUNCTION: flush(), Method
    OutputStream& BufferedOutputStream::flush(){
        flushBuffer();
        flushOutput();
        return *this;
    } // #END: flush()

// #DIV: Protected Methods
 
    // #FUNCTION: flushBuffer(), Method
    void BufferedOutputStream::flushBuffer(){
        for(const std::string& log: m_logBuffer){
            write(log);
        }
        m_logBuffer.clear();
    } // #END: flushBuffer()

    // #FUNCTION: handleLog(std::string&&), Method
    void BufferedOutputStream::handleLog(std::string&& p_log){
        m_logBuffer.emplace_back(std::move(p_log));
    } // #END: handleLog(std::string&&)

// #END: BufferedOutputStream

} // #END: pureLog
