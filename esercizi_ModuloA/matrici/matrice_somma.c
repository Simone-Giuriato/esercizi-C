/*Scrivere un programma in C per calcolare la somma tra due matrici.

Il programma deve inizialmente leggere da tastiera le due matrici, tramite una funzione da invocare due volte (una per ogni matrice).
La funzione di lettura deve chiedere all’utente le dimensioni di una matrice (numero di righe e colonne) e deve poi fargli inserire i valori. Si supponga che le matrici abbiano dimensione massima 20 x 20.
Se non sono verificate le condizioni per la somma il programma deve stampare un messaggio di errore.
Se invece sono verificate, il programma calcola la somma (tramite una funzione) e la stampa a video (tramite una funzione).*/


#include <stdio.h>

#define DIM 20

void lettura(int matrice[DIM][DIM], int *righe, int *colonne)
{
    int i, j;

    do
    {
        printf("Inserisci il numero di righe (max 20): ");
        scanf("%d", righe);
        printf("Inserisci il numero di colonne (max 20): ");
        scanf("%d", colonne);

        if (*righe <= 0 || *colonne <= 0 || *righe > DIM || *colonne > DIM)
        {
            printf("Errore: dimensioni non valide. Riprova.\n");
        }
    } while (*righe <= 0 || *colonne <= 0 || *righe > DIM || *colonne > DIM);

    printf("Inserisci gli elementi della matrice:\n");
    for (i = 0; i < *righe; i++)
    {
        for (j = 0; j < *colonne; j++)
        {
            printf("Inserisci Elemento (%d,%d): ", i + 1, j + 1);
            scanf("%d", &matrice[i][j]);
        }
    }
}

void somma(int m1[DIM][DIM], int m2[DIM][DIM], int ris[DIM][DIM], int righe, int colonne)
{
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            ris[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void stampa(int m[DIM][DIM], int righe, int colonne)
{
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int mat1[DIM][DIM];
    int mat2[DIM][DIM];
    int sum[DIM][DIM]; // risultato somma delle 2 matrici
    int righe1, colonne1, righe2, colonne2;

    lettura(mat1, &righe1, &colonne1);
    lettura(mat2, &righe2, &colonne2);

    if (righe1 != righe2 || colonne1 != colonne2)
    {
        printf("\nErrore: Le dimensioni delle due matrici non consentono la somma.\n");
        return 1; // Uscita con errore
    }
    somma(mat1, mat2, sum, righe1, colonne1);

    printf("Ecco la somma delle due matrici:\n");
    stampa(sum, righe1, colonne1);
}