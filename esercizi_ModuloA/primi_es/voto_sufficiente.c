#include<stdio.h>
//dati tre voti dice se almeno uno è sufficiente>=18 e fa media
int  main(){
    int a;
    int b,c;

    printf("Inserisci il primo voto:");
    scanf("%d",&a);

    printf("Inserisci il secondo voto:");
    scanf("%d",&b);

    printf("Inserisci il terzo voto:");
    scanf("%d",&c);

    if((a>=18)||(b>=18)||(c>=18)){
        printf("Almeno un voto è sufficiente\n");
    }else{
        printf("Tutti i voti sono Insufficienti\n");
    }

    int d;

    d=(a+b+c)/3;
    printf("La media dei tre voti è:\n %d",d);
}