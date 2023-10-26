#include <stdio.h>
//sondaggio

int main(){
    int si;
    int no;
    int boh;

    printf("Quante risposte sono 'si'?");
    scanf("%d",&si);

    printf("Quante risposte sono 'no'?");
    scanf("%d",&no);

    printf("Quante risposte sono 'non so'?");
    scanf("%d",&boh);

    int totale;
    totale= si+no+boh; //risposte totali per percentuali

    int percentualeSi;
    int percentualeNo;
    int percentualeBoh;

    percentualeSi=si*100/totale;

    percentualeBoh=boh*100/totale;

    percentualeNo= no*100/totale;

    printf(" In percentuali le risposte 'si' sono: %d%%, le risposte no sono: %d %%, le risposte 'non so' sono: %d %%",percentualeSi,percentualeNo,percentualeBoh);


}