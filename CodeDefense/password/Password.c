#include "Password.h"

Password * passwordInit() {
    return (Password *)calloc(1, sizeof(Password));
}

char * getPassword(Password *password, char *prompt) {
    const int MAX_SIZE = 32;
    const int MIN_SIZE = 8;
    char buff[MAX_SIZE];
    int repeat = 1;
    
    int numberFlag = 0;
    int lowerFlag = 0;
    int specialFlag = 0;
    int upperFlag = 0;
    int spaceFlag = 0;
    
    /*
    regex_t regex;
    // char *pattern = "^(?=.{8,32}$)(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[(!@#$%^&*_)]).*";
    // char *pattern = "^(?=.*\\d)(?=.*[a-z])(?=.*[A-Z])(?!.*\\s).{4, 8}$";
    // char *pattern = "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[^\\da-zA-Z]).{8,15}$";
    // char *pattern = "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[^\\da-zA-Z]).{6,20}$";
    int result = regcomp(&regex, pattern, 0);
    if(result) {
    	fprintf(stderr, "Could not compile regex\n");
    	exit(1);
    }
    */
    while(repeat) {
        printf("Enter your password: ");
        fgets(buff, MAX_SIZE, stdin);
        
        cleanBuffer(buff);
        
        if((strlen(buff) >= MIN_SIZE) && (strlen(buff) <= MAX_SIZE)) {
        	char *pw = grabPassword(buff);
        	
        	int i;
        	for(i = 0; i < strlen(pw); i++) {
        		if(isdigit(pw[i])) { numberFlag = 1; }
        		if(isupper(pw[i])) { upperFlag = 1; }
        		if(islower(pw[i])) { lowerFlag = 1; }
        		if(ispunct(pw[i])) { specialFlag = 1; }
        		if(isspace(pw[i])) { spaceFlag = 1; }
        	}
        	
        	int result = checkResult(numberFlag, upperFlag, lowerFlag, specialFlag, spaceFlag);
        	if(result == 0) {
        		repeat = 0;
        	} else {
        		printError(numberFlag, upperFlag, lowerFlag, specialFlag, spaceFlag);
        		reset(&numberFlag, &upperFlag, &lowerFlag, &specialFlag, &spaceFlag);
        	}
        } else {
            printf("Password must range from 8 to 32 characters inclusive\n");
        }
    }
    
    char *input = saltPassword(buff);
    
    return input;
}

void cleanBuffer(char *buffer) {
	if(buffer[strlen(buffer) - 1] != '\n') {
		buffer[strlen(buffer) - 1] = '\n';
		
		char c;
		while((c = getchar()) != '\n' && c != EOF);
	}
}

int checkResult(int n_flag, int l_flag, int u_flag, int s_flag, int sp_flag) {
	if(n_flag == 1 && l_flag == 1 && u_flag == 1 && s_flag == 1 && sp_flag == 0) {
		return 0;
	}
	
	return -1;
}

void printError(int n_flag, int l_flag, int u_flag, int s_flag, int sp_flag) {
	printf("Errors\n");
	
	if(!n_flag) printf("- Must have a number\n");
	if(!l_flag) printf("- Must have a lowerclase character\n");
	if(!u_flag) printf("- Must have an uppercase character\n");
	if(!s_flag) printf("- Must have a special character\n");
	if(sp_flag) printf("- No spaces allowed\n");
	
	printf("\n");
}

void reset(int *n_flag, int *l_flag, int *u_flag, int *s_flag, int *sp_flag) {
	*n_flag = 0;
	*l_flag = 0;
	*u_flag = 0;
	*s_flag = 0;
	*sp_flag = 0;
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

char * grabPassword(char *input) {
	char *pw = (char *)calloc(strlen(input), sizeof(char) - 1);
	strncpy(pw, input, strlen(input) - 1);
	
	return pw;
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
