// #FILE: logger.tpp, Module Template Implementation File

#pragma once

#include "logger.hpp" // #INCLUDE: logger.hpp, Module Header File
#include <format>
#include <string>

namespace pureLog::logger{ // #scope: pureLog::logger

// #DIV: Public Static Methods

    // #FUNCTION: get(), Static Method
    template<class T_Logger, OutputStreamDerived T_OutputStream> 
    [[nodiscard]] T_Logger& Logger<T_Logger, T_OutputStream>::get(){
        // static_assert(std::is_default_constructible_v<T_Logger>, "Custom logger type must define a default constructor.");
        static_assert(LoggerDerived<T_Logger, T_OutputStream>, "Custom logger type must derive from pureLog::Logger.");
        static T_Logger instance = T_Logger();
        return instance;
    } // #END: get()    

// #DIV: Public Methods

    // #FUNCTION: log(), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream> 
    T_Logger& Logger<T_Logger, T_OutputStream>::log(){
        initiateLog(Log::Level::LOG);
        return static_cast<T_Logger&>(*this);
    } // #END: log()

    // #FUNCTION: log<..T_Args>(const std::string&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    template<class... T_Args> T_Logger& Logger<T_Logger, T_OutputStream>::log(const std::string& p_message, T_Args&&... p_args){
        initiateLog(Log::Level::LOG, p_message, std::forward<T_Args>(p_args)...);
        return static_cast<T_Logger&>(*this);
    } // #END: log<..T_Args>(const std::string&)

    // #FUNCTION: log(std::string&&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    T_Logger& Logger<T_Logger, T_OutputStream>::log(std::string&& p_message){
        initiateLog(Log::Level::LOG, std::move(p_message));
        return static_cast<T_Logger&>(*this);
    } // #END: log(std::string&&)

    // #FUNCTION: info(), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream> 
    T_Logger& Logger<T_Logger, T_OutputStream>::info(){
        initiateLog(Log::Level::INFO);
        return static_cast<T_Logger&>(*this);
    } // #END: info()

    // #FUNCTION: info<..T_Args>(const std::string&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    template<class... T_Args> T_Logger& Logger<T_Logger, T_OutputStream>::info(const std::string& p_message, T_Args&&... p_args){
        initiateLog(Log::Level::INFO, p_message, std::forward<T_Args>(p_args)...);
        return static_cast<T_Logger&>(*this);
    } // #END: info<..T_Args>(const std::string&)

    // #FUNCTION: info(std::string&&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    T_Logger& Logger<T_Logger, T_OutputStream>::info(std::string&& p_message){
        initiateLog(Log::Level::INFO, std::move(p_message));
        return static_cast<T_Logger&>(*this);
    } // #END: info(std::string&&)

    // #FUNCTION: warn(), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream> 
    T_Logger& Logger<T_Logger, T_OutputStream>::warn(){
        initiateLog(Log::Level::WARN);
        return static_cast<T_Logger&>(*this);
    } // #END: warn()

    // #FUNCTION: warn<..T_Args>(const std::string&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    template<class... T_Args> T_Logger& Logger<T_Logger, T_OutputStream>::warn(const std::string& p_message, T_Args&&... p_args){
        initiateLog(Log::Level::WARN, p_message, std::forward<T_Args>(p_args)...);
        return static_cast<T_Logger&>(*this);
    } // #END: warn<..T_Args>(const std::string&)

    // FUNCTION: warn(std::string&&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    T_Logger& Logger<T_Logger, T_OutputStream>::warn(std::string&& p_message){
        initiateLog(Log::Level::WARN, std::move(p_message));
        return static_cast<T_Logger&>(*this);
    } // #END: warn(std::string&&)

    // #FUNCTION: error(), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream> 
    T_Logger& Logger<T_Logger, T_OutputStream>::error(){
        initiateLog(Log::Level::ERROR);
        return static_cast<T_Logger&>(*this);
    } // #END: error()

    // #FUNCTION: error<..T_Args>(const std::string&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    template<class... T_Args> T_Logger& Logger<T_Logger, T_OutputStream>::error(const std::string& p_message, T_Args&&... p_args){
        initiateLog(Log::Level::ERROR, p_message, std::forward<T_Args>(p_args)...);
        return static_cast<T_Logger&>(*this);
    } // #END: error<..T_Args>(const std::string&)

    // FUNCTION: error(std::string&&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    T_Logger& Logger<T_Logger, T_OutputStream>::error(std::string&& p_message){
        initiateLog(Log::Level::ERROR, std::move(p_message));
        return static_cast<T_Logger&>(*this);
    } // #END: error(std::string&&)

    // #FUNCTION: critical(), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream> 
    T_Logger& Logger<T_Logger, T_OutputStream>::critical(){
        initiateLog(Log::Level::CRITICAL);
        return static_cast<T_Logger&>(*this);
    } // #END: critical()

    // #FUNCTION: critical<..T_Args>(const std::string&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    template<class... T_Args> T_Logger& Logger<T_Logger, T_OutputStream>::critical(const std::string& p_message, T_Args&&... p_args){
        initiateLog(Log::Level::CRITICAL, p_message, std::forward<T_Args>(p_args)...);
        return static_cast<T_Logger&>(*this);
    } // #END: critical<..T_Args>(const std::string&)

    // #FUNCTION: critical(std::string&&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    T_Logger& Logger<T_Logger, T_OutputStream>::critical(std::string&& p_message){
        initiateLog(Log::Level::CRITICAL, std::move(p_message));
        return static_cast<T_Logger&>(*this);
    } // #END: critical(std::string&&)

    // #FUNCTION: fatal(), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream> 
    T_Logger& Logger<T_Logger, T_OutputStream>::fatal(){
        initiateLog(Log::Level::FATAL);
        return static_cast<T_Logger&>(*this);
    } // #END: fatal()

    // #FUNCTION: fatal<..T_Args>(const std::string&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    template<class... T_Args> T_Logger& Logger<T_Logger, T_OutputStream>::fatal(const std::string& p_message, T_Args&&... p_args){
        initiateLog(Log::Level::FATAL, p_message, std::forward<T_Args>(p_args)...);
        return static_cast<T_Logger&>(*this);
    } // #END: fatal<..T_Args>(const std::string&)

    // #FUNCTION: fatal(std::string&&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    T_Logger& Logger<T_Logger, T_OutputStream>::fatal(std::string&& p_message){
        initiateLog(Log::Level::FATAL, std::move(p_message));
        return static_cast<T_Logger&>(*this);
    } // #END: fatal(std::string&&)

    // #FUNCTION: trace(), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream> 
    T_Logger& Logger<T_Logger, T_OutputStream>::trace(){
        initiateLog(Log::Level::TRACE);
        return static_cast<T_Logger&>(*this);
    } // #END: trace()

    // #FUNCTION: trace<..T_Args>(const std::string&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    template<class... T_Args> T_Logger& Logger<T_Logger, T_OutputStream>::trace(const std::string& p_message, T_Args&&... p_args){
        initiateLog(Log::Level::TRACE, p_message, std::forward<T_Args>(p_args)...);
        return static_cast<T_Logger&>(*this);
    } // #END: trace<..T_Args>(const std::string&)

    // #FUNCTION: trace(std::string&&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    T_Logger& Logger<T_Logger, T_OutputStream>::trace(std::string&& p_message){
        initiateLog(Log::Level::TRACE, std::move(p_message));
        return static_cast<T_Logger&>(*this);
    } // #END: trace(std::string&&)

    // #FUNCTION: debug(), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream> 
    T_Logger& Logger<T_Logger, T_OutputStream>::debug(){
        initiateLog(Log::Level::DEBUG);
        return static_cast<T_Logger&>(*this);
    } // #END: debug()

    // #FUNCTION: debug<..T_Args>(const std::string&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    template<class... T_Args> T_Logger& Logger<T_Logger, T_OutputStream>::debug(const std::string& p_message, T_Args&&... p_args){
        initiateLog(Log::Level::DEBUG, p_message, std::forward<T_Args>(p_args)...);
        return static_cast<T_Logger&>(*this);
    } // #END: debug<..T_Args>(const std::string&)

    // #FUNCTION: debug(std::string&&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    T_Logger& Logger<T_Logger, T_OutputStream>::debug(std::string&& p_message){
        initiateLog(Log::Level::DEBUG, std::move(p_message));
        return static_cast<T_Logger&>(*this);
    } // #END: debug(std::string&&)

    // #FUNCTION: message<...Args>(const std::string&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    template<class... Args>
    T_Logger& Logger<T_Logger, T_OutputStream>::message(const std::string& p_message, Args&&... p_args){
        if(m_bufferedLog){
            if(m_bufferedLog->message.empty()){ 
                if constexpr(sizeof...(p_args) == 0){ // No formatting arguments
                    m_bufferedLog->message = std::move(p_message);
                }else{
                    m_bufferedLog->message = std::vformat(p_message, std::make_format_args(std::forward<Args>(p_args)...));;
                }
            }else{ // Already has message content
                if constexpr(sizeof...(p_args) == 0){ // No formatting arguments
                    m_bufferedLog->message += std::move(p_message);
                }else{
                    m_bufferedLog->message += std::vformat(p_message, std::make_format_args(std::forward<Args>(p_args)...));;
                }
            }
        }
        return static_cast<T_Logger&>(*this);
    } // #END: message(const std::string& )

    // #FUNCTION: message(std::string&&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    T_Logger& Logger<T_Logger, T_OutputStream>::message(std::string&& p_message){
        if(m_bufferedLog){
            if(m_bufferedLog->message.empty()){ 
                m_bufferedLog->message = std::move(p_message);
            }else{ // Already has message content
                m_bufferedLog->message += std::move(p_message);
            }
        }
        return static_cast<T_Logger&>(*this);
    } // #END: message(std::string&&)

    // #FUNCTION: time(const TimePoint&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream> 
    T_Logger& Logger<T_Logger, T_OutputStream>::time(const std_TimePoint& p_time){
        if(m_bufferedLog){
            m_bufferedLog->time = p_time;
        }
        return static_cast<T_Logger&>(*this);
    } // #END: time(const TimePoint&)

    // #FUNCTION: time(const std::time_t), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream> 
    T_Logger& Logger<T_Logger, T_OutputStream>::time(const std::time_t p_time){
        if(m_bufferedLog){
            m_bufferedLog->time = std::chrono::system_clock::from_time_t(p_time);
        }
        return static_cast<T_Logger&>(*this);
    } // #END: time(const std::time_t)

    // #FUNCTION: location(const std::source_location&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream> 
    T_Logger& Logger<T_Logger, T_OutputStream>::location(const std::source_location& p_location){
        if(m_bufferedLog){
            m_bufferedLog->location = p_location;
        }
        return static_cast<T_Logger&>(*this);
    } // #END: location(const std::source_location&)

    // #FUNCTION: location(std::source_location&&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    T_Logger& Logger<T_Logger, T_OutputStream>::location(std::source_location&& p_location){
        if(m_bufferedLog){
            m_bufferedLog->location = std::move(p_location);
        }
        return static_cast<T_Logger&>(*this);
    } // #END: location(std::source_location&&)

    // #FUNCTION: send(), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    T_Logger& Logger<T_Logger, T_OutputStream>::send(){
        flushBuffer();
        return static_cast<T_Logger&>(*this);
    } // #END: send()

    // #FUNCTION: flush(), Method   
    template<class T_Logger, OutputStreamDerived T_OutputStream> 
    T_Logger& Logger<T_Logger, T_OutputStream>::flush(){
        flushBuffer();
        m_outputStream.flush();
        return static_cast<T_Logger&>(*this);
    } // #END: flush()

    // #FUNCTION: logFormat(const std::array<Format, FORMAT_COUNT>&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    T_Logger& Logger<T_Logger, T_OutputStream>::logFormat(const std::array<Log::Format, Log::NUM_FORMATS>& p_logFormat){
        m_logFormat = p_logFormat;
        return static_cast<T_Logger&>(*this);
    } // #END: logFormat(const std::array<Format, FORMAT_COUNT>&)

