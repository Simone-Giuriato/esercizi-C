/*
Un sistema di cronometraggio per la Formula 1 registra i tempi in millisecondi. Tuttavia tali tempi devono essere presentati in termini di minuti, secondi e millisecondi.

Creare una procedura che, ricevuto in ingresso un tempo dato in millisecondi, fornisca al chiamante l’equivalente in termini di minuti, secondi, millisecondi.
void fromMillisec(int millisec, int* mm, int* sec, int* min).

Si realizzi un programma in linguaggio C. Il programma all'interno della funzione main chiede all’utente di inserire un valore di tempo in millisecondi, invoca la funzione fromMillisec per la conversione e stampa a video il tempo nel formato
min:sec,millisec
*/

#include <stdio.h>

//con VOID non ritorno nulla, ma vado a fare un passagio di riferimento accedendo alle celle di varibaili del main
void fromMillisec(int millisec, int *mm, int *sec, int *min)    //i puntatori modificano direttamente la cella delle varibili dichiarete nel main
{

    *min = millisec / (1000 * 60);
    millisec = millisec - (*min * 1000 * 60);
    *sec = millisec / 1000;
    *mm = millisec - (*sec * 1000);
}

int main()
{
    int milli;
    int mm, sec, min;

    printf("Inserisci in quanti millisecondi è stato effetuato il giro:");
    scanf("%d", &milli);

    fromMillisec(milli, &mm, &sec, &min); // con la & estraggo l'indirizzo di variabile, notare che le var con & corrispondo con le var con * nella firma della funzione

    printf("ris:  %d:%d, %d\n", min, sec, mm);
}