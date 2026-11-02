#include "pch.h"
#include "CppUnitTest.h"

#define main lab_rec_main
#include "..\Lab-06.1 rec\Lab-06.1 rec.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab06Tests {
    TEST_CLASS(Lab_06_1_Tests_Rec)
    {
    public:
        TEST_METHOD(TestAddsFiveToEachElement)
        {
            int values[] = { -40, -1, 0, 5, 10, 42 };
            const int expected[] = { -35, 4, 5, 10, 15, 47 };

            ProcessArray(values, 6, 0);

            for (int i = 0; i < 6; ++i)
            {
                Assert::AreEqual(expected[i], values[i]);
            }
        }

        TEST_METHOD(TestLeavesElementsBeforeStartingIndexUnchanged)
        {
            int values[] = { 1, 2, 3, 4, 5 };
            const int expected[] = { 1, 2, 8, 9, 10 };

            ProcessArray(values, 5, 2);

            for (int i = 0; i < 5; ++i)
            {
                Assert::AreEqual(expected[i], values[i]);
            }
        }

        TEST_METHOD(TestDoesNothingForEmptyArray)
        {
            int values[] = { 7, 8, 9 };

            ProcessArray(values, 0, 0);

            Assert::AreEqual(7, values[0]);
            Assert::AreEqual(8, values[1]);
            Assert::AreEqual(9, values[2]);
        }

        TEST_METHOD(TestDoesNothingWhenStartingIndexIsAtOrPastEnd)
        {
            int values[] = { 7, 8, 9 };

            ProcessArray(values, 3, 3);
            ProcessArray(values, 3, 4);

            Assert::AreEqual(7, values[0]);
            Assert::AreEqual(8, values[1]);
            Assert::AreEqual(9, values[2]);
        }

        TEST_METHOD(TestProcessesSingleElement)
        {
            int value[] = { -3 };

            ProcessArray(value, 1, 0);

            Assert::AreEqual(2, value[0]);
        }
    };
}
