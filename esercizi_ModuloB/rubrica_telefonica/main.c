/*
gcc -c main.c
gcc -c function.c
gcc -o rubrica main.o function.o
*/

/*
Si deve sviluppare un programma che realizzi una rubrica telefonica. In particolare, ogni elemento della rubrica è caratterizzato dalle seguenti informazioni:
Cognome, Nome e Telefono.                  
La rubrica telefonica viene realizzata come una tavola inizializzata in memoria centrale ordinata sulla chiave costituita dalla coppia cognome-nome (array ordinato in base al cognome e, in caso di uguaglianza, al nome).

Il programma deve essere in grado di gestire varie richieste dell’utente:

    Inserimento: l’utente vuole inserire un nuovo record nella rubrica. Dati cognome, nome e numero di telefono della persona da inserire, il programma aggiunge un nuovo elemento all’archivio. Poi riordina la rubrica (qsort) in modo da mantenerla ordinata rispetto alla chiave
    Stampa: l’utente richiede la stampa dell’intera rubrica
    Uscita: l’utente richiede che il programma termini


                       
L’interazione tra l’utente e il programma avviene in modo ciclico: l’utente può sottoporre una richiesta ad ogni ciclo ed il programma, sfruttando un meccanismo di selezione (switch), 
reagisce nel modo richiesto. L’esecuzione del programma si conclude quando l’utente richiede l’uscita. Si tratta di creare un menù testuale.
Il progetto deve essere opportunamente strutturato su più file.
*/
#include "header.h"
int main()
{

    rubrica R;

    int scelta = 0;
    int inseriti = 0;
    int uscita = 0;
    do
    {
        scelta = menu();
        switch (scelta)
        {
        case 1:
            inseriti = inserire(R, inseriti);
            break;
        case 2:
            stampa(R, inseriti);
            break;
        case 3:
            uscita = 1;
            break;
        default:
            printf("Scelta sbagliata\n\n");
            break;
        }

    } while (uscita != 1); //! uscita   (utente ha deciso di uscire, la variabile uscita impostata ad 1)
}