#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0;

    scanf("%d", &N);

    while (N > 0)
    {
        int num_alunos = 0;

        scanf("%d", &num_alunos);

        int notas[num_alunos];
        int notas_org[num_alunos];

        for (int i = 0; i < num_alunos; i++)
        {
            scanf("%d", &notas[i]);
        }
    
        for (int i = 0; i < num_alunos; i++)
        {
            notas_org[i] = notas[i];
        }

        for (int i = 0; i < (num_alunos-1); i++)
        {
            for (int j = 0; j < (num_alunos-i-1); j++) 
            {
                if (notas_org[j] < notas_org[j+1]) 
                {
                    int temp = notas_org[j];
                    notas_org[j] = notas_org[j+1];
                    notas_org[j+1] = temp;
                }
            }
        }

        int var = 0;

        for (int i = 0; i < num_alunos; i++)
        {
            if(notas_org[i] == notas[i])
            {
                var++;
            }
        }

        printf("%d\n", var);

        N--;
    }
}
