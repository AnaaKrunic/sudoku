# 🧩 Sudoku – Object-Oriented C++ Game

A console-based Sudoku game built with **C++** and **object-oriented programming principles**.  
This project generates Sudoku puzzles, allows manual solving, and can automatically solve them using a **backtracking algorithm**.

---

## 🎯 Features

- 🔢 **Sudoku generation** with configurable size and difficulty  
- 🧠 **Automatic solving** using recursive backtracking  
- 🎮 **Interactive gameplay** through a simple text-based menu  
- 💾 **Load and save** puzzles from files  
- ✅ **Validation and testing** of Sudoku solutions  

---

## 🧱 Project Structure

The project is organized into several key classes:

| Class | Description |
|-------|--------------|
| **`Sudoku`** | Handles grid creation, validation, and file I/O |
| **`SudokuGame`** | Manages the game loop and user interaction |
| **`SudokuSolver`** | Solves puzzles using the backtracking algorithm |
| **`Menu`** | Displays the main and game menus |

---

## 🧩 How It Works

1. Generate a new Sudoku board or load one from a file  
2. Choose to solve it manually or let the computer do it  
3. The solver checks the board’s validity and outputs the final solution  

---

## ⚙️ Build & Run

To compile and run the project:

```bash
g++ main.cpp Sudoku.cpp SudokuGame.cpp SudokuSolver.cpp Menu.cpp -o sudoku
./sudoku output.txt input.txt
