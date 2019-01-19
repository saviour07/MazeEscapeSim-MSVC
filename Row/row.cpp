#include "stdafx.h"
#include "row.h"
#include "Rng/rng.h"

namespace mes_row
{
    void Row::UpdateDirection(const int xPos)
    {
        std::wstring msg;
        auto& direction = mRow[xPos];
        if (direction.IsNorth())
        {
            msg = L"Moving NORTH to EAST";
            direction.ToEast();
        }
        else if (direction.IsEast())
        {
            msg = L"Moving EAST to SOUTH";
            direction.ToSouth();
        }
        else if (direction.IsSouth())
        {
            msg = L"Moving SOUTH to WEST";
            direction.ToWest();
        }
        else if (direction.IsWest())
        {
            msg = L"Moving WEST to NORTH";
            direction.ToNorth();
        }
        else if (direction.IsOut())
        {
            msg = L"OUT - Nothing to do!";
        }
        mLogger.WriteLine(msg);
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