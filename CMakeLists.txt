cmake_minimum_required(VERSION 3.20)
include(FetchContent)

enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(sudokulib VERSION 0.1.0.0)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        f8d7d77c06936315286eb55f8de22cd23c188571 # release-1.14.0
)

FetchContent_MakeAvailable(googletest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(analyze-sudoku
               src/analyze-sudoku.cpp
               src/analyzeSudokuHelpers.cpp
               src/solveSudoku.cpp)

add_executable(partialSudokuTest
               test/PartialSudoku_test.cpp)

add_executable(analyzeSudokuHelpersTest
               test/analyzeSudokuHelpers_test.cpp
               src/analyzeSudokuHelpers.cpp)

add_executable(solveSudokuTest
               test/solveSudoku_test.cpp
               src/solveSudoku.cpp)

target_link_libraries(partialSudokuTest PRIVATE gtest)
target_link_libraries(analyzeSudokuHelpersTest PRIVATE gtest)
target_link_libraries(solveSudokuTest PRIVATE gtest)

set_property(TARGET analyze-sudoku PROPERTY CXX_STANDARD 20)
set_property(TARGET partialSudokuTest PROPERTY CXX_STANDARD 20)
set_property(TARGET analyzeSudokuHelpersTest PROPERTY CXX_STANDARD 20)
set_property(TARGET solveSudokuTest PROPERTY CXX_STANDARD 20)

add_test(NAME PartialSudokuTest COMMAND partialSudokuTest)
add_test(NAME AnalyzeSudokuHelpersTest COMMAND analyzeSudokuHelpersTest)
add_test(NAME SolveSudokuTest COMMAND solveSudokuTest)
