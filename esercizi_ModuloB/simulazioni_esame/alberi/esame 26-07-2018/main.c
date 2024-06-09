// esame 26/07/2018

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int quantità;

} alimento;

typedef struct nodo
{
    alimento value;
    struct nodo *left;
    struct nodo *right;
} NODO;

typedef NODO *tree;

tree constree(alimento A, tree l, tree r)
{
    tree aux = NULL;
    aux = (tree)malloc(sizeof(NODO));
    aux->value = A;
    aux->left = l;
    aux->right = r;

    return aux;
}

tree insord(alimento A, tree t)
{
    if (t == NULL)
    {
        return constree(A, NULL, NULL);
    }
    else
    {
        if (strcmp(A.nome, t->value.nome) <= 0)
        {
            t->left = insord(A, t->left);
        }
        else
        {
            t->right = insord(A, t->right);
        }
        return t;
    }
}

tree funzioneA(FILE *f, tree t)
{
    alimento A;

    while (fread(&A, sizeof(alimento), 1, f) > 0)
    {
        if (A.quantità >= 100)
        {
            t = insord(A, t);
        }
    }
    return t;
}

void funzioneB(tree T) // stamopo a video il contenuto dell'albero
{
    if (T != NULL)
    {
        funzioneB(T->left);
        printf("%s con %d scatole\n", T->value.nome, T->value.quantità);
        funzioneB(T->right);
    }
}

void funzioneC(FILE *g, tree T, int *somma)
{

    if (T != NULL)
    {

        *somma = (*somma) + T->value.quantità;
        funzioneC(g, T->left, somma);
        fprintf(g, "%s con %d scatole\n", T->value.nome, T->value.quantità);
        funzioneC(g, T->right, somma);
    }
}

int main()
{

    tree T = NULL;
    FILE *f;
    f = fopen("alimenti.bin", "rb");
    if (f == NULL)
    {
        printf("Errore nell'apertura del file alimenti.bin");
        exit(-1);
    }

    T = funzioneA(f, T);
    fclose(f);
    funzioneB(T);
    FILE *g;
    g = fopen("out1.txt", "wt");
    if (g == NULL)
    {
        printf("Errore nell'apertura del file out1.txt");
        exit(-1);
    }
    int somma = 0;
    funzioneC(g, T, &somma);
    fprintf(g, "Il numero totale di scatole è: %d\n", somma);
    fclose(g);
}