#pragma once

#include <string>

#ifdef DIRECTION_EXPORT
#    define DIRECTION_API __declspec(dllexport)
#else
#    define DIRECTION_API __declspec(dllimport)
#endif

namespace mes_direction
{
    class Direction
    {
    public:
        DIRECTION_API void StartDirection(const int idx);

        const std::wstring& DirectionName() const { return mDirection; }
        bool IsNorth() const { return mDirection.compare(mNorthString) == 0; }
        bool IsEast() const { return mDirection.compare(mEastString) == 0; }
        bool IsSouth() const { return mDirection.compare(mSouthString) == 0; }
        bool IsWest() const { return mDirection.compare(mWestString) == 0; }
        bool IsOut() const { return mDirection.compare(mOutString) == 0; }

        void ToNorth() { mDirection = mNorthString; }
        void ToEast() { mDirection = mEastString; }
        void ToSouth() { mDirection = mSouthString; }
        void ToWest() { mDirection = mWestString; }
        void ToOut() { mDirection = mOutString; }

    private:
        std::wstring mDirection;
        const std::wstring mNorthString = L"North";
        const std::wstring mSouthString = L"South";
        const std::wstring mEastString = L"East";
        const std::wstring mWestString = L"West";
        const std::wstring mOutString = L"Out";
    };
}
