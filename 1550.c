#include <stdio.h>

int inverter_numero(int n);
void resolver();


int main()
{
    int T = 0;
    if (scanf("%d", &T) == 1)
    {
        while (T > 0)
        {
            resolver();
            T--;
        }
    }
}

int inverter_numero(int n)
{
    int reverso = 0;
    while (n > 0)
    {
        reverso = (reverso * 10) + (n % 10);
        n = n / 10;
    }
    return reverso;
}

void resolver()
{
    int A = 0, B = 0;
    if (scanf("%d %d", &A, &B) != 2) return;

    if (A == B)
    {
        printf("0\n");
        return;
    }

    int dist[10000];
    int i = 0;
    while (i < 10000)
    {
        dist[i] = -1; 
        i++;
    }

    int fila[10000];
    int inicio = 0;
    int fim = 0;

    dist[A] = 0;
    fila[fim] = A;
    fim = fim + 1;

    while (inicio < fim)
    {
        int atual = fila[inicio];
        inicio = inicio + 1;

        if (atual == B)
        {
            printf("%d\n", dist[atual]);
            return;
        }

        int proximo_soma = atual + 1;
        if (proximo_soma < 10000)
        {
            if (dist[proximo_soma] == -1)
            {
                dist[proximo_soma] = dist[atual] + 1;
                fila[fim] = proximo_soma;
                fim = fim + 1;
            }
        }

        int proximo_inverte = inverter_numero(atual);
        if (proximo_inverte < 10000) 
        {
            if (dist[proximo_inverte] == -1)
            {
                dist[proximo_inverte] = dist[atual] + 1;
                fila[fim] = proximo_inverte;
                fim = fim + 1;
            }
        }
    }
}

