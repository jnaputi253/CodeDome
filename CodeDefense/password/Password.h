#ifndef PASSWORD_H_
#define PASSWORD_H_

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <crypt.h>
#include <ctype.h>

typedef struct {
    char *pw1;
    char *pw2;
} Password;

Password * passwordInit();

void cleanBuffer(char *buffer);

char * getPassword(Password *pw, char *prompt);

char * saltPassword(char *password);

char * grabPassword(char *input);

int checkResult(int n_flag, int l_flag, int u_flag, int s_flag, int sp_flag);

void printError(int n_flag, int l_flag, int u_flag, int s_flag, int sp_flag);

void reset(int *n_flag, int *l_flag, int *u_flag, int *s_flag, int *sp_flag);

void comparePasswords(Password *pw);

void cleanPassword(Password *password);

#endif
