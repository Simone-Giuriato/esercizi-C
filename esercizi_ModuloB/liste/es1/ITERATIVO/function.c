#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list cons(int i, list L)
{

    //(inserimento in testa slittano a destra)
    list t;
    t = (list)malloc(sizeof(item)); // per le malloc fare cast esplicito
    // malloc alloca dinamicamente
    (*t).value = i; // nel campo value metto dato dell'utente
    (*t).next = L;  // nel puntatore a next (nodo successivo) metto la casella che viene dopo di questa che senza l inserimetno sarebbe stat prima

    return t;
}
void showList(list L)
{
    printf("Valori della lista:\n");
    while (L != NULL)
    { // fichè non raggiungo l'ultimo elemento che con gli inserimenti sarà slittato a dx
        // era stato messo a NULL
        printf("%d\n", L->value); //(*L).value
        L = L->next;
    }
}

int member(int n, list L)
{
    // se lo trova mi da 1, se non trova, andrà a ritornare 0.
    while (L != NULL)
    {
        if (L->value == n)
        {
            return 1;
        }
        else
        {
            L = L->next; // se non lo trova passo all elemento successivo, finche non arrivo al valore NULL (vedi while)
        }
    }
    return 0; // fuori dal while, questo vuol dire che non c'è l elemento da cercare
}
