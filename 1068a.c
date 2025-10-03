#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int verifica = 0;

    char N[1000];

    fgets(N, sizeof(N), stdin);

    char *str = N;

    printf("A string: %s", N);

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
                printf("incorrect");
                return 1;
            }
        }

        str++;

    }


    if (verifica != 0)
    {
        printf("incorrect");
    }
    else
    {
        printf("correct");
    }
    

}

