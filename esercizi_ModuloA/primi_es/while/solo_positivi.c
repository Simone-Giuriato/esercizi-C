#include <stdio.h>


int main()
{

    int num = 1; // num vale 1 per farlo entrare nel ciclo while, subito dopo verrà cambiato con il valore inserito dall'utente
    printf("Inserisci un numero (0 per terminare):");

    int somma = 0;
    float media = 0;
    int i = 0;

    while (num != 0)
    {

        scanf("%d", &num);
        if (num > 0)
        {
            i++;
            somma = somma + num;
        }
    }
    media = somma / i;

    printf("La somma e': @%d@\n", somma);
    printf("La media e': @%f@\n", media);
}