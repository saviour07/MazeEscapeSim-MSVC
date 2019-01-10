#include "stdafx.h"
#include "consolelogger.h"

namespace mes_consolelogger
{
    ConsoleLogger::ConsoleLogger()
        : mes_ilogger::ILogger(std::wcout)
    {
    }

    void ConsoleLogger::Write(const std::wstring& line, const bool endWithNewLine)
    {
        Output << line;
        if (endWithNewLine)
        {
            Output << std::endl;
        }
    }
}