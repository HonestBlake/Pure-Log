// #FILE: logger.hpp, Module Header File

#pragma once

#include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
#include "log.hpp" // #INCLUDE: log.hpp, Module Header File
#include "outputStream.hpp" // #INCLUDE: outputStream.hpp, Module Header File
#include "consoleOut.hpp" // #INCLUDE: consoleOut.hpp, Module Header File
#include "formatting.hpp" // #INCLUDE: formatting.hpp, Module Header File

namespace pureLog::logger{ // #scope: pureLog::logger

    using DefaultOutputStream = StdCout<OutputStream::UNBUFFERED>;
    
    // #CONCEPT: LoggerDerived, Type Concept
    template<class Type, bool t_usingLevelFormatting, bool t_usingColors> concept LoggerDerived = std::is_base_of_v<Logger<Type, t_usingLevelFormatting, t_usingColors>, Type>;
    // #END: LoggerDerived

    // #CLASS: Logger<T_Derived>
    template<class T_Derived, bool t_usingLevelFormatting, bool t_usingColors> class Logger{
    public:
    // Public Factory Methods
        Logger(const Logger&) = delete; // #DELETE: Logger(const Logger&), Deleted Copy Constructor
        Logger(Logger&&) = delete; // #DELETE: Logger(Logger&&), Deleted Move Constructor
        virtual ~Logger();
    // Public Operators
        Logger& operator=(const Logger&) = delete; // #DELETE: operator=(const Logger&), Deleted Copy Assignment Operator
        Logger& operator=(Logger&&) = delete; // #DELETE: operator=(Logger&&), Deleted Move Assignment Operator
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
        T_Derived& formatting(const Formatting& p_formatting);
        T_Derived& formatting(Formatting&& p_formatting);
        T_Derived& nameFormat(const std::string& p_name);
        T_Derived& nameFormat(std::string&& p_name);
        T_Derived& levelFormat(const std::string& p_level);
        T_Derived& levelFormat(std::string&& p_level);
        T_Derived& messageFormat(const std::string& p_message);
        T_Derived& messageFormat(std::string&& p_message);
        T_Derived& timeFormat(const std::string& p_time);
        T_Derived& timeFormat(std::string&& p_time);
        T_Derived& locationFormat(const std::string& p_location);
        T_Derived& locationFormat(std::string&& p_location);
        T_Derived& orderFormat(const std::array<Formatting::Type, Formatting::COUNT>& p_order);
        T_Derived& orderFormat(const std::initializer_list<Formatting::Type> p_order);
        // Level format setters
        T_Derived& levelSpecificFormatting(const std::variant<Log::Level, std::string>& p_level, const Formatting& p_formatting);
        T_Derived& levelSpecificFormatting(const std::variant<Log::Level, std::string>& p_level, Formatting&& p_formatting); 
        T_Derived& levelSpecificNameFormat(const std::variant<Log::Level, std::string>& p_level, const std::string& p_name);
        T_Derived& levelSpecificNameFormat(const std::variant<Log::Level, std::string>& p_level, std::string&& p_name);
        T_Derived& levelSpecificLevelFormat(const std::variant<Log::Level, std::string>& p_level, const std::string& p_levelFormat);
        T_Derived& levelSpecificLevelFormat(const std::variant<Log::Level, std::string>& p_level, std::string&& p_levelFormat);
        T_Derived& levelSpecificMessageFormat(const std::variant<Log::Level, std::string>& p_level, const std::string& p_message);
        T_Derived& levelSpecificMessageFormat(const std::variant<Log::Level, std::string>& p_level, std::string&& p_message);
        T_Derived& levelSpecificTimeFormat(const std::variant<Log::Level, std::string>& p_level, const std::string& p_time);
        T_Derived& levelSpecificTimeFormat(const std::variant<Log::Level, std::string>& p_level, std::string&& p_time);
        T_Derived& levelSpecificLocationFormat(const std::variant<Log::Level, std::string>& p_level, const std::string& p_location);
        T_Derived& levelSpecificLocationFormat(const std::variant<Log::Level, std::string>& p_level, std::string&& p_location);
        T_Derived& levelSpecificOrderFormat(const std::variant<Log::Level, std::string>& p_level, const std::array<Formatting::Type, Formatting::COUNT>& p_order);
        T_Derived& levelSpecificOrderFormat(const std::variant<Log::Level, std::string>& p_level, const std::initializer_list<Formatting::Type> p_order);
        // Color setters
        T_Derived& coloring(const Coloring& p_coloring);
        T_Derived& coloring(Coloring&& p_coloring);
        T_Derived& logColor(const Color p_color);
        T_Derived& nameColor(const Color p_color);
        T_Derived& levelColor(const Color p_color);
        T_Derived& messageColor(const Color p_color);
        T_Derived& timeColor(const Color p_color);
        T_Derived& locationColor(const Color p_color);
        // Level color setters
        T_Derived& levelSpecificColoring(const std::variant<Log::Level, std::string>& p_level, const Coloring& p_coloring);
        T_Derived& levelSpecificColoring(const std::variant<Log::Level, std::string>& p_level, Coloring&& p_coloring);
        T_Derived& levelSpecificLogColor(const std::variant<Log::Level, std::string>& p_level, const Color p_color);
        T_Derived& levelSpecificNameColor(const std::variant<Log::Level, std::string>& p_level, const Color p_color);
        T_Derived& levelSpecificLevelColor(const std::variant<Log::Level, std::string>& p_level, const Color p_color);
        T_Derived& levelSpecificMessageColor(const std::variant<Log::Level, std::string>& p_level, const Color p_color);
        T_Derived& levelSpecificTimeColor(const std::variant<Log::Level, std::string>& p_level, const Color p_color);
        T_Derived& levelSpecificLocationColor(const std::variant<Log::Level, std::string>& p_level, const Color p_color);
        // Setters
        T_Derived& name(const std::string& p_name);
        T_Derived& name(std::string&& p_name);
        T_Derived& outputStream(OutputStream& p_outputStream);
        // Getters
        [[nodiscard]] constexpr bool usingLevelFormatting()const;
        [[nodiscard]] constexpr bool usingColors()const;
        [[nodiscard]] const Formatting& formatting()const;
        [[nodiscard]] const std::unordered_map<std::variant<Log::Level, std::string>, Formatting>& levelSpecificFormatting()const;
        [[nodiscard]] const Coloring& coloring()const;
        [[nodiscard]] const std::unordered_map<std::variant<Log::Level, std::string>, Coloring>& levelSpecificColoring()const;
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
        std::string getFormattedPart(const Formatting::Type p_format, const Log& p_log);
        virtual std::string getFormattedName(const std::variant<Log::Level, std::string>& p_level, const std::string& p_name);
        virtual std::string getFormattedMessage(const std::variant<Log::Level, std::string>& p_level, const std::string& p_message);
        virtual std::string getFormattedLevel(const std::variant<Log::Level, std::string>& p_level);
        virtual std::string getFormattedTime(const std::variant<Log::Level, std::string>& p_level, const std_TimePoint& p_time);
        virtual std::string getFormattedLocation(const std::variant<Log::Level, std::string>& p_level, const std::source_location& p_location);
        // Color Helpers
        std::string getLogColorCode(const std::variant<Log::Level, std::string>& p_level);
        std::string getPartColorCode(const std::variant<Log::Level, std::string>& p_level, const Formatting::Type p_format);
        std::string getColoredLog(const std::variant<Log::Level, std::string>& p_level, std::string&& p_log);
        std::string getColoredPart(const std::variant<Log::Level, std::string>& p_level, const Formatting::Type p_format, std::string&& p_part);
    // Protected Members
        std::string m_name;
        Formatting m_formatting;
        std::unordered_map<std::variant<Log::Level, std::string>, Formatting> m_levelSpecificFormatting;
        Coloring m_coloring;
        std::unordered_map<std::variant<Log::Level, std::string>, Coloring> m_levelSpecificColoring;
        std::optional<Log> m_bufferedLog;
        OutputStream& m_outputStream;
    }; // #END: Logger

} // #END: pureLog::logger

#include "logger.tpp" // #INCLUDE: logger.tpp, Module Template Implementation File