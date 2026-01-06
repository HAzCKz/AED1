#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *num = malloc(sizeof(int));
    int *vetor;
    int posicao = 0;

    scanf("%i", num);

    vetor = (int *) malloc(*num * sizeof(int));

    if (vetor == NULL)
    {
        printf("Erro!");
        return 1;
    }

    for (int i = 0; i < *num; i++)
    {
        scanf("%i", vetor + i);
    }

    int *menor = vetor;
    
    for (int i = 0; i < *num; i++)
    {
        if (*menor > *vetor)
        {
            *menor = *vetor;
            posicao = i;
        }
        vetor++;
    }

    printf("Menor valor: %i\n", *menor);
    printf("Posicao: %i\n", posicao);
}
