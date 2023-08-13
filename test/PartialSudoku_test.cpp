#include "sudoku/PartialSudoku.h"

#include <gtest/gtest.h>

namespace PartialSudokuTest {

TEST(isValid, returns_true_for_empty_sudoku) {
    sudoku::PartialSudoku sudoku = sudoku::PartialSudoku::empty();

    EXPECT_TRUE(sudoku::isValid(sudoku));
}

TEST(isValid, returns_true_test_1) {
    sudoku::PartialSudoku sudoku = sudoku::PartialSudoku({
        std::array<sudoku::Cell, sudoku::kNumCols>{ 1, 2, 3,   0, 0, 0,   0, 4, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 4, 0,   0, 0, 7,   0, 1, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 7, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 1, 0,   0, 4, 0,   0, 0, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 1,   0, 0, 6,   0, 2, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 5,   0, 0, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 2, 0, 0,   0, 3, 4,   0, 0, 0 }
    });

    EXPECT_TRUE(sudoku::isValid(sudoku));
}

TEST(isValid, returns_true_test_2) {
    sudoku::PartialSudoku sudoku = sudoku::PartialSudoku({
        std::array<sudoku::Cell, sudoku::kNumCols>{ 4, 3, 5,   2, 6, 9,   7, 8, 1 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 6, 8, 2,   5, 7, 1,   4, 9, 3 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 1, 9, 7,   8, 3, 4,   5, 6, 2 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 8, 2, 6,   1, 9, 5,   3, 4, 7 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 3, 7, 4,   6, 8, 2,   9, 1, 5 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 9, 5, 1,   7, 4, 3,   6, 2, 8 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 5, 1, 9,   3, 2, 6,   8, 7, 4 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 2, 4, 8,   9, 5, 7,   1, 3, 6 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 7, 6, 3,   4, 1, 8,   2, 5, 9 }
    });

    EXPECT_TRUE(sudoku::isValid(sudoku));
}

TEST(isValid, returns_false_when_same_number_in_a_column) {
    sudoku::PartialSudoku sudoku = sudoku::PartialSudoku({
        std::array<sudoku::Cell, sudoku::kNumCols>{ 1, 2, 3,   0, 0, 0,   0, 4, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 4, 0,   0, 0, 7,   0, 1, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 7, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 1, 0,   0, 4, 0,   0, 0, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 7,   0, 0, 0 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 1,   0, 0, 6,   0, 2, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 5,   0, 0, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 2, 0, 0,   0, 3, 4,   0, 0, 0 }
    });

    EXPECT_FALSE(sudoku::isValid(sudoku));
}

TEST(isValid, returns_false_when_same_number_in_a_row) {
    sudoku::PartialSudoku sudoku = sudoku::PartialSudoku({
        std::array<sudoku::Cell, sudoku::kNumCols>{ 1, 2, 3,   0, 0, 0,   0, 4, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 4, 0,   4, 0, 7,   0, 1, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 7, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 1, 0,   0, 4, 0,   0, 0, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 1,   0, 0, 6,   0, 2, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 5,   0, 0, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 2, 0, 0,   0, 3, 4,   0, 0, 0 }
    });

    EXPECT_FALSE(sudoku::isValid(sudoku));
}

TEST(isValid, returns_false_when_same_number_in_a_box) {
    sudoku::PartialSudoku sudoku = sudoku::PartialSudoku({
        std::array<sudoku::Cell, sudoku::kNumCols>{ 1, 2, 3,   0, 0, 0,   0, 4, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 4, 0,   0, 0, 7,   0, 1, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 7, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 1, 0,   0, 4, 0,   0, 0, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 1,   0, 0, 6,   0, 2, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 5,   2, 0, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 2, 0, 0,   0, 3, 4,   0, 0, 0 }
    });

    EXPECT_FALSE(sudoku::isValid(sudoku));
}

} // namespace PartialSudokuTest

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
