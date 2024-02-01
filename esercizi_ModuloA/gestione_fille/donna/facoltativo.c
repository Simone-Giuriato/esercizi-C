#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "header.h"

typedef struct
{
    int inf;
    int sup;
    char car;
} scala;



int lettura_b(scala B[])
{
    FILE *b;
    b = fopen("scala.bin", "rb");
    if (b == NULL)
    {
        printf("Errore nell'apertura del file scala.bin");
        exit(-1);
    }
    int n = 0; // numero righe lette

    n = fread(B, sizeof(scala), 255, b);
    fclose(b);
   /* for(int i=0;i<n;i++){
        printf("%d %d %c\n", B[i].inf, B[i].sup, B[i].car);
    }*/
    return n;
}

char calcolo_carattere(int a, int S,scala B[],int n)
{
   for(int i=0;i<n;i++){
    if(a>=B[i].inf && a<=B[i].sup){
       return B[i].car;
    }
   }
}

void visualizzazione(int M[][255], int W, int H, int S, scala B[], int n)
{
    char c;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            c = calcolo_carattere(M[i][j], S,B,n);
            printf("%c", c);
        }
        printf("\n");
    }
}

int main()
{
    int M[255][255];
    int W; // larghezza
    int H; // altezza
    int S; // numero sfumature
    scala B[255];
    int n=0; //numero righe effettive

    lettura(M, &W, &H, &S);
    n=lettura_b(B); //seconda parte
    visualizzazione(M, W, H, S,B,n);
}