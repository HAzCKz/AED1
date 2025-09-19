#include <stdio.h>

#define LINHAS 9
#define COLUNAS 9

int main()
{
    int instancia = 0, k = 0, l = 0, m = 0;  
    
    scanf("%i", &instancia);

    int verifica[instancia], verifica_3 = 0;

    int matriz[instancia][LINHAS][COLUNAS];

    while (k < instancia) // Leitura dos elementos das matrizes
    {
        for (int i = 0; i < LINHAS; i++)
        {
            for (int j = 0; j < COLUNAS; j++)
            {
                scanf("%i", &matriz[k][i][j]);
            }
        }
        k++;
    }


    while (m < instancia)
    {
        int valido = 1;


        for (int i = 0; i < LINHAS; i++)
        {
            for (int j = 0; j < COLUNAS; j++)
            {
                if (matriz[m][i][j] < 1 || matriz[m][i][j] > 9)
                {
                    valido = 1;
                }
            }
        }
        
        // verificação das LINHAS
        for (int i = 0; i < LINHAS; i++) {
            for (int j = 0; j < COLUNAS; j++) {
                for (int k = j + 1; k < COLUNAS; k++) {
                    if (matriz[m][i][j] == matriz[m][i][k]) {
                        valido = 0; // repetição na linha
                    }
                }
            }
        }

        // verificação das COLUNAS
        for (int j = 0; j < COLUNAS; j++) {
            for (int i = 0; i < LINHAS; i++) {
                for (int k = i + 1; k < LINHAS; k++) {
                    if (matriz[m][i][j] == matriz[m][k][j]) {
                        valido = 0; // repetição na coluna
                    }
                }
            }
        }

        for (int bi = 0; bi < 9; bi += 3) {       // linha inicial do bloco
            for (int bj = 0; bj < 9; bj += 3) {   // coluna inicial do bloco
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        for (int k = 0; k < 3; k++) {
                            for (int l = 0; l < 3; l++) {
                                if (!(i == k && j == l)) {
                                    if (matriz[m][bi+i][bj+j] == matriz[m][bi+k][bj+l]) {
                                        valido = 0; // repetição no bloco
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        verifica[m] = valido;
        m++;
    }


    while (l < instancia) // Exibicao das matrizes
    {
        /*for (int i = 0; i < LINHAS; i++)
        {
            for (int j = 0; j < COLUNAS; j++)
            {
                printf("%i", matriz[l][i][j]);
            }
            printf("\n");
        }
        printf("\n");*/


        if (verifica[l] == 0)
        {
            printf("Instancia %d\n", l+1);
            printf("NAO\n\n");

        }
        else
        {
            printf("Instancia %d\n", l+1);
            printf("SIM\n\n");
        }
        l++;
    }

    
}