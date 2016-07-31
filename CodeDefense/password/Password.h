#ifndef PASSWORD_H_
#define PASSWORD_H_

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <crypt.h>

typedef struct {
    char *pw1;
    char *pw2;
} Password;

Password * passwordInit();

char * getPassword(Password *pw, char *prompt);

char * saltPassword(char *password);

void comparePasswords(Password *pw);

void cleanPassword(Password *password);

#endif
