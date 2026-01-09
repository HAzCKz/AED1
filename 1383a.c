#include <stdio.h>

#define LINHAS 9
#define COLUNAS 9

int main()
{
    int instancia = 0, k = 0, l = 0, m = 0;
    
    scanf("%i", &instancia);

    int verifica[instancia];

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
        
        for (int i = 0; i < LINHAS; i++) 
        {
            for (int j = 0; j < COLUNAS; j++) 
            {
                for (int k = j + 1; k < COLUNAS; k++) 
                {
                    if (matriz[m][i][j] == matriz[m][i][k]) 
                    {
                        valido = 0; 
                    }
                }
            }
        }

        for (int j = 0; j < COLUNAS; j++) 
        {
            for (int i = 0; i < LINHAS; i++) 
            {
                for (int k = i + 1; k < LINHAS; k++) 
                {
                    if (matriz[m][i][j] == matriz[m][k][j]) 
                    {
                        valido = 0; 
                    }
                }
            }
        }

        for (int linha_i = 0; linha_i < 9; linha_i += 3) 
        {       // linha inicial do bloco
            for (int coluna_i = 0; coluna_i < 9; coluna_i += 3) 
            {   // coluna inicial do bloco
                for (int i = 0; i < 3; i++)
                 {
                    for (int j = 0; j < 3; j++) 
                    {
                        for (int k = 0; k < 3; k++) 
                        {
                            for (int l = 0; l < 3; l++) 
                            {
                                if (!(i == k && j == l)) 
                                {
                                    if (matriz[m][linha_i+i][coluna_i+j] == matriz[m][linha_i+k][coluna_i+l]) 
                                    {
                                        valido = 0; 
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


    while (l < instancia) 
    {
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