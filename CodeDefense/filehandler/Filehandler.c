#include "Filehandler.h"

FileHandler * initHandler() {
    return (FileHandler *)calloc(1, sizeof(FileHandler));
}

char * getFile(char * prompt) {
    char buff[200];
    char extension[5];
    int repeat = 1;
    
    while(repeat) {
        printf("%s", prompt);
        fgets(buff, 200, stdin);
        
        int offset = strlen(buff) - 4;
        strncpy(extension, (buff + offset), 3);
        
        int result = strcmp(extension, "txt");
        
        if(result == 0) {
            if(validateFile(buff) == 0) {
                repeat = 0;
            } else if(validateFile(buff) == -1) {
                printf("The file does not exist\n");
            }
        } else {
            printf("Please enter a text file (.txt) only\n");
            buff[0] = '\0';
            extension[0] = '0';
        }
    }
    
    
    char *filename = (char *)calloc(strlen(buff) - 1, sizeof(char));
    strncpy(filename, buff, strlen(buff) - 1);
    return filename;
}

int validateFile(char *filename) {
    char *file = (char *)calloc(strlen(filename) - 1, sizeof(char));
    strncpy(file, filename, strlen(filename) - 1);
    
    int result;
    FILE *fp = fopen(file, "r");
    
    if(fp != NULL) {
        result = 0;
    } else if(fp == NULL) {
        result = -1;
    }
    
    fclose(fp);
    return result;
}

void cleanFile(FileHandler *fh) {
    if(fh != NULL) {
        free(fh->inputFile);
        free(fh->outputFile);
        free(fh);
        fh = NULL;
    }
}
