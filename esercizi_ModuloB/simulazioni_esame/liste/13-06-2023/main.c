// 13-06-2023

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int codice;
    char committente[20];
    int costo;
} progetto;

typedef struct list_element
{
    progetto value;
    struct list_element *next;
} item;

typedef item *list;

list cons(progetto P, list l)
{
    list aux = NULL;
    aux = (list)malloc(sizeof(item));
    aux->value = P;
    aux->next = l;

    return aux;
}

list insord(progetto P, list l)
{

    if (l == NULL)
    {
        return cons(P, l);
    }
    else
    {
        if (P.codice <= l->value.codice)
        {
            return cons(P, l);
        }
        else
        {
            l->next = insord(P, l->next);
            return l;
        }
    }
}

list funzione1(FILE *f, list l)
{
    progetto P;

    while (fread(&P, sizeof(progetto), 1, f) > 0)
    {

        l = insord(P, l);
    }
    return l;
}

void funzione2(FILE *b, list l)
{
    int somma = 0;

    while (l != NULL)
    {
        somma = somma + l->value.costo;
        l = l->next;
    }
    fprintf(b, "IL costo totale dei progetti è: %d\n", somma);
}

int main()
{

    list L = NULL;
    FILE *f;
    f = fopen("progetti.bin", "rb");
    if (f == NULL)
    {
        printf("Errore nell'apertura del file progetti.bin");
        exit(-1);
    }

    L = funzione1(f, L);
    fclose(f);
    /*while (L != NULL) //OCCHIO A NON LASCIARLO SUL MAIN PERCHÈ FA DIVENTARE IL PUNTATORE ALLA LISTA NULL, E NON FA ANDARE PIÙ IL RESTO
    {
        printf("%d %s %d\n", L->value.codice, L->value.committente, L->value.costo);
        L = L->next;
    }*/

    FILE *b;
    b = fopen("info1.txt", "wt");

    if (b == NULL)
    {
        printf("Errore nell'apertura del file info1.txt");
        exit(-1);
    }

    funzione2(b, L);
    fclose(b);
}