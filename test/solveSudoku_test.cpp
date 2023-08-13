#include "sudoku/PartialSudoku.h"
#include "sudoku/constants.h"
#include "sudoku/solveSudoku.h"

#include <gtest/gtest.h>

namespace solveSudokuTest {

TEST(solveSudoku, solves_sudoku_already_solved) {
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

    auto result = sudoku::findAllSolutions(sudoku);

    EXPECT_EQ(result.size(), 1);
    for (auto i = 0; i < sudoku::kNumRows; i++) {
        for (auto j = 0; j < sudoku::kNumCols; j++) {
            EXPECT_EQ(sudoku.at(i, j), result[0].at(i, j));
        }
    }
}

TEST(solveSudoku, solves_sudoku_with_only_one_number_empty) {
    sudoku::PartialSudoku sudoku = sudoku::PartialSudoku({
        std::array<sudoku::Cell, sudoku::kNumCols>{ 4, 3, 5,   2, 6, 9,   7, 8, 1 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 6, 8, 2,   5, 7, 1,   4, 9, 3 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 1, 9, 7,   8, 3, 4,   5, 6, 2 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 8, 2, 6,   1, 9, 5,   3, 4, 7 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 3, 7, 4,   6, 8, 2,   9, 1, 5 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 9, 5, 1,   7, 4, 0,   6, 2, 8 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 5, 1, 9,   3, 2, 6,   8, 7, 4 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 2, 4, 8,   9, 5, 7,   1, 3, 6 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 7, 6, 3,   4, 1, 8,   2, 5, 9 }
    });

    auto result = sudoku::findAllSolutions(sudoku);

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0].at(5, 5), 3);
}

TEST(solveSudoku, solves_sudoku_with_5_empty_spots_but_a_single_solution) {
    sudoku::PartialSudoku sudoku = sudoku::PartialSudoku({
        std::array<sudoku::Cell, sudoku::kNumCols>{ 4, 3, 5,   2, 6, 9,   7, 8, 1 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 6, 8, 2,   5, 7, 1,   4, 9, 3 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 1, 9, 7,   8, 3, 4,   5, 6, 2 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 8, 2, 0,   1, 9, 5,   3, 4, 7 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 3, 0, 0,   6, 8, 2,   9, 1, 0 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 9, 5, 1,   7, 4, 0,   6, 2, 8 },

        std::array<sudoku::Cell, sudoku::kNumCols>{ 5, 1, 9,   3, 2, 6,   8, 7, 4 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 2, 4, 8,   9, 5, 7,   1, 3, 6 },
        std::array<sudoku::Cell, sudoku::kNumCols>{ 7, 6, 3,   4, 1, 8,   2, 5, 9 }
    });

    auto result = sudoku::findAllSolutions(sudoku);

    EXPECT_EQ(result.size(), 1);
    EXPECT_TRUE(sudoku::isSolved(result[0]));
}

} // namespace solveSudokuTest

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
