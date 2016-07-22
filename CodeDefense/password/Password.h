#ifndef PASSWORD_H_
#define PASSWORD_H_

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

typedef struct {
    char password[30];
    char passwordMatch[30];
} Password;

Password * passwordInit();

void getPassword(Password *pw);

void getPasswordMatch(Password *pw);

#endif
