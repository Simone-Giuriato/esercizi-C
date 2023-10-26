#include <stdio.h>

/*
Si scriva un programma C che:
- Legga da tastiera 10 elementi interi e li inserisca in un array opportuno
- Calcoli la media aritmetica degli elementi dell'array;
- Chieda all'utente se vuole che vengano stampati i valori dell'array minori o uguali, oppure maggiori, della media;
- Legga la risposta (char: '<' per 'minore o uguale', '>' per 'maggiore');
- Stampi a video gli elementi desiderati
*/

#define DIM 10
int domanda()
{
    char x;
    do
    {
        printf("\nVuoi stampare i valori dell'array maggiori o minori della media?\nInserisci < per valori minori uguali, > per i valori maggiori ");
        scanf(" %c", &x);

    } while (x != '<' && x != '>');

    if (x == '<')
    {
        return 1; // valori minori uguali della media
    }
    else
    {
        return 2; // valori maggiori della media
    }
}

int main()
{
    int a[10], risposta, media, somma = 0;

    for (int i = 0; i < DIM; i++)
    {
        printf("Inserisci valore %d°:", i);
        scanf("%d", &a[i]);
        somma = somma + a[i];
    }

    media = somma / 10; // la media la fa intera
    printf("La media dell'array è: %d", media);

    risposta = domanda();

    if (risposta == 1)
    {

        for (int i = 0; i < DIM; i++)
        {

            if (a[i] <= media)
            {
                printf("%d ", a[i]);
            }
        }
    }
    else
    {

        for (int i = 0; i < DIM; i++)
        {

            if (a[i] > media)
            {
                printf("%d ", a[i]);
            }
        }
    }
}