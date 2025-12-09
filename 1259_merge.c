#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int esq, int mid, int dir, int desc);
void mergeSort(int *arr, int esq, int dir, int desc);

int main() {
    int N;
    scanf("%d", &N);

    int *pares = (int*) malloc(N * sizeof(int));
    int *impares = (int*) malloc(N * sizeof(int));
    int p = 0, i = 0;

    for (int j = 0; j < N; j++) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0)
            pares[p++] = x;
        else
            impares[i++] = x;
    }

    mergeSort(pares, 0, p - 1, 0);  
    mergeSort(impares, 0, i - 1, 1);

    for (int j = 0; j < p; j++) printf("%d\n", pares[j]);
    for (int j = 0; j < i; j++) printf("%d\n", impares[j]);

    free(pares);
    free(impares);
    return 0;
}

void merge(int *arr, int esq, int mid, int dir, int desc) {
    int n1 = mid - esq + 1;
    int n2 = dir - mid;
    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[esq + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        if ((desc == 0 && L[i] <= R[j]) || (desc == 1 && L[i] >= R[j]))
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int *arr, int esq, int dir, int desc) {
    if (esq < dir) {
        int mid = (esq + dir) / 2;
        mergeSort(arr, esq, mid, desc);
        mergeSort(arr, mid + 1, dir, desc);
        merge(arr, esq, mid, dir, desc);
    }
}