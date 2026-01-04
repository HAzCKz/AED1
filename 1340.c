#include <stdio.h>
#include <stdlib.h>

void resolver() {
    int n;
    while (scanf("%d", &n) != EOF) {
        // Estruturas de dados (vetores simples)
        int pilha[1005], topo_pilha = 0;
        int fila[1005], frente_fila = 0, tras_fila = 0;
        int pq[1005], tam_pq = 0;

        // Flags para identificar as estruturas
        int eh_pilha = 1;
        int eh_fila = 1;
        int eh_pq = 1;

        int i;
        for (i = 0; i < n; i = i + 1) {
            int comando, x;
            scanf("%d %d", &comando, &x);

            if (comando == 1) {
                // Inserir na Pilha
                pilha[topo_pilha] = x;
                topo_pilha = topo_pilha + 1;

                // Inserir na Fila
                fila[tras_fila] = x;
                tras_fila = tras_fila + 1;

                // Inserir na Priority Queue
                pq[tam_pq] = x;
                tam_pq = tam_pq + 1;
            } 
            else if (comando == 2) {
                // Testar Pilha (LIFO)
                if (topo_pilha == 0) {
                    eh_pilha = 0;
                } else {
                    int elemento = pilha[topo_pilha - 1];
                    topo_pilha = topo_pilha - 1;
                    if (elemento != x) {
                        eh_pilha = 0;
                    }
                }

                // Testar Fila (FIFO)
                if (frente_fila == tras_fila) {
                    eh_fila = 0;
                } else {
                    int elemento = fila[frente_fila];
                    frente_fila = frente_fila + 1;
                    if (elemento != x) {
                        eh_fila = 0;
                    }
                }

                // Testar Priority Queue (Maior sai primeiro)
                if (tam_pq == 0) {
                    eh_pq = 0;
                } else {
                    // Busca o índice do maior elemento
                    int indice_maior = 0;
                    int j;
                    for (j = 1; j < tam_pq; j = j + 1) {
                        if (pq[j] > pq[indice_maior]) {
                            indice_maior = j;
                        }
                    }
                    
                    int elemento_maior = pq[indice_maior];
                    
                    // Remove o elemento "puxando" os outros para cobrir o buraco
                    for (j = indice_maior; j < tam_pq - 1; j = j + 1) {
                        pq[j] = pq[j + 1];
                    }
                    tam_pq = tam_pq - 1;

                    if (elemento_maior != x) {
                        eh_pq = 0;
                    }
                }
            }
        }

        // Avaliação dos resultados
        int total = eh_pilha + eh_fila + eh_pq;

        if (total == 0) {
            printf("impossible\n");
        } else if (total > 1) {
            printf("not sure\n");
        } else if (eh_pilha == 1) {
            printf("stack\n");
        } else if (eh_fila == 1) {
            printf("queue\n");
        } else if (eh_pq == 1) {
            printf("priority queue\n");
        }
    }
}

int main() {
    resolver();
    return 0;
}