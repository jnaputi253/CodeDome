#include <stdio.h>
#include <stdlib.h>
#include "person/Person.h"
#include "number/Number.h"
#include "filehandler/Filehandler.h"

void cleanup(Person *me, Number *num, FileHandler *fh);

int main() {
	Person *me = init();
    /* 
    This stuff works fine.  But I had to comment it out to not make your compiler complain.
    If it does somehow, I'm sorry ;-;
    
    me->firstName = getName("Enter your first name: ");
    me->lastName = getName("Enter your last name: ");
    
    printf("Name: %s %s\n", me->firstName, me->lastName);
    */
    
    Number *number = initNumbers();
    number->firstNumber = getNumber("Enter your first number: ");
    number->secondNumber = getNumber("Enter your second number: ");
    
    printf("First Number: %d\n", number->firstNumber);
    printf("Second Number: %d\n", number->secondNumber);
    
    // TODO: work on the add function and assign to a number
    // TODO: work on the multiply function and assign to a number
    
    FileHandler *handler = initHandler();
    handler->inputFile = getFile("Enter your input file: ");
    handler->outputFile = getFile("Enter your output file: ");
    
    
    printf("\nInput File: %s\n", handler->inputFile);
    printf("Output File: %s\n", handler->outputFile);
    
    free(me);
    free(number);
    free(handler);

	return 0;
}

void cleanup(Person *me, Number *num, FileHandler *fh) {
    if(me != NULL) {
        // The below is fine.  I just needed to block this since no mem is allocated.
        // free(me->firstName);
        // free(me->lastName);
        free(me);
        me = NULL;
    }
    
    if(num != NULL) {
        free(num);
        num = NULL;
    }
    
    if(fh != NULL) {
        free(fh);
        free(fh->inputFile);
        free(fh->outputFile);
        fh = NULL;
    }
}
