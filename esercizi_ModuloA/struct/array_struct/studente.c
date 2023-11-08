/*
Si scriva un programma C che definisca un tipo di dato Studente:
Ogni studente è caratterizzato da:
- matricola (intero);
- nome (stringa contenente al più 20 caratteri compreso il terminatore);
- cognome (stringa contenente al più 20 caratteri compreso il terminatore).

Il programma acquisisca da tastiera i dati di al massimo 100 studenti salvandone le informazioni in un vettore di strutture.
L’inserimento termina quando si inserisce una matricola uguale a 0.

Stampi i nomi e i cognomi di tutti gli studenti inseriti.
Chieda all'utente il nome e cognome di uno studente, lo cerchi nel vettore e ne stampi la matricola.
Nota: Inserire le stringhe senza spazi.
*/

#include <stdio.h>
#include <string.h>


#define DIM 20
//numero massimo di studenti inseriti è 100, ma verrà chiesto all'utente quanti inserirne

typedef struct
{
    int matricola;
    char nome[DIM];
    char cognome[DIM];

} studente;

int main()
{

    studente a[100];
    int matricola = 0;
    char nome[DIM];
    char cognome[DIM];
    int i = 0; // numero studenti inseriti
    int trovato=0; //variabile bool che se trovo l'utenete esco subito dal ciclo
    int n;

    printf("Quanti studenti vuoi inserire?");
    scanf("%d", &n);

    while (i < n)
    {
        printf("Inserisci la matricola:");
        scanf("%d", &a[i].matricola);
        printf("Inserisci nome e cognome:");
        scanf("%s %s", a[i].nome, a[i].cognome);
        i++;
    }

    for (int j = 0; j < i; j++)
    {
        printf("Nome: %s Cognome: %s \n", a[j].nome, a[j].cognome);
    }

    printf("Inserisci Nome e Cognome da cercare:");
    scanf("%s %s", nome, cognome);
    i = 0;

    while (i < n)
    {
        if (strcmp(a[i].nome, nome) == 0 && strcmp(a[i].nome, nome) == 0)
        {
            printf("Matricola dello studente cercato: %d\n", a[i].matricola);
            trovato=1;
        }
        if(trovato==1){
            i=n;
        }

        i++;
    }
}
