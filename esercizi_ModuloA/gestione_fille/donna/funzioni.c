#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "header.h"

void lettura(int M[255][255], int *W, int *H, int *S)
{
    FILE *f;
    f = fopen("immag.pgm", "rt");
    if (f == NULL)
    {
        printf("Errore nell'apertura del file imag.pgm");
        exit(-1);
    }
    char s[3]; // stringa P2

    fscanf(f, "%s", s); // leggo P2
    fscanf(f, "%d %d %d", W, H, S);
    // printf("%d %d %d", *W,*H,*S);
    M[*H][*W] = 0;

    for (int i = 0; i < *H; i++)
    {
        for (int j = 0; j < *W; j++)
        {
            fscanf(f, "%d", &M[i][j]);
        }
    }
    fclose(f);
}

