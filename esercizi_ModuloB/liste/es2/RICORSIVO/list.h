#include <stdio.h>
#include <stdlib.h>

#define RECURSIVE //o ITERATIVE

typedef struct list_element
{
    int value;
    struct list_element *next;
} item;

typedef item *list;

list insord(list L, int el);
int lenght(list L, int n);
void showList(list L);
int sumList(list L,int somma);