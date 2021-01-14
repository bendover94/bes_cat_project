// source: Rheinwerk Computing: C von A bis Z
//http://openbook.rheinwerk-verlag.de/c_von_a_bis_z/025_c_netzwerkprogrammierung_006.htm##mja8101c6e0e4cb2e6fd8312114dad30d7

#include <stdio.h>
#include <string.h>
#include "socketprx.h"
#include "misc.h"
#include "file_io.h"
#define BUF 1024

int main (void) {
    socket_t sock1, sock2;
    //int addrlen;
    char *sendBuffer = (char*) malloc (BUF);
    char *recvBuffer = (char*) malloc (BUF);
    char index;

    sock1 = create_socket(AF_INET, SOCK_STREAM, 0);
    atexit(cleanup);
    bind_socket( &sock1, INADDR_ANY, 15000 );
    listen_socket (&sock1);
    //addrlen = sizeof (struct sockaddr_in);

    while (1) {
        accept_socket( &sock1, &sock2 );
        do {
            recvBuffer[0] = '\0';

            printf("waiting for message\n"); 
            TCP_recv (&sock2, recvBuffer, BUF-1);
            if(recvBuffer[0] >= '0' && recvBuffer[0] <= '9')
            {
                index = recvBuffer[0];
            } 
            printf("received message: %s", recvBuffer);

            read_file_from_server(sendBuffer, index);

            TCP_send (&sock2, sendBuffer, strlen (sendBuffer));
            printf ("Nachricht gesendet: %s\n", sendBuffer);
        } while (strcmp (recvBuffer, "quit\n") != 0);
        close_socket (&sock2);
    }
    close_socket (&sock1);
    return EXIT_SUCCESS;
}  






