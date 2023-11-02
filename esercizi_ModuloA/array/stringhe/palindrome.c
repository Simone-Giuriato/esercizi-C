/*
Scrivere un programma che riceve in ingresso una parola inserita da tastiera. Si consideri che la parola può contenere solo caratteri minuscoli, e complessivamente al massimo 30 caratteri.
Il programma deve svolgere le seguenti operazioni:
- Visualizzare la parola inserita;
- Verificare se la parola è palindroma;
- Visualizzare il risultato.

N.B.: Una parola si dice "palindroma" se può essere letta indifferentemente da sinistra verso destra e da destra verso sinistra. Ad esempio, le seguenti parole sono palindrome: otto, ingegni, anna, osso.
*/

#include <stdio.h>
#include <string.h>

#define DIM 31

int main()
{
    char str[DIM];
    int lunghezza = 0;
    int c = 0;

    do
    {
        printf("Inserisci una parola (massimo 30 caratteri):");
        scanf("%s", str);
        lunghezza = strlen(str);

    } while (lunghezza > 30);

    printf("La parola inserita è: %s\n", str);

    for (int i = 0; i < lunghezza; i++)
    {

        if (str[i] == str[lunghezza - 1 - i])   //-1 è dovuto al carattere terminatore \0
        {
            c++;
        }
    }

    if (c == (lunghezza))
    {
        printf("La parola è palindroma\n");
    }
    else
    {
        printf("La parola NON è palindroma\n");
    }
}