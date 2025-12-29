// #FILE: outputStream.hpp, Module Header File

#pragma once

#include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File

namespace pureLog::outputStream{ // #scope: pureLog::outputStream

    // #ENUM: OutputStream::Buffering, std::uint8_t Enum Class
    enum class OutputBuffering: std::uint8_t{
        UNBUFFERED, // No buffering
        MANUAL_FLUSH, // Manual flush control
        TERMINATE_FLUSH // Flush at program termination
    }; // #END: OutputStream::Buffering

    // #CLASS: OutputStream
    template<class T_OutputStream> class OutputStream{
    public:
    // Public Factory Methods
        virtual ~OutputStream() = default; // #DEFAULT: ~OutputStream(), Default Public Destructor
    // Public Operators
        T_OutputStream& operator<<(const std::string& p_log);
        T_OutputStream& operator<<(std::string&& p_log);
    // Public Static Methods
        [[nodiscard]] static T_OutputStream& get();
    // Public Methods
        T_OutputStream& push(const std::string& p_log);
        T_OutputStream& push(std::string&& p_log);
        virtual T_OutputStream& flush(); 
    protected:
    // Protected Factory Methods
        OutputStream() = default; // #DEFAULT: OutputStream(), Default Protected Constructor
    // Protected Methods
        virtual void flushOutput();
        virtual void handleLog(const std::string& p_log);
        virtual void handleLog(std::string&& p_log);
        virtual void write(const std::string& p_log) = PURE_LOG_PURE_VIRTUAL; // #VIRTUAL: write(Log&&), Pure Virtual Method
    }; // #END: OutputStream

    // #CLASS: BufferedOutputStream
    template<class T_OutputStream> class BufferedOutputStream: public OutputStream<T_OutputStream>{
    public:
    // Public Factory Methods
        virtual ~BufferedOutputStream() = default; // #DEFAULT: ~BufferedOutputStream(), Default Public Destructor
    // Public Methods
        T_OutputStream& flush()override;
    protected:
    // Protected Factory Methods
        BufferedOutputStream() = default; // #DEFAULT: BufferedOutputStream(), Default Protected Constructor
    // Protected Methods
        void flushBuffer();
        void handleLog(const std::string& p_log)override;
        void handleLog(std::string&& p_log)override;
    // Protected Members
        std::vector<std::string> m_logBuffer; 
    }; // #END: BufferedOutputStream

    bool constexpr isBuffered(OutputBuffering p_buffering);

    template<bool t_conditional, class T_OutputStream> 
    using ConditionallyBuffered = std::conditional_t<t_conditional, BufferedOutputStream<T_OutputStream>, OutputStream<T_OutputStream>>;

} // #END: pureLog::outputStream

#include "outputStream.tpp" // #INCLUDE: outputStream.tpp, Module Template Implementation File