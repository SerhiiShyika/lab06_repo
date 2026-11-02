#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <sstream>
#include <string>

#define main lab_06_4_rec_main
#define Create Lab064Rec_Create
#define Print Lab064Rec_Print
#define MinAbsIndex Lab064Rec_MinAbsIndex
#define SumAfterNegative Lab064Rec_SumAfterNegative
#define FillZeros Lab064Rec_FillZeros
#define Compress Lab064Rec_Compress
#include "..\Lab-06.4-Rec\Lab-06.4-Rec.cpp"
#undef Compress
#undef FillZeros
#undef SumAfterNegative
#undef MinAbsIndex
#undef Print
#undef Create
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab06Tests
{
	TEST_CLASS(Lab_06_4_Tests_Rec)
	{
	public:
		TEST_METHOD(TestCreateReadsAllElementsRecursively)
		{
			std::istringstream input("1.5 -2.25 3.75");
			std::streambuf* originalBuffer = std::cin.rdbuf(input.rdbuf());
			double values[3];

			bool result = Lab064Rec_Create(values, 3, 0);

			std::cin.rdbuf(originalBuffer);

			Assert::IsTrue(result);
			Assert::AreEqual(1.5, values[0], 0.000001);
			Assert::AreEqual(-2.25, values[1], 0.000001);
			Assert::AreEqual(3.75, values[2], 0.000001);
		}

		TEST_METHOD(TestCreateReturnsFalseForInvalidInput)
		{
			std::istringstream input("1.5 invalid 3.75");
			std::streambuf* originalBuffer = std::cin.rdbuf(input.rdbuf());
			double values[3] = {};

			bool result = Lab064Rec_Create(values, 3, 0);

			std::cin.rdbuf(originalBuffer);

			Assert::IsFalse(result);
			Assert::AreEqual(1.5, values[0], 0.000001);
		}

		TEST_METHOD(TestMinAbsIndexReturnsSmallestAbsoluteValue)
		{
			const double values[] = { -4.5, 2.0, -1.25, 3.0 };

			Assert::AreEqual(2, Lab064Rec_MinAbsIndex(values, 4, 1, 1));
		}

		TEST_METHOD(TestMinAbsIndexKeepsFirstIndexForEqualValues)
		{
			const double values[] = { 2.5, -2.5, 4.0 };

			Assert::AreEqual(0, Lab064Rec_MinAbsIndex(values, 3, 1, 0));
		}

		TEST_METHOD(TestSumAfterNegativeSumsAbsoluteValuesRecursively)
		{
			const double values[] = { 4.0, -2.0, -3.5, 1.5, -4.0 };

			Assert::AreEqual(9.0,
				Lab064Rec_SumAfterNegative(values, 5, 0, false),
				0.000001);
		}

		TEST_METHOD(TestSumAfterNegativeReturnsZeroWithoutNegativeElement)
		{
			const double values[] = { 1.0, 2.5, 0.0, 8.0 };

			Assert::AreEqual(0.0,
				Lab064Rec_SumAfterNegative(values, 4, 0, false),
				0.000001);
		}

		TEST_METHOD(TestFillZerosFillsFromStartingIndex)
		{
			double values[] = { 1.0, 2.0, 3.0, 4.0 };

			Lab064Rec_FillZeros(values, 4, 2);

			Assert::AreEqual(1.0, values[0], 0.000001);
			Assert::AreEqual(2.0, values[1], 0.000001);
			Assert::AreEqual(0.0, values[2], 0.000001);
			Assert::AreEqual(0.0, values[3], 0.000001);
		}

		TEST_METHOD(TestCompressKeepsValuesOutsideIntervalAndZerosRemainingElements)
		{
			double values[] = { -5.0, 1.0, 10.0, 3.0, 12.0, -2.0 };
			const double expected[] = { -5.0, 10.0, 12.0, -2.0, 0.0, 0.0 };

			Lab064Rec_Compress(values, 6, 0.0, 5.0, 0, 0);

			for (int i = 0; i < 6; ++i)
				Assert::AreEqual(expected[i], values[i], 0.000001);
		}

		TEST_METHOD(TestCompressZerosArrayWhenAllValuesAreInsideInterval)
		{
			double values[] = { 1.0, 2.0, 3.0 };

			Lab064Rec_Compress(values, 3, 0.0, 5.0, 0, 0);

			for (double value : values)
				Assert::AreEqual(0.0, value, 0.000001);
		}

		TEST_METHOD(TestPrintOutputsFormattedValuesRecursively)
		{
			const double values[] = { 1.5, -2.25 };
			std::ostringstream expected;
			expected << std::setw(10) << values[0]
				<< std::setw(10) << values[1] << '\n';

			std::ostringstream output;
			std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());

			Lab064Rec_Print(values, 2, 0);

			std::cout.rdbuf(originalBuffer);

			Assert::AreEqual(expected.str(), output.str());
		}
	};
}
