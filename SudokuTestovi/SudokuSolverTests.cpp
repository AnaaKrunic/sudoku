#include "pch.h"
#include "CppUnitTest.h"
#include "../Sudoku/sudokuSolver.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuTests
{
	TEST_CLASS(SudokuSolverTests)
	{
	public:
		TEST_METHOD(TestFindEmptyLocation)
		{
			SudokuSolver solver;
			vector<vector<int>> sudoku = {
				{1, 2, 3, 4, 5, 6, 7, 8, 9},
				{4, 5, 6, 7, 8, 9, 1, 2, 3},
				{7, 8, 9, 1, 2, 3, 4, 5, 6},
				{2, 3, 4, 5, 6, 7, 8, 9, 1},
				{5, 6, 7, 8, 9, 1, 2, 3, 4},
				{8, 9, 1, 2, 3, 4, 5, 6, 7},
				{3, 4, 5, 6, 7, 8, 9, 1, 2},
				{6, 7, 8, 9, 1, 2, 3, 4, 5},
				{9, 1, 2, 3, 4, 5, 6, 7, 8}
			};

			int row, col;

			bool result = solver.findEmptyLocation(sudoku, row, col);

			Assert::AreEqual(false, result);

			sudoku = {
				{1, 2, 3, 4, 5, 6, 7, 8, 9},
				{4, 5, 6, 7, 8, 9, 1, 2, 3},
				{7, 8, 9, 1, 2, 3, 4, 5, 6},
				{2, 3, 4, 5, 6, 7, 8, 9, 1},
				{5, 6, 7, 8, 9, 1, 2, 3, 4},
				{8, 9, 1, 2, 0, 4, 5, 6, 7},
				{3, 4, 5, 6, 7, 8, 9, 1, 2},
				{6, 7, 8, 9, 1, 2, 3, 4, 5},
				{9, 1, 2, 3, 4, 5, 6, 7, 8}
			};
			
			result = solver.findEmptyLocation(sudoku, row, col);

			Assert::AreEqual(true, result);
			Assert::AreEqual(0, sudoku[row][col]);
		}
		TEST_METHOD(TestIsValid)
		{
			SudokuSolver solver;
			vector<vector<int>> sudoku = {
				{0, 2, 3, 4, 5, 6, 7, 8, 9},
				{4, 5, 6, 7, 8, 9, 1, 2, 3},
				{7, 8, 9, 1, 2, 3, 4, 5, 6},
				{2, 3, 4, 5, 6, 7, 8, 9, 1},
				{5, 6, 7, 8, 9, 1, 2, 3, 4},
				{8, 9, 1, 2, 3, 4, 5, 6, 7},
				{3, 4, 5, 6, 7, 8, 9, 1, 2},
				{6, 7, 8, 9, 1, 2, 3, 4, 5},
				{9, 1, 2, 3, 4, 5, 6, 7, 8}
			};

			int num = 1;
			int row = 0;
			int col = 0;

			bool result = solver.isValid(sudoku, row, col, num);

			Assert::AreEqual(true, result); // da li je broj 1 validan na ovoj poziciji

			sudoku = {
				{1, 2, 3, 4, 5, 6, 7, 8, 9},
				{4, 5, 6, 7, 8, 9, 1, 2, 3},
				{7, 8, 9, 1, 2, 3, 4, 5, 6},
				{2, 3, 4, 5, 6, 7, 8, 9, 1},
				{5, 6, 7, 8, 9, 1, 2, 3, 4},
				{1, 9, 1, 2, 3, 4, 5, 6, 7},
				{3, 4, 5, 6, 7, 8, 9, 1, 2},
				{6, 7, 8, 9, 1, 2, 3, 4, 5},
				{9, 1, 2, 3, 4, 5, 6, 7, 8}
			};

			result = solver.isValid(sudoku, row, col, num);

			Assert::AreEqual(false, result);
		}
		TEST_METHOD(TestSolveSudoku)
		{
			SudokuSolver solver;
			Sudoku sudoku(9, 20);
			sudoku.fillValues();

			vector<vector<int>> sudokuVector = sudoku.toMatrix();

			bool result = solver.solveSudoku(sudokuVector);

			sudoku.updateFromMatrix(sudokuVector);

			Assert::AreEqual(true, result);
			Assert::AreEqual(0, sudoku.isValid()); // provera ispravnosti resenja
		}
	};
}
