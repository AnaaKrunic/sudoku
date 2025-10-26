#include "sudokuSolver.h"
#include <vector>

bool SudokuSolver::findEmptyLocation(const vector<vector<int>>& sudoku, int& row, int& col) const {
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (sudoku[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool SudokuSolver::isValid(const vector<vector<int>>& sudoku, int row, int col, int num) const {
    for (int x = 0; x < SIZE; x++) {
        if (sudoku[row][x] == num || sudoku[x][col] == num || sudoku[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return false;
        }
    }
    return true;
}

bool SudokuSolver::solveSudoku(vector<vector<int>>& sudoku) {
    int row, col;
    if (!findEmptyLocation(sudoku, row, col)) {
        return true;
    }
    for (int num = 1; num <= SIZE; num++) {
        if (isValid(sudoku, row, col, num)) {
            sudoku[row][col] = num;
            if (solveSudoku(sudoku)) {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}

bool SudokuSolver::solveSudoku(Sudoku& sudoku) {
    vector<vector<int>> sudokuVector = sudoku.toMatrix();
    bool result = solveSudoku(sudokuVector);

    sudoku.updateFromMatrix(sudokuVector);

    return result;
}

