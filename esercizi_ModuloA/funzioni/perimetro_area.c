#include <stdio.h>
#include <math.h>

/*
Codificare in C la funzione int perimetro(int a, int b, int c) che, dati i lati a, b, c di un triangolo, ne calcola il perimetro.

Codificare in C la funzione float area(int a, int b, int c) che restituisce l’area di un triangolo i cui lati misurano a, b, c. A tal scopo si usi la formula di Erone  dove p è la metà del perimetro.

Si faccia uso di funzioni dove possibile.
Definire un possibile main che prende in ingresso i tre lati di un triangolo e stampa perimetro ed area.
*/

int perimetro(int a, int b, int c)
{
    int p = 0;
    p = a + b + c;

    return p;
}

float area(int a, int b, int c)
{
    float are;
    float p = 0;
    p = perimetro(a, b, c);
    p = p / 2; // semiperimetro

    are = sqrt(p * (p - a) * (p - b) * (p - c)); // area con formula di Erone
    return are;
}

int main()
{

    int l1, l2, l3 = 0;
    int p = 0;
    float a = 0;
    printf("Inserisci il primo lato del triangolo:");
    scanf("%d", &l1);

    printf("Inserisci il secondo lato del triangolo:");
    scanf("%d", &l2);

    printf("Inserisci il terzo lato del triangolo:");
    scanf("%d", &l3);

    p = perimetro(l1, l2, l3);
    a = area(l1, l2, l3);

    printf("Il perimetro è: %d \nL'area è:%f\n", p, a);
}