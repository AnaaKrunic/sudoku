#include "pch.h"
#include "CppUnitTest.h"
#include "../Sudoku/sudokuGenerator.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuTests
{
	TEST_CLASS(SudokuTests)
	{
	public:

		TEST_METHOD(TestFillValues)
		{
			Sudoku sudoku(9, 0);
			sudoku.fillValues();

			// da li su sva polja popunjena
			Assert::AreEqual(0, sudoku.isValid());
		}

		TEST_METHOD(TestReadFromFile)
		{
			Sudoku sudoku(9, 20);
			bool success = sudoku.readFromFile("proba_sudoku.txt");

			// da li je ucitavanje bilo uspesno
			Assert::IsTrue(success);
		}

		TEST_METHOD(TestWriteToFile)
		{
			Sudoku sudoku(9, 20);
			sudoku.fillValues();
			bool success = sudoku.writeToFile("proba_sudoku.txt");

			// da li je cuvanje bilo uspešno
			Assert::IsTrue(success);
		}

		TEST_METHOD(TestIsValid)
		{
			Sudoku sudoku(9, 0);
			sudoku.fillValues();

			// da li je tablica ispravna
			Assert::AreEqual(0, sudoku.isValid());

			sudoku.updateFromMatrix({
				{1, 2, 3, 4, 5, 6, 7, 8, 9},
				{0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 0}
				});

			// da li sada postoji greska
			Assert::AreNotEqual(0, sudoku.isValid());
		}

		TEST_METHOD(TestClear)
		{
			Sudoku sudoku(9, 20);
			sudoku.fillValues();

			sudoku.clear();

			Assert::AreEqual(9 * 9, sudoku.isValid());
		}
	};
}
