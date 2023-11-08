#include <stdio.h>
#include <string.h>
/*
Un negozio di alimentari ha un archivio (realizzato tramite un array di strutture, vedi file allegato) in cui vengono memorizzati i prodotti presenti in magazzino. Per ogni prodotto in magazzino, si dispone dei seguenti dati:
- La descrizione (stringa max 20 caratteri compreso il terminatore).
- La quantità disponibile in magazzino (intero).
- L’anno di scadenza (intero).
Si definisca il tipo di dato "prodotto" con i 3 campi definiti sopra.
Si utilizzi poi la dichiarazione nel file allegato per creare l'array di strutture ed inizializzarlo.
Nello stesso file è riportata la definizione della costante Nprodotti che rappresenta il numero di prodotti presenti nell'array.

Il programma deve memorizzare in un secondo array di strutture tutti i prodotti che sono da cancellare dall’archivio perché scaduti.
Al termine si stampi a video il vettore dei prodotti scaduti.
*/

typedef struct
{
    char descrizione[20];
    int quantità;
    int scadenza; // anno di scadenza

} prodotto;

int main()
{
    int Nprodotti = 11; // costante
    int k; //contatore per gli scaduti

    prodotto magazzino[] = {    
        {"Biscotti", 25, 2022},
        {"Marmellata", 5, 2017},
        {"Nutella", 30, 2028},
        {"Burro", 4, 2015},
        {"Grissini", 9, 2024},
        {"Miele", 14, 2014},
        {"Latte", 46, 1998},
        {"Yogurt", 2, 1991},
        {"Mozzarella", 7, 2014},
        {"Pasta", 56, 2006},
        {"Sottilette", 48, 2021}
    };

    prodotto scaduti[11];

    for(int i=0; i<Nprodotti;i++){
        if(magazzino[i].scadenza<2023){ //oggi siamo nel 2023 

            scaduti[k]=magazzino[i];    //inserisco prodotti scaduti nell'apposito array, cambio contatore per non creare vuoti
            k++;                        //così mi inserisce ovviamente l'intera riga (composta da desc,quantità e scadenza)

        }

    }

    for(int j=0; j<k;j++){
        printf("%s, %d, %d\n",scaduti[j].descrizione, scaduti[j].quantità,scaduti[j].scadenza); 
    }
}