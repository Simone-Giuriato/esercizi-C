#include <stdio.h>
/*
Si scriva un programma C che:
- Legga da tastiera 10 elementi interi e li inserisca in un vettore di dimensione opportuna;
- Verifichi se la sequenza è ordinata in ordine strettamente crescente e stampi a video il risultato
*/

int main()
{
    int a[10], crescente, dec = 0;
    ;

    for (int i = 0; i < 10; i++)
    {
        printf("Inserisci il %d° valore:", i + 1);
        scanf("%d", &a[i]);
    }

    for (int j = 0; j < 9; j++)
    { // si ferma a 9 perchè l'ultimo elemento non deve fare confronti
        if (a[j] < a[j + 1])
        {
            crescente++;
        }
    }

    if (crescente == 9)
    {
        printf("L'array è ordinato in senso strettamente crescente\n");
    }
    else
    {
        printf("L'array NON è ordinato in senso strettamente crescente\n");
    }
}