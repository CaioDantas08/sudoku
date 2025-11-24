# Introduction

Este projeto implementa uma versão interativa do clássico jogo Sudoku com interface textual, desenvolvida em C++ como parte da disciplina Programação I (DIM0176). O sistema permite carregar múltiplos puzzles a partir de arquivos, jogar interativamente através de comandos textuais, desfazer ações, realizar verificações limitadas de jogadas, exibir mensagens e cores de feedback, além de salvar e carregar partidas em andamento por serialização binária. O projeto também explora conceitos fundamentais de programação, como modularização, uso de classes, manipulação de matrizes, leitura e escrita de arquivos, processamento de argumentos de linha de comando e organização de código para projetos maiores.

# Author(s)

Damião Felipe Oliveira de Lima
Caio Dantas Martins

E-mail: felipe.lima.715@ufrn.edu.br
E-mail: caiowillame08@gmail.com

# Problems found or limitations
não conseguimos completar o save game;
não conseguimos exibir os dígitos já usados e os não totalmente usados durante as partidas

# Grading

Preencha os itens que você implementou, indicando qual a nota esperada para cada item.

Item     | Valor máximo   | Valor esperado
-------- | :-----: | :-----:
Trata corretamente os argumentos de linha de comando | 5 pts | 5
Lê e armazena os vários puzzles contidos em um arquivo de entrada |5 pts| 5
Exibe corretamente a tela principal com o menu de ações |5 pts| 5
Permite a escolha dos vários puzzles lidos do arquivo  |5 pts| 5
Executa corretamente a ação de posicionamento de dígitos no tabuleiro (comando posicionar) identificação jogadas inválidas |11 pts| 11
Executa corretamente a remoção de dígitos posicionados pelo jogador (comando remover) |10 pts| 10
Executa corretamente o comando de desfazer ação |12 pts| 12
Executa corretamente o comando de verificação do tabuleiro |12 pts| 12
Salva corretamente, em arquivo externo, uma partida em andamento | 7 pts | ??
Carrega corretamente, de um arquivo externo, uma partida em andamento previamente salva e consegue retormar a partida | 8 pts | ??
Exibe as regras do jogo quando solicitado |5 pts| 5
Indica corretamente se uma partida finalizada foi vencida ou perdida |5 pts| 5
Apresenta uma interface com usuário igual ou similar a que foi especificada nesse documento |5 pts| 5
Apresenta uma validação robusta dos comandos textuais de ação fornecidos pelo usuário |5 pts| 5
Exibe corretamente a lista de dígitos disponíveis, conforme o progresso do jogo |5 pts| 5
Apresenta as indicações com `setas` da coordenada da célula que foi alvo da última ação |5 pts| 5
Apresenta um fluxo correto entre telas, com opção de retomar uma partida suspensa e solicitação de confirmação de finalização de partida, caso exista uma partida em andamento |5 pts| 5

# Compiling and Runnig


