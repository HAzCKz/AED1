#include <stdio.h>

#define INF 1000000000

int matriz[501][501];
int dist[501];
int visitado[501];
int N, E;

void dijkstra(int origem) {
    int i, j;

    // Inicialização para cada nova busca
    i = 1;
    while (i <= N) {
        dist[i] = INF;
        visitado[i] = 0; // 0 para falso, 1 para verdadeiro
        i = i + 1;
    }

    dist[origem] = 0;

    i = 1;
    while (i <= N) {
        // 1. Encontrar o nó com a menor distância que ainda não foi visitado
        int u = -1;
        int min_dist = INF;

        j = 1;
        while (j <= N) {
            if (visitado[j] == 0) {
                if (dist[j] < min_dist) {
                    min_dist = dist[j];
                    u = j;
                }
            }
            j = j + 1;
        }

        // Se não encontrou mais ninguém alcançável, para
        if (u == -1) {
            break;
        }

        visitado[u] = 1;

        // 2. Relaxar as arestas (atualizar vizinhos)
        j = 1;
        while (j <= N) {
            if (matriz[u][j] != INF) {
                if (dist[u] + matriz[u][j] < dist[j]) {
                    dist[j] = dist[u] + matriz[u][j];
                }
            }
            j = j + 1;
        }
        i = i + 1;
    }
}

int main() {
    while (scanf("%d %d", &N, &E) == 2 && (N != 0 || E != 0)) {
        int i, j;

        // Limpar matriz
        i = 1;
        while (i <= N) {
            j = 1;
            while (j <= N) {
                matriz[i][j] = INF;
                j = j + 1;
            }
            i = i + 1;
        }

        // Ler arestas
        int x, y, h;
        i = 0;
        while (i < E) {
            scanf("%d %d %d", &x, &y, &h);
            matriz[x][y] = h;

            // Regra do país: se ida e volta existem, custo é 0
            if (matriz[y][x] != INF) {
                matriz[x][y] = 0;
                matriz[y][x] = 0;
            }
            i = i + 1;
        }

        int K, o, d;
        scanf("%d", &K);
        while (K > 0) {
            scanf("%d %d", &o, &d);
            
            dijkstra(o);

            if (dist[d] == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", dist[d]);
            }
            K = K - 1;
        }
        printf("\n");
    }
    return 0;
}