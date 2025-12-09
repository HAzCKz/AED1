#include <stdio.h>

#define MAXN 10005
#define MAXM 30005

typedef struct {
    int to;
    int next;
} Edge;

Edge edges[MAXM];
int head[MAXN];
int edge_count;

int state[MAXN]; // 0: não visitado, 1: visitando, 2: visitado
int found_cycle;

void dfs(int u) {
    if (found_cycle) return; // já encontrou ciclo
    state[u] = 1; // visitando
    for (int e = head[u]; e != -1; e = edges[e].next) {
        int v = edges[e].to;
        if (state[v] == 0) {
            dfs(v);
        } else if (state[v] == 1) {
            found_cycle = 1; // ciclo detectado
            return;
        }
    }
    state[u] = 2; // visitado
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int N, M;
        scanf("%d %d", &N, &M);

        // Inicializar grafo
        for (int i = 1; i <= N; i++) head[i] = -1;
        edge_count = 0;

        // Ler arestas
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            edges[edge_count].to = B;
            edges[edge_count].next = head[A];
            head[A] = edge_count++;
        }

        // Inicializar estado
        for (int i = 1; i <= N; i++) state[i] = 0;
        found_cycle = 0;

        // Detectar ciclos
        for (int i = 1; i <= N; i++) {
            if (state[i] == 0) dfs(i);
        }

        if (found_cycle) printf("SIM\n");
        else printf("NAO\n");
    }
    return 0;
}
