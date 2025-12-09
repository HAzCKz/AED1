#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    for (int t = 0; t < N; t++) {
        int M, C;
        scanf("%d %d", &M, &C);

        int **table = (int**) malloc(M * sizeof(int*));
        for (int i = 0; i < M; i++) {
            table[i] = (int*) malloc(C * sizeof(int));
            for (int j = 0; j < C; j++) {
                table[i][j] = 0; 
            }
        }

        for (int i = 0; i < C; i++) {
            int key;
            scanf("%d", &key);
            int slot = key % M;

            for (int j = 0; j < C; j++) {
                if (table[slot][j] == 0) {
                    table[slot][j] = key;
                    break;
                }
            }
        }


        for (int i = 0; i < M; i++) {
            printf("%d -> ", i);
            int j = 0;
            int printed = 0;
            while (j < C && table[i][j] != 0) {
                printf("%d -> ", table[i][j]);
                printed = 1;
                j++;
            }
            printf("\\\n");
        }

        if (t != N - 1) printf("\n");


        for (int i = 0; i < M; i++) free(table[i]);
        free(table);
    }

    return 0;
}
