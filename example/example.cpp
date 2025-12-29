#include "consoleOut.hpp"
#include "pureLog.hpp"
#include <pureLog/pureLog.hpp>

class B{

};

class Output: public pureLog::OutputStream<Output>{
public:
    friend class pureLog::OutputStream<Output>;
    

private:

    Output(): pureLog::OutputStream<Output>(){

    }

    void write(const std::string& p_log)override{
        // Simple console output for demonstration
    }

};

class Logger1{ public:
    Logger1(){

    }

};
using StdCout  = pureLog::ConsoleOut<pureLog::OutputBuffering::UNBUFFERED, pureLog::ConsoleInterface::STD_COUT>;

class Debugger: public pureLog::Logger<Debugger, StdCout>{
public:
    friend class pureLog::Logger<Debugger, StdCout>;
private:
    Debugger(): pureLog::Logger<Debugger, StdCout>("Debugger"){

    }
};

int main(){
    Debugger& debugger = Debugger::get();
    debugger.debug("This is a debug {}.", "message").message(" Additional message content").location().time().send().flush();
    std::string msg = "Formatted number: {}";
    return 0;
}