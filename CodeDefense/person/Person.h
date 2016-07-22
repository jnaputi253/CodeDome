#ifndef PERSON_H_
#define PERSON_H_

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

typedef struct {
	char firstName[50];
	char lastName[50];
} Person;

Person * init();

void getFirstName(Person *person);

void getLastName(Person *person);

char * clearArray(char *array, int size);

#endif

