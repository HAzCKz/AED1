#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;

    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
        {
            break;
        }

        int vetor[1000];

        while (1)
        {
            scanf("%d", &vetor[0]);

            if (vetor[0] == 0)
            {
                printf("\n");
                break;
            }

            for (int i = 1; i < n; i++)
            {
                scanf("%d", &vetor[i]);
            }

            int pilha[1000];
            int top = 0;
            int prox = 1;
            int i = 0;

            while (i < n)
            {
                if (prox <= n && prox == vetor[i])
                {
                    prox++;
                    i++;
                }
                else if (top > 0 && pilha[top - 1] == vetor[i])
                {
                    top--;
                    i++;
                }
                else if (prox <= n)
                {
                    pilha[top++] = prox;
                    prox++;
                }
                else
                {
                    break;
                }
            }

            if (i == n)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
}
