/*Si scriva un programma in C che legga da tastiera una sequenza di numeri interi, uno alla volta, e li inserisca in un vettore di dimensione fisica DIM e dimensione logica N. L’inserimento termina quando l’utente inserisce 0 o quando l’array è pieno (ovvero quando sono stati già inseriti DIM elementi). 
Letto un numero da tastiera, cercare tale numero nell’array mediante una ricerca esaustiva. 
A tale scopo, implementare la funzione ricerca: 
int ricerca (vettore vet, int el, int N, int *pos) 
che dati in input un vettore, l’elemento da cercare e il puntatore alla posizione, restituisce 1 se l’elemento è presente nel vettore, 0 altrimenti.*/
#include <stdio.h>
#include <string.h>
#include <stdio.h>

#define DIM 50

int ricerca(int vet[], int el, int N, int *pos)
{

    for (int i = 0; i < N; i++)
    {
        if (vet[i] == el)
        {
            *pos = i;
            return 1; // elemento presente
        }
    }
    return 0; // non è presente l'elemento voluto
}

int main()
{

    int a[DIM];
    int n = 0; // dim logica
    int pos;
    int elemento = 0;

    do
    {
        printf("Inserisci un elemento (0 per terminare): ");
        scanf("%d", &elemento);

        if (elemento != 0)
        {                    // Verifica se l'elemento è diverso da 0
            a[n] = elemento; // Memorizza l'elemento nell'array
            n++;             // Incrementa la dimensione logica del vettore
        }

    } while (elemento != 0 && n < DIM); // Termina l'inserimento se viene inserito 0 o raggiunta la dimensione massima

    printf("\nInserisci l'elemento da cercare nell'array appena inserito: ");
    scanf("%d", &elemento);
    printf("%d", ricerca(a, elemento, n, &pos));
}