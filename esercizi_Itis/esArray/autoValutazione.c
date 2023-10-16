#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
# define DIM 5

void ordinaCresc(int numeri[], int dim)
{
  
    for (int i = 0; i < dim -1; i++)
    {
        for (int j = 0; j < dim -1; j++)
        {
            if (numeri[j] > numeri[j+1])
            {
                int tmp = numeri[j];
                numeri[j] = numeri[j+1];
                numeri[j+1] = tmp;
            }
        }
    }
    
}
void ordinaDec(int numeri[], int dim)
{
    int tmp;
   
    for ( int i = 0; i < dim-1 ; i++)
    {
        for (int j = 0; j < dim-1; j++)
        {
            if (numeri[j] < numeri[j+1])
            {
                tmp = numeri[j];
                numeri[j] = numeri[j+1];
                numeri[j+1] = tmp;
            }
        }
    }
    
    
}

int main(){
int array[DIM];



for(int i=0; i<DIM;i++){
    printf("Inserisci un numero nell'array:");
    scanf("%d", &array[i]);
}
    int i=0;
    int numeroEsame[DIM]; 
    int contatore=0;
    int piuFrequente=0;
    int numero;
    int pari[DIM];
    int dispari[DIM];
    int cntpari=0;
    int cntdispari=0;
    
    for( i=0;i<DIM;i++ ){
        for(int j=0; j<DIM; j++){
            if(array[i]==array[j]){
                contatore++;

            }
        }
        if(contatore>piuFrequente){
            piuFrequente=contatore;
            numero= array[i];            
        }
         contatore=0;
    }
    printf("Il numero %d è presente %d volte\n", numero, piuFrequente);


     
      
       for (i = 0; i < DIM; i++)
    {
               
            if ((array[i]%2) == 0)
            {
                pari[cntpari++]=array[i];

                
                
            }
             if ((array[i] % 2) != 0)
            {
                dispari[cntdispari++]=array[i];
                
            }      
    }
    printf("Numeri pari in ordine crescente:\n");
    ordinaCresc(pari, cntpari);
     for (i = 0; i < cntpari; i++)
    {
         
        printf("%d\n", pari[i]);
               
            
    }
    ordinaDec(dispari, cntdispari);
    printf("Numeri dispari in ordine decrescente:\n");
     for (i = 0; i < cntdispari; i++)
    {
       
        printf("%d\n", dispari[i]);
               
            
    }


    return 0;

}