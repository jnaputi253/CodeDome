#ifndef PERSON_H_
#define PERSON_H_

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

typedef struct {
	char *firstName;
	char *lastName;
} Person;

Person * init();

char * getName(char *prompt);

void cleanPerson(Person *p);

#endif

