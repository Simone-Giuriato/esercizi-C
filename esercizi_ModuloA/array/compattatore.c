/*
Si scriva un programma in C che legge N numeri interi da tastiera e li memorizza in un vettore di ingresso.
Il numero N viene inserito dall'utente ed è strettamente minore di 20.

Il programma deve generare un vettore di uscita che "compatta" i numeri contenuti nel vettore di ingresso.
In particolare:
- Ogni numero che compare ripetuto nel vettore di ingresso deve comparire una sola volta nel vettore di uscita.
- Ogni numero uguale a zero presente nel vettore di ingresso non deve comparire nel vettore di uscita.

Al termine, il programma deve stampare a video il contenuto del vettore di uscita.
*/

#include <stdio.h>

int main() {
    int array[20], array2[20];
    int n = 0, j = 0;

    do {
        printf("Inserisci da quanto è composto l'array (tra 1 e 19): ");
        scanf("%d", &n);
    } while (n < 1 || n > 19);

    for (int i = 0; i < n; i++) {
        printf("Inserisci il valore %d dell'array: ", i + 1);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++) {
        if (array[i] != 0) {    //toglo gli zeri
            int duplicato = 0;
            int k = 0;
            while (k < j) { //cerco duplicati
                if (array[i] == array2[k]) { // se c'è duplicato imposto la variabile uguale ad 1
                    duplicato = 1;
                }
                k++;
            }
            if (duplicato==0) {       //se duplicato è 0 (0 vuol dire che non è duplicato)
                array2[j] = array[i];
                j++;
            }
        }
    }

    printf("Array 2:\n");
    for (int k = 0; k < j; k++) {
        printf("%d ", array2[k]);
    }

    return 0;
}


/*
 a=0;

       do{
          if(array2[i]!=array2[a]){
                array3[a]=array2[i];
                a++;
            }

       }while(a<j);*/