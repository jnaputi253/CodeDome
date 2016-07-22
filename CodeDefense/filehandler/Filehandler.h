#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char inputFile[200];
    char outputFile[200];
} FileHandler;

FileHandler * initHandler();

void getInputFile(FileHandler *handler);

void getOutputFile(FileHandler *handler);

char * getExtension(char *buff, int offset);

#endif
