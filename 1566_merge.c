#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r);

void mergeSort(int arr[], int l, int r);

int main() {
    int NC;
    scanf("%d", &NC);

    for (int c = 0; c < NC; c++) {
        int N;
        scanf("%d", &N);
        int *alturas = (int*)malloc(N * sizeof(int));

        for (int i = 0; i < N; i++) {
            scanf("%d", &alturas[i]);
        }

        mergeSort(alturas, 0, N - 1);

        for (int i = 0; i < N; i++) {
            if (i != 0) printf(" ");
            printf("%d", alturas[i]);
        }
        printf("\n");

        free(alturas);
    }

    return 0;
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}