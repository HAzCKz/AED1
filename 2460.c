#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int conteudo;
    struct celula *seg;
}celula;

void Insere_Num (celula *p, int num);
void Printa (celula *lst);
void Inverte_lista (celula *lst);
void BuscaRemove_Celula(celula *lst, int num);



int main()
{
    celula *lst = malloc(sizeof(celula));
    lst->seg = NULL;

    int N = 0;
    scanf("%d", &N);

    while (N > 0)
    {
        int n = 0;
        scanf("%d", &n);
        Insere_Num(lst, n);
        N--;
    }

    Inverte_lista(lst);

    int M = 0;

    scanf("%d", &M);

    while (M > 0)
    {
        int n2 = 0;
        scanf("%d", &n2);
        BuscaRemove_Celula(lst, n2);
        M--;
    }
        
    Printa(lst);

    printf("\n");


}

void Insere_Num (celula *p, int num)
{
    celula *nova = malloc(sizeof(celula));
    nova->seg = p->seg;
    nova->conteudo = num;
    p->seg = nova;
}

void BuscaRemove_Celula(celula *lst, int num)
{
    celula *p, *q;
    p = lst;
    q = lst->seg;

    while (q!=NULL && q->conteudo != num)
    {
        p = q;
        q = q->seg;
    }

    if (q!=NULL)
    {
        p->seg = q->seg;
        free(q);
    }
    
}

void Printa (celula *lst)
{
    celula *p = lst->seg;

    if (p == NULL) {
        printf("\n");
        return;
    }


    printf("%d", p->conteudo);
    p = p->seg;

    while (p != NULL)
    {
        printf(" %d", p->conteudo);
        p = p->seg;
    }

    printf("\n");
}


void Inverte_lista(celula *lst)
{
    celula *ant = NULL;
    celula *atual = lst->seg;
    celula *prox;

    while (atual != NULL)
    {
        prox = atual->seg;
        atual->seg = ant;
        ant = atual;
        atual = prox;
    }

    lst->seg = ant;
}
