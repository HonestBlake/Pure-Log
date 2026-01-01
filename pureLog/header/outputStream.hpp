// #FILE: outputStream.hpp, Module Header File

#pragma once

#include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File

namespace pureLog::outputStream{ // #SCOPE: pureLog::outputStream

    // #CONCEPT: OutputStreamDerived, Type Concept
    template<class Type> concept OutputStreamDerived = std::is_base_of_v<OutputStream, Type>;
    // #END: OutputStreamDerived

    // #ENUM: OutputStream::Buffering, std::uint8_t Enum Class
    enum class OutputBuffering: std::uint8_t{
        UNBUFFERED, // No buffering
        MANUAL_FLUSH, // Manual flush control
        TERMINATE_FLUSH // Flush at program termination
    }; // #END: OutputStream::Buffering

    // #CLASS: OutputStream
    class OutputStream{
    public:
    // Public Factory Methods
        virtual ~OutputStream() = default; // #DEFAULT: ~OutputStream(), Default Virtual Destructor
    // Public Operators
        OutputStream& operator<<(std::string&& p_log);
    // Public Static Methods
        template<class T_Derived> [[nodiscard]] static T_Derived& get();
    // Public Methods
        virtual OutputStream& flush(); 
    // Public Static Members
        static constexpr bool BUFFERED = true;
        static constexpr bool UNBUFFERED = false;
    protected:
    // Protected Factory Methods
        OutputStream() = default; // #DEFAULT: OutputStream(), Default Protected Constructor
    // Protected Methods
        virtual void flushOutput();
        virtual void handleLog(std::string&& p_log);
        virtual void write(const std::string& p_log) = PURE_LOG_PURE_VIRTUAL; // #VIRTUAL: write(Log&&), Pure Virtual Method
    }; // #END: OutputStream

    // #CLASS: BufferedOutputStream
    class BufferedOutputStream: public OutputStream{
    public:
    // Public Factory Methods
        virtual ~BufferedOutputStream() = default; // #DEFAULT: ~BufferedOutputStream(), Default Virtual Destructor
    // Public Methods
        OutputStream& flush()override;
    protected:
    // Protected Factory Methods
        BufferedOutputStream() = default; // #DEFAULT: BufferedOutputStream(), Default Protected Constructor
    // Protected Methods
        void flushBuffer();
        void handleLog(std::string&& p_log)override;
    // Protected Members
        std::vector<std::string> m_logBuffer; 
    }; // #END: BufferedOutputStream

    template<bool t_conditional> 
    using ConditionallyBuffered = std::conditional_t<t_conditional, BufferedOutputStream, OutputStream>;

} // #END: pureLog::outputStream

#include "outputStream.tpp" // #INCLUDE: outputStream.tpp, Module Template Implementation File