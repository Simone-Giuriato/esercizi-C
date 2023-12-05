#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[20];
    char cognome[20];
    int eta;
} personaggio;

int main()
{

    personaggio P;
    FILE *f, *b,*p;
    f = fopen("anagrafe.txt", "rt");
    b = fopen("anagrafe.bin", "wb");
    p = fopen("ana.txt", "wt");


    while (fscanf(f, "%s %s %d", P.nome, P.cognome, &P.eta) != EOF)
    {
        fflush(f);
        fwrite(&P, sizeof(personaggio), 1, b);
    }

    //manca l'altro pezzo dove scrivo da binario a testuale segui consegna es1
    
       
    

    fclose(f);

    fclose(b);
}