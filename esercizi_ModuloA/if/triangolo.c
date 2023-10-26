#include <stdio.h>
//dice se un triangolo è scaleno, isoscele o equilatero. Infine dice se è o meno rettangolo
int main(){
    int a,b,c;

    printf("Inserisci il primo lato del triangolo:");
    scanf("%d",&a);

    printf("Inserisci il secondo lato del triangolo:");
    scanf("%d",&b);

    printf("Inserisci il secondo lato del triangolo:");
    scanf("%d",&c);

    if((a==b) && (b==c)){

        printf("Il triangolo è equilatero\n");
    }else if((a==b)||(a==c)||(b==c)){

        printf("Il triangolo è isoscele\n");
    }else{
        printf("Il triangolo è scaleno\n");
    }

    if((a*a+b*b==c*c)||(c*c+b*b==a*a)||(a*a+c*c==b*b)){ //eseguo pitagora per vedere se è rettangolo
        printf("Il triangolo è rettangolo");
    }else{
        printf("Il triangolo NON è rettangolo");
    }




}