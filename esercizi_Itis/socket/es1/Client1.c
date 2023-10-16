#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h> //definiscono la struttura degli indirizzi e funzioni del tip ntohl pg.161--> ci fa la struct nel libro
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>     //stesse librerie del server

#define DIM 512     //costante per la stringa che uso nel programma
#define SERVERPORT 1313     //porta uguale al server

int main(int argc,char** argv)
{   
    struct sockaddr_in servizio;    //stessa struct pg.161
    int socketfd;       //identificativo per la creazione della socket
    char str1[DIM];
    // definizione dei dati del socket pg114 libro
    servizio.sin_family=AF_INET;            //questi 3 cose azzurrine sono nella struct sockaddr_in servizio
    servizio.sin_addr.s_addr=htonl(INADDR_ANY); //INADDR_ANY qualsiasi indirizzo, posso mettere inet_addre("127.0.0.0") che è localhost pg.161/162
    servizio.sin_port=htons(SERVERPORT);    
    // impostazione del transport endpoint del server
    socketfd=socket(AF_INET,SOCK_STREAM,0);     //creazione socket pg.163

    connect(socketfd,(struct sockaddr*)&servizio,sizeof(servizio)); 
    
    printf("Inserisci la stringa\n");
    scanf("%s",str1);
    write(socketfd,str1,sizeof(str1));  //la scrivo sulla socket mandandola al server  pg.167
    
    
    
    close(socketfd);    //chiudo socket

    return 0;
}
