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

    for (int i = 0; i < 2; i++)
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
        somma_crediti==somma_crediti+array[i].crediti;
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
    m_p=(a,lung);


    /*for (int i = 0; i < lung; i++)
    {
        printf("%d", a[i].voto);
    }*/

    printf("La media è: %.2f",m);
    printf("La media pesata è: %.2f",m_p);
}