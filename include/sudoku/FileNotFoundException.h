#pragma once

#include "Exception.h"

#include <string>

namespace sudoku {

class FileNotFoundException : public Exception {
private:
    std::string filePath_;
public:
    FileNotFoundException(std::string const & filePath) : filePath_(filePath) {}

    constexpr std::string const & filePath() const { return filePath_; }
};

}
