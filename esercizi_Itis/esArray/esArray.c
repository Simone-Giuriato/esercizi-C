/*Alunno: Giuriato Simone
  Classe: 5°F
  Data:   28/9/2022*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DIM 4       //numero elementi dell'array

void StampaElementi(int array[])        //stampa elementi dell'array
{
    for (int i = 0; i < DIM; i++)
    {
        printf("%d ", array[i]);
    }
    
}

void ElementiInversi(int array[])       //stampa l'array all'inverso di quando sono stati inseriti i numeri
{
    for (int i = DIM - 1; i >= 0; i--)
    {
        printf("%d ", array[i]);
    }
   
}

void ElementiPari(int array[])      //stampa gli elementi pari dell'array
{
    for (int i = 0; i < DIM; i++)
    {
        if ((array[i] % 2) == 0)
        {
            printf("%d ", array[i]);
        }
    }
   
}

void ElementiDispari(int array[])       //stampa gli elementi dispari dell'array
{
    for (int i = 0; i < DIM; i++)
    {
        if ((array[i] % 2) != 0)
        {
            printf("%d ", array[i]);
        }
    }
    
}

int RicercaNumero(int array[], int numeroCercare)       //cerca un numero dato dall'utente
{
    int contatore;

    for (int i = 0; i < DIM; i++)
    {
        if (array[i] == numeroCercare)
        {
            contatore++;
        }
    }

    return contatore;
}

int EliminaNumero(int array[], int numeroDaEliminare)       //se presente elimina un numero dell'array scelto dall'utente
{
    int trovato = 0;
    int n = DIM;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == numeroDaEliminare)
        {
            array[i] = array[i + 1];
            trovato = 1;
            n--;
        }
        if (trovato == 1)
        {
            array[i] = array[i + 1];
        }
    }

    return n;
}

void ScambiaPosizioni(int array[])      //scambia posizioni due a due
{
    int tmp = 0, i = 1;
    while (i < DIM)
    {
        tmp = array[i];
        array[i] = array[i - 1];       
        array[i - 1] = tmp;
        i = i+2;
    }
}

void RiodinaArray(int array[])      //ordina in modo crescente array (uso di variabile temporanea con tmp)
{
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void MediaSomma(int array[]){            //somma per la media
    int somma=0;
    float media=0;


    
	for(int i=0; i<DIM; i++){
        somma=somma+array[i];
    
    }
    media = somma/DIM;
    printf("la somma degli elementi è: %d\n", somma);
    printf("La media degli elementi è: %f\n", media);

}
		


int main()
{
    

    int scelta;
    int numeri[DIM];
    int nCerca;
    int nElimina;
    int somma;
    int media;

    for (int i = 0; i < DIM; i++)           //richiesta di inserire i  numeri che compongano l'array
    {
        printf("Inserisci un numero:\n");
        scanf("%d", &numeri[i]);
    }

    printf("\n");

    do 
    {
        printf("\n---------------------------MENU' DI SCELTA----------------------------\n");
        printf("--> 1 Stampare gli elementi dell'array\n");
        printf("--> 2 per Stampare gli elementi dell'array in modo inverso\n");
        printf("--> 3 per Stmapare gli elementi pari\n");
        printf("--> 4 per Stampare gli elementi dispari\n");
        printf("--> 5 per Ricercare un elemento, a tua scelta, nell'array\n");
        printf("--> 6 per Eliminare un elemento dell'array\n");
        printf("--> 7 per Alternare a due a due le posizioni dell'array\n");
        printf("--> 8 per Ordinare l'array\n");
        printf("--> 9 per ottenere la somma e la media degli elementi dell'array.");
        scanf("%d", &scelta);
        printf("\n");
    } while (scelta < 1 || scelta > 9);     //valori accettati sono dall' uno al nove che sonon le possibili scelte del menù

    switch (scelta)
    {
        case 1:
            printf("Ecco gli elementi dell'array:\n");
            StampaElementi(numeri);
            break;
        case 2:
            printf("Ecco gli elementi dell'array inversi:\n");
            ElementiInversi(numeri);
            break;
        case 3:
            printf("Gli elementi pari dell'array  sono:\n");
            ElementiPari(numeri);
            break;
        case 4:
            printf("Gli elementi dispari dell'array  sono:\n");
            ElementiDispari(numeri);
            break;
        case 5:
            printf("Inserisci un numero da cercare:\n");
            scanf("%d", &nCerca);
            printf("Il numero %d compare %d volte\n", nCerca, RicercaNumero(numeri, nCerca));
            break;
        case 6:
            printf("Inserisci un numero da eliminare:\n");
            scanf("%d", &nElimina);
            int n = EliminaNumero(numeri, nElimina);
            for (int i = 0; i < n; i++)
            {
                printf(" %d ", numeri[i]);
            }
            printf("\n");
            break;
        case 7:
            ScambiaPosizioni(numeri);
            StampaElementi(numeri);
            break;
        case 8:
            RiodinaArray(numeri);
            StampaElementi(numeri);
            break;
        case 9:
            MediaSomma(numeri);   
            break;
        default:
            break;
    }
    return 0;
}