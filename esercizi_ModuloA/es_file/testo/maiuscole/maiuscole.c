/*
Scrivere un programma che legga il contenuto di un file di input chiamato input.txt, esegua una semplice elaborazione su ciascuna parola del file,
trasformando tutte le minuscole in maiuscole e scriva i risultati su un file di output chiamato output.txt.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void maiuscole(char stringa[])  //converto da minuscolo a maiuscolo senza toupper
{
    for (int i = 0; stringa[i]; i++)
    {
        if (stringa[i] >= 97 && stringa[i] <= 122)
        {
            stringa[i] = stringa[i] - 32;
        }
    }
}
int main()
{
    FILE *f;
    f = fopen("input.txt", "r");        //apro input.txt in lettura
    char stringa[100];
    if (f == NULL)
    {
        printf("Errore nell'apertura del file input.txt");
        exit(-1);
    }
    FILE *fp;
    fp = fopen("output.txt", "wt");     //apro output.txt in scrittura

    while (fscanf(f, "%s", stringa) != EOF) //finchè legge parole --> EOF (end of the end)
    {
        maiuscole(stringa);
        fprintf(fp, "%s", stringa); // stampo l'intera stringa convertita in maiuscolo
        fprintf(fp, " ");           // aggiungo uno spazio al termine di ogni stringa
    }


    //chiudo i due file 
    fclose(fp);
    fclose(f);
}
