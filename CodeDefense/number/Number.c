#include "Number.h"

Number * initNumbers() {
    return (Number *)calloc(1, sizeof(Number));
}

void readFirstNumber(Number *num) {
    int number;
    char buff[20];
    char *backup;
    
    printf("Enter the first number (if input is invalid, it defaults to 0): ");
    fgets(buff, 20, stdin);
    
    number = atoi(buff);
    if(number > INT_MAX) {
        printf("Your value is too large.  Defaulting to 0\n");
    } else {
        num->firstNumber = number;
    }
}

void readSecondNumber(Number *num) {
    int number;
    char buff[20];
    
    printf("Enter the second number (if input is invalid, it defaults to 0): ");
    fgets(buff, 20, stdin);
    
    number = atoi(buff);
    if(number > INT_MAX) {
        printf("Your value is too large.  Defaulting to 0\n");
    } else {
        num->firstNumber = number;
    }
}

int add(int num1, int num2) {
    if(((num1 > 0) && (num2 > INT_MAX - num1))
       || ((num1 < 0) && (num2 < INT_MIN - num1))) {
        printf("Summing the two numbers results in an overflow.  Defaulting to 0");
        return 0;
    } else {
        return num1 + num2;
    }
}

int multiply(int num1, int num2) {
    if(((num1 > 0) && (num2 > INT_MAX - num1))
       || ((num1 < 0) && (num2 < INT_MIN - num1))) {
        printf("Summing the two numbers results in an overflow.  Defaulting to 0");
        return 0;
    } else {
        return num1 * num2;
    }
}
