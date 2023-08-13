#pragma once

#include "Exception.h"

#include <string>

namespace sudoku {

class InvalidParamException : public Exception {
private:
    std::string message_;
public:
    InvalidParamException(std::string const & message) : message_(message) {}

    char const * what() const noexcept override { return message_.data(); }
};

} // namespace sudoku
