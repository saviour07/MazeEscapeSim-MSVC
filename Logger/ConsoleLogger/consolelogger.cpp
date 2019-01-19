#include "stdafx.h"
#include "consolelogger.h"

namespace mes_consolelogger
{
    ConsoleLogger::ConsoleLogger()
        : mes_ilogger::ILogger(std::wcout)
    {
    }

    void ConsoleLogger::Write(const std::wstring& line)
    {
        Output << line;
    }

    void ConsoleLogger::WriteLine(const std::wstring& line)
    {
        Write(line);
        Output << std::endl;
    }
}