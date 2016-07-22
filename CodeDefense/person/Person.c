#include "Person.h"

Person * init() {
	return (Person *)calloc(1, sizeof(Person));
}

void getFirstName(Person *person) {
	char *pattern = "^[A-Za-z]*$";
	regex_t regex;
	char buff[50];

	int result = regcomp(&regex, pattern, 0);
	if(result) {
		fprintf(stderr, "Could not compile regex\n");
		exit(1);
	}

	int loop = 1;

	while(loop != 0) {
		printf("Enter your first name: ");
		fgets(buff, 50, stdin);

		char input[50];
		strncpy(input, buff, strlen(buff) - 1);

		result = regexec(&regex, input, 0, NULL, 0);

		if(result == 0) {
			if((strlen(input)) > 50) {
				printf("50 characters max\n");
			} else {
				strncpy(person->firstName, input, strlen(input));
				loop = 0;
			}
		} else {
			printf("%s is an invalid input\n", input);
            
            buff[0] = '\0';
            input[0] = '\0';
		}
	}

	regfree(&regex);
}

void getLastName(Person *person) {
	char *pattern = "^[A-Za-z]*$";
	regex_t regex;
	char buff[50];

	int result = regcomp(&regex, pattern, 0);
	if(result) {
		fprintf(stderr, "Could not compile regex\n");
		exit(1);
	}

	int loop = 1;

	while(loop != 0) {
		printf("Enter your last name: ");
		fgets(buff, 50, stdin);

		char input[50];
		strncpy(input, buff, strlen(buff) - 1);

		result = regexec(&regex, input, 0, NULL, 0);

		if(result == 0) {
			if((strlen(input)) > 50) {
				printf("50 characters max\n");
			} else {
				strncpy(person->lastName, input, strlen(input));
				loop = 0;
			}
		} else {
			printf("%s is an invalid input\n", input);
            
            buff[0] = '\0';
            input[0] = '\0';
		}
	}

	regfree(&regex);
}
