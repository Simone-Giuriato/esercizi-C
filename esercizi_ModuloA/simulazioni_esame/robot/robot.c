//prima parte dell'esercizo robot

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int x;
    int y;
} coordinate;

int lettura(coordinate R[])
{
    FILE *f;
    f = fopen("robots.txt", "rt");
    if (NULL == f)
    {
        printf("Errore nell'apertura del file robots.txt\n");
        exit(-1);
    }
    int i = 0;

    while (fscanf(f, "%d %d", &R[i].x, &R[i].y) != EOF)
    {
        i++;
    }

    fclose(f);
    return i;
}

void stampa(coordinate R[], int n)
{

    printf("Coordinate dei robot prese dal file robots.txt\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", R[i].x, R[i].y);
    }
}

void visualizzazione_tabellone(int x1, int y1, coordinate R[], int n)
{

    char tabellone[20][20];
    int i = 0;
    int j = 0;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            tabellone[i][j] = ' ';
            // printf("%c\t", tabellone[i][j]);
        }
        // printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        tabellone[R[i].x][R[i].y] = '*'; // metto un * nelle coordinate dei robot
    }

    tabellone[x1][y1] = '!'; // metto un ! nella coordinata del giocatore

    for (i = 0; i < 20; i++) // stampo
    {
        for (j = 0; j < 20; j++)
        {

            printf("%c\t", tabellone[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    coordinate R[50]; // robot
    int x1 = 10;      // x1 y1 coordinate del giocatore che parte da 10 10
    int y1 = 10;
    int n = 0; // quanti robot(righe nel file)

    n = lettura(R);
    stampa(R, n);
    visualizzazione_tabellone(x1, y1, R, n);
}

/*"Robots" e` un videogioco in cui il giocatore deve scappare da un gruppo di robot che lo inseguono.
In questa versione, si gioca su un tabellone 20x20.
La posizione iniziale dei robot è indicata su un file di testo robots.txt; per ciascun robot si hanno due interi, che rappresentano la posizione x e y del robot; le coordinate vanno da 0 a 19. I robot sono al massimo 50.
Il giocatore inizia dalla posizione centrale, con coordinate (10,10).
In tutte le funzioni si possono aggiungere altri parametri.

ESERCIZIO 1 (16 PUNTI):
Si scriva un programma C che legge il file robots.txt e visualizza sullo schermo il tabellone di gioco, organizzando il programma come segue:
1. nel main, si assegnino le coordinate (10,10) alla posizione del giocatore, si invochi una funzione di lettura (da sviluppare al punto 2), una di stampa (punto 3) e una di visualizzazione del tabellone (punto 4).
2. la funzione di lettura deve leggere il file robots.txt e portarne il contenuto in un opportuno array di strutture. La funzione di lettura deve essere invocata solo una volta, dal main. È vietato leggere più volte il file.
3. la funzione di stampa deve mostrare a video il contenuto dell'array letto al punto 2
4. la funzione di visualizzazione del tabellone deve prendere come parametri le coordinate a cui si trova il giocatore, l'array letto al punto 2 (più eventualmente altri parametri) e deve:
   - creare una matrice 20x20 di caratteri e inizializzare ciascuna cella con uno spazio ' '
   - per ciascun robot nell'array letto al punto 2, deve riportare un asterisco '*' nella cella corrispondente della matrice. Ad esempio, se nel file c'è un robot nella posizione (2,5), si dovrà assegnare un asterisco alla cella di coordinate [2][5] della matrice
   - assegnare alla cella dove si trova il giocatore il carattere punto esclamativo '!'
   - visualizzare sullo schermo la matrice
*/