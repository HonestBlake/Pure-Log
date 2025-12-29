// #file: logger.hpp, header file

#pragma once

#include "betterLogger.hpp" // Project header
#include "defaultLogStacks.hpp" // Built-in log stacks
#include "formats.hpp" // Logger formats

namespace worTech::betterCpp::loggers{
    
    // #namespace: defaultFormats, variable namespace
    namespace defaultFormats{
        inline constexpr std::array<Format, log::FORMAT_SIZE> FORMAT_ORDER = {
            Format::LOGGER,
            Format::TIME,
            Format::LEVEL,
            Format::MESSAGE,
            Format::LOCATION
        };
        inline constexpr bool USES_BOLD = true;
    } // #end: defaultFormats

    // #class: Logger, abstract singleton class
    class Logger{
    public:
    // public factory methods
        virtual ~Logger() = default;
    // public static methods
        template<class T_derived> static Logger& get();
    // public methods
        const Logger& log(const std::string& p_message)const;
        const Logger& log(const std::string& p_message, const std::source_location& p_location)const;
        const Logger& log(const std::string& p_message, const time_t& p_time)const;
        const Logger& log(const std::string& p_message, const std::source_location& p_location, const time_t& p_time)const;
        const Logger& log(std::string&& p_message)const;
        const Logger& log(std::string&& p_message, const std::source_location& p_location)const;
        const Logger& log(std::string&& p_message, const time_t& p_time)const;
        const Logger& log(std::string&& p_message, const std::source_location& p_location, const time_t& p_time)const;
        template<Level t_logLevel> const Logger& log(const std::string& p_message)const;
        template<Level t_logLevel> const Logger& log(const std::string& p_message, const std::source_location& p_location)const;
        template<Level t_logLevel> const Logger& log(const std::string& p_message, const time_t& p_time)const;
        template<Level t_logLevel> const Logger& log(const std::string& p_message, const std::source_location& p_location, const time_t& p_time)const;
        template<Level t_logLevel> const Logger& log(std::string&& p_message)const;
        template<Level t_logLevel> const Logger& log(std::string&& p_message, const std::source_location& p_location)const;
        template<Level t_logLevel> const Logger& log(std::string&& p_message, const time_t& p_time)const;
        template<Level t_logLevel> const Logger& log(std::string&& p_message, const std::source_location& p_location, const time_t& p_time)const;
    protected:
    // protected factory methods
        Logger(const std::string& p_name);
        Logger(const std::string& p_name, const std::array<Format, log::FORMAT_SIZE>& p_formatOrder);
        Logger(const std::string& p_name, bool p_usesBold);
        Logger(const std::string& p_name, const std::array<Format, log::FORMAT_SIZE>& p_formatOrder, bool p_usesBold);
        Logger(std::string&& p_name);
        Logger(std::string&& p_name, const std::array<Format, log::FORMAT_SIZE>& p_formatOrder);
        Logger(std::string&& p_name, bool p_usesBold);
        Logger(std::string&& p_name, const std::array<Format, log::FORMAT_SIZE>& p_formatOrder, bool p_usesBold);
        Logger(const Logger&) = delete;
        Logger(Logger&&) = delete;
    // protected operators
        Logger& operator=(const Logger&) = delete;
        Logger& operator=(Logger&&) = delete;
    // protected members
        std::string m_name;
        std::array<Format, log::FORMAT_SIZE> m_formatOrder = deflt::FORMAT_ORDER;
        bool m_usesBold = deflt::USES_BOLD;
    // protected methods
        virtual const Logger& sendLog(std::string&& p_log)const;
        virtual std::string formatLogger(const Level p_logLevel)const;
        virtual std::string formatLevel(const Level p_logLevel)const;
        virtual std::string formatTime(const Level p_logLevel, const time_t& p_time)const;
        virtual std::string formatMessage(const Level p_logLevel, const std::string& p_message)const;
        virtual std::string formatMessage(const Level p_logLevel, std::string&& p_message)const;
        virtual std::string formatLocation(const Level p_logLevel, const std::source_location& p_location)const;
        virtual std::string getLogColor(const Level p_logLevel)const;
        virtual std::string getLogColorBold(const Level p_logLevel)const;
        virtual std::string getLogLevelName(const Level p_logLevel)const;
        template<Level t_logLevel> std::string formatLog(const std::string& p_message, const std::optional<std::source_location> p_location, const std::optional<time_t> p_time)const;
        template<Level t_logLevel> std::string formatLog(std::string&& p_message, const std::optional<std::source_location> p_location, const std::optional<time_t> p_time)const;
    }; // #end: Logger
    
} // namespace worTech::betterCpp::loggers

#include "loggers.tpp" // Template implementations