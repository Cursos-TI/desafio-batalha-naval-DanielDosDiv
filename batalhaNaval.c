    #include <stdio.h>

    int main() {
        int index;
        int CordenadaLinha, CordenadaColuna;
        char *Linha[11] = {" ", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
        int Navio1[3] = {3, 3, 3};  // Representando o navio
        int Navio2[3] = {3, 3, 3};  // Representando outro navio, se necessário
        
        printf("-------- BATALHA NAVAL -------- \n");

        // Tabuleiro com 10 linhas e 11 colunas (contando a linha de letras)
        int MatrizTabuleiro[10][11] = {
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };

        // Imprimir a linha de letras
        for (int i = 0; i < 11; i++) {
            printf(" %s ", Linha[i]);
        }
        printf("\n");

        // Posicionando o Navio 1 (na linha 4, em colunas consecutivas)
        for (int i = 0, j = 3; i < 3; i++, j++) {
            if (MatrizTabuleiro[i][j] == 3)
            {
                printf("Occoreu um problema ao posicionar o navio, pq ja tem um navio nessa cordenada");
            return 0;
            }
            
            MatrizTabuleiro[4][j] = Navio1[i];  // Atribuindo os valores do array do navio
        }
        
        //Posicionando navio 2
        for (int i = 0, j = 5; i < 3; i++, j++)
        {
            if (MatrizTabuleiro[j][i] == 3)
            {
                printf("Occoreu um problema ao posicionar o navio");
            return 0;
            }
            
            MatrizTabuleiro[j][7] = Navio2[i];
        }
        
        // Imprimir o tabuleiro
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 11; j++) {
                printf(" %d ", MatrizTabuleiro[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        return 0;
    }
