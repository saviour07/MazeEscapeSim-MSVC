#pragma once
#include <ostream>
#include <string>

namespace mes_ilogger
{
    class ILogger
    {
        public:
            ILogger(std::wostream& output)
                : Output(output)
            {
            }
            virtual void Write(const std::wstring& line, const bool endWithNewLine) = 0;

        protected:
            std::wostream& Output;
    };
}