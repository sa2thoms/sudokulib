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
    // TODO (sithomson): put a full solution here
    sudoku::PartialSudoku sudoku = sudoku::PartialSudoku({
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 0, 0, 0,   0, 0, 0,   0, 0, 0 }
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
    return RUN_ALL_TESTS();
}
