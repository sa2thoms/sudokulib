#include "analyzeSudokuHelpers.h"

#include "sudoku_FileNotFoundException.h"

#include <fstream>

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
