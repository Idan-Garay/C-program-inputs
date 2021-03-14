#include <stdio.h>
#include <string.h>

typedef struct Name {
    char fN[24]; /*First name*/
    char lN[16]; /*Last name*/
    char mI; /*Middle initial*/
} Nametype;

typedef enum {FALSE, TRUE} boolean;

boolean sameName(Nametype name1, Nametype name2) {
    boolean bool = FALSE;
    if (strcmp(name1.fN, name2.fN) == 0 && strcmp(name1.lN, name2.lN) == 0 && name1.mI == name2.mI) {
        bool = TRUE;
    }

    return bool;
}

int main() {
    Nametype name;
    Nametype name2 = {"Idan", "Garay", 'T'};

    scanf("%s %c %s", name.fN, &name.mI, name.lN);

    printf("Same Name? (%d)", sameName(name, name2));
    return 0;
}