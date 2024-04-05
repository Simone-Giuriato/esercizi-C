#include <stdio.h>
#include <stdlib.h>

#define DIM 100

typedef int ARRAY[DIM];
typedef enum {falso, vero} boolean;

int compare_int(const void* a, const void* b);
boolean ricerca_bin(ARRAY a, int N, int el, int *pos);