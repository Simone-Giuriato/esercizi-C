/*
Uno studente deve calcolare la media dei suoi esami per la laurea. Per ogni esame si hanno:
- nome: stringa contenente al massimo 20 caratteri, incluso il terminatore;
- crediti: intero;
- voto: intero.
L’università necessita sia della media aritmetica sia della media pesata. Nella media pesata si considerano i crediti come pesi.

Esempio
- Informatica -> 15 crediti, voto 30
- Inglese -> 6 crediti, voto 20
Media aritmetica = (30 + 20) / 2 = 25.00
Media pesata = (30*15 + 20*6) / (15+6) = 27.14

Si scriva un programma C che:
- Legge da tastiera un opportuno array di strutture che contiene gli esami sostenuti dallo studente. Gli esami sono al massimo 20. La lettura va effettuata in una opportuna funzione da invocare nel main.
- Calcola media pesata e media aritmetica tramite una funzione da invocare nel main.
- Nel main, stampa i risultati.
*/

#include <stdio.h>

typedef struct
{
    char nome[20];
    int crediti;
    int voto;

} esame;

int lettura(esame array[20])
{
    int n = 0;

    printf("Quanti esami vuoi inserire (massimo 20)?");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Inserisci nome:");
        scanf("%s", array[i].nome);
        printf("Inserisci crediti:");
        scanf("%d", &array[i].crediti);
        printf("Inserisci voto:");
        scanf("%d", &array[i].voto);
    }
    return n;
}

float media(esame array[20], int n){
    int s=0;

    for(int i=0;i<n;i++){
        s=s+array[i].voto;
    }

    return s/n;
}

float media_pesata(esame array[20],int n){
    int s=0;
    int somma_crediti=0;

    for(int i=0;i<n;i++){
        s=s+(array[i].voto*array[i].crediti);
        somma_crediti=somma_crediti+array[i].crediti;
    }

    return s/somma_crediti;
}

int main()
{
    esame a[20];
    int lung;
    float m,m_p;

    lung=lettura(a);
    m=media(a,lung);
    m_p=media_pesata(a,lung);

    printf("La media è: %.2f\n",m);
    printf("La media pesata è: %.2f\n",m_p);

    return 0;
} 

//non funziona a pieno, non so perche le medie le stampa solo come intere, (credo voglia i voti inseriti come dicimali, ma da consegna sono vincolati ad interi)