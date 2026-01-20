#include <pureLog/pureLog.hpp>

class Output: public pureLog::BufferedOutputStream{
    friend Output& pureLog::OutputStream::get<Output>();
private:
    Output(): pureLog::BufferedOutputStream(){}

    void write(const std::string& p_log)override{
        std::cout << p_log;
    }
};


class Debugger: public pureLog::Logger<Debugger>{
    friend class pureLog::Logger<Debugger>;
private:
    Debugger(): pureLog::Logger<Debugger>("Debugger", pureLog::OutputStream::get<pureLog::StdCout<pureLog::OutputStream::BUFFERED>>()){
    }
public:
    Debugger& special(){
        initiateLog("Special", "This is a special log message!");
        return *this;
    }
};

class File: public pureLog::FileOut<pureLog::OutputStream::UNBUFFERED>{
    friend File& pureLog::OutputStream::get<File>();
private:
    File(): pureLog::FileOut<pureLog::OutputStream::UNBUFFERED>(std::filesystem::path("log.txt")){
    }
};

class FileLogger: public pureLog::Logger<FileLogger>{
    friend class pureLog::Logger<FileLogger>;
private:
    FileLogger(): pureLog::Logger<FileLogger>("FileLogger", pureLog::OutputStream::get<File>()){
        if(!pureLog::OutputStream::get<File>().isOpen()){
            throw std::runtime_error("Failed to open log file.");
        }
    }
};

int main(){
    Debugger& debugger = Debugger::get();
    // debugger.colorFormatWarnName();
    // debugger.formatNameColor(pureLog::Color::WHITE);
    // debugger.formatLogColor(pureLog::Color::BRIGHT_RED);
    // debugger.formatLocationColor(pureLog::Color::UNDERLINE_RED);
    // debugger.formatTimeColor(pureLog::Color::WHITE);
    // debugger.formatLevelColor(pureLog::Color::BOLD_RED);
    debugger.nameColor(pureLog::Color::BRIGHT_CYAN);
    debugger.levelSpecificLevelColor("Special", pureLog::Color::BRIGHT_PURPLE);
    debugger.levelSpecificMessageFormat("Special", "[SPECIAL LOG]: {}");
    debugger.levelSpecificLevelFormat("Special", "\"{}\"");
    debugger.levelSpecificLogColor("Special", pureLog::Color::BRIGHT_RED);
    debugger.levelSpecificLogColor(pureLog::Log::Level::WARN, pureLog::Color::YELLOW);
    debugger.levelSpecificLevelFormat(pureLog::Log::Level::TRACE, "");
    debugger.levelSpecificLogColor(pureLog::Log::Level::TRACE, pureLog::Color::BRIGHT_GREEN);

    for(int i: std::views::iota(0, 2)){
        debugger.log("Invalid value passed to parser: {}", 3).time();
        debugger.warn("This is a warning message.").location();
        debugger.info("Informational message without additional data.");
        debugger.debug("Debugging value: {}");
        debugger.critical("Critical error encountered! System will shut down.").time().location();
        debugger.special();
        debugger.trace("hi").location();
        debugger.flush().timeFormat("<{}:{}:{}:{}>");
    }

    return 0;
}