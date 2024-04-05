#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compare.h"


#define DIM 11



int main(){

    float elemento;
    float a[DIM];
    int n=0;

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

    qsort(a,n,sizeof(float),compare_float_p); //occhio ai parametri della qsort (libreria stdlib.h)

    printf("Ecco il Vettore ordinato:");

    for(int i=0; i<n;i++){
        printf("\n%f",a[i]);

    }
}