#include <stdio.h>
#include <string.h>

int main() 
{
    int N;
    scanf("%d", &N);
    getchar(); 

    char line[10000];
    while (N--) {
        if (!fgets(line, sizeof(line), stdin)) break;

        int len = strlen(line);
        if (line[len-1] == '\n') line[len-1] = '\0';

        char items[1000][50];
        int count = 0;

        int i = 0;
        while (line[i]) {
            int j = 0;
                 while (line[i] && line[i] != ' ') {
                items[count][j++] = line[i++];
            }
            items[count][j] = '\0';
            count++;
            while (line[i] == ' ') i++; 

             for (int x = 0; x < count-1; x++) {
            for (int y = x+1; y < count; y++) {
                if (strcmp(items[x], items[y]) > 0) {
                    char tmp[50];
                    strcpy(tmp, items[x]);
                    strcpy(items[x], items[y]);
                    strcpy(items[y], tmp);
                }
            }
        }

        
        for (int k = 0; k < count; k++) {
            if (k == 0 || strcmp(items[k], items[k-1]) != 0) {
                if (k != 0) printf(" ");
                printf("%s", items[k]);
            }
        }
        printf("\n");
    }

}
}
