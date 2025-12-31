#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int conteudo;
    struct no* esq;
    struct no* dir;
}no;

typedef no* arvore;

arvore Insere(arvore r, int y);

void Prefixa(arvore r);
void Infixa(arvore r);
void Posfixa(arvore r);


int main()
{ 
    int C = 0;
    scanf("%d", &C);

    int caso = 1;

    while (C > 0)
    {
        arvore raiz = NULL;

        int N = 0; // Número de folhas da árvore 

        scanf("%d", &N);
    
        int valores[N];

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &valores[i]);
            raiz = Insere(raiz, valores[i]);
        }

        
        printf("Case %d:\n", caso);

        printf("Pre.:");
        Prefixa(raiz);
        
        printf("\nIn..:");
        Infixa(raiz);
        
        printf("\nPost:");
        Posfixa(raiz);

        printf("\n\n");



        C--;
        caso++;

    }


}

arvore Insere(arvore r, int y)
{
    if (r == NULL)
    {
        r = malloc(sizeof(arvore));
        r->conteudo = y;
        r->dir = r->esq = NULL;
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


void Prefixa(arvore r) //r-e-d
{
    if (r != NULL)
    {
        printf(" %d", r->conteudo);
        Prefixa(r->esq);
        Prefixa(r->dir);
    }
}

void Infixa(arvore r) //e-r-d
{
    if (r != NULL)
    {
        Infixa(r->esq);
        printf(" %d", r->conteudo);
        Infixa(r->dir);
    }
}

void Posfixa (arvore r) // e-d-r
{
    if (r != NULL)
    {
        Posfixa(r->esq);
        Posfixa(r->dir);
        printf(" %d", r->conteudo);
    }
}
