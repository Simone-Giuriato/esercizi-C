#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nodo
{
    int value;
    struct nodo *left, *right;

} NODO;

typedef NODO *tree;

tree constree(int i, tree l, tree r)
{
    tree t;
    t = (tree)malloc(sizeof(NODO));
    t->value = i;
    t->left = l;
    t->right = r;

    return t;
}

void preorder(tree t)
{
    if (t != NULL)
    {
        printf("%d\n", t->value);
        preorder(t->left);  // prima tutto il sinsitro
        preorder(t->right); // quando è stato stampato tutto il sinistro vado con tutto il destro
    }
}
void postorder(tree t)
{
    if (t != NULL)

    {
        postorder(t->left);
        postorder(t->right);
        printf("%d\n", t->value);
    }
}

void inorder(tree t)
{
    if (t != NULL)

    {
        inorder(t->left);
        printf("%d\n", t->value);
        inorder(t->right);
    }
}

int nnodi(tree t)
{
    if (t == NULL)
        return 0; // se vuoto nodi son 0
    else
        return (1 + nnodi(t->left) + nnodi(t->right)); // la radice + sinistro+ destro
}
int max(int a, int b)
{ // mi serve sapere il massimo tra sotto albero sinistra o destra
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int height_aux(tree t) // non capita molto bene l altezza
{
    if (t == NULL)
    {

        return 0;
    }
    else
    {
        return (1 + max(height_aux(t->left), height_aux(t->right))); // 1 (arco collega radice al sottoalbero, piu il sottolabero decretato maggiore dalla funzione max)
    }
}

int height(tree t) // numero di archi
{
    if (t == NULL)
    {

        return 0;
    }
    else
    {
        return (max(height_aux(t->left), height_aux(t->right)));
    }
}

int main()
{
    tree T;
    T = NULL;
    int i = 0;

    do
    {
        printf("Inserisci un valore (0 per terminare):");
        scanf("%d", &i);
        if (i != 0)
        {
            T = constree(i, T, NULL);
        }

    } while (i != 0);

    printf("\nOrdine PreOrder:\n");
    preorder(T); // prima radice poi sottoAlberi (prima tutto quello sinistro poi il destro)
    printf("Ordine PostOrder:\n");
    postorder(T); // prima i sottoAlberi (da sx a dx) e per ultima la radice
    printf("Ordine Inorder:\n");
    inorder(T); // sottoAlbero sx- radice- sottoAlbero dx

    printf("Il numero di nodi è: %d\n", nnodi(T));

    printf("L'altezza dell'albero è:%d\n", height(T)); // lunghezza del cammino più lungo dalla radice ad una foglia
}

/*int conta_el(element e, tree t)
{
    if (t == NULL)
        return 0;
    else if (e == t->value)

        return 1 + conta_el(e, t->left) + conta_el(e, t->right);

    else

        return conta_el(e, t->left)

               + conta_el(e, t->right);
}
*/