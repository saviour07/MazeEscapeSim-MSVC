#pragma once
#include <iostream>
#include "ILogger.h"

namespace mes_consolelogger
{
    class LOGGER_API ConsoleLogger : public mes_ilogger::ILogger
    {
    public:
        ConsoleLogger();
        void Write(const std::wstring& line);
        void WriteLine(const std::wstring& line);
    };
}