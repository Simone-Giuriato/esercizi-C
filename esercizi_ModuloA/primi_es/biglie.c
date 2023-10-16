#include <stdio.h>
/*
In un barattolo ci sono N biglie, ciascuna delle quali può essere di colore rosso o azzurro.
Sappiamo che le biglie rosse sono sempre il doppio di quelle azzurre.
Leggere
da tastiera il numero intero N di biglie contenute nel barattolo, dove N
è un multiplo di 3 (non vanno eseguiti controlli sul numero inserito).
Stampare a video il numero di biglie rosse e di biglie azzurre calcolate in funzione di N.
*/
int main(){

    int nBiglie;
    int rosse; //doppio azzurre
    int azzurre;
    printf("Quante biglie ci sono nel barattolo (sono obbligatoriamente un multiplo di 3)?"); 
    scanf("%d",&nBiglie);

    rosse= nBiglie/3 *2; //sappiamo che le rosse sono il doppio di azzurre
    azzurre= nBiglie/3*1;

    printf("Ci sono %d biglie rosse\n", rosse);
    printf("Ci sono %d biglie azzure\n", azzurre);







}