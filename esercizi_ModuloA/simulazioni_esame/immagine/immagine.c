#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void lettura(int M[100][100], int *W, int *H, int *S)
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

char calcolo_carattere(int a, int S){
    if(a>(S/2)){
        return '*';

    }else if (a<(S/2)){
        return ' ';

    }
}

void visualizzazione(int M[100][100], int W, int H, int S){
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
    int M[100][100];
    int W; // larghezza
    int H; // altezza
    int S; // numero sfumature

    lettura(M, &W, &H, &S);
    visualizzazione(M, W, H, S);
}