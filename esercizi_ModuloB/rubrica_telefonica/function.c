#include "header.h"

int menu(void)
{
    int ris;
    printf("Scegli quale operazione effettuare nella rubrica:\n");
    printf("Inserire--> 1\n"); // utente digiti 1 per inserire
    printf("Stampare--> 2\n");
    printf("Uscire--> 3\n");
    printf("Scelta:\n");
    scanf("%d", &ris);

    return ris; // ritorno la risposta ricevuta (o 1 o 2 o 3)
}

int compare(elemento *e1, elemento *e2)
{
    // riordino prima il cogonome, se cognome uguale vado col nome (come da consegna)
    int confrontoCognome = (strcmp(e1->cognome, (*e2).cognome)); // e1->cognome=*e2).cognome
    if (confrontoCognome == 0)
    {
        return strcmp((*e1).nome, (*e2).nome);
    }
    return confrontoCognome;
}
int inserire(rubrica R, int n)
{ // ogni volta ricevo una dimensione logica dell'array che viene modifciato ogni inserimento

    if (n <= DIM - 1)
    { // controllo che la rubrica non sia piena
        printf("Inserisci nome:\n");
        scanf("%s", R[n].nome);
        printf("Inserisci cognome:\n");
        scanf("%s", R[n].cognome);
        printf("Inserisci numero di telefono:\n");
        scanf("%s", R[n].tel);
        n++; // aumento di 1 la dimensione logica cosi il prossimo inserimento non si sovrappone
    }
    else
    {
        printf("Rubrica piena\n");
    }

    qsort(R, n, sizeof(elemento), compare);
    return n; // ritorno la nuova dim logica
}

void stampa(rubrica R, int n)
{
    printf("\nEcco la tua rubrica:");
    for (int i = 0; i < n; i++)
    {

        printf("\nNome: %s \n", R[i].nome);
        printf("Cognome: %s \n", R[i].cognome);
        printf("Telefono: %s \n", R[i].tel);
        printf("\n\n");
    }
}