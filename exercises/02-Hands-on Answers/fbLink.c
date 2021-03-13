#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createFBLink(char fName[], char lName[]) {

    if (fName[0] != '\0' || lName[0] != '\0')
        printf("%s.%s@facebook.com\n", fName, lName);
    else 
        printf("no facebook link generated\n");

}

char * createFbLink(char fName[], char lName[]) {
    if (fName[0] != '\0' || lName[0] != '\0') {
        int len1, len2;
        len1 = strlen(fName);
        len2 = strlen(lName);

        char *link = (char*) malloc((len1+len2+14) * sizeof(char));
        if (link != NULL) {
            memcpy(link, fName, len1);
            strncat(link, '.', 1);
            strncat(link, lName, len2);
            strncat(link, "@facebook.com\0", 13);
        }
        free (link);
    } else 
        printf("no facebook link generated\n");
}

int main() {
    char fName[] = "Idan";
    char lName[] = "Garay";

    createFBLink(fName, lName);

    return 0;
}