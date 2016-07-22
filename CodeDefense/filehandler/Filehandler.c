#include "Filehandler.h"

FileHandler * initHandler() {
    return (FileHandler *)calloc(1, sizeof(FileHandler));
}

void getInputFile(FileHandler * handler) {
    char buff[200];
    char extension[5];
    int repeat = 1;
    
    while(repeat) {
        printf("Enter your input file: ");
        fgets(buff, 200, stdin);
        
        int offset = strlen(buff) - 4;
        strncpy(extension, (buff + offset), 3);
        
        int result = strcmp(extension, "txt");
        
        printf("Extension: %s\n", extension);
        if(result == 0) {
            printf("It is a text file\n");
            strncpy(handler->inputFile, buff, strlen(buff));
            printf("Copy done\n");
            repeat = 0;
        } else {
            printf("It is not a text file\n");
            buff[0] = '\0';
            extension[0] = '0';
        }
    }
}

void getOutputFile(FileHandler * handler) {
    char buff[200];
    char extension[5];
    int repeat = 1;
    
    while(repeat) {
        printf("Enter your output file: ");
        fgets(buff, 200, stdin);
        
        int offset = strlen(buff) - 4;
        strncpy(extension, (buff + offset), 3);
        
        int result = strcmp(extension, "txt");

        if(result == 0) {
            strncpy(handler->outputFile, buff, strlen(buff));
            repeat = 0;
        } else {
            printf("It is not a text file\n");
            buff[0] = '\0';
            extension[0] = '0';
        }
    }
}
