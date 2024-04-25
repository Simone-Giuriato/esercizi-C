/*Sapendo che il file elenco1.txt ha almeno 20 studenti,
si scriva una funzione (funzioneAB) per caricare i soli nomi
dei primi venti studenti in un array V di 20 stringhe (ognuna al massimo di 50 char). Questa funzione (funzioneAB)
riceve come parametri il vettore V e il puntatore al file elenco1.txt
 più eventuali parametri a scelta, e restituisce void.

Nel main, si ordini il vettore V tramite una opportuna chiamata della funzione qsort
 e si stampi poi su un file di testo outputAB.txt
il contenuto dell’array V.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM 50

typedef struct
{
    char nome[DIM];
    char cognome[DIM];
} Persona;

typedef Persona P[20];

void AB(P elenco, FILE *f, int *n)
{
    f = fopen("elenco1.txt", "rt");
    if (f == NULL)
    {
        printf("Errore nell'apertura del file elenco1.txt");
        exit(-1);
    }

    while (fscanf(f, "%s %s", elenco[*n].nome, elenco[*n].cognome) != EOF && (*n) < 20)
    {
        (*n)++;
    }
    fclose(f);
}

/*void stampa(P elenco, int n) {
    for (int i = 0; i < n; i++) {
        printf(" %s \n", elenco[i].nome);
    }
}*/

int compare(const void *a, const void *b)
{
    return strcmp(((Persona *)a)->nome, ((Persona *)b)->nome);
} // guarda soluzione perche non so sta parte

int main()
{
    P elenco;

    FILE *f = NULL;
    int n = 0;

    AB(elenco, f, &n);
    // stampa(elenco, n);
    qsort(elenco, n, sizeof(Persona), compare);

    f = fopen("outputAB.txt", "wt");
    if (f == NULL)
    {
        printf("Errore nell'apertura del file outputAB.txt");
        exit(-1);
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%s %s\n", elenco[i].nome, elenco[i].cognome);
    }

    fclose(f);

    return 0;
}