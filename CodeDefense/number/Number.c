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
    char buff[10];
    char *backup;
    int run = 1;
    
    while(run) {
        printf("%s", prompt);
        fgets(buff, 10, stdin);
        
        if(buff[strlen(buff) - 1] != '\n') {
            buff[strlen(buff) - 1] = '\n';
            
            char c;
            while((c = getchar()) != '\n' && c != EOF);
        }
        
        number = atoi(buff);
        
        if(number == 0) {
            if(buff[0] == 0) {
                run = 0;
            } else if(buff[0] != 0) {
                printf("Enter only a number\n\n");
                buff[0] = '\0';
            }
        } else if(number > 0) {
            if(number > (int)INT_MAX) {
                printf("Your input is too large\n\n");
                buff[0] = '\0';
            } else {
                run = 0;
            }
        } else if(number < 0) {
            if(number < (int)INT_MIN) {
                printf("Your input is too small\n\n");
                buff[0] = '\0';
            } else {
                run = 0;
            }
        }
    }
    
    return number;
}

int add(int num1, int num2) {
    if(((num1 + num2) > INT_MAX) || ((num1 + num2) < INT_MIN)) {
        printf("The sum of the two numbers would cause an overflow.  Defaulting to 0\n\n");
        return 0;
    }
    
    return num1 + num2;
}

int multiply(int num1, int num2) {
    if(((num1 * num2) > INT_MAX) || ((num1 * num2) < INT_MIN)) {
        printf("The product of the two numbers would cause an overflow.  Defaulting to 0\n\n");
    }
    
    return num1 * num2;
}

void cleanNumber(Number *num) {
    if(num != NULL) {
        free(num);
        num = NULL;
    }
}