// #DIV: Protected Factory Methods

    // #FUNCTION: Logger(const std::string&), Constructor
    template<class T_Logger, OutputStreamDerived T_OutputStream> 
    Logger<T_Logger, T_OutputStream>::Logger(const std::string& p_name): m_name(p_name), m_outputStream(T_OutputStream::get()), m_logFormat(DEFAULT_LOG_FORMAT){
        
    } // #END: Logger(const std::string&)

    // #FUNCTION: Logger(const std::string&, const std::array<Format, FORMAT_COUNT>&), Constructor
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    Logger<T_Logger, T_OutputStream>::Logger(const std::string& p_name, const std::array<Log::Format, Log::NUM_FORMATS>& p_logFormat): m_name(p_name), m_outputStream(T_OutputStream::get()), m_logFormat(p_logFormat){
        
    } // #END: Logger(const std::string&, const std::array<Format, FORMAT_COUNT>&)

// #DIV: Protected Methods

    // #FUNCTION: initiateLog(Log::Level), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    void Logger<T_Logger, T_OutputStream>::initiateLog(Log::Level p_level){
        if(m_bufferedLog){
            flushBuffer();
        }
        m_bufferedLog = Log(p_level);
    } // #END: initiateLog(Log::Level)

    // #FUNCTION: initiateLog<...T_Args>(Log::Level, const std::string&, Args&&...), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    template<class... T_Args> void Logger<T_Logger, T_OutputStream>::initiateLog(Log::Level p_level, const std::string& p_message, T_Args&&... p_args){
        initiateLog(p_level);
        if constexpr(sizeof...(p_args) == 0){ // No formatting arguments
            m_bufferedLog->message = p_message;
        }else{
            m_bufferedLog->message = std::vformat(p_message, std::make_format_args(std::forward<T_Args>(p_args)...));
        }
    } // #END: initiateLog<...T_Args>(Log::Level, const std::string&, Args&&...)

    // #FUNCTION: initiateLog(Log::Level, std::string&&, Args&&...), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    void Logger<T_Logger, T_OutputStream>::initiateLog(Log::Level p_level, std::string&& p_message){
        initiateLog(p_level);
        m_bufferedLog->message = std::move(p_message);
    } // #END: initiateLog(Log::Level, std::string&&, Args&&...)

    // #FUNCTION: flushBuffer(), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>    
    void Logger<T_Logger, T_OutputStream>::flushBuffer(){
        if(m_bufferedLog){
            m_outputStream << formatLog(*m_bufferedLog);
            m_bufferedLog.reset();
        }
    } // #END: flushBuffer()
    
    // #FUNCTION: formatLog(const Log&), Static Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    std::string Logger<T_Logger, T_OutputStream>::formatLog(const Log& p_log){
        std::string formattedLog;
        for(Log::Format format: m_logFormat){
            if(std::string formattedPart = formatPart(format, p_log); !formattedPart.empty()){
                formattedLog += formattedLog.empty()? formattedPart: Log::FORMAT_SEPARATOR + formattedPart;
            }
        }
        return formattedLog;
    } // #END: formatLog(const Log&)

    // #FUNCTION: formatPart(const Log::Format, const Log&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    std::string Logger<T_Logger, T_OutputStream>::formatPart(const Log::Format p_format, const Log& p_log){
        switch(p_format){
            case Log::Format::TIME: {
                if(p_log.time) return formatTime(*p_log.time);
                else return "";
            }
            case Log::Format::LEVEL: return formatLevel(p_log.level);
            case Log::Format::NAME: return formatName(m_name);
            case Log::Format::MESSAGE: return formatMessage(p_log.message);
            case Log::Format::LOCATION: {
                if(p_log.location) return formatLocation(*p_log.location);
                else return "";
            }
            default: return "";
        }
    } // #END: formatPart(const Log::Format, const Log&)

    // #FUNCTION: formatName(const std::string&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    std::string Logger<T_Logger, T_OutputStream>::formatName(const std::string& p_name){
        return std::vformat(Log::NAME_FORMAT, std::make_format_args(p_name));
    } // #END: formatName(const std::string&)

    // #FUNCTION: formatMessage(const std::string&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    std::string Logger<T_Logger, T_OutputStream>::formatMessage(const std::string& p_message){
        return p_message;
    } // #END: formatMessage(const std::string&)

    // #FUNCTION: formatLevel(const Log::Level), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    std::string Logger<T_Logger, T_OutputStream>::formatLevel(const Log::Level p_level){
        return std::vformat(Log::LEVEL_FORMAT, std::make_format_args(Log::LEVEL_STRINGS.at(p_level)));
    } // #END: formatLevel(const Log::Level)

    // #FUNCTION: formatTime(const std_TimePoint&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    std::string Logger<T_Logger, T_OutputStream>::formatTime(const std_TimePoint& p_time){
        const std::uint8_t hours = std::chrono::duration_cast<std::chrono::hours>(p_time.time_since_epoch()).count() % 24;
        const std::uint8_t minutes = std::chrono::duration_cast<std::chrono::minutes>(p_time.time_since_epoch()).count() % 60;
        const std::uint8_t seconds = std::chrono::duration_cast<std::chrono::seconds>(p_time.time_since_epoch()).count() % 60;
        return std::vformat(Log::TIME_FORMAT, std::make_format_args(hours, minutes, seconds));
    } // #END: formatTime(const std_TimePoint&)

    // #FUNCTION: formatLocation(const std::source_location&), Method
    template<class T_Logger, OutputStreamDerived T_OutputStream>
    std::string Logger<T_Logger, T_OutputStream>::formatLocation(const std::source_location& p_location){
        const char* function = p_location.function_name();
        const std::uint32_t line = p_location.line();
        const char* file = p_location.file_name();
        return std::vformat(Log::LOCATION_FORMAT, std::make_format_args(function, line, file));
    } // #END: formatLocation(const std::source_location&)

} // #END: pureLog::logger


// [Docme] Error: Problems processing - docme::Engine::parse(), line: 234 parser.cpp