#include <stdio.h>
#include <stdlib.h>
    
int main()
{
    int n = 0;

    while (scanf("%d", &n) != EOF)
    {
        int pilha[1005], topo = 0;

        int fila[1005], frente = 0, tras = 0;

        int pq[1005], tam_pq = 0;

        int eh_pilha = 1;
        int eh_fila = 1;
        int eh_pq = 1;


        for (int i = 0; i < n; i++)
        {
            int comando, x;

            scanf("%d", &comando);
            scanf("%d", &x);

            if (comando == 1) 
            {
                pilha[topo] = x;
                topo++;

                fila[tras] = x;
                tras++;

                pq[tam_pq] = x;
                tam_pq++;
            } 

            else if (comando == 2)
            {
                //Teste da Pilha
                int elementop = pilha[topo - 1];

                topo = topo - 1;

                if (elementop != x)
                {
                    eh_pilha = 0;
                }

                //Teste da Fila
                int elementof = fila[frente];

                frente = frente + 1;

                if (elementof != x)
                {
                    eh_fila = 0;
                }
                
                // Teste da Fila de Prio.
                int indice_maior = 0;

                for (int j = 1; j < tam_pq; j++)
                {
                    if (pq[j] > pq[indice_maior])
                    {
                        indice_maior = j;
                    }
                }

                int elemento_maior = pq[indice_maior];

                for (int j = indice_maior; j < tam_pq - 1; j++)
                {
                    pq[j] = pq[j + 1];
                }
                tam_pq = tam_pq - 1;

                if (elemento_maior != x)
                {
                    eh_pq = 0;
                }
                
            }
        }


        int total = eh_pilha + eh_fila + eh_pq;

        if (total == 0)
        {
            printf("impossible\n");
        }
        else if (total > 1)
        {
            printf("not sure\n");
        }
        else if (eh_pilha == 1)
        {
            printf("stack\n");
        }
        else if (eh_fila == 1)
        {
            printf("queue\n");
        }
        else if (eh_pq == 1)
        {
            printf("priority queue\n");
        }
    }
}
