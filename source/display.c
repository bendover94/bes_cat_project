#include <string.h>
#include <time.h>
#include "socketprx.h"
#include "file_io.h"
#include "misc.h"
#include "display.h"


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