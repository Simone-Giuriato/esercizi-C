// esame 4-07-2023
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{ // struct contenente solo un campo
    char parola[50];
} element;

typedef struct list_element
{
    element value;
    struct list_element *next;
} item;

typedef struct list_element *list;

int isLess(element a, element b)
{
    if ((strcmp(a.parola, b.parola)) > 0)
    {
        return -1;
    }
    else if ((strcmp(a.parola, b.parola)) == 0)
    {
        return 0;
    }
    {
        return 1;
    }
}

list cons(element a, list l)
{
    list aux = NULL;
    aux = (list)malloc(sizeof(item));
    aux->value = a;
    aux->next = l;

    return aux;
}

list insord(element a, list l)  //non devo avere doppioni
{
     if(l == NULL)
        return cons(a, NULL);
    else{
        if(strcmp(a.parola, l->value.parola) < 0)   //a piu piccola di quella della lista corrente
            return cons(a, l);
        else if(strcmp(a.parola, l->value.parola) == 0) //stesse parole
            return cons(a, l->next);
        else
            l->next = insord(a, l->next);   //a più grande allora vado al prossimo elemento in lista
            return l;
    }
}

list funzioneA(FILE *f, list l)
{
    element a;
    int n;
    while (fscanf(f, "%s", a.parola) != EOF)
    {

        l = insord(a, l);
    }
    return l;
}

void funzione2(FILE *t, list l)
{
    int n = 0;

    while (l != NULL)
    {
        n++;
        fprintf(t, "%s\n", l->value.parola);
        l = l->next;
    }

    fprintf(t, "Le parole in totale sono: %d\n", n);
}

int main()
{

    list L = NULL;
    FILE *f;
    f = fopen("parole.txt", "rt");
    if (f == NULL)
    {
        printf("Errore nell'apertura del file parole.txt");
        exit(-1);
    }

    L = funzioneA(f, L);
    fclose(f);
    /*while(L!=NULL){   //stampo la lista
        printf("%s\n",L->value.parola);
        L=L->next;
    }*/

    FILE *t;
    t = fopen("uniche.txt", "wt");
    if (t == NULL)
    {
        printf("Errore nell'apertura del file uniche.txt");
        exit(-1);
    }

    funzione2(t, L);
    fclose(t);
}