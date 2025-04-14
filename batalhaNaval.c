#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HABILIDADE 5

void imprimirTabuleiro(int tabuleiro[TAM][11], char *Linha[]) {
    for (int i = 0; i < 11; i++) {
        printf(" %s ", Linha[i]);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < 11; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Aplica a matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][11], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int centroLinha, int centroColuna) {
    int offset = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linha = centroLinha - offset + i;
                int coluna = centroColuna - offset + j;

                if (linha >= 0 && linha < TAM && coluna > 0 && coluna < 11) {
                    if (tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 5; // Marcando área de habilidade
                    }
                }
            }
        }
    }
}

void construirCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void construirCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            matriz[i][j] = (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) ? 1 : 0;
        }
    }
}

void construirOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

int main() {
    int MatrizTabuleiro[10][11] = {0};
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];
    char *Linha[11] = {" ", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};

    // Inicializa índices da primeira coluna
    for (int i = 0; i < TAM; i++) {
        MatrizTabuleiro[i][0] = i + 1;
    }

    printf("-------- BATALHA NAVAL -------- \n");

    // Posicionar Navio 1 na linha 4
    for (int i = 0, j = 3; i < 3; i++, j++) {
        MatrizTabuleiro[4][j] = 3;
    }

    // Posicionar Navio 2 na coluna 7
    for (int i = 0, j = 5; i < 3; i++, j++) {
        MatrizTabuleiro[j][7] = 3;
    }

    // Cone
    construirCone(habilidade);
    aplicarHabilidade(MatrizTabuleiro, habilidade, 2, 6);

    // Cruz
    construirCruz(habilidade);
    aplicarHabilidade(MatrizTabuleiro, habilidade, 7, 4);

    // Octaedro
    construirOctaedro(habilidade);
    aplicarHabilidade(MatrizTabuleiro, habilidade, 6, 9);

    // Mostrar o tabuleiro final
    imprimirTabuleiro(MatrizTabuleiro, Linha);

    return 0;
}
