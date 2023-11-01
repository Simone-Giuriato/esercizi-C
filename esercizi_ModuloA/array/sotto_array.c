#include <stdio.h>

/*
Si scriva un programma C che:
- Attraverso una funzione int lunghezza() legga da tastiera un intero N, l'intero deve essere compreso tra 1 e 20, se non lo è si stampi un messaggio di errore;
- Legga da tastiera N elementi interi e li inserisca in un array chiamato InputArray
- Si chieda una soglia S e si copi:
1. Gli elementi del vettore InputArray che hanno valori maggiori della soglia in un secondo vettore Array2;
2. Gli elementi del vettore InputArray che hanno valori minori della soglia in un terzo vettore Array3;
- Si stampino a video gli elementi di Array2 e Array3

NOTA: negli Array 2 e 3 non devono esserci "buchi", pertanto i vettori dovranno essere i più corti possibili, e contenere tutti gli elementi.

*/

int lunghezza()
{
    int n;

    printf("Inserisci un numero compreso da 1 a 20 (quanti numeri composto l'array):");
    scanf("%d", &n);

    if (n < 1 || n > 20)
    {
        printf("ERRORE");
    }

    return n;
}

int main()
{

    int n = lunghezza();

    int inputArray[n], array2[n], array3[n];
    int s = 0, j = 0, k = 0;

    printf("Inserisci una soglia:");
    scanf("%d", &s);

    for (int i = 1; i <= n; i++)
    {
        printf("Inserisci valore %d dell'array:", i);
        scanf("%d", &inputArray[i]);
    }

    for (int i = 0; i < n; i++)
    {

        if (inputArray[i] > s)
        {
            array2[j] = inputArray[i];
            j++;
        }
        else if (inputArray[i] < s)
        {
            array3[k] = inputArray[i];
            k++;
        }
    }
    printf("ARRAY 2:");

    for (int i = 0; i < j; i++)
    {

        printf("%d ", array2[i]);
    }
    printf("\nARRAY 3:");
    for (int i = 0; i < k; i++)
    {

        printf("%d ", array3[i]);
    }
    printf("\n");
}