// #file: 

#pragma once

#include "logStacks.hpp" // Module header

namespace worTech::betterCpp::logStacks{

// #div: public static methods

    // #func: get<T_derived>(), public static method
    // #scope: LogStack, abstact singleton class
    // #info: creates and returns a static instance of a LogStack derived class
    // #template: class T_derived, derived class of LogStack
    // #calls: T_derived();
    template<class T_derived> LogStack& LogStack::get(){
        static T_derived instance = T_derived();
        return instance;
    }

}