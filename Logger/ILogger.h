#pragma once
#include <ostream>
#include <string>

#ifdef LOGGER_EXPORT
#    define LOGGER_API __declspec(dllexport)
#else
#    define LOGGER_API __declspec(dllimport)
#endif

namespace mes_ilogger
{
    class LOGGER_API ILogger
    {
        public:
            ILogger(std::wostream& output)
                : Output(output)
            {
            }
            virtual void Write(const std::wstring& line) = 0;
            virtual void WriteLine(const std::wstring& line) = 0;

        protected:
            std::wostream& Output;
    };
}
