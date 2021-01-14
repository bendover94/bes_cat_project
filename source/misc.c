#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "misc.h"

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