// #FILE: logger.hpp, Module Header File

#pragma once

#include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
#include "log.hpp" // #INCLUDE: log.hpp, Module Header File
#include "outputStream.hpp" // #INCLUDE: outputStream.hpp, Module Header File
#include "consoleOut.hpp" // #INCLUDE: consoleOut.hpp, Module Header File

namespace pureLog::logger{ // #scope: pureLog::logger

    using DefaultOutputStream = consoleOut::ConsoleOut<outputStream::OutputBuffering::UNBUFFERED, consoleOut::ConsoleInterface::STD_COUT>;
    
    // #CONCEPT: LoggerDerived, Type Concept
    template<class T_Logger, class T_OutputStream> concept LoggerDerived = std::is_base_of_v<Logger<T_Logger, T_OutputStream>, T_Logger>;
    // #END: LoggerDerived

    // #CLASS: Logger
    template<class T_Logger, OutputStreamDerived T_OutputStream> class Logger{
    public:
    // Public Factory Methods
        ~Logger() = default; // #DEFAULT: ~Logger(), Destructor
    // Public Static Methods
        [[nodiscard]] static T_Logger& get();
    // Public Methods
        T_Logger& log();
        template<class... T_Args> T_Logger& log(const std::string& p_message, T_Args&&... p_args);
        T_Logger& log(std::string&& p_message);
        T_Logger& info();
        template<class... T_Args> T_Logger& info(const std::string& p_message, T_Args&&... p_args);
        T_Logger& info(std::string&& p_message);
        T_Logger& warn();
        template<class... T_Args> T_Logger& warn(const std::string& p_message, T_Args&&... p_args);
        T_Logger& warn(std::string&& p_message);
        T_Logger& error();
        template<class... T_Args> T_Logger& error(const std::string& p_message, T_Args&&... p_args);
        T_Logger& error(std::string&& p_message);
        T_Logger& critical();
        template<class... T_Args> T_Logger& critical(const std::string& p_message, T_Args&&... p_args);
        T_Logger& critical(std::string&& p_message);
        T_Logger& fatal();
        template<class... T_Args> T_Logger& fatal(const std::string& p_message, T_Args&&... p_args);
        T_Logger& fatal(std::string&& p_message);
        T_Logger& trace();
        template<class... T_Args> T_Logger& trace(const std::string& p_message, T_Args&&... p_args);
        T_Logger& trace(std::string&& p_message);
        T_Logger& debug();
        template<class... T_Args> T_Logger& debug(const std::string& p_message, T_Args&&... p_args);
        T_Logger& debug(std::string&& p_message);
        template<class... T_Args> T_Logger& message(const std::string& p_message, T_Args&&... p_args);
        T_Logger& message(std::string&& p_message);
        T_Logger& time(const std_TimePoint& p_time = std::chrono::system_clock::now());
        T_Logger& time(const std::time_t p_time);
        T_Logger& location(const std::source_location& p_location = std::source_location::current());
        T_Logger& location(std::source_location&& p_location);
        T_Logger& send();
        T_Logger& flush();
        T_Logger& logFormat(const std::array<Log::Format, Log::NUM_FORMATS>& p_logFormat);
        T_Logger& logFormat(std::array<Log::Format, Log::NUM_FORMATS>&& p_logFormat);
        T_Logger& logFormat(std::initializer_list<Log::Format> p_logFormat);
    // Public Static Members
        static inline constexpr std::array<Log::Format, Log::NUM_FORMATS> DEFAULT_LOG_FORMAT = {
            Log::Format::TIME,
            Log::Format::LEVEL,
            Log::Format::NAME,
            Log::Format::MESSAGE,
            Log::Format::LOCATION
        };
    protected:
    // Protected Factory Methods
        explicit Logger(const std::string& p_name);
        Logger(const std::string& p_name, const std::array<Log::Format, Log::NUM_FORMATS>& p_logFormat);
    // Protected Methods
        void initiateLog(Log::Level p_level);
        template<class... T_Args> void initiateLog(Log::Level p_level, const std::string& p_message, T_Args&&... p_args);
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
        T_OutputStream& m_outputStream;
        std::array<Log::Format, Log::NUM_FORMATS> m_logFormat;
    }; // #END: Logger



} // #END: pureLog::logger

#include "logger.tpp" // #INCLUDE: logger.tpp, Module Template Implementation File
    