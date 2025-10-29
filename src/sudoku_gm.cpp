#include "sudoku_gm.hpp"
#include "../lib/tcolor.hpp"
#include "module_cli.hpp"

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

void SudokuGame::setup(const RunningOptions& run_opt) {}

void SudokuGame::update() {}

void SudokuGame::render() const {}
