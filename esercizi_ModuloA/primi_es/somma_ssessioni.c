#include <stdio.h>
/*Un consulente deve calcolare il numero di ore e minuti spesi lavorando per un cliente.
Egli ha lavorato in due distinte sessioni di lavoro, per ciascuna delle
quali ha annotato il numero di ore e il numero di minuti impiegati.
Si scriva un programma in C che, a partire dalle ore e minuti della prima
sessione di lavoro e dalle ore e minuti della seconda sessione di
lavoro, calcoli il numero di ore e minuti complessivi.
*/

int main()
{
    int ore1, minuti1;
    int ore2, minuti2;

    printf("Iserisci le ore lavorate nella prima ssesione:");
    scanf("%d", &ore1);
    printf("Iserisci le ore lavorate nella prima sesione:");
    scanf("%d", &minuti1);

    printf("Iserisci le ore lavorate nella seconda sesione:");
    scanf("%d", &ore2);
    printf("Iserisci le ore lavorate nella seconda sesione:");
    scanf("%d", &minuti2);

    int oreSomma;
    int minutiSomma;


    oreSomma=ore1+ore2; //sommo le ore
    minutiSomma= minuti1+minuti2; //sommo le ore

    int nuoveOre;

    nuoveOre= minutiSomma/60; //i minuti giusti che formano un ora divantano ore

    oreSomma=oreSomma+nuoveOre; //sommo le ore con le "nuove"
    minutiSomma= minutiSomma- nuoveOre*60; //tolgo dai minuti le "nuove ore"


    printf("Il consulente ha lavorato: %d ore e %d minuti\n", oreSomma, minutiSomma);



}