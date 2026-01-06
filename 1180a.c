#include <stdio.h>

int main()
{
    int N;
    int posicao, menor;

    scanf("%i", &N);

    int X[N]; 

    for (int i = 0; i < N; i++)
    {
        scanf("%i", &X[i]);
    }

    menor = X[0];

    for (int i = 0; i < N; i++)
    {
        if(X[i] < menor)
        {
            menor = X[i];
            posicao = i;
        }
    }

    printf("Menor valor: %i\n", menor);
    printf("Posicao: %i\n", posicao);
}
