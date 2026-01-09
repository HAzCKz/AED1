#include <stdio.h>
#include <stdlib.h>

void peneira(int *vetor, int inicio, int fim);
void heapsort(int *vetor, int n);

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

            heapsort(alturas, n);

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
            nc--;
        }
    }

}

void heapsort(int *vetor, int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        peneira(vetor, i, n - 1);
    }

    for (int i = n - 1; i >= 1; i--)
    {
        int aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;

        peneira(vetor, 0, i - 1);
    }
}

void peneira(int *vetor, int inicio, int fim)
{
    int pai = inicio;
    int filho = (2 * pai) + 1;
    int aux = vetor[inicio];

    while (filho <= fim)
    {
        if (filho < fim && vetor[filho] < vetor[filho + 1])
        {
            filho = filho + 1;
        }

        if (aux < vetor[filho])
        {
            vetor[pai] = vetor[filho];
            pai = filho;
            filho = (2 * pai) + 1;
        }
        else
        {
            break;
        }
    }
    
    vetor[pai] = aux;
}