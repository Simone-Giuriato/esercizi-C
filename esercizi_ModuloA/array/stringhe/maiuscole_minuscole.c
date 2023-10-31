#include <stdio.h>
#include <string.h>

/*
Scrivere un programma C che chieda all’utente di inserire due stringhe e verifichi se queste coincidono.

Nel caso coincidano, si trasformino SOLAMENTE nella seconda stringa i caratteri maiuscoli in minuscoli e viceversa e si verifichi nuovamente il valore di uguaglianza, stampandone il risultato.

Consiglio: sfruttare i codici ASCII dei caratteri (i maiuscoli da 65 a 90, i minuscoli da 97 a 122) per le conversioni da maiuscoli a minuscoli. Usare una somma o una sottrazione con 32 per le conversioni. 
Per effettuare il confronto tra due stringhe utilizzare la funzione strcmp contenuta nella libreria 'string'.
*/

#define DIM 100

int main()
{

    char str[DIM], str1[DIM];
    int i = 0;

    printf("Inserisci la prima stringa:");
    scanf("%s", str);

    printf("Inserisci la seconda stringa:");
    scanf("%s", str1);

    if (strcmp(str, str1) == 0)
    {
        while (str[i] != 0)
        {

            // printf("vale: %d", str[i]);

            if (str[i] >= 65 && str[i] <= 90)
            {
                str[i] = str[i] + 32;
            }
            else if (str[i] >= 97 && str[i] <= 122)
            {
                str[i] = str[i] - 32;
            }

            i++;
        }
    }
    else
    {
        printf("Le stringhe NON coincidono.");
    }
 

    printf("La stringa con maiuscole e minuscole invertite è: %s\n", str);
}