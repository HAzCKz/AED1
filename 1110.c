#include <stdio.h>

int main()
{
    int entrada = 0;

    scanf("%d", &entrada);

    while (entrada != 0)
    {
        int v[entrada];

        int n = entrada;

        for (int i = 1; i <= entrada; i++)
        {
            v[entrada - i] = n;
            n--;
        }


        for (int i = 0; i < entrada; i++)
        {
            printf("Entrada: %d\n", v[i]);
        }

        

        scanf("%d", &entrada);
    }
 
}