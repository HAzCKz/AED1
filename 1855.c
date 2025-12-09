#include <stdio.h>

#define MAX 100

char mapa[MAX][MAX];
int visitado[MAX][MAX];

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    getchar(); // consumir o \n
    for(int i=0; i<y; i++) {
        for(int j=0; j<x; j++) {
            mapa[i][j] = getchar();
            visitado[i][j] = 0;
        }
        getchar(); // consumir o \n
    }

    int cx = 0, cy = 0; // posição inicial
    int dx = 1, dy = 0; // começando indo para a direita

    while(1) {
        // Fora do mapa
        if(cx < 0 || cx >= x || cy < 0 || cy >= y) {
            printf("!\n");
            return 0;
        }

        // Ciclo detectado
        if(visitado[cy][cx]) {
            printf("!\n");
            return 0;
        }
        visitado[cy][cx] = 1;

        char c = mapa[cy][cx];

        // Baú encontrado
        if(c == '*') {
            printf("*\n");
            return 0;
        }

        // Mudar direção
        if(c == '>') { dx=1; dy=0; }
        else if(c == '<') { dx=-1; dy=0; }
        else if(c == 'v') { dx=0; dy=1; }
        else if(c == '^') { dx=0; dy=-1; }
        // '.' continua na mesma direção

        // Movimentar
        cx += dx;
        cy += dy;
    }

    return 0;
}
