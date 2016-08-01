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
        
        if(buff[strlen(buff) - 1] != '\n') {
            buff[strlen(buff) - 1] = '\n';
            
            char c;
            while((c = getchar()) != '\n' && c != EOF);
        }
        
        name = (char *)calloc(strlen(buff) - 1, sizeof(char));
        strncpy(name, buff, strlen(buff) - 1);
        result = regexec(&regex, name, 0, NULL, 0);
        
        if(result == 0) {
            if(strlen(name) > 50 || strlen(name) < 3) {
                printf("Input must be 3 to 50 characters\n\n");
                buff[0] = '\0';
                name[0] = '\0';
            } else {
                loop = 0;
            }
        } else {
            printf("Input is invalid\n\n");
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
