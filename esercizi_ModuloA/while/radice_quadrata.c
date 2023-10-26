#include <stdio.h>
/*
Scrivere un programma C che calcoli la radice quadrata (intera) di un naturale N, 
𝐬𝐞𝐧𝐳𝐚 usare le funzioni del linguaggio C per calcolare la radice quadrata. 
*/

int main(){
    int numero;
    printf("Inserisci un numero:");
    scanf("%d",&numero);
    int i=0;
    int risultato=0;

    while(risultato<=numero){
        i++;
        risultato=i*i;
        
        
    }

   i=i-1;
    

    printf("La radice quadrata di %d è %d:",numero,i);

}