#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(" 0 ");  // Água
            } else if (tabuleiro[i][j] == 3) {
                printf(" 3 ");  // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf(" 5 ");  // Área afetada pela habilidade
            }
        }
        printf("\n");
    }
}

// Função para aplicar a habilidade em cone
void aplicarHabilidadeCone(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Representação do cone (0 = não afetado, 1 = afetado)
    int cone[5][5] = {  
        { 0, 0, 1, 0, 0 },  
        { 0, 1, 1, 1, 0 },  
        { 0, 0, 1, 0, 0 },  
        { 0, 0, 0, 0, 0 },  
        { 0, 0, 0, 0, 0 }  
    };

    // Sobrescreve as posições afetadas no tabuleiro com valor 5
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int novaLinha = linha + i - 2;  
                int novaColuna = coluna + j - 2;
                if (novaLinha >= 0 && novaLinha < TAM_TABULEIRO && novaColuna >= 0 && novaColuna < TAM_TABULEIRO) {
                    tabuleiro[novaLinha][novaColuna] = 5;  // Marca a área afetada pelo cone
                }
            }
        }
    }
}

// Função para aplicar a habilidade em cruz
void aplicarHabilidadeCruz(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Representação da cruz (0 = não afetado, 1 = afetado)
    int cruz[5][5] = {  
        { 0, 0, 1, 0, 0 },  
        { 0, 0, 1, 0, 0 },  
        { 1, 1, 1, 1, 1 },  
        { 0, 0, 1, 0, 0 },  
        { 0, 0, 1, 0, 0 }  
    };

    // Sobrescreve as posições afetadas no tabuleiro com valor 5
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int novaLinha = linha + i - 2;
                int novaColuna = coluna + j - 2;
                if (novaLinha >= 0 && novaLinha < TAM_TABULEIRO && novaColuna >= 0 && novaColuna < TAM_TABULEIRO) {
                    tabuleiro[novaLinha][novaColuna] = 5;  // Marca a área afetada pela cruz
                }
            }
        }
    }
}

// Função para aplicar a habilidade em octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Representação do octaedro (0 = não afetado, 1 = afetado)
    int octaedro[5][5] = {  
        { 0, 0, 1, 0, 0 },  
        { 0, 1, 1, 1, 0 },  
        { 1, 1, 1, 1, 1 },  
        { 0, 1, 1, 1, 0 },  
        { 0, 0, 1, 0, 0 }  
    };

    // Sobrescreve as posições afetadas no tabuleiro com valor 5
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int novaLinha = linha + i - 2;
                int novaColuna = coluna + j - 2;
                if (novaLinha >= 0 && novaLinha < TAM_TABULEIRO && novaColuna >= 0 && novaColuna < TAM_TABULEIRO) {
                    tabuleiro[novaLinha][novaColuna] = 5;  
                }
            }
        }
    }
}

int main() {
    // Inicializando o tabuleiro com água (valor 0)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = { 0 };

    // Posicionando os navios (valor 3)
    tabuleiro[2][3] = 3;  // Navio na posição (2, 3)
    tabuleiro[3][3] = 3;  // Navio na posição (3, 3)
    tabuleiro[4][3] = 3;  // Navio na posição (4, 3)

    // Exibindo o tabuleiro inicial
    printf("Tabuleiro inicial com navios:\n");
    exibirTabuleiro(tabuleiro);

    // Aplicando habilidades especiais
    // Definindo pontos de origem para as habilidades

    // Aplicando cone na posição (5, 5)
    aplicarHabilidadeCone(tabuleiro, 5, 5);
    printf("\nTabuleiro após aplicar cone na posição (5, 5):\n");
    exibirTabuleiro(tabuleiro);

    // Aplicando cruz na posição (3, 3)
    aplicarHabilidadeCruz(tabuleiro, 3, 3);
    printf("\nTabuleiro após aplicar cruz na posição (3, 3):\n");
    exibirTabuleiro(tabuleiro);

    // Aplicando octaedro na posição (7, 7)
    aplicarHabilidadeOctaedro(tabuleiro, 7, 7);
    printf("\nTabuleiro após aplicar octaedro na posição (7, 7):\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}