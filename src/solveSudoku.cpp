#include "sudoku/solveSudoku.h"


// efficiently moves the contents of the two input vector into a single output vector
template <typename T>
constexpr std::vector<T> concatenateVectors(std::vector<T> && a, std::vector<T> && b) {
    std::vector<T> ret;
    ret.reserve(a.size() + b.size());

    ret.insert(ret.end(), std::make_move_iterator(a.begin()), std::make_move_iterator(a.end()));
    ret.insert(ret.end(), std::make_move_iterator(b.begin()), std::make_move_iterator(b.end()));

    return ret;
}

constexpr std::optional<sudoku::Point<std::size_t>> findFirstEmptySpot(sudoku::PartialSudoku const & sudoku) {
    for (std::size_t y = 0; y < sudoku::kNumRows; y++) {
        for (std::size_t x = 0; x < sudoku::kNumCols; x++) {
            if (sudoku[y][x] == sudoku::kEmptyCell) {
                return sudoku::Point<std::size_t>{x, y};
            }
        }
    }
    return std::nullopt;
}

std::vector<sudoku::PartialSudoku> sudoku::findAllSolutions(sudoku::PartialSudoku const & sudoku) {
    if (!isValid(sudoku)) {
        // no solutions
        return {};
    }

    auto firstEmptySquare = findFirstEmptySpot(sudoku);

    if (!firstEmptySquare.has_value()) {
        // sudoku is already solved
        return {sudoku};
    }

    std::vector<PartialSudoku> solutions = {};

    for (Cell val = 1; val <= 9; val++) {
        if (isValidInsertion(sudoku, firstEmptySquare->x, firstEmptySquare->y, val)) {
            PartialSudoku updatedSudoku = sudoku;
            updatedSudoku[*firstEmptySquare] = val;
            solutions = concatenateVectors(std::move(solutions), findAllSolutions(updatedSudoku));
        }
    }

    return solutions;
}
