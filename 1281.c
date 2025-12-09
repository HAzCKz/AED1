#include <stdio.h>
#include <string.h>

#define MAXM 1005
#define MAXNOME 55

char nomes[MAXM][MAXNOME];
double precos[MAXM];

int busca(char *nome, int m);

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M;
        scanf("%d", &M);

        for (int i = 0; i < M; i++) {
            scanf("%s %lf", nomes[i], &precos[i]);
        }

        int P;
        scanf("%d", &P);

        double total = 0.0;

        for (int i = 0; i < P; i++) {
            char nome[MAXNOME];
            int qtd;
            scanf("%s %d", nome, &qtd);

            int idx = busca(nome, M);
            if (idx != -1) {
                total += precos[idx] * qtd;
            }
        }

        printf("R$ %.2lf\n", total);
    }

    return 0;
}

int busca(char *nome, int m) {
    for (int i = 0; i < m; i++) {
        if (strcmp(nome, nomes[i]) == 0)
            return i;
    }
    return -1;
}
