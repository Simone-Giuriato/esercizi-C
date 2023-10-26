#include <stdio.h>
//trova il valore assoluto

main(){
    int a;

    printf("Inserisci un numero: ");
    scanf("%d",&a);

    if(a>=0)
    {printf("il valore assoluto è: %d\n",a);
    
    }else{
        a=-a;
        printf("Il valore assoluto è:\n%d\n", a);

    }
    

}