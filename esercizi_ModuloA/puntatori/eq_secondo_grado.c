/*
Si scriva un programma in linguaggio C che, dati 3 valori a, b e c, fornisce le soluzioni dell’equazione di secondo grado:

ax^2 + bx + c = 0

Nel main, il programma deve:
- leggere da tastiera i coefficienti a, b e c;
- invocare una funzione "radici";
- infine stampare i risultati.

La funzione radici deve comunicare al main:
- se le radici sono reali o no;
- il valore delle radici (nel caso queste siano reali).
*/
#include <stdio.h>
#include <math.h>       //gcc eq_secondo_grado.c -o eq -lm (-lm alla fine)

void radici(float a, float b, float c, float *rad1, float *rad2, int *ok)
{ // variabile ok per dire se radici reali o no

float delta;
delta=((b * b) - (4 * a * c));

    if (delta >= 0)
    { // se sono reali:

    *rad1=(-b+sqrt(delta))/2*a;
    *rad2=(-b-sqrt(delta))/2*a;

    
    }
    else
    {
        *ok = 0; // radici non reali pongo ok=0
    }
}

int main()
{
    float a, b, c, rad1, rad2;
    int ok=1;   //fondamentale porre un valore non 0 perche è come un bool

    printf("Programma per il calcolo di equazioni di secondo grado\n");

    printf("Inserisci il coefficiente a:");
    scanf("%f", &a);
    printf("Inserisci il coefficiente b:");
    scanf("%f", &b);
    printf("Inserisci il coefficiente c:");
    scanf("%f", &c);

    radici(a, b, c, &rad1, &rad2, &ok);

    if(ok==0){
        printf("Radici non reali.\n");
    }else{
        printf("Radici reali:\n radice 1: %f\n radice 2: %f", rad1,rad2);
    }
}