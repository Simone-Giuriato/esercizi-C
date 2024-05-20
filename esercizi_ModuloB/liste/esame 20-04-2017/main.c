#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int kcal;
} alimento;

typedef struct list_element
{
    alimento value;
    struct list_element *next;
} item;

typedef struct list_element *list;

int isLess(alimento a, alimento b){
    if(strcmp(a.nome,b.nome)<=0){   //<0 a precede b, quindi sarebbe ordinato
        return 1;
    }else{
        return 0;
    }

}

list cons(list L, alimento A)   //alloco memoria per ogni nodo della lista
{
    list aux;
    aux = (list)malloc(sizeof(item));
    aux->value = A;
    aux->next = L;
    return aux;
}

list insord(list L, alimento A)//inserimento ordinato in testa
{//RICORSIVO
    if(L==NULL){    //se lista è vuota   
        return cons(L,A);
    }else if(isLess(A,L->value)){
        return cons(L,A);
    }else{
        L->next=insord(L->next,A);  //vado al nodo successivo e faccio il confornto con l alimento 
        return L;   // giunto qua: se è l'ultimo elemento di ordine allora ritorno L (è finito l ordinamento)
    }

}

list funzioneA(FILE *f,list L)
{
    alimento A;
    int n = 0;
    while (fread(&A,sizeof(alimento),1, f) > 0) //>0 finchè legge
    {
        L = insord(L, A);
    }
    return L;
}

void funzioneB(list L){ //stampoa video tutti gli alimenti e le relative kacal
    while(L!=NULL){
        printf("%s %d\n",L->value.nome,L->value.kcal);
        L=L->next;

    }
}

void funzioneC(FILE *g,list L){
    int n=0;
    fprintf(g,"ALIMENTI IPO-CALORICI:\n");
    while(L!=NULL){
        if(L->value.kcal>100){  //alimenti ipo-calorici sopra le 100kcal

        fprintf(g,"%s %d\n", L->value.nome, L->value.kcal);
        
        n++;

        } 
        L=L->next; 
        
    }
    fprintf(g,"Il numero totale di alimenti ipo-calorici è: %d",n);

}

int main()
{
    list L;
    L = NULL;
    FILE *f;
    f = fopen("alimenti.bin", "rb");
    if (f == NULL)
    {
        printf("Errore nell'apertura del file alimenti.bin");
        exit(-1);
    }

    L = funzioneA(f, L);
    fclose(f);
    funzioneB(L);
    FILE *g;
    g=fopen("output.txt","wt");
    if(g==NULL){
        printf("Errore nell'apertura del file output.txt");
        exit(-1);
    }

    funzioneC(g,L);
}