#include "stdafx.h"
#include "CppUnitTest.h"
#include "direction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DirectionTest
{
    TEST_CLASS(DirectionTestClass)
    {
    public:
        TEST_METHOD(GivenIndexOfOne_WhenStartDirectionIsCalled_ThenDirectionIsNorth)
        {
            const int idx = 1;
            mes_direction::Direction direction;
            direction.StartDirection(idx);
            Assert::IsTrue(direction.IsNorth());
        }

        TEST_METHOD(GivenIndexOfTwo_WhenStartDirectionIsCalled_ThenDirectionIsSouth)
        {
            const int idx = 2;
            mes_direction::Direction direction;
            direction.StartDirection(idx);
            Assert::IsTrue(direction.IsSouth());
        }

        TEST_METHOD(GivenIndexOfThree_WhenStartDirectionIsCalled_ThenDirectionIsEast)
        {
            const int idx = 3;
            mes_direction::Direction direction;
            direction.StartDirection(idx);
            Assert::IsTrue(direction.IsEast());
        }

        TEST_METHOD(GivenIndexOfFour_WhenStartDirectionIsCalled_ThenDirectionIsWest)
        {
            const int idx = 4;
            mes_direction::Direction direction;
            direction.StartDirection(idx);
            Assert::IsTrue(direction.IsWest());
        }

        TEST_METHOD(GivenIndexOfFive_WhenStartDirectionIsCalled_ThenDirectionIsOut)
        {
            const int idx = 5;
            mes_direction::Direction direction;
            direction.StartDirection(idx);
            Assert::IsTrue(direction.IsOut());
        }

        TEST_METHOD(GivenIndexOfZero_WhenNoDirectionIsSet_ThenDirectionIsEmpty)
        {
            const std::wstring empty;
            mes_direction::Direction direction;
            Assert::AreEqual(empty, direction.DirectionName());
        }
    };
}