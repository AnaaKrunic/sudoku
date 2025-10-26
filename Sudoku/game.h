#pragma once
#include "sudokuGenerator.h"
#include "sudokuSolver.h"
#include <string>

class SudokuGame {
private:
    Sudoku sudoku;            ///< Instance of the Sudoku class.
    SudokuSolver solver;       ///< Instance of the SudokuSolver class.
    string inputFileName;      ///< Name of the input file.
    string outputFileName;     ///< Name of the output file.
    int valid;                 ///< Counter for the valid Sudoku solutions.
    int mistakes;              ///< Counter for the mistakes made during gameplay.
    int gameCounter;            ///< Counter for the number of games played.

public:
    /**
     * @brief Constructor for the SudokuGame class.
     *
     * @param N The size of the Sudoku grid.
     * @param K The number of digits to remove when generating a puzzle.
     */
    SudokuGame(int N, int K);

    /**
     * @brief Main function to play the Sudoku game.
     */
    void playGame();

    /**
     * @brief Displays the game menu and handles user input.
     */
    void displayGameMenu();

    /**
     * @brief Sets the input file name for reading Sudoku configurations.
     *
     * @param filename The name of the input file.
     */
    void setInputFileName(const string& filename);

    /**
     * @brief Sets the output file name for writing Sudoku configurations.
     *
     * @param filename The name of the output file.
     */
    void setOutputFileName(const string& filename);

    /**
     * @brief Handles the play again functionality and restarts the game if chosen.
     */
    void playAgain();
};