#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct card
{
    int pos;
} card;


// swaps two charcters
void swap(int *a, int *b)
{
    int tmp = *a; 
    *a = *b; 
    *b = tmp;
}

// randomises the member pos of struct card. 
void randomise_struct(card *cards, int n)
{
    int tmp;
    printf("%d",n);
    int num = 10;

    for(int i = 0; i < 10; i++)
    {
        printf("%d", cards[i].pos);
    }
    
    srand(time(NULL));
    for (int i = n- 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&(cards[i].pos), &(cards[j].pos));
        //swap(cards[i].pos, cards[j].pos);
        /*
        tmp = cards[i].pos;
        cards[i].pos = cards[j].pos;
        cards[j].pos = tmp; 
    */
    }
}


int main(void)
{
    card cards[10];
    
    for(int i = 0; i < 10; i++)
    {
        cards[i].pos = i;
        printf("%d", cards[i].pos);
    }
    printf("\n*******************\n");

    int size = sizeof(cards) / sizeof(card);
    
    printf("%d", size);
    printf("\n*******************\n");
    randomise_struct(cards, size);
    printf("\n*******************\n");
    
    for(int i = 0; i < 10; i++)
    {
        printf("%d", cards[i].pos);
    }


} 
