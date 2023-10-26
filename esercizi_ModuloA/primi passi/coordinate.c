#include <stdio.h>
//dice se i due punti coincidono

int main(){
    int x,y,a,b;

    printf("Iserisci la ascissa del primo punto:");
    scanf("%d",&x);
    printf("Iserisci la ordinata del primo punto:");
    scanf("%d",&y);


    printf("Iserisci l'ascissa del secondo punto:");
    scanf("%d",&a);
    printf("Iserisci l'ordinata del secondo punto:");
    scanf("%d",&b);

    if((x==a)&&(y==b))
    printf("I due punti coincidono\n");
    else
    printf("I due punti non coincidono\n");
}