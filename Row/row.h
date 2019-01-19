#pragma once

#include <vector>
#include "direction.h"
#include "ILogger.h"

#ifdef ROW_EXPORT
#    define ROW_API __declspec(dllexport)
#else
#    define ROW_API __declspec(dllimport)
#endif

namespace mes_row
{
    typedef std::vector<mes_direction::Direction> Directions;
    class Row
    {
    public:
        ROW_API Row(mes_ilogger::ILogger& logger, const int rowNumber, const bool isLastRow = false)
            : mLogger(logger), mRowNumber(rowNumber), mIsLastRow(isLastRow)
        {
        }
        ROW_API void UpdateDirection(const int xPos);
        ROW_API void GenerateRow(const int numberOfCols);

        ROW_API size_t Count() const { return mRow.size(); }
        ROW_API const Directions& GetDirections() const { return mRow; }

    private:
        mes_ilogger::ILogger& mLogger;
        int mRowNumber = 0;
        bool mIsLastRow = false;
        Directions mRow;

        bool isFirstRow() const { return mRowNumber == 0; }
        bool isLastRow() const { return mIsLastRow; }
        bool isFirstDirection(const int colIdx) const { return colIdx == 0; }
        bool isLastDirection(const int colIdx, const int numberOfCols) const { return colIdx == numberOfCols - 1; }
    };
}
