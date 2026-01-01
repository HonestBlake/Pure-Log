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

int main(){
    Debugger& debugger = Debugger::get();
    for(int i: std::views::iota(0, 1)){
        debugger.error("Invalid value passed to parser: {}", 3).time();
        debugger.warn("This is a warning message.").location();
        debugger.info("Informational message without additional data.");
        debugger.debug("Debugging value: {}", 42);
        debugger.critical("Critical error encountered! System will shut down.").time().location();
    }
    return 0;
}