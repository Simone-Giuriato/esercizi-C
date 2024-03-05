/*int argc è un parametro di tipo intero che rappresenta il
numero di argomenti passati al programma da linea di
comando. Anche il nome del programma è considerato un
argomento quindi argc vale sempre almeno 1
char *argv[] è un puntatore a un puntatore a carattere,
ovvero un array di stringhe. Gli argomenti nel vettore di
stringhe sono memorizzati nell’ordine con cui sono stati
inseriti dall’utente sulla linea di comando. L’array è
indicizzato a partire da zero, quindi argv[0] contiene il nome
del programma stesso. N.B.: gli argomenti sono contenuti in
stringhe quindi non è possibile assegnare direttamente il
contenuto di un argomento ad un intero*/

/*
Realizzare un programma C che, dato come argomento il nome di
un file (di testo), ne visualizzi il contenuto a pagine (20 righe alla
volta). Dopo la visualizzazione di ciascun gruppo di righe, chiedere
all’utente se vuole visualizzare le successive 20 (o le restanti nel
file se il file ha meno di 20 righe non ancora lette) o fermarsi.

Se si utilizza un percorso relativo, il file col quale si vuole interagi-
re (in questo caso leggere) deve trovarsi:

nella stessa cartella dove si trovano i file .c e .h del progetto
se si esegue il programma da Visual Studio
nella stessa cartella che contiene il file eseguibile
<nome_progetto>.exe (solitamente la sottocartella Debug)
se si esegue il programma da terminale
Alternativamente, è possibile utilizzare un percorso assoluto e il
file può trovarsi in altre posizioni all’interno del file system.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    FILE *f;
    f = fopen(argv[1], "rt");
    char str[100];
    int n_righe;

    if (f == NULL)
    {
        printf("Errore nell'apertura del file di input");
        exit(-1);
    }

    char scelta;
    do
    {

        while (fgets(str, sizeof(str), f) != NULL && n_righe < 20)
        {
            printf("%s\n", str);
            n_righe++;
            if (feof(f))
            {
                printf("fine del file raggiunta\n");
            }
        }
        if (!feof(f))
        {
            printf("Premi 's' se vuoi continuare a vedere:\n");
            scanf("%c", &scelta);
        }
        

    } while (!feof(f) && scelta == 's');
    fclose(f);
}