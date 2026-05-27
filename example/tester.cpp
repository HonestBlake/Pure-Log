#include "better/logger.hpp"

class TestLogger: public btr::Logger{
public:
    TestLogger(): Logger("Test", false){}
private:
    const Logger& sendLog(std::string&& p_log)const override{
        btr::LogStack::get<btr::TerminateFlush>().pushLog(std::forward<std::string>(p_log));
        return *this;
    }
};

class TestDebugLogger: public btr::Logger{
public:
    TestDebugLogger(): Logger("TestDebug", {btr::Format::TIME, btr::Format::LOGGER, btr::Format::LEVEL, btr::Format::MESSAGE, 
        btr::Format::LOCATION}){}
private:
    const Logger& sendLog(std::string&& p_log)const override{
        btr::LogStack::get<btr::AutoFlush>().pushLog(std::forward<std::string>(p_log));
        return *this;
    }
};

int main(){
    std::string test = "test log on built in main logger";

    btr::Logger::get<btr::Main>().log(test);
    btr::Logger::get<btr::Debug>().log<btr::Level::ERROR>("test log on built in debug logger");
    btr::Logger::get<TestDebugLogger>().log<btr::Level::INFO>("test log on custom debug logger", btr::Help::getCurrentTime());
    btr::Logger::get<TestDebugLogger>().log<btr::Level::TRACE>("test log on custom debug logger", std::source_location::current());
    btr::Logger::get<TestLogger>().log<btr::Level::WARNING>("test log on custom logger with end flush");
    btr::Logger::get<TestLogger>().log<btr::Level::ERROR>("test log on custom logger with end flush", std::source_location::current(), btr::Help::getCurrentTime());
    btr::Logger::get<TestDebugLogger>().log<btr::Level::CRITICAL>("test log on custom debug logger", std::source_location::current());

    return EXIT_SUCCESS;
}


class DebugLogger: public pureLog::Logger<pureLog::CStdPrintfOutputStream>{

};

int main(){
    pureLog::Logger& logger = pureLog::Logger::get<DebugLogger>();

// --------------------------------------------------------------------------------------------------------------
    pureLog::Logger& logger = pureLog::Logger::get<DebugLogger>();
    logger.log("This is a test log message.").time().location();
    logger.flush();
    logger.warn("This is a test warning message.");
    logger.error("This is a test error message.");
    logger.debug("This is a test debug message.");
    logger.critical("This is a test critical message.");
    logger.info("This is a test info message.");
    logger.trace("This is a test trace message.");
    logger.fatal("This is a test fatal message.");
    logger.log("This is another test log {} with a placeholder.", 42).time();
    logger.error("This is another test error {} with a placeholder.", "error").time().location();
    return 0;
}