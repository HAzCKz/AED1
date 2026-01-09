#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int conteudo;
    int chave;
    struct No *esq;
    struct No *dir;
}No;

No* Insere(No *r, int y);
void Infixa(No *r, int *primeiro, int total);
void FreeArvore(No *r);

int main()
{
    int casos = 0;
    scanf("%d", &casos);

    while (casos > 0)
    {
        int pessoas = 0;
        No *raiz = NULL;

        scanf("%d", &pessoas);

        for (int i = 0; i < pessoas; i++)
        {
            int h;
            scanf("%d", &h);
            raiz = Insere(raiz, h);
        }

        int primeiro = 1; 
        Infixa(raiz, &primeiro, pessoas);
        printf("\n");

        FreeArvore(raiz);
        casos = casos - 1;
    }

}

No* Insere(No *r, int y)
{
    if (r == NULL)
    {
        No *novo = malloc(sizeof(No));
        novo->conteudo = y;
        novo->chave = 1;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if (y == r->conteudo)
    {
        r->chave = r->chave + 1;
    }
    else if (y < r->conteudo)
    {
        r->esq = Insere(r->esq, y);
    }
    else
    {
        r->dir = Insere(r->dir, y);
    }

    return r;
}

void Infixa(No *r, int *primeiro, int total)
{
    if (r != NULL)
    {
        Infixa(r->esq, primeiro, total);

        for (int i = 0; i < r->chave; i++)
        {
            if (*primeiro == 1)
            {
                printf("%d", r->conteudo);
                *primeiro = 0;
            }
            else
            {
                printf(" %d", r->conteudo);
            }
        }

        Infixa(r->dir, primeiro, total);
    }
}

void FreeArvore(No *r)
{
    if (r != NULL)
    {
        FreeArvore(r->esq);
        FreeArvore(r->dir);
        free(r);
    }
}
