#include <sstream>
#include "row.h"
#include "Rng/rng.h"

namespace mes_row
{
    void Row::UpdateDirection(const int xPos)
    {
        std::wstringstream msg;
        auto& direction = mRow[xPos];
        if (direction.IsNorth())
        {
            msg << "Moving NORTH to EAST";
            direction.ToEast();
        }
        else if (direction.IsEast())
        {
            msg << "Moving EAST to SOUTH";
            direction.ToSouth();
        }
        else if (direction.IsSouth())
        {
            msg << "Moving SOUTH to WEST";
            direction.ToWest();
        }
        else if (direction.IsWest())
        {
            msg << "Moving WEST to NORTH";
            direction.ToNorth();
        }
        else if (direction.IsOut())
        {
            msg << "OUT - Nothing to do!";
        }
        mLogger.Write(msg.str(), true);
    }

    void Row::GenerateRow(const int numberOfCols)
    {
        for (int colIdx = 0; colIdx < numberOfCols; ++colIdx)
        {
            mes_direction::Direction dir;
            if (isFirstRow() || isLastRow() || isFirstDirection(colIdx) || isLastDirection(colIdx, numberOfCols))
            {
                dir.ToOut();
            }
            else
            {
                mes_rng::Rng rng;
                const auto randomNumber = rng.GenerateNumber(1, 4);
                dir.StartDirection(randomNumber);
            }
            mRow.push_back(dir);
        }
    }
}