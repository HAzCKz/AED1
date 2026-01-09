#include <stdio.h>
#include <string.h>

char MATRIZ[10001][10001];
int VETOR[10001];
int ciclo;

void dfs(int u, int n);

int main()
{
    int t = 0;

    scanf("%d", &t);

    while (t > 0)
    {
        int n = 0, m = 0;

        scanf("%d", &n);
        scanf("%d", &m);

        for (int i = 0; i <= n; i++)
        {
            VETOR[i] = 0;

            for (int j = 0; j <= n; j++)
            {
                MATRIZ[i][j] = 0;
            }
        }

        for (int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d", &a);
            scanf("%d", &b);

            MATRIZ[a][b] = 1; 
        }

        ciclo = 0;

        for (int i = 1; i <= n; i++)
        {
            if (VETOR[i] == 0)
            {
                dfs(i, n);

                if (ciclo == 1)
                {
                    break;
                }
            }
        }

        if (ciclo == 1)
        {
            printf("SIM\n");
        } 
        
        else
        {
            printf("NAO\n");
        }

        t--;
    }
}

void dfs(int u, int n)
{
    VETOR[u] = 1; 

    for (int v = 1; v <= n; v++)
    {
        if (MATRIZ[u][v] == 1)
        {
            if (VETOR[v] == 1)
            {
                ciclo = 1;
                return;
            }
            
            if (VETOR[v] == 0)
            {
                dfs(v, n);

                if (ciclo == 1)
                {
                    return;
                }
            }
        }
    }

    VETOR[u] = 2; 
}
