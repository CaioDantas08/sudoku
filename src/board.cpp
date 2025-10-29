#include "board.hpp"

SudokuBoard::SudokuBoard() {
  // Empty board.
  std::fill(m_board.begin(), m_board.end(), 0);
}
