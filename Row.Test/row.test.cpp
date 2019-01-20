#include "stdafx.h"
#include "CppUnitTest.h"
#include "row.h"
#include "testlogger.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RowTest
{
    TEST_CLASS(RowTestClass)
    {
    public:
        TEST_METHOD(GivenFirstRow_WhenGeneratingTenColumns_ThenRowCountIsTen)
        {
            TestLogger logger;
            const int rowNumber = 0;
            const bool isLastRow = false;
            const size_t colCount = 10;

            mes_row::Row row(logger, rowNumber, isLastRow);
            row.GenerateRow(colCount);

            Assert::AreEqual(colCount, row.Count());
        }

        TEST_METHOD(GivenFirstRow_WhenGeneratingColumns_ThenDirectionIsOut)
        {
            TestLogger logger;
            const int rowNumber = 0;
            const bool isLastRow = false;
            const size_t colCount = 1;

            mes_row::Row row(logger, rowNumber, isLastRow);
            row.GenerateRow(colCount);
            const auto directions = row.GetDirections();

            Assert::AreEqual(colCount, directions.size());
            Assert::IsTrue(directions[0].IsOut());
        }

        TEST_METHOD(GivenLastRow_WhenGeneratingColumns_ThenDirectionIsOut)
        {
            TestLogger logger;
            const int rowNumber = 1;
            const bool isLastRow = true;
            const size_t colCount = 1;

            mes_row::Row row(logger, rowNumber, isLastRow);
            row.GenerateRow(colCount);
            const auto directions = row.GetDirections();

            Assert::AreEqual(colCount, directions.size());
            Assert::IsTrue(directions[0].IsOut());
        }
    };
}