/*
Scrivere un programma in linguaggio C che legga due parole da tastiera.
Le parole possono contenere al più 100 caratteri ciascuna.
Si verifichi se la seconda parola è contenuta nella prima.
*/
#include<stdio.h>
#include<string.h>
#define N 100

int main()
{
    char str1[N], str2[N];
    int len1, len2 , i, j, trovato;
 
    printf("Inserisci una parola:  ");
    scanf("%s",str1);
    printf("parola da cercare: ");
    scanf("%s",str2);

    len1=strlen(str1);
    len2=strlen(str2);
    trovato=0;
    i=0; // posizione sulla prima stringa
    while(i <= len1 - len2 && !trovato)
    {
        j=0;    // posizione nella seconda stringa
        // Verifico se str1 a partire dalla posizione i e` uguale a str2
        while (str2[j]!='\0' && str1[i+j]==str2[j])
            j++;

        // Se sono arrivato in fondo a str2 ho trovato la sottostringa
        if (str2[j]=='\0')
            trovato=1;

        i++;
    }
    if (trovato)
        printf("La parola %s e' contenuta in %s\n",str2,str1);
    else
        printf("La parola %s NON e' contenuta in %s\n",str2,str1);
}