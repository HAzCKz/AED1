#include <stdio.h>
#include <string.h>

#define MAXN 100000
#define MAXL 205

char nums[MAXN][MAXL];
char aux[MAXN][MAXL];

int cmp(char a[], char b[]);
void merge(int l, int m, int r);
void mergesort(int l, int r);
int lcp(char a[], char b[]);

int main() {
    int N;

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++)
            scanf("%s", nums[i]);

        mergesort(0, N - 1);

        long long total = 0;

        for (int i = 1; i < N; i++)
            total += lcp(nums[i - 1], nums[i]);

        printf("%lld\n", total);
    }

    return 0;
}

int cmp(char a[], char b[]) {
    return strcmp(a, b);
}

void merge(int l, int m, int r) {
    int i = l, j = m + 1, k = l;

    while (i <= m && j <= r) {
        if (cmp(nums[i], nums[j]) <= 0) {
            strcpy(aux[k++], nums[i++]);
        } else {
            strcpy(aux[k++], nums[j++]);
        }
    }

    while (i <= m) strcpy(aux[k++], nums[i++]);
    while (j <= r) strcpy(aux[k++], nums[j++]);

    for (i = l; i <= r; i++)
        strcpy(nums[i], aux[i]);
}

void mergesort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergesort(l, m);
    mergesort(m + 1, r);
    merge(l, m, r);
}

int lcp(char a[], char b[]) {
    int i = 0;
    while (a[i] && b[i] && a[i] == b[i]) i++;
    return i;
}
