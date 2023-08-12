#pragma once

#include <exception>

namespace sudoku {

class Exception : public std::exception {
public:
    using std::exception::exception;
};

}
