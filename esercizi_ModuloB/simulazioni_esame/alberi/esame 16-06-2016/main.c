#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int scatole;
} alimento;

typedef struct nodo
{
    alimento value;
    struct nodo *left, *right;
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
        if (strcmp(A.nome, t->value.nome) < 0)
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

tree funzioneA(FILE *b, tree t)
{
    alimento A;

    while (fread(&A, sizeof(alimento), 1, b) > 0)
    {
        t = insord(A, t);
    }
    return t;
}

void funzioneB(tree t)
{
    if (t != NULL)
    {
        funzioneB(t->left);
        printf("%s %d\n", t->value.nome, t->value.scatole);
        funzioneB(t->right);
    }
}

tree searchTree(tree t, char *nome)
{
    if (t == NULL || strcmp(t->value.nome, nome) == 0)
    {
        return t;
    }
    if (strcmp(nome, t->value.nome) < 0)
    {
        return searchTree(t->left, nome);
    }
    else
    {
        return searchTree(t->right, nome);
    }
}

void funzioneC(FILE *f, tree T, FILE *o)
{

    alimento A;
    while (fscanf(f, "%s %d", A.nome, &A.scatole) != EOF)
    {
        tree node = searchTree(T, A.nome);
        if (node != NULL && node->value.scatole >= A.scatole)
        {
            fprintf(o, "%s\n", A.nome);
        }
    }
}

int main()
{

    tree T = NULL;
    FILE *b;
    b = fopen("alimenti.bin", "rb");
    if (b == NULL)
    {
        printf("Errore nell'apertura de file alimenti.bin");
        exit(-1);
    }

    T = funzioneA(b, T);
    fclose(b);
    funzioneB(T);

    FILE *f;
    f = fopen("pranzo.txt", "rt");
    if (f == NULL)
    {
        printf("Errore nell'apertura del file pranzo.txt");
        exit(-1);
    }

    FILE *o;
    o = fopen("out.txt", "wt");
    if (o == NULL)
    {
        printf("Errore nell'apertura del file out.txt");
        exit(-1);
    }

    funzioneC(f, T, o);
}