// #FILE: outputStream.tpp, Module Template Implementation File

#pragma once

#ifndef PURE_LOG_USE_MODULES // Using Headers
    #include "outputStream.hpp" // #INCLUDE: outputStream.hpp, Module Header File
#endif

namespace pureLog{ // #scope: pureLog

// #SCOPE: OutputStream

// #DIV: Public Static Methods

    // #FUNCTION: get<T_Derived>(), Static Method
    template<class T_Derived> [[nodiscard]] T_Derived& OutputStream::get(){
        static_assert(OutputStreamDerived<T_Derived>, "Custom output stream type must derive from pureLog::OutputStream.");
        static T_Derived instance = T_Derived();
        return instance;
    } // #END: get<T_Derived>()

// #END: OutputStream

} // #END: pureLog
