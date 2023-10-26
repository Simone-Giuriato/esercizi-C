#include <stdio.h>
/*
Scrivere un programma C che calcoli la somma di due numeri interi tramite i cicli iterativi utilizzando solo l’operazione di incremento (operatore ++), supponendo quindi di non avere a disposizione l’operatore di somma.
Si usi il tipo di ciclo ritenuto più adeguato.*/

int main(){
    int a=0;
    int b=0;

    printf("Inserisci il primo numero:");
    scanf("%d",&a);

    printf("Inserisci il secondo numero:");
    scanf("%d",&b);

    int i=0;

    while(i!=b){

        a++;
        i++;
    }

    printf("Somma:%d", a);
}