#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v;
    int w;
} Edge;

Edge edges[50000];
int parent[40000];

void merge(Edge arr[], int l, int m, int r);
void mergeSort(Edge arr[], int l, int r);
int uf_find(int x);
void uf_union(int x, int y);


int main()
{
    while (1)
    {
        int M = 0, N = 0;
        scanf("%d %d", &M, &N);

        if (M == 0 && N == 0)
        {
            break;
        }

        for (int i = 0; i < N; i++)
        {
            int X = 0, Y = 0, Z = 0;
            scanf("%d %d %d", &X, &Y, &Z);
            edges[i].u = X;
            edges[i].v = Y;
            edges[i].w = Z;
        }

        for (int i = 0; i < M; i++) parent[i] = i;

        mergeSort(edges, 0, N - 1);

        long long mst_cost = 0;
        for (int i = 0; i < N; i++)
        {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;
            if (uf_find(u) != uf_find(v))
            {
                uf_union(u, v);
                mst_cost += w;
            }
        }

        printf("%lld\n", mst_cost);
    }
}

void merge(Edge arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    Edge *L = malloc(n1 * sizeof(Edge));
    Edge *R = malloc(n2 * sizeof(Edge));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].w <= R[j].w) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(Edge arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int uf_find(int x)
{
    while (parent[x] != x) x = parent[x];
    return x;
}

void uf_union(int x, int y)
{
    int px = uf_find(x);
    int py = uf_find(y);
    if (px != py) parent[py] = px;
}