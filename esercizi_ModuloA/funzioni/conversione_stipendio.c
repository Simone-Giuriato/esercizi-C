#include <stdio.h>

/*
Si progetti un programma che converta lo stipendio di un dipendente di un'azienda in sterline o in yen.
Si creino le seguenti funzioni:
- Funzione di conversione euro/sterlina: float EuroSterlina che effettua la conversione (1 euro = 0,91 sterlina)
- Funzione di conversione euro/yen: float EuroYen che effettua la conversione (1 euro = 124,09)

Si scriva poi un main() che prenda in ingresso un intero e chieda all'utente se vuole convertirlo in sterline o in yen e chiami la funzione di conversione adeguata (EuroSterlina per la conversione in sterline, EuroYen per la conversione in yen).
Si stampi infine lo stipendio convertito.

CONSIGLI:
Per evitare i warning nelle conversioni di tipo, si puo` usare il type casting.
Chi volesse stampare solo 2 decimali di un float, può utilizzare %.2f nella stringa formato della printf.
*/

float EuroSterlina(int euro){
    float sterlina=0;
    sterlina=euro*0.91;

    return sterlina;
    
}

float EuroYen(int euro){

    float yen=0;
    yen= euro*124.09;

    return yen;
    
}

int main(){

    int stipendio=0;
    int risposta=0;

    printf("Inserisci il tuo stipendio:");
    scanf("%d",&stipendio);

    printf("Digita 1 se preferisci convertire lo stipendio in Sterline:\nDigita 2 se preferisici convertire lo stipendio in Yen\n");
    scanf("%d",&risposta);

    if(risposta==1){
       

        printf("Lo stipendio convertito in sterline ammonta a: %.2f Sterline\n",EuroSterlina(stipendio));
    }else if(risposta==2){
        
        printf("Lo stipendio convertito in Yen ammonta a: %.2f Yen\n",EuroYen(stipendio));

    }else{
        printf("Reinserire risposta (deve essere un valore o 1 o 2)");
    }

    



}