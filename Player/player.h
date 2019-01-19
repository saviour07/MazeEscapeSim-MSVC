#pragma once

#include "maze.h"
#include "ILogger.h"

#ifdef PLAYER_EXPORT
#    define PLAYER_API __declspec(dllexport)
#else
#    define PLAYER_API __declspec(dllimport)
#endif

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
        PLAYER_API Player(mes_ilogger::ILogger& logger)
            : mLogger(logger)
        {
        }
        PLAYER_API PlayerPosition StartPosition(const int rowSize, const int colSize);
        PLAYER_API bool IsOutsideMaze(const mes_maze::Grid& rows);
        PLAYER_API PlayerPosition MoveDirection(mes_maze::Grid& rows);

    private:
        int mCurrentXPosition = 1;
        int mCurrentYPosition = 1;
        mes_ilogger::ILogger& mLogger;

        void PrintDirections(const mes_row::Directions& directions);
    };
}
