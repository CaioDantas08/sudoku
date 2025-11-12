#include "sudoku_gm.hpp"
#include "../lib/tcolor.hpp"
#include "module_cli.hpp"
#include <iostream>

void bem_vindo(){
    std::cout << ">>> Opening input file [...]data(input.txt).\n";
    std::cout << ">>> Processing data, please wait.\n";
    std::cout << ">>> Finished reading input data file.\n";
    std::cout << "\n";
    std::cout << "=================================================\n";
    std::cout <<   "Welcome to a terminal version of Sudoku, v1.0\n";
    std::cout <<   "Copyright (C) 2020, Selan R. dos Santos\n";
    std::cout << "=================================================\n";
    std::cout << "\n";
    std::cout << "Press enter to start.\n";
    std::cin.ignore(); 
}

SudokuGame::SudokuGame() {
  // TODO: edit or remove as you wish.
}

void SudokuGame::usage(std::string msg) const {

    std::cout << "Usage: sudoku [-c <num>] [-h] <input_puzzle_file>\n";
    std::cout << "Game options:\n";
    std::cout << "  -c <num>  Number of checks per game. Default = 3.\n";
    std::cout << "  -h         Print this help text.\n";

    exit(EXIT_SUCCESS);

  }

  //Help do meio do jogo
void SudokuGame::help() const{

  std::cout << "-------------------------------------------------------------------------------\n";
  std::cout <<    "The goal of Sudoku is to fill a 9x9 grid with numbers so that each row,\n";
  std::cout <<    "column and 3x3 section (nonet) contain all of the digits between 1 and 9.\n\n";
  std::cout <<    "The Sudoku rules are:\n";
  std::cout <<    "1. Each row, column, and nonet can contain each number (typically 1 to 9)\n";
  std::cout <<    "exactly once.\n";
  std::cout <<    "2. The sum of all numbers in any nonet, row or column must be equal to 45.\n"
  std::cout << "-------------------------------------------------------------------------------\n\n"
  std::cout << "Press enter to go back.";
  std::cin.ignore();

}

bool SudokuGame::game_over() {
  // TODO: modificar conforme desenvolimento.
  return over;  // Isto é apenas um Stub, modificar posteriormente.

}

void SudokuGame::process_events(){
  std::string input;
  std::cin >> input;

  if(input == "1"){
    m_game_state = m_game_state_e::PLAYING;
  }else if(input == "2"){
    current_puzzle = (current_puzzle + 1) % m_puzzles.size();
  }else if(input == "3"){
    //SALVAR ARQUIVO
  }else if(input == "4"){
    m_game_state = m_game_state_e::QUITTING;
  }else if(input == "5"){
    m_game_state = m_game_state_e:HELPING;
  }

}

void SudokuGame::setup(const RunningOptions& run_opt){

  if(run_opt.help){
    usage("");
  }

  std::ifstream file(run_opt.input_file);

  SudokuBoard board;
  while(board.carregar_arquivo(file)){
    m_puzzles.push_back(board);
  }

  verifications_board = run_opt.number_verifications;

  m_game_state == m_game_state_e::STARTING; 



}

void SudokuGame::update() {

}

void SudokuGame::render() const {

  
  if(m_game_state == m_game_state_e::STARTING){
    bem_vindo();
  }
  else if(m_game_state == m_game_state_e::QUITTING){
    exit(EXIT_SUCCESS);
  }


  

}
