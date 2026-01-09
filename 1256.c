#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;

    scanf("%d", &n);

    for (int t = 0; t < n; t++)
    {
        int m = 0, c = 0;

        scanf("%d", &m);
        scanf("%d", &c);

        int **tabela = malloc(m * sizeof(int*));

        for (int i = 0; i < m; i++)
        {
            tabela[i] = malloc(c * sizeof(int));

            for (int j = 0; j < c; j++)
            {
                tabela[i][j] = -1;
            }
        }

        for (int i = 0; i < c; i++)
        {
            int chave;

            scanf("%d", &chave);

            int slot = chave % m;

            for (int j = 0; j < c; j++)
            {
                if (tabela[slot][j] == -1)
                {
                    tabela[slot][j] = chave;
                    break;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            printf("%d -> ", i);

            for (int j = 0; j < c; j++)
            {
                if (tabela[i][j] != -1)
                {
                    printf("%d -> ", tabela[i][j]);
                }
            }

            printf("\\\n");
        }

        if (t != n - 1)
        {
            printf("\n");
        }

        free(tabela);
    }

}
