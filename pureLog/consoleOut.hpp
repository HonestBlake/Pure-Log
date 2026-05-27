// #FILE: consoleOut.hpp, Module Header File

#pragma once

#if defined(PURE_LOG_USE_MODULES) && defined(INCLUDED_BY_MODULE) // Using Modules
    #define MODULE_EXPORT export
#else // Using Headers Or Open as stand alone file
    #include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
    #include "outputStream.hpp" // #INCLUDE: outputStream.hpp, Module Header File
    #define MODULE_EXPORT
#endif

namespace pureLog{ // #scope: pureLog

    // #CLASS: StdCout<t_buffering>, Template Class
    MODULE_EXPORT template<bool t_isBuffered> class StdCout: public ConditionallyBuffered<t_isBuffered>{
    // Friends
        friend StdCout<t_isBuffered>& OutputStream::get<StdCout<t_isBuffered>>();
    public:
    // Public Factory Methods
        ~StdCout();
    private:
    // Private Factory Methods
        StdCout() = default; // #DEFAULT: StdCout(), Default Protected Constructor
    // Private Methods
        void write(const std::string& p_log)override;
        void flushOutput()override;
    }; // #END: StdCout<t_buffering>

    // #CLASS: StdCerr<t_buffering>, Template Class
    MODULE_EXPORT template<bool t_isBuffered> class StdCerr: public ConditionallyBuffered<t_isBuffered>{
    // Friends
        friend StdCerr<t_isBuffered>& OutputStream::get<StdCerr<t_isBuffered>>();
    public:
    // Public Factory Methods
        ~StdCerr();
    private:
    // Private Factory Methods
        StdCerr() = default; // #DEFAULT: StdCerr(), Default Protected Constructor
    // Private Methods
        void write(const std::string& p_log)override;
        void flushOutput()override;
    }; // #END: StdCerr<t_buffering>

} // #END: pureLog

#undef MODULE_EXPORT
