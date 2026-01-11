// #FILE: logger.tpp, Module Template Implementation File

#pragma once

#include "colors.hpp"
#include "logger.hpp" // #INCLUDE: logger.hpp, Module Header File
#include <unordered_map>

namespace pureLog::logger{ // #scope: pureLog::logger

// #SCOPE: Logger<T_Derived>

// #DIV: Public Factory Methods

    // #FUNCTION: ~Logger(), Virtual Destructor
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::~Logger(){
        flushBuffer();
    } // #END: ~Logger()

// #DIV: Public Static Methods

    // #FUNCTION: get(), Static Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors> 
    [[nodiscard]] T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::get(){
        static_assert(LoggerDerived<T_Derived, t_usingLevelFormatting, t_usingColors>, "Custom logger type must derive from pureLog::Logger.");
        static T_Derived instance = T_Derived();
        return instance;
    } // #END: get()    

// #DIV: Public Methods

    // #FUNCTION: log(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::log(){
        initiateLog(Log::Level::NONE);
        return static_cast<T_Derived&>(*this);
    } // #END: log()

    // #FUNCTION: log<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::log(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::NONE, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: log<..T_Args>(const std::string&)

    // #FUNCTION: log(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::log(std::string&& p_message){
        initiateLog(Log::Level::NONE, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: log(std::string&&)

    // #FUNCTION: info(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::info(){
        initiateLog(Log::Level::INFO);
        return static_cast<T_Derived&>(*this);
    } // #END: info()

    // #FUNCTION: info<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::info(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::INFO, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: info<..T_Args>(const std::string&)

    // #FUNCTION: info(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::info(std::string&& p_message){
        initiateLog(Log::Level::INFO, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: info(std::string&&)

    // #FUNCTION: warn(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::warn(){
        initiateLog(Log::Level::WARN);
        return static_cast<T_Derived&>(*this);
    } // #END: warn()

    // #FUNCTION: warn<..T_Args>(const std::string&), Method
    // #FUNCTION: warn<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::warn(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::WARN, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: warn<..T_Args>(const std::string&)
    
    // FUNCTION: warn(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::warn(std::string&& p_message){
        initiateLog(Log::Level::WARN, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: warn(std::string&&)

    // #FUNCTION: error(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::error(){
        initiateLog(Log::Level::ERROR);
        return static_cast<T_Derived&>(*this);
    } // #END: error()

    // #FUNCTION: error<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::error(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::ERROR, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: error<..T_Args>(const std::string&)

    // FUNCTION: error(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::error(std::string&& p_message){
        initiateLog(Log::Level::ERROR, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: error(std::string&&)

    // #FUNCTION: critical(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::critical(){
        initiateLog(Log::Level::CRITICAL);
        return static_cast<T_Derived&>(*this);
    } // #END: critical()

    // #FUNCTION: critical<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::critical(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::CRITICAL, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: critical<..T_Args>(const std::string&)

    // #FUNCTION: critical(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::critical(std::string&& p_message){
        initiateLog(Log::Level::CRITICAL, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: critical(std::string&&)

    // #FUNCTION: fatal(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::fatal(){
        initiateLog(Log::Level::FATAL);
        return static_cast<T_Derived&>(*this);
    } // #END: fatal()

    // #FUNCTION: fatal<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::fatal(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::FATAL, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: fatal<..T_Args>(const std::string&)

    // #FUNCTION: fatal(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::fatal(std::string&& p_message){
        initiateLog(Log::Level::FATAL, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: fatal(std::string&&)

    // #FUNCTION: trace(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::trace(){
        initiateLog(Log::Level::TRACE);
        return static_cast<T_Derived&>(*this);
    } // #END: trace()

    // #FUNCTION: trace<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::trace(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::TRACE, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: trace<..T_Args>(const std::string&)

    // #FUNCTION: trace(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::trace(std::string&& p_message){
        initiateLog(Log::Level::TRACE, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: trace(std::string&&)

    // #FUNCTION: debug(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::debug(){
        initiateLog(Log::Level::DEBUG);
        return static_cast<T_Derived&>(*this);
    } // #END: debug()

    // #FUNCTION: debug<..T_Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    template<class... T_Args> T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::debug(const std::string& p_message, T_Args... p_args){
        initiateLog(Log::Level::DEBUG, p_message, p_args...);
        return static_cast<T_Derived&>(*this);
    } // #END: debug<..T_Args>(const std::string&)

    // #FUNCTION: debug(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::debug(std::string&& p_message){
        initiateLog(Log::Level::DEBUG, std::move(p_message));
        return static_cast<T_Derived&>(*this);
    } // #END: debug(std::string&&)

    // #FUNCTION: message<...Args>(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    template<class... Args>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::message(const std::string& p_message, Args... p_args){
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
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::message(std::string&& p_message){
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
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::time(const std_TimePoint& p_time){
        if(m_bufferedLog){
            m_bufferedLog->time = p_time;
        }
        return static_cast<T_Derived&>(*this);
    } // #END: time(const TimePoint&)

    // #FUNCTION: time(const std::time_t), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::time(const std::time_t p_time){
        if(m_bufferedLog){
            m_bufferedLog->time = std::chrono::system_clock::from_time_t(p_time);
        }
        return static_cast<T_Derived&>(*this);
    } // #END: time(const std::time_t)

    // #FUNCTION: location(const std::source_location&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::location(const std::source_location& p_location){
        if(m_bufferedLog){
            m_bufferedLog->location = p_location;
        }
        return static_cast<T_Derived&>(*this);
    } // #END: location(const std::source_location&)

    // #FUNCTION: location(std::source_location&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::location(std::source_location&& p_location){
        if(m_bufferedLog){
            m_bufferedLog->location = std::move(p_location);
        }
        return static_cast<T_Derived&>(*this);
    } // #END: location(std::source_location&&)

    // #FUNCTION: send(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::send(){
        flushBuffer();
        return static_cast<T_Derived&>(*this);
    } // #END: send()

    // #FUNCTION: flush(), Method   
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors> 
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::flush(){
        flushBuffer();
        m_outputStream.flush();
        return static_cast<T_Derived&>(*this);
    } // #END: flush()

    // #FUNCTION: formatting(const Formatting&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::formatting(const Formatting& p_formatting){
        m_formatting = p_formatting;
        return static_cast<T_Derived&>(*this);
    } // #END: formatting(const Formatting&)

    // #FUNCTION: formatting(Formatting&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::formatting(Formatting&& p_formatting){
        m_formatting = std::move(p_formatting);
        return static_cast<T_Derived&>(*this);
    } // #END: formatting(Formatting&&)

    // #FUNCTION: nameFormat(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::nameFormat(const std::string& p_name){
        m_formatting.name = p_name;
        return static_cast<T_Derived&>(*this);
    } // #END: nameFormat(const std::string&)

    // #FUNCTION: nameFormat(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::nameFormat(std::string&& p_name){
        m_formatting.name = std::move(p_name);
        return static_cast<T_Derived&>(*this);
    } // #END: nameFormat(std::string&&)

    // #FUNCTION: levelFormat(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelFormat(const std::string& p_level){
        m_formatting.level = p_level;
        return static_cast<T_Derived&>(*this);
    } // #END: levelFormat(const std::string&)

    // #FUNCTION: levelFormat(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelFormat(std::string&& p_level){
        m_formatting.level = std::move(p_level);
        return static_cast<T_Derived&>(*this);
    } // #END: levelFormat(std::string&&)

    // #FUNCTION: messageFormat(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::messageFormat(const std::string& p_message){
        m_formatting.message = p_message;
        return static_cast<T_Derived&>(*this);
    } // #END: messageFormat(const std::string&)

    // #FUNCTION: messageFormat(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::messageFormat(std::string&& p_message){
        m_formatting.message =  std::move(p_message);
        return static_cast<T_Derived&>(*this);
    } // #END: messageFormat(std::string&&)

    // #FUNCTION: timeFormat(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::timeFormat(const std::string& p_time){
        m_formatting.time = p_time;
        return static_cast<T_Derived&>(*this);
    } // #END: timeFormat(const std::string&)

    // #FUNCTION: timeFormat(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::timeFormat(std::string&& p_time){
        m_formatting.time = std::move(p_time);
        return static_cast<T_Derived&>(*this);
    } // #END: timeFormat(std::string&&)

    // #FUNCTION: locationFormat(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::locationFormat(const std::string& p_location){
        m_formatting.location = p_location;
        return static_cast<T_Derived&>(*this);
    } // #END: locationFormat(const std::string&)

    // #FUNCTION: locationFormat(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::locationFormat(std::string&& p_location){
        m_formatting.location = std::move(p_location);
        return static_cast<T_Derived&>(*this);
    } // #END: locationFormat(std::string&&)

    // #FUNCTION: orderFormat(const std::array<Formatting::Type, Formatting::COUNT>&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::orderFormat(const std::array<Formatting::Type, Formatting::COUNT>& p_order){
        m_formatting.order = p_order;
        return static_cast<T_Derived&>(*this);
    } // #END: orderFormat(const std::array<Formatting::Type, Formatting::COUNT>&)

    // #FUNCTION: orderFormat(const std::initializer_list<Formatting::Type>), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::orderFormat(const std::initializer_list<Formatting::Type> p_order){
        std::copy(p_order.begin(), p_order.end(), m_formatting.order.begin());
        return static_cast<T_Derived&>(*this);
    } // #END: orderFormat(const std::initializer_list<Formatting::Type>)

    // #FUNCTION: levelSpecificFormatting(const std::variant<Log::Level, std::string>&, const Formatting&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificFormatting(const std::variant<Log::Level, std::string>& p_level, const Formatting& p_formatting){
        static_assert(t_usingLevelFormatting, "Cannot set level specific format when level formats are disabled.");
        m_levelSpecificFormatting[p_level] = p_formatting;
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificFormatting(const std::variant<Log::Level, std::string>&)

    // #FUNCTION: levelSpecificFormatting(const std::variant<Log::Level, std::string>&, Formatting&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificFormatting(const std::variant<Log::Level, std::string>& p_level, Formatting&& p_formatting){
        static_assert(t_usingLevelFormatting, "Cannot set level specific format when level formats are disabled.");
        m_levelSpecificFormatting[p_level] = std::move(p_formatting);
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificFormatting(const std::variant<Log::Level, std::string>&, Formatting&&)

    // #FUNCTION: levelSpecificNameFormat(const std::variant<Log::Level, std::string>&, const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificNameFormat(const std::variant<Log::Level, std::string>& p_level, const std::string& p_name){
        static_assert(t_usingLevelFormatting, "Cannot set level specific format name when level formats are disabled.");
        m_levelSpecificFormatting[p_level].name = p_name;
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificNameFormat(const std::variant<Log::Level, std::string>&, const std::string&)

    // #FUNCTION: levelSpecificNameFormat(const std::variant<Log::Level, std::string>&, std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificNameFormat(const std::variant<Log::Level, std::string>& p_level, std::string&& p_name){
        static_assert(t_usingLevelFormatting, "Cannot set level specific format name when level formats are disabled.");
        m_levelSpecificFormatting[p_level].name = std::move(p_name);
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificNameFormat(const std::variant<Log::Level, std::string>&, std::string&&)

    // #FUNCTION: levelSpecificLevelFormat(const std::variant<Log::Level, std::string>&, const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificLevelFormat(const std::variant<Log::Level, std::string>& p_level, const std::string& p_levelFormat){
        static_assert(t_usingLevelFormatting, "Cannot set level specific format level when level formats are disabled.");
        m_levelSpecificFormatting[p_level].level = p_levelFormat;
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificLevelFormat(const std::variant<Log::Level, std::string>&, const std::string&)

    // #FUNCTION: levelSpecificLevelFormat(const std::variant<Log::Level, std::string>&, std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificLevelFormat(const std::variant<Log::Level, std::string>& p_level, std::string&& p_levelFormat){
        static_assert(t_usingLevelFormatting, "Cannot set level specific format level when level formats are disabled.");
        m_levelSpecificFormatting[p_level].level = std::move(p_levelFormat);
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificLevelFormat(const std::variant<Log::Level, std::string>&, std::string&&)

    // #FUNCTION: levelSpecificMessageFormat(const std::variant<Log::Level, std::string>&, const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificMessageFormat(const std::variant<Log::Level, std::string>& p_level, const std::string& p_message){
        static_assert(t_usingLevelFormatting, "Cannot set level specific format message when level formats are disabled.");
        m_levelSpecificFormatting[p_level].message = p_message;
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificMessageFormat(const std::variant<Log::Level, std::string>&, const std::string&)

    // #FUNCTION: levelSpecificMessageFormat(const std::variant<Log::Level, std::string>&, std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificMessageFormat(const std::variant<Log::Level, std::string>& p_level, std::string&& p_message){
        static_assert(t_usingLevelFormatting, "Cannot set level specific format message when level formats are disabled.");
        m_levelSpecificFormatting[p_level].message = std::move(p_message);
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificMessageFormat(const std::variant<Log::Level, std::string>&, std::string&&)

    // #FUNCTION: levelSpecificTimeFormat(const std::variant<Log::Level, std::string>&, const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificTimeFormat(const std::variant<Log::Level, std::string>& p_level, const std::string& p_time){
        static_assert(t_usingLevelFormatting, "Cannot set level specific format time when level formats are disabled.");
        m_levelSpecificFormatting[p_level].time = p_time;
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificTimeFormat(const std::variant<Log::Level, std::string>&, const std::string&)

    // #FUNCTION: levelSpecificTimeFormat(const std::variant<Log::Level, std::string>&, std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificTimeFormat(const std::variant<Log::Level, std::string>& p_level, std::string&& p_time){
        static_assert(t_usingLevelFormatting, "Cannot set level specific format time when level formats are disabled.");
        m_levelSpecificFormatting[p_level].time = std::move(p_time);
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificTimeFormat(const std::variant<Log::Level, std::string>&, std::string&&)

    // #FUNCTION: levelSpecificLocationFormat(const std::variant<Log::Level, std::string>&, const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificLocationFormat(const std::variant<Log::Level, std::string>& p_level, const std::string& p_location){
        static_assert(t_usingLevelFormatting, "Cannot set level specific format location when level formats are disabled.");
        m_levelSpecificFormatting[p_level].location = p_location;
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificLocationFormat(const std::variant<Log::Level, std::string>&, const std::string&)

    // #FUNCTION: levelSpecificLocationFormat(const std::variant<Log::Level, std::string>&, std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificLocationFormat(const std::variant<Log::Level, std::string>& p_level, std::string&& p_location){
        static_assert(t_usingLevelFormatting, "Cannot set level specific format location when level formats are disabled.");
        m_levelSpecificFormatting[p_level].location = std::move(p_location);
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificLocationFormat(const std::variant<Log::Level, std::string>&, std::string&&)

    // #FUNCTION: levelSpecificOrderFormat(const std::variant<Log::Level, std::string>&, const std::array<Formatting::Type, Formatting::COUNT>&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificOrderFormat(const std::variant<Log::Level, std::string>& p_level, const std::array<Formatting::Type, Formatting::COUNT>& p_order){
        static_assert(t_usingLevelFormatting, "Cannot set level specific format order when level formats are disabled.");
        m_levelSpecificFormatting[p_level].order = p_order;
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificOrderFormat(const std::variant<Log::Level, std::string>&, const std::array<Formatting::Type, Formatting::COUNT>&)
    
    // #FUNCTION: levelSpecificOrderFormat(const std::variant<Log::Level, std::string>&, const std::initializer_list<Formatting::Type>), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificOrderFormat(const std::variant<Log::Level, std::string>& p_level, const std::initializer_list<Formatting::Type> p_order){
        static_assert(t_usingLevelFormatting, "Cannot set level specific format order when level formats are disabled.");
        std::copy(p_order.begin(), p_order.end(), m_levelSpecificFormatting[p_level].order.begin());
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificOrderFormat(const std::variant<Log::Level, std::string>&, const std::initializer_list<Formatting::Type>)

    // #FUNCTION: coloring(const Coloring&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::coloring(const Coloring& p_coloring){
        static_assert(t_usingColors, "Cannot set coloring when colors are disabled.");
        m_coloring = p_coloring;
        return static_cast<T_Derived&>(*this);
    } // #END: coloring(const Coloring&)

    // #FUNCTION: coloring(Coloring&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::coloring(Coloring&& p_coloring){
        static_assert(t_usingColors, "Cannot set coloring when colors are disabled.");
        m_coloring = std::move(p_coloring);
        return static_cast<T_Derived&>(*this);
    } // #END: coloring(Coloring&&)

    // #FUNCTION: logColor(const Color), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::logColor(const Color p_color){
        static_assert(t_usingColors, "Cannot set log color when colors are disabled.");
        m_coloring.log = p_color;
        return static_cast<T_Derived&>(*this);
    } // #END: logColor(const Color)

    // #FUNCTION: nameColor(const Color), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::nameColor(const Color p_color){
        static_assert(t_usingColors, "Cannot set name color when colors are disabled.");
        m_coloring.name = p_color;
        return static_cast<T_Derived&>(*this);
    } // #END: nameColor(const Color)  

    // #FUNCTION: levelColor(const Color), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelColor(const Color p_color){
        static_assert(t_usingColors, "Cannot set level color when colors are disabled.");
        m_coloring.level = p_color;
        return static_cast<T_Derived&>(*this);
    } // #END: levelColor(const Color)

    // #FUNCTION: messageColor(const Color), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::messageColor(const Color p_color){
        static_assert(t_usingColors, "Cannot set message color when colors are disabled.");
        m_coloring.message = p_color;
        return static_cast<T_Derived&>(*this);
    } // #END: messageColor(const Color)

    // #FUNCTION: timeColor(const Color), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::timeColor(const Color p_color){
        static_assert(t_usingColors, "Cannot set time color when colors are disabled.");
        m_coloring.time = p_color;
        return static_cast<T_Derived&>(*this);
    } // #END: timeColor(const Color)

    // #FUNCTION: locationColor(const Color), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::locationColor(const Color p_color){
        static_assert(t_usingColors, "Cannot set location color when colors are disabled.");
        m_coloring.location = p_color;
        return static_cast<T_Derived&>(*this);
    } // #END: locationColor(const Color)

    // #FUNCTION: levelSpecificColoring(const std::variant<Log::Level, std::string>&, const Coloring&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificColoring(const std::variant<Log::Level, std::string>& p_level, const Coloring& p_coloring){
        static_assert(t_usingColors, "Cannot set level specific coloring when colors are disabled.");
        m_levelSpecificColoring[p_level] = p_coloring;
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificColoring(const std::variant<Log::Level, std::string>&, const Coloring&)
    
    // #FUNCTION: levelSpecificColoring(const std::variant<Log::Level, std::string>&, Coloring&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificColoring(const std::variant<Log::Level, std::string>& p_level, Coloring&& p_coloring){
        static_assert(t_usingColors, "Cannot set level specific coloring when colors are disabled.");
        m_levelSpecificColoring[p_level] = std::move(p_coloring);
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificColoring(const std::variant<Log::Level, std::string>&, Coloring&&)

    // #FUNCTION: levelSpecificLogColor(const std::variant<Log::Level, std::string>&, const Color), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificLogColor(const std::variant<Log::Level, std::string>& p_level, const Color p_color){
        static_assert(t_usingColors, "Cannot set level specific log color when colors are disabled.");
        m_levelSpecificColoring[p_level].log = p_color;
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificLogColor(const std::variant<Log::Level, std::string>&, const Color)

    // #FUNCTION: levelSpecificNameColor(const std::variant<Log::Level, std::string>&, const Color), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificNameColor(const std::variant<Log::Level, std::string>& p_level, const Color p_color){
        static_assert(t_usingColors, "Cannot set level specific name color when colors are disabled.");
        m_levelSpecificColoring[p_level].name = p_color; 
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificNameColor(const std::variant<Log::Level, std::string>&, const Color)

    // #FUNCTION: levelSpecificLevelColor(const std::variant<Log::Level, std::string>&, const Color), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificLevelColor(const std::variant<Log::Level, std::string>& p_level, const Color p_color){
        static_assert(t_usingColors, "Cannot set level specific level color when colors are disabled.");
        m_levelSpecificColoring[p_level].level = p_color;
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificLevelColor(const std::variant<Log::Level, std::string>&, const Color)

    // #FUNCTION: levelSpecificMessageColor(const std::variant<Log::Level, std::string>&, const Color), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificMessageColor(const std::variant<Log::Level, std::string>& p_level, const Color p_color){
        static_assert(t_usingColors, "Cannot set level specific message color when colors are disabled.");
        m_levelSpecificColoring[p_level].message = p_color;
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificMessageColor(const std::variant<Log::Level, std::string>&, const Color)

    // #FUNCTION: levelSpecificTimeColor(const std::variant<Log::Level, std::string>&, const Color), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificTimeColor(const std::variant<Log::Level, std::string>& p_level, const Color p_color){
        static_assert(t_usingColors, "Cannot set level specific time color when colors are disabled.");
        m_levelSpecificColoring[p_level].time = p_color;
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificTimeColor(const std::variant<Log::Level, std::string>&, const Color)

    // #FUNCTION: levelSpecificLocationColor(const std::variant<Log::Level, std::string>&, const Color), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificLocationColor(const std::variant<Log::Level, std::string>& p_level, const Color p_color){
        static_assert(t_usingColors, "Cannot set level specific location color when colors are disabled.");
        m_levelSpecificColoring[p_level].location = p_color;
        return static_cast<T_Derived&>(*this);
    } // #END: levelSpecificLocationColor(const std::variant<Log::Level, std::string>&, const Color)

    // #FUNCTION: name(const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::name(const std::string& p_name){
        m_name = p_name;
        return static_cast<T_Derived&>(*this);
    } // #END: name(const std::string&)

    // #FUNCTION: name(std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    T_Derived& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::name(std::string&& p_name){
        m_name = std::move(p_name);
        return static_cast<T_Derived&>(*this);
    } // #END: name(std::string&&)

    // #FUNCTION: usingLevelFormatting(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    [[nodiscard]] constexpr bool Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::usingLevelFormatting()const{
        return t_usingLevelFormatting;
    } // #END: usingLevelFormatting()

    // #FUNCTION: usingColors(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    [[nodiscard]] constexpr bool Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::usingColors()const{
        return t_usingColors;
    } // #END: usingColors()

    // #FUNCTION: formatting(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    [[nodiscard]] const Formatting& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::formatting()const{
        return m_formatting;
    } // #END: formatting()

    // #FUNCTION: levelSpecificFormatting(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    [[nodiscard]] const std::unordered_map<std::variant<Log::Level, std::string>, Formatting>& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificFormatting()const{
        static_assert(t_usingLevelFormatting, "Cannot get level specific formats when level formats are disabled.");
        return m_levelSpecificFormatting;
    } // #END: levelSpecificFormatting()

    // #FUNCTION: coloring(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    [[nodiscard]] const Coloring& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::coloring()const{
        static_assert(t_usingColors, "Cannot get coloring when colors are disabled.");
        return m_coloring;
    } // #END: coloring()

    // #FUNCTION: levelSpecificColoring(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    [[nodiscard]] const std::unordered_map<std::variant<Log::Level, std::string>, Coloring>& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::levelSpecificColoring()const{
        static_assert(t_usingColors, "Cannot get level specific coloring when colors are disabled.");
        return m_levelSpecificColoring;
    } // #END: levelSpecificColoring()

    // #FUNCTION: name(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    [[nodiscard]] const std::string& Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::name()const{
        return m_name;
    } // #END: name()

