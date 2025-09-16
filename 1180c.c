#include <stdio.h>
#include <stdlib.h>

int acha_Menor(int *v, int *n);

int main()
{
    int *num = malloc(sizeof(int));
    int *vetor;

    scanf("%i", num);

    vetor = (int *) malloc(*num * sizeof(int));

    int *menor = vetor;

    if (vetor == NULL)
    {
        printf("Erro!");
        return 1;
    }

    for (int i = 0; i < *num; i++)
    {
        scanf("%i", vetor + i);
    }

    
    for (int i = 0; i < *num; i++)
    {
        if (*menor > *vetor)
        {
            *menor = *vetor;
        }
        vetor++;
    }

    printf("O menor do vetor: %i", *menor);
}
