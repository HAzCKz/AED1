#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

int main()
{
    int instancia = 0, k = 0, l = 0;    

    scanf("%i", &instancia);

    int matriz[instancia][LINHAS][COLUNAS];

    while (k < instancia)
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

    while (l < instancia)
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
    }
    

    
}