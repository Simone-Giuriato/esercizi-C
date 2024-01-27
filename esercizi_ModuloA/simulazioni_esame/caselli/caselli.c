
// svolge la prima parte (da 16 pti.) vedere variante.c per la seconda parte
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    char nome[20];
    int inizio;
    int fine;

} turno;

int lettura(turno T[])
{
    FILE *fb;
    fb = fopen("casello.bin", "rb");
    if (NULL == fb)
    {
        printf("Erore nell'apertura del file casello.bin");
        exit(-1);
    }
    int n = 0;
    n = fread(T, sizeof(turno), 100, fb);

    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d\n", T[i].nome, T[i].inizio, T[i].fine);
    }
    fclose(fb);
    return n;
}
int casellanti_ora(turno T[], int orario, int n)
{ // n è il numero di casellanti nel file //restituisce il numero di casellanti per ogni ora
    int num_casellanti = 0;

    for (int j = 0; j < n; j++)
    {
        if (orario >= T[j].inizio && orario < T[j].fine)
        {
            num_casellanti++;
        }
    }
    return num_casellanti;
}

void elabora(turno T[], int n)
{
    int num_casellanti;
    printf("Orari scoperti dai casellanti (<4 casellanti):\n");

    for (int i = 0; i < 24; i++)
    {
        num_casellanti = casellanti_ora(T, i, n);
        if (num_casellanti < 4)
        {
            printf("Ore: %d, con %d casellanti\n", i, num_casellanti); // i= ora del giorno
        }
    }
}

int main()
{
    turno T[100];   // info data dalla consegna
    int n = 0;      // numero righe che mi darà la funzione lettura
    n = lettura(T); // legge il file casello.bin e ne stampa a video il contenuto
    elabora(T, n);  // elaborazione che stampa gli orari scoperti dai casellanti (richiama un altra funzione all'interno)
}