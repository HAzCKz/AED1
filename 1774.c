#include <stdio.h>
#include <stdlib.h>

#define MAXC 200
#define MAXR 60

typedef struct {
    int u, v, p;
} Edge;

Edge edges[MAXC];
int parent[MAXR+1];
int R, C;

// Função de união-find
int find(int x) {
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void union_sets(int x, int y) {
    int a = find(x);
    int b = find(y);
    if(a != b) parent[b] = a;
}

// Comparação para qsort
int cmp(const void *a, const void *b) {
    Edge *ea = (Edge*)a;
    Edge *eb = (Edge*)b;
    return ea->p - eb->p;
}

int main() {
    scanf("%d %d", &R, &C);

    for(int i=0;i<C;i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].p);
    }

    // Inicializar union-find
    for(int i=1;i<=R;i++) parent[i] = i;

    // Ordenar arestas pelo peso
    qsort(edges, C, sizeof(Edge), cmp);

    int total = 0;
    for(int i=0;i<C;i++) {
        if(find(edges[i].u) != find(edges[i].v)) {
            union_sets(edges[i].u, edges[i].v);
            total += edges[i].p;
        }
    }

    printf("%d\n", total);
    return 0;
}
