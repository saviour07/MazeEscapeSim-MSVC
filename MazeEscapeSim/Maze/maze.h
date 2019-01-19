#pragma once

#include <vector>
#include "row.h"
#include "ILogger.h"

namespace mes_maze
{
    typedef std::vector<mes_row::Row> Grid;
    class Maze
    {
        public:
            Maze(mes_ilogger::ILogger& logger, const int rowCount, const int colCount)
                : mLogger(logger), mRowCount(rowCount + 2), mColCount(colCount + 2)
            {
            }
            void GenerateMaze();
            Grid Rows;

            const int& RowCount() { return mRowCount; }
            const int& ColCount() { return mColCount; }

        private:
            mes_ilogger::ILogger& mLogger;
            int mRowCount;
            int mColCount;

            void PrintMaze();
    };
}
