// Issues in this code
//
// The main issue is just the input buffer.  If you insert more than the specified amount,
// it would just spill out to the next input.  To handle this, I have increased the buffer size from
// 20 to 200.  If it sounds excessive, it is; however, I can't figure out how to ensure it won't spill.
// So for now, I am relying on a large buffer to help alleviate that; however, what scares me is that
// Tom will probably put a value > 200.  As a consequence, this safety measure will fail and I don't
// want to allocate more memory to the buffer.
//
//
// There is a check, however, to determine if the value is greater than the max value with the macro
// INT_MAX; or, the min value with INT_MIN.
// I haven't tested this on Windows so I am hoping it works ok for you.  If not, I was
// just considering placing the actual hard value in there to check (2147483647 and -2147483648)
// in place of the macros in the if-else statements below.
//
// I was considering using a loop but just defaulted to put a 0 for now until I can get the
// buffer figured out.

#include "Number.h"

Number * initNumbers() {
    return (Number *)calloc(1, sizeof(Number));
}

int getNumber(char *prompt) {
    int number;
    char buff[200];
    char *backup;
    
    printf("%s", prompt);
    fgets(buff, 20, stdin);
    
    number = atoi(buff);
    if(number > INT_MAX) {
        printf("Your value is too large.  Defaulting to 0\n");
        return 0;
    } else if(number < INT_MIN) {
        printf("Your value is too small.  Defaulting to 0\n");
        return 0;
    }
    
    return number;
}

int add(int num1, int num2) {
    if((num1 + num2) > INT_MAX) {
        printf("The sum of the two numbers would cause an overflow.  Defaulting to 0\n");
        return 0;
    }
    
    return num1 + num2;
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

void cleanNumber(Number *num) {
    if(num != NULL) {
        free(num);
        num = NULL;
    }
}
