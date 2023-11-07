/*
Scrivere un programma C che definisca la struttura “punto” composta dalle sue coordinate x e y (float) in un piano cartesiano.
Si richieda all’utente di inserire le coordinate di 4 punti (A, B, C, D).
Si calcoli e si stampi a video il perimetro (float) della figura (racchiuso tra @) che ha per lati i segmenti: AB, BC, CD, DA.

CONSIGLIO: Per calcolare la radice quadrata utilizzare la funzione double sqrt(double x) della libreria math.
Per verificare come utilizzare correttamente la funzione sqrt consultare il man di Linux.
gcc nomefile.c -o nomefile -lm
*/
#include <stdio.h>
#include <math.h>

typedef struct
{
    float x;
    float y;

} punto;

punto leggi_punto()
{
    printf("Inserisci coordinate del punto(x y):");
    punto p;
    scanf("%f %f", &p.x, &p.y);

    return p;
}

float Distanza(punto punto1, punto punto2)
{
    float a, b;

    a = punto1.x - punto2.x;
    b = punto1.y - punto2.y;

    return sqrt((a * a) + (b * b));
}

int main()
{

    punto A, B, C, D;
    float AB, BC, CD, DA;
    float perimetro;

    A = leggi_punto();
    B = leggi_punto();
    C = leggi_punto();
    D = leggi_punto();

    AB = Distanza(A, B);
    BC = Distanza(B, C);
    CD = Distanza(C, D);
    DA = Distanza(D, A);

    perimetro = AB + BC + CD + DA;

    printf("Il perimetro vale: @%f@\n", perimetro);
}