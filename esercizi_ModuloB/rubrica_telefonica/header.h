#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM 20 // dimensione rubrica

typedef struct
{ // definizione di un elemento della rubrica
    char cognome[20];
    char nome[20];
    char tel[16];
} elemento;

typedef elemento rubrica[DIM]; // come è composta la rubrica? Array di elemento (qua 20 elementi)

int menu(void);
int compare(elemento *e1, elemento *e2);
int inserire(rubrica R, int n);
void stampa(rubrica R, int n);
