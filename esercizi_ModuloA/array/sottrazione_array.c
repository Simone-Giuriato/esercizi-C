/*1. Si scriva una funzione che legge da input una sequenza di n interi terminata dal numero -1 e la memorizza in un array. Il valore -1 non va inserito nell'array. Il valore n è al massimo 100.
2. Nel main, si invochi due volte la funzione al punto 1 per leggere due array.
3. Si scriva una procedura che prende come parametri due array (ed eventuali altri parametri) ed elimina dal primo array i numeri presenti nel secondo. Ad esempio, se come parametri si hanno gli array [2,5,7,3,4,7] e [7,9,5], la procedura dovrà modificare il primo array come segue: [2,3,4].
4. Nel main, si invochi la procedura al punto 3 passando i due array letti al punto 2 ed infine si stampi l'array risultante tramite una procedura.*/

#include <stdio.h>

int lettura(int array[])
{
   
    int valore;
    int n=0;

    printf("Inserisci una sequenza di interi terminata da -1:\n");

    do {
        scanf("%d", &valore);

        if (valore != -1) {
            array[n] = valore;
            n++;        //aumento dimensione
        }

        //se il numero è -1 ecco che non faccio nulla(non lo metto nell'array), ma lo faccio uscire dal do while

    } while (valore != -1 && n < 100);
    return n;
}

void sottrazione(int a[], int b[], int *dim1, int dim2)
{
    int tempArray[*dim1];
    int tempSize = 0;
    for (int i = 0; i < *dim1; i++)
    {
        int presente = 0;
        for (int j = 0; j < dim2; j++)
        {
            if (a[i] == b[j])
            {
                presente = 1;
                j = dim2;   //se è cosi lo faccio uscire dal ciclo
            }
        }
        if (presente==0) //se non c'è corrispondenza
        {
            tempArray[tempSize++] = a[i];   //metto in un array temporaneo il valore, e poi aumento l indice dell 'array temp
        }
    }
    for (int i = 0; i < tempSize; i++)
    {
        a[i] = tempArray[i];    //riempito l'array temporaneo,come richiesto da consegna, butto tutto dentro l'array di partenza
    }

    *dim1 = tempSize;   //la nuova dimensione dell'array1 sarà la dimensione dell'array temp
}

int main()
{
    int a[100], b[100];
    int lung1, lung2;

    lung1 = lettura(a);
    printf("Ora passiamo al secondo array:\n");
    lung2 = lettura(b);
    sottrazione(a, b, &lung1, lung2);

    printf("Il primo array senza gli elementi che sono nel secondo array risulta:\n");

    for (int i = 0; i < lung1; i++)
    {
        printf("%d\n", a[i]);
    }
}