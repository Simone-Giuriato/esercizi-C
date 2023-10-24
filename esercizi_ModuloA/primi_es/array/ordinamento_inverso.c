#include <stdio.h>

/*
- Legga una sequenza di 10 interi e la memorizzi in un array;
- Chieda all'utente attraverso una funzione con l'interfaccia int ordine() se vuole che la sequenza venga stampata nello stesso ordine di inserimento o in ordine inverso, che legga la risposta seguente: (char 's' per 'stesso', 'i' per 'inverso'); qualora l'utente inserisca un carattere diverso da 's' e 'i', la funzione deve chiedere nuovamente di inserire la risposta. 
- Stampi l'array nell'ordine richiesto. Il programma deve stampare a video la sequenza fra simboli @ (chiocciola/a commerciale) come indicato nella figura riportata di seguito. I numeri all'interno della sequenza devono essere separati da uno, o più, spazi.
*/

int ordine()
{
    char risposta;

    do
    {

        printf("In che ordine vuoi stampare l'array? (s per avere lo stesso ordine, i per l'ordine inverso):\n");
        scanf(" %c", &risposta);

    } while (risposta != 'i' && risposta != 's');

   
    if (risposta == 'i')
    {
        return 1;
    }
    else
    {
        return 2; // se inserisce 's'
    }
}

int main()
{
    int a[10];
    int lettera = 0;

    for (int i = 0; i < 10; i++)
    {

        printf("Inserisci il %d ° valore:", i + 1);
        scanf("%d", &a[i]);
    }

    lettera = ordine();

    printf("@");

    if (lettera == 1)
    {
        for (int i = 9; i >= 0; i--)
        {
            printf("%d", a[i]);
            if (i > 0)
            {
                printf(" ");
            }
        }
    }
    else
    {

        for (int i = 0; i < 10; i++)
        {
            printf("%d", a[i]);
            if (i < 9)
            {
                printf(" ");
            }
        }
    }
    printf("@\n");
}