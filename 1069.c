#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N; 
    scanf("%d\n", &N);
    

    while (N > 0)
    {
        int push = 0, total = 0;
        char diamantes[1000];

        fgets(diamantes, sizeof(diamantes), stdin);

        for (int i = 0, n = strlen(diamantes); i < n; i++)
        {
            if (diamantes[i] == '<')
            {
                push++; 
            }
            else if (diamantes[i] == '>' && push > 0)
            {
                push--;  
                total++; 
            }
        }

        printf("%d\n", total);
        N--;
    }
}
