/*
L’orario di una lezione è rappresentato dalla struttura:

typedef struct
{ char nomecorso[20];
int orainizio, orafine;
} orario;

Si scriva una funzione che, date 2 lezioni, verifica se si sovrappongono e, qualora si sovrappongano, lo segnali al chiamante e sposti in avanti la lezione che inizia più tardi, in modo che inizi appena finisce l’altra lezione.
Nota: non sappiamo a priori quale delle due lezioni comincia prima (bisogna controllare il valore di orainizio).
Nota2: Non è obbligatorio fare il controllo dell'input, si supponga che l'utente inserisca un ora iniziale compresa tra 0 e 23.
*/

#include <stdio.h>

typedef struct
{
    char nomecorso[20];
    int orainizio, orafine;
} orario;

void sovrappongono(orario lezione1, orario lezione2)
{

    int durata = 0;
    int modifica = 0; // bool
    if (lezione1.orainizio <= lezione2.orainizio && lezione1.orafine >= lezione2.orainizio)
    { // qual'ora coincidessero rientrano in questo caso

        durata = lezione2.orafine - lezione2.orainizio;
        lezione2.orainizio = lezione1.orafine;
        lezione2.orafine = lezione2.orainizio + durata; // sposto la lezione 2
        modifica = 1;
    }
    else if (lezione2.orainizio < lezione1.orainizio && lezione2.orafine > lezione1.orainizio)
    {

        durata = lezione1.orafine - lezione1.orainizio;
        lezione1.orainizio = lezione2.orafine;
        lezione1.orafine = lezione1.orainizio + durata; // sposto la lezione 1
        modifica = 1;
    }

    if (modifica == 1)
    {
        printf("Le lezioni si sovrappongono:\n");
        printf("Ecco il nuovo piano: \n");
        printf("%s, Inizio: %d, Fine: %d\n", lezione1.nomecorso, lezione1.orainizio, lezione1.orafine);
        printf("%s, Inizio: %d, Fine: %d\n", lezione2.nomecorso, lezione2.orainizio, lezione2.orafine);
    }
    else
    {
        printf("Le lezioni non si sovrappongono\n");
    }
}

int main()
{

    orario lezione1, lezione2;

    printf("Inserisci il nome della prima lezione:");
    scanf("%s", lezione1.nomecorso);
    printf("Inserisci ora inizio della prima lezione:");
    scanf("%d", &lezione1.orainizio);
    printf("Inserisci ora fine della prima lezione:");
    scanf("%d", &lezione1.orafine);

    printf("Inserisci il nome della seconda lezione:");
    scanf("%s", lezione2.nomecorso);
    printf("Inserisci ora inizio dellla seconda lezione:");
    scanf("%d", &lezione2.orainizio);
    printf("Inserisci ora fine della seconda lezione:");
    scanf("%d", &lezione2.orafine);

    sovrappongono(lezione1, lezione2);
}
