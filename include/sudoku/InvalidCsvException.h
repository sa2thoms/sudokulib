#pragma once

#include "Exception.h"

#include <string>

namespace sudoku {

class InvalidCsvException : public Exception {
private:
    std::string message_;
public:
    using Exception::Exception;
    InvalidCsvException(std::string const & message) : message_(message) {}
};

} // namespace sudoku
