#include <stdio.h>

int main() {
    int NC;
    scanf("%d", &NC);

    for (int c = 0; c < NC; c++) {
        int N;
        scanf("%d", &N);
        int alturas[N];

        for (int i = 0; i < N; i++) {
            scanf("%d", &alturas[i]);
        }

        // Insertion Sort diretamente no main
        for (int i = 1; i < N; i++) {
            int key = alturas[i];
            int j = i - 1;
            while (j >= 0 && alturas[j] > key) {
                alturas[j + 1] = alturas[j];
                j--;
            }
            alturas[j + 1] = key;
        }

        // Impressão
        for (int i = 0; i < N; i++) {
            if (i != 0) printf(" ");
            printf("%d", alturas[i]);
        }
        printf("\n");
    }

    return 0;
}
