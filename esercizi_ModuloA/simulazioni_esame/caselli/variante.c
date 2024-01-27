// svolge la seconda parte (da 4 pti.)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    char nome[20];
    int inizio; // 0 a 23
    int fine;   // 1 a 24

} turno;

int lettura(turno T[])
{ // lettura casello.bin
    FILE *fb;
    fb = fopen("casello.bin", "rb");
    if (NULL == fb)
    {
        printf("Erore nell'apertura del file casello.bin");
        exit(-1);
    }
    int n = 0;
    n = fread(T, sizeof(turno), 100, fb);

    printf("Ecco la lista dei casellanti con i loro turni:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d\n", T[i].nome, T[i].inizio, T[i].fine);
    }
    fclose(fb);
    return n;
}

void lettura_fasce(unsigned char C[])
{
    FILE *f;
    int i = 0;

    f = fopen("casellanti.bin", "rb");

    while (fread(&C[i], sizeof(unsigned char), 1, f) > 0) // legge, altro modo (seguire questo)
    {
        i++;
    }

    fclose(f);
}
int casellanti_ora(turno T[], int orario, int n)
{ // n è il numero di casellanti nel file //restituisce il numero di casellanti per ogni ora
    int num_casellanti = 0;

    for (int i = 0; i < n; i++)
    {
        if (T[i].fine - T[i].inizio < 0)
        {
            if ((orario >= T[i].inizio || orario < T[i].fine)) // modifica per la seconda parte: caso in cui turno supera mezzanotte
                num_casellanti++;
        }
        else
        {
            if ((orario >= T[i].inizio && orario < T[i].fine)) // rimane come nella prima parte
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

void elabora_2(turno T[], int N, unsigned char C[])
{

    printf("Turni scoperti (con il numero di casellanti variabile):\n");

    for (int j = 0; j < 25; j++)
    {
        if (casellanti_ora(T, j, N) < ((int)C[j]))
            printf("Ore %d numero casellanti %d\n", j, casellanti_ora(T, j, N));
    }
}

int main()
{
    turno T[100]; // info data dalla consegna
    unsigned char C[100];
    int n = 0;      // numero righe che mi darà la funzione lettura
    n = lettura(T); // legge il file casello.bin e ne stampa a video il contenuto
    // elabora(T, n);  // elaborazione che stampa gli orari scoperti dai casellanti (richiama un altra funzione all'interno)
    lettura_fasce(C);   // aggiunta variante
    elabora_2(T, n, C); // aggiunta variante prende il posto della funzione variante poichè non ho fasse fisce ma cambiano in base a casellanti.bin
}