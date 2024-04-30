/*
gcc -c main.c
gcc -c function.c
gcc -o riscorsivo main.o function.o
./iterativo

*/

typedef struct list_element
{
    int value;
    struct list_element *next; // etichetta struct list_element per la ricorsione
} item;

typedef item *list;

list cons(int i, list L);
void showListr(list L);
int member(int n, list L);