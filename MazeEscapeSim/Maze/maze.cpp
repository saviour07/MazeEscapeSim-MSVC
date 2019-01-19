#include <iostream>
#include "maze.h"

namespace mes_maze
{
    void Maze::GenerateMaze()
    {
        for (int rowIdx = 0; rowIdx < mRowCount; ++rowIdx)
        {
            mes_row::Row row(mLogger, rowIdx, rowIdx == mRowCount - 1);
            row.GenerateRow(mColCount);
            Rows.push_back(row);
        }

        PrintMaze();
    }

    void Maze::PrintMaze()
    {
        for (const auto& row : Rows)
        {
            for (const auto& dir : row.GetDirections())
            {
                const auto name = dir.DirectionName();
                mLogger.Write(name);

                auto len = name.size();
                while (len < 6)
                {
                    mLogger.Write(L" ");
                    len++;
                }
            }
            mLogger.WriteLine(L"");
        }
    }
}
