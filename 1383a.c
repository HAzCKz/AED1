#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

int main()
{
    int instancia = 0, k = 0, l = 0, m = 0;  
    
    int valor_coluna = 0, valor_linha = 0, verifica = 0, erro = 0;

    scanf("%i", &instancia);

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

    int ii = 0, jj = 0;

    while (m < instancia)
    {
        for (ii = 0; ii < LINHAS; ii++)
        {

            valor_linha = matriz[m][ii][0];

            for (jj = 1; jj < COLUNAS; jj++)
            {        
                valor_coluna = matriz[m][0][jj];        
                if(valor_linha == matriz[m][ii][jj] || valor_coluna == matriz[m][ii][jj])
                {
                    erro = 1;
                }
            }
            
        }
        m++;
    }


    while (l < instancia) // Exibicao das matrizes
    {
        for (int i = 0; i < LINHAS; i++)
        {
            for (int j = 0; j < COLUNAS; j++)
            {
                printf("%i", matriz[l][i][j]);
            }
            printf("\n");
        }
        printf("\n");
        l++;

        if (erro == 0)
        {
            printf("O sudoku esta correto!\n");
        }
        else
        {
            printf("O sudoku esta errado!\n");
        }
    }
    

    
}