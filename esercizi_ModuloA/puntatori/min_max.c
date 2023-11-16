#include <stdio.h>

/*
Progettare e codificare in linguaggio C una procedura che dati tre interi (a, b, c) calcoli il massimo (max) e il minimo (min). La procedura dovrà avere la seguente interfaccia:
void minmax(int a, int b, int c, int* min, int* max);

Scrivere poi un programma che utilizza tale procedura. Il programma, 
all'interno della funzione main, dovrà leggere da tastiera tre numeri interi, 
calcolare il massimo e il minimo invocando la procedura descritta sopra 
e stampare il risultato a video fra simboli @.
*/

void minmax(int a, int b, int c, int *min, int *max)
{
    if (a > b && a > c) //potevo fare una cosa più corta impostando a *max=a e poi fare il confronto
    {
        *max = a;
    }
    else if (b > a && b > c)
    {
        *max = b;
    }
    else if (c > a && c > b)
    {
        *max = c;
    }

    if (a < b && a < c)
    {
        *min = a;
    }
    else if (b < a && b < c)
    {
        *min = b;
    }
    else if (c < a && c < b)
    {
        *min = c;
    }
}

int main()
{
    int a, b, c;
    int min, max;
    printf("Inserisci il primo numero:");
    scanf("%d", &a);
    printf("Inserisci il secondo numero:");
    scanf("%d", &b);
    printf("Inserisci il terzo numero:");
    scanf("%d", &c);

    minmax(a, b, c, &min, &max);

    printf("Minimo: @ %d @\nMassimo: @ %d @\n", min, max);
}