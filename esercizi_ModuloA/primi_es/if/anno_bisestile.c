#include <stdio.h>

int main(){
    int anno;
    int resto;

    printf("Inserisci l'anno:");
    scanf("%d",&anno);

    resto=anno%4;

    if((anno%4==0 && anno%100!=0)||(anno%400==0)){
        printf("L'anno %d è bisestile\n",anno);
    }else{
        printf("L'anno %d è NON bisestile\n",anno);
    }
}