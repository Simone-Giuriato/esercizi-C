
#include <stdio.h>

/*
Si scriva una funzione range(int start, int stop, int step) che stampi una sequenza ordinata di numeri interi a partire dall'intero "start" (compreso) fino all'intero "stop" (non compreso) con un passo dato dal parametro "step".


Esempio:
range(1,10,2) -> 1 3 5 7 9


All'interno del main richiamare la funzione range per stampare i risultati delle tabelline dall'1 ad un numero N letto da tastiera.
*/

void range(int start, int stop, int step)
{
	int i;
	for (i = start; i < stop; i = i + step)
	{
		printf("%d ", i);
	}
}

int main()
{
	int n;
	printf("Inserisci numero\n");
	scanf("%d", &n);
	printf("Stampo tabelline da 1 a %d\n", n);

	for (int i = 1; i <= n; i++)
	{
		range(i, i * 10 + 1, i);
		printf("\n");
	}
}