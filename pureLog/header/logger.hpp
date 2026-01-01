// #FILE: logger.hpp, Module Header File

#pragma once

#include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
#include "log.hpp" // #INCLUDE: log.hpp, Module Header File
#include "outputStream.hpp" // #INCLUDE: outputStream.hpp, Module Header File
#include "consoleOut.hpp" // #INCLUDE: consoleOut.hpp, Module Header File

namespace pureLog::logger{ // #scope: pureLog::logger

    using DefaultOutputStream = StdCout<OutputStream::UNBUFFERED>;
    
    // #CONCEPT: LoggerDerived, Type Concept
    template<class Type> concept LoggerDerived = std::is_base_of_v<Logger<Type>, Type>;
    // #END: LoggerDerived

    // #CLASS: Logger<T_Derived>
    template<class T_Derived> class Logger{
    public:
    // Public Factory Methods
        virtual ~Logger();
    // Public Static Methods
        [[nodiscard]] static T_Derived& get();
    // Public Methods
        T_Derived& log();
        template<class... T_Args> T_Derived& log(const std::string& p_message, T_Args... p_args);
        T_Derived& log(std::string&& p_message);
        T_Derived& info();
        template<class... T_Args> T_Derived& info(const std::string& p_message, T_Args... p_args);
        T_Derived& info(std::string&& p_message);
        T_Derived& warn();
        template<class... T_Args> T_Derived& warn(const std::string& p_message, T_Args... p_args);
        T_Derived& warn(std::string&& p_message);
        T_Derived& error();
        template<class... T_Args> T_Derived& error(const std::string& p_message, T_Args... p_args);
        T_Derived& error(std::string&& p_message);
        T_Derived& critical();
        template<class... T_Args> T_Derived& critical(const std::string& p_message, T_Args... p_args);
        T_Derived& critical(std::string&& p_message);
        T_Derived& fatal();
        template<class... T_Args> T_Derived& fatal(const std::string& p_message, T_Args... p_args);
        T_Derived& fatal(std::string&& p_message);
        T_Derived& trace();
        template<class... T_Args> T_Derived& trace(const std::string& p_message, T_Args... p_args);
        T_Derived& trace(std::string&& p_message);
        T_Derived& debug();
        template<class... T_Args> T_Derived& debug(const std::string& p_message, T_Args... p_args);
        T_Derived& debug(std::string&& p_message);
        template<class... T_Args> T_Derived& message(const std::string& p_message, T_Args... p_args);
        T_Derived& message(std::string&& p_message);
        T_Derived& time(const std_TimePoint& p_time = std::chrono::system_clock::now());
        T_Derived& time(const std::time_t p_time);
        T_Derived& location(const std::source_location& p_location = std::source_location::current());
        T_Derived& location(std::source_location&& p_location);
        T_Derived& send();
        T_Derived& flush();
        T_Derived& logFormat(const std::array<Log::Format, Log::NUM_FORMATS>& p_logFormat);
        T_Derived& logFormat(std::array<Log::Format, Log::NUM_FORMATS>&& p_logFormat);
        T_Derived& logFormat(std::initializer_list<Log::Format> p_logFormat);
        T_Derived& outputStream(OutputStream& p_outputStream);
    // Public Static Members
    protected:
    // Protected Factory Methods
        Logger(const std::string& p_name, OutputStream& p_outputStream = OutputStream::get<DefaultOutputStream>());
    // Protected Methods
        void initiateLog(Log::Level p_level);
        template<class... T_Args> void initiateLog(Log::Level p_level, const std::string& p_message, T_Args... p_args);
        void initiateLog(Log::Level p_level, std::string&& p_message);
        void flushBuffer();
        std::string formatLog(const Log& p_log);
        std::string formatPart(const Log::Format p_format, const Log& p_log);
        virtual std::string formatName(const std::string& p_name);
        virtual std::string formatMessage(const std::string& p_message);
        virtual std::string formatLevel(const Log::Level p_level);
        virtual std::string formatTime(const std_TimePoint& p_time);
        virtual std::string formatLocation(const std::source_location& p_location);
    // Protected Members
        std::string m_name;
        std::optional<Log> m_bufferedLog;
        OutputStream& m_outputStream;
        std::array<Log::Format, Log::NUM_FORMATS> m_logFormat;
    }; // #END: Logger



} // #END: pureLog::logger

#include "logger.tpp" // #INCLUDE: logger.tpp, Module Template Implementation File
    