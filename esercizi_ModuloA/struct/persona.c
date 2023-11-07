#include <stdio.h>

/*
Scrivere un programma in linguaggio C che definisca la struttura “persona” composta da:

Si richiedano all'utente tutti i dati, si inseriscano nella struttura dati appena definita e poi si stampino a video.
Nota: Inserire le stringhe senza spazi.
*/

typedef struct 
{
    char nome[32];
    char cognome[32];
    char via[64];
    int civico;
    char città[64];
    char provincia[3];
    int giorno,mese,anno;       //data di di nascita


} persona;

int main(){

    persona p; //creo una variabile di tipo persona, il tipo è creato nella struct soprastante

    //leggo le info che appartengono al tipo persona
    printf("Inserire Nome e cognome:");
    scanf("%s %s",p.nome,p.cognome);

    printf("Inserire il proprio indirizzo:");
    scanf("%s %d %s %s", p.via,&p.civico,p.città,p.provincia);

    printf("Inserire la data di nascita:");
    scanf("%d %d %d",&p.giorno,&p.mese,&p.anno);

    //stampo le info appena inserite
    printf("Nome e cognome: %s %s\n",p.nome, p.cognome);
    printf("Indirizzo: %s %d %s %s\n", p.via,p.civico,p.città,p.provincia);
    printf("Data di nascita: %d %d %d\n",p.giorno,p.mese,p.anno);
}


