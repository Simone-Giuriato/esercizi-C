#include "funzioni.h"

boolean ricerca_bin(ARRAY a, int N, int el, int *pos){
	int first=0, last=N-1, med=(first+last)/2;
	boolean Trovato=falso;

	while ( (first<=last) && (!Trovato) ){
		if (el==a[med]){
			Trovato=vero; 
			*pos=med;
		} else {
			if (el < a[med]) {
			last=med-1;
			} else { 
				first=med+1;
			}
		}
		med = (first + last) / 2;
	}
	return Trovato;
}

/*
 * Confronta due interi a e b e restituisce:
 * a < b  => -1
 * a == b => 0
 * a > b  => 1
 */
int compare_int(const void* a, const void* b) {
	int v1,v2;
	v1 = *(int*) a;
	v2 = *(int*) b;

	if(v1 < v2) return -1;
	else if(v1 == v2) return 0;
	else return 1;
}