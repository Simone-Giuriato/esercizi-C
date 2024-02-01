/*Nel file di testo anagrafe.txt contenuto nella domanda fuori da questo modulo sono presenti personaggi storici ed attuali (Nome Cognome eta).

Nome e Cognome sono stringhe lunghe al massimo 20 caratteri (compreso terminatore).

Si legga l’anagrafe testuale e, una persona alla volta, si salvi il contenuto nel file binario anagrafe.bin
Si legga l’anagrafe binaria (ovvero anagrafe.bin) e, una persona alla volta, si salvi il contenuto nel file di testo copia_anagrafe.txt*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    char nome[20];
    char cognome[20];
    int età;

} persona;

int letturaf(persona P[]) // leggo file di testo
{
    FILE *f;
    f = fopen("anagrafe.txt", "rt");
    if (NULL == f)
    {
        printf("Errore nell'apertura del file anagrafe.txt");
        exit(-1);
    }
    int i = 0;

    while (fscanf(f, "%s %s %d", P[i].nome, P[i].cognome, &P[i].età) != EOF)
    {
        i++;
    }

    for (int j = 0; j < i; j++)
    {
        printf("%s %s %d\n", P[j].nome, P[j].cognome, P[j].età);
    }
    fclose(f);
    return i;
}

void scritturab(persona P[], int n)
{ // ricopio nel file binario quello letto nel file di testo
    FILE *b;
    b = fopen("anagrafe.bin", "wb");
    if (NULL == b)
    {
        printf("Errore nell'apertura del file anagrafe.bin");
        exit(-1);
    }

    fwrite(P, sizeof(persona), n, b);

    fclose(b);
}

int letturab(persona P[])
{
    FILE *b;
    b = fopen("anagrafe.bin", "rb");
    if (NULL == b)
    {
        printf("Errore nell'apertura del file anagrafe.bin");
        exit(-1);
    }

    int n = 0;
    n = fread(P, sizeof(persona), 100, b);
    fclose(b);
    return n;
}

void scritturaf(persona P[], int n)
{
    FILE *f;
    f = fopen("anagrafe2.txt", "wt");
    if (NULL == f)
    {
        printf("Errore nell'apertura del file anagrafe2.txt");
        exit(-1);
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%s %s %d\n", P[i].nome, P[i].cognome, P[i].età);
    }
    fclose(f);
}

int main()
{

    persona P[100];
    int n = 0;
    int i = 0;
    n = letturaf(P);
    scritturab(P, n);
    i = letturab(P);
    scritturaf(P, i);
}