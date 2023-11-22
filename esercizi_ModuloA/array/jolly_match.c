/*
Si scriva una funzione jolly_match che ha come parametri due stringhe, di cui la seconda può contenere il carattere jolly '?'.
Il valore di ritorno della funzione è 1 se le stringhe "fanno match" e 0 altrimenti.

Le stringhe "fanno match" se i caratteri nelle stesse posizioni sono uguali oppure se nella seconda c’è il carattere jolly '?'

Esempio:
jolly_match("anguria", "a?gur??") restituisce 1
jolly_match("augurai", "a?gur??") restituisce 1
jolly_match("augurai", "a?guri?") restituisce 0

Nel main si leggano da tastiera due stringhe e si stampi tra chioccioline la parola "si" se fanno match, "no" altrimenti
*/

#include <stdio.h>
#include <string.h>

#define DIM 100

int jolly_match(char str[DIM], char str2[DIM], int dim1)
{
    int c = 0;

    for (int i = 0; i < dim1; i++)
    {
        if (str[i] == str2[i] || str2[i] == '?')
        {
            c++;
        }
    }

       if (c == dim1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    char str[DIM], str2[DIM];
    printf("Inserisci una stringa:");
    scanf("%s", str);
    printf("Inserisci seconda stringa:");
    scanf("%s", str2);
    int lung1 = strlen(str);

    if (jolly_match(str, str2, lung1) == 1)
    {
        printf("@@ SI @@\n");
    }
    else
    {
        printf("@@ NO @@\n");
    }
}