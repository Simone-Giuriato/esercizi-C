#include <stdio.h>
/*Si calcoli il valore di π approssimato. Si utilizzi la formula di Liebniz di PiGreco.
Il numero di addendi (corrispondenti alla precisione del calcolo) dovrà essere dato in input prima dell’esecuzione del calcolo. 
Ad ogni iterazione stampare il valore corrente di π.
*/

int main()
{

    int addendi = 0;
    float pigreco = 0;
    float numeratore = 1;
    float somma=0;

    printf("Inserisci il numero di addendi:");
    scanf("%d", &addendi);
    int i = 0;

    while (i != addendi)
    {
        if(i%2==0){
            numeratore=1;
        }else{
            numeratore=-1;
        }

        

        pigreco = ((numeratore) / (2 * i + 1)) * 4;
        somma=somma+pigreco;

        printf("%d addendi: %f\n", i, somma);

        i++;
    }
}