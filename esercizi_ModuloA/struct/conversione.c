#include <stdio.h>

typedef struct{
    int miglia;
    int yarde;
    int piedi;
    int pollici;

}misuraUK;

typedef struct{
    int km;
    int metri;
    int mm;

}misuraUe;

int main(){
    misuraUK misING;
    misuraUe Europa;
    int yarde;
    int piedi;
    int pollici;


    printf("Inserisci miglia:");
    scanf("%d",&misING.miglia);

    printf("Inserisci yarde:");
    scanf("%d",&misING.yarde);

    printf("Inserisci piedi:");
    scanf("%d",&misING.piedi);

    printf("Inserisci pollici:");
    scanf("%d",&misING.pollici);

    yarde=misING.yarde+misING.miglia*1760;
    piedi=misING.piedi+yarde*3;
    pollici=misING.pollici+piedi*12;
    Europa.mm=pollici*25.4;

    

    

    
}