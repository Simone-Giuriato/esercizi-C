#include "compare.h"

/*
Confronto a e b
a<b --> -1
a==b --> 0
a>b -->  1
*/

int compare_float(const void* a, const void* b) {
	float v1,v2;
	v1 = *(float*) a;
	v2 = *(float*) b;

	if(v1 < v2) return -1;
	else if(v1 == v2) return 0;
	else return 1;
}

int compare_float_p(const void* a, const void* b) {
	float *v1, *v2;
	v1 = (float*) a;
	v2 = (float*) b;

	if(*v1 < *v2) return -1;
	else if(*v1 == *v2) return 0;
	else return 1;
}


//queste 2 funzioni fanno la stessa cosa ma in modo differente, vedere compare.h

//IN main.c viene usata compare_float_p