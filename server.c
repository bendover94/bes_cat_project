#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 1234
#define RCVBUF 1024

// 
static void echo(int); 

// Handle error messages
static void error_exit(char *errorMessage); 

// output client messege
static void echo(int client_socket);


int main(int argc, char ** argv)
{
	//"Systax for binding socket"
	//"int bind (int s, const struct sockaddr name, int namelen);

    struct sockaddr_in server, client; 
    int sock, fd;  

    unsigned int len; 

    // crate socket
    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); 
    if(sock < 0)
        error_exit("ERROR: could not create socket"); 

    memset(&server, 0, sizeof(server)); 
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY); 
	server.sin_port = htons (PORT);
	
    // bind to serveradress
    if(bind(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
        error_exit("ERROR: could not bind socket"); 

    if(listen(sock, 5) == -1)
        error_exit("ERROR: problem while listen"); 

    printf("Server ready: waiting for connections..\n"); 

    for(;;) {
        len = sizeof(client); 
        fd = accept(sock, (struct sockaddr*)&client, &len); 
        if(fd < 0)
            error_exit("error accepting");
        printf("working. clientaddress: %s\n", inet_ntoa(client.sin_addr)); 
        echo(fd); 

        close(fd); 
    }
    return EXIT_SUCCESS; 
}



static void error_exit(char *errorMessage)
{
    fprintf(stderr, "%s: %s\n", errorMessage, strerror(errno)); 

    exit(EXIT_FAILURE); 
}


static void echo(int client_socket) {
    char echoBuffer[RCVBUF]; 
    int recvSize; 
    time_t runTime; 

    if((recvSize = recv(client_socket, echoBuffer, RCVBUF, 0)) < 0)
        error_exit("ERROR: receiving from recv()"); 

    echoBuffer[recvSize] = '\0'; 
    time(&runTime); 

    printf("Message from Client: %s \t%s", echoBuffer, ctime(&runTime)); 
}


