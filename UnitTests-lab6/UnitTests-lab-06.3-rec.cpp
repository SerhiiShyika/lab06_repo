#include "pch.h"
#include "CppUnitTest.h"

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#define main lab_06_3_rec_main
#define Create Lab063Rec_Create
#define Print Lab063Rec_Print
#define SumOdd Lab063Rec_SumOdd
#include "..\Lab-06.3-Rec\Lab-06.3-Rec.cpp"
#undef SumOdd
#undef Print
#undef Create
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab06Tests
{
	TEST_CLASS(Lab_06_3_Tests_Rec)
	{
	public:
		TEST_METHOD(TestCreateGeneratesValuesWithinBounds)
		{
			constexpr int size = 100;
			int values[size];

			std::srand(12345);
			Lab063Rec_Create(values, size, -40, 50, 0);

			for (int i = 0; i < size; ++i)
			{
				Assert::IsTrue(values[i] >= -40);
				Assert::IsTrue(values[i] <= 50);
			}
		}

		TEST_METHOD(TestCreateUsesTheOnlyValueWhenBoundsAreEqual)
		{
			int values[10];

			Lab063Rec_Create(values, 10, 7, 7, 0);

			for (int i = 0; i < 10; ++i)
				Assert::AreEqual(7, values[i]);
		}

		TEST_METHOD(TestCreateSupportsNonzeroStartingIndex)
		{
			int values[] = { 1, 2, 0, 0, 0, 6 };

			Lab063Rec_Create(values, 5, 8, 8, 2);

			Assert::AreEqual(1, values[0]);
			Assert::AreEqual(2, values[1]);
			Assert::AreEqual(8, values[2]);
			Assert::AreEqual(8, values[3]);
			Assert::AreEqual(8, values[4]);
			Assert::AreEqual(6, values[5]);
		}

		TEST_METHOD(TestSumOddFunctionReturnsSumOfOddIntegers)
		{
			const int values[] = { -5, -2, 0, 3, 7, 8 };

			Assert::AreEqual(5, Lab063Rec_SumOdd(values, 6, 0));
		}

		TEST_METHOD(TestSumOddTemplateReturnsSumOfLongValues)
		{
			const long values[] = { -9L, 2L, 4L, 11L, 15L };

			Assert::AreEqual(17L, Lab063Rec_SumOdd<long>(values, 5, 0));
		}

		TEST_METHOD(TestSumOddReturnsZeroWhenThereAreNoOddValues)
		{
			const int values[] = { -8, 0, 2, 14 };

			Assert::AreEqual(0, Lab063Rec_SumOdd(values, 4, 0));
			Assert::AreEqual(0, Lab063Rec_SumOdd<int>(values, 4, 0));
		}

		TEST_METHOD(TestSumOddReturnsZeroAtRecursionBaseCase)
		{
			const int values[] = { 1, 3, 5 };

			Assert::AreEqual(0, Lab063Rec_SumOdd(values, 3, 3));
			Assert::AreEqual(0, Lab063Rec_SumOdd<int>(values, 3, 3));
		}

		TEST_METHOD(TestPrintOutputsFormattedValues)
		{
			const int values[] = { 1, -2, 30 };
			std::ostringstream output;
			std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());

			Lab063Rec_Print(values, 3, 0);

			std::cout.rdbuf(originalBuffer);

			Assert::AreEqual(std::string("    1   -2   30\n"), output.str());
		}

		TEST_METHOD(TestPrintOutputsOnlyNewlineAtRecursionBaseCase)
		{
			std::ostringstream output;
			std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());

			Lab063Rec_Print(nullptr, 0, 0);

			std::cout.rdbuf(originalBuffer);

			Assert::AreEqual(std::string("\n"), output.str());
		}
	};
}
