#pragma once
#include <iostream>
#include "ILogger.h"

namespace RowTest
{
    class LOGGER_API TestLogger : public mes_ilogger::ILogger
    {
    public:
        TestLogger();
        void Write(const std::wstring&);
        void WriteLine(const std::wstring&);
    };
}