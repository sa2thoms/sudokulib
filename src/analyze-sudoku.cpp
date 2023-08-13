#include "sudoku/analyzeSudokuHelpers.h"
#include "sudoku/FileNotFoundException.h"
#include "sudoku/solveSudoku.h"

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
        
        sudoku::PartialSudoku mySudoku = sudoku::createSudokuFromCsv(fileContents);

        auto solutions = sudoku::findAllSolutions(mySudoku);

        std::cout << "There are " << solutions.size() << " possible solutions to your sudoku." << std::endl;

        if (!solutions.empty()) {
            std::cout << "Here is the first solution:" << std::endl << sudoku::toString(solutions[0]) << std::endl;
        }
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
