#include <stdio.h>

// Função para inverter os dígitos do número
int inverter_numero(int n) {
    int reverso = 0;
    while (n > 0) {
        reverso = (reverso * 10) + (n % 10);
        n = n / 10;
    }
    return reverso;
}

void resolver() {
    int A, B;
    if (scanf("%d %d", &A, &B) != 2) return;

    if (A == B) {
        printf("0\n");
        return;
    }

    // dist armazena a quantidade de cliques e serve como marcador de visitados
    int dist[10000];
    int i = 0;
    while (i < 10000) {
        dist[i] = -1; // -1 significa que o número não foi visitado
        i = i + 1;
    }

    // Implementação de uma fila simples usando um array
    int fila[10000];
    int inicio = 0;
    int fim = 0;

    // Inicialização
    dist[A] = 0;
    fila[fim] = A;
    fim = fim + 1;

    // Enquanto a fila não estiver vazia
    while (inicio < fim) {
        int atual = fila[inicio];
        inicio = inicio + 1;

        // Se chegamos no alvo, imprimimos e saímos da função
        if (atual == B) {
            printf("%d\n", dist[atual]);
            return;
        }

        // Opção 1: Somar 1
        int proximo_soma = atual + 1;
        if (proximo_soma < 10000) {
            if (dist[proximo_soma] == -1) {
                dist[proximo_soma] = dist[atual] + 1;
                fila[fim] = proximo_soma;
                fim = fim + 1;
            }
        }

        // Opção 2: Inverter o número
        int proximo_inverte = inverter_numero(atual);
        if (proximo_inverte < 10000) {
            if (dist[proximo_inverte] == -1) {
                dist[proximo_inverte] = dist[atual] + 1;
                fila[fim] = proximo_inverte;
                fim = fim + 1;
            }
        }
    }
}

int main() {
    int T;
    if (scanf("%d", &T) == 1) {
        while (T > 0) {
            resolver();
            T = T - 1;
        }
    }
    return 0;
}