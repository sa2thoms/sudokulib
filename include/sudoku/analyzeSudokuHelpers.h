#pragma once

#include "sudoku/PartialSudoku.h"

#include <string>

namespace sudoku {

std::string readFile(std::string const & filePath);

PartialSudoku createSudokuFromCsv(std::string const & csvString);

}
