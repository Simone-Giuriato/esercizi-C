#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int kcal;
} alimento;

typedef struct nodo
{
    alimento value;
    struct nodo *left, *right;
} NODO;

typedef NODO *tree;

int isLess(alimento a, alimento b)
{
    if (strcmp(a.nome, b.nome) > 0)
    { // se a più grande
        return 0;
    }
    else
    {
        return 1;
    }
}

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
        if (isLess(A, t->value))
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
        if (A.kcal >= 200) // inserisco in albero solo quelli iper-calorici (con più di 200 calorie)
        {
            t = insord(A, t);
        }
    }
    return t;
}

void funzioneB(tree t) // stampo a video
{                      // inorder

    if (t != NULL)
    {
        funzioneB(t->left);
        printf("%s %d\n", t->value.nome, t->value.kcal);
        funzioneB(t->right);
    }
}

void funzioneC(FILE *b, tree t, int *somma)
{

    if (t != NULL)
    {
        funzioneC(b, t->left, somma);
        *somma = (*somma) + t->value.kcal;
        funzioneC(b, t->right, somma);
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
    funzioneB(T);
    fclose(f);

    FILE *b;
    b = fopen("ipertree.txt", "wt");
    if (b == NULL)
    {
        printf("Errore nell'apertura del file ipertree.txt");
        exit(-1);
    }
    int somma = 0;

    funzioneC(b, T, &somma);
    fprintf(b, "L'energia totale degli alimenti iper-calorici è: %d\n", somma);
    fclose(b);
}