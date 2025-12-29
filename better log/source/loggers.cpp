// #file: loggers.hpp, source file

#include "loggers.hpp" // Module header

namespace worTech::betterCpp::loggers{

// #div: public methods

    // #func: log(std::string&), public const method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with no log level
    // #overload: log(std::string&, std::source_location&)
    // #overload: log(std::string&, time_t&)
    // #overload: log(std::string&, std::source_location&, time_t&)
    // #overload: log(std::string&&)
    // #overload: log(std::string&&, std::source_location&)
    // #overload: log(std::string&&, time_t&)
    // #overload: log(std::string&&, std::source_location&, time_t&)
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&, std::optional<std::source_location>, std::optional<time_t>)
    // #param: const std::string& p_message, message to log
    // #return: const Logger&, current Logger instance
    const Logger& Logger::log(const std::string& p_message)const{
        sendLog(formatLog<Level::NONE>(p_message, std::nullopt, std::nullopt));
        return *this; 
    }
    // #func: log(std::string&, std::source_location&), public const method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with no log level
    // #overload: log(std::string&)
    // #overload: log(std::string&, time_t&)
    // #overload: log(std::string&, std::source_location&, time_t&)
    // #overload: log(std::string&&)
    // #overload: log(std::string&&, std::source_location&)
    // #overload: log(std::string&&, time_t&)
    // #overload: log(std::string&&, std::source_location&, time_t&)
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&, std::optional<std::source_location>, std::optional<time_t>)
    // #param: const std::string& p_message, message to log
    // #param: const std::source_location& p_location, source location of the message
    // #return: const Logger&, current Logger instance
    const Logger& Logger::log(const std::string& p_message, const std::source_location& p_location)const{
        sendLog(formatLog<Level::NONE>(p_message, p_location, std::nullopt));
        return *this;
    }
    // #func: log(std::string&, time_t&), public const method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with no log level
    // #overload: log(std::string&)
    // #overload: log(std::string&, std::source_location&)
    // #overload: log(std::string&, std::source_location&, time_t&)
    // #overload: log(std::string&&)
    // #overload: log(std::string&&, std::source_location&)
    // #overload: log(std::string&&, time_t&)
    // #overload: log(std::string&&, std::source_location&, time_t&)
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&, std::optional<std::source_location>, std::optional<time_t>)
    // #param: const std::string& p_message, message to log
    // #param: const time_t& p_time, time of the message
    // #return: const Logger&, current Logger instance
    const Logger& Logger::log(const std::string& p_message, const time_t& p_time)const{
        sendLog(formatLog<Level::NONE>(p_message, std::nullopt, p_time));
        return *this;
    }
    // #func: log(std::string&, std::source_location&, time_t&), public const method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with no log level
    // #overload: log(std::string&)
    // #overload: log(std::string&, std::source_location&)
    // #overload: log(std::string&, time_t&)
    // #overload: log(std::string&&)
    // #overload: log(std::string&&, std::source_location&)
    // #overload: log(std::string&&, time_t&)
    // #overload: log(std::string&&, std::source_location&, time_t&)
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&, std::optional<std::source_location>, std::optional<time_t>)
    // #param: const std::string& p_message, message to log
    // #param: const std::source_location& p_location, source location of the message
    // #param: const time_t& p_time, time of the message
    // #return: const Logger&, current Logger instance
    const Logger& Logger::log(const std::string& p_message, const std::source_location& p_location, const time_t& p_time)const{
        sendLog(formatLog<Level::NONE>(p_message, p_location, p_time));
        return *this;
    }
    // #func: log(std::string&&), public const method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with no log level
    // #note: takes ownership of the message
    // #overload: log(std::string&)
    // #overload: log(std::string&, std::source_location&)
    // #overload: log(std::string&, time_t&)
    // #overload: log(std::string&, std::source_location&, time_t&)
    // #overload: log(std::string&&, std::source_location&)
    // #overload: log(std::string&&, time_t&)
    // #overload: log(std::string&&, std::source_location&, time_t&)
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&&, std::optional<std::source_location>, std::optional<time_t>)
    // #param: std::string&& p_message, message to log
    // #return: const Logger&, current Logger instance
    const Logger& Logger::log(std::string&& p_message)const{
        sendLog(formatLog<Level::NONE>(std::forward<std::string>(p_message), std::nullopt, std::nullopt));
        return *this;
    }
    // #func: log(std::string&&, std::source_location&), public const method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with no log level
    // #note: takes ownership of the message
    // #overload: log(std::string&)
    // #overload: log(std::string&, std::source_location&)
    // #overload: log(std::string&, time_t&)
    // #overload: log(std::string&, std::source_location&, time_t&)
    // #overload: log(std::string&&)
    // #overload: log(std::string&&, time_t&)
    // #overload: log(std::string&&, std::source_location&, time_t&)
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&&, std::optional<std::source_location>, std::optional<time_t>)
    // #param: std::string&& p_message, message to log
    // #param: const std::source_location& p_location, source location of the message
    // #return: const Logger&, current Logger instance
    const Logger& Logger::log(std::string&& p_message, const std::source_location& p_location)const{
        sendLog(formatLog<Level::NONE>(std::forward<std::string>(p_message), p_location, std::nullopt));
        return *this;
    }
    // #func: log(std::string&&, time_t&), public const method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with no log level
    // #note: takes ownership of the message
    // #overload: log(std::string&)
    // #overload: log(std::string&, std::source_location&)
    // #overload: log(std::string&, time_t&)
    // #overload: log(std::string&, std::source_location&, time_t&)
    // #overload: log(std::string&&)
    // #overload: log(std::string&&, std::source_location&)
    // #overload: log(std::string&&, std::source_location&, time_t&)
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&&, std::optional<std::source_location>, std::optional<time_t>)
    // #param: std::string&& p_message, message to log
    // #param: const time_t& p_time, time of the message
    // #return: const Logger&, current Logger instance
    const Logger& Logger::log(std::string&& p_message, const time_t& p_time)const{
        sendLog(formatLog<Level::NONE>(std::forward<std::string>(p_message), std::nullopt, p_time));
        return *this;
    }
    // #func: log(std::string&&, std::source_location&, time_t&), public const method
    // #scope: Logger, abstract singleton class
    // #info: logs a message with no log level
    // #note: takes ownership of the message
    // #overload: log(std::string&)
    // #overload: log(std::string&, std::source_location&)
    // #overload: log(std::string&, time_t&)
    // #overload: log(std::string&, std::source_location&, time_t&)
    // #overload: log(std::string&&)
    // #overload: log(std::string&&, std::source_location&)
    // #overload: log(std::string&&, time_t&)
    // #calls: sendLog(std::string&&)
    // #calls: formatLog<Level>(std::string&&, std::optional<std::source_location>, std::optional<time_t>)
    // #param: std::string&& p_message, message to log
    // #param: const std::source_location& p_location, source location of the message
    // #param: const time_t& p_time, time of the message
    // #return: const Logger&, current Logger instance
    const Logger& Logger::log(std::string&& p_message, const std::source_location& p_location, const time_t& p_time)const{
        sendLog(formatLog<Level::NONE>(std::forward<std::string>(p_message), p_location, p_time));
        return *this;
    }

