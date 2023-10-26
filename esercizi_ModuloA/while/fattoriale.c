#include <stdio.h>
/*
Scrivere un programma C che, dato un numero intero N, calcoli il fattoriale di tutti i numeri interi minori o uguali a N. Si usi il tipo di ciclo ritenuto più adeguato.
*/

int main()
{
    int num = 0;
    int i = 1;
    int fattoriale = 1;
    int c = 0;

    printf("Inserisci un numero:");
    scanf("%d", &num);

    printf("Il numero dato è %d, ora avrai i fattoriale dei numeri minori uguali a questo numero\n", num);

    while (i <= num)
    {
        while (c != i)
        {
            c = c + 1;

            fattoriale = fattoriale * c;
        }
        printf("Il numero %d ha fattoriale:%d\n", i, fattoriale);

        i++;
        c = 0;
        fattoriale = 1;
    }
}