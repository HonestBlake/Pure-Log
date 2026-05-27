// #FILE: fileOut.hpp, Module Header File

#pragma once

#if defined(PURE_LOG_USE_MODULES) && defined(INCLUDED_BY_MODULE) // Using Modules
    #define MODULE_EXPORT export
#else // Using Headers Or Open as stand alone file
    #include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
    #include "outputStream.hpp" // #INCLUDE: outputStream.hpp, Module Header File
    #define MODULE_EXPORT
#endif

namespace pureLog{ // #scope: pureLog

    // #CLASS: FileOut<t_isBuffered>, Template Class
    MODULE_EXPORT template<bool t_isBuffered> class FileOut: public ConditionallyBuffered<t_isBuffered>{
    // Friends
        friend FileOut& OutputStream::get<FileOut<t_isBuffered>>();
    public:
    // Public Factory Methods
        virtual ~FileOut();
    // Public Methods
        bool isOpen()const;
    protected:
    // Protected Factory Methods
        FileOut(const std::filesystem::path& p_filePath);
    private:
    // Private Methods
        void write(const std::string& p_log)override;
        void flushOutput()override;
    // Private Members
        std::ofstream m_outputFile;
    }; // #END: FileOut<t_isBuffered>

} // #END: pureLog

#undef MODULE_EXPORT
