#include "direction.h"

namespace mes_direction
{
    void Direction::StartDirection(const int idx)
    {
        switch (idx)
        {
            case 1:
            {
                mDirection = mNorthString;
                break;
            }
            case 2:
            {
                mDirection = mSouthString;
                break;
            }
            case 3:
            {
                mDirection = mEastString;
                break;
            }
            case 4:
            {
                mDirection = mWestString;
                break;
            }
            case 5:
            {
                mDirection = mOutString;
                break;
            }
            default:
                break;
        }
    }
}