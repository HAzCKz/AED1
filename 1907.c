#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar as coordenadas de cada pixel
typedef struct {
    int x;
    int y;
} Ponto;

// Matriz global para evitar sobrecarga na pilha de execução
char mapa[1030][1030];
Ponto pilha[1100000]; // Pilha para a DFS (tamanho N * M)
int topo = -1;

void empilhar(int x, int y) {
    topo++;
    pilha[topo].x = x;
    pilha[topo].y = y;
}

Ponto desempilhar() {
    return pilha[topo--];
}

int main() {
    int N, M;
    int cliques = 0;

    // Lendo as dimensões da imagem
    if (scanf("%d %d", &N, &M) != 2) {
        return 0;
    }

    // Lendo o cenário
    for (int i = 0; i < N; i++) {
        scanf("%s", mapa[i]);
    }

    // Percorrendo cada pixel da matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            
            // Se encontrarmos um pixel branco '.', iniciamos uma nova coloração (clique)
            if (mapa[i][j] == '.') {
                cliques++;
                
                // Iniciamos a DFS manual usando a nossa pilha
                empilhar(i, j);
                mapa[i][j] = 'o'; // Marcamos como colorido (preto) para não repetir

                while (topo != -1) {
                    Ponto atual = desempilhar();

                    // Direções: Cima, Baixo, Esquerda, Direita
                    int dx[] = {-1, 1, 0, 0};
                    int dy[] = {0, 0, -1, 1};

                    for (int k = 0; k < 4; k++) {
                        int nx = atual.x + dx[k];
                        int ny = atual.y + dy[k];

                        // Verificamos se o vizinho está dentro dos limites e se é branco
                        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                            if (mapa[nx][ny] == '.') {
                                mapa[nx][ny] = 'o'; // Marca antes de empilhar para evitar duplicatas na pilha
                                empilhar(nx, ny);
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", cliques);

    return 0;
}