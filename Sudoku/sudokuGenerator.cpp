#include "sudokuGenerator.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

Sudoku::Sudoku(int N, int K) : N(N), K(K) {
    double SRNd = sqrt(N);
    SRN = static_cast<int>(SRNd);
    mat = new int* [N];

    for (int i = 0; i < N; ++i) {
        mat[i] = new int[N];
        memset(mat[i], 0, N * sizeof(int));
    }
}

Sudoku::~Sudoku() {
    for (int i = 0; i < N; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
}

void Sudoku::fillValues() {
    fillDiagonal();
    fillRemaining(0, SRN);
    removeKDigits();
}

void Sudoku::fillDiagonal() {
    for (int i = 0; i < N; i = i + SRN) {
        fillBox(i, i);
    }
}

bool Sudoku::unUsedInBox(int rowStart, int colStart, int num) {
    for (int i = 0; i < SRN; i++) {
        for (int j = 0; j < SRN; j++) {
            if (mat[rowStart + i][colStart + j] == num) {
                return false;
            }
        }
    }
    return true;
}

void Sudoku::fillBox(int row, int col) {
    int num;
    for (int i = 0; i < SRN; i++) {
        for (int j = 0; j < SRN; j++) {
            do {
                num = randomGenerator(N);
            } while (!unUsedInBox(row, col, num));
            mat[row + i][col + j] = num;
        }
    }
}

int Sudoku::randomGenerator(int num) {
    return static_cast<int>(floor((static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * num + 1));
}

bool Sudoku::CheckIfSafe(int i, int j, int num) {
    return (
        unUsedInRow(i, num) && unUsedInCol(j, num)
        && unUsedInBox(i - i % SRN, j - j % SRN, num));
}

bool Sudoku::unUsedInRow(int i, int num) {
    for (int j = 0; j < N; j++) {
        if (mat[i][j] == num) {
            return false;
        }
    }
    return true;
}

bool Sudoku::unUsedInCol(int j, int num) {
    for (int i = 0; i < N; i++) {
        if (mat[i][j] == num) {
            return false;
        }
    }
    return true;
}

bool Sudoku::fillRemaining(int i, int j) {
    if (j >= N && i < N - 1) {
        i = i + 1;
        j = 0;
    }
    if (i >= N && j >= N) {
        return true;
    }
    if (i < SRN) {
        if (j < SRN) {
            j = SRN;
        }
    }
    else if (i < N - SRN) {
        if (j == (static_cast<int>(i / SRN)) * SRN) {
            j = j + SRN;
        }
    }
    else {
        if (j == N - SRN) {
            i = i + 1;
            j = 0;
            if (i >= N) {
                return true;
            }
        }
    }
    for (int num = 1; num <= N; num++) {
        if (CheckIfSafe(i, j, num)) {
            mat[i][j] = num;
            if (fillRemaining(i, j + 1)) {
                return true;
            }
            mat[i][j] = 0;
        }
    }
    return false;
}

void Sudoku::removeKDigits() {
    int count = K;
    while (count != 0) {
        int cellId = randomGenerator(N * N) - 1;
        int i = (cellId / N);
        int j = cellId % N;
        if (j != 0) {
            j = j - 1;
        }
        if (mat[i][j] != 0) {
            count--;
            mat[i][j] = 0;
        }
    }
}

void Sudoku::printSudoku() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] == 0)
                cout << "  ";
            else
                cout << to_string(mat[i][j]) + " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> Sudoku::toMatrix() const {
    vector<vector<int>> sudokuMatrix(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            sudokuMatrix[i][j] = mat[i][j];
        }
    }

    return sudokuMatrix;
}

void Sudoku::updateFromMatrix(const vector<vector<int>>& sudokuMatrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = sudokuMatrix[i][j];
        }
    }
}

bool Sudoku::readFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Nije moguce otvoriti fajl" << endl;
        return false;
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (!(inputFile >> mat[i][j])) {
                cerr << "Greska prilikom citanja iz fajla: " << filename << endl;
                inputFile.close();
                return false;
            }
        }
    }

    inputFile.close();
    return true;
}

bool Sudoku::writeToFile(const string& filename) const {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Nije moguce otvoriti fajl" << endl;
        return false;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            outputFile << mat[i][j] << " ";
        }
        outputFile << endl;
    }

    outputFile.close();
    return true;
}

int Sudoku::isValid() const {
    int errorCount = 0;

    // Provera da li je sve popunjeno
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (mat[i][j] == 0) {
                ++errorCount;  // pronadjeno prazno polje
            }
        }
    }

    // Provera po redovima
    for (int i = 0; i < N; ++i) {
        std::vector<int> usedNumbers(N + 1, 0);
        for (int j = 0; j < N; ++j) {
            if (mat[i][j] != 0) {
                if (++usedNumbers[mat[i][j]] > 1) {
                    ++errorCount;  // ponovila se vrednost u redu
                }
            }
        }
    }

    // Provera po kolonama
    for (int j = 0; j < N; ++j) {
        std::vector<int> usedNumbers(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            if (mat[i][j] != 0) {
                if (++usedNumbers[mat[i][j]] > 1) {
                    ++errorCount;  // ponovila se vrednost u koloni
                }
            }
        }
    }

    return errorCount;
}

void Sudoku::clear() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            mat[i][j] = 0;
        }
    }
}
