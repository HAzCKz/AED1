#include <stdio.h>

int adj[26][26];
int visited[26];

// DFS simples
void dfs(int v, int V, int comp[], int *count) {
    visited[v] = 1;
    comp[(*count)++] = v;
    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, V, comp, count);
        }
    }
}

// Insertion sort para ordenar componentes
void sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int t = 1; t <= N; t++) {
        int V, E;
        scanf("%d %d", &V, &E);

        // Inicializar arrays manualmente
        for (int i = 0; i < 26; i++) {
            visited[i] = 0;
            for (int j = 0; j < 26; j++) {
                adj[i][j] = 0;
            }
        }

        // Ler arestas
        for (int i = 0; i < E; i++) {
            char u, v;
            scanf(" %c %c", &u, &v);
            int a = u - 'a';
            int b = v - 'a';
            adj[a][b] = 1;
            adj[b][a] = 1;
        }

        printf("Case #%d:\n", t);
        int components = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                int comp[26], count = 0;
                dfs(i, V, comp, &count);
                sort(comp, count);
                for (int j = 0; j < count; j++) {
                    printf("%c,", comp[j] + 'a');
                }
                printf("\n");
                components++;
            }
        }

        printf("%d connected components\n\n", components);
    }

    return 0;
}
