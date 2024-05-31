typedef struct nodo
{
    int value;
    struct nodo *left, *right;
} NODO;

typedef NODO *tree;

int menu(void);

int getElement();
int max(int a, int b);

tree constree(int elemento, tree l, tree r);
tree ordins(int elemento, tree T);

void preorder(tree T);
void postorder(tree T);
void inorder(tree T);

int ricerca(int elemento, tree T);

int height_aux(tree T);
int height(tree T);

int somma_elementi(tree T);

int nnodi(tree T);

int bilanciamento(tree T);