#pragma once

#include "constants.h"
#include "InvalidParamException.h"

#include <cstdint>
#include <array>

namespace sudoku {

template <typename T>
struct Point {
    T x;
    T y;
};

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

    constexpr Cell const & operator[](Point<std::size_t> p) const { return rows_[p.y][p.x]; }
    constexpr Cell & operator[](Point<std::size_t> p) { return rows_[p.y][p.x]; }

    constexpr Cell const & at(std::size_t y, std::size_t x) const { return rows_[y][x]; }

};

// returns false if the number is already present in the given row, column, or box
constexpr bool isValidInsertion(PartialSudoku const & sudoku, std::size_t x, std::size_t y, Cell value) {
    if (value == kEmptyCell) {
        throw InvalidParamException("cell value must be between 1 and 9, inclusive");
    }

    for (auto k = 0; k < kNumRows; k++) {
        if (k != y && sudoku[k][x] == value) {
            return false;
        }
    }
    for (auto k = 0; k < kNumCols; k++) {
        if (k != x && sudoku[y][k] == value) {
            return false;
        }
    }

    auto center_y = (y / 3) * 3 + 1;
    auto center_x = (x / 3) * 3 + 1;
    for (auto m = center_y - 1; m < center_y + 2; m++) {
        for (auto n = center_x - 1; n < center_x + 2; n++) {
            if ((m != y || n != x) && sudoku[m][n] == value) {
                return false;
            }
        }
    }

    return true;
}

// returns false if any value appears twice in the same row, column, or box
constexpr bool isValid(PartialSudoku const & sudoku) {
    for (auto i = 0; i < kNumRows; i++) {
        for (auto j = 0; j < kNumCols; j++) {
            Cell cell = sudoku[i][j];

            if (cell == kEmptyCell) {
                continue;
            }

            if (!isValidInsertion(sudoku, j, i, cell)) {
                return false;
            }
        }
    }

    return true;
}

} // namespace sudoku
