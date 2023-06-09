#include <stdio.h>

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    printf(" %c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\n");
}

// Função para verificar se algum jogador venceu
int verificarVitoria(char tabuleiro[3][3], char jogador) {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
            return 1; // Jogador venceu
    }

    // Verificar colunas
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == jogador && tabuleiro[1][j] == jogador && tabuleiro[2][j] == jogador)
            return 1; // Jogador venceu
    }

    // Verificar diagonais
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador))
        return 1; // Jogador venceu

    return 0; // Ninguém venceu ainda
}

int main() {
    char tabuleiro[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int linha, coluna;
    char jogador = 'X';

    printf("Bem-vindo ao Jogo da Velha!\n");

    // Loop principal do jogo
    while (1) {
        imprimirTabuleiro(tabuleiro);

        // Obter a jogada do jogador
        printf("Jogador %c, insira a linha (1-3): ", jogador);
        scanf("%d", &linha);
        printf("Jogador %c, insira a coluna (1-3): ", jogador);
        scanf("%d", &coluna);

        // Verificar se a posição é válida
        if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha - 1][coluna - 1] != ' ') {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }

        // Atualizar o tabuleiro com a jogada do jogador
        tabuleiro[linha - 1][coluna - 1] = jogador;

        // Verificar se o jogador venceu
        if (verificarVitoria(tabuleiro, jogador)) {
            printf("Jogador %c venceu! Parabéns!\n", jogador);
            break;
        }

        // Verificar se houve um empate
        int empate = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tabuleiro[i][j] == ' ') {
                    empate = 0;
                    break;
                }
            }
        }
        if (empate) {
            printf("Empate! O jogo acabou.\n");
            break;
        }

        // Alternar o jogador
        jogador = (jogador == 'X') ? 'O' : 'X';
    }

    return 0;
}
