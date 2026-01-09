#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto{
    int x;
    int y;
} Ponto;

char mapa[1030][1030];

Ponto pilha[1100000];

int topo = -1;

void Empilha(int x, int y);
Ponto Desempilha();


int main()
{
    int N = 0, M = 0;
    int cliques = 0;

    if (scanf("%d %d", &N, &M) != 2)
    {
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%s", mapa[i]);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            
            if (mapa[i][j] == '.')
            {
                cliques++;
                
                Empilha(i, j);

                mapa[i][j] = 'o'; 

                while (topo != -1)
                {
                    Ponto atual = Desempilha();

                    int dx[] = {-1, 1, 0, 0};
                    int dy[] = {0, 0, -1, 1};

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = atual.x + dx[k];
                        int ny = atual.y + dy[k];

                        if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                        {
                            if (mapa[nx][ny] == '.')
                            {
                                mapa[nx][ny] = 'o';
                                Empilha(nx, ny);
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%d\n", cliques);
}

void Empilha(int x, int y)
{
    topo++;
    pilha[topo].x = x;
    pilha[topo].y = y;
}

Ponto Desempilha() 
{
    return pilha[topo--];
}
