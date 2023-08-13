#pragma once

#include "constants.h"
#include "PartialSudoku.h"

#include <iterator>
#include <vector>
#include <optional>

namespace sudoku {

std::vector<PartialSudoku> findAllSolutions(PartialSudoku const & sudoku);

// returns false if there are any empty spots left
constexpr bool isFilled(PartialSudoku const & sudoku) {
    for (auto i = 0; i < kNumRows; i++) {
        for (auto j = 0; j < kNumCols; j++) {
            if (sudoku.at(i, j) == kEmptyCell) {
                return false;
            }
        }
    }

    return true;
}

constexpr bool isSolved(PartialSudoku const & sudoku) {
    return isFilled(sudoku) && isValid(sudoku);
}

} // namespace sudoku
