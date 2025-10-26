#include "game.h"
#include "menu.h"
#include <iostream>
#include <string>

using namespace std;

SudokuGame::SudokuGame(int N, int K) : sudoku(N, K), gameCounter(0) {
    valid = 0;
    mistakes = 0;
}

void SudokuGame::playGame()
{
	int choice;
	do {
        choice = Menu::showMainMenu();
        switch (choice) {
        case 1: {
            sudoku.readFromFile(outputFileName);
            sudoku.writeToFile(inputFileName);
            displayGameMenu();
            return;
        }
        case 2: {
            sudoku.clear();
            sudoku.fillValues();
            sudoku.writeToFile(outputFileName);
            displayGameMenu();
            return;
        }
        }
	} while (choice != 0);
}

void SudokuGame::displayGameMenu()
{
    int choice;
    do {
        choice = Menu::showGameMenu();
        switch (choice) {
        case 1: {
            // samostalno resavanje, otvara se sudoku_solution.txt
            sudoku.writeToFile(inputFileName);
            cout << "Sudoku zagontetka se nalazi u fajlu " + inputFileName << endl;
            cout << "Pritisnite Enter kada zavrsite sa resavanjem...";
            string a;
            cin >> a;

            sudoku.readFromFile(inputFileName);
            
            sudoku.printSudoku();

            mistakes = sudoku.isValid();
            cout << " Broj gresaka: " + to_string(mistakes) << endl;
            cout << " Broj pogodaka: " + to_string(81 - mistakes) << endl;
            cout << " Igra: " + to_string(gameCounter + 1) << endl;

            playAgain();

            return;
        }
        case 2: {
            // kompjuter resava sudoku i upisuje ga u sudoku_solution.txt
            solver.solveSudoku(sudoku);
            sudoku.writeToFile(inputFileName);
            sudoku.printSudoku();
            cout << " Igra: " + to_string(gameCounter + 1) << endl;

            playAgain();

            return;
        }
        }
    } while (choice != 0);
    playGame();
}

void SudokuGame::playAgain() {
    
    int choice = Menu::playAgainMenu();
    switch (choice) {
    case 1: {
        gameCounter++;
        playGame();
        return;
    }
    case 0: {
        cout << "Hvala sto ste igrali!\n" << endl;
        return;
    }
    }   
}

void SudokuGame::setInputFileName(const string& filename) {
    inputFileName = filename;
}

void SudokuGame::setOutputFileName(const string& filename) {
    outputFileName = filename;
}
