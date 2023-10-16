#include <stdio.h>
/*
Si legga da tastiera un numero N, compreso fra 1 e 100.
Si stampino poi i numeri da 1 a N, escludendo:
- i multipli di 7
- i numeri in cui una cifra è 7
In questi casi, bisogna stampare “BUM!”*/

int main()
{
    int n = 0;

    printf("Inserisci un numero da 1 a 100:");
    scanf("%d", &n);
    int i = 1;

    while (i >= 1 && i <= n)
    {

        if (i == 17 || i == 27 || i == 37 || i == 47 || i == 57 || i == 67 || i == 71 || i == 72 || i == 73 || i == 74 || i == 75 || i == 76 || i == 77 || i == 78 || i == 79 || i == 87 || i == 97 || i % 7 == 0)
        {
            printf("BUM\t");
        }
        else
        {
            printf("%d\t", i);
        }

        i++;
    }
}