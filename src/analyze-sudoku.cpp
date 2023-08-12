#include "analyzeSudokuHelpers.h"
#include "sudoku_FileNotFoundException.h"

#include <exception>
#include <iostream>
#include <string>
#include <optional>

void usage() {
    std::cout << "Usage:" << std::endl;
    std::cout << "    sudoku-analyzer <sudoku-file>" << std::endl;
    std::cout << "    e.g. \"sudoku-analyzer my-sudoku.txt\"" << std::endl;
}

struct ArgValues {
    std::string sudokuFilePath;
};

std::optional<ArgValues> processArgs(int argc, char ** argv) {
    if (argc != 2) {
        return std::nullopt;
    }
    ArgValues ret = { .sudokuFilePath = argv[1] };
    return ret;
}

int main(int argc, char ** argv) {
    auto argVals = processArgs(argc, argv);
    if (!argVals.has_value()) {
        usage();
        return 1;
    }

    try {
        std::string fileContents = sudoku::readFile(argVals->sudokuFilePath);
        
        // TODO (sa2thoms): analyze
        std::cout << fileContents << std::endl;
    }
    catch (sudoku::FileNotFoundException const & e) {
        std::cout << "Could not find file \"" << e.filePath() << "\"" << std::endl;
        return -1;
    }
    catch (std::exception const & e) {
        std::cout << "Something went wrong: " << e.what() << std::endl;
        return -1;
    }
}
