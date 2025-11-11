#include "sudoku_gm.hpp"
#include "../lib/tcolor.hpp"
#include "module_cli.hpp"

void bem_vindo(){
    std::cout << ">>> Opening input file [...]data(input.txt).\n";
    std::cout << ">>> Processing data, please wait.\n";
    std::cout << ">>> Finished reading input data file.\n";
    std::cout << "\n";
    std::cout << "Welcome to a terminal version of Sudoku, v1.0\n";
    std::cout << "Copyright (C) 2020, Selan R. dos Santos\n";
    std::cout << "\n";
    std::cout << "Press enter to start.\n";
    std::cin.ignore(); 
}

SudokuGame::SudokuGame() {
  // TODO: edit or remove as you wish.
}

void SudokuGame::usage(std::string msg) const { exit(not msg.empty() ? 1 : 0); }

bool SudokuGame::game_over() {
  // TODO: modificar conforme desenvolimento.
  return true;  // Isto é apenas um Stub, modificar posteriormente.
}

void SudokuGame::process_events() {
  if (m_game_state == game_state_e::STARTING or m_game_state == game_state_e::HELPING) {
    // TODO: do something here...
  } else if (m_game_state == game_state_e::ENDING) {
    // TODO: do something here...
  }
}

void SudokuGame::setup(const RunningOptions& run_opt){

  std::ifstream file(run_opt.input_file);


}

void SudokuGame::update() {}

void SudokuGame::render() const {}
