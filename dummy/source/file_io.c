#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_io.h"
#include "misc.h"

void test_file_io()
{
    printf("hello from file_io\n");
}

/*
// writes settings to the array of cards, including filename, gamestate, and board position 
// used to set and reset the board 
void write_setup(card *card)
{
    FILE *fp;
    fp = fopen("../client_data/setup.txt", "r");
    if (fp == NULL)
    {
        error_exit("ERROR: opening file");
    }
    else
    {
        printf("opened settings file \n");
    }

    for (int i = 0; i < 10; i++)
    {
        fscanf(fp, "%d, %d, %s", &card[i].pos, &card[i].state, card[i].fileName);
    }
    fclose(fp);
}

void write_client_picture_file(char *buffer, card *card, int index)
{
    FILE *fp;
    char path[] = CLIENT_FILE_PATH;
    strcat(path, card[index].fileName);
    fp = fopen(path, "w");
    if (fp == NULL)
    {
        error_exit_file(card[index].fileName);
    }
    fprintf(fp, buffer);
    fclose(fp);
}

// reads picture file, clientside (smaller function, might be changed to read_file_from_server() funktion )
void read_picture_file(char *buffer, card card)
{
    FILE *fp;
    char path[] = CLIENT_FILE_PATH;
    strcat(path, card.fileName);

    fp = fopen(path, "r");
    if (fp == NULL)
    {
        error_exit("ERROR: opening picture file");
    }
    else
    {
        printf("opened picture file \n");
    }

    fscanf(fp, "%s", buffer);
    fclose(fp);
}

// returns the size of a file that is stored in the card
int check_filesize(card card)
{
    int fileSize = 0;
    FILE *fp;
    fp = fopen(card.fileName, "r");
    if (fp == NULL)
    {
        error_exit("ERROR: opening picture file");
    }
    else
    {
        printf("opened picture file \n");
    }
    fseek(fp, 0, SEEK_END);
    fileSize = ftelll(fp);

    fclose(fp);
    return fileSize;
}

// reads the picture file on the server 
void read_file_from_server(char *sendBuffer, char index)
{
    char path[] = SERVER_FILE_PATH;
    char fileName[] = "file0.txt";
    fileName[4] = index;
    strcpy(path, fileName);
    long length;

    FILE *fp = fopen(fileName, "r");
    // Check if there was an error.
    if (fp == NULL)
    {
        error_exit_file(path);
    }
    // Get the file length
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    // Create the string for the file contents.
    char *readBuffer = malloc(sizeof(char) * (length + 1));
    readBuffer[length] = '\0';
    fread(readBuffer, sizeof(char), length, fp);
    strcpy(sendBuffer, readBuffer);

    fclose(fp);
    free(readBuffer);
}
*/