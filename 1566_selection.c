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

        for (int i = 0; i < N - 1; i++) {

            int min_idx = i;
            for (int j = i + 1; j < N; j++) {
                if (alturas[j] < alturas[min_idx]) {
                    min_idx = j;
                }
            }

            int temp = alturas[i];
            alturas[i] = alturas[min_idx];
            alturas[min_idx] = temp;
        }

        for (int i = 0; i < N; i++) {
            if (i != 0) printf(" ");
            printf("%d", alturas[i]);
        }
        printf("\n");
    }

    return 0;
}
