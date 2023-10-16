#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int SoloLettere(char parola[]){
    int controllo=0;
    for(int i=0; i<strlen(parola); i++){
        if(parola[i]>='0' && parola[i]<='9')
        {
            controllo++;
        
        }
       
    }
        return controllo;

}
void Vocali_Consonanti(char parola[]){
     
    int vocali=0;
    int consonanti=0;
    for(int i=0; i<strlen(parola); i++){
         if (parola[i] == 'a' || parola[i] == 'e' || parola[i] == 'i'
            || parola[i] == 'o' || parola[i] == 'u'){
                vocali++;

            }else{
                consonanti++;

                }
            
    }
    printf("Il numero di vocali è: %d\n",vocali);
    printf("Il numero di consonanti è: %d\n",consonanti);
    
}
void Ricerca(char parola[]){       
    int contatore = 0;
    char lettera;
    printf("Inserisci una lettere da cercare\n");
    scanf("%s",&lettera);

    for (int i = 0; i < strlen(parola); i++)
    {
        if (parola[i]==lettera)
        {
            contatore++;
        }
    }

    printf("la lettera compare %d volte\n", contatore);
}
void Doppie(char parola[]){
    int doppie=0;
    for(int i=0; i<strlen(parola); i++){
        if(parola[i]==parola[i+1]){
            doppie++;
        }
        
    }
    if(doppie>0){
            printf("Sono presenti delle doppie\n");
        }else{
            printf("Non sono presenti dopppie\n");
        }
}
void Pari_Dispari(char parola[], char pari[], char dispari[]){
    for (int i = 0; i < strlen(parola); i++)
    {
        if ((i%2)==0)
        {
            strncat(pari, &parola[i], 1);

        }else{
             strncat(dispari, &parola[i], 1);

        }
       
    }
    printf("Ecco la stringa con le posizioni pari: %s\n", pari);
    printf("Ecco la stringa con le posizioni dispari: %s\n", dispari);


}

void Corta_Lunga(char parola[], char parola2[]){
    int lung=strlen(parola);
    int lung2=strlen(parola2);

    if(lung>lung2){
        printf("la stringa iniziale è più lunga della stringa appena inserita\n");
    }else if(lung2>lung){
         printf("la stringa appena inserita è più lunga della stringa iniziale\n");

    }else{
        printf("le due stringhe hanno la stessa lunghezza\n");
    }

}
int contaVocali(char parola[])
{
    int cnt = 0;
    for (int i = 0; i < strlen(parola); i++)
    {
        if (parola[i] == 'a' || parola[i] == 'e' || parola[i] == 'i'
            || parola[i] == 'o' || parola[i] == 'u')
        {
            cnt++;
        }
    }

    return cnt;
}

int contaConsonanti(char parola[])
{
    int cnt = 0;
    for (int i = 0; i < strlen(parola); i++)
    {
        if (parola[i] != 'a' || parola[i] != 'e' || parola[i] != 'i'
            || parola[i] != 'o' || parola[i] != 'u')
        {
            cnt++;
        }
    }

    return cnt;
}

 void ContaStesseLettere(char parola[], char parola2[]){
    for(int i=0; i<strlen(parola); i++){
        for(int j=0; j<strlen(parola2); j++){
            if(parola[i]==parola2[j]){
                printf("%c", parola[i]);
            }
        }

    }


}

int main()
{
    char stringa[100], stringa2[100], pari[100], dispari[100];
    int scelta;
    
    printf("Inserisci una stringa: ");
    scanf("%s", stringa); 

    if(SoloLettere(stringa)>0){
        printf("Sono presenti dei numeri nella stringa.\n");

    }else{

    do 
    {
        printf("\n---------------------------MENU' DI SCELTA----------------------------\n");
        printf("--> 1 Sapere il numero di consonanti e vocali nella parola.\n");
        printf("--> 2 Per ricercare una lettera nella parola precedente.\n");
        printf("--> 3 Per sapere se sono presenti doppie nella parola.\n");
        printf("--> 4 Per creare stringhe che contengano 1 le lettere di posizione pari, \nla 2° le lettere di posizione dispari.\n");
        printf("--> 5 Per sapere quale delle due stringhe è più corta o più lunga.\n");
        printf("--> 6 Per sapere quali sono le lettere contenute in ambedue le stringhe.\n");
        printf("--> 7 Per sapere quale delle 2 stringhe contiene più vocali.\n");
        printf("--> 8 Per sapere quale delle 2 stringhe contiene più consonanti.\n");
        scanf("%d", &scelta);
        printf("\n");
    } while (scelta < 1 || scelta > 8);     //valori accettati sono dall' uno al nove che sonon le possibili scelte del menù


        switch (scelta)
    {
        case 1:
            Vocali_Consonanti(stringa);
            break;
        case 2:
            Ricerca(stringa);
            break;
        case 3:
            Doppie(stringa);           
            break;
        case 4: 
        Pari_Dispari(stringa, pari, dispari);
          
            break;
        case 5:
            printf("Inserisci un' altra stringa: \n");
            scanf("%s", stringa2); 
            Corta_Lunga(stringa, stringa2);           
            break;
        case 6:
            printf("Inserisci un' altra stringa: \n");
            scanf("%s", stringa2); 
            printf("Ecco le lettere contenute in entrambe le stringhe: \n");
            ContaStesseLettere(stringa,stringa2);
                
            break;
        case 7:
            printf("Inserisci un' altra stringa: \n");
            scanf("%s", stringa2);

            if(contaVocali(stringa)>contaVocali(stringa2))
            {
                printf("La prima stringa ha più vocali.\n");
            }else if(contaVocali(stringa)<contaVocali(stringa2)){
                printf("la seconda stringa ha più vocali.\n");

            }else{
                printf("Le due stringhe hanno lo stesso numero di vocali.\n");
            }

            break;
        case 8:
            printf("Inserisci un' altra stringa: \n");
            scanf("%s", stringa2);

            if(contaConsonanti(stringa)>contaConsonanti(stringa2))
            {
                printf("La prima stringa ha più consonanti.\n");
            }else if(contaConsonanti(stringa)<contaConsonanti(stringa2)){
                printf("la seconda stringa ha più consonanti.\n");

            }else{
                printf("Le due stringhe hanno lo stesso numero di consonanti.\n");
            }

            break;
        default:
            break;
    }

        
}
    return 0;
}