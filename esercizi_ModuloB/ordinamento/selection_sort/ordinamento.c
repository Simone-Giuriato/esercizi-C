//NAIVE SORT o SELECTION SORT
/*COMANDI:
gcc -c main.c
gcc -c funzioni.c
gcc -o anagrafe main.o funzioni o
./anagrafe*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

#define DIM 11

int main()
{

    float a[DIM];
    int n = 0; // dim logica
    int pos;
    float elemento = 0;

    do
    {
        printf("Inserisci un elemento (0 per terminare): ");
        scanf("%f", &elemento);

        if (elemento != 0)
        {                    // Verifica se l'elemento è diverso da 0
            a[n] = elemento; // Memorizza l'elemento nell'array
            n++;             // Incrementa la dimensione logica del vettore
        }

    } while (elemento != 0 && n < DIM); // Termina l'inserimento se viene inserito 0 o raggiunta la dimensione massima

    naiveSort(a, n);

    printf("Ecco l'array ordinato:\n");

    for (int j = 0; j < n; j++)
    {
        printf("%.2f\n", a[j]);
    }
}