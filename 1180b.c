#include <stdio.h>

int main ()
{
    int N, menor, posicao;

    int *tamanho = &N;

    scanf("%i", tamanho);
    
    int X[*tamanho];

    int *end_x = X;

    for (int i = 0; i < *tamanho; i++)
    {
        scanf("%i", end_x);
        end_x++;
    }

    end_x = X;

    menor = *end_x;

    for (int i = 0; i < *tamanho; i++)
    {
        if (*end_x <= menor)
        {
            menor = *end_x;
            posicao = i;
        }
        end_x++;
    }

    printf("Menor: %i\n", menor);
    printf("Posicao %i\n", posicao);
}