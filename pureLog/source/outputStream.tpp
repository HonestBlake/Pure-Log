// #FILE: outputStream.tpp, Module Template Implementation File

#pragma once

#include "outputStream.hpp" // #INCLUDE: outputStream.hpp, Module Header File

namespace pureLog::outputStream{ // #scope: pureLog::outputStream

// #SCOPE: OutputStream

// #DIV: Public Static Methods

    // #FUNCTION: get<T_Derived>(), Static Method
    template<class T_Derived> [[nodiscard]] T_Derived& OutputStream::get(){
        static_assert(OutputStreamDerived<T_Derived>, "Custom output stream type must derive from pureLog::OutputStream.");
        static T_Derived instance = T_Derived();
        return instance;
    } // #END: get<T_Derived>()

// #END: OutputStream

} // #END: pureLog::outputStream