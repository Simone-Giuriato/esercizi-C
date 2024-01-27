/*Nel file di testo anagrafe.txt contenuto nella domanda fuori da questo modulo sono presenti personaggi storici ed attuali (Nome Cognome eta).

Nome e Cognome sono stringhe lunghe al massimo 20 caratteri (compreso terminatore).

Si legga l’anagrafe testuale e, una persona alla volta, si salvi il contenuto nel file binario anagrafe.bin
Si legga l’anagrafe binaria (ovvero anagrafe.bin) e, una persona alla volta, si salvi il contenuto nel file di testo copia_anagrafe.txt
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[21];
    char cognome[21];
    int età;
} credenziali;

int main() {
    FILE *f1, *b1, *f2;

    credenziali personaggio;

    // Leggi da anagrafe.txt e scrivi in anagrafe.bin
    f1 = fopen("anagrafe.txt", "rt");
    if (f1 == NULL) {
        perror("Errore in apertura del file anagrafe.txt");
        exit(-1);
    }

    b1 = fopen("anagrafe.bin", "wb");
    if (b1 == NULL) {
        perror("Errore in apertura del file anagrafe.bin");
        exit(-1);
    }

    while (fscanf(f1, "%s %s %d", personaggio.nome, personaggio.cognome, &personaggio.età) == 3) {
        fwrite(&personaggio, sizeof(credenziali), 1, b1);
    }

    fclose(f1);
    fclose(b1);

    // Leggi da anagrafe.bin e scrivi in copia_anagrafe.txt
    b1 = fopen("anagrafe.bin", "rb");
    if (b1 == NULL) {
        perror("Errore in apertura del file anagrafe.bin");
        exit(-1);
    }

    f2 = fopen("copia_anagrafe.txt", "wt");
    if (f2 == NULL) {
        perror("Errore in apertura del file copia_anagrafe.txt");
        exit(-1);
    }

    while (fread(&personaggio, sizeof(credenziali), 1, b1)==1) {
        fprintf(f2, "%s %s %d\n", personaggio.nome, personaggio.cognome, personaggio.età);
    }

    fclose(b1);
    fclose(f2);

    return 0;
}