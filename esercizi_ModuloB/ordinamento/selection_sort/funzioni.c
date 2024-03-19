
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

#define DIM 11

void swap(float *a, float *b)   //mi serve una funzione swap per fare il naiveSort
{

    float tmp = *a;
    *a = *b;
    *b = tmp;
}

void naiveSort(float a[], int dim)
{
    int j, i, posmin;
    float min;

    for (j = 0; j < dim; j++)
    {
        posmin = j;
        for (min = a[j], i = j + 1; i < dim; i++)
            if (a[i] < min)
            {
                posmin = i;
                min = a[i];
            }

        if (posmin != j)
            swap(&a[j], &a[posmin]);
    }
}