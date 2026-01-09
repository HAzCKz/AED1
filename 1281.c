#include <stdio.h>
#include <string.h>

char nomes[1001][51];

int busca(char *nome, int m);

int main()
{
    double precos[1001];

    int n = 0;

    scanf("%d", &n);

    while (n > 0)
    {
        int produtos = 0;
        scanf("%d", &produtos);

        for (int i = 0; i < produtos; i++)
        {
            scanf("%s %lf", nomes[i], &precos[i]);
        }

        int n_produtos = 0;
        scanf("%d", &n_produtos);

        double total = 0.0;

        for (int i = 0; i < n_produtos; i++)
        {
            char nome_pedido[51];
            int qtd = 0;
            
            scanf("%s %d", nome_pedido, &qtd);

            int igual = busca(nome_pedido, produtos);

            if (igual != -1)
            {
                total = total + (precos[igual] * qtd);
            }
        }

        printf("R$ %.2lf\n", total);

        n--;
    }
}

int busca(char *nome, int m)
{
    for (int i = 0; i < m; i++)
    {
        if (strcmp(nome, nomes[i]) == 0)
        {
            return i;
        }
    }

    return -1;
}
