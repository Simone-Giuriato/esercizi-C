/*
Si scriva un programma C che:
- legge da tastiera, tramite una funzione int input(int array[]), un intero N (al massimo 100) e un array di N interi, e restituisce N;
- calcola la somma degli elementi dell'array, tramite una funzione int somma(int array[], int n);
- calcola la media degli elementi dell'array, tramite una funzione float media(int array[], int n);
- calcola il numero degli elementi pari dell'array, tramite una funzione int conta_pari(int array[], int n);
- infine, mostri a video i risultati ottenuti.

Nota: per la soluzione riferirsi alle soluzioni dell'esercitazione 8
*/
#include <stdio.h>

int input(int array[])
{
    int n = 0;

    printf("Inserisci quindi numeri vuoi inserire nell'array (massimo 100):");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Inserisci elemento:");
        scanf("%d", &array[i]);
    }

    return n;
}

int somma(int array[], int n)
{
    int s = 0;

    for (int i = 0; i < n; i++)
    {
        s = s + array[i];
    }

    return s;
}

float media(int array[], int n)
{
    int s = somma(array, n);
    return s / n;
}

int conta_pari(int array[], int n)
{
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if ((array[i] % 2) == 0)
        {
            c++;
        }
    }
    return c;
}

int main()
{
    int lung, sum;
    int a[100];
    float m;
    int cPari;

    lung = input(a);
    sum = somma(a, lung);
    m = media(a, lung);
    cPari = conta_pari(a, lung);

    printf("La somma degli elementi è: %d\n", sum);
    printf("La media degli elementi è: %.2f\n", m);
    printf("Il numero di elementi pari è: %d\n", cPari);
}