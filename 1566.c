#include <stdio.h>

int main()
{
    int casos = 0;

    scanf("%d", &casos);

    // inserir loop while(casos > 0)

    long pessoas = 0;

    scanf("%d", &pessoas);

    
}


No *Busca (arvore r, int k)
{
    if (r == NULL)
    {
        return;
    }
    else
    {
        if(k!= r->chave)
        {
            if(k > r->chave)
            {
                Busca(r->dir, k);
            }
            if(k < r->chave)
            {
                Busca(r->esq, k);
            }
            else
            {
                return r;
            }
        }
    }