// #DIV: Protected Factory Methods

    // #FUNCTION: Logger<T_Name, T_Format>(const std::string&, OutputStream&), Constructor
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::Logger(const std::string& p_name, OutputStream& p_outputStream): m_name(p_name), m_outputStream(p_outputStream){

    } // #END: Logger<T_Name, T_Format>(const std::string&, OutputStream&)

    // #FUNCTION: Logger<T_Name, T_Format>(std::string&&, OutputStream&), Constructor
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::Logger(std::string&& p_name, OutputStream& p_outputStream): m_name(std::move(p_name)), m_outputStream(p_outputStream){

    } // #END: Logger<T_Name, T_Format>(std::string&&, OutputStream&)

// #DIV: Protected Methods

    // #FUNCTION: initiateLog(Log::Level), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    void Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::initiateLog(const std::variant<Log::Level, std::string> p_level){
        if(m_bufferedLog){
            flushBuffer();
        }
        m_bufferedLog = Log(std::move(p_level));
    } // #END: initiateLog(Log::Level)

    // #FUNCTION: initiateLog<...T_Args>(Log::Level, const std::string&, Args&&...), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    template<class... T_Args> void Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::initiateLog(const std::variant<Log::Level, std::string> p_level, const std::string& p_message, T_Args... p_args){
        initiateLog(std::move(p_level));
        if constexpr(sizeof...(p_args) == 0){ // No formatting arguments
            m_bufferedLog->message = p_message;
        }else{
            m_bufferedLog->message = std::vformat(p_message, std::make_format_args(p_args...));
        }
    } // #END: initiateLog<...T_Args>(Log::Level, const std::string&, Args&&...)

    // #FUNCTION: initiateLog(Log::Level, std::string&&, Args&&...), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    void Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::initiateLog(const std::variant<Log::Level, std::string> p_level, std::string&& p_message){
        initiateLog(std::move(p_level));
        m_bufferedLog->message = std::move(p_message);
    } // #END: initiateLog(Log::Level, std::string&&, Args&&...)

    // #FUNCTION: flushBuffer(), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>    
    void Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::flushBuffer(){
        if(m_bufferedLog){
            if constexpr(t_usingColors){ // Colors enabled
                m_outputStream << getColoredLog(m_bufferedLog->level, getFormattedLog(*m_bufferedLog)); 
            }else{
                m_outputStream << getFormattedLog(*m_bufferedLog);
            }
            m_bufferedLog.reset();
        }
    } // #END: flushBuffer()
    
    // #FUNCTION: getFormattedLog(const Log&), Static Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::getFormattedLog(const Log& p_log){
        std::string formattedLog;
        // Format log parts
        for(Formatting::Type format: m_formatting.order){
            if(std::string formattedPart = getFormattedPart(format, p_log); !formattedPart.empty()){
                if(!formattedLog.empty()){ // Not first part
                    formattedLog += Formatting::SEPARATOR;
                }
                if constexpr(t_usingColors){ // Colors enabled
                    formattedLog += getColoredPart(p_log.level, format, std::move(formattedPart));
                }else{
                    formattedLog += std::move(formattedPart);
                }
            }
        }
        return formattedLog + Formatting::LOG_END;
    } // #END: getFormattedLog(const Log&)

    // #FUNCTION: getFormattedPart(const Log::Format, const Log&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::getFormattedPart(const Formatting::Type p_format, const Log& p_log){
        switch(p_format){
            case Formatting::Type::TIME: return (p_log.time)? getFormattedTime(p_log.level, *p_log.time): "";
            case Formatting::Type::LEVEL: return getFormattedLevel(p_log.level);
            case Formatting::Type::NAME: return getFormattedName(p_log.level, m_name);
            case Formatting::Type::MESSAGE: return getFormattedMessage(p_log.level, p_log.message);
            case Formatting::Type::LOCATION: return (p_log.location)? getFormattedLocation(p_log.level, *p_log.location): "";
            default: return "";
        }
    } // #END: getFormattedPart(const Log::Format, const Log&)

    // #FUNCTION: getFormattedName(const std::variant<Log::Level, std::string>&, const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::getFormattedName(const std::variant<Log::Level, std::string>& p_level, const std::string& p_name){
        if constexpr(t_usingLevelFormatting){ // Check for specific format
            if(auto node = m_levelSpecificFormatting.find(p_level); node != m_levelSpecificFormatting.end()) [[unlikely]] { // Specific format for this level
                const Formatting& levelFormatting = node->second;
                return std::vformat(levelFormatting.name, std::make_format_args(p_name));
            }
        }
        return std::vformat(m_formatting.name, std::make_format_args(p_name));
    } // #END: getFormattedName(const std::variant<Log::Level, std::string>&, const std::string&)

    // #FUNCTION: getFormattedMessage(const std::variant<Log::Level, std::string>&, const std::string&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::getFormattedMessage(const std::variant<Log::Level, std::string>& p_level, const std::string& p_message){
        if constexpr(t_usingLevelFormatting){ // Check for specific format
            if(auto node = m_levelSpecificFormatting.find(p_level); node != m_levelSpecificFormatting.end()) [[unlikely]] { // Specific format for this level
                const Formatting& levelFormatting = node->second;
                return std::vformat(levelFormatting.message, std::make_format_args(p_message));
            }
        }
        return std::vformat(m_formatting.message, std::make_format_args(p_message));
    } // #END: getFormattedMessage(const std::variant<Log::Level, std::string>&, const std::string&)

    // #FUNCTION: getFormattedLevel(const std::variant<Log::Level, std::string>&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::getFormattedLevel(const std::variant<Log::Level, std::string>& p_level){
        const std::string levelString = Log::getLevelString(p_level);
        if constexpr(t_usingLevelFormatting){ // Check for specific format
            if(auto node = m_levelSpecificFormatting.find(p_level); node != m_levelSpecificFormatting.end()) [[unlikely]] { // Specific format for this level
                const Formatting& levelFormatting = node->second;
                return std::vformat(levelFormatting.level, std::make_format_args(levelString));
            }
        }
        return std::vformat(m_formatting.level, std::make_format_args(levelString));
    } // #END: getFormattedLevel(const std::variant<Log::Level, std::string>&)

    // #FUNCTION: getFormattedTime(const std::variant<Log::Level, std::string>&, const std_TimePoint&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::getFormattedTime(const std::variant<Log::Level, std::string>& p_level, const std_TimePoint& p_time){
        // Convert time
        const std::uint8_t hours = std::chrono::duration_cast<std::chrono::hours>(p_time.time_since_epoch()).count() % 24;
        const std::uint8_t minutes = std::chrono::duration_cast<std::chrono::minutes>(p_time.time_since_epoch()).count() % 60;
        const std::uint8_t seconds = std::chrono::duration_cast<std::chrono::seconds>(p_time.time_since_epoch()).count() % 60;
        const std::uint16_t milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(p_time.time_since_epoch()).count() % 1000;
        if constexpr(t_usingLevelFormatting){ // Check for specific format
            if(auto node = m_levelSpecificFormatting.find(p_level); node != m_levelSpecificFormatting.end()) [[unlikely]] { // Specific format for this level
                const Formatting& levelFormatting = node->second;
                return std::vformat(levelFormatting.time, std::make_format_args(hours, minutes, seconds, milliseconds));
            }
        }
        return std::vformat(m_formatting.time, std::make_format_args(hours, minutes, seconds, milliseconds));
    } // #END: getFormattedTime(const std::variant<Log::Level, std::string>&, const std_TimePoint&)

    // #FUNCTION: getFormattedLocation(const std::variant<Log::Level, std::string>&, const std::source_location&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::getFormattedLocation(const std::variant<Log::Level, std::string>& p_level, const std::source_location& p_location){
        // Get location components
        const std::string function = p_location.function_name();
        const std::uint32_t line = p_location.line();
        const std::string file = p_location.file_name();
        if constexpr(t_usingLevelFormatting){ // Check for specific format
            if(auto node = m_levelSpecificFormatting.find(p_level); node != m_levelSpecificFormatting.end()) [[unlikely]] { // Specific format for this level
                const Formatting& levelFormatting = node->second;
                return std::vformat(levelFormatting.location, std::make_format_args(function, line, file));
            }
        }
        return std::vformat(m_formatting.location, std::make_format_args(function, line, file));
    } // #END: getFormattedLocation(const std::variant<Log::Level, std::string>&, const std::source_location&)

    // #FUNCTION: getLogColorCode(const std::variant<Log::Level, std::string>&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::getLogColorCode(const std::variant<Log::Level, std::string>& p_level){
        if(auto node = m_levelSpecificColoring.find(p_level); node != m_levelSpecificColoring.end()) [[unlikely]] { // Specific coloring for this level
            const Coloring& levelSpecificColoring = node->second;
            if(levelSpecificColoring.log) return ansi::getColorCode(*levelSpecificColoring.log); // Return specific color if set
        }
        return (m_coloring.log)? ansi::getColorCode(*m_coloring.log): ""; // Return general color if set
    } // #END: getLogColorCode(const std::variant<Log::Level, std::string>&)

    // #FUNCTION: getPartColorCode(const std::variant<Log::Level, std::string>&, const Formatting::Type), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::getPartColorCode(const std::variant<Log::Level, std::string>& p_level, const Formatting::Type p_format){
        // Check level specific coloring
        if(auto node = m_levelSpecificColoring.find(p_level); node != m_levelSpecificColoring.end()) [[unlikely]] { // Specific coloring for this level
            const Coloring& levelSpecificColoring = node->second;
            switch(p_format){ // Check for level specific part color
                case Formatting::Type::TIME: {
                    if(levelSpecificColoring.time) return ansi::getColorCode(*levelSpecificColoring.time); // Return specific color if set
                    break;
                }case Formatting::Type::LEVEL: {
                    if(levelSpecificColoring.level) return ansi::getColorCode(*levelSpecificColoring.level); // Return specific color if set
                    break;
                }case Formatting::Type::NAME: {
                    if(levelSpecificColoring.name) return ansi::getColorCode(*levelSpecificColoring.name); // Return specific color if set
                    break;
                }case Formatting::Type::MESSAGE: {
                    if(levelSpecificColoring.message) return ansi::getColorCode(*levelSpecificColoring.message); // Return specific color if set
                    break;
                }case Formatting::Type::LOCATION: {
                    if(levelSpecificColoring.location) return ansi::getColorCode(*levelSpecificColoring.location); // Return specific color if set
                    break;
                }default: {
                    break;
                }
            } // switch
            if(levelSpecificColoring.log) return ""; // Return to log color if set
        } // if
        // Check coloring
        switch(p_format){ // Check for part color
            case Formatting::Type::TIME: {
                if(m_coloring.time) return ansi::getColorCode(*m_coloring.time); // Return color if set
                break;
            }case Formatting::Type::LEVEL: {
                if(m_coloring.level) return ansi::getColorCode(*m_coloring.level); // Return color if set
                break;
            }case Formatting::Type::NAME: {
                if(m_coloring.name) return ansi::getColorCode(*m_coloring.name); // Return color if set
                break;
            }case Formatting::Type::MESSAGE: {
                if(m_coloring.message) return ansi::getColorCode(*m_coloring.message); // Return color if set
                break;
            }case Formatting::Type::LOCATION: {
                if(m_coloring.location) return ansi::getColorCode(*m_coloring.location); // Return color if set
                break;
            }default: {
                break;
            }
        } // switch
        return ""; // No color set
    } // #END: getPartColorCode(const std::variant<Log::Level, std::string>&, const Formatting::Type)

    // #FUNCTION: getColoredPart(const std::variant<Log::Level, std::string>&, const Formatting::Type, std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::getColoredPart(const std::variant<Log::Level, std::string>& p_level, const Formatting::Type p_format, std::string&& p_part){
        // Check for part color
        if(const std::string colorCode = getPartColorCode(p_level, p_format); !colorCode.empty()){ // Color set
            if(getLogColorCode(p_level).empty()){ // No log color 
                return colorCode + std::move(p_part) + ansi::RESET;
            }else{ // Log color set
                return colorCode + std::move(p_part) + getLogColorCode(p_level); // Reset to log color
            }
        }else{ // No color set
            return std::move(p_part); // No color set
        }
    } // #END: getColoredPart(const std::variant<Log::Level, std::string>&, const Formatting::Type, std::string&&)

    // #FUNCTION: getColoredLog(const std::variant<Log::Level, std::string>&, std::string&&), Method
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors>
    std::string Logger<T_Derived, t_usingLevelFormatting, t_usingColors>::getColoredLog(const std::variant<Log::Level, std::string>& p_level, std::string&& p_log){
        if(const std::string colorCode = getLogColorCode(p_level); !colorCode.empty()){ // Color set
            return colorCode + std::move(p_log) + ansi::RESET;
        }else{ // No color set
            return std::move(p_log);
        }
    } // #END: getColoredLog(const std::variant<Log::Level, std::string>&, std::string&&)
// #END: Logger<T_Derived>

} // #END: pureLog::logger