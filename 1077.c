#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 300

int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixaParaPosfixa(char* expressao) {
    char pilha[MAX];
    char resultado[MAX];
    int topo = -1, k = 0;

    for (int i = 0; expressao[i] != '\0'; i++) {
        char ch = expressao[i];

        if (isalnum(ch)) {  // Se for operando (letra ou número)
            resultado[k++] = ch;
        }
        else if (ch == '(') {  // Se for '('
            pilha[++topo] = ch;
        }
        else if (ch == ')') {  // Se for ')'
            while (topo >= 0 && pilha[topo] != '(') {
                resultado[k++] = pilha[topo--];
            }
            topo--;  // Remover o '('
        }
        else {  // Se for operador (+, -, *, /, ^)
            while (topo >= 0 && pilha[topo] != '(' &&
                (precedencia(pilha[topo]) > precedencia(ch) || 
                (precedencia(pilha[topo]) == precedencia(ch) && ch != '^'))) {
                resultado[k++] = pilha[topo--];
            }
            pilha[++topo] = ch;
        }
    }

    // Esvaziar a pilha
    while (topo >= 0) {
        resultado[k++] = pilha[topo--];
    }

    resultado[k] = '\0';  // Terminar a string de resultado
    printf("%s\n", resultado);
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();  // Para consumir o '\n' após o número de casos

    for (int i = 0; i < N; i++) {
        char expressao[MAX];
        fgets(expressao, sizeof(expressao), stdin);
        expressao[strcspn(expressao, "\n")] = 0;  // Remover o '\n' da entrada
        infixaParaPosfixa(expressao);
    }

    return 0;
}
