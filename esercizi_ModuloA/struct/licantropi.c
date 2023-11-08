/*
In un gioco di ruolo si sfidano umani e licantropi.
Ciascun personaggio, rappresentato attraverso un tipo di dato struttura, possiede le seguenti caratteristiche:

- HP (Health Points o Punti Vita): Rappresentano la quantità di danno che il personaggio può sopportare. Se i "Punti Vita" raggiungono il valore zero (o un valore inferiore) il personaggio muore.
- ATT (Attack Points o Punti Attacco): Rappresentano la capacità offensiva del personaggio.
- DEF (Defense Points o Punti Difesa): Rappresentano la capacità difensiva del personaggio.

Quando un personaggio attacca un avversario, il danno inflitto all'avversario si calcola sottraendo il valore DEF dell'avversario dal valore ATT dell'attaccante moltiplicato per 2.
Supponendo ATT dell'umano pari a 10 e DEF del licantropo pari a 5, il danno inflitto dall'umano al licantropo è pari a (10*2)-5.

In ogni round di gioco l'umano attacca per primo, e il danno inflitto viene sottratto dal valore HP del licantropo. Se il licantropo sopravvive (HP > 0), è il suo turno di attaccare. Se l'umano sopravvive all'attacco del licantropo (HP > 0) comincia un nuovo round.

L' umano può inoltre possedere delle pozioni curative (indicate con il valore POT): quando i suoi HP diventano uguali o inferiori a 10, l'umano può, e DEVE, utilizzare una pozione per guadagnare 10 HP all'inizio del round.

Nel round in cui l'umano usa la pozione curativa non può attaccare ma per l'effetto della pozione riceve solo la metà dei danni quando il licantropo lo attacca.
Ogni pozione può essere usata solamente una volta e poi deve essere scartata.

Scrivere un programma in linguaggio C che legga da tastiera le caratteristiche prima dell'umano e poi del licantropo (HP, ATT e DEF numeri interi) e le inserisca in opportune strutture dati. Il programma deve poi leggere da tastiera il numero di pozioni curative possedute dall'umano (POT numero intero).
Al termine dell'inserimento dei valori il programma deve simulare una battaglia e stampare:
-> "Vittoria in X rounds" se l'umano vince
-> "Sconfitta in X rounds" se l'umano perde
dove X è il numero di round giocati.
*/

#include <stdio.h>

typedef struct
{
    int HP;
    int ATT;
    int DEF;
} statistiche;

int main()
{

    statistiche umano, licantropo;
    int POT; // numero di pozione curative che solo l'umano può possedere
    int aUmano, aLica;  //contiene il valore dell'attacco risp. umano o licantropo da sotrarre alla vita del nemico
    int round=0;

    printf("Inserisci le caratteristiche dell'umano (HP, ATT, DEF):");
    scanf("%d, %d, %d", &umano.HP, &umano.ATT, &umano.DEF);
    printf("Inserisci le caratteristiche del licantropo (HP, ATT, DEF):");
    scanf("%d, %d, %d", &licantropo.HP, &licantropo.ATT, &licantropo.DEF);
    printf("Inserisci quante pozioni curative possiede l'umano:");
    scanf("%d", &POT);

    while (umano.HP > 0 && licantropo.HP > 0)
    {
        if (umano.HP <= 10 && POT>0)
        {
            POT--;
            printf("------------INIZIO ROUND-----------\n");
            printf("HP Umano: %d, HP Licantropo: %d\n", umano.HP, licantropo.HP);
            umano.HP=umano.HP+10;
            printf("L'umano usa pozione. HP Umano ora: %d\n", umano.HP);
            aLica = ((licantropo.ATT * 2) - umano.DEF) / 2;
            umano.HP = umano.HP - aLica;
            printf("Licantropo attacca. L'umano è protetto dalla pozione. HP Umano: %d\n", umano.HP);
            round++;
            printf("------------FINE ROUND-----------\n");
        }
        printf("------------INIZIO ROUND-----------\n");
        printf("HP Umano: %d, HP Licantropo: %d\n", umano.HP, licantropo.HP);
        aUmano = (umano.ATT * 2) - licantropo.DEF;
        licantropo.HP = licantropo.HP - aUmano;
        printf("L'umano attacca. HP Licantropo: %d\n", licantropo.HP);
        aLica = (licantropo.ATT * 2) - umano.DEF;
        umano.HP = umano.HP - aLica;
        printf("Licantropo attacca. HP Umano: %d\n", umano.HP);
        round++;
        printf("------------FINE ROUND-----------\n");
    }

    if(umano.HP>0){     //ha vinto l'umano (noi)
        printf("Vittoria in %d rounds \n",round);
    }else {
        printf("Sconfitta in %d rounds \n", round);       //ha vinto il Licantropo (sconfitta per l'umano)
    }// si specifica che se l'umano perde con -1 di vita e il licantropo muore con -12 esempio, è una sconfitta perchè l'umano è comunque morto
}