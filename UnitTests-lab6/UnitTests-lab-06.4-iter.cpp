#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>
#include <sstream>
#include <string>

#define main lab_06_4_iter_main
#define Create Lab064_Create
#define Print Lab064_Print
#define MinAbsIndex Lab064_MinAbsIndex
#define SumAfterNegative Lab064_SumAfterNegative
#define Compress Lab064_Compress
#include "..\Lab-06.4-Iter\Lab-06.4-Iter.cpp"
#undef Compress
#undef SumAfterNegative
#undef MinAbsIndex
#undef Print
#undef Create
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab06Tests
{
	TEST_CLASS(Lab_06_4_Tests_Iter)
	{
	public:
		TEST_METHOD(TestCreateReadsAllElements)
		{
			std::istringstream input("1.5 -2.25 3.75");
			std::streambuf* originalBuffer = std::cin.rdbuf(input.rdbuf());
			double values[3];

			Lab064_Create(values, 3);

			std::cin.rdbuf(originalBuffer);

			Assert::AreEqual(1.5, values[0], 0.000001);
			Assert::AreEqual(-2.25, values[1], 0.000001);
			Assert::AreEqual(3.75, values[2], 0.000001);
		}

		TEST_METHOD(TestMinAbsIndexReturnsSmallestAbsoluteValue)
		{
			const double values[] = { -4.5, 2.0, -1.25, 3.0 };

			Assert::AreEqual(2, Lab064_MinAbsIndex(values, 4));
		}

		TEST_METHOD(TestMinAbsIndexKeepsFirstIndexForEqualValues)
		{
			const double values[] = { 2.5, -2.5, 4.0 };

			Assert::AreEqual(0, Lab064_MinAbsIndex(values, 3));
		}

		TEST_METHOD(TestSumAfterNegativeSumsAbsoluteValuesAfterFirstNegative)
		{
			const double values[] = { 4.0, -2.0, -3.5, 1.5, -4.0 };

			Assert::AreEqual(9.0, Lab064_SumAfterNegative(values, 5), 0.000001);
		}

		TEST_METHOD(TestSumAfterNegativeReturnsZeroWithoutNegativeElement)
		{
			const double values[] = { 1.0, 2.5, 0.0, 8.0 };

			Assert::AreEqual(0.0, Lab064_SumAfterNegative(values, 4), 0.000001);
		}

		TEST_METHOD(TestCompressKeepsValuesOutsideIntervalAndZerosRemainingElements)
		{
			double values[] = { -5.0, 1.0, 10.0, 3.0, 12.0, -2.0 };
			const double expected[] = { -5.0, 10.0, 12.0, -2.0, 0.0, 0.0 };

			Lab064_Compress(values, 6, 0.0, 5.0);

			for (int i = 0; i < 6; ++i)
				Assert::AreEqual(expected[i], values[i], 0.000001);
		}

		TEST_METHOD(TestCompressZerosArrayWhenAllValuesAreInsideInterval)
		{
			double values[] = { 1.0, 2.0, 3.0 };

			Lab064_Compress(values, 3, 0.0, 5.0);

			for (double value : values)
				Assert::AreEqual(0.0, value, 0.000001);
		}

		TEST_METHOD(TestPrintOutputsFormattedValues)
		{
			const double values[] = { 1.5, -2.25 };
			std::ostringstream expected;
			expected << std::setw(10) << values[0]
				<< std::setw(10) << values[1] << '\n';

			std::ostringstream output;
			std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());

			Lab064_Print(values, 2);

			std::cout.rdbuf(originalBuffer);

			Assert::AreEqual(expected.str(), output.str());
		}
	};
}
