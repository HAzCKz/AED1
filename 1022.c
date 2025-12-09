#include <stdio.h>

int mdc(int a, int b);

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int n1, d1, n2, d2;
        char op, barra1, barra2;
        scanf("%d %c %d %c %d %c %d", &n1, &barra1, &d1, &op, &n2, &barra2, &d2);

        int resN, resD;

        if (op == '+') {
            resN = n1*d2 + n2*d1;
            resD = d1*d2;
        } else if (op == '-') {
            resN = n1*d2 - n2*d1;
            resD = d1*d2;
        } else if (op == '*') {
            resN = n1 * n2;
            resD = d1 * d2;
        } else if (op == '/') {
            resN = n1 * d2;
            resD = n2 * d1;
        }

        int absN = resN;
        int absD = resD;

        if (absN < 0) absN = -absN;
        if (absD < 0) absD = -absD;

        int divisor = mdc(absN, absD);

        int simpN = resN / divisor;
        int simpD = resD / divisor;

        printf("%d/%d = %d/%d\n", resN, resD, simpN, simpD);
    }

    return 0;
}

int mdc(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
