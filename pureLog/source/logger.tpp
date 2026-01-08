// #FILE: logger.tpp, Module Template Implementation File

#pragma once

#include "colors.hpp"
#include "logger.hpp" // #INCLUDE: logger.hpp, Module Header File
#include <format>
#include <string>

namespace pureLog::logger{ // #scope: pureLog::logger

// #SCOPE: Logger<T_Derived>

// #DIV: Public Factory Methods

    // #FUNCTION: ~Logger(), Virtual Destructor
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    Logger<T_Derived, t_usingLevelFormats, t_usingColors>::~Logger(){
        flushBuffer();
    } // #END: ~Logger()

// #DIV: Public Static Methods

    // #FUNCTION: get(), Static Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors> 
    [[nodiscard]] T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::get(){
        static_assert(LoggerDerived<T_Derived>, "Custom logger type must derive from pureLog::Logger.");
        static T_Derived instance = T_Derived();
        return instance;
    } // #END: get()    

// #DIV: Public Methods

    // #FUNCTION: log(), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::log(){
        initiateLog(Log::Level::NONE);
        return static_cast<T_Derived&>(*this);
    } // #END: log()

    // #FUNCTION: log<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::log(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::NONE, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: log<..T_Args>(const std::string&)

    // #FUNCTION: log(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::log(std::string&& p_message){
        initiateLog(Log::Level::NONE, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: log(std::string&&)

    // #FUNCTION: info(), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::info(){
        initiateLog(Log::Level::INFO);
        return static_cast<T_Derived&>(*this);
    } // #END: info()

    // #FUNCTION: info<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::info(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::INFO, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: info<..T_Args>(const std::string&)

    // #FUNCTION: info(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::info(std::string&& p_message){
        initiateLog(Log::Level::INFO, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: info(std::string&&)

    // #FUNCTION: warn(), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::warn(){
        initiateLog(Log::Level::WARN);
        return static_cast<T_Derived&>(*this);
    } // #END: warn()

    // #FUNCTION: warn<..T_Args>(const std::string&), Method
    // #FUNCTION: warn<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::warn(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::WARN, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: warn<..T_Args>(const std::string&)
    
    // FUNCTION: warn(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::warn(std::string&& p_message){
        initiateLog(Log::Level::WARN, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: warn(std::string&&)

    // #FUNCTION: error(), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::error(){
        initiateLog(Log::Level::ERROR);
        return static_cast<T_Derived&>(*this);
    } // #END: error()

    // #FUNCTION: error<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::error(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::ERROR, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: error<..T_Args>(const std::string&)

    // FUNCTION: error(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::error(std::string&& p_message){
        initiateLog(Log::Level::ERROR, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: error(std::string&&)

    // #FUNCTION: critical(), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::critical(){
        initiateLog(Log::Level::CRITICAL);
        return static_cast<T_Derived&>(*this);
    } // #END: critical()

    // #FUNCTION: critical<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::critical(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::CRITICAL, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: critical<..T_Args>(const std::string&)

    // #FUNCTION: critical(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::critical(std::string&& p_message){
        initiateLog(Log::Level::CRITICAL, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: critical(std::string&&)

    // #FUNCTION: fatal(), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::fatal(){
        initiateLog(Log::Level::FATAL);
        return static_cast<T_Derived&>(*this);
    } // #END: fatal()

    // #FUNCTION: fatal<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::fatal(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::FATAL, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: fatal<..T_Args>(const std::string&)

    // #FUNCTION: fatal(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::fatal(std::string&& p_message){
        initiateLog(Log::Level::FATAL, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: fatal(std::string&&)

    // #FUNCTION: trace(), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::trace(){
        initiateLog(Log::Level::TRACE);
        return static_cast<T_Derived&>(*this);
    } // #END: trace()

    // #FUNCTION: trace<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::trace(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::TRACE, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: trace<..T_Args>(const std::string&)

    // #FUNCTION: trace(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::trace(std::string&& p_message){
        initiateLog(Log::Level::TRACE, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: trace(std::string&&)

    // #FUNCTION: debug(), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::debug(){
        initiateLog(Log::Level::DEBUG);
        return static_cast<T_Derived&>(*this);
    } // #END: debug()

    // #FUNCTION: debug<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::debug(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::DEBUG, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: debug<..T_Args>(const std::string&)

    // #FUNCTION: debug(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::debug(std::string&& p_message){
        initiateLog(Log::Level::DEBUG, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: debug(std::string&&)

    // #FUNCTION: message<...Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    template<class... Args>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::message(const std::string& p_message, Args... p_args){
        if(m_bufferedLog){
            if(m_bufferedLog->message.empty()){ 
                if constexpr(sizeof...(p_args) == 0){ // No formatting arguments
                    m_bufferedLog->message = std::move(p_message);
                }else{
                    m_bufferedLog->message = std::vformat(p_message, std::make_format_args(p_args...));;
                }
            }else{ // Already has message content
                if constexpr(sizeof...(p_args) == 0){ // No formatting arguments
                    m_bufferedLog->message += std::move(p_message);
                }else{
                    m_bufferedLog->message += std::vformat(p_message, std::make_format_args(p_args...));;
                }
            }
        }
        return static_cast<T_Derived&>(*this);
    } // #END: message(const std::string& )
    
    // #FUNCTION: message(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::message(std::string&& p_message){
        if(m_bufferedLog){
            if(m_bufferedLog->message.empty()){ 
                m_bufferedLog->message = std::move(p_message);
            }else{ // Already has message content
                m_bufferedLog->message += std::move(p_message);
            }
        }
        return static_cast<T_Derived&>(*this);
    } // #END: message(std::string&&)

    // #FUNCTION: time(const TimePoint&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::time(const std_TimePoint& p_time){
        if(m_bufferedLog){
            m_bufferedLog->time = p_time;
        }
        return static_cast<T_Derived&>(*this);
    } // #END: time(const TimePoint&)

    // #FUNCTION: time(const std::time_t), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::time(const std::time_t p_time){
        if(m_bufferedLog){
            m_bufferedLog->time = std::chrono::system_clock::from_time_t(p_time);
        }
        return static_cast<T_Derived&>(*this);
    } // #END: time(const std::time_t)

    // #FUNCTION: location(const std::source_location&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::location(const std::source_location& p_location){
        if(m_bufferedLog){
            m_bufferedLog->location = p_location;
        }
        return static_cast<T_Derived&>(*this);
    } // #END: location(const std::source_location&)

    // #FUNCTION: location(std::source_location&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::location(std::source_location&& p_location){
        if(m_bufferedLog){
            m_bufferedLog->location = std::move(p_location);
        }
        return static_cast<T_Derived&>(*this);
    } // #END: location(std::source_location&&)

    // #FUNCTION: send(), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::send(){
        flushBuffer();
        return static_cast<T_Derived&>(*this);
    } // #END: send()

    // #FUNCTION: flush(), Method   
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::flush(){
        flushBuffer();
        m_outputStream.flush();
        return static_cast<T_Derived&>(*this);
    } // #END: flush()

    // #FUNCTION: format(const Format&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::format(const Format& p_format){
        m_format = p_format;
        return static_cast<T_Derived&>(*this);
    } // #END: format(const Format&)

    // #FUNCTION: format(Format&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::format(Format&& p_format){
        m_format = std::move(p_format);
        return static_cast<T_Derived&>(*this);
    } // #END: format(Format&&)

    // #FUNCTION: formatName(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatName(const std::string& p_name){
        m_format.name = p_name;
        return static_cast<T_Derived&>(*this);
    } // #END: formatName(const std::string&)

    // #FUNCTION: formatName(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatName(std::string&& p_name){
        m_format.name = std::move(p_name);
        return static_cast<T_Derived&>(*this);
    } // #END: formatName(std::string&&)

    // #FUNCTION: formatLevel(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatLevel(const std::string& p_level){
        m_format.level = p_level;
        return static_cast<T_Derived&>(*this);
    } // #END: formatLevel(const std::string&)

    // #FUNCTION: formatLevel(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatLevel(std::string&& p_level){
        m_format.level = std::move(p_level);
        return static_cast<T_Derived&>(*this);
    } // #END: formatLevel(std::string&&)

    // #FUNCTION: formatMessage(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatMessage(const std::string& p_message){
        m_format.message = p_message;
        return static_cast<T_Derived&>(*this);
    } // #END: formatMessage(const std::string&)

    // #FUNCTION: formatMessage(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatMessage(std::string&& p_message){
        m_format.message =  std::move(p_message);
        return static_cast<T_Derived&>(*this);
    } // #END: formatMessage(std::string&&)

    // #FUNCTION: formatTime(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatTime(const std::string& p_time){
        m_format.time = p_time;
        return static_cast<T_Derived&>(*this);
    } // #END: formatTime(const std::string&)

    // #FUNCTION: formatTime(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatTime(std::string&& p_time){
        m_format.time = std::move(p_time);
        return static_cast<T_Derived&>(*this);
    } // #END: formatTime(std::string&&)

    // #FUNCTION: formatLocation(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatLocation(const std::string& p_location){
        m_format.location = p_location;
        return static_cast<T_Derived&>(*this);
    } // #END: formatLocation(const std::string&)

    // #FUNCTION: formatLocation(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatLocation(std::string&& p_location){
        m_format.location = std::move(p_location);
        return static_cast<T_Derived&>(*this);
    } // #END: formatLocation(std::string&&)

    // #FUNCTION: formatOrder(const std::array<Format::Type, Format::COUNT>&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatOrder(const std::array<Format::Type, Format::COUNT>& p_order){
        m_format.order = p_order;
        return static_cast<T_Derived&>(*this);
    } // #END: formatOrder(const std::array<Format::Type, Format::COUNT>&)

    // #FUNCTION: formatOrder(const std::initializer_list<Format::Type>), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatOrder(const std::initializer_list<Format::Type> p_order){
        std::copy(p_order.begin(), p_order.end(), m_format.order.begin());
        return static_cast<T_Derived&>(*this);
    } // #END: formatOrder(const std::initializer_list<Format::Type>)

    // #FUNCTION: addLevelFormat(const std::variant<Log::Level, std::string>&, const Format&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::addLevelFormat(const std::variant<Log::Level, std::string>& p_level, const Format& p_format){
        static_assert(t_usingLevelFormats, "Cannot set level specific format when level formats are disabled.");
        m_levelFormats[p_level] = p_format;
        return static_cast<T_Derived&>(*this);
    } // #END: addLevelFormat(const std::variant<Log::Level, std::string>&)

    // #FUNCTION: addLevelFormat(const std::variant<Log::Level, std::string>&, Format&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::addLevelFormat(const std::variant<Log::Level, std::string>& p_level, Format&& p_format){
        static_assert(t_usingLevelFormats, "Cannot set level specific format when level formats are disabled.");
        m_levelFormats[p_level] = std::move(p_format);
        return static_cast<T_Derived&>(*this);
    } // #END: addLevelFormat(const std::variant<Log::Level, std::string>&, Format&&)

    // #FUNCTION: addLevelFormatName(const std::variant<Log::Level, std::string>&, const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::addLevelFormatName(const std::variant<Log::Level, std::string>& p_level, const std::string& p_name){
        static_assert(t_usingLevelFormats, "Cannot set level specific format name when level formats are disabled.");
        m_levelFormats[p_level].name = p_name;
        return static_cast<T_Derived&>(*this);
    } // #END: addLevelFormatName(const std::variant<Log::Level, std::string>&, const std::string&)

    // #FUNCTION: addLevelFormatName(const std::variant<Log::Level, std::string>&, std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::addLevelFormatName(const std::variant<Log::Level, std::string>& p_level, std::string&& p_name){
        static_assert(t_usingLevelFormats, "Cannot set level specific format name when level formats are disabled.");
        m_levelFormats[p_level].name = std::move(p_name);
        return static_cast<T_Derived&>(*this);
    } // #END: addLevelFormatName(const std::variant<Log::Level, std::string>&, std::string&&)

    // #FUNCTION: addLevelFormatLevel(const std::variant<Log::Level, std::string>&, const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::addLevelFormatLevel(const std::variant<Log::Level, std::string>& p_level, const std::string& p_levelFormat){
        static_assert(t_usingLevelFormats, "Cannot set level specific format level when level formats are disabled.");
        m_levelFormats[p_level].level = p_levelFormat;
        return static_cast<T_Derived&>(*this);
    } // #END: addLevelFormatLevel(const std::variant<Log::Level, std::string>&, const std::string&)

    // #FUNCTION: addLevelFormatLevel(const std::variant<Log::Level, std::string>&, std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::addLevelFormatLevel(const std::variant<Log::Level, std::string>& p_level, std::string&& p_levelFormat){
        static_assert(t_usingLevelFormats, "Cannot set level specific format level when level formats are disabled.");
        m_levelFormats[p_level].level = std::move(p_levelFormat);
        return static_cast<T_Derived&>(*this);
    } // #END: addLevelFormatLevel(const std::variant<Log::Level, std::string>&, std::string&&)

    // #FUNCTION: addLevelFormatMessage(const std::variant<Log::Level, std::string>&, const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::addLevelFormatMessage(const std::variant<Log::Level, std::string>& p_level, const std::string& p_message){
        static_assert(t_usingLevelFormats, "Cannot set level specific format message when level formats are disabled.");
        m_levelFormats[p_level].message = p_message;
        return static_cast<T_Derived&>(*this);
    } // #END: addLevelFormatMessage(const std::variant<Log::Level, std::string>&, const std::string&)

    // #FUNCTION: addLevelFormatMessage(const std::variant<Log::Level, std::string>&, std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::addLevelFormatMessage(const std::variant<Log::Level, std::string>& p_level, std::string&& p_message){
        static_assert(t_usingLevelFormats, "Cannot set level specific format message when level formats are disabled.");
        m_levelFormats[p_level].message = std::move(p_message);
        return static_cast<T_Derived&>(*this);
    } // #END: addLevelFormatMessage(const std::variant<Log::Level, std::string>&, std::string&&)

    // #FUNCTION: addLevelFormatTime(const std::variant<Log::Level, std::string>&, const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::addLevelFormatTime(const std::variant<Log::Level, std::string>& p_level, const std::string& p_time){
        static_assert(t_usingLevelFormats, "Cannot set level specific format time when level formats are disabled.");
        m_levelFormats[p_level].time = p_time;
        return static_cast<T_Derived&>(*this);
    } // #END: addLevelFormatTime(const std::variant<Log::Level, std::string>&, const std::string&)

    // #FUNCTION: addLevelFormatTime(const std::variant<Log::Level, std::string>&, std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::addLevelFormatTime(const std::variant<Log::Level, std::string>& p_level, std::string&& p_time){
        static_assert(t_usingLevelFormats, "Cannot set level specific format time when level formats are disabled.");
        m_levelFormats[p_level].time = std::move(p_time);
        return static_cast<T_Derived&>(*this);
    } // #END: addLevelFormatTime(const std::variant<Log::Level, std::string>&, std::string&&)

    // #FUNCTION: addLevelFormatLocation(const std::variant<Log::Level, std::string>&, const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::addLevelFormatLocation(const std::variant<Log::Level, std::string>& p_level, const std::string& p_location){
        static_assert(t_usingLevelFormats, "Cannot set level specific format location when level formats are disabled.");
        m_levelFormats[p_level].location = p_location;
        return static_cast<T_Derived&>(*this);
    } // #END: addLevelFormatLocation(const std::variant<Log::Level, std::string>&, const std::string&)

    // #FUNCTION: addLevelFormatLocation(const std::variant<Log::Level, std::string>&, std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::addLevelFormatLocation(const std::variant<Log::Level, std::string>& p_level, std::string&& p_location){
        static_assert(t_usingLevelFormats, "Cannot set level specific format location when level formats are disabled.");
        m_levelFormats[p_level].location = std::move(p_location);
        return static_cast<T_Derived&>(*this);
    } // #END: addLevelFormatLocation(const std::variant<Log::Level, std::string>&, std::string&&)

    // #FUNCTION: addLevelFormatOrder(const std::variant<Log::Level, std::string>&, const std::array<Format::Type, Format::COUNT>&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::addLevelFormatOrder(const std::variant<Log::Level, std::string>& p_level, const std::array<Format::Type, Format::COUNT>& p_order){
        static_assert(t_usingLevelFormats, "Cannot set level specific format order when level formats are disabled.");
        m_levelFormats[p_level].order = p_order;
        return static_cast<T_Derived&>(*this);
    } // #END: addLevelFormatOrder(const std::variant<Log::Level, std::string>&, const std::array<Format::Type, Format::COUNT>&)
    
    // #FUNCTION: addLevelFormatOrder(const std::variant<Log::Level, std::string>&, const std::initializer_list<Format::Type>), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::addLevelFormatOrder(const std::variant<Log::Level, std::string>& p_level, const std::initializer_list<Format::Type> p_order){
        static_assert(t_usingLevelFormats, "Cannot set level specific format order when level formats are disabled.");
        std::copy(p_order.begin(), p_order.end(), m_levelFormats[p_level].order.begin());
        return static_cast<T_Derived&>(*this);
    } // #END: addLevelFormatOrder(const std::variant<Log::Level, std::string>&, const std::initializer_list<Format::Type>)


    // !
    
    // // #FUNCTION: formatColor(const Format::TextColor&), Method
    // template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    // T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatColor(const Format::TextColor& p_color){
    //     m_format.color = p_color;
    //     return static_cast<T_Derived&>(*this);
    // } // #END: formatColor(const Format::TextColor&)

    // // #FUNCTION: formatColor(Format::TextColor&&), Method
    // template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    // T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatColor(Format::TextColor&& p_color){
    //     m_format.color = std::move(p_color);
    //     return static_cast<T_Derived&>(*this);
    // } // #END: formatColor(Format::TextColor&&)

    // // #FUNCTION: formatLogColor(const Color), Method
    // template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    // T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatLogColor(const Color p_color){
    //     m_format.color.log = p_color;
    //     return static_cast<T_Derived&>(*this);
    // } // #END: formatLogColor(const Color)

    // // #FUNCTION: formatNameColor(const Color), Method
    // template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    // T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatNameColor(const Color p_color){
    //     m_format.color.name = p_color;
    //     return static_cast<T_Derived&>(*this);
    // } // #END: formatNameColor(const Color)

    // // #FUNCTION: formatLevelColor(const Color), Method
    // template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    // T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatLevelColor(const Color p_color){
    //     m_format.color.level = p_color;
    //     return static_cast<T_Derived&>(*this);
    // } // #END: formatLevelColor(const Color)

    // // #FUNCTION: formatMessageColor(const Color), Method
    // template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    // T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatMessageColor(const Color p_color){
    //     m_format.color.message = p_color;
    //     return static_cast<T_Derived&>(*this);
    // } // #END: formatMessageColor(const Color)

    // // #FUNCTION: formatTimeColor(const Color), Method
    // template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    // T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatTimeColor(const Color p_color){
    //     m_format.color.time = p_color;
    //     return static_cast<T_Derived&>(*this);
    // } // #END: formatTimeColor(const Color)

    // // #FUNCTION: formatLocationColor(const Color), Method
    // template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    // T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::formatLocationColor(const Color p_color){
    //     m_format.color.location = p_color;
    //     return static_cast<T_Derived&>(*this);
    // } // #END: formatLocationColor(const Color)

    // // #FUNCTION: name(const std::string&), Method

    //!

    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::name(const std::string& p_name){
        m_name = p_name;
        return static_cast<T_Derived&>(*this);
    } // #END: name(const std::string&)

    // #FUNCTION: name(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::name(std::string&& p_name){
        m_name = std::move(p_name);
        return static_cast<T_Derived&>(*this);
    } // #END: name(std::string&&)

    // #FUNCTION: format(), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    [[nodiscard]] const Format& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::format()const{
        return m_format;
    } // #END: format()

    // #FUNCTION: levelFormats(), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    [[nodiscard]] const std::unordered_map<std::variant<Log::Level, std::string>, Format>& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::levelFormats()const{
        static_assert(t_usingLevelFormats, "Cannot get level specific formats when level formats are disabled.");
        return m_levelFormats;
    } // #END: levelFormats()

    // #FUNCTION: name(), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    [[nodiscard]] const std::string& Logger<T_Derived, t_usingLevelFormats, t_usingColors>::name()const{
        return m_name;
    } // #END: name()

