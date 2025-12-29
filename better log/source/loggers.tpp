// #file:

#include "loggers.hpp" // Module header

namespace worTech::betterCpp::loggers{

// #div: public static methods

    // #func: get<T_derived>(), public static method
    // #scope: Logger, abstract singleton class
    // #info: returns a static instance of a T_derived Logger class
    // #template: class T_derived, derived logger class type
    // #return: const Logger&, static Logger instance
    template<class T_derived> Logger& Logger::get(){
        static T_derived instance = T_derived();
        return instance;
    }

// #div: public methods

    // #func: log<t_logLevel>(std::string&), public const template method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with a log level
    // #overload: log<t_logLevel>(std::string&, std::source_location&)
    // #overload: log<t_logLevel>(std::string&, time_t&)
    // #overload: log<t_logLevel>(std::string&, std::source_location&, time_t&)
    // #overload: log<t_logLevel>(std::string&&)
    // #overload: log<t_logLevel>(std::string&&, std::source_location&)
    // #overload: log<t_logLevel>(std::string&&, time_t&)
    // #overload: log<t_logLevel>(std::string&&, std::source_location&, time_t&)
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&, std::optional<std::source_location>, std::optional<time_t>)
    // #template: Level t_logLevel, log level of the message
    // #param: const std::string& p_message, message to log
    // #return: const Logger&, current Logger instance
    template<Level t_logLevel> const Logger& Logger::log(const std::string& p_message)const{
        sendLog(formatLog<t_logLevel>(p_message, std::nullopt, std::nullopt));
        return *this;
    }
    // #func: log<t_logLevel>(std::string&, std::source_location&), public const template method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with a log level
    // #overload: log<t_logLevel>(std::string&)
    // #overload: log<t_logLevel>(std::string&, time_t&)
    // #overload: log<t_logLevel>(std::string&, std::source_location&, time_t&)
    // #overload: log<t_logLevel>(std::string&&)
    // #overload: log<t_logLevel>(std::string&&, std::source_location&)
    // #overload: log<t_logLevel>(std::string&&, time_t&)
    // #overload: log<t_logLevel>(std::string&&, std::source_location&, time_t&)
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&, std::optional<std::source_location>&, std::optional<time_t>) 
    // #template: Level t_logLevel, log level of the message
    // #param: const std::string& p_message, message to log
    // #param: const std::source_location& p_location, source location of the message
    // #return: const Logger&, current Logger instance
    template<Level t_logLevel> const Logger& Logger::log(const std::string& p_message, const std::source_location& p_location)const{
        sendLog(formatLog<t_logLevel>(p_message, p_location, std::nullopt)); 
        return *this;
    }
    // #func: log<t_logLevel>(std::string&, time_t&), public const template method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with a log level
    // #overload: log<t_logLevel>(std::string&)
    // #overload: log<t_logLevel>(std::string&, std::source_location&)
    // #overload: log<t_logLevel>(std::string&, std::source_location&, time_t&)
    // #overload: log<t_logLevel>(std::string&&)
    // #overload: log<t_logLevel>(std::string&&, std::source_location&)
    // #overload: log<t_logLevel>(std::string&&, time_t&)
    // #overload: log<t_logLevel>(std::string&&, std::source_location&, time_t&)
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&, std::optional<std::source_location>&, std::optional<time_t>)
    // #template: Level t_logLevel, log level of the message
    // #param: const std::string& p_message, message to log
    // #param: const time_t& p_time, time of the message
    // #return: const Logger&, current Logger instance
    template<Level t_logLevel> const Logger& Logger::log(const std::string& p_message, const time_t& p_time)const{
        sendLog(formatLog<t_logLevel>(p_message, std::nullopt, p_time));
        return *this;
    }
    // #func: log<t_logLevel>(std::string&, std::source_location&, time_t&), public const template method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with a log level
    // #overload: log<t_logLevel>(std::string&)
    // #overload: log<t_logLevel>(std::string&, std::source_location&)
    // #overload: log<t_logLevel>(std::string&, time_t&)
    // #overload: log<t_logLevel>(std::string&&)
    // #overload: log<t_logLevel>(std::string&&, std::source_location&)
    // #overload: log<t_logLevel>(std::string&&, time_t&)
    // #overload: log<t_logLevel>(std::string&&, std::source_location&, time_t&)
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&, std::optional<std::source_location>&, std::optional<time_t>)
    // #template: Level t_logLevel, log level of the message
    // #param: const std::string& p_message, message to log
    // #param: const std::source_location& p_location, source location of the message
    // #param: const time_t& p_time, time of the message
    // #return: const Logger&, current Logger instance
    template<Level t_logLevel> const Logger& Logger::log(const std::string& p_message, const std::source_location& p_location, 
    const time_t& p_time)const{
        sendLog(formatLog<t_logLevel>(p_message, p_location, p_time));
        return *this;
    }
    // #func: log<t_logLevel>(std::string&&), public const template method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with a log level
    // #note: takes ownership of the message
    // #overload: log<t_logLevel>(std::string&)
    // #overload: log<t_logLevel>(std::string&, std::source_location&)
    // #overload: log<t_logLevel>(std::string&, time_t&)
    // #overload: log<t_logLevel>(std::string&, std::source_location&, time_t&)
    // #overload: log<t_logLevel>(std::string&&, std::source_location&)
    // #overload: log<t_logLevel>(std::string&&, time_t&)
    // #overload: log<t_logLevel>(std::string&&, std::source_location&, time_t&)
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&&, std::optional<std::source_location>, std::optional<time_t>)
    // #template: Level t_logLevel, log level of the message
    // #param: std::string&& p_message, message to log
    // #return: const Logger&, current Logger instance
    template<Level t_logLevel> const Logger& Logger::log(std::string&& p_message)const{
        sendLog(formatLog<t_logLevel>(std::forward<std::string>(p_message), std::nullopt, std::nullopt));
        return *this;
    }
    // #func: log<t_logLevel>(std::string&&, std::source_location&), public const template method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with a log level
    // #note: takes ownership of the message
    // #overload: log<t_logLevel>(std::string&)
    // #overload: log<t_logLevel>(std::string&, std::source_location&)
    // #overload: log<t_logLevel>(std::string&, time_t&)
    // #overload: log<t_logLevel>(std::string&, std::source_location&, time_t&)
    // #overload: log<t_logLevel>(std::string&&)
    // #overload: log<t_logLevel>(std::string&&, time_t&)
    // #overload: log<t_logLevel>(std::string&&, std::source_location&, time_t&)
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&&, std::optional<std::source_location>, std::optional<time_t>)
    // #template: Level t_logLevel, log level of the message
    // #param: std::string&& p_message, message to log
    // #param: const std::source_location& p_location, source location of the message
    // #return: const Logger&, current Logger instance
    template<Level t_logLevel> const Logger& Logger::log(std::string&& p_message, const std::source_location& p_location)const{
        sendLog(formatLog<t_logLevel>(std::forward<std::string>(p_message), p_location, std::nullopt));
        return *this;
    }
    // #func: log<t_logLevel>(std::string&&, time_t&), public const template method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with a log level
    // #note: takes ownership of the message
    // #overload: log<t_logLevel>(std::string&)
    // #overload: log<t_logLevel>(std::string&, std::source_location&)
    // #overload: log<t_logLevel>(std::string&, time_t&)
    // #overload: log<t_logLevel>(std::string&, std::source_location&, time_t&)
    // #overload: log<t_logLevel>(std::string&&)
    // #overload: log<t_logLevel>(std::string&&, std::source_location&)
    // #overload: log<t_logLevel>(std::string&&, std::source_location&, time_t&)
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&&, std::optional<std::source_location>, std::optional<time_t>)
    // #template: Level t_logLevel, log level of the message
    // #param: std::string&& p_message, message to log
    // #param: const time_t& p_time, time of the message
    // #return: const Logger&, current Logger instance
    template<Level t_logLevel> const Logger& Logger::log(std::string&& p_message, const time_t& p_time)const{
        sendLog(formatLog<t_logLevel>(std::forward<std::string>(p_message), std::nullopt, p_time));
        return *this;
    }
    // #func: log<t_logLevel>(std::string&&, std::source_location&, time_t&), public const template method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with a log level
    // #note: takes ownership of the message
    // #overload: log<t_logLevel>(std::string&)
    // #overload: log<t_logLevel>(std::string&, std::source_location&)
    // #overload: log<t_logLevel>(std::string&, time_t&)
    // #overload: log<t_logLevel>(std::string&, std::source_location&, time_t&)
    // #overload: log<t_logLevel>(std::string&&)
    // #overload: log<t_logLevel>(std::string&&, std::source_location&)
    // #overload: log<t_logLevel>(std::string&&, time_t&)
    // #uses: Level, uint8_t enum class
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&&, std::optional<std::source_location>, std::optional<time_t>)
    // #template: Level t_logLevel, log level of the message
    // #param: std::string&& p_message, message to log
    // #param: const std::source_location& p_location, source location of the message
    // #param: const time_t& p_time, time of the message
    // #return: const Logger&, current Logger instance
    template<Level t_logLevel> const Logger& Logger::log(std::string&& p_message, const std::source_location& p_location, 
    const time_t& p_time)const{
        sendLog(formatLog<t_logLevel>(std::forward<std::string>(p_message), p_location, p_time));
        return *this;
    }

