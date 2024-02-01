/*COMANDI:
gcc -c main.c
gcc -c funzioni.c
gcc -o anagrafe main.c funzioni c 
./anagrafe*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"  //ricordarsi di importare questa sia nel main.c sia nel file con funzioni
//le struct vanne nel fle funzioni
int main()
{

    persona P[100];
    int n = 0;
    int i = 0;
    n = letturaf(P);
    scritturab(P, n);
    i = letturab(P);
    scritturaf(P, i);
}