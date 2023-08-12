cmake_minimum_required(VERSION 3.20)

project(sudokulib VERSION 0.1.0.0)

add_executable(analyze-sudoku
               src/analyze-sudoku.cpp
               src/analyzeSudokuHelpers.cpp)

set_property(TARGET analyze-sudoku PROPERTY CXX_STANDARD 20)
