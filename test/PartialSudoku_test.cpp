#include "sudoku/PartialSudoku.h"

#include <gtest/gtest.h>

namespace PartialSudokuTest {

TEST(isValid, returns_true_for_empty_sudoku) {
    sudoku::PartialSudoku sudoku = sudoku::PartialSudoku::empty();

    EXPECT_TRUE(sudoku::isValid(sudoku));
}

} // namespace PartialSudokuTest

int main() {
    return RUN_ALL_TESTS();
}
