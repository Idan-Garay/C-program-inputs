#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studDetails {
    char fN[24];
    char lN[16];
    char sCode[16];
}studDetails;

char * getAccount(studDetails stud) {
    char *acc = (char*) malloc(50 * sizeof(char));

    strcat(acc, stud.lN);
    strncat(acc, stud.fN, 2*sizeof(char));
    strcat(acc, "_");
    strcat(acc, stud.sCode);

    return acc;
}

int main() {
    studDetails stud = {"Idan", "Garay", "CS1201"};

    char *acc = getAccount(stud);
    printf("%s", acc);
    free(acc);

    return 0;
}