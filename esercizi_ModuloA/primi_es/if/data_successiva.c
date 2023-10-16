#include <stdio.h>

//trova la data succcessiva
int main(){

    int anno, mese, giorno;

    printf("Inserisci l'anno della data:");
    scanf("%d",&anno);

    printf("Inserisci il mese della data:");
    scanf("%d",&mese);

    printf("Inserisci il giorno della data:");
    scanf("%d",&giorno);
    


    if(mese==2){        //se il mese è Febbraio:
        if(giorno==29){   //se il giorno è il 29 
            giorno=1;       //il giorno dopo sarà il primo del mese successivo
            mese++;     //aumento il mese
            printf("Il giorno successivo è: %d/%d/%d\n",giorno,mese,anno);
                   
        }else if(giorno==28 && ((anno%4==0 && anno%100!=0)|| (anno%400==0))){ //se è 28 e l anno è bisestile, allora il giorno dopo sarà il 29/02
            giorno++; //29
            printf("Il giorno successivo è: %d/%d/%d\n",giorno,mese,anno);

        }else if(giorno==28 && ((anno%4!=0 && anno%100==0)|| (anno%400!=0))){ // è il 28 ed è un anno normale
            giorno=1; 
            mese++;
            printf("Il giorno successivo è: %d/%d/%d\n",giorno,mese,anno);

        }else{ //altri giorni interni a febbrario
            giorno++;
            printf("Il giorno successivo è: %d/%d/%d\n",giorno,mese,anno);
        }

    }else if((mese==4)||(mese==6)||(mese==9)||(mese==11)){ //mese con 30 giorni
        
        if(giorno==30){ //se è il 30 cambio mese e diventa il primo del mese successivo
            giorno=1;
            mese++;
            printf("Il giorno successivo è: %d/%d/%d\n",giorno,mese,anno);
        }else{ //altri giorni interni
            giorno++;
            printf("Il giorno successivo è: %d/%d/%d\n",giorno,mese,anno);
        }

    }else{
        if(mese==12 && giorno==31){     //ultimo dell anno
            giorno=1;
            mese=1;
            anno++;
            printf("Il giorno successivo è: %d/%d/%d\n",giorno,mese,anno);

        }else if( giorno==31){ //mese con 31 giorni ed il giorno è il 31
            mese++;
            giorno=1;
            printf("Il giorno successivo è: %d/%d/%d\n",giorno,mese,anno);

        }else{ //mese con 31 giorni e giorno <31
            giorno++;
            printf("Il giorno successivo è: %d/%d/%d\n",giorno,mese,anno);
        }
        
        
        
            
    }


  
    
}