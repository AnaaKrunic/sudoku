#pragma once
#include "sudokuGenerator.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

const int SIZE = 9;

class Sudoku {
	int** mat;
	int N;
	int SRN;
	int K;
	bool playerMode;

public:
	/**
	 * @brief Constructs a Sudoku object with the specified size and difficulty.
	 *
	 * @param N The size of the Sudoku grid.
	 * @param K The number of digits to remove for puzzle generation.
	 */
	Sudoku(int N, int K);

	/**
	 * @brief Destroys the Sudoku object, freeing allocated memory.
	 */
	~Sudoku();

	/**
	 * @brief Fills the Sudoku grid with values.
	 */	
	void fillValues();

	/**
	 * @brief Fills the diagonal of the Sudoku grid with values.
	 */
	void fillDiagonal();

	/**
	 * @brief Checks if a number is unused in the specified box.
	 *
	 * @param rowStart The starting row of the box.
	 * @param colStart The starting column of the box.
	 * @param num The number to check.
	 * @return True if the number is unused, false otherwise.
	 */
	bool unUsedInBox(int rowStart, int colStart, int num);

	/**
	 * @brief Fills a 3x3 box in the Sudoku grid.
	 *
	 * @param row The starting row of the box.
	 * @param col The starting column of the box.
	 */
	void fillBox(int row, int col);

	/**
	 * @brief Generates a random number between 1 and the given limit.
	 *
	 * @param num The upper limit for the random number.
	 * @return The generated random number.
	 */
	int randomGenerator(int num);

	/**
	 * @brief Checks if placing a number at a specific location is safe.
	 *
	 * @param i The row of the location.
	 * @param j The column of the location.
	 * @param num The number to check.
	 * @return True if the placement is safe, false otherwise.
	 */
	bool CheckIfSafe(int i, int j, int num);

	/**
	 * @brief Checks if a number is unused in the specified row.
	 *
	 * @param i The row to check.
	 * @param num The number to check.
	 * @return True if the number is unused, false otherwise.
	 */
	bool unUsedInRow(int i, int num);

	/**
	 * @brief Checks if a number is unused in the specified column.
	 * 
	 * @param j The column to check.
	 * @param num The number to check.
	 * @return True if the number is unused, false otherwise.
	 */
	bool unUsedInCol(int j, int num);

	/**
	 * @brief Recursively fills the remaining part of the Sudoku grid.
	 *
	 * @param i The current row.
	 * @param j The current column.
	 * @return True if the Sudoku is filled, false otherwise.
	 */
	bool fillRemaining(int i, int j);

	/**
	 * @brief Removes K digits from the Sudoku grid to create a puzzle.
	 */
	void removeKDigits();

	/**
	 * @brief Prints the Sudoku grid to the console.
	 */
	void printSudoku();

	/**
	 * @brief Converts the Sudoku grid to a matrix.
	 *
	 * @return The 2D vector representing the Sudoku grid.
	 */
	vector<vector<int>> toMatrix() const;

	/**
	 * @brief Updates the Sudoku grid from the given matrix.
	 *
	 * @param sudokuMatrix The matrix representing the Sudoku grid.
	 */
	void updateFromMatrix(const vector<vector<int>>& sudokuMatrix);

	/**
	 * @brief Reads the Sudoku grid from a file.
	 *
	 * @param filename The name of the file to read from.
	 * @return True if the read is successful, false otherwise.
	 */
	bool readFromFile(const std::string& filename);

	/**
	 * @brief Writes the Sudoku grid to a file.
	 *
	 * @param filename The name of the file to write to.
	 * @return True if the write is successful, false otherwise.
	 */
	bool writeToFile(const std::string& filename) const;

	/**
	 * @brief Validates the Sudoku grid and counts the errors.
	 *
	 * @return The number of errors in the Sudoku grid.
	 */
	int isValid() const;

	/**
	 * @brief Clears the Sudoku board by setting all values to 0.
	 *
	 * This function resets all elements of the Sudoku board to 0,
	 * effectively clearing the board.
	 */	
	void clear();
};

