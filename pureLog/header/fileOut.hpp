// #FILE: consoleOut.hpp, Module Header File

#pragma once

#include "pureLog.hpp" // #INCLUDE: pureLog.hpp, Project Header File
#include "outputStream.hpp" // #INCLUDE: outputStream.hpp, Module Header File

namespace pureLog::fileOut{ // #scope: pureLog::fileOut

    // #CLASS: FileOut
    class FileOut: public outputStream::OutputStream<FileOut>{

    }; // #END: FileOut

} // #END: pureLog::fileOut