// #div: protected methods

    // #func: formatLog<t_logLevel>(std::string&, std::optional<std::source_location>, std::optional<time_t>), protected const template method
    // #scope: Logger, abstract singleton class
    // #info: formats a log following a specific format order
    // #note: can be overriden to change how the log is formatted
    // #note: relies on RVO to avoid copy
    // #overload: formatLog<t_logLevel>(std::string&&, std::optional<std::source_location>, std::optional<time_t>)
    // #uses: Level, uint8_t enum class
    // #uses: Format, uint8_t enum class
    // #calls: formatLogger(Level)
    // #calls: conditionally formatLevel(Level)
    // #calls: conditionally formatTime(Level, time_t)
    // #calls: formatMessage(Level, std::string&)
    // #calls: conditionally formatLocation(Level, std::source_location&)
    // #template: Level t_logLevel, log level of the message
    // #param: const std::string& p_message, message to log
    // #param: const std::optional<std::source_location>& p_location, optional source location of the message
    // #param: const std::optional<time_t>& p_time, optional time of the message
    // #return: std::string, formatted log
    // #detail: formats the log by iterating over the format order and calling the corresponding format method formatting and concatenating
    // each part of the log then returning it
    template<Level t_logLevel> std::string Logger::formatLog(const std::string& p_message, const std::optional<std::source_location> p_location, 
    const std::optional<time_t> p_time)const{
        std::string log;
        for(const Format& format: m_formatOrder){
            switch(format){
                case Format::LOGGER: {
                    log += formatLogger(t_logLevel);
                    break;
                }case Format::LEVEL: {
                    if(t_logLevel != Level::NONE){
                        log += formatLevel(t_logLevel);
                    }
                    break;
                }case Format::TIME: {
                    if(p_time.has_value()){
                        log += formatTime(t_logLevel, p_time.value());
                    }
                    break;
                }case Format::MESSAGE: {
                    log += formatMessage(t_logLevel, p_message);
                    break;
                }case Format::LOCATION: {
                    if(p_location.has_value()){
                        log += formatLocation(t_logLevel, p_location.value());
                    }
                    break;
                } 
            } 
        }
        return log;      
    }
    // #func: formatLog<t_logLevel>(std::string&&, std::optional<std::source_location>, std::optional<time_t>), protected const template method
    // #scope: Logger, abstract singleton class
    // #info: formats a log following a specific format order
    // #note: can be overriden to change how the log is formatted
    // #note: relies on RVO to avoid copy
    // #note: takes ownership of the message
    // #overload: formatLog<t_logLevel>(std::string&, std::optional<std::source_location>, std::optional<time_t>)
    // #uses: Level, uint8_t enum class
    // #uses: Format, uint8_t enum class
    // #calls: formatLogger(Level)
    // #calls: conditionally formatLevel(Level)
    // #calls: conditionally formatTime(Level, time_t)
    // #calls: formatMessage(Level, std::string&)
    // #calls: conditionally formatLocation(Level, std::source_location&)
    // #template: Level t_logLevel, log level of the message
    // #param: const std::string& p_message, message to log
    // #param: const std::optional<std::source_location>& p_location, optional source location of the message
    // #param: const std::optional<time_t>& p_time, optional time of the message
    // #return: std::string, formatted log
    // #detail: formats the log by iterating over the format order and calling the corresponding format method formatting and concatenating
    // each part of the log then returning it
    template<Level t_logLevel> std::string Logger::formatLog(std::string&& p_message,
    const std::optional<std::source_location> p_location, const std::optional<time_t> p_time)const{
        std::string log;
        for(const Format& format: m_formatOrder){
            switch(format){
                case Format::LOGGER: {
                    log += formatLogger(t_logLevel);
                    break;
                }case Format::LEVEL: {
                    if(t_logLevel != Level::NONE){
                        log += formatLevel(t_logLevel);
                    }
                    break;
                }case Format::TIME: {
                    if(p_time.has_value()){
                        log += formatTime(t_logLevel, p_time.value());
                    }
                    break;
                }case Format::MESSAGE: {
                    log += formatMessage(t_logLevel, std::forward<std::string>(p_message));
                    break;
                }case Format::LOCATION: {
                    if(p_location.has_value()){
                        log += formatLocation(t_logLevel, p_location.value());
                    }
                    break;
                } 
            } 
        }
        return log;      
    }

}