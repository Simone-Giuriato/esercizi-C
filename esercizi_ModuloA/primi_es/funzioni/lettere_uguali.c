#include <stdio.h>
/*
Codificare in linguaggio C la funzione
int uguale(char a, char b)
che restituisce:
1 se i due caratteri sono uguali, oppure rappresentano la stessa lettera (anche se una delle due è maiuscola e l'altra minuscola).
0 altrimenti.

Per esempio, devono fornire 1 le invocazioni: uguali('r','R'), uguali('*','*'), uguali('F','f')
mentre forniscono 0 le invocazioni: uguali('F','&'), uguali('!','A').

Suggerimento: Utilizzare codice ASCII.
*/

int uguale(char a, char b)
{

    if ((a == b) || (a + 32) == b || (b + 32) == a) //32 è la differenza tra a e A
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char l1, l2;
    char risultato = 0;

    printf("Inserisci i primo carattere:");
    scanf("%c", &l1);

    printf("Inserisci il secondo carattere:");
    scanf(" %c", &l2);  //aggiunto spazio in " %c" per non creare problemi di buffer 

    risultato = uguale(l1, l2);

    if (risultato == 1)
    {
        printf("I due caratteri sono uguali\n");
    }
    else
    {
        printf("I due caratteri NON sono uguali\n");
    }
}