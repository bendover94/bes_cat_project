#ifndef MISC_H_
#define MISC_H_

void error_exit(char *error_message); 
void error_exit_file(char *fileName)

typedef struct card
{
    int pos;
    int state;
    char fileName[10]; 
}card;


#endif
