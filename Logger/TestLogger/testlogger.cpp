#include "stdafx.h"
#include "testlogger.h"

namespace RowTest
{
    TestLogger::TestLogger()
        : mes_ilogger::ILogger(std::wcout)
    {
    }
    void TestLogger::Write(const std::wstring&) {}
    void TestLogger::WriteLine(const std::wstring&) {}
}