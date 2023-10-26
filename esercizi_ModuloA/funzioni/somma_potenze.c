#include <stdio.h>

/*
Si scriva una funzione int somma_potenze(int a, int n); che dati a e n deve calcolare la sommatoria per i che varia da 1 a n di a^i.
A tal fine si scriva e si usi una funzione int potenza(int x, int y); che dati x e y deve calcolare x^y usando come operazione primitiva il prodotto.

Si realizzi quindi un programma che prende in ingresso a ed n e stampi a video il risultato della sommatoria.

Esempio
Se a = 2 e i = 5 il programma dovrà calcolare:
2^1 + 2^2 + 2^3 + 2^4 + 2^5 = 2 + 4 + 8 + 16 + 32 = 62
*/

int potenza(int x, int y) {
    int i = 1;  // Inizia da 1 perché x^0 è sempre 1
    int risultato = 1;

    while (i <= y) {
        risultato =risultato* x;
        printf("%d", risultato);
        i++;
        
    }

    

    return risultato;
}

int somma_potenze(int a, int n) {
    int i = 0;
    int addendo = 0;
    int sommatoria = 0;

    while (i <= n) {
        addendo = potenza(a, i);
        sommatoria=sommatoria+ addendo;
        i++;
    }

    return sommatoria-1;
}

int main() {
    int val, base, risultato = 0;

    printf("Inserisci un valore di esponente: ");
    scanf("%d", &val);

    printf("Inserisci la base della potenza: ");
    scanf("%d", &base);

    risultato = somma_potenze(base, val);

    printf("La sommatoria di tutte le potenze entro l'esponente (compreso) dato è: %d\n", risultato);

}