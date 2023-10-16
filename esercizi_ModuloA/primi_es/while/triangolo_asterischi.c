#include <stdio.h>
/*Dato un numero di righe N, disegnare sullo schermo la seguente figura (esempio per N = 5)
    *
   ***
  *****
 *******
*********
*/

int main()
{
    int n = 0;

    printf("Inserisci quante righe è formato il triangolo:");
    scanf("%d", &n);

    int i = 0;
    int c = 1; // Numero di asterischi
    int a, b;

    while (i != n)
    {
        a = n - i - 1;

        while (a > 0)
        {
            printf(" ");
            a--;
        }

        b = c;

        while (b > 0)
        {
            printf("*");
            b--;
        }

        printf("\n");

        i++;
        c =c+ 2;
    }

    
}