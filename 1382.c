#include <stdio.h>

int a[10005];
int vis[10005];

int Ciclos(int n);

int main() {
    
    int T;
    
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        for (int i = 1; i <= N; i++) {
            scanf("%d", &a[i]);
            vis[i] = 0;
        }

        int ciclos = Ciclos(N);

        int min_swaps = N - ciclos;
        printf("%d\n", min_swaps);
    }

    return 0;
}

int Ciclos(int n) {
    int ciclos = 0;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ciclos++;
            int x = i;
            while (!vis[x]) {
                vis[x] = 1;
                x = a[x];
            }
        }
    }

    return ciclos;
}
