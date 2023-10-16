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

#define DIM 512
#define SERVERPORT 1313   //indica la porta usata (furoi dalla 1024) porta uguale sia su server e client


int main()
{
    struct sockaddr_in servizio, addr_remoto;// record con i dati del server e del client, indirizzo server poi quello del client 
    int socketfd, soa, fromlen=sizeof(servizio);  //di solito ci sono sempre
    char str[DIM];  
    // definizione dei dati del socket pg114 libro
    servizio.sin_family=AF_INET;  //DA QUI
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    // impostazione del transport endpoint del server
    socketfd=socket(AF_INET,SOCK_STREAM,0);   
    // leghiamo l'indirizzo al transport endpoint
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));  //A QUI è fissa  parte di bind a pg.164
    // poniamo il server in ascolto delle richieste dei client 
    listen(socketfd,10);// pu� attendere fino a 10 client pg.164
    // ciclo infinito perchè così il server è sempre in ascolto  andrebbe con while true{}
    while(1)
    {
        printf("\n\nServer in ascolto...");

        fflush(stdout);   //pulisce il buffer/canale di comunicazione così non ci sono dati che non centrano

        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);   //accetta la connsesione pg.165
        //legge dal client
        read(soa,str,sizeof(str)); //legge l'accettazione soa   pg.167
        for(int i=0; i<strlen(str);i++){
          str[i]=toupper(str[i]);   //mette a maisucolo
        }
       
        
        printf("Stringa ricevuta: %s\n",str);
       
        close(soa); //chiusura file descriptor associato alla connesione nell'accettazione

     }
      
   return 0;
    
}
