#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000
#define MAXC 10001
#define MAXV 100005 

int head[MAXC], para[MAXV], peso[MAXV], prox[MAXV];
int total_arestas = 0;

int dist[MAXC][2];

typedef struct
{
    int u, custo, estado; 
} No;

No heap[MAXV * 2];
int tam_heap = 0;

void Adiciona_Aresta(int u, int v, int g);
void push(int u, int c, int s);
No pop();

int main()
{
    int C = 0, V = 0, i = 0;

    if (scanf("%d %d", &C, &V) != 2) return 0;

    for (i = 1; i <= C; i++)
    {
        head[i] = 0;
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    for (i = 0; i < V; i++)
    {
        int u, v, g;
        scanf("%d %d %d", &u, &v, &g);
        Adiciona_Aresta(u, v, g);
        Adiciona_Aresta(v, u, g);
    }

    dist[1][0] = 0;
    push(1, 0, 0);

    while (tam_heap > 0)
    {
        No atual = pop();
        int u = atual.u;
        int d = atual.custo;
        int s = atual.estado;

        if (d > dist[u][s]) continue;

        int proximo_s = 1 - s; 

        for (i = head[u]; i != 0; i = prox[i])
        {
            int v = para[i];
            int g = peso[i];

            if (dist[u][s] + g < dist[v][proximo_s])
            {
                dist[v][proximo_s] = dist[u][s] + g;
                push(v, dist[v][proximo_s], proximo_s);
            }
        }
    }

    if (dist[C][0] == INF)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", dist[C][0]);
    }

}

void Adiciona_Aresta(int u, int v, int g)
{
    total_arestas = total_arestas + 1;
    para[total_arestas] = v;
    peso[total_arestas] = g;
    prox[total_arestas] = head[u];
    head[u] = total_arestas;
}

void push(int u, int c, int s)
{
    int i = tam_heap;
    tam_heap = tam_heap + 1;
    while (i > 0 && heap[(i - 1) / 2].custo > c)
    {
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i].u = u;
    heap[i].custo = c;
    heap[i].estado = s;
}

No pop()
{
    No min = heap[0];
    tam_heap = tam_heap - 1;
    heap[0] = heap[tam_heap];
    int i = 0;
    while (i * 2 + 1 < tam_heap)
    {
        int f = i * 2 + 1;
        if (f + 1 < tam_heap && heap[f + 1].custo < heap[f].custo) f = f + 1;
        if (heap[i].custo <= heap[f].custo) break;
        No t = heap[i]; heap[i] = heap[f]; heap[f] = t;
        i = f;
    }
    return min;
}