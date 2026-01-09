#include <stdio.h>
#include <stdlib.h>

void quicksort(int *vetor, int esq, int dir);

int alturas[3000001];

int main()
{
    int nc = 0;

    if (scanf("%d", &nc) == 1)
    {
        while (nc > 0)
        {
            int n = 0;
            scanf("%d", &n);

            for (int i = 0; i < n; i++)
            {
                scanf("%d", &alturas[i]);
            }

            quicksort(alturas, 0, n - 1);

            for (int i = 0; i < n; i++)
            {
                if (i == n - 1)
                {
                    printf("%d", alturas[i]);
                }
                else
                {
                    printf("%d ", alturas[i]);
                }
            }

            printf("\n");
            nc = nc - 1;
        }
    }

}

void quicksort(int *vetor, int esq, int dir)
{
    int i = esq;
    int j = dir;
    int pivo = vetor[(esq + dir) / 2];

    while (i <= j)
    {
        while (vetor[i] < pivo)
        {
            i = i + 1;
        }

        while (vetor[j] > pivo)
        {
            j = j - 1;
        }

        if (i <= j)
        {
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            
            i = i + 1;
            j = j - 1;
        }
    }

    if (esq < j)
    {
        quicksort(vetor, esq, j);
    }

    if (i < dir)
    {
        quicksort(vetor, i, dir);
    }
}
