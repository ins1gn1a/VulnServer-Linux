#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 

void printresponse(char *str){
    char buffer[728];
    strcpy(buffer,str);
}

void printresponse2(char *str){
    char buffer[60];
    strcpy(buffer,str);
}

int main(int argc, char *argv[])
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr; 

    char sendBuff[1025];
    time_t ticks; 
    char client_message[2000];

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(8080); 

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    listen(listenfd, 10); 
    puts("Waiting for incoming connections...");

    while(1)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 
        write(connfd , "[i] Welcome! Type HELP for commands.\n" , 37);

        while( (recv(connfd , client_message , 2000 , 0)) > 0 )
            {
                if (strncmp(client_message, "HELP", 4) == 0){
                        printresponse2(client_message);
                        write(connfd, "[i] Available Commands:\nHELP\nTIME\nEXIT\n\n", 39); 
                }
                else if (strncmp(client_message, "TIME", 4) == 0){
                    
                    printresponse(client_message);
                    //Send the message back to client
                    ticks = time(NULL);
                    snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));
                    write(connfd, sendBuff, strlen(sendBuff)); 

                }
                
                else if (strncmp(client_message, "EXIT", 4) == 0){
                        write(connfd, "[i] Bye\n", 8); 
                        close(connfd);
                }
                
                else{
                    write(connfd, "[i] Available Commands:\nHELP\nTIME\nEXIT\n\n", 39); 
                }
            }
   
    }
}
