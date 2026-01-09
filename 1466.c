#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int conteudo;
    struct no *esq;
    struct no *dir;
}No;

No* inserir(No *raiz, int conteudo);
void imprimirNivel(No *raiz);
void liberarArvore(No *raiz);

int main()
{
    int C = 0;

    if (scanf("%d", &C) == 1)
    {
        for (int t = 1; t <= C; t++)
        {
            int N;
            scanf("%d", &N);

            No *raiz = NULL;

            for (int i = 0; i < N; i++)
            {
                int num;
                scanf("%d", &num);
                raiz = inserir(raiz, num);
            }

            printf("Case %d:\n", t);
            imprimirNivel(raiz);
            printf("\n"); 

            liberarArvore(raiz);
        }
    }
}

No* inserir(No *raiz, int y)
{
    if (raiz == NULL)
    {
        No *novo = malloc(sizeof(No));
        novo->conteudo = y;
        novo->esq = novo->dir = NULL;

        return novo;
    }

    if (y < raiz->conteudo)
    {
        raiz->esq = inserir(raiz->esq, y);
    }
    else
    {
        raiz->dir = inserir(raiz->dir, y);
    }

    return raiz;
}

void imprimirNivel(No *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    No *fila[505];
    int inicio = 0;
    int fim = 0;

    fila[fim++] = raiz;

    int primeiro = 1;

    while (inicio < fim)
    {
        No *atual = fila[inicio++];

        if (primeiro == 1)
        {
            printf("%d", atual->conteudo);
            primeiro = 0;
        }
        else
        {
            printf(" %d", atual->conteudo);
        }

        if (atual->esq != NULL)
        {
            fila[fim++] = atual->esq;
        }
        if (atual->dir != NULL)
        {
            fila[fim++] = atual->dir;
        }
    }
    printf("\n");
    
}

void liberarArvore(No *raiz)
{
    if (raiz != NULL)
    {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}
