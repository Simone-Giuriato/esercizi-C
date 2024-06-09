// esame 14/06/2018

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int stato; // 0--> messo male, 1--> buono stato
    int profondità;
} reperto;

typedef struct list_element
{
    reperto value;
    struct list_element *next;
} item;

typedef item *list;

list cons(reperto R, list l)
{
    list aux = NULL;
    aux = (list)malloc(sizeof(item));
    aux->value = R;
    aux->next = l;

    return aux;
}

list insord(reperto R, list l)
{
    if (l == NULL)
    {
        return cons(R, l);
    }
    else
    {
        if (strcmp(R.nome, l->value.nome) < 0)
        {
            return cons(R, l);
        }
        else
        {
            l->next = insord(R, l->next);
            return l;
        }
    }
}

list funzioneA(FILE *f, list L)
{
    reperto R;
    while (fscanf(f, "%s %d %d", R.nome, &R.stato, &R.profondità) != EOF)
    {

        L = insord(R, L);
    }
    return L;
}

void funzioneB(list l)
{

    while (l != NULL)
    {
        printf("%s %d %d\n", l->value.nome, l->value.stato, l->value.profondità);
        l = l->next;
    }
}

void funzioneC(FILE *t, list l)
{
    int somma = 0;
    while (l != NULL)
    {
        if (strcmp(l->value.nome, "anfora") == 0)
        {
            somma++;
        }
        l = l->next;
    }
    fprintf(t, "Il numero di anfore presenti nella lista è: %d", somma);
}

void funzioneD(FILE *b, list l)
{
    while (l != NULL)
    {
        if (l->value.profondità > 3)
        {
            fprintf(b, "%s %d %d\n", l->value.nome, l->value.stato, l->value.profondità);
        }
        l = l->next;
    }
}

int main()
{

    list L = NULL;
    FILE *u;
    FILE *m;
    u = fopen("lucia.txt", "rt");
    if (u == NULL)
    {
        printf("Errore nell'apertura del file lucia.txt");
        exit(-1);
    }

    m = fopen("mara.txt", "rt");
    if (m == NULL)
    {
        printf("Errore nell'apertura del file mara.txt");
        exit(-1);
    }

    L = funzioneA(u, L);
    L = funzioneA(m, L);
    fclose(u);
    fclose(m);

    funzioneB(L);
    FILE *t;
    t = fopen("parola.txt", "wt");
    if (t == NULL)
    {
        printf("Errore nell'apertura del file parola.txt");
        exit(-1);
    }
    funzioneC(t, L);
    fclose(t);

    FILE *b;
    b = fopen("profondi.txt", "wt");
    if (b == NULL)
    {
        printf("Errore nell'apertura del file profondi.txt");
        exit(-1);
    }
    funzioneD(b, L);
    fclose(b);
}