// RICORSIVO

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    list L;
    L = NULL; // root inizialmente a null
    int i;

    do
    {
        printf("Inserire un valore (0 per terminare):\n");
        scanf("%d", &i);
        if (i != 0)
        { // confronto che non abbia inserito 0, cosi da non mettere 0 nella lista
            L = cons(i, L);
        }

    } while (i != 0);
    printf("Elementi nella lista:\n");
    showListr(L);

    // ricerca di un elemento n dato dall'utente
    int n;
    printf("Inserisci un elemento da cercare nella lista:\n");
    scanf("%d", &n);
    if ((member(n, L)) == 1)
    {
        printf("Elemento trovato nella lista\n");
    }
    else
    {
        printf("Elemento NON trovato.\n");
    }
}