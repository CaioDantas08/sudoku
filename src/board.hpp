#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

/*!
 * Sudoku board.
 */

/// This class stores values for a 9x9 Sudoku board.
#include <array>
class SudokuBoard {
public:
  using value_type = short;
  static constexpr value_type max_dim{ 9 };

private:
  std::array<value_type, max_dim * max_dim> m_board;

public:
  SudokuBoard();
};

#endif
