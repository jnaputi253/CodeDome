/**
 * Known Issues
 *
 * a)   When validating the length, if you put more than 50 characters the input will just pour
 *      out to the next input section.  For example: I put over 50 characters and it jumped me down
 *      all the way to the Input File section of the code.
 *
 *      A WARNING: THE REGEX LIBRARY WILL PROBABLY ACT UP ON WINDOWS.  As a safety measure, I have
 *      commented out the function.
 *
 *      Aside from that, it filters the input fine.  At least for me, so I can't say much.
 **/

#include "Person.h"

Person * init() {
	return (Person *)calloc(1, sizeof(Person));
}

char * getName(char *prompt) {
    char *pattern = "^[A-Za-z]*$";
    regex_t regex;
    char buff[50];
    char *name;
    
    int result = regcomp(&regex, pattern, 0);
    if(result) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }
    
    int loop = 1;
    
    while(loop) {
        printf("%s", prompt);
        fgets(buff, 50, stdin);
        
        name = (char *)calloc(strlen(buff) - 1, sizeof(char));
        strncpy(name, buff, strlen(buff) - 1); // Gets rid of the newline feed.
        result = regexec(&regex, name, 0, NULL, 0); // Checks for pattern match.
        
        if(result == 0) {
            if(strlen(name) > 50 || strlen(name) < 3) { // Big issue spot right here.
                printf("Input must be 3 to 50 characters\n");
                buff[0] = '\0';
                name[0] = '\0';
            } else {
                loop = 0;
            }
        } else {
            printf("Input is invalid\n");
            buff[0] = '\0';
            name[0] = '\0';
        }
    }
    
    return name;
}

void cleanPerson(Person *p) {
    if(p != NULL) {
        free(p->firstName);
        free(p->lastName);
        free(p);
        p = NULL;
    }
}
