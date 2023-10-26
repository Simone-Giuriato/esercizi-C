#include <stdio.h>
/*
Scrivere un programma in linguaggio C che stampi a video i numeri perfetti tra 1 e 10000.
Un numero si dice perfetto se è uguale alla somma dei suoi divisori.

Esempio: 28 = 1 + 2 + 4 + 7 + 14 è un numero perfetto*/

int main()
{
    int i = 1;
    int somma = 0;
    int c = 0;
    int divisiore = 1;

    while (i >= 0 && i < 10000)
    {

        while (c != (i - 1))
        {
            c++;
            if (i % c == 0)
            {

                somma = somma + c;
            }
        }
        if (somma == i)
        {

            printf("%d e' un numero perfetto\n", i);
        }

        i++;
        c = 0;
        somma = 0;
    }

    // pezzo di codice per trovare i divisori di un numero
    /*int i=1;
    int c=1;
    int a=0;
    printf("Inserisci un numero:");
    scanf("%d",&a);

    while(i!=a){

            if(a%i==0){
            printf("%d\n", i);


        }
        i++;


    }*/
}