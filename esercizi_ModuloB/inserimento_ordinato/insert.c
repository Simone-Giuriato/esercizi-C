#include "insert.h"

boolean insert(int intArray[], int newItem, int dim, int *N) {
	int i = 0, j;
	boolean found = FALSE;
	if (*N < dim) {
		// dim. logica < dim. fisica
		while ((i < *N) && !found) {
		//ricerca della posizione di inserimento
			if (newItem <= intArray[i]) {
				found = TRUE;
			}
			else {
				i++;
			}
		}
		if (found) {
		//eventuale shift
			for(j = *N; j > i; j--) {
				//shift
				intArray[j] = intArray[j - 1]; 
			}
		}

		//inserimento e notifica del successo
		intArray[i] = newItem; 
		(*N)++;
		return TRUE;
	}
	return FALSE;
}