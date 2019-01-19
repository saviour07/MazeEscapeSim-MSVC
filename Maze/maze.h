#pragma once

#include <vector>
#include "row.h"
#include "ILogger.h"

#ifdef MAZE_EXPORT
#    define MAZE_API __declspec(dllexport)
#else
#    define MAZE_API __declspec(dllimport)
#endif

namespace mes_maze
{
    MAZE_API typedef std::vector<mes_row::Row> Grid;
    class Maze
    {
    public:
        MAZE_API Maze(mes_ilogger::ILogger& logger, const int rowCount, const int colCount)
            : mLogger(logger), mRowCount(rowCount + 2), mColCount(colCount + 2)
        {
        }
        MAZE_API void GenerateMaze();
        Grid Rows;

        MAZE_API const int& RowCount() { return mRowCount; }
        MAZE_API const int& ColCount() { return mColCount; }

    private:
        mes_ilogger::ILogger& mLogger;
        int mRowCount;
        int mColCount;

        void PrintMaze();
    };
}
