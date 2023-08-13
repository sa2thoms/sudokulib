#include "sudoku/analyzeSudokuHelpers.h"

#include "sudoku/FileNotFoundException.h"
#include "sudoku/InvalidCsvException.h"
#include "sudoku/PartialSudoku.h"
#include "sudoku/constants.h"

#include <fstream>
#include <sstream>

std::string sudoku::readFile(std::string const & filePath) {
    std::string buffer;
    std::ifstream f(filePath);
    if (not f.good()) {
        throw sudoku::FileNotFoundException(filePath);
    }
    f.seekg(0, std::ios::end);
    buffer.resize(f.tellg());
    f.seekg(0);
    f.read(buffer.data(), buffer.size());
    return buffer;
}

sudoku::PartialSudoku sudoku::createSudokuFromCsv(std::string const & csvString) {
    if (csvString.size() < 81) {
        throw InvalidCsvException("string to small to hold sudoku csv");
    }
    PartialSudoku ret = PartialSudoku::empty();
    int x = 0;
    int y = 0;

    for (std::string::const_iterator c = csvString.begin(); c < csvString.end(); c++) {
        if (*c == ',') x++;
        if (*c == '\n') {
            x = 0;
            y++;
        }
        if (x >= kNumCols) continue;
        if (y >= kNumRows) break;

        if ('0' <= *c && *c <= '9') {
            ret[y][x] = (*c) - '0';
        }
    }

    return ret;
}

std::string sudoku::toString(sudoku::PartialSudoku const & sudoku) {
    std::stringstream ss;
    for (auto y = 0; y < sudoku::kNumRows; y++) {
        for (auto x = 0; x < sudoku::kNumCols; x++) {
            ss << "+---";
        }
        ss << "+\n";
        for (auto x = 0; x < sudoku::kNumCols; x++) {
            ss << "| " << static_cast<int>(sudoku.at(y, x)) << " ";
        }
        ss << "|\n";
    }
    for (auto x = 0; x < sudoku::kNumCols; x++) {
        ss << "+---";
    }
    ss << "+\n";

    return ss.str();
}
