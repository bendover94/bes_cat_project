#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "misc.h"
#include <time.h>


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

// check input
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

// error function 
// source: Rheinwerk Computing: C von A bis Z
void error_exit(char *error_message) {
    fprintf(stderr, "%s: %s\n", error_message, strerror(errno));
    exit(EXIT_FAILURE);
}

// not used 
// error function in respect to files 
/*
void error_exit_file(char *fileName)
{
    fprintf(stderr, "error: opening file %s: %s: %s\n", fileName, strerror(errno));
    exit(EXIT_FAILURE);
}
*/