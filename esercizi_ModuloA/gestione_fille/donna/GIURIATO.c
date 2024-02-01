//file contente main del primo esercizio da 16pti
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "header.h"



char calcolo_carattere(int a, int S){
    if(a>(S/2)){
        return '*';

    }else if (a<(S/2)){
        return ' ';

    }
}

void visualizzazione(int M[255][255], int W, int H, int S){
    char c;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
           c=calcolo_carattere(M[i][j],S);
           printf("%c",c);
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

    lettura(M, &W, &H, &S);
    visualizzazione(M, W, H, S);
}