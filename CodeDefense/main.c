#include <stdio.h>
#include <stdlib.h>
#include "person/Person.h"
#include "number/Number.h"
#include "filehandler/Filehandler.h"
#include "password/Password.h"

void writeData(Person *p, Number *n, Password *pw, FileHandler *fh);
void writeDataFromInputFile(FileHandler *fh);

int main() {
	Person *me = init();
    me->firstName = getName("Enter your first name: ");
    me->lastName = getName("Enter your last name: ");
    
    Number *number = initNumbers();
    number->firstNumber = getNumber("Enter your first number: ");
    number->secondNumber = getNumber("Enter your second number: ");
    
    FileHandler *handler = initHandler();
    handler->inputFile = getFile("Enter your input file: ");
    handler->outputFile = getFile("Enter your output file: ");
    
    Password *password = passwordInit();
    password->pw1 = getPassword(password, "Enter password: ");
    password->pw2 = getPassword(password, "Enter matching password: ");
    
    comparePasswords(password);
    
    writeData(me, number, password, handler);
    writeDataFromInputFile(handler);
    
    cleanPerson(me);
    printf("Person cleaned\n");
    cleanNumber(number);
    printf("Number cleaned\n");
    cleanFile(handler);
    printf("File cleaned\n");
    cleanPassword(password);
    printf("Password cleaned\n");

	return 0;
}

void writeData(Person *p, Number *n, Password *pw, FileHandler *fh) {
    FILE *fp = fopen(fh->outputFile, "w+");
    
    fputs(p->firstName, fp);
    fputs(p->lastName, fp);
    fprintf(fp, "%d", n->firstNumber);
    fputs("\n", fp);
    fprintf(fp, "%d", n->secondNumber);
    fputs("\n", fp);
    
    fprintf(fp, "%d + %d = %d\n", n->firstNumber,
            n->secondNumber, add(n->firstNumber, n->secondNumber));
    
    fprintf(fp, "%d * %d = %d\n", n->firstNumber,
            n->secondNumber, multiply(n->firstNumber, n->secondNumber));
    
    fputs(pw->pw1, fp);
    fputs("\n", fp);
    fputs(pw->pw2, fp);
    fputs("\n", fp);
    
    fclose(fp);
    
    printf("Successfully written to file\n");
}

void writeDataFromInputFile(FileHandler *fh) {
    FILE *fin = fopen(fh->inputFile, "r");
    FILE *fout = fopen(fh->outputFile, "a");
    
    char line[100];
    printf("Set the array\n");
    
    while((fgets(line, 100, fin) != NULL)) {
        fputs(line, fout);
    }
    
    fclose(fin);
    fclose(fout);
    
    printf("Successfully written to file\n");
}
