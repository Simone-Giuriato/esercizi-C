#include <stdio.h>
/*
Si scriva un programma C che:
- Legga da tastiera 10 elementi interi e li inserisca in un array;
- Stampi a video, per ogni elemento del vettore, quante volte esso compare all'interno del vettore
*/

int main(){
    int array[10];
    int frequenze[10];

    for(int i=0;i<10;i++){
        printf("Inserisci il valore %d dell'array:", i+1);
        scanf("%d",&array[i]);
    }

    for(int i=0;i<10;i++){
       for(int j=0; j<10;j++){
        if(array[i]==array[j]){
            frequenze[i]++;
        }

       
       }
        
    }

    printf("Conteggio degli elementi:\n");
    for (int i = 0; i < 10; i++) {
        
            printf("%d appare %d volte\n", array[i], frequenze[i]);
           
    }

    
}

//Non è perfetto perchè con i duplicati non li toglie ma comunque le frequenze sono giuste ci sono solo delle ripetizioni