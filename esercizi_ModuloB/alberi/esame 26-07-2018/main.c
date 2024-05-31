// simulazione esame 26-07-2018 ALBERI e STRUTTURE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int quantità;
} alimento;

typedef struct nodo
{
    alimento value;
    struct nodo *left, *right;

} NODO;

typedef NODO *tree;

int isLess(alimento a, alimento b)
{ // confronto solo 2 nomi per sapere quale arriva prima

    if (strcmp(a.nome, b.nome) > 0)
    {
        return 0; // a più grande di b (non in ordine)
    }
    else
    {
        return 1; // a più piccolo di b (in ordine)
    }
}
tree constree(alimento A, tree l, tree r)
{
    tree aux;
    aux = (tree)malloc(sizeof(NODO));
    aux->value = A;
    aux->left = l;
    aux->right = r;

    return aux;
}

tree insord(alimento A, tree T)
{
    if (T == NULL)
    {

        return constree(A, NULL, NULL);
    }
    else if (isLess(A, T->value))
    { // se mi ha ritornato 1 è in ordine quindi alimento più pccolo radice vado a sx
        T->left = insord(A, T->left);
    }
    else
    { // alimento più grande (nome) della radice vado a destra
        T->right = insord(A, T->right);
    }
    return T;
}

tree funzioneA(FILE *f, tree T)
{
    alimento A;
    while (fread(&A, 1, sizeof(alimento), f) > 0)
    { // finchè leggo
        if (A.quantità >= 100)
        { // se ha almeno 100 scatole di prodotto, allora procedo con l'inserimento
            T = insord(A, T);
        }
    }
    return T;
}

void funzioneB(tree T) // inorder
{

    if (T != NULL)
    {

        funzioneB(T->left);
        printf("Il prodotto %s con %d scatole\n", T->value.nome, T->value.quantità);
        funzioneB(T->right);
    }
}

void funzioneC(FILE *f, tree T, int *tot)
{
    if (T != NULL)
    {
        //*tot è il totale delle scatole
        funzioneC(f, T->left, tot);
        fprintf(f, "%s con %d scatole\n", T->value.nome, T->value.quantità);
        *tot = (*tot) + T->value.quantità;
        funzioneC(f, T->right, tot);
    }
}

int main()
{
    FILE *f;
    tree T;
    T = NULL;

    f = fopen("alimenti.bin", "rb");
    if (f == NULL)
    {
        printf("Errore nell'apertura del file alimenti.bin");
        exit(-1);
    }

    T = funzioneA(f, T);
    fclose(f);
    funzioneB(T);

    FILE *t;
    t = fopen("out.txt", "wt");
    if (t == NULL)
    {
        printf("Errore nell'apertura del file out.txt");
        exit(-1);
    }
    int tot = 0; // numero totale scatole
    funzioneC(t, T, &tot);
    fprintf(f,"Numero totale di scatole: %d\n", tot);
    fclose(t);
}
