/*
Si scriva un programma in C che legga da tastiera una
sequenza di numeri interi, uno alla volta, e li inserisca in un
vettore di dimensione fisica DIM e dimensione logica N. L’inserimento termina quando l’utente inserisce 0 o quando
l’array è pieno (ovvero quando sono stati già inseriti DIM
elementi).
Ordinare il vettore con la funzione qsort (ricordarsi di
definire opportunamente la relativa compare)Letto un numero da tastiera, cercare tale numero nell’array
mediante una ricerca binaria. A tale scopo, implementare la
funzione ricerca_bin:
boolean ricerca_bin(ARRAY a, int N, int el, int *pos) 
che dati in input un vettore, la sua dimensione logica, l’elemento da cercare e il
puntatore alla posizione.
La funzione restituisce true se l’elemento è
presente nel vettore, false altrimenti, e la posizione dell'elemento cercato (se presente) in pos.
*/

#include <stdio.h>
#include "funzioni.h"


int main() {
	int k = 0, elem, i, pos;
	ARRAY a;

	printf("Inserisci un numero intero, 0 per concludere: \n");
	scanf("%d", &elem);

	while(elem != 0 && k <= DIM) {
		a[k] = elem;
		k++;

		printf("Inserisci un numero intero, 0 per concludere: \n");
		scanf("%d", &elem);
	}
	
	printf("Sono stati inseriti %d elementi su %d disponibili\n", k, DIM);
	//ordino il vettore
	qsort(a, k, sizeof(int), compare_int);

	printf("\nVettore ordinato:\n");
	for(i = 0; i < k; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("\nInserisci il numero da cercare: \n");
	scanf("%d", &elem);

	if((ricerca_bin(a, k, elem, &pos))) {
		printf("L'elemento %d è presente nel vettore alla posizione: %d\n", elem, pos);
	} else {
		printf("L'elemento %d non è presente nel vettore\n", elem);
	}

	return 0;
}