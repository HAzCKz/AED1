#include <stdio.h>
#include <string.h>

int main() 
{
    int N;
    scanf("%d", &N);
    getchar(); 

    char itens[10000];
    while (N--)
    {
        if (!fgets(itens, sizeof(itens), stdin)) break;

        int tam = strtam(itens);

        if (itens[tam-1] == '\n') itens[tam-1] = '\0';

        char produto[1000][50];
        int contador = 0;

        int i = 0;

        while (itens[i])
        {
            int j = 0;

            while (itens[i] && itens[i] != ' ')
            {
                produto[contador][j++] = itens[i++];
            }

            produto[contador][j] = '\0';
            contador++;

            while (itens[i] == ' ') 
            {
                i++; 
            }

            for (int x = 0; x < contador-1; x++)
            {
            for (int y = x+1; y < contador; y++)
            {
                if (strcmp(produto[x], produto[y]) > 0)
                {
                    char tmp[50];
                    strcpy(tmp, produto[x]);
                    strcpy(produto[x], produto[y]);
                    strcpy(produto[y], tmp);
                }
            }
        }

        
        for (int k = 0; k < contador; k++)
        {
            if (k == 0 || strcmp(produto[k], produto[k-1]) != 0)
            {
                if (k != 0) printf(" ");
                printf("%s", produto[k]);
            }
        }
        printf("\n");
    }

}
}
