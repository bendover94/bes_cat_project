#ifndef MISC_H_
#define MISC_H_

typedef struct card_
{
    int pos;
    int state;
    char fileName[10]; 
}card;

void randomise_struct(card *card, int n);
void swap(int *a, int *b);
int check_input(int index, card *card);
void error_exit(char *error_message); 
void error_exit_file(char *fileName);


#endif
