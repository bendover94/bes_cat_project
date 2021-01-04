#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>


#define BUF 1024
#define MASSAGELEN 1024
#define PORT 1234

static void error_exit(char *errorMessage); 

int main(int argc, char **argv)
{
    struct sockaddr_in server; 
    struct hostent *host_info; 
    unsigned long addr; 

    int sock; 

    char *echoString; 
    int echoLen; 

    if(argc < 3)
        error_exit("ERROR: missing commandline args"); 

    sock = socket(AF_INET, SOCK_STREAM, 0); 
    if(sock < 0)
        error_exit("ERROR: failed creating socket"); 

    memset(&server, 0, sizeof(server)); 
    if((addr = inet_addr(argv[1])) != INADDR_NONE) {
        memcpy((char *)&server.sin_addr, &addr, sizeof(addr)); 
    }
    else {
        host_info = gethostbyname(argv[1]); 
        if(host_info == NULL)
            error_exit("ERROR: unknown server");
        memcpy((char*)&server.sin_addr, 
                host_info->h_addr, host_info->h_length); 
    }
    server.sin_family = AF_INET; 
    server.sin_port = htons(PORT); 

    //connect to server
    if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0)
        error_exit("ERROR: could not establish connection to server"); 

    echoString = argv[2]; 
    echoLen = strlen(echoString); 
    
    //send message to server
    if(send(sock, echoString, echoLen, 0) != echoLen)
        error_exit("send wrong number of bytes"); 

    close(sock); 
    
    return EXIT_SUCCESS; 
}

static void error_exit(char *errorMessage) {
    fprintf(stderr, "%s: %s\n", errorMessage, strerror(errno));
    exit(EXIT_FAILURE); 
}

