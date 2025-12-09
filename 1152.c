#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v;
    int w;
} Edge;

int cmp(const void *a, const void *b) {
    Edge *ea = (Edge*)a;
    Edge *eb = (Edge*)b;
    return ea->w - eb->w;
}

// Union-Find
int parent[200000];
int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;
}

int main() {
    while (1) {
        int m, n;
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;

        Edge *edges = (Edge*)malloc(n * sizeof(Edge));
        long long total = 0;

        for (int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            edges[i].u = x;
            edges[i].v = y;
            edges[i].w = z;
            total += z;
        }

        qsort(edges, n, sizeof(Edge), cmp);

        for (int i = 0; i < m; i++) parent[i] = i;

        long long mst_cost = 0;
        for (int i = 0; i < n; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;
            if (find(u) != find(v)) {
                unite(u, v);
                mst_cost += w;
            }
        }

        printf("%lld\n", total - mst_cost);
        free(edges);
    }
    return 0;
}
