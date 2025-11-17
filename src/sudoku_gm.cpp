
	
#include "sudoku_gm.hpp"
#include "../lib/tcolor.hpp"
#include "module_cli.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <limits>

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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
 
    
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
void SudokuGame::help() {

  std::cout << "-------------------------------------------------------------------------------\n";
  std::cout <<    "The goal of Sudoku is to fill a 9x9 grid with numbers so that each row,\n";
  std::cout <<    "column and 3x3 section (nonet) contain all of the digits between 1 and 9.\n\n";
  std::cout <<    "The Sudoku rules are:\n";
  std::cout <<    "1. Each row, column, and nonet can contain each number (typically 1 to 9)\n";
  std::cout <<    "exactly once.\n";
  std::cout <<    "2. The sum of all numbers in any nonet, row or column must be equal to 45.\n";
  std::cout << "-------------------------------------------------------------------------------\n\n";
  std::cout << "Press enter to go back.\n\n\n";

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    std::cout << "|--------[ MAIN SCREEN ]--------|" << std::endl;
    selection_board = m_puzzles[current_puzzle];
    selection_board.exibir_tabuleiro(false);
    std::cout << "MSG: []\n";
    std::cout << "1-Play 2-New Game 3-Load Saved Game 4-Quit 5-Help\n";
    std::cout << "Select option [1,5] > ";

  


}

bool SudokuGame::game_over() {
  // TODO: modificar conforme desenvolimento.
  return over;  // Isto é apenas um Stub, modificar posteriormente.

}

void SudokuGame::process_events(){

  
  if(m_game_state == game_state_e::MENU){

  std::string opcao_selecionada;
  std::getline(std::cin, opcao_selecionada);

  value_type opcao = std::stoi(opcao_selecionada);
  if(opcao < 1 || opcao > 5){
    std::cerr << "Erro: não existe essa opção." << std::endl;
    return;
  }

  if(opcao_selecionada == "1"){
    m_game_state = game_state_e::PLAYING;
    selection_board = m_puzzles[current_puzzle];
  }else if(opcao_selecionada == "2"){
    current_puzzle = (current_puzzle + 1) % m_puzzles.size();
  }else if(opcao_selecionada == "3"){
    //SALVAR ARQUIVO
  }else if(opcao_selecionada == "4"){
    m_game_state = game_state_e::QUITTING;
  }else if(opcao_selecionada == "5"){
    m_game_state = game_state_e::HELPING;
  }

}

}

void SudokuGame::setup(const RunningOptions& run_opt){
  

  if(run_opt.help){
    usage("");
  }

  std::ifstream file(run_opt.input_file);
  if(!file.is_open()){
    std::cerr << "Erro: não foi possível abrir o arquivo\n";
    return;
  }

  SudokuBoard board;
  while(board.carregar_arquivo(file)){
    m_puzzles.push_back(board);
  }

  verifications_board = run_opt.number_verifications;

  m_game_state = game_state_e::STARTING; 



}

void SudokuGame::update() {
   //Se o jogo completou
    if(selection_board.jogo_completo()){
      if(selection_board.resultado_jogo()){
        selection_board.exibir_tabuleiro(true);
        std::cout << "Parabéns, você ganhou!" << std::endl;
      }else{
        selection_board.exibir_tabuleiro(true);
        std::cout << "Que pena, há erros no tabuleiro." << std::endl;
      }
      m_game_state = game_state_e::MENU;
    }
}

