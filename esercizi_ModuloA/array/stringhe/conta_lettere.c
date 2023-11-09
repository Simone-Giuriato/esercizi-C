/*
Scrivere un programma C che chieda all’utente di inserire una stringa (di sole lettere minuscole) e che conti quante volte appare ciascuna delle lettere all’interno della stringa inserita.

Per salvare i risultati del conteggio si crei un vettore di interi in cui la posizione 0 corrisponde alla lettera ‘a’ e l’ultima posizione alla lettera ‘z’.
Stampi a video il vettore creato (sfruttare i codici ASCII).

Esempio di stampa:

a b c d e f g h i ...
[ 3 1 5 0 0 0 1 0 2 ... ]
*/

#include<stdio.h>
#include<string.h>

#define N 256

int main()
{

	int occ[26];
	char str[N],i;

	// Inizializzo il vettore di contatori
	for (i = 0; i < 26; i++)
		occ[i] = 0;

	printf("Inserire la stringa\n");
	scanf("%s", str);

    i = 0;
    while (str[i] != '\0')
    {
        occ[str[i] - 'a'] ++;
        i++;
    }

	printf("  ");
	for (i = 'a'; i <= 'z'; i++)
		printf("%c ", i);
	printf("\n");
	printf("[ ");
	for (i = 0; i < 26; i++)
		printf("%d ", occ[i]);
	printf("]\n");

}