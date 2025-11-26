#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0;

    scanf("%d", &N);

    //while (N > 0)
    /{
        int num_alunos = 0;

        scanf("%d", &num_alunos);

        int *notas = malloc(sizeof(int)*num_alunos);
        int *notas_org = malloc(sizeof(int)*num_alunos);


        for (int i = 0; num_alunos > i; i++)
        {
            scanf("%d", (notas+i));
        }

        for (int i = 0; i < num_alunos; i++)
        {
            
        }
        
        //N--;
    //}
}
