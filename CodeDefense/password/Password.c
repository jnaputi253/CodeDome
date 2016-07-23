#include "Password.h"

Password * passwordInit() {
    return (Password *)calloc(1, sizeof(Password));
}

char * getPassword(Password *password, char *prompt) {
    const int MAX_SIZE = 30;
    const int MIN_SIZE = 6;
    char buff[MAX_SIZE];
    int repeat = 1;
    
    while(repeat) {
        printf("Enter your password: ");
        fgets(buff, MAX_SIZE, stdin);
        
        if((strlen(buff) >= MIN_SIZE) && (strlen(buff) <= MAX_SIZE)) {
            repeat = 0;
        } else {
            printf("Invalid input, try again!\n");
        }
    }
    
    char *input = saltPassword(buff);
    printf("Password: %s\n", input);
    
    return input;
}

char * saltPassword(char *buff) {
    char *salt = "FSASD9J";
    char *saltedPassword = (char *)calloc((strlen(buff) - 1 + strlen(salt) - 1), sizeof(char));
    
    strncat(saltedPassword, buff, strlen(buff) - 1);
    strncat(saltedPassword, salt, strlen(buff) - 1);
    
    return saltedPassword;
}

void comparePasswords(Password *pw) {
    int result = strcmp(pw->pw1, pw->pw2);
    
    if(result == 0) {
        printf("\nThe passwords are the same\n\n");
    } else {
        printf("\nThe passwords are different\n\n");
    }
}

void cleanPassword(Password *pw) {
    if(pw != NULL) {
        free(pw->pw1);
        free(pw->pw2);
        free(pw);
        pw = NULL;
    }
}
