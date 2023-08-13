#pragma once

#include "sudoku/constants.h"

#include <cstdint>
#include <array>

namespace sudoku {

class PartialSudoku {
public:
    using Cell_t = Cell;
    using Row_t = std::array<Cell_t, kNumCols>;

private:
    std::array<Row_t, kNumRows> rows_;

public:
    constexpr PartialSudoku() = delete;
    constexpr PartialSudoku(PartialSudoku const &) = default;
    constexpr PartialSudoku(PartialSudoku &&) = default;
    constexpr PartialSudoku & operator=(PartialSudoku const &) = default;
    constexpr PartialSudoku & operator=(PartialSudoku &&) = default;
    constexpr ~PartialSudoku() = default;

    constexpr PartialSudoku(std::array<Row_t, kNumRows> const & rows) : rows_(rows) {}

    static constexpr PartialSudoku empty() {
        std::array<Row_t, kNumRows> vals;
        for (Row_t & row : vals) {
            for (Cell_t & cell : row) {
                cell = 0;
            }
        }
        return PartialSudoku(vals);
    }

    constexpr Row_t const & operator[](std::size_t index) const { return rows_[index]; }
    constexpr Row_t & operator[](std::size_t index) { return rows_[index]; }

};

// returns false if any value appears twice in the same row, column, or box
constexpr bool isValid(PartialSudoku const & sudoku) {
    for (auto i = 0; i < kNumRows; i++) {
        for (auto j = 0; j < kNumCols; j++) {
            PartialSudoku::Cell_t cell = sudoku[i][j];

            if (cell == kEmptyCell) {
                continue;
            }

            for (auto k = 0; k < kNumRows; k++) {
                if (k != i && sudoku[k][j] == cell) {
                    return false;
                }
            }
            for (auto k = 0; k < kNumCols; k++) {
                if (k != j && sudoku[i][k] == cell) {
                    return false;
                }
            }

            auto center_i = (i / 3) * 3 + 1;
            auto center_j = (j / 3) * 3 + 1;
            for (auto m = center_i - 1; m < center_i + 2; m++) {
                for (auto n = center_j - 1; n < center_j + 2; n++) {
                    if ((m != i || n != j) && sudoku[m][n] == cell) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

} // namespace sudoku
