#include <stdio.h>

/*
Invertire una stringa (data dall'utente) senza l'uso della libreria string.h
*/


# define DIM 50

int main(){
    char str[DIM], str2[DIM];
    int i=0,j=0;

    printf("Inserisci una stringa:");
    scanf("%s",str);

    while(str[i]!='\0'){
        i++;
    }

    printf("La stringa ha lunghezza: @ %d @\n", i);

    while(str[j]!='\0'){
        str2[j]=str[i-j-1];  
        j++;
    }

    str2[j]='\0';

    printf("Stringa invertita: @ %s @\n",str2);


}