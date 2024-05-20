/*
Un file di testo, elenco1.txt, contiene il nome e il cognome de-
gli studenti di un corso universitario. Ciascun nome o cognome è

una stringa lunga al massimo 50 char, senza spazi. Lo stesso stu-
dente (nome e cognome) compare una volta sola nel file, ma due

studenti possono avere lo stesso cognome.
*/
/*Si realizzi un programma C, organizzato in almeno due funzioni:
funzione1 che crea una lista L contenente cognome e nome
(stringhe) degli studenti, e ordinata in senso crescente sul
campo cognome. La funzione1 riceve come parametri:
il puntatore al file di ingresso, aperto in lettura nel main;
il puntatore a L (inizializzato a NULL nel main prima
della prima chiamata alla funzione);
eventuali parametri a scelta;
e restituisce il puntatore alla radice della lista L;
funzione2 che stampa il contenuto della lista L su un file di
uscita elenco2.txt. La funzione2 riceve come parametri:
il puntatore al file di uscita, aperto nel main;
il puntatore a L;
eventuali parametri a scelta;
e restituisce void.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 50

typedef struct // strcut per la composizione del file
{
    char nome[DIM];
    char cognome[DIM];

} persona;

typedef struct list_element // struct lista
{
    persona value;
    struct list_element *next;
} item;

typedef item *list;
int isLess(persona a, persona b) // confronto due cognomi, in caso uguali due nomi
{
    // return 1 se minore o uguale

    if (strcmp(a.cognome, b.cognome) > 0)
    {
        return 0;
    }
    else if (strcmp(a.cognome, b.cognome) < 0)
    {
        return 1;
    }
    else
    {
        return strcmp(a.nome, b.nome) <= 0; // ordino i nomi
    }
}

list cons(persona P, list L) // salvo in memoria con malloc, creando nuovi nodi
{

    list aux = (list)malloc(sizeof(item));
    aux->value = P;
    aux->next = L;
    return aux;
}

/*list insord(persona P, list L) // inserimento ordinato nella lista con funzione isLess e cons
{                              // RICORSIVA
    if (L == NULL)
        return cons(P, L); // caso base, lista vuota
    else
    {
        if (isLess(P, L->value)) // usando l'inserimeento in testa, se elemento in considerazione minore del primo
            return cons(P, L);

        else
        {
            L->next = insord(P, L->next); // richiamo ricorsivo per cercare il posto giusto, anando ad analizzare il nodo successivo con next

            return L;
        }
    }
}*/

list insord(persona P, list L)
{ // inserimento ordinato nella lista con funzione isLess e cons
    // ITERATIVA
    list new_node = cons(P, NULL); // Crea un nuovo nodo con la persona da inserire
    list prev = NULL;              // precedente
    list current = L;              // corrente

    // Trova il punto di inserimento nella lista
    while (current != NULL && isLess(current->value, P))
    {
        prev = current;
        current = current->next; // nel corrente metto il prossimo
    }

    // Inserisce il nuovo nodo nella lista
    if (prev == NULL)
    {
        new_node->next = L; // Inserimento in testa
        return new_node;    // Ritorna il nuovo nodo come nuova testa
    }
    else
    {
        prev->next = new_node; // Inserimento nel mezzo o in fondo
        new_node->next = current;
        return L; // La testa della lista non cambia
    }
}

list funzione1(FILE *f, list L) // leggo una riga alla volta, e faccio confronto dei cognomi
{
    persona P;
    while (fscanf(f, "%s %s", P.nome, P.cognome) != EOF)
    {

        L = insord(P, L);
    }
    return L;
}
void showList(list L) // stampo a video la lista ordinata
{
    // versione iterativa
    while (L != NULL)
    {

        printf("%s %s\n", L->value.cognome, L->value.nome);

        L = L->next;
    }
}
void funzione2(FILE *d, list L) // scrivo nel file la lista ordinata
{
    while (L != NULL)
    {

        fprintf(d, "%s %s\n", L->value.cognome, L->value.nome);

        L = L->next;
    }
}

int main()
{
    list L;
    L = NULL;
    FILE *f;
    f = fopen("elenco1.txt", "rt");
    if (f == NULL)
    {
        printf("errore nell'apertura del file");
        exit(-1);
    }
    L = funzione1(f, L);
    fclose(f);

    showList(L);

    FILE *d;
    d = fopen("elenco2.txt", "wt");
    if (d == NULL)
    {
        printf("errore nell'apertura di elenco2.txt");
        exit(-1);
    }

    funzione2(d, L);
    fclose(d);
}