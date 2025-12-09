#include <stdio.h>
#include <stdlib.h>

#define MAXN 2005

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* adj[MAXN];
Node* adj_rev[MAXN];
int visitado[MAXN];
int N, M;

void add_edge(Node* lista[], int u, int v);
void dfs(Node* lista[], int u);

int main() {
    while (1) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;

        for (int i = 1; i <= N; i++) {
            adj[i] = NULL;
            adj_rev[i] = NULL;
        }

        for (int i = 0; i < M; i++) {
            int V, W, P;
            scanf("%d %d %d", &V, &W, &P);
            add_edge(adj, V, W);
            add_edge(adj_rev, W, V);
            if (P == 2) {
                add_edge(adj, W, V);
                add_edge(adj_rev, V, W);
            }
        }

        int ok = 1;

        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= N; j++) visitado[j] = 0;
            dfs(i == 0 ? adj : adj_rev, 1);
            for (int j = 1; j <= N; j++) {
                if (!visitado[j]) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;
        }

        printf("%d\n", ok);
    }
    return 0;
}

void add_edge(Node* lista[], int u, int v) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->v = v;
    novo->next = lista[u];
    lista[u] = novo;
}

void dfs(Node* lista[], int u) {
    visitado[u] = 1;
    for (Node* p = lista[u]; p != NULL; p = p->next) {
        if (!visitado[p->v]) dfs(lista, p->v);
    }
}
