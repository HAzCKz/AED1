#include <stdio.h>
#include <string.h>

int main() {

    int N;

    while (scanf("%d", &N) && N) {

        char entrada[27], saida[27];
        
        for (int i = 0; i < N; i++)
        {
            scanf(" %c", &entrada[i]);
        } 
        for (int i = 0; i < N; i++)
        {
            scanf(" %c", &saida[i]);
        } 

        char pilha[27];
        int top = -1; // pilha vazia
        int idxE = 0, idxS = 0;
        int impossible = 0;

        while (idxS < N) {
            if (top >= 0 && pilha[top] == saida[idxS]) {
                printf("R");
                top--;
                idxS++;
            } else if (idxE < N) {
                pilha[++top] = entrada[idxE++];
                printf("I");
            } else {
                impossible = 1;
                break;
            }
        }

        if (impossible) printf(" Impossible");
        printf("\n");
    }
    return 0;
}
