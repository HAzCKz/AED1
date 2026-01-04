#include <stdio.h>
#include <stdlib.h>

#define INFINITO 999999
#define MAX_CIDADES 255

int grafo[MAX_CIDADES][MAX_CIDADES];
int dist[MAX_CIDADES];
int visitado[MAX_CIDADES];

void resolver_dijkstra(int inicio, int n) {
    int i, j, u, v;

    for (i = 0; i < n; i = i + 1) {
        dist[i] = INFINITO;
        visitado[i] = 0;
    }

    dist[inicio] = 0;

    for (i = 0; i < n; i = i + 1) {
        u = -1;
        
        // Busca o vértice não visitado com a menor distância atual
        for (v = 0; v < n; v = v + 1) {
            if (visitado[v] == 0) {
                if (u == -1 || dist[v] < dist[u]) {
                    u = v;
                }
            }
        }

        // Se não houver mais vértices alcançáveis, encerra
        if (dist[u] == INFINITO) {
            break;
        }

        visitado[u] = 1;

        // Relaxamento das arestas
        for (v = 0; v < n; v = v + 1) {
            if (grafo[u][v] != INFINITO) {
                if (dist[u] + grafo[u][v] < dist[v]) {
                    dist[v] = dist[u] + grafo[u][v];
                }
            }
        }
    }
}

int main() {
    int N, M, C, K;
    int u, v, p, i, j;

    // Leitura dos parâmetros: N(cidades), M(estradas), C(rota), K(conserto)
    while (scanf("%d %d %d %d", &N, &M, &C, &K) == 4) {
        // Verificação de parada extensa
        if (N == 0 && M == 0 && C == 0 && K == 0) {
            break;
        }

        // Inicializa a matriz de adjacência com valor de "infinito"
        for (i = 0; i < N; i = i + 1) {
            for (j = 0; j < N; j = j + 1) {
                grafo[i][j] = INFINITO;
            }
        }

        for (i = 0; i < M; i = i + 1) {
            scanf("%d %d %d", &u, &v, &p);

            // Regras de movimentação baseadas na Rota de Serviço (0 até C-1)
            
            // Caso 1: Ambas as cidades estão dentro da rota de serviço
            if (u < C && v < C) {
                // A regra diz que se entrar na rota, deve seguir a sequência.
                // Portanto, só permitimos o caminho no sentido u -> u+1.
                if (u - v == 1) {
                    grafo[v][u] = p;
                } else if (v - u == 1) {
                    grafo[u][v] = p;
                }
            }
            // Caso 2: u está na rota e v está fora
            else if (u < C && v >= C) {
                // Só é possível ir de v (fora) para u (dentro)
                grafo[v][u] = p;
            }
            // Caso 3: v está na rota e u está fora
            else if (v < C && u >= C) {
                // Só é possível ir de u (fora) para v (dentro)
                grafo[u][v] = p;
            }
            // Caso 4: Ambas estão fora da rota de serviço
            else if (u >= C && v >= C) {
                // Movimentação livre (mão dupla)
                grafo[u][v] = p;
                grafo[v][u] = p;
            }
        }

        resolver_dijkstra(K, N);

        // O resultado esperado é o custo para chegar no destino final da rota (C-1)
        printf("%d\n", dist[C - 1]);
    }

    return 0;
}