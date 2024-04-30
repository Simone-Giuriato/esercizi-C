/*
gcc -c main.c
gcc -c function.c
gcc -o iterativo main.o function.o
./iterativo

*/

typedef struct list_element
{
    int value;
    struct list_element *next; // etichetta struct list_element per la ricorsione
} item;

typedef item *list;

list cons(int i, list L);
void showList(list L);
int member(int n, list L);
