#ifndef NUMBER_H_
#define NUMBER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int firstNumber;
    int secondNumber;
} Number;

Number * initNumbers();

int getNumber(char *prompt);

int add(int num1, int num2);

int multiply(int num1, int num2);

#endif
