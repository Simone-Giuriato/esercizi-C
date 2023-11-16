#include <stdio.h>
#include <math.h>

int quadratoperfetto(int x, int *rad)
{

    *rad = sqrt(x);

    if ((*rad * *rad) == x)
    { // se il quadrato tra radici mi da esattamente il numero x di partenza, se fosse una radici essendo dati tipo int ci sarebbero degli arrotondamenti ed ecco che se eseguo il quadrato non ritorno al numero x di partenza
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int x, rad = 0;

    printf("Inserisci un numero:");
    scanf("%d", &x);

    if (quadratoperfetto(x, &rad))
    { // se vale 1

        printf("È un quadrato perfetto\n");
        printf("La sua radice è: %d\n", rad);
    }
    else
    {
        printf("Non è un quadrato perfetto\n");
    }
}