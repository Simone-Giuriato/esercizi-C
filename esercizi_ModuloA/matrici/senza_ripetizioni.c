/*
Si scriva un programma in linguaggio C che permette all'utente di inserire delle parole (stringhe) in un opportuno vettore di stringhe (matrice di char) senza ripetizioni.

Il main dopo aver chiesto all'utente di inserire una parola da tastiera la inserisce in coda al vettore tramite una funzione "inserimento".
La funzione "inserimento" prende come parametri il vettore di stringhe, la parola da inserire ed eventuali altri parametri:
- restituisce 0 se la stringa è già presente nel vettore;
- altrimenti procede ad inserire la nuova parola e restituisce 1.

Il programma deve continuare a richiedere l'inserimento di nuove parole finché l'utente non inserisce la parola "fine" (che non va inserita nel vettore).
Al termine dell'inserimento il programma deve stampare a video l'intero vettore di stringhe tramite una procedura.Si scriva un programma in linguaggio C che permette all'utente di inserire delle parole (stringhe) in un opportuno vettore di stringhe (matrice di char) senza ripetizioni.

Il main dopo aver chiesto all'utente di inserire una parola da tastiera la inserisce in coda al vettore tramite una funzione "inserimento".
La funzione "inserimento" prende come parametri il vettore di stringhe, la parola da inserire ed eventuali altri parametri:
- restituisce 0 se la stringa è già presente nel vettore;
- altrimenti procede ad inserire la nuova parola e restituisce 1.

Il programma deve continuare a richiedere l'inserimento di nuove parole finché l'utente non inserisce la parola "fine" (che non va inserita nel vettore).
Al termine dell'inserimento il programma deve stampare a video l'intero vettore di stringhe tramite una procedura.
*/

#include <stdio.h>
#include <string.h>

#define DIM 100

int Presente(char m[DIM][DIM], int dimensione, char parola[DIM]) {
    for (int i = 0; i < dimensione; i++) {
        if (strcmp(m[i], parola) == 0) {    //confornto se la parola è presente (guardo solo la riga, le colonne ovvero le lettere che fanno vocali non mi interessa)
            return 1; // La parola è già presente
        }
    }
    return 0; // La parola non è presente
}

int inserimento(char matrice[DIM][DIM], int *dimensione, char parola[DIM]){
    if (Presente(matrice, *dimensione, parola)) {
        return 0; // La parola è già presente, inserimento non riuscito
    } else {
        strcpy(matrice[*dimensione], parola);
        (*dimensione)++;        //aumento la dimensione matrice visto che ho aggiaunto una nuova parola
        return 1; // Inserimento riuscito
    }
}

void stampa(char matrice[DIM][DIM], int dimensione) {
    printf("Matrice di stringhe:\n");
    for (int i = 0; i < dimensione; i++) {
        printf("%s\n", matrice[i]);
    }
}


int main(){
    char parole[DIM][DIM];
    char stringa [DIM];
    int risultato,dimensione=0;
    printf("Inserisci una parola (inserisci 'fine' per terminare):\n");

    int continua = 1; // Variabile per controllare la condizione di uscita dal ciclo

    while (continua) {
        // Richiesta di inserimento
        
        scanf("%s", stringa);

        // Verifica se l'utente ha inserito "fine" per terminare l'inserimento
        if (strcmp(stringa, "fine") == 0) {
            continua = 0; // Imposta la variabile per terminare il ciclo
        } else {
            // Chiamata alla funzione di inserimento
            risultato = inserimento(parole, &dimensione, stringa);

            // Gestione del risultato della funzione inserimento della parola
            if (risultato == 0) {
                printf("La parola è già presente nel vettore. Inserimento non riuscito.\n");
            } else {
                printf("Parola inserita con successo.\n");
            }
        }
    }

    stampa(parole,dimensione);

    

    
}

