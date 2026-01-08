#include <stdio.h>

int ADJ[26][26];
int VETOR[26];

void dfs(int v, int V, int comp[], int *v_aux);
void sort(int arr[], int n);

int main()
{
    int N;
    scanf("%d", &N);

    for (int t = 1; t <= N; t++)
    {
        int VERTICE = 0, Av_auxTA = 0;

        scanf("%d", &VERTICE);
        scanf("%d", &Av_auxTA);

        for (int i = 0; i < 26; i++)
        {
            VETOR[i] = 0;

            for (int j = 0; j < 26; j++)
            {
                ADJ[i][j] = 0;
            }
        }

        for (int i = 0; i < Av_auxTA; i++)
        {
            char u, v;
            scanf(" %c %c", &u, &v);
            int a = u - 'a';
            int b = v - 'a';
            ADJ[a][b] = 1; // Grafo não dirigido
            ADJ[b][a] = 1;
        }

        printf("Case #%d:\n", t);

        int res = 0;

        for (int i = 0; i < VERTICE; i++)
        {
            if (VETOR[i] == 0)
            {
                int comp[26], v_aux = 0;

                dfs(i, VERTICE, comp, &v_aux);

                sort(comp, v_aux);

                for (int j = 0; j < v_aux; j++)
                {
                    printf("%c,", comp[j] + 'a');
                }

                printf("\n");

                res++;
            }
        }

        printf("%d connected components\n\n", res);
    }
}

void dfs(int v, int V, int comp[], int *v_aux)
{
    VETOR[v] = 1;
    comp[(*v_aux)++] = v;
    
    for (int i = 0; i < V; i++)
    {
        if (ADJ[v][i] && VETOR[i] == 0)
        {
            dfs(i, V, comp, v_aux);
        }
    }
}

void sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
