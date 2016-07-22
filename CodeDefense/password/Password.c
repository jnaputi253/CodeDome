#include "Password.h"

Password * passwordInit() {
    return (Password *)calloc(1, sizeof(Password));
}

void getPassword(Password *password) {
    char buff[30];
    int repeat = 1;
    
}
