#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int g = 1;

    while(g < 10000)
    {
        char N[10000];

        int verifica = 0;

        fgets(N, sizeof(N), stdin);

        char *str = N;

        //printf("A string: %s", N);

        for (int i = 0, len = strlen(N); i <= len; i++)
        {
            if(*str == '(')
            {
                verifica++;
            }

            if(*str == ')')
            {
                verifica--;
                if(verifica < 0)
                {
                    printf("incorrect\n");
                }
            }

            str++;

        }

        if (verifica != 0)
        {
            printf("incorrect\n");
        }
        else
        {
            printf("correct\n");
        }

        g++;
    }

}

