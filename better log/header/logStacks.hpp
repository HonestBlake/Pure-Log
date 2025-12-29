// #file: logStack.hpp, header file

#pragma once

#include "betterLogger.hpp" // Project header

namespace worTech::betterCpp::logStacks{

    // #namespace: defaultFormats, variable namespace
    namespace defaultFormats{
        inline constexpr bool TERMINATE_FLUSH = false;
        inline constexpr bool INSTANT_FLUSH = true;
    } // #end: defaultFormats

    // #class: LogStack, abstract singleton class
    class LogStack{
    public:
    // public factory methods
        virtual ~LogStack() = 0;
    // public static methods
        template<class T_derived> static LogStack& get();
    // public methods
        LogStack& pushLog(const std::string& p_log);
        LogStack& pushLog(std::string&& p_log);
        LogStack& flush();
    protected:
    // protected factory methods
        LogStack() = default;
        LogStack(bool p_terminateFlush, bool p_instantFlush);
        LogStack(const LogStack&) = delete;
        LogStack(LogStack&&) = delete;
    // protected operators
        LogStack& operator=(const LogStack&) = delete;
        LogStack& operator=(LogStack&&) = delete;
    // protected members
        std::vector<std::string> m_logBuffer;
        bool m_terminateFlush = deflt::TERMINATE_FLUSH;
        bool m_instantFlush = deflt::INSTANT_FLUSH;
    // protected methods
        virtual void recordLog(std::string&& p_log);
    }; // #end: LogStack

} // namespace worTech::betterLogger::logStacks

#include "logStack.tpp" // template implementation