#include "pch.h"
#include "CppUnitTest.h"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#define main lab_06_3_iter_main
#define Create Lab063_Create
#define Print Lab063_Print
#define SumOdd Lab063_SumOdd
#include "..\Lab-06.3-Iter\Lab-06.3-Iter.cpp"
#undef SumOdd
#undef Print
#undef Create
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab06Tests
{
	TEST_CLASS(Lab_06_3_Tests_Iter)
	{
	public:
		TEST_METHOD(TestCreateGeneratesValuesWithinBounds)
		{
			constexpr int size = 100;
			int values[size];

			std::srand(12345);
			Lab063_Create(values, size, -40, 50);

			for (int i = 0; i < size; ++i)
			{
				Assert::IsTrue(values[i] >= -40);
				Assert::IsTrue(values[i] <= 50);
			}
		}

		TEST_METHOD(TestCreateUsesTheOnlyValueWhenBoundsAreEqual)
		{
			int values[10];

			Lab063_Create(values, 10, 7, 7);

			for (int i = 0; i < 10; ++i)
				Assert::AreEqual(7, values[i]);
		}

		TEST_METHOD(TestSumOddFunctionReturnsSumOfOddIntegers)
		{
			const int values[] = { -5, -2, 0, 3, 7, 8 };

			Assert::AreEqual(5, Lab063_SumOdd(values, 6));
		}

		TEST_METHOD(TestSumOddTemplateReturnsSumOfLongValues)
		{
			const long values[] = { -9L, 2L, 4L, 11L, 15L };

			Assert::AreEqual(17L, Lab063_SumOdd<long>(values, 5));
		}

		TEST_METHOD(TestSumOddReturnsZeroWhenThereAreNoOddValues)
		{
			const int values[] = { -8, 0, 2, 14 };

			Assert::AreEqual(0, Lab063_SumOdd(values, 4));
			Assert::AreEqual(0, Lab063_SumOdd<int>(values, 4));
		}

		TEST_METHOD(TestSumOddReturnsZeroForEmptyArray)
		{
			Assert::AreEqual(0, Lab063_SumOdd(nullptr, 0));
			Assert::AreEqual(0, Lab063_SumOdd<int>(nullptr, 0));
		}

		TEST_METHOD(TestPrintOutputsFormattedValues)
		{
			const int values[] = { 1, -2, 30 };
			std::ostringstream output;
			std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());

			Lab063_Print(values, 3);

			std::cout.rdbuf(originalBuffer);

			Assert::AreEqual(std::string("    1   -2   30\n"), output.str());
		}

		TEST_METHOD(TestPrintOutputsOnlyNewlineForEmptyArray)
		{
			std::ostringstream output;
			std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());

			Lab063_Print(nullptr, 0);

			std::cout.rdbuf(originalBuffer);

			Assert::AreEqual(std::string("\n"), output.str());
		}
	};
}
