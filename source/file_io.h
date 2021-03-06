#ifndef FILE_IO_H_
#define FILE_IO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misc.h"


//static const char* CLIENT_FILE_PATH = "../client_data/";
//static const char* SERVER_FILE_PATH = "../server_data/";
//static const char* SETUP_FILE = "../client_data/setup.txt";
//static const char* CARD_FORMAT_IN = "%d, %d, %s";
//static const char* CARD_FORMAT_OUT = "%d, %d, %s";


int check_filesize(card card);
void read_setup_file (card *card);
void read_picturefile(char *buffer);
void read_file_from_server(char *sendBuffer, char index);
void write_setup(card *card);
void write_client_picture_file(char *buffer, card *card, int index);


#endif
