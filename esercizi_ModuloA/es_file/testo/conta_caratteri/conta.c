/*
Scrivere un programma C che chiede da terminale di inserire il nome di un file di testo da aprire in lettura e di quello di output su cui scrivere (es. Inserisci nome file input: , Inserisci nome file output:), eseguire quindi la lettura delle parole contenute nel file (stringhe) e scrivere il numero di caratteri di ciascuna parola in un file di output.
Potete usare il file di input dell'esercizio precedente o crearne uno voi salvandolo con nomefile.txt.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char filenameRead[50];
    char filenameWrite[50];
    FILE *fr;
    FILE *fw;
    char str[50];
    int i = 0;

    printf("Inserisci un nome di file input: ");
    scanf("%s", filenameRead);
    fr = fopen(filenameRead, "rt");

    if (fr == NULL)
    {
        printf("Errore nell'apertura del file di input");
        exit(-1);
    }

    printf("Inserisci un nome di file output: ");
    scanf("%s", filenameWrite);
    fw = fopen(filenameWrite, "wt");

    if (fw == NULL)
    {
        printf("Errore del file di output");
        exit(-2);       //se sono in questo caso dove è presente l'errore termino il programma
    }

    while (fscanf(fr, "%s", str) != EOF)
    { // termine del file, non c'è più nulla da leggere EOF
        i = 0;
        while (str[i] != '\0')  //fino alla fine della stringa
        {
            i++;    //conto ogni carattere
        }
        fprintf(fw, "La parola '%s' ha: %d caratteri.\n", str, i);
    }

    fclose(fr);
    fclose(fw);
}