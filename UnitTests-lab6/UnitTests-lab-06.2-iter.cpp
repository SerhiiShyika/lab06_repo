#include "pch.h"
#include "CppUnitTest.h"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#define main lab_06_2_iter_main
#define Create Lab062_Create
#define Print Lab062_Print
#define FindMinEven Lab062_FindMinEven
#define ProcessArray Lab062_ProcessArray
#include "..\Lab-06.2 Iter\Lab-06.2 Iter.cpp"
#undef ProcessArray
#undef FindMinEven
#undef Print
#undef Create
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab06Tests
{
	TEST_CLASS(Lab_06_2_Tests_Iter)
	{
	public:
		TEST_METHOD(TestFindsSmallestEvenElement)
		{
			const int values[] = { 7, 4, -8, 6, 3 };

			Assert::AreEqual(2, Lab062_FindMinEven(values, 5));
		}

		TEST_METHOD(TestReturnsFirstIndexForRepeatedMinimum)
		{
			const int values[] = { 10, 2, 2, 8 };

			Assert::AreEqual(1, Lab062_FindMinEven(values, 4));
		}

		TEST_METHOD(TestReturnsMinusOneWhenThereAreNoEvenElements)
		{
			const int values[] = { -5, 1, 7, 9 };

			Assert::AreEqual(-1, Lab062_FindMinEven(values, 4));
		}

		TEST_METHOD(TestReturnsMinusOneForEmptyArray)
		{
			Assert::AreEqual(-1, Lab062_FindMinEven(nullptr, 0));
		}

		TEST_METHOD(TestProcessesArrayBySwappingWithSmallestEven)
		{
			int values[] = { 9, 8, 2, 6, 4 };
			const int expected[] = { 2, 8, 9, 6, 4 };

			Lab062_ProcessArray(values, 5);

			for (int i = 0; i < 5; ++i)
				Assert::AreEqual(expected[i], values[i]);
		}

		TEST_METHOD(TestLeavesArrayUnchangedWhenThereAreNoEvenElements)
		{
			int values[] = { 1, 3, 5, 7 };

			Lab062_ProcessArray(values, 4);

			for (int i = 0; i < 4; ++i)
				Assert::AreEqual(2 * i + 1, values[i]);
		}

		TEST_METHOD(TestLeavesArrayUnchangedForEmptyArray)
		{
			Lab062_ProcessArray(nullptr, 0);
		}

		TEST_METHOD(TestCreatesValuesWithinSpecifiedBounds)
		{
			constexpr int size = 100;
			int values[size];

			std::srand(12345);
			Lab062_Create(values, size, -3, 5);

			for (int i = 0; i < size; ++i)
			{
				Assert::IsTrue(values[i] >= -3);
				Assert::IsTrue(values[i] <= 5);
			}
		}

		TEST_METHOD(TestCreateUsesTheOnlyValueWhenBoundsAreEqual)
		{
			int values[10];

			std::srand(12345);
			Lab062_Create(values, 10, 7, 7);

			for (int i = 0; i < 10; ++i)
				Assert::AreEqual(7, values[i]);
		}

		TEST_METHOD(TestPrintsElementsWithWidthFiveAndNewline)
		{
			const int values[] = { 1, -2, 30 };
			std::ostringstream output;
			std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());

			Lab062_Print(values, 3);

			std::cout.rdbuf(originalBuffer);

			Assert::AreEqual(std::string("    1   -2   30\n"), output.str());
		}

		TEST_METHOD(TestPrintsOnlyNewlineForEmptyArray)
		{
			std::ostringstream output;
			std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());

			Lab062_Print(nullptr, 0);

			std::cout.rdbuf(originalBuffer);

			Assert::AreEqual(std::string("\n"), output.str());
		}
	};
}
