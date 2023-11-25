/*
1. Si scriva una procedura che, prendendo come parametri:
- un array di numeri (interi)
- una soglia (intero)
- eventuali altri parametri
ponga a 0 i valori inferiori alla soglia.

2. Si scriva un programma che:
- legge da input, tramite una procedura o funzione, una sequenza di n interi terminata dal numero -1 e la memorizza in un array. Il valore -1 non va inserito nell’array. Il valore n è al massimo 100;
- legge da tastiera il valore della soglia;
- invoca la procedura al punto 1 passando l'array letto in input;
- stampa a video, tramite una procedura, l'array modificato.
*/

#include <stdio.h>

int lettura(int a[])
{
    int dim=0;
    int tmp;
    
 do
    {
        printf("Inserisci un numero: ");
        
        scanf("%d", &tmp);

        if (tmp != -1 && dim < 100) // controlla che dim sia inferiore a 100 prima di accedere a a[dim]
        {
            a[dim] = tmp;
            dim++; // aumenta dimensione
        }

    } while (tmp != -1 && dim < 100);

    return dim;
}
void zero(int a[], int s, int dim)
{ // porre a 0 i valori inferiori alla soglia

    for (int i = 0; i < dim; i++)
    {
        if (a[i] < s)
        { // se il valore è minore della soglia pongo a zero
            a[i] = 0;
        }
    }
}

void stampa(int array[],int dim){
    for(int i=0;i<dim;i++){
        printf("%d\n", array[i]);

    }

}

int main()
{
    int numeri[100];
    int dimensione = 0;
    int soglia;

    dimensione = lettura(numeri);

    printf("Inserisci una soglia:");
    scanf("%d", &soglia);

    zero(numeri, soglia, dimensione);
    printf("Stampo l'array modificato:\n");
    stampa(numeri,dimensione);
}