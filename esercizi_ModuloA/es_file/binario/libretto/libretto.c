/*Si scriva un programma che legga un file binario: “libretto.bin” in cui sono presenti gli esami sostenuti e il relativo voto e produca in uscita un file di testo "libretto.txt" contenente la copia dei dati letti dal file binario e in ultima riga l'esame con il voto più alto.
Si divida opportunamente il programma in procedure / funzioni.

Il file “libretto.txt” deve avere la stesa struttura del file “libretto.bin” composta da una stringa di al più 20 caratteri più il terminatore e un numero intero.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char materia[21];
    int voto;
} esame;

int lettura(esame E[])
{
    FILE *b;
    b = fopen("libretto.bin", "rb");
    if (NULL == b)
    {
        printf("ERRORE nell'apertura del file libretto.bin");
        exit(-1);
    }
    int n = 0;
    n = fread(E, sizeof(esame), 100, b);
    fclose(b);
    return n;
}
void scrittura(int n, esame E[])
{
    FILE *f;
    f = fopen("libretto.txt", "wt");
    if (NULL == f)
    {
        printf("ERRORE nell'apertura del file libretto.txt");
        exit(-1);
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%s %d\n", E[i].materia, E[i].voto);
    }
    int voto_max = 0;
    char materia_max[21];

    for (int i = 0; i < n; i++)
    {
        if (E[i].voto > voto_max)
        {
            voto_max = E[i].voto;
            strcpy(materia_max, E[i].materia);
        }
    }

    fprintf(f, "La materia migliore: %s con il voto di: %d", materia_max, voto_max);
}

int main()
{
    esame E[100];
    int n = 0;
    n = lettura(E);
    scrittura(n, E);

    int voto_max = 0;
    char materia_max[21];
}