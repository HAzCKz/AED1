#include <stdio.h>

int main()
{
    int v = 0, t = 0;
    
    while (scanf("%d %d", &v, &t) != EOF)
    {
        printf("%d\n", 2 * v * t);
    }
}
