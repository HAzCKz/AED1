#include <stdio.h>
#include <stdlib.h>

int grafo[255][255];
int dist[255];
int visitado[255];


int main() {
    int cidades = 0, estradas = 0, rota = 0, conserto = 0;
    int u = 0, v = 0, p = 0, i = 0, j = 0;

    while (scanf("%d %d %d %d", &cidades, &estradas, &rota, &conserto) == 4)
    {
        if (cidades == 0 && estradas == 0 && rota == 0 && conserto == 0)
        {
            break;
        }

        for (i = 0; i < cidades; i = i + 1)
        {
            for (j = 0; j < cidades; j = j + 1)
            {
                grafo[i][j] = 999999;
            }
        }

        for (i = 0; i < estradas; i = i + 1)
        {
            scanf("%d %d %d", &u, &v, &p);

            if (u < rota && v < rota)
            {
                if (u - v == 1)
                {
                    grafo[v][u] = p;
                }
                else if (v - u == 1)
                {
                    grafo[u][v] = p;
                }
            }

            else if (u < rota && v >= rota)
            {
                grafo[v][u] = p;
            }

            else if (v < rota && u >= rota)
            {
                grafo[u][v] = p;
            }

            else if (u >= rota && v >= rota)
            {
                grafo[u][v] = p;
                grafo[v][u] = p;
            }
        }

        resolver_dijkstra(conserto, cidades);

        printf("%d\n", dist[rota - 1]);
    }

}

void resolver_dijkstra(int inicio, int n)
{
    int i = 0, j = 0, u = 0, v = 0;

    for (i = 0; i < n; i = i + 1)
    {
        dist[i] = 999999;
        visitado[i] = 0;
    }

    dist[inicio] = 0;

    for (i = 0; i < n; i = i + 1)
    {
        u = -1;
        
        for (v = 0; v < n; v = v + 1) 
        {
            if (visitado[v] == 0)
            {
                if (u == -1 || dist[v] < dist[u])
                {
                    u = v;
                }
            }
        }

        if (dist[u] == 999999)
        {
            break;
        }

        visitado[u] = 1;

        for (v = 0; v < n; v = v + 1)
        {
            if (grafo[u][v] != 999999)
            {
                if (dist[u] + grafo[u][v] < dist[v])
                {
                    dist[v] = dist[u] + grafo[u][v];
                }
            }
        }
    }
}
