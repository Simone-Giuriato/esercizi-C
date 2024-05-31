#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

// ALBERI BINARI DI RICERCA

int menu(void)
{
    int scelta = 0;
    printf("\nMENÙ DI SCELTA:\n");
    printf("Premi 0 per uscire dal programma;\n");
    printf("Premi 1 per Inserire elementi nell'albero;\n");
    printf("Premi 2 per eseguire stampa PREORDER;\n");
    printf("Premi 3 per eseguire stampa POSTORDER;\n");
    printf("Premi 4 per eseguire stampa INORDER;\n");
    printf("Premi 5 per cercare un elemento;\n");
    printf("Premi 6 per calcolare l'altezza dell'albero;\n");
    printf("Premi 7 per fare la somma degli elementi dell'albero;\n");
    printf("Premi 8 per calcolare il numero totale di nodi dell'albero;\n");
    printf("Premi 9 per calcolare il bilanciamento dell'albero;\n");
    scanf("%d", &scelta);

    return scelta;
}

int getElement()
{
    int i = 0;
    printf("Inserisci un numero nell'albero:");
    scanf("%d", &i);
    return i;
}

tree constree(int elemento, tree l, tree r)
{
    tree t1;
    t1 = (tree)malloc(sizeof(NODO));
    t1->value = elemento;
    t1->left = l;
    t1->right = r;

    return t1;
}

tree ordins(int elemento, tree T)
{ // RICORSIVO più compatto
    if (T == NULL)
    {
        return constree(elemento, NULL, NULL); //constree(elemento, T, NULL)
    }
    else if (elemento <= T->value) //<=
    {                              // minore della radice
        T->left = ordins(elemento, T->left);
    }
    else
    {
        T->right = ordins(elemento, T->right);
    }
    return T;
}

// le viste degli alberi sono RICORSIVI
void preorder(tree T)
{ // prima radice poi sottoalberi da sx a dx

    if (T != NULL)
    {

        printf("%d\n", T->value);
        preorder(T->left);
        preorder(T->right);
    }
}

void postorder(tree T) // prima sx poi dx poi radice
{
    if (T != NULL)
    {
        postorder(T->left);
        postorder(T->right);
        printf("%d\n", T->value);
    }
}

void inorder(tree T)
{ // prima sx poi radice poi dx
    if (T != NULL)
    {
        inorder(T->left);
        printf("%d\n", T->value);
        inorder(T->right);
    }
}

int ricerca(int elemento, tree T)
{
    // ITERATIVO
    int trovato = 0;

    while (T != NULL && !trovato)
    {
        if (T->value == elemento)
        {
            trovato = 1;
        }
        else if (elemento < T->value)
        {
            T = T->left;
        }
        else
        {
            T = T->right;
        }
    }
    return trovato;
}
int max(int a, int b)
{ // funzione per fare il confronto
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int height_aux(tree T)
{ // RICORSIVA
    if (T == NULL)
    {
        return 0; // se albero vuoto, altezza sarà 0
    }
    else
    {
        return (1 + max(height_aux(T->left), height_aux(T->right)));
    }
}

int height(tree T)
{ // RICORSIVA
    if (T == NULL)
    {
        return 0; // se albero vuoto, altezza sarà 0
    }
    else
    {
        return (max(height_aux(T->left), height_aux(T->right))); // come height_aux ma senza 1
    }
}

int somma_elementi(tree T)
{ // RICORSIVA
    int somma = 0;

    if (T == NULL)
    {
        return 0;
    }
    else
    {
        return T->value + somma_elementi(T->left) + somma_elementi(T->right);
    }
}

int nnodi(tree T)
{
    // RICORSIVA
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + nnodi(T->left) + nnodi(T->right);
    }
}

int bilanciamento(tree T)   //non credo sia giustissimo
{
    // se differenza tra altezza albero sinistro e albero destro è maggiore di uno, l albero non è bilanciato
    int height_left = 0;
    int height_right = 0;
    int bilanciato = 0;

    height_left = height(T->left);
    height_right = height(T->right);

    if ((height_left - height_right) > 1 || (height_right - height_left) > 1)
    {
        bilanciato = 0;
    }
    else
    {
        bilanciato = 1;
    }

    // return bilanciamento(T->left) && bilanciamento(T->right);
    return bilanciato;
}