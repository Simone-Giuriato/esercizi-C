#include <stdio.h>

int tempo_to_sec(int ore,int minuti,int sec){
    
    int somma=0;

    somma=min_to_sec(minuti)+ore_to_sec(ore)+sec;

    return somma;



    
}

int min_to_sec(int m){ //dati i minuti da i secondi
    m=m*60;
    return m;

}
int ore_to_sec(int o){ //dati le ore da i secondi

    o=o*3600;
    return o;

}

int main(){
    int ore,minuti,secondi=0;
    int risulato=0;

    printf("Inserisci le ore intere della durata del CD audio:");
    scanf("%d",&ore);

    printf("Inserisci i minuti interi della durata del CD audio:");
    scanf("%d",&minuti);

    printf("Inserisci i secondi interi della durata del CD audio:");
    scanf("%d",&secondi);

    risulato=tempo_to_sec(ore,minuti,secondi);


    printf("Il brano dura @%d@ secondi\n",risulato);


}
