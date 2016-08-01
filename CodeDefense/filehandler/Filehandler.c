#include "Filehandler.h"

FileHandler * initHandler() {
    return (FileHandler *)calloc(1, sizeof(FileHandler));
}

char * getFile(FileHandler *fh, char * prompt) {
    char buff[50];
    char *extension;
    int repeat = 1;
    
    while(repeat) {
        printf("%s", prompt);
        fgets(buff, 50, stdin);
        
        if(!hasPath(buff)) {
		     char *dot = strrchr(buff, '.');
		     if(dot)
		     {
		     		extension = dot + 1;
		     }

		     int result = strcmp(extension, "txt\n");
		     
		     if(result == 0) {
		 		   if(matchCheck(fh, buff) == 0) {
		 		   	if(validateFile(buff) == 0) {
		 		   	   repeat = 0;
		 		   	} else if(validateFile(buff) == -1) {
		 		   	   printf("The file does not exist\n");
		 		   	}
		 		   } else if(matchCheck(fh, buff) == -1) {
		 		      printf("The input file and output file cannot be the same\n");
		 		      clear(buff, extension);
		 		   }
		     } else {
		         printf("Text file (.txt) only\n");
		         clear(buff, extension);
		     }
        } else {
        	printf("Path input not allowed.  File must be in the directory\n\n");
        	clear(buff, extension);
        }
    }
    
    
    char *filename = (char *)calloc(strlen(buff) - 1, sizeof(char));
    strncpy(filename, buff, strlen(buff) - 1);
    return filename;
}

int matchCheck(FileHandler *fh, char *file) {
	char *temp = (char *)calloc(strlen(file) - 1, sizeof(char));
	strncpy(temp, file, strlen(file) - 1);
	
	if(fh->inputFile != NULL) {
		if(strcmp(fh->inputFile, temp) == 0) {
			return - 1;
		}
	}
	
	return 0;
}

int hasPath(char *input) {
	int result = 0;
	
	int i;
	for(i = 0; i < strlen(input); i++) {
		if(input[i] == '\\' || input[i] == '/') {
			result = 1;
		}
	}
	
	return result;
}

int validateFile(char *filename) {
    char *file = (char *)calloc(strlen(filename) - 1, sizeof(char));
    strncpy(file, filename, strlen(filename) - 1);
    
    int result;
    FILE *fp = fopen(file, "r");
    
    if(fp != NULL) {
        result = 0;
        fclose(fp);
    } else if(fp == NULL) {
        result = -1;
    }
    
    return result;
}

void clear(char *buffer, char *extension) {
	buffer[0] = '\0';
	extension[0] = '\0';
}

void cleanFile(FileHandler *fh) {
    if(fh != NULL) {
        free(fh->inputFile);
        free(fh->outputFile);
        free(fh);
        fh = NULL;
    }
}
