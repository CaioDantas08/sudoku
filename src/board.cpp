#include "board.hpp"

SudokuBoard::SudokuBoard() {
  // Empty board.
    std::fill(m_board.begin(), m_board.end(), 0);
}

//Carregar o pluzze do arquivo
bool SudokuBoard::carregar_arquivo(std::istream& ler_tabuleiro){

  if(ler_tabuleiro.is_open()){

    for (value_type i = 0; i < 81; i++){
      int valor{0};
      ler_tabuleiro >> valor;

      if(valor <= 0){
        m_board[i] = 0;
        m_fixed[i] = false;
      }else{
        m_board[i] = valor;
        m_fixed[i] = true;
      }    
    }
  }else{
    return false;
  } 

  return true;
}

//Capturar valor da celula
value_type SudokuBoard::get_valor(value_type linha, value_type coluna) const{
  return m_board[linha*max_dim + coluna];
}

//Se é celula fixa
bool SudokuBoard::eh_fixa(value_type linha, value_type coluna) const{
  return m_fixed[linha * max_dim + coluna];
}

//Se a celula está vazia
bool SudokuBoard::eh_vazia(value_type linha, value_type coluna) const{
  return m_board[linha*max_dim + coluna] == 0;
}

//Colocar digito
bool SudokuBoard::colocar_digito(value_type linha, value_type coluna, value_type digito){
  value_type valor = m_board[linha*max_dim + coluna];

  if(eh_fixa(linha,coluna)){
      std::cerr << "Error: Cannot modify fixed cell\n";
      return false;
  }

  if(!eh_vazia(linha, coluna)){
      std::cerr << "Error: Cell already occupied\n";
      return false;
  }

  if(digito < 1 || digito > 9){
      std::cerr << "Error: Invalid digit\n";
      return false;    
  }

  m_board[linha*max_dim + coluna] = digito;
  return true;
 
}
//Remover digito
bool SudokuBoard::remover_digito(value_type linha, value_type coluna){
  if(eh_vazia(linha,coluna) || eh_fixa(linha,coluna)){
    std::cerr << "Error: Cell not occupied or fixed cell\n";
    return false;
  }

  m_board[linha*max_dim + coluna] = 0;
  return true;

}

//Limpar as jogadas do usuário e voltar ao tabuleiro inicial
void SudokuBoard::limpar_tabuleiro(){

  for (value_type i = 0; i < 81; i++){
    if(m_board[i] > 0 && !m_fixed[i]) m_board[i] = 0;
  }
  

}

//Validar a jogada
bool SudokuBoard::eh_jogada_valida(value_type linha, value_type coluna, value_type digito) const{

  bool eh_valida{true};

  //Verificando repetições na linha
  for(value_type c = 0; c < 9; c++){
    if(digito == m_board[linha * max_dim + c]){
        eh_valida = false;
        break;
    }
  }
  //Verificando repetições na coluna
  for(value_type r = 0; r < 9; r++) {
    if(digito == m_board[r * max_dim + coluna]){
        eh_valida = false;
        break;
    }
  }

  //Lógica da região 3x3
  if (eh_valida) {
        int inicio_linha = (linha / 3) * 3;
        int inicio_coluna = (coluna / 3) * 3;

        for (value_type r = inicio_linha; r < inicio_linha + 3; r++) {
            for (value_type c = inicio_coluna; c < inicio_coluna + 3; c++) {
                if (digito == m_board[r * max_dim + c]) {
                    eh_valida = false;
                    break;
                }
            }
            if (!eh_valida) break;
        }
    }

  return eh_valida;

}

//Exibir tabuleiro
void SudokuBoard::exibir_tabuleiro() const{

}

//Se o jogo terminou
bool SudokuBoard::jogo_completo() const{
  bool completou{true};
  for(auto g : m_board){
    if((g == 0)) completou = false;
  }
  return completou;
}

