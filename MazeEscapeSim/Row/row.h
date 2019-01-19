#pragma once

#include <vector>
#include "direction.h"
#include "ILogger.h"

namespace mes_row
{
    typedef std::vector<mes_direction::Direction> Directions;
    class Row
    {
    public:
        Row(mes_ilogger::ILogger& logger, const int rowNumber, const bool isLastRow = false)
            : mLogger(logger), mRowNumber(rowNumber), mIsLastRow(isLastRow)
        {
        }
        void UpdateDirection(const int xPos);
        void GenerateRow(const int numberOfCols);

        size_t Count() const { return mRow.size(); }
        const Directions& GetDirections() const { return mRow; }

    private:
        mes_ilogger::ILogger& mLogger;
        int mRowNumber = 0;
        bool mIsLastRow = false;
        Directions mRow;
    };
}
