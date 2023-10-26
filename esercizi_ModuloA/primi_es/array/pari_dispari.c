#include <stdio.h>

/*
- Legga da tastiera 10 elementi interi e li inserisca in un array opportuno
- Stampi a video il numero di elementi pari e quello di elementi dispari presenti nel vettore.
*/

int main()
{
    int a[10], pari, dispari = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Inserisci il %d° valore:", i);
        scanf("%d", &a[i]);

        if (a[i] % 2 == 0)
        {
            pari++;
        }
        else
        {
            dispari++;
        }
    }

    printf("Il numero di elementi pari è: %d\n", pari);
    printf("Il numero di elementi disapri è: %d\n", dispari);
}