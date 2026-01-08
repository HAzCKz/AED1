#include <stdio.h>

void dfs(int u);

int MATRIZ[100][100];
int VETOR[100];
int vertices, res;

int main()
{
    int t = 0;
    scanf("%d", &t);

    while (t > 0)
    {
        int primeiro = 0, aresta = 0, a = 0, b = 0;

        scanf("%d", &primeiro);
        scanf("%d", &vertices);
        scanf("%d", &aresta);


        for (int i = 0; i < vertices; i++)
        {
            VETOR[i] = 0;

            for (int j = 0; j < vertices; j++)
            {
                MATRIZ[i][j] = 0;
            }
        }

        for (int i = 0; i < aresta; i++)
        {
            scanf("%d", &a);
            scanf("%d", &b);

            MATRIZ[a][b] = MATRIZ[b][a] = 1;
        }

        res = 0;

        dfs(primeiro);

        printf("%d\n", res);

        t--;
    }

}

void dfs(int u)
{
    VETOR[u] = 1;

    for (int v = 0; v < vertices; v++)
    {
        if (MATRIZ[u][v] && VETOR[v] == 0)
        {
            res++;    // ida
            dfs(v);
            res++;    // volta
        }
    }
}
