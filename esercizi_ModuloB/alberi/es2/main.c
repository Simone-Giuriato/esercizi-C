/*
gcc -c main.c
gcc -c function.c
gcc -o alberi main.o function.o


*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

// ALBERI BINARI DI RICERCA

int main()
{
    tree T;
    T = NULL;
    int scelta = 0; // bool per uscire
    int uscita = 0;
    int numero = 0;    // numero da inserire nell'albero
    int risposta = 0;  // bool risposta per continuare ad inserire elementi nell'albero
    int ricercato = 0; // elemento inserito da l'utente per essere cercato tra gli elementi dell'albero
    int trovato = 0;   // bool per dire se l'elemento cercato è stato trovato o meno

    do
    {
        scelta = menu();
        switch (scelta)
        {
        case 0:         // uscire
            uscita = 1; // metto bool a 1 ed col ciclo while esco dal menu
            break;
        case 1: // inserire elementi nell' albero
            do
            {
                numero = getElement();
                T = ordins(numero, T);
                printf("Voi continuare ad inserire numeri nell'albero?\n");
                printf("Inserisci 0 per smettere: \n");
                printf("Inserisci 1 per continuare ad inserire:\n");
                scanf("%d", &risposta);

            } while (risposta == 1);

            break;
        case 2: // stampa PREORDER

            printf("Stampa PREORDER:\n");
            preorder(T);

            break;
        case 3: // stampa POSTORDER
            printf("Stampa POSTORDER:\n");
            postorder(T);

            break;
        case 4: // stampa INORDER
            printf("Stampa INORDER:\n");
            inorder(T);

            break;

        case 5: // ricerca di un elemento

            printf("Inserisci un elemento da cercare:");
            scanf("%d", &ricercato);

            trovato = ricerca(ricercato, T);
            if (trovato)
            {
                printf("Elemento: %d è stato trovato\n", ricercato);
            }
            else
            {
                printf("Elemento NON presente nell'albero\n");
            }
            break;
        case 6: // altezza di un albero

            printf("L'altezza dell' albero è:%d\n", height(T));

            break;

        case 7: // somma elementi

            printf("La somma degli elementi dell'albero è: %d\n", somma_elementi(T));

            break;
        case 8: // numero dei nodi

            printf("Il numero totale di nodi dell'albero è: %d\n", nnodi(T));

            break;
        case 9: // calcolo bilanciamento

            if (bilanciamento(T))
            {
                printf("Albero bilanciato\n");
            }
            else
            {
                printf("Albero NON bilanciato\n");
            }

            break;

        default:
            printf("Scelta sbagliata\n");
            break;
        }

    } while (!uscita);
}