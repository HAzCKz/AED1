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

        for (int iii = 0; iii < N - 1; iii++)
        {
            int min_idx = iii;

            for (int j = iii + 1; j < N; j++)
            {
                if (alturas[j] < alturas[min_idx])
                {
                    min_idx = j;
                }
            }

            int temp = alturas[iii];
            alturas[iii] = alturas[min_idx];
            alturas[min_idx] = temp;
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
