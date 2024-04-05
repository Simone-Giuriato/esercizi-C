/*    Si scriva un programma in C che legga da tastiera una sequenza di numeri interi, uno alla volta, e li inserisca in un vettore ordinato in senso non decrescente preservando l’ordinamento del vettore ad ogni passo di inserimento. Il vettore ha dimensione fisica DIM e dimensione logica N.
    L’inserimento termina quando l’utente inserisce 0 o quando l’array è pieno (ovvero quando sono stati già inseriti DIM elementi)
    Per inserire ciascun nuovo valore nel vettore si utilizzi la funzione insert (da definire in un file insert.c).*/

#include <stdio.h>
#include "insert.h"

#define DIM 10

void main() {
	int v[DIM], N = 0, i = 0, newItem = 0;

	printf("Inserisci un numero intero, 0 per concludere: \n");
	scanf("%d", &newItem);

	while(newItem != 0 && insert(v, newItem, DIM, &N)) {
		printf("Inserisci un numero intero, 0 per concludere: \n");
		scanf("%d", &newItem);
	}
	
	printf("Sono stati inseriti %d elementi su %d disponibili: ", N, DIM);
	for(i = 0; i < N; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}