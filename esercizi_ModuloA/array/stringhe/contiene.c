#include <stdio.h>
#include <string.h>

#define MAX_CHAR 100

int main() {
    char primaParola[MAX_CHAR];
    char secondaParola[MAX_CHAR];

    
    printf("Inserisci la prima parola (massimo %d caratteri): ", MAX_CHAR - 1); //-1 perchè lascio un posto per il carattere terminatore
    scanf("%s", primaParola);

    printf("Inserisci la seconda parola (massimo %d caratteri): ", MAX_CHAR - 1);
    scanf("%s", secondaParola);

    // Verifica se la seconda parola è contenuta nella prima
    int lunghezzaPrima = strlen(primaParola);
    int lunghezzaSeconda = strlen(secondaParola);
    int contenuta = 0;

    int i = 0;
    while (i <= lunghezzaPrima - lunghezzaSeconda && contenuta==0) {    //&& !contenuta
        int j = 0;
        while (j < lunghezzaSeconda && primaParola[i + j] == secondaParola[j]) {
            j++;
        }

        if (j == lunghezzaSeconda) {
            contenuta = 1; // La seconda parola è contenuta nella prima
        }

        i++;
    }

    // Stampa il risultato
    if (contenuta) {
        printf("La seconda parola '%s' è contenuta nella prima parola '%s'.\n", secondaParola, primaParola);
    } else {
        printf("La seconda parola '%s' non è contenuta nella prima parola '%s'.\n", secondaParola, primaParola);
    }

    
}