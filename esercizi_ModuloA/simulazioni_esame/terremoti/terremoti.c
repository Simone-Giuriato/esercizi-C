#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float latitudine;
    float longitudine;
    float profondità; // in km
    float magnitudine;
    char luogo[60];

} terremoto;

int lettura(terremoto T[])
{
    FILE *fp;
    fp = fopen("terremoti.txt", "rt");
    if (NULL == fp)
    {
        printf("Errore nell'apertura del file terremoti.txt");
        exit(-1);
    }
    int k = 0;

    while (fscanf(fp, " %f %f %f %f %s", &T[k].latitudine, &T[k].longitudine,
                  &T[k].profondità, &T[k].magnitudine, T[k].luogo) != EOF)
    {
        k++;
    }
    fclose(fp);

    return k; // ritorno il numero delle info
}

void stampa(terremoto T[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %f %f %f %f %s\n", T[i].latitudine, T[i].longitudine,
               T[i].profondità, T[i].magnitudine, T[i].luogo);
    }
}

void visualizza(terremoto T[], int n)
{
    printf("\n\nEcco i terremoti ad alto magnitudine (>5):\n");
    printf("#########################################\n");

    for (int i = 0; i < n; i++)
    {
        if (T[i].magnitudine > 5)
        {
            printf("%f %f %f %f %s\n", T[i].latitudine, T[i].longitudine,
                   T[i].profondità, T[i].magnitudine, T[i].luogo);
        }
    }

    printf("#########################################\n");
}

void elenco(terremoto T[], int n)
{
    FILE *f;
    f = fopen("Alta_Magnitudine.txt", "wt");
    if (NULL == f)
    {
        printf("Errore nell'apertura del file Alta_Magnitudine.txt");
        exit(-1);
    }
    fprintf(f, "Terremoti ad ALta Magnitudine (>5):\n");

    for (int i = 0; i < n; i++)
    {
        if (T[i].magnitudine > 5)
        {
            fprintf(f, " %f %f %f %f %s\n", T[i].latitudine, T[i].longitudine,
                    T[i].profondità, T[i].magnitudine, T[i].luogo);
        }
    }
    fclose(f);
}

int main()
{

    terremoto T[100];
    int n = 0; // numero dei terremoti letti dal file

    n = lettura(T);
    stampa(T, n);     // stampa tutto il contenuto del file
    visualizza(T, n); // stampa solo terremoti ad alta magnitudine (>5)
    elenco(T, n);     // elenco in un file di testo i terrremoti ad alta magnitudine
}