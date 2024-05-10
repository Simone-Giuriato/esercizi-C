#include <stdio.h>
#include <stdlib.h>

#include "list.h"



int main()
{
    list L;
    L = NULL;
    int i = 0;

    do
    {
        printf("Inserisci un elemento (0 per terminare):\n");
        scanf("%d", &i);

        if (i != 0)
        {
            L = insord(L, i);
        }

    } while (i != 0);
    printf("Valori della lista \n");
    showList(L);
    int n = 0;
    n = lenght(L,n);
    printf("Nella lista ci sono %d elementi\n", n);
    int somma = 0;
    somma = sumList(L,somma);
    printf("La somma degli elementi della lista è: %d \n", somma);
}
