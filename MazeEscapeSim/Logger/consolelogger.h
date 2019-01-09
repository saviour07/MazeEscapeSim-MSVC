#pragma once
#include <iostream>
#include "ILogger.h"

namespace mes_consolelogger
{
    class ConsoleLogger : public mes_ilogger::ILogger
    {
        public:
            ConsoleLogger()
                : mes_ilogger::ILogger(std::wcout)
            {
            }

            void Write(const std::wstring& line, const bool endWithNewLine)
            {
                Output << line;
                if (endWithNewLine)
                {
                    Output << std::endl;
                }
            }
    };
}