#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

/*!
 * Sudoku board.
 */

/// This class stores values for a 9x9 Sudoku board.
#include <array>
#include <iostream>
class SudokuBoard {
public:
  using value_type = short;
  static constexpr value_type max_dim{ 9 };

private:
  std::array<value_type, max_dim * max_dim> m_board;
  std::array<bool, max_dim * max_dim> m_fixed;

public:
  SudokuBoard(); 

  bool carregar_arquivo(std::istream& ler_tabuleiro);
  value_type get_valor(value_type linha, value_type coluna) const;
  bool eh_fixa(value_type linha, value_type coluna) const;
  bool eh_vazia(value_type linha, value_type coluna) const;
  bool colocar_digito(value_type linha, value_type coluna, value_type digito);
  bool remover_digito(value_type linha, value_type coluna);
  void limpar_tabuleiro();
  bool eh_jogada_valida(value_type linha, value_type coluna, value_type digito) const;
  void exibir_tabuleiro() const;
  bool jogo_completo() const;
};





#endif  
