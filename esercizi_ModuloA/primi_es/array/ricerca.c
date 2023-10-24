#include <stdio.h>
/*
Si legga da tastiera un array di 10 elementi di tipo int.
Si legga da tastiera un intero x.
Si cerchi se esiste l'elemento x nell'array: se è presente si visualizzino tutti gli indici in cui l'elemento compare, 
altrimenti si informi l'utente che l'elemento non è presente.
*/

int main()
{
    int a[10];
    int x, contatore = 0;

    printf("Inserisci un valore da cercare:");
    scanf("%d", &x);

    for (int i = 0; i < 10; i++)
    {
        printf("Inserisci il %d valore:", i);
        scanf("%d", &a[i]);
    }

    for (int j = 0; j < 10; j++)
    {
        if (a[j] == x)
        {
            printf("Il numero %d, compare nella poszione:%d\n", x,j);
        }
        else
        {
            contatore++;
        }
    }
    if (contatore == 10)
    {
        printf("Il numero cercato non è presente.");
    }
}