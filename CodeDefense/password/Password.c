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
    
    return input;
}

char * saltPassword(char *buff) {
	unsigned long seed[2];
	char salt[] = "$6$........";
	const char *seedChars = 
		"./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	seed[0] = time(NULL);
	seed[1] = getpid() ^ (seed[0] >> 14 & 0x30000);

	int i;
	for(i = 0; i < 8; i++) {
		salt[3+i] = seedChars[(seed[i/5] >> (i%6) * 6) & 0x3f];
	}

	return crypt(buff, salt);
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
        free(pw);
        pw = NULL;
    }
}