// #div: protected factory methods

    // #func: Logger(std::string&), protected constructor
    // #info: constucts a Logger given a name
    // #overload: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&)
    // #overload: Logger(std::string&, bool)
    // #overload: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&, bool)
    // #overload: Logger(std::string&&)
    // #overload: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&)
    // #overload: Logger(std::string&&, bool)
    // #overload: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&, bool)
    // #param: const std::string& p_name, name of the Logger
    Logger::Logger(const std::string& p_name): m_name(p_name){}
    // #func: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&), protected constructor
    // #info: constucts a Logger given a name and a format order
    // #overload: Logger(std::string&)
    // #overload: Logger(std::string&, bool)
    // #overload: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&, bool)
    // #overload: Logger(std::string&&)
    // #overload: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&)
    // #overload: Logger(std::string&&, bool)
    // #overload: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&, bool)
    // #uses: FormatType, uint8_t enum class
    // #uses: logFormatting, variable namespace
    // #param: const std::string& p_name, name of the Logger
    // #param: const std::array<Format, log::FORMAT_SIZE>& p_formatOrder, log format order
    Logger::Logger(const std::string& p_name, const std::array<Format, log::FORMAT_SIZE>& p_formatOrder): m_name(p_name), 
        m_formatOrder(p_formatOrder){}
    // #func: Logger(std::string&, bool), protected constructor
    // #info: constucts a Logger given a name and a uses bold flag
    // #overload: Logger(std::string&)
    // #overload: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&)
    // #overload: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&, bool)
    // #overload: Logger(std::string&&)
    // #overload: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&)
    // #overload: Logger(std::string&&, bool)
    // #overload: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&, bool)
    // #param: const std::string& p_name, name of the Logger
    // #param: bool p_usesBold, uses bold flag
    Logger::Logger(const std::string& p_name, bool p_usesBold): m_name(p_name), m_usesBold(p_usesBold){}
    // #func: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&, bool), protected constructor
    // #info: constucts a Logger given a name, a format order, and a uses bold flag
    // #overload: Logger(std::string&)
    // #overload: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&)
    // #overload: Logger(std::string&, bool)
    // #overload: Logger(std::string&&)
    // #overload: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&)
    // #overload: Logger(std::string&&, bool)
    // #overload: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&, bool)
    // #uses: FormatType, uint8_t enum class
    // #uses: logFormatting, variable namespace
    // #param: const std::string& p_name, name of the Logger
    // #param: const std::array<Format, log::FORMAT_SIZE>& p_formatOrder, log format order
    // #param: bool p_usesBold, uses bold flag
    Logger::Logger(const std::string& p_name, const std::array<Format, log::FORMAT_SIZE>& p_formatOrder, bool p_usesBold): m_name(p_name),
    m_formatOrder(p_formatOrder){}
    // #func: Logger(std::string&&), protected constructor
    // #info: constucts a Logger given a name
    // #note: takes ownership of the name
    // #overload: Logger(std::string&)
    // #overload: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&)
    // #overload: Logger(std::string&, bool)
    // #overload: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&, bool)
    // #overload: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&)
    // #overload: Logger(std::string&&, bool)
    // #overload: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&, bool)
    // #param: std::string&& p_name, name of the Logger
    Logger::Logger(std::string&& p_name): m_name(std::forward<std::string>(p_name)){}
    // #func: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&), protected constructor
    // #info: constucts a Logger given a name and a format order
    // #note: takes ownership of the name
    // #overload: Logger(std::string&)
    // #overload: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&)
    // #overload: Logger(std::string&, bool)
    // #overload: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&, bool)
    // #overload: Logger(std::string&&)
    // #overload: Logger(std::string&&, bool)
    // #overload: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&, bool)
    // #uses: FormatType, uint8_t enum class
    // #uses: logFormatting, variable namespace
    // #param: std::string&& p_name, name of the Logger
    // #param: const std::array<Format, log::FORMAT_SIZE>& p_formatOrder, log format order
    Logger::Logger(std::string&& p_name, const std::array<Format, log::FORMAT_SIZE>& p_formatOrder): m_name(std::forward<std::string>(p_name)),
        m_formatOrder(p_formatOrder){}
    // #func: Logger(std::string&&, bool), protected constructor
    // #info: constucts a Logger given a name and a uses bold flag
    // #note: takes ownership of the name
    // #overload: Logger(std::string&)
    // #overload: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&)
    // #overload: Logger(std::string&, bool)
    // #overload: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&, bool)
    // #overload: Logger(std::string&&)
    // #overload: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&)
    // #overload: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&, bool)
    // #param: std::string&& p_name, name of the Logger
    // #param: bool p_usesBold, uses bold flag
    Logger::Logger(std::string&& p_name, bool p_usesBold): m_name(std::forward<std::string>(p_name)), m_usesBold(p_usesBold){}
    // #func: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&, bool), protected constructor
    // #info: constucts a Logger given a name, a format order, and a uses bold flag
    // #note: takes ownership of the name
    // #overload: Logger(std::string&)
    // #overload: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&)
    // #overload: Logger(std::string&, bool)
    // #overload: Logger(std::string&, std::array<Format, log::FORMAT_SIZE>&, bool)
    // #overload: Logger(std::string&&)
    // #overload: Logger(std::string&&, std::array<Format, log::FORMAT_SIZE>&)
    // #overload: Logger(std::string&&, bool)
    // #uses: FormatType, uint8_t enum class
    // #uses: logFormatting, variable namespace
    // #param: std::string&& p_name, name of the Logger
    // #param: const std::array<Format, log::FORMAT_SIZE>& p_formatOrder, log format order
    // #param: bool p_usesBold, uses bold flag
    Logger::Logger(std::string&& p_name, const std::array<Format, log::FORMAT_SIZE>& p_formatOrder, bool p_usesBold): 
        m_name(std::forward<std::string>(p_name)), m_formatOrder(p_formatOrder), m_usesBold(p_usesBold){}

