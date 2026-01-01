// #FILE: fileOut.cpp, Module Source File

#include "fileOut.hpp" // #INCLUDE: fileOut.hpp, Module Header File

namespace pureLog::fileOut{ // #scope: pureLog::fileOut

// #SCOPE: FileOut<t_isBuffered>

// #DIV: Protected Factory Methods

    // #FUNCTION: ~FileOut(), Destructor
    template<bool t_isBuffered> FileOut<t_isBuffered>::~FileOut(){
        if constexpr(t_isBuffered){
            this->flushBuffer();
        }
        flushOutput();
    } // #END: ~FileOut()

// #DIV: Public Methods

    // #FUNCTION: isOpen(), Method
    template<bool t_isBuffered> bool FileOut<t_isBuffered>::isOpen()const{
        return m_outputFile.is_open();
    } // #END: isOpen()

// #DIV: Private Factory Methods

    // #FUNCTION: FileOut(const std::filesystem::path&), Constructor
    template<bool t_isBuffered> FileOut<t_isBuffered>::FileOut(const std::filesystem::path& p_filePath): m_outputFile(p_filePath, std::ios::app){
    
    } // #END: FileOut(const std::filesystem::path&)

// #DIV: Private Methods

    // #FUNCTION: write(const std::string&), Method
    template<bool t_isBuffered> void FileOut<t_isBuffered>::write(const std::string& p_log){
        if(m_outputFile){
            m_outputFile << p_log;
        }
    } // #END: write(const std::string&)

    // #FUNCTION: flushOutput(), Method
    template<bool t_isBuffered> void FileOut<t_isBuffered>::flushOutput(){
        if(m_outputFile){
            m_outputFile.flush();
        }
    } // #END: flushOutput()

// #END: FileOut<t_isBuffered>  

} // #END: pureLog::fileOut