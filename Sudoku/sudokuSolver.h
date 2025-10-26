#pragma once
#include "sudokuGenerator.h"

class SudokuSolver {
public:
    /**
     * @brief Finds the first empty location in the Sudoku grid.
     *
     * @param sudoku The Sudoku grid represented as a 2D vector.
     * @param row Output parameter for the row of the empty location.
     * @param col Output parameter for the column of the empty location.
     * @return True if an empty location is found, false otherwise.
     */
    bool findEmptyLocation(const vector<vector<int>>& sudoku, int& row, int& col) const;

    /**
     * @brief Checks if placing a number at a specific location is valid in the Sudoku grid.
     *
     * @param sudoku The Sudoku grid represented as a 2D vector.
     * @param row The row of the location to check.
     * @param col The column of the location to check.
     * @param num The number to be placed at the location.
     * @return True if the placement is valid, false otherwise.
     */
    bool isValid(const vector<vector<int>>& sudoku, int row, int col, int num) const;

    /**
     * @brief Solves the Sudoku puzzle using backtracking.
     *
     * @param sudoku The Sudoku grid represented as a 2D vector.
     * @return True if the Sudoku is solvable, false otherwise.
     */
    bool solveSudoku(vector<vector<int>>& sudoku);

    /**
     * @brief Solves the Sudoku puzzle using backtracking and updates the original Sudoku object.
     *
     * @param sudoku The Sudoku object to be solved.
     * @return True if the Sudoku is solvable, false otherwise.
     */
    bool solveSudoku(Sudoku& sudoku);
};