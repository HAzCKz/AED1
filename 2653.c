#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **joias = malloc(1000001 * sizeof(char *));
    char buffer[1000001];

    int quant = 0;
    int i;

    while (scanf("%s", buffer) != EOF)
    {
        int existe = 0;

        for (i = 0; i < quant; i = i + 1)
        {
            if (strcmp(joias[i], buffer) == 0)
            {
                existe = 1;
                break;
            }
        }

        if (existe == 0)
        {
            joias[quant] = malloc((strlen(buffer) + 1) * sizeof(char));

            strcpy(joias[quant], buffer);
            
            quant++;
        }
    }

    printf("%d\n", quant);

    free(joias);
}
