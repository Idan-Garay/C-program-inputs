#include <stdio.h>
#include "SETArray.h"

void displayBits(char val) {
    int bit = (sizeof(val)*8) -1;
    unsigned int masked;

    for (masked = 1 << bit; masked > 0; masked >>=1) {
        printf("%d", (masked&val? 1 : 0));
    }
}

int main() {

    SET A = {{1,5,3,7,0,2}, 6};
    SET B = {{3,0,55,1}, 4};

    sortSet(&B);
    SET C = unionn(A, B);
    printf("Union:");
    displaySet(C);

    return 0;
}

// UID

