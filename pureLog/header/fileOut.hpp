// #FILE: consoleOut.hpp, Module Header File

#pragma once

#include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
#include "outputStream.hpp" // #INCLUDE: outputStream.hpp, Module Header File

namespace pureLog::fileOut{ // #scope: pureLog::fileOut

    // #CLASS: FileOut<t_isBuffered>, Template Class
    template<bool t_isBuffered> class FileOut: public ConditionallyBuffered<t_isBuffered>{
    // Friends
        friend FileOut& pureLog::outputStream::OutputStream::get<FileOut<t_isBuffered>>();
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

    // Explicit template instantiations for all configurations
    template class FileOut<OutputStream::UNBUFFERED>;
    template class FileOut<OutputStream::BUFFERED>;

} // #END: pureLog::fileOut  