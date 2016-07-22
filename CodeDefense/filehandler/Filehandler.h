#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    char *inputFile;
    char *outputFile;
} FileHandler;

FileHandler * initHandler();

char * getFile(char * prompt);

int validateFile(char *filename);

#endif
