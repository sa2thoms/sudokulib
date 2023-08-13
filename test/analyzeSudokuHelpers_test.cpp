#include "sudoku/InvalidCsvException.h"
#include "sudoku/analyzeSudokuHelpers.h"
#include "sudoku/constants.h"

#include <gtest/gtest.h>

namespace analyzeSudokuHelpersTest {

TEST(createSudokuFromCsv, creates_sudoku_from_good_csv) {
    std::string csvString = "0, 1, 2, 3, 4, 5, 6, 7, 8\n"
                            "0, 0, 0, 0, 0, 0, 0, 0, 0\n"
                            "0, 0, 0, 0, 0, 0, 0, 0, 0\n"
                            "0, 0, 0, 0, 0, 0, 0, 0, 0\n"
                            "0, 0, 0, 0, 0, 0, 0, 0, 0\n"
                            "0, 0, 0, 0, 0, 0, 0, 0, 0\n"
                            "0, 0, 0, 0, 0, 0, 0, 0, 0\n"
                            "0, 0, 0, 0, 0, 0, 0, 0, 0\n"
                            "0, 0, 0, 0, 0, 0, 0, 0, 0\n";
    auto result = sudoku::createSudokuFromCsv(csvString);

    EXPECT_EQ(result[0][0], sudoku::kEmptyCell);
    EXPECT_EQ(result[0][1], 1);
    EXPECT_EQ(result[0][2], 2);
    EXPECT_EQ(result[0][3], 3);
    EXPECT_EQ(result[0][4], 4);
    EXPECT_EQ(result[0][5], 5);
    EXPECT_EQ(result[0][6], 6);
    EXPECT_EQ(result[0][7], 7);
    EXPECT_EQ(result[0][8], 8);
    for (auto x = 0; x < sudoku::kNumCols; x++) {
        for (auto y = 1; y < sudoku::kNumRows; y++) {
            EXPECT_EQ(result[y][x], sudoku::kEmptyCell);
        }
    }
}

TEST(createSudokuFromCsv, creates_sudoku_from_questionable_csv) {
    std::string csvString = "0, 1, hmm maybe 2, 3, 4, 5, 6, 7, 8\n"
                            "0, 0, 0, 0, 0, 0, 0, 0, 0\n"
                            "0, 0, 0, 0,     0, 0, 0, 0, 0\n"
                            "0, 0, 0, 0, wowee, 0, 0, 0, 0\n"
                            "0, 0, 0, 0, 0, 0, 0, 0, 0\n"
                            "0, 0, 0, 0, 0, 0, 0, 0, 0\n"
                            "0, 0, 0, 0, 0, 0, 0, 0, 0\n"
                            "0, 0, 0, 0, 0, 0, 0, 0, 0\n"
                            "0, 0, 0, 0, 0, 0, 0, 0, 0\n\n\n\n\n\n";
    auto result = sudoku::createSudokuFromCsv(csvString);

    EXPECT_EQ(result[0][0], sudoku::kEmptyCell);
    EXPECT_EQ(result[0][1], 1);
    EXPECT_EQ(result[0][2], 2);
    EXPECT_EQ(result[0][3], 3);
    EXPECT_EQ(result[0][4], 4);
    EXPECT_EQ(result[0][5], 5);
    EXPECT_EQ(result[0][6], 6);
    EXPECT_EQ(result[0][7], 7);
    EXPECT_EQ(result[0][8], 8);
    for (auto x = 0; x < sudoku::kNumCols; x++) {
        for (auto y = 1; y < sudoku::kNumRows; y++) {
            EXPECT_EQ(result[y][x], sudoku::kEmptyCell);
        }
    }
}

TEST(createSudokuFromCsv, throws_if_bad_csv) {
    std::string csvString = "lol this string aint no csv";

    EXPECT_THROW(sudoku::createSudokuFromCsv(csvString), sudoku::InvalidCsvException);
}

} // namespace analyzeSudokuHelpersTest

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
