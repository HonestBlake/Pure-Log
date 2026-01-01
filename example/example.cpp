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
    FileLogger& debugger = FileLogger::get();
    for(int i: std::views::iota(0, 1)){
        debugger.error("Invalid value passed to parser: {}", 3).time();
        debugger.warn("This is a warning message.").location();
        debugger.info("Informational message without additional data.");
        debugger.debug("Debugging value: {}", 42);
        debugger.critical("Critical error encountered! System will shut down.").time().location();
    }
    return 0;
}