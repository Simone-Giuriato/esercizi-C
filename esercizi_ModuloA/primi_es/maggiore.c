#include <stdio.h>

 main(){
    
    int a;
    int b;

    a=0;
    b=0;

    

    printf("Inserisci il primo numero:");
    
    scanf("%d",&a);
    printf("Inserisci il secondo numero:");
    scanf("%d",&b);

    if(a>b){
        printf("Il numero %d e' maggiore di %d\n",a,b);
    }else if(a<b){
         printf("Il numero %d e' maggiore di %d\n",b,a);
    }else{
        printf("I due numeri sono uguali\n");
    }

   
}