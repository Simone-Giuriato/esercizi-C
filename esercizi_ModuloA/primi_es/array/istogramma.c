#include <stdio.h>
/*
Si scriva un programma che richieda in ingresso l'andamento annuale del valore delle azioni
(12 valori interi, uno per ogni mese) e inserisca i valori in un vettore.
Si stampi a video un istogramma orizzontale.
*/

int main()
{
    int a[12], j, tmp = 0;

    for (int i = 0; i < 12; i++)
    {
        printf("Inserisci l'azione del %d° mese:", i + 1);
        scanf("%d", &a[i]);
    }

    for (j = 0; j < 12; j++)
    {

        printf("%d:", j + 1);
        tmp = a[j]; // metto il valore dentro una var tmp per avercelo dopp disponibile per stampare quanti * e facilitare la lettura

        while (a[j] != 0)
        { // stampo tanti * quanto è il valore all'interno della variabile

            printf("*");
            a[j]--;
        }
        printf(" (%d)\n", tmp);
    }
}