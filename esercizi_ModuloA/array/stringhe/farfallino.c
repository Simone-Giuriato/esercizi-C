/*
Il programma deve svolgere le seguenti operazioni:
- Visualizzare la parola inserita e la sua lunghezza;
- Costruire una nuova parola in cui tutte le vocali siano sostituite con 3 caratteri: la vocale + carattere ‘f’ + la vocale;
- Il programma deve memorizzare la nuova parola in una opportuna variabile;
- Visualizzare la nuova parola e la sua lunghezza.

Esempio:
“ciao” -> “cifiafaofo”
“casa” -> “cafasafa”
*/

#include <stdio.h>
#include <string.h>

#define DIM 101

int main(){
    char str[DIM], str2[DIM];
    int lunghezza=0, i=0, j=0;

    printf("Inserisci una parola (massimo 100 caratteri): ");
    scanf("%s",str);

    lunghezza=strlen(str);

    for(i=0; i<lunghezza; i++){
        if(str[i]=='a' ||str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u'){
            str2[j++]=str[i];       //aumento un altro contatore perchè nella nuova stringa devo scalare aggiungendo nuove cose che nella stringa iniziale non c'erano
            str2[j++]='f';
            str2[j++]=str[i];
        }else{
            str2[j++]=str[i];
        }
    }

    str2[j]='\0';  //aggiungo terminatore alla fine 

    lunghezza=strlen(str2);

    printf("Parola: %s, di lunghezza: %d\n",str2, lunghezza);

}