// #FILE: logger.hpp, Module Header File

#pragma once

#include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
#include "log.hpp" // #INCLUDE: log.hpp, Module Header File
#include "outputStream.hpp" // #INCLUDE: outputStream.hpp, Module Header File
#include "consoleOut.hpp" // #INCLUDE: consoleOut.hpp, Module Header File
#include "formats.hpp" // #INCLUDE: formats.hpp, Module Header File
#include <string>

namespace pureLog::logger{ // #scope: pureLog::logger

    using DefaultOutputStream = StdCout<OutputStream::UNBUFFERED>;
    
    // #CONCEPT: LoggerDerived, Type Concept
    template<class Type> concept LoggerDerived = std::is_base_of_v<Logger<Type>, Type>;
    // #END: LoggerDerived

    // #CLASS: Logger<T_Derived>
    template<class T_Derived, bool t_usingLevelFormats, bool t_usingColors> class Logger{
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
        // Format setters
        T_Derived& format(const Format& p_format);
        T_Derived& format(Format&& p_format);
        T_Derived& formatName(const std::string& p_name);
        T_Derived& formatName(std::string&& p_name);
        T_Derived& formatLevel(const std::string& p_level);
        T_Derived& formatLevel(std::string&& p_level);
        T_Derived& formatMessage(const std::string& p_message);
        T_Derived& formatMessage(std::string&& p_message);
        T_Derived& formatTime(const std::string& p_time);
        T_Derived& formatTime(std::string&& p_time);
        T_Derived& formatLocation(const std::string& p_location);
        T_Derived& formatLocation(std::string&& p_location);
        T_Derived& formatOrder(const std::array<Format::Type, Format::COUNT>& p_order);
        T_Derived& formatOrder(const std::initializer_list<Format::Type> p_order);
        // Level format setters
        T_Derived& addLevelFormat(const std::variant<Log::Level, std::string>& p_level, const Format& p_format);
        T_Derived& addLevelFormat(const std::variant<Log::Level, std::string>& p_level, Format&& p_format); 
        T_Derived& addLevelFormatName(const std::variant<Log::Level, std::string>& p_level, const std::string& p_name);
        T_Derived& addLevelFormatName(const std::variant<Log::Level, std::string>& p_level, std::string&& p_name);
        T_Derived& addLevelFormatLevel(const std::variant<Log::Level, std::string>& p_level, const std::string& p_levelFormat);
        T_Derived& addLevelFormatLevel(const std::variant<Log::Level, std::string>& p_level, std::string&& p_levelFormat);
        T_Derived& addLevelFormatMessage(const std::variant<Log::Level, std::string>& p_level, const std::string& p_message);
        T_Derived& addLevelFormatMessage(const std::variant<Log::Level, std::string>& p_level, std::string&& p_message);
        T_Derived& addLevelFormatTime(const std::variant<Log::Level, std::string>& p_level, const std::string& p_time);
        T_Derived& addLevelFormatTime(const std::variant<Log::Level, std::string>& p_level, std::string&& p_time);
        T_Derived& addLevelFormatLocation(const std::variant<Log::Level, std::string>& p_level, const std::string& p_location);
        T_Derived& addLevelFormatLocation(const std::variant<Log::Level, std::string>& p_level, std::string&& p_location);
        T_Derived& addLevelFormatOrder(const std::variant<Log::Level, std::string>& p_level, const std::array<Format::Type, Format::COUNT>& p_order);
        T_Derived& addLevelFormatOrder(const std::variant<Log::Level, std::string>& p_level, const std::initializer_list<Format::Type> p_order);

        // Color setters
        // T_Derived& formatColor(const Format::TextColor& p_color);
        // T_Derived& formatColor(Format::TextColor&& p_color);
        T_Derived& formatLogColor(const Color p_color);
        T_Derived& formatNameColor(const Color p_color);
        T_Derived& formatLevelColor(const Color p_color);
        T_Derived& formatMessageColor(const Color p_color);
        T_Derived& formatTimeColor(const Color p_color);
        T_Derived& formatLocationColor(const Color p_color);
        // Setters
        T_Derived& name(const std::string& p_name);
        T_Derived& name(std::string&& p_name);
        T_Derived& outputStream(OutputStream& p_outputStream);
        // Getters
        [[nodiscard]] const Format& format()const;
        [[nodiscard]] const std::unordered_map<std::variant<Log::Level, std::string>, Format>& levelFormats()const;
        [[nodiscard]] const std::string& name()const;
    // Public Static Members
    protected:
    // Protected Factory Methods
        Logger(const std::string& p_name, OutputStream& p_outputStream = OutputStream::get<DefaultOutputStream>());
        Logger(std::string&& p_name, OutputStream& p_outputStream = OutputStream::get<DefaultOutputStream>());
    // Protected Methods
        void initiateLog(const std::variant<Log::Level, std::string> p_level);
        template<class... T_Args> void initiateLog(const std::variant<Log::Level, std::string> p_level, const std::string& p_message, T_Args... p_args);
        void initiateLog(const std::variant<Log::Level, std::string> p_level, std::string&& p_message); // NOTE: Overload without formatting arguments because std::vformat can't take a move so becomes useless if useing format args you must construct
        void flushBuffer();
        // Formatting Helpers
        std::string getFormattedLog(const Log& p_log);
        std::string getFormattedPart(const Format::Type p_format, const Log& p_log);
        virtual std::string getFormattedName(const std::variant<Log::Level, std::string>& p_level, const std::string& p_name);
        virtual std::string getFormattedMessage(const std::variant<Log::Level, std::string>& p_level, const std::string& p_message);
        virtual std::string getFormattedLevel(const std::variant<Log::Level, std::string>& p_level);
        virtual std::string getFormattedTime(const std::variant<Log::Level, std::string>& p_level, const std_TimePoint& p_time);
        virtual std::string getFormattedLocation(const std::variant<Log::Level, std::string>& p_level, const std::source_location& p_location);
        // Color Helpers
        std::string getColoredLog(const std::variant<Log::Level, std::string>& p_level, std::string&& p_log);
        std::string getColoredPart(const Format::Type p_format, std::string&& p_part);
    // Protected Members
        std::string m_name;
        Format m_format;
        std::unordered_map<std::variant<Log::Level, std::string>, Format> m_levelFormats;
        std::optional<Log> m_bufferedLog;
        OutputStream& m_outputStream;
    }; // #END: Logger

} // #END: pureLog::logger

#include "logger.tpp" // #INCLUDE: logger.tpp, Module Template Implementation File