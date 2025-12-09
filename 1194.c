#include <stdio.h>
#include <string.h>

void PosFixo(char *pre, char *in, int n);

int main() {
    int C;
    scanf("%d", &C);

    for (int t = 0; t < C; t++) {
        int N;
        char pre[55], in[55];
        scanf("%d %s %s", &N, pre, in);
        PosFixo(pre, in, N);
        printf("\n");
    }

    return 0;
}

void PosFixo(char *pre, char *in, int n) {
    if (n == 0) return;

    char raiz = pre[0];

    int i;
    for (i = 0; i < n; i++) {
        if (in[i] == raiz) break;
    }

    PosFixo(pre + 1, in, i);

    PosFixo(pre + 1 + i, in + i + 1, n - i - 1);

    
    putchar(raiz);
}
