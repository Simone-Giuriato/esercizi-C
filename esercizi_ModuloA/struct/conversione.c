/*
Scrivere un programma C che definisca la struttura “misuraUK” composta da quattro interi (miglia, yarde, piedi, pollici), e una struttura “misuraUE” composta da tre interi (km, metri, mm).

Si richieda poi una misura inglese e si stampi a video la corrispondente misura europea.
Ricordate che:
- 1 miglio = 1760 yarde
- 1 yarda = 3 piedi
- 1 piede = 12 pollici
- 1 pollice = 25,4 mm
*/

#include <stdio.h>

// Definizione della struttura "misuraUK"
struct misuraUK {
    int miglia;
    int yarde;
    int piedi;
    int pollici;
};

// Definizione della struttura "misuraUE"
struct misuraUE {
    int km;
    int metri;
    int mm;
};

int main() {
    // Dichiarazione della misura inglese
    struct misuraUK misuraUK;

    // Richiesta della misura inglese all'utente
    printf("Inserisci la misura inglese:\n");
    printf("Miglia: ");
    scanf("%d", &misuraUK.miglia);
    printf("Yarde: ");
    scanf("%d", &misuraUK.yarde);
    printf("Piedi: ");
    scanf("%d", &misuraUK.piedi);
    printf("Pollici: ");
    scanf("%d", &misuraUK.pollici);

    // Converti la misura inglese in millimetri
    int millimetri = 0;

    millimetri += misuraUK.miglia * 1760 * 3 * 12 * 25.4;
    millimetri += misuraUK.yarde * 3 * 12 * 25.4;
    millimetri += misuraUK.piedi * 12 * 25.4;
    millimetri += misuraUK.pollici * 25.4;

    // Converti i millimetri nella rappresentazione europea
    struct misuraUE misuraEU;

    misuraEU.km = millimetri / 1000000;
    misuraEU.metri = (millimetri % 1000000) / 1000;
    misuraEU.mm = millimetri % 1000;

    // Stampa il risultato
    printf("Misura inglese: %d miglia, %d yarde, %d piedi, %d pollici\n", misuraUK.miglia, misuraUK.yarde, misuraUK.piedi, misuraUK.pollici);
    printf("Corrispondente misura europea: %d km, %d metri, %d mm\n", misuraEU.km, misuraEU.metri, misuraEU.mm);

    return 0;
}