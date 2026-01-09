#include <stdio.h>

#define INF 999999

int matriz[501][501];
int dist[501];
int visitado[501];
int N = 0, E = 0;

void dijkstra(int origem) ;

int main() {
    while (scanf("%d %d", &N, &E) == 2 && (N != 0 || E != 0))
    {
        int i = 0 , j = 0;

        i = 1;

        while (i <= N)
        {
            j = 1;

            while (j <= N)
            {
                matriz[i][j] = INF;
                j++;;
            }

            i++;
        }

        int x = 0, y = 0, h = 0;

        i = 0;

        while (i < E)
        {
            scanf("%d %d %d", &x, &y, &h);
            matriz[x][y] = h;

            if (matriz[y][x] != INF)
            {
                matriz[x][y] = 0;
                matriz[y][x] = 0;
            }
            i++;
        }

        int K = 0, o = 0, d = 0;
        scanf("%d", &K);

        while (K > 0)
        {
            scanf("%d %d", &o, &d);
            
            dijkstra(o);

            if (dist[d] == INF)
            {
                printf("Nao e possivel entregar a carta\n");
            }
            else
            {
                printf("%d\n", dist[d]);
            }
            K--;;
        }
        printf("\n");
    }
}

void dijkstra(int origem)
{
    int i = 0, j = 0;

    i = 1;

    while (i <= N)
    {
        dist[i] = INF;
        visitado[i] = 0;
        i = i + 1;
    }

    dist[origem] = 0;

    i = 1;

    while (i <= N)
    {
        int u = -1;
        int min_dist = INF;

        j = 1;

        while (j <= N)
        {
            if (visitado[j] == 0)
            {
                if (dist[j] < min_dist)
                {
                    min_dist = dist[j];
                    u = j;
                }
            }
            j++;
        }

        if (u == -1)
        {
            break;
        }

        visitado[u] = 1;

        j = 1;

        while (j <= N)
        {
            if (matriz[u][j] != INF)
            {
                if (dist[u] + matriz[u][j] < dist[j])
                {
                    dist[j] = dist[u] + matriz[u][j];
                }
            }
            j++;
        }
        i++;
    }
}
