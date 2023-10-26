#include <stdio.h>
#include <math.h>

float ipotenusa(int a,int b){
    int ip=0;

    ip=sqrt((a*a)+(b*b));

    return ip;

}

int main(){
    int c1,c2=0;
    float val_ipotenusa=0;

    printf("Inserisic il primo cateto:");
    scanf("%d",&c1);

    printf("Inserisic il secondo cateto:");
    scanf("%d",&c2);

    val_ipotenusa=ipotenusa(c1,c2);

    printf("Il valore dell'ipotenusa è: %f",val_ipotenusa);

    




}