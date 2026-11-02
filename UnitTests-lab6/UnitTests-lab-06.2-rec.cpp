#include "pch.h"
#include "CppUnitTest.h"

#define main lab_main_06_2_rec
#define Create Create_06_2_rec
#define Print Print_06_2_rec
#define FindMinEven FindMinEven_06_2_rec
#define ProcessArray ProcessArray_06_2_rec
#include "..\Lab-06.2 rec\Lab-06.2 rec.cpp"
#undef main
#undef Create
#undef Print
#undef FindMinEven
#undef ProcessArray

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab06Tests
{
	TEST_CLASS(Lab_06_2_Tests_Rec)
	{
	public:
		TEST_METHOD(TestCreateFillsElementsWithinBounds)
		{
			int values[6] = {};

			srand(12345);
			Create_06_2_rec(values, 6, -5, 5, 0);

			for (int i = 0; i < 6; ++i)
			{
				Assert::IsTrue(values[i] >= -5 && values[i] <= 5);
			}
		}

		TEST_METHOD(TestCreateFillsOnlyRequestedElements)
		{
			int values[] = { 99, 99, 99, 99, 99 };

			Create_06_2_rec(values, 3, 7, 7, 0);

			Assert::AreEqual(7, values[0]);
			Assert::AreEqual(7, values[1]);
			Assert::AreEqual(7, values[2]);
			Assert::AreEqual(99, values[3]);
			Assert::AreEqual(99, values[4]);
		}

		TEST_METHOD(TestCreateSupportsNonzeroStartingIndex)
		{
			int values[] = { 1, 2, 0, 0, 0, 6 };

			Create_06_2_rec(values, 5, 8, 8, 2);

			Assert::AreEqual(1, values[0]);
			Assert::AreEqual(2, values[1]);
			Assert::AreEqual(8, values[2]);
			Assert::AreEqual(8, values[3]);
			Assert::AreEqual(8, values[4]);
			Assert::AreEqual(6, values[5]);
		}

		TEST_METHOD(TestCreateDoesNothingAtRecursionBaseCase)
		{
			int values[] = { 4, 8, 15, 16 };

			Create_06_2_rec(values, 4, -10, 10, 4);

			Assert::AreEqual(4, values[0]);
			Assert::AreEqual(8, values[1]);
			Assert::AreEqual(15, values[2]);
			Assert::AreEqual(16, values[3]);
		}
	};
}
