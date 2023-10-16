#include <stdio.h>
#include <time.h> 
 
#define N 1000000
 
int main() {
  int numeri[N];
  int i, j;
  FILE *file;
  srand(time(0)); //inizializza il generatore sull'ora attuale dell'elaboratore time(0) fa ottenere valori diversi
  

  if ((file = fopen("numeri.txt", "w+")) == NULL)
    {
        printf("Errore apertura file\n");
        return -1;
    }

  for(i=0;i<N;i++) {        //popolare l'array
    numeri[i]=rand()%N+1;
    for(j=0;j<i;j++) {      //controllo che i numeri non siano già stati insieriti nella array
       	if(numeri[i]==numeri[j]) {
           i--;
           break;
        }
        if (j == i - 1)
            {
                numeri[i] ==numeri[j];
                fprintf(file, "%d\n", numeri[i]);
            }
     }
}
  
   fclose(file);
    printf("I numeri sono stati stampati nel file.txt\n");
   
  return 0;
}