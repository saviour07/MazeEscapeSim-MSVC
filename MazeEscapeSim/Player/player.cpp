#include <sstream>
#include "player.h"
#include "../util/rng.h"
#include "../Direction/direction.h"

namespace mes_player
{
    PlayerPosition Player::StartPosition(const int rowSize, const int colSize)
    {;
        {
            mes_rng::Rng rng;
            mCurrentYPosition = rng.GenerateNumber(1, rowSize - 2);
        }
        {
            mes_rng::Rng rng;
            mCurrentXPosition = rng.GenerateNumber(1, colSize - 2);
        }

        PlayerPosition result;
        result.X = mCurrentXPosition;
        result.Y = mCurrentYPosition;
        return result;
    }

    bool Player::IsOutsideMaze(const mes_maze::Grid& rows)
    {
        const auto dirs = rows.at(mCurrentYPosition).GetDirections();
        const auto dir = dirs.at(mCurrentXPosition);

        std::wstringstream directionMsg;
        directionMsg << L"Direction Name: " << dir.DirectionName();
        mLogger.Write(directionMsg.str(), true);

        return dir.IsOut();
    }

    PlayerPosition Player::MoveDirection(mes_maze::Grid& rows)
    {
        const auto previousYPos = mCurrentYPosition;
        const auto previousXPos = mCurrentXPosition;

        auto dirs = rows.at(mCurrentYPosition).GetDirections();
        PrintDirections(dirs);

        std::wstringstream directionMsg;

        const auto direction = dirs.at(mCurrentXPosition);
        if (direction.IsNorth())
        {
            directionMsg << L"Moving UP";
            mCurrentYPosition--;
        }
        if (direction.IsEast())
        {
            directionMsg << L"Moving RIGHT";
            mCurrentXPosition++;
        }
        if (direction.IsSouth())
        {
            directionMsg << L"Moving DOWN";
            mCurrentYPosition++;
        }
        if (direction.IsWest())
        {
            directionMsg << L"Moving LEFT";
            mCurrentXPosition--;
        }
        if (direction.IsOut())
        {
            directionMsg << L"Moving OUT";
            mCurrentXPosition = 0;
            mCurrentYPosition = 0;
        }
        mLogger.Write(directionMsg.str(), true);

        rows.at(previousYPos).UpdateDirection(previousXPos);

        PlayerPosition result;
        result.X = mCurrentXPosition;
        result.Y = mCurrentYPosition;
        return result;
    }

    void Player::PrintDirections(const mes_row::Directions& directions)
    {
        for (const auto& dir : directions)
        {
            std::wstringstream msg;
            msg << dir.DirectionName() << L" ";
            mLogger.Write(msg.str(), false);
        }
        mLogger.Write(L"", true);
    }
}