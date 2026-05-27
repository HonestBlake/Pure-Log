// #FILE: outputStream.hpp, Module Header File

#pragma once

#if defined(PURE_LOG_USE_MODULES) && defined(INCLUDED_BY_MODULE) // Using Modules
    #define MODULE_EXPORT export
#else // Using Headers Or Open as stand alone file
    #include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
    #define MODULE_EXPORT
#endif

namespace pureLog{ // #SCOPE: pureLog

    // #ENUM: OutputStream::Buffering, std::uint8_t Enum Class
    MODULE_EXPORT enum class OutputBuffering: std::uint8_t{
        UNBUFFERED, // No buffering
        MANUAL_FLUSH, // Manual flush control
        TERMINATE_FLUSH // Flush at program termination
    }; // #END: OutputStream::Buffering

    // #CLASS: OutputStream
    MODULE_EXPORT class OutputStream{
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

    // #CONCEPT: OutputStreamDerived, Type Concept
    MODULE_EXPORT template<class Type> concept OutputStreamDerived = std::is_base_of_v<OutputStream, Type>;
    // #END: OutputStreamDerived

    // #CLASS: BufferedOutputStream
    MODULE_EXPORT class BufferedOutputStream: public OutputStream{
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

    MODULE_EXPORT template<bool t_conditional>
    using ConditionallyBuffered = std::conditional_t<t_conditional, BufferedOutputStream, OutputStream>;

} // #END: pureLog

#undef MODULE_EXPORT

#include "outputStream.tpp" // #INCLUDE: outputStream.tpp, Module Template Implementation File