// #div: protected methods

    // #func: sendLog(std::string&&), protected const virtual method
    // #scope: Logger, abstract singleton class
    // #info: pushes a log to the log stack
    // #note: takes ownership of the log
    // #note: can be overriden to change what LogStack to use
    // #uses: LogStack, abstarct singleton class
    // #uses: AutoFlush, singleton class
    // #calls: LogStack::get<T_derived>()
    // #calls: LogStack::pushLog(std::string&&)
    // #param: std::string&& p_log, log to push
    // #return: const Logger&, current Logger instance
    const Logger& Logger::sendLog(std::string&& p_log)const{
        LogStack::get<AutoFlush>().pushLog(std::forward<std::string>(p_log));
        return *this;
    }
    // #func: formatLogger(Level), protected const virtual method
    // #scope: Logger, abstract singleton class
    // #info: formats the logger name
    // #note: can be overriden to change how the logger name is formatted
    // #note: relies on RVO to avoid copy
    // #uses: Level, uint8_t enum class
    // #uses: logFormatting, variable namespace
    // #uses: ansiiColorCodes, variable namespace
    // #calls: getLogColor(Level)
    // #param: const Level p_logLevel, log level of the message
    // #return: std::string, formatted logger name
    // #detail: formats the logger name sorrounded by the specified beguin and end characters all wrapped in the Level specific color then 
    // returns it
    std::string Logger::formatLogger(const Level p_logLevel)const{
        return getLogColor(p_logLevel) + log::LOGGER_BEGIN + m_name + log::LOGGER_END + log::SPACE + ansii::RESET;
    }
    // #func: formatLevel(Level), protected const virtual method
    // #scope: Logger, abstract singleton class
    // #info: formats the log level conditionally using bold
    // #note: can be overriden to change how the log level is formatted
    // #note: relies on RVO to avoid copy
    // #uses: Level, uint8_t enum class
    // #uses: logFormatting, variable namespace
    // #uses: ansiiColorCodes, variable namespace
    // #calls: getLogColor(Level) or getLogColorBold(Level)
    // #param: const Level p_logLevel, log level to format
    // #return: std::string, formatted log level
    // #detail: formats the log level sorrounded by the specified beguin and end characters all wrapped in the Level specific color and 
    // conditionally using bold then returns it
    std::string Logger::formatLevel(const Level p_logLevel)const{
        if(m_usesBold){
            return getLogColorBold(p_logLevel) + getLogLevelName(p_logLevel) + log::LEVEL_END + log::SPACE + ansii::RESET;
        }else{
            return getLogColor(p_logLevel) + getLogLevelName(p_logLevel) + log::LEVEL_END + log::SPACE + ansii::RESET;
        }
    }
    // #func: formatTime(Level, time_t), protected const virtual method
    // #scope: Logger, abstract singleton class
    // #info: formats the time
    // #note: can be overriden to change how the time is formatted
    // #note: relies on RVO to avoid copy
    // #uses: Level, uint8_t enum class
    // #uses: logFormatting, variable namespace
    // #uses: ansiiColorCodes, variable namespace
    // #calls: getLogColor(Level)
    // #param: const Level p_logLevel, log level of the message
    // #param: const time_t& p_time, time to format
    // #return: std::string, formatted time
    // #detail: formats the time sorrounded by the specified beguin and end characters all wrapped in the Level specific color formating the 
    // time_t into a hh:mm:ss format then returns it
    std::string Logger::formatTime(const Level p_logLevel, const time_t& p_time)const{
        std::tm* time = std::localtime(&p_time);
        return getLogColor(p_logLevel) + log::TIME_BEGIN + std::to_string(time->tm_hour) + log::TIME_SPACE + ((time->tm_min < 10)? "0": "") 
            + std::to_string(time->tm_min) + log::TIME_SPACE + ((time->tm_sec < 10)? "0": "") + std::to_string(time->tm_sec) + log::TIME_END 
            + log::SPACE + ansii::RESET;
    }
    // #func: formatMessage(Level, std::string&), protected const virtual method
    // #scope: Logger, abstract singleton class
    // #info: formats the message
    // #note: can be overriden to change how the message is formatted
    // #note: relies on RVO to avoid copy
    // #uses: Level, uint8_t enum class
    // #uses: logFormatting, variable namespace
    // #uses: ansiiColorCodes, variable namespace
    // #calls: getLogColor(Level)
    // #param: const Level p_logLevel, log level of the message
    // #param: const std::string& p_message, message to format
    // #return: std::string, formatted message
    // #detail: formats the message wrapped in the Level specific color then returns it
    std::string Logger::formatMessage(const Level p_logLevel, const std::string& p_message)const{
        return getLogColor(p_logLevel) + p_message + log::SPACE + ansii::RESET;
    }
    // #func: formatMessage(Level, std::string&&), protected const virtual method
    // #scope: Logger, abstract singleton class
    // #info: formats the message
    // #note: takes ownership of the message
    // #note: can be overriden to change how the message is formatted
    // #note: relies on RVO to avoid copy
    // #uses: Level, uint8_t enum class
    // #uses: logFormatting, variable namespace
    // #uses: ansiiColorCodes, variable namespace
    // #calls: getLogColor(Level)
    // #param: const Level p_logLevel, log level of the message
    // #param: std::string&& p_message, message to format
    // #return: std::string, formatted message
    // #detail: formats the message wrapped in the Level specific color then returns it
    std::string Logger::formatMessage(const Level p_logLevel, std::string&& p_message)const{
        return getLogColor(p_logLevel) + std::forward<std::string>(p_message) + log::SPACE + ansii::RESET;
    }
    // #func: formatLocation(Level, std::source_location&), protected const virtual method
    // #scope: Logger, abstract singleton class
    // #info: formats the location 
    // #note: can be overriden to change how the location is formatted
    // #note: relies on RVO to avoid copy
    // #uses: Level, uint8_t enum class
    // #uses: logFormatting, variable namespace
    // #uses: ansiiColorCodes, variable namespace
    // #calls: getLogColor(Level)
    // #param: const Level p_logLevel, log level of the message
    // #param: const std::source_location& p_location, location to format
    // #return: std::string, formatted location
    // #detail: formats the location starting with the line number followed by the function name and file name all wrapped in the Level
    // specific color then returns it
    std::string Logger::formatLocation(const Level p_logLevel, const std::source_location& p_location)const{
        return getLogColor(p_logLevel) + log::LINE_BEGIN + log::SPACE + std::to_string(p_location.line()) 
            + log::SPACE + p_location.function_name() + log::SPACE + p_location.file_name() + log::SPACE + ansii::RESET;
    }
    // #func: getLogColor(Level), protected const virtual method
    // #scope: Logger, abstract singleton class
    // #info: gets the color of the log level
    // #note: can be overriden to change how the log level color is determined
    // #note: relies on RVO to avoid copy
    // #uses: Level, uint8_t enum class
    // #uses: logFormatting, variable namespace
    // #param: Level p_logLevel, log level to get color for
    // #return: std::string, color of the log level
    std::string Logger::getLogColor(Level p_logLevel)const{
        return log::LEVEL_COLOR.at(p_logLevel);
    }
    // #func: getLogColorBold(Level), protected cosnt virtual method
    // #scope: Logger, abstract singleton class
    // #info: gets the bold color of the log level
    // #note: can be overriden to change how the log level bold color is determined
    // #note: relies on RVO to avoid copy
    // #uses: Level, uint8_t enum class
    // #uses: logFormatting, variable namespace
    // #param: Level p_logLevel, log level to get color for
    // #return: std::string, bold color of the log level
    std::string Logger::getLogColorBold(const Level p_logLevel)const{
        return log::LEVEL_COLOR_BOLD.at(p_logLevel);
    }
    // #func: getLogLevelName(Level), protected const virtual method
    // #scope: Logger, abstract singleton class
    // #info: gets the name of the log level
    // #note: can be overriden to change how the log level name is determined
    // #note: relies on RVO to avoid copy
    // #uses: Level, uint8_t enum class
    // #uses: logFormatting, variable namespace
    // #param: Level p_logLevel, log level to get name for
    // #return: std::string, name of the log level
    std::string Logger::getLogLevelName(Level p_logLevel)const{
        return log::LEVEL_NAME.at(p_logLevel);
    }
    
} // namespace worTech::betterLogger::loggers