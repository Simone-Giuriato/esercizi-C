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

#define DIM 512
#define SERVERPORT 1313

int Occorrenze(char stringa[], char car[]){
    int cnt=0;
    
    for(int i=0;i<strlen(stringa);i++){
        if(stringa[i]==car[0]){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    struct sockaddr_in servizio, addr_remoto;// record con i dati del server e del client
    int socketfd, soa, fromlen=sizeof(servizio);
    char str[DIM];
    char carattere[1];
    int contatore=0;
    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY); 
    servizio.sin_port=htons(SERVERPORT);

    socketfd=socket(AF_INET,SOCK_STREAM,0);
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    listen(socketfd,10);

    while(1){
        printf("Server in ascolto...");
        fflush(stdout);
        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);

        read(soa,str,DIM);
        printf("Stringa: %s\n", str);

        read(soa,carattere,1);
        printf("Carattere da cercare: %c\n", carattere[0]);

        contatore=Occorrenze(str,carattere);
       

    
        printf("Il carattere si ripete %d volte",contatore);

        write(soa,&contatore,sizeof(int));
   

        

        close(soa);
    }
    return 0;
}
