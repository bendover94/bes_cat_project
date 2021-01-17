// source: Rheinwerk Computing: C von A bis Z
//http://openbook.rheinwerk-verlag.de/c_von_a_bis_z/025_c_netzwerkprogrammierung_006.htm##mja8101c6e0e4cb2e6fd8312114dad30d7

#include <string.h>
#include <time.h>
#include "socketprx.h"
#include "file_io.h"
#include "misc.h"
#include "display.h"

#define BUF 1024

int main (int argc, char *argv[]) {
    socket_t sock;
    char *sendBuffer = (char*)malloc(BUF);
    char *recvBuffer = (char*)malloc(BUF);

    if( argc < 2 ){
        printf("Usage: %s ServerAdresse\n", *argv);
        exit(EXIT_FAILURE);
    }

    sock = create_socket(AF_INET, SOCK_STREAM, 0);
    atexit(cleanup);
    connect_socket(&sock, argv[1], 15000);

    card cards[10]; 

    write_setup(cards);
    randomise_struct(cards, (sizeof(cards)/ sizeof(card)));

    do {
        recvBuffer[0] = '\0';
        fgets (sendBuffer, BUF, stdin);
        TCP_send (&sock, sendBuffer, strlen (sendBuffer));
        printf("send message: %s", sendBuffer);
        TCP_recv (&sock, recvBuffer, BUF-1);
        
        int index = (int)*sendBuffer;
        write_client_picture_file(recvBuffer, cards, index);

        printf("received message: %s", recvBuffer);

    } while (strcmp (sendBuffer, "quit\n") != 0);
    close_socket (&sock);
    return EXIT_SUCCESS;
}