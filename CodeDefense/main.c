#include <stdio.h>
#include <stdlib.h>
#include "person/Person.h"
#include "number/Number.h"
#include "filehandler/Filehandler.h"

int main() {
	Person *me = init();
	getFirstName(me);
	getLastName(me);
    
    Number *number = initNumbers();
    readFirstNumber(number);
    readSecondNumber(number);
    
    // TODO: work on the add function and assign to a number
    // TODO: work on the multiply function and assign to a number
    
    FileHandler *handler = initHandler();
    getInputFile(handler);
    getOutputFile(handler);
    
    printf("Input File: %s\n", handler->inputFile);
    printf("Output File: %s\n", handler->outputFile);
    
    free(me);
    free(number);
    free(handler);

	return 0;
}

