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

char * getFile(FileHandler *fh, char * prompt);

int matchCheck(FileHandler *fh, char *file);

int hasPath(char *input);

int validateFile(char *filename);

void clear(char *buffer, char *extension);

void cleanFile(FileHandler *fh);

#endif
