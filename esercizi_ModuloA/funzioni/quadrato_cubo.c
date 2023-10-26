#include <stdio.h>
#include <math.h>/*
Progettare quindi e codificare un programma che legge un float da tastiera 
e visualizza il suo quadrato ed il suo cubo. 
Per calcolare il quadrato ed il cubo si devono utilizzare le due funzioni sopra definite.
*/
float square(float x){
    float a;
    a=x*x;
    return a;

}
float cube(float x){
    float b;
    b=x*x*x;
    return b;

}

int main(){
    int num=0;
    float cubo,quadrato;

    printf("Inserisci un numero:");
    scanf("%d",&num);

    quadrato=square(num);
    cubo=cube(num);

    printf("Il quadrato del numero dato è: %f\n",quadrato);
    printf("Il cubo del numero dato è: %f\n", cubo);


}