#include <stdio.h>
/*
Codificare in C la funzione int disuguaglianza triangolare(int a, int b, int c) che restituisce:

1 se vale la disuguaglianza triangolare a <= b + c
0 altrimenti.

Si progetti un programma che legge da tastiera tre lati di un triangolo, poi applichi la funzione disuguaglianza triangolare 
per verificare se è possibile costruire un triangolo di quelle dimensioni.

N.B.: un triangolo sarà costruibile solamente se ogni suo lato è minore (o uguale) della somma degli altri due.
*/

int disuguaglianza(int a,int b, int c){

    if(a<=(b+c)){
        return 1;

    }else{

        return 0;
    }

}

int main(){

    int l1,l2,l3=0;

    printf("Inserisci il primo lato:");
    scanf("%d",&l1);
    printf("Inserisci il secondo lato:");
    scanf("%d",&l2);
    printf("Inserisci il terzo lato:");
    scanf("%d",&l3);

    disuguaglianza(l1,l2,l3);

    

}