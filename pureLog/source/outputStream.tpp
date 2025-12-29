// #FILE: outputStream.tpp, Module Template Implementation File

#pragma once

#include "outputStream.hpp" // #INCLUDE: outputStream.hpp, Module Header File

namespace pureLog::outputStream{ // #scope: pureLog::outputStream

// #SCOPE: OutputStream

// #DIV: Public Operators

    // #FUNCTION: operator<<(const std::string&), Operator
    template<class T_OutputStream>
    T_OutputStream& OutputStream<T_OutputStream>::operator<<(const std::string& p_log){
        handleLog(p_log);
        return static_cast<T_OutputStream&>(*this);
    } // #END: operator<<(const std::string&)

    // #FUNCTION: operator<<(std::string&&), Operator
    template<class T_OutputStream> 
    T_OutputStream& OutputStream<T_OutputStream>::operator<<(std::string&& p_log){
        handleLog(std::move(p_log));
        return static_cast<T_OutputStream&>(*this);
    } // #END: operator<<(std::string&&)

// #DIV: Public Static Methods

    // #FUNCTION: get(), Static Method
    template<class T_OutputStream> 
    T_OutputStream& OutputStream<T_OutputStream>::get(){
        // static_assert(std::is_default_constructible_v<T_OutputStream>, "Custom output stream type must define a default constructor.");
        static_assert(OutputStreamDerived<T_OutputStream>, "Custom output stream type must derive from pureLog::OutputStream.");
        static T_OutputStream instance = T_OutputStream();
        return instance;
    } // #END: get()

// #DIV: Public Methods

    // #FUNCTION: push(const std::string&), Method
    template<class T_OutputStream>
    T_OutputStream& OutputStream<T_OutputStream>::push(const std::string& p_log){
        handleLog(p_log);
        return dynamic_cast<T_OutputStream&>(*this);
    } // #END: push(const std::string&)

    // #FUNCTION: push(std::string&&), Method
    template<class T_OutputStream> 
    T_OutputStream& OutputStream<T_OutputStream>::push(std::string&& p_log){
        handleLog(std::move(p_log));
        return dynamic_cast<T_OutputStream&>(*this);
    } // #END: push(std::string&&)

    // #FUNCTION: flush(), Method
    template<class T_OutputStream> 
    T_OutputStream& OutputStream<T_OutputStream>::flush(){
        flushOutput();
        return *dynamic_cast<T_OutputStream*>(this);
    } // #END: flush()

// #DIV: Protected Methods

    // #FUNCTION: handleLog(const std::string&), Method
    template<class T_OutputStream>
    void OutputStream<T_OutputStream>::handleLog(const std::string& p_log){
        write(p_log);
    } // #END: handleLog(const std::string&)

    // #FUNCTION: handleLog(std::string&&), Method
    template<class T_OutputStream> 
    void OutputStream<T_OutputStream>::handleLog(std::string&& p_log){
        write(p_log);
    } // #END: handleLog(std::string&&)

    // #FUNCTION: flushOutput(), Method
    template<class T_OutputStream>
    void OutputStream<T_OutputStream>::flushOutput(){
        // Implemented by derived classes
    } // #END: flushOutput()


// #END: OutputStream

// #SCOPE: BufferedOutputStream

// #DIV: Public Methods

    // #FUNCTION: flush(), Method
    template<class T_OutputStream> 
    T_OutputStream& BufferedOutputStream<T_OutputStream>::flush(){
        flushBuffer();
        this->flushOutput();
        return *dynamic_cast<T_OutputStream*>(this);
    } // #END: flush()

// #DIV: Protected Methods
 
    // #FUNCTION: flushBuffer(), Method
    template<class T_OutputStream> 
    void BufferedOutputStream<T_OutputStream>::flushBuffer(){
        for(const std::string& log: m_logBuffer){
            this->write(log);
        }
        m_logBuffer.clear();
    } // #END: flushBuffer()

    // #FUNCTION: handleLog(const std::string&), Method
    template<class T_OutputStream>
    void BufferedOutputStream<T_OutputStream>::handleLog(const std::string& p_log){
        m_logBuffer.push_back(p_log);
    } // #END: handleLog(const std::string&)

    // #FUNCTION: handleLog(std::string&&), Method
    template<class T_OutputStream>
    void BufferedOutputStream<T_OutputStream>::handleLog(std::string&& p_log){
        m_logBuffer.push_back(std::move(p_log));
    } // #END: handleLog(std::string&&)

// #END: BufferedOutputStream

bool constexpr isBuffered(OutputBuffering p_buffering){
    return p_buffering != OutputBuffering::UNBUFFERED;
}

} // #END: pureLog::outputStream