void SudokuGame::render() {

  
  if(m_game_state == game_state_e::STARTING){
    bem_vindo();
    m_game_state = game_state_e::MENU;

    std::cout << "|--------[ MAIN SCREEN ]--------|" << std::endl;
    selection_board = m_puzzles[current_puzzle];
    selection_board.exibir_tabuleiro(false);
    std::cout << "MSG: []\n";
    std::cout << "1-Play 2-New Game 3-Load Saved Game 4-Quit 5-Help\n";
    std::cout << "Select option [1,5] > ";
  }
  else if(m_game_state == game_state_e::HELPING){
    help();
    m_game_state = game_state_e::MENU;
  }

  else if(m_game_state == game_state_e::PLAYING){

    

    selection_board.exibir_tabuleiro(false);
    std::cout << "Verificações restantes: " << verifications_board << "\n";
    std::cout << "Digite comando: ";
    


     std::string letraslinha_maiuscula  = "ABCDEFGHI"; 
     std::string letraslinha_minuscula  = "abcdefghi";
     std::string conversao_linha_coluna = "123456789";          


    std::string input;
    std::getline(std::cin,input);

    if(input.empty()){
      m_game_state = game_state_e::MENU;
      render();
      
    }
    //Inserir um dígito
    else if((input[0] == 'p' or input[0] == 'P') && input.size() >=4){

      char char_linha  = input[1];
      char char_coluna = input[2];
      char char_digito = input[3];

      std::string string_digito = std::string(1, char_digito); 
      
      value_type digito{-1};

      try{
        digito = std::stoi(string_digito);
      }catch(...){
        std::cerr << "Erro: digito inválido." << std::endl;
        return;
      }
  
      value_type linha{-1};
      value_type coluna{-1};

      for (value_type i = 0; i < 9; i++){
        
        if(letraslinha_maiuscula[i] == char_linha){
          linha = i;
          break;
        }else if(letraslinha_minuscula[i] == char_linha){
          linha = i;
          break;
        }   
      }

      for (value_type i = 0; i < 9; i++){
        if(conversao_linha_coluna[i] == char_coluna){
          coluna = i;
          break;
        }
      }
      
      if(linha == -1 || coluna == -1){
        std::cerr << "Erro: coordenadas inválidas\n";
        return;
      } 

      if(selection_board.eh_vazia(linha,coluna)){
        selection_board.colocar_digito(linha,coluna,digito);
      }else{
        std::cerr << "Erro: célula ocupada." << std::endl;                        
      }    

    }
    //Fazer uma verificação
    else if((input[0] == 'c' or input[0] == 'C') && input.size() == 1){

      if(verifications_board > 0){
        selection_board.exibir_tabuleiro(true);
        verifications_board--;
      }else{
        std::cerr << "Número de verificações esgotado!" << std::endl;
      }

    }
    //Remover o digito
    else if((input[0] == 'r' or input[0] == 'R') && input.size() >=3){
      char char_linha;
      char char_coluna;

      value_type linha{-1};
      value_type coluna{-1};
      
      char_linha = input[1];
      char_coluna = input[2];
      
      for (value_type i = 0; i < 9; i++){
        
        if(letraslinha_maiuscula[i] == char_linha){
          linha = i;
          break;
        }else if(letraslinha_minuscula[i] == char_linha){
          linha = i;
          break;
        }   
      }

      for (value_type i = 0; i < 9; i++){
        if(conversao_linha_coluna[i] == char_coluna){
          coluna = i;
          break;
        }
      }
      

      if(!selection_board.eh_vazia(linha,coluna) && !selection_board.eh_fixa(linha,coluna)){
        selection_board.remover_digito(linha,coluna);
      }else{
        std::cerr << "Erro: célula fixa ocupando ou vazia." << std::endl;                        
      }
      
      
    }
    //Desfazer ultima jogada
    else if(input[0] == 'u'){
      
    }
    

  
    
   
  }
  else if(m_game_state == game_state_e::QUITTING){
    exit(EXIT_SUCCESS); // O correto é over = true;
  }
  else if(m_game_state == game_state_e::MENU){

    std::cout << "|--------[ MAIN SCREEN ]--------|" << std::endl;

    selection_board = m_puzzles[current_puzzle];
    selection_board.exibir_tabuleiro(false);

    std::cout << "MSG: []\n";

    std::cout << "1-Play 2-New Game 3-Load Saved Game 4-Quit 5-Help\n";
    std::cout << "Select option [1,5] > ";

    
  }


  

}





