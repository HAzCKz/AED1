#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    char conteudo;
    struct No *esq;
    struct No *dir;
} No;

No* Insere(No* p, char ele);
int search(No* p, char ele);
void InFixa(No* p, int *primeiro_ele);
void PreFixa(No* p, int *primeiro_ele);
void PosFixa(No* p, int *primeiro_ele);


int main()
{
    No* raiz = NULL;

    char comando[20];
    char elemento;
    int primeiro_ele;
    
    while (scanf("%s", comando) != EOF)
    {
        if (strcmp(comando, "I") == 0)
        {
            scanf(" %c", &elemento); 
            raiz = Insere(raiz, elemento);
            
        }
        
        else if (strcmp(comando, "INFIXA") == 0)
        {
            int primeiro_ele = 1; 
            InFixa(raiz, &primeiro_ele);
            printf("\n");
            
        }
        
        else if (strcmp(comando, "PREFIXA") == 0)
        {
            int primeiro_ele = 1;
            PreFixa(raiz, &primeiro_ele);
            printf("\n");
            
        }
        
        else if (strcmp(comando, "POSFIXA") == 0)
        {
            int primeiro_ele = 1;
            PosFixa(raiz, &primeiro_ele);
            printf("\n");
            
        }

        else if (strcmp(comando, "P") == 0)
        {
            scanf(" %c", &elemento);
            if (search(raiz, elemento) == 1)
            {
                printf("%c existe\n", elemento);
            }
            else
            {
                printf("%c nao existe\n", elemento);
            }
        }
    }
}


No* Insere(No* p, char y)
{
    if (p == NULL)
    {
        No* nova = malloc(sizeof(No));
        nova->conteudo = y;
        nova->esq = NULL;
        nova->dir = NULL;
        return nova;
    }
    
    if (y < p->conteudo)
    {
        p->esq = Insere(p->esq, y);
    }
    
    else if (y > p->conteudo)
    {
        p->dir = Insere(p->dir, y);
    }
    
    return p;
}

int search(No* p, char y)
{
    if (p == NULL)
    {
        return 0;
    }
    
    if (p->conteudo == y)
    {
        return 1;
    }

    if (y < p->conteudo)
    {
        return search(p->esq, y);
    }
    
    else
    {
        return search(p->dir, y);
    }
}

void InFixa(No* p, int *primeiro_ele)
{
    if (p != NULL)
    {
        InFixa(p->esq, primeiro_ele);
        
        if ((*primeiro_ele) == 0)
        {
            printf(" ");
        } 
        printf("%c", p->conteudo);
        *primeiro_ele = 0; 
        
        InFixa(p->dir, primeiro_ele);
    }
}

void PreFixa(No* p, int *primeiro_ele)
{
    if (p == NULL) return;
    
    if ((*primeiro_ele) == 0)
    {
        printf(" ");
    } 

    printf("%c", p->conteudo);

    *primeiro_ele = 0;
    
    PreFixa(p->esq, primeiro_ele);
    PreFixa(p->dir, primeiro_ele);
}

void PosFixa(No* p, int *primeiro_ele)
{
    if (p != NULL)
    {
        PosFixa(p->esq, primeiro_ele);
        PosFixa(p->dir, primeiro_ele);
        
        if ((*primeiro_ele) == 0)
        {
            printf(" ");
        }

        printf("%c", p->conteudo);

        *primeiro_ele = 0;
    }
}
