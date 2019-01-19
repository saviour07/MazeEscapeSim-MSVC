#include <sstream>
#include "player.h"
#include "Rng/rng.h"
#include "direction.h"

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

        const std::wstring msg(L"Direction Name: " + dir.DirectionName());
        mLogger.WriteLine(msg);

        return dir.IsOut();
    }

    PlayerPosition Player::MoveDirection(mes_maze::Grid& rows)
    {
        const auto previousYPos = mCurrentYPosition;
        const auto previousXPos = mCurrentXPosition;

        auto dirs = rows.at(mCurrentYPosition).GetDirections();
        PrintDirections(dirs);

        std::wstring msg;
        const auto direction = dirs.at(mCurrentXPosition);
        if (direction.IsNorth())
        {
            msg = L"Moving UP";
            mCurrentYPosition--;
        }
        if (direction.IsEast())
        {
            msg = L"Moving RIGHT";
            mCurrentXPosition++;
        }
        if (direction.IsSouth())
        {
            msg = L"Moving DOWN";
            mCurrentYPosition++;
        }
        if (direction.IsWest())
        {
            msg = L"Moving LEFT";
            mCurrentXPosition--;
        }
        if (direction.IsOut())
        {
            msg = L"Moving OUT";
            mCurrentXPosition = 0;
            mCurrentYPosition = 0;
        }
        mLogger.WriteLine(msg);

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
            const std::wstring msg(dir.DirectionName() + L" ");
            mLogger.Write(msg);
        }
        mLogger.WriteLine(L"");
    }
}