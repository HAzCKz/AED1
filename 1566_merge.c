#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

int main()
{
    int NC;
    scanf("%d", &NC);

    for (int i = 0; i < NC; i++)
    {
        int N;
        scanf("%d", &N);
        int *alturas = (int*)malloc(N * sizeof(int));

        for (int ii = 0; ii < N; ii++)
        {
            scanf("%d", &alturas[ii]);
        }

        mergeSort(alturas, 0, N - 1);

        for (int iii = 0; iii < N; iii++)
        {
            if (iii != 0)
            {
                printf(" ");
            }

            printf("%d", alturas[iii]);
        }
        printf("\n");

        free(alturas);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
         R[j] = arr[m + 1 + j];
    }

    int ii = 0, jj = 0, k = l;

    while (ii < n1 && jj < n2)
    {
        if (L[ii] <= R[jj])
        {
            arr[k++] = L[ii++];
        }
        else
        {
            arr[k++] = R[jj++];
        }
        
    }

    while (ii < n1) 
    {
        arr[k++] = L[ii++];
    }

    while (jj < n2)
    {
        arr[k++] = R[jj++];
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
