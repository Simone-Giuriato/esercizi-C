//FUNSIONI CHE HANNO COME PARAMETRI ALTRE FUNZIONI
// gcc es1.c -o es1 -lm

/*
Si realizzi un programma che calcola la somma e la media di una
funzione f : R Ñ R in un intervallo dato [a,b].

Definire una funzione sommaf che restituisca il valore della som-
matoria, con la seguente interfaccia:

double sommaf(double (*f)(double par), int m, int n);
dove f è la funzione matematica di cui calcolare la sommatoria, a
e b gli estremi dell’intervallo.
Definire poi una funzione mediaf che restituisca il valore della
media, con la seguente interfaccia:
double mediaf(double (*f)(double par), int m, int n);

La funzione main deve eseguire le seguenti operazioni:
1 Chiedere all’utente di inserire da tastiera gli estremi
dell’intervallo (int a, int b)
2 Chiamare la funzione sommaf passando come parametri:
una funzione matematica, di libreria o definita da
programma (ad esempio funzioni seno e coseno, funzione
reciproco 1/x, etc...)
i due estremi dell’intervallo inseriti dall’utente
3 Stampare a video il risultato della funzione sommaf
Ripetere i punti 2 e 3 con la funzione mediaf.
*/

#include <stdio.h>
#include <math.h>

double sommaf(double (*f)(double par), int m, int n) // il par si può omettere
{
    int k;
    double sum = 0;
    for (k = m; k <= n; k++)
    {
        sum = sum + (*f)(k); // sum= sum + ciò che ritorna la funzione che ho passato dal main (in questo caso il coseno), in funzione di k
    }

    return sum;
}

double mediaf(double (*f)(double par), int m, int n)
{
    int k;
    int j = 0;
    double sum = 0;
    double media = 0;
    for (k = m; k <= n; k++)
    {
        sum = sum + (*f)(k);
        j++;
    }
    media = sum / j; // faccio la media

    return media;
}

int main()
{
    int a, b;
    printf("Inserisci i due estremi dell'intervallo:");
    scanf("%d %d", &a, &b);

    printf("La somma è: %lf\n", sommaf(cos, a, b));
    printf("La media è: %lf\n", mediaf(cos, a, b));
}