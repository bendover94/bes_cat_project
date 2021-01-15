// source: Rheinwerk Computing: C von A bis Z
//http://openbook.rheinwerk-verlag.de/c_von_a_bis_z/025_c_netzwerkprogrammierung_006.htm##mja8101c6e0e4cb2e6fd8312114dad30d7

#include <string.h>
#include <time.h>
#include "socketprx.h"
#include "file_io.h"
#include "misc.h"

#define BUF 1024

void randomise_struct(card *card, int n);
void swap(int *a, int *b);
void display_board(card *cards);
int check_input(int index, card *card);

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

// randomises the member pos of struct card. 
void randomise_struct(card *card, int n)
{
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&(card[i].pos), &(card[j].pos));
    }
}

// swaps two charcters
void swap(int *a, int *b)
{
    int tmp = *a; 
    *a = *b; 
    *b = tmp;
}

// Dosplays the positions of all cards on the screen 
void display_board(card *cards)
{
    printf("THIS IS A SAMPLE BOARD");
    printf("+---+---+---+---+---+\n");
    printf("|");
    for (int i = 0; i < 5; i++)
    {
        printf(" %d |", cards[i].pos);
    }
    printf("\n");
    printf("+---+---+---+---+---+\n");
    for (int i = 4; i < 10; i++)
    {
        printf(" %d |", cards[i].pos);
    }    
    printf("\n");
    printf("+---+---+---+---+---+\n");
}

int check_input(int index, card *card)
{
    int check = 0; 
    for (int i = 0; i < 10; i++)
    {
        if (card[i].pos == index && card[i].state == 1)
        {
            check = 1; 
            break; 
        }        
    }
    return check;
}
