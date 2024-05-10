//ES 2 liste ITERATIVO

#include "list.h"

list insord(list L, int el)
{
    {
        list pprec, patt = L, aux;
        int trovato = 0;
        while (patt != NULL && !trovato)
        {
            if (el <= patt->value)
                trovato = 1;
            else
            {
                pprec = patt;
                patt = patt->next;
            }
        }

        aux = (list)malloc(sizeof(item));
        aux->value = el;
        aux->next = patt;
        if (patt == L)
            return aux; // inizio lista
        else
        {
            pprec->next = aux;
            return L;
        }
    }
}

int lenght(list L)
{
    int i = 0;
    while (L != NULL)
    {
        i++;
        L = L->next;
    }
    return i;
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

int sumList(list L)
{
    int somma = 0;
    while (L != NULL)
    {
        somma = somma + L->value;
        L = L->next;
    }
    return somma;
}