// #DIV: Protected Factory Methods

    // #FUNCTION: Logger<T_Name, T_Format>(const std::string&, OutputStream&), Constructor
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    Logger<T_Derived, t_usingLevelFormats, t_usingColors>::Logger(const std::string& p_name, OutputStream& p_outputStream): m_name(p_name), m_outputStream(p_outputStream){

    } // #END: Logger<T_Name, T_Format>(const std::string&, OutputStream&)

    // #FUNCTION: Logger<T_Name, T_Format>(std::string&&, OutputStream&), Constructor
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    Logger<T_Derived, t_usingLevelFormats, t_usingColors>::Logger(std::string&& p_name, OutputStream& p_outputStream): m_name(std::move(p_name)), m_outputStream(p_outputStream){

    } // #END: Logger<T_Name, T_Format>(std::string&&, OutputStream&)

// #DIV: Protected Methods

    // #FUNCTION: initiateLog(Log::Level), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    void Logger<T_Derived, t_usingLevelFormats, t_usingColors>::initiateLog(const std::variant<Log::Level, std::string> p_level){
        if(m_bufferedLog){
            flushBuffer();
        }
        m_bufferedLog = Log(std::move(p_level));
    } // #END: initiateLog(Log::Level)

    // #FUNCTION: initiateLog<...T_Args>(Log::Level, const std::string&, Args&&...), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    template<class... T_Args> void Logger<T_Derived, t_usingLevelFormats, t_usingColors>::initiateLog(const std::variant<Log::Level, std::string> p_level, const std::string& p_message, T_Args... p_args){
        initiateLog(std::move(p_level));
        if constexpr(sizeof...(p_args) == 0){ // No formatting arguments
            m_bufferedLog->message = p_message;
        }else{
            m_bufferedLog->message = std::vformat(p_message, std::make_format_args(p_args...));
        }
    } // #END: initiateLog<...T_Args>(Log::Level, const std::string&, Args&&...)

    // #FUNCTION: initiateLog(Log::Level, std::string&&, Args&&...), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    void Logger<T_Derived, t_usingLevelFormats, t_usingColors>::initiateLog(const std::variant<Log::Level, std::string> p_level, std::string&& p_message){
        initiateLog(std::move(p_level));
        m_bufferedLog->message = std::move(p_message);
    } // #END: initiateLog(Log::Level, std::string&&, Args&&...)

    // #FUNCTION: flushBuffer(), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>    
    void Logger<T_Derived, t_usingLevelFormats, t_usingColors>::flushBuffer(){
        if(m_bufferedLog){
            if constexpr(t_usingColors){ // Add colors
                m_outputStream << getColoredLog(m_bufferedLog->level, getFormattedLog(*m_bufferedLog)); 
            }else{
                m_outputStream << getFormattedLog(*m_bufferedLog);
            }
            m_bufferedLog.reset();
        }
    } // #END: flushBuffer()
    
    // #FUNCTION: getFormattedLog(const Log&), Static Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormats, t_usingColors>::getFormattedLog(const Log& p_log){
        std::string formattedLog;
        // Format log parts
        for(Format::Type format: m_format.order){
            if(std::string formattedPart = getFormattedPart(format, p_log); !formattedPart.empty()){
                if(!formattedLog.empty()){ // Not first part
                    formattedLog += Format::SEPARATOR;
                }
                if constexpr(t_usingColors){ // Add colors
                    formattedLog += getColoredPart(format, std::move(formattedPart));
                }
            }
        }
        return formattedLog + Format::LOG_END;
    } // #END: getFormattedLog(const Log&)

    // #FUNCTION: getFormattedPart(const Log::Format, const Log&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormats, t_usingColors>::getFormattedPart(const Format::Type p_format, const Log& p_log){
        switch(p_format){
            case Format::Type::TIME: return (p_log.time)? getFormattedTime(p_log.level, *p_log.time): "";
            case Format::Type::LEVEL: return getFormattedLevel(p_log.level);
            case Format::Type::NAME: return getFormattedName(p_log.level, m_name);
            case Format::Type::MESSAGE: return getFormattedMessage(p_log.level, p_log.message);
            case Format::Type::LOCATION: return (p_log.location)? getFormattedLocation(p_log.level, *p_log.location): "";
            default: return "";
        }
    } // #END: getFormattedPart(const Log::Format, const Log&)

    // #FUNCTION: getFormattedName(const std::variant<Log::Level, std::string>&, const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormats, t_usingColors>::getFormattedName(const std::variant<Log::Level, std::string>& p_level, const std::string& p_name){
        if constexpr(t_usingLevelFormats){ // Check for specific format
            if(auto node = m_levelFormats.find(p_level); node != m_levelFormats.end()) [[unlikely]] { // Specific format for this level
                const Format& levelFormat = node->second;
                return std::vformat(levelFormat.name, std::make_format_args(p_name));
            }
        }
        return std::vformat(m_format.name, std::make_format_args(p_name));
    } // #END: getFormattedName(const std::variant<Log::Level, std::string>&, const std::string&)

    // #FUNCTION: getFormattedMessage(const std::variant<Log::Level, std::string>&, const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormats, t_usingColors>::getFormattedMessage(const std::variant<Log::Level, std::string>& p_level, const std::string& p_message){
        if constexpr(t_usingLevelFormats){ // Check for specific format
            if(auto node = m_levelFormats.find(p_level); node != m_levelFormats.end()) [[unlikely]] { // Specific format for this level
                const Format& levelFormat = node->second;
                return std::vformat(levelFormat.message, std::make_format_args(p_message));
            }
        }
        return std::vformat(m_format.message, std::make_format_args(p_message));
    } // #END: getFormattedMessage(const std::variant<Log::Level, std::string>&, const std::string&)

    // #FUNCTION: getFormattedLevel(const std::variant<Log::Level, std::string>&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormats, t_usingColors>::getFormattedLevel(const std::variant<Log::Level, std::string>& p_level){
        if(std::holds_alternative<std::string>(p_level)) [[unlikely]] { // Custom level string
            if constexpr(t_usingLevelFormats){ // Check for specific format
                if(auto node = m_levelFormats.find(p_level); node != m_levelFormats.end()) [[unlikely]] { // Specific format for this level
                    const Format& levelFormat = node->second;
                    return std::vformat(levelFormat.level, std::make_format_args(std::get<std::string>(p_level)));
                }
            }
            return std::vformat(m_format.level, std::make_format_args(std::get<std::string>(p_level)));
        }
        if(std::get<Log::Level>(p_level) == Log::Level::NONE){ // No level to display
            return "";
        }
        if constexpr(t_usingLevelFormats){ // Check for specific format
            if(auto node = m_levelFormats.find(p_level); node != m_levelFormats.end()) [[unlikely]] { // Specific format for this level
                const Format& levelFormat = node->second;
                return std::vformat(levelFormat.level, std::make_format_args(Log::LEVEL_STRINGS.at(std::get<Log::Level>(p_level))));
            }
        }
        return std::vformat(m_format.level, std::make_format_args(Log::LEVEL_STRINGS.at(std::get<Log::Level>(p_level))));
    } // #END: getFormattedLevel(const std::variant<Log::Level, std::string>&)

    // #FUNCTION: getFormattedTime(const std::variant<Log::Level, std::string>&, const std_TimePoint&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormats, t_usingColors>::getFormattedTime(const std::variant<Log::Level, std::string>& p_level, const std_TimePoint& p_time){
        // Convert time
        const std::uint8_t hours = std::chrono::duration_cast<std::chrono::hours>(p_time.time_since_epoch()).count() % 24;
        const std::uint8_t minutes = std::chrono::duration_cast<std::chrono::minutes>(p_time.time_since_epoch()).count() % 60;
        const std::uint8_t seconds = std::chrono::duration_cast<std::chrono::seconds>(p_time.time_since_epoch()).count() % 60;
        const std::uint16_t milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(p_time.time_since_epoch()).count() % 1000;
        if constexpr(t_usingLevelFormats){ // Check for specific format
            if(auto node = m_levelFormats.find(p_level); node != m_levelFormats.end()) [[unlikely]] { // Specific format for this level
                const Format& levelFormat = node->second;
                return std::vformat(levelFormat.time, std::make_format_args(hours, minutes, seconds, milliseconds));
            }
        }
        return std::vformat(m_format.time, std::make_format_args(hours, minutes, seconds, milliseconds));
    } // #END: getFormattedTime(const std::variant<Log::Level, std::string>&, const std_TimePoint&)

    // #FUNCTION: getFormattedLocation(const std::variant<Log::Level, std::string>&, const std::source_location&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormats, t_usingColors>::getFormattedLocation(const std::variant<Log::Level, std::string>& p_level, const std::source_location& p_location){
        // Get location components
        const std::string function = p_location.function_name();
        const std::uint32_t line = p_location.line();
        const std::string file = p_location.file_name();
        if constexpr(t_usingLevelFormats){ // Check for specific format
            if(auto node = m_levelFormats.find(p_level); node != m_levelFormats.end()) [[unlikely]] { // Specific format for this level
                const Format& levelFormat = node->second;
                return std::vformat(levelFormat.location, std::make_format_args(function, line, file));
            }
        }
        return std::vformat(m_format.location, std::make_format_args(function, line, file));
    } // #END: getFormattedLocation(const std::variant<Log::Level, std::string>&, const std::source_location&)

    // #FUNCTION: getColoredPart(const Log::Format, std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormats, t_usingColors>::getColoredPart(const Format::Type p_format, std::string&& p_part){
        return std::move(p_part);
    } // #END: getColoredPart(const Log::Format, std::string&&)

    // #FUNCTION: getColoredLog(const std::variant<Log::Level, std::string>&, std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormats, t_usingColors>::getColoredLog(const std::variant<Log::Level, std::string>& p_level, std::string&& p_log){
        return std::move(p_log);
    } // #END: getColoredLog(const std::variant<Log::Level, std::string>&, std::string&&)
// #END: Logger<T_Derived>

} // #END: pureLog::logger