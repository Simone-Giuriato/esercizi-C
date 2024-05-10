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

int lenght(list L, int n) {
    if (L == NULL) {
        return n; // Se la lista è vuota, restituisci la lunghezza corrente
    } else {
        n++;
        return lenght(L->next, n); // Altrimenti, continua a contare dalla prossima posizione
    }
}
void showList(list L)
{
    
    if (L != NULL)
    { // fichè non raggiungo l'ultimo elemento che con gli inserimenti sarà slittato a dx
        // era stato messo a NULL
        printf("%d\n", L->value); //(*L).value
        L = L->next;
        showList(L);
    }
}

int sumList(list L,int somma)
{
    
    if (L != NULL)  //se ho altri elementi faccio somma ancora
    {
        somma = somma + L->value;
        L = L->next;
        sumList(L,somma);
    }else{  //se non ho elementi restituisco la somma direttamente
        return somma;

    }
    
}
