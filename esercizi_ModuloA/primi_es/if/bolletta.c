#include <stdio.h>
/*Si scriva un programma che calcoli la bolletta elettrica dei clienti di una società di fornitura.

Il programma prende in ingresso il numero di kilowattora (kWh) consumati dall'utente nell'ultimo mese e restituisce la cifra dovuta in euro.

Per educare le famiglie a un consumo consapevole dell'energia elettrica la società ha deciso che il costo per kWh cambia in base al consumo mensile come segue:
- i primi 200 kWh costano 1 euro/kWh
- i kWh dal 201-esimo fino al 400-esimo costano 2 euro/kWh
- i kWh dal 401-esimo al 600-esimo costano 3 euro/kWh
- i kWh oltre il 600-esimo costano 4 euro/kWh
(si noti che si tratta di una funzione continua).*/

int main()
{
    int kwh;
    int costo;

    printf("Inserisci i kwh cosumati nell'ultimo mese:");
    scanf("%d", &kwh);

    int residuo; //kwh residui dalle operazioni negli scaglioni
    int totale; //totale costi
    if(kwh<200){
        totale=kwh*1;

    
    }

    if(kwh>=200){
        totale=200*1;
        residuo=kwh-200;

        if(kwh>=400){

            if(kwh>=600){
                totale=totale+(200*2);
                residuo=residuo-200;
                totale=totale+200*3;
                residuo=residuo-200;
                totale=totale+residuo*4;
            }else{
                totale=totale+(residuo*3);


            }
        }else{
            totale=totale+(residuo*2);
        }
    }


   printf("La bolletta è di %d euro", totale); 

    

    
}
