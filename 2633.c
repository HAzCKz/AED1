#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[21];
    int validade;
} Carne;

void ordenar(Carne carnes[], int n);

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        if (N == 0) {
            printf("\n");
            continue;
        }
        Carne carnes[N];
        for (int i = 0; i < N; i++) {
            scanf("%s %d", carnes[i].nome, &carnes[i].validade);
        }
        ordenar(carnes, N);
        for (int i = 0; i < N; i++) {
            if (i > 0) printf(" ");
            printf("%s", carnes[i].nome);
        }
        printf("\n");
    }
    return 0;
}

void ordenar(Carne carnes[], int n) {
    for (int i = 1; i < n; i++) {
        Carne chave = carnes[i];
        int j = i - 1;
        while (j >= 0 && carnes[j].validade > chave.validade) {
            carnes[j + 1] = carnes[j];
            j--;
        }
        carnes[j + 1] = chave;
    }
}
