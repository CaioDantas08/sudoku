#ifndef SUDOKU_GAME_H
#define SUDOKU_GAME_H

/*!
 *  Sudoku game class header.
 */

#include <cstdint>
#include <string>
#include <vector>
#include <iostream>
#include "board.hpp"
#include "module_cli.hpp"  // where RunningOptions is defined.
#include <stack>

void bem_vindo();

using value_type = int;


/// Game class representing a Life Game simulation manager.
class SudokuGame {
private:
  //=== Structs

  //!< Possible game states.
  enum class game_state_e : std::uint8_t {
    STARTING = 0,  //!< Beginning the game.
    ENDING,
    MENU,
    HELPING,
    QUITTING,
    PLAYING,
    // TODO: add/modify your own game states here.
  };

  //=== Data members

  game_state_e m_game_state;           //!< Current game state.
  std::vector<SudokuBoard> m_puzzles;  //!< List of valid puzzles to be offered to player.
  
  //Pilha de objetos - contém todas as instâncias(jogadas) do jogo.
  std::stack<SudokuBoard> salvar_jogadas;
  bool saiu_da_partida{false};

   //Cores para usar na minha gambiarra
  const std::string RESET = "\033[0m";
  const std::string AZUL = "\033[1;34m"; 
  const std::string AMARELO = "\033[33m";
  
  //Variáveis relacionadas aos tabuleiros
  bool over{false};
  value_type verifications_board{3}; // numero de verificações
  value_type const_verifications_board{3};
  value_type current_puzzle{0}; //Verificar o pluzze atual
  SudokuBoard selection_board; //Jogo atual

  //Para obter a lógica das setas indicando a última jogada
  value_type ultima_linha{-1};
  value_type ultima_coluna{-1};

public:
  SudokuGame();
  ~SudokuGame() = default;

  void usage(std::string error_msg) const;
  void help();
  void update();
  void process_events();
  void render();
  void setup(const RunningOptions&);
  bool game_over();
};  // SudokuGame class.
#endif
