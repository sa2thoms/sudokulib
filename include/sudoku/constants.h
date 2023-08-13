#pragma once

#include <cstdint>
#include <cstddef>

namespace sudoku {

static inline constexpr std::size_t kNumRows = 9;
static inline constexpr std::size_t kNumCols = 9;

using Cell = int8_t;
static inline constexpr Cell kEmptyCell = 0;

} // namespace sudoku
