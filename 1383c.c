#include <stdio.h>
#include <stdlib.h>

#define LINHAS 9
#define COLUNAS 9

int main() {
    int instancia = 0, k = 0, l = 0, m = 0;

    scanf("%i", &instancia);
    

    int *verifica = malloc(instancia * sizeof(int));

    int (*matriz)[LINHAS][COLUNAS] = malloc(instancia * sizeof(*matriz));

    while (k < instancia)
    {
        for (int i = 0; i < LINHAS; i = i + 1)
        {
            for (int j = 0; j < COLUNAS; j = j + 1)
            {
                scanf("%i", &matriz[k][i][j]);
            }
        }
        k++;
    }

    while (m < instancia)
    {
        int valido = 1;

        for (int i = 0; i < LINHAS; i = i + 1)
        {
            for (int j = 0; j < COLUNAS; j = j + 1)
            {
                if (matriz[m][i][j] < 1 || matriz[m][i][j] > 9)
                {
                    valido = 0; 
                }
            }
        }

        for (int i = 0; i < LINHAS; i = i + 1)
        {
            for (int j = 0; j < COLUNAS; j = j + 1)
            {
                for (int x = j + 1; x < COLUNAS; x = x + 1)
                {
                    if (matriz[m][i][j] == matriz[m][i][x])
                    {
                        valido = 0;
                    }
                }
            }
        }

        for (int j = 0; j < COLUNAS; j = j + 1)
        {
            for (int i = 0; i < LINHAS; i = i + 1)
            {
                for (int x = i + 1; x < LINHAS; x = x + 1)
                {
                    if (matriz[m][i][j] == matriz[m][x][j])
                    {
                        valido = 0;
                    }
                }
            }
        }

        for (int linha_i = 0; linha_i < 9; linha_i = linha_i + 3)
        {
            for (int coluna_i = 0; coluna_i < 9; coluna_i = coluna_i + 3)
            {
                
                for (int i = 0; i < 9; i = i + 1)
                {
                    int r1 = linha_i + (i / 3);
                    int c1 = coluna_i + (i % 3);
                    for (int j = i + 1; j < 9; j = j + 1)
                    {
                        int r2 = linha_i + (j / 3);
                        int c2 = coluna_i + (j % 3);
                        if (matriz[m][r1][c1] == matriz[m][r2][c2])
                        {
                            valido = 0;
                        }
                    }
                }
            }
        }

        verifica[m] = valido;
        m = m + 1;
    }

    while (l < instancia)
    {
        printf("Instancia %d\n", l + 1);
        if (verifica[l] == 0)
        {
            printf("NAO\n\n");
        }
        else
        {
            printf("SIM\n\n");
        }
        l = l + 1;
    }

    free(verifica);
    free(matriz);
}
