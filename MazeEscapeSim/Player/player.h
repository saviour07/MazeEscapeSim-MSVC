#pragma once

#include "maze.h"
#include "ILogger.h"

namespace mes_player
{
    struct PlayerPosition
    {
        int X;
        int Y;
    };

    class Player
    {
    public:
        Player(mes_ilogger::ILogger& logger)
            : mLogger(logger)
        {
        }
        PlayerPosition StartPosition(const int rowSize, const int colSize);
        bool IsOutsideMaze(const mes_maze::Grid& rows);
        PlayerPosition MoveDirection(mes_maze::Grid& rows);

    private:
        int mCurrentXPosition = 1;
        int mCurrentYPosition = 1;
        mes_ilogger::ILogger& mLogger;

        void PrintDirections(const mes_row::Directions& directions);
    };
}
