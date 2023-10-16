#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>

int Palindroma(char stringa[]){
    int i,j=0;
    
    for(i=0;i<strlen(stringa);i++){
        if (stringa[i] != stringa[strlen(stringa) - 1 - i])
        {
           return -1;
        }
        return 1;
        
    }
}
#define DIM 100
#define SERVERPORT 1313   //indica la porta usata (furoi dalla 1024) porta uguale sia su server e client

int main(){
    int risposta=0;
    struct sockaddr_in servizio, addr_remoto;// record con i dati del server e del client
    int socketfd, soa, fromlen=sizeof(servizio);
    char str[DIM],newstr[DIM];
    // definizione dei dati del socket 
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    // impostazione del transport endpoint del server
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    // leghiamo l'indirizzo al transport endpoint
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    // poniamo il server in ascolto delle richieste dei client 
    listen(socketfd,10);// può attendere fino a 10 client

    while(1){
        printf("Server in ascolto...");
        fflush(stdout);
        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);

       read(soa,str,sizeof(str));      //Legge dal client
             
        if(Palindroma(str)>0){
            printf("La stringa è palindroma\n");
            
            write(soa, "Stringa palindroma\n", 19);
        
        }else{
            printf("La stringa NON è palindroma\n");
           
            write(soa, "La stringa NON è palindroma\n", 29 );

        }
       close(soa);
    }
   return 0;
}