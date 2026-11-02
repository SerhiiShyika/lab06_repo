#include "pch.h"
#include "pch.h"
#include "CppUnitTest.h"

#define main lab_main
#include "..\Lab-06.1 it\Lab-06.1 it.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab06Tests {
    TEST_CLASS(Lab_06_1_Tests_It)
    {
    public:
        TEST_METHOD(TestAddsFiveToEachElement)
        {
            int values[] = { -40, -1, 0, 5, 10, 42 };
            int expected[] = { -35, 4, 5, 10, 15, 47 };

            ProcessArray(values, 6);

            for (int i = 0; i < 6; ++i)
            {
                Assert::AreEqual(expected[i], values[i]);
            }
        }

        TEST_METHOD(TestDoesNothingForEmptyArray)
        {
            int values[] = { 7, 8, 9 };

            ProcessArray(values, 0);

            Assert::AreEqual(7, values[0]);
            Assert::AreEqual(8, values[1]);
            Assert::AreEqual(9, values[2]);
        }

        TEST_METHOD(TestHandlesRepeatedCalls)
        {
            int values[] = { 1, 2, 3 };
            int expected[] = { 11, 12, 13 };

            ProcessArray(values, 3);
            ProcessArray(values, 3);

            for (int i = 0; i < 3; ++i)
            {
                Assert::AreEqual(expected[i], values[i]);
            }
        }

        TEST_METHOD(TestHandlesNegativeAndPositiveValues)
        {
            int values[] = { -10, -5, 0, 5, 10 };
            int expected[] = { -5, 0, 5, 10, 15 };

            ProcessArray(values, 5);
            for (int i = 0; i < 5; ++i)
            {
                Assert::AreEqual(expected[i], values[i]);
            }
        }

    };
}
