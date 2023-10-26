#include <stdio.h>

/*
Si scriva una funzione con interfaccia
float soglia(float x, float inf, float sup)
che fornisce
- il valore di x, se x è compreso fra inf e sup
- il valore inf, se x e` minore di inf
- il valore sup, se x e` maggiore di sup

Si scriva poi un programma C che
- legge da tastiera un array A di 10 float
- legge da tastiera due numeri inf e sup
- costruisce un secondo array B, in cui ogni elemento e` ottenuto applicando la funzione soglia al corrispondente elemento dell'array A
- visualizza sullo schermo l'array B
*/

float soglia(float x, float inf, float sup)
{

    if (x < inf)
    {
        return inf;
    }
    else if (x > sup)
    {
        return sup;
    }
    else
    {
        return x;
    }
}

int main()
{
    float a[10], inf, sup = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Inserisci il %d° valore:", i + 1);
        scanf("%f", &a[i]);
    }

    printf("Inserisci estremo superiore:");
    scanf("%f", &sup);
    printf("Inserisci estremo inferiore:");
    scanf("%f", &inf);

    float b[10], val = 0;

    for (int j = 0; j < 10; j++)
    {
        val = soglia(a[j], inf, sup);

        printf("%.2f ", val);   //lascio solo 2 cifre dopo la virgola
    }
    printf("\n");
}