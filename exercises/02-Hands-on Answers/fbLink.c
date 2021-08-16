#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *createFBLink(char fName[], char lName[]) {
    int fNameLen = strlen(fName);
    int lNameLen = strlen(lName);
    char *ptr = NULL;
    
    if (fNameLen != 0 & lNameLen != 0) {
        int fullNameLen = fNameLen + lNameLen;
        ptr = (char*) calloc(14+fullNameLen, sizeof(char));

        if (ptr != NULL) {
            sprintf(ptr, "%s.%s@facebook.com", fName, lName);
        }
    }

    return ptr;
}

int main() {
    char fName[24] = "Josh", lName[16] = "Garay";
    char *email;

    scanf("%s", fName);
    scanf("%s", lName);

    email = createFBLink(fName, lName);
    printf("%s", email);
    
    return 0;
}