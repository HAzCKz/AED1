#include <stdio.h>

int main()
{
    int NC;
    scanf("%d", &NC);

    for (int i = 0; i < NC; i++)
    {
        int N;
        scanf("%d", &N);
        int alturas[N];

        for (int ii = 0; ii < N; ii++)
        {
            scanf("%d", &alturas[ii]);
        }

        // Insertion Sort
        for (int iii = 1; iii < N; iii++)
        {
            int chave = alturas[iii];
            int j = iii - 1;
            
            while (j >= 0 && alturas[j] > chave)
            {
                alturas[j + 1] = alturas[j];
                j--;
            }

            alturas[j + 1] = chave;
        }

        for (int p = 0; p < N; p++)
        {
            if (p != 0)
            {
                printf(" ");
            }

            printf("%d", alturas[p]);
        }
        printf("\n");
    }

}
