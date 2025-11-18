#include "board.hpp"
#include <iostream>
SudokuBoard::SudokuBoard() {
  // Empty board.
    std::fill(m_board.begin(), m_board.end(), 0);
}


//Carregar o pluzze do arquivo
bool SudokuBoard::carregar_arquivo(std::istream& ler_tabuleiro){


    for (value_type i = 0; i < 81; i++){
      int valor{0};
      if(!(ler_tabuleiro >> valor)) return false;


      if(valor <= 0){
        m_board[i] = 0;
        m_fixed[i] = false;
      }else{
        m_board[i] = valor;
        m_fixed[i] = true;
      }    
    }

  return true;
}

//Capturar valor da celula
int SudokuBoard::get_valor(value_type linha, value_type coluna) const{
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
    if(c == coluna) continue;
    if(digito == m_board[linha * max_dim + c]){
        eh_valida = false;
        break;
    }
  }
  //Verificando repetições na coluna
  for(value_type r = 0; r < 9; r++) {
    if(r == linha) continue;
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
                if(r == linha && coluna == c) continue;
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
void SudokuBoard::exibir_tabuleiro(bool modo_verificacao, value_type ultima_linha, value_type ultima_coluna) const{

    const std::string RESET = "\033[0m";
    const std::string BRANCO_NEGRITO = "\033[1;37m";  // Fixo
    const std::string AZUL = "\033[1;34m";            // Normal usuário
    const std::string VERMELHO = "\033[1;31m";        // Inválido (verificação)
    const std::string VERDE = "\033[1;32m";           // Correto (verificação)


    // Coordenadas das colunas
    std::cout << "      1 2 3   4 5 6   7 8 9\n";
    


    std::cout << "      ";
    for(int col = 0; col < 9; col++){
        if(col == ultima_coluna){
            std::cout << VERMELHO << "v " << RESET << " ";  
        }else{
            std::cout << "  ";
        }

        if(col == 2 or col == 5){
          std::cout << "  ";
        }
    }
    std::cout << "\n";

    std::cout << "    +-------+-------+-------+\n";
    
    for(int linha = 0; linha < 9; linha++){

      if(linha == ultima_linha){
            std::cout << VERMELHO << ">" << RESET << " ";
      }else{
            std::cout << "  ";
      }
        // Coordenada da linha
        std::cout << char('A' + linha) << " | ";
        
        for(int coluna = 0; coluna < 9; coluna++){
            int valor = get_valor(linha, coluna);
            std::string cor = RESET;
            
            
            if(eh_fixa(linha, coluna)){
                cor = BRANCO_NEGRITO;  // Se é fixa, cor branca
            }else if(valor != 0){
                if(modo_verificacao){
                    if(eh_jogada_valida(linha, coluna, valor)){
                        cor = VERDE; //Se é válida e o modo de verificação tá ativado, cor verde.
                    }else{
                        cor = VERMELHO; //Se é jogada inválida, vermelho
                    }
                }else{
                    cor = AZUL; //Caso o modo de verificacao for false
                }
            }
            
        
            if(valor == 0){
                std::cout << ". ";
            }else{
                std::cout << cor << valor << RESET << " ";
            }
            
            // Separadores de região
            if (coluna == 2 || coluna == 5) {
                std::cout << "| ";
            }
        }
        
        std::cout << "|\n";
        
        // Separadores de região entre linhas
        if (linha == 2 || linha == 5) {
            std::cout << "    +-------+-------+-------+\n";
        }
    }
    
    std::cout << "    +-------+-------+-------+\n";

}

//Se o jogo terminou
bool SudokuBoard::jogo_completo() const{
  bool completou{true};
  for(auto g : m_board){
    if((g == 0)) completou = false;
  }
  return completou;
}

bool SudokuBoard::resultado_jogo() const{

  bool acertou{true};

  for (value_type i = 0; i < 9; i++){
    for (value_type j= 0; j < 9; j++){
      if(!eh_jogada_valida(i,j,get_valor(i,j))){
        acertou = false;
      }
    }
  }
  return acertou;
}

