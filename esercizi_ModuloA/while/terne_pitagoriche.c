#include <stdio.h>
/*
Realizzare un programma C che, chiesto all’utente un numero intero pari a N, ricavi e stampi a video tutte le terne pitagoriche con i cateti minori o uguali ad N.

Una terna pitagorica è formata da tre numeri naturali (a, b, c) tali che a^2 + b^2 = c^2.
Esempio 3,4,5 -> (9+16=25).

Calcolare solo le terne in cui a < b.
*/

int main() {
    int num, a, b, c;

    // Richiesta all'utente di inserire un numero intero pari
    printf("Inserisci un numero dal quale ricavare le terne pitagoriche con cateti minori o uguali: ");
    scanf("%d", &num);


    // Trova e stampa le terne pitagoriche con a < b e cateti minori o uguali al numero dato
    printf("Terne pitagoriche con a < b e cateti minori o uguali a %d:\n", num);

    a = 1;
    while (a <= num) {
        b = a;
        while (b <= num) {
            c = b;
            while (c <= num) {
                if (a * a + b * b == c * c && a < b) {  //calcolo delle terne con a<b
                    printf("(%d, %d, %d)\n", a, b, c);
                }
                c++;
            }
            b++;
        }
        a++;
    }

